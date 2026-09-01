// The renderer: the world into an eight-bit indexed surface.  See render.c.
#ifndef RENDER_H
#define RENDER_H

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
void renderWorld(const World *world, int zoom, int viewX, int viewY,
                 Surface *out);

#endif
