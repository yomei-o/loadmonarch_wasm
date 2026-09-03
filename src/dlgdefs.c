// The sixteen dialogs the executable carries, transcribed control for control
// out of its DLGTEMPLATE resources - same ids, same places, same captions.
//
// tools/dump_dialogs.py prints the resources this was written from, so the two
// can be compared whenever one is touched.  Positions and sizes are dialog
// units, exactly as the resource has them; dlg.c turns them into pixels.
#include "dlg.h"

#include <stddef.h>

/* --------------------------------------------------- 124 "Default Orders" */

static const DlgControl kDefaultOrders[] = {
    {DC_COMBO,  1125,   5,  5,  85, 71, ""},
    {DC_COMBO,  1126,   5, 35,  85, 47, ""},
    {DC_PUSH,   1075,   5, 60,  40, 15, "OK"},
    {DC_PUSH,      8,  50, 60,  40, 15, "Cancel"},
    {DC_END, 0, 0, 0, 0, 0, ""},
};
const DlgTemplate kDlgDefaultOrders = {"Default Orders", 94, 81,
                                       kDefaultOrders};

/* ---------------------------------------------------------- 120 "Version" */

static const DlgControl kVersion[] = {
    {DC_PUSH,      8, 147,  7,  35, 14, "Ok"},
    {DC_ICON,  65535,   5, 15,  18, 20, ""},
    {DC_TEXT,   1195,  33, 15, 112,  8, "Lord Monarch Online"},
    {DC_TEXT,  65535,  32, 27, 150, 10,
     "Copyright (C) 1997 Nihon Falcom Co."},
    {DC_END, 0, 0, 0, 0, 0, ""},
};
const DlgTemplate kDlgVersion = {"Version", 189, 50, kVersion};

/* ------------------------------------------------------ 118 "Information" */

// What comes up when a unit that was told to go somewhere can only get there
// the hard way: 00412ff0 puts "Powerful enemies in path." in the static when
// the balloon said three and "Passage blocked by friendly unit" when it said
// four, and the two "Remainder" buttons are only enabled when more than one
// unit was chosen.
static const DlgControl kInformation[] = {
    {DC_TEXT,   1067,   5,  5, 135, 20, ""},
    {DC_DEFPUSH, 1068,  5, 30,  65, 14, "Go!"},
    {DC_PUSH,   1069,  75, 30,  65, 14, "Don't go!"},
    {DC_PUSH,      3,   5, 50,  65, 14, "Remainder go!"},
    {DC_PUSH,      4,  75, 50,  65, 14, "Remainder don't go!"},
    {DC_END, 0, 0, 0, 0, 0, ""},
};
const DlgTemplate kDlgInformation = {"Information", 144, 70, kInformation};

/* ---------------------------------------------------- 115 "System Setting" */

// The four unnamed boxes are "??", "?2", "?3" and "?4" in the resource - the
// English release never had them translated - so they are drawn as the
// resource has them.  1118 is the trackbar the original calls the Game Restart
// Timer, which is DAT_00437698: the tick pacing, 0 to 29.
static const DlgControl kSystemSetting[] = {
    {DC_GROUP, 65535,   5,  5, 115,120, "Window to open during play"},
    {DC_CHECK,  1067,  10, 20, 100, 10, "Progress Window"},
    {DC_CHECK,  1068,  10, 35, 100, 10, "Unit Window"},
    {DC_CHECK,  1070,  10, 50, 100, 10, "Graph Window"},
    {DC_CHECK,  1071,  10, 65, 105, 10, "??"},
    {DC_CHECK,  1072,  10, 80, 105, 10, "?2"},
    {DC_CHECK,  1073,  10, 95, 105, 10, "?3"},
    {DC_CHECK,  1074,  10,110, 105, 10, "?4"},
    {DC_GROUP, 65535, 125,  5, 125, 55, "Game Restart Timer"},
    {DC_SLIDER, 1118, 130, 21,  85, 15, ""},
    {DC_TEXT,   1119, 215, 25,  20, 10, "Fast"},
    {DC_CHECK,  1113, 140, 45, 105, 10, "Game Paused While in Window"},
    {DC_GROUP, 65535, 125, 65, 125, 30, "Misc."},
    {DC_CHECK,  1114, 130, 80,  90, 10, "Help Balloons On"},
    {DC_PUSH,      1, 125,110,  45, 15, "OK"},
    {DC_PUSH,      2, 205,110,  45, 15, "Cancel"},
    {DC_END, 0, 0, 0, 0, 0, ""},
};
const DlgTemplate kDlgSystemSetting = {"System Setting", 259, 130,
                                       kSystemSetting};

/* ------------------------------------------------------------- 107 "Load" */

static const DlgControl kLoad[] = {
    {DC_LIST,   1015,   5,  5, 175, 85, ""},
    {DC_DEFPUSH,1110, 185,  5,  40, 15, "Load"},
    {DC_PUSH,      8, 185, 25,  40, 15, "Cancel"},
    {DC_END, 0, 0, 0, 0, 0, ""},
};
const DlgTemplate kDlgLoad = {"Load", 229, 95, kLoad};

/* ------------------------------------------------------------- 106 "Save" */

