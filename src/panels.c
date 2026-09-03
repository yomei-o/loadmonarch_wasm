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

#include "dlgload.h"
#include "font.h"
#include "rsrc.h"
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
// blue then green then yellow.
//
// The destination is **one** row of ten.  004265b9's `lea ecx, [edx*8 + 0x48]`
// with `edx = (n % 10) + pitch * 12` has no term for `n / 10` in it at all, so
// piece 10 lands on top of piece 0 in green and piece 20 on top of that in
// yellow: the bar fills blue, then fills again green over the blue, then
// yellow.  Drawing them on three rows - which is what this did - showed only
// the blue tenth of a gauge and left the two rows below it in the panel's
// other slots.
static void blitGauge(Surface *out, const World *world, int n, int dx,
                      int dy) {
    for (int i = 0; i < n && i < 30; i++)
        blitSheet(out, world, (i % 10) * 8, (i / 10 + 4) * 16, 8, 16,
                  dx + (i % 10) * 8, dy);
}

// 00426ec0's count for the unit's own gauge, which is its strength by the
// decade: under a thousand fills the blue ten, under ten thousand the green
// ten and anything more the yellow - the same three bands 0041b520 chooses a
// unit's sprite size by.
static int strengthPieces(unsigned strength) {
    if (strength < 1000u) return (int)(strength * 10u / 1000u);
    if (strength < 10000u) return (int)(strength * 10u / 10000u) + 10;
    const int n = (int)(strength * 10u / 100000u) + 20;
    return n > 30 ? 30 : n;
}

// 00426da9: what the third line says about a unit.  The leader says so, the
// nibble 0x0e is the one that has broken off, and everything else is the name
// of the order it is under.
static const char *unitOrderName(const World *w, unsigned char at0d) {
    if (at0d & 0x20) return worldOrderName(w, 13);      // I'm Leader
    const unsigned n = at0d & 0x0fu;
    if (n == 0x0e) return worldOrderName(w, 15);        // Break
    return worldOrderName(w, n);
}

