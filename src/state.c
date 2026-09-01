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
        faction->at1c = 0;
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

// 0041b370's tail.  The head of that routine also walks the entities to build
// the per-faction sums; what it adds is not settled yet, so only the parts
// the executable makes plain are here: the entity count, the capped strength,
// and the defeat mark.
void stateRecomputeTotals(GameState *state) {
    for (int i = 0; i < FACTION_COUNT; i++) state->factions[i].entities = 0;

    for (int i = 0; i < ENTITY_COUNT; i++) {
        const Entity *entity = &state->entities[i];
        if (entity->faction < FACTION_COUNT)
            state->factions[entity->faction].entities++;
    }
    for (int i = 0; i < FACTION_COUNT; i++) {
        Faction *faction = &state->factions[i];
        const unsigned sum = faction->at28 + faction->at30;
        faction->strength = sum < FACTION_STRENGTH_CAP + 1
                                ? sum : FACTION_STRENGTH_CAP;
    }
    // Only the four playable factions can be knocked out: 0041b370's last
    // sweep stops at 0xe0, one record short of the fifth.
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
}
