// Decompresses every .BZ the game ships and reports what came out.  The
// game's own buffer is 0x8030 bytes, so anything larger is a decoder fault.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/bz.h"

int main(int argc, char **argv) {
    if (argc < 2) { fprintf(stderr, "usage: bz_test <file.bz>...\n"); return 2; }
    // The largest buffer the game hands the decoder: 0x40000 for data1.bz,
    // 0x8030 for the tile banks.
    static unsigned char out[0x40000];
    int bad = 0;
    for (int i = 1; i < argc; i++) {
        FILE *f = fopen(argv[i], "rb");
        if (!f) { printf("%-24s open failed\n", argv[i]); bad++; continue; }
        fseek(f, 0, SEEK_END);
        long n = ftell(f);
        fseek(f, 0, SEEK_SET);
        unsigned char *src = malloc(n);
        if (fread(src, 1, n, f) != (size_t)n) { fclose(f); free(src); bad++; continue; }
        fclose(f);
        unsigned produced = 0;
        const int ok = bzDecompress(src, (unsigned)n, out, sizeof out, &produced);
        printf("%-24s %7ld -> %7u  %s\n", argv[i], n, produced,
               ok ? "ok" : "FAILED");
        if (!ok) bad++;
        free(src);
    }
    printf("%d problem(s)\n", bad);
    return bad ? 1 : 0;
}
