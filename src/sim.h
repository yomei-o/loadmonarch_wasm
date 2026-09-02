// The simulation sweep.  See sim.c for what the terrain byte encodes.
#ifndef SIM_H
#define SIM_H

#include "state.h"

typedef struct {
    GameState *state;
    unsigned cursor;            // DAT_00437690 / DAT_004369fc
    unsigned entityCursor;      // DAT_004377fc
    unsigned long long frames;
    unsigned humanFaction;      // DAT_004365cd
    int autoTax;                // DAT_0043769c == 1
    unsigned pendingOrder;      // DAT_004365e0, stamped onto a new unit
} Sim;

void simInit(Sim *sim, GameState *state);

// One call of 00417380: 0x8f cells from where the last one stopped, then one
// call of the entity cursor.
void simStep(Sim *sim);

// 004204f0: one call of the entity cursor, 0x3f of the sixty-four.
void simStepEntities(Sim *sim);


typedef enum {
    SIM_ACTION_DONE = 1,            // 0040b330's 1
    SIM_ACTION_NO_FUNDS = 2,        // its 2
    SIM_ACTION_REFUSED = 3,         // its 3
    SIM_ACTION_PROGRESS = 4,        // 0040b680's 4 - work done, not finished
    SIM_ACTION_SPENT_ENTITY = 6,    // its 6 - the entity was used up
} SimActionResult;

// 0041a8d0.
int simSpend(GameState *state, unsigned faction, unsigned cost);

// 00420b30.
void simRetireEntity(GameState *state, unsigned slot, unsigned col,
                     unsigned row);

// 00405250: a three-step path to a cell up to three away.
void simMakeRoute(GameState *state, unsigned slot, int dx, int dy);

// 00405200: one step along it; zero once it is spent.
int simAdvanceRoute(GameState *state, unsigned slot);

// 00420aa0: mark an entity dying, with a cause.
void simMarkDying(GameState *state, unsigned slot, unsigned char cause);


// 0040b330: raise one of the faction's unit cells at (col, row), paid for by
// the purse and by the acting entity's strength.
SimActionResult simBuildUnitCell(Sim *sim, unsigned slot, unsigned col,
                                 unsigned row);

// 0040bc20: pull down the building the unit is standing on.  Terrain 1..4.
SimActionResult simDemolishBuilding(Sim *sim, unsigned slot);

// 0040b840: tear down the wall at this unit's target.
SimActionResult simDemolishWall(Sim *sim, unsigned slot);

// 0040b960: turn cleared ground into a mine, or feed one.  Terrain 0x7a.
SimActionResult simMakeMine(Sim *sim, unsigned slot);

// 0040bb10: break the neutral spawner at this unit's target.  Terrain 5.
SimActionResult simBreakSpawner(Sim *sim, unsigned slot);

// 0040b440: raise or reinforce a wall at this unit's target.  Terrain 0x7b.
SimActionResult simBuildWall(Sim *sim, unsigned slot);

// 0040b680: work the obstacle at this unit's target down towards ground.
SimActionResult simClearTarget(Sim *sim, unsigned slot);

// Puts a leader on each castle so a stage can start.  NOT from the
// executable - see the comment in sim.c.
void simSeedLeaders(Sim *sim);

// The entity the human player's orders act through.
unsigned simHumanActor(const Sim *sim);


// 00405360, 00405390 and 0041a680: the distance fill 0041dc60 runs before it
// collects tax.  Reset every cell, shut the fill out of foreign ground, then
// walk it from one cell, leaving distances in each cell's +0x08.  Territory the
// walk cannot reach is territory that stops paying.
void simResetFill(GameState *state);
void simBlockForeign(GameState *state, unsigned faction);
void simFillFrom(GameState *state, int col, int row);

#endif
