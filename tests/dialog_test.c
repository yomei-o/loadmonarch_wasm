// The dialogs, driven the way a player drives them: open one, press the
// controls, and check what it did to the game.
//
// Positions come out of dlgControlRect, so this presses the same pixels a
// pointer would - if a control moves, the test moves with it.
#include <stdio.h>
#include <string.h>

#include "../src/dlgrun.h"
#include "panels.h"
#include "../src/state.h"
#include "../src/world.h"

static int failures;

static void expect(const char *what, long got, long want) {
    if (got == want) return;
    printf("  FAIL %s: got %ld want %ld\n", what, got, want);
    failures++;
}

// Press the control with this id, wherever it happens to be.
static int press(DlgRunner *r, int id) {
    int x, y, w, h;
    if (!dlgControlRect(&r->dlg, id, &x, &y, &w, &h)) {
        printf("  FAIL no control %d\n", id);
        failures++;
        return 0;
    }
    return dlgRunClick(r, x + w / 2, y + h / 2);
}

// A row of a list box, which is drawn where the control is.
static int pressRow(DlgRunner *r, int id, int row) {
    int x, y, w, h;
    if (!dlgControlRect(&r->dlg, id, &x, &y, &w, &h)) return 0;
    return dlgRunClick(r, x + 8, y + 2 + row * 16 + 8);
}

// A row of a combo's list, which drops below the bar rather than over it.
static int pressComboRow(DlgRunner *r, int id, int row) {
    int x, y, w, h;
    if (!dlgControlRect(&r->dlg, id, &x, &y, &w, &h)) return 0;
    return dlgRunClick(r, x + 8, y + h + 2 + row * 16 + 8);
}

/* ------------------------------------------------------ what the host does */

static int g_speed = 25;
static int g_window[3] = {1, 1, 1};
static int g_slotRead = -1, g_slotWrite = -1, g_slotRemove = -1;
static int g_stageLoaded = -1;
static char g_slot[4][32] = {"first", "", "third", ""};

static int slotName(void *, int slot, char *out, int size) {
    if (slot < 0 || slot >= 4 || !g_slot[slot][0]) return 0;
    snprintf(out, (size_t)size, "%s", g_slot[slot]);
    return 1;
}
static int slotRead(void *, int slot) { g_slotRead = slot; return 1; }
static int slotWrite(void *, int slot, const char *) {
    g_slotWrite = slot;
    snprintf(g_slot[slot], sizeof g_slot[slot], "written");
    return 1;
}
static int slotRemove(void *, int slot) {
    g_slotRemove = slot;
    g_slot[slot][0] = 0;
    return 1;
}
static int getSpeed(void *) { return g_speed; }
static void setSpeed(void *, int s) { g_speed = s; }
static int stageName(void *, int stage, char *out, int size) {
    snprintf(out, (size_t)size, "Stage %d", stage + 1);
    return 1;
}
static int loadStage(void *, int stage) { g_stageLoaded = stage; return 1; }
static int getWindow(void *, int w) { return w >= 0 && w < 3 ? g_window[w] : 0; }
static void setWindow(void *, int w, int on) {
    if (w >= 0 && w < 3) g_window[w] = on;
}

