#include "ui.h"

#include "font.h"
#include "toolbar.h"
#include "world.h"

#include <string.h>

/* ------------------------------------------------------- Windows 95 edges */

static void fill(Surface *out, int x, int y, int w, int h, unsigned char c) {
    for (int j = 0; j < h; j++) {
        const int py = y + j;
        if (py < 0 || py >= out->height) continue;
        unsigned char *row = out->pixels + (size_t)py * out->width;
        for (int i = 0; i < w; i++) {
            const int px = x + i;
            if (px < 0 || px >= out->width) continue;
            row[px] = c;
        }
    }
}

// A raised edge without the face behind it, which is what a tool bar button
// wears when the pointer is over it.
static void bevelUpAt(Surface *out, int x, int y, int w, int h) {
    fill(out, x, y, w, 1, (unsigned char)UI_LIGHT);
    fill(out, x, y, 1, h, (unsigned char)UI_LIGHT);
    fill(out, x, y + h - 1, w, 1, (unsigned char)UI_SHADOW);
    fill(out, x + w - 1, y, 1, h, (unsigned char)UI_SHADOW);
}

static void bevelDownAt(Surface *out, int x, int y, int w, int h) {
    fill(out, x, y, w, 1, (unsigned char)UI_SHADOW);
    fill(out, x, y, 1, h, (unsigned char)UI_SHADOW);
    fill(out, x, y + h - 1, w, 1, (unsigned char)UI_LIGHT);
    fill(out, x + w - 1, y, 1, h, (unsigned char)UI_LIGHT);
}

// The raised panel a menu is drawn on: white along the top and left, grey then
// black along the bottom and right.  That is the whole of the period's look.
static void raised(Surface *out, int x, int y, int w, int h) {
    fill(out, x, y, w, h, (unsigned char)UI_FACE);
    fill(out, x, y, w, 1, (unsigned char)UI_LIGHT);
    fill(out, x, y, 1, h, (unsigned char)UI_LIGHT);
    fill(out, x, y + h - 2, w - 1, 1, (unsigned char)UI_SHADOW);
    fill(out, x + w - 2, y, 1, h - 1, (unsigned char)UI_SHADOW);
    fill(out, x, y + h - 1, w, 1, (unsigned char)UI_DARK);
    fill(out, x + w - 1, y, 1, h, (unsigned char)UI_DARK);
}

// The little triangle that says an item has a menu of its own.
static void arrow(Surface *out, int x, int y, unsigned char ink) {
    for (int i = 0; i < 5; i++)
        fill(out, x + i, y + i, 1, 9 - i * 2, ink);
}

/* --------------------------------------------------------- the order menu */

void uiOrderInit(OrderMenu *menu) {
    memset(menu, 0, sizeof *menu);
    menu->hot = -1;
    menu->subOf = -1;
    menu->subHot = -1;
}

// The words the original puts in the strengths menu: order name one for "go
// back to Auto", order name zero for "stop where you are", and the order's own
// name with " continue" after it.
static const char *strengthName(const GameState *game, unsigned order,
                                int strength, char *scratch, int size) {
    if (strength == 0) return worldOrderName(&game->world, 1);
    if (strength == 1) return worldOrderName(&game->world, 0);
    const char *own = worldOrderName(&game->world, order);
    int at = 0;
    while (own[at] && at < size - 10) { scratch[at] = own[at]; at++; }
    const char *tail = " continue";
    for (int i = 0; tail[i] && at < size - 1; i++) scratch[at++] = tail[i];
    scratch[at] = 0;
    return scratch;
}

