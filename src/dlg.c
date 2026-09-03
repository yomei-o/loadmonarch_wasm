#include "dlg.h"

#include "font.h"
#include "ui.h"

#include <string.h>

/* ----------------------------------------------------------- the drawing */

static void fillRect(Surface *out, int x, int y, int w, int h,
                     unsigned char c) {
    for (int j = 0; j < h; j++) {
        const int py = y + j;
        if (py < 0 || py >= out->height) continue;
        unsigned char *row = out->pixels + (size_t)py * out->width;
        for (int i = 0; i < w; i++) {
            const int px = x + i;
            if (px < 0 || px >= out->width) continue;
            row[px] = c;
        }
    }
}

// Raised: white along the top and left, grey then black along the other two.
static void bevelUp(Surface *out, int x, int y, int w, int h) {
    fillRect(out, x, y, w, 1, (unsigned char)UI_LIGHT);
    fillRect(out, x, y, 1, h, (unsigned char)UI_LIGHT);
    fillRect(out, x + 1, y + h - 2, w - 2, 1, (unsigned char)UI_SHADOW);
    fillRect(out, x + w - 2, y + 1, 1, h - 2, (unsigned char)UI_SHADOW);
    fillRect(out, x, y + h - 1, w, 1, (unsigned char)UI_DARK);
    fillRect(out, x + w - 1, y, 1, h, (unsigned char)UI_DARK);
}

// Sunken: the same two the other way about, which is what an edit field, a
// list box and a frame all wear.
static void bevelDown(Surface *out, int x, int y, int w, int h) {
    fillRect(out, x, y, w, 1, (unsigned char)UI_SHADOW);
    fillRect(out, x, y, 1, h, (unsigned char)UI_SHADOW);
    fillRect(out, x + 1, y + 1, w - 2, 1, (unsigned char)UI_DARK);
    fillRect(out, x + 1, y + 1, 1, h - 2, (unsigned char)UI_DARK);
    fillRect(out, x, y + h - 1, w, 1, (unsigned char)UI_LIGHT);
    fillRect(out, x + w - 1, y, 1, h, (unsigned char)UI_LIGHT);
}

static void caption(Surface *out, int x, int y, int w, int h,
                    const char *text, unsigned char ink, int centred) {
    if (!text || !*text) return;
    const int tw = fontTextWidth(text);
    const int tx = centred ? x + (w - tw) / 2 : x;
    const int ty = y + (h - 16) / 2;
    fontDrawText(out, tx, ty < y ? y : ty, ink, text);
}

// A static that carries more than one line of it.  Windows wraps a static's
// text inside its rectangle and breaks on the newlines the resource has;
// drawing only the first line lost the second half of what dialog 119 says
// about alliances, and the whole of the rules dialog 123 shows.
static int isLeadByte(unsigned char c) {
    return (c >= 0x81 && c <= 0x9f) || (c >= 0xe0 && c <= 0xfc);
}

static void captionWrapped(Surface *out, int x, int y, int w, int h,
                           const char *text, unsigned char ink, int centred) {
    if (!text || !*text) return;
    const int line = 16;
    int at = y;
    const char *p = text;
    while (*p && at + line <= y + h + line) {
        // As many words as fit, stopping at a newline - and where there is no
        // space to break at, as many characters as fit.  Japanese is written
        // without spaces, so breaking only on those ran the Japanese
        // release's alliance dialog off the side of its own window.
        const char *stop = NULL;
        const char *q = p;
        char buffer[192];
        int taken = 0;
        while (*q && *q != '\n') {
            const int step = isLeadByte((unsigned char)*q) && q[1] ? 2 : 1;
            if (taken + step >= (int)sizeof buffer) break;
            memcpy(buffer + taken, q, (size_t)step);
            buffer[taken + step] = 0;
            if (fontTextWidth(buffer) > w && taken > 0) break;
            taken += step;
            q += step;
            // A space is where a line would rather break.
            if (q[-1] == ' ') stop = q;
        }
        // If a word boundary was passed and the line filled up mid-word, go
        // back to it; otherwise the break is where the width ran out.
        if (*q && *q != '\n' && stop) q = stop;
        size_t take = (size_t)(q - p);
        if (take >= sizeof buffer) take = sizeof buffer - 1;
        memcpy(buffer, p, take);
        buffer[take] = 0;
        const int tw = fontTextWidth(buffer);
        fontDrawText(out, centred ? x + (w - tw) / 2 : x, at, ink, buffer);
        at += line;
        p = q;
        while (*p == ' ') p++;
        if (*p == '\n') p++;
    }
}

