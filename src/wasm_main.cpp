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
#include "dlgrun.h"
#include "ui.h"
#include "state.h"
#include "world.h"
}

// The largest view this will draw.  The map is 48 cells, so 768 shows all of
// it at the middle zoom and there is no point going past that.
#define VIEW_MAX_W 800
#define VIEW_MAX_H 800
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
OrderMenu g_menu;
ToolBar g_tool;
int g_showBar = 1;              // Hide Title Bar, which is really the menu bar
int g_showTool = 1;             // Hide Tool Bar
int g_showStatus = 1;           // Status Window, the numbers over the board
DlgRunner g_dlg;
DlgHost g_dlgHost;

// What the page keeps for the dialogs: eight save slots and the three windows
// it draws beside the board.  The slots live on the page (localStorage), so
// the port only holds their names and asks the page to do the reading and the
// writing through these.
#define SAVE_SLOTS 8
char g_slotName[SAVE_SLOTS][40];
int g_windowShown[3] = {1, 1, 1};
int g_speed = 25;                   // DAT_00437698, 0 slow to 29 fast
int g_slotWanted = -1;              // the slot the page is being asked for
int g_slotAction = 0;               // 1 read, 2 write, 3 remove
StageList g_stages;
TuneList g_tunes;
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
unsigned char g_indices[VIEW_MAX_W * VIEW_MAX_H];
unsigned g_pixels[VIEW_MAX_W * VIEW_MAX_H];
Surface g_surface;              // the map, which starts under the menu bar
Surface g_screen;               // all of it, bar included
MenuBar g_bar;
int g_viewW = 640, g_viewH = 480;

void clampView() {
    const TileBank *bank = worldBank(&g_game.world, g_zoom);
    const int span = WORLD_GRID * (bank->tileSize > 0 ? bank->tileSize : 16);
    const int maxX = span - g_viewW, maxY = span - g_viewH;
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
    g_viewX = (span - g_viewW) / 2;
    g_viewY = (span - g_viewH) / 2;
    clampView();
    g_lastAction = 0;
    return 1;
}

}   // namespace

// Wired once the archive is open; defined with the dialog
// callbacks further down.
static void dialogsReady(void);

// The music exports, which the sound dialog reaches back into.
extern "C" EMSCRIPTEN_KEEPALIVE int lm_music_play(int number, int loop);
extern "C" EMSCRIPTEN_KEEPALIVE void lm_music_stop(void);

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
    worldReadTunes(&g_tunes, &g_host);          // SOUND/SOUND.CFG
    if (!loadStage(0)) return 0;
    surfaceInit(&g_screen, g_viewW, g_viewH + UI_CHROME_H, g_indices);
    surfaceInit(&g_surface, g_viewW, g_viewH,
                g_indices + (size_t)UI_CHROME_H * g_viewW);
    dialogsReady();
    return stageCount();
}

EMSCRIPTEN_KEEPALIVE const char *lm_message(void) { return g_message; }
EMSCRIPTEN_KEEPALIVE int lm_width(void) { return g_viewW; }
EMSCRIPTEN_KEEPALIVE int lm_height(void) {
    return g_viewH + UI_CHROME_H;
}

// How much of the top belongs to the chrome, so a host can leave room for it -
// the menu bar and the tool bar under it together.
EMSCRIPTEN_KEEPALIVE int lm_bar_height(void) { return UI_CHROME_H; }

// The menu bar's own share of that, which is where a dropped menu starts.
EMSCRIPTEN_KEEPALIVE int lm_menu_height(void) { return UI_BAR_H; }

