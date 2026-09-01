// The simulation sweep.  See sim.c for what the terrain byte encodes.
#ifndef SIM_H
#define SIM_H

#include "state.h"

typedef struct {
    GameState *state;
    unsigned cursor;            // DAT_00437690 / DAT_004369fc
    unsigned long long frames;
    unsigned humanFaction;      // DAT_004365cd
    int autoTax;                // DAT_0043769c == 1
} Sim;

void simInit(Sim *sim, GameState *state);

// One call of 00417380: 0x8f cells from where the last one stopped.
void simStep(Sim *sim);

#endif
