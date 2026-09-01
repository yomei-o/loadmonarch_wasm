// Where the game's files come from.
//
// Two places, one interface: a directory on disk for the native build and the
// harness, or the player's own zip held in memory for the browser.  Nothing
// above this knows which.
#ifndef HOST_H
#define HOST_H

#include "zip.h"

typedef enum {
    HOST_NONE = 0,
    HOST_DIRECTORY,
    HOST_ZIP,
} HostKind;

typedef struct {
    HostKind kind;
    char directory[512];        // HOST_DIRECTORY
    Zip zip;                    // HOST_ZIP
} Host;

// Points the host at a directory holding BG/, CHR/, DATA/ and MAP/.
int hostUseDirectory(Host *host, const char *directory);

// Points it at a zip already in memory - the player's own archive.  The
// bytes must outlive the host.
int hostUseZip(Host *host, const unsigned char *data, unsigned size);

// Reads one of the game's files by its path within the installation, e.g.
// "MAP/B_000.MAP".  Non-zero on success.
int hostRead(const Host *host, const char *path, unsigned char *out,
             unsigned capacity, unsigned *sizeOut);

#endif
