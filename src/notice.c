#include "notice.h"

#include "render.h"
#include "ui.h"

#include <stdio.h>
#include <string.h>

void noticeOpen(Notice *notice, int kind, unsigned faction, unsigned ally,
                const char *name) {
    memset(notice, 0, sizeof *notice);
    notice->up = 1;
    notice->kind = kind;
    notice->faction = faction;
    notice->ally = ally;
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

    // The kings, and then the words.  Both notices put their first sprite at
    // 16,16 - the destination 004243c0 is handed is the bitmap plus 0x1010,
    // which on a 256-wide window is row sixteen, column sixteen - and the
    // second of 00411eb0's pair at 208,16.
    const TileBank *bank = worldSprites(world, 2);
    const unsigned side = notice->faction < 4 ? notice->faction : 0;
    char line[64];

    if (notice->kind == NOTICE_BREAK_ALLIANCE) {
        const unsigned ally = notice->ally < 4 ? notice->ally : 0;
        renderSprite(out, bank, 0x60u | (side << 3) | 4u, x + 16, y + 16, 0);
        renderSprite(out, bank, 0x60u | (ally << 3), x + 208, y + 16, 0);
        uiTextOutMid(out, x, NOTICE_W, y + 0x18, 0, 1, "Break alliance");
        return;
    }

    // 00411d70: the king at tick nought - 0x60 | side << 3 | facing 6 - and
    // then four frames of him fighting, 0xa4 | side << 3 | phase.  The words
    // come only once that is over.
    // The original draws these into the window's own bitmap, so the last
    // frame is still there when the words arrive; this port paints the
    // window from scratch every time, so it holds the fourth frame.
    if (notice->tick == 0) {
        renderSprite(out, bank, 0x60u | (side << 3) | 6u, x + 16, y + 16, 1);
    } else {
        const unsigned phase =
            (unsigned)(notice->tick < 4 ? notice->tick : 4) - 1u;
        renderSprite(out, bank, 0xa4u | (side << 3) | phase,
                     x + 16, y + 16, 1);
    }
    if (notice->tick < NOTICE_WORDS_AT) return;
    snprintf(line, sizeof line, "%s has Fallen", notice->name);
    uiTextOutMid(out, x, NOTICE_W, y + 0x18, 0, 1, line);
}
