#include "ui.h"

#include "font.h"

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
