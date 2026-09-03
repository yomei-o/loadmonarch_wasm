// Dialog 105 and the campaign behind it - 0041f4c0's five modes, 0041b140's
// record, and what the window puts on the screen.
//
//   tests/endstage_test.exe [zip]
//
// The window is checked by drawing it and reading the surface back: the
// background has to be the sheet's own rows and the headings have to land in
// the balloon, which is the one thing a test can say about text it cannot
// read.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/endstage.h"
#include "../src/ui.h"
#include "../src/host.h"
#include "../src/render.h"
#include "../src/world.h"
#include "../src/zip.h"

static int failures;

static void check(int ok, const char *what) {
    if (!ok) {
        printf("FAIL  %s\n", what);
        failures++;
    }
}

static void checkf(int ok, const char *fmt, int a, int b) {
    if (!ok) {
        printf("FAIL  ");
        printf(fmt, a, b);
        printf("\n");
        failures++;
    }
}

// How many pixels of one colour a line of text put down: the whole sixteen
// rows of its band, because any single row through a short string can be
// nearly empty.
static int bandw(const Surface *s, int x, int y, int w, unsigned char ink) {
    int n = 0;
    for (int j = 0; j < 16 && y + j < s->height; j++)
        for (int i = 0; i < w && x + i < s->width; i++)
            if (s->pixels[(size_t)(y + j) * s->width + x + i] == ink) n++;
    return n;
}

static int band(const Surface *s, int x, int y, unsigned char ink) {
    return bandw(s, x, y, 256, ink);
}