/* ------------------------------------------------------------- the state */

static DlgState *stateOf(Dialog *d, int id) {
    for (int i = 0; i < d->states; i++)
        if (d->state[i].id == id) return &d->state[i];
    return NULL;
}

static const DlgState *stateOfConst(const Dialog *d, int id) {
    for (int i = 0; i < d->states; i++)
        if (d->state[i].id == id) return &d->state[i];
    return NULL;
}

int dlgValue(const Dialog *d, int id) {
    const DlgState *s = stateOfConst(d, id);
    return s ? s->value : 0;
}

void dlgSetValue(Dialog *d, int id, int value) {
    DlgState *s = stateOf(d, id);
    if (s) s->value = value;
}

int dlgEnabled(const Dialog *d, int id) {
    const DlgState *st = stateOfConst(d, id);
    return st ? st->enabled : 1;
}

void dlgWrapInto(Surface *out, const char *text, int x, int y, int w,
                 int h) {
    captionWrapped(out, x, y, w, h, text, (unsigned char)UI_DARK, 0);
}

void dlgSetText(Dialog *d, int id, const char *text) {
    DlgState *st = stateOf(d, id);
    if (!st) return;
    if (!text) { st->hasText = 0; st->text[0] = 0; return; }
    int i = 0;
    for (; text[i] && i < DLG_ITEM_TEXT - 1; i++) st->text[i] = text[i];
    st->text[i] = 0;
    st->hasText = 1;
}

void dlgEnable(Dialog *d, int id, int enabled) {
    DlgState *s = stateOf(d, id);
    if (s) s->enabled = enabled;
}

static void addTo(Dialog *d, int bank, const char *text) {
    if (bank < 0 || bank >= DLG_BANKS) return;
    if (d->items[bank] >= DLG_ITEMS_MAX) return;
    strncpy(d->item[bank][d->items[bank]], text ? text : "",
            DLG_ITEM_TEXT - 1);
    d->item[bank][d->items[bank]][DLG_ITEM_TEXT - 1] = 0;
    d->items[bank]++;
}

void dlgClearItems(Dialog *d) {
    d->items[0] = 0;
    d->listTop = 0;
    d->listSel = -1;
}

void dlgAddItem(Dialog *d, const char *text) { addTo(d, 0, text); }

void dlgClearItems2(Dialog *d) { d->items[1] = 0; }

void dlgAddItem2(Dialog *d, const char *text) { addTo(d, 1, text); }

// Which bank a list or combo draws from: the order it appears in.
static int bankOf(const Dialog *d, int id) {
    int n = 0;
    for (int i = 0; d->tpl->control[i].kind != DC_END; i++) {
        const DlgControl *c = &d->tpl->control[i];
        if (c->kind != DC_LIST && c->kind != DC_COMBO) continue;
        if (c->id == id) return n < DLG_BANKS ? n : DLG_BANKS - 1;
        n++;
    }
    return 0;
}

/* -------------------------------------------------------------- geometry */

// The caption bar the original's dialogs wear, in dialog units.
#define DLG_TITLE_H 9

static int controlCount(const DlgTemplate *tpl) {
    int n = 0;
    while (tpl->control[n].kind != DC_END) n++;
    return n;
}

// A combo box's height in the resource is how far its list drops, not how tall
// the control is - dialog 124's first combo is seventy-one units, which would
// otherwise cover the second combo and both buttons under it.  The bar itself
// is one row.
#define COMBO_H 20

static void controlBox(const Dialog *d, const DlgControl *c,
                       int *x, int *y, int *w, int *h) {
    *x = d->x + c->x * DLG_SCALE;
    *y = d->y + (DLG_TITLE_H + c->y) * DLG_SCALE;
    *w = c->w * DLG_SCALE;
    *h = c->kind == DC_COMBO ? COMBO_H : c->h * DLG_SCALE;
}

int dlgControlRect(const Dialog *d, int id, int *x, int *y, int *w, int *h) {
    if (!d->tpl) return 0;
    for (int i = 0; d->tpl->control[i].kind != DC_END; i++)
        if (d->tpl->control[i].id == id) {
            controlBox(d, &d->tpl->control[i], x, y, w, h);
            return 1;
        }
    return 0;
}

