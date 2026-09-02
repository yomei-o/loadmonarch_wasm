// The question a player asks first: do the four countries grow on their own?
//
// Nothing here is about matching the executable line by line.  It runs a stage
// and watches the map change hands, because a port whose countries sit still
// is wrong however faithful its routines look.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/host.h"
#include "../src/sim.h"
#include "../src/state.h"
#include "../src/world.h"

static unsigned held(const GameState *game, unsigned faction) {
    unsigned n = 0;
    for (int i = 0; i < WORLD_CELLS; i++) {
        const unsigned char t = game->world.cells[i].terrain;
        if ((unsigned char)(t - faction) == 8 ||
            (unsigned char)(t - faction) == 0x0c) n++;
    }
    return n;
}

// How much of the walking is a unit stepping straight back where it came from.
//
// This is the shape of the bug that made the port unplayable once: units in a
// settled area shuttled between two cells for the length of a stage, because
// the finder that says where a settlement may go was not asking 0041e670.  It
// looks like purposeful movement one frame at a time and is obvious over a
// thousand, so it is measured rather than watched.
typedef struct {
    unsigned char here[ENTITY_COUNT][2];
    unsigned char before[ENTITY_COUNT][2];
    unsigned char known[ENTITY_COUNT];
    unsigned long moves, backwards;
} Wandering;

static void watchWandering(const GameState *game, Wandering *w) {
    for (int i = 0; i < ENTITY_COUNT; i++) {
        const Entity *e = &game->entities[i];
        if (e->flags & 0x80) { w->known[i] = 0; continue; }
        const unsigned char c = e->position[0], r = e->position[1];
        if (!w->known[i]) {
            w->known[i] = 1;
            w->here[i][0] = w->before[i][0] = c;
            w->here[i][1] = w->before[i][1] = r;
            continue;
        }
        if (c == w->here[i][0] && r == w->here[i][1]) continue;
        w->moves++;
        if (c == w->before[i][0] && r == w->before[i][1]) w->backwards++;
        w->before[i][0] = w->here[i][0];
        w->before[i][1] = w->here[i][1];
        w->here[i][0] = c;
        w->here[i][1] = r;
    }
}

