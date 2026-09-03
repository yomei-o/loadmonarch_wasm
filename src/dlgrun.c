#include "dlgload.h"
#include "dlgrun.h"

#include "font.h"
#include "ui.h"
#include "world.h"

#include <stdio.h>
#include <string.h>

// The seven orders the original's Default Orders menu offers, which is the
// table at 0x434444 read out of the executable.
static const unsigned char kDefaultOrderList[7] = {1, 4, 5, 8, 9, 0x0b, 0};

void dlgRunInit(DlgRunner *r, Sim *sim, const DlgHost *host) {
    memset(r, 0, sizeof *r);
    r->sim = sim;
    r->host = host;
    r->which = DLG_NONE;
    r->allyPick = -1;
}

int dlgRunUp(const DlgRunner *r) {
    return r->which != DLG_NONE && dlgIsOpen(&r->dlg);
}

DlgWhich dlgForCommand(int command) {
    switch (command) {
    case 40038: return DLG_DEFAULT_ORDERS;      // Orders / Default Orders
    case 40055: return DLG_VERSION;             // Help / Version
    case 40033: return DLG_SYSTEM_SETTING;      // Controls / System Setting
    case 40051: return DLG_LOAD;                // System / Load
    case 40021: return DLG_SAVE;                // System / Save
    case 40020: return DLG_LOAD_QUEST_MAP;      // System / Load Quest Map
    case 40117: return DLG_LOAD_SINGLE_MAP;     // System / Load Single Map
    case 40012: return DLG_ALLIANCE;            // Controls / Alliance Setting
    case 40116: return DLG_SOUND_SETTING;       // Controls / Sound Setting
    case 40067: return DLG_CUSTOM_SOUNDS;       // and the long form of it
    case 40037: return DLG_HELP;                // Help / Quick Rules
    default: return DLG_NONE;
    }
}

/* ------------------------------------------------------------- filling in */

// slotName answers zero for a slot with nothing in it, which is how Save New
// knows where to put one.
static void fillSlots(DlgRunner *r) {
    dlgClearItems(&r->dlg);
    r->firstEmpty = -1;
    if (!r->host || !r->host->slotName) return;
    char name[DLG_ITEM_TEXT], row[DLG_ITEM_TEXT];
    for (int i = 0; i < r->host->slots && i < DLG_ITEMS_MAX; i++) {
        if (r->host->slotName(r->host->user, i, name, sizeof name)) {
            snprintf(row, sizeof row, "%d. %s", i + 1, name);
        } else {
            snprintf(row, sizeof row, "%d. -", i + 1);
            if (r->firstEmpty < 0) r->firstEmpty = i;
        }
        dlgAddItem(&r->dlg, row);
    }
}

static void fillStages(DlgRunner *r) {
    dlgClearItems(&r->dlg);
    r->stageCount = 0;
    if (!r->host || !r->host->stageName) return;
    for (int i = 0; i < r->host->stages && i < DLG_ITEMS_MAX; i++) {
        char row[DLG_ITEM_TEXT];
        char name[DLG_ITEM_TEXT];
        if (!r->host->stageName(r->host->user, i, name, sizeof name)) continue;
        snprintf(row, sizeof row, "%2d %s", i + 1, name);
        dlgAddItem(&r->dlg, row);
        r->stageCount++;
    }
}

static void fillDefaultOrders(DlgRunner *r) {
    // Two combos: which order, then what to do when it is done.  The words are
    // the game's own - order name one is "Auto" and order name zero is "Take
    // Break", which is exactly how 00423940 labels the three rows.
    dlgClearItems(&r->dlg);
    dlgClearItems2(&r->dlg);
    const World *w = &r->sim->state->world;
    for (int i = 0; i < 7; i++)
        dlgAddItem(&r->dlg, worldOrderName(w, kDefaultOrderList[i]));
    // And what to do when the work is done, in the game's own words: order
    // name one is Auto, order name zero is Take Break, and the third is the
    // order itself with "continue" after it.
    dlgAddItem2(&r->dlg, worldOrderName(w, 1));
    dlgAddItem2(&r->dlg, worldOrderName(w, 0));
    dlgAddItem2(&r->dlg, "continue");

    const unsigned pending = r->sim->pendingOrder;
    int which = 0;
    for (int i = 0; i < 7; i++)
        if (kDefaultOrderList[i] == (pending & 0x0f)) which = i;
    dlgSetValue(&r->dlg, 1125, which);
    dlgSetValue(&r->dlg, 1126,
                (pending & 0x80) ? 2 : (pending & 0x40) ? 1 : 0);
}

