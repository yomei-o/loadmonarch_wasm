// data1.bz holds the interface art: a linear run of 16x16 tiles that
// 00407560 lays out into a 256-pixel-wide sheet, biasing every value by 0x70
// and treating 0x1f as the transparent one.  Unlike the BG and CHR banks this
// payload is not planar - it decompresses straight to palette indices, which
// arrive in 0x11..0x30 and land in 0x81..0xa0 after the bias.
#include <stdio.h>
#include <stdlib.h>
#include "../src/bz.h"

#define SHEET_W 256
#define TOTAL   0x40000

int main(int argc, char **argv) {
    if (argc < 3) { fprintf(stderr, "usage: data1_test <data1.bz> <out.pgm>\n"); return 2; }
    FILE *f = fopen(argv[1], "rb");
    if (!f) { perror(argv[1]); return 2; }
    fseek(f, 0, SEEK_END); long n = ftell(f); fseek(f, 0, SEEK_SET);
    unsigned char *src = malloc(n);
    if (fread(src, 1, n, f) != (size_t)n) return 2;
    fclose(f);

    unsigned char *raw = malloc(TOTAL);
    unsigned produced = 0;
    if (!bzDecompress(src, (unsigned)n, raw, TOTAL, &produced)) {
        fprintf(stderr, "decompress failed\n"); return 1;
    }
    printf("%s: %ld -> %u\n", argv[1], n, produced);

    unsigned char *sheet = calloc(TOTAL, 1);
    unsigned s = 0;                       // source byte cursor
    for (unsigned band = 0; band < TOTAL; band += 0x1000) {
        for (unsigned col = 0; col < 16; col++) {
            unsigned d = band + col * 16;
            for (unsigned row = 0; row < 16; row++) {
                for (unsigned x = 0; x < 16; x++) {
                    const unsigned char v = raw[s + x];
                    sheet[d + x] = (v == 0x1f) ? 0x70 : (unsigned char)(v + 0x70);
                }
                s += 16;
                d += SHEET_W;
            }
        }
    }
    const unsigned h = TOTAL / SHEET_W;
    FILE *o = fopen(argv[2], "wb");
    fprintf(o, "P5\n%u %u\n255\n", SHEET_W, h);
    // The sheet holds palette indices; write them raw and let the viewer
    // colour them.  0x1f - the transparent one - biases to 0x8f.
    fwrite(sheet, 1, TOTAL, o);
    fclose(o);
    printf("wrote %s %ux%u\n", argv[2], SHEET_W, h);
    return 0;
}
