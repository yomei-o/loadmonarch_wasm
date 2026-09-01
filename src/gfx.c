// Turning a decompressed .BZ into pixels, from 00406810.
//
// The payload is four bitplanes, the way PC-98 and EGA hardware wanted them:
// within a tile, plane 0 sits at +0x00, plane 1 at +0x20, plane 2 at +0x40 and
// plane 3 at +0x60, and one pixel's four bits come from the same bit position
// in each.  Every finished byte then gets 0x10 added - the game's sprites live
// in the second sixteen entries of the palette, not the first.
//
// Three tile sizes ship: 8x8 and 16x16 are direct, while a 32x32 is assembled
// out of four 16x16 quadrants named by a four-byte record in the table at
// 0x7ca0 of the same buffer.
#include "gfx.h"

#define PLANE_STRIDE 0x20u
#define TILE_SRC     0x80u          // bytes of source per 16x16 tile
#define QUAD_TABLE   0x7ca0u        // 32x32 quadrant records, 4 bytes each

// One pixel out of four planes at a byte offset within a tile.
static unsigned char planarPixel(const unsigned char *tile, unsigned byteOff,
                                 unsigned bit) {
    const unsigned mask = 0x80u >> bit;
    unsigned v = 0;
    if (tile[byteOff] & mask) v |= 1;
    if (tile[byteOff + PLANE_STRIDE] & mask) v |= 2;
    if (tile[byteOff + PLANE_STRIDE * 2] & mask) v |= 4;
    if (tile[byteOff + PLANE_STRIDE * 3] & mask) v |= 8;
    return (unsigned char)v;
}

// A 16x16 tile's 256 pixels, in reading order.
static void unpack16(const unsigned char *tile, unsigned char *out) {
    for (unsigned i = 0; i < 256; i++)
        out[i] = planarPixel(tile, i >> 3, i & 7);
}

int gfxUnpackTiles(const unsigned char *buf, unsigned bufSize, int tileSize,
                   unsigned char *out, unsigned outCapacity,
                   unsigned *tilesOut) {
    const unsigned tiles = 0x80;               // 128, for every size
    unsigned produced = 0;

    if (tileSize == 8) {
        // An 8x8 tile is the left half of a 16-wide plane row.
        if (bufSize < tiles * TILE_SRC || outCapacity < tiles * 64u) return 0;
        for (unsigned t = 0; t < tiles; t++) {
            const unsigned char *tile = buf + t * TILE_SRC;
            for (unsigned row = 0; row < 8; row++)
                for (unsigned col = 0; col < 8; col++)
                    out[produced++] = planarPixel(tile, row * 2, col);
        }
    } else if (tileSize == 16) {
        if (bufSize < tiles * TILE_SRC || outCapacity < tiles * 256u) return 0;
        for (unsigned t = 0; t < tiles; t++) {
            unpack16(buf + t * TILE_SRC, out + produced);
            produced += 256;
        }
    } else if (tileSize == 32) {
        if (bufSize < QUAD_TABLE + tiles * 4u ||
            outCapacity < tiles * 1024u) return 0;
        for (unsigned t = 0; t < tiles; t++) {
            const unsigned char *rec = buf + QUAD_TABLE + t * 4u;
            // Reading order of the record is top-left, bottom-left,
            // top-right, bottom-right - the two middle entries are swapped
            // relative to how the quadrants sit on screen.
            const unsigned quad[4] = {rec[0], rec[2], rec[1], rec[3]};
            unsigned char q[4][256];
            for (int i = 0; i < 4; i++)
                unpack16(buf + quad[i] * TILE_SRC, q[i]);
            for (unsigned row = 0; row < 32; row++) {
                const int top = row < 16;
                const unsigned sub = row & 15;
                for (unsigned col = 0; col < 32; col++) {
                    const int left = col < 16;
                    const unsigned char *src =
                        q[(top ? 0 : 2) + (left ? 0 : 1)];
                    out[produced++] = src[sub * 16 + (col & 15)];
                }
            }
        }
    } else {
        return 0;
    }

    // 00406810's closing pass over everything it just wrote.
    for (unsigned i = 0; i < produced; i++) out[i] = (unsigned char)(out[i] + 0x10);
    if (tilesOut) *tilesOut = tiles;
    return 1;
}

/* ------------------------------------------------------------- palettes */

// 004065e0: the bank's own sixteen colours sit at 0x8000, three bytes each,
// four bits per channel in the order blue, red, green - so each is shifted up
// by four to fill a byte.  004065e0's caller asks for 0x10 entries starting
// at palette index 0x10, which is exactly the bias 00406810 applies.
static int tilePaletteAt(const unsigned char *buf, unsigned bufSize,
                         unsigned char *rgb256, unsigned base) {
    if (bufSize < 0x8000u + 16u * 3u) return 0;
    const unsigned char *src = buf + 0x8000u;
    for (unsigned i = 0; i < 16; i++) {
        unsigned char *dst = rgb256 + (base + i) * 3u;
        dst[0] = (unsigned char)(src[1] << 4);   // red
        dst[1] = (unsigned char)(src[2] << 4);   // green
        dst[2] = (unsigned char)(src[0] << 4);   // blue
        src += 3;
    }
    return 1;
}

int gfxTilePalette(const unsigned char *buf, unsigned bufSize,
                   unsigned char *rgb256) {
    return tilePaletteAt(buf, bufSize, rgb256, 0x10u);
}

