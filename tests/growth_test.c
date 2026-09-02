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

    static const char *stages[] = {"B_003.MAP", "B_004.MAP", "B_006.MAP",
                                   "B_009.MAP", "B_103.MAP"};
    int failures = 0;
    for (unsigned s = 0; s < sizeof stages / sizeof stages[0]; s++) {
        static GameState game;
        char message[256];
        if (!worldLoadStage(&game.world, &host, stages[s], message,
                            sizeof message)) {
            printf("  FAIL %s: %s\n", stages[s], message);
            failures++;
            continue;
        }
        stateStartStage(&game);
        Sim sim;
        simInit(&sim, &game);
        simSeedLeaders(&sim);

        unsigned before[4], after[4];
        for (int i = 0; i < 4; i++) before[i] = held(&game, (unsigned)i);
        for (int i = 0; i < 4000; i++) simStep(&sim);
        for (int i = 0; i < 4; i++) after[i] = held(&game, (unsigned)i);

        int grew = 0;
        printf("  %-10s", stages[s]);
        for (int i = 0; i < 4; i++) {
            printf(" %u->%-4u", before[i], after[i]);
            if (after[i] > before[i]) grew++;
        }
        printf("  (%d of 4 grew)\n", grew);
        // Three of the four ought to be bigger after four thousand sweeps.  A
        // country that is boxed in or losing a war may not be, but three
        // standing still means the units are not working.
        if (grew < 3) {
            printf("  FAIL %s: only %d of the four countries grew\n",
                   stages[s], grew);
            failures++;
        }

        // And then they have to meet.  A stage that never resolves is not a
        // game: run it out and look for casualties and for somebody knocked
        // out of it.
        for (int i = 0; i < 60000; i++) simStep(&sim);
        unsigned losses = 0, out = 0;
        for (int i = 0; i < 4; i++) {
            losses += game.factions[i].at14;
            if (game.factions[i].flags & 0x40) out++;
        }
        printf("  %-10s after 64000: losses %u, %u knocked out\n",
               stages[s], losses, out);
        if (losses == 0) {
            printf("  FAIL %s: nobody ever fought\n", stages[s]);
            failures++;
        }
        if (out == 0) {
            printf("  FAIL %s: nobody was knocked out\n", stages[s]);
            failures++;
        }
        worldFree(&game.world);
    }
    printf(failures ? "%d growth check(s) failed\n" : "growth checks ok\n",
           failures);
    return failures ? 1 : 0;
}
