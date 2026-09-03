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

/* ------------------------------- 0041a1b0, 0041a3d0 and 00419ab0's strips */

// Every marker in this window is an eight by sixteen sprite off the top row of
// the interface sheet, laid on its strip with 0x70 left out, and every one of
// them sits at x = 24 + value * 4 - which is why 0041a1b0 reads a drag back
// with a divide by four.  There is no widget here and no bar to fill: the
// strips are art and so are the markers.
#define MARK_W 8
#define MARK_H 16
#define MARK_TAX_AUTO 96        // a blue piece: where the tax would settle
#define MARK_TAX_HAND 104       // a gold crown: where the player has put it
#define MARK_SPEED 112          // the clock's weight
#define MARK_CLOCK 120          // eight frames of a turning clock

#define SLIDER_X0 24            // 0x18, where all three strips start
#define SLIDER_MAX 30           // 0x1e, what 0041a1b0 caps a drag at
#define TAX_ROW 16              // 0x10
#define CLOCK_ROW 80            // 0x50
#define SPEED_ROW 144           // 0x90
#define CLOCK_SPAN 120          // 0x78, the clock's own range - pixels, not steps

// The scales, which 0041a3d0 treats as a button: x 0x60 to 0x70, y 0x28 to
// 0x38.
#define SCALES_X0 96
#define SCALES_X1 112
#define SCALES_Y0 40
#define SCALES_Y1 56

static int clampSlider(int v) {
    return v < 0 ? 0 : v > SLIDER_MAX ? SLIDER_MAX : v;
}

// 0041a1b0: clamp x into 0x18 to 0xdc, take 0x18 off it, cap the rest at 0x7c,
// divide by four - signed, so it rounds toward zero - and cap at thirty.
static int sliderValue(int px) {
    if (px < SLIDER_X0) px = SLIDER_X0;
    if (px > 0xdc) px = 0xdc;
    int at = px - SLIDER_X0;
    if (at > 0x7c) at = 0x7c;
    if (at < 0) at = 0;
    at /= 4;
    return at > SLIDER_MAX ? SLIDER_MAX : at;
}

PanelSlider panelProgressSlider(int px, int py, int *value) {
    // 0041a3d0's button comes first, because it sits inside no strip.
    if (px >= SCALES_X0 && px < SCALES_X1 && py > SCALES_Y0 && py < SCALES_Y1)
        return PANEL_SLIDER_AUTOTAX;
    // 0041a1b0's own two: x from 0x18 to a little past the strip, and the two
    // sixteen-pixel bands the strips sit in.
    if (px < SLIDER_X0 || px > 0x93) return PANEL_SLIDER_NONE;
    if (py >= TAX_ROW && py <= TAX_ROW + 0x10) {
        if (value) *value = sliderValue(px);
        return PANEL_SLIDER_TAX;
    }
    if (py >= SPEED_ROW && py <= SPEED_ROW + 0x10) {
        if (value) *value = sliderValue(px);
        return PANEL_SLIDER_SPEED;
    }
    return PANEL_SLIDER_NONE;
}

// 00419ab0's own sum, which is 0041dc60's: twenty per cent less a hundredth of
// the purse, and nothing at all once the purse is past 0x1400 - or past 0xffff,
// where it stops looking.
int panelAutoTaxRate(const GameState *game, unsigned faction) {
    if (faction >= FACTION_COUNT) return 0;
    const unsigned funds = game->factions[faction].funds;
    if (funds >= 0xffffu) return 0;
    const unsigned high = (funds >> 8) & 0xffu;
    return high > 0x14u ? 0 : (int)(0x14u - high);
}

// One marker, from the top of the sheet onto a strip.
static void mark(Surface *out, const World *w, int sheetX, int dx, int dy) {
    blitSheet(out, w, sheetX, 0, MARK_W, MARK_H, dx, dy);
}