void dlgOpen(Dialog *d, const DlgTemplate *tpl, int surfaceW, int surfaceH) {
    memset(d, 0, sizeof *d);
    d->tpl = tpl;
    d->open = 1;
    d->hot = -1;
    d->held = -1;
    d->listSel = -1;
    const int w = tpl->w * DLG_SCALE;
    const int h = (tpl->h + DLG_TITLE_H) * DLG_SCALE;
    d->surfaceW = surfaceW;
    d->surfaceH = surfaceH;
    d->x = (surfaceW - w) / 2;
    d->y = (surfaceH - h) / 2;
    if (d->x < 0) d->x = 0;
    if (d->y < 0) d->y = 0;

    const int n = controlCount(tpl);
    for (int i = 0; i < n && i < DLG_CONTROLS_MAX; i++) {
        d->state[i].id = tpl->control[i].id;
        d->state[i].value = 0;
        d->state[i].enabled = 1;
        d->states++;
    }
}

void dlgClose(Dialog *d) {
    d->open = 0;
    d->tpl = NULL;
    d->comboOpen = 0;
}

int dlgIsOpen(const Dialog *d) { return d->open && d->tpl; }

/* --------------------------------------------------------------- drawing */

#define ROW_H 16                // one row of a list, in pixels

static void drawList(Surface *out, const Dialog *d, int bank, int x, int y,
                     int w, int h, int selected) {
    fillRect(out, x, y, w, h, (unsigned char)UI_LIGHT);
    bevelDown(out, x, y, w, h);
    const int rows = (h - 4) / ROW_H;
    for (int i = 0; i < rows; i++) {
        const int n = d->listTop + i;
        if (n >= d->items[bank]) break;
        const int ry = y + 2 + i * ROW_H;
        const int picked = (n == selected);
        if (picked)
            fillRect(out, x + 2, ry, w - 4, ROW_H, (unsigned char)UI_PICK);
        fontDrawText(out, x + 4, ry, (unsigned char)(picked ? UI_PICK_TEXT
                                                            : UI_DARK),
                     d->item[bank][n]);
    }
}

