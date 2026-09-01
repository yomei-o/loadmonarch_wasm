// Draw the same number in each of the four fonts, so a wrong row or a wrong
// palette shows up at once.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/host.h"
#include "../src/render.h"
#include "../src/state.h"

int main(int argc, char **argv) {
    if (argc < 3) { fprintf(stderr, "usage: font_probe <zip> <out.ppm>\n"); return 2; }
    static Host host;
    FILE *f = fopen(argv[1], "rb");
    if (!f) { perror(argv[1]); return 2; }
    fseek(f, 0, SEEK_END); long size = ftell(f); fseek(f, 0, SEEK_SET);
    unsigned char *archive = malloc((size_t)size);
    if (!archive || fread(archive, 1, (size_t)size, f) != (size_t)size) return 2;
    fclose(f);
    if (!hostUseZip(&host, archive, (unsigned)size)) return 1;

    static GameState game;
    char message[256];
    if (!worldLoadStage(&game.world, &host, "B_000.MAP", message,
                        sizeof message)) {
        fprintf(stderr, "%s\n", message);
        return 1;
    }
    printf("ui sheet %s\n", game.world.ui.pixels ? "loaded" : "MISSING");

    const int W = 200, H = 80;
    static unsigned char pix[200 * 80];
    memset(pix, UI_TRANSPARENT, sizeof pix);
    Surface s;
    surfaceInit(&s, W, H, pix);
    for (int font = 0; font < 4; font++)
        renderNumber(&game.world, (UiFont)font, 80, font * 18, 1234567u, &s);

    FILE *o = fopen(argv[2], "wb");
    fprintf(o, "P6\n%d %d\n255\n", W, H);
    for (int i = 0; i < W * H; i++)
        fwrite(game.world.ui.palette[pix[i]], 1, 3, o);
    fclose(o);
    printf("wrote %s\n", argv[2]);
    return 0;
}