int uiOrderOpen(OrderMenu *menu, const GameState *game, int col, int row,
                int x, int y, int surfaceW, int surfaceH) {
    uiOrderInit(menu);
    if (col < 0 || row < 0 || col >= WORLD_GRID || row >= WORLD_GRID) return 0;
    const unsigned char terrain =
        game->world.cells[WORLD_INDEX((unsigned)col, (unsigned)row)].terrain;
    menu->klass = orderClassOf(terrain);
    menu->col = col;
    menu->row = row;

    int widest = 0;
    for (unsigned o = 0; o < 16; o++) {
        if (!orderAllowedOn(menu->klass, o)) continue;
        const char *name = worldOrderName(&game->world, o);
        if (!name || !*name) continue;
        menu->order[menu->count++] = (unsigned char)o;
        const int w = fontTextWidth(name);
        if (w > widest) widest = w;
    }
    if (!menu->count) return 0;

    // A Cancel row, the way 00423940 finishes its menu.
    const int cancel = fontTextWidth("Cancel");
    if (cancel > widest) widest = cancel;

    menu->width = widest + 32;
    const int height = (menu->count + 1) * UI_ITEM_H + 4;
    if (x + menu->width > surfaceW) x = surfaceW - menu->width;
    if (y + height > surfaceH) y = surfaceH - height;
    menu->x = x < 0 ? 0 : x;
    menu->y = y < 0 ? 0 : y;
    menu->surfaceW = surfaceW;
    menu->surfaceH = surfaceH;
    menu->open = 1;
    return 1;
}

void uiOrderClose(OrderMenu *menu) { uiOrderInit(menu); }

static int rowAt(const OrderMenu *menu, int x, int y) {
    const int height = (menu->count + 1) * UI_ITEM_H + 4;
    if (x < menu->x || x >= menu->x + menu->width) return -1;
    if (y < menu->y + 2 || y >= menu->y + height - 2) return -1;
    const int r = (y - menu->y - 2) / UI_ITEM_H;
    return r > menu->count ? -1 : r;
}

static int subRowAt(const OrderMenu *menu, int x, int y) {
    if (menu->subOf < 0) return -1;
    const int rows = orderStrengths(menu->order[menu->subOf]);
    if (x < menu->subX || x >= menu->subX + menu->subWidth) return -1;
    if (y < menu->subY + 2 || y >= menu->subY + 2 + rows * UI_ITEM_H) return -1;
    return (y - menu->subY - 2) / UI_ITEM_H;
}

static void openSub(OrderMenu *menu, const GameState *game, int which,
                    int surfaceW) {
    menu->subOf = which;
    menu->subHot = -1;
    const unsigned order = menu->order[which];
    char scratch[64];
    int widest = 0;
    for (int s = 0; s < orderStrengths(order); s++) {
        const char *name = strengthName(game, order, s, scratch,
                                        (int)sizeof scratch);
        const int w = fontTextWidth(name ? name : "");
        if (w > widest) widest = w;
    }
    menu->subWidth = widest + 20;
    menu->subX = menu->x + menu->width - 4;
    if (menu->subX + menu->subWidth > surfaceW)
        menu->subX = menu->x - menu->subWidth + 4;
    menu->subY = menu->y + 2 + which * UI_ITEM_H;
}

void uiOrderHover(OrderMenu *menu, const GameState *game, int x, int y) {
    if (!menu->open) return;
    const int sub = subRowAt(menu, x, y);
    if (sub >= 0) {
        menu->subHot = sub;
        return;
    }
    const int r = rowAt(menu, x, y);
    menu->hot = r;
    if (r >= 0 && r < menu->count && r != menu->subOf)
        openSub(menu, game, r, menu->surfaceW);
}

