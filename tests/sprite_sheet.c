// Draw a range of a sprite bank's tiles side by side, large, so what the
// sprite numbers actually point at can be judged rather than guessed.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/gfx.h"
#include "../src/host.h"
#include "../src/render.h"
#include "../src/state.h"

int main(int argc, char **argv) {
    if (argc < 5) {
        fprintf(stderr, "usage: sprite_sheet <zip> <zoom> <first> <out.ppm> "
                        "[count]\n");
        return 2;
    }
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
    if (!worldLoadStage(&game.world, &host, "B_003.MAP", message,
                        sizeof message)) {
        fprintf(stderr, "%s\n", message);
        return 1;
    }
    const int zoom = atoi(argv[2]);
    const unsigned first = (unsigned)atoi(argv[3]);
    const unsigned count = argc > 5 ? (unsigned)atoi(argv[5]) : 32;

    // Ask the world for the bank the way the renderer does, but reach past the
    // stand-in so the 8-pixel bank can be seen even while it is unused.
    const TileBank *bank = zoom == 0 ? &game.world.sprites8
                         : (zoom == 2 ? &game.world.sprites32
                                      : &game.world.sprites);
    if (!bank->pixels) { fprintf(stderr, "that bank did not load\n"); return 1; }
    const int ts = bank->tileSize;
    printf("zoom %d: %u tiles of %d, showing %u from %u\n", zoom, bank->tiles,
           ts, count, first);

    const unsigned cols = 8, rows = (count + cols - 1) / cols;
    const unsigned W = cols * (unsigned)ts, H = rows * (unsigned)ts;
    unsigned char *pix = malloc((size_t)W * H);
    memset(pix, CHR_TRANSPARENT, (size_t)W * H);
    for (unsigned i = 0; i < count; i++) {
        const unsigned tile = first + i;
        if (tile >= bank->tiles) break;
        const unsigned char *src = bank->pixels + (size_t)tile * ts * ts;
        for (int y = 0; y < ts; y++)
            for (int x = 0; x < ts; x++)
                pix[(size_t)((i / cols) * ts + y) * W + (i % cols) * ts + x] =
                    src[y * ts + x];
    }
    FILE *o = fopen(argv[4], "wb");
    fprintf(o, "P6\n%u %u\n255\n", W, H);
    for (size_t i = 0; i < (size_t)W * H; i++)
        fwrite(bank->palette[pix[i]], 1, 3, o);
    fclose(o);
    printf("wrote %s\n", argv[4]);
    return 0;
}
