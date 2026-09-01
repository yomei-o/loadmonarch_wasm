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

// 1833 works the sprite out as 0xa0 (or 0xa4 when a flag is clear, 0xa8 for
// the neutral faction) plus faction * 8 plus an animation frame less one.  The
// bank this port unpacks holds 128 tiles, so the number is taken modulo that -
// the sprite banks the original keeps are larger than one .BZ provides and how
// it fills the rest is not read yet.  The colours still come out per faction,
// which is what makes a unit readable on the map.
static unsigned spriteFor(const Entity *entity, const TileBank *bank) {
    const unsigned base = entity->faction == 4 ? 0xa8u : 0xa0u;
    const unsigned frame = (unsigned)(entity->at0c & 3u) + 1u;
    const unsigned index = base + entity->faction * 8u + frame - 1u;
    return bank->tiles ? index % bank->tiles : 0u;
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
        const int originX = cellX + (ts - ss) / 2;
        const int originY = cellY + (ts - ss) / 2;
        if (originX + ss <= 0 || originY + ss <= 0) continue;
        if (originX >= out->width || originY >= out->height) continue;

        const unsigned char *tile =
            bank->pixels + spriteFor(entity, bank) * (unsigned)(ss * ss);
        for (int y = 0; y < ss; y++) {
            const int py = originY + y;
            if (py < 0 || py >= out->height) continue;
            unsigned char *dst = out->pixels + (size_t)py * out->width;
            for (int x = 0; x < ss; x++) {
                const int px = originX + x;
                if (px < 0 || px >= out->width) continue;
                const unsigned char v = tile[y * ss + x];
                if (v == CHR_TRANSPARENT) continue;
                dst[px] = v;
            }
        }
    }
}
