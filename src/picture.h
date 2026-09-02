// The game's pictures: the title, the five interludes, and the ending.
//
// DATA/*.256 is as plain as a file gets - two little-endian words giving the
// width and the height, then one byte a pixel indexing DATA/*.PAL, which is
// 256 entries of red, green, blue and a byte that is ignored.
#ifndef PICTURE_H
#define PICTURE_H

#include "host.h"

typedef struct {
    unsigned width;
    unsigned height;
    unsigned *pixels;           // width * height, 0xAABBGGRR for a canvas
} Picture;

// `stem` is the name without an extension, e.g. "LOGO" or "GAKU2"; both the
// .256 and its .PAL are read from DATA/.  Non-zero on success, and the caller
// owns pixels until pictureFree.
int pictureLoad(Picture *picture, const Host *host, const char *stem);
void pictureFree(Picture *picture);

#endif
