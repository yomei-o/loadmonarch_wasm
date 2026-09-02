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

// 00405fc0's tail.  Records of sixteen bytes at 0x7ea0; thirteen are usable,
// the loader having zeroed bytes 13 to 15 so a full-length name still ends.
// For the five countries the first byte is a palette index rather than a
// letter, and the original writes a space over it - so the names it prints
// begin with one.  Kept as it is, since that is what the game shows.
#define NAME_TABLE_AT 0x7ea0u

static void loadNames(NameTable *names, const unsigned char *raw,
                      unsigned size) {
    memset(names, 0, sizeof *names);
    if (size < NAME_TABLE_AT + NAME_RECORDS * 16u) return;
    for (unsigned r = 0; r < NAME_RECORDS; r++) {
        const unsigned char *record = raw + NAME_TABLE_AT + r * 16u;
        unsigned from = 0;
        if (r >= NAME_COUNTRY && r < NAME_COUNTRY + 5) {
            names->colour[r] = record[0];
            from = 1;
        }
        unsigned out = 0;
        for (unsigned i = from; i < NAME_TEXT && record[i]; i++)
            names->text[r][out++] = (char)record[i];
        // Trailing blanks are padding in some sets; the game shows them, but
        // nothing is lost by not carrying them into a caption.
        while (out > 0 && names->text[r][out - 1] == 0x20) out--;
        names->text[r][out] = 0;
    }
    names->loaded = 1;
}

// MAP/NAME.TXT.  A tiny ini: [entry] carries QESTNAME and MAP, then [0], [1]
// and so on carry NAME and FILE.  Lines beginning // are comments - in the
// Japanese release they are the Japanese titles, and in the English one they
// are what the English titles were translated from.
int worldReadStages(StageList *stages, const Host *host) {
    memset(stages, 0, sizeof *stages);
    static unsigned char text[8192];
    unsigned size = 0;
    if (!hostRead(host, "MAP/NAME.TXT", text, sizeof text - 1, &size)) return 0;
    text[size] = 0;

    int at = -1;                        // which stage block we are inside
    const char *p = (const char *)text;
    while (*p) {
        const char *end = p;
        while (*end && *end != '\n' && *end != '\r') end++;
        const size_t length = (size_t)(end - p);

        if (length > 2 && p[0] == '[') {
            // [entry] or [n]
            at = (p[1] >= '0' && p[1] <= '9') ? atoi(p + 1) : -1;
        } else if (length > 9 && strncmp(p, "QESTNAME=", 9) == 0) {
            const char *value = p + 9;
            const size_t n = length - 9;
            const size_t take = n < STAGE_NAME - 1 ? n : STAGE_NAME - 1;
            memcpy(stages->quest, value, take);
            stages->quest[take] = 0;
        } else if (length > 5 && strncmp(p, "NAME=", 5) == 0) {
            const char *value = p + 5;
            const size_t n = length - 5;
            char *into = at >= 0 && at < STAGE_MAX ? stages->name[at] : NULL;
            if (into) {
                const size_t take = n < STAGE_NAME - 1 ? n : STAGE_NAME - 1;
                memcpy(into, value, take);
                into[take] = 0;
            }
        } else if (length > 5 && strncmp(p, "FILE=", 5) == 0 &&
                   at >= 0 && at < STAGE_MAX) {
            const size_t n = length - 5;
            const size_t take = n < STAGE_FILE - 1 ? n : STAGE_FILE - 1;
            memcpy(stages->file[at], p + 5, take);
            stages->file[at][take] = 0;
            // The file names are written in lower case here and upper case in
            // the archive; the host matches by tail, so make them agree.
            for (char *c = stages->file[at]; *c; c++)
                if (*c >= 'a' && *c <= 'z') *c = (char)(*c - 'a' + 'A');
            if ((unsigned)at + 1 > stages->count) stages->count = (unsigned)at + 1;
        }

        p = end;
        while (*p == '\n' || *p == '\r') p++;
    }
    return stages->count > 0;
}

// SOUND.CFG, the same ini shape as NAME.TXT.  Only the blocks that name a
// MIDI file are kept - the rest are sound effects this release does not ship.
int worldReadTunes(TuneList *tunes, const Host *host) {
    memset(tunes, 0, sizeof *tunes);
    static unsigned char text[16384];
    unsigned size = 0;
    if (!hostRead(host, "SOUND/SOUND.CFG", text, sizeof text - 1, &size))
        return 0;
    text[size] = 0;

    int entry = -1;
    unsigned char loops = 0;
    char name[TUNE_NAME] = {0};
    int hasFile = 0;
    const char *p = (const char *)text;

    for (;;) {
        const char *end = p;
        while (*end && *end != 10 && *end != 13) end++;
        const size_t length = (size_t)(end - p);

        const int newBlock = length > 2 && p[0] == '[';
        if ((newBlock || *p == 0) && entry >= 0 && hasFile &&
            tunes->count < TUNE_MAX) {
            const unsigned at = tunes->count++;
            tunes->entry[at] = (unsigned)entry;
            tunes->loops[at] = loops;
            memcpy(tunes->name[at], name, sizeof name);
        }
        if (newBlock) {
            entry = -1;
            loops = 0;
            hasFile = 0;
            name[0] = 0;
        } else if (length > 6 && strncmp(p, "ENTRY=", 6) == 0) {
            entry = atoi(p + 6);
        } else if (length > 5 && strncmp(p, "LOOP=", 5) == 0) {
            loops = (unsigned char)atoi(p + 5);
        } else if (length > 5 && strncmp(p, "MIDI=", 5) == 0) {
            hasFile = length > 6;       // "MIDI=" with nothing after it is none
        } else if (length > 5 && strncmp(p, "NAME=", 5) == 0) {
            size_t take = length - 5;
            if (take > TUNE_NAME - 1) take = TUNE_NAME - 1;
            memcpy(name, p + 5, take);
            name[take] = 0;
        }

        if (*end == 0) break;
        p = end;
        while (*p == 10 || *p == 13) p++;
    }
    return tunes->count > 0;
}

static int loadBank(TileBank *bank, const Host *host, const char *path,
                    int tileSize, NameTable *names, char *message,
                    unsigned messageSize) {
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
    if (names) loadNames(names, raw, produced);
    free(raw);
    return 1;
}

const char *worldCountryName(const World *world, unsigned faction) {
    if (!world->names.loaded || faction >= 5) return "";
    return world->names.text[NAME_COUNTRY + faction];
}

const char *worldOrderName(const World *world, unsigned order) {
    if (!world->names.loaded || order >= 16) return "";
    return world->names.text[NAME_ORDER + order];
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
        world->cells[i].occupant = 0x40;
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
        // Only the large file carries the name table.
        if (!loadBank(bank, host, path, banks[b].size,
                      banks[b].size == 32 ? &world->names : NULL, message,
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
    // 00422740 picks a bank by tile size, so each zoom draws from its own and
    // nothing is scaled.  The 8-pixel bank looked like an alphabet until
    // 0041b520 was read: those glyph-like tiles are the leader badges, and the
    // numbering is shared across all three banks.
    if (zoom >= 2 && world->sprites32.pixels) return &world->sprites32;
    if (zoom <= 0 && world->sprites8.pixels) return &world->sprites8;
    return &world->sprites;
}

const TileBank *worldBank(const World *world, int zoom) {
    if (zoom <= 0) return &world->bank8;
    if (zoom == 1) return &world->bank16;
    return &world->bank32;
}
