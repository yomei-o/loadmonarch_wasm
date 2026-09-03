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

// One pixel off the interface sheet, for the times a fitting wants a colour
// the sheet already has rather than one named here.
static unsigned char sheetPixel(const World *world, int sx, int sy) {
    const UiSheet *ui = &world->ui;
    if (!ui->pixels || sx < 0 || sy < 0 || sx >= UI_SHEET_W || sy >= UI_SHEET_H)
        return 0;
    return ui->pixels[(size_t)sy * UI_SHEET_W + sx];
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

/* --------------------------------------------------- 0041a1b0's two strips */

// Both run from x 24 to x 148 and answer nought to thirty, and the reading is
// the original's own: clamp, take a hundred and twenty-four of it, divide by
// four, cap at thirty.
#define SLIDER_X0 24
#define SLIDER_SPAN 124
#define SLIDER_MAX 30

// Both strips are built the same way: a well sixteen rows deep, black but for
// a line four rows through the middle of it that runs the whole width - the
// tax's shading from grey through orange to red, the clock's plain yellow.
// There is no thumb anywhere on the sheet, so the line is not a scale to put a
// marker on: it is the bar itself, drawn full and then blacked back to the
// value.  Which is why the art as it sits is the strip at thirty.
// The well itself is a hair wider than the range the mouse is read over: it
// runs x 24 to 151, a hundred and twenty-eight across, where 0041a1b0's clamp
// only reaches 124.  So the bar is drawn over the well and read over the clamp.
#define BAR_W 128

#define TAX_LINE 22
#define SPEED_LINE 150
#define LINE_H 4

static int clampSlider(int v) {
    return v < 0 ? 0 : v > SLIDER_MAX ? SLIDER_MAX : v;
}

// Black out the line from the value to the right-hand end of it, in whatever
// black the well around it is drawn in - taken from the well rather than named
// here, so it stays the sheet's own colour.
//
// The clock's line has the two figures standing on it, one at either end, and
// the line runs behind them: blacking the tail out flat would cut the runner
// off at the knees.  So that one is given the colour of its line and rubs out
// only what is that colour.  The tax's rows have nothing on them, so it passes
// -1 and the whole tail goes.
static void barTail(Surface *out, const World *w, int x, int lineY, int wellY,
                    int onlyColour, int value) {
    // Sampled from the middle of the well, because both ends of the clock's
    // have a figure standing in them.
    const unsigned char black = sheetPixel(w, SLIDER_X0 + BAR_W / 2, wellY);
    const int from = x + SLIDER_X0 +
        (value * BAR_W + SLIDER_MAX - 1) / SLIDER_MAX;
    const int to = x + SLIDER_X0 + BAR_W;
    for (int j = 0; j < LINE_H; j++) {
        const int py = lineY + j;
        if (py < 0 || py >= out->height) continue;
        unsigned char *row = out->pixels + (size_t)py * out->width;
        for (int px = from; px < to; px++) {
            if (px < 0 || px >= out->width) continue;
            if (onlyColour >= 0 && row[px] != (unsigned char)onlyColour)
                continue;
            row[px] = black;
        }
    }
}

static int sliderValue(int px) {
    int at = px - SLIDER_X0;
    if (at < 0) at = 0;
    if (at > SLIDER_SPAN) at = SLIDER_SPAN;
    at /= 4;
    return at > SLIDER_MAX ? SLIDER_MAX : at;
}

PanelSlider panelProgressSlider(int px, int py, int *value) {
    // 0041a1b0's hit areas are looser than the strips it draws: y 16 to 32 for
    // the one and 144 to 160 for the other.
    if (px < SLIDER_X0 - 8 || px > SLIDER_X0 + SLIDER_SPAN + 8)
        return PANEL_SLIDER_NONE;
    if (py >= 16 && py <= 32) {
        if (value) *value = sliderValue(px);
        return PANEL_SLIDER_TAX;
    }
    if (py >= 144 && py <= 160) {
        if (value) *value = sliderValue(px);
        return PANEL_SLIDER_SPEED;
    }
    return PANEL_SLIDER_NONE;
}

void panelProgressWindow(Surface *out, const GameState *game, unsigned faction,
                         unsigned days, unsigned daysLeft, int speed,
                         int x, int y) {
    const World *w = &game->world;
    blitPanel(out, w, 0, PROGRESS_TOP, PANEL_W, PANEL_H, x, y);
    if (faction >= FACTION_COUNT) return;

    // Both bars come up full with the panel, so showing a value means blacking
    // out what is past it.  Rounding up, so that thirty fills the line and
    // nought leaves nothing of it.
    barTail(out, w, x, y + TAX_LINE, PROGRESS_TOP + TAX_LINE - 4, -1,
            clampSlider(game->factions[faction].taxRate));
    barTail(out, w, x, y + SPEED_LINE, PROGRESS_TOP + SPEED_LINE - 4,
            sheetPixel(w, SLIDER_X0 + BAR_W / 2, PROGRESS_TOP + SPEED_LINE),
            clampSlider(speed));

    renderNumber(w, UI_FONT_LARGE_WHITE, x + 80, y + 40,
                 game->factions[faction].funds, out);
    // The tax box comes with a per cent sign already printed in it, at x 136
    // to 143, so the number stops short of that rather than being written over
    // it - which also settles what the rate is measured in.
    renderNumber(w, UI_FONT_LARGE_WHITE, x + 136, y + 40,
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

    // 00404e40 writes four things per country - "%s Area Occupied: %3.2f",
    // "%s Funds: %d", "%s Leader Strength: %d" and "%s Unit and Base Totals:
    // %d" - into a window the player sizes and drags, so it can afford two
    // columns of full sentences.  This one lives in a column a hundred and
    // seventy-six across, which is twenty-two characters of the half-width
    // font, so the same four numbers go under each name as a row instead.
    // The leader's strength is deliberately not part of the total, as in the
    // original.
    char line[80];
    unsigned total = 0;
    int at = y + 4;
    fontDrawText(out, x + 6, at, (unsigned char)UI_DARK,
                 "Area%   Funds  Units");
    at += 16;
    for (unsigned f = 0; f < PLAYABLE_FACTIONS; f++) {
        if (at + 32 > y + h) break;                 // no room for another
        const char *name = worldCountryName(&game->world, f);
        const Faction *c = &game->factions[f];
        const unsigned leader = c->at0c < ENTITY_COUNT
            ? game->entities[c->at0c].at08 : 0u;
        if (c->flags & 0x40) {
            snprintf(line, sizeof line, "%s Defeated", name);
            fontDrawText(out, x + 6, at, (unsigned char)UI_DARK, line);
            at += 16;
            continue;
        }
        snprintf(line, sizeof line, "%s (K %u)", name, leader);
        fontDrawText(out, x + 6, at, (unsigned char)UI_DARK, line);
        snprintf(line, sizeof line, "%2d.%02d %6u %6u", (int)c->area,
                 (int)((c->area - (int)c->area) * 100.0f), c->funds,
                 c->strength);
        fontDrawText(out, x + 6, at + 16, (unsigned char)UI_DARK, line);
        at += 34;
        total += c->strength;
    }

}
