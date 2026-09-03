// Draw dialog 105 in one of its five modes and write it out, so the window
// can be looked at without opening one.
//
//   endstage_shot <zip> <mode 0..4> <out.ppm> [tick]
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/endstage.h"
#include "../src/host.h"
#include "../src/render.h"
#include "../src/ui.h"
#include "../src/world.h"

int main(int argc, char **argv) {
    if (argc < 4) {
        fprintf(stderr, "usage: endstage_shot <zip> <mode> <out.ppm> [tick]\n");
        return 2;
    }
    const int mode = atoi(argv[2]);
    const int tick = argc > 4 ? atoi(argv[4]) : 0;

    static Host host;
    FILE *f = fopen(argv[1], "rb");
    if (!f) { perror(argv[1]); return 2; }
    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);
    unsigned char *bytes = (unsigned char *)malloc((size_t)size);
    if (!bytes || fread(bytes, 1, (size_t)size, f) != (size_t)size) return 2;
    fclose(f);
    if (!hostUseZip(&host, bytes, (unsigned)size)) return 2;

    static World world;
    char message[128];
    if (!worldLoadStage(&world, &host, "B_000.MAP", message, sizeof message)) {
        fprintf(stderr, "%s\n", message);
        return 1;
    }
    static GameState game;
    memset(&game, 0, sizeof game);
    game.world = world;

    static Surface surface;
    static unsigned char pixels[END_W * END_H];
    surfaceInit(&surface, END_W, END_H, pixels);
    memset(pixels, 0, sizeof pixels);

    // A plausible score, so every line has something in it.
    StageScore score;
    memset(&score, 0, sizeof score);
    score.claimable = 1782;
    score.held = 1201;
    score.areaPercent = 67.39f;
    score.penalty = 67;
    score.yourLosses = 3400;
    score.enemyLosses = 8100;
    score.battlePercent = 238.23f;
    score.bonus = 238;
    score.daysLeft = mode == END_TIME_OVER ? 0u : 412u;
    score.remaining = (int)score.daysLeft - (int)score.penalty +
                      (int)score.bonus;

    static EndStage end;
    endStageOpen(&end, mode, &score, 4, "Backroad Euromap",
                 mode == END_WON_AGAIN ? 37 : 0);
    for (int i = 0; i < tick; i++) endStageStep(&end);
    endStageDraw(&surface, &end, &world, 0, 0);

    static unsigned char table[256][3];
    renderPalette(&game, 1, table);

    FILE *out = fopen(argv[3], "wb");
    if (!out) { perror(argv[3]); return 2; }
    fprintf(out, "P6\n%d %d\n255\n", END_W, END_H);
    for (int i = 0; i < END_W * END_H; i++)
        fwrite(table[pixels[i]], 1, 3, out);
    fclose(out);
    printf("wrote %s: mode %d, tick %d\n", argv[3], mode, tick);
    return 0;
}