static const DlgControl kSave[] = {
    {DC_EDIT,   1109,   5,  5, 170, 15, ""},
    {DC_LIST,   1015,   5, 25, 170, 75, ""},
    {DC_DEFPUSH,1018, 185, 10,  40, 15, "Save New"},
    {DC_DEFPUSH,1019, 185, 30,  40, 15, "Save"},
    {DC_DEFPUSH,1020, 185, 50,  40, 15, "Delete"},
    {DC_PUSH,      8, 185, 70,  40, 15, "Cancel"},
    {DC_END, 0, 0, 0, 0, 0, ""},
};
const DlgTemplate kDlgSave = {"Save", 229, 106, kSave};

/* -------------------------------------------------- 127 "Load Single Map" */

static const DlgControl kLoadSingleMap[] = {
    {DC_LIST,   1002,   5,  5, 155, 55, ""},
    {DC_DEFPUSH,1040, 165,  5,  45, 15, "Go!"},
    {DC_PUSH,      2, 165, 25,  45, 15, "Cancel"},
    {DC_END, 0, 0, 0, 0, 0, ""},
};
const DlgTemplate kDlgLoadSingleMap = {"Load Single Map", 215, 66,
                                       kLoadSingleMap};

/* -------------------------------------------------- 119 "Alliance Setting" */

// The frames are where the game draws the countries' own colours: 1077 and
// 1078 are the pair at the top for the player, 1080/1081/1091 and the two rows
// under them are the three candidates, and 1095/1096/1097 are their Set
// buttons.  1083 is the line that says what is about to happen.
static const DlgControl kAlliance[] = {
    {DC_TEXT,   1076,  15,  5,  85, 10, ""},
    {DC_FRAME,  1077,  15, 15,  30, 35, ""},
    {DC_FRAME,  1078,  60, 15,  30, 35, ""},
    {DC_FRAME,  1094,  40, 65,  30, 35, ""},
    {DC_TEXT,   1079, 125,  5, 100,  8, ""},
    {DC_FRAME,  1080, 125, 15,  25, 25, ""},
    {DC_FRAME,  1081, 160, 15,  25, 25, ""},
    {DC_FRAME,  1091, 195, 15,  25, 25, ""},
    {DC_PUSH,   1095, 230, 15,  25, 15, "Set"},
    {DC_TEXT,   1085, 125, 50, 100,  8, ""},
    {DC_FRAME,  1086, 125, 60,  25, 25, ""},
    {DC_FRAME,  1087, 160, 60,  25, 25, ""},
    {DC_FRAME,  1092, 195, 60,  25, 25, ""},
    {DC_PUSH,   1096, 230, 60,  25, 15, "Set"},
    {DC_TEXT,   1088, 125, 90, 100,  8, ""},
    {DC_FRAME,  1089, 125,100,  25, 25, ""},
    {DC_FRAME,  1090, 160,100,  25, 25, ""},
    {DC_FRAME,  1093, 195,100,  25, 25, ""},
    {DC_PUSH,   1097, 230,100,  25, 15, "Set"},
    {DC_TEXT,  65535,  10,105, 105, 60,
     "Click on the country you wish to make an alliance with."},
    {DC_TEXT,   1083, 125,135,  80, 10, ""},
    {DC_PUSH,   1082, 125,155,  45, 15, "OK"},
    {DC_PUSH,   1074, 215,155,  45, 15, "Reset"},
    {DC_END, 0, 0, 0, 0, 0, ""},
};
const DlgTemplate kDlgAlliance = {"Alliance Setting", 263, 175, kAlliance};

/* ----------------------------------------------------- 126 "Sound Setting" */

static const DlgControl kSoundSetting[] = {
    {DC_GROUP, 65535,   5,  5, 115, 50, "Sound on/off"},
    {DC_CHECK,  1089,  15, 20,  33, 10, "BGM"},
    {DC_CHECK,  1090,  60, 20,  61, 10, "Sound Effects"},
    {DC_TEXT,  65535,  60, 36,   8, 10, "("},
    {DC_CHECK,  1175,  70, 35,  30, 10, "Voice"},
    {DC_TEXT,  65535, 104, 36,   8, 10, ")"},
    {DC_GROUP, 65535,   5, 55, 115, 30, "BGM"},
    {DC_RADIO,  1189,  15, 70,  30, 10, "CD"},
    {DC_RADIO,  1190,  70, 70,  30, 10, "MIDI"},
    {DC_PUSH,     10,   5, 90,  55, 15, "Volume"},
    {DC_PUSH,      3,  65, 90,  55, 14, "More"},
    {DC_PUSH,      9,   5,110,  55, 15, "OK"},
    {DC_PUSH,      2,  65,110,  55, 15, "Cancel"},
    {DC_END, 0, 0, 0, 0, 0, ""},
};
const DlgTemplate kDlgSoundSetting = {"Sound Setting", 123, 130,
                                      kSoundSetting};

/* ------------------------------------------------------------- 123 "Help" */

static const DlgControl kHelp[] = {
    {DC_TEXT,  65535,   5,  5,  60,  8, "Game Screen"},
    {DC_GROUP,  1124,   5, 20, 115,115, ""},
    {DC_COMBO,  1122, 130,  5, 150, 70, ""},
    {DC_GROUP, 65535, 125, 20, 160,115, ""},
    {DC_TEXT,   1123, 130, 30, 150,100, ""},
    {DC_PUSH,   1120, 130,140,  45, 15, "Back"},
    {DC_PUSH,   1121, 180,140,  45, 15, "Next"},
    {DC_PUSH,      8, 240,140,  45, 15, "Close"},
    {DC_END, 0, 0, 0, 0, 0, ""},
};
const DlgTemplate kDlgHelp = {"Help", 289, 161, kHelp};