void panelProgressWindow(Surface *out, const GameState *game, unsigned faction,
                         unsigned days, unsigned daysLeft, int speed,
                         unsigned frame, int x, int y) {
    const World *w = &game->world;
    blitPanel(out, w, 0, PROGRESS_TOP, PANEL_W, PANEL_H, x, y);
    if (faction >= FACTION_COUNT) return;

    // The tax strip carries two markers: where the tax would settle if nobody
    // touched it, and where the player has put it.  Both at x = 24 + rate * 4.
    mark(out, w, MARK_TAX_AUTO,
         x + SLIDER_X0 + clampSlider(panelAutoTaxRate(game, faction)) * 4,
         y + TAX_ROW);
    mark(out, w, MARK_TAX_HAND,
         x + SLIDER_X0 + clampSlider(game->factions[faction].taxRate) * 4,
         y + TAX_ROW);

    // And the clock strip one, the same way.
    mark(out, w, MARK_SPEED, x + SLIDER_X0 + clampSlider(speed) * 4,
         y + SPEED_ROW);

    // The middle strip is the stage's own clock: 00419ab0 puts the marker at
    // days left over the whole allowance, a hundred and twenty pixels across,
    // so it starts at the right and walks left as the time goes.  It turns as
    // it walks, eight frames off the same row of the sheet.
    {
        const unsigned total = days + daysLeft;
        int at = total ? (int)((unsigned long long)daysLeft * CLOCK_SPAN /
                               total) : CLOCK_SPAN;
        if (at < 0) at = 0;
        if (at > CLOCK_SPAN) at = CLOCK_SPAN;
        mark(out, w, MARK_CLOCK + (int)(frame & 7u) * MARK_W,
             x + SLIDER_X0 + at, y + CLOCK_ROW);
    }

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

/* ----------------------------------------- 0041d460 and 0041d220: a country */

// The window is a two by four grid of thirty-two pixel pictures with a number
// beside each, and both halves come straight out of the two routines.
//
// 0041d460 lays the pictures: tile 0xe0 + country * 8 + i of the large sprite
// bank - the 0x40000 buffer at DAT_00436440, which is C_%03dl1 to l4 merged -
// at x = 16 + (i & 1) * 32 and y = 16 + (i / 2) * 40.  The second one is the
// exception: a country with an ally shows the ally's flag there instead of its
// own, which is what +0x1e names when it is not 0x80.  Then the country's name
// at 4, 2.
//
// 0041d220 writes the numbers, all at x 100 but the area at 84, in this order
// down the window - and they line up with the pictures beside them: the king
// with his own strength, the flag with the ground, the soldiers with the
// army, the villages with the land, and the last two with the money.
#define COUNTRY_TILE 0xe0
#define COUNTRY_TILES 8
#define COUNTRY_TILE_X 16
#define COUNTRY_TILE_Y 16
#define COUNTRY_ROW_H 40
#define COUNTRY_NUM_X 100
#define COUNTRY_AREA_X 84

// One thirty-two pixel picture off the large sprite bank, opaquely - a
// picture is a picture and 0x70 does not appear inside these.
static void blitTile(Surface *out, const TileBank *bank, unsigned index,
                     int dx, int dy) {
    if (!bank->pixels || bank->tileSize <= 0 || index >= bank->tiles) return;
    const int ts = bank->tileSize;
    const unsigned char *src = bank->pixels + (size_t)index * ts * ts;
    for (int y = 0; y < ts; y++) {
        const int py = dy + y;
        if (py < 0 || py >= out->height) continue;
        unsigned char *row = out->pixels + (size_t)py * out->width;
        for (int x = 0; x < ts; x++) {
            const int px = dx + x;
            if (px < 0 || px >= out->width) continue;
            const unsigned char v = src[(size_t)y * ts + x];
            if (v == UI_TRANSPARENT) continue;
            row[px] = v;
        }
    }
}

void panelCountryWindow(Surface *out, const GameState *game, unsigned faction,
                        int x, int y) {
    if (faction >= PLAYABLE_FACTIONS) return;
    const World *w = &game->world;
    const TileBank *bank = worldSprites(w, 2);      // the thirty-two pixel set
    const Faction *c = &game->factions[faction];

    for (unsigned i = 0; i < COUNTRY_TILES; i++) {
        unsigned tile = COUNTRY_TILE + faction * COUNTRY_TILES + i;
        // The flag: an ally's when there is one.  +0x1e is 0x80 when there is
        // not, which is what 004273f0 leaves it at.
        if (i == 1 && c->at1e != 0x80 && c->at1e < PLAYABLE_FACTIONS)
            tile = COUNTRY_TILE + 1u + c->at1e * COUNTRY_TILES;
        blitTile(out, bank, tile,
                 x + COUNTRY_TILE_X + (int)(i & 1u) * 32,
                 y + COUNTRY_TILE_Y + (int)(i / 2u) * COUNTRY_ROW_H);
    }

    const unsigned char ink = fontInk(w, UI_FONT_LARGE_WHITE);
    const char *name = worldCountryName(w, faction);
    if (name && *name) fontDrawText(out, x + 4, y + 2, ink, name);

    // 0041d220's eight, in its order.  The king's is nought when the country
    // has lost him, which is what the routine's own bounds test says.
    const unsigned king = c->at0c < ENTITY_COUNT
        ? game->entities[c->at0c].at08 : 0u;
    char line[24];
    static const int kRowY[8] = { 16, 32, 56, 72, 96, 112, 136, 152 };
    for (unsigned i = 0; i < 8; i++) {
        int at = x + COUNTRY_NUM_X;
        switch (i) {
        case 0: snprintf(line, sizeof line, "%u", king); break;
        case 1:
            at = x + COUNTRY_AREA_X;
            snprintf(line, sizeof line, "%d.%02d", (int)c->area,
                     (int)((c->area - (int)c->area) * 100.0f));
            break;
        case 2: snprintf(line, sizeof line, "%u", c->at28); break;
        case 3: snprintf(line, sizeof line, "%u", c->entities); break;
        case 4: snprintf(line, sizeof line, "%u", c->at30); break;
        case 5: snprintf(line, sizeof line, "%u", c->at2c); break;
        case 6: snprintf(line, sizeof line, "%u", c->funds); break;
        default: snprintf(line, sizeof line, "%u", c->taxRate); break;
        }
        fontDrawText(out, at, y + kRowY[i], ink, line);
    }
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
