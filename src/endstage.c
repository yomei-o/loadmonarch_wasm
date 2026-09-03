#include "endstage.h"

#include "font.h"
#include "ui.h"

#include <stdio.h>
#include <string.h>

// One 0040a870 call.  The colours are its own indices; see ui.h.
static void say(Surface *out, int x, int y, int ink, int shadow,
                const char *text) {
    uiTextOut(out, x, y, ink, shadow, text);
}

// The same, centred in the window: 00411050 passes 1 for its map line and sets
// the width DAT_004321e0 points at to 0x100.
static void sayMid(Surface *out, int left, int y, int ink, int shadow,
                   const char *text) {
    uiTextOutMid(out, left, END_W, y, ink, shadow, text);
}

void campaignClear(Campaign *campaign) {
    memset(campaign, 0, sizeof *campaign);
}

int campaignRecord(Campaign *campaign, int stage, const StageScore *score,
                   int *against) {
    if (against) *against = 0;
    if (stage < 0 || stage >= STAGE_MAX) return 0;
    // 0041b140 does nothing at all when DAT_00436404 is zero: a stage whose
    // clock has run out scores nothing and is not filed.
    if (score->remaining <= 0 || score->daysLeft == 0) return 0;

    const unsigned had = campaign->remaining[stage];
    // 0041b0e0: the difference the window shows is this run less the record.
    if (against && had) *against = (int)score->remaining - (int)had;
    // The record only moves when it is beaten, and the next map only opens the
    // first time through - DAT_0043643d is "there was a record already", and
    // 0041b140 returns without touching either when this run did not beat it.
    if (had && (unsigned)score->remaining <= had) return 0;
    if (!had && campaign->reached <= stage) campaign->reached = stage + 1;
    campaign->remaining[stage] = (unsigned)score->remaining;
    return 1;
}

unsigned campaignRank(const Campaign *campaign) {
    // 0041f6c0 walks 0 to DAT_00436a00 inclusive, so the stage it has just
    // opened counts even though it has no record yet - which is nought, and
    // changes nothing.
    unsigned best = 0;
    for (int i = 0; i <= campaign->reached && i < STAGE_MAX; i++)
        if (campaign->remaining[i] > best) best = campaign->remaining[i];
    if (best >= 100000u) return 0x13;
    if (best < 10000u) return best / 1000u;
    return best / 10000u + 9u;
}

int endStageMode(int outcome, const StageScore *score, const Campaign *campaign,
                 int stage, int quest) {
    // The order is 0041f4c0's own, and it is not the order a reader would
    // choose: each test overwrites the one before, so being knocked out wins
    // over everything and a single map over the clock.
    int mode = END_WON;
    if (score->daysLeft == 0) mode = END_TIME_OVER;
    else if (campaign && stage >= 0 && stage < STAGE_MAX &&
             campaign->remaining[stage]) mode = END_WON_AGAIN;
    if (!quest) mode = END_SINGLE_MAP;
    if (outcome == 2) mode = END_DEFEATED;
    return mode;
}

int endStageReplays(int mode) {
    return mode == END_DEFEATED || mode == END_TIME_OVER;
}

void endStageOpen(EndStage *end, int mode, const StageScore *score, int stage,
                  const char *name, int against) {
    memset(end, 0, sizeof *end);
    end->up = 1;
    end->mode = mode;
    end->stage = stage;
    end->score = *score;
    end->against = against;
    if (name) snprintf(end->name, sizeof end->name, "%s", name);
}

void endStageStep(EndStage *end) {
    // 00410020 stops counting at a thousand, which is what stops the prompt
    // being drawn over and over.
    if (end->up && end->tick < 1000) end->tick++;
}

int endStageDismiss(EndStage *end) {
    if (!end->up) return 0;
    end->up = 0;
    return 1;
}

/* --------------------------------------------------------------- the scenes */

// A per-cent with two decimals, which is what "%3.2f" gives.  Done by hand
// rather than with %f so the port does not depend on a float printf.
static void percent(char *out, size_t size, float value) {
    int whole = (int)value;
    int frac = (int)((value - (float)whole) * 100.0f + 0.5f);
    if (frac > 99) frac = 99;
    if (whole < 0) { whole = 0; frac = 0; }
    snprintf(out, size, "%3d.%02d", whole, frac);
}

