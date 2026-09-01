// The simulation sweep, from the routine at 00417380.
//
// The whole game advances through one cyclic cursor over the 2304 cells: each
// call walks 0x8f of them from where the last one stopped, wrapping, and
// dispatches on the cell's terrain byte.  That byte is doing double duty - it
// is the tile number the renderer draws AND the cell's state, with the owning
// faction folded into its value:
//
//   5           a neutral spawner (0041dec0)
//   8 + f       faction f's unit standing here (0041d870)
//   0x0c + f    faction f's claimed ground (handled inline in the switch)
//   0x14 + f    faction f's castle (0041dc60)
//
// Anything else the sweep leaves alone, which is why plain scenery never
// changes.
#include "sim.h"

#include <string.h>

#define SWEEP_PER_CALL 0x8f        // 00417380's loop counter
#define ENTITY_NONE 0x40           // 0041cdc0 returns this when none is free

// 0041cdc0: the first inactive entity, or ENTITY_NONE.
static unsigned allocEntity(GameState *state) {
    for (unsigned i = 0; i < ENTITY_COUNT; i++)
        if (state->entities[i].flags & 0x80) return i;
    return ENTITY_NONE;
}

// 0041dec0.  A neutral cell grows in value ten at a time; when it passes
// 0xf5 it spends that much and puts a neutral entity on itself.
static void stepNeutral(GameState *state, unsigned index, unsigned col,
                        unsigned row) {
    WorldCell *cell = &state->world.cells[index];
    if (cell->value < 0xf5) {
        cell->value += 10;
        return;
    }
    cell->value -= 0xf5;
    if (cell->owner < ENTITY_NONE) return;      // somebody is already here

    const unsigned slot = allocEntity(state);
    if (slot >= ENTITY_COUNT) return;
    Entity *entity = &state->entities[slot];
    entity->position[0] = (unsigned char)col;
    entity->position[1] = (unsigned char)row;
    // The original copies the position word over the target word, so a fresh
    // entity is already standing on its own destination.
    entity->target[0] = entity->position[0];
    entity->target[1] = entity->position[1];
    entity->flags = 0;                          // active
    entity->at0c = 6;
    entity->at0d = 0x0e;
    entity->faction = 4;                        // the neutral faction
    entity->at08 = 200;
    entity->at18 = 0x1f0;
    entity->at0f = 10;
    cell->owner = (unsigned char)slot;
}

// The 0x0c..0x0f arm, which the sweep handles without a call: claimed ground
// follows its owner's state byte, and reverts to nothing once that faction is
// out.  Only runs while the faction carries flag 0x40.
static void stepClaimed(GameState *state, unsigned index, unsigned faction) {
    if (faction >= FACTION_COUNT) return;
    const Faction *owner = &state->factions[faction];
    if ((owner->flags & 0x40) == 0) return;
    WorldCell *cell = &state->world.cells[index];
    cell->terrain = owner->at1f == 4 ? 0
                                     : (unsigned char)(owner->at1f + 0x0c);
}

// 0041dc60's head: a faction's tax rate comes out of its own funds, and the
// poorer it is the more it takes.  The human player's is only recomputed in
// the mode DAT_0043769c selects; every other faction's is set every sweep.
static void updateTaxRate(GameState *state, unsigned faction, int isHuman,
                          int autoTax) {
    if (faction >= FACTION_COUNT) return;
    Faction *owner = &state->factions[faction];
    if (isHuman) {
        if (!autoTax) return;
        owner->taxRate = 0;
        const unsigned funds = owner->funds;
        if (funds < 0xffff) {
            owner->taxRate = (unsigned char)(funds >> 8);
            owner->taxRate = owner->taxRate < 0x15
                                 ? (unsigned char)(0x14 - owner->taxRate)
                                 : 0;
        }
        return;
    }
    unsigned char rate = 0;
    const unsigned funds = owner->funds;
    if (funds < FACTION_STRENGTH_CAP && (funds & 0xffffff00u) < 0x701)
        rate = (unsigned char)(~((funds >> 8) << 2) & 0x1c);
    owner->taxRate = rate;
}

