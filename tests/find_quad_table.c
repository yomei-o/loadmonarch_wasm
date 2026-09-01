// Tile N of the 32x32 bank must depict the same terrain as tile N of the
// 16x16 bank - the map uses one terrain byte for every zoom.  So the quadrant
// table's position can be found rather than assumed: try every offset and
// score how well the assembled 32x32 tiles match the 16x16 ones halved.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/bz.h"
#include "../src/gfx.h"

#define TILE_SRC 0x80u
#define PLANE_STRIDE 0x20u
#define TILES 0x80u

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

static unsigned char *load(const char *path, unsigned *producedOut) {
    FILE *f = fopen(path, "rb");
    if (!f) return NULL;
    fseek(f, 0, SEEK_END); long n = ftell(f); fseek(f, 0, SEEK_SET);
    unsigned char *src = malloc(n);
    if (fread(src, 1, n, f) != (size_t)n) { free(src); fclose(f); return NULL; }
    fclose(f);
    unsigned char *raw = malloc(0x8030);
    if (!bzDecompress(src, (unsigned)n, raw, 0x8030, producedOut)) {
        free(src); free(raw); return NULL;
    }
    free(src);
    return raw;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "usage: find_quad_table <medium.bz> <large.bz>\n");
        return 2;
    }
    unsigned mProduced = 0, lProduced = 0;
    unsigned char *m = load(argv[1], &mProduced);
    unsigned char *l = load(argv[2], &lProduced);
    if (!m || !l) { fprintf(stderr, "load failed\n"); return 2; }

    // The 16x16 reference tiles.
    static unsigned char ref[TILES][256];
    for (unsigned t = 0; t < TILES; t++)
        for (unsigned i = 0; i < 256; i++)
            ref[t][i] = planarPixel(m + t * TILE_SRC, i >> 3, i & 7);

    long best = -1;
    unsigned bestOffset = 0;
    static const int order[4] = {0, 2, 1, 3};   // TL TR BL BR
    for (unsigned off = 0; off + TILES * 4 <= 0x8030u; off += 4) {
        long score = 0;
        for (unsigned t = 0; t < TILES; t++) {
            const unsigned char *rec = l + off + t * 4u;
            // Halve the assembled 32x32 by taking every other pixel, then
            // compare with the 16x16 tile of the same number.
            for (unsigned row = 0; row < 16; row++) {
                for (unsigned col = 0; col < 16; col++) {
                    const unsigned sr = row * 2, sc = col * 2;
                    const int corner = (sr < 16 ? 0 : 2) + (sc < 16 ? 0 : 1);
                    const unsigned sub = rec[order[corner]];
                    const unsigned char v = planarPixel(
                        l + sub * TILE_SRC,
                        ((sr & 15) * 16 + (sc & 15)) >> 3,
                        ((sr & 15) * 16 + (sc & 15)) & 7);
                    if (v == ref[t][row * 16 + col]) score++;
                }
            }
        }
        if (score > best) { best = score; bestOffset = off; }
    }
    const long total = (long)TILES * 256;
    printf("best offset %#x  score %ld / %ld  (%.1f%%)\n",
           bestOffset, best, total, 100.0 * best / total);
    printf("gfx.c currently uses 0x7ca0\n");
    return 0;
}
