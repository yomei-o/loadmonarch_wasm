// The sixteen order names the game's own data file carries, and which of them
// the Help dialog has a description for.
//
//   tools/order_names.exe [zip]
//
// 00413f90 fills the Help combo with six topics and then twelve names out of
// the runtime table at 0x435b86, seventeen bytes apart, stopping at 0x435c52
// - which is twelve exactly.  .data holds eighteen pages and no more, so the
// last four orders have no description at all.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/host.h"
#include "../src/world.h"

int main(int argc, char **argv) {
    const char *archive = argc > 1 ? argv[1] : "ds7e.zip";
    FILE *f = fopen(archive, "rb");
    if (!f) { printf("cannot open %s\n", archive); return 1; }
    fseek(f, 0, SEEK_END); long size = ftell(f); fseek(f, 0, SEEK_SET);
    unsigned char *zip = (unsigned char *)malloc((size_t)size);
    if (!zip || fread(zip, 1, (size_t)size, f) != (size_t)size) return 1;
    fclose(f);
    static Host host;
    if (!hostUseZip(&host, zip, (unsigned)size)) {
        printf("%s is not a zip this port can read\n", archive);
        return 1;
    }
    static World world;
    char message[128];
    if (!worldLoadStage(&world, &host, "B_000.MAP", message, sizeof message)) {
        printf("B_000.MAP: %s\n", message);
        return 1;
    }
    for (unsigned i = 0; i < 16; i++)
        printf("  order %2u  %-16s %s\n", i, worldOrderName(&world, i),
               i < 12 ? "has a page" : "-- no page in .data");
    return 0;
}
