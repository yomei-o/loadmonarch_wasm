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
#define CELL_VALUE_MAX 0xff        // 0041d870 clamps growth here
#define UNIT_VALUE 200             // and turns value into a unit at this
#define ENTITY_STRENGTH_CAP 100000

// The eight neighbours, from the paired tables at 00434420 and 00434428:
// west, east, north, south, then the four diagonals.
static const signed char kNeighbourDx[8] = {-1, 1, 0, 0, -1, 1, 1, -1};
static const signed char kNeighbourDy[8] = {0, 0, -1, 1, -1, -1, 1, 1};

// Only cells inside the border are worked on, which is the guard 0040b680
// applies before it indexes.
static int inBounds(int col, int row) {
    return col > 0 && row > 0 && col < WORLD_GRID - 1 && row < WORLD_GRID - 1;
}

// 0041ee10's tally of what surrounds a cell.
typedef struct {
    unsigned char ownGround;    // neighbours already this faction's ground
    unsigned char empty;        // neighbours holding nothing at all
    unsigned char foreign;      // neighbours below 0x0d - somebody else's
    unsigned char emptyCol;     // the first empty neighbour found
    unsigned char emptyRow;
} Neighbourhood;

static void scanNeighbours(const GameState *state, unsigned col, unsigned row,
                           unsigned faction, Neighbourhood *out) {
    memset(out, 0, sizeof *out);
    for (int i = 0; i < 8; i++) {
        const int nc = (int)col + kNeighbourDx[i];
        const int nr = (int)row + kNeighbourDy[i];
        if (!inBounds(nc, nr)) continue;
        const unsigned char t =
            state->world.cells[WORLD_INDEX((unsigned)nc, (unsigned)nr)].terrain;
        if (t == faction + 0x0cu) {
            out->ownGround++;
        } else if (t == 0) {
            if (++out->empty == 1) {
                out->emptyCol = (unsigned char)nc;
                out->emptyRow = (unsigned char)nr;
            }
        } else if (t < 0x0d) {
            out->foreign++;
        }
    }
}

// 0041c780: the first neighbour holding another faction's claimed ground -
// where a cell pushes when it has no empty land left to take.
static int pickEnemyGround(const GameState *state, unsigned col, unsigned row,
                           unsigned faction, unsigned char *outCol,
                           unsigned char *outRow) {
    for (int i = 0; i < 8; i++) {
        const int nc = (int)col + kNeighbourDx[i];
        const int nr = (int)row + kNeighbourDy[i];
        if (!inBounds(nc, nr)) continue;
        const unsigned char t =
            state->world.cells[WORLD_INDEX((unsigned)nc, (unsigned)nr)].terrain;
        if (t > 0x0b && t < 0x10 && t != faction + 0x0cu) {
            *outCol = (unsigned char)nc;
            *outRow = (unsigned char)nr;
            return 1;
        }
    }
    return 0;
}

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

// 0041d870's first branch: a faction carrying flag 0x40 is being relabelled.
// at1f names what its cells become - or they are wiped when it is 4 - and the
// change spreads over the 3x3 the original walks.
static void relabelFaction(GameState *state, unsigned index, unsigned col,
                           unsigned row, unsigned faction) {
    const Faction *owner = &state->factions[faction];
    const unsigned char becomes =
        owner->at1f == 4 ? 0 : (unsigned char)(owner->at1f + 8);
    const unsigned char groundBecomes =
        owner->at1f == 4 ? 0 : (unsigned char)(owner->at1f + 0x0c);
    state->world.cells[index].terrain = becomes;
    for (int dc = -1; dc < 2; dc++) {
        for (int dr = -1; dr < 2; dr++) {
            const int nc = (int)col + dc, nr = (int)row + dr;
            if (!inBounds(nc, nr)) continue;
            WorldCell *cell =
                &state->world.cells[WORLD_INDEX((unsigned)nc, (unsigned)nr)];
            if (cell->terrain == faction + 0x0cu) cell->terrain = groundBecomes;
        }
    }
}

