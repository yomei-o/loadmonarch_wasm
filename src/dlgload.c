#include "dlgload.h"

#include "font.h"
#include "rsrc.h"

#include <stdio.h>
#include <string.h>

// The port's dialogs and the resource each one is.
static const struct { DlgWhich which; unsigned id; } kIds[] = {
    {DLG_LOAD_QUEST_MAP,  104},
    {DLG_SAVE,            106},
    {DLG_LOAD,            107},
    {DLG_CUSTOM_SOUNDS,   112},
    {DLG_SYSTEM_SETTING,  115},
    {DLG_INFORMATION,     118},
    {DLG_ALLIANCE,        119},
    {DLG_VERSION,         120},
    {DLG_HELP,            123},
    {DLG_DEFAULT_ORDERS,  124},
    {DLG_SOUND_SETTING,   126},
    {DLG_LOAD_SINGLE_MAP, 127},
};
#define DLG_LOADED_MAX (sizeof kIds / sizeof kIds[0])

// One loaded template, with room for its own strings.
typedef struct {
    int filled;
    DlgTemplate tpl;
    DlgControl control[RSRC_CONTROLS_MAX + 1];      // DC_END terminated
    char caption[RSRC_TEXT];
    char text[RSRC_CONTROLS_MAX][RSRC_TEXT];
} Loaded;

static Loaded g_loaded[DLG_LOADED_MAX];

unsigned dlgResourceId(DlgWhich which) {
    for (unsigned i = 0; i < DLG_LOADED_MAX; i++)
        if (kIds[i].which == which) return kIds[i].id;
    return 0;
}

const DlgTemplate *dlgLoaded(DlgWhich which) {
    for (unsigned i = 0; i < DLG_LOADED_MAX; i++)
        if (kIds[i].which == which && g_loaded[i].filled)
            return &g_loaded[i].tpl;
    return NULL;
}

// Which of the port's widgets a resource control is.  The class comes back
// from rsrc.c as the name Windows gives it, and the low bits of the style say
// which sort of button or static it is - the same bits dump_dialogs.py reads.
static DlgControlKind kindOf(const RsrcControl *c) {
    if (strcmp(c->cls, "Button") == 0) {
        switch (c->style & 0x0f) {
        case 0x00: return DC_PUSH;              // BS_PUSHBUTTON
        case 0x01: return DC_DEFPUSH;           // BS_DEFPUSHBUTTON
        case 0x02: case 0x03: return DC_CHECK;  // CHECKBOX, AUTOCHECKBOX
        case 0x04: case 0x09: return DC_RADIO;  // RADIOBUTTON, AUTORADIO
        case 0x07: return DC_GROUP;             // BS_GROUPBOX
        default: return DC_PUSH;
        }
    }
    if (strcmp(c->cls, "Static") == 0) {
        switch (c->style & 0x1f) {
        case 0x00: return DC_TEXT;              // SS_LEFT
        case 0x01: return DC_TEXTC;             // SS_CENTER
        case 0x02: return DC_TEXT;              // SS_RIGHT, drawn left
        case 0x03: return DC_ICON;              // SS_ICON
        // The rectangles and frames are what the game fills with its own art.
        case 0x04: case 0x05: case 0x06:
        case 0x07: case 0x08: case 0x09: return DC_FRAME;
        default: return DC_TEXT;
        }
    }
    if (strcmp(c->cls, "ListBox") == 0) return DC_LIST;
    if (strcmp(c->cls, "ComboBox") == 0) return DC_COMBO;
    if (strcmp(c->cls, "Edit") == 0) return DC_EDIT;
    if (strcmp(c->cls, "msctls_trackbar32") == 0) return DC_SLIDER;
    if (strcmp(c->cls, "msctls_updown32") == 0) return DC_SPIN;
    return DC_TEXT;
}

// A caption the font cannot draw would come out as empty boxes, and the
// built-in English is better than that - so a template with one in it is not
// taken at all.  Everything in a dialog is one string or another; taking half
// of it would leave a window in two languages.
static int drawable(const RsrcDialog *from) {
    if (!fontCanDraw(from->caption, NULL)) return 0;
    for (int i = 0; i < from->controls; i++)
        if (!fontCanDraw(from->control[i].text, NULL)) return 0;
    return 1;
}

static int fill(Loaded *out, const RsrcDialog *from) {
    if (from->controls > RSRC_CONTROLS_MAX) return 0;
    if (from->w <= 0 || from->h <= 0) return 0;
    if (!drawable(from)) return 0;

    memset(out, 0, sizeof *out);
    snprintf(out->caption, sizeof out->caption, "%s", from->caption);
    out->tpl.caption = out->caption;
    out->tpl.w = from->w;
    out->tpl.h = from->h;
    out->tpl.control = out->control;

    for (int i = 0; i < from->controls; i++) {
        const RsrcControl *c = &from->control[i];
        snprintf(out->text[i], sizeof out->text[i], "%s", c->text);
        out->control[i].kind = kindOf(c);
        // 0xffff is the id a resource gives a control nothing talks to, and
        // the port writes that as 65535.
        out->control[i].id = c->id == 0xffffffffu ? 65535 : (int)c->id;
        out->control[i].x = c->x;
        out->control[i].y = c->y;
        out->control[i].w = c->w;
        out->control[i].h = c->h;
        out->control[i].text = out->text[i];
    }
    out->control[from->controls].kind = DC_END;
    out->filled = 1;
    return 1;
}

int dlgLoadFromHost(const Host *host) {
    static unsigned char image[400 * 1024];
    unsigned got = 0;

    for (unsigned i = 0; i < DLG_LOADED_MAX; i++) g_loaded[i].filled = 0;
    if (!hostRead(host, "DS7E_WIN.EXE", image, sizeof image, &got) &&
        !hostRead(host, "DS7J_WIN.EXE", image, sizeof image, &got))
        return 0;

    static Pe pe;
    if (!peOpen(&pe, image, got)) return 0;

    int done = 0;
    for (unsigned i = 0; i < DLG_LOADED_MAX; i++) {
        static RsrcDialog from;
        if (!rsrcDialog(&pe, kIds[i].id, &from)) continue;
        if (fill(&g_loaded[i], &from)) done++;
    }
    return done;
}
