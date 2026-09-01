// Work out how the CHR bank is laid out rather than guess: classify each of
// its 128 tiles by the colour that dominates it, and print the grid.  The
// four factions are told apart by colour on screen, so their grouping falls
// straight out of the data.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/bz.h"
#include "../src/gfx.h"
#include "../src/host.h"

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "usage: chr_layout <zip|dir> <CHR/C_010M.BZ>\n");
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

    static unsigned char file[0x40000];
    unsigned got = 0;
    if (!hostRead(&host, argv[2], file, sizeof file, &got)) {
        fprintf(stderr, "cannot read %s\n", argv[2]);
        return 1;
    }
    static unsigned char raw[0x8030];
    unsigned produced = 0;
    if (!bzDecompress(file, got, raw, sizeof raw, &produced)) return 1;

    static unsigned char pix[0x80 * 16 * 16];
    unsigned tiles = 0;
    if (!gfxUnpackTiles(raw, produced, 16, pix, sizeof pix, &tiles)) return 1;
    unsigned char pal[256][3];
    memset(pal, 0, sizeof pal);
    gfxTilePalette(raw, produced, &pal[0][0]);

    // The most common non-background index in each tile, and its colour.
    printf("tile  index  rgb        letter\n");
    char grid[8][17];
    memset(grid, ' ', sizeof grid);
    for (unsigned t = 0; t < tiles; t++) {
        unsigned counts[256] = {0};
        for (unsigned i = 0; i < 256; i++)
            counts[pix[t * 256 + i]]++;
        // Index 0x10 is the transparent one - the tiles sit on it.
        unsigned best = 0, bestCount = 0;
        for (unsigned v = 0x11; v < 0x20; v++)
            if (counts[v] > bestCount) { bestCount = counts[v]; best = v; }
        const int r = pal[best][0], g = pal[best][1], b = pal[best][2];
        char letter = '.';
        if (bestCount == 0) letter = ' ';
        else if (r > g + 40 && r > b + 40) letter = 'R';
        else if (g > r + 40 && g > b + 40) letter = 'G';
        else if (b > r + 40 && b > g + 40) letter = 'B';
        else if (r > b + 40 && g > b + 40) letter = 'Y';
        else letter = 'o';
        grid[t / 16][t % 16] = letter;
        if (t < 8)
            printf("%4u  %#4x   %3d %3d %3d  %c\n", t, best, r, g, b, letter);
    }
    printf("\nlayout, 16 tiles a row (R red, G green, B blue, Y yellow):\n");
    for (int row = 0; row < 8; row++) {
        grid[row][16] = 0;
        printf("  row %d: %s\n", row, grid[row]);
    }
    return 0;
}
