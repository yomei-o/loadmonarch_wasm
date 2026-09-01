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
