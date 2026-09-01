// Decompress a .BZ, unpack its tiles, and write them as a PNG-able PPM sheet
// coloured with the game's own palette so the result can be judged by eye.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/bz.h"
#include "../src/gfx.h"

int main(int argc, char **argv) {
    if (argc < 5) {
        fprintf(stderr, "usage: tiles_test <in.bz> <tileSize> <pal.rgb> <out.ppm>\n");
        return 2;
    }
    const int tileSize = atoi(argv[2]);

    FILE *f = fopen(argv[1], "rb");
    if (!f) { perror(argv[1]); return 2; }
    fseek(f, 0, SEEK_END); long n = ftell(f); fseek(f, 0, SEEK_SET);
    unsigned char *src = malloc(n);
    if (fread(src, 1, n, f) != (size_t)n) return 2;
    fclose(f);

    static unsigned char raw[0x8030];
    unsigned produced = 0;
    bzDecompress(src, (unsigned)n, raw, sizeof raw, &produced);
    printf("%s: %ld -> %u bytes\n", argv[1], n, produced);

    static unsigned char pix[0x80 * 32 * 32];
    unsigned tiles = 0;
    if (!gfxUnpackTiles(raw, produced, tileSize, pix, sizeof pix, &tiles)) {
        fprintf(stderr, "unpack failed\n");
        return 1;
    }

    // The palette: 224 RGBQUADs starting at index 0x10, which is exactly
    // where 00406810 puts the tile indices.
    unsigned char pal[256][3];
    memset(pal, 0, sizeof pal);
    FILE *p = fopen(argv[3], "rb");
    if (p) {
        unsigned char e[4];
        for (int i = 0x10; i < 0x100 && fread(e, 1, 4, p) == 4; i++) {
            pal[i][0] = e[2]; pal[i][1] = e[1]; pal[i][2] = e[0];
        }
        fclose(p);
    }

    const unsigned cols = 16, rows = tiles / cols;
    const unsigned W = cols * tileSize, H = rows * tileSize;
    FILE *o = fopen(argv[4], "wb");
    fprintf(o, "P6\n%u %u\n255\n", W, H);
    for (unsigned y = 0; y < H; y++) {
        for (unsigned x = 0; x < W; x++) {
            const unsigned t = (y / tileSize) * cols + (x / tileSize);
            const unsigned v = pix[t * tileSize * tileSize
                                   + (y % tileSize) * tileSize + (x % tileSize)];
            fwrite(pal[v], 1, 3, o);
        }
    }
    fclose(o);
    printf("wrote %s  %ux%u  %u tiles of %d\n", argv[4], W, H, tiles, tileSize);
    return 0;
}