// 00413f90 fills the Help combo with six topics of its own and then twelve
// of the game's order names - eighteen, one a page, which is exactly how many
// pages .data holds.
#define HELP_TOPICS 6
#define HELP_ORDERS 12

// What the port had before it could read the game's own: four pages of its
// own words, kept for an archive whose executable will not read.
static const char *kHelpTopics[4] = {
    "Game Screen", "Giving an order", "Roads and bridges", "Winning"
};

/* ------------------------------------------------------------------ open */

// What a dialog is filled with when it opens: its lists, its values, and
// the controls the program greys rather than the resource.  Split out of
// dlgRunOpen so the template can come from either place.
static void dlgRunFurnish(DlgRunner *r, DlgWhich which) {
    r->which = which;
    r->allyPick = -1;

    switch (which) {
    case DLG_DEFAULT_ORDERS:
        fillDefaultOrders(r);
        break;
    case DLG_LOAD:
    case DLG_SAVE:
        fillSlots(r);
        // 106 and 107 keep Save, Delete and Load greyed until a row is picked,
        // which is what the resource's DISABLED bits say.
        dlgEnable(&r->dlg, 1019, 0);
        dlgEnable(&r->dlg, 1020, 0);
        dlgEnable(&r->dlg, 1110, 0);
        break;
    case DLG_LOAD_SINGLE_MAP:
    case DLG_LOAD_QUEST_MAP:
        fillStages(r);
        // The resource has Awards disabled; it is the program that turns it
        // on, and there is nothing to award until a stage has been cleared.
        dlgEnable(&r->dlg, 1188,
                  r->host && r->host->campaignRank
                      ? r->host->campaignRank(r->host->user) > 0 : 0);
        break;
    case DLG_CUSTOM_SOUNDS:
        dlgClearItems(&r->dlg);
        if (r->host && r->host->tuneName) {
            char name[DLG_ITEM_TEXT];
            for (int i = 0; i < r->host->tunes && i < DLG_ITEMS_MAX; i++)
                if (r->host->tuneName(r->host->user, i, name, sizeof name))
                    dlgAddItem(&r->dlg, name);
        }
        dlgSetValue(&r->dlg, 1128, 1);          // MIDI, which is what there is
        dlgEnable(&r->dlg, 1130, 0);            // no CD
        dlgEnable(&r->dlg, 1133, 0);
        dlgEnable(&r->dlg, 1137, 0);
        // The release ships no WAVE files at all, so the whole of the lower
        // half has nothing to work on.
        dlgEnable(&r->dlg, 1020, 0);
        dlgEnable(&r->dlg, 1090, 0);
        dlgEnable(&r->dlg, 1091, 0);
        dlgEnable(&r->dlg, 1132, 0);
        dlgEnable(&r->dlg, 1135, 0);
        dlgEnable(&r->dlg, 1134, 0);
        dlgEnable(&r->dlg, 1192, 0);
        dlgEnable(&r->dlg, 1194, 0);
        dlgEnable(&r->dlg, 10, 0);
        break;
    case DLG_SYSTEM_SETTING:
        if (r->host && r->host->getWindow) {
            dlgSetValue(&r->dlg, 1067, r->host->getWindow(r->host->user, 0));
            dlgSetValue(&r->dlg, 1068, r->host->getWindow(r->host->user, 1));
            dlgSetValue(&r->dlg, 1070, r->host->getWindow(r->host->user, 2));
        }
        if (r->host && r->host->getSpeed) {
            // The trackbar runs left to right as the label says: Fast is at
            // the right, and the game's own number is 0 slow to 29 fast.
            const int speed = r->host->getSpeed(r->host->user);
            dlgSetValue(&r->dlg, 1118, speed * 100 / 30);
        }
        dlgSetValue(&r->dlg, 1114, r->sim->state->showOrders);
        break;
    case DLG_ALLIANCE: {
        // 00413390: a country bigger than the player cannot be asked, and
        // Reset only works when there is an alliance to undo.
        const GameState *g = r->sim->state;
        const unsigned me = r->sim->humanFaction;
        static const int setId[3] = {1095, 1096, 1097};
        int n = 0;
        for (unsigned f = 0; f < PLAYABLE_FACTIONS && n < 3; f++) {
            if (f == me) continue;
            const int bigger = me < PLAYABLE_FACTIONS &&
                               g->factions[me].at2c < g->factions[f].at2c;
            dlgEnable(&r->dlg, setId[n], !bigger);
            n++;
        }
        dlgEnable(&r->dlg, 1074,
                  me < PLAYABLE_FACTIONS && g->factions[me].at1e != 0x80);
        break;
    }
    case DLG_SOUND_SETTING:
        dlgSetValue(&r->dlg, 1089, 1);          // BGM on
        dlgSetValue(&r->dlg, 1190, 1);          // and it is MIDI, not CD
        dlgEnable(&r->dlg, 1090, 0);            // no sound effects exist
        dlgEnable(&r->dlg, 1175, 0);            // nor any voice
        dlgEnable(&r->dlg, 1189, 0);            // and no CD to play
        dlgEnable(&r->dlg, 10, 0);
        dlgEnable(&r->dlg, 3, 0);
        break;
    case DLG_INFORMATION: {
        int chosen = 0;
        for (int i = 0; i < ENTITY_COUNT; i++)
            if (r->sim->state->entities[i].flags21c & 1) chosen++;
        // 00412ff0 enables the two Remainder buttons only when more than one
        // unit was picked; on its own there is no remainder to speak of.
        dlgEnable(&r->dlg, 3, chosen > 1);
        dlgEnable(&r->dlg, 4, chosen > 1);
        r->askKind = r->sim->askKind;
        r->askUnit = r->sim->askUnit;
        break;
    }
    case DLG_HELP:
        // The resource leaves "Static" in 1123 - Visual Studio's own
        // placeholder - and 004145c0 writes the page over it.
        dlgSetText(&r->dlg, 1123, "");
        dlgClearItems(&r->dlg);
        // 00413f90 fills the combo with six topics of its own and then twelve
        // of the game's order names, which is eighteen - one a page.
        if (dlgHelpPages() >= HELP_TOPICS + HELP_ORDERS) {
            for (int i = 0; i < HELP_TOPICS; i++)
                dlgAddItem(&r->dlg, dlgHelpTopic(i));
            for (int i = 0; i < HELP_ORDERS; i++)
                dlgAddItem(&r->dlg,
                           worldOrderName(&r->sim->state->world, (unsigned)i));
        } else {
            // Nothing was read, so the port's own four stand.
            for (int i = 0; i < 4; i++) dlgAddItem(&r->dlg, kHelpTopics[i]);
        }
        dlgSetValue(&r->dlg, 1122, 0);
        dlgEnable(&r->dlg, 1120, 0);
        break;
    default:
        break;
    }
}

