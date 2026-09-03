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
// 0040a870 builds its own twelve colours for the end-of-stage window,
// and two of them are not in the scheme above: the grey its headings are
// cut in and the red its penalty line is.  See src/endstage.c.
#define UI_END_GREY  0xf7u      // 80,80,80
#define UI_END_RED   0xf8u      // 245,0,0
// A tooltip's own two, which are the desktop's rather than the game's:
// COLOR_INFOBK and COLOR_INFOTEXT.
#define UI_TIP_FACE  0xf9u      // 255,255,225
#define UI_TIP_TEXT  0xfau      // 0,0,0

// 0040a870, the string drawer the game's own painted windows use.  It builds
// twelve COLORREFs on the stack, and every call names two of them: the ink,
// and a shadow drawn one pixel down and right.  The index is the original's
// own, so a call reads the way the executable has it.
//
//    0 white   1 black    the notices
//    2 white   3 black    the end-of-stage numbers
//    4 red     5 grey     its penalty line
//    6 grey    7 white    its headings
//    8 white   9 blue     unused by anything that calls it
//   10 black  11 white
unsigned char uiTextInk(int index);
void uiTextOut(Surface *out, int x, int y, int ink, int shadow,
               const char *text);
// The same centred in a window `width` wide, which is what 0040a870 does when
// its seventh argument is set: it measures the string and puts it at
// (width - measured) / 2.
void uiTextOutMid(Surface *out, int left, int width, int y, int ink,
                  int shadow, const char *text);

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


/* --------------------------------------------- 0040b0a0's country popup */

// The tool bar's 40120 does not toggle anything: 0040b0a0 puts up a popup and
// posts whatever is picked as a command.  0040b1d0 fills it - one item per
// country, named as the scenery set names it, command 0xea66 + n, ticked when
// that country's Status Window is already up and greyed while the country
// carries flag 0x40.
typedef struct {
    int open;
    int x, y, width;
    int hot;                    // the row under the pointer, or -1
    unsigned char ticked[PLAYABLE_FACTIONS];
    unsigned char greyed[PLAYABLE_FACTIONS];
} CountryMenu;

void uiCountryMenuInit(CountryMenu *menu);

// Opens it where the pointer is, clamped to the surface.  `shown` is the four
// window flags, which decide the ticks.
void uiCountryMenuOpen(CountryMenu *menu, const GameState *game,
                       const int *shown, int surfaceW, int surfaceH);

void uiCountryMenuDraw(Surface *out, const GameState *game,
                       const CountryMenu *menu);
void uiCountryMenuHover(CountryMenu *menu, int x, int y);

// A click: the command 0xea66 + n when one was picked, 0 while the pointer is
// still in the menu, and -1 when it was dismissed.
int uiCountryMenuClick(CountryMenu *menu, int x, int y);


/* ------------------------------------------------------------ the menu bar */

// MENU 101 out of the executable's .rsrc, item for item and command for
// command, with the wording from its string table.  A command the port cannot
// carry out yet is marked so it draws greyed, the way Windows draws one.
#define UI_BAR_H 20             // how tall the menu bar is
#define UI_TOOL_H 24            // and the tool bar under it
#define UI_CHROME_H (UI_BAR_H + UI_TOOL_H)

// The tool bar's own palette goes here; the icons are four-bit and bring their
// own sixteen colours, which are the standard VGA ones.
#define UI_TOOL_BASE 0xd0u
#define UI_MENU_MAX 5
// Controls is the longest: Start, Pause, the four countries of Leader
// Position, the three of Resize Map, Alliance, the two Customize items
// and four separators.
#define UI_MENU_ITEMS 16

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

// The bar's own table, for a test that reads MENU 101 out of the executable
// and compares.  `text` is null where the item is a separator, and empty for
// the four Leader Position entries, whose captions are country names filled
// in as they are drawn.
const char *uiBarMenuName(int menu);
int uiBarMenuItems(int menu);
const char *uiBarItemText(int menu, int item);
unsigned uiBarItemCommand(int menu, int item);

// The words the bar shows, taken from MENU 101 of whichever release has been
// loaded rather than from the table above: the Japanese one writes its menu in
// Japanese, and both releases have the same items in the same places with the
// same commands - which tests/rsrc_test.c checks against both.  Shift-JIS,
// like everything else the port draws.  A null or empty string puts the
// built-in English back.
// What the tool bar says about the icon under the pointer.  The original
// imports LoadStringA and builds its bar with CreateToolbarEx, whose
// tooltips come out of the STRINGTABLE keyed by command - "Alliance
// Setting" for 40012 - so this is that string, in whichever language the
// release is.  A null or empty one puts the tooltip away.
void uiToolSetTip(unsigned command, const char *text);
const char *uiToolTip(unsigned command);

void uiBarSetMenuName(int menu, const char *text);
void uiBarSetItemText(int menu, int item, const char *text);
// And whether anything has been set, so a host can say where its words came
// from.
int uiBarTextLoaded(void);

/* ------------------------------------------------------------ the tool bar */

// Lord Monarch puts no words up there: twenty-three 16x16 icons out of
// BITMAP 102, with the command of each in the MFC tool bar resource beside it.
typedef struct {
    int hot;                    // the button under the pointer, or -1
    int held;                   // the one the button went down on, or -1
} ToolBar;

void uiToolInit(ToolBar *tool);

// Draws it under the menu bar.  `running` ticks Start or Pause, and `zoom`
// which of Small, Medium and Large is on.
void uiToolDraw(Surface *out, const ToolBar *tool, int running, int zoom);

// Non-zero when the pointer is over the bar at all.
int uiToolHover(ToolBar *tool, int x, int y);

// The command the button under the point sends, or 0.  *inside comes back
// non-zero when the point was on the bar, whether or not it hit a button.
unsigned uiToolClick(ToolBar *tool, int x, int y, int *inside);

#endif
