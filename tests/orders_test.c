// The player's own path through an order, one order at a time.
//
// state_test calls the six working routines directly, which proves each of
// them does its arithmetic.  This asks the question a player asks instead:
// I chose these units, I pointed at that square, I picked this order - did
// the square change?  Every step in between is the one the page takes:
// simSelect, simAimSelection, simOrderSelected, and then the clock.
#include <stdio.h>
#include <string.h>

#include "../src/sim.h"
#include "../src/state.h"
#include "../src/world.h"

static int failures;

static void expect(const char *what, long got, long want) {
    if (got == want) return;
    printf("  FAIL %s: got %ld want %ld\n", what, got, want);
    failures++;
}

// A bare board with one country, one soldier, and money.  The soldier stands
// at 20,20; the square it will be pointed at is 22,20, two cells east, so it
// has to walk before it can work.
static void board(GameState *state, Sim *sim, unsigned strength) {
    memset(state, 0, sizeof *state);
    for (int i = 0; i < WORLD_CELLS; i++) {
        state->world.cells[i].terrain = 0;
        state->world.cells[i].value = 100;
        state->world.cells[i].occupant = CELL_NO_ENTITY;
    }
    stateResetEntitiesAndFactions(state);
    stateMarkBlocked(state);

    Entity *e = &state->entities[1];
    e->flags = 0;
    e->faction = 0;
    e->at0d = 1;
    e->at08 = strength;
    e->at0c = 6;
    e->at0f = 10;
    e->at18 = 0x1f0;
    e->position[0] = 20;
    e->position[1] = 20;
    e->target[0] = 20;
    e->target[1] = 20;
    state->world.cells[WORLD_INDEX(20, 20)].occupant = 1;

    state->factions[0].funds = 100000;
    state->factions[0].at08[0] = 20;
    state->factions[0].at08[1] = 20;
    state->factions[0].at1e = 0x80;

    simInit(sim, state);
    sim->humanFaction = 0;
    state->frame = 1;
}

// Choose the soldier, point it at the square, give it the order - and then let
// the clock run until the square stops being what it was.  Answers how many
// sweeps that took, or -1.
static long carryOut(Sim *sim, GameState *state, unsigned order,
                     unsigned col, unsigned row, unsigned char was) {
    if (!simSelect(sim, 1, state->entities[1].position[0],
                   state->entities[1].position[1], 1)) return -2;
    simAimSelection(sim, (int)col, (int)row);
    if (simOrderSelected(sim, order, 0, (int)col, (int)row) < 1) return -3;

    const unsigned index = WORLD_INDEX(col, row);
    for (long i = 1; i <= 4000; i++) {
        simStep(sim);
        if (state->world.cells[index].terrain != was) return i;
        if (state->entities[1].flags & 0x80) return -4;   // it used itself up
    }
    return -1;
}

