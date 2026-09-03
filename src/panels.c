// The three windows the game opens beside the board: Unit, Progress and Graph.
//
// They are dialogs 105, 114 and 121 in the resources, and every one of them
// has no controls at all - the program draws their insides itself.  The first
// two draw from the interface sheet, which carries a 176-wide panel apiece:
// rows 112 to 287 are the Unit Window and 288 to 463 the Progress Window,
// measured by assembling them until the border closed and every fitting landed
// in a slot.  The Graph Window has no picture: 00404e40 writes eight lines of
// text down each of two columns and a total under them, which is why looking
// for its background on the sheet never turned anything up.
//
// They were drawn on the page in HTML until now.  That got the numbers right
// and the feel wrong.
#include "panels.h"

#include "font.h"
#include "ui.h"

#include <stdio.h>
#include <string.h>

#define PANEL_W 176
#define PANEL_H 176
#define UNIT_TOP 112
#define PROGRESS_TOP 288

// One rectangle of the sheet.  `keep` non-zero draws every pixel, which is
// what a panel's own background wants - it is a window, and the board does not
// show through a window.  Zero leaves the transparent index out, which is what
// the fittings drawn on top of it want.
static void blitSheetPart(Surface *out, const World *world, int sx, int sy,
                          int w, int h, int dx, int dy, int keep);

static void blitSheet(Surface *out, const World *world, int sx, int sy,
                      int w, int h, int dx, int dy) {
    blitSheetPart(out, world, sx, sy, w, h, dx, dy, 0);
}

static void blitPanel(Surface *out, const World *world, int sx, int sy,
                      int w, int h, int dx, int dy) {
    blitSheetPart(out, world, sx, sy, w, h, dx, dy, 1);
}

static void blitSheetPart(Surface *out, const World *world, int sx, int sy,
                          int w, int h, int dx, int dy, int keep) {
    const UiSheet *ui = &world->ui;
    if (!ui->pixels) return;
    for (int y = 0; y < h; y++) {
        const int py = dy + y;
        if (py < 0 || py >= out->height) continue;
        if (sy + y < 0 || sy + y >= UI_SHEET_H) continue;
        unsigned char *row = out->pixels + (size_t)py * out->width;
        for (int x = 0; x < w; x++) {
            const int px = dx + x;
            if (px < 0 || px >= out->width) continue;
            const unsigned char v =
                ui->pixels[(size_t)(sy + y) * UI_SHEET_W + sx + x];
            if (!keep && v == UI_TRANSPARENT) continue;
            row[px] = v;
        }
    }
}

// 00426900's gauge: up to thirty pieces of eight by sixteen taken from row
// (n / 10 + 4) * 16, column (n % 10) * 8 - three rows of ten on the sheet,
// blue then green then yellow, so a full bar changes colour as it fills.
static void blitGauge(Surface *out, const World *world, int n, int dx,
                      int dy) {
    for (int i = 0; i < n && i < 30; i++)
        blitSheet(out, world, (i % 10) * 8, (i / 10 + 4) * 16, 8, 16,
                  dx + (i % 10) * 8, dy + (i / 10) * 16);
}

void panelUnitWindow(Surface *out, const GameState *game, int x, int y,
                     int terrain, unsigned value) {
    const World *w = &game->world;
    blitPanel(out, w, 0, UNIT_TOP, PANEL_W, PANEL_H, x, y);
    if (terrain < 0) return;

    // The cell's own tile at the large size, where 00426900 puts it.
    const TileBank *bank = worldBank(w, 2);
    if (bank && bank->pixels && (unsigned)terrain < bank->tiles) {
        const int ts = bank->tileSize;
        const unsigned char *src =
            bank->pixels + (size_t)terrain * (size_t)ts * ts;
        for (int j = 0; j < ts; j++) {
            const int py = y + 112 + j;
            if (py < 0 || py >= out->height) continue;
            unsigned char *row = out->pixels + (size_t)py * out->width;
            for (int i = 0; i < ts; i++) {
                const int px = x + 16 + i;
                if (px < 0 || px >= out->width) continue;
                row[px] = src[(size_t)j * ts + i];
            }
        }
    }

    renderNumber(w, UI_FONT_LARGE_WHITE, x + 152, y + 120, value, out);
    const unsigned over = (terrain >= 8 && terrain < 12) ? 0x90u : 0xffu;
    int n = (int)(value * 30u / (over ? over : 1u));
    if (n > 10) n = 10;                 // the slot the panel leaves is one row
    blitGauge(out, w, n, x + 72, y + 96);
}

