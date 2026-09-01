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
    unsigned char owner;      // +0x00  0x40 at load, later the faction byte
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
    unsigned troops;          // +0x14  cleared, then set from the active count
} WorldCell;

// One decompressed and unpacked graphics bank.
typedef struct {
    int tileSize;                                   // 8, 16 or 32
    unsigned tiles;
    unsigned char *pixels;                          // tiles * tileSize^2
    unsigned char palette[256][3];                  // its own sixteen at 0x10
} TileBank;

typedef struct {
    WorldCell cells[WORLD_CELLS];
    unsigned char scenerySet;   // the .MAP byte at 0x900: 10, 20, 30, 40, 50
    // Not named small/medium/large: rpcndr.h defines `small` as a macro for
    // char, so MSVC rejects a field by that name outright.
    TileBank bank8;             // B_%03ds.bz
    TileBank bank16;            // B_%03dm.bz
    TileBank bank32;            // B_%03dl.bz
    TileBank sprites;           // C_%03dm.bz, the 16-pixel unit sprites
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

#endif
