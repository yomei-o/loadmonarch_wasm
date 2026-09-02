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

// Draws the units on top by sweeping the cells the way 004240c0 does: each
// cell names its occupant, its order balloon goes one cell above, and a sprite
// parked on the cell itself (the cursor) goes last.  0041b520 decides the
// sprite number; see render.c for how it is packed.
void renderUnits(const GameState *game, int zoom, int viewX, int viewY,
                 int transpose, Surface *out);

// The game's own digits, measured off the interface sheet: eight by sixteen at
// the top of it, and a four by eight set below.  White and red of each.
typedef enum {
    UI_FONT_LARGE_WHITE = 0,
    UI_FONT_LARGE_RED,
    UI_FONT_SMALL_WHITE,
    UI_FONT_SMALL_RED,
} UiFont;

// Draws a number in one of those fonts, right-aligned to (x, y).  Returns the
// width it took.
int renderNumber(const World *world, UiFont font, int x, int y,
                 unsigned value, Surface *out);

// 0041b520: the sprite number an entity shows, packed out of its size, its
// faction, which way it faces and the frame counter.  Exposed so the packing
// can be tested without a surface.
unsigned renderSpriteNumber(const Entity *entity, unsigned frame);

// Fills a 256-entry colour table for the surface: the terrain, sprite and
// interface bands at once, with the two entries the game pulses scaled by
// where `game->frame` has reached.  Every host uses this rather than its own.
// The colour a country is drawn in, as 0xRRGGBB.  The name table carries a
// palette index per country (00405fc0 reads it out of the first byte of each
// record and blanks it), and every scenery set chooses its own, so this is the
// only honest source for a swatch beside a country's name.
unsigned renderCountryColour(const GameState *game, int zoom, unsigned faction);

void renderPalette(const GameState *game, int zoom,
                   unsigned char table[256][3]);

// A strip along the top of the view: each faction's purse and tax rate in the
// game's own numerals.
void renderStatus(const GameState *game, Surface *out);

#endif
