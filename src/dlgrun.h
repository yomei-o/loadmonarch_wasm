// Running the game's dialogs: which one is up, what it shows, and what
// pressing its buttons does.
//
// The dialogs themselves are in dlg.c (the widgets) and dlgdefs.c (the
// resources).  This is the part that knows what each one is *for*, so a host
// only has to forward the pointer and draw the surface.  Both hosts share it,
// which is the point.
#ifndef DLGRUN_H
#define DLGRUN_H

#include "dlg.h"
#include "sim.h"

typedef enum {
    DLG_NONE = 0,
    DLG_DEFAULT_ORDERS,         // 124, from Orders / Default Orders
    DLG_VERSION,                // 120, from Help / Version
    DLG_INFORMATION,            // 118, when a unit cannot get there cleanly
    DLG_SYSTEM_SETTING,         // 115, from Controls / System Setting
    DLG_LOAD,                   // 107
    DLG_SAVE,                   // 106
    DLG_LOAD_SINGLE_MAP,        // 127
    DLG_ALLIANCE,               // 119, from Controls / Alliance Setting
    DLG_SOUND_SETTING,          // 126, from Controls / Customize Sounds
    DLG_HELP,                   // 123, from Help / Quick Rules
    DLG_LOAD_QUEST_MAP,         // 104, from System / Load Quest Map
    DLG_CUSTOM_SOUNDS           // 112, from Controls / Customize Sounds
} DlgWhich;

// What the host has to do for the port, because it is the host's business and
// not the game's: read and write save slots, and change how fast the clock
// runs.  A host that cannot do one leaves the pointer null and the dialog
// tells the player so.
typedef struct {
    // Save slots.  `name` is filled by the port; `slots` says how many there
    // are.  read/write/remove answer non-zero on success.
    int (*slotName)(void *user, int slot, char *out, int size);
    int (*slotRead)(void *user, int slot);
    int (*slotWrite)(void *user, int slot, const char *name);
    int (*slotRemove)(void *user, int slot);
    int slots;

    // The soundtrack, for dialog 112: SOUND/SOUND.CFG's entries, and playing
    // or stopping one.
    int (*tuneName)(void *user, int tune, char *out, int size);
    int (*tuneNumber)(void *user, int tune);
    int tunes;
    void (*tunePlay)(void *user, int tune);
    void (*tuneStop)(void *user);

    // The clock: 0 slowest, 29 fastest, which is DAT_00437698's range.
    int (*getSpeed)(void *user);
    void (*setSpeed)(void *user, int speed);

    // The campaign list, and loading one of them.  The host owns the archive,
    // so it is the host that can name the stages.
    int (*stageName)(void *user, int stage, char *out, int size);
    int stages;
    int (*loadStage)(void *user, int stage);

    // Whether a window is showing, and turning it on or off.  0 progress,
    // 1 unit, 2 graph.
    int (*getWindow)(void *user, int which);
    void (*setWindow)(void *user, int which, int on);

    void *user;
} DlgHost;

typedef struct {
    Dialog dlg;
    DlgWhich which;
    Sim *sim;
    const DlgHost *host;

    // What the dialog is working on while it is up.
    int askUnit;                // DLG_INFORMATION: the unit being asked about
    int askKind;                // 0 blocked by a friend, 1 enemies in the path
    int allyPick;               // DLG_ALLIANCE: the country under the pointer
    int stageCount;             // how many rows the map list has
    int firstEmpty;             // the save slot Save New will use, or -1
    int lastOrdered;            // how many took the order the Information
                                // dialog was asking about
    int showEnding;             // 104's Ending was pressed; the host reads it
} DlgRunner;

void dlgRunInit(DlgRunner *r, Sim *sim, const DlgHost *host);

// Opens one.  Non-zero when it went up; zero when there was nothing to show,
// which is how "no save slots" and "no alliance to make" answer.
int dlgRunOpen(DlgRunner *r, DlgWhich which, int surfaceW, int surfaceH);

int dlgRunUp(const DlgRunner *r);
void dlgRunDraw(Surface *out, const DlgRunner *r, const GameState *game);
void dlgRunHover(DlgRunner *r, int x, int y);

// A click.  Answers non-zero when the dialog closed, so the caller knows the
// pointer belongs to the game again.
int dlgRunClick(DlgRunner *r, int x, int y);

// The command numbers MENU 101 uses, turned into dialogs.  DLG_NONE when the
// command is not one of ours.
DlgWhich dlgForCommand(int command);

#endif
