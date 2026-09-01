// Planar .BZ payload to 8-bit pixels.  See gfx.c.
#ifndef GFX_H
#define GFX_H

// Unpacks the 128 tiles in a decompressed .BZ buffer.  tileSize is 8, 16 or
// 32; out receives tiles*tileSize*tileSize bytes of palette indices.
// Returns non-zero on success.
int gfxUnpackTiles(const unsigned char *buf, unsigned bufSize, int tileSize,
                   unsigned char *out, unsigned outCapacity,
                   unsigned *tilesOut);

#endif
