// Which cells have a unit standing on them, for aiming a screenshot.
#include <stdio.h>
#include <stdlib.h>
#include "../src/sim.h"
#include "../src/world.h"
#include "../src/host.h"
int main(int argc, char **argv) {
    const char *a = argc > 1 ? argv[1] : "ds7e.zip";
    FILE *f = fopen(a, "rb");
    fseek(f, 0, SEEK_END); long size = ftell(f); fseek(f, 0, SEEK_SET);
    unsigned char *zip = (unsigned char *)malloc((size_t)size);
    if (fread(zip, 1, (size_t)size, f) != (size_t)size) return 1;
    fclose(f);
    static Host host; hostUseZip(&host, zip, (unsigned)size);
    static GameState game; static Sim sim;
    char message[128];
    if (!worldLoadStage(&game.world, &host, argc > 2 ? argv[2] : "B_000.MAP",
                        message, sizeof message)) { printf("%s\n", message); return 1; }
    stateStartStage(&game);
    simInit(&sim, &game);
    simSeedLeaders(&sim);
    for (int i = 0; i < (argc > 3 ? atoi(argv[3]) : 40); i++) simStep(&sim);
    int shown = 0;
    for (unsigned r = 0; r < WORLD_GRID && shown < 12; r++)
        for (unsigned c = 0; c < WORLD_GRID && shown < 12; c++) {
            const WorldCell *cell = &game.world.cells[WORLD_INDEX(c, r)];
            if (cell->occupant >= CELL_NO_ENTITY) continue;
            const Entity *e = &game.entities[cell->occupant];
            printf("  %2u,%2u  unit %2u  faction %u  strength %u  at0d %02x\n",
                   c, r, cell->occupant, e->faction, e->at08, e->at0d);
            shown++;
        }
    return 0;
}
