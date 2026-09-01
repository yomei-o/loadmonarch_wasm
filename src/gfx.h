// Planar .BZ payload to 8-bit pixels.  See gfx.c.
#ifndef GFX_H
#define GFX_H

// Unpacks the 128 tiles in a decompressed .BZ buffer.  tileSize is 8, 16 or
// 32; out receives tiles*tileSize*tileSize bytes of palette indices.
// Returns non-zero on success.
int gfxUnpackTiles(const unsigned char *buf, unsigned bufSize, int tileSize,
                   unsigned char *out, unsigned outCapacity,
                   unsigned *tilesOut);

// The same, for the sprite banks: 00406c70 biases by 0x30 rather than 0x10 and
// turns a full nibble into 0x70, the index it draws as transparent.  Only the
// 16-pixel size is handled - the 8- and 32-pixel sprite banks are rearranged
// as well, which is not ported.
#define CHR_TRANSPARENT 0x70
// 208, not the terrain banks' 128: 00406c70's pass runs to 0x6800 of the
// payload, which at 0x80 bytes a tile is 208 of them - and it has to be,
// because the sprite numbers 1833 works out reach 187.
#define CHR_TILES 208
int gfxUnpackSprites(const unsigned char *buf, unsigned bufSize,
                     unsigned char *out, unsigned outCapacity,
                     unsigned *tilesOut);

// The sixteen colours a tile bank carries in its own tail, written into
// rgb[0x10*3 .. 0x20*3) so they line up with the 0x10 bias gfxUnpackTiles
// applies.  Returns non-zero when the buffer is long enough to hold them.
int gfxTilePalette(const unsigned char *buf, unsigned bufSize,
                   unsigned char *rgb256);

// The same colours, placed where the sprite banks' pixels look for them:
// 004065e0 is called with 0x30 for those, not 0x10.
int gfxSpritePalette(const unsigned char *buf, unsigned bufSize,
                     unsigned char *rgb256);

// The interface palette: the first 48 four-byte entries of data1.rgb, placed
// at index 0x80 where the data1.bz sheet's biased indices land.
void gfxUiPalette(const unsigned char *rgbFile, unsigned size,
                  unsigned char *rgb256);

#endif