void uiOrderDraw(Surface *out, const GameState *game, const OrderMenu *menu) {
    if (!menu->open) return;
    const int height = (menu->count + 1) * UI_ITEM_H + 4;
    raised(out, menu->x, menu->y, menu->width, height);

    char scratch[64];
    for (int i = 0; i <= menu->count; i++) {
        const int y = menu->y + 2 + i * UI_ITEM_H;
        const char *name = i < menu->count
            ? worldOrderName(&game->world, menu->order[i]) : "Cancel";
        const int picked = (i == menu->hot);
        if (picked)
            fill(out, menu->x + 2, y, menu->width - 4, UI_ITEM_H,
                 (unsigned char)UI_PICK);
        fontDrawText(out, menu->x + 8, y + 1,
                     (unsigned char)(picked ? UI_PICK_TEXT : UI_DARK), name);
        if (i < menu->count)
            arrow(out, menu->x + menu->width - 12, y + 4,
                  (unsigned char)(picked ? UI_PICK_TEXT : UI_DARK));
    }

    if (menu->subOf >= 0) {
        const unsigned order = menu->order[menu->subOf];
        const int rows = orderStrengths(order);
        raised(out, menu->subX, menu->subY, menu->subWidth,
               rows * UI_ITEM_H + 4);
        for (int s = 0; s < rows; s++) {
            const int y = menu->subY + 2 + s * UI_ITEM_H;
            const char *name = strengthName(game, order, s, scratch,
                                            (int)sizeof scratch);
            const int picked = (s == menu->subHot);
            if (picked)
                fill(out, menu->subX + 2, y, menu->subWidth - 4, UI_ITEM_H,
                     (unsigned char)UI_PICK);
            fontDrawText(out, menu->subX + 8, y + 1,
                         (unsigned char)(picked ? UI_PICK_TEXT : UI_DARK),
                         name ? name : "");
        }
    }
}

int uiOrderClick(OrderMenu *menu, const GameState *game, int x, int y,
                 unsigned *order, int *strength) {
    if (!menu->open) return -1;

    const int sub = subRowAt(menu, x, y);
    if (sub >= 0) {
        *order = menu->order[menu->subOf];
        *strength = sub;
        uiOrderClose(menu);
        return 1;
    }
    const int r = rowAt(menu, x, y);
    if (r < 0) {                            // outside: the menu goes away
        uiOrderClose(menu);
        return -1;
    }
    if (r == menu->count) {                 // Cancel
        uiOrderClose(menu);
        return -1;
    }
    // An order with only one row of its own would be a menu for nothing, but
    // every order has at least two, so a click on the order opens them.
    openSub(menu, game, r, menu->surfaceW);
    menu->hot = r;
    return 0;
}

/* ------------------------------------------------------------ the menu bar */

// MENU 101 and the string table beside it, out of the executable's .rsrc.  The
// submenus the original nests - Load Map, Leader Position, Resize Map - are
// spelled out in their parent here, because a menu bar with one level of
// dropdown is the whole of what the game needs and a second level is a lot of
// hit-testing for two items.
//
// enabled = 0 draws greyed: the command is in the original and this port has
// nothing to do for it yet.
static const BarMenu kBar[UI_MENU_MAX] = {
    {"System", {
        {"Load",              40051, 1, 0},
        {"Save",              40021, 1, 0},
        {"Load Quest Map",    40020, 1, 0},
        {"Load Single Map",   40117, 1, 0},
        {NULL, 0, 0, 0},
        {"Restart",           40110, 1, 0},
        {"New",               40114, 1, 0},
        {NULL, 0, 0, 0},
        {"Quit",              40044, 1, 0},
    }, 9},
    {"Controls", {
        {"Start",             40045, 1, 1},
        {"Pause",             40030, 1, 1},
        {NULL, 0, 0, 0},
        {"Small",             40048, 1, 1},
        {"Medium",            40049, 1, 1},
        {"Large",             40050, 1, 1},
        {NULL, 0, 0, 0},
        {"Alliance Setting",  40012, 1, 0},
        {"System Setting",    40033, 1, 0},
        {"Sound Setting",     40116, 1, 0},
    }, 10},
    {"Display", {
        {"Unit Window",       60001, 1, 1},
        {"Progress Window",   60002, 1, 1},
        {"Graph Window",      60003, 1, 1},
        {NULL, 0, 0, 0},
        {"Hide Tool Bar",     60005, 1, 1},
        {"Hide Title Bar",    40108, 1, 1},
        {"Float Tool Bar",    40109, 0, 0},   // a docked bar has nowhere
                                      // to float to in a canvas
        {NULL, 0, 0, 0},
        {"Set Windows to default", 40111, 1, 0},
    }, 9},
    {"Orders", {
        {"Overall Order(For new units)", 40062, 1, 0},
        {"Overall Order(Override all)",  40061, 1, 0},
        {NULL, 0, 0, 0},
        {"Recall Leader",     40113, 1, 0},
        {NULL, 0, 0, 0},
        // Leader Position is a submenu of the four countries in the original -
        // 00408aa0 renames 40080 to 40083 with their names as a stage loads -
        // and one level of dropdown is what this bar has, so they sit here
        // with their names filled in at draw time.
        {"",                  40080, 1, 0},
        {"",                  40081, 1, 0},
        {"",                  40082, 1, 0},
        {"",                  40083, 1, 0},
        {NULL, 0, 0, 0},
        {"Default Orders",    40038, 1, 0},
    }, 11},
    {"Help", {
        {"Quick Rules",       40037, 1, 0},
        {"Version",           40055, 1, 0},
    }, 2},
};

