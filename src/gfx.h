// Planar .BZ payload to 8-bit pixels.  See gfx.c.
#ifndef GFX_H
#define GFX_H

// Unpacks the 128 tiles in a decompressed .BZ buffer.  tileSize is 8, 16 or
// 32; out receives tiles*tileSize*tileSize bytes of palette indices.
// Returns non-zero on success.
int gfxUnpackTiles(const unsigned char *buf, unsigned bufSize, int tileSize,
                   unsigned char *out, unsigned outCapacity,
                   unsigned *tilesOut);

// The sixteen colours a tile bank carries in its own tail, written into
// rgb[0x10*3 .. 0x20*3) so they line up with the 0x10 bias gfxUnpackTiles
// applies.  Returns non-zero when the buffer is long enough to hold them.
int gfxTilePalette(const unsigned char *buf, unsigned bufSize,
                   unsigned char *rgb256);

// The interface palette: the first 48 four-byte entries of data1.rgb, placed
// at index 0x80 where the data1.bz sheet's biased indices land.
void gfxUiPalette(const unsigned char *rgbFile, unsigned size,
                  unsigned char *rgb256);

#endif