int dlgRunOpen(DlgRunner *r, DlgWhich which, int surfaceW, int surfaceH) {
    // Whatever the loaded release has for it, and dlgdefs.c - the English
    // release, transcribed - where there is nothing to read.  See dlgload.c.
    const DlgTemplate *tpl = dlgLoaded(which);
    if (tpl) {
        dlgOpen(&r->dlg, tpl, surfaceW, surfaceH);
        dlgRunFurnish(r, which);
        return 1;
    }
    switch (which) {
    case DLG_DEFAULT_ORDERS:   tpl = &kDlgDefaultOrders; break;
    case DLG_VERSION:          tpl = &kDlgVersion; break;
    case DLG_INFORMATION:      tpl = &kDlgInformation; break;
    case DLG_SYSTEM_SETTING:   tpl = &kDlgSystemSetting; break;
    case DLG_LOAD:             tpl = &kDlgLoad; break;
    case DLG_SAVE:             tpl = &kDlgSave; break;
    case DLG_LOAD_SINGLE_MAP:  tpl = &kDlgLoadSingleMap; break;
    case DLG_ALLIANCE:         tpl = &kDlgAlliance; break;
    case DLG_SOUND_SETTING:    tpl = &kDlgSoundSetting; break;
    case DLG_HELP:             tpl = &kDlgHelp; break;
    case DLG_LOAD_QUEST_MAP:   tpl = &kDlgLoadQuestMap; break;
    case DLG_CUSTOM_SOUNDS:    tpl = &kDlgCustomSounds; break;
    default: break;
    }
    if (!tpl) return 0;
    dlgOpen(&r->dlg, tpl, surfaceW, surfaceH);
    dlgRunFurnish(r, which);
    return 1;
}

