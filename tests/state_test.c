// Checks the ported state chain against the sizes and values the executable
// uses, so a wrong offset shows up here rather than as odd behaviour later.
#include <stdio.h>
#include <stddef.h>
#include <string.h>

#include "../src/sim.h"
#include "../src/state.h"

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
    expect("WorldCell.owner", (long)offsetof(WorldCell, owner), 0x00);
    expect("WorldCell.marked", (long)offsetof(WorldCell, marked), 0x04);
    expect("WorldCell.blocked", (long)offsetof(WorldCell, blocked), 0x05);
    expect("WorldCell.cost", (long)offsetof(WorldCell, cost), 0x08);
    expect("WorldCell.value", (long)offsetof(WorldCell, value), 0x0c);
    expect("WorldCell.terrain", (long)offsetof(WorldCell, terrain), 0x10);
    expect("WorldCell.troops", (long)offsetof(WorldCell, troops), 0x14);

    // The reset values, and the two things the chain derives.
    static GameState state;
    memset(&state, 0, sizeof state);
    for (int i = 0; i < WORLD_CELLS; i++)
        state.world.cells[i].terrain = (unsigned char)(i % 0x60);
    stateStartStage(&state);

    expect("faction funds after reset", state.factions[0].funds, 5000);
    expect("entity inactive after reset", state.entities[0].flags, 0x80);
    expect("entity at18 after reset", state.entities[0].at18, 0x1f0);
    expect("cell owner after place", state.world.cells[0].owner, 0x40);
    expect("blocked at terrain 0x2f", state.world.cells[0x2f].blocked, 0);
    expect("blocked at terrain 0x30", state.world.cells[0x30].blocked, 1);
    // Every playable faction starts with no strength, so all four are marked.
    expect("defeated flag with no strength", state.factions[0].flags & 0x10,
           0x10);
    expect("fifth faction untouched", state.factions[4].flags & 0x10, 0);

    // An active entity writes its own index into the cell it stands on.
    state.entities[7].flags = 0;
    state.entities[7].position[0] = 5;      // column
    state.entities[7].position[1] = 9;      // row
    statePlaceEntities(&state);
    expect("cell owner from entity", state.world.cells[WORLD_INDEX(5, 9)].owner,
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
    // Direction 5 is (+1, +1), the one 0041d690 falls back on.
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
        e->at18 = 0x1f0;                        // no route: direction 5
        e->at0c = 0;                            // facing the wrong way
        e->position[0] = 20;
        e->position[1] = 20;
        state.world.cells[WORLD_INDEX(20, 20)].owner = 1;
        simStepEntities(&walk);
        expect("the leader turned first", e->at0c, 5);
        expect("and did not move yet",
               e->position[0] * 100 + e->position[1], 20 * 100 + 20);
        simStepEntities(&walk);
        expect("then it stepped", e->position[0] * 100 + e->position[1],
               21 * 100 + 21);
        expect("it left the cell behind",
               state.world.cells[WORLD_INDEX(20, 20)].owner, 0x40);
        expect("and occupies the new one",
               state.world.cells[WORLD_INDEX(21, 21)].owner, 1);

        // Scenery stops it, and clears the route of anyone but the player.
        state.world.cells[WORLD_INDEX(22, 22)].terrain = 0x60;
        e->at18 = 0;
        e->route[0] = 5;
        simStepEntities(&walk);
        expect("scenery stopped the step",
               e->position[0] * 100 + e->position[1], 21 * 100 + 21);
        expect("and the route was cleared", e->at18, 0x1f0);

        // So does somebody else's unit - it becomes a fight instead of a step.
        state.world.cells[WORLD_INDEX(22, 22)].terrain = 0;
        state.world.cells[WORLD_INDEX(22, 22)].owner = 9;
        state.entities[9].flags = 0;
        state.entities[9].faction = 1;          // an enemy
        state.entities[9].at08 = 5000;
        e->at18 = 0;
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
        e->at0d = 4;                       // an order nothing is ported for
        e->at18 = 0x1f0;
        e->at08 = 4096;
        e->position[0] = 20;
        e->position[1] = 20;
        state.world.cells[WORLD_INDEX(20, 20)].terrain = 8;   // its own ground
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
        a->at08 = 4000; a->at0c = 5; a->at18 = 0x1f0;
        a->position[0] = 15; a->position[1] = 15;
        state.world.cells[WORLD_INDEX(15, 15)].terrain = 0x14;   // on a castle
        state.world.cells[WORLD_INDEX(15, 15)].owner = 1;
        Entity *b = &state.entities[9];
        b->flags = 0; b->faction = 2; b->at08 = 300;
        b->position[0] = 16; b->position[1] = 16;
        state.world.cells[WORLD_INDEX(16, 16)].owner = 9;
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
        a->at08 = 4000; a->at0c = 5; a->at18 = 0x1f0;
        a->position[0] = 18; a->position[1] = 18;
        state.world.cells[WORLD_INDEX(18, 18)].terrain = 8;   // its own ground
        state.world.cells[WORLD_INDEX(18, 18)].owner = 1;
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
        a->at08 = 1000; a->at0c = 5; a->at18 = 0x1f0;
        a->position[0] = 22; a->position[1] = 22;
        state.world.cells[WORLD_INDEX(22, 22)].terrain = 8;
        state.world.cells[WORLD_INDEX(22, 22)].owner = 1;
        Entity *b = &state.entities[9];
        b->flags = 0; b->faction = 0; b->at08 = 700;
        b->position[0] = 23; b->position[1] = 23;
        state.world.cells[WORLD_INDEX(23, 23)].owner = 9;
        state.factions[0].funds = 100000;
        simStepEntities(&join);
        expect("the leader absorbed its own", a->at08 >= 1000 + 700 - 8, 1);
        expect("the absorbed unit went inactive", b->flags & 0x80, 0x80);
        expect("and the leader took the cell",
               a->position[0] * 100 + a->position[1], 23 * 100 + 23);
    }

    printf(failures ? "%d check(s) failed\n" : "state checks ok\n", failures);
    return failures ? 1 : 0;
}
