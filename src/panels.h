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

// The Graph Window (00404c30, 0040463b, 00404890, 00404960), which is a bar
// chart and not a list of anything: 176 by 176, transparent where nothing is
// drawn, with five countries' worth of bars in it.
//
// Each country has four, sixteen pixels apart, in two halves of the window:
//
//   bar 0  its leader's strength   x = 16 + f*32       up from y = 168
//   bar 1  its total               x = 16 + f*32 + 16  up from y = 168
//   bar 2  the ground it holds     x = 16 + f*32       up from y = 52
//   bar 3  its purse               x = 16 + f*32 + 16  up from y = 52
//
// A bar is fourteen wide inside its sixteen, in the country's own colour, and
// carries a sixteen-pixel picture on its head: its leader, one of its units,
// a house that grows with the ground it holds, or a stack of coins.
//
// The seventeen sentences 00404e40 writes are not drawn in the window at all
// - they are the tooltips its bars carry, one per bar plus the neutral
// country's - which is what panelGraphTip answers.
#define GRAPH_BARS 20               // five countries, four apiece
#define GRAPH_LINES 17              // and the sentences that go with them
#define GRAPH_W 176
#define GRAPH_H 176

// What the window remembers between ticks: 00404890 moves a bar one pixel at
// a time towards where it should be, and 00404960 winds a dying country's
// picture through five frames.
typedef struct {
    short height[GRAPH_BARS];       // +0x394
    unsigned char gone[GRAPH_BARS]; // +0x39d bit 1: nothing there
    unsigned char phase[GRAPH_BARS];// +0x39e
} GraphWindow;

// One tick of it: every bar takes a step towards what the war says it should
// be.  0040463b works the targets out and 00404890 walks them.
void panelGraphTick(GraphWindow *win, const GameState *game);

// And the drawing, at the window's top left.
void panelGraphDraw(Surface *out, const GraphWindow *win,
                    const GameState *game, int x, int y);

// The sentence for the bar under a point inside the window, or nothing.
// 00404d37 hands each bar's rectangle and its sentence to the tooltip window
// with WM_USER+4; the rectangles are sixteen wide, the top eight from y = 0 to
// 0x40 and the bottom nine from 0x40 to 0xb0.
int panelGraphTip(const GameState *game, int px, int py, char *out, int size);

#endif
