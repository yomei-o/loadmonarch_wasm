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

/* --------------------------------------------------------------- the parade */

// The fourteen walk scripts FUN_00411340 builds on its own stack, recovered
// with tools/walk_scripts.py.  A script is words: a command, and for most of
// them an argument.  00410200 reads them -
//
//   0, 2, 4, 6  face that way, and keep doing whatever is being done
//   0x0a .. 0x0d  move: left, right, down, up, for arg << 4 ticks
//   0x0f, 0x10  stand still for arg ticks
//   0x12, 0x13  fighting sprites, 0xa4 and 0xa0 over the side
//   0x14        one of the neutral country's, 0xc8 over the argument
//   0x15        stop for ever
//   0x16        nobody moves at all for arg ticks
//   0xff        this one is finished
//
// - and 004104d0 is what actually moves an actor, by its step, while its
// current command is one of 0x0a to 0x0d.
//
// The second word of every script is replaced by what FUN_00411340 is handed,
// which is how sixteen soldiers walking the same script set off one after
// another: the first command is the wait.
#define S_END 0xff
static const unsigned short kWalk[END_SCRIPTS][END_SCRIPT_MAX] = {
    /* 0  */ {0x0f, 0x01, 0x00, 0x0a, 0x07, 0xff},
    /* 1  */ {0x0f, 0x01, 0x00, 0x0a, 0x04, 0x16, 0x15e, 0x06, 0x04, 0x0b,
              0x04, 0xff},
    /* 2  */ {0x0f, 0x01, 0x04, 0x0b, 0x02, 0x10, 0x15e, 0x00, 0x0a, 0x02,
              0xff},
    /* 3  */ {0x0f, 0x01, 0x0a, 0x06, 0x12, 0x00, 0x12, 0x01, 0x12, 0x02,
              0x12, 0x03, 0x15, 0xff},
    /* 4  */ {0x0f, 0x01, 0x00, 0x0b, 0x01, 0x06, 0x0b, 0x01, 0x04, 0x0b,
              0x05, 0xff},
    /* 5  */ {0x0f, 0x01, 0x0a, 0x05, 0x10, 0x02, 0x13, 0x00, 0x13, 0x01,
              0x13, 0x02, 0x13, 0x03, 0x15, 0xff},
    /* 6  */ {0x0f, 0x01, 0x0a, 0x04, 0x10, 0x03, 0x13, 0x00, 0x13, 0x01,
              0x13, 0x02, 0x13, 0x03, 0x15, 0xff},
    /* 7  */ {0x0f, 0x01, 0x0a, 0x03, 0x10, 0x04, 0x13, 0x00, 0x13, 0x01,
              0x13, 0x02, 0x13, 0x03, 0x15, 0xff},
    /* 8  */ {0x0f, 0x01, 0x0a, 0x02, 0x10, 0x05, 0x13, 0x00, 0x13, 0x01,
              0x13, 0x02, 0x13, 0x03, 0x15, 0xff},
    /* 9  */ {0x0f, 0x01, 0x0a, 0x01, 0x10, 0x06, 0x13, 0x00, 0x13, 0x01,
              0x13, 0x02, 0x13, 0x03, 0x15, 0xff},
    /* 10 */ {0x0f, 0x01, 0x0a, 0x00, 0x10, 0x07, 0x13, 0x00, 0x13, 0x01,
              0x13, 0x02, 0x13, 0x03, 0x15, 0xff},
    /* 11 */ {0x0f, 0x01, 0x06, 0x15, 0xff},
    /* 12 */ {0x0f, 0x01, 0x00, 0x0a, 0x04, 0x10, 0x0a, 0x06, 0x04, 0x0b,
              0x04, 0xff},
    /* 13 */ {0x0f, 0x01, 0x0a, 0x05, 0x06, 0x04, 0x02, 0x00, 0x06, 0x04,
              0x02, 0x00, 0x06, 0x04, 0x02, 0x00, 0x06, 0x04, 0x0b, 0x05,
              0xff},
};

// FUN_00411340: one actor, with the script it is to walk and the wait that
// script's second word becomes.
static void actorStart(EndStage *end, int index, int script, int wait) {
    if (index < 0 || index >= END_ACTORS) return;
    if (script < 0 || script >= END_SCRIPTS) return;
    EndActor *a = &end->actor[index];
    memcpy(a->script, kWalk[script], sizeof a->script);
    a->script[1] = (unsigned short)wait;
    a->pc = 0;
    a->wait = 1;                        // +0x25c = 1: it steps at once
    a->alive = 1;
}

