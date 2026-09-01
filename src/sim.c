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
#define ROUTE_EMPTY 0x1f0          // what +0x18 holds when there is no route

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
    simStepEntities(sim);
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

// 0040b440: the wall.  Terrain 0x7b is one, and a unit raises it on bare land
// or on ground its faction already holds - pouring work in at a quarter the
// cost clearing charges.  A finished wall blocks movement, which is why the
// original refreshes every cell's +0x05 the moment one goes up.
//
// An existing wall can be reinforced up to 0xff.  A cell with somebody
// standing on it refuses, and anything else falls through to the raid the
// caller handles.
SimActionResult simBuildWall(Sim *sim, unsigned slot) {
    GameState *state = sim->state;
    if (slot >= ENTITY_COUNT) return SIM_ACTION_REFUSED;
    Entity *entity = &state->entities[slot];
    const unsigned col = entity->target[0];
    const unsigned row = entity->target[1];
    if (col == 0 || row == 0 || col > 0x2e || row > 0x2e)
        return SIM_ACTION_REFUSED;
    const unsigned faction = entity->faction;
    if (faction >= FACTION_COUNT) return SIM_ACTION_REFUSED;

    WorldCell *cell = &state->world.cells[WORLD_INDEX(col, row)];
    if (cell->owner < ENTITY_NONE) return SIM_ACTION_NO_FUNDS;  // 0040b440's 2

    const unsigned strengthWork = entity->at08 >> 4;

    if (cell->terrain == 0x7b) {
        // Reinforcing one that is already there.
        unsigned room = cell->value < 0xffu ? 0xffu - cell->value : 0u;
        unsigned amount = room < strengthWork ? room : strengthWork;
        if (!simSpend(state, faction, amount >> 2)) return SIM_ACTION_NO_FUNDS;
        cell->value = cell->value < 0xffu ? cell->value + amount : 0xffu;
        return SIM_ACTION_DONE;
    }

    const int owned = cell->terrain >= 0x0c && cell->terrain <= 0x10;
    if (cell->terrain != 0 && !owned) return SIM_ACTION_REFUSED;

    unsigned amount = cell->value + 0xffu;
    if (amount > strengthWork) amount = strengthWork;
    if (!simSpend(state, faction, amount >> 2)) return SIM_ACTION_NO_FUNDS;

    if (cell->value < amount) {
        cell->value = amount - cell->value;
        cell->terrain = 0x7b;
        // 00405330 again: a wall is terrain at or above 0x30, so every cell's
        // blocked flag has to be worked out afresh.
        stateMarkBlocked(state);
        return SIM_ACTION_DONE;
    }
    cell->value -= amount;
    return SIM_ACTION_PROGRESS;
}

