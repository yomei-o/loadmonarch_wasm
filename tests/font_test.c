// Every string the game supplies, drawn with the port's own font onto a plain
// surface - so a missing glyph is obvious instead of being lost against the
// map.  Writes a PPM; also fails outright if the font has no glyph for
// something the game actually says.
//
// It walks every stage MAP/NAME.TXT lists, because each scenery set names the
// countries and the orders differently and the font is a subset - the whole
// campaign is the only thing that proves the subset is enough.  The PPM it
// writes is of the first stage.
//
//   tests/font_test.exe <zip|dir> [out.ppm]
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/font.h"
#include "../src/font16.h"
#include "../src/host.h"
#include "../src/render.h"
#include "../src/state.h"
#include "../src/world.h"

#define W 512
#define H 400

static int failures;
static unsigned char surface[W * H];

static int isLead(unsigned char c) {
    return (c >= 0x81 && c <= 0x9f) || (c >= 0xe0 && c <= 0xef);
}

// The same search fontDrawText does, so this can say which character is out.
static int haveWide(unsigned code) {
    for (unsigned i = 0; i < kFontWideCount; i++)
        if (kFontWideCode[i] == code) return 1;
    return 0;
}

static int blank(const unsigned char *glyph, int n) {
    for (int i = 0; i < n; i++) if (glyph[i]) return 0;
    return 1;
}

static void check(const char *what, const char *text) {
    for (const unsigned char *p = (const unsigned char *)text; *p;) {
        if (isLead(p[0]) && p[1]) {
            const unsigned code = ((unsigned)p[0] << 8) | p[1];
            if (!haveWide(code)) {
                printf("  FAIL %s: no glyph for %04x\n", what, code);
                failures++;
            }
            p += 2;
        } else {
            if (p[0] > 0x20 && blank(kFontHalf[p[0]], 16)) {
                printf("  FAIL %s: no glyph for %02x\n", what, p[0]);
                failures++;
            }
            p++;
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "usage: font_test <zip|dir> [out.ppm]\n");
        return 2;
    }
    const char *ppmPath = argc > 2 ? argv[2] : NULL;
    static Host host;
    const size_t length = strlen(argv[1]);
    if (length > 4 && strcmp(argv[1] + length - 4, ".zip") == 0) {
        FILE *f = fopen(argv[1], "rb");
        if (!f) { perror(argv[1]); return 2; }
        fseek(f, 0, SEEK_END);
        const long size = ftell(f);
        fseek(f, 0, SEEK_SET);
        unsigned char *bytes = (unsigned char *)malloc((size_t)size);
        if (!bytes || fread(bytes, 1, (size_t)size, f) != (size_t)size) return 2;
        fclose(f);
        if (!hostUseZip(&host, bytes, (unsigned)size)) return 2;
    } else if (!hostUseDirectory(&host, argv[1])) {
        return 2;
    }

    // StageList holds the names as a two-dimensional array of characters, not
    // as pointers, so it is indexed rather than cast.
    static StageList stages;
    unsigned count = 1;
    int haveList = worldReadStages(&stages, &host);
    if (haveList) count = stages.count;

    static GameState game;
    char message[256];
    for (unsigned st = 0; st < count; st++) {
        const char *stage = haveList ? stages.file[st] : "B_000.MAP";
        if (!worldLoadStage(&game.world, &host, stage, message,
                            sizeof message)) {
            printf("  FAIL %s: %s\n", stage, message);
            failures++;
            continue;
        }
        for (unsigned f = 0; f < 5; f++) {
            const char *name = worldCountryName(&game.world, f);
            if (name && *name) check(stage, name);
        }
        for (unsigned o = 0; o < 16; o++) {
            const char *name = worldOrderName(&game.world, o);
            if (name && *name) check(stage, name);
        }
        if (st + 1 < count) worldFree(&game.world);
    }

    Surface out;
    memset(surface, 0, sizeof surface);
    surfaceInit(&out, W, H, surface);
    const unsigned char ink = fontInk(&game.world, UI_FONT_LARGE_WHITE);

    int y = 4;
    for (unsigned f = 0; f < 5; f++) {
        const char *name = worldCountryName(&game.world, f);
        if (!name || !*name) continue;
        fontDrawText(&out, 4, y, ink, name);
        y += 18;
    }
    y += 8;
    for (unsigned o = 0; o < 16; o++) {
        const char *name = worldOrderName(&game.world, o);
        if (!name || !*name) continue;
        fontDrawText(&out, 4, y, ink, name);
        y += 18;
    }

    // And the strings the executable carries itself, which are ASCII.
    static const char *fixed[] = {
        "Area Occupied: 12.34", "Leader Strength: 9999", "Unit Totals: 9999",
        "Defeated", "has Fallen", "Break alliance", "Repairing paths",
    };
    for (unsigned i = 0; i < sizeof fixed / sizeof fixed[0]; i++) {
        check("fixed", fixed[i]);
        fontDrawText(&out, 260, 4 + (int)i * 18, ink, fixed[i]);
    }

    if (ppmPath) {
        unsigned char palette[256][3];
        renderPalette(&game, 1, palette);
        FILE *ppm = fopen(ppmPath, "wb");
        if (!ppm) { perror(ppmPath); return 2; }
        fprintf(ppm, "P6\n%d %d\n255\n", W, H);
        for (int i = 0; i < W * H; i++)
            fwrite(palette[surface[i]], 1, 3, ppm);
        fclose(ppm);
        printf("  wrote %s\n", ppmPath);
    }
    printf("  the font carries %u full-width glyphs; %u stages checked\n",
           kFontWideCount, count);
    printf(failures ? "%d font check(s) failed\n" : "font checks ok\n",
           failures);
    worldFree(&game.world);
    return failures ? 1 : 0;
}