int main(int argc, char **argv) {
    static Campaign camp;
    StageScore score;
    int against = 0;

    /* ------------------------------------------------- 0041f4c0's five modes */
    campaignClear(&camp);
    memset(&score, 0, sizeof score);
    score.daysLeft = 120;
    score.remaining = 300;

    checkf(endStageMode(1, &score, &camp, 0, 1) == END_WON,
           "a first win in the campaign is mode %d, not %d",
           endStageMode(1, &score, &camp, 0, 1), END_WON);
    checkf(endStageMode(1, &score, &camp, 0, 0) == END_SINGLE_MAP,
           "the same win off the campaign is mode %d, not %d",
           endStageMode(1, &score, &camp, 0, 0), END_SINGLE_MAP);
    checkf(endStageMode(2, &score, &camp, 0, 1) == END_DEFEATED,
           "being knocked out is mode %d, not %d",
           endStageMode(2, &score, &camp, 0, 1), END_DEFEATED);
    {
        StageScore over = score;
        over.daysLeft = 0;
        checkf(endStageMode(1, &over, &camp, 0, 1) == END_TIME_OVER,
               "a win with the clock gone is mode %d, not %d",
               endStageMode(1, &over, &camp, 0, 1), END_TIME_OVER);
        // 0041f4c0 tests the human's own flag last, so it wins.
        checkf(endStageMode(2, &over, &camp, 0, 1) == END_DEFEATED,
               "and being out still beats it: mode %d, not %d",
               endStageMode(2, &over, &camp, 0, 1), END_DEFEATED);
        // And a single map beats the clock, being tested after it.
        checkf(endStageMode(1, &over, &camp, 0, 0) == END_SINGLE_MAP,
               "a single map beats the clock: mode %d, not %d",
               endStageMode(1, &over, &camp, 0, 0), END_SINGLE_MAP);
    }

    /* ------------------------------------------------------------ 0041b140 */
    check(campaignRecord(&camp, 0, &score, &against),
          "the first win is filed");
    checkf(camp.reached == 1, "one stage is open, not %d", camp.reached, 1);
    checkf(camp.remaining[0] == 300, "the record is %d, not %d",
           (int)camp.remaining[0], 300);
    check(against == 0, "and there was nothing to beat");

    // Now the stage is one the campaign has seen.
    checkf(endStageMode(1, &score, &camp, 0, 1) == END_WON_AGAIN,
           "a second win is mode %d, not %d",
           endStageMode(1, &score, &camp, 0, 1), END_WON_AGAIN);

    // A worse run does not move the record, and does not open a map either.
    {
        StageScore worse = score;
        worse.remaining = 200;
        check(!campaignRecord(&camp, 0, &worse, &against),
              "a worse run is not filed");
        checkf(against == -100, "it is a hundred days short, not %d",
               against, -100);
        checkf(camp.reached == 1, "and no map opened: %d, not %d",
               camp.reached, 1);
    }
    // A better one moves it, and still opens nothing - the stage was already
    // cleared once.
    {
        StageScore better = score;
        better.remaining = 400;
        check(campaignRecord(&camp, 0, &better, &against),
              "a better run is filed");
        checkf(against == 100, "a hundred days gained, not %d", against, 100);
        checkf(camp.remaining[0] == 400, "the record is now %d, not %d",
               (int)camp.remaining[0], 400);
        checkf(camp.reached == 1, "still one map open, not %d",
               camp.reached, 1);
    }
    // Clearing the next one opens the one after it.
    check(campaignRecord(&camp, 1, &score, &against), "stage 2 is filed");
    checkf(camp.reached == 2, "two stages open, not %d", camp.reached, 2);
    // A stage won on its last day is worth nothing and is not filed at all.
    {
        StageScore none = score;
        none.daysLeft = 0;
        none.remaining = 0;
        check(!campaignRecord(&camp, 5, &none, &against),
              "a stage the clock beat is not filed");
        checkf(camp.reached == 2, "and opens nothing: %d, not %d",
               camp.reached, 2);
    }

    /* ------------------------------------------------- what it puts on screen */
    check(endStageReplays(END_DEFEATED) && endStageReplays(END_TIME_OVER),
          "a loss and a time-out play the stage again");
    check(!endStageReplays(END_WON) && !endStageReplays(END_WON_AGAIN) &&
          !endStageReplays(END_SINGLE_MAP),
          "and a win does not");

    static Host host;
    const char *archive = argc > 1 ? argv[1] : "ds7e.zip";
    FILE *f = fopen(archive, "rb");
    if (!f) {
        printf("FAIL  cannot open %s\n", archive);
        return 1;
    }
    fseek(f, 0, SEEK_END);
    long length = ftell(f);
    fseek(f, 0, SEEK_SET);
    unsigned char *bytes = (unsigned char *)malloc((size_t)length);
    if (!bytes || fread(bytes, 1, (size_t)length, f) != (size_t)length) {
        printf("FAIL  cannot read %s\n", archive);
        return 1;
    }
    fclose(f);
    if (!hostUseZip(&host, bytes, (unsigned)length)) {
        printf("FAIL  %s is not a zip this port can read\n", archive);
        return 1;
    }

    static World world;
    char message[128];
    if (!worldLoadStage(&world, &host, "B_000.MAP", message, sizeof message)) {
        printf("FAIL  B_000.MAP: %s\n", message);
        return 1;
    }
    check(world.ui.pixels != NULL, "the interface sheet is loaded");

    static Surface surface;
    static unsigned char pixels[400 * 400];
    surfaceInit(&surface, 400, 400, pixels);

    static EndStage end;
    endStageOpen(&end, END_WON, &score, 0, "Conqueror's trial", 0);
    check(end.up, "the window is up");
    memset(surface.pixels, 0, (size_t)surface.width * surface.height);
    endStageDraw(&surface, &end, &world, 20, 20);

    // The background is the sheet, row for row.  One pixel of the garden - the
    // bottom band, which no text is written over - settles it.
    {
        const unsigned char want =
            world.ui.pixels[(size_t)(END_SHEET_TOP + 250) * UI_SHEET_W + 128];
        const unsigned char got =
            surface.pixels[(size_t)(20 + 250) * surface.width + 20 + 128];
        checkf(got == want, "the garden pixel is %02x, not the sheet's %02x",
               got, want);
    }
    // And nothing was drawn outside it.
    checkf(surface.pixels[0] == 0, "the corner outside the window is %02x",
           surface.pixels[0], 0);

    // The heading lands in the balloon: the row through y = 0x14 + 8 has to
    // carry the heading's grey, and the panel's rows the numbers' white.
    {
        const int grey = band(&surface, 20, 20 + 0x14, UI_END_GREY);
        const int white = band(&surface, 20, 20 + 0x6e, UI_LIGHT);
        const int red = band(&surface, 20, 20 + 0x8c, UI_END_RED);
        checkf(grey > 60, "the heading has %d grey pixels, wanted over %d",
               grey, 60);
        checkf(white > 60, "the numbers have %d white pixels, over %d",
               white, 60);
        checkf(red > 60, "the penalty has %d red pixels, over %d", red, 60);
        checkf(bandw(&surface, 20 + 0x16, 20 + 0x14, 8, UI_END_GREY) > 0,
               "the heading's first letter is missing: %d pixels, wanted over "
               "%d", bandw(&surface, 20 + 0x16, 20 + 0x14, 8, UI_END_GREY), 0);
    }

    // The prompt takes the balloon over at tick 400, and the heading goes.
    for (int i = 0; i < END_PROMPT; i++) endStageStep(&end);
    checkf(end.tick == END_PROMPT, "the counter is at %d, not %d", end.tick,
           END_PROMPT);
    {
        memset(surface.pixels, 0, (size_t)surface.width * surface.height);
        endStageDraw(&surface, &end, &world, 20, 20);
        const int prompt = band(&surface, 20, 20 + 0x28, UI_END_GREY);
        checkf(prompt > 40, "the second prompt line has %d pixels, over %d",
               prompt, 40);
        // 00410020 wipes the balloon with 0040ffe0 before it writes the
        // prompt, so the heading is not under it any more.  The prompt's own
        // first line starts with two spaces where "Bravo!" starts with a B,
        // so the eight pixels at the heading's left edge say which is up.
        checkf(bandw(&surface, 20 + 0x16, 20 + 0x14, 8, UI_END_GREY) == 0,
               "the heading is still there: %d pixels at its B, wanted %d",
               bandw(&surface, 20 + 0x16, 20 + 0x14, 8, UI_END_GREY), 0);
    }

    // A click closes it, whenever it comes - 0040ea50's jump table sends this
    // dialog's left button up straight to its close.
    check(endStageDismiss(&end), "a click dismisses it");
    check(!end.up, "and it is gone");
    check(!endStageDismiss(&end), "a second click does nothing");
    memset(surface.pixels, 0, (size_t)surface.width * surface.height);
    endStageDraw(&surface, &end, &world, 20, 20);
    check(surface.pixels[(size_t)(20 + 250) * surface.width + 20 + 128] == 0,
          "a dismissed window draws nothing");

    // Mode 2 has no numbers at all, only "Game Over" in the panel.
    endStageOpen(&end, END_DEFEATED, &score, 0, "Conqueror's trial", 0);
    memset(surface.pixels, 0, (size_t)surface.width * surface.height);
    endStageDraw(&surface, &end, &world, 20, 20);
    {
        const int white = band(&surface, 20, 20 + 0x6e, UI_LIGHT);
        checkf(white > 30, "Game Over has %d white pixels, over %d",
               white, 30);
    }

    if (failures) {
        printf("%d failure(s)\n", failures);
        return 1;
    }
    printf("endstage checks ok\n");
    return 0;
}