void uiBarInit(MenuBar *bar) {
    memset(bar, 0, sizeof *bar);
    bar->open = -1;
    bar->hotMenu = -1;
    bar->hotItem = -1;
}

int uiBarOpen(const MenuBar *bar) { return bar->open >= 0; }

// Where each title sits.  Measured rather than stored, so the wording can
// change with the release without moving anything.
static void barPlaces(int *x) {
    int at = 4;
    for (int m = 0; m < UI_MENU_MAX; m++) {
        x[m] = at;
        at += fontTextWidth(kBar[m].text) + 12;
    }
    x[UI_MENU_MAX] = at;
}

static int barTitleAt(const int *x, int px, int py) {
    if (py < 0 || py >= UI_BAR_H) return -1;
    for (int m = 0; m < UI_MENU_MAX; m++)
        if (px >= x[m] - 4 && px < x[m + 1] - 4) return m;
    return -1;
}

static int dropWidth(int menu) {
    int widest = 0;
    for (int i = 0; i < kBar[menu].count; i++) {
        const char *t = kBar[menu].item[i].text;
        if (!t) continue;
        const int w = fontTextWidth(t);
        if (w > widest) widest = w;
    }
    // The four country rows are named as the menu is drawn, and a country name
    // can be long, so the box leaves room for one.
    if (menu == 3 && widest < 200) widest = 200;
    return widest + 40;
}

static int dropHeight(int menu) {
    int h = 4;
    for (int i = 0; i < kBar[menu].count; i++)
        h += kBar[menu].item[i].text ? UI_ITEM_H : 6;
    return h;
}

static int dropItemAt(int menu, const int *x, int px, int py) {
    if (px < x[menu] - 4 || px >= x[menu] - 4 + dropWidth(menu)) return -1;
    int at = UI_BAR_H + 2;
    for (int i = 0; i < kBar[menu].count; i++) {
        const int h = kBar[menu].item[i].text ? UI_ITEM_H : 6;
        if (py >= at && py < at + h) return kBar[menu].item[i].text ? i : -1;
        at += h;
    }
    return -1;
}

// What carries a tick just now.  The original ticks the map size that is on,
// the windows that are showing, and Start or Pause depending on which way the
// clock is going.
static int barTicked(int running, unsigned command) {
    switch (command) {
    case 40045: return running;
    case 40030: return !running;
    default: return 0;
    }
}

// 40080 to 40083 carry a country's name rather than a caption of their own.
static const char *barLabel(const GameState *game, const BarItem *item) {
    if (item->command >= 40080 && item->command <= 40083) {
        const char *name =
            worldCountryName(&game->world, item->command - 40080);
        return name && *name ? name : "-";
    }
    return item->text;
}

