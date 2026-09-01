#include "world.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bz.h"
#include "gfx.h"

#define MAP_FILE_SIZE (WORLD_CELLS + 2)     // 0x902
#define BANK_BUFFER   0x8030u               // what 00406640 allocates

static unsigned char *slurp(const char *path, long *sizeOut) {
    FILE *f = fopen(path, "rb");
    if (!f) return NULL;
    fseek(f, 0, SEEK_END);
    const long n = ftell(f);
    fseek(f, 0, SEEK_SET);
    unsigned char *buf = (unsigned char *)malloc(n > 0 ? (size_t)n : 1);
    if (!buf || fread(buf, 1, (size_t)n, f) != (size_t)n) {
        free(buf);
        fclose(f);
        return NULL;
    }
    fclose(f);
    *sizeOut = n;
    return buf;
}

static int loadBank(TileBank *bank, const char *path, int tileSize,
                    char *message, unsigned messageSize) {
    memset(bank, 0, sizeof *bank);
    long size = 0;
    unsigned char *file = slurp(path, &size);
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

int worldLoadStage(World *world, const char *dataDir, const char *mapName,
                   char *message, unsigned messageSize) {
    memset(world, 0, sizeof *world);
    snprintf(world->dataDir, sizeof world->dataDir, "%s", dataDir);

    char path[1024];
    snprintf(path, sizeof path, "%s/MAP/%s", dataDir, mapName);
    long size = 0;
    unsigned char *map = slurp(path, &size);
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
    for (unsigned b = 0; b < sizeof banks / sizeof banks[0]; b++) {
        snprintf(path, sizeof path, "%s/BG/B_%03d%s.BZ", dataDir,
                 world->scenerySet, banks[b].suffix);
        TileBank *bank = (TileBank *)((char *)world + banks[b].offset);
        if (!loadBank(bank, path, banks[b].size, message, messageSize)) {
            worldFree(world);
            return 0;
        }
    }
    return 1;
}

void worldFree(World *world) {
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
