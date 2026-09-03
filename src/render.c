// Drawing the world into an eight-bit indexed surface.
//
// Eight bits, not RGB, because that is what the original draws into: it hands
// GDI a CreateDIBSection surface with a 256-entry colour table and blits.
// Keeping the same shape means the WebAssembly host can hand the same surface
// to a canvas and the native host to StretchBlt, with one renderer between.
#include "gfx.h"
#include "render.h"

#include "font.h"
#include "toolbar.h"

#include <string.h>

void surfaceInit(Surface *surface, int width, int height,
                 unsigned char *pixels) {
    surface->width = width;
    surface->height = height;
    surface->pixels = pixels;
}

void renderWorld(const World *world, int zoom, int viewX, int viewY,
                 int transpose, Surface *out) {
    const TileBank *bank = worldBank(world, zoom);
    if (!bank->pixels || bank->tileSize <= 0) return;
    const int ts = bank->tileSize;

    for (int y = 0; y < out->height; y++) {
        const int worldY = viewY + y;
        unsigned char *row = out->pixels + (size_t)y * out->width;
        if (worldY < 0 || worldY >= WORLD_GRID * ts) {
            memset(row, 0, (size_t)out->width);
            continue;
        }
        const int cellY = worldY / ts;
        const int inY = worldY % ts;
        for (int x = 0; x < out->width; x++) {
            const int worldX = viewX + x;
            if (worldX < 0 || worldX >= WORLD_GRID * ts) {
                row[x] = 0;
                continue;
            }
            const int cellX = worldX / ts;
            const WorldCell *cell = &world->cells[
                transpose ? cellX * WORLD_GRID + cellY
                          : cellY * WORLD_GRID + cellX];
            const unsigned tile = cell->terrain % bank->tiles;
            row[x] = bank->pixels[tile * (unsigned)(ts * ts) + inY * ts +
                                  worldX % ts];
        }
    }
}


// 0041b520: which sprite an entity shows.  The number is bit-packed, not
// looked up, and the ranges fill the 208-tile bank exactly:
//
//   walking    size | faction<<3 | facing | frame        0x00..0x7f
//   working    0x80/0x82/0x84/0x86 | faction<<3 | frame  0x80..0x9f
//   fighting   0xa0 (0xa4 leader) | faction<<3 | phase   0xa0..0xbf
//   neutral    0xc0 | facing | frame, or 0xc8 | phase    0xc0..0xcf
//
// where size is 0 below a thousand strong, 0x20 below ten thousand, 0x40 above
// that, and 0x60 for a leader whatever its strength.  A leader is therefore
// drawn by rank, not by size - and 0xcc, past everything, is the cursor.
unsigned renderSpriteNumber(const Entity *entity, unsigned frame) {
    const unsigned leader = (entity->at0d & 0x20) != 0;
    const unsigned faction = entity->faction;
    const unsigned beat = (frame & 2) >> 1;

    if (faction == 4) {
        if (entity->flags & 2) return 0xc8u | entity->at0e;
        return 0xc0u | (unsigned)(entity->at0c & 6) | beat;
    }
    if (entity->flags & 2)
        return (leader ? 0xa4u : 0xa0u) | entity->at0e | (faction << 3);
    if (entity->flags & 1) {
        const unsigned base = leader ? 0x86u
                            : entity->at08 < 1000 ? 0x80u
                            : entity->at08 < 10000 ? 0x82u : 0x84u;
        return base | (faction << 3) | beat;
    }
    const unsigned base = leader ? 0x60u
                        : entity->at08 < 1000 ? 0x00u
                        : entity->at08 < 10000 ? 0x20u : 0x40u;
    return base | (unsigned)(entity->at0c & 6) | (faction << 3) | beat;
}

// 00424460: one tile of the sprite bank over the surface, 'p' left alone.
static void blitSprite(const TileBank *bank, unsigned number, int x, int y,
                       Surface *out) {
    if (!bank->pixels || number >= bank->tiles) return;
    const int ss = bank->tileSize;
    const unsigned char *tile = bank->pixels + (size_t)number * ss * ss;
    for (int ty = 0; ty < ss; ty++) {
        const int py = y + ty;
        if (py < 0 || py >= out->height) continue;
        unsigned char *dst = out->pixels + (size_t)py * out->width;
        for (int tx = 0; tx < ss; tx++) {
            const int px = x + tx;
            if (px < 0 || px >= out->width) continue;
            const unsigned char v = tile[ty * ss + tx];
            if (v == CHR_TRANSPARENT) continue;
            dst[px] = v;
        }
    }
}

