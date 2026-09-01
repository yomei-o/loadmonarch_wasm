// The WebAssembly boundary.
//
// The page owns three things only a browser can do: taking the player's zip,
// putting pixels on a canvas, and delivering input.  Everything else - the
// zip, the graphics formats, the world and the simulation - is the same C the
// native build uses.
#include <emscripten.h>

#include <cstdio>
#include <cstdlib>
#include <cstring>

extern "C" {
#include "host.h"
#include "midi.h"
#include "render.h"
#include "sim.h"
#include "state.h"
#include "world.h"
}

#define VIEW_W 640
#define VIEW_H 480
#define STAGES 15

static const char *kStages[STAGES] = {
    "B_000.MAP", "B_002.MAP", "B_003.MAP", "B_004.MAP", "B_005.MAP",
    "B_006.MAP", "B_009.MAP", "B_103.MAP", "B_104.MAP", "B_105.MAP",
    "S_101.MAP", "S_105.MAP", "S_115.MAP", "S_201.MAP", "T_000.MAP",
};

namespace {

GameState g_game;
Sim g_sim;
Host g_host;
unsigned char *g_archive;
unsigned g_archiveSize;
int g_stage;
int g_zoom = 1;
int g_viewX, g_viewY;
int g_running = 1;
int g_lastAction;
unsigned g_lastCol, g_lastRow;
char g_message[256];

// The screen the renderer writes, as palette indices, and the RGBA the canvas
// wants.  Two buffers rather than one because the renderer is the same code
// the native build hands to a DIB section.
unsigned char g_indices[VIEW_W * VIEW_H];
unsigned g_pixels[VIEW_W * VIEW_H];
Surface g_surface;

void clampView() {
    const TileBank *bank = worldBank(&g_game.world, g_zoom);
    const int span = WORLD_GRID * (bank->tileSize > 0 ? bank->tileSize : 16);
    const int maxX = span - VIEW_W, maxY = span - VIEW_H;
    if (g_viewX > maxX) g_viewX = maxX;
    if (g_viewY > maxY) g_viewY = maxY;
    if (g_viewX < 0) g_viewX = 0;
    if (g_viewY < 0) g_viewY = 0;
}

int loadStage(int stage) {
    if (stage < 0) stage = STAGES - 1;
    if (stage >= STAGES) stage = 0;
    World fresh;
    if (!worldLoadStage(&fresh, &g_host, kStages[stage], g_message,
                        sizeof g_message)) {
        return 0;
    }
    worldFree(&g_game.world);
    g_game.world = fresh;
    g_stage = stage;
    stateStartStage(&g_game);
    simInit(&g_sim, &g_game);
    simSeedLeaders(&g_sim);
    const TileBank *bank = worldBank(&g_game.world, g_zoom);
    const int span = WORLD_GRID * (bank->tileSize > 0 ? bank->tileSize : 16);
    g_viewX = (span - VIEW_W) / 2;
    g_viewY = (span - VIEW_H) / 2;
    clampView();
    g_lastAction = 0;
    return 1;
}

}   // namespace

