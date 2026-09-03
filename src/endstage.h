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
// What happens after the click is 0041f4c0's tail.  A loss or a stage whose
// clock ran out reloads the same stage - FUN_00405de0(DAT_0043450c).  A win
// files the record through 0041b140 and then runs 0041f6c0, which works the
// player's class out, opens dialog 114 if it has gone up, and - when the stage
// just cleared is the furthest the campaign has got - calls FUN_004067c0,
// which loads DAT_00436a00.  That is the "Go to the next stage" the window
// promises: the game goes there by itself, and Load Quest Map is for picking
// an earlier one again.  The last stage instead runs FUN_00409570: dialog 114,
// then 121, then "Congratulations! you have completed ...".
//
// The parade: each scene sets up as many as twenty actors at +0x25c, 0x118
// bytes apiece, through FUN_00411340, and 00410020 walks them with
// FUN_00410200 and draws them with FUN_004104d0.  An actor is a sprite, a
// place, a step and a little program - the scripts FUN_00411340 builds on its
// own stack, which tools/walk_scripts.py recovers - and the whole of it is the
// player's own soldiers marching across the garden behind the gate towers.
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

// One of the parade.  The fields are 00410200's and 004104d0's, by the
// offsets they use into the 0x118 bytes an actor has.
#define END_ACTORS 20
#define END_SCRIPTS 14                 // FUN_00411340 builds fourteen
#define END_SCRIPT_MAX 24

typedef struct {
    int alive;                      // +0x258
    int wait;                       // +0x25c, -1 stops for ever
    int x, y;                       // +0x260, +0x264
    unsigned char command;          // +0x268, what it is doing now
    int pc;                         // +0x368, a word at a time
    signed char step;               // +0x369
    unsigned char sprite;           // +0x36a, the base without the facing
    signed char facing;             // +0x36b
    unsigned char side;             // +0x36c
    unsigned short script[END_SCRIPT_MAX];
} EndActor;

typedef struct {
    int up;
    int mode;                       // EndStageMode
    int tick;                       // +0x238, one per WM_TIMER
    int stage;                      // DAT_0043450c when it opened
    char name[STAGE_NAME];          // FUN_0041a650's title for that stage
    StageScore score;               // frozen when it opened
    int against;                    // DAT_00436438: this run less the record
    EndActor actor[END_ACTORS];
    int hold;                       // +0x5838: nobody moves while this counts
} EndStage;

void campaignClear(Campaign *campaign);

// 0041f6c0's player class: the best remaining-with-bonus of every stage
// cleared so far, put on a scale of twenty - a thousand days a step to ten
// thousand, then ten thousand a step, and everything past a hundred thousand
// is the top.  DAT_00436a04 is where it is kept, and a class that has just
// gone up is what opens dialog 114.
unsigned campaignRank(const Campaign *campaign);

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

// `side` is the player's own country, whose soldiers march.
void endStageOpen(EndStage *end, int mode, const StageScore *score, int stage,
                  const char *name, int against, unsigned side);
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