/* ------------------------------------------------------------------ draw */

static const char *kHelpPages[4] = {
    "The board is forty-eight cells\n"
    "square.  Drag with the right\n"
    "button to look about, and the\n"
    "wheel scrolls it too.",

    "Drag over your units to gather\n"
    "them, or click one.  Then click\n"
    "the square you want worked on:\n"
    "a menu comes up there with the\n"
    "orders that square accepts.",

    "Scenery and open water take the\n"
    "clearing order and nothing else.\n"
    "Clearing them is how a road or a\n"
    "bridge is made.  The order that\n"
    "shuts one again is on the road.",

    "A country is out when it holds\n"
    "nothing.  Three of the four gone\n"
    "and the stage is yours.",
};

// What the original puts into these controls, it puts in the way Windows
// does: `SetDlgItemInt` for the numbers and `SendDlgItemMessageA` with
// WM_SETTEXT for the words - it imports no SetDlgItemTextA - so the control's
// own text is replaced and Windows repaints its whole rectangle.  The port used to paint over the resource's text instead,
// which showed in the Japanese release - a static twenty rows tall draws its
// text two rows down, so the last two rows of "å¨é¨" stayed under the number
// that was meant to replace it.  Anything that fits in a control's text goes
// through dlgSetText now, and the two that do not - the rules page and the
// tune's file - are painted after dlgDraw over a cleared rectangle.
static void fillTexts(DlgRunner *r, const GameState *game) {
    Dialog *d = &r->dlg;
    switch (r->which) {
    case DLG_INFORMATION:
        dlgSetText(d, 1067, r->askKind ? "Powerful enemies in path."
                                       : "Passage blocked by friendly unit");
        break;
    case DLG_ALLIANCE: {
        // The countries' names beside the frames their colours go in, which
        // is what the original fills those statics with.
        const unsigned me = r->sim->humanFaction;
        dlgSetText(d, 1076, worldCountryName(&game->world, me));
        static const int nameId[3] = {1079, 1085, 1088};
        int n = 0;
        for (unsigned f = 0; f < PLAYABLE_FACTIONS && n < 3; f++) {
            if (f == me) continue;
            dlgSetText(d, nameId[n], worldCountryName(&game->world, f));
            n++;
        }
        dlgSetText(d, 1083, r->allyPick >= 0
                   ? worldCountryName(&game->world, (unsigned)r->allyPick)
                   : "");
        break;
    }
    case DLG_LOAD_QUEST_MAP: {
        dlgSetText(d, 1039,
                   r->dlg.listSel >= 0 && r->dlg.listSel < r->dlg.items[0]
                   ? r->dlg.item[0][r->dlg.listSel] : "---");

        // What the stage on the board is worth so far, which is what 0041aa30
        // and 0041aaf0 work out when it ends.  Before this the whole panel
        // read "---"; now it reads, and the numbers move as the war does.
        StageScore score;
        simStageScore(r->sim, &score);
        char n[24];
        static const struct { int id; int which; } slot[] = {
            {1051, 0},          // Maps
            {1181, 1}, {1180, 2}, {1182, 3}, {1186, 4},     // Area
            {1183, 5}, {1184, 6}, {1185, 7}, {1187, 8},     // Battle
            {1115, 9}, {1118, 10},                          // Results
        };
        for (unsigned i = 0; i < sizeof slot / sizeof slot[0]; i++) {
            switch (slot[i].which) {
            case 0: snprintf(n, sizeof n, "%d", r->stageCount); break;
            case 1: snprintf(n, sizeof n, "%u", score.held); break;
            case 2: snprintf(n, sizeof n, "%u",
                             score.claimable - score.held); break;
            case 3: snprintf(n, sizeof n, "%d.%02d", (int)score.areaPercent,
                             (int)((score.areaPercent -
                                    (int)score.areaPercent) * 100.0f)); break;
            case 4: snprintf(n, sizeof n, "%u", score.penalty); break;
            case 5: snprintf(n, sizeof n, "%u", score.yourLosses); break;
            case 6: snprintf(n, sizeof n, "%u", score.enemyLosses); break;
            case 7: snprintf(n, sizeof n, "%d", (int)score.battlePercent);
                    break;
            case 8: snprintf(n, sizeof n, "%u", score.bonus); break;
            case 9: snprintf(n, sizeof n, "%d", score.remaining); break;
            default: snprintf(n, sizeof n, "%u", score.daysLeft); break;
            }
            dlgSetText(d, slot[i].id, n);
        }
        break;
    }
    default:
        break;
    }
}

