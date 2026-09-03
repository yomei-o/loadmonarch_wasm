#include <stdio.h>
#include <stdlib.h>
#include "../src/host.h"
#include "../src/rsrc.h"
int main(int argc, char **argv) {
    const char *a = argc > 1 ? argv[1] : "ds7e.zip";
    FILE *f = fopen(a, "rb");
    fseek(f, 0, SEEK_END); long size = ftell(f); fseek(f, 0, SEEK_SET);
    unsigned char *zip = (unsigned char *)malloc((size_t)size);
    if (fread(zip, 1, (size_t)size, f) != (size_t)size) return 1;
    fclose(f);
    static Host host; hostUseZip(&host, zip, (unsigned)size);
    static unsigned char image[400*1024]; unsigned got = 0;
    if (!hostRead(&host, "DS7E_WIN.EXE", image, sizeof image, &got))
        hostRead(&host, "DS7J_WIN.EXE", image, sizeof image, &got);
    static Pe pe; peOpen(&pe, image, got);
    static RsrcDialog d;
    for (unsigned id = 1; id < 400; id++)
        if (rsrcDialog(&pe, id, &d))
            printf("%3u  %3d x %3d  %2d controls  \"%s\"\n", id, d.w, d.h,
                   d.controls, d.caption);
    return 0;
}
