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

    printf(failures ? "%d check(s) failed\n" : "state checks ok\n", failures);
    return failures ? 1 : 0;
}