// A control whose text is too long for DLG_ITEM_TEXT is painted after
// dlgDraw, and the rectangle is cleared first so the resource's own
// placeholder does not show through it.
static int clearedSlot(Surface *out, const Dialog *d, int id,
                       int *x, int *y, int *w, int *h) {
    if (!dlgControlRect(d, id, x, y, w, h)) return 0;
    for (int j = 0; j < *h; j++) {
        const int py = *y + j;
        if (py < 0 || py >= out->height) continue;
        unsigned char *row = out->pixels + (size_t)py * out->width;
        for (int i = 0; i < *w; i++) {
            const int pxx = *x + i;
            if (pxx < 0 || pxx >= out->width) continue;
            row[pxx] = (unsigned char)UI_FACE;
        }
    }
    return 1;
}

void dlgRunDraw(Surface *out, DlgRunner *r, const GameState *game) {
    if (!dlgRunUp(r)) return;
    fillTexts(r, game);
    dlgDraw(out, &r->dlg);

    int x, y, w, h;
    switch (r->which) {
    case DLG_ALLIANCE: {
        // The names are the statics' own text now; what is left is the
        // countries' colours, which go in the black frames beside them.
        const unsigned me = r->sim->humanFaction;
        static const int frameId[3] = {1080, 1086, 1089};
        int n = 0;
        for (unsigned f = 0; f < PLAYABLE_FACTIONS && n < 3; f++) {
            if (f == me) continue;
            if (dlgControlRect(&r->dlg, frameId[n], &x, &y, &w, &h)) {
                const unsigned char ink = (unsigned char)(0x71 + f);
                for (int j = 2; j < h - 2; j++)
                    for (int i = 2; i < w - 2; i++)
                        if (x + i >= 0 && x + i < out->width &&
                            y + j >= 0 && y + j < out->height)
                            out->pixels[(size_t)(y + j) * out->width + x + i] =
                                ink;
            }
            n++;
        }
        break;
    }
    case DLG_CUSTOM_SOUNDS: {
        // The file the chosen entry plays, which is its number: entry ten is
        // SOUND/LM010.MID.
        if (r->dlg.listSel >= 0 && r->host && r->host->tuneNumber &&
            dlgControlRect(&r->dlg, 1131, &x, &y, &w, &h)) {
            char path[32];
            snprintf(path, sizeof path, "SOUND/LM%03d.MID",
                     r->host->tuneNumber(r->host->user, r->dlg.listSel));
            // Where dlg.c draws an edit's own text, so it sits in the box
            // whatever height the release gives it.
            fontDrawText(out, x + 4, y + (h - 16) / 2,
                         (unsigned char)UI_DARK, path);
        }
        break;
    }
    case DLG_HELP: {
        const int page = dlgValue(&r->dlg, 1122);
        const int loaded = dlgHelpPages();
        if (page >= 0 && page < (loaded ? loaded : 4) &&
            clearedSlot(out, &r->dlg, 1123, &x, &y, &w, &h)) {
            // 004145c0 puts the page the combo has selected into the static.
            // The game's own text is one paragraph a page with its own
            // newlines in it, so it is wrapped to the control; the port's four
            // are already broken into lines.
            if (loaded) {
                dlgWrapInto(out, dlgHelpPage(page), x, y, w, h);
                break;
            }
            const char *p = kHelpPages[page];
            char line[64];
            int at = 0, row = 0;
            for (;; p++) {
                if (*p == '\n' || *p == 0) {
                    line[at] = 0;
                    fontDrawText(out, x, y + row * 18, (unsigned char)UI_DARK,
                                 line);
                    row++;
                    at = 0;
                    if (*p == 0) break;
                    continue;
                }
                if (at < (int)sizeof line - 1) line[at++] = *p;
            }
        }
        break;
    }
    default:
        break;
    }
}