// 0041d870's growth branch, which is how a country expands.  A unit's cell
// gains value for every neighbouring cell its own faction already holds; once
// that value covers the neighbours it feeds, the cell claims a piece of ground
// - empty land first, otherwise a neighbour's - and at 200 it turns the
// accumulated value into a unit, or hands it to the unit already standing
// there.
static void growFromUnit(Sim *sim, unsigned index, unsigned col, unsigned row,
                         unsigned faction) {
    GameState *state = sim->state;
    WorldCell *cell = &state->world.cells[index];

    Neighbourhood around;
    scanNeighbours(state, col, row, faction, &around);
    cell->value += around.ownGround + 1u;
    if ((around.ownGround + 1u) * 0x10u > cell->value) return;
    if (cell->value > CELL_VALUE_MAX) cell->value = CELL_VALUE_MAX;

    unsigned char takeCol = 0, takeRow = 0;
    int take;
    if (around.empty == 0) {
        take = pickEnemyGround(state, col, row, faction, &takeCol, &takeRow);
    } else {
        takeCol = around.emptyCol;
        takeRow = around.emptyRow;
        take = 1;
    }
    if (take) {
        WorldCell *target = &state->world.cells[WORLD_INDEX(takeCol, takeRow)];
        target->value = CELL_VALUE_RESET;
        target->terrain = (unsigned char)(faction + 0x0c);
        if (cell->value < UNIT_VALUE) return;
    }

    if (cell->owner < ENTITY_NONE) {
        Entity *entity = &state->entities[cell->owner];
        if (entity->faction != faction) return;
        entity->at08 += cell->value;
        cell->value = 1;
        if (entity->at08 > ENTITY_STRENGTH_CAP)
            entity->at08 = ENTITY_STRENGTH_CAP;
        return;
    }

    const unsigned slot = allocEntity(state);
    if (slot >= ENTITY_COUNT) return;
    Entity *entity = &state->entities[slot];
    entity->faction = (unsigned char)faction;
    entity->at08 = cell->value - 1;
    entity->position[0] = (unsigned char)col;
    entity->position[1] = (unsigned char)row;
    entity->target[0] = entity->position[0];
    entity->target[1] = entity->position[1];
    entity->flags = 0;
    entity->at220 = 0xff;
    cell->owner = (unsigned char)slot;
    cell->value = 1;
    // A unit the player raised carries the order the interface has selected
    // (DAT_004365e0); everyone else's gets the plain one.
    if (faction == sim->humanFaction && sim->pendingOrder != 1) {
        entity->flags |= 4;
        entity->at0d = (unsigned char)(sim->pendingOrder | 0x10);
        return;
    }
    entity->at0d = 1;
}

// 0041d870.
static void stepUnit(Sim *sim, unsigned index, unsigned faction) {
    if (faction >= FACTION_COUNT) return;
    GameState *state = sim->state;
    const unsigned col = index / WORLD_GRID;
    const unsigned row = index % WORLD_GRID;
    const unsigned flags = state->factions[faction].flags;
    if (flags & 0x40) {
        relabelFaction(state, index, col, row, faction);
        return;
    }
    if (flags & 1) return;
    growFromUnit(sim, index, col, row, faction);
}