// 00410200: one step of one actor's script.
static void actorStep(EndStage *end, int index) {
    EndActor *a = &end->actor[index];
    if (a->pc < 0 || a->pc >= END_SCRIPT_MAX) { a->alive = 0; return; }
    const unsigned command = a->script[a->pc];
    const unsigned argument = a->pc + 1 < END_SCRIPT_MAX
        ? a->script[a->pc + 1] : 0;
    a->wait = 1;
    a->command = (unsigned char)command;

    switch (command) {
    case 0: case 2: case 4: case 6:
        a->facing = (signed char)command;
        a->pc += 1;
        return;
    case 0x0a: case 0x0b: case 0x0c: case 0x0d:
        a->wait = (int)(argument << 4);
        a->pc += 2;
        return;
    case 0x0f: case 0x10:
        a->wait = (int)argument;
        a->pc += 2;
        return;
    case 0x12:
        a->sprite = (unsigned char)((a->side * 8u + argument) | 0xa4u);
        a->pc += 2;
        return;
    case 0x13:
        a->sprite = (unsigned char)((a->side * 8u + argument) | 0xa0u);
        a->pc += 2;
        return;
    case 0x14:
        a->sprite = (unsigned char)(argument | 0xc8u);
        a->pc += 2;
        return;
    case 0x15:
        a->wait = -1;                   // and never again
        return;
    case 0x16:
        end->hold = (int)argument;      // +0x5838
        a->pc += 2;
        return;
    case S_END:
        a->alive = 0;
        a->pc += 1;
        return;
    default:
        a->pc += 1;
        return;
    }
}

// 004104d0's own half: an actor moves while its current command says to, and
// the sprite it is drawn as steps by one on alternate ticks while it moves.
static void actorMove(EndStage *end, EndActor *a) {
    if (end->hold) return;
    switch (a->command) {
    case 0x0a:
        if (a->x) { a->x -= a->step; if (a->x < 0) a->x = 0; }
        break;
    case 0x0b:
        if (a->x < 0x100) { a->x += a->step; if (a->x > 0xff) a->x = 0x100; }
        break;
    case 0x0c:
        if (a->y < 0x100) a->y += a->step;
        break;
    case 0x0d:
        // As 004104d0 has it: the same addition, and the step is what makes
        // the difference.
        if (a->y) a->y += a->step;
        break;
    default:
        break;
    }
}

