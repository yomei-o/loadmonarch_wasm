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
        state->world.cells[i].owner = CELL_NO_ENTITY;
        state->world.cells[i].troops = 0;
    }
    for (int i = 0; i < ENTITY_COUNT; i++) {
        Entity *entity = &state->entities[i];
        entity->flags21c &= ~1u;
        entity->at220 = 0xff;
        if ((entity->flags & 0x80) == 0) {
            const unsigned index = WORLD_INDEX(entity->position[0],
                                               entity->position[1]);
            if (index < WORLD_CELLS)
                state->world.cells[index].owner = (unsigned char)i;
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

// The chain at 00407790: 004273b0, 00405330, 004272b0, 00427210, 0041b370.
// worldLoadStage has already put the map's terrain in place, so the cell
// reset that opens the original's chain is deliberately not repeated here -
// it runs before a map is read, not after.
void stateStartStage(GameState *state) {
    stateMarkBlocked(state);
    stateResetEntitiesAndFactions(state);
    statePlaceEntities(state);
    stateRecomputeTotals(state);
    stateMarkDefeated(state);
}
