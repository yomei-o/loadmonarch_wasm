// Dialog 105 - the window at the end of a stage - and the campaign record
// behind it.
//
// 0041f4c0 is the routine that decides a stage is over.  It works out the
// score, files it, and then opens dialog 105 through FUN_004095d0(0x69, mode,
// hwnd) - a modal window with no controls at all, 176 by 188 dialog units,
// which the program paints itself.  0040fca0 centres it and fills its bitmap
// with the interface sheet's rows 512 to 767 verbatim: a yellow speech balloon
// over a framed brown panel over a walled garden with a sun in it.  0040e8b8's
// message table sends WM_TIMER to 00410020, which paints the mode's own scene
// and steps its animation, and WM_LBUTTONUP to 0040ea50, whose jump table
// closes exactly this dialog and its three control-less siblings.  So any
// click dismisses it, whenever it comes.
//
// What happens after the click is 0041f4c0's tail: a loss or a stage whose
// clock ran out reloads the same stage (FUN_00405de0(DAT_0043450c)), and a win
// keeps the record 0041b140 has just written, which is what opens the next map
// in Load Quest Map.
//
// Not done, and worth doing: the parade.  Each scene sets up twenty actors at
// +0x25c (0x118 bytes apiece) through FUN_00411340 and 00410020 walks them
// with FUN_00410200 and draws them with FUN_004104d0 - the player's own
// soldiers marching across the garden, behind the two gate towers the routine
// stamps back over them from the sheet at 0x2c000 and 0x2c0e0.  The text and
// the flow are here; the marching is not.
#ifndef ENDSTAGE_H
#define ENDSTAGE_H

#include "render.h"
#include "sim.h"
#include "world.h"

// 0041f4c0's uVar6, which is the mode it hands the dialog.
typedef enum {
    END_WON = 0,            // won it, and the campaign has not seen it before
    END_TIME_OVER = 1,      // won it, but the clock had run out
    END_DEFEATED = 2,       // the player's own country is gone
    END_WON_AGAIN = 3,      // won a stage the campaign already has a record of
    END_SINGLE_MAP = 4      // won it outside the campaign
} EndStageMode;

// The window's own size: 0040fca0 asks for 0x100 by 0x100 and centres that.
#define END_W 256
#define END_H 256
// Where the background comes from - sheet row 512, 256 rows of it.
#define END_SHEET_TOP 512
// 00410020 draws "Click here / to go on!" when its counter reaches this, and
// stops counting at 1000.
#define END_PROMPT 400

// 00436a00 and the table at 00436a0c: what the campaign remembers between
// stages.  The original keeps fourteen dwords a stage and writes them to a
// "Score v11" file through FUN_004057f0; what is kept here is the one number
// the game reads back - the remaining-with-bonus a stage was cleared with,
// which 0041b0e0 subtracts to say whether this run beat it - plus how far the
// player has got, which is what decides the maps Load Quest Map will open.
typedef struct {
    unsigned remaining[STAGE_MAX];  // 0 where the stage has never been cleared
    int reached;                    // DAT_00436a00, the furthest stage opened
    unsigned rank;                  // DAT_00436a04, 0041f6c0's player class
} Campaign;

typedef struct {
    int up;                         // is the window showing
    int mode;                       // EndStageMode
    int tick;                       // +0x238, one per WM_TIMER
    int stage;                      // DAT_0043450c when it opened
    char name[STAGE_NAME];          // FUN_0041a650's title for that stage
    StageScore score;               // frozen when it opened
    int against;                    // DAT_00436438: this run less the record
} EndStage;

void campaignClear(Campaign *campaign);

// 0041b140.  Files the win: the stage's record, and one more stage opened when
// this was the first time through it.  Answers non-zero when the record
// changed, which is what 0041f4c0 tests before it saves the score file.  The
// difference against the old record - 0041b0e0's DAT_00436438 - lands in
// `against`.
int campaignRecord(Campaign *campaign, int stage, const StageScore *score,
                   int *against);

// 0041f4c0's five-way verdict.  `outcome` is simStageOutcome's, `quest`
// non-zero when the campaign is being played rather than one map on its own.
// The order the original tests in matters: being knocked out beats everything,
// then a single map, then the clock, then a stage already cleared.
int endStageMode(int outcome, const StageScore *score, const Campaign *campaign,
                 int stage, int quest);

void endStageOpen(EndStage *end, int mode, const StageScore *score, int stage,
                  const char *name, int against);
void endStageStep(EndStage *end);
// Answers non-zero if the window was up and has now been dismissed.
int endStageDismiss(EndStage *end);

// Draws it with its top left at x,y.  The caller centres it; 0040fca0 centres
// on the screen.
void endStageDraw(Surface *out, const EndStage *end, const World *world,
                  int x, int y);

// Whether the stage has to be played again rather than left behind - the tail
// of 0041f4c0, which reloads DAT_0043450c for exactly these two modes.
int endStageReplays(int mode);

#endif
