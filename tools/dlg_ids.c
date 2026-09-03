// Which control ids each release's dialogs really have, so the numbers and
// lists src/dlgrun.c writes into them can be checked against both.
//
//   tools/dlg_ids.exe [ds7e.zip] [ds7j.zip]
//
// dlgRunDraw puts every one of them at the rectangle `dlgControlRect(id)`
// gives it, so as long as an id is in both releases with the same rectangle
// the Japanese release needs nothing of its own.  This says which are not.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/host.h"
#include "../src/rsrc.h"

typedef struct { unsigned dialog; int id; const char *what; } Slot;

static const Slot kSlots[] = {
    {104, 1039, "the map's name"},
    {104, 1051, "Maps"},
    {104, 1181, "held"}, {104, 1180, "left"}, {104, 1182, "per cent"},
    {104, 1186, "penalty"},
    {104, 1183, "your losses"}, {104, 1184, "theirs"},
    {104, 1185, "battle per cent"}, {104, 1187, "bonus"},
    {104, 1115, "remaining"}, {104, 1118, "days"},
    {112, 1131, "the tune's file"},
    {118, 1067, "the sentence"},
    {119, 1076, "your country"},
    {119, 1079, "country 1"}, {119, 1080, "colour 1"},
    {119, 1085, "country 2"}, {119, 1086, "colour 2"},
    {119, 1088, "country 3"}, {119, 1089, "colour 3"},
    {119, 1083, "the one picked"},
    {123, 1122, "the page combo"}, {123, 1123, "the page"},
};

static int loadPe(const char *archive, Pe *pe, unsigned char *image,
                  unsigned room) {
    FILE *f = fopen(archive, "rb");
    if (!f) { printf("%s: cannot open\n", archive); return 0; }
    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);
    unsigned char *zip = (unsigned char *)malloc((size_t)size);
    if (!zip || fread(zip, 1, (size_t)size, f) != (size_t)size) return 0;
    fclose(f);
    static Host host[2];
    static int used;
    Host *h = &host[used++ & 1];
    if (!hostUseZip(h, zip, (unsigned)size)) {
        printf("%s: not a zip this port can read\n", archive);
        return 0;
    }
    unsigned got = 0;
    if (!hostRead(h, "DS7E_WIN.EXE", image, room, &got) &&
        !hostRead(h, "DS7J_WIN.EXE", image, room, &got)) {
        printf("%s: no executable\n", archive);
        return 0;
    }
    return peOpen(pe, image, got);
}

int main(int argc, char **argv) {
    const char *zips[2] = {
        argc > 1 ? argv[1] : "ds7e.zip",
        argc > 2 ? argv[2] : "ds7j.zip",
    };
    static unsigned char image[2][400 * 1024];
    static Pe pe[2];
    for (int k = 0; k < 2; k++)
        if (!loadPe(zips[k], &pe[k], image[k], sizeof image[k])) return 1;

    unsigned last = 0;
    int missing = 0, differs = 0;
    static RsrcDialog d[2];
    for (unsigned i = 0; i < sizeof kSlots / sizeof kSlots[0]; i++) {
        const Slot *s = &kSlots[i];
        if (s->dialog != last) {
            last = s->dialog;
            printf("\ndialog %u\n", last);
            for (int k = 0; k < 2; k++) {
                if (!rsrcDialog(&pe[k], last, &d[k])) {
                    printf("  %-10s not there\n", zips[k]);
                    memset(&d[k], 0, sizeof d[k]);
                    continue;
                }
                printf("  %-10s %4d,%4d %3d x %3d, %d controls  \"%s\"\n",
                       zips[k], d[k].x, d[k].y, d[k].w, d[k].h,
                       d[k].controls, d[k].caption);
            }
        }
        const RsrcControl *c[2] = {NULL, NULL};
        for (int k = 0; k < 2; k++)
            for (int j = 0; j < d[k].controls; j++)
                if ((int)d[k].control[j].id == s->id) {
                    c[k] = &d[k].control[j];
                    break;
                }
        char where[2][32];
        for (int k = 0; k < 2; k++) {
            if (!c[k]) snprintf(where[k], sizeof where[k], "%-21s", "-");
            else snprintf(where[k], sizeof where[k], "%4d,%4d %3dx%3d",
                          c[k]->x, c[k]->y, c[k]->w, c[k]->h);
        }
        int same = c[0] && c[1] && c[0]->x == c[1]->x && c[0]->y == c[1]->y &&
                   c[0]->w == c[1]->w && c[0]->h == c[1]->h;
        if (!c[0] || !c[1]) missing++;
        else if (!same) differs++;
        printf("    %4d %-18s %s | %s %s\n", s->id, s->what,
               where[0], where[1], same ? "" : "<-");
    }
    printf("\n%d of the ids are not in both, %d are in a different place\n",
           missing, differs);
    return 0;
}
