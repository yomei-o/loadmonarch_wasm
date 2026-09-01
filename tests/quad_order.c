// The 32x32 tiles are built from four 16x16 quadrants named by a four-byte
// record.  0041dc60's neighbours aside, the executable's own order is not
// obvious from the decompilation alone, so this draws all four plausible
// readings of the record side by side: a castle or a mountain assembled the
// wrong way is obvious at a glance.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/bz.h"
#include "../src/gfx.h"

#define TILE_SRC 0x80u
#define QUAD_TABLE 0x7ca0u
#define PLANE_STRIDE 0x20u

static unsigned char planarPixel(const unsigned char *tile, unsigned off,
                                 unsigned bit) {
    const unsigned mask = 0x80u >> bit;
    unsigned v = 0;
    if (tile[off] & mask) v |= 1;
    if (tile[off + PLANE_STRIDE] & mask) v |= 2;
    if (tile[off + PLANE_STRIDE * 2] & mask) v |= 4;
    if (tile[off + PLANE_STRIDE * 3] & mask) v |= 8;
    return (unsigned char)v;
}

int main(int argc, char **argv) {
    if (argc < 4) {
        fprintf(stderr, "usage: quad_order <bank.bz> <tiles> <out.ppm>\n");
        return 2;
    }
    const int shown = atoi(argv[2]);

    FILE *f = fopen(argv[1], "rb");
    if (!f) { perror(argv[1]); return 2; }
    fseek(f, 0, SEEK_END); long n = ftell(f); fseek(f, 0, SEEK_SET);
    unsigned char *src = malloc(n);
    if (fread(src, 1, n, f) != (size_t)n) return 2;
    fclose(f);

    static unsigned char raw[0x8030];
    unsigned produced = 0;
    if (!bzDecompress(src, (unsigned)n, raw, sizeof raw, &produced)) return 1;
    unsigned char pal[256][3];
    memset(pal, 0, sizeof pal);
    gfxTilePalette(raw, produced, &pal[0][0]);

    // Four readings of the record: which byte goes to which corner.
    static const int orders[4][4] = {
        {0, 2, 1, 3},   // TL TR BL BR - what gfx.c uses
        {0, 1, 2, 3},
        {0, 2, 3, 1},
        {2, 0, 3, 1},
    };
    const unsigned W = (unsigned)shown * 32, H = 4 * 32;
    unsigned char *sheet = calloc((size_t)W * H, 1);

    for (int variant = 0; variant < 4; variant++) {
        for (int t = 0; t < shown; t++) {
            const unsigned char *rec = raw + QUAD_TABLE + (unsigned)t * 4u;
            unsigned char q[4][256];
            for (int corner = 0; corner < 4; corner++) {
                const unsigned sub = rec[orders[variant][corner]];
                const unsigned char *tile = raw + sub * TILE_SRC;
                for (unsigned i = 0; i < 256; i++)
                    q[corner][i] = planarPixel(tile, i >> 3, i & 7);
            }
            for (unsigned row = 0; row < 32; row++)
                for (unsigned col = 0; col < 32; col++) {
                    const int corner = (row < 16 ? 0 : 2) + (col < 16 ? 0 : 1);
                    const unsigned char v =
                        q[corner][(row & 15) * 16 + (col & 15)];
                    sheet[(size_t)(variant * 32 + row) * W + t * 32 + col] =
                        (unsigned char)(v + 0x10);
                }
        }
    }
    FILE *o = fopen(argv[3], "wb");
    fprintf(o, "P6\n%u %u\n255\n", W, H);
    for (size_t i = 0; i < (size_t)W * H; i++) fwrite(pal[sheet[i]], 1, 3, o);
    fclose(o);
    printf("wrote %s: four orders, %d tiles each\n", argv[3], shown);
    return 0;
}
