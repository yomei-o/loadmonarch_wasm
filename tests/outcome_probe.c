/* Why a stage with only one country left does not end.
 *
 *   tests/outcome_probe.exe [zip] [map] [ticks]
 *
 * 0041f4c0 counts the countries whose flag word has 0x40, 1 AND 0x10 - all
 * three - and wants three of them before it calls a stage over.  This plays a
 * map until nobody but one country has anything left, prints every country's
 * flags, and then watches any leader that is marked dying but never finishes.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/host.h"
#include "../src/sim.h"
#include "../src/state.h"
#include "../src/world.h"

int main(int argc, char **argv) {
    const char *archive = argc > 1 ? argv[1] : "ds7e.zip";
    const char *map = argc > 2 ? argv[2] : "B_000.MAP";
    const long limit = argc > 3 ? atol(argv[3]) : 40000;

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

    long i;
    for (i = 0; i < limit; i++) {
        game.factions[sim.humanFaction].funds = 999999999u;   /* the cheat */
        simStep(&sim);
        int standing = 0;
        for (unsigned k = 0; k < PLAYABLE_FACTIONS; k++)
            if (game.factions[k].strength) standing++;
        if (standing <= 1) break;
        if (simStageOutcome(&sim)) break;
    }

    printf("%ld ticks, outcome %d\n", i, simStageOutcome(&sim));
    for (unsigned k = 0; k < PLAYABLE_FACTIONS; k++) {
        const Faction *c = &game.factions[k];
        printf("  country %u  flags %04x  %s%s%s  strength %u  cells %u  "
               "units %u  leader slot %u\n",
               k, c->flags,
               (c->flags & 0x40) ? "conquered" : "---------",
               (c->flags & 1) ? " leader-lost" : " -----------",
               (c->flags & 0x10) ? " defeated" : " --------",
               c->strength, c->at2c, c->entities, c->at0c);
    }

    /* Any leader that is dying and not getting on with it. */
    for (unsigned k = 0; k < PLAYABLE_FACTIONS; k++) {
        const Faction *c = &game.factions[k];
        if (!(c->flags & 0x40) || (c->flags & 1)) continue;
        if (c->at0c >= ENTITY_COUNT) continue;
        const unsigned slot = c->at0c;
        printf("  country %u's leader is slot %u; eight ticks of it:\n", k, slot);
        for (int t = 0; t < 8; t++) {
            const Entity *e = &game.entities[slot];
            printf("    flags %02x  at0e %u  at08 %u  at0d %02x  cursor %u\n",
                   e->flags, e->at0e, e->at08, e->at0d, sim.entityCursor);
            simStep(&sim);
        }
        printf("    country flags now %04x, outcome %d\n",
               game.factions[k].flags, simStageOutcome(&sim));
    }
    return 0;
}
