/* What happens when the player kills an enemy KING while that country still
 * holds ground - which is how a player wins, and not how the AI wars end.
 *
 *   tests/king_kill.exe [zip] [map]
 *
 * The stage is played for a while, then every enemy king is struck down the
 * way 00420e70 does it (marked dying, with the player's faction as the cause).
 * After that the countries should drain away and 0041f4c0 should call the
 * stage over.  If the war just runs on, this prints why.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/host.h"
#include "../src/sim.h"
#include "../src/state.h"
#include "../src/world.h"

static void report(const GameState *game, Sim *sim, const char *when) {
    printf("%s: outcome %d\n", when, simStageOutcome(sim));
    for (unsigned k = 0; k < PLAYABLE_FACTIONS; k++) {
        const Faction *c = &game->factions[k];
        printf("  country %u flags %04x %s%s%s strength %6u cells %3u "
               "units %2u leader %u\n", k, c->flags,
               (c->flags & 0x40) ? "conquered" : "---------",
               (c->flags & 1) ? " leader-lost" : " -----------",
               (c->flags & 0x10) ? " defeated" : " --------",
               c->strength, c->at2c, c->entities, c->at0c);
    }
}

int main(int argc, char **argv) {
    const char *archive = argc > 1 ? argv[1] : "ds7e.zip";
    const char *map = argc > 2 ? argv[2] : "B_000.MAP";
    const int when = argc > 3 ? atoi(argv[3]) : 600;

    FILE *f = fopen(archive, "rb");
    if (!f) { printf("cannot open %s\n", archive); return 1; }
    fseek(f, 0, SEEK_END); long size = ftell(f); fseek(f, 0, SEEK_SET);
    unsigned char *zip = (unsigned char *)malloc((size_t)size);
    if (!zip || fread(zip, 1, (size_t)size, f) != (size_t)size) return 1;
    fclose(f);
    static Host host;
    if (!hostUseZip(&host, zip, (unsigned)size)) { printf("not a zip\n"); return 1; }

    static GameState game;
    char message[256];
    if (!worldLoadStage(&game.world, &host, map, message, sizeof message)) {
        printf("%s: %s\n", map, message);
        return 1;
    }
    stateStartStage(&game);
    static Sim sim;
    simInit(&sim, &game);
    simSeedLeaders(&sim);

    for (int i = 0; i < when; i++) {
        game.factions[sim.humanFaction].funds = 999999999u;
        simStep(&sim);
    }
    report(&game, &sim, "before the kings fall");

    /* The player rides in and kills all three kings. */
    for (unsigned k = 0; k < PLAYABLE_FACTIONS; k++) {
        if (k == sim.humanFaction) continue;
        const unsigned slot = game.factions[k].at0c;
        if (slot < ENTITY_COUNT)
            simMarkDying(&game, slot, (unsigned char)sim.humanFaction);
    }
    printf("\nall three kings struck down\n");

    for (int i = 0; i < 4000; i++) {
        game.factions[sim.humanFaction].funds = 999999999u;
        simStep(&sim);
        if (simStageOutcome(&sim)) {
            printf("the stage ended after %d ticks\n", i);
            report(&game, &sim, "at the end");
            return 0;
        }
    }
    printf("FOUR THOUSAND TICKS AND THE STAGE HAS NOT ENDED\n");
    report(&game, &sim, "stuck");
    return 1;
}
