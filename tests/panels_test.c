// The Unit Window, against what 00426900 does.
//
//   tests/panels_test.exe [zip]
//
// The window has two halves: the unit standing on the cell under the cursor
// (its sprite, a gauge of its strength, "STR  %6d" and its own order) and the
// cell itself (its tile, a gauge of its worth, "NUM/DEF  %6d" and the order a
// new unit would take).  Every one of those lands in a slot of its own, and
// the gauge is one row of ten whose colour cycles - which is the part the port
// had wrong, so it is the part worth a test.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/font.h"
#include "../src/host.h"
#include "../src/panels.h"
#include "../src/render.h"
#include "../src/sim.h"
#include "../src/state.h"
#include "../src/ui.h"
#include "../src/world.h"

static int failures;

static void check(int ok, const char *what) {
    if (!ok) { printf("FAIL  %s\n", what); failures++; }
}

static void checkf(int ok, const char *fmt, int a, int b) {
    if (!ok) { printf("FAIL  "); printf(fmt, a, b); printf("\n"); failures++; }
}

// How many pixels in a sixteen-row band are neither the panel's own colours
// nor its background - which is what text and gauge pieces are.
static int inked(const Surface *s, int x, int y, int w, unsigned char ink) {
    int n = 0;
    for (int j = 0; j < 16 && y + j < s->height; j++)
        for (int i = 0; i < w && x + i < s->width; i++)
            if (s->pixels[(size_t)(y + j) * s->width + x + i] == ink) n++;
    return n;
}

// The gauge's pieces are eight wide; a cell is filled when its middle row
// carries anything but what the empty slot carries.
static int gaugeCells(const Surface *s, int x, int y, unsigned char empty) {
    int n = 0;
    for (int i = 0; i < 10; i++) {
        const unsigned char v =
            s->pixels[(size_t)(y + 8) * s->width + x + i * 8 + 4];
        if (v != empty) n++;
    }
    return n;
}

