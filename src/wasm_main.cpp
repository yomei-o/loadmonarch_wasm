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
#include "picture.h"
#include "render.h"
#include "sim.h"
#include "state.h"
#include "world.h"
}

#define VIEW_W 640
#define VIEW_H 480
// The campaign comes out of MAP/NAME.TXT - its order, which is not the order
// the file names sort in, and its titles.  The list below is only what to fall
// back on if that file is missing.
static const char *kFallbackStages[] = {
    "B_000.MAP", "B_003.MAP", "B_004.MAP", "B_006.MAP", "S_201.MAP",
    "B_104.MAP", "B_002.MAP", "B_005.MAP", "S_115.MAP", "B_009.MAP",
    "S_101.MAP", "T_000.MAP", "S_105.MAP", "B_105.MAP", "B_103.MAP",
};

namespace {

GameState g_game;
Sim g_sim;
StageList g_stages;
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

int stageCount() {
    return g_stages.count ? (int)g_stages.count
                          : (int)(sizeof kFallbackStages /
                                  sizeof kFallbackStages[0]);
}

const char *stageFile(int stage) {
    return g_stages.count ? g_stages.file[stage] : kFallbackStages[stage];
}

int loadStage(int stage) {
    const int count = stageCount();
    if (stage < 0) stage = count - 1;
    if (stage >= count) stage = 0;
    World fresh;
    if (!worldLoadStage(&fresh, &g_host, stageFile(stage), g_message,
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
    worldReadStages(&g_stages, &g_host);        // MAP/NAME.TXT
    if (!loadStage(0)) return 0;
    surfaceInit(&g_surface, VIEW_W, VIEW_H, g_indices);
    return stageCount();
}

EMSCRIPTEN_KEEPALIVE const char *lm_message(void) { return g_message; }
EMSCRIPTEN_KEEPALIVE int lm_width(void) { return VIEW_W; }
EMSCRIPTEN_KEEPALIVE int lm_height(void) { return VIEW_H; }
EMSCRIPTEN_KEEPALIVE const char *lm_stage_name(void) {
    return stageFile(g_stage);
}

// What the game calls this stage, from MAP/NAME.TXT.
EMSCRIPTEN_KEEPALIVE const char *lm_stage_title(void) {
    return g_stages.count ? g_stages.name[g_stage] : "";
}
EMSCRIPTEN_KEEPALIVE const char *lm_quest_name(void) {
    return g_stages.quest;
}
EMSCRIPTEN_KEEPALIVE int lm_stage_count(void) { return stageCount(); }
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
    renderStatus(&g_game, &g_surface);
    // The pulsing entries move with the frame, so the table is rebuilt here
    // rather than only when a stage loads.
    unsigned char colours[256][3];
    renderPalette(&g_game, g_zoom, colours);
    for (int i = 0; i < VIEW_W * VIEW_H; i++) {
        const unsigned char *rgb = colours[g_indices[i]];
        g_pixels[i] = 0xff000000u | (unsigned)rgb[0] |
                      ((unsigned)rgb[1] << 8) | ((unsigned)rgb[2] << 16);
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
// 0040b270's cursor, pointed at a view pixel rather than nudged by a key.
EMSCRIPTEN_KEEPALIVE void lm_set_cursor(int x, int y) {
    const TileBank *bank = worldBank(&g_game.world, g_zoom);
    const int ts = bank->tileSize > 0 ? bank->tileSize : 16;
    if (x < 0 || y < 0) {
        stateMoveCursor(&g_game, -1, -1);
        return;
    }
    stateMoveCursor(&g_game, (g_viewX + x) / ts, (g_viewY + y) / ts);
}
EMSCRIPTEN_KEEPALIVE int lm_cursor_col(void) { return g_game.cursorCol; }
EMSCRIPTEN_KEEPALIVE int lm_cursor_row(void) { return g_game.cursorRow; }

// Whether order balloons float above the units - DAT_004376a1.
EMSCRIPTEN_KEEPALIVE void lm_show_orders(int on) { g_game.showOrders = on; }
EMSCRIPTEN_KEEPALIVE int lm_orders_shown(void) { return g_game.showOrders; }

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
    // The menu at 0x434444 composes this byte: the order itself, plus 0x10 to
    // make it a standing order at all, and 0x40 or 0x80 for the two stronger
    // variants.  This takes the plain order and asks for the middle one.
    g_sim.pendingOrder =
        order <= 0 ? 1u : (unsigned)((order & 0x0f) | 0x10);
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

/* --------------------------------------------- choosing units and sending */

// The original's own flow: choose units, which puts a balloon over each, then
// point at a cell to say where the order is to be carried out.  `force` picks
// up units that already have orders as well as the idle ones.
EMSCRIPTEN_KEEPALIVE int lm_select_all(int force) {
    return simSelectAll(&g_sim, force);
}

EMSCRIPTEN_KEEPALIVE int lm_selected(void) {
    int n = 0;
    for (int i = 0; i < ENTITY_COUNT; i++)
        if (g_game.entities[i].flags21c & 1) n++;
    return n;
}

EMSCRIPTEN_KEEPALIVE void lm_clear_selection(void) {
    simClearSelection(&g_game);
}

// Aims the chosen units at the cell under a view pixel without ordering
// anything: each answers in the balloon over its head.  Non-zero when at least
// one of them can get there without passing danger.
EMSCRIPTEN_KEEPALIVE int lm_aim(int x, int y) {
    const TileBank *bank = worldBank(&g_game.world, g_zoom);
    const int ts = bank->tileSize > 0 ? bank->tileSize : 16;
    const int col = (g_viewX + x) / ts;
    const int row = (g_viewY + y) / ts;
    if (col < 0 || row < 0 || col >= WORLD_GRID || row >= WORLD_GRID) return 0;
    return simAimSelection(&g_sim, col, row);
}

// Gives the chosen units the current order, aimed at the cell under a view
// pixel.  Returns how many of them found a way there.
EMSCRIPTEN_KEEPALIVE int lm_order_at(int order, int modifier, int x, int y) {
    const TileBank *bank = worldBank(&g_game.world, g_zoom);
    const int ts = bank->tileSize > 0 ? bank->tileSize : 16;
    const int col = (g_viewX + x) / ts;
    const int row = (g_viewY + y) / ts;
    if (col < 0 || row < 0 || col >= WORLD_GRID || row >= WORLD_GRID) return 0;
    return simOrderSelected(&g_sim, (unsigned)order, modifier, col, row);
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
// 0041b370's total: what its cells hold plus what its armies carry.
EMSCRIPTEN_KEEPALIVE int lm_strength(int faction) {
    return faction >= 0 && faction < FACTION_COUNT
        ? (int)g_game.factions[faction].strength : 0;
}
// The scenery set's own wording, out of the large terrain file's name table.
EMSCRIPTEN_KEEPALIVE const char *lm_country_name(int faction) {
    return worldCountryName(&g_game.world, (unsigned)(faction < 0 ? 9 : faction));
}
EMSCRIPTEN_KEEPALIVE const char *lm_order_name(int order) {
    return worldOrderName(&g_game.world, (unsigned)(order < 0 ? 99 : order));
}
// 0041f4c0's verdict: 0 while the stage is being played, 1 when the player has
// outlasted the rest, 2 when the player is out.
EMSCRIPTEN_KEEPALIVE int lm_outcome(void) { return simStageOutcome(&g_sim); }

/* ------------------------------------------------------------ pictures */

// The title, the five interludes and the ending, straight out of DATA/.  The
// page asks for one by name and draws it on its own canvas.
Picture g_picture;

EMSCRIPTEN_KEEPALIVE int lm_picture_open(const char *stem) {
    pictureFree(&g_picture);
    return pictureLoad(&g_picture, &g_host, stem);
}
EMSCRIPTEN_KEEPALIVE int lm_picture_width(void) {
    return (int)g_picture.width;
}
EMSCRIPTEN_KEEPALIVE int lm_picture_height(void) {
    return (int)g_picture.height;
}
EMSCRIPTEN_KEEPALIVE const unsigned *lm_picture_pixels(void) {
    return g_picture.pixels;
}

/* ------------------------------------------- what is under the cursor */

// 00426900, the Unit Window: it shows the cell the cursor is on - its terrain
// tile, the number that cell holds, and a gauge of it.  A unit cell's number is
// labelled NUM and everything else's DEF, and both are the cell's +0x0c, the
// value that grows and gets spent.  Here the pieces are handed out and the page
// draws them as text.
EMSCRIPTEN_KEEPALIVE int lm_cursor_terrain(void) {
    if (g_game.cursorCol >= WORLD_GRID || g_game.cursorRow >= WORLD_GRID)
        return -1;
    return g_game.world.cells[WORLD_INDEX(g_game.cursorCol,
                                          g_game.cursorRow)].terrain;
}

EMSCRIPTEN_KEEPALIVE int lm_cursor_value(void) {
    if (g_game.cursorCol >= WORLD_GRID || g_game.cursorRow >= WORLD_GRID)
        return -1;
    return (int)g_game.world.cells[WORLD_INDEX(g_game.cursorCol,
                                               g_game.cursorRow)].value;
}

// The unit standing there, if any: its strength, or -1.
EMSCRIPTEN_KEEPALIVE int lm_cursor_unit(void) {
    if (g_game.cursorCol >= WORLD_GRID || g_game.cursorRow >= WORLD_GRID)
        return -1;
    const unsigned char slot = g_game.world.cells[
        WORLD_INDEX(g_game.cursorCol, g_game.cursorRow)].occupant;
    if (slot >= ENTITY_COUNT) return -1;
    if (g_game.entities[slot].flags & 0x80) return -1;
    return (int)g_game.entities[slot].at08;
}

EMSCRIPTEN_KEEPALIVE int lm_cursor_unit_faction(void) {
    if (g_game.cursorCol >= WORLD_GRID || g_game.cursorRow >= WORLD_GRID)
        return -1;
    const unsigned char slot = g_game.world.cells[
        WORLD_INDEX(g_game.cursorCol, g_game.cursorRow)].occupant;
    if (slot >= ENTITY_COUNT) return -1;
    if (g_game.entities[slot].flags & 0x80) return -1;
    return g_game.entities[slot].faction;
}

// 0041b640's share of the board, in hundredths of a percent so it crosses the
// boundary as an integer.  Recomputed on demand, the way the original computes
// it for its own panel rather than every tick.
EMSCRIPTEN_KEEPALIVE void lm_update_areas(void) {
    stateComputeAreas(&g_game);
}
EMSCRIPTEN_KEEPALIVE int lm_area(int faction) {
    return faction >= 0 && faction < FACTION_COUNT
        ? (int)(g_game.factions[faction].area * 100.0f + 0.5f) : 0;
}

// The leader's own strength, which is not counted in the country's - 0x0c
// names the entity, and 0x40 means it has none.
EMSCRIPTEN_KEEPALIVE int lm_leader_strength(int faction) {
    if (faction < 0 || faction >= FACTION_COUNT) return 0;
    const unsigned slot = g_game.factions[faction].at0c;
    if (slot >= ENTITY_COUNT) return 0;
    if (g_game.entities[slot].flags & 0x80) return 0;
    return (int)g_game.entities[slot].at08;
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

// 0040a110's choice, as a file number.  Each scenery set ships three tunes
// numbered after it - 10, 11, 12 for the first - and the war picks between the
// first two.  -1 means leave what is playing alone.
EMSCRIPTEN_KEEPALIVE int lm_music_wanted(void) {
    const int which = simMusicWanted(&g_sim);
    if (which < 0) return -1;
    return (int)g_game.world.scenerySet + which;
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
