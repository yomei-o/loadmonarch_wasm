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

// The purse, the tax rate, the days gone and the days left, with the share of
// the board along the top.
void panelProgressWindow(Surface *out, const GameState *game, unsigned faction,
                         unsigned days, unsigned daysLeft, int x, int y);

// 00404e40's eight lines a column, in its own words.
void panelGraphWindow(Surface *out, const GameState *game, int x, int y,
                      int w, int h);

#endif
