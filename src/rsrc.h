// The executable's own resources, read out of the executable.
//
// The menu bar and the sixteen dialogs in this port were transcribed from
// tools/dump_menus.py and tools/dump_dialogs.py by hand, and one of them came
// out wrong - Leader Position under the wrong menu, three captions invented,
// separators in the wrong places - and nothing noticed for weeks.  A test can
// read the resource itself and say so, which is what this is for.
//
// DS7E_WIN.EXE is a PE32: the resource directory is a tree of three levels -
// type, then name or id, then language - and the leaves are data entries
// giving an RVA and a size.  MENU 101 is RT_MENU (4) and the dialogs are
// RT_DIALOG (5).
#ifndef RSRC_H
#define RSRC_H

#define RSRC_TYPE_MENU 4
#define RSRC_TYPE_DIALOG 5

// A resource string is UTF-16 and the rest of this port speaks Shift-JIS -
// the game's own data files are in it and src/font16.c draws it - so the two
// have to be put together somewhere.  src/rsrc_sjis.c is that somewhere, and
// tools/make_rsrc_text.py generates it from the characters the two releases
// actually use, which is about two hundred and fifty.
typedef struct {
    unsigned short code;        // the UTF-16 code point
    unsigned char sjis[3];      // one or two bytes, nought terminated
} RsrcChar;

extern const RsrcChar kRsrcChars[];
extern const int kRsrcCharCount;

typedef struct {
    const unsigned char *image;     // the whole file
    unsigned size;
    unsigned base;                  // ImageBase
    unsigned sections;
    unsigned sectionAt;             // file offset of the section table
} Pe;

int peOpen(Pe *pe, const unsigned char *image, unsigned size);
// The bytes of one resource, or null.  `length` may be null.
const unsigned char *peResource(const Pe *pe, unsigned type, unsigned id,
                                unsigned *length);

/* ------------------------------------------------------------------ menus */

// One item of a menu, in the order the resource has them.  A separator has an
// empty caption and no command; a submenu is flattened into its parent, which
// is what the port's own menu bar does with Load Map, Leader Position and
// Resize Map.
#define RSRC_MENU_MAX 64
// Long enough for the longest string in the resources: dialog 119's static
// runs to a hundred and thirty characters over three lines, and at 64 it
// came back cut in half - which looked like the port being wrong.
#define RSRC_TEXT 256

typedef struct {
    int popup;                      // 1 where this item opens a submenu
    int separator;
    unsigned command;
    char text[RSRC_TEXT];           // with the & stripped
} RsrcMenuItem;

typedef struct {
    char text[RSRC_TEXT];           // the bar's own caption
    RsrcMenuItem item[RSRC_MENU_MAX];
    int items;
} RsrcMenu;

#define RSRC_MENUS_MAX 8

typedef struct {
    RsrcMenu menu[RSRC_MENUS_MAX];  // one per drop-down on the bar
    int menus;
} RsrcMenuBar;

// Reads MENU `id`.  Submenus below the bar are flattened into the drop-down
// they belong to, their trailing separators and all.
int rsrcMenuBar(const Pe *pe, unsigned id, RsrcMenuBar *out);

/* ---------------------------------------------------------------- dialogs */

#define RSRC_CONTROLS_MAX 48

typedef struct {
    unsigned style;
    unsigned exStyle;
    short x, y, w, h;
    unsigned id;
    char cls[RSRC_TEXT];            // "Button", "Static", ... or #0080 etc.
    char text[RSRC_TEXT];
} RsrcControl;

typedef struct {
    unsigned style;
    short x, y, w, h;
    char caption[RSRC_TEXT];
    RsrcControl control[RSRC_CONTROLS_MAX];
    int controls;
} RsrcDialog;

// Reads DIALOG `id`, plain template or DLGTEMPLATEEX.
int rsrcDialog(const Pe *pe, unsigned id, RsrcDialog *out);

/* ---------------------------------------------------------------- strings */

// One entry of the STRINGTABLE, which the executable keeps in blocks of
// sixteen: string `id` lives in block id / 16 + 1 at index id & 15.  Both
// releases carry one keyed by command number - "Alliance Setting" for 40012 -
// which is what LoadStringA is imported for and what the tool bar CreateToolbarEx
// makes shows in its tooltips.  Answers non-zero when there is one.
#define RSRC_TYPE_STRING 6
int rsrcString(const Pe *pe, unsigned id, char *out, int size);

#endif
