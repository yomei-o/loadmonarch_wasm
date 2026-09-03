// Why dialog 104's "Maps" slot keeps a row of the label that overflows into
// it in the Japanese release.  Prints what the port thinks the rectangles are
// and which rows are painted in the slot's own columns.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/dlg.h"
#include "../src/dlgload.h"
#include "../src/host.h"
#include "../src/render.h"
#include "../src/ui.h"

int main(int argc, char **argv) {
    const char *archive = argc > 1 ? argv[1] : "ds7j.zip";
    FILE *f = fopen(archive, "rb");
    if (!f) return 1;
    fseek(f, 0, SEEK_END); long size = ftell(f); fseek(f, 0, SEEK_SET);
    unsigned char *zip = (unsigned char *)malloc((size_t)size);
    if (fread(zip, 1, (size_t)size, f) != (size_t)size) return 1;
    fclose(f);
    static Host host;
    if (!hostUseZip(&host, zip, (unsigned)size)) return 1;
    printf("loaded %d dialogs\n", dlgLoadFromHost(&host));

    static Dialog d;
    const DlgTemplate *t = dlgLoaded(DLG_LOAD_QUEST_MAP);
    if (!t) { printf("no template\n"); return 1; }
    dlgOpen(&d, t, 0, 0);
    static Surface s;
    static unsigned char px[400 * 400];
    surfaceInit(&s, 400, 400, px);
    memset(px, (unsigned char)UI_FACE, sizeof px);
    dlgDraw(&s, &d);

    int x, y, w, h;
    if (dlgControlRect(&d, 1050, &x, &y, &w, &h))
        printf("1050 (the label) %d,%d %dx%d\n", x, y, w, h);
    if (!dlgControlRect(&d, 1051, &x, &y, &w, &h)) return 1;
    printf("1051 (the slot)  %d,%d %dx%d\n", x, y, w, h);

    for (int j = -2; j < 20; j++) {
        printf("  y%+3d (%3d) ", j, y + j);
        for (int i = 0; i < w; i++) {
            const unsigned char v =
                px[(size_t)(y + j) * s.width + x + i];
            putchar(v == (unsigned char)UI_FACE ? '.' : '#');
        }
        putchar('\n');
    }
    return 0;
}
