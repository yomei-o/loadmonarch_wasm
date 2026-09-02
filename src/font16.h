// The Shinonome 16-dot bitmap font, as tools/make_font.py lays it out.
//
// The original draws every string with GDI, so a port that only has the
// interface sheet's digits cannot write a country's name, or "has Fallen", or
// anything else the game says.  This is the font that lets it.
#ifndef FONT16_H
#define FONT16_H

// Half width, eight by sixteen, one byte a row, indexed by the byte itself -
// ASCII and the JIS X 0201 katakana at 0xa1 to 0xdf.
extern const unsigned char kFontHalf[256][16];

// Full width, sixteen by sixteen, two bytes a row, indexed through
// kFontWideCode - a sorted table of Shift-JIS codes, so a lookup is a binary
// search.
extern const unsigned short kFontWideCode[];
extern const unsigned char kFontWide[][32];
extern const unsigned kFontWideCount;

#endif
