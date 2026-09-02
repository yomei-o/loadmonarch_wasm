// Drawing a string, which the original leaves to GDI and this port has to do
// itself.  The text is Shift-JIS, because that is what the game's own data is:
// the country and order names come out of the terrain file as Shift-JIS, and
// so does everything MAP/NAME.TXT says.
#ifndef FONT_H
#define FONT_H

#include "render.h"

// How wide the string will be: eight pixels a half-width byte, sixteen a
// full-width pair.
int fontTextWidth(const char *text);

// Draws it at x,y in one palette index, and answers the width.  Sixteen pixels
// tall.  A character the font does not carry is drawn as a hollow box, so a
// missing glyph shows up as a missing glyph rather than as nothing.
int fontDrawText(Surface *out, int x, int y, unsigned char ink,
                 const char *text);

// The same, ending at x rather than starting there - for a caption pinned to
// the right of a panel, the way the game's numbers are.
int fontDrawTextRight(Surface *out, int x, int y, unsigned char ink,
                      const char *text);

// The palette index the interface sheet's own digits are drawn in, so a string
// beside them is the same colour.  Answers 0xff if the sheet is not loaded.
unsigned char fontInk(const World *world, UiFont font);

#endif