void dlgRunHover(DlgRunner *r, int x, int y) {
    if (!dlgRunUp(r)) return;
    dlgHover(&r->dlg, x, y);
}

/* ----------------------------------------------------------------- click */

// Which country the nth Set button is about, skipping the player's own.
static int allyAt(const DlgRunner *r, int n) {
    const unsigned me = r->sim->humanFaction;
    int seen = 0;
    for (unsigned f = 0; f < PLAYABLE_FACTIONS; f++) {
        if (f == me) continue;
        if (seen == n) return (int)f;
        seen++;
    }
    return -1;
}

static void applyDefaultOrders(DlgRunner *r) {
    const int which = dlgValue(&r->dlg, 1125);
    const int strength = dlgValue(&r->dlg, 1126);
    const unsigned order = kDefaultOrderList[which < 0 || which > 6 ? 0 : which];
    if (order == 0) {
        r->sim->pendingOrder = 0;
        return;
    }
    unsigned code = order | 0x10u;
    if (strength == 1) code |= 0x40u;
    if (strength == 2) code |= 0x80u;
    r->sim->pendingOrder = order == 1 && strength == 0 ? 1u : code;
}

static void applySystemSetting(DlgRunner *r) {
    if (r->host && r->host->setWindow) {
        r->host->setWindow(r->host->user, 0, dlgValue(&r->dlg, 1067));
        r->host->setWindow(r->host->user, 1, dlgValue(&r->dlg, 1068));
        r->host->setWindow(r->host->user, 2, dlgValue(&r->dlg, 1070));
    }
    if (r->host && r->host->setSpeed)
        r->host->setSpeed(r->host->user, dlgValue(&r->dlg, 1118) * 30 / 100);
    r->sim->state->showOrders = dlgValue(&r->dlg, 1114);
}