// 004244b0: the order balloon, taken from the interface sheet rather than the
// sprite bank.  Each order has a 32-tall band of the sheet, and the three
// zooms sit side by side at x = 0xc0 + the tile size - which lands them at
// 0xc8, 0xd0 and 0xe0, filling 0xc8..0xff without a gap.
static void blitBalloon(const UiSheet *ui, unsigned number, int size, int x,
                        int y, Surface *out) {
    if (!ui->pixels) return;
    const unsigned sx = 0xc0u + (unsigned)size;
    const unsigned sy = number * 32u;
    if (sy + (unsigned)size > UI_SHEET_H || sx + (unsigned)size > UI_SHEET_W)
        return;
    for (int ty = 0; ty < size; ty++) {
        const int py = y + ty;
        if (py < 0 || py >= out->height) continue;
        unsigned char *dst = out->pixels + (size_t)py * out->width;
        const unsigned char *row = ui->pixels + (size_t)(sy + ty) * UI_SHEET_W;
        for (int tx = 0; tx < size; tx++) {
            const int px = x + tx;
            if (px < 0 || px >= out->width) continue;
            const unsigned char v = row[sx + tx];
            if (v == UI_TRANSPARENT) continue;
            dst[px] = v;
        }
    }
}

// 004240c0 draws the units by sweeping the cells, not the entity array: a cell
// names its occupant, and that is the only thing on screen.  An entity whose
// cell link is stale is invisible, which is the original's behaviour and worth
// keeping - it is how a unit disappears the instant it is taken off the board.
void renderUnits(const GameState *game, int zoom, int viewX, int viewY,
                 int transpose, Surface *out) {
    (void)transpose;
    const TileBank *bank = worldSprites(&game->world, zoom);
    const TileBank *ground = worldBank(&game->world, zoom);
    if (!bank->pixels || !ground->pixels || ground->tileSize <= 0) return;
    const int ts = ground->tileSize;
    const unsigned frame = game->frame;

    for (unsigned col = 0; col < WORLD_GRID; col++) {
        const int cellX = (int)col * ts - viewX;
        if (cellX + ts <= 0 || cellX >= out->width) continue;
        for (unsigned row = 0; row < WORLD_GRID; row++) {
            const int cellY = (int)row * ts - viewY;
            if (cellY + ts <= 0 || cellY >= out->height) continue;
            const WorldCell *cell =
                &game->world.cells[WORLD_INDEX(col, row)];

            if (cell->occupant < ENTITY_COUNT) {
                const Entity *entity = &game->entities[cell->occupant];
                blitSprite(bank, renderSpriteNumber(entity, frame), cellX, cellY,
                           out);
                // Its order, if it has one, floats one cell above.
                if (game->showOrders && entity->at220 != 0xff)
                    blitBalloon(&game->world.ui, entity->at220, ts, cellX,
                                cellY - ts, out);
            }
            // And whatever the cell itself carries - the cursor lives here.
            if (cell->overlay != 0)
                blitSprite(bank, (frame & 1) + cell->overlay, cellX, cellY,
                           out);
        }
    }
}

/* ------------------------------------------- the interface, from data1.bz */

// Where each font sits on the sheet, and how big its glyphs are.  Measured by
// finding the inked columns: the large digits are eight wide over sixteen
// rows, the small ones four over eight, and each has a white and a red set.
static const struct { int x, y, w, h; } kUiFonts[4] = {
    {0, 0, 8, 16},          // large white
    {0, 16, 8, 16},         // large red
    {0, 32, 4, 8},          // small white
    {0, 48, 4, 8},          // small red
};

// One glyph of the sheet, with 0x70 left out.
static void blitGlyph(const UiSheet *ui, int sx, int sy, int w, int h,
                      int dx, int dy, Surface *out) {
    for (int y = 0; y < h; y++) {
        const int py = dy + y;
        if (py < 0 || py >= out->height) continue;
        unsigned char *row = out->pixels + (size_t)py * out->width;
        for (int x = 0; x < w; x++) {
            const int px = dx + x;
            if (px < 0 || px >= out->width) continue;
            const unsigned char v =
                ui->pixels[(size_t)(sy + y) * UI_SHEET_W + sx + x];
            if (v == UI_TRANSPARENT) continue;
            row[px] = v;
        }
    }
}

int renderNumber(const World *world, UiFont font, int x, int y,
                 unsigned value, Surface *out) {
    const UiSheet *ui = &world->ui;
    if (!ui->pixels) return 0;
    if (font < 0 || font > 3) font = UI_FONT_LARGE_WHITE;
    const int gw = kUiFonts[font].w, gh = kUiFonts[font].h;

    // Right to left, which is how a number falls out of a division.
    int at = x - gw;
    unsigned left = value;
    do {
        const unsigned digit = left % 10u;
        blitGlyph(ui, kUiFonts[font].x + (int)digit * gw, kUiFonts[font].y,
                  gw, gh, at, y, out);
        at -= gw;
        left /= 10u;
    } while (left);
    return x - at - gw;
}


