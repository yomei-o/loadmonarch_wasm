#include "state.h"

#include <string.h>

// 004273b0.  Note it writes the reset terrain over what the map file supplied,
// so it belongs before a stage's cells are filled, not after.
void stateResetCells(GameState *state) {
    for (int i = 0; i < WORLD_CELLS; i++) {
        state->world.cells[i].terrain = TERRAIN_RESET;
        state->world.cells[i].value = CELL_VALUE_RESET;
    }
}

// 00405330.  The one place the executable says what the 0x30 boundary means.
void stateMarkBlocked(GameState *state) {
    for (int i = 0; i < WORLD_CELLS; i++) {
        WorldCell *cell = &state->world.cells[i];
        cell->blocked = cell->terrain < TERRAIN_WALKABLE_MAX ? 0 : 1;
    }
}

// 004272b0.
void stateResetEntitiesAndFactions(GameState *state) {
    memset(state->entities, 0, sizeof state->entities);
    memset(state->factions, 0, sizeof state->factions);

    for (int i = 0; i < ENTITY_COUNT; i++) {
        Entity *entity = &state->entities[i];
        entity->flags = 0x80;           // inactive until a stage places it
        entity->flags21c &= ~1u;
        entity->at220 = 0xff;
        entity->at18 = 0x1f0;
    }
    for (int i = 0; i < FACTION_COUNT; i++) {
        Faction *faction = &state->factions[i];
        faction->funds = FACTION_FUNDS_RESET;
        faction->taxRate = 0;
        faction->at1e = 0x80;
        faction->at14 = 0;
        // The original clears bits 0, 1, 2, 3, 4, 5 and 7 one at a time,
        // leaving bit 6 alone.  Written out rather than as one mask so the
        // omission stays visible.
        faction->flags &= ~(1u << 3);
        faction->flags &= ~(1u << 0);
        faction->flags &= ~(1u << 4);
        faction->flags &= ~(1u << 6);
        faction->flags &= ~(1u << 1);
        faction->flags &= ~(1u << 2);
        faction->flags &= ~(1u << 5);
    }
}

// 00427210.
void statePlaceEntities(GameState *state) {
    for (int i = 0; i < WORLD_CELLS; i++) {
        state->world.cells[i].occupant = CELL_NO_ENTITY;
        state->world.cells[i].overlay = 0;
    }
    for (int i = 0; i < ENTITY_COUNT; i++) {
        Entity *entity = &state->entities[i];
        entity->flags21c &= ~1u;
        entity->at220 = 0xff;
        if ((entity->flags & 0x80) == 0) {
            const unsigned index = WORLD_INDEX(entity->position[0],
                                               entity->position[1]);
            if (index < WORLD_CELLS)
                state->world.cells[index].occupant = (unsigned char)i;
        }
    }
}

// 0041b370.  A faction's strength is two sums: what its cells hold and what
// its entities carry, each capped at a hundred thousand on the way in and the
// pair capped again at the end.  Everything the interface calls a total comes
// from here.
void stateRecomputeTotals(GameState *state) {
    for (int i = 0; i < FACTION_COUNT; i++) {
        Faction *faction = &state->factions[i];
        faction->entities = 0;      // +0x24
        faction->at28 = 0;
        faction->at2c = 0;
        faction->at30 = 0;
    }

    // The cells: a neutral spawner's value goes to the neutral faction, and a
    // unit cell's to whoever holds it, counted as it goes.
    for (int i = 0; i < WORLD_CELLS; i++) {
        const WorldCell *cell = &state->world.cells[i];
        if (cell->terrain == 5) {
            state->factions[4].at30 += cell->value;
            continue;
        }
        const int owner = (int)cell->terrain - 8;
        if (owner < 0 || owner >= 4) continue;
        Faction *faction = &state->factions[owner];
        faction->at30 += cell->value;
        if (faction->at30 > FACTION_STRENGTH_CAP)
            faction->at30 = FACTION_STRENGTH_CAP;
        faction->at2c++;
    }

    // The entities, leaders excepted - a leader's strength is not part of its
    // country's, which is why losing one is a different kind of loss.
    for (int i = 0; i < ENTITY_COUNT; i++) {
        const Entity *entity = &state->entities[i];
        if (entity->flags & 0x80) continue;
        if (entity->at0d & 0x20) continue;
        if (entity->faction >= FACTION_COUNT) continue;
        Faction *faction = &state->factions[entity->faction];
        faction->at28 += entity->at08;
        if (faction->at28 > FACTION_STRENGTH_CAP)
            faction->at28 = FACTION_STRENGTH_CAP;
        faction->entities++;
    }

    for (int i = 0; i < FACTION_COUNT; i++) {
        Faction *faction = &state->factions[i];
        const unsigned sum = faction->at28 + faction->at30;
        faction->strength = sum < FACTION_STRENGTH_CAP + 1
                                ? sum : FACTION_STRENGTH_CAP;
    }
}

