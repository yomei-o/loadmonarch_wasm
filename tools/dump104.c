#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../src/host.h"
#include "../src/rsrc.h"
int main(int argc, char **argv) {
    const char *archive = argc > 1 ? argv[1] : "ds7j.zip";
    unsigned id = argc > 2 ? (unsigned)atoi(argv[2]) : 104;
    FILE *f = fopen(archive, "rb");
    if (!f) return 1;
    fseek(f, 0, SEEK_END); long size = ftell(f); fseek(f, 0, SEEK_SET);
    unsigned char *zip = (unsigned char *)malloc((size_t)size);
    if (fread(zip, 1, (size_t)size, f) != (size_t)size) return 1;
    fclose(f);
    static Host host;
    if (!hostUseZip(&host, zip, (unsigned)size)) return 1;
    static unsigned char image[400 * 1024];
    unsigned got = 0;
    if (!hostRead(&host, "DS7E_WIN.EXE", image, sizeof image, &got) &&
        !hostRead(&host, "DS7J_WIN.EXE", image, sizeof image, &got)) return 1;
    static Pe pe;
    if (!peOpen(&pe, image, got)) return 1;
    static RsrcDialog d;
    if (!rsrcDialog(&pe, id, &d)) return 1;
    printf("dialog %u  %d x %d  \"%s\"  %d controls\n", id, d.w, d.h,
           d.caption, d.controls);
    for (int i = 0; i < d.controls; i++)
        printf("  %4u %-10s %4d,%4d %3dx%3d style %08x  \"%s\"\n",
               d.control[i].id, d.control[i].cls, d.control[i].x,
               d.control[i].y, d.control[i].w, d.control[i].h,
               d.control[i].style, d.control[i].text);
    return 0;
}
