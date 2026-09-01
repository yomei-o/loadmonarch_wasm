// Drawing the world into an eight-bit indexed surface.
//
// Eight bits, not RGB, because that is what the original draws into: it hands
// GDI a CreateDIBSection surface with a 256-entry colour table and blits.
// Keeping the same shape means the WebAssembly host can hand the same surface
// to a canvas and the native host to StretchBlt, with one renderer between.
#include "gfx.h"
#include "render.h"

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

// 1833 works the sprite out as 0xa0 - 0xa8 for the neutral faction - plus
// faction * 8 plus an animation frame, less one.  Those numbers reach 187,
// which is why the sprite bank holds 208 tiles rather than the terrain banks'
// 128; the frame is the facing the entity carries.
static unsigned spriteFor(const Entity *entity, const TileBank *bank) {
    const unsigned base = entity->faction == 4 ? 0xa8u : 0xa0u;
    const unsigned frame = (unsigned)(entity->at0c & 7u) + 1u;
    const unsigned index = base + entity->faction * 8u + frame - 1u;
    return index < bank->tiles ? index : 0u;
}

void renderUnits(const GameState *game, int zoom, int viewX, int viewY,
                 int transpose, Surface *out) {
    const TileBank *bank = worldSprites(&game->world, zoom);
    if (!bank->pixels || bank->tileSize <= 0) return;
    const TileBank *ground = worldBank(&game->world, zoom);
    if (!ground->pixels || ground->tileSize <= 0) return;
    const int ts = ground->tileSize;
    const int ss = bank->tileSize;

    for (int i = 0; i < ENTITY_COUNT; i++) {
        const Entity *entity = &game->entities[i];
        if (entity->flags & 0x80) continue;
        const unsigned col = entity->position[0];
        const unsigned row = entity->position[1];
        if (col >= WORLD_GRID || row >= WORLD_GRID) continue;

        // Where the cell sits on screen, with the sprite centred in it.
        const int cellX = (transpose ? (int)col : (int)col) * ts - viewX;
        const int cellY = (transpose ? (int)row : (int)row) * ts - viewY;
        if (cellX + ts <= 0 || cellY + ts <= 0) continue;
        if (cellX >= out->width || cellY >= out->height) continue;

        const unsigned char *tile =
            bank->pixels + spriteFor(entity, bank) * (unsigned)(ss * ss);
        // A bank whose tiles match the cell draws at its own size; the
        // 8-pixel zoom still borrows the 16-pixel bank and is scaled.
        const int size = ss == ts ? ss : ts;
        const int drawX = cellX + (ts - size) / 2;
        const int drawY = cellY + (ts - size) / 2;
        for (int y = 0; y < size; y++) {
            const int py = drawY + y;
            if (py < 0 || py >= out->height) continue;
            unsigned char *dst = out->pixels + (size_t)py * out->width;
            const int sy = size == ss ? y : y * ss / size;
            for (int x = 0; x < size; x++) {
                const int px = drawX + x;
                if (px < 0 || px >= out->width) continue;
                const int sx = size == ss ? x : x * ss / size;
                const unsigned char v = tile[sy * ss + sx];
                if (v == CHR_TRANSPARENT) continue;
                dst[px] = v;
            }
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

void renderStatus(const GameState *game, Surface *out) {
    const UiSheet *ui = &game->world.ui;
    if (!ui->pixels) return;

    // Four columns, one per faction, each with its purse above its tax rate.
    // A faction that is out is drawn in the red set, which is what that second
    // font is for.
    const int columnWidth = out->width / PLAYABLE_FACTIONS;
    for (int f = 0; f < PLAYABLE_FACTIONS; f++) {
        const int right = columnWidth * (f + 1) - 6;
        const int out_ = (game->factions[f].flags & 0x10) != 0;
        renderNumber(&game->world,
                     out_ ? UI_FONT_LARGE_RED : UI_FONT_LARGE_WHITE,
                     right, 2, game->factions[f].funds, out);
        // The faction's total, which is the pair of sums 0041b370 keeps, and
        // its tax rate - both in the large font, since the small one is four
        // pixels wide and unreadable at this scale.
        const int width = renderNumber(
            &game->world, out_ ? UI_FONT_LARGE_RED : UI_FONT_LARGE_WHITE,
            right, 20, game->factions[f].strength, out);
        renderNumber(&game->world,
                     out_ ? UI_FONT_LARGE_RED : UI_FONT_LARGE_WHITE,
                     right - width - 8, 20, game->factions[f].taxRate, out);
    }
}