// 0041b370's last sweep, which stops at 0xe0 - one record short of the fifth
// faction, so only the four playable ones can be knocked out.  Nothing ever
// clears that mark, so it is kept apart from the sums: those are safe to
// recompute whenever, this is not.
void stateMarkDefeated(GameState *state) {
    for (int i = 0; i < PLAYABLE_FACTIONS; i++) {
        Faction *faction = &state->factions[i];
        if (faction->strength == 0) {
            faction->at1f = 4;
            faction->flags |= 0x10;
        }
    }
}

// 0041cdf0.  How much of the board is worth counting: everything that can
// change hands.  Scenery, water and the rest are not in the reckoning, so a
// map that is half mountain does not make every country look small.
unsigned stateClaimableCells(const GameState *state) {
    unsigned total = 0;
    for (int i = 0; i < WORLD_CELLS; i++) {
        const unsigned char terrain = state->world.cells[i].terrain;
        if (terrain <= 4 || (terrain >= 8 && terrain <= 0x0f) ||
            terrain == 0x7b)
            total++;
    }
    return total;
}

// 0041ceb0.  What one country holds: its unit cells and its plain territory.
unsigned stateFactionCells(const GameState *state, unsigned faction) {
    unsigned held = 0;
    for (int i = 0; i < WORLD_CELLS; i++) {
        const unsigned char terrain = state->world.cells[i].terrain;
        if ((unsigned char)(terrain - faction) == 8 ||
            (unsigned char)(terrain - faction) == 0x0c)
            held++;
    }
    return held;
}

// 0041b640.  Each country's share, to two decimals.  The original computes it
// for the interface rather than every tick, and so does this.
void stateComputeAreas(GameState *state) {
    const unsigned total = stateClaimableCells(state);
    for (int i = 0; i < PLAYABLE_FACTIONS; i++) state->factions[i].area = 0.0f;
    if (total == 0) return;
    for (int i = 0; i < PLAYABLE_FACTIONS; i++) {
        const unsigned held = stateFactionCells(state, (unsigned)i);
        // Rounded the way the original rounds it: to hundredths.
        const float share = (float)((int)(held * 10000.0f / (float)total)) *
                            0.01f;
        state->factions[i].area = share;
    }
}

// 00405c60 and its writing half.  Three blocks, in the order the original
// lays them out.
void stateSave(const GameState *state, unsigned char *out) {
    memcpy(out, state->factions, sizeof state->factions);
    memcpy(out + sizeof state->factions, state->world.cells,
           sizeof state->world.cells);
    memcpy(out + sizeof state->factions + sizeof state->world.cells,
           state->entities, sizeof state->entities);
}

void stateLoad(GameState *state, const unsigned char *in) {
    memcpy(state->factions, in, sizeof state->factions);
    memcpy(state->world.cells, in + sizeof state->factions,
           sizeof state->world.cells);
    memcpy(state->entities,
           in + sizeof state->factions + sizeof state->world.cells,
           sizeof state->entities);
}

// The chain at 00407790: 004273b0, 00405330, 004272b0, 00427210, 0041b370.
// worldLoadStage has already put the map's terrain in place, so the cell
// reset that opens the original's chain is deliberately not repeated here -
// it runs before a map is read, not after.
// 0040b270.  Not a keyboard routine, whatever this port assumed at first: the
// executable carries exactly one accelerator (I, command 40001) and compares
// nothing against VK_LEFT, VK_UP, VK_RIGHT or VK_DOWN anywhere in its 792
// functions.  What 0040b270 does is slide the cursor one cell per tick toward
// somewhere the game wants the player to look - 00424520 parks it on another
// country when that country does something worth seeing.  A cell is a cell
// however it was chosen, so the hosts point this at the mouse.
// 0xcc is the balloon 0040b270 lays in a cell's own +0x14 to point a country
// out; the mouse's own frame is not a sprite at all but a piece of the
// interface sheet, which src/render.c draws.  Nothing lays 0xcc here yet.
#define CURSOR_SPRITE 0xccu

void stateMoveCursor(GameState *state, int col, int row) {
    if (col < 0 || row < 0 || col >= WORLD_GRID || row >= WORLD_GRID) {
        state->cursorCol = 0xff;
        state->cursorRow = 0xff;
        return;
    }
    state->cursorCol = (unsigned char)col;
    state->cursorRow = (unsigned char)row;
}

void stateStartStage(GameState *state) {
    state->frame = 1;                   // DAT_00435b1c starts at one
    state->showOrders = 1;              // DAT_004376a1
    state->cursorCol = 0xff;            // nowhere until a host points it
    state->cursorRow = 0xff;

    stateMarkBlocked(state);
    stateResetEntitiesAndFactions(state);
    statePlaceEntities(state);
    stateRecomputeTotals(state);

    // The original's chain ends with the marking too, and can afford to: by
    // the time it runs, the scenario it loaded has already put every country's
    // leader and opening units on the board, so nobody has zero strength.
    // Here the leaders are seeded afterwards, so marking now would condemn all
    // four before the stage began - and 0041f090 would then wipe them out on
    // the first tick.  The tick does the marking, once there is somebody to
    // mark.
}