extern "C" {

// The player's zip, copied in by the page.  Returns the number of stages when
// it reads, or zero with a reason in lm_message().
EMSCRIPTEN_KEEPALIVE int lm_open_zip(const unsigned char *data, int size) {
    free(g_archive);
    g_archive = (unsigned char *)malloc((size_t)size);
    if (!g_archive) {
        snprintf(g_message, sizeof g_message, "out of memory");
        return 0;
    }
    memcpy(g_archive, data, (size_t)size);
    g_archiveSize = (unsigned)size;
    if (!hostUseZip(&g_host, g_archive, g_archiveSize)) {
        snprintf(g_message, sizeof g_message,
                 "that file is not a zip this can read");
        return 0;
    }
    if (!loadStage(0)) return 0;
    surfaceInit(&g_surface, VIEW_W, VIEW_H, g_indices);
    return STAGES;
}

EMSCRIPTEN_KEEPALIVE const char *lm_message(void) { return g_message; }
EMSCRIPTEN_KEEPALIVE int lm_width(void) { return VIEW_W; }
EMSCRIPTEN_KEEPALIVE int lm_height(void) { return VIEW_H; }
EMSCRIPTEN_KEEPALIVE const char *lm_stage_name(void) {
    return kStages[g_stage];
}
EMSCRIPTEN_KEEPALIVE int lm_stage(void) { return g_stage; }

EMSCRIPTEN_KEEPALIVE void lm_step(int times) {
    if (!g_running) return;
    for (int i = 0; i < times; i++) simStep(&g_sim);
}

// Draws the world and resolves the palette, handing back RGBA the canvas can
// take straight into an ImageData.
EMSCRIPTEN_KEEPALIVE const unsigned *lm_frame(void) {
    renderWorld(&g_game.world, g_zoom, g_viewX, g_viewY, 1, &g_surface);
    renderUnits(&g_game, g_zoom, g_viewX, g_viewY, 1, &g_surface);
    const TileBank *bank = worldBank(&g_game.world, g_zoom);
    const TileBank *sprites = &g_game.world.sprites;
    for (int i = 0; i < VIEW_W * VIEW_H; i++) {
        const unsigned char index = g_indices[i];
        // The terrain's colours sit at 0x10, the sprites' at 0x30.
        const TileBank *from = (index >= 0x30 && index < 0x40) ? sprites : bank;
        g_pixels[i] = 0xff000000u |
                      (unsigned)from->palette[index][0] |
                      ((unsigned)from->palette[index][1] << 8) |
                      ((unsigned)from->palette[index][2] << 16);
    }
    return g_pixels;
}

EMSCRIPTEN_KEEPALIVE void lm_scroll(int dx, int dy) {
    const TileBank *bank = worldBank(&g_game.world, g_zoom);
    const int step = bank->tileSize > 0 ? bank->tileSize : 16;
    g_viewX += dx * step;
    g_viewY += dy * step;
    clampView();
}

EMSCRIPTEN_KEEPALIVE void lm_set_zoom(int zoom) {
    if (zoom < 0) zoom = 0;
    if (zoom > 2) zoom = 2;
    if (zoom == g_zoom) return;
    const TileBank *from = worldBank(&g_game.world, g_zoom);
    const TileBank *to = worldBank(&g_game.world, zoom);
    if (from->tileSize > 0 && to->tileSize > 0) {
        const double scale = (double)to->tileSize / from->tileSize;
        g_viewX = (int)((g_viewX + VIEW_W / 2) * scale) - VIEW_W / 2;
        g_viewY = (int)((g_viewY + VIEW_H / 2) * scale) - VIEW_H / 2;
    }
    g_zoom = zoom;
    clampView();
}

EMSCRIPTEN_KEEPALIVE int lm_zoom(void) { return g_zoom; }

EMSCRIPTEN_KEEPALIVE int lm_load_stage(int stage) { return loadStage(stage); }

EMSCRIPTEN_KEEPALIVE void lm_pause(int paused) { g_running = !paused; }
EMSCRIPTEN_KEEPALIVE int lm_running(void) { return g_running; }

// A click, in canvas pixels: the same order the native shell issues.
EMSCRIPTEN_KEEPALIVE int lm_click(int x, int y) {
    const TileBank *bank = worldBank(&g_game.world, g_zoom);
    const int ts = bank->tileSize > 0 ? bank->tileSize : 16;
    g_lastCol = (unsigned)((g_viewX + x) / ts);
    g_lastRow = (unsigned)((g_viewY + y) / ts);
    const unsigned actor = simHumanActor(&g_sim);
    g_lastAction = actor < ENTITY_COUNT
        ? (int)simBuildUnitCell(&g_sim, actor, g_lastCol, g_lastRow)
        : (int)SIM_ACTION_REFUSED;
    return g_lastAction;
}

// DAT_004365e0: the order a unit the player raises will carry.  1 is the
// plain one (build where you stand); 4 sends it after a neighbour's
// settlement.  growFromUnit stamps it on, exactly as the original does.
EMSCRIPTEN_KEEPALIVE void lm_set_order(int order) {
    g_sim.pendingOrder = order < 0 ? 0u : (unsigned)order;
}
EMSCRIPTEN_KEEPALIVE int lm_order(void) { return (int)g_sim.pendingOrder; }

// Gives every unit of the player's faction that order, which is how a country
// is actually directed - the original routes it through the command window.
EMSCRIPTEN_KEEPALIVE int lm_order_all(int order) {
    int changed = 0;
    for (int i = 0; i < ENTITY_COUNT; i++) {
        Entity *entity = &g_game.entities[i];
        if (entity->flags & 0x80) continue;
        if (entity->faction != g_sim.humanFaction) continue;
        if (entity->at0d & 0x20) continue;         // leave the leader alone
        // Bit 7 is what 00403170 reads as "keep hunting"; without it order 4
        // sends the unit home instead.
        const unsigned hunt = (order & 0x0f) == 4 ? 0x80u : 0u;
        entity->at0d = (unsigned char)(hunt | 0x10u | (order & 0x0f));
        entity->at18 = 0x1f0;                     // drop whatever it was doing
        changed++;
    }
    return changed;
}

EMSCRIPTEN_KEEPALIVE int lm_last_action(void) { return g_lastAction; }
EMSCRIPTEN_KEEPALIVE int lm_last_col(void) { return (int)g_lastCol; }
EMSCRIPTEN_KEEPALIVE int lm_last_row(void) { return (int)g_lastRow; }

/* ---------------------------------------------------- what the panel shows */

EMSCRIPTEN_KEEPALIVE double lm_sweeps(void) { return (double)g_sim.frames; }
EMSCRIPTEN_KEEPALIVE int lm_scenery(void) {
    return (int)g_game.world.scenerySet;
}
EMSCRIPTEN_KEEPALIVE int lm_funds(int faction) {
    return faction >= 0 && faction < FACTION_COUNT
        ? (int)g_game.factions[faction].funds : 0;
}
EMSCRIPTEN_KEEPALIVE int lm_tax(int faction) {
    return faction >= 0 && faction < FACTION_COUNT
        ? (int)g_game.factions[faction].taxRate : 0;
}
EMSCRIPTEN_KEEPALIVE int lm_losses(int faction) {
    return faction >= 0 && faction < FACTION_COUNT
        ? (int)g_game.factions[faction].at14 : 0;
}
EMSCRIPTEN_KEEPALIVE int lm_out(int faction) {
    return faction >= 0 && faction < FACTION_COUNT
        ? ((g_game.factions[faction].flags & 0x10) ? 1 : 0) : 0;
}

// Counted from the terrain, the way the sweep reads it: units, claimed ground
// and castles per faction, and how many entities that faction has alive.
EMSCRIPTEN_KEEPALIVE int lm_count(int faction, int what) {
    if (faction < 0 || faction >= FACTION_COUNT) return 0;
    unsigned total = 0;
    if (what == 3) {
        for (int i = 0; i < ENTITY_COUNT; i++)
            if ((g_game.entities[i].flags & 0x80) == 0 &&
                g_game.entities[i].faction == (unsigned char)faction) total++;
        return (int)total;
    }
    const unsigned char base = what == 0 ? 8 : (what == 1 ? 0x0c : 0x14);
    for (int i = 0; i < WORLD_CELLS; i++)
        if (g_game.world.cells[i].terrain == (unsigned char)(base + faction))
            total++;
    return (int)total;
}

EMSCRIPTEN_KEEPALIVE void *lm_alloc(int size) { return malloc((size_t)size); }
EMSCRIPTEN_KEEPALIVE void lm_free(void *p) { free(p); }

}   // extern "C"

