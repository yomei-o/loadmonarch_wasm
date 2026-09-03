// Drive the ported simulation with no window at all.
//
// The Win32 shell is only a viewer; everything the game does lives in world.c,
// state.c and sim.c, so it can be run and watched from a console - which is
// both faster and does not steal the screen from whoever is using the machine.
//
//   sim_harness <dataDir> <map> [sweeps] [build:col,row ...]
//
// Prints the state at the start, after each build order, and at the end.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/host.h"
#include "../src/sim.h"
#include "../src/state.h"
#include "../src/world.h"

static void report(GameState *game, const Sim *sim, const char *when) {
    stateRecomputeTotals(game);
    unsigned units[FACTION_COUNT] = {0}, ground[FACTION_COUNT] = {0};
    unsigned castles[FACTION_COUNT] = {0}, neutral = 0, empty = 0, live = 0;
    for (int i = 0; i < WORLD_CELLS; i++) {
        const unsigned char t = game->world.cells[i].terrain;
        if (t == 0) empty++;
        else if (t == 5) neutral++;
        else if (t >= 8 && t <= 0x0b) units[t - 8]++;
        else if (t >= 0x0c && t <= 0x0f) ground[t - 0x0c]++;
        else if (t >= 0x14 && t <= 0x17) castles[t - 0x14]++;
    }
    for (int i = 0; i < ENTITY_COUNT; i++)
        if ((game->entities[i].flags & 0x80) == 0) live++;

    printf("--- %s (sweep %llu)  empty %u  neutral %u  entities %u\n",
           when, sim->frames, empty, neutral, live);
    for (int f = 0; f < FACTION_COUNT; f++) {
        unsigned mine = 0;
        for (int i = 0; i < ENTITY_COUNT; i++)
            if ((game->entities[i].flags & 0x80) == 0 &&
                game->entities[i].faction == (unsigned char)f) mine++;
        printf("    faction %d  funds %6u  tax %3u  castles %u  units %3u  "
               "ground %4u  losses %6u  live %2u%s\n",
               f, game->factions[f].funds, game->factions[f].taxRate,
               castles[f], units[f], ground[f], game->factions[f].at14, mine,
               (game->factions[f].flags & 0x10) ? "  out" : "");
    }
}



