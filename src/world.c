#include "world.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bz.h"
#include "gfx.h"

#define MAP_FILE_SIZE (WORLD_CELLS + 2)     // 0x902
#define BANK_BUFFER   0x8030u               // what 00406640 allocates

// The largest of the game's files is a 256-colour still at 196,616 bytes.
#define MAX_GAME_FILE 0x40000u

static unsigned char *slurp(const Host *host, const char *path,
                            long *sizeOut) {
    unsigned char *buf = (unsigned char *)malloc(MAX_GAME_FILE);
    if (!buf) return NULL;
    unsigned got = 0;
    if (!hostRead(host, path, buf, MAX_GAME_FILE, &got)) {
        free(buf);
        return NULL;
    }
    *sizeOut = (long)got;
    return buf;
}

static int loadBank(TileBank *bank, const Host *host, const char *path,
                    int tileSize, char *message, unsigned messageSize) {
    memset(bank, 0, sizeof *bank);
    long size = 0;
    unsigned char *file = slurp(host, path, &size);
    if (!file) {
        snprintf(message, messageSize, "%s: cannot open", path);
        return 0;
    }
    unsigned char *raw = (unsigned char *)malloc(BANK_BUFFER);
    unsigned produced = 0;
    if (!raw || !bzDecompress(file, (unsigned)size, raw, BANK_BUFFER,
                              &produced)) {
        snprintf(message, messageSize, "%s: cannot decompress", path);
        free(file);
        free(raw);
        return 0;
    }
    free(file);

    const unsigned bytes = (unsigned)(TILE_BANK_TILES * tileSize * tileSize);
    bank->pixels = (unsigned char *)malloc(bytes);
    if (!bank->pixels ||
        !gfxUnpackTiles(raw, produced, tileSize, bank->pixels, bytes,
                        &bank->tiles)) {
        snprintf(message, messageSize, "%s: cannot unpack %dx%d tiles",
                 path, tileSize, tileSize);
        free(raw);
        return 0;
    }
    bank->tileSize = tileSize;
    gfxTilePalette(raw, produced, &bank->palette[0][0]);
    free(raw);
    return 1;
}

int worldLoadStage(World *world, const Host *host, const char *mapName,
                   char *message, unsigned messageSize) {
    memset(world, 0, sizeof *world);
    snprintf(world->stage, sizeof world->stage, "%s", mapName);

    char path[256];
    snprintf(path, sizeof path, "MAP/%s", mapName);
    long size = 0;
    unsigned char *map = slurp(host, path, &size);
    if (!map) {
        snprintf(message, messageSize, "%s: cannot open", path);
        return 0;
    }
    if (size != MAP_FILE_SIZE) {
        snprintf(message, messageSize, "%s: %ld bytes, expected %d",
                 path, size, MAP_FILE_SIZE);
        free(map);
        return 0;
    }

    // 00405de0's spread: terrain into +0x10, 100 into +0x0c, 0x40 into +0x00.
    for (int i = 0; i < WORLD_CELLS; i++) {
        world->cells[i].terrain = map[i];
        world->cells[i].value = 100;
        world->cells[i].owner = 0x40;
    }
    world->scenerySet = map[WORLD_CELLS];
    free(map);

    // The same byte the original hands to 00405fc0.
    static const struct { const char *suffix; int size; size_t offset; } banks[] = {
        {"s", 8, offsetof(World, bank8)},
        {"m", 16, offsetof(World, bank16)},
        {"l", 32, offsetof(World, bank32)},
    };
    // The sprite bank, whose palette 004065e0 puts at 0x30 - and which
    // 00406c70 unpacks with a different bias, so it goes through its own
    // routine.  A stage without one still plays; the units are just unseen.
    {
        char spritePath[256];
        snprintf(spritePath, sizeof spritePath, "CHR/C_%03dm.BZ",
                 world->scenerySet);
        long spriteSize = 0;
        unsigned char *spriteFile = slurp(host, spritePath, &spriteSize);
        if (spriteFile) {
            unsigned char *raw = (unsigned char *)malloc(BANK_BUFFER);
            unsigned produced = 0;
            if (raw && bzDecompress(spriteFile, (unsigned)spriteSize, raw,
                                    BANK_BUFFER, &produced)) {
                const unsigned bytes = CHR_TILES * 16u * 16u;
                world->sprites.pixels = (unsigned char *)malloc(bytes);
                if (world->sprites.pixels &&
                    gfxUnpackSprites(raw, produced, world->sprites.pixels,
                                     bytes, &world->sprites.tiles)) {
                    world->sprites.tileSize = 16;
                    gfxSpritePalette(raw, produced, &world->sprites.palette[0][0]);
                } else {
                    free(world->sprites.pixels);
                    world->sprites.pixels = NULL;
                }
            }
            free(raw);
            free(spriteFile);
        }
    }

    for (unsigned b = 0; b < sizeof banks / sizeof banks[0]; b++) {
        snprintf(path, sizeof path, "BG/B_%03d%s.BZ", world->scenerySet,
                 banks[b].suffix);
        TileBank *bank = (TileBank *)((char *)world + banks[b].offset);
        if (!loadBank(bank, host, path, banks[b].size, message,
                      messageSize)) {
            worldFree(world);
            return 0;
        }
    }
    return 1;
}

void worldFree(World *world) {
    free(world->sprites.pixels);
    world->sprites.pixels = NULL;
    free(world->bank8.pixels);
    free(world->bank16.pixels);
    free(world->bank32.pixels);
    world->bank8.pixels = world->bank16.pixels = world->bank32.pixels = NULL;
}

const TileBank *worldBank(const World *world, int zoom) {
    if (zoom <= 0) return &world->bank8;
    if (zoom == 1) return &world->bank16;
    return &world->bank32;
}