// 0040b680: clearing.  A unit works on the cell its target names - terrain
// 0x30..0x5f is an obstacle, and 0x7a is the one that pays out - spending
// funds at thirty a unit of work, or two for the 0x7a, and putting in at most
// a sixteenth of its own strength.  When the cell's value runs out it becomes
// 0x20, which is walkable.
//
// The original gates this on 0041ac10, which is not read; here the target has
// to be inside the border, which is the guard 0040b680 itself applies next.
SimActionResult simClearTarget(Sim *sim, unsigned slot) {
    GameState *state = sim->state;
    if (slot >= ENTITY_COUNT) return SIM_ACTION_REFUSED;
    Entity *entity = &state->entities[slot];
    const unsigned col = entity->target[0];
    const unsigned row = entity->target[1];
    if (col == 0 || row == 0 || col > 0x2e || row > 0x2e)
        return SIM_ACTION_REFUSED;
    const unsigned faction = entity->faction;
    if (faction >= FACTION_COUNT) return SIM_ACTION_REFUSED;

    WorldCell *cell = &state->world.cells[WORLD_INDEX(col, row)];
    unsigned cost, work;
    if (cell->terrain == 0x7a) {
        cost = 2;
        work = cell->value + 0xff;
    } else if (cell->terrain >= 0x30 && cell->terrain <= 0x5f) {
        cost = 0x1e;
        work = cell->value + 1;
    } else {
        return SIM_ACTION_REFUSED;
    }

    unsigned amount = entity->at08 >> 4;
    if (work < amount) amount = work;
    if (!simSpend(state, faction, amount * cost)) return SIM_ACTION_NO_FUNDS;

    if (cell->value > amount) {
        cell->value -= amount;
        return SIM_ACTION_PROGRESS;
    }
    // 0040b680 leaves the overshoot behind as the new cell's value.
    cell->value = amount - cell->value;
    cell->terrain = 0x20;
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
        // 2000 rather than the 200 a unit costs to raise, so a stage can be
        // played rather than spending its only leader on the first order.
        // Another thing this function invents; see above.
        entity->at08 = 2000;
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

/* ------------------------------------------------------ routes, 00405250 */

// The tables at 00434130 and 00434150.  The first is a diamond: an offset of
// up to three cells maps to a row number, and anything further out maps to
// zero.  The rows are three-step paths, and reading them settles the encoding
// the routes use - 2 north, 6 south, 0 west, 4 east.
//
// What 5 means in a route is NOT settled.  0041d6d0 maps it to (+1,+1), and a
// leader with no route walks that way, which the port checks; but row 13 is
// the (0,0) offset and reads 5 5 5, which cannot be three steps south-east.
// Treating it as a do-nothing filler was tried and it broke the verified walk,
// so the tables are kept as the data they are and the question is left open
// rather than answered by guesswork.
static const unsigned char kRouteRow[7][7] = {
    /* dy=-3 */ {0, 0, 0, 1, 0, 0, 0},
    /* dy=-2 */ {0, 0, 2, 3, 4, 0, 0},
    /* dy=-1 */ {0, 5, 6, 7, 8, 9, 0},
    /* dy= 0 */ {10, 11, 12, 13, 14, 15, 16},
    /* dy=+1 */ {0, 17, 18, 19, 20, 21, 0},
    /* dy=+2 */ {0, 0, 22, 23, 24, 0, 0},
    /* dy=+3 */ {0, 0, 0, 25, 0, 0, 0},
};
static const unsigned char kRouteSteps[26][3] = {
    {6, 2, 2}, {2, 2, 2}, {2, 2, 0}, {2, 2, 5}, {2, 2, 4}, {2, 0, 0},
    {2, 0, 5}, {2, 5, 5}, {2, 4, 5}, {2, 4, 4}, {0, 0, 0}, {0, 0, 5},
    {0, 5, 5}, {5, 5, 5}, {4, 5, 5}, {4, 4, 5}, {4, 4, 4}, {6, 0, 0},
    {6, 0, 5}, {6, 5, 5}, {6, 4, 5}, {6, 4, 4}, {6, 6, 0}, {6, 6, 5},
    {6, 6, 4}, {6, 6, 6},
};

// 00405250.  Gives an entity a three-step path to a cell up to three away and
// points its target at the far end.
//
// The original works out the length as weight[dy] + weight[dx] from a
// four-entry {0,1,2,3} on its own stack, indexed by the raw offset - so a
// negative one reads past that array, and one of its six callers does pass
// (-3,-3), which the diamond has no row for either.  The length it means is
// the number of real steps, which is |dx| + |dy|, and that is what this uses.
void simMakeRoute(GameState *state, unsigned slot, int dx, int dy) {
    if (slot >= ENTITY_COUNT) return;
    if (dx < -3 || dx > 3 || dy < -3 || dy > 3) return;
    Entity *entity = &state->entities[slot];
    const unsigned char row = kRouteRow[dy + 3][dx + 3];
    entity->at18 = 0;
    entity->at14 = (unsigned)((dx < 0 ? -dx : dx) + (dy < 0 ? -dy : dy));
    entity->route[0] = kRouteSteps[row][0];
    entity->route[1] = kRouteSteps[row][1];
    entity->route[2] = kRouteSteps[row][2];
    entity->target[0] = (unsigned char)((int)entity->position[0] + dx);
    entity->target[1] = (unsigned char)((int)entity->position[1] + dy);
}

// 00405200.  One step along, and the route is spent once the index reaches the
// length - which is what puts 0x1f0 back.
int simAdvanceRoute(GameState *state, unsigned slot) {
    if (slot >= ENTITY_COUNT) return 0;
    Entity *entity = &state->entities[slot];
    if (entity->at18 == ROUTE_EMPTY) return 0;
    entity->at18++;
    if (entity->at14 <= entity->at18) {
        entity->at18 = ROUTE_EMPTY;
        return 0;
    }
    return 1;
}

/* ------------------------------------------------- entities, 004204f0 */

static void stepPlainUnit(Sim *sim, unsigned slot);     // 00401770, below
static void stepOrderedUnit(Sim *sim, unsigned slot);  // 00402bc0, below
static int trampleGround(GameState *state, unsigned index, unsigned faction);
static int payUpkeep(GameState *state, unsigned slot, unsigned index,
                     unsigned faction);

// 0041d6d0's table, read off the sixteen words it builds on the stack.  A
// direction is a column delta and a row delta; 5 is the one 0041d690 falls
// back on when an entity has no route.
static const signed char kStepDx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
static const signed char kStepDy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
#define DIRECTION_DEFAULT 5

// 0041d690: the next direction comes out of the route the entity carries -
// +0x18 indexes into the bytes from +0x1c, which is what most of the 0x224
// record is for.
static unsigned char nextDirection(const Entity *entity) {
    if (entity->at18 == ROUTE_EMPTY) return DIRECTION_DEFAULT;
    if (entity->at18 >= sizeof entity->route) return DIRECTION_DEFAULT;
    return entity->route[entity->at18];
}

// 0041ec30: the step has to land strictly inside the border.
static int stepInBounds(unsigned col, unsigned row, int dx, int dy) {
    const int nc = (int)col + dx, nr = (int)row + dy;
    return nc > 0 && nc < WORLD_GRID && nr > 0 && nr < WORLD_GRID;
}

// 00420af0: an entity marked dying gets three ticks before it is retired.
static void stepDying(GameState *state, unsigned slot, unsigned col,
                      unsigned row) {
    Entity *entity = &state->entities[slot];
    entity->at0e++;
    if (entity->at0e > 3) simRetireEntity(state, slot, col, row);
}

/* ------------------------------------------- meeting somebody, 00401000 */

// 00420e70.  Damage is capped by what the defender has, tallied into the
// defender faction's +0x14, and a defender it finishes is marked dying with
// the *attacker's faction* as the cause - which is how a country changes
// hands: 00420b30 copies that cause into the faction's +0x1f, and the unit
// arm's relabel branch then repaints its cells in the winner's colour.
static void dealDamage(GameState *state, unsigned attacker, unsigned defender,
                       unsigned damage) {
    if (attacker >= ENTITY_COUNT || defender >= ENTITY_COUNT) return;
    Entity *victim = &state->entities[defender];
    unsigned dealt = damage;
    if (dealt > victim->at08) dealt = victim->at08;
    if (victim->faction < FACTION_COUNT)
        state->factions[victim->faction].at14 += dealt;
    if (victim->at08 <= dealt) {
        simMarkDying(state, defender, state->entities[attacker].faction);
        return;
    }
    victim->at08 -= dealt;
}

// 00420c60: the fight.  Standing on a castle a unit strikes for a quarter of
// its strength and takes nothing back; against a unit on a castle the exchange
// is even; in the open the attacker gives an eighth and receives a sixteenth.
static int fightAt(Sim *sim, unsigned slot, unsigned col, unsigned row) {
    GameState *state = sim->state;
    const unsigned index = WORLD_INDEX(col, row);
    const unsigned char target = state->world.cells[index].owner;
    if (target >= ENTITY_NONE) return 0;
    Entity *me = &state->entities[slot];
    Entity *them = &state->entities[target];
    if (them->faction == me->faction) return 0;
    if (me->faction < FACTION_COUNT &&
        state->factions[me->faction].at1e == them->faction) return 0;
    if ((them->at0d & 0x0f) == 0x0c) return 0;      // it has no leader left
    if (them->at18 > 0x1ef) {
        const unsigned char facing = (unsigned char)((me->at0c + 4) & 6);
        if (them->at0c != facing) them->at0c = facing;
    }

    const unsigned here = WORLD_INDEX(me->position[0], me->position[1]);
    const unsigned onCastle = (unsigned)(state->world.cells[here].terrain
                                         - 0x14u);
    if (onCastle < 4) {
        dealDamage(state, slot, target, (me->at08 >> 2) + 1);
        return 1;
    }
    const unsigned theirCastle =
        (unsigned)(state->world.cells[index].terrain - 0x14u);
    if (theirCastle < 4) {
        dealDamage(state, slot, target, (me->at08 >> 3) + 1);
        dealDamage(state, target, slot, (them->at08 >> 3) + 1);
        return 1;
    }
    dealDamage(state, slot, target, (me->at08 >> 3) + 1);
    dealDamage(state, target, slot, (them->at08 >> 4) + 1);
    return 1;
}

// 00420610: two of the same faction meeting merge, and the leader is the one
// that absorbs.  The original has a further branch for the two ordered roles
// (+0x0d bit 4) which is not read; those pairs are left to pass by instead.
static int mergeAt(Sim *sim, unsigned slot, unsigned col, unsigned row) {
    GameState *state = sim->state;
    const unsigned char other = state->world.cells[WORLD_INDEX(col, row)].owner;
    if (other >= ENTITY_NONE) return 0;
    Entity *me = &state->entities[slot];
    Entity *them = &state->entities[other];
    if (them->faction != me->faction) return 0;
    if (them->flags & 2) return 0;
    if (them->at08 + me->at08 > 100000) return 0;

    if (me->at0d & 0x20) {                  // I am the leader: it joins me
        me->at08 += them->at08;
        simRetireEntity(state, other, col, row);
        return 0;                           // and I carry on into the cell
    }
    if (them->at0d & 0x20) {                // it is: I join it
        them->at08 += me->at08;
        simRetireEntity(state, slot, me->position[0], me->position[1]);
        return 1;
    }
    return 0;
}

// 004208b0: walking into another faction's settlement raids it.  The cell's
// value falls by the attacker's strength, and when there is none left the
// settlement is razed back to bare land.
static int raidSettlement(Sim *sim, unsigned slot, unsigned col,
                          unsigned row) {
    GameState *state = sim->state;
    const unsigned index = WORLD_INDEX(col, row);
    WorldCell *cell = &state->world.cells[index];
    const unsigned char owner = (unsigned char)(cell->terrain - 8);
    if (owner > 3) return 0;
    Entity *me = &state->entities[slot];
    if (owner == me->faction) return 0;
    if (me->faction < FACTION_COUNT &&
        state->factions[me->faction].at1e == owner) return 0;

    unsigned damage = me->at08;
    if (damage > cell->value) damage = cell->value;
    state->factions[owner].at14 += damage;
    if (damage < cell->value) {
        cell->value -= damage;
        return 1;
    }
    cell->value = CELL_VALUE_RESET;
    cell->terrain = 0;
    return 1;
}

// 0041ef80.  Before a unit gets on with its order it looks for a fight: the
// four square directions, starting from the one it faces, and the first
// neighbour 00420c60 will take is struck without the unit moving at all.
static int lashOut(Sim *sim, unsigned slot, unsigned col, unsigned row) {
    const Entity *entity = &sim->state->entities[slot];
    for (int turn = 0; turn < 8; turn += 2) {
        const unsigned dir = (unsigned)((entity->at0c + turn) & 6);
        const int dx = kStepDx[dir], dy = kStepDy[dir];
        if (!stepInBounds(col, row, dx, dy)) continue;
        if (fightAt(sim, slot, (unsigned)((int)col + dx),
                    (unsigned)((int)row + dy)))
            return 1;
    }
    return 0;
}

// 00401000's ordinary path: face the way the route says, and only once facing
// it, take the step.  Turning costs a tick, which is why units visibly pivot
// before they set off.
//
// What happens when the destination holds somebody is 00420c60, 00420610 and
// 004208b0 above, asked in that order.
static void stepWalk(Sim *sim, unsigned slot) {
    GameState *state = sim->state;
    Entity *entity = &state->entities[slot];
    const unsigned col = entity->position[0];
    const unsigned row = entity->position[1];
    const unsigned char want = nextDirection(entity);

    if (entity->at0c != want) {
        entity->at0c = want;
        entity->at0e = entity->at0c;
        return;
    }
    if (want >= 8) return;
    const int dx = kStepDx[want], dy = kStepDy[want];
    if (!stepInBounds(col, row, dx, dy)) {
        if (entity->faction != sim->humanFaction) entity->at18 = ROUTE_EMPTY;
        return;
    }
    const unsigned nc = (unsigned)((int)col + dx);
    const unsigned nr = (unsigned)((int)row + dy);
    WorldCell *to = &state->world.cells[WORLD_INDEX(nc, nr)];
    if (to->terrain >= TERRAIN_WALKABLE_MAX) {
        if (entity->faction != sim->humanFaction) entity->at18 = ROUTE_EMPTY;
        return;
    }
    // 00401000 asks the three in this order: fight, merge, then raid.  Any of
    // them consuming the step means the unit stays where it is.
    if (fightAt(sim, slot, nc, nr)) return;
    if (mergeAt(sim, slot, nc, nr)) return;
    if (entity->flags & 0x80) return;      // a merge can retire the mover
    if (to->owner < ENTITY_NONE) {
        if (entity->faction != sim->humanFaction) entity->at18 = ROUTE_EMPTY;
        return;
    }
    if (raidSettlement(sim, slot, nc, nr)) return;
    state->world.cells[WORLD_INDEX(col, row)].owner = CELL_NO_ENTITY;
    to->owner = (unsigned char)slot;
    entity->position[0] = (unsigned char)nc;
    entity->position[1] = (unsigned char)nr;
    simAdvanceRoute(state, slot);       // 00401000's closing 00405200
}

// 00403170's walk.  The same step as the leader's, with one thing more: when
// the way is blocked it spends a turn of patience from +0x0f, and once that
// runs out it abandons the route and takes the plain order.  That is why a
// unit does not stand forever against a wall.
//
// The original guards the giving-up with 0041eb60 and 0041a800, neither of
// which is read; here the counter alone decides.
static void stepWalkOrdered(Sim *sim, unsigned slot) {
    GameState *state = sim->state;
    Entity *entity = &state->entities[slot];
    const unsigned col = entity->position[0];
    const unsigned row = entity->position[1];
    const unsigned char want = nextDirection(entity);

    if (entity->at0c != want) {
        entity->at0c = want;
        entity->at0e = entity->at0c;
        return;
    }
    if (want >= 8) return;
    const int dx = kStepDx[want], dy = kStepDy[want];

    if (!stepInBounds(col, row, dx, dy)) {
        entity->at0d = 1;
        entity->at18 = ROUTE_EMPTY;
        return;
    }
    const unsigned nc = (unsigned)((int)col + dx);
    const unsigned nr = (unsigned)((int)row + dy);
    WorldCell *to = &state->world.cells[WORLD_INDEX(nc, nr)];

    // A turn of patience is spent whenever the step does not happen.
    const int giveUp = --entity->at0f == 0;
    if (giveUp) {
        entity->at0f = 1;
        entity->at0d = 1;
        entity->at18 = ROUTE_EMPTY;
    }

    if (to->terrain >= TERRAIN_WALKABLE_MAX) return;
    if (fightAt(sim, slot, nc, nr)) return;
    if (mergeAt(sim, slot, nc, nr)) return;
    if (entity->flags & 0x80) return;
    if (to->owner < ENTITY_NONE) return;
    if (raidSettlement(sim, slot, nc, nr)) return;
    if (giveUp) return;

    // The way is clear: take it, and the patience spent above is returned.
    entity->at0f++;
    state->world.cells[WORLD_INDEX(col, row)].owner = CELL_NO_ENTITY;
    to->owner = (unsigned char)slot;
    entity->position[0] = (unsigned char)nc;
    entity->position[1] = (unsigned char)nr;
    simAdvanceRoute(state, slot);
}

// 0041abd0 over 0041abf0.  The original's own generator is the Microsoft C
// rand() the executable carries; this is a generator of the same shape, kept
// here so a stage plays the same way twice rather than to match the original's
// sequence - which it does not.
static unsigned g_random = 1;

static unsigned simRandom(unsigned limit) {
    g_random = g_random * 1103515245u + 12345u;
    const unsigned value = (g_random >> 16) & 0x7fffu;
    return limit ? value % limit : 0u;
}

// 00402700, the neutral entity.  +0x0f is its wander timer: bit 7 means it is
// resting, and it only steps on an even tick, which is what makes the little
// figures amble rather than march.
static void stepNeutralEntity(Sim *sim, unsigned slot) {
    GameState *state = sim->state;
    Entity *entity = &state->entities[slot];

    entity->at0f--;
    if (entity->at0f & 0x80) {
        if ((entity->at0f & 0x7f) == 0)
            entity->at0f = (unsigned char)(simRandom(0x14) * 2 + 0x14);
        return;
    }
    if (entity->at0f == 0) {
        const unsigned r = simRandom(0x14);
        if (r < 0x0b) entity->at0f = (unsigned char)(r | 0x80);   // a rest
        else entity->at0f = (unsigned char)(simRandom(0x14) * 2 + 0x14);
        return;
    }
    if (entity->at0f & 1) return;            // it moves on even ticks only

    const unsigned col = entity->position[0];
    const unsigned row = entity->position[1];
    if (!inBounds((int)col, (int)row)) return;
    trampleGround(state, WORLD_INDEX(col, row), entity->faction);

    const unsigned char dir = entity->at0c;
    if (dir < 8 && stepInBounds(col, row, kStepDx[dir], kStepDy[dir])) {
        const unsigned nc = (unsigned)((int)col + kStepDx[dir]);
        const unsigned nr = (unsigned)((int)row + kStepDy[dir]);
        WorldCell *to = &state->world.cells[WORLD_INDEX(nc, nr)];
        // 0x1d is refused as well as anything from 0x30 up - the one terrain a
        // wanderer will not walk onto.
        if (to->terrain < TERRAIN_WALKABLE_MAX && to->terrain != 0x1d) {
            if (fightAt(sim, slot, nc, nr)) return;
            if (mergeAt(sim, slot, nc, nr)) return;
            if (entity->flags & 0x80) return;
            if (to->owner < ENTITY_NONE) {
                // Somebody is in the way: turn, sometimes about face.
                entity->at0c = (unsigned char)((simRandom(100) < 0x32 ? 4u : 2u)
                                               + entity->at0c) & 7u;
                return;
            }
            if (raidSettlement(sim, slot, nc, nr)) return;
            entity->at0f--;
            if (entity->at0f != 0) {
                state->world.cells[WORLD_INDEX(col, row)].owner =
                    CELL_NO_ENTITY;
                to->owner = (unsigned char)slot;
                entity->position[0] = (unsigned char)nc;
                entity->position[1] = (unsigned char)nr;
                return;
            }
        }
    }

    // It could not go that way.  The original now scans the four square
    // directions through 0041f020 and builds a mask of which are open, falling
    // back to all eight - neither that routine nor the mask is read, so this
    // simply picks a new heading and tries again later.
    entity->at0f = (unsigned char)(simRandom(10) + 1);
    entity->at0c = (unsigned char)(simRandom(8));
}

// 004204f0: the entity cursor, the counterpart of the cell sweep.  It walks
// 0x3f of the sixty-four entities per call and picks a behaviour by role.
// Only the leader's walk is ported; the neutral (00402700), plain (00401770)
// and the two ordered behaviours (00403170, 00402bc0) are thousands of bytes
// each and are left alone rather than approximated.
void simStepEntities(Sim *sim) {
    GameState *state = sim->state;
    for (int n = 0x3f; n != 0; n--) {
        const unsigned previous = sim->entityCursor;
        sim->entityCursor = previous + 1;
        if (sim->entityCursor > 0x3f) sim->entityCursor = previous - 0x3f;
        const unsigned slot = sim->entityCursor;
        if (slot >= ENTITY_COUNT) continue;

        Entity *entity = &state->entities[slot];
        if (entity->flags & 0x80) continue;
        const unsigned col = entity->position[0];
        const unsigned row = entity->position[1];
        entity->flags &= (unsigned char)~1u;

        if (entity->flags & 2) {
            stepDying(state, slot, col, row);
            continue;
        }
        if (entity->faction == 4) {
            stepNeutralEntity(sim, slot);               // 00402700
            continue;
        }
        if (entity->at0d & 0x20) {
            stepWalk(sim, slot);                        // 00401000
            continue;
        }
        if (entity->at0d & 0x10) {
            stepOrderedUnit(sim, slot);                 // 00402bc0
            // A unit with a route walks it, by 00403170's step rather than
            // the leader's - the difference is the patience counter.
            if (entity->at18 != ROUTE_EMPTY) stepWalkOrdered(sim, slot);
            continue;
        }
        stepPlainUnit(sim, slot);                       // 00401770
    }
}

/* --------------------------------------------- the plain unit, 00401770 */

// 00420aa0: mark an entity dying, with a cause in +0x0f.  The cursor's dying
// arm then counts three ticks before it goes.
void simMarkDying(GameState *state, unsigned slot, unsigned char cause) {
    if (slot >= ENTITY_COUNT) return;
    Entity *entity = &state->entities[slot];
    if ((entity->flags & 2) == 0) {
        entity->flags |= 2;
        entity->at0f = cause;
        entity->at0e = 0;
    }
    entity->at08 = 0;
}

// 0041a920, the upkeep.  Standing on a castle or on its own faction's unit
// cell, a unit is paid for out of the treasury - a small slice of its own
// strength.  Anywhere else it eats that strength instead, and starves.
static int payUpkeep(GameState *state, unsigned slot, unsigned index,
                     unsigned faction) {
    Entity *entity = &state->entities[slot];
    const unsigned char t = state->world.cells[index].terrain;
    const int onCastle = (int)t - 0x14 >= 0 && (int)t - 0x14 < 4;
    const int onOwnUnit = (unsigned char)(t - faction) == 8;
    if (onCastle || onOwnUnit) {
        if (simSpend(state, faction, entity->at08 >> 11)) return 1;
    }
    const unsigned drain = (entity->at08 >> 8) + 1;
    if (entity->at08 <= drain) {
        simMarkDying(state, slot, 4);
        return 0;
    }
    entity->at08 -= drain;
    return 1;
}

// 00420a40: walking over ground another faction has claimed wipes it.  An
// ally named by +0x1e is spared.
static int trampleGround(GameState *state, unsigned index, unsigned faction) {
    WorldCell *cell = &state->world.cells[index];
    const int owner = (int)cell->terrain - 0x0c;
    if (owner < 0 || owner >= 4) return 0;
    if ((unsigned)owner == faction) return 0;
    if (state->factions[faction].at1e == (unsigned char)owner) return 0;
    cell->terrain = 0;
    return 1;
}

/* ------------------------------------------------ orders, 00402bc0 */

// The offsets both choosers look along, from 00434400 and 00434410: one cell
// each way, then two.  Index zero is unused - the original starts at one.
static const signed char kLookDx[9] = {0, -1, 1, 0, 0, -2, 2, 0, 0};
static const signed char kLookDy[9] = {0, 0, 0, -1, 1, 0, 0, -2, 2};

// 0041ebf0.  Inside the border and not blocked terrain.
static int passableCell(const GameState *state, int col, int row) {
    if (col <= 0 || row <= 0 || col >= 0x2f || row >= 0x2f) return 0;
    return state->world.cells[WORLD_INDEX((unsigned)col, (unsigned)row)]
               .blocked == 0;
}

// 0041e700's first test: a friendly already there whose strength added to this
// one would pass the hundred thousand cap.  The rest of that routine is not
// read; this is the part its callers act on.
static int wouldOverflow(const GameState *state, unsigned slot, int col,
                         int row) {
    const unsigned char other =
        state->world.cells[WORLD_INDEX((unsigned)col, (unsigned)row)].owner;
    if (other >= ENTITY_NONE || other == slot) return 0;
    const Entity *them = &state->entities[other];
    const Entity *me = &state->entities[slot];
    if (them->faction != me->faction) return 0;
    return them->at08 + me->at08 > 100000u;
}

// The pair of choosers share a shape: walk the eight offsets, remember which
// were impassable in a shifting mask, and skip a candidate whose path was
// blocked four steps back.  That mask is what stops a unit setting off towards
// something on the far side of a wall.
static int chooseAlong(const GameState *state, unsigned slot, int wantEnemy,
                       signed char *outDx, signed char *outDy) {
    const Entity *me = &state->entities[slot];
    const int col = me->position[0], row = me->position[1];
    if (!passableCell(state, col, row)) return 0;
    const unsigned faction = me->faction;

    int mask = 0;
    for (int i = 1; i < 9; i++) {
        mask >>= 1;
        const int nc = kLookDx[i] + col;
        const int nr = kLookDy[i] + row;
        if (!passableCell(state, nc, nr)) {
            mask |= 0x80;
            continue;
        }
        if (mask & 8) continue;
        const unsigned char t = state->world.cells[
            WORLD_INDEX((unsigned)nc, (unsigned)nr)].terrain;
        int wanted;
        if (wantEnemy) {
            // 0041e0a0: somebody else's settlement, and not an ally's.
            wanted = t > 7 && t < 0x0c &&
                     (unsigned char)(t - 8) != faction &&
                     state->factions[faction].at1e != (unsigned char)(t - 8);
        } else {
            // 0041e560: one of its own.
            wanted = t == (unsigned char)(faction + 8);
        }
        if (!wanted) continue;
        if (wouldOverflow(state, slot, nc, nr)) continue;
        *outDx = kLookDx[i];
        *outDy = kLookDy[i];
        return 1;
    }
    return 0;
}

// 0041e560.  A unit already standing on one of its own settlements stays.
static int chooseHome(const GameState *state, unsigned slot,
                      signed char *dx, signed char *dy) {
    const Entity *me = &state->entities[slot];
    const unsigned index = WORLD_INDEX(me->position[0], me->position[1]);
    if ((unsigned char)(state->world.cells[index].terrain - me->faction) == 8)
        return 0;
    return chooseAlong(state, slot, 0, dx, dy);
}

// 00403100.  Back to the plain order, and off towards home if there is one.
static void fallbackOrder(Sim *sim, unsigned slot) {
    GameState *state = sim->state;
    Entity *entity = &state->entities[slot];
    entity->flags &= (unsigned char)~4u;
    entity->at0d = 1;
    signed char dx = 0, dy = 0;
    if (chooseHome(state, slot, &dx, &dy)) {
        simMakeRoute(state, slot, dx, dy);
        return;
    }
    entity->at0c = 6;
}

// 00402bc0 and 00403170's shared shape.  Upkeep, a swing at anything
// adjacent, then the order - whose high bits 00403170 also reads.
static void stepOrderedUnit(Sim *sim, unsigned slot) {
    GameState *state = sim->state;
    Entity *entity = &state->entities[slot];
    const unsigned faction = entity->faction;
    if (faction >= FACTION_COUNT) return;
    const unsigned col = entity->position[0];
    const unsigned row = entity->position[1];
    if (!inBounds((int)col, (int)row)) return;
    const unsigned index = WORLD_INDEX(col, row);

    if (!payUpkeep(state, slot, index, faction)) return;
    trampleGround(state, index, faction);
    if (lashOut(sim, slot, col, row)) return;

    switch (entity->at0d & 0x0f) {
    case 0:
        entity->at0c = 6;
        entity->flags &= (unsigned char)~4u;
        return;
    case 2:
        // 00403170's case 2: face south and build where you stand.
        entity->at0c = 6;
        simBuildUnitCell(sim, slot, col, row);
        return;
    case 4: {
        // 00403170 reads the high bits of +0x0d here as well as the order:
        // bit 7 means keep hunting, bit 6 puts the unit back to ordered-idle,
        // and neither means go home and build.  0041e0a0 finds the quarry.
        signed char dx = 0, dy = 0;
        if (entity->at0d & 0x80) {
            if ((entity->flags & 8) == 0 &&
                chooseAlong(state, slot, 1, &dx, &dy)) {
                simMakeRoute(state, slot, dx, dy);
                entity->flags &= (unsigned char)~4u;
                return;
            }
            fallbackOrder(sim, slot);
            return;
        }
        if (entity->at0d & 0x40) {
            entity->at0d = 0x10;
            return;
        }
        entity->at0d = 1;
        if (chooseHome(state, slot, &dx, &dy)) simMakeRoute(state, slot, dx, dy);
        else entity->at0c = 6;
        return;
    }
    case 5:
        if (simBuildUnitCell(sim, slot, col, row) == SIM_ACTION_DONE) return;
        fallbackOrder(sim, slot);
        return;
    case 6: {
        // 00403170's case 6 is the wall, and its tail matches case 7's.
        const SimActionResult r = simBuildWall(sim, slot);
        if (r == SIM_ACTION_PROGRESS || r == SIM_ACTION_DONE) return;
        if (r == SIM_ACTION_REFUSED &&
            raidSettlement(sim, slot, entity->target[0], entity->target[1]))
            return;
        if (entity->at0d & 0x80) return;
        if (entity->at0d & 0x40) { entity->at0d = 0x10; return; }
        fallbackOrder(sim, slot);
        return;
    }
    case 7: {
        // 00403170's case 7 is the clearing order, and its tail is the same
        // hunt-or-home the high bits of +0x0d choose.
        const SimActionResult r = simClearTarget(sim, slot);
        if (r == SIM_ACTION_PROGRESS || r == SIM_ACTION_DONE) return;
        if (entity->at0d & 0x80) return;
        if (entity->at0d & 0x40) { entity->at0d = 0x10; return; }
        fallbackOrder(sim, slot);
        return;
    }
    default:
        // 00403170 carries cases 6 through 0x0c as well, several hundred lines
        // of them, and none is read.  Falling back sends the unit home rather
        // than inventing what they do.
        fallbackOrder(sim, slot);
        return;
    }
}

// 00401770.  The order a unit carries is the low nibble of +0x0d, and it acts
// on it by itself - which is what makes a country play without being told.
//
// Ported: the upkeep gate, the 0x0c state a unit falls into when its faction
// loses its leader, standing on somebody else's castle, and orders 1, 2 and 3
// - which all raise one of the faction's unit cells through 0040b330.  The
// rest of that routine walks a unit toward a target through 0041ef80 and
// handles the remaining orders; neither is read, so a unit with any other
// order simply holds still.
static void stepPlainUnit(Sim *sim, unsigned slot) {
    GameState *state = sim->state;
    Entity *entity = &state->entities[slot];
    const unsigned faction = entity->faction;
    if (faction >= FACTION_COUNT) return;
    const unsigned col = entity->position[0];
    const unsigned row = entity->position[1];
    if (!inBounds((int)col, (int)row)) return;
    const unsigned index = WORLD_INDEX(col, row);

    if (!payUpkeep(state, slot, index, faction)) return;

    if ((entity->at0d & 0x0f) == 0x0c) {
        // Its faction lost its leader: it joins whoever at1f names, or dies.
        const unsigned char becomes = state->factions[faction].at1f;
        if (becomes == 4) {
            simMarkDying(state, slot, 4);
            return;
        }
        entity->faction = becomes;
        entity->at0d = 1;
        if (entity->faction == sim->humanFaction) entity->at0d = 0;
        return;
    }

    trampleGround(state, index, faction);

    const unsigned onCastle = (unsigned)(state->world.cells[index].terrain
                                         - 0x14u);
    if (onCastle < 4 && onCastle != faction) {
        // Somebody else's castle: drop everything, take the order that deals
        // with it, and strike out at whatever is next to it.
        entity->at18 = ROUTE_EMPTY;
        entity->at0c = 6;
        entity->at0d = 2;
        lashOut(sim, slot, col, row);
        return;
    }

    if (entity->at18 != ROUTE_EMPTY) {
        // It has somewhere to be; the walk is the leader's routine, which the
        // cursor only gives to leaders in the original.  Left alone here.
        return;
    }

    // 0041ef80 first: a unit with nowhere to be strikes an adjacent enemy
    // rather than getting on with its order.
    if (lashOut(sim, slot, col, row)) return;

    switch (entity->at0d & 0x0f) {
    case 1:
    case 2:
    case 3:
        if (simBuildUnitCell(sim, slot, col, row) == SIM_ACTION_REFUSED)
            entity->at0c = 6;
        break;
    default:
        break;
    }
}