static int actorMoving(const EndActor *a) {
    switch (a->command) {
    case 0: case 2: case 4: case 6: case 0x11:
    case 0x0a: case 0x0b: case 0x0c: case 0x0d:
        return 1;
    default:
        return 0;
    }
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

// The player's own soldiers, set up the way each scene sets them up.  The
// three that have one all start at 0xe0,0xd0 - the right-hand gate - with a
// step of two and the king at their head, and every soldier is given a wait
// of its own so they come through one at a time.
static void sceneActors(EndStage *end, unsigned side) {
    const unsigned char king = (unsigned char)((side | 0xcu) << 3);
    const unsigned char unit = (unsigned char)(side << 3);

    switch (end->mode) {
    case END_WON:
    case END_WON_AGAIN:
    case END_SINGLE_MAP: {
        // 00410680: the king on script 0, then fifteen soldiers on the same
        // one, at 0x20 apart.
        EndActor *a = &end->actor[0];
        a->x = 0xe0; a->y = 0xd0; a->step = 2;
        a->sprite = king; a->side = (unsigned char)side; a->facing = 0;
        actorStart(end, 0, 0, 1);
        int at = 0x20;
        for (int i = 1; at < 0x110 && i < END_ACTORS; i++, at += 0x10) {
            EndActor *b = &end->actor[i];
            b->x = 0xe0; b->y = 0xd0; b->step = 2;
            b->side = (unsigned char)side;
            b->sprite = unit;
            // 004106f8: three in ten are a large unit and three a medium one,
            // which is the same size bit 0041b520 packs into a sprite.
            const unsigned roll = simRandom(100);
            if (roll < 0x1e) b->sprite |= 0x40u;
            else if (roll < 0x3c) b->sprite |= 0x20u;
            actorStart(end, i, 0, at);
        }
        break;
    }
    case END_TIME_OVER: {
        // 00410910: the king walks off on script 1, one of the neutral
        // country's comes the other way on script 2, and the soldiers follow
        // on script 0x0c.
        EndActor *a = &end->actor[0];
        a->x = 0xe0; a->y = 0xd0; a->step = 2;
        a->sprite = king; a->side = (unsigned char)side;
        actorStart(end, 0, 1, 1);
        EndActor *w = &end->actor[16];
        w->x = 0; w->y = 0xd0; w->step = 1;
        w->sprite = 0xc0;
        w->side = 4;                    // 00410b0d: the neutral country
        actorStart(end, 16, 2, 0x16);
        int at = 0x20;
        for (int i = 1; at < 0x110 && i < 16; i++, at += 0x10) {
            EndActor *b = &end->actor[i];
            b->x = 0xe0; b->y = 0xd0; b->step = 2;
            b->side = (unsigned char)side;
            b->sprite = unit;
            const unsigned roll = simRandom(100);
            if (roll < 0x1e) b->sprite |= 0x40u;
            else if (roll < 0x3c) b->sprite |= 0x20u;
            actorStart(end, i, 0x0c, at);
        }
        break;
    }
    case END_DEFEATED: {
        // 00410be0: the king on script 3 - which is the fighting one - and
        // five soldiers on 5 to 9 (00410cbd hands out `ebx + 4` with the
        // index already 1), waiting 0x20 to 0x60.
        EndActor *a = &end->actor[0];
        a->x = 0xe0; a->y = 0xd0; a->step = 2;
        a->sprite = king; a->side = (unsigned char)side;
        actorStart(end, 0, 3, 1);
        int at = 0x20;
        for (int i = 1; at < 0x70 && i < END_ACTORS; i++, at += 0x10) {
            EndActor *b = &end->actor[i];
            b->x = 0xe0; b->y = 0xd0; b->step = 2;
            b->side = (unsigned char)side;
            b->sprite = unit;
            actorStart(end, i, i + 4, at);
        }
        break;
    }
    default:
        break;
    }
}

void endStageOpen(EndStage *end, int mode, const StageScore *score, int stage,
                  const char *name, int against, unsigned side) {
    memset(end, 0, sizeof *end);
    end->up = 1;
    end->mode = mode;
    end->stage = stage;
    end->score = *score;
    end->against = against;
    if (name) snprintf(end->name, sizeof end->name, "%s", name);
    sceneActors(end, side < 4 ? side : 0);
}

void endStageStep(EndStage *end) {
    if (!end->up) return;
    // 00410020 stops counting at a thousand, which is what stops the prompt
    // being drawn over and over.
    if (end->tick < 1000) end->tick++;

    // And then the parade, which is the rest of that routine: an actor that
    // is alive counts its wait down and takes its next step at nought, and
    // everything stands still while +0x5838 is counting.
    for (int i = 0; i < END_ACTORS; i++) {
        EndActor *a = &end->actor[i];
        if (!a->alive) continue;
        if (end->hold) {
            end->hold--;                // and this one does not move at all
        } else if (--a->wait == 0) {
            actorStep(end, i);
        }
        actorMove(end, a);
    }
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

    // The parade walks in the garden at the bottom, behind the two gate
    // towers 00410020 stamps back over it from the sheet at 0x2c000 and
    // 0x2c0e0 - which is why a soldier disappears into the gateway rather
    // than walking over it.
    const TileBank *bank = worldSprites(world, 2);
    for (int i = 0; i < END_ACTORS; i++) {
        const EndActor *a = &end->actor[i];
        if (!a->alive || !a->sprite) continue;
        // 00410627: an actor still standing on its opening wait is not drawn
        // at all.
        if (a->command == 0x0f) continue;
        unsigned number = (unsigned)a->sprite | (unsigned)a->facing;
        // 004105e3: while it is moving - and nothing moves while the hold is
        // on - the frame alternates with the tick.
        if (!end->hold && actorMoving(a) && (end->tick & 2)) number += 1;
        renderSprite(out, bank, number, x + a->x, y + a->y, 0);
    }
    for (int part = 0; part < 2; part++) {
        const int sx = part ? 224 : 0;
        if (!ui->pixels) break;
        for (int j = 0; j < 64; j++) {
            const int py = y + 192 + j;
            if (py < 0 || py >= out->height) continue;
            unsigned char *row = out->pixels + (size_t)py * out->width;
            for (int i = 0; i < 32; i++) {
                const int px = x + sx + i;
                if (px < 0 || px >= out->width) continue;
                const unsigned char v =
                    ui->pixels[(size_t)(END_SHEET_TOP + 192 + j) * UI_SHEET_W
                               + sx + i];
                if (v == UI_TRANSPARENT) continue;
                row[px] = v;
            }
        }
    }

    drawPanel(out, end, x, y);
    drawBalloon(out, end, x, y);
}