void dlgDraw(Surface *out, const Dialog *d) {
    if (!dlgIsOpen(d)) return;
    const DlgTemplate *tpl = d->tpl;
    const int w = tpl->w * DLG_SCALE;
    const int h = (tpl->h + DLG_TITLE_H) * DLG_SCALE;

    fillRect(out, d->x, d->y, w, h, (unsigned char)UI_FACE);
    bevelUp(out, d->x, d->y, w, h);
    // The caption bar: navy with the title in white, which is what a 1997
    // desktop gave an active window.
    fillRect(out, d->x + 3, d->y + 3, w - 6, DLG_TITLE_H * DLG_SCALE - 4,
             (unsigned char)UI_PICK);
    fontDrawText(out, d->x + 7, d->y + 4, (unsigned char)UI_PICK_TEXT,
                 tpl->caption ? tpl->caption : "");

    for (int i = 0; tpl->control[i].kind != DC_END; i++) {
        const DlgControl *c = &tpl->control[i];
        int cx, cy, cw, ch;
        controlBox(d, c, &cx, &cy, &cw, &ch);
        const DlgState *st = stateOfConst(d, c->id);
        const int on = st ? st->enabled : 1;
        // What the program has put there, or the resource's own caption.
        const char *caption_ = st && st->hasText ? st->text : c->text;
        const unsigned char ink =
            (unsigned char)(on ? UI_DARK : UI_GREY_TEXT);

        switch (c->kind) {
        case DC_PUSH:
        case DC_DEFPUSH: {
            const int down = (d->held == i && d->hot == i);
            fillRect(out, cx, cy, cw, ch, (unsigned char)UI_FACE);
            if (down) bevelDown(out, cx, cy, cw, ch);
            else bevelUp(out, cx, cy, cw, ch);
            if (c->kind == DC_DEFPUSH)
                fillRect(out, cx - 1, cy - 1, cw + 2, 1,
                         (unsigned char)UI_DARK);
            caption(out, cx + down, cy + down, cw, ch, caption_, ink, 1);
            break;
        }
        case DC_CHECK:
        case DC_RADIO: {
            const int box = 13;
            const int by = cy + (ch - box) / 2;
            fillRect(out, cx, by, box, box, (unsigned char)UI_LIGHT);
            bevelDown(out, cx, by, box, box);
            if (st && st->value) {
                // A tick for a box, a dot for a radio.
                if (c->kind == DC_CHECK) {
                    for (int k = 0; k < 3; k++)
                        fillRect(out, cx + 3 + k, by + 6 + k, 1, 2, ink);
                    for (int k = 0; k < 5; k++)
                        fillRect(out, cx + 6 + k, by + 7 - k, 1, 2, ink);
                } else {
                    fillRect(out, cx + 4, by + 4, 5, 5, ink);
                }
            }
            caption(out, cx + box + 4, cy, cw, ch, caption_, ink, 0);
            break;
        }
        case DC_GROUP:
            // The frame, broken where the caption sits.
            fillRect(out, cx, cy + 6, cw, 1, (unsigned char)UI_SHADOW);
            fillRect(out, cx, cy + 7, cw, 1, (unsigned char)UI_LIGHT);
            fillRect(out, cx, cy + 6, 1, ch - 6, (unsigned char)UI_SHADOW);
            fillRect(out, cx + 1, cy + 7, 1, ch - 8, (unsigned char)UI_LIGHT);
            fillRect(out, cx, cy + ch - 2, cw, 1, (unsigned char)UI_SHADOW);
            fillRect(out, cx, cy + ch - 1, cw, 1, (unsigned char)UI_LIGHT);
            fillRect(out, cx + cw - 2, cy + 6, 1, ch - 6,
                     (unsigned char)UI_SHADOW);
            fillRect(out, cx + cw - 1, cy + 6, 1, ch - 6,
                     (unsigned char)UI_LIGHT);
            if (caption_ && *caption_) {
                const int tw = fontTextWidth(caption_);
                fillRect(out, cx + 6, cy, tw + 6, 16, (unsigned char)UI_FACE);
                fontDrawText(out, cx + 9, cy, ink, caption_);
            }
            break;
        case DC_TEXT:
            // One line gets the vertical centring a Windows static gives it;
            // anything taller than two rows is wrapped text and is drawn from
            // the top, which is where Windows puts it.
            if (ch >= 32) captionWrapped(out, cx, cy, cw, ch, caption_, ink, 0);
            else caption(out, cx, cy, cw, ch, caption_, ink, 0);
            break;
        case DC_TEXTC:
            if (ch >= 32) captionWrapped(out, cx, cy, cw, ch, caption_, ink, 1);
            else caption(out, cx, cy, cw, ch, caption_, ink, 1);
            break;
        case DC_FRAME:
            fillRect(out, cx, cy, cw, ch, (unsigned char)UI_DARK);
            bevelDown(out, cx, cy, cw, ch);
            break;
        case DC_LIST:
            drawList(out, d, bankOf(d, c->id), cx, cy, cw, ch, d->listSel);
            break;
        case DC_COMBO: {
            const int barH = COMBO_H;
            fillRect(out, cx, cy, cw, barH, (unsigned char)UI_LIGHT);
            bevelDown(out, cx, cy, cw, barH);
            const int bank = bankOf(d, c->id);
            const int v = st ? st->value : 0;
            if (v >= 0 && v < d->items[bank])
                fontDrawText(out, cx + 4, cy + 2, ink, d->item[bank][v]);
            // The drop arrow, on its own raised square.
            const int ax = cx + cw - barH;
            fillRect(out, ax, cy + 2, barH - 4, barH - 4,
                     (unsigned char)UI_FACE);
            bevelUp(out, ax, cy + 2, barH - 4, barH - 4);
            for (int k = 0; k < 4; k++)
                fillRect(out, ax + 4 + k, cy + 7 + k, (4 - k) * 2, 1, ink);
            break;
        }
        case DC_EDIT:
            fillRect(out, cx, cy, cw, ch, (unsigned char)UI_LIGHT);
            bevelDown(out, cx, cy, cw, ch);
            fontDrawText(out, cx + 4, cy + (ch - 16) / 2, ink, d->edit);
            break;
        case DC_SLIDER: {
            const int mid = cy + ch / 2;
            fillRect(out, cx, mid - 2, cw, 4, (unsigned char)UI_SHADOW);
            bevelDown(out, cx, mid - 2, cw, 4);
            const int v = st ? st->value : 0;
            const int at = cx + (cw - 10) * (v < 0 ? 0 : v > 100 ? 100 : v)
                               / 100;
            fillRect(out, at, cy, 10, ch, (unsigned char)UI_FACE);
            bevelUp(out, at, cy, 10, ch);
            break;
        }
        case DC_SPIN: {
            // Two little buttons stacked, each with a three-pixel triangle -
            // which is what an up-down control is.  The port has nothing for
            // it to change: 112's is the CD track, and there is no CD.
            const int half = ch / 2;
            for (int part = 0; part < 2; part++) {
                const int by = cy + part * half;
                fillRect(out, cx, by, cw, half, (unsigned char)UI_FACE);
                bevelUp(out, cx, by, cw, half);
                const int mx = cx + cw / 2, my = by + half / 2;
                for (int k = 0; k < 3; k++) {
                    const int row = part ? my + 1 - k : my - 1 + k;
                    fillRect(out, mx - k, row, k * 2 + 1, 1, ink);
                }
            }
            break;
        }
        case DC_ICON:
            fillRect(out, cx, cy, cw, ch, (unsigned char)UI_SHADOW);
            bevelUp(out, cx, cy, cw, ch);
            break;
        case DC_END:
            break;
        }
    }

    // A combo that is down draws its list over everything else.
    if (d->comboOpen) {
        int cx, cy, cw, ch;
        if (dlgControlRect(d, d->comboOpen, &cx, &cy, &cw, &ch)) {
            const int bank = bankOf(d, d->comboOpen);
            const int n = d->items[bank];
            const int rows = n < 8 ? n : 8;
            drawList(out, d, bank, cx, cy + COMBO_H, cw, rows * ROW_H + 4,
                     dlgValue(d, d->comboOpen));
        }
    }
}