int main(void) {
    static GameState state;
    Sim sim;

    // Order 5: raise a settlement on bare ground.
    board(&state, &sim, 8000);
    {
        const long took = carryOut(&sim, &state, 5, 22, 20, 0);
        expect("order 5 raised something", took > 0, 1);
        expect("and it is this country's settlement",
               state.world.cells[WORLD_INDEX(22, 20)].terrain, 8);
        printf("  order 5 (settlement) took %ld sweeps\n", took);
    }

    // Order 6: a wall on bare ground, terrain 0x7b, and the board has to know
    // it cannot be walked on.
    board(&state, &sim, 8000);
    {
        const long took = carryOut(&sim, &state, 6, 22, 20, 0);
        expect("order 6 built something", took > 0, 1);
        expect("and it is a wall",
               state.world.cells[WORLD_INDEX(22, 20)].terrain, 0x7b);
        expect("which blocks the way",
               state.world.cells[WORLD_INDEX(22, 20)].blocked, 1);
        printf("  order 6 (wall) took %ld sweeps\n", took);
    }

    // Order 7: cut through scenery.  What it leaves is cleared ground, whose
    // low four bits 0041af10 fills in, so the family is what to check.
    board(&state, &sim, 8000);
    state.world.cells[WORLD_INDEX(22, 20)].terrain = 0x35;
    state.world.cells[WORLD_INDEX(22, 20)].value = 100;
    stateMarkBlocked(&state);
    {
        const long took = carryOut(&sim, &state, 7, 22, 20, 0x35);
        expect("order 7 cut through", took > 0, 1);
        expect("leaving cleared ground",
               state.world.cells[WORLD_INDEX(22, 20)].terrain >> 4, 2);
        expect("which can now be walked on",
               state.world.cells[WORLD_INDEX(22, 20)].blocked, 0);
        printf("  order 7 (clear) took %ld sweeps\n", took);
    }

    // Order 9: pull a wall down.
    board(&state, &sim, 8000);
    state.world.cells[WORLD_INDEX(22, 20)].terrain = 0x7b;
    state.world.cells[WORLD_INDEX(22, 20)].value = 100;
    stateMarkBlocked(&state);
    {
        const long took = carryOut(&sim, &state, 9, 22, 20, 0x7b);
        expect("order 9 pulled it down", took > 0, 1);
        expect("leaving bare ground",
               state.world.cells[WORLD_INDEX(22, 20)].terrain, 0);
        printf("  order 9 (demolish wall) took %ld sweeps\n", took);
    }

    // Order 10: block a path - cleared ground worked down into a mine.
    board(&state, &sim, 8000);
    state.world.cells[WORLD_INDEX(22, 20)].terrain = 0x20;
    state.world.cells[WORLD_INDEX(22, 20)].value = 100;
    stateMarkBlocked(&state);
    {
        const long took = carryOut(&sim, &state, 10, 22, 20, 0x20);
        expect("order 10 dug in", took > 0, 1);
        expect("leaving a mine",
               state.world.cells[WORLD_INDEX(22, 20)].terrain, 0x7a);
        printf("  order 10 (mine) took %ld sweeps\n", took);
    }

    // Order 11: break a monster den.
    board(&state, &sim, 8000);
    state.world.cells[WORLD_INDEX(22, 20)].terrain = 5;
    state.world.cells[WORLD_INDEX(22, 20)].value = 100;
    stateMarkBlocked(&state);
    {
        const long took = carryOut(&sim, &state, 11, 22, 20, 5);
        expect("order 11 broke the den", took > 0, 1);
        expect("leaving rubble",
               state.world.cells[WORLD_INDEX(22, 20)].terrain >> 4, 6);
        printf("  order 11 (break den) took %ld sweeps\n", took);
    }

    // Order 8: pull a building down.  This one is worked from the square
    // itself rather than beside it, so the unit walks onto it first.
    board(&state, &sim, 8000);
    state.world.cells[WORLD_INDEX(22, 20)].terrain = 2;
    state.world.cells[WORLD_INDEX(22, 20)].value = 100;
    stateMarkBlocked(&state);
    {
        const long took = carryOut(&sim, &state, 8, 22, 20, 2);
        expect("order 8 pulled the building down", took > 0, 1);
        printf("  order 8 (demolish) took %ld sweeps, terrain now %02x\n",
               took, state.world.cells[WORLD_INDEX(22, 20)].terrain);
    }

    // Order 0: stand still.  Nothing to check on the board - what matters is
    // that the unit does not wander off, which is the whole point of it.
    board(&state, &sim, 8000);
    {
        expect("order 0 was accepted",
               simSelect(&sim, 1, 20, 20, 1) &&
               (simAimSelection(&sim, 22, 20), simOrderSelected(&sim, 0, 0, 22, 20)) >= 0, 1);
        state.entities[1].at0d = 0;               // the order with no work
        state.entities[1].at18 = 0x1f0;
        for (int i = 0; i < 400; i++) simStep(&sim);
        expect("and the unit stayed where it was",
               state.entities[1].position[0] * 100 +
               state.entities[1].position[1], 20 * 100 + 20);
    }

    printf(failures ? "%d order check(s) failed\n" : "order checks ok\n",
           failures);
    return failures ? 1 : 0;
}