int gfxSpritePalette(const unsigned char *buf, unsigned bufSize,
                     unsigned char *rgb256) {
    return tilePaletteAt(buf, bufSize, rgb256, 0x30u);
}

// 0040e560 with start 0x80 and count 0x30: data1.rgb's entries are already
// eight bits per channel, red first, with a flag byte the palette ignores.
void gfxUiPalette(const unsigned char *rgbFile, unsigned size,
                  unsigned char *rgb256) {
    for (unsigned i = 0; i < 0x30u && (i + 1) * 4u <= size; i++) {
        unsigned char *dst = rgb256 + (0x80u + i) * 3u;
        dst[0] = rgbFile[i * 4 + 0];
        dst[1] = rgbFile[i * 4 + 1];
        dst[2] = rgbFile[i * 4 + 2];
    }
}

// 00406c70's 16-pixel path.  Same four planes as the terrain banks, but a full
// nibble means "draw nothing here" and everything else lands in the palette
// bank at 0x30 rather than 0x10.
int gfxUnpackSprites(const unsigned char *buf, unsigned bufSize,
                     unsigned char *out, unsigned outCapacity,
                     unsigned *tilesOut) {
    const unsigned tiles = CHR_TILES;
    if (bufSize < tiles * TILE_SRC || outCapacity < tiles * 256u) return 0;
    unsigned produced = 0;
    for (unsigned t = 0; t < tiles; t++) {
        const unsigned char *tile = buf + t * TILE_SRC;
        for (unsigned i = 0; i < 256; i++) {
            const unsigned char v = planarPixel(tile, i >> 3, i & 7);
            out[produced++] = v == 0x0f ? CHR_TRANSPARENT
                                        : (unsigned char)(v + 0x30);
        }
    }
    if (tilesOut) *tilesOut = tiles;
    return 1;
}

// 00406c70's 8-pixel path.  The rearrangement is the whole difference: the
// unpacked 16x16 is cut into quarters, and the halves are taken down a column
// at a time - left top, left bottom, right top, right bottom.
int gfxUnpackSprites8(const unsigned char *buf, unsigned bufSize,
                      unsigned char *out, unsigned outCapacity,
                      unsigned *tilesOut) {
    // 208 tiles, four to a source block, so 52 blocks - and the file is
    // exactly that long.  The original's loop runs to 0x2000 instead and reads
    // twelve blocks past the end into a bank that has no room for them; the
    // bound below is the one the data supports.
    const unsigned sources = CHR_TILES8 / 4u;           // 52
    if (bufSize < sources * TILE_SRC) return 0;
    if (outCapacity < CHR_TILES8 * 64u) return 0;
    unsigned produced = 0;
    for (unsigned s = 0; s < sources; s++) {
        const unsigned char *tile = buf + s * TILE_SRC;
        unsigned char full[256];
        // Every block but the last lays its transparent nibble on the pulsing
        // colour, which is what makes a unit visible at this size.
        const unsigned char ground =
            s * TILE_SRC < 0x1980u ? CHR_PULSE : CHR_TRANSPARENT;
        for (unsigned i = 0; i < 256; i++) {
            const unsigned char v = planarPixel(tile, i >> 3, i & 7);
            full[i] = v == 0x0f ? ground : (unsigned char)(v + 0x30);
        }
        for (unsigned half = 0; half < 2; half++) {          // left, right
            for (unsigned band = 0; band < 2; band++) {      // top, bottom
                for (unsigned row = 0; row < 8; row++) {
                    const unsigned sourceRow = band * 8 + row;
                    for (unsigned col = 0; col < 8; col++)
                        out[produced++] = full[sourceRow * 16 + half * 8 + col];
                }
            }
        }
    }
    if (tilesOut) *tilesOut = produced / 64u;
    return 1;
}

// Its 32-pixel path.  Four consecutive source tiles make one, the second
// sitting to the right of the first and the last two beneath them.
int gfxUnpackSprites32(const unsigned char *buf, unsigned bufSize,
                       unsigned char *out, unsigned outCapacity,
                       unsigned *tilesOut) {
    if (bufSize < 0x8000u) return 0;
    if (outCapacity < CHR_TILES32_PER_FILE * 1024u) return 0;
    unsigned produced = 0;
    for (unsigned s = 0; s < CHR_TILES32_PER_FILE; s++) {
        const unsigned char *base = buf + s * 0x200u;
        unsigned char quad[4][256];
        for (unsigned q = 0; q < 4; q++) {
            const unsigned char *tile = base + q * TILE_SRC;
            for (unsigned i = 0; i < 256; i++) {
                const unsigned char v = planarPixel(tile, i >> 3, i & 7);
                quad[q][i] = v == 0x0f ? CHR_TRANSPARENT
                                       : (unsigned char)(v + 0x30);
            }
        }
        for (unsigned row = 0; row < 32; row++) {
            const unsigned band = row < 16 ? 0u : 2u;
            for (unsigned col = 0; col < 32; col++) {
                const unsigned which = band + (col < 16 ? 0u : 1u);
                out[produced++] = quad[which][(row & 15) * 16 + (col & 15)];
            }
        }
    }
    if (tilesOut) *tilesOut = CHR_TILES32_PER_FILE;
    return 1;
}
