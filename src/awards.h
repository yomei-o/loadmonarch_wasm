// Dialog 114 - the Awards certificate.
//
// 0041f6c0 opens it through FUN_004095d0(0x72, 0, hwnd) when the player's
// class goes up, and FUN_00409570 opens it again at the end of the campaign
// before the ending.  Like the other control-less windows it paints itself:
// 004120c0 asks for 0x160 by 0x130 - 352 by 304 - centres it, loads one of
// the interlude pictures behind it and writes thirteen lines of a citation on
// top, every one of them centred, black with a white shadow (0040a870's
// colours 10 and 11).
//
// The picture is chosen by the MONTH, not by the rank: 004121c8 takes
// wMonth - 1 out of the GetLocalTime it has just done and indexes twelve
// entries with it, and they group into the four seasons - GAKU1 for March to
// May, GAKU2 for June to August, GAKU3 for September to November, GAKU4 for
// December to February.  The four pictures are the seasons, and the
// certificate is dated, so a certificate carries the season it was won in.
//
// The rank itself is 0041f6c0's class, and the twenty names for it are the
// table at DS:0x433480: "Class -", then Class 9 down to Class 1, then First
// Degree and Degree 2 up to Degree 9, and Master at the top.
#ifndef AWARDS_H
#define AWARDS_H

#include "picture.h"
#include "render.h"

#define AWARD_W 352
#define AWARD_H 304

typedef struct {
    int up;
    unsigned rank;              // DAT_00436a04
    int year, month, day;       // what the citation is dated
    char title[32];             // the program's own name, which it quotes
} Awards;

// "Class 3", "First Degree", "Master" ... - DS:0x433480's twenty.
const char *awardsRankName(unsigned rank);

// Which of the interlude pictures the month calls for: "GAKU1" to "GAKU4".
const char *awardsPictureStem(int month);

void awardsOpen(Awards *awards, unsigned rank, const char *title,
                int year, int month, int day);
int awardsDismiss(Awards *awards);

// `behind` is the picture awardsPictureStem asked for, already loaded, or null
// - the citation still reads without it.
void awardsDraw(Surface *out, const Awards *awards, const Picture *behind,
                int x, int y);

#endif
