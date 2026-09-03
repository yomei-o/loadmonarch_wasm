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
    static RsrcMenuBar bar;
    if (!rsrcMenuBar(&pe, 101, &bar)) { printf("no menu\n"); return 1; }
    for (int m = 0; m < bar.menus; m++) {
        printf("== %s\n", bar.menu[m].text);
        for (int i = 0; i < bar.menu[m].items; i++)
            printf("   %5u %s%s\n", bar.menu[m].item[i].command,
                   bar.menu[m].item[i].separator ? "----" : bar.menu[m].item[i].text,
                   bar.menu[m].item[i].popup ? "  >" : "");
    }
    return 0;
}
