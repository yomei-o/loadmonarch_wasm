#include "host.h"

#include <stdio.h>
#include <string.h>

int hostUseDirectory(Host *host, const char *directory) {
    memset(host, 0, sizeof *host);
    if (!directory || !*directory) return 0;
    host->kind = HOST_DIRECTORY;
    snprintf(host->directory, sizeof host->directory, "%s", directory);
    return 1;
}

int hostUseZip(Host *host, const unsigned char *data, unsigned size) {
    memset(host, 0, sizeof *host);
    if (!zipOpen(&host->zip, data, size)) return 0;
    host->kind = HOST_ZIP;
    return 1;
}

int hostRead(const Host *host, const char *path, unsigned char *out,
             unsigned capacity, unsigned *sizeOut) {
    if (!host || !path) return 0;
    if (host->kind == HOST_ZIP) return zipRead(&host->zip, path, out, capacity,
                                               sizeOut);
    if (host->kind != HOST_DIRECTORY) return 0;

    char full[1024];
    snprintf(full, sizeof full, "%s/%s", host->directory, path);
    FILE *f = fopen(full, "rb");
    if (!f) return 0;
    const size_t got = fread(out, 1, capacity, f);
    const int overflowed = !feof(f);
    fclose(f);
    if (overflowed) return 0;       // the caller's buffer was too small
    *sizeOut = (unsigned)got;
    return 1;
}