// The framed panel under the balloon - the arithmetic, which stands whatever
// the balloon is saying.
static void drawPanel(Surface *out, const EndStage *end, int x, int y) {
    char line[64], num[16];
    const StageScore *s = &end->score;

    if (end->mode == END_DEFEATED) {
        say(out, x + 0x52, y + 0x6e, 2, 3, "Game Over");
        return;
    }

    snprintf(line, sizeof line, "Map%d   %s", end->stage + 1, end->name);
    if (end->mode == END_SINGLE_MAP) sayMid(out, x, y + 0x49, 2, 3, line);
    else                            say(out, x + 0x16, y + 0x49, 2, 3, line);

    if (end->mode == END_SINGLE_MAP) {
        snprintf(line, sizeof line, "Area(P/E)    %6u/%6u", s->held,
                 s->claimable > s->held ? s->claimable - s->held : 0u);
        say(out, x + 0x16, y + 0x5f, 2, 3, line);
        percent(num, sizeof num, s->areaPercent);
        snprintf(line, sizeof line, "Area            %s Per.", num);
        say(out, x + 0x16, y + 0x6e, 2, 3, line);
        if (s->daysLeft == 0) {
            say(out, x + 0x16, y + 0x7d, 4, 5, "Penalty           no count");
        } else {
            snprintf(line, sizeof line, "Penalty        %6d days",
                     -(int)s->penalty);
            say(out, x + 0x16, y + 0x7d, 4, 5, line);
        }
        snprintf(line, sizeof line, "Losses       %6u/%6u", s->yourLosses,
                 s->enemyLosses);
        say(out, x + 0x16, y + 0x8f, 2, 3, line);
        percent(num, sizeof num, s->battlePercent);
        snprintf(line, sizeof line, "Battle effic    %s Per", num);
        say(out, x + 0x16, y + 0x9e, 2, 3, line);
        snprintf(line, sizeof line, "Bonus          %6u days", s->bonus);
        say(out, x + 0x16, y + 0xad, 2, 3, line);
        return;
    }

    percent(num, sizeof num, s->areaPercent);
    snprintf(line, sizeof line, "Area            %s Per.", num);
    say(out, x + 0x16, y + 0x5f, 2, 3, line);
    snprintf(line, sizeof line, "Remaining      %6u days", s->daysLeft);
    say(out, x + 0x16, y + 0x6e, 2, 3, line);

    if (end->mode == END_TIME_OVER) {
        // 00410910: no bonus is counted for a stage the clock beat, and the
        // panel says so in words rather than showing a nought.
        say(out, x + 0x16, y + 0x7d, 2, 3, "Bonus             no count");
        say(out, x + 0x16, y + 0x8c, 4, 5, "Penalty           no count");
        return;
    }

    snprintf(line, sizeof line, "Bonus          %6u days", s->bonus);
    say(out, x + 0x16, y + 0x7d, 2, 3, line);
    // 004107d0 negates it before printing: a penalty reads as days lost.
    snprintf(line, sizeof line, "Penalty        %6d days", -(int)s->penalty);
    say(out, x + 0x16, y + 0x8c, 4, 5, line);
    if (end->tick >= 0x14) {
        snprintf(line, sizeof line, "Total bonus    %6d days", s->remaining);
        say(out, x + 0x16, y + 0xaa, 2, 3, line);
    }
}

// The balloon.  Three things can be in it, and each one wipes what was there
// before it with 0040ffe0: the mode's own heading, then in mode 3 what this
// run did to the record, and from tick 400 the invitation to click.
static void drawBalloon(Surface *out, const EndStage *end, int x, int y) {
    if (end->tick >= END_PROMPT) {
        say(out, x + 0x0e, y + 0x14, 6, 7, "  Click here");
        say(out, x + 0x0e, y + 0x28, 6, 7, "       to go on!");
        return;
    }

    // 00410d00: between these two ticks the balloon belongs to the record.  A
    // gain flashes - 00410f5f puts it in the heading's grey on odd ticks and
    // in the penalty's red on even ones - and a loss is red throughout.
    if (end->mode == END_WON_AGAIN && end->against != 0 &&
        end->tick >= 0x14 && end->tick <= 0x50) {
        char line[64];
        int ink = 4, shadow = 5;
        if (end->against < 0) {
            snprintf(line, sizeof line, "You lose %d days!", -end->against);
        } else {
            snprintf(line, sizeof line, "You gain %d days!", end->against);
            if (end->tick & 1) { ink = 6; shadow = 7; }
        }
        say(out, x + 0x16, y + 0x1e, ink, shadow, line);
        return;
    }

    switch (end->mode) {
    case END_TIME_OVER:
        say(out, x + 0x16, y + 0x0f, 6, 7, "Bravo! you win!");
        say(out, x + 0x16, y + 0x1d, 6, 7, "But day's over");
        say(out, x + 0x16, y + 0x2b, 6, 7, "Please try again..");
        break;
    case END_DEFEATED:
        say(out, x + 0x16, y + 0x14, 6, 7, "You have be defeated");
        say(out, x + 0x16, y + 0x23, 6, 7, "Please try again..");
        break;
    case END_SINGLE_MAP:
        say(out, x + 0x16, y + 0x14, 6, 7, "Single map mode");
        say(out, x + 0x16, y + 0x23, 6, 7, "Please try again..");
        break;
    default:
        say(out, x + 0x16, y + 0x14, 6, 7, "Bravo! you win!");
        say(out, x + 0x16, y + 0x23, 6, 7, "Go to the next stage");
        break;
    }
}

void endStageDraw(Surface *out, const EndStage *end, const World *world,
                  int x, int y) {
    if (!end->up) return;

    // 0040fca0's own loop: 256 rows of 256 pixels straight out of the sheet at
    // 0x20000, which is row 512 - a yellow speech balloon over a framed brown
    // panel over a walled garden.  Opaque: it is a window, and the board does
    // not show through a window.
    const UiSheet *ui = &world->ui;
    for (int j = 0; j < END_H; j++) {
        const int py = y + j;
        if (py < 0 || py >= out->height) continue;
        unsigned char *row = out->pixels + (size_t)py * out->width;
        for (int i = 0; i < END_W; i++) {
            const int px = x + i;
            if (px < 0 || px >= out->width) continue;
            row[px] = ui->pixels
                ? ui->pixels[(size_t)(END_SHEET_TOP + j) * UI_SHEET_W + i]
                : (unsigned char)UI_FACE;
        }
    }

    drawPanel(out, end, x, y);
    drawBalloon(out, end, x, y);
}