void simInit(Sim *sim, GameState *state) {
    memset(sim, 0, sizeof *sim);
    sim->state = state;
    sim->humanFaction = 0;      // DAT_004365cd, until the menus set it
    sim->autoTax = 1;           // DAT_0043769c
    sim->pendingOrder = 1;      // DAT_004365e0, the order a new unit takes
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

/* ------------------------------------------------------------- actions */

// 0041a8d0.  Spends from the acting faction's purse, or fails.
int simSpend(GameState *state, unsigned faction, unsigned cost) {
    if (faction >= FACTION_COUNT) return 0;
    Faction *owner = &state->factions[faction];
    if (owner->funds < cost) return 0;
    owner->funds -= cost;
    return 1;
}

// 0041e670: does the 3x3 around this cell already hold one of this faction's
// unit cells?  Its caller wants the answer to be no - a new one may only go
// where none is adjacent, which is what keeps units spread out.
static int unitCellAdjacent(const GameState *state, unsigned col, unsigned row,
                            unsigned faction) {
    const unsigned char alt =
        (unsigned char)(state->factions[faction].at1e + 8);
    const unsigned char own = (unsigned char)(faction + 8);
    for (int dc = -1; dc < 2; dc++) {
        for (int dr = -1; dr < 2; dr++) {
            const int nc = (int)col + dc, nr = (int)row + dr;
            if (!inBounds(nc, nr)) continue;
            const unsigned char t = state->world.cells[
                WORLD_INDEX((unsigned)nc, (unsigned)nr)].terrain;
            if (t == alt || t == own) return 1;
        }
    }
    return 0;
}

// 00420b30.  Retires an entity.  Losing one that carries the leader bit
// (+0x0d bit 5) puts its whole faction into the state flag 0 selects - which
// is what stops that faction growing - and resets its remaining entities.
void simRetireEntity(GameState *state, unsigned slot, unsigned col,
                     unsigned row) {
    if (slot >= ENTITY_COUNT) return;
    Entity *entity = &state->entities[slot];
    entity->at220 = 0xff;
    entity->at08 = 0;
    entity->at18 = 0x1f0;
    entity->at0e = 3;
    if (entity->at0d & 0x20) {
        const unsigned faction = entity->faction;
        if (faction < FACTION_COUNT) {
            Faction *owner = &state->factions[faction];
            owner->flags |= 1;
            owner->at1f = entity->at0f;
            owner->at0c = 0x40;
            for (int i = 0; i < ENTITY_COUNT; i++) {
                Entity *other = &state->entities[i];
                if (other->flags & 0x80) continue;
                if (other->faction != faction) continue;
                other->at0d = (unsigned char)((other->at0d & 0x20) | 0x0c);
                other->at0c = 6;
                other->flags |= 1;
                other->at220 = 0xff;
                other->at18 = 0x1f0;
            }
        }
    }
    if (inBounds((int)col, (int)row))
        state->world.cells[WORLD_INDEX(col, row)].owner = CELL_NO_ENTITY;
    entity->flags = 0x80;
}

// 0040b330: the order that turns ground into one of the faction's unit cells.
// It costs a hundred from the purse plus up to two hundred of the acting
// entity's own strength, and the entity is retired when that is all it had.
SimActionResult simBuildUnitCell(Sim *sim, unsigned slot, unsigned col,
                                 unsigned row) {
    GameState *state = sim->state;
    if (slot >= ENTITY_COUNT) return SIM_ACTION_REFUSED;
    if (!inBounds((int)col, (int)row)) return SIM_ACTION_REFUSED;
    Entity *entity = &state->entities[slot];
    if (entity->flags & 0x80) return SIM_ACTION_REFUSED;
    const unsigned faction = entity->faction;
    if (faction >= FACTION_COUNT) return SIM_ACTION_REFUSED;

    const unsigned index = WORLD_INDEX(col, row);
    WorldCell *cell = &state->world.cells[index];
    const unsigned char t = cell->terrain;
    // Empty land, or ground somebody has claimed - nothing else.
    if (t != 0 && (t < 0x0c || t > 0x10)) return SIM_ACTION_REFUSED;
    if (unitCellAdjacent(state, col, row, faction)) return SIM_ACTION_REFUSED;
    if (!simSpend(state, faction, 100)) return SIM_ACTION_NO_FUNDS;

    unsigned spend = entity->at08;
    if (spend > 199) spend = 200;
    cell->terrain = (unsigned char)(faction + 8);
    cell->value = (spend >> 1) + 1;
    if (entity->at08 <= spend) {
        simRetireEntity(state, slot, entity->position[0], entity->position[1]);
        return SIM_ACTION_SPENT_ENTITY;
    }
    entity->at08 -= spend;
    return SIM_ACTION_DONE;
}

// Not from the executable.  A faction only earns while an entity carrying the
// leader bit stands on its castle (0041dc60 tests it), and only grows while
// that bit is intact (00420b30 clears the faction otherwise) - but nothing in
// the decompilation has been found that *sets* that bit, so the original
// probably starts a stage from a saved template.  Until that is read, this
// puts one leader on each castle so a stage can begin at all.  It is marked
// out here rather than dressed up as the original's own doing.
void simSeedLeaders(Sim *sim) {
    GameState *state = sim->state;
    for (unsigned i = 0; i < WORLD_CELLS; i++) {
        const unsigned char t = state->world.cells[i].terrain;
        if (t < 0x14 || t > 0x17) continue;
        const unsigned faction = t - 0x14u;
        const unsigned slot = allocEntity(state);
        if (slot >= ENTITY_COUNT) return;
        Entity *entity = &state->entities[slot];
        entity->faction = (unsigned char)faction;
        entity->position[0] = (unsigned char)(i / WORLD_GRID);
        entity->position[1] = (unsigned char)(i % WORLD_GRID);
        entity->target[0] = entity->position[0];
        entity->target[1] = entity->position[1];
        entity->flags = 0;
        entity->at08 = 200;
        entity->at0c = 6;
        entity->at0d = 0x20 | 1;        // the leader bit, plus the plain order
        entity->at0f = 4;               // what the faction becomes if lost
        entity->at18 = 0x1f0;
        entity->at220 = 0xff;
        state->world.cells[i].owner = (unsigned char)slot;
    }
    (void)sim;
}

// The human faction's first active entity, which is what the click below acts
// through.  The original routes an order to a chosen entity and lets it walk
// there; that selection and movement live in code not read yet.
unsigned simHumanActor(const Sim *sim) {
    for (unsigned i = 0; i < ENTITY_COUNT; i++) {
        const Entity *entity = &sim->state->entities[i];
        if (entity->flags & 0x80) continue;
        if (entity->faction == sim->humanFaction) return i;
    }
    return ENTITY_COUNT;
}