int main(int argc, char **argv) {
    static Host host;
    FILE *f = fopen(argc > 1 ? argv[1] : "ds7e.zip", "rb");
    if (!f) { puts("  (no archive - nothing to measure)"); return 0; }
    fseek(f, 0, SEEK_END);
    const long size = ftell(f);
    fseek(f, 0, SEEK_SET);
    unsigned char *bytes = (unsigned char *)malloc((size_t)size);
    if (!bytes || fread(bytes, 1, (size_t)size, f) != (size_t)size) return 2;
    fclose(f);
    if (!hostUseZip(&host, bytes, (unsigned)size)) return 2;

// Every stage the campaign lists, in its own order, and whether the four
// countries can be expected to find each other without a player.
//
// Three of them cannot: "Saint Steed", "Strange Islands" and "Moon and Stars".
// Each puts its countries in pockets with terrain from 0x30 to 0x5f between -
// scenery on the first and the last, open water on the islands - and that
// whole range is cleared by order 7 and by nothing else.  Clearing water is
// how a bridge gets built, and order 7 reaches a unit exactly two ways:
// 00401770 gives it to one that walks into a mine, and 00421d30 gives it to
// one 0041c8e0 has found a mine for - and 0041c8e0 looks for terrain 0x7a
// alone, of which those maps have none.  0041c410, the wide search, does not
// weigh that range at all.  Every at0d assignment in the executable was read
// to be sure: a country the machine plays never opens a way through it, so
// those three stages wait for the player to bridge them, and a port whose
// machine bridged them would be the wrong one.
static const struct {
    const char *file;
    int meets;
} stages[] = {
    {"B_000.MAP", 1},   // Conqueror's trial
    {"B_003.MAP", 1},   // Backroad Euromap
    {"B_004.MAP", 1},   // Ancient Kingdom
    {"B_006.MAP", 1},   // Steel Brain
    {"S_201.MAP", 1},   // Candy Waltz
    {"B_104.MAP", 0},   // Strange Islands
    {"B_002.MAP", 1},   // Precious Nature
    {"B_005.MAP", 0},   // Saint Steed
    {"S_115.MAP", 1},   // Geo Port Flash
    {"B_009.MAP", 1},   // Triple Attack
    {"S_101.MAP", 1},   // Forest War
    {"T_000.MAP", 1},   // Number One!
    {"S_105.MAP", 1},   // Sleeping Dragon
    {"B_105.MAP", 1},   // Space Colony
    {"B_103.MAP", 0},   // Moon and Stars
};
    int failures = 0;
    for (unsigned s = 0; s < sizeof stages / sizeof stages[0]; s++) {
        static GameState game;
        char message[256];
        if (!worldLoadStage(&game.world, &host, stages[s].file, message,
                            sizeof message)) {
            printf("  FAIL %s: %s\n", stages[s].file, message);
            failures++;
            continue;
        }
        stateStartStage(&game);
        Sim sim;
        simInit(&sim, &game);
        // Nobody at the keyboard: DAT_004365cd holds the country the player
        // has, and four is none of them, so all four are played by the
        // machine.  That is what this test is asking about.
        sim.humanFaction = 4;
        simSeedLeaders(&sim);

        unsigned before[4], after[4];
        for (int i = 0; i < 4; i++) before[i] = held(&game, (unsigned)i);
        static Wandering wander;
        memset(&wander, 0, sizeof wander);
        for (int i = 0; i < 4000; i++) {
            simStep(&sim);
            watchWandering(&game, &wander);
        }
        for (int i = 0; i < 4; i++) after[i] = held(&game, (unsigned)i);

        int grew = 0;
        printf("  %-10s", stages[s].file);
        for (int i = 0; i < 4; i++) {
            printf(" %u->%-4u", before[i], after[i]);
            if (after[i] > before[i]) grew++;
        }
        const double back = wander.moves
            ? 100.0 * (double)wander.backwards / (double)wander.moves : 0.0;
        printf("  (%d of 4 grew, %.0f%% of %lu steps went straight back)\n", grew, back, wander.moves);
        // A country walking its units to work turns round now and then; one
        // shuttling between two cells does nothing else.  Half would be the
        // pure shuttle, and the port did once sit near it.
        if (wander.moves > 1000 && back > 30.0) {
            printf("  FAIL %s: the units are shuffling on the spot\n",
                   stages[s].file);
            failures++;
        }
        // Three of the four ought to be bigger after four thousand sweeps.  A
        // country that is boxed in or losing a war may not be, but three
        // standing still means the units are not working.
        // Three of the four ought to be bigger after four thousand sweeps -
        // unless the fighting has already started, in which case somebody is
        // smaller for the best of reasons.
        unsigned early = 0;
        for (int i = 0; i < 4; i++) early += game.factions[i].at14;
        if (stages[s].meets && grew < 3 && early == 0) {
            printf("  FAIL %s: only %d of the four countries grew, and"
                   " nobody had fought\n", stages[s].file, grew);
            failures++;
        }

        // And then they have to meet.  A stage that never resolves is not a
        // game: run it out and look for casualties and for somebody knocked
        // out of it.
        long settled = -1;
        for (int i = 0; i < 60000; i++) {
            simStep(&sim);
            if (settled < 0 && simStageOutcome(&sim)) settled = 4000 + i;
        }
        unsigned losses = 0, out = 0;
        for (int i = 0; i < 4; i++) {
            losses += game.factions[i].at14;
            if (game.factions[i].flags & 0x40) out++;
        }
        printf("  %-10s after 64000: losses %u, %u knocked out", stages[s].file,
               losses, out);
        // 0041f4c0 calls a stage over once three of the four are gone.
        if (settled >= 0) printf(", settled at sweep %ld", settled);
        putchar(10);
        if (!stages[s].meets) {
            printf("  %-10s waits for a player to bridge it,"
                   " and the original is the same\n", stages[s].file);
            worldFree(&game.world);
            continue;
        }
        if (losses == 0) {
            printf("  FAIL %s: nobody ever fought\n", stages[s].file);
            failures++;
        }
        if (out == 0) {
            printf("  FAIL %s: nobody was knocked out\n", stages[s].file);
            failures++;
        }
        worldFree(&game.world);
    }
    printf(failures ? "%d growth check(s) failed\n" : "growth checks ok\n",
           failures);
    return failures ? 1 : 0;
}