// How big a view to draw.  The original's is fixed at what a 1997 screen had;
// a page can have as much as it can show, up to the whole 48-cell map at the
// middle zoom.
EMSCRIPTEN_KEEPALIVE void lm_set_view(int w, int h) {
    if (w < 160 || h < 120 || w > VIEW_MAX_W || h > VIEW_MAX_H - UI_CHROME_H)
        return;
    g_viewW = w;
    g_viewH = h;
    surfaceInit(&g_screen, g_viewW, g_viewH + UI_CHROME_H, g_indices);
    surfaceInit(&g_surface, g_viewW, g_viewH,
                g_indices + (size_t)UI_CHROME_H * g_viewW);
    clampView();
}
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
    if (g_showStatus) renderStatus(&g_game, &g_surface);
    uiOrderDraw(&g_screen, &g_game, &g_menu);       // 00423940's own menu
    // Hidden bars still take their room - the board is where it was, and the
    // strip is drawn in the face grey - because a map that jumps about when a
    // bar is hidden is worse than one that does not.
    if (g_showTool) uiToolDraw(&g_screen, &g_tool, g_running, g_zoom);
    if (g_showBar) uiBarDraw(&g_screen, &g_game, g_running, &g_bar);
    dlgRunDraw(&g_screen, &g_dlg, &g_game);         // and whatever dialog is up
    // The pulsing entries move with the frame, so the table is rebuilt here
    // rather than only when a stage loads.
    unsigned char colours[256][3];
    renderPalette(&g_game, g_zoom, colours);
    for (int i = 0; i < g_viewW * (g_viewH + UI_CHROME_H); i++) {
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

// Scroll by pixels rather than whole cells, for dragging and the wheel.
EMSCRIPTEN_KEEPALIVE void lm_scroll_by(int dx, int dy) {
    g_viewX += dx;
    g_viewY += dy;
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
        g_viewX = (int)((g_viewX + g_viewW / 2) * scale) - g_viewW / 2;
        g_viewY = (int)((g_viewY + g_viewH / 2) * scale) - g_viewH / 2;
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
    stateMoveCursor(&g_game, (g_viewX + x) / ts, (g_viewY + y - UI_CHROME_H) / ts);
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
    g_lastRow = (unsigned)((g_viewY + y - UI_CHROME_H) / ts);
    const unsigned actor = simHumanActor(&g_sim);
    g_lastAction = actor < ENTITY_COUNT
        ? (int)simBuildUnitCell(&g_sim, actor, g_lastCol, g_lastRow)
        : (int)SIM_ACTION_REFUSED;
    return g_lastAction;
}

// DAT_004365e0: the order a unit the player raises will carry.  1 is the
// plain one (build where you stand); 4 sends it after a neighbour's
// settlement.  growFromUnit stamps it on, exactly as the original does.
EMSCRIPTEN_KEEPALIVE void lm_set_order(int order, int strength) {
    // The menu at 0x434444 composes this byte: the order itself, plus 0x10 to
    // make it a standing order at all, and 0x40 or 0x80 for the two stronger
    // variants.  `strength` picks which of the three - what 00403170 reads the
    // high bits for once the work is done.
    if (order <= 0) {
        g_sim.pendingOrder = 1u;
        return;
    }
    unsigned code = (unsigned)((order & 0x0f) | 0x10);
    if (strength == 1) code |= 0x40u;
    if (strength == 2) code |= 0x80u;
    g_sim.pendingOrder = code;
}
EMSCRIPTEN_KEEPALIVE int lm_order(void) { return (int)g_sim.pendingOrder; }

// Gives every unit of the player's faction that order, which is how a country
// is actually directed - the original routes it through the command window.
EMSCRIPTEN_KEEPALIVE int lm_order_all(int order, int strength) {
    int changed = 0;
    for (int i = 0; i < ENTITY_COUNT; i++) {
        Entity *entity = &g_game.entities[i];
        if (entity->flags & 0x80) continue;
        if (entity->faction != g_sim.humanFaction) continue;
        if (entity->at0d & 0x20) continue;         // leave the leader alone
        // Bit 7 is what 00403170 reads as "keep hunting"; without it order 4
        // sends the unit home instead.
        // Order 4 without a strength would send the unit home the moment it
        // struck once, which is not what "the whole army, attack" means; the
        // strength the caller asks for wins when it gives one.
        unsigned high = strength == 1 ? 0x40u : strength == 2 ? 0x80u : 0u;
        if (!high && (order & 0x0f) == 4) high = 0x80u;
        entity->at0d = (unsigned char)(high | 0x10u | (order & 0x0f));
        entity->at18 = 0x1f0;                     // drop whatever it was doing
        changed++;
    }
    return changed;
}

/* --------------------------------------------- choosing units and sending */

// The Orders menu's Recall Leader (40113).
EMSCRIPTEN_KEEPALIVE int lm_recall_leader(void) {
    return simRecallLeader(&g_sim, g_sim.humanFaction);
}

// The original's own flow: choose units, which puts a balloon over each, then
// point at a cell to say where the order is to be carried out.  `force` picks
// up units that already have orders as well as the idle ones.
EMSCRIPTEN_KEEPALIVE int lm_select_all(int force) {
    return simSelectAll(&g_sim, force);
}

// The same, for the one unit under a view pixel.  Without it the only way to
// choose anybody is all of them at once, which is not how the game is played:
// you pick the units near the thing you want done.
EMSCRIPTEN_KEEPALIVE int lm_select_at(int x, int y, int force) {
    const TileBank *bank = worldBank(&g_game.world, g_zoom);
    const int ts = bank->tileSize > 0 ? bank->tileSize : 16;
    const int col = (g_viewX + x) / ts;
    const int row = (g_viewY + y - UI_CHROME_H) / ts;
    if (col < 0 || row < 0 || col >= WORLD_GRID || row >= WORLD_GRID) return 0;
    const unsigned char slot =
        g_game.world.cells[WORLD_INDEX((unsigned)col, (unsigned)row)].occupant;
    if (slot >= ENTITY_COUNT) return 0;
    return simSelect(&g_sim, slot, col, row, force);
}

// Every unit of the player's inside a rectangle of view pixels - the drag the
// original uses to gather up an army before sending it anywhere.
EMSCRIPTEN_KEEPALIVE int lm_select_rect(int x0, int y0, int x1, int y1,
                                        int force) {
    const TileBank *bank = worldBank(&g_game.world, g_zoom);
    const int ts = bank->tileSize > 0 ? bank->tileSize : 16;
    int c0 = (g_viewX + (x0 < x1 ? x0 : x1)) / ts;
    int c1 = (g_viewX + (x0 < x1 ? x1 : x0)) / ts;
    int r0 = (g_viewY + (y0 < y1 ? y0 : y1) - UI_CHROME_H) / ts;
    int r1 = (g_viewY + (y0 < y1 ? y1 : y0) - UI_CHROME_H) / ts;
    if (c0 < 0) c0 = 0;
    if (r0 < 0) r0 = 0;
    if (c1 > WORLD_GRID - 1) c1 = WORLD_GRID - 1;
    if (r1 > WORLD_GRID - 1) r1 = WORLD_GRID - 1;
    int chosen = 0;
    for (int col = c0; col <= c1; col++)
        for (int row = r0; row <= r1; row++) {
            const unsigned char slot =
                g_game.world.cells[WORLD_INDEX((unsigned)col,
                                               (unsigned)row)].occupant;
            if (slot >= ENTITY_COUNT) continue;
            if (g_game.entities[slot].at0d & 0x20) continue;   // not the king
            if (simSelect(&g_sim, slot, col, row, force)) chosen++;
        }
    return chosen;
}

// Whether the cell under a view pixel holds one of the player's own units, so
// a page can tell a click meant to choose from a click meant to build.
EMSCRIPTEN_KEEPALIVE int lm_unit_here(int x, int y) {
    const TileBank *bank = worldBank(&g_game.world, g_zoom);
    const int ts = bank->tileSize > 0 ? bank->tileSize : 16;
    const int col = (g_viewX + x) / ts;
    const int row = (g_viewY + y - UI_CHROME_H) / ts;
    if (col < 0 || row < 0 || col >= WORLD_GRID || row >= WORLD_GRID) return 0;
    const unsigned char slot =
        g_game.world.cells[WORLD_INDEX((unsigned)col, (unsigned)row)].occupant;
    if (slot >= ENTITY_COUNT) return 0;
    return g_game.entities[slot].faction == g_sim.humanFaction;
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
    const int row = (g_viewY + y - UI_CHROME_H) / ts;
    if (col < 0 || row < 0 || col >= WORLD_GRID || row >= WORLD_GRID) return 0;
    return simAimSelection(&g_sim, col, row);
}

// Gives the chosen units the current order, aimed at the cell under a view
// pixel.  Returns how many of them found a way there.
EMSCRIPTEN_KEEPALIVE int lm_order_at(int order, int modifier, int x, int y) {
    const TileBank *bank = worldBank(&g_game.world, g_zoom);
    const int ts = bank->tileSize > 0 ? bank->tileSize : 16;
    const int col = (g_viewX + x) / ts;
    const int row = (g_viewY + y - UI_CHROME_H) / ts;
    if (col < 0 || row < 0 || col >= WORLD_GRID || row >= WORLD_GRID) return 0;
    return simOrderSelected(&g_sim, (unsigned)order, modifier, col, row);
}

/* ------------------------------------------- 00423940, the order menu */

// The original's flow: units are chosen, the player clicks the square, and a
// menu comes up at the cursor offering the orders that square accepts.  Two
// tables in the executable decide which; on water it is order 7 alone, which
// is how a bridge gets built.
//
// Non-zero when a menu opened.  Zero means the square accepts nothing, and the
// caller can get on with whatever else a click there means.
EMSCRIPTEN_KEEPALIVE int lm_menu_open(int x, int y) {
    const TileBank *bank = worldBank(&g_game.world, g_zoom);
    const int ts = bank->tileSize > 0 ? bank->tileSize : 16;
    const int col = (g_viewX + x) / ts;
    const int row = (g_viewY + y - UI_CHROME_H) / ts;
    return uiOrderOpen(&g_menu, &g_game, col, row, x, y, g_viewW,
                       g_viewH + UI_CHROME_H);
}

EMSCRIPTEN_KEEPALIVE int lm_menu_up(void) { return g_menu.open; }

EMSCRIPTEN_KEEPALIVE void lm_menu_close(void) { uiOrderClose(&g_menu); }

EMSCRIPTEN_KEEPALIVE void lm_menu_hover(int x, int y) {
    uiOrderHover(&g_menu, &g_game, x, y);
}

// A click while the menu is up.  Answers how many units took the order, -1
// when the menu was dismissed, and 0 while the pointer is still in it.
EMSCRIPTEN_KEEPALIVE int lm_menu_click(int x, int y) {
    unsigned order = 0;
    int strength = 0;
    const int col = g_menu.col, row = g_menu.row;
    const int done = uiOrderClick(&g_menu, &g_game, x, y, &order, &strength);
    if (done < 0) return -1;
    if (done == 0) return 0;
    const int given = simOrderSelected(&g_sim, order, strength, col, row);
    if (given == SIM_ORDER_ASK) {
        // A unit can only get there the hard way; 00423cc0 asks about it,
        // through dialog 118, before it goes.
        dlgRunOpen(&g_dlg, DLG_INFORMATION, g_viewW, g_viewH + UI_CHROME_H);
        return 0;
    }
    return given;
}

/* ---------------------------------------------------------- the dialogs */

// Zero for an empty slot, which is how the dialog knows where Save New goes.
static int hostSlotName(void *, int slot, char *out, int size) {
    if (slot < 0 || slot >= SAVE_SLOTS || !g_slotName[slot][0]) return 0;
    snprintf(out, (size_t)size, "%s", g_slotName[slot]);
    return 1;
}

// The page does the actual reading and writing, because the bytes live in its
// localStorage; these leave a note for it to pick up.
static int hostSlotRead(void *, int slot) {
    g_slotWanted = slot;
    g_slotAction = 1;
    return 1;
}
static int hostSlotWrite(void *, int slot, const char *name) {
    if (slot < 0 || slot >= SAVE_SLOTS) return 0;
    snprintf(g_slotName[slot], sizeof g_slotName[slot], "%s",
             name && *name ? name : "Saved");
    g_slotWanted = slot;
    g_slotAction = 2;
    return 1;
}
static int hostSlotRemove(void *, int slot) {
    if (slot < 0 || slot >= SAVE_SLOTS) return 0;
    g_slotName[slot][0] = 0;
    g_slotWanted = slot;
    g_slotAction = 3;
    return 1;
}

// SOUND/SOUND.CFG for dialog 112.
static int hostTuneName(void *, int tune, char *out, int size) {
    if (tune < 0 || tune >= (int)g_tunes.count) return 0;
    snprintf(out, (size_t)size, "%3u %s", g_tunes.entry[tune],
             g_tunes.name[tune]);
    return 1;
}
static int hostTuneNumber(void *, int tune) {
    return tune >= 0 && tune < (int)g_tunes.count ? (int)g_tunes.entry[tune] : 0;
}
static void hostTunePlay(void *, int tune) {
    if (tune < 0 || tune >= (int)g_tunes.count) return;
    lm_music_play((int)g_tunes.entry[tune], g_tunes.loops[tune]);
}
static void hostTuneStop(void *) { lm_music_stop(); }

static int hostGetSpeed(void *) { return g_speed; }
static void hostSetSpeed(void *, int speed) {
    g_speed = speed < 0 ? 0 : speed > 29 ? 29 : speed;
}

static int hostStageName(void *, int stage, char *out, int size) {
    if (stage < 0 || stage >= stageCount()) return 0;
    const char *name = g_stages.count ? g_stages.name[stage]
                                      : stageFile(stage);
    snprintf(out, (size_t)size, "%s", name ? name : "");
    return 1;
}
static int hostLoadStage(void *, int stage) { return lm_load_stage(stage); }

static int hostGetWindow(void *, int which) {
    return which >= 0 && which < 3 ? g_windowShown[which] : 0;
}
static void hostSetWindow(void *, int which, int on) {
    if (which >= 0 && which < 3) g_windowShown[which] = on ? 1 : 0;
}

static void dialogsReady(void) {
    uiToolInit(&g_tool);
    g_dlgHost.slotName = hostSlotName;
    g_dlgHost.slotRead = hostSlotRead;
    g_dlgHost.slotWrite = hostSlotWrite;
    g_dlgHost.slotRemove = hostSlotRemove;
    g_dlgHost.slots = SAVE_SLOTS;
    g_dlgHost.tuneName = hostTuneName;
    g_dlgHost.tuneNumber = hostTuneNumber;
    g_dlgHost.tunes = (int)g_tunes.count;
    g_dlgHost.tunePlay = hostTunePlay;
    g_dlgHost.tuneStop = hostTuneStop;
    g_dlgHost.getSpeed = hostGetSpeed;
    g_dlgHost.setSpeed = hostSetSpeed;
    g_dlgHost.stageName = hostStageName;
    g_dlgHost.stages = lm_stage_count();
    g_dlgHost.loadStage = hostLoadStage;
    g_dlgHost.getWindow = hostGetWindow;
    g_dlgHost.setWindow = hostSetWindow;
    g_dlgHost.user = nullptr;
    dlgRunInit(&g_dlg, &g_sim, &g_dlgHost);
}

// Opening one by the command number MENU 101 gives it.
EMSCRIPTEN_KEEPALIVE int lm_dialog_open(int command) {
    const DlgWhich which = dlgForCommand(command);
    if (which == DLG_NONE) return 0;
    g_dlgHost.stages = lm_stage_count();
    return dlgRunOpen(&g_dlg, which, g_viewW, g_viewH + UI_CHROME_H);
}

EMSCRIPTEN_KEEPALIVE int lm_dialog_up(void) { return dlgRunUp(&g_dlg); }
EMSCRIPTEN_KEEPALIVE void lm_dialog_hover(int x, int y) {
    dlgRunHover(&g_dlg, x, y);
}
EMSCRIPTEN_KEEPALIVE int lm_dialog_click(int x, int y) {
    return dlgRunClick(&g_dlg, x, y);
}

// What a dialog has asked the page to do with a save slot, and which one.
// Reading it clears it.
EMSCRIPTEN_KEEPALIVE int lm_slot_action(void) {
    const int a = g_slotAction;
    g_slotAction = 0;
    return a;
}
EMSCRIPTEN_KEEPALIVE int lm_slot_wanted(void) { return g_slotWanted; }
EMSCRIPTEN_KEEPALIVE int lm_slot_count(void) { return SAVE_SLOTS; }

// The page tells the port what its slots are called, so the list can show them.
EMSCRIPTEN_KEEPALIVE void lm_slot_set_name(int slot, const char *name) {
    if (slot < 0 || slot >= SAVE_SLOTS) return;
    snprintf(g_slotName[slot], sizeof g_slotName[slot], "%s", name ? name : "");
}

EMSCRIPTEN_KEEPALIVE int lm_speed(void) { return g_speed; }
EMSCRIPTEN_KEEPALIVE void lm_set_speed(int speed) { hostSetSpeed(nullptr, speed); }
EMSCRIPTEN_KEEPALIVE int lm_window_shown(int which) {
    return hostGetWindow(nullptr, which);
}

/* -------------------------------------------------- MENU 101, the menu bar */

// A click on the bar or in a dropped menu.  Answers the command number the
// original's menu would have sent, 0 for "the click was ours but nothing came
// of it", and leaves *inside zero when the click was not on the chrome at all
// - which is how a host knows to pass it to the map instead.
EMSCRIPTEN_KEEPALIVE int lm_bar_click(int x, int y) {
    int inside = 0;
    unsigned command = 0;
    if (g_showBar) command = uiBarClick(&g_bar, x, y, &inside);
    if (!inside && !command && g_showTool) {
        command = uiToolClick(&g_tool, x, y, &inside);
        if (!inside && !command) return -1;
    }
    if (!inside && !command) return -1;
    return (int)command;
}

EMSCRIPTEN_KEEPALIVE int lm_bar_hover(int x, int y) {
    const int onBar = g_showBar && uiBarHover(&g_bar, x, y);
    const int onTool = g_showTool && uiToolHover(&g_tool, x, y);
    return onBar || onTool;
}

EMSCRIPTEN_KEEPALIVE int lm_bar_open(void) { return uiBarOpen(&g_bar); }

// Carries out the ones that are the game's own business.  Non-zero when it
// did; the rest - loading, saving, the help - belong to the host, which reads
// the number and does its own thing.
EMSCRIPTEN_KEEPALIVE int lm_command(int command) {
    switch (command) {
    case 40045:                                     // Start
        g_running = 1;
        return 1;
    case 40030:                                     // Pause
        g_running = 0;
        return 1;
    case 40048: lm_set_zoom(0); return 1;           // Resize Map: Small
    case 40049: lm_set_zoom(1); return 1;           // Medium
    case 40050: lm_set_zoom(2); return 1;           // Large
    case 40110:                                     // Restart
        return lm_load_stage(lm_stage());
    case 40114:                                     // New
        return lm_load_stage(0);
    case 40113:                                     // Recall Leader
        return simRecallLeader(&g_sim, g_sim.humanFaction);
    case 40062:                                     // Overall Order, new units
        lm_select_all(0);
        return 1;                                   // done, however many it found
    case 40061:                                     // Overall Order, all
        lm_select_all(1);
        return 1;
    case 60001:                                     // Unit Window
        g_windowShown[1] = !g_windowShown[1];
        return 1;
    case 60002:                                     // Progress Window
        g_windowShown[0] = !g_windowShown[0];
        return 1;
    case 60003:                                     // Graph Window
        g_windowShown[2] = !g_windowShown[2];
        return 1;
    case 40080: case 40081: case 40082: case 40083: {
        // Leader Position: mark that country's king and look at him.
        int col = 0, row = 0;
        if (!simShowLeader(&g_sim, (unsigned)(command - 40080), &col, &row))
            return 1;                           // it has none; nothing to show
        const TileBank *bank = worldBank(&g_game.world, g_zoom);
        const int ts = bank->tileSize > 0 ? bank->tileSize : 16;
        g_viewX = col * ts - g_viewW / 2;
        g_viewY = row * ts - g_viewH / 2;
        clampView();
        return 1;
    }
    case 40108:                                     // Hide Title Bar
        g_showBar = !g_showBar;
        return 1;
    case 60005:                                     // Hide Tool Bar
        g_showTool = !g_showTool;
        return 1;
    case 40120:                                     // Status Window
        g_showStatus = !g_showStatus;
        return 1;
    case 40111:                                     // Set Windows to default
        g_showBar = 1;
        g_showTool = 1;
        g_showStatus = 1;
        g_windowShown[0] = g_windowShown[1] = g_windowShown[2] = 1;
        return 1;
    case 40044:                                     // Quit
        g_running = 0;
        return 1;
    default:
        break;
    }
    switch (command) {
    case 40038:                                     // Default Orders
        return 0;                                   // it has a dialog
    default:
        return 0;
    }
}

// Leader Position, for a host that wants it without going through the menu.
EMSCRIPTEN_KEEPALIVE int lm_show_leader(int faction) {
    return lm_command(40080 + (faction < 0 ? 0 : faction > 3 ? 3 : faction));
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
// 0xRRGGBB, from this scenery set's own palette.
EMSCRIPTEN_KEEPALIVE int lm_country_colour(int faction) {
    if (faction < 0 || faction > 4) return 0;
    return (int)renderCountryColour(&g_game, g_zoom, (unsigned)faction);
}
EMSCRIPTEN_KEEPALIVE const char *lm_order_name(int order) {
    return worldOrderName(&g_game.world, (unsigned)(order < 0 ? 99 : order));
}
/* ------------------------------------------------- the interface's art */

// A rectangle of data1.bz's sheet, in the interface's own colours, as RGBA the
// page can put straight into an ImageData.  0x70 is the sheet's transparent
// index and comes back with an alpha of zero.
//
// It is here so a page can draw the game's own furniture where it wants it -
// the gauge in the Unit Window, for instance, whose pieces 00426900 takes from
// ((n / 10 + 4) * 0x200 + n % 10) * 8, eight wide and sixteen tall.
unsigned g_uiPixels[256 * 256];

EMSCRIPTEN_KEEPALIVE const unsigned *lm_ui_region(int x, int y, int w, int h) {
    if (!g_game.world.ui.pixels) return NULL;
    if (w <= 0 || h <= 0 || w > 256 || h > 256) return NULL;
    for (int row = 0; row < h; row++) {
        for (int col = 0; col < w; col++) {
            const int sx = x + col, sy = y + row;
            unsigned out = 0;
            if (sx >= 0 && sy >= 0 && sx < UI_SHEET_W && sy < UI_SHEET_H) {
                const unsigned char v =
                    g_game.world.ui.pixels[(size_t)sy * UI_SHEET_W + sx];
                if (v != UI_TRANSPARENT) {
                    const unsigned char *rgb = g_game.world.ui.palette[v];
                    out = 0xff000000u | rgb[0] | ((unsigned)rgb[1] << 8) |
                          ((unsigned)rgb[2] << 16);
                }
            }
            g_uiPixels[(size_t)row * w + col] = out;
        }
    }
    return g_uiPixels;
}

// One tile of a terrain bank, in that bank's colours, for a page that wants to
// show what a cell holds the way 00426900 does - it draws the 32-pixel tile of
// whatever the cursor is on.
EMSCRIPTEN_KEEPALIVE const unsigned *lm_terrain_tile(int zoom, int number) {
    const TileBank *bank = worldBank(&g_game.world, zoom);
    if (!bank->pixels || number < 0 || (unsigned)number >= bank->tiles)
        return NULL;
    const int ts = bank->tileSize;
    if (ts * ts > 256 * 256) return NULL;
    const unsigned char *tile = bank->pixels + (size_t)number * ts * ts;
    for (int i = 0; i < ts * ts; i++) {
        const unsigned char *rgb = bank->palette[tile[i]];
        g_uiPixels[i] = 0xff000000u | rgb[0] | ((unsigned)rgb[1] << 8) |
                        ((unsigned)rgb[2] << 16);
    }
    return g_uiPixels;
}

/* --------------------------------------------------------- saved games */

// The original's own save: three blocks and no header.  The page keeps the
// bytes wherever it likes; the stage number is not in them, so it keeps that
// too.
unsigned char g_save[SAVE_SIZE];

// 0041b4f0's day count: what the game's own readme asks you to keep small.
EMSCRIPTEN_KEEPALIVE int lm_days(void) { return (int)g_sim.days; }
EMSCRIPTEN_KEEPALIVE int lm_days_left(void) { return (int)g_sim.countdown; }

EMSCRIPTEN_KEEPALIVE int lm_save_size(void) { return (int)SAVE_SIZE; }

EMSCRIPTEN_KEEPALIVE const unsigned char *lm_save(void) {
    stateSave(&g_game, g_save);
    return g_save;
}

// The cells come back with the game, so the fill flags and the blocked flags
// are already in them; the entity links are rebuilt the way a stage load does.
EMSCRIPTEN_KEEPALIVE int lm_load(const unsigned char *bytes, int size) {
    if (size != (int)SAVE_SIZE) return 0;
    stateLoad(&g_game, bytes);
    stateMarkBlocked(&g_game);
    statePlaceEntities(&g_game);
    stateRecomputeTotals(&g_game);
    simInit(&g_sim, &g_game);
    return 1;
}

// Which country the player has.  DAT_004365cd in the original, where it comes
// from the campaign; here it is a choice, since any of the four plays the same
// way and watching a different one is half the interest of a port.
EMSCRIPTEN_KEEPALIVE void lm_set_human(int faction) {
    if (faction < 0 || faction >= 4) return;
    g_sim.humanFaction = (unsigned)faction;
}
EMSCRIPTEN_KEEPALIVE int lm_human(void) { return (int)g_sim.humanFaction; }

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
// SOUND.CFG's own name for a tune, and whether it loops.
EMSCRIPTEN_KEEPALIVE const char *lm_tune_name(int number) {
    for (unsigned i = 0; i < g_tunes.count; i++)
        if (g_tunes.entry[i] == (unsigned)number) return g_tunes.name[i];
    return "";
}
EMSCRIPTEN_KEEPALIVE int lm_tune_loops(int number) {
    for (unsigned i = 0; i < g_tunes.count; i++)
        if (g_tunes.entry[i] == (unsigned)number) return g_tunes.loops[i];
    return 1;
}

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
// The synthesiser pans its instruments, so the page takes both channels: this
// answers a pointer to the left channel, with the right one lm_music_capacity
// floats further on.
EMSCRIPTEN_KEEPALIVE const float *lm_music_render2(int frames, int rate) {
    const unsigned cap = sizeof g_audio / sizeof g_audio[0];
    unsigned want = frames < 0 ? 0u : (unsigned)frames;
    if (want > cap / 2) want = cap / 2;
    float *left = g_audio;
    float *right = g_audio + cap / 2;
    midiRenderStereo(left, right, want, rate > 0 ? (unsigned)rate : 22050u);
    return g_audio;
}

// The rate has to be settled before a tune is loaded - the synthesiser builds
// its tables from it - so a page says what its AudioContext runs at first.
EMSCRIPTEN_KEEPALIVE void lm_music_rate(int rate) {
    midiSetRate(rate > 0 ? (unsigned)rate : 22050u);
}

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

// Frames a stereo render can take: half the buffer, since both channels live
// in it.
EMSCRIPTEN_KEEPALIVE int lm_music_capacity2(void) {
    return (int)(sizeof g_audio / sizeof g_audio[0] / 2);
}

EMSCRIPTEN_KEEPALIVE int lm_music_capacity(void) {
    return (int)(sizeof g_audio / sizeof g_audio[0]);
}

}   // extern "C"
