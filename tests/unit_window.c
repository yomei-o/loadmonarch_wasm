// Compose the Unit Window the way 00426900 does and write it out, so the
// layout can be looked at rather than guessed.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../src/host.h"
#include "../src/world.h"

#define W 176
#define H 176

static unsigned char px[H][W];

static void blit(const World *w, int sx, int sy, int bw, int bh, int dx, int dy) {
    for (int y = 0; y < bh; y++)
        for (int x = 0; x < bw; x++) {
            const int ax = sx + x, ay = sy + y, tx = dx + x, ty = dy + y;
            if (ax < 0 || ay < 0 || ax >= UI_SHEET_W || ay >= UI_SHEET_H) continue;
            if (tx < 0 || ty < 0 || tx >= W || ty >= H) continue;
            const unsigned char v = w->ui.pixels[(size_t)ay * UI_SHEET_W + ax];
            if (v != UI_TRANSPARENT) px[ty][tx] = v;
        }
}

int main(int argc, char **argv) {
    static Host h; FILE*f=fopen("ds7e.zip","rb"); fseek(f,0,SEEK_END); long s=ftell(f);
    fseek(f,0,SEEK_SET); unsigned char*a=malloc(s); fread(a,1,s,f); fclose(f);
    hostUseZip(&h,a,(unsigned)s);
    static World w; char m[256];
    if (!worldLoadStage(&w,&h,"B_003.MAP",m,sizeof m)) { puts(m); return 1; }

    const int top = argc > 1 ? atoi(argv[1]) : 110;
    memset(px, UI_TRANSPARENT, sizeof px);
    blit(&w, 0, top, W, H, 0, 0);

    // the 32-pixel tile of a settlement, where the routine puts it
    const unsigned char terrain = 8;
    const unsigned char *tile = w.bank32.pixels + (size_t)terrain * 32 * 32;
    for (int y = 0; y < 32; y++)
        for (int x = 0; x < 32; x++) px[112 + y][16 + x] = tile[y * 32 + x];

    // the number 0123 in the large white font, right-aligned at x=152, y=120
    const char *text = "0123";
    for (int i = 0; i < 4; i++) {
        const int d = text[3 - i] - '0';
        blit(&w, d * 8, 0, 8, 16, 152 - (i + 1) * 8, 120);
    }
    // ten gauge pieces along y=96 from x=72
    for (int i = 0; i < 10; i++) blit(&w, i * 8, 64, 8, 16, 72 + i * 8, 96);

    FILE *o = fopen(argc > 2 ? argv[2] : "tests/unitwin.ppm", "wb");
    fprintf(o, "P6\n%d %d\n255\n", W, H);
    for (int y = 0; y < H; y++)
        for (int x = 0; x < W; x++) {
            const unsigned char v = px[y][x];
            const unsigned char *rgb = (v >= 0x80 && v < 0xb0) ? w.ui.palette[v]
                                     : (v >= 0x30 && v < 0x40) ? w.sprites.palette[v]
                                     : w.bank32.palette[v];
            fwrite(rgb, 1, 3, o);
        }
    fclose(o);
    printf("top %d -> %s\n", top, argc > 2 ? argv[2] : "tests/unitwin.ppm");
    return 0;
}