int main(int argc, char **argv) {
    const char *archive = argc > 1 ? argv[1] : "ds7e.zip";
    FILE *f = fopen(archive, "rb");
    if (!f) { printf("FAIL  cannot open %s\n", archive); return 1; }
    fseek(f, 0, SEEK_END); long size = ftell(f); fseek(f, 0, SEEK_SET);
    unsigned char *zip = (unsigned char *)malloc((size_t)size);
    if (!zip || fread(zip, 1, (size_t)size, f) != (size_t)size) return 1;
    fclose(f);
    static Host host;
    if (!hostUseZip(&host, zip, (unsigned)size)) {
        printf("FAIL  %s is not a zip this port can read\n", archive);
        return 1;
    }

    static GameState game;
    char message[256];
    if (!worldLoadStage(&game.world, &host, "B_000.MAP", message,
                        sizeof message)) {
        printf("FAIL  B_000.MAP: %s\n", message);
        return 1;
    }
    stateStartStage(&game);
    static Sim sim;
    simInit(&sim, &game);
    simSeedLeaders(&sim);

    static Surface surface;
    static unsigned char pixels[240 * 240];
    surfaceInit(&surface, 240, 240, pixels);
    const unsigned char ink = fontInk(&game.world, UI_FONT_LARGE_WHITE);

    WorldCell cell;
    memset(&cell, 0, sizeof cell);
    cell.terrain = 1;                   // not 8 to 11: measured against 0xff
    cell.value = 255;
    cell.cost = 0x1f0;                  // no way there
    cell.occupant = CELL_NO_ENTITY;

    // No unit: the two upper slots stay empty and the third reads the cell's
    // distance instead of an order.
    memset(pixels, 0, sizeof pixels);
    panelUnitWindow(&surface, &game, 0, 0, &cell, 1u, CELL_NO_ENTITY);
    check(inked(&surface, 64, 40, 96, ink) == 0,
          "with no unit there is no strength line");
    check(gaugeCells(&surface, 72, 16,
                     pixels[(size_t)24 * surface.width + 72 + 4]) == 0,
          "and no strength gauge");
    checkf(inked(&surface, 64, 64, 96, ink) > 20,
           "\"DIS. -----\" has %d pixels, wanted over %d",
           inked(&surface, 64, 64, 96, ink), 20);

    // The cell's own half: 255 out of 0xff is thirty pieces, which is the cap.
    // Drawing it empty and full and comparing says where the gauge is allowed
    // to be - one row of sixteen at y = 96, and nowhere else.  Three rows of
    // ten, which is what the port drew, fails this.
    {
        static unsigned char full[240 * 240];
        memcpy(full, pixels, sizeof full);
        WorldCell bare = cell;
        bare.value = 0;
        memset(pixels, 0, sizeof pixels);
        panelUnitWindow(&surface, &game, 0, 0, &bare, 1u, CELL_NO_ENTITY);
        // The gauge's own sixteen rows have to move, and the sixteen below
        // them - where three rows of ten put the second one - must not.  The
        // number at y = 120 moves too, which is why the band between them is
        // what this looks at.
        int within = 0, below = 0;
        for (int j = 0; j < 176; j++) {
            int differs = 0;
            for (int i = 64; i < 176; i++)
                if (full[(size_t)j * surface.width + i] !=
                    pixels[(size_t)j * surface.width + i]) differs = 1;
            if (!differs) continue;
            if (j >= 96 && j < 112) within++;
            if (j >= 112 && j < 120) below++;
        }
        checkf(within > 8, "the gauge moved %d of its %d rows", within, 16);
        checkf(below == 0, "%d rows below it moved as well, wanted %d",
               below, 0);
        memcpy(pixels, full, sizeof full);
    }
    checkf(inked(&surface, 64, 120, 96, ink) > 20,
           "\"DEF    255\" has %d pixels, wanted over %d",
           inked(&surface, 64, 120, 96, ink), 20);
    checkf(inked(&surface, 64, 144, 96, ink) > 10,
           "the pending order's name has %d pixels, wanted over %d",
           inked(&surface, 64, 144, 96, ink), 10);

    // A unit on the cell: the upper half fills in, and the third slot is its
    // order rather than the distance.
    {
        int slot = -1;
        for (unsigned i = 0; i < ENTITY_COUNT; i++)
            if (game.entities[i].at08 >= 1000u &&
                !(game.entities[i].flags & 0x80u)) { slot = (int)i; break; }
        check(slot >= 0, "the stage has a unit over a thousand strong");
        if (slot >= 0) {
            memset(pixels, 0, sizeof pixels);
            cell.occupant = (unsigned char)slot;
            panelUnitWindow(&surface, &game, 0, 0, &cell, 1u, slot);
            checkf(inked(&surface, 64, 40, 96, ink) > 20,
                   "\"STR\" has %d pixels, wanted over %d",
                   inked(&surface, 64, 40, 96, ink), 20);
            checkf(inked(&surface, 64, 64, 96, ink) > 10,
                   "its order has %d pixels, wanted over %d",
                   inked(&surface, 64, 64, 96, ink), 10);
            // Over a thousand strong: the gauge is past its first ten, so the
            // leftmost cells are the second row's colour and there are eleven
            // pieces in all - which one row of ten can only show as ten.
            checkf(gaugeCells(&surface, 72, 16, 0) == 10,
                   "the strength gauge shows %d cells, wanted %d",
                   gaugeCells(&surface, 72, 16, 0), 10);
            // The sprite went in the box at (16,48).
            int any = 0;
            for (int j = 48; j < 80 && !any; j++)
                for (int i = 16; i < 48; i++)
                    if (pixels[(size_t)j * surface.width + i]) { any = 1; break; }
            check(any, "its sprite is in the box above the tile");
        }
    }

    if (failures) { printf("%d failure(s)\n", failures); return 1; }
    printf("panels checks ok\n");
    return 0;
}
