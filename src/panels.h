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

// The purse, the tax rate, the days gone and the days left - and the two
// strips 0041a1b0 lets the player drag: the tax along the top and the clock
// along the bottom, both nought to thirty.
void panelProgressWindow(Surface *out, const GameState *game, unsigned faction,
                         unsigned days, unsigned daysLeft, int speed,
                         int x, int y);

// Which of the two strips a point in the window is on, and what value it means
// there.  0 neither, 1 the tax, 2 the clock.  The arithmetic is 0041a1b0's:
// the strip runs from x 24 to x 148 and answers nought to thirty.
typedef enum { PANEL_SLIDER_NONE = 0, PANEL_SLIDER_TAX, PANEL_SLIDER_SPEED }
    PanelSlider;

PanelSlider panelProgressSlider(int px, int py, int *value);

// 00404e40's eight lines a column, in its own words.
void panelGraphWindow(Surface *out, const GameState *game, int x, int y,
                      int w, int h);

#endif
