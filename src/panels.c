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

/* ------------------------------------------------------- the Graph Window */

int panelGraphLines(void) { return GRAPH_LINES; }

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

// Where each bar stands and what it is measured against.  00404c30 lays them
// out: five countries of four, sixteen apart, the first two of each up from
// y = 0xa8 and the other two from y = 0x34.  0040463b works out the heights.
typedef struct {
    int x, base, height;
    unsigned char colour, style, gone;
} GraphBar;

// 0040463b's own scales.  A leader and a total are measured against a hundred
// thousand over ninety-six pixels; the ground held against a hundred per cent
// over thirty-two; and the purse against ten thousand over thirty-two, capped.
static int barTarget(const GameState *game, unsigned f, int which, int *gone) {
    const Faction *c = &game->factions[f];
    *gone = 0;
    switch (which) {
    case 0: {
        const unsigned leader = c->at0c < ENTITY_COUNT
            ? game->entities[c->at0c].at08 : 0u;
        if (!leader) *gone = 1;
        return (int)(leader * 96u / 100000u);
    }
    case 1:
        if (!c->strength) *gone = 1;
        return (int)(c->strength * 96u / 100000u);
    case 2:
        if (!(c->area > 0.0f)) *gone = 1;
        return (int)(c->area * 32.0f) / 100;
    default: {
        if (c->funds < 100u) *gone = 1;
        int n = (int)(c->funds * 32u / 10000u);
        return n > 32 ? 32 : n;
    }
    }
}

static void barAt(const GameState *game, int i, GraphBar *out) {
    const unsigned f = (unsigned)(i / 4);
    const int which = i % 4;
    const int xbase = 16 + (int)f * 32;
    out->x = xbase + (which & 1 ? 16 : 0);
    out->base = which < 2 ? 0xa8 : 0x34;
    // 004048d0: the neutral country's bar is 0x76 and the rest are 0x71 up.
    out->colour = (unsigned char)(f == 4 ? 0x76u : 0x71u + f);
    // 00404ca8: the first two carry that country's leader and one of its
    // units; the other two carry a house and a stack of coins.
    switch (which) {
    case 0: out->style = (unsigned char)((f << 3) | 0x66u); break;
    case 1: out->style = (unsigned char)((f << 3) | 0x06u); break;
    case 2: out->style = 0xf0; break;
    default: out->style = 0xf1; break;
    }
    int gone = 0;
    out->height = f < PLAYABLE_FACTIONS || which == 1
        ? barTarget(game, f, which, &gone) : 0;
    // The neutral country has only the one bar - 00404793 works out its total
    // and nothing else - so its other three stay down.
    if (f >= PLAYABLE_FACTIONS && which != 1) gone = 1;
    out->gone = (unsigned char)gone;
}

void panelGraphTick(GraphWindow *win, const GameState *game) {
    for (int i = 0; i < GRAPH_BARS; i++) {
        GraphBar bar;
        barAt(game, i, &bar);
        win->gone[i] = bar.gone;
        // 004047bd: one pixel a tick, up or down, until it is there.
        if (win->height[i] < bar.height) win->height[i]++;
        else if (win->height[i] > bar.height) win->height[i]--;
        // 004049eb: a country that has gone winds its picture through five
        // frames and stops; one that stands winds it back.
        if (bar.gone) {
            if (win->phase[i] < 4) win->phase[i]++;
        } else if (win->phase[i]) {
            win->phase[i]--;
        }
    }
}

// 00404b09 and 00404bc5: one of the sixteen by sixteen pictures the sheet
// keeps in two bands - houses at 0x1d000, which is row 464, and stacks of
// coins at 0x1e000, sixteen rows below it.
static void blitIcon(Surface *out, const World *world, unsigned base,
                     int index, int dx, int dy) {
    const UiSheet *ui = &world->ui;
    if (!ui->pixels) return;
    const unsigned off = base + (unsigned)index * 16u;
    const unsigned sx = off % UI_SHEET_W, sy = off / UI_SHEET_W;
    if (sy + 16 > UI_SHEET_H) return;
    for (int j = 0; j < 16; j++) {
        const int py = dy + j;
        if (py < 0 || py >= out->height) continue;
        unsigned char *row = out->pixels + (size_t)py * out->width;
        const unsigned char *src =
            ui->pixels + (size_t)(sy + j) * UI_SHEET_W + sx;
        for (int i = 0; i < 16; i++) {
            const int px = dx + i;
            if (px < 0 || px >= out->width) continue;
            if (src[i] == UI_TRANSPARENT) continue;
            row[px] = src[i];
        }
    }
}

void panelGraphDraw(Surface *out, const GraphWindow *win,
                    const GameState *game, int x, int y) {
    const World *w = &game->world;
    const TileBank *sprites = worldSprites(w, 1);   // the sixteen-pixel set
    const unsigned frame = game->frame;

    for (int i = 0; i < GRAPH_BARS; i++) {
        GraphBar bar;
        barAt(game, i, &bar);
        const int height = win->height[i];
        if (height <= 0 && !win->gone[i]) continue;

        // 004048d0: fourteen wide inside the sixteen, grown up from its foot.
        if (height > 0)
            fillRect(out, x + bar.x + 1, y + bar.base - height, 14, height,
                     bar.colour);

        // And the picture on its head, sixteen above the top of the bar.
        const int iy = y + bar.base - height - 16;
        if (bar.style == 0xf0 || bar.style == 0xf1) {
            // 00404ac3 and 00404ae3: five frames of falling when the country
            // has gone, and otherwise a picture that grows with the number -
            // one step over ten and another over twenty.
            const unsigned band = bar.style == 0xf1 ? 0x1e000u : 0x1d000u;
            int index = 0;
            if (win->gone[i]) index = 5 + win->phase[i];
            else if (height > 0x14) index = 4;
            else if (height > 0x0a) index = 2;
            blitIcon(out, w, band, index, x + bar.x, iy);
        } else if (sprites) {
            // 004049d3: 0xa0 and 0xa4 are the fighting frames a country that
            // has gone shows, 0xa8 the neutral one's; otherwise its own.
            const unsigned f = (unsigned)(i / 4);
            unsigned number;
            if (win->gone[i]) {
                const unsigned base = f == 4 ? 0xa8u
                    : ((i % 4) == 0 ? 0xa4u : 0xa0u) + (f << 3);
                number = base + win->phase[i];
            } else {
                number = (unsigned)bar.style + (frame & 1u);
            }
            renderSprite(out, sprites, number, x + bar.x, iy, 0);
        }
    }
}

int panelGraphTip(const GameState *game, int px, int py, char *out, int size) {
    if (out && size) out[0] = 0;
    if (px < 0 || py < 0 || px >= GRAPH_W || py >= GRAPH_H) return 0;
    // 00404d37 and 00404dac: eight strips of sixteen across the top half and
    // eight across the bottom, and the neutral country's ninth at x = 0x90.
    if (px < 16) return 0;              // the margin the bars start after
    const int slot = (px - 16) / 16;
    int line = -1;
    if (py < 0x40) {
        if (slot < 8) line = slot;
    } else if (slot < 8) {
        line = 8 + slot;
    } else if (slot == 8) {
        line = 16;
    }
    if (line < 0) return 0;
    graphLine(out, size, game, line);
    return out[0] != 0;
}