/* ------------------------------------------------------------------ music */

// The tunes are .MID files in the zip, and there is no synthesiser in a
// browser, so midi.c makes the sound and the page only moves it to the
// speakers.  One tune at a time, which is what the original does through MCI.
namespace {
float g_audio[4096];
unsigned char g_tune[0x60000];
int g_tuneLoaded;
}   // namespace

extern "C" {

// Names are the ones in the zip: SOUND/LM000.MID and up.  Non-zero when it
// will play.
EMSCRIPTEN_KEEPALIVE int lm_music_play(int number, int loop) {
    char path[64];
    snprintf(path, sizeof path, "SOUND/LM%03d.MID", number);
    unsigned got = 0;
    if (!hostRead(&g_host, path, g_tune, sizeof g_tune, &got)) {
        g_tuneLoaded = 0;
        return 0;
    }
    g_tuneLoaded = midiLoad(g_tune, got, loop);
    return g_tuneLoaded;
}

EMSCRIPTEN_KEEPALIVE void lm_music_stop(void) {
    midiStop();
    g_tuneLoaded = 0;
}

EMSCRIPTEN_KEEPALIVE int lm_music_playing(void) {
    return g_tuneLoaded && !midiFinished();
}

// Renders the next block and hands back where it is.  The page asks for as
// many frames as its audio callback needs; anything over the buffer is
// clamped to what lm_music_capacity reports.
EMSCRIPTEN_KEEPALIVE const float *lm_music_render(int frames, int rate) {
    unsigned want = frames < 0 ? 0u : (unsigned)frames;
    if (want > sizeof g_audio / sizeof g_audio[0])
        want = sizeof g_audio / sizeof g_audio[0];
    if (!g_tuneLoaded) {
        memset(g_audio, 0, want * sizeof g_audio[0]);
        return g_audio;
    }
    midiRender(g_audio, want, rate > 0 ? (unsigned)rate : 22050u);
    return g_audio;
}

EMSCRIPTEN_KEEPALIVE int lm_music_capacity(void) {
    return (int)(sizeof g_audio / sizeof g_audio[0]);
}

}   // extern "C"