// The palette the drawing surface wants, assembled the way the original's
// several SetPaletteEntries calls leave it.  Four bands are live at once and a
// host that collapses them draws one band in another's colours:
//
//   0x10..0x1f  the terrain bank's sixteen
//   0x30..0x3f  the sprite bank's sixteen
//   0x70        RGB(0, 0, 0x96), the interface ground
//   0x76        a pulsing copy of sprite colour 0x3f
//   0x80..0xaf  data1.rgb's forty-eight, the interface
//
// and 0x1f pulses in place.  0040a6f0 scales both pulsing entries by
// kPulse[frame & 0xf], a triangle from full down to under a third and back,
// which is what makes marked ground breathe and the smallest units blink.
static const unsigned char kPulse[16] = {100, 90, 80, 70, 60, 50, 40, 30,
                                         40,  50, 60, 70, 80, 90, 100, 100};

static unsigned world_names_colour(const World *world, unsigned faction) {
    return world->names.loaded && faction < 5
               ? world->names.colour[NAME_COUNTRY + faction] : 0;
}

unsigned renderCountryColour(const GameState *game, int zoom,
                             unsigned faction) {
    const TileBank *ground = worldBank(&game->world, zoom);
    if (!ground) return 0;
    const unsigned index = world_names_colour(&game->world, faction);
    const unsigned char *rgb = ground->palette[index & 0xff];
    return ((unsigned)rgb[0] << 16) | ((unsigned)rgb[1] << 8) | rgb[2];
}

void renderPalette(const GameState *game, int zoom,
                   unsigned char table[256][3]) {
    const TileBank *ground = worldBank(&game->world, zoom);
    const TileBank *sprites = worldSprites(&game->world, zoom);
    const unsigned scale = kPulse[game->frame & 0xf];

    for (unsigned i = 0; i < 256; i++) {
        const unsigned char *from = ground->palette[i];
        if (i >= 0x80 && i < 0xb0 && game->world.ui.pixels)
            from = game->world.ui.palette[i];
        else if (i >= 0x30 && i < 0x40)
            from = sprites->palette[i];
        table[i][0] = from[0];
        table[i][1] = from[1];
        table[i][2] = from[2];
    }

    // 00405fc0 installs the terrain's sixteen twice: once as they are, and
    // once at 0x55/100 of their brightness sixteen entries further on.
    for (unsigned i = 0; i < 16; i++)
        for (int c = 0; c < 3; c++)
            table[0x20 + i][c] =
                (unsigned char)(ground->palette[0x10 + i][c] * 0x55u / 100u);

    table[UI_TRANSPARENT][0] = 0;
    table[UI_TRANSPARENT][1] = 0;
    table[UI_TRANSPARENT][2] = 0x96;

    // 0x71 to 0x75 are the five countries' colours, named by the first byte of
    // each country's record in the name table: a terrain index whose low four
    // bits pick out of the sprite bank's sixteen.  The interface graphics are
    // drawn in these, which is how a panel knows whose it is.
    for (unsigned f = 0; f < 5; f++) {
        const unsigned char *from =
            sprites->palette[0x30u + (world_names_colour(&game->world, f) &
                                      0x0fu)];
        table[0x71 + f][0] = from[0];
        table[0x71 + f][1] = from[1];
        table[0x71 + f][2] = from[2];
    }
    // The chrome the port draws its menus with.  Nothing in the game's own art
    // uses 0xf0 and up, and these are the Windows 95 system colours the
    // original's menus were drawn in - it is an MFC application, so its menus
    // were whatever the desktop's scheme said, and this is that scheme.
    static const unsigned char chrome[9][3] = {
        {192, 192, 192},        // UI_FACE
        {255, 255, 255},        // UI_LIGHT
        {128, 128, 128},        // UI_SHADOW
        {0, 0, 0},              // UI_DARK
        {0, 0, 128},            // UI_PICK
        {255, 255, 255},        // UI_PICK_TEXT
        {128, 128, 128},        // UI_GREY_TEXT
        {80, 80, 80},           // UI_END_GREY, 0040a870's heading grey
        {245, 0, 0},            // UI_END_RED, its penalty red
    };
    for (unsigned i = 0; i < 9; i++)
        for (int c = 0; c < 3; c++) table[0xf0 + i][c] = chrome[i][c];

    // And the tool bar's own sixteen, which BITMAP 102 brings with it - the
    // standard VGA set, with entry seven the face grey the icons sit on.
    for (unsigned i = 0; i < 16; i++)
        for (int c = 0; c < 3; c++)
            table[0xd0 + i][c] = kToolbarPalette[i][c];

    for (int c = 0; c < 3; c++) {
        table[0x1f][c] =
            (unsigned char)(ground->palette[0x1f][c] * scale / 100u);
        table[CHR_PULSE][c] =
            (unsigned char)(sprites->palette[0x3f][c] * scale / 100u);
    }
}
