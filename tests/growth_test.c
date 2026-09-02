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

// Every stage the campaign lists, in its own order, and whether the four
// countries can be expected to find each other without a player.
//
// Two of them cannot.  "Saint Steed" and "Moon and Stars" put their countries
// in pockets of bare ground with scenery between, and scenery in the range
// 0x30 to 0x5f is cleared by order 7 and by nothing else.  Order 7 reaches a
// unit exactly two ways: 00401770 gives it to one that walks into a mine, and
// 00421d30 gives it to one 0041c8e0 has found a mine for - and 0041c8e0 looks
// for terrain 0x7a alone, of which those maps have none.  0041c410, the wide
// search, does not weigh scenery at all.  Every at0d assignment in the
// executable was read to be sure of this: a machine country never opens a way
// through scenery, so those two stages wait for the player, and a port whose
// countries dug their own way out would be the wrong one.
static const struct {
    const char *file;
    int meets;
} stages[] = {
    {"B_000.MAP", 1},   // Conqueror's trial
    {"B_003.MAP", 1},   // Backroad Euromap
    {"B_004.MAP", 1},   // Ancient Kingdom
    {"B_006.MAP", 1},   // Steel Brain
    {"S_201.MAP", 1},   // Candy Waltz
    {"B_104.MAP", 1},   // Strange Islands
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
        for (int i = 0; i < 4000; i++) simStep(&sim);
        for (int i = 0; i < 4; i++) after[i] = held(&game, (unsigned)i);

        int grew = 0;
        printf("  %-10s", stages[s].file);
        for (int i = 0; i < 4; i++) {
            printf(" %u->%-4u", before[i], after[i]);
            if (after[i] > before[i]) grew++;
        }
        printf("  (%d of 4 grew)\n", grew);
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
            printf("  %-10s is walled apart by scenery no country clears,"
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
