// Draw a stage: the .MAP's 48x48 terrain grid, each cell taking a tile from
// the background bank its own trailer byte selects.
//
// 00405de0 reads the 0x902-byte file, spreads the 2304 cells into 24-byte
// runtime records (terrain at +0x10, a 100 at +0x0c, 0x40 at +0x00), and
// hands the byte at offset 0x900 to the loader at 00405fc0 - which is what
// picks B_%03ds/m/l.bz.  So the trailer is the scenery set, not a difficulty.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/bz.h"
#include "../src/gfx.h"

#define GRID 48

static unsigned char *slurp(const char *path, long *sizeOut) {
    FILE *f = fopen(path, "rb");
    if (!f) return NULL;
    fseek(f, 0, SEEK_END);
    long n = ftell(f);
    fseek(f, 0, SEEK_SET);
    unsigned char *p = malloc(n);
    if (!p || fread(p, 1, n, f) != (size_t)n) { free(p); fclose(f); return NULL; }
    fclose(f);
    *sizeOut = n;
    return p;
}

int main(int argc, char **argv) {
    if (argc < 5) {
        fprintf(stderr, "usage: map_test <x.map> <bank.bz> <tileSize> <out.ppm>\n");
        return 2;
    }
    const int tileSize = atoi(argv[3]);

    long mapSize = 0;
    unsigned char *map = slurp(argv[1], &mapSize);
    if (!map || mapSize != GRID * GRID + 2) {
        fprintf(stderr, "%s: not a 0x902 map\n", argv[1]);
        return 2;
    }
    printf("%s: scenery set %u\n", argv[1], map[0x900]);

    long bankSize = 0;
    unsigned char *bank = slurp(argv[2], &bankSize);
    if (!bank) { perror(argv[2]); return 2; }

    static unsigned char raw[0x8030];
    unsigned produced = 0;
    if (!bzDecompress(bank, (unsigned)bankSize, raw, sizeof raw, &produced)) {
        fprintf(stderr, "bank failed to decompress\n");
        return 1;
    }
    static unsigned char pix[0x80 * 32 * 32];
    unsigned tiles = 0;
    if (!gfxUnpackTiles(raw, produced, tileSize, pix, sizeof pix, &tiles)) {
        fprintf(stderr, "unpack failed\n");
        return 1;
    }
    unsigned char pal[256][3];
    memset(pal, 0, sizeof pal);
    gfxTilePalette(raw, produced, &pal[0][0]);

    const unsigned W = GRID * tileSize, H = GRID * tileSize;
    FILE *o = fopen(argv[4], "wb");
    fprintf(o, "P6\n%u %u\n255\n", W, H);
    for (unsigned y = 0; y < H; y++) {
        for (unsigned x = 0; x < W; x++) {
            const unsigned cell = (y / tileSize) * GRID + (x / tileSize);
            const unsigned tile = map[cell] % tiles;
            const unsigned v = pix[tile * tileSize * tileSize
                                   + (y % tileSize) * tileSize
                                   + (x % tileSize)];
            fwrite(pal[v], 1, 3, o);
        }
    }
    fclose(o);
    printf("wrote %s %ux%u\n", argv[4], W, H);
    return 0;
}
