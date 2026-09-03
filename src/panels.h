// The three windows the game opens beside the board - Unit, Progress and
// Graph, which are dialogs 105, 114 and 121 and have no controls at all
// because the program draws their insides itself.  See panels.c.
#ifndef PANELS_H
#define PANELS_H

#include "render.h"
#include "state.h"

#define PANEL_SIDE 176          // both sheet panels are square and this wide

// 00426900.  The window has two halves and the routine draws both.
//
// The lower half is the cell under the cursor: its tile at (16,112), its
// gauge at (72,96), "NUM  %6d" or "DEF  %6d" at (64,120) and the name of the
// order a new unit will take - DAT_004365e0, `pending` - at (64,144).
//
// The upper half is the unit standing on that cell: its sprite at (16,48), a
// gauge of its strength at (72,16), "STR  %6d" at (64,40) and its own order
// at (64,64).  Where there is no unit, that last line reads "DIS. %d" - the
// cell's routing cost - or "DIS. -----" where there is no way there.
//
// `under` null means the cursor is off the board.  `unit` is the entity the
// window is showing, which is the window's own +0x394 and not the cell's
// occupant: 00426c4b replaces it only when the cell has one, so an empty cell
// leaves the last unit on show.  The caller keeps it, as the window does.
void panelUnitWindow(Surface *out, const GameState *game, int x, int y,
                     const WorldCell *under, unsigned pending, int unit);

// The purse, the tax rate, the days gone and the days left, and the three
// markers 00419ab0 lays on the window's strips: what the tax would be left to
// itself, what the player has set it to, and how fast the clock is running.
// `frame` is DAT_00435b1c, the frame counter - the clock that slides along the
// middle strip turns as it goes, in eight steps.
// `broke` is DAT_0043451c: 00419d49 writes the purse in red rather than
// white for the sweep in which the country could not pay for something.
void panelProgressWindow(Surface *out, const GameState *game, unsigned faction,
                         unsigned days, unsigned daysLeft, int speed,
                         unsigned frame, int broke, int x, int y);

// What a point in the window is on.  0041a1b0 reads two draggable strips - the
// tax along the top and the clock along the bottom - and 0041a3d0 reads the
// scales beside the tax, which turn the automatic tax on and off.
typedef enum {
    PANEL_SLIDER_NONE = 0,
    PANEL_SLIDER_TAX,
    PANEL_SLIDER_SPEED,
    PANEL_SLIDER_AUTOTAX        // the scales: a click toggles, no value
} PanelSlider;

PanelSlider panelProgressSlider(int px, int py, int *value);

// 0041d460 and 0041d220: one country's Status Window, which 0041d050 titles
// "Status Window <name>".  There is one per country, commands 60006 to 60009,
// and the tool bar's 40120 is the popup that opens them.  176 by 176 like the
// rest, and transparent where it is not drawn on - the original fills its
// bitmap with 0x70 and lets the board through.
void panelCountryWindow(Surface *out, const GameState *game, unsigned faction,
                        int x, int y);

// 0041dc60's own sum, which is what the blue marker on the tax strip shows:
// the rate the tax would settle at if nobody touched it.
int panelAutoTaxRate(const GameState *game, unsigned faction);

// The Graph Window: the seventeen lines 00404e40 writes, in the release's
// own wording, as many as the window is tall enough for, from `scroll`.  The
// original's is 176 by 176 with a Windows scroll bar in it (00404316 makes
// room for one and the program drives it with SetScrollInfo), so the lines
// are longer than it is wide in both releases and it shows a few at a time.
#define GRAPH_LINES 17
#define GRAPH_ROW_H 16          // 00404d53 steps its lines by 0x10
#define GRAPH_BAR_W 16
void panelGraphWindow(Surface *out, const GameState *game, int x, int y,
                      int w, int h, int scroll);

// How many of the seventeen a window that tall shows, and how many there are,
// so the caller can bound its own scroll.
int panelGraphRows(int h);
int panelGraphLines(void);

#endif