void uiBarDraw(Surface *out, const GameState *game, int running,
               const MenuBar *bar) {
    int x[UI_MENU_MAX + 1];
    barPlaces(x);

    fill(out, 0, 0, out->width, UI_BAR_H, (unsigned char)UI_FACE);
    fill(out, 0, UI_BAR_H - 1, out->width, 1, (unsigned char)UI_SHADOW);
    for (int m = 0; m < UI_MENU_MAX; m++) {
        const int lit = (m == bar->open) || (m == bar->hotMenu);
        if (lit)
            fill(out, x[m] - 4, 1, x[m + 1] - x[m], UI_BAR_H - 2,
                 (unsigned char)UI_PICK);
        fontDrawText(out, x[m], 2,
                     (unsigned char)(lit ? UI_PICK_TEXT : UI_DARK),
                     kBar[m].text);
    }
    if (bar->open < 0) return;

    const int menu = bar->open;
    const int w = dropWidth(menu), h = dropHeight(menu);
    raised(out, x[menu] - 4, UI_BAR_H, w, h);
    int at = UI_BAR_H + 2;
    for (int i = 0; i < kBar[menu].count; i++) {
        const BarItem *item = &kBar[menu].item[i];
        if (!item->text) {
            fill(out, x[menu], at + 2, w - 12, 1, (unsigned char)UI_SHADOW);
            fill(out, x[menu], at + 3, w - 12, 1, (unsigned char)UI_LIGHT);
            at += 6;
            continue;
        }
        const int picked = (i == bar->hotItem) && item->enabled;
        if (picked)
            fill(out, x[menu] - 2, at, w - 4, UI_ITEM_H,
                 (unsigned char)UI_PICK);
        unsigned char ink = (unsigned char)UI_DARK;
        if (!item->enabled) ink = (unsigned char)UI_GREY_TEXT;
        else if (picked) ink = (unsigned char)UI_PICK_TEXT;
        fontDrawText(out, x[menu] + 16, at + 1, ink,
                     barLabel(game, item));
        if (item->tick && barTicked(running, item->command)) {
            // A tick, drawn rather than taken from a font: two strokes.
            for (int k = 0; k < 4; k++)
                fill(out, x[menu] + 3 + k, at + 8 + k, 1, 2, ink);
            for (int k = 0; k < 6; k++)
                fill(out, x[menu] + 7 + k, at + 10 - k, 1, 2, ink);
        }
        at += UI_ITEM_H;
    }
}

int uiBarHover(MenuBar *bar, int x, int y) {
    int places[UI_MENU_MAX + 1];
    barPlaces(places);
    const int title = barTitleAt(places, x, y);
    if (title >= 0) {
        bar->hotMenu = title;
        bar->hotItem = -1;
        // Sliding along the bar with a menu down opens the next one, which is
        // what a menu bar does.
        if (bar->open >= 0) bar->open = title;
        return 1;
    }
    bar->hotMenu = -1;
    if (bar->open < 0) return y < UI_BAR_H;
    bar->hotItem = dropItemAt(bar->open, places, x, y);
    return bar->hotItem >= 0 ||
           (x >= places[bar->open] - 4 &&
            x < places[bar->open] - 4 + dropWidth(bar->open) &&
            y < UI_BAR_H + dropHeight(bar->open));
}

unsigned uiBarClick(MenuBar *bar, int x, int y, int *inside) {
    int places[UI_MENU_MAX + 1];
    barPlaces(places);
    *inside = 0;

    const int title = barTitleAt(places, x, y);
    if (title >= 0) {
        *inside = 1;
        bar->open = (bar->open == title) ? -1 : title;
        bar->hotItem = -1;
        return 0;
    }
    if (y < UI_BAR_H) {                     // the bar, but not on a title
        *inside = 1;
        bar->open = -1;
        return 0;
    }
    if (bar->open < 0) return 0;            // nothing of ours down there

    const int item = dropItemAt(bar->open, places, x, y);
    const int over = x >= places[bar->open] - 4 &&
                     x < places[bar->open] - 4 + dropWidth(bar->open) &&
                     y < UI_BAR_H + dropHeight(bar->open);
    if (!over) {                            // a click away closes it
        bar->open = -1;
        return 0;
    }
    *inside = 1;
    if (item < 0) return 0;
    const BarItem *chosen = &kBar[bar->open].item[item];
    bar->open = -1;
    bar->hotItem = -1;
    return chosen->enabled ? chosen->command : 0;
}


/* ------------------------------------------------------------ the tool bar */

void uiToolInit(ToolBar *tool) {
    tool->hot = -1;
    tool->held = -1;
}