// An ASCII picture of who holds what, for looking at a stage the way the
// player would.  Digits are a country's unit cells, the letters under them its
// plain ground, '#' is anything a unit cannot walk on, and '*' a monster den.
static void drawMap(const GameState *game) {
    for (unsigned row = 0; row < WORLD_GRID; row++) {
        for (unsigned col = 0; col < WORLD_GRID; col++) {
            const unsigned char t =
                game->world.cells[WORLD_INDEX(col, row)].terrain;
            char c;
            if (t == 0) c = '.';
            else if (t == 5) c = '*';
            else if (t >= 8 && t <= 0x0b) c = (char)('0' + (t - 8));
            else if (t >= 0x0c && t <= 0x0f) c = (char)('a' + (t - 0x0c));
            else if (t >= 0x14 && t <= 0x17) c = (char)('A' + (t - 0x14));
            else if (t == 0x7a) c = 'm';
            else if (t == 0x7b) c = 'W';
            else if (t >= 0x30 && t <= 0x5f) c = '~';
            else if (t >= 0x30) c = '#';
            else c = '?';
            putchar(c);
        }
        putchar(10);
    }
    unsigned seen[256];
    memset(seen, 0, sizeof seen);
    for (int i = 0; i < WORLD_CELLS; i++) seen[game->world.cells[i].terrain]++;
    for (int t = 0; t < 256; t++)
        if (seen[t]) printf("  terrain %02x: %u\n", t, seen[t]);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr,
                "usage: sim_harness <dataDir|zip> <map> [sweeps] "
                "[build:col,row ...]\n");
        return 2;
    }
    static GameState game;
    static Host host;
    // A path ending in .zip is the player's own archive; anything else is an
    // extracted directory.  Both reach the loader the same way.
    const size_t length = strlen(argv[1]);
    if (length > 4 && strcmp(argv[1] + length - 4, ".zip") == 0) {
        FILE *f = fopen(argv[1], "rb");
        if (!f) { perror(argv[1]); return 2; }
        fseek(f, 0, SEEK_END);
        const long size = ftell(f);
        fseek(f, 0, SEEK_SET);
        unsigned char *archive = malloc((size_t)size);
        if (!archive || fread(archive, 1, (size_t)size, f) != (size_t)size)
            return 2;
        fclose(f);
        if (!hostUseZip(&host, archive, (unsigned)size)) {
            fprintf(stderr, "%s is not a readable zip\n", argv[1]);
            return 1;
        }
    } else if (!hostUseDirectory(&host, argv[1])) {
        fprintf(stderr, "cannot use %s\n", argv[1]);
        return 1;
    }
    char message[256];
    if (!worldLoadStage(&game.world, &host, argv[2], message,
                        sizeof message)) {
        fprintf(stderr, "%s\n", message);
        return 1;
    }
    stateStartStage(&game);

    Sim sim;
    simInit(&sim, &game);
    simSeedLeaders(&sim);
    // DAT_004365cd holding four is none of the countries, so all four
    // are played by the machine.
    for (int a = 4; a < argc; a++)
        if (strcmp(argv[a], "nohuman") == 0) sim.humanFaction = 4;
    printf("stage %s, scenery set %u\n", argv[2], game.world.scenerySet);
    report(&game, &sim, "start");

    const long sweeps = argc > 3 ? strtol(argv[3], NULL, 10) : 1000;

    for (int a = 4; a < argc; a++) {
        unsigned col = 0, row = 0;
        if (strcmp(argv[a], "map") == 0) continue;
        if (strcmp(argv[a], "nohuman") == 0) continue;
        if (strncmp(argv[a], "trace:", 6) == 0) {
            // Follow one country tick by tick: how many settlement cells it
            // holds, how ripe they are, and what each of its live units is
            // doing.  Written to find out why the country the player has grows
            // so much more slowly than the ones the machine plays.
            const unsigned who = (unsigned)atoi(argv[a] + 6);
            for (int t = 0; t <= 12; t++) {
                if (t) for (int i = 0; i < 100; i++) simStep(&sim);
                unsigned cells = 0, ripe = 0, busy = 0, top = 0;
                for (unsigned c = 0; c < WORLD_GRID; c++)
                    for (unsigned r = 0; r < WORLD_GRID; r++) {
                        const WorldCell *cell =
                            &game.world.cells[WORLD_INDEX(c, r)];
                        if ((unsigned)(cell->terrain - 8u) != who) continue;
                        cells++;
                        if (cell->value > top) top = cell->value;
                        if (cell->value >= 200) ripe++;
                        if (cell->occupant < ENTITY_COUNT) busy++;
                    }
                printf("+%4d  cells %3u  ripe %2u  occupied %2u  best %3u"
                       "  funds %5u\n",
                       t * 100, cells, ripe, busy, top,
                       game.factions[who].funds);
                for (int i = 0; i < ENTITY_COUNT; i++) {
                    const Entity *e = &game.entities[i];
                    if (e->flags & 0x80) continue;
                    if (e->faction != who) continue;
                    printf("      slot %3d at %2u,%2u  order %02x  str %5u"
                           "  route %s  flags %02x  face %u\n",
                           i, e->position[0], e->position[1], e->at0d,
                           e->at08, e->at18 == 0x1f0 ? "-" : "yes",
                           e->flags, e->at0c);
                }
            }
            continue;
        }
        if (strncmp(argv[a], "win:", 4) == 0) {
            // The question a player asks: with the tax at nothing and the
            // purse full, does the stage actually finish?  The country is the
            // player's, so 00421ae0 never runs for it - its units only ever
            // look for work nearby, which is the whole of what a player's
            // country does by itself.
            const unsigned who = sim.humanFaction;
            const long limit = strtol(argv[a] + 4, NULL, 10);
            long at = 0;
            int outcome = 0;
            while (at < limit && (outcome = simStageOutcome(&sim)) == 0) {
                game.factions[who].taxRate = 0;
                game.factions[who].funds = 0xffffu;
                simStep(&sim);
                at++;
            }
            unsigned live = 0, cells = 0;
            for (int i = 0; i < ENTITY_COUNT; i++)
                if (!(game.entities[i].flags & 0x80) &&
                    game.entities[i].faction == who) live++;
            for (unsigned c = 0; c < WORLD_GRID; c++)
                for (unsigned r = 0; r < WORLD_GRID; r++)
                    if ((unsigned)(game.world.cells[WORLD_INDEX(c, r)].terrain
                                   - 8u) == who) cells++;
            printf("win %s: outcome %d after %ld sweeps (day %u), "
                   "%u live, %u settlements, area %.2f%%, funds %u\n",
                   argv[2], outcome, at, sim.days, live, cells,
                   (double)game.factions[who].area,
                   game.factions[who].funds);
            continue;
        }
        if (strcmp(argv[a], "names") == 0) {
            // Every string the scenery set supplies, raw, so the bytes can be
            // collected: the five countries and the sixteen orders.
            for (unsigned f = 0; f < 5; f++)
                printf("N %s\n", worldCountryName(&game.world, f));
            for (unsigned o = 0; o < 16; o++)
                printf("N %s\n", worldOrderName(&game.world, o));
            continue;
        }
        if (sscanf(argv[a], "clear:%u,%u", &col, &row) == 2) {
            // What a player does: gather the army, point it at a square of
            // scenery with the clearing order, and watch.
            // The four seeded leaders are all there is at sweep zero, and
            // 00409e90 never picks a leader up, so let the countries raise an
            // army first.
            for (int i = 0; i < 2000; i++) simStep(&sim);
            const int chosen = simSelectAll(&sim, 1);
            const int sent = simOrderSelected(&sim, 7, 0, (int)col, (int)row);
            printf("clear %u,%u: %d chosen, %d sent, terrain %02x\n",
                   col, row, chosen, sent,
                   game.world.cells[WORLD_INDEX(col, row)].terrain);
            for (int t = 1; t <= 20; t++) {
                for (int i = 0; i < 100; i++) simStep(&sim);
                const WorldCell *c = &game.world.cells[WORLD_INDEX(col, row)];
                unsigned near = 0;
                int who = -1;
                for (int dc = -1; dc <= 1; dc++)
                    for (int dr = -1; dr <= 1; dr++) {
                        const int cc = (int)col + dc, rr = (int)row + dr;
                        if (cc < 0 || rr < 0 || cc > 47 || rr > 47) continue;
                        const unsigned char o =
                            game.world.cells[WORLD_INDEX(cc, rr)].occupant;
                        if (o < ENTITY_COUNT) { near++; who = o; }
                    }
                printf("  +%4d  terrain %02x  value %u  beside %u",
                       t * 100, c->terrain, c->value, near);
                if (who >= 0) {
                    const Entity *e = &game.entities[who];
                    printf("  (slot %d order %02x at %u,%u target %u,%u"
                           " route %s)", who, e->at0d, e->position[0],
                           e->position[1], e->target[0], e->target[1],
                           e->at18 == 0x1f0 ? "none" : "yes");
                }
                putchar(10);
            }
            continue;
        }
        if (sscanf(argv[a], "build:%u,%u", &col, &row) != 2) {
            fprintf(stderr, "cannot read %s\n", argv[a]);
            continue;
        }
        const unsigned actor = simHumanActor(&sim);
        const int result = actor < ENTITY_COUNT
            ? (int)simBuildUnitCell(&sim, actor, col, row)
            : (int)SIM_ACTION_REFUSED;
        static const char *name[7] = {
            "?", "placed", "no funds", "refused", "?", "?", "spent the unit",
        };
        printf("build at %u,%u through entity %u: %s\n", col, row, actor,
               name[result >= 0 && result < 7 ? result : 0]);
    }

    for (long i = 0; i < sweeps; i++) simStep(&sim);
    report(&game, &sim, "end");
    for (int a = 4; a < argc; a++)
        if (strcmp(argv[a], "map") == 0) drawMap(&game);
    // What every live unit is carrying, per country: a country whose units
    // all sit on one order is a country that has stopped playing.
    for (unsigned f = 0; f < FACTION_COUNT; f++) {
        unsigned tally[16];
        memset(tally, 0, sizeof tally);
        unsigned live = 0, routed = 0;
        for (int i = 0; i < ENTITY_COUNT; i++) {
            const Entity *e = &game.entities[i];
            if (e->flags & 0x80) continue;
            if (e->faction != f) continue;
            live++;
            tally[e->at0d & 0x0f]++;
            if (e->at18 != 0x1f0) routed++;
        }
        if (!live) continue;
        printf("  faction %u  live %2u  walking %2u  orders", f, live, routed);
        for (int o = 0; o < 16; o++)
            if (tally[o]) printf("  %d:%u", o, tally[o]);
        putchar(10);
    }
    worldFree(&game.world);
    return 0;
}
