// Reading the game out of its own zip.  See zip.c.
#ifndef ZIP_H
#define ZIP_H

typedef struct {
    const unsigned char *data;
    unsigned size;
    unsigned directory;         // where the central directory starts
    unsigned entryCount;
} Zip;

// Points the reader at a zip already in memory.  Non-zero on success.
int zipOpen(Zip *zip, const unsigned char *data, unsigned size);

// Reads the entry whose name ends with `name` - so "MAP/B_000.MAP" finds
// "DS7E_WIN/MAP/B_000.MAP".  Case and slash direction do not matter.
int zipRead(const Zip *zip, const char *name, unsigned char *out,
            unsigned capacity, unsigned *sizeOut);

#endif