int main(void) {
    static GameState state;
    memset(&state, 0, sizeof state);
    for (unsigned i = 0; i < NAME_RECORDS; i++)
        snprintf(state.world.names.text[i], 16, "n%u", i);
    // The order names the dialogs quote by number.
    snprintf(state.world.names.text[NAME_ORDER + 0], 16, "Take Break");
    snprintf(state.world.names.text[NAME_ORDER + 1], 16, "Auto");
    snprintf(state.world.names.text[NAME_ORDER + 4], 16, "Ambush");
    snprintf(state.world.names.text[NAME_ORDER + 5], 16, "Now Open");
    state.world.names.loaded = 1;
    state.factions[0].at1e = 0x80;
    state.factions[1].at1e = 0x80;
    state.factions[0].at2c = 100;
    state.factions[1].at2c = 50;            // smaller, so it can be asked
    state.factions[2].at2c = 500;           // bigger, so it cannot
    state.factions[3].at2c = 10;

    Sim sim;
    simInit(&sim, &state);
    sim.humanFaction = 0;

    DlgHost host;
    memset(&host, 0, sizeof host);
    host.slotName = slotName;
    host.slotRead = slotRead;
    host.slotWrite = slotWrite;
    host.slotRemove = slotRemove;
    host.slots = 4;
    host.getSpeed = getSpeed;
    host.setSpeed = setSpeed;
    host.stageName = stageName;
    host.stages = 6;
    host.loadStage = loadStage;
    host.getWindow = getWindow;
    host.setWindow = setWindow;

    DlgRunner r;
    dlgRunInit(&r, &sim, &host);

    // 124: pick an order and a strength, press OK, and see pendingOrder.
    {
        expect("Default Orders opens",
               dlgRunOpen(&r, DLG_DEFAULT_ORDERS, 640, 480), 1);
        press(&r, 1125);                    // the order combo drops
        pressComboRow(&r, 1125, 1);         // its second row is order 4
        press(&r, 1126);                    // and the strength combo
        pressComboRow(&r, 1126, 2);         // "continue"
        expect("OK closed it", press(&r, 1075), 1);
        expect("the order took", sim.pendingOrder & 0x0f, 4);
        expect("with the continue bit", (sim.pendingOrder & 0x80) != 0, 1);
        printf("  Default Orders left pendingOrder %02x\n", sim.pendingOrder);
    }

    // 115: the trackbar and the window boxes.
    {
        dlgRunOpen(&r, DLG_SYSTEM_SETTING, 640, 480);
        expect("it took the speed it was given",
               dlgValue(&r.dlg, 1118), 25 * 100 / 30);
        int x, y, w, h;
        dlgControlRect(&r.dlg, 1118, &x, &y, &w, &h);
        dlgRunClick(&r, x + w - 2, y + h / 2);          // drag it to Fast
        press(&r, 1067);                                // Progress Window off
        expect("OK closed it", press(&r, 1), 1);
        expect("the clock is faster", g_speed > 25, 1);
        expect("and a window was turned off", g_window[0], 0);
        printf("  System Setting left the speed at %d\n", g_speed);
    }

    // 107: pick a slot and load it.
    {
        dlgRunOpen(&r, DLG_LOAD, 640, 480);
        expect("Load is off until a row is picked",
               dlgValue(&r.dlg, 1110), 0);
        pressRow(&r, 1015, 2);                          // the third slot
        expect("Load closed it", press(&r, 1110), 1);
        expect("and asked for that slot", g_slotRead, 2);
    }

    // 106: Save New goes to the first empty one, Delete empties a full one.
    {
        dlgRunOpen(&r, DLG_SAVE, 640, 480);
        expect("Save New closed it", press(&r, 1018), 1);
        expect("into the first empty slot", g_slotWrite, 1);

        dlgRunOpen(&r, DLG_SAVE, 640, 480);
        pressRow(&r, 1015, 0);
        expect("Delete leaves it up", press(&r, 1020), 0);
        expect("and emptied the slot", g_slotRemove, 0);
        press(&r, 8);
    }

    // 127: the campaign list.
    {
        dlgRunOpen(&r, DLG_LOAD_SINGLE_MAP, 640, 480);
        pressRow(&r, 1002, 3);
        expect("Go! closed it", press(&r, 1040), 1);
        expect("and loaded that stage", g_stageLoaded, 3);
    }

    // 119: a country smaller than the player can be asked, a bigger one not.
    {
        dlgRunOpen(&r, DLG_ALLIANCE, 640, 480);
        expect("the smaller country can be asked",
               dlgValue(&r.dlg, 1095) >= 0, 1);
        int x, y, w, h;
        dlgControlRect(&r.dlg, 1096, &x, &y, &w, &h);
        // 1096 is the second row, which is the country holding five hundred
        // cells - too big, so its Set does nothing.
        dlgRunClick(&r, x + w / 2, y + h / 2);
        expect("and the bigger one is not", r.allyPick, -1);
        press(&r, 1095);                                // ask the smaller one
        expect("OK closed it", press(&r, 1082), 1);
        expect("the alliance took", state.factions[0].at1e, 1);
        expect("and both sides know", state.factions[1].at1e, 0);

        dlgRunOpen(&r, DLG_ALLIANCE, 640, 480);
        expect("Reset is live now", press(&r, 1074), 0);
        expect("and it undid it", state.factions[0].at1e, 0x80);
        expect("on both sides", state.factions[1].at1e, 0x80);
        press(&r, 1082);
    }

    // 123: the pages walk.
    {
        dlgRunOpen(&r, DLG_HELP, 640, 480);
        press(&r, 1121);
        press(&r, 1121);
        expect("Next turned the pages", dlgValue(&r.dlg, 1122), 2);
        press(&r, 1120);
        expect("and Back turned one round", dlgValue(&r.dlg, 1122), 1);
        expect("Close closed it", press(&r, 8), 1);
    }

    // 120 and 126 just have to open and close.
    {
        expect("Version opens", dlgRunOpen(&r, DLG_VERSION, 640, 480), 1);
        expect("and closes", press(&r, 8), 1);
        expect("Sound Setting opens",
               dlgRunOpen(&r, DLG_SOUND_SETTING, 640, 480), 1);
        expect("and closes", press(&r, 9), 1);
    }

    // 118, the one that changes the game: 00423cc0 stops on every unit whose
    // route is only a hard one and asks about it.  Three units are chosen and
    // the middle one is awkward, so the loop has to stop once, take an answer,
    // and carry on with the other two.
    {
        memset(&state.entities, 0, sizeof state.entities);
        for (int i = 0; i < ENTITY_COUNT; i++) {
            state.entities[i].flags = 0x80;
            state.entities[i].at18 = 0x1f0;
            state.entities[i].at220 = 0xff;
        }
        for (int i = 0; i < WORLD_CELLS; i++) {
            state.world.cells[i].terrain = 0;
            state.world.cells[i].value = 100;
            state.world.cells[i].occupant = CELL_NO_ENTITY;
        }
        stateMarkBlocked(&state);
        state.factions[0].funds = 100000;
        for (int i = 1; i <= 3; i++) {
            Entity *e = &state.entities[i];
            e->flags = 0;
            e->faction = 0;
            e->at08 = 4000;
            e->at0c = 6;
            e->at0f = 10;
            e->at18 = 0x1f0;
            e->position[0] = (unsigned char)(20 + i);
            e->position[1] = 20;
            e->target[0] = e->position[0];
            e->target[1] = e->position[1];
            state.world.cells[WORLD_INDEX(e->position[0], 20)].occupant =
                (unsigned char)i;
            e->flags21c |= 1;               // all three are chosen
            e->at220 = 2;                   // and can get there cleanly
        }
        // The middle one can only get there through a friend, which is the
        // balloon 00412ff0 calls "Passage blocked by friendly unit".
        state.entities[2].at220 = 4;

        int given = simOrderSelected(&sim, 1, 0, 25, 25);
        expect("the loop stopped to ask", given, SIM_ORDER_ASK);
        expect("about the awkward one", sim.askUnit, 2);
        expect("and says which trouble it is", sim.askKind, 0);

        given = simOrderAnswer(&sim, 1);    // Don't go, for that one only
        expect("and then finished", given >= 0, 1);
        expect("with the other two under orders", given, 2);
        expect("and the one held back not", state.entities[2].at0d & 0x10, 0);
        printf("  118 stopped once and %d of 3 went\n", given);

        // Remainder don't go: nobody after the awkward one moves.
        for (int i = 1; i <= 3; i++) {
            state.entities[i].flags21c |= 1;
            state.entities[i].at0d = 0;
            state.entities[i].at18 = 0x1f0;
            state.entities[i].at220 = 2;
        }
        state.entities[1].at220 = 3;        // enemies in the path, this time
        given = simOrderSelected(&sim, 1, 0, 25, 25);
        expect("it asks about the first", sim.askUnit, 1);
        expect("and this trouble is the other kind", sim.askKind, 1);
        given = simOrderAnswer(&sim, 3);    // Remainder don't go
        expect("so nobody went", given, 0);
    }

    // 0041a1b0's two strips.  The arithmetic is its own: clamp x - 0x18 into
    // 0 to 0x7c, divide by four, cap at thirty - so every reading but the last
    // is four pixels wide and the strip answers thirty-one of them.
    {
        int v = -1;
        // 0041a1b0 wants x at 0x18 or past it before it reads the strip at
        // all; a point left of that falls through to dragging the window.
        expect("left of the strip is not the strip",
               panelProgressSlider(23, 24, &v), PANEL_SLIDER_NONE);
        panelProgressSlider(24, 24, &v);
        expect("nought at the left end", v, 0);
        panelProgressSlider(27, 24, &v);
        expect("still nought three across", v, 0);
        panelProgressSlider(28, 24, &v);
        expect("one at four", v, 1);
        panelProgressSlider(24 + 120, 24, &v);
        expect("thirty at a hundred and twenty", v, 30);
        panelProgressSlider(24 + 124, 24, &v);
        expect("and thirty at the clamp", v, 30);
        expect("the lower strip is the clock",
               panelProgressSlider(60, 150, &v), PANEL_SLIDER_SPEED);
        expect("between the two is neither",
               panelProgressSlider(60, 90, &v), PANEL_SLIDER_NONE);
        expect("and well right of them is neither",
               panelProgressSlider(200, 24, &v), PANEL_SLIDER_NONE);
        // 0041a3d0's button: the scales beside the number.
        expect("the scales turn the automatic tax on and off",
               panelProgressSlider(100, 48, &v), PANEL_SLIDER_AUTOTAX);
    }

    printf(failures ? "%d dialog check(s) failed\n" : "dialog checks ok\n",
           failures);
    return failures ? 1 : 0;
}
