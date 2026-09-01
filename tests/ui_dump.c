// Draw the interface sheet, or a region of it, in the colours the game gives
// it - data1.rgb's first 48 entries land at palette index 0x80, which is where
// the sheet's own bias puts its pixels.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/bz.h"
#include "../src/gfx.h"
#include "../src/host.h"

#define SHEET_W 256
#define SHEET_BYTES 0x40000

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "usage: ui_dump <zip|dir> <out.ppm> [y0] [rows]\n");
        return 2;
    }
    static Host host;
    const size_t length = strlen(argv[1]);
    if (length > 4 && strcmp(argv[1] + length - 4, ".zip") == 0) {
        FILE *f = fopen(argv[1], "rb");
        if (!f) { perror(argv[1]); return 2; }
        fseek(f, 0, SEEK_END);
        const long size = ftell(f);
        fseek(f, 0, SEEK_SET);
        unsigned char *archive = malloc((size_t)size);
        if (!archive || fread(archive, 1, (size_t)size, f) != (size_t)size)
            return 2;
        fclose(f);
        if (!hostUseZip(&host, archive, (unsigned)size)) return 1;
    } else if (!hostUseDirectory(&host, argv[1])) {
        return 1;
    }

    static unsigned char file[SHEET_BYTES];
    unsigned got = 0;
    if (!hostRead(&host, "DATA/DATA1.BZ", file, sizeof file, &got)) return 1;
    unsigned char *raw = malloc(SHEET_BYTES);
    unsigned produced = 0;
    if (!raw || !bzDecompress(file, got, raw, SHEET_BYTES, &produced)) return 1;

    // 00407560's layout: a run of 16x16 tiles into a 256-wide sheet, 0x1f
    // meaning transparent, everything else biased by 0x70.
    unsigned char *sheet = calloc(SHEET_BYTES, 1);
    unsigned s = 0;
    for (unsigned band = 0; band < SHEET_BYTES; band += 0x1000) {
        for (unsigned col = 0; col < 16; col++) {
            unsigned d = band + col * 16;
            for (unsigned row = 0; row < 16; row++) {
                for (unsigned x = 0; x < 16; x++) {
                    const unsigned char v = raw[s + x];
                    sheet[d + x] = (v == 0x1f) ? 0x70
                                               : (unsigned char)(v + 0x70);
                }
                s += 16;
                d += SHEET_W;
            }
        }
    }

    unsigned char pal[256][3];
    memset(pal, 0, sizeof pal);
    unsigned char rgb[896];
    unsigned rgbGot = 0;
    if (hostRead(&host, "DATA/DATA1.RGB", rgb, sizeof rgb, &rgbGot))
        gfxUiPalette(rgb, rgbGot, &pal[0][0]);

    const unsigned y0 = argc > 3 ? (unsigned)atoi(argv[3]) : 0;
    unsigned rows = argc > 4 ? (unsigned)atoi(argv[4])
                             : SHEET_BYTES / SHEET_W - y0;
    if (y0 + rows > SHEET_BYTES / SHEET_W) rows = SHEET_BYTES / SHEET_W - y0;

    FILE *o = fopen(argv[2], "wb");
    fprintf(o, "P6\n%u %u\n255\n", SHEET_W, rows);
    for (unsigned y = 0; y < rows; y++)
        for (unsigned x = 0; x < SHEET_W; x++)
            fwrite(pal[sheet[(y0 + y) * SHEET_W + x]], 1, 3, o);
    fclose(o);
    printf("wrote %s: rows %u..%u of the interface sheet\n", argv[2], y0,
           y0 + rows);
    return 0;
}
