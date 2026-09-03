#include "notice.h"

#include "ui.h"

#include <stdio.h>
#include <string.h>

void noticeOpen(Notice *notice, int kind, unsigned faction, const char *name) {
    memset(notice, 0, sizeof *notice);
    notice->up = 1;
    notice->kind = kind;
    notice->faction = faction;
    if (name) snprintf(notice->name, sizeof notice->name, "%s", name);
}

int noticeStep(Notice *notice) {
    if (!notice->up) return 0;
    notice->tick++;
    // 00411d59: `cmp eax, 0x1e / jle` - past thirty it calls its own close.
    if (notice->tick > NOTICE_LIFE) {
        notice->up = 0;
        return 1;
    }
    return 0;
}

int noticeDismiss(Notice *notice) {
    if (!notice->up) return 0;
    notice->up = 0;
    return 1;
}

void noticeDraw(Surface *out, const Notice *notice, const World *world,
                int x, int y) {
    if (!notice->up) return;

    // 00411cb4's loop: 64 rows of 256 out of the sheet at 0x3c000, which is
    // row 960.  Opaque, like every window.
    const UiSheet *ui = &world->ui;
    for (int j = 0; j < NOTICE_H; j++) {
        const int py = y + j;
        if (py < 0 || py >= out->height) continue;
        unsigned char *row = out->pixels + (size_t)py * out->width;
        for (int i = 0; i < NOTICE_W; i++) {
            const int px = x + i;
            if (px < 0 || px >= out->width) continue;
            row[px] = ui->pixels
                ? ui->pixels[(size_t)(NOTICE_SHEET_TOP + j) * UI_SHEET_W + i]
                : (unsigned char)UI_DARK;
        }
    }

    // White on black, centred, at y 0x18 - both notices put their words in
    // the same place.
    char line[64];
    if (notice->kind == NOTICE_BREAK_ALLIANCE) {
        uiTextOutMid(out, x, NOTICE_W, y + 0x18, 0, 1, "Break alliance");
        return;
    }
    if (notice->tick < NOTICE_WORDS_AT) return;
    snprintf(line, sizeof line, "%s has Fallen", notice->name);
    uiTextOutMid(out, x, NOTICE_W, y + 0x18, 0, 1, line);
}
