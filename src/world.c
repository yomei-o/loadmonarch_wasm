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

// 00407560: data1.bz is a run of 16x16 tiles laid into a 256-wide sheet, with
// 0x1f meaning transparent and everything else biased by 0x70.  One sheet
// serves every stage, so it is loaded with the first.
static int loadUiSheet(UiSheet *ui, const Host *host) {
    if (ui->pixels) return 1;
    long size = 0;
    unsigned char *file = slurp(host, "DATA/DATA1.BZ", &size);
    if (!file) return 0;
    unsigned char *raw = (unsigned char *)malloc(0x40000);
    unsigned produced = 0;
    if (!raw || !bzDecompress(file, (unsigned)size, raw, 0x40000, &produced)) {
        free(file);
        free(raw);
        return 0;
    }
    free(file);

    ui->pixels = (unsigned char *)calloc(UI_SHEET_W * UI_SHEET_H, 1);
    if (!ui->pixels) { free(raw); return 0; }
    unsigned s = 0;
    for (unsigned band = 0; band < UI_SHEET_W * UI_SHEET_H; band += 0x1000) {
        for (unsigned col = 0; col < 16; col++) {
            unsigned d = band + col * 16;
            for (unsigned row = 0; row < 16; row++) {
                for (unsigned x = 0; x < 16; x++) {
                    const unsigned char v = raw[s + x];
                    ui->pixels[d + x] = v == 0x1f
                        ? UI_TRANSPARENT : (unsigned char)(v + 0x70);
                }
                s += 16;
                d += UI_SHEET_W;
            }
        }
    }
    free(raw);

    long rgbSize = 0;
    unsigned char *rgb = slurp(host, "DATA/DATA1.RGB", &rgbSize);
    if (rgb) {
        gfxUiPalette(rgb, (unsigned)rgbSize, &ui->palette[0][0]);
        free(rgb);
    }
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
    loadUiSheet(&world->ui, host);

    // The same byte the original hands to 00405fc0.
    static const struct { const char *suffix; int size; size_t offset; } banks[] = {
        {"s", 8, offsetof(World, bank8)},
        {"m", 16, offsetof(World, bank16)},
        {"l", 32, offsetof(World, bank32)},
    };
    // The sprite banks, whose palette 004065e0 puts at 0x30 and which
    // 00406c70 unpacks with its own bias and rearrangements.  A stage missing
    // one still plays; the units are drawn from whichever bank did load.
    {
        // 8 pixels: one file, cut into quarters.
        char p8[256];
        snprintf(p8, sizeof p8, "CHR/C_%03ds.BZ", world->scenerySet);
        long size8 = 0;
        unsigned char *f8 = slurp(host, p8, &size8);
        if (f8) {
            unsigned char *raw = (unsigned char *)malloc(BANK_BUFFER);
            unsigned produced = 0;
            if (raw && bzDecompress(f8, (unsigned)size8, raw, BANK_BUFFER,
                                    &produced)) {
                const unsigned bytes = CHR_TILES8 * 8u * 8u;
                world->sprites8.pixels = (unsigned char *)malloc(bytes);
                if (world->sprites8.pixels &&
                    gfxUnpackSprites8(raw, produced, world->sprites8.pixels,
                                      bytes, &world->sprites8.tiles)) {
                    world->sprites8.tileSize = 8;
                    gfxSpritePalette(raw, produced,
                                     &world->sprites8.palette[0][0]);
                } else {
                    free(world->sprites8.pixels);
                    world->sprites8.pixels = NULL;
                }
            }
            free(raw);
            free(f8);
        }

        // 32 pixels: four files, sixty-four tiles each, merged in fours.
        const unsigned bytes32 = 4u * CHR_TILES32_PER_FILE * 32u * 32u;
        world->sprites32.pixels = (unsigned char *)malloc(bytes32);
        if (world->sprites32.pixels) {
            unsigned tiles32 = 0;
            for (int part = 1; part <= 4; part++) {
                char p32[256];
                snprintf(p32, sizeof p32, "CHR/C_%03dL%d.BZ",
                         world->scenerySet, part);
                long size32 = 0;
                unsigned char *f32 = slurp(host, p32, &size32);
                if (!f32) continue;
                unsigned char *raw = (unsigned char *)malloc(BANK_BUFFER);
                unsigned produced = 0;
                if (raw && bzDecompress(f32, (unsigned)size32, raw,
                                        BANK_BUFFER, &produced)) {
                    unsigned made = 0;
                    unsigned char *at = world->sprites32.pixels +
                                        (size_t)tiles32 * 32u * 32u;
                    if (gfxUnpackSprites32(raw, produced, at,
                                           CHR_TILES32_PER_FILE * 1024u,
                                           &made)) {
                        tiles32 += made;
                        if (part == 1)
                            gfxSpritePalette(raw, produced,
                                             &world->sprites32.palette[0][0]);
                    }
                }
                free(raw);
                free(f32);
            }
            if (tiles32) {
                world->sprites32.tiles = tiles32;
                world->sprites32.tileSize = 32;
            } else {
                free(world->sprites32.pixels);
                world->sprites32.pixels = NULL;
            }
        }
    }
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
    free(world->ui.pixels);
    world->ui.pixels = NULL;
    free(world->sprites.pixels);
    free(world->sprites8.pixels);
    free(world->sprites32.pixels);
    world->sprites.pixels = NULL;
    world->sprites8.pixels = NULL;
    world->sprites32.pixels = NULL;
    free(world->bank8.pixels);
    free(world->bank16.pixels);
    free(world->bank32.pixels);
    world->bank8.pixels = world->bank16.pixels = world->bank32.pixels = NULL;
}

const TileBank *worldSprites(const World *world, int zoom) {
    if (zoom >= 2 && world->sprites32.pixels) return &world->sprites32;
    // The 8-pixel bank is loaded and unpacked, but not used: the sprite number
    // 1833 works out lands on letter glyphs in it, so that bank is numbered
    // differently and how has not been read.  Drawing from the 16-pixel one
    // scaled is wrong in a way that looks right, which is better than drawing
    // the alphabet.
    (void)zoom;
    return &world->sprites;
}

const TileBank *worldBank(const World *world, int zoom) {
    if (zoom <= 0) return &world->bank8;
    if (zoom == 1) return &world->bank16;
    return &world->bank32;
}