// 0041dc60's tail: every cell holding one of this faction's units, whose cost
// has not run out, pays tax rate times its value over 256 - and loses that
// much of its value.  The original also fires three side effects here
// (00405360, 00405390, 0041a680) and decrements DAT_0043781c; none of those is
// read yet, so this collects only the money.
static void collectTax(GameState *state, unsigned faction) {
    if (faction >= FACTION_COUNT) return;
    Faction *owner = &state->factions[faction];
    for (int i = 0; i < WORLD_CELLS; i++) {
        WorldCell *cell = &state->world.cells[i];
        if ((unsigned char)(cell->terrain - faction) != 8) continue;
        if (cell->cost >= 0x1f0) continue;
        const unsigned income = (owner->taxRate * cell->value) >> 8;
        owner->funds += income;
        if (owner->funds > FACTION_STRENGTH_CAP)
            owner->funds = FACTION_STRENGTH_CAP;
        cell->value = cell->value < income ? 0 : cell->value - income;
    }
}

// 0041dc60.  The castle only pays out when one of its own entities stands on
// it, that entity carries bit 5 of +0x0d, and the cell two rows south holds
// either nothing special or this same faction's unit or ground.
static void stepCastle(Sim *sim, unsigned index, unsigned faction) {
    GameState *state = sim->state;
    updateTaxRate(state, faction, faction == sim->humanFaction,
                  sim->autoTax);

    const unsigned char occupant = state->world.cells[index].owner;
    if (occupant >= ENTITY_NONE) return;
    const Entity *entity = &state->entities[occupant];
    if (entity->faction != faction) return;
    if ((entity->at0d & 0x20) == 0) return;

    // 0041dc60 reads +0x40 from the cell, which is two cells further on -
    // two rows south, since the index is column-major.
    if (index + 2 >= WORLD_CELLS) return;
    const unsigned char ahead = state->world.cells[index + 2].terrain;
    if (ahead >= TERRAIN_WALKABLE_MAX) return;
    if (ahead >= 8 && ahead <= 0x0b && (unsigned char)(ahead - faction) != 8)
        return;
    if (ahead >= 0x0c && ahead <= 0x0f && (unsigned char)(ahead - faction) != 0x0c)
        return;

    collectTax(state, faction);
}

// 0041d870, the unit arm.  A thousand bytes of movement, combat and claiming
// that has not been read yet; leaving it out means units sit still rather than
// behaving wrongly.
static void stepUnit(Sim *sim, unsigned index, unsigned faction) {
    (void)sim; (void)index; (void)faction;
}

void simInit(Sim *sim, GameState *state) {
    memset(sim, 0, sizeof *sim);
    sim->state = state;
    sim->humanFaction = 0;      // DAT_004365cd, until the menus set it
    sim->autoTax = 1;           // DAT_0043769c
}

void simStep(Sim *sim) {
    GameState *state = sim->state;
    for (int n = SWEEP_PER_CALL; n != 0; n--) {
        // 00417380 advances first, then wraps by subtracting 0x8ff.
        const unsigned previous = sim->cursor;
        sim->cursor = previous + 1;
        if (sim->cursor > WORLD_CELLS - 1) sim->cursor = previous - (WORLD_CELLS - 1);

        const unsigned index = sim->cursor;
        if (index >= WORLD_CELLS) continue;
        const unsigned char terrain = state->world.cells[index].terrain;
        const unsigned col = index / WORLD_GRID;
        const unsigned row = index % WORLD_GRID;

        if (terrain == 5) {
            stepNeutral(state, index, col, row);
        } else if (terrain >= 8 && terrain <= 0x0b) {
            stepUnit(sim, index, terrain - 8u);
        } else if (terrain >= 0x0c && terrain <= 0x0f) {
            stepClaimed(state, index, terrain - 0x0cu);
        } else if (terrain >= 0x14 && terrain <= 0x17) {
            stepCastle(sim, index, terrain - 0x14u);
        }
    }
    sim->frames++;
}
