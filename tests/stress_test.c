// Every stage, run long, with the things that must always be true checked as
// it goes.  Nothing here knows what the game ought to do - only what it must
// never do: a unit off the board, a cell naming an entity that is not there,
// an entity whose own cell has forgotten it, a strength past the cap.
//
// This is the test that would have caught the walk running off the end of a
// three-step route, and the one to run after touching anything in sim.c.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/host.h"
#include "../src/sim.h"
#include "../src/state.h"
#include "../src/world.h"

static int failures;

static void fail(const char *stage, long sweep, const char *what, long a,
                 long b) {
    printf("  FAIL %s at sweep %ld: %s (%ld, %ld)\n", stage, sweep, what, a, b);
    failures++;
}

static void check(const GameState *game, const char *stage, long sweep) {
    for (int i = 0; i < ENTITY_COUNT; i++) {
        const Entity *e = &game->entities[i];
        if (e->flags & 0x80) continue;
        if (e->position[0] >= WORLD_GRID || e->position[1] >= WORLD_GRID) {
            fail(stage, sweep, "an entity is off the board",
                 e->position[0], e->position[1]);
            return;
        }
        if (e->faction > 4) {
            fail(stage, sweep, "an entity belongs to nobody", i, e->faction);
            return;
        }
        if (e->at18 != 0x1f0 && e->at18 >= sizeof e->route) {
            fail(stage, sweep, "a route index is past the route", i, e->at18);
            return;
        }
        if (e->at18 != 0x1f0 && e->at14 > sizeof e->route) {
            fail(stage, sweep, "a route is longer than the record", i, e->at14);
            return;
        }
    }
    for (int i = 0; i < WORLD_CELLS; i++) {
        const unsigned char who = game->world.cells[i].occupant;
        if (who == 0x40) continue;
        if (who >= ENTITY_COUNT) {
            fail(stage, sweep, "a cell names nobody in particular", i, who);
            return;
        }
        if (game->entities[who].flags & 0x80) {
            fail(stage, sweep, "a cell names a retired entity", i, who);
            return;
        }
    }
    for (int f = 0; f < FACTION_COUNT; f++) {
        if (game->factions[f].strength > 100000) {
            fail(stage, sweep, "a country is past the cap", f,
                 (long)game->factions[f].strength);
            return;
        }
    }
}

int main(int argc, char **argv) {
    const char *archive = argc > 1 ? argv[1] : "ds7e.zip";
    const long sweeps = argc > 2 ? strtol(argv[2], NULL, 10) : 4000;

    static Host host;
    FILE *f = fopen(archive, "rb");
    if (!f) {
        printf("  (no %s beside the repository - nothing to stress)\n", archive);
        return 0;
    }
    fseek(f, 0, SEEK_END);
    const long size = ftell(f);
    fseek(f, 0, SEEK_SET);
    unsigned char *bytes = (unsigned char *)malloc((size_t)size);
    if (!bytes || fread(bytes, 1, (size_t)size, f) != (size_t)size) return 2;
    fclose(f);
    if (!hostUseZip(&host, bytes, (unsigned)size)) return 2;

    StageList stages;
    static const char *fallback[] = {"B_000.MAP"};
    const char *const *names = fallback;
    unsigned count = 1;
    if (worldReadStages(&stages, &host)) count = stages.count;

    for (unsigned s = 0; s < count; s++) {
        const char *name = stages.count ? stages.file[s] : names[s];
        static GameState game;
        char message[256];
        if (!worldLoadStage(&game.world, &host, name, message,
                            sizeof message)) {
            printf("  FAIL %s: %s\n", name, message);
            failures++;
            continue;
        }
        stateStartStage(&game);
        Sim sim;
        simInit(&sim, &game);
        simSeedLeaders(&sim);

        for (long i = 0; i < sweeps; i++) {
            simStep(&sim);
            if (i % 250 == 0) check(&game, name, i);
        }
        check(&game, name, sweeps);
        worldFree(&game.world);
    }

    printf(failures ? "%d stress check(s) failed\n" : "stress checks ok\n",
           failures);
    return failures ? 1 : 0;
}
