// The renderer: the world into an eight-bit indexed surface.  See render.c.
#ifndef RENDER_H
#define RENDER_H

#include "state.h"
#include "world.h"

typedef struct {
    int width;
    int height;
    unsigned char *pixels;      // width * height palette indices
} Surface;

void surfaceInit(Surface *surface, int width, int height,
                 unsigned char *pixels);

// Draws the terrain with the bank for `zoom` (0 small, 1 medium, 2 large),
// scrolled to the world pixel (viewX, viewY).  Off-map area comes out zero.
// The original's cell index is `a * 0x30 + b`, and comparing against the
// running game settles which is which: **a is the column, b is the row**.
// transpose = 1 is therefore the correct one; 0 is kept only so the two can
// be flipped side by side if the question ever comes up again.
void renderWorld(const World *world, int zoom, int viewX, int viewY,
                 int transpose, Surface *out);

// Draws the units on top, from the sprite bank the stage loaded.  1833's
// sprite number is 0xa0 + faction * 8 + frame, and the palette entry 0x70
// stands for "leave what is underneath" - which is what makes them read as
// figures rather than blocks.
void renderUnits(const GameState *game, int zoom, int viewX, int viewY,
                 int transpose, Surface *out);

#endif