/* ------------------------------------------------------------ hit testing */

static int controlAt(const Dialog *d, int x, int y) {
    for (int i = 0; d->tpl->control[i].kind != DC_END; i++) {
        const DlgControl *c = &d->tpl->control[i];
        if (c->kind == DC_GROUP || c->kind == DC_TEXT ||
            c->kind == DC_TEXTC || c->kind == DC_ICON) continue;
        int cx, cy, cw, ch;
        controlBox(d, c, &cx, &cy, &cw, &ch);
        if (x >= cx && x < cx + cw && y >= cy && y < cy + ch) return i;
    }
    return -1;
}

void dlgHover(Dialog *d, int x, int y) {
    if (!dlgIsOpen(d)) return;
    d->hot = controlAt(d, x, y);
}

// Which row of a list a point is on, or -1.
static int rowAt(const Dialog *d, int bank, int x, int y, int lx, int ly,
                 int lw, int lh) {
    if (x < lx || x >= lx + lw || y < ly + 2 || y >= ly + lh - 2) return -1;
    const int r = d->listTop + (y - ly - 2) / ROW_H;
    return r < d->items[bank] ? r : -1;
}

int dlgClick(Dialog *d, int x, int y) {
    if (!dlgIsOpen(d)) return -1;
    const DlgTemplate *tpl = d->tpl;
    const int w = tpl->w * DLG_SCALE;
    const int h = (tpl->h + DLG_TITLE_H) * DLG_SCALE;

    // A combo that is down eats the click, wherever it lands.
    if (d->comboOpen) {
        int cx, cy, cw, ch;
        if (dlgControlRect(d, d->comboOpen, &cx, &cy, &cw, &ch)) {
            const int bank = bankOf(d, d->comboOpen);
            const int n = d->items[bank];
            const int rows = n < 8 ? n : 8;
            const int r = rowAt(d, bank, x, y, cx, cy + COMBO_H, cw,
                                rows * ROW_H + 4);
            if (r >= 0) dlgSetValue(d, d->comboOpen, r);
        }
        d->comboOpen = 0;
        return 0;
    }

    if (x < d->x || x >= d->x + w || y < d->y || y >= d->y + h) {
        // Outside.  A dialog is modal, so this is not a click on the map -
        // it is simply ignored, which is what a modal dialog does.
        return 0;
    }

    const int i = controlAt(d, x, y);
    if (i < 0) return 0;
    const DlgControl *c = &tpl->control[i];
    DlgState *st = stateOf(d, c->id);
    if (st && !st->enabled) return 0;

    int cx, cy, cw, ch;
    controlBox(d, c, &cx, &cy, &cw, &ch);

    switch (c->kind) {
    case DC_PUSH:
    case DC_DEFPUSH:
        d->result = c->id;
        return c->id;
    case DC_CHECK:
        if (st) st->value = !st->value;
        return 0;
    case DC_RADIO:
        // One of a group: everything with the same kind next to it goes off.
        for (int k = 0; tpl->control[k].kind != DC_END; k++) {
            if (tpl->control[k].kind != DC_RADIO) continue;
            DlgState *o = stateOf(d, tpl->control[k].id);
            if (o) o->value = 0;
        }
        if (st) st->value = 1;
        return 0;
    case DC_LIST: {
        const int r = rowAt(d, bankOf(d, c->id), x, y, cx, cy, cw, ch);
        if (r >= 0) d->listSel = r;
        return 0;
    }
    case DC_COMBO:
        d->comboOpen = c->id;
        return 0;
    case DC_SLIDER: {
        int v = (x - cx) * 100 / (cw > 1 ? cw - 1 : 1);
        if (v < 0) v = 0;
        if (v > 100) v = 100;
        if (st) st->value = v;
        return 0;
    }
    default:
        return 0;
    }
}
