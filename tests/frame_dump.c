// Render one frame of a stage to a PPM, without a window - so the sprites can
// be looked at while somebody else is using the screen.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/host.h"
#include "../src/render.h"
#include "../src/ui.h"
#include "../src/sim.h"
#include "../src/state.h"

int main(int argc, char **argv) {
    if (argc < 4) {
        fprintf(stderr, "usage: frame_dump <zip|dir> <map> <out.ppm> "
                        "[sweeps] [zoom]\n");
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

    static GameState game;
    char message[256];
    if (!worldLoadStage(&game.world, &host, argv[2], message,
                        sizeof message)) {
        fprintf(stderr, "%s\n", message);
        return 1;
    }
    stateStartStage(&game);
    Sim sim;
    simInit(&sim, &game);
    simSeedLeaders(&sim);

    const long sweeps = argc > 4 ? strtol(argv[4], NULL, 10) : 400;
    for (long i = 0; i < sweeps; i++) simStep(&sim);
    const int zoom = argc > 5 ? atoi(argv[5]) : 1;

    const int W = 640, H = 480;
    static unsigned char indices[640 * 480];
    Surface surface;
    surfaceInit(&surface, W, H, indices);

    const TileBank *ground = worldBank(&game.world, zoom);
    const int span = WORLD_GRID * (ground->tileSize > 0 ? ground->tileSize : 16);
    const int viewX = (span - W) / 2 > 0 ? (span - W) / 2 : 0;
    const int viewY = (span - H) / 2 > 0 ? (span - H) / 2 : 0;
    renderWorld(&game.world, zoom, viewX, viewY, 1, &surface);
    renderUnits(&game, zoom, viewX, viewY, 1, &surface);
    renderStatus(&game, &surface);

    // menu:<col>,<row> opens 00423940's order menu over the picture, at the
    // place the pointer would be for that square, so the chrome can be looked
    // at against the map it sits on.
    for (int a = 6; a < argc; a++) {
        unsigned col = 0, row = 0;
        if (sscanf(argv[a], "menu:%u,%u", &col, &row) != 2) continue;
        const int ts = ground->tileSize > 0 ? ground->tileSize : 16;
        OrderMenu menu;
        const int px = (int)col * ts - viewX + ts / 2;
        const int py = (int)row * ts - viewY + ts / 2;
        if (!uiOrderOpen(&menu, &game, (int)col, (int)row, px, py, W, H)) {
            printf("no order can be given on %u,%u\n", col, row);
            continue;
        }
        uiOrderHover(&menu, &game, menu.x + 10, menu.y + 2 + UI_ITEM_H / 2);
        uiOrderDraw(&surface, &game, &menu);
        printf("menu at %u,%u: %d order(s) offered\n", col, row, menu.count);
    }

    unsigned drawn = 0;
    for (int i = 0; i < ENTITY_COUNT; i++)
        if ((game.entities[i].flags & 0x80) == 0) drawn++;
    printf("%s: %ld sweeps, zoom %d, %u live entities, sprites %s\n",
           argv[2], sweeps, zoom, drawn,
           worldSprites(&game.world, zoom)->pixels ? "loaded" : "MISSING");

    FILE *o = fopen(argv[3], "wb");
    fprintf(o, "P6\n%d %d\n255\n", W, H);
    unsigned char colours[256][3];
    renderPalette(&game, zoom, colours);
    for (int i = 0; i < W * H; i++) fwrite(colours[indices[i]], 1, 3, o);
    fclose(o);
    printf("wrote %s\n", argv[3]);
    worldFree(&game.world);
    return 0;
}
