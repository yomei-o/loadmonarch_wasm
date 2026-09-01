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
    const TileBank *bank = &game->world.sprites;
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
        // The original keeps a sprite bank per zoom - C_%03ds.BZ split into
        // quarters and four C_%03dl*.BZ merged in fours - and neither of those
        // rearrangements is ported.  Only the 16-pixel bank is, so at the
        // other zooms the sprite is scaled to the cell instead.  That is this
        // port's doing, not the game's.
        const int size = ts < ss ? ts : (ts > ss ? ts : ss);
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
