#include "awards.h"

#include "ui.h"

#include <stdio.h>
#include <string.h>

// DS:0x433480's twenty, in its own order: index nought is nobody, then the
// classes count down to one and the degrees count up, and the top is Master.
static const char *kRank[20] = {
    "Class -", "Class 9", "Class 8", "Class 7", "Class 6", "Class 5",
    "Class 4", "Class 3", "Class 2", "Class 1",
    "First Degree", "Degree 2", "Degree 3", "Degree 4", "Degree 5",
    "Degree 6", "Degree 7", "Degree 8", "Degree 9", "Master"
};

const char *awardsRankName(unsigned rank) {
    return rank < 20 ? kRank[rank] : kRank[19];
}

const char *awardsPictureStem(int month) {
    // 004121c8: wMonth - 1, and anything outside one to twelve becomes
    // nought.  The twelve entries group into the seasons.
    static const char *kByMonth[12] = {
        "GAKU4", "GAKU4",                    // January, February
        "GAKU1", "GAKU1", "GAKU1",           // March to May
        "GAKU2", "GAKU2", "GAKU2",           // June to August
        "GAKU3", "GAKU3", "GAKU3",           // September to November
        "GAKU4"                              // December
    };
    const int at = month - 1;
    return kByMonth[at >= 0 && at < 12 ? at : 0];
}

void awardsOpen(Awards *awards, unsigned rank, const char *title,
                int year, int month, int day) {
    memset(awards, 0, sizeof *awards);
    awards->up = 1;
    awards->rank = rank;
    awards->year = year;
    awards->month = month;
    awards->day = day;
    snprintf(awards->title, sizeof awards->title, "%s",
             title && title[0] ? title : "Lord Monarch");
}

int awardsDismiss(Awards *awards) {
    if (!awards->up) return 0;
    awards->up = 0;
    return 1;
}

void awardsDraw(Surface *out, const Awards *awards, const Picture *behind,
                int x, int y) {
    if (!awards->up) return;
    (void)behind;               // the host puts it there; see wasm_main.cpp

    // Thirteen lines, every one centred in the window and every one at x 40 in
    // 004120c0's own calls - which is what 0040a870 ignores when its centring
    // flag is set, and every call here sets it.  The pair of colours is 10 and
    // 11: black, with the shadow in white.
    const char *rank = awardsRankName(awards->rank);
    char line[64];
    struct { int y; const char *text; } row[13];
    int n = 0;

    row[n].y = 0x30; row[n++].text = "Awords";
    row[n].y = 0x42; row[n++].text = awards->title;
    row[n].y = 0x52; row[n++].text = rank;
    row[n].y = 0x6a; row[n++].text = "You have brilliantly";
    row[n].y = 0x7a; row[n++].text = "fulfilled your duties in ";
    static char inTitle[48];
    snprintf(inTitle, sizeof inTitle, "%s and to", awards->title);
    row[n].y = 0x8a; row[n++].text = inTitle;
    row[n].y = 0x9a; row[n++].text = "certify your achievements";
    row[n].y = 0xaa; row[n++].text = "we hereby award with the ";
    static char rankOf[48];
    snprintf(rankOf, sizeof rankOf, "rank of %s", rank);
    row[n].y = 0xba; row[n++].text = rankOf;
    row[n].y = 0xdc; row[n++].text = "Nihon Falcom Corporation.";
    row[n].y = 0xec; row[n++].text = "The Lord Monarch Awards";
    snprintf(line, sizeof line, "Committee. %d/%d/%d", awards->year,
             awards->month, awards->day);
    row[n].y = 0xfc; row[n++].text = line;

    for (int i = 0; i < n; i++)
        uiTextOutMid(out, x, AWARD_W, y + row[i].y, 10, 11, row[i].text);
}
