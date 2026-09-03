// The port's menu bar and dialogs against the executable's own resources.
//
//   tests/rsrc_test.exe [zip]
//
// Both were transcribed by hand from tools/dump_menus.py and
// tools/dump_dialogs.py, and the menu came out wrong - Leader Position under
// Orders instead of Controls, three captions invented, the separators in the
// wrong places - with nothing to notice.  This reads MENU 101 and every
// DIALOG out of DS7E_WIN.EXE inside the zip and compares them item for item.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/dlg.h"
#include "../src/host.h"
#include "../src/rsrc.h"
#include "../src/ui.h"

static int failures;

static void check(int ok, const char *what) {
    if (!ok) {
        printf("FAIL  %s\n", what);
        failures++;
    }
}

int main(int argc, char **argv) {
    const char *archive = argc > 1 ? argv[1] : "ds7e.zip";
    FILE *f = fopen(archive, "rb");
    if (!f) { printf("FAIL  cannot open %s\n", archive); return 1; }
    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);
    unsigned char *zip = (unsigned char *)malloc((size_t)size);
    if (!zip || fread(zip, 1, (size_t)size, f) != (size_t)size) return 1;
    fclose(f);

    // The executable out of the zip, through the port's own reader.
    static Host host;
    if (!hostUseZip(&host, zip, (unsigned)size)) {
        printf("FAIL  %s is not a zip this port can read\n", archive);
        return 1;
    }
    static unsigned char image[400 * 1024];
    unsigned got = 0;
    if (!hostRead(&host, "DS7E_WIN.EXE", image, sizeof image, &got)) {
        printf("FAIL  no DS7E_WIN.EXE in %s\n", archive);
        return 1;
    }
    printf("  DS7E_WIN.EXE: %u bytes\n", got);

    static Pe pe;
    check(peOpen(&pe, image, got), "it is a PE32");
    printf("  ImageBase %08x, %u sections\n", pe.base, pe.sections);

    /* -------------------------------------------------------- MENU 101 */
    static RsrcMenuBar bar;
    check(rsrcMenuBar(&pe, 101, &bar), "MENU 101 reads");
    printf("  MENU 101: %d drop-downs\n", bar.menus);
    check(bar.menus == UI_MENU_MAX, "the bar has as many drop-downs as the "
                                    "port draws");
    for (int m = 0; m < bar.menus && m < UI_MENU_MAX; m++) {
        const RsrcMenu *menu = &bar.menu[m];
        const char *name = uiBarMenuName(m);
        if (strcmp(name, menu->text) != 0) {
            printf("FAIL  drop-down %d is \"%s\", not \"%s\"\n", m, name,
                   menu->text);
            failures++;
        }
        if (uiBarMenuItems(m) != menu->items) {
            printf("FAIL  \"%s\" has %d items, the resource %d\n", menu->text,
                   uiBarMenuItems(m), menu->items);
            failures++;
            continue;
        }
        for (int i = 0; i < menu->items; i++) {
            const RsrcMenuItem *want = &menu->item[i];
            const char *text = uiBarItemText(m, i);
            const unsigned command = uiBarItemCommand(m, i);
            // 40080 to 40083 carry a country's name at run time, so the port
            // leaves their captions empty; the resource has placeholders.
            const int named = command < 40080 || command > 40083;
            if (want->separator) {
                if (text) {
                    printf("FAIL  \"%s\" item %d should be a separator\n",
                           menu->text, i);
                    failures++;
                }
                continue;
            }
            if (!text) {
                printf("FAIL  \"%s\" item %d is a separator, wanted \"%s\"\n",
                       menu->text, i, want->text);
                failures++;
                continue;
            }
            if (command != want->command) {
                printf("FAIL  \"%s\" / \"%s\" is command %u, not %u\n",
                       menu->text, want->text, command, want->command);
                failures++;
            }
            if (named && strcmp(text, want->text) != 0) {
                printf("FAIL  \"%s\" item %d reads \"%s\", not \"%s\"\n",
                       menu->text, i, text, want->text);
                failures++;
            }
        }
        printf("  %-8s %2d items, all as the resource has them\n", menu->text,
               menu->items);
    }

    /* -------------------------------------------------------- the dialogs */
    // Every dialog the port lays out, against its own resource.  The port
    // spells the ids out here because a DlgTemplate does not carry one.
    static const struct { unsigned id; const DlgTemplate *tpl; } kDialogs[] = {
        {104, &kDlgLoadQuestMap},
        {106, &kDlgSave},
        {107, &kDlgLoad},
        {112, &kDlgCustomSounds},
        {115, &kDlgSystemSetting},
        {118, &kDlgInformation},
        {119, &kDlgAlliance},
        {120, &kDlgVersion},
        {123, &kDlgHelp},
        {124, &kDlgDefaultOrders},
        {126, &kDlgSoundSetting},
        {127, &kDlgLoadSingleMap},
    };
    for (unsigned d = 0; d < sizeof kDialogs / sizeof kDialogs[0]; d++) {
        static RsrcDialog want;
        const DlgTemplate *tpl = kDialogs[d].tpl;
        if (!rsrcDialog(&pe, kDialogs[d].id, &want)) {
            printf("FAIL  DIALOG %u will not read\n", kDialogs[d].id);
            failures++;
            continue;
        }
        if (want.w != tpl->w || want.h != tpl->h) {
            printf("FAIL  DIALOG %u is %dx%d, the port has %dx%d\n",
                   kDialogs[d].id, want.w, want.h, tpl->w, tpl->h);
            failures++;
        }
        if (strcmp(want.caption, tpl->caption) != 0) {
            printf("FAIL  DIALOG %u is titled \"%s\", the port \"%s\"\n",
                   kDialogs[d].id, want.caption, tpl->caption);
            failures++;
        }
        int n = 0;
        for (const DlgControl *c = tpl->control; c->kind != DC_END; c++) n++;
        if (n != want.controls) {
            printf("FAIL  DIALOG %u has %d controls, the port %d\n",
                   kDialogs[d].id, want.controls, n);
            failures++;
            continue;
        }
        // Every control of the resource has to be somewhere in the port's
        // list, with the same id and the same rectangle - but not
        // necessarily in the same place in the list: dlgdefs.c has them in
        // the order they are drawn, which is a port decision.  The kind is
        // not compared either, because the port has one kind per widget
        // where a resource has a class and a style.
        int wrong = 0;
        int taken[RSRC_CONTROLS_MAX];
        memset(taken, 0, sizeof taken);
        for (int i = 0; i < want.controls; i++) {
            const RsrcControl *r = &want.control[i];
            const unsigned id = r->id == 0xffffffffu ? 65535u : r->id;
            int found = -1;
            for (int j = 0; j < n && found < 0; j++) {
                const DlgControl *c = &tpl->control[j];
                if (taken[j]) continue;
                if ((unsigned)c->id == id && c->x == r->x && c->y == r->y &&
                    c->w == r->w && c->h == r->h) found = j;
            }
            if (found >= 0) {
                taken[found] = 1;
                // And the caption, where the port has one of its own rather
                // than a placeholder for text it fills in at run time.  This
                // is where a caption somebody made up shows itself.
                const char *mine = tpl->control[found].text;
                // An empty caption in the resource is one the program
                // fills in at run time - dialog 120's version line - so the
                // port having words there is right, not wrong.
                if (mine && mine[0] && r->text[0] &&
                    strcmp(mine, "??") != 0 &&
                    strcmp(mine, "?2") != 0 && strcmp(mine, "?3") != 0 &&
                    strcmp(mine, "?4") != 0 && strcmp(mine, "---") != 0 &&
                    strcmp(mine, r->text) != 0) {
                    if (wrong < 4)
                        printf("FAIL  DIALOG %u control %u reads \"%s\", the "
                               "resource \"%s\"\n", kDialogs[d].id, id, mine,
                               r->text);
                    wrong++;
                }
                continue;
            }
            if (wrong < 4)
                printf("FAIL  DIALOG %u: nothing in the port matches %u at "
                       "%d,%d %dx%d \"%s\"\n", kDialogs[d].id, id, r->x,
                       r->y, r->w, r->h, r->text);
            wrong++;
        }
        if (wrong) failures += wrong;
        printf("  DIALOG %3u %-26s %2d controls%s\n", kDialogs[d].id,
               want.caption, want.controls, wrong ? "  (see above)" : "");
    }

    if (failures) {
        printf("%d failure(s)\n", failures);
        return 1;
    }
    printf("resource checks ok\n");
    return 0;
}