// Where each button starts, walking the resource: a button is as wide as its
// icon plus a little, a separator is a narrow gap.
#define TOOL_PAD 4
#define TOOL_SEP 8

static int toolPlace(int button) {
    int at = 2;
    for (int i = 0; i < button && i < kToolbarButtons; i++)
        at += kToolbarCommand[i] ? kToolbarButton + TOOL_PAD * 2 : TOOL_SEP;
    return at;
}

// Which button a point is on, counting separators out.
static int toolAt(int x, int y) {
    if (y < UI_BAR_H || y >= UI_BAR_H + UI_TOOL_H) return -1;
    for (int i = 0; i < kToolbarButtons; i++) {
        if (!kToolbarCommand[i]) continue;
        const int at = toolPlace(i);
        if (x >= at && x < at + kToolbarButton + TOOL_PAD * 2) return i;
    }
    return -1;
}

// What carries the pressed look because it is what the game is doing.
static int toolLatched(int command, int running, int zoom) {
    switch (command) {
    case 40045: return running;
    case 40030: return !running;
    case 40048: return zoom == 0;
    case 40049: return zoom == 1;
    case 40050: return zoom == 2;
    default: return 0;
    }
}

void uiToolDraw(Surface *out, const ToolBar *tool, int running, int zoom) {
    fill(out, 0, UI_BAR_H, out->width, UI_TOOL_H, (unsigned char)UI_FACE);
    fill(out, 0, UI_BAR_H + UI_TOOL_H - 1, out->width, 1,
         (unsigned char)UI_SHADOW);

    int image = 0;
    for (int i = 0; i < kToolbarButtons; i++) {
        const int command = kToolbarCommand[i];
        const int at = toolPlace(i);
        if (!command) {
            // A separator: the groove the period drew between groups.
            fill(out, at + TOOL_SEP / 2 - 1, UI_BAR_H + 3, 1, UI_TOOL_H - 8,
                 (unsigned char)UI_SHADOW);
            fill(out, at + TOOL_SEP / 2, UI_BAR_H + 3, 1, UI_TOOL_H - 8,
                 (unsigned char)UI_LIGHT);
            continue;
        }
        const int bw = kToolbarButton + TOOL_PAD * 2;
        const int down = (tool->held == i && tool->hot == i) ||
                         toolLatched(command, running, zoom);
        if (tool->hot == i || down) {
            if (down) bevelDownAt(out, at, UI_BAR_H + 2, bw, UI_TOOL_H - 5);
            else bevelUpAt(out, at, UI_BAR_H + 2, bw, UI_TOOL_H - 5);
        }
        // The icon, with the face grey left out so the button shows through.
        const int ix = image * kToolbarButton;
        for (int y = 0; y < kToolbarH; y++)
            for (int x = 0; x < kToolbarButton; x++) {
                const unsigned char v =
                    kToolbarPixels[(size_t)y * kToolbarW + ix + x];
                if (v == 7) continue;           // the face grey is the paper
                const int px = at + TOOL_PAD + x + (down ? 1 : 0);
                const int py = UI_BAR_H + 4 + y + (down ? 1 : 0);
                if (px < 0 || px >= out->width || py < 0 || py >= out->height)
                    continue;
                out->pixels[(size_t)py * out->width + px] =
                    (unsigned char)(UI_TOOL_BASE + v);
            }
        image++;
    }
}

int uiToolHover(ToolBar *tool, int x, int y) {
    if (y < UI_BAR_H || y >= UI_BAR_H + UI_TOOL_H) {
        tool->hot = -1;
        return 0;
    }
    tool->hot = toolAt(x, y);
    return 1;
}

unsigned uiToolClick(ToolBar *tool, int x, int y, int *inside) {
    *inside = 0;
    if (y < UI_BAR_H || y >= UI_BAR_H + UI_TOOL_H) return 0;
    *inside = 1;
    const int i = toolAt(x, y);
    tool->held = -1;
    if (i < 0) return 0;
    return kToolbarCommand[i];
}
