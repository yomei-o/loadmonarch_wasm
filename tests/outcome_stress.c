/* Does a stage always end once one country is left standing?
 *
 *   tests/outcome_stress.exe [zip] [ticks per map]
 *
 * 0041f4c0 wants three countries with 0x40, 1 AND 0x10 in their flag word.
 * A country can lose everything and still be missing one of those bits, and
 * then the war runs on with nobody to fight - which is what "all the enemies
 * are gone and the map keeps going" is.  This plays every map to that point
 * and gives the stage two hundred more ticks to notice.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/host.h"
#include "../src/sim.h"
#include "../src/state.h"
#include "../src/world.h"

static int failures;

int main(int argc, char **argv) {
    const char *archive = argc > 1 ? argv[1] : "ds7e.zip";
    const long limit = argc > 2 ? atol(argv[2]) : 20000;

    FILE *f = fopen(archive, "rb");
    if (!f) { printf("cannot open %s\n", archive); return 1; }
    fseek(f, 0, SEEK_END); long size = ftell(f); fseek(f, 0, SEEK_SET);
    unsigned char *zip = (unsigned char *)malloc((size_t)size);
    if (!zip || fread(zip, 1, (size_t)size, f) != (size_t)size) return 1;
    fclose(f);
    static Host host;
    if (!hostUseZip(&host, zip, (unsigned)size)) { printf("not a zip\n"); return 1; }

    static StageList stages;
    if (!worldReadStages(&stages, &host)) { printf("no stage list\n"); return 1; }

    for (unsigned s = 0; s < stages.count; s++) {
        static GameState game;
        char message[256];
        if (!worldLoadStage(&game.world, &host, stages.file[s], message,
                            sizeof message)) {
            printf("  %-14s %s\n", stages.file[s], message);
            continue;
        }
        stateStartStage(&game);
        static Sim sim;
        simInit(&sim, &game);
        simSeedLeaders(&sim);

        long i;
        int alone = -1;
        for (i = 0; i < limit; i++) {
            game.factions[sim.humanFaction].funds = 999999999u;
            simStep(&sim);
            if (simStageOutcome(&sim)) break;
            int standing = 0;
            for (unsigned k = 0; k < PLAYABLE_FACTIONS; k++)
                if (game.factions[k].strength) standing++;
            if (standing <= 1 && alone < 0) alone = (int)i;
            /* Two hundred ticks after the last one fell is plenty: a leader
             * marked dying needs four. */
            if (alone >= 0 && i > alone + 200) break;
        }
        const int outcome = simStageOutcome(&sim);
        int standing = 0;
        for (unsigned k = 0; k < PLAYABLE_FACTIONS; k++)
            if (game.factions[k].strength) standing++;
        printf("%-14s %6ld ticks  outcome %d  standing %d", stages.file[s], i,
               outcome, standing);
        if (!outcome && standing <= 1) {
            printf("   <- STUCK");
            failures++;
            for (unsigned k = 0; k < PLAYABLE_FACTIONS; k++) {
                const Faction *c = &game.factions[k];
                printf("\n    country %u flags %04x strength %u units %u "
                       "cells %u leader %u", k, c->flags, c->strength,
                       c->entities, c->at2c, c->at0c);
                if (c->at0c < ENTITY_COUNT) {
                    const Entity *e = &game.entities[c->at0c];
                    printf(" [flags %02x at0e %u at0d %02x]",
                           e->flags, e->at0e, e->at0d);
                }
            }
        }
        printf("\n");
    }
    printf(failures ? "%d stage(s) stuck\n" : "no stage got stuck\n", failures);
    return failures ? 1 : 0;
}