int dlgRunClick(DlgRunner *r, int x, int y) {
    if (!dlgRunUp(r)) return 0;
    const int id = dlgClick(&r->dlg, x, y);
    if (id <= 0) {
        // A list or a combo may have moved, which changes what can be pressed.
        if (r->which == DLG_LOAD)
            dlgEnable(&r->dlg, 1110, r->dlg.listSel >= 0);
        if (r->which == DLG_SAVE) {
            dlgEnable(&r->dlg, 1019, r->dlg.listSel >= 0);
            dlgEnable(&r->dlg, 1020, r->dlg.listSel >= 0);
        }
        if (r->which == DLG_HELP) {
            const int page = dlgValue(&r->dlg, 1122);
            dlgEnable(&r->dlg, 1120, page > 0);
            dlgEnable(&r->dlg, 1121, page < 3);
        }
        return 0;
    }

    switch (r->which) {
    case DLG_DEFAULT_ORDERS:
        if (id == 1075) applyDefaultOrders(r);
        break;

    case DLG_SYSTEM_SETTING:
        if (id == 1) applySystemSetting(r);
        break;

    case DLG_LOAD:
        if (id == 1110 && r->dlg.listSel >= 0 && r->host && r->host->slotRead)
            r->host->slotRead(r->host->user, r->dlg.listSel);
        break;

    case DLG_SAVE:
        if (id == 1018 && r->host && r->host->slotWrite) {
            // Save New: the first empty slot, or the last if they are all
            // taken - which is what a list with no empty row can do.
            int at = r->firstEmpty;
            if (at < 0) at = r->dlg.listSel >= 0 ? r->dlg.listSel : 0;
            r->host->slotWrite(r->host->user, at, r->dlg.edit);
        } else if (id == 1019 && r->dlg.listSel >= 0 && r->host &&
                   r->host->slotWrite) {
            r->host->slotWrite(r->host->user, r->dlg.listSel, r->dlg.edit);
        } else if (id == 1020 && r->dlg.listSel >= 0 && r->host &&
                   r->host->slotRemove) {
            r->host->slotRemove(r->host->user, r->dlg.listSel);
            fillSlots(r);
            r->dlg.listSel = -1;
            return 0;                           // it stays up
        }
        break;

    case DLG_LOAD_SINGLE_MAP:
    case DLG_LOAD_QUEST_MAP:
        if (id == 1040 && r->dlg.listSel >= 0 && r->host && r->host->loadStage)
            r->host->loadStage(r->host->user, r->dlg.listSel,
                               r->which == DLG_LOAD_QUEST_MAP);
        else if (id == 1188) {                  // Awards
            r->showAwards = 1;
            break;
        }
        else if (id == 1189) {                  // Ending
            r->showEnding = 1;
            break;
        }
        break;

    case DLG_CUSTOM_SOUNDS:
        if (id == 1088 && r->dlg.listSel >= 0 && r->host && r->host->tunePlay) {
            r->host->tunePlay(r->host->user, r->dlg.listSel);
            return 0;                           // it stays up while it plays
        }
        if (id == 1089) {
            if (r->host && r->host->tuneStop) r->host->tuneStop(r->host->user);
            return 0;
        }
        break;

    case DLG_ALLIANCE:
        if (id == 1095 || id == 1096 || id == 1097) {
            r->allyPick = allyAt(r, id - 1095);
            return 0;
        }
        if (id == 1074) {                       // Reset
            const unsigned me = r->sim->humanFaction;
            if (me < PLAYABLE_FACTIONS) {
                const unsigned char was = r->sim->state->factions[me].at1e;
                if (was < PLAYABLE_FACTIONS)
                    r->sim->state->factions[was].at1e = 0x80;
                r->sim->state->factions[me].at1e = 0x80;
            }
            r->allyPick = -1;
            dlgEnable(&r->dlg, 1074, 0);
            return 0;
        }
        if (id == 1082 && r->allyPick >= 0) {   // OK
            // Not the executable's own doing: 00413390 reads +0x1e and
            // 00411eb0 clears it, but nothing in the program ever writes a
            // country into it - the commit half of this dialog was cut before
            // release.  Everything else in the engine honours an alliance, so
            // the port finishes what the dialog plainly means, and says so
            // here rather than pretending it found it.
            const unsigned me = r->sim->humanFaction;
            if (me < PLAYABLE_FACTIONS) {
                r->sim->state->factions[me].at1e = (unsigned char)r->allyPick;
                r->sim->state->factions[r->allyPick].at1e = (unsigned char)me;
            }
        }
        break;

    case DLG_INFORMATION: {
        // The four in the resource's own order: Go, Don't go, Remainder go,
        // Remainder don't go.
        int choice = 0;
        if (id == 1069) choice = 1;
        else if (id == 3) choice = 2;
        else if (id == 4) choice = 3;
        const int more = simOrderAnswer(r->sim, choice);
        r->lastOrdered = more == SIM_ORDER_ASK ? r->lastOrdered : more;
        if (more == SIM_ORDER_ASK) {
            // Another unit is in the same difficulty; ask about that one.
            const int w = r->dlg.surfaceW, h = r->dlg.surfaceH;
            dlgClose(&r->dlg);
            r->which = DLG_NONE;
            dlgRunOpen(r, DLG_INFORMATION, w, h);
            return 0;
        }
        break;
    }
    case DLG_HELP:
        if (id == 1120 || id == 1121) {
            int page = dlgValue(&r->dlg, 1122) + (id == 1121 ? 1 : -1);
            if (page < 0) page = 0;
            if (page > 3) page = 3;
            dlgSetValue(&r->dlg, 1122, page);
            dlgEnable(&r->dlg, 1120, page > 0);
            dlgEnable(&r->dlg, 1121, page < 3);
            return 0;
        }
        break;

    default:
        break;
    }

    dlgClose(&r->dlg);
    r->which = DLG_NONE;
    return 1;
}
