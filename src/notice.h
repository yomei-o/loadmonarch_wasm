// Dialog 122 - the notice the game throws up when a country goes.
//
// 165 by 44 dialog units and no controls: 00411bb0 asks for 0x100 by 0x40,
// centres it on the screen, fills its bitmap with the interface sheet's rows
// 960 to 1023 - a blue frame with a black middle - and starts a 100 ms timer.
// 00411d10 is what that timer runs, and it counts to thirty and then closes
// the window itself, so the notice is a three-second toast.  A click closes it
// early, the way it does every one of these control-less windows.
//
// There are two of them, told apart by the low half of the parameter
// FUN_004095d0 is handed:
//
//   0  00411d70, from FUN_00424520 - "%s has Fallen".  The window plays five
//      frames of the country's castle coming down first and only writes the
//      words at tick six.
//   1  00411eb0, from 0041f0d0 - "Break alliance", which every country still
//      standing gets when the second of the four has fallen.
//
// Not done: the five frames of the castle, and the two flags 00411eb0 draws
// beside its words.  Both are sprite numbers built out of the country's own
// terrain byte - 00411d70 asks for `(byte << 3) | 0x66` and then
// `(tick + byte * 8) - 1 | 0xa4` - and neither the numbering nor the bank they
// index has been worked out yet.
#ifndef NOTICE_WINDOW_H
#define NOTICE_WINDOW_H

#include "render.h"
#include "state.h"

#define NOTICE_W 256
#define NOTICE_H 64
#define NOTICE_SHEET_TOP 960
// 00411d59: past thirty ticks the window closes itself.
#define NOTICE_LIFE 30
// 00411d70 holds the words back until the castle has finished falling.
#define NOTICE_WORDS_AT 6

typedef enum {
    NOTICE_FALLEN = 0,
    NOTICE_BREAK_ALLIANCE = 1
} NoticeKind;

typedef struct {
    int up;
    int kind;
    int tick;
    unsigned faction;
    char name[24];              // the country's own name, for "%s has Fallen"
} Notice;

void noticeOpen(Notice *notice, int kind, unsigned faction, const char *name);
// One 100 ms timer tick.  Answers non-zero once it has closed itself.
int noticeStep(Notice *notice);
int noticeDismiss(Notice *notice);
void noticeDraw(Surface *out, const Notice *notice, const World *world,
                int x, int y);

#endif
