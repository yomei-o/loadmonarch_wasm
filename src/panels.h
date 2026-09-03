// The three windows the game opens beside the board - Unit, Progress and
// Graph, which are dialogs 105, 114 and 121 and have no controls at all
// because the program draws their insides itself.  See panels.c.
#ifndef PANELS_H
#define PANELS_H

#include "render.h"
#include "state.h"

#define PANEL_SIDE 176          // both sheet panels are square and this wide

// 00426900: the cell under the cursor - its tile, its worth, and the gauge.
// `terrain` below zero means the cursor is off the board.
void panelUnitWindow(Surface *out, const GameState *game, int x, int y,
                     int terrain, unsigned value);

// The purse, the tax rate, the days gone and the days left, and the three
// markers 00419ab0 lays on the window's strips: what the tax would be left to
// itself, what the player has set it to, and how fast the clock is running.
// `frame` is DAT_00435b1c, the frame counter - the clock that slides along the
// middle strip turns as it goes, in eight steps.
void panelProgressWindow(Surface *out, const GameState *game, unsigned faction,
                         unsigned days, unsigned daysLeft, int speed,
                         unsigned frame, int x, int y);

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

// 00404e40's eight lines a column, in its own words.
void panelGraphWindow(Surface *out, const GameState *game, int x, int y,
                      int w, int h);

#endif
