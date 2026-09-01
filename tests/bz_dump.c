// Decompress one .BZ into the game's own 0x8030 buffer and write the result
// as a PGM, so the tiles can be looked at rather than trusted.
#include <stdio.h>
#include <stdlib.h>
#include "../src/bz.h"

int main(int argc, char **argv) {
    if (argc < 3) { fprintf(stderr, "usage: bz_dump <in.bz> <out.pgm>\n"); return 2; }
    FILE *f = fopen(argv[1], "rb");
    if (!f) return 2;
    fseek(f, 0, SEEK_END); long n = ftell(f); fseek(f, 0, SEEK_SET);
    unsigned char *src = malloc(n);
    if (fread(src, 1, n, f) != (size_t)n) return 2;
    fclose(f);
    static unsigned char out[0x8030];
    unsigned produced = 0;
    const int ok = bzDecompress(src, (unsigned)n, out, sizeof out, &produced);
    printf("%s: %ld -> %u of %u  %s\n", argv[1], n, produced,
           (unsigned)sizeof out, ok ? "ok" : "clamped/failed");
    // 0x30 header, then 0x8000 of pixels: lay them out 128 bytes wide.
    const unsigned off = 0x30, W = 128, H = 0x8000 / W;
    FILE *o = fopen(argv[2], "wb");
    fprintf(o, "P5\n%u %u\n255\n", W, H);
    fwrite(out + off, 1, (size_t)W * H, o);
    fclose(o);
    printf("header: ");
    for (int i = 0; i < 16; i++) printf("%02x ", out[i]);
    printf("\n");
    return 0;
}