void panelUnitWindow(Surface *out, const GameState *game, int x, int y,
                     const WorldCell *under, unsigned pending, int unit) {
    const World *w = &game->world;
    blitPanel(out, w, 0, UNIT_TOP, PANEL_W, PANEL_H, x, y);
    if (!under) return;
    const int terrain = (int)under->terrain;
    const unsigned value = under->value;

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

    // 00426900 clears a 96 by 16 slot at (0x40, 0x78) and writes the cell's
    // worth into it with TextOutA - "NUM  %6d" for a cell of terrain 8 to 11
    // and "DEF  %6d" for every other, at most twelve characters
    // (00426b29's min against lstrlenA), white on nothing (SetTextColor
    // 0xffffff and SetBkMode TRANSPARENT at 004258a8).  It is the window's own
    // GUI text and not the game's big digits, which is what the port drew
    // here: the digits ended at x = 152, where the string does, and the label
    // in front of them was missing.
    const unsigned char ink = fontInk(w, UI_FONT_LARGE_WHITE);
    char line[32];
    snprintf(line, sizeof line, "%s%6u",
             (terrain >= 8 && terrain < 12) ? "NUM  " : "DEF  ", value);
    if (strlen(line) > 12) line[12] = 0;
    fontDrawText(out, x + 64, y + 120, ink, line);

    // And at (0x40, 0x90) the name of the order a new unit will take, which
    // 00426a69 reads as DAT_004365e0 & 0xf out of the name table.
    const char *order = worldOrderName(w, pending & 0xfu);
    if (order && *order) fontDrawText(out, x + 64, y + 144, ink, order);

    // 004269c0: a cell of terrain 8 to 11 is measured against 0x90 and every
    // other against 0xff, thirty pieces at the full value, and 00426b59 caps
    // the count at 0x1e - not at ten.  The eleventh piece goes back to the
    // left in green and the twenty-first in yellow.
    const unsigned over = (terrain >= 8 && terrain < 12) ? 0x90u : 0xffu;
    int n = (int)(value * 30u / (over ? over : 1u));
    if (n > 30) n = 30;
    blitGauge(out, w, n, x + 72, y + 96);

    // And the upper half: the unit the window is showing, if it still has one.
    // 00426c71 drops it as soon as the entity is inactive.
    const Entity *e = unit >= 0 && unit < 0x40 && unit < ENTITY_COUNT
        ? &game->entities[unit] : NULL;
    if (e && (e->flags & 0x80u)) e = NULL;
    if (!e) {
        // 00427128: the cell's routing cost, with 0x1f0 for no way there.
        char dis[24];
        if (under->cost == 0x1f0u) snprintf(dis, sizeof dis, "DIS. -----");
        else snprintf(dis, sizeof dis, "DIS. %u", under->cost);
        if (strlen(dis) > 12) dis[12] = 0;
        fontDrawText(out, x + 64, y + 64, ink, dis);
        return;
    }

    const TileBank *sprites = worldSprites(w, 2);
    if (sprites)
        renderSprite(out, sprites, renderSpriteNumber(e, game->frame),
                     x + 16, y + 48, 0);
    blitGauge(out, w, strengthPieces(e->at08), x + 72, y + 16);
    snprintf(line, sizeof line, "STR  %6u", e->at08);
    if (strlen(line) > 12) line[12] = 0;
    fontDrawText(out, x + 64, y + 40, ink, line);
    const char *its = unitOrderName(w, e->at0d);
    if (its && *its) fontDrawText(out, x + 64, y + 64, ink, its);
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
                         unsigned frame, int broke, int x, int y) {
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

    // The four numbers, where 00419ab0's own four TextOut calls put them:
    // "%6d" at 32,40 and "%2d" at 120,40 on the top row, "%6d" at 32,104 and
    // 96,104 on the bottom.  Both formats right-align inside their field, so
    // the right edge of a six-character number written at 32 is 80 - which is
    // where the port's own right-aligned digits already ended.  The tax box
    // comes with a per cent sign printed in it at 136 to 143, and "%2d" at 120
    // ends at 136 exactly.
    //
    // 00419d40 is the one thing that was missing: the purse goes red for the
    // sweep in which the country could not pay - DAT_0043451c - and white
    // again after it.
    if (broke) {
        char purse[16];
        snprintf(purse, sizeof purse, "%u", game->factions[faction].funds);
        fontDrawTextRight(out, x + 80, y + 40, (unsigned char)UI_END_RED,
                          purse);
    } else {
        renderNumber(w, UI_FONT_LARGE_WHITE, x + 80, y + 40,
                     game->factions[faction].funds, out);
    }
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

// The seventeen lines 00404e40 writes, in the order it writes them: for each
// of the four countries its area and then its funds, then for each of them
// its leader's strength and then its total - both of those replaced by the
// fallen line when the country is out - and last the neutral country's own
// total.  The wording is the release's own (src/dlgload.c reads the six
// formats out of .data); these are the English release's, transcribed from
// 0x432088, 0x4320a4, 0x4320b8, 0x4320d0, 0x4320dc and 0x4320f4, for an
// archive whose executable will not read.
static const char *kGraphFallback[RSRC_GRAPH_LINES] = {
    "%s Area Occupied %3.2f",
    "%s Funds %d",
    "%s Leader Strength %d",
    "%s Unit Totals %d",
    "%s Unit and Base Totals %d",
    "%s Defeated",
};

static const char *graphFormat(int which) {
    const char *own = dlgGraphLine(which);
    return own && *own ? own : kGraphFallback[which];
}

// One of the seventeen.  `line` comes back empty for an index past the end.
static void graphLine(char *line, int size, const GameState *game, int i) {
    line[0] = 0;
    if (i < 0 || i >= GRAPH_LINES) return;
    if (i == GRAPH_LINES - 1) {
        // 00404f9a: faction four's +0x10 and its name at DS:0x435b75.
        const Faction *wild = &game->factions[4];
        const char *name = worldCountryName(&game->world, 4);
        snprintf(line, (size_t)size,
                 graphFormat(wild->strength ? RSRC_GRAPH_ALL
                                            : RSRC_GRAPH_DEFEATED),
                 name, wild->strength);
        return;
    }
    const unsigned f = (unsigned)((i % 8) / 2);
    if (f >= PLAYABLE_FACTIONS) return;
    const char *name = worldCountryName(&game->world, f);
    const Faction *c = &game->factions[f];
    if (i < 8) {
        // 00404e61's loop: the area as a fraction, then the purse.  Neither
        // is dropped when a country falls.
        if ((i & 1) == 0)
            snprintf(line, (size_t)size, graphFormat(RSRC_GRAPH_AREA),
                     name, (double)c->area);
        else
            snprintf(line, (size_t)size, graphFormat(RSRC_GRAPH_FUNDS),
                     name, c->funds);
        return;
    }
    // 00404ef4's loop: the leader's own strength and the country's total, and
    // the fallen line in place of both once +0x04 has bit 6 set.
    if (c->flags & 0x40u) {
        snprintf(line, (size_t)size, graphFormat(RSRC_GRAPH_DEFEATED), name);
        return;
    }
    if ((i & 1) == 0) {
        const unsigned leader = c->at0c < ENTITY_COUNT
            ? game->entities[c->at0c].at08 : 0u;
        snprintf(line, (size_t)size, graphFormat(RSRC_GRAPH_LEADER),
                 name, leader);
    } else {
        snprintf(line, (size_t)size, graphFormat(RSRC_GRAPH_UNITS),
                 name, c->strength);
    }
}

int panelGraphLines(void) { return GRAPH_LINES; }

int panelGraphRows(int h) {
    const int rows = (h - 8) / GRAPH_ROW_H;
    return rows < 1 ? 1 : rows;
}

// A rectangle of one colour, bounded to the surface.  dlg.c has its own; the
// two do not share one because a panel is not a dialog.
static void fillRect(Surface *out, int x, int y, int w, int h,
                     unsigned char ink) {
    for (int j = 0; j < h; j++) {
        const int py = y + j;
        if (py < 0 || py >= out->height) continue;
        unsigned char *row = out->pixels + (size_t)py * out->width;
        for (int i = 0; i < w; i++) {
            const int px = x + i;
            if (px >= 0 && px < out->width) row[px] = ink;
        }
    }
}

// The bar down the right: a trough with a thumb in it, in the same raised and
// sunken style dlg.c gives the game's own widgets.  The window really has a
// Windows scroll bar - 00404316 makes room for one with GetSystemMetrics and
// the program calls SetScrollInfo on it - so what is here is the port's own
// drawing of one, arrows and all, rather than a reading of anything.
static void scrollBar(Surface *out, int x, int y, int h, int scroll,
                      int rows) {
    const int w = GRAPH_BAR_W;
    for (int j = 0; j < h; j++) {
        const int py = y + j;
        if (py < 0 || py >= out->height) continue;
        unsigned char *row = out->pixels + (size_t)py * out->width;
        for (int i = 0; i < w; i++) {
            const int px = x + i;
            if (px >= 0 && px < out->width)
                row[px] = (unsigned char)UI_GREY_TEXT;
        }
    }
    // The two arrow buttons, and a triangle in each.
    for (int end = 0; end < 2; end++) {
        const int by = end ? y + h - w : y;
        fillRect(out, x, by, w, w, (unsigned char)UI_FACE);
        fillRect(out, x, by, w, 1, (unsigned char)UI_LIGHT);
        fillRect(out, x, by, 1, w, (unsigned char)UI_LIGHT);
        fillRect(out, x, by + w - 1, w, 1, (unsigned char)UI_SHADOW);
        fillRect(out, x + w - 1, by, 1, w, (unsigned char)UI_SHADOW);
        for (int k = 0; k < 4; k++) {
            const int ry = end ? by + 5 + k : by + 10 - k;
            fillRect(out, x + 4 + k, ry, (4 - k) * 2, 1,
                     (unsigned char)UI_DARK);
        }
    }
    // And the thumb, as far down the trough as the scroll has gone.
    const int span = h - 2 * w;
    const int over = GRAPH_LINES - rows;
    if (span < 8 || over <= 0) return;
    int thumb = span * rows / GRAPH_LINES;
    if (thumb < 8) thumb = 8;
    const int at = y + w + (span - thumb) * scroll / over;
    fillRect(out, x, at, w, thumb, (unsigned char)UI_FACE);
    fillRect(out, x, at, w, 1, (unsigned char)UI_LIGHT);
    fillRect(out, x, at, 1, thumb, (unsigned char)UI_LIGHT);
    fillRect(out, x, at + thumb - 1, w, 1, (unsigned char)UI_SHADOW);
    fillRect(out, x + w - 1, at, 1, thumb, (unsigned char)UI_SHADOW);
}

void panelGraphWindow(Surface *out, const GameState *game, int x, int y,
                      int w, int h, int scroll) {
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

    const int rows = panelGraphRows(h);
    const int over = GRAPH_LINES - rows;
    if (scroll < 0) scroll = 0;
    if (scroll > (over > 0 ? over : 0)) scroll = over > 0 ? over : 0;

    // 00404d37 draws its lines sixteen apart and stops when the window is
    // full, which is what a scroll bar is for.
    const int right = x + w - (over > 0 ? GRAPH_BAR_W : 0);
    char line[80];
    for (int r = 0; r < rows; r++) {
        const int i = scroll + r;
        if (i >= GRAPH_LINES) break;
        graphLine(line, sizeof line, game, i);
        if (!line[0]) continue;
        fontDrawTextClipped(out, x + 4, y + 4 + r * GRAPH_ROW_H, right,
                            (unsigned char)UI_DARK, line);
    }
    if (over > 0) scrollBar(out, x + w - GRAPH_BAR_W, y, h, scroll, rows);
}
