#include "font.h"

#include "font16.h"

#include <stddef.h>

// A lead byte of a Shift-JIS pair.
static int isLead(unsigned char c) {
    return (c >= 0x81 && c <= 0x9f) || (c >= 0xe0 && c <= 0xef);
}

// kFontWideCode is sorted, so this is a binary search.
static const unsigned char *wideGlyph(unsigned code) {
    unsigned low = 0, high = kFontWideCount;
    while (low < high) {
        const unsigned mid = (low + high) / 2u;
        if (kFontWideCode[mid] == code) return kFontWide[mid];
        if (kFontWideCode[mid] < code) low = mid + 1u;
        else high = mid;
    }
    return NULL;
}

int fontCanDraw(const char *text, unsigned *firstMissing) {
    if (firstMissing) *firstMissing = 0;
    for (const unsigned char *p = (const unsigned char *)text; *p;) {
        if (isLead(p[0]) && p[1]) {
            const unsigned code = ((unsigned)p[0] << 8) | p[1];
            if (!wideGlyph(code)) {
                if (firstMissing) *firstMissing = code;
                return 0;
            }
            p += 2;
            continue;
        }
        // Every half-width code has a cell, though plenty of them are blank -
        // the ones this font leaves empty are the control codes, which no
        // caption carries.
        p++;
    }
    return 1;
}

int fontTextWidth(const char *text) {
    int width = 0;
    for (const unsigned char *p = (const unsigned char *)text; *p;) {
        if (isLead(p[0]) && p[1]) {
            width += 16;
            p += 2;
        } else {
            width += 8;
            p++;
        }
    }
    return width;
}

static void plot(Surface *out, int x, int y, unsigned char ink) {
    if (x < 0 || y < 0 || x >= out->width || y >= out->height) return;
    out->pixels[(size_t)y * out->width + x] = ink;
}

// A hollow box, for a character the subset does not carry.
static void drawBox(Surface *out, int x, int y, int w, unsigned char ink) {
    for (int i = 1; i < w - 1; i++) {
        plot(out, x + i, y + 2, ink);
        plot(out, x + i, y + 14, ink);
    }
    for (int i = 2; i <= 14; i++) {
        plot(out, x + 1, y + i, ink);
        plot(out, x + w - 2, y + i, ink);
    }
}

static int drawUpTo(Surface *out, int x, int y, int right, unsigned char ink,
                    const char *text);

int fontDrawText(Surface *out, int x, int y, unsigned char ink,
                 const char *text) {
    return drawUpTo(out, x, y, 1 << 24, ink, text);
}

int fontDrawTextClipped(Surface *out, int x, int y, int right,
                        unsigned char ink, const char *text) {
    return drawUpTo(out, x, y, right, ink, text);
}

static int drawUpTo(Surface *out, int x, int y, int right, unsigned char ink,
                    const char *text) {
    int at = x;
    for (const unsigned char *p = (const unsigned char *)text; *p;) {
        if (isLead(p[0]) && p[1]) {
            if (at + 16 > right) break;
            const unsigned code = ((unsigned)p[0] << 8) | p[1];
            const unsigned char *glyph = wideGlyph(code);
            if (glyph) {
                for (int row = 0; row < 16; row++) {
                    const unsigned bits =
                        ((unsigned)glyph[row * 2] << 8) | glyph[row * 2 + 1];
                    for (int col = 0; col < 16; col++)
                        if (bits & (0x8000u >> col))
                            plot(out, at + col, y + row, ink);
                }
            } else {
                drawBox(out, at, y, 16, ink);
            }
            at += 16;
            p += 2;
        } else {
            if (at + 8 > right) break;
            const unsigned char *glyph = kFontHalf[p[0]];
            for (int row = 0; row < 16; row++)
                for (int col = 0; col < 8; col++)
                    if (glyph[row] & (0x80u >> col))
                        plot(out, at + col, y + row, ink);
            at += 8;
            p++;
        }
    }
    return at - x;
}

int fontDrawTextRight(Surface *out, int x, int y, unsigned char ink,
                      const char *text) {
    const int width = fontTextWidth(text);
    fontDrawText(out, x - width, y, ink, text);
    return width;
}

unsigned char fontInk(const World *world, UiFont font) {
    unsigned char ink = 0xff;
    const UiSheet *ui = &world->ui;
    if (!ui->pixels) return ink;
    // The zero of that font, whose first inked pixel is the colour the game
    // draws its numbers in.  Reading it beats writing a number down here: the
    // interface palette belongs to data1.rgb and changes with the release.
    int sx = 0, sy = 0, w = 8, h = 16;
    switch (font) {
    case UI_FONT_LARGE_WHITE: sx = 0; sy = 0; break;
    case UI_FONT_LARGE_RED:   sx = 0; sy = 16; break;
    case UI_FONT_SMALL_WHITE: sx = 0; sy = 32; w = 4; h = 8; break;
    case UI_FONT_SMALL_RED:   sx = 0; sy = 48; w = 4; h = 8; break;
    default: break;
    }
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++) {
            const unsigned char v =
                ui->pixels[(size_t)(sy + y) * UI_SHEET_W + sx + x];
            if (v != UI_TRANSPARENT) return v;
        }
    return ink;
}