void panelProgressWindow(Surface *out, const GameState *game, unsigned faction,
                         unsigned days, unsigned daysLeft, int x, int y) {
    const World *w = &game->world;
    blitPanel(out, w, 0, PROGRESS_TOP, PANEL_W, PANEL_H, x, y);
    if (faction >= FACTION_COUNT) return;

    // The bar at the top is two rows in one frame: an empty one above and a
    // full gradient below it.  Filling it means copying the gradient's first N
    // pixels up into the empty row, so it changes colour as it grows.  What it
    // measures is not written anywhere; the share of the board is the reading
    // that suits a window called Progress and the one this port has exactly.
    // area is a percentage to two decimals, so a hundred per cent is 100.0
    // and the whole bar is a hundred and twenty-eight pixels.
    int filled = (int)(game->factions[faction].area * 128.0f / 100.0f);
    if (filled < 0) filled = 0;
    if (filled > 128) filled = 128;
    if (filled > 0)
        blitSheet(out, w, 24, PROGRESS_TOP + 26, filled, 6, x + 24, y + 16);

    renderNumber(w, UI_FONT_LARGE_WHITE, x + 80, y + 40,
                 game->factions[faction].funds, out);
    renderNumber(w, UI_FONT_LARGE_WHITE, x + 144, y + 40,
                 game->factions[faction].taxRate, out);
    renderNumber(w, UI_FONT_LARGE_WHITE, x + 80, y + 104, days, out);
    renderNumber(w, UI_FONT_LARGE_WHITE, x + 144, y + 104, daysLeft, out);
}

// 00404e40's own lines, in its own words and its own order: two columns of
// eight, a country to every pair of rows, and a total under them.
void panelGraphWindow(Surface *out, const GameState *game, int x, int y,
                      int w, int h) {
    // No picture of its own, so it gets the plain window a dialog with no
    // controls would have.
    for (int j = 0; j < h; j++) {
        const int py = y + j;
        if (py < 0 || py >= out->height) continue;
        unsigned char *row = out->pixels + (size_t)py * out->width;
        for (int i = 0; i < w; i++) {
            const int px = x + i;
            if (px >= 0 && px < out->width) row[px] = (unsigned char)UI_FACE;
        }
    }

    char line[80];
    unsigned total = 0;
    for (unsigned f = 0; f < PLAYABLE_FACTIONS; f++) {
        const char *name = worldCountryName(&game->world, f);
        const Faction *c = &game->factions[f];
        const int row = (int)f * 40;
        if (c->flags & 0x40) {
            snprintf(line, sizeof line, "%s Defeated", name);
            fontDrawText(out, x + 6, y + 4 + row, (unsigned char)UI_DARK, line);
            continue;
        }
        snprintf(line, sizeof line, "%s Area Occupied: %d.%02d", name,
                 (int)c->area, (int)((c->area - (int)c->area) * 100.0f));
        fontDrawText(out, x + 6, y + 4 + row, (unsigned char)UI_DARK, line);
        snprintf(line, sizeof line, "%s Funds: %u", name, c->funds);
        fontDrawText(out, x + 6, y + 22 + row, (unsigned char)UI_DARK, line);

        const unsigned leader = c->at0c < ENTITY_COUNT
            ? game->entities[c->at0c].at08 : 0u;
        snprintf(line, sizeof line, "%s Leader Strength: %u", name, leader);
        fontDrawText(out, x + w / 2, y + 4 + row, (unsigned char)UI_DARK, line);
        snprintf(line, sizeof line, "%s Unit Totals: %u", name, c->strength);
        fontDrawText(out, x + w / 2, y + 22 + row, (unsigned char)UI_DARK,
                     line);
        total += c->strength;
    }
    snprintf(line, sizeof line, "Unit and Base Totals: %u", total);
    fontDrawText(out, x + 6, y + h - 20, (unsigned char)UI_DARK, line);
}
