// The game's own furniture, drawn into the same surface as the map.
//
// The original is an MFC application, so every menu it shows is a real Windows
// menu.  The one that matters is 00423940's: choose units, click the square you
// want something done to, and a popup comes up at the cursor listing the orders
// that make sense on that square - two tables in the executable decide which,
// and on water the answer is order 7 alone, which is how a bridge is built.
//
// A page that puts HTML controls there instead gets the commands right and the
// feel wrong: the pointer has to leave the game to press them.  So this draws
// the menu in the surface, in the Windows 95 colours, and a click on it is a
// click in the game.
#ifndef UI_H
#define UI_H

#include "orders.h"
#include "render.h"
#include "sim.h"

// Palette entries the chrome uses.  Nothing in the game's own art draws with
// 0xf0 and up; renderPalette fills them in.
#define UI_FACE      0xf0u      // 192,192,192 - the face of a control
#define UI_LIGHT     0xf1u      // white - the lit edge
#define UI_SHADOW    0xf2u      // 128,128,128 - the shaded edge
#define UI_DARK      0xf3u      // black - the outer edge and the text
#define UI_PICK      0xf4u      // 0,0,128 - behind the item under the pointer
#define UI_PICK_TEXT 0xf5u      // white on that
#define UI_GREY_TEXT 0xf6u      // 128,128,128 - a command that cannot be used

#define UI_ITEM_H 18            // one row of a menu
#define UI_ORDERS_MAX 16

typedef struct {
    int open;                   // is a popup up
    int x, y;                   // its top left, in surface pixels
    int width;                  // measured when it opens
    int col, row;               // the square it is about
    OrderClass klass;
    unsigned char order[UI_ORDERS_MAX];
    int count;                  // how many orders are offered
    int hot;                    // the row under the pointer, or -1
    int subOf;                  // the row whose strengths are showing, or -1
    int subHot;                 // and which of them, or -1
    int subX, subY, subWidth;
    int surfaceW, surfaceH;     // remembered so a submenu can be kept on screen
} OrderMenu;

void uiOrderInit(OrderMenu *menu);

// Builds the menu for a square and puts it at (x, y), clamped so it fits.
// Non-zero when there was at least one order to offer.
int uiOrderOpen(OrderMenu *menu, const GameState *game, int col, int row,
                int x, int y, int surfaceW, int surfaceH);

void uiOrderClose(OrderMenu *menu);

// Draws it.  Needs the world for the order names, which the scenery set
// supplies and which are the words the original puts in this menu.
void uiOrderDraw(Surface *out, const GameState *game, const OrderMenu *menu);

// The pointer moved over the surface.
void uiOrderHover(OrderMenu *menu, const GameState *game, int x, int y);

// A click.  Answers 1 when an order was chosen - `order` and `strength` say
// which - 0 while the pointer is still working through the menu, and -1 when
// the menu was dismissed.
int uiOrderClick(OrderMenu *menu, const GameState *game, int x, int y,
                 unsigned *order, int *strength);


/* ------------------------------------------------------------ the menu bar */

// MENU 101 out of the executable's .rsrc, item for item and command for
// command, with the wording from its string table.  A command the port cannot
// carry out yet is marked so it draws greyed, the way Windows draws one.
#define UI_BAR_H 20
#define UI_MENU_MAX 5
#define UI_MENU_ITEMS 12

typedef struct {
    const char *text;           // NULL for a separator
    unsigned command;
    unsigned char enabled;
    unsigned char tick;         // 1 when this item can carry a tick
} BarItem;

typedef struct {
    const char *text;
    BarItem item[UI_MENU_ITEMS];
    int count;
} BarMenu;

typedef struct {
    int open;                   // which menu is down, or -1
    int hotMenu;                // which title the pointer is over, or -1
    int hotItem;
    int x[UI_MENU_MAX + 1];     // where each title starts, measured on draw
    int width;                  // of the open menu
} MenuBar;

void uiBarInit(MenuBar *bar);
// `running` is what the host's own clock is doing, which is what ticks
// Start or Pause.
void uiBarDraw(Surface *out, const GameState *game, int running,
               const MenuBar *bar);
int uiBarHover(MenuBar *bar, int x, int y);
unsigned uiBarClick(MenuBar *bar, int x, int y, int *inside);
int uiBarOpen(const MenuBar *bar);

#endif
