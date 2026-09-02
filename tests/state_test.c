// Checks the ported state chain against the sizes and values the executable
// uses, so a wrong offset shows up here rather than as odd behaviour later.
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "../src/sim.h"
#include "../src/state.h"
#include "../src/host.h"
#include "../src/render.h"

static int failures;

static void expect(const char *what, long got, long want) {
    if (got != want) {
        printf("  FAIL %-34s got %ld want %ld\n", what, got, want);
        failures++;
    }
}

int main(void) {
    // The strides the original walks its arrays with.
    expect("sizeof(Entity)", (long)sizeof(Entity), 0x224);
    expect("sizeof(Faction)", (long)sizeof(Faction), 0x38);
    expect("sizeof(WorldCell)", (long)sizeof(WorldCell), 0x18);
    expect("cells total", (long)(sizeof(WorldCell) * WORLD_CELLS), 0xd800);
    expect("entities total", (long)(sizeof(Entity) * ENTITY_COUNT), 0x8900);
    expect("factions total", (long)(sizeof(Faction) * FACTION_COUNT), 0x118);

    // Offsets the decompilation names explicitly.
    expect("Entity.position", (long)offsetof(Entity, position), 0x00);
    expect("Entity.target", (long)offsetof(Entity, target), 0x02);
    expect("Entity.faction", (long)offsetof(Entity, faction), 0x04);
    expect("Entity.at08", (long)offsetof(Entity, at08), 0x08);
    expect("Entity.at0c", (long)offsetof(Entity, at0c), 0x0c);
    expect("Entity.at0d", (long)offsetof(Entity, at0d), 0x0d);
    expect("Entity.at0f", (long)offsetof(Entity, at0f), 0x0f);
    expect("Entity.flags", (long)offsetof(Entity, flags), 0x10);
    expect("Entity.at14", (long)offsetof(Entity, at14), 0x14);
    expect("Entity.at18", (long)offsetof(Entity, at18), 0x18);
    expect("Entity.flags21c", (long)offsetof(Entity, flags21c), 0x21c);
    expect("Entity.at220", (long)offsetof(Entity, at220), 0x220);
    expect("Faction.flags", (long)offsetof(Faction, flags), 0x04);
    expect("Faction.at0c", (long)offsetof(Faction, at0c), 0x0c);
    expect("Faction.strength", (long)offsetof(Faction, strength), 0x10);
    expect("Faction.funds", (long)offsetof(Faction, funds), 0x18);
    expect("Faction.taxRate", (long)offsetof(Faction, taxRate), 0x1c);
    expect("Faction.at1f", (long)offsetof(Faction, at1f), 0x1f);
    expect("Faction.entities", (long)offsetof(Faction, entities), 0x24);
    expect("Faction.at28", (long)offsetof(Faction, at28), 0x28);
    expect("Faction.at30", (long)offsetof(Faction, at30), 0x30);
    expect("WorldCell.occupant", (long)offsetof(WorldCell, occupant), 0x00);
    expect("WorldCell.marked", (long)offsetof(WorldCell, marked), 0x04);
    expect("WorldCell.blocked", (long)offsetof(WorldCell, blocked), 0x05);
    expect("WorldCell.cost", (long)offsetof(WorldCell, cost), 0x08);
    expect("WorldCell.value", (long)offsetof(WorldCell, value), 0x0c);
    expect("WorldCell.terrain", (long)offsetof(WorldCell, terrain), 0x10);
    expect("WorldCell.overlay", (long)offsetof(WorldCell, overlay), 0x14);

    // The reset values, and the two things the chain derives.
    static GameState state;
    memset(&state, 0, sizeof state);
    for (int i = 0; i < WORLD_CELLS; i++)
        state.world.cells[i].terrain = (unsigned char)(i % 0x60);
    stateStartStage(&state);

    expect("faction funds after reset", state.factions[0].funds, 5000);
    expect("entity inactive after reset", state.entities[0].flags, 0x80);
    expect("entity at18 after reset", state.entities[0].at18, 0x1f0);
    expect("cell owner after place", state.world.cells[0].occupant, 0x40);
    expect("blocked at terrain 0x2f", state.world.cells[0x2f].blocked, 0);
    expect("blocked at terrain 0x30", state.world.cells[0x30].blocked, 1);
    // The stage start no longer marks anybody - see stateStartStage - but the
    // marking itself still does what it says.
    expect("nobody is marked at the start", state.factions[0].flags & 0x10, 0);
    stateMarkDefeated(&state);
    expect("defeated flag with no strength", state.factions[0].flags & 0x10,
           0x10);
    expect("fifth faction untouched", state.factions[4].flags & 0x10, 0);

    // An active entity writes its own index into the cell it stands on.
    state.entities[7].flags = 0;
    state.entities[7].position[0] = 5;      // column
    state.entities[7].position[1] = 9;      // row
    statePlaceEntities(&state);
    expect("cell owner from entity", state.world.cells[WORLD_INDEX(5, 9)].occupant,
           7);

    // A unit cell beside empty land claims it, and turns its accumulated
    // value into a unit once there is nothing left to take.
    memset(&state, 0, sizeof state);
    stateResetEntitiesAndFactions(&state);
    statePlaceEntities(&state);
    {
        const unsigned unitCell = WORLD_INDEX(10, 10);
        // Scenery all round but one gap, so the claim has only one place to
        // go: the scan runs west, east, north, south then the diagonals, and
        // an all-empty board would be claimed to the west.
        for (int dc = -1; dc < 2; dc++)
            for (int dr = -1; dr < 2; dr++)
                state.world.cells[WORLD_INDEX(10 + dc, 10 + dr)].terrain = 0x60;
        state.world.cells[unitCell].terrain = 8;      // faction 0's unit
        state.world.cells[unitCell].value = 101;      // what 0040b330 leaves
        state.world.cells[WORLD_INDEX(11, 10)].terrain = 0;   // the one gap
        Sim grow;
        simInit(&grow, &state);
        for (int i = 0; i < WORLD_CELLS / 0x8f + 2; i++) simStep(&grow);
        expect("unit claimed the empty neighbour",
               state.world.cells[WORLD_INDEX(11, 10)].terrain, 0x0c);
        expect("claimed ground starts at 100",
               state.world.cells[WORLD_INDEX(11, 10)].value, 100);
    }

    // 0040b330: the order costs a hundred, plants the faction's unit cell, and
    // refuses a second one beside the first.
    memset(&state, 0, sizeof state);
    stateResetEntitiesAndFactions(&state);
    statePlaceEntities(&state);
    {
        Sim act;
        simInit(&act, &state);
        state.entities[0].flags = 0;
        state.entities[0].faction = 0;
        state.entities[0].at08 = 1000;            // enough to survive spending
        state.entities[0].position[0] = 20;
        state.entities[0].position[1] = 20;
        state.factions[0].funds = 250;
        const int first = (int)simBuildUnitCell(&act, 0, 20, 20);
        expect("order placed a unit", first, SIM_ACTION_DONE);
        expect("order cost a hundred", state.factions[0].funds, 150);
        expect("cell became the faction's unit",
               state.world.cells[WORLD_INDEX(20, 20)].terrain, 8);
        expect("cell value from the unit's strength",
               state.world.cells[WORLD_INDEX(20, 20)].value, 101);
        expect("unit paid from its own strength", state.entities[0].at08, 800);
        const int second = (int)simBuildUnitCell(&act, 0, 21, 20);
        expect("a second beside it is refused", second, SIM_ACTION_REFUSED);
        expect("the refusal cost nothing", state.factions[0].funds, 150);
        // Spending an entity down to nothing retires it.
        state.entities[0].at08 = 200;
        const int last = (int)simBuildUnitCell(&act, 0, 30, 30);
        expect("the order used the unit up", last, SIM_ACTION_SPENT_ENTITY);
        expect("the used unit went inactive",
               state.entities[0].flags & 0x80, 0x80);
    }

    // 004204f0 and 00401000: turning costs a tick, then the leader steps.
    // Direction 5 is (+1, +1) - and it has to be given as a route, because
    // 00401000 walks only in the branch it takes when it has one.  A king with
    // nowhere to be faces south and stands.
    memset(&state, 0, sizeof state);
    stateResetEntitiesAndFactions(&state);
    statePlaceEntities(&state);
    {
        Sim walk;
        simInit(&walk, &state);
        walk.humanFaction = 3;                  // so this leader is not the human's
        Entity *e = &state.entities[1];
        e->flags = 0;
        e->faction = 0;
        e->at0d = 0x20;                         // the leader bit
        e->at18 = 0;                            // a route, so it walks
        e->at14 = 8;
        for (unsigned i = 0; i < 8; i++) e->route[i] = 5;   // south-east
        e->at0c = 0;                            // facing the wrong way
        e->position[0] = 20;
        e->position[1] = 20;
        state.world.cells[WORLD_INDEX(20, 20)].occupant = 1;
        simStepEntities(&walk);
        expect("the leader turned first", e->at0c, 5);
        expect("and did not move yet",
               e->position[0] * 100 + e->position[1], 20 * 100 + 20);
        simStepEntities(&walk);
        expect("then it stepped", e->position[0] * 100 + e->position[1],
               21 * 100 + 21);
        expect("it left the cell behind",
               state.world.cells[WORLD_INDEX(20, 20)].occupant, 0x40);
        expect("and occupies the new one",
               state.world.cells[WORLD_INDEX(21, 21)].occupant, 1);

        // Scenery stops it, and clears the route of anyone but the player.
        state.world.cells[WORLD_INDEX(22, 22)].terrain = 0x60;
        e->at18 = 0;
        e->at14 = 8;
        e->route[0] = 5;
        simStepEntities(&walk);
        expect("scenery stopped the step",
               e->position[0] * 100 + e->position[1], 21 * 100 + 21);
        expect("and the route was cleared", e->at18, 0x1f0);

        // So does somebody else's unit - it becomes a fight instead of a step.
        state.world.cells[WORLD_INDEX(22, 22)].terrain = 0;
        state.world.cells[WORLD_INDEX(22, 22)].occupant = 9;
        state.entities[9].flags = 0;
        state.entities[9].faction = 1;          // an enemy
        state.entities[9].at08 = 5000;
        e->at18 = 0;
        e->at14 = 8;
        e->route[0] = 5;
        e->at08 = 8000;
        simStepEntities(&walk);
        expect("an enemy unit stopped the step",
               e->position[0] * 100 + e->position[1], 21 * 100 + 21);
        expect("and took damage instead", state.entities[9].at08 < 5000, 1);
        expect("the mover was hit back", e->at08 < 8000, 1);

        // A dying entity counts three ticks and then goes.
        Entity *d = &state.entities[2];
        d->flags = 2;
        d->faction = 0;
        d->position[0] = 30;
        d->position[1] = 30;
        d->at0e = 0;
        for (int i = 0; i < 4; i++) simStepEntities(&walk);
        expect("a dying entity was retired", d->flags & 0x80, 0x80);
    }

    // 0041a920: on its own ground a unit is paid for out of the treasury; off
    // it, the unit eats its own strength and eventually starves.
    memset(&state, 0, sizeof state);
    stateResetEntitiesAndFactions(&state);
    statePlaceEntities(&state);
    {
        Sim keep;
        simInit(&keep, &state);
        keep.humanFaction = 3;
        Entity *e = &state.entities[1];
        e->flags = 0;
        e->faction = 0;
        e->at0d = 4;
        e->at18 = 0x1f0;
        e->at08 = 4096;
        e->position[0] = 20;
        e->position[1] = 20;
        state.world.cells[WORLD_INDEX(20, 20)].terrain = 8;   // its own ground
        // One of its own beside it, so the settlement it would otherwise fall
        // back on building is refused and only the upkeep moves.
        state.world.cells[WORLD_INDEX(21, 20)].terrain = 8;
        state.factions[0].funds = 1000;
        simStepEntities(&keep);
        expect("upkeep came from the treasury", state.factions[0].funds,
               1000 - (4096 >> 11));
        expect("and left the unit's strength alone", e->at08, 4096);

        // Off its own ground it pays with itself.
        state.world.cells[WORLD_INDEX(20, 20)].terrain = 0;
        simStepEntities(&keep);
        expect("off its ground it paid with strength", e->at08,
               4096 - ((4096 >> 8) + 1));

        // Down to nothing, it is marked dying.
        e->at08 = 1;
        simStepEntities(&keep);
        expect("a starved unit is marked dying", e->flags & 2, 2);
    }

    // 00420a40: walking over somebody else's claimed ground wipes it.
    memset(&state, 0, sizeof state);
    stateResetEntitiesAndFactions(&state);
    statePlaceEntities(&state);
    {
        Sim tramp;
        simInit(&tramp, &state);
        tramp.humanFaction = 3;
        Entity *e = &state.entities[1];
        e->flags = 0;
        e->faction = 0;
        e->at0d = 4;
        e->at18 = 0x1f0;
        e->at08 = 4096;
        e->position[0] = 25;
        e->position[1] = 25;
        state.world.cells[WORLD_INDEX(25, 25)].terrain = 0x0d;  // faction 1's
        state.factions[0].funds = 1000;
        simStepEntities(&tramp);
        expect("enemy ground was wiped",
               state.world.cells[WORLD_INDEX(25, 25)].terrain, 0);
    }

    // 00401770's orders 1..3: a unit raises one of its faction's unit cells
    // by itself, which is what makes a country expand unattended.
    memset(&state, 0, sizeof state);
    stateResetEntitiesAndFactions(&state);
    statePlaceEntities(&state);
    {
        Sim order;
        simInit(&order, &state);
        order.humanFaction = 3;
        Entity *e = &state.entities[1];
        e->flags = 0;
        e->faction = 0;
        e->at0d = 1;                       // the plain build order
        e->at18 = 0x1f0;
        e->at08 = 4096;
        e->position[0] = 26;
        e->position[1] = 26;
        state.factions[0].funds = 1000;
        simStepEntities(&order);
        expect("the unit built by itself",
               state.world.cells[WORLD_INDEX(26, 26)].terrain, 8);
        expect("and it was paid for", state.factions[0].funds < 1000, 1);
    }

    // A unit whose faction lost its leader joins whoever at1f names.
    memset(&state, 0, sizeof state);
    stateResetEntitiesAndFactions(&state);
    statePlaceEntities(&state);
    {
        Sim fall;
        simInit(&fall, &state);
        fall.humanFaction = 3;
        Entity *e = &state.entities[1];
        e->flags = 0;
        e->faction = 0;
        e->at0d = 0x0c;
        e->at08 = 4096;
        e->position[0] = 27;
        e->position[1] = 27;
        state.factions[0].at1f = 2;         // it becomes faction 2's
        state.factions[0].funds = 1000;
        simStepEntities(&fall);
        expect("the unit changed sides", e->faction, 2);
        expect("and took the plain order", e->at0d, 1);
    }

    // 00420c60: from a castle a unit strikes for a quarter and takes nothing
    // back.  00420e70: the killing blow marks the loser with the winner's
    // faction, which is what lets a country change hands.
    memset(&state, 0, sizeof state);
    stateResetEntitiesAndFactions(&state);
    statePlaceEntities(&state);
    {
        Sim war;
        simInit(&war, &state);
        war.humanFaction = 3;
        Entity *a = &state.entities[1];
        a->flags = 0; a->faction = 0; a->at0d = 0x20;
        a->at08 = 4000; a->at0c = 5; a->at18 = 0; a->at14 = 4; a->route[0] = 5;   // walking south-east
        a->position[0] = 15; a->position[1] = 15;
        state.world.cells[WORLD_INDEX(15, 15)].terrain = 0x14;   // on a castle
        state.world.cells[WORLD_INDEX(15, 15)].occupant = 1;
        Entity *b = &state.entities[9];
        b->flags = 0; b->faction = 2; b->at08 = 300;
        b->position[0] = 16; b->position[1] = 16;
        state.world.cells[WORLD_INDEX(16, 16)].occupant = 9;
        state.factions[0].funds = 100000;
        simStepEntities(&war);
        expect("the defender was killed outright", b->flags & 2, 2);
        expect("and marked with the winner's faction", b->at0f, 0);
        expect("the losses were tallied", state.factions[2].at14 > 0, 1);
    }

    // 004208b0: walking into another faction's settlement razes it once its
    // value is gone.
    memset(&state, 0, sizeof state);
    stateResetEntitiesAndFactions(&state);
    statePlaceEntities(&state);
    {
        Sim raid;
        simInit(&raid, &state);
        raid.humanFaction = 3;
        Entity *a = &state.entities[1];
        a->flags = 0; a->faction = 0; a->at0d = 0x20;
        a->at08 = 4000; a->at0c = 5; a->at18 = 0; a->at14 = 4; a->route[0] = 5;   // walking south-east
        a->position[0] = 18; a->position[1] = 18;
        state.world.cells[WORLD_INDEX(18, 18)].terrain = 8;   // its own ground
        state.world.cells[WORLD_INDEX(18, 18)].occupant = 1;
        state.world.cells[WORLD_INDEX(19, 19)].terrain = 9;   // faction 1's
        state.world.cells[WORLD_INDEX(19, 19)].value = 50;
        state.factions[0].funds = 100000;
        simStepEntities(&raid);
        expect("the settlement was razed",
               state.world.cells[WORLD_INDEX(19, 19)].terrain, 0);
        expect("and left bare land at 100",
               state.world.cells[WORLD_INDEX(19, 19)].value, 100);
    }

    // 00420610: a leader walking into one of its own absorbs it and moves on.
    memset(&state, 0, sizeof state);
    stateResetEntitiesAndFactions(&state);
    statePlaceEntities(&state);
    {
        Sim join;
        simInit(&join, &state);
        join.humanFaction = 3;
        Entity *a = &state.entities[1];
        a->flags = 0; a->faction = 0; a->at0d = 0x20;
        a->at08 = 1000; a->at0c = 5; a->at18 = 0; a->at14 = 4; a->route[0] = 5;   // walking south-east
        a->position[0] = 22; a->position[1] = 22;
        state.world.cells[WORLD_INDEX(22, 22)].terrain = 8;
        state.world.cells[WORLD_INDEX(22, 22)].occupant = 1;
        Entity *b = &state.entities[9];
        b->flags = 0; b->faction = 0; b->at08 = 700;
        b->position[0] = 23; b->position[1] = 23;
        state.world.cells[WORLD_INDEX(23, 23)].occupant = 9;
        state.factions[0].funds = 100000;
        simStepEntities(&join);
        expect("the leader absorbed its own", a->at08 >= 1000 + 700 - 8, 1);
        expect("the absorbed unit went inactive", b->flags & 0x80, 0x80);
        expect("and the leader took the cell",
               a->position[0] * 100 + a->position[1], 23 * 100 + 23);
    }

    // 0041e0a0 through 00402bc0: order 4 heads for a neighbour's settlement,
    // and the route it lays out is walked.
    memset(&state, 0, sizeof state);
    stateResetEntitiesAndFactions(&state);
    statePlaceEntities(&state);
    {
        Sim march;
        simInit(&march, &state);
        march.humanFaction = 3;
        Entity *e = &state.entities[1];
        e->flags = 0;
        e->faction = 0;
        e->at0d = 0x80 | 0x10 | 4;       // ordered, hunting, order 4
        e->at18 = 0x1f0;
        e->at08 = 8000;
        e->position[0] = 20;
        e->position[1] = 20;
        state.world.cells[WORLD_INDEX(20, 20)].occupant = 1;
        state.world.cells[WORLD_INDEX(20, 20)].terrain = 8;   // its own ground
        state.factions[0].funds = 100000;
        // Faction 1's settlement two cells east, with clear ground between.
        state.world.cells[WORLD_INDEX(22, 20)].terrain = 9;
        stateMarkBlocked(&state);
        simStepEntities(&march);
        expect("the order laid out a route", e->at18 != 0x1f0, 1);
        expect("aimed at the settlement",
               e->target[0] * 100 + e->target[1], 22 * 100 + 20);
    }

    // 0041e560 through 00403100: a unit away from its own settlements is sent
    // home, and one standing on one stays put.
    memset(&state, 0, sizeof state);
    stateResetEntitiesAndFactions(&state);
    statePlaceEntities(&state);
    {
        Sim home;
        simInit(&home, &state);
        home.humanFaction = 3;
        Entity *e = &state.entities[1];
        e->flags = 0;
        e->faction = 0;
        e->at0d = 0x10 | 7;              // an order the switch falls through
        e->at18 = 0x1f0;
        e->at08 = 8000;
        e->position[0] = 30;
        e->position[1] = 30;
        state.world.cells[WORLD_INDEX(30, 30)].occupant = 1;
        state.world.cells[WORLD_INDEX(32, 30)].terrain = 8;   // home, two east
        state.factions[0].funds = 100000;
        stateMarkBlocked(&state);
        simStepEntities(&home);
        expect("the fallback sent it home", e->at18 != 0x1f0, 1);
        expect("and set the plain order", e->at0d & 0x0f, 1);

        // Standing on its own, it is left alone.
        e->at0d = 0x10 | 7;
        e->at18 = 0x1f0;
        e->position[0] = 32;
        e->position[1] = 30;
        simStepEntities(&home);
        expect("on its own ground it stays", e->at18, 0x1f0);
    }

    // 0040b680: an obstacle is worked down at thirty a unit of work, and
    // becomes walkable ground once its value is gone.
    memset(&state, 0, sizeof state);
    stateResetEntitiesAndFactions(&state);
    statePlaceEntities(&state);
    {
        Sim dig;
        simInit(&dig, &state);
        Entity *e = &state.entities[1];
        e->flags = 0;
        e->faction = 0;
        e->at08 = 1600;                 // a sixteenth is 100 of work
        e->position[0] = 20;
        e->position[1] = 20;
        e->target[0] = 21;
        e->target[1] = 20;
        WorldCell *rock = &state.world.cells[WORLD_INDEX(21, 20)];
        rock->terrain = 0x40;           // an obstacle
        rock->value = 250;
        state.factions[0].funds = 100000;
        const unsigned before = state.factions[0].funds;
        expect("work went in", (long)simClearTarget(&dig, 1),
               SIM_ACTION_PROGRESS);
        expect("the obstacle wore down", rock->value, 150);
        expect("and it was paid for at thirty a unit",
               before - state.factions[0].funds, 100 * 0x1e);

        // Enough work finishes it, and 0x20 is walkable.
        rock->value = 40;
        expect("the obstacle was cleared", (long)simClearTarget(&dig, 1),
               SIM_ACTION_DONE);
        expect("and became ground", rock->terrain, 0x20);
        // The work available is capped by what the cell needs - value + 1 -
        // so a cell at 40 takes 41 of work and leaves 1 behind.
        expect("the overshoot became its value", rock->value, 1);

        // Ordinary terrain refuses the order.
        rock->terrain = 0x60;
        expect("plain scenery is not clearable",
               (long)simClearTarget(&dig, 1), SIM_ACTION_REFUSED);

        // 0x7a is the cheap one that carries a lot of work.
        rock->terrain = 0x7a;
        rock->value = 10;
        state.factions[0].funds = 100000;
        const unsigned before2 = state.factions[0].funds;
        expect("the rich cell cleared", (long)simClearTarget(&dig, 1),
               SIM_ACTION_DONE);
        expect("at two a unit of work",
               before2 - state.factions[0].funds, 100 * 2);
    }

    // 0040b440: a wall goes up on bare land at a quarter what clearing costs,
    // and once it stands the cell is blocked.
    memset(&state, 0, sizeof state);
    stateResetEntitiesAndFactions(&state);
    statePlaceEntities(&state);
    {
        Sim build;
        simInit(&build, &state);
        Entity *e = &state.entities[1];
        e->flags = 0;
        e->faction = 0;
        e->at08 = 1600;                 // a sixteenth is 100 of work
        e->position[0] = 20;
        e->position[1] = 20;
        e->target[0] = 21;
        e->target[1] = 20;
        WorldCell *site = &state.world.cells[WORLD_INDEX(21, 20)];
        site->terrain = 0;              // bare land
        site->value = 250;
        state.factions[0].funds = 100000;
        unsigned before = state.factions[0].funds;
        expect("work went into the wall", (long)simBuildWall(&build, 1),
               SIM_ACTION_PROGRESS);
        expect("the site came down", site->value, 150);
        expect("at a quarter the cost of clearing",
               before - state.factions[0].funds, 100 / 4);

        site->value = 40;
        expect("the wall went up", (long)simBuildWall(&build, 1),
               SIM_ACTION_DONE);
        expect("the cell is a wall", site->terrain, 0x7b);
        expect("and it blocks movement", site->blocked, 1);

        // A standing wall takes reinforcement up to 0xff.
        site->value = 200;
        before = state.factions[0].funds;
        expect("reinforcing worked", (long)simBuildWall(&build, 1),
               SIM_ACTION_DONE);
        expect("up to the cap", site->value, 0xff);
        expect("paying for what it took",
               before - state.factions[0].funds, (0xff - 200) / 4);

        // Somebody standing there refuses it.
        site->terrain = 0;
        site->occupant = 9;
        expect("an occupied site refuses", (long)simBuildWall(&build, 1),
               SIM_ACTION_NO_FUNDS);
    }

    // The rest of the repertoire: 0040bc20, 0040b840, 0040b960, 0040bb10.
    memset(&state, 0, sizeof state);
    stateResetEntitiesAndFactions(&state);
    statePlaceEntities(&state);
    {
        Sim work;
        simInit(&work, &state);
        Entity *e = &state.entities[1];
        e->flags = 0;
        e->faction = 0;
        e->at08 = 3200;                 // a half is 1600, an eighth 400,
        e->position[0] = 20;            // a thirty-second 100
        e->position[1] = 20;
        e->target[0] = 21;
        e->target[1] = 20;
        state.factions[0].funds = 100000;
        WorldCell *here = &state.world.cells[WORLD_INDEX(20, 20)];
        WorldCell *there = &state.world.cells[WORLD_INDEX(21, 20)];

        // A building under the unit comes down in one blow at this strength.
        here->terrain = 3;
        here->value = 200;
        expect("the building fell", (long)simDemolishBuilding(&work, 1),
               SIM_ACTION_DONE);
        expect("leaving bare land", here->terrain, 0);
        expect("at the usual hundred", here->value, 100);

        // A wall gives way a thirty-second at a time, then the cell is bare.
        there->terrain = 0x7b;
        there->value = 250;
        expect("the wall gave", (long)simDemolishWall(&work, 1),
               SIM_ACTION_PROGRESS);
        expect("by a thirty-second", there->value, 150);
        there->value = 50;
        expect("then it came down", (long)simDemolishWall(&work, 1),
               SIM_ACTION_DONE);
        expect("and stopped blocking", there->blocked, 0);

        // Cleared ground becomes a mine, and a mine takes feeding.
        there->terrain = 0x24;          // inside 0x20..0x2f
        there->value = 40;
        expect("the mine was dug", (long)simMakeMine(&work, 1),
               SIM_ACTION_DONE);
        expect("and reads as one", there->terrain, 0x7a);
        there->value = 200;
        expect("feeding it worked", (long)simMakeMine(&work, 1),
               SIM_ACTION_DONE);
        expect("up to the cap", there->value, 0xff);

        // A spawner takes an eighth a turn and then is gone for good.
        there->terrain = 5;
        there->value = 1000;
        there->occupant = 0x40;
        expect("the spawner took damage", (long)simBreakSpawner(&work, 1),
               SIM_ACTION_PROGRESS);
        expect("an eighth of it", there->value, 1000 - 400);
        there->value = 100;
        expect("then it broke", (long)simBreakSpawner(&work, 1),
               SIM_ACTION_DONE);
        expect("into plain scenery", there->terrain, 0x60);

        // And each refuses terrain it has no business with.
        there->terrain = 0x60;
        expect("a wall order refuses scenery",
               (long)simDemolishWall(&work, 1), SIM_ACTION_REFUSED);
        expect("a spawner order too",
               (long)simBreakSpawner(&work, 1), SIM_ACTION_REFUSED);
    }

    // 0041b520's packing.  A number is size | faction << 3 | facing | frame,
    // and every branch has to stay inside the 208-tile bank.
    {
        Entity e;
        memset(&e, 0, sizeof e);
        e.faction = 0;
        e.at08 = 500;
        expect("smallest unit, first frame", renderSpriteNumber(&e, 0), 0);
        expect("and its second", renderSpriteNumber(&e, 2), 1);
        e.at0c = 4;                     // facing
        expect("facing is bits one and two", renderSpriteNumber(&e, 0), 4);
        e.at0c = 0;
        e.faction = 2;
        expect("faction is bits three and four", renderSpriteNumber(&e, 0),
               0x10);
        e.at08 = 1500;
        expect("a thousand strong moves up a size",
               renderSpriteNumber(&e, 0), 0x30);
        e.at08 = 20000;
        expect("ten thousand moves up again", renderSpriteNumber(&e, 0), 0x50);
        e.at0d = 0x20;                  // a leader
        expect("a leader is drawn by rank, not size",
               renderSpriteNumber(&e, 0), 0x70);
        e.at0d = 0;
        e.at08 = 500;
        e.flags = 1;
        expect("at work", renderSpriteNumber(&e, 0), 0x90);
        e.flags = 2;
        e.at0e = 3;
        expect("fighting", renderSpriteNumber(&e, 0), 0xb3);
        e.at0d = 0x20;
        expect("a leader fighting", renderSpriteNumber(&e, 0), 0xb7);
        e.faction = 4;
        e.at0d = 0;
        expect("a neutral fighting", renderSpriteNumber(&e, 0), 0xcb);
        e.flags = 0;
        e.at0c = 2;
        expect("a neutral walking", renderSpriteNumber(&e, 2), 0xc3);

        // Nothing may reach past the bank, cursor included.
        unsigned highest = 0;
        for (unsigned f = 0; f < 5; f++)
            for (unsigned flags = 0; flags < 4; flags++)
                for (unsigned dir = 0; dir < 8; dir++)
                    for (unsigned phase = 0; phase < 4; phase++)
                        for (unsigned leader = 0; leader < 2; leader++) {
                            memset(&e, 0, sizeof e);
                            e.faction = (unsigned char)f;
                            e.flags = (unsigned char)flags;
                            e.at0c = (unsigned char)dir;
                            e.at0e = (unsigned char)phase;
                            e.at0d = leader ? 0x20 : 0;
                            e.at08 = 50000;
                            const unsigned n = renderSpriteNumber(&e, 1);
                            if (n > highest) highest = n;
                        }
        expect("no sprite number leaves the bank", highest < 0xcc, 1);
    }

    // 004219b0's first priority is a neutral spawn, and 0040bb10 is what
    // happens when a unit gets to one: it eats an eighth of its own strength
    // out of the spawn each tick until there is nothing left, and the cell
    // turns to scenery.  This is the only answer to the monsters, so it is
    // worth knowing it works.
    memset(&state, 0, sizeof state);
    stateResetEntitiesAndFactions(&state);
    statePlaceEntities(&state);
    {
        Sim raid;
        simInit(&raid, &state);
        raid.humanFaction = 3;
        Entity *e = &state.entities[1];
        e->flags = 0;
        e->faction = 0;
        e->at0d = 0x0b;                 // the spawn-breaking preference
        e->at18 = 0x1f0;
        e->at08 = 800;
        e->at0f = 10;
        e->position[0] = 10;
        e->position[1] = 10;
        e->target[0] = 11;
        e->target[1] = 10;
        state.world.cells[WORLD_INDEX(10, 10)].terrain = 8;   // its own ground
        state.world.cells[WORLD_INDEX(10, 10)].occupant = 1;
        state.world.cells[WORLD_INDEX(11, 10)].terrain = 5;   // the spawn
        state.world.cells[WORLD_INDEX(11, 10)].value = 200;
        state.factions[0].funds = 100000;

        simStepEntities(&raid);
        expect("the spawn was worked down",
               state.world.cells[WORLD_INDEX(11, 10)].value < 200, 1);
        for (int i = 0; i < 8; i++) {
            e->at0d = 0x0b;             // it reverts once the work is done
            e->target[0] = 11;
            e->target[1] = 10;
            simStepEntities(&raid);
        }
        expect("and then it was gone",
               state.world.cells[WORLD_INDEX(11, 10)].terrain, 0x60);
    }

    // 0041f0d0 and 0041f4c0: a country falls, and the stage ends.
    memset(&state, 0, sizeof state);
    stateResetEntitiesAndFactions(&state);
    statePlaceEntities(&state);
    {
        Sim end;
        simInit(&end, &state);
        end.humanFaction = 0;

        // Give faction 1 a castle, a purse and a leader to lose.
        state.factions[1].at08[0] = 12;
        state.factions[1].at08[1] = 12;
        state.factions[1].funds = 4000;
        state.factions[1].at1f = 0;             // faction 0 inherits
        state.factions[1].flags |= 0x10;        // nothing left
        state.world.cells[WORLD_INDEX(12, 12)].terrain = 0x15;
        state.world.cells[WORLD_INDEX(13, 12)].terrain = 9;
        state.factions[0].funds = 1000;

        simConquerFaction(&end, 1);
        expect("the fallen country is out", state.factions[1].flags & 0x40,
               0x40);
        expect("its castle is gone",
               state.world.cells[WORLD_INDEX(12, 12)].terrain, 0);
        expect("and the ground beside it",
               state.world.cells[WORLD_INDEX(13, 12)].terrain, 0);
        expect("its purse went to the heir", state.factions[0].funds, 5000);
        expect("and it has none left", state.factions[1].funds, 0);

        // Three out and the player still in is a win; the player out is a
        // loss, whatever anyone else has done.
        expect("still playing", simStageOutcome(&end), 0);
        for (int f = 1; f < 4; f++)
            state.factions[f].flags |= 0x40 | 0x10 | 1;
        expect("three gone and the player left is a win",
               simStageOutcome(&end), 1);
        state.factions[0].flags |= 0x40;
        expect("the player out is a loss", simStageOutcome(&end), 2);
    }

    // 00422290: a unit born under a standing order looks across the whole map
    // for an enemy and marches.  On an open board with one enemy cell far
    // away, so the near finder cannot see it and only the wide hunt can.
    memset(&state, 0, sizeof state);
    stateResetEntitiesAndFactions(&state);
    statePlaceEntities(&state);
    {
        Sim hunt;
        simInit(&hunt, &state);
        hunt.humanFaction = 0;

        Entity *h = &state.entities[3];
        h->flags = 4;                   // born with a standing order
        h->faction = 0;
        h->at0d = 0x14;                 // order 4, standing
        h->at08 = 50000;
        h->at0f = 10;
        h->at18 = 0x1f0;
        h->position[0] = 4;
        h->position[1] = 4;
        statePlaceEntities(&state);
        state.world.cells[WORLD_INDEX(30, 30)].terrain = 9;   // faction 1's

        simPrepareFill(&state, 3, 4, 4);
        expect("the far cell is reachable",
               state.world.cells[WORLD_INDEX(30, 30)].cost < 0x1f0, 1);

        int took = 0;
        for (int i = 0; i < 200 && !took; i++) {
            simStep(&hunt);
            if (h->at18 != 0x1f0) took = 1;
        }
        expect("the hunter set out", took, 1);
        if (took) {
            expect("for the enemy cell", h->target[0] == 30 && h->target[1] == 30,
                   1);
            printf("  hunter at %d,%d heading for %d,%d, %u steps\n",
                   h->position[0], h->position[1], h->target[0], h->target[1],
                   h->at14);

            // And it gets there: an empty board, one unit, nothing in the way.
            int nearest = 26 + 26;              // from 4,4 to 30,30
            for (int i = 0; i < 4000; i++) {
                simStep(&hunt);
                const int c = h->position[0], r = h->position[1];
                const int d = (c > 30 ? c - 30 : 30 - c) +
                              (r > 30 ? r - 30 : 30 - r);
                if (d < nearest) nearest = d;
            }
            printf("  it closed to %d of 30,30\n", nearest);
            expect("the hunter arrived", nearest <= 1, 1);
        }

        // Too small to be worth the walk: 00422290 wants twice the distance.
        Entity *small = &state.entities[4];
        small->flags = 4;
        small->faction = 0;
        small->at0d = 0x14;
        small->at08 = 4;                // the walk is far longer than that
        small->at0f = 10;
        small->at18 = 0x1f0;
        small->position[0] = 4;
        small->position[1] = 6;
        statePlaceEntities(&state);
        for (int i = 0; i < 20; i++) simStep(&hunt);
        expect("a small unit stays home", small->at18, 0x1f0);

        // 0041f790: the player's own units say what they are doing.  A unit
        // under orders shows 10 or 11, alternating.  The hunter marched and
        // went back to its own devices on the way, so it is given an order
        // again to have something to say.
        state.entities[3].flags = 4;        // alive, and born under an order
        state.entities[3].faction = 0;      // the player's, whatever became of it
        state.entities[3].flags21c = 0;
        state.entities[3].at08 = 50000;
        state.entities[3].at0d = 0x14;
        simUpdateBalloons(&hunt);
        int wearing = 0;
        for (int i = 0; i < ENTITY_COUNT; i++) {
            const Entity *e = &state.entities[i];
            if (e->flags & 0x80) continue;
            if (e->at220 == 0xff) continue;
            wearing++;
            expect("a balloon is one the sheet has", e->at220 < 16, 1);
        }
        expect("somebody is wearing a balloon", wearing > 0, 1);

        expect("and the ordered one says so",
               state.entities[3].at220 == 10 || state.entities[3].at220 == 11,
               1);

        // Nobody else's units carry one.
        state.entities[3].faction = 1;
        simStep(&hunt);
        expect("another country's unit stays quiet",
               state.entities[3].at220, 0xff);
        state.entities[3].faction = 0;

        // 004237e0: aiming the chosen units at a cell, before any order.
        state.entities[3].flags21c |= 1;            // pretend it was chosen
        expect("an open cell is reachable safely",
               simReachTarget(&state, 3, 20, 20), 2);
        expect("and the balloon says so", state.entities[3].at220, 2);
        // Walled in, nothing can be reached at all.
        for (int dc = -1; dc <= 1; dc++)
            for (int dr = -1; dr <= 1; dr++)
                if (dc || dr)
                    state.world.cells[WORLD_INDEX(
                        state.entities[3].position[0] + dc,
                        state.entities[3].position[1] + dr)].blocked = 1;
        expect("walled in, nowhere is reachable",
               simReachTarget(&state, 3, 20, 20), 1);
        expect("and the balloon says that too", state.entities[3].at220, 1);
        expect("aiming the force answers for it",
               simAimSelection(&hunt, 20, 20), 0);
        for (int dc = -1; dc <= 1; dc++)
            for (int dr = -1; dr <= 1; dr++)
                state.world.cells[WORLD_INDEX(
                    state.entities[3].position[0] + dc,
                    state.entities[3].position[1] + dr)].blocked = 0;
        state.entities[3].flags21c &= ~1u;

    }

    // The name table out of the large terrain file.  It needs the game's own
    // files, so this runs only where they are - beside the repository, as the
    // build script is run.
    {
        static Host host;
        FILE *archive = fopen("ds7e.zip", "rb");
        if (archive) {
            fseek(archive, 0, SEEK_END);
            const long size = ftell(archive);
            fseek(archive, 0, SEEK_SET);
            unsigned char *bytes = (unsigned char *)malloc((size_t)size);
            if (bytes && fread(bytes, 1, (size_t)size, archive) == (size_t)size &&
                hostUseZip(&host, bytes, (unsigned)size)) {
                static World probe;
                char message[256];
                if (worldLoadStage(&probe, &host, "B_003.MAP", message,
                                   sizeof message)) {
                    expect("the name table loaded", probe.names.loaded, 1);
                    expect("country 0 is named",
                           strlen(worldCountryName(&probe, 0)) > 0, 1);
                    expect("all five countries are named",
                           strlen(worldCountryName(&probe, 4)) > 0, 1);
                    expect("and all sixteen orders",
                           strlen(worldOrderName(&probe, 15)) > 0, 1);
                    expect("a country carries a colour",
                           probe.names.colour[1] != 0, 1);
                    // 0041a680's fill, which decides whose land pays tax.
                    static GameState game;
                    game.world = probe;
                    stateStartStage(&game);

                    // Find faction 0's castle, and fill from it the way
                    // 0041dc60 does.
                    int home = -1;
                    for (int i = 0; i < WORLD_CELLS; i++)
                        if (game.world.cells[i].terrain == 0x14) { home = i; break; }
                    expect("faction 0 has a castle", home >= 0, 1);
                    if (home >= 0) {
                        const int hc = home / WORLD_GRID, hr = home % WORLD_GRID;
                        simResetFill(&game);
                        simBlockForeign(&game, 0);
                        simFillFrom(&game, hc, hr);
                        expect("the capital is nought steps from itself",
                               game.world.cells[home].cost, 0u);

                        unsigned reached = 0, own = 0;
                        for (int i = 0; i < WORLD_CELLS; i++) {
                            const WorldCell *c = &game.world.cells[i];
                            if (c->terrain != 0x0c && c->terrain != 8) continue;
                            own++;
                            if (c->cost < 0x1f0) reached++;
                        }
                        expect("some of its own ground is reachable",
                               reached > 0, 1);
                        expect("and not more than it owns", reached <= own, 1);
                        printf("  faction 0: %u of %u cells reach the capital\n",
                               reached, own);

                        // Wall the capital in and nothing but itself is left.
                        simResetFill(&game);
                        simBlockForeign(&game, 0);
                        for (int dc = -1; dc <= 1; dc++)
                            for (int dr = -1; dr <= 1; dr++) {
                                if (!dc && !dr) continue;
                                const int c = hc + dc, r = hr + dr;
                                if (c < 0 || r < 0 || c >= WORLD_GRID ||
                                    r >= WORLD_GRID) continue;
                                game.world.cells[WORLD_INDEX(c, r)].marked = 1;
                            }
                        simFillFrom(&game, hc, hr);
                        unsigned islands = 0;
                        for (int i = 0; i < WORLD_CELLS; i++)
                            if (game.world.cells[i].cost < 0x1f0) islands++;
                        expect("walled in, the capital reaches only itself",
                               islands, 1u);

                        // An empty map fills without running away: the queue is
                        // 255 long and wraps, so this must still terminate.
                        simResetFill(&game);
                        for (int i = 0; i < WORLD_CELLS; i++)
                            game.world.cells[i].marked = 0;
                        simFillFrom(&game, 24, 24);
                        unsigned open = 0;
                        for (int i = 0; i < WORLD_CELLS; i++)
                            if (game.world.cells[i].cost < 0x1f0) open++;
                        // Every cell but the outer ring, which 0041ebb0 never
                        // walks: 2304 - 188.
                        expect("an open map fills but for its edge", open,
                               WORLD_CELLS - (WORLD_GRID * 4 - 4));
                        printf("  open fill reached %u of %d cells "
                               "(all but the outer ring)\n",
                               open, WORLD_CELLS);
                    }

                    // Choosing units and sending them somewhere: 0040a020,
                    // 00409e90, 00423cc0 and the route builder underneath.
                    {
                        Sim sim;
                        simInit(&sim, &game);
                        simSeedLeaders(&sim);
                        for (int i = 0; i < 300; i++) simStep(&sim);

                        const int chosen = simSelectAll(&sim, 1);
                        expect("units can be chosen", chosen > 0, 1);
                        unsigned withBalloon = 0;
                        for (int i = 0; i < ENTITY_COUNT; i++)
                            if (game.entities[i].at220 != 0xff) withBalloon++;
                        expect("and each carries a balloon",
                               (int)withBalloon, chosen);

                        // Send them to a cell one of them can reach, and see a
                        // route appear.
                        int sent = 0, routed = 0;
                        for (int col = 4; col < 44 && !sent; col += 5)
                            for (int row = 4; row < 44 && !sent; row += 5) {
                                if (game.world.cells[WORLD_INDEX(col, row)]
                                        .terrain >= 0x30) continue;
                                sent = simOrderSelected(&sim, 8, 0, col, row);
                            }
                        expect("an order reaches somebody", sent > 0, 1);
                        for (int i = 0; i < ENTITY_COUNT; i++)
                            if (game.entities[i].at18 != 0x1f0) routed++;
                        expect("and leaves routes behind", routed > 0, 1);
                        printf("  %d chosen, %d took the order, %d hold a "
                               "route\n", chosen, sent, routed);

                        for (int i = 0; i < ENTITY_COUNT; i++)
                            expect("the balloons are cleared",
                                   game.entities[i].at220, 0xff);

                        // Follow a route on paper, the way 0041d690 reads it:
                        // route[k] is the step to take k cells along.  This
                        // checks what 00405000 wrote, with no walking code in
                        // the way.
                        {
                            static const signed char sx[8] =
                                {-1, -1, 0, 1, 1, 1, 0, -1};
                            static const signed char sy[8] =
                                {0, -1, -1, -1, 0, 1, 1, 1};
                            int checked = 0;
                            for (int i = 0; i < ENTITY_COUNT && !checked; i++) {
                                const Entity *e = &game.entities[i];
                                // Longer than the three-step table can hold,
                                // so it came from 00405000 rather than
                                // 00405250 - those are the routes this checks.
                                if (e->at18 == 0x1f0 || e->at14 < 4) continue;
                                int c = e->position[0], r = e->position[1];
                                for (unsigned k = 0; k < e->at14; k++) {
                                    c += sx[e->route[k] & 7];
                                    r += sy[e->route[k] & 7];
                                }
                                printf("  route of %u steps ends at %d,%d; "
                                       "the target is %d,%d\n", e->at14, c, r,
                                       e->target[0], e->target[1]);
                                expect("a route ends where it was aimed",
                                       c == e->target[0] && r == e->target[1],
                                       1);
                                checked = 1;
                            }
                            expect("there was a route to follow", checked, 1);
                        }

                        // And the routes are walked.  One unit on its own:
                        // twenty-three of them sent to the same cell spend
                        // their time in each other's way, which says nothing
                        // about whether walking works.
                        int walker = -1;
                        for (int i = 0; i < ENTITY_COUNT && walker < 0; i++) {
                            const Entity *e = &game.entities[i];
                            if (e->flags & 0x80) continue;
                            if (e->faction != sim.humanFaction) continue;
                            if (e->at0d & 0x20) continue;
                            // Somewhere open, a few cells off, that the fill
                            // can reach from where this unit stands.
                            simResetFill(&game);
                            simFillFrom(&game, e->position[0], e->position[1]);
                            for (int col = 2; col < 46 && walker < 0; col++)
                                for (int row = 2; row < 46 && walker < 0; row++) {
                                    const WorldCell *c =
                                        &game.world.cells[WORLD_INDEX(col, row)];
                                    if (c->cost < 6 || c->cost > 12) continue;
                                    if (simSelect(&sim, (unsigned)i,
                                                  e->position[0],
                                                  e->position[1], 1) &&
                                        simOrderSelected(&sim, 8, 0, col, row))
                                        walker = i;
                                }
                        }
                        expect("somebody holds a route worth walking",
                               walker >= 0, 1);
                        if (walker >= 0) {
                            const Entity *w = &game.entities[walker];
                            const int wasCol = w->position[0];
                            const int wasRow = w->position[1];
                            const int toCol = w->target[0];
                            const int toRow = w->target[1];
                            const int before = (wasCol > toCol ? wasCol - toCol
                                                              : toCol - wasCol) +
                                               (wasRow > toRow ? wasRow - toRow
                                                              : toRow - wasRow);
                            // It may well wander off once it arrives and finds
                            // nothing to do, so what matters is whether it got
                            // there at all.
                            int closest = before;
                            for (int i = 0; i < 1200; i++) {
                                simStep(&sim);
                                const int c = w->position[0], r = w->position[1];
                                const int d = (c > toCol ? c - toCol : toCol - c) +
                                              (r > toRow ? r - toRow : toRow - r);
                                if (d < closest) closest = d;
                            }
                            printf("  sent %d cells; closest approach %d\n",
                                   before, closest);
                            // Reported, not asserted: on a live board with
                            // sixty other units moving, how far one of them
                            // gets says nothing certain about the routing.
                            // The synthetic march below is what judges that.
                        }

                        // Dropping a choice restores what it changed.  Any of
                        // the player's own units will do; slot 1 is not
                        // necessarily one of them.
                        int mine = -1;
                        for (int i = 0; i < ENTITY_COUNT; i++) {
                            const Entity *e = &game.entities[i];
                            if (e->flags & 0x80) continue;
                            if (e->faction != sim.humanFaction) continue;
                            if (e->at0d & 0x20) continue;
                            mine = i;
                            break;
                        }
                        expect("the player has a unit to choose", mine >= 0, 1);
                        if (mine >= 0) {
                            const unsigned char facing = game.entities[mine].at0c;
                            expect("choosing it takes",
                                   simSelect(&sim, (unsigned)mine,
                                             game.entities[mine].position[0],
                                             game.entities[mine].position[1], 1),
                                   1);
                            expect("a chosen unit shows the chosen pose",
                                   game.entities[mine].at0c, 6);
                            simClearSelection(&game);
                            expect("and gets its facing back",
                                   game.entities[mine].at0c, facing);
                            expect("with the balloon gone",
                                   game.entities[mine].at220, 0xff);

                            // A route to where you already stand is not a
                            // route - but 00405000 reads the distance before
                            // it compares positions, so the field has to have
                            // been filled from there first.
                            simResetFill(&game);
                            simFillFrom(&game, game.entities[mine].position[0],
                                        game.entities[mine].position[1]);
                            expect("standing there already",
                                   simRouteTo(&game, (unsigned)mine,
                                              game.entities[mine].position[0],
                                              game.entities[mine].position[1]),
                                   10);
                            expect("an unfilled cell has no route",
                                   simRouteTo(&game, (unsigned)mine, 0, 0), 0);
                        }
                    }

                    printf("  countries:");
                    for (unsigned f = 0; f < 5; f++)
                        printf(" [%s]", worldCountryName(&probe, f));
                    printf("\n  orders:");
                    for (unsigned o = 0; o < 16; o++)
                        printf(" [%s]", worldOrderName(&probe, o));
                    putchar('\n');
                    worldFree(&probe);
                }
            }
            fclose(archive);
        }
    }

    printf(failures ? "%d check(s) failed\n" : "state checks ok\n", failures);
    return failures ? 1 : 0;
}
