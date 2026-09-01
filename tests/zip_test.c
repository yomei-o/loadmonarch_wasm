// Pull every file the game needs out of the real zip and check the sizes
// against what the format work established.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/zip.h"

static int failures;

static void expect(const char *what, long got, long want) {
    if (got != want) {
        printf("  FAIL %-30s got %ld want %ld\n", what, got, want);
        failures++;
    }
}

int main(int argc, char **argv) {
    const char *path = argc > 1 ? argv[1] : "ds7e.zip";
    FILE *f = fopen(path, "rb");
    if (!f) { perror(path); return 2; }
    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);
    unsigned char *data = malloc(size);
    if (fread(data, 1, size, f) != (size_t)size) return 2;
    fclose(f);

    Zip zip;
    if (!zipOpen(&zip, data, (unsigned)size)) {
        printf("  FAIL could not open the zip\n");
        return 1;
    }
    printf("%s: %ld bytes, %u entries\n", path, size, zip.entryCount);

    static unsigned char out[0x60000];
    unsigned got = 0;

    // A map: 0x902 bytes, and the trailer names its scenery set.
    if (!zipRead(&zip, "MAP/B_000.MAP", out, sizeof out, &got)) {
        printf("  FAIL could not read MAP/B_000.MAP\n");
        failures++;
    } else {
        expect("B_000.MAP size", got, 0x902);
        expect("B_000.MAP scenery set", out[0x900], 10);
    }

    // A tile bank, still compressed - the .BZ is a file inside the zip.
    if (!zipRead(&zip, "BG/B_010M.BZ", out, sizeof out, &got)) {
        printf("  FAIL could not read BG/B_010M.BZ\n");
        failures++;
    } else {
        expect("B_010M.BZ size", got, 7475);
    }

    // The interface art and the palette.
    if (!zipRead(&zip, "DATA/DATA1.BZ", out, sizeof out, &got)) {
        printf("  FAIL could not read DATA/DATA1.BZ\n");
        failures++;
    } else {
        expect("DATA1.BZ size", got, 22795);
    }
    if (!zipRead(&zip, "DATA/DATA1.RGB", out, sizeof out, &got)) {
        printf("  FAIL could not read DATA/DATA1.RGB\n");
        failures++;
    } else {
        expect("DATA1.RGB size", got, 896);
    }

    // A 256-colour still, which is stored uncompressed and large.
    if (!zipRead(&zip, "DATA/LOGO.256", out, sizeof out, &got)) {
        printf("  FAIL could not read DATA/LOGO.256\n");
        failures++;
    } else {
        expect("LOGO.256 size", got, 49160);
        expect("LOGO.256 width", (long)(out[0] | (out[1] << 8)), 256);
        expect("LOGO.256 height", (long)(out[4] | (out[5] << 8)), 192);
    }

    // Something that is not there must fail rather than return rubbish.
    if (zipRead(&zip, "MAP/NOPE.MAP", out, sizeof out, &got)) {
        printf("  FAIL a missing entry appeared to read\n");
        failures++;
    }

    printf(failures ? "%d check(s) failed\n" : "zip checks ok\n", failures);
    return failures ? 1 : 0;
}
