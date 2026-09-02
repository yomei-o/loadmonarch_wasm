// The stage: a 48x48 grid of cells, and the graphics banks it names.
//
// The original keeps one 24-byte record per cell in the 0xd800 array at
// DAT_0043453c, indexed row * 0x30 + column.  The fields below are the ones
// 00405de0 initialises and the rest of the executable reads; the names are
// ours, the offsets and the uses are the executable's.
#ifndef WORLD_H
#define WORLD_H

#include "host.h"

#define WORLD_GRID 48                       // 0x30, the index stride
#define WORLD_CELLS (WORLD_GRID * WORLD_GRID)

// The cell index is column * WORLD_GRID + row - checked against the running
// original, which draws the transpose of the naive reading.
#define WORLD_INDEX(col, row) ((col) * WORLD_GRID + (row))
#define TILE_BANK_TILES 128

typedef struct {
    unsigned char occupant;   // +0x00  the entity standing here, or >= 0x40
                              //        for nobody.  004240c0 draws whatever
                              //        this indexes; it is not an owner.
    unsigned char pad1;
    unsigned char pad2;
    unsigned char pad3;
    unsigned char marked;     // +0x04  set to 1 while a region is walked
    unsigned char blocked;    // +0x05  00405330: 1 when terrain >= 0x30
    unsigned char pad6[2];
    unsigned cost;            // +0x08  compared with < to find a minimum:
                              //        the routing cost of stepping here
    unsigned value;           // +0x0c  100 at load, later (v >> 1) + 1
    unsigned char terrain;    // +0x10  the tile number, straight from the file
    unsigned char pad11[3];
    unsigned overlay;         // +0x14  a sprite number drawn over the cell,
                              //        two frames wide.  0040b270 parks the
                              //        cursor (0xcc) here and clears the old
                              //        cell as it moves.
} WorldCell;

// One decompressed and unpacked graphics bank.
typedef struct {
    int tileSize;                                   // 8, 16 or 32
    unsigned tiles;
    unsigned char *pixels;                          // tiles * tileSize^2
    unsigned char palette[256][3];                  // its own sixteen at 0x10
} TileBank;

// 00405fc0 copies a table of 16-byte records out of the large terrain file at
// 0x7ea0 and keeps 22 of them.  Record 0 is junk; 1 to 5 name the five
// countries and carry each one's colour in their first byte, which the loader
// reads out and blanks; 6 to 21 name the sixteen orders, in order.  Every
// scenery set has its own, so the countries and even the wording of the orders
// change from campaign to campaign.
#define NAME_RECORDS 22
#define NAME_TEXT    13         // 0x7ea0's records are 16 wide, 13 usable
#define NAME_COUNTRY 1          // record of country 0
#define NAME_ORDER   6          // record of order 0

typedef struct {
    char text[NAME_RECORDS][NAME_TEXT + 1];
    unsigned char colour[NAME_RECORDS];     // 1..5 only: a palette index
    int loaded;
} NameTable;

// MAP/NAME.TXT: the campaign itself.  An [entry] header giving the quest's
// name and how many stages there are, then one [n] block per stage with a
// NAME= and a FILE=.  The order in this file is the order the stages are
// played in, which is not the order their file names sort in - and the names
// are the ones the game shows.  The Japanese release writes them in Shift-JIS.
#define STAGE_MAX   32
#define STAGE_NAME  40
#define STAGE_FILE  20

typedef struct {
    unsigned count;
    char quest[STAGE_NAME];
    char name[STAGE_MAX][STAGE_NAME];
    char file[STAGE_MAX][STAGE_FILE];
} StageList;

// Reads it, or returns 0 and leaves the list empty.
int worldReadStages(StageList *stages, const Host *host);

// SOUND/SOUND.CFG: the soundtrack, in the same shape as the campaign list.
// Each block gives an ENTRY - which is the number in the file name, so entry 10
// is LM010.MID - a NAME, a MIDI file, whether it LOOPs, and a CD track for the
// release that had one.  The names say what the tunes are for: every scenery
// set has a Normal, a Happy and a Pause, which is exactly the pair 0040a110
// chooses between.
//
// The last entries name sound effects and carry no file: this release has no
// effects, only music.
#define TUNE_MAX  40
#define TUNE_NAME 40

typedef struct {
    unsigned count;
    unsigned entry[TUNE_MAX];       // the file number, e.g. 10 for LM010.MID
    char name[TUNE_MAX][TUNE_NAME];
    unsigned char loops[TUNE_MAX];
} TuneList;

int worldReadTunes(TuneList *tunes, const Host *host);

// data1.bz, laid out by 00407560: a 256-wide sheet of everything the
// interface is drawn from, with 0x70 standing for transparent.
#define UI_SHEET_W 256
#define UI_SHEET_H 1024
#define UI_TRANSPARENT 0x70

typedef struct {
    unsigned char *pixels;                  // UI_SHEET_W * UI_SHEET_H, or null
    unsigned char palette[256][3];          // data1.rgb's 48 at index 0x80
} UiSheet;

typedef struct {
    WorldCell cells[WORLD_CELLS];
    unsigned char scenerySet;   // the .MAP byte at 0x900: 10, 20, 30, 40, 50
    // Not named small/medium/large: rpcndr.h defines `small` as a macro for
    // char, so MSVC rejects a field by that name outright.
    TileBank bank8;             // B_%03ds.bz
    TileBank bank16;            // B_%03dm.bz
    TileBank bank32;            // B_%03dl.bz
    TileBank sprites8;          // C_%03ds.bz, cut into quarters
    TileBank sprites;           // C_%03dm.bz, the 16-pixel unit sprites
    TileBank sprites32;         // C_%03dl1..4.bz, merged in fours
    UiSheet ui;                 // data1.bz, shared by every stage
    NameTable names;            // 0x7ea0 of B_%03dl.bz
    char stage[64];             // which map this is
} World;

// Loads a stage and the three background banks its trailer selects, through
// whichever host the caller set up - a directory or the player's zip.
// Returns non-zero on success; message receives a reason on failure.
int worldLoadStage(World *world, const Host *host, const char *mapName,
                   char *message, unsigned messageSize);

void worldFree(World *world);

// The bank for a zoom level: 0 small, 1 medium, 2 large.
const TileBank *worldBank(const World *world, int zoom);

// The name of a country, or of an order, in the wording this scenery set uses.
// Never null; an empty string if the table did not load.
const char *worldCountryName(const World *world, unsigned faction);
const char *worldOrderName(const World *world, unsigned order);

// The sprite bank for that zoom.  Never null, but its pixels can be, when the
// stage had no such file.
const TileBank *worldSprites(const World *world, int zoom);

#endif
