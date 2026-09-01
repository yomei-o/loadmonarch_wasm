// The game's state, at the offsets the executable uses.
//
// Three arrays hold everything the simulation touches.  Their sizes and
// strides are not guesses: 004272b0 and 00427210 walk them with literal
// bounds, and 0041b370 recomputes totals across them.
//
//   DAT_0043453c   2304 cells      0x18 bytes each, 0xd800 total
//   DAT_00434538     64 entities   0x224 bytes each, 0x8900 total
//   DAT_00434534      5 factions   0x38 bytes each, 0x118 total
//
// Field names are ours; every offset carries the routine it came from.  What
// a field means is written down only where the executable makes it plain -
// the rest keep their offsets and no story.
#ifndef STATE_H
#define STATE_H

#include "world.h"

#define ENTITY_COUNT  64        // 0x8900 / 0x224
#define FACTION_COUNT 5         // 0x118 / 0x38, of which four can be defeated
#define PLAYABLE_FACTIONS 4     // 0041b370's defeat sweep stops at 0xe0

#define CELL_NO_ENTITY 0x40     // 00427210's fill for "nobody here"
#define TERRAIN_WALKABLE_MAX 0x30   // 00405330: >= 0x30 blocks movement
#define TERRAIN_RESET 0x30          // 004273b0's fill
#define CELL_VALUE_RESET 100        // 004273b0 and 00405de0
#define FACTION_FUNDS_RESET 5000    // 004272b0
#define FACTION_STRENGTH_CAP 100000 // 0041b370 caps at 0x186a0

typedef struct {
    unsigned char position[2];  // +0x00, +0x01  column, row (see WORLD_INDEX)
    unsigned char target[2];    // +0x02, +0x03  0040b680 bounds both to 1..46
    unsigned char faction;      // +0x04         indexes the faction array
    unsigned char at05[3];
    unsigned at08;              // +0x08         200 for a neutral spawn
    unsigned char at0c;         // +0x0c         6 on spawn and on a move
    unsigned char at0d;         // +0x0d         0x0e on spawn; bit 5 gates tax
    unsigned char at0e;
    unsigned char at0f;         // +0x0f         10 on spawn
    unsigned char flags;        // +0x10         0x80 = inactive (004272b0)
    unsigned char at11[7];
    unsigned at18;              // +0x18         0x1f0 at reset
    unsigned char at1c[0x21c - 0x1c];
    unsigned flags21c;          // +0x21c        bit 0 cleared at reset
    unsigned char at220;        // +0x220        0xff at reset
    unsigned char at221[3];
} Entity;

typedef struct {
    unsigned char at00[4];
    unsigned flags;             // +0x04         bit 4 (0x10) = defeated
    unsigned char at08[8];
    unsigned strength;          // +0x10         at28 + at30, capped
    unsigned at14;              // +0x14         cleared at reset
    unsigned funds;             // +0x18         5000 at reset
    unsigned char taxRate;      // +0x1c         0041dc60 derives it from funds
    unsigned char at1d;
    unsigned char at1e;         // +0x1e         0x80 at reset
    unsigned char at1f;         // +0x1f         4 once defeated
    unsigned char at20[4];
    unsigned entities;          // +0x24         entities counted per faction
    unsigned at28;              // +0x28         summed into strength
    unsigned char at2c[4];
    unsigned at30;              // +0x30         summed into strength
    unsigned char at34[4];
} Faction;

typedef struct {
    World world;                            // the cells and the tile banks
    Entity entities[ENTITY_COUNT];
    Faction factions[FACTION_COUNT];
} GameState;

// 004273b0: every cell back to default terrain and value.
void stateResetCells(GameState *state);

// 00405330: +0x05 records whether the terrain blocks movement.
void stateMarkBlocked(GameState *state);

// 004272b0: entities and factions to their starting values.
void stateResetEntitiesAndFactions(GameState *state);

// 00427210: per-stage reset, and the pass that writes each active entity's
// own index into the cell it stands on.
void statePlaceEntities(GameState *state);

// 0041b370: recompute each faction's entity count and strength, and mark a
// faction with no strength left as defeated.
void stateRecomputeTotals(GameState *state);

// The whole chain 00407790 runs after a map loads, in its order.
void stateStartStage(GameState *state);

#endif
