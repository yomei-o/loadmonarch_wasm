#include "picture.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PICTURE_MAX (512u * 384u)       // END.256, the largest of them

static unsigned read32(const unsigned char *p) {
    return (unsigned)p[0] | ((unsigned)p[1] << 8) | ((unsigned)p[2] << 16) |
           ((unsigned)p[3] << 24);
}

void pictureFree(Picture *picture) {
    free(picture->pixels);
    picture->pixels = NULL;
    picture->width = 0;
    picture->height = 0;
}

int pictureLoad(Picture *picture, const Host *host, const char *stem) {
    memset(picture, 0, sizeof *picture);

    char path[64];
    static unsigned char palette[1024];
    unsigned got = 0;
    snprintf(path, sizeof path, "DATA/%s.PAL", stem);
    if (!hostRead(host, path, palette, sizeof palette, &got)) return 0;
    if (got < 1024) return 0;

    unsigned char *file = (unsigned char *)malloc(PICTURE_MAX + 8u);
    if (!file) return 0;
    snprintf(path, sizeof path, "DATA/%s.256", stem);
    if (!hostRead(host, path, file, PICTURE_MAX + 8u, &got) || got < 8) {
        free(file);
        return 0;
    }

    const unsigned width = read32(file);
    const unsigned height = read32(file + 4);
    if (width == 0 || height == 0 || (unsigned long long)width * height >
                                         (unsigned long long)(got - 8)) {
        free(file);
        return 0;
    }

    unsigned *pixels = (unsigned *)malloc((size_t)width * height * 4u);
    if (!pixels) {
        free(file);
        return 0;
    }
    for (unsigned i = 0; i < width * height; i++) {
        const unsigned char *entry = palette + (unsigned)file[8 + i] * 4u;
        // Red, green, blue, and a byte that is ignored - not the blue-first
        // order a Windows colour table uses, whatever the file extension
        // suggests.  Entry nine settles it: 166, 202, 240 is the pale blue of
        // the standard palette, and reading it the other way round turns every
        // picture peach.
        pixels[i] = 0xff000000u | (unsigned)entry[0] |
                    ((unsigned)entry[1] << 8) | ((unsigned)entry[2] << 16);
    }
    free(file);

    picture->width = width;
    picture->height = height;
    picture->pixels = pixels;
    return 1;
}
