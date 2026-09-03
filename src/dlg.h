// The game's dialogs, drawn in the surface.
//
// The executable carries sixteen of them as DLGTEMPLATE resources, and this
// port lays each one out from that dump - the same controls, at the same
// places, with the same ids and the same captions.  Dialog units are turned
// into pixels at two apiece, which is close to what MS Sans Serif 10pt gave
// them and lands every caption on a whole character of the port's own font.
//
// It is a small widget set, but the dialogs need all of it: push buttons,
// check boxes, radio buttons, group boxes, static text, a list box, a combo
// box, an edit field and a slider.  Nothing is keyboard-driven, because the
// original is not either - it has one accelerator in the whole program.
#ifndef DLG_H
#define DLG_H

#include "render.h"

// Dialog units to pixels.
#define DLG_SCALE 2

typedef enum {
    DC_END = 0,                 // the terminator of a control list
    DC_PUSH,                    // a push button
    DC_DEFPUSH,                 // the same, drawn with the heavy border
    DC_CHECK,                   // an auto check box
    DC_RADIO,                   // an auto radio button
    DC_GROUP,                   // a group box, with its caption in the border
    DC_TEXT,                    // static text, left
    DC_TEXTC,                   // static text, centred
    DC_FRAME,                   // a sunken black frame, which the game fills
    DC_LIST,                    // a list box
    DC_COMBO,                   // a drop-down list
    DC_EDIT,                    // a single-line edit field
    DC_SLIDER,                  // msctls_trackbar32
    DC_ICON                     // where the program's icon goes
} DlgControlKind;

typedef struct {
    DlgControlKind kind;
    int id;
    short x, y, w, h;           // in dialog units, as the resource has them
    const char *text;
} DlgControl;

#define DLG_CONTROLS_MAX 40
#define DLG_ITEMS_MAX 64
#define DLG_ITEM_TEXT 40
#define DLG_BANKS 2

typedef struct {
    const char *caption;
    short w, h;                 // in dialog units
    const DlgControl *control;  // DC_END terminated
} DlgTemplate;

// What a control is showing.  Kept beside the template rather than in it, so
// the template can stay const and shared.
typedef struct {
    int id;
    int value;                  // check state, radio choice, slider, selection
    int enabled;
} DlgState;

typedef struct {
    const DlgTemplate *tpl;
    int open;
    int x, y;                   // top left in surface pixels
    int hot;                    // control under the pointer, or -1
    int held;                   // control the button went down on, or -1
    DlgState state[DLG_CONTROLS_MAX];
    int states;

    // The rows a list or a combo shows.  Default Orders has two combos with
    // different contents, so there are two banks: they are handed out in the
    // order the controls appear, so the first list or combo uses bank zero and
    // the second bank one.
    char item[DLG_BANKS][DLG_ITEMS_MAX][DLG_ITEM_TEXT];
    int items[DLG_BANKS];
    int listTop;                // first row drawn
    int listSel;               // chosen row, or -1
    int comboOpen;              // the id of the combo whose list is down, or 0

    // What the edit field holds, for Save.
    char edit[DLG_ITEM_TEXT];

    int result;                 // the id of the button that closed it, or 0
} Dialog;

void dlgOpen(Dialog *d, const DlgTemplate *tpl, int surfaceW, int surfaceH);
void dlgClose(Dialog *d);
int dlgIsOpen(const Dialog *d);

// The state of one control by id, and how to set it.
int dlgValue(const Dialog *d, int id);
void dlgSetValue(Dialog *d, int id, int value);
void dlgEnable(Dialog *d, int id, int enabled);

void dlgClearItems(Dialog *d);
void dlgAddItem(Dialog *d, const char *text);

// The same for the second bank, which the second list or combo of a dialog
// draws from.
void dlgClearItems2(Dialog *d);
void dlgAddItem2(Dialog *d, const char *text);

void dlgDraw(Surface *out, const Dialog *d);
void dlgHover(Dialog *d, int x, int y);

// A click.  Answers the id of the control that was pressed and closed the
// dialog, 0 while it is still up, and -1 when the click was outside it.
int dlgClick(Dialog *d, int x, int y);

// Where a control sits, in surface pixels - so a host can put the game's own
// art inside a frame the dialog reserves.
int dlgControlRect(const Dialog *d, int id, int *x, int *y, int *w, int *h);

/* --------------------------------------------------- the game's own sixteen */

extern const DlgTemplate kDlgDefaultOrders;     // 124
extern const DlgTemplate kDlgVersion;           // 120
extern const DlgTemplate kDlgInformation;       // 118
extern const DlgTemplate kDlgSystemSetting;     // 115
extern const DlgTemplate kDlgLoad;              // 107
extern const DlgTemplate kDlgSave;              // 106
extern const DlgTemplate kDlgLoadSingleMap;     // 127
extern const DlgTemplate kDlgAlliance;          // 119
extern const DlgTemplate kDlgSoundSetting;      // 126
extern const DlgTemplate kDlgHelp;              // 123

#endif
