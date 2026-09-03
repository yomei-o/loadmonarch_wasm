// The Graph Window's six formats, as rsrcGraphLines finds them in each
// release.
//
//   tools/graph_lines.exe ds7e.zip ds7j.zip
#include <stdio.h>
#include <stdlib.h>
#include "../src/host.h"
#include "../src/rsrc.h"

static void show(const char *archive) {
    FILE *f = fopen(archive, "rb");
    if (!f) { printf("%s: cannot open\n", archive); return; }
    fseek(f, 0, SEEK_END); long size = ftell(f); fseek(f, 0, SEEK_SET);
    unsigned char *zip = (unsigned char *)malloc((size_t)size);
    if (!zip || fread(zip, 1, (size_t)size, f) != (size_t)size) return;
    fclose(f);
    static Host host;
    if (!hostUseZip(&host, zip, (unsigned)size)) return;
    static unsigned char image[400 * 1024];
    unsigned got = 0;
    if (!hostRead(&host, "DS7E_WIN.EXE", image, sizeof image, &got) &&
        !hostRead(&host, "DS7J_WIN.EXE", image, sizeof image, &got)) return;
    static Pe pe;
    if (!peOpen(&pe, image, got)) return;
    const char *line[RSRC_GRAPH_LINES];
    const int n = rsrcGraphLines(&pe, line, RSRC_GRAPH_LINES);
    printf("%s: %d\n", archive, n);
    static const char *what[RSRC_GRAPH_LINES] = {
        "area", "funds", "leader", "units", "all", "defeated"
    };
    for (int i = 0; i < n; i++)
        printf("  %-9s %s\n", what[i], line[i]);
}

int main(int argc, char **argv) {
    if (argc > 1) for (int i = 1; i < argc; i++) show(argv[i]);
    else { show("ds7e.zip"); show("ds7j.zip"); }
    return 0;
}
