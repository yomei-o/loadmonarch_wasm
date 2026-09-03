// The simulation sweep.  See sim.c for what the terrain byte encodes.
#ifndef SIM_H
#define SIM_H

#include "state.h"

// What 0041f0d0 announces while it takes a country apart, kept for the host to
// show: it opens dialog 122 for the country itself and then, once the second
// of the four has gone, for every country still standing that had an ally.
// They are modal in the original - DialogBoxParamA blocks - so they queue.
#define SIM_EVENTS_MAX 8
typedef enum {
    SIM_EVENT_FALLEN = 0,           // dialog 122's mode 0
    SIM_EVENT_BREAK_ALLIANCE = 1    // its mode 1
} SimEventKind;

typedef struct {
    unsigned char kind;
    unsigned char faction;
    unsigned char other;        // the ally, for a broken alliance
} SimEvent;

typedef struct {
    GameState *state;
    unsigned cursor;            // DAT_00437690 / DAT_004369fc
    unsigned entityCursor;      // DAT_004377fc
    unsigned long long frames;
    unsigned humanFaction;      // DAT_004365cd
    int autoTax;                // DAT_0043769c == 1
    unsigned pendingOrder;      // DAT_004365e0, stamped onto a new unit

    // DAT_0043781c.  0040a5e0 puts four back at the top of every tick, and
    // 0041eb60 spends one whenever a unit tries to act where it stands.  Only
    // four units a tick get that far; the rest are told to wait, which is what
    // keeps a board of sixty-four from doing sixty-four searches at once.
    int budget;

    // DAT_0043451c.  Set when something the player wanted could not be paid
    // for, cleared at the top of every entity sweep, and read by the balloon
    // pass - which is the only way the game tells you that you are broke.
    int shortOfFunds;

    // 0041b4f0's two clocks, which move on every other tick.  DAT_004365c8
    // counts up and is what the game scores you on - its own README asks for
    // the fewest days - and DAT_004365c4 counts down, which is what a stage
    // with a limit runs out of.
    unsigned days;
    unsigned countdown;

    // 00423cc0's asking, which the original does with a modal dialog in the
    // middle of its loop.  DAT_00434548 is the policy - 0 ask, 1 let the rest
    // through, 2 hold the rest back - DAT_0043454c the unit being asked about
    // and DAT_00434544 which of the two things is wrong with its route.  The
    // rest is where to pick the loop up again.
    int askPolicy;
    int askUnit;
    int askKind;                // 0 a friend in the way, 1 enemies in the path
    int askAt;                  // the entity the loop stopped on
    int askGiven;               // how many had taken the order by then
    unsigned askOrder;
    int askModifier, askCol, askRow;

    // DAT_004321c4: whoever is wearing the leader balloon because the player
    // asked to be shown him, so the next asking can take it off again.
    int shownLeader;

    // 0041f0d0's announcements, waiting for the host to show them.
    SimEvent event[SIM_EVENTS_MAX];
    int events;
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

// The Orders menu's Recall Leader (40113): send this country's leader back to
// its castle through 00421660.  Non-zero when a route came back.
int simRecallLeader(Sim *sim, unsigned faction);

// The Leader Position submenu (40080 to 40083, which 00408aa0 renames to the
// four countries).  It puts the leader balloon over that country's king,
// takes it off whoever had it, and answers where he is so a host can scroll
// there - which is what 00423f90 is doing in the original.
int simShowLeader(Sim *sim, unsigned faction, int *col, int *row);


// 0040a110.  Which of the stage's two tunes the war calls for: 0 while the
// player is behind the other three put together, 1 while it is eight times
// their combined strength, -1 anywhere between - leave what is playing alone.
int simMusicWanted(const Sim *sim);

// 0041f0d0, 0041f090 and 0041f4c0: the end of a country and the end of a
// stage.  A country that has lost its leader or its strength is finished off -
// its castle wiped, its purse handed to whoever +0x1f names - and the stage is
// over when the player is out, or when three of the four are.
void simConquerFaction(Sim *sim, unsigned faction);

// Takes the oldest one and answers non-zero, or nothing and answers zero.
int simTakeEvent(Sim *sim, SimEvent *out);
void simCheckConquest(Sim *sim);
int simStageOutcome(Sim *sim);      // 0 playing, 1 the player won, 2 lost

// What a finished stage was worth, which is what dialog 104's Information,
// Area, Battle and Results groups list.  0041aa30 works out the area half and
// 0041aaf0 the battle half; 0041f4c0 puts the two together.
typedef struct {
    unsigned winner;            // DAT_00436400: the first country still in

    // Area: how much of the board there was to take and how much the winner
    // holds, as a percentage to two decimals, and the same as a whole number,
    // which is what comes off the days.
    unsigned claimable;         // DAT_00436418
    unsigned held;              // DAT_00436414
    float areaPercent;          // DAT_0043641c
    unsigned penalty;           // DAT_00436420

    // Battle: what the winner lost against what everybody else lost.  Killing
    // more than you lose is worth up to five hundred days, and only while
    // there is time left on the clock.
    unsigned yourLosses;        // DAT_00436424
    unsigned enemyLosses;       // DAT_00436428
    float battlePercent;        // DAT_0043642c
    unsigned bonus;             // DAT_00436430, capped at 500

    unsigned daysLeft;          // DAT_00436410
    int remaining;              // DAT_00436404: daysLeft - penalty + bonus
} StageScore;

void simStageScore(const Sim *sim, StageScore *out);

// 00421910.  A unit on one of its own country's settlements takes it up: the
// cell's worth becomes the unit's, and the cell goes back to bare ground.
int simAbsorbOwnCell(Sim *sim, unsigned slot);

// 0041f790.  Puts a balloon over each of the player's units that has something
// to say: under orders, out of money, too small for the job, or - over the
// leader - away from home.  Runs every tick and clears the rest.
void simUpdateBalloons(Sim *sim);

// 0041a9f0.  The distance field as one particular unit sees it: cleared,
// painted with what that unit must keep away from (00405510), then flooded
// from where it stands.
void simPrepareFill(GameState *state, unsigned slot, int col, int row);

// 00405000 and its two helpers.  simRouteTo turns a filled distance field into
// a route the unit can walk - 1 if it laid one, 10 if the unit is already
// there, 0 if it cannot be reached.  simUnblockTarget (004056f0) opens a wall
// or cave the order is aimed at, and simShortenRoute (004051b0) stops a unit
// one cell short, which is how the building orders work.
int simRouteTo(GameState *state, unsigned slot, int col, int row);
void simUnblockTarget(GameState *state, int col, int row);
int simShortenRoute(GameState *state, unsigned slot);

// Choosing units and giving them an order, from 0040a020, 00409e90/00409f10,
// 00409f90 and 00423cc0.  A chosen unit carries a balloon until the order is
// given or the choice is dropped.  simSelectAll's `force` picks the units that
// already have orders as well as the idle ones.
int simSelect(Sim *sim, unsigned slot, int col, int row, int force);
int simSelectAll(Sim *sim, int force);
void simClearSelection(GameState *state);
// Answers how many units took the order, or SIM_ORDER_ASK when one of them
// can only get there the hard way and the player has to say whether it should.
// The host shows the Information dialog and calls simOrderAnswer, which picks
// the loop up where it stopped.
#define SIM_ORDER_ASK (-1)
int simOrderSelected(Sim *sim, unsigned order, int modifier, int col, int row);

// 0 Go, 1 Don't go, 2 Remainder go, 3 Remainder don't go - the four buttons of
// dialog 118, in the order the resource has them.  Answers as above.
int simOrderAnswer(Sim *sim, int choice);

// 004237e0 and the loop over it.  Asks a chosen unit whether it can reach a
// cell and writes the answer into the balloon over its head - 2 safely, 3 only
// through danger, 4 only by pushing past its own people, 1 not at all.
// simAimSelection asks the whole chosen force and is non-zero when at least one
// can go safely.  This is the live answer the game shows while the pointer
// moves, before any order is given.
int simReachTarget(GameState *state, unsigned slot, int col, int row);
int simAimSelection(Sim *sim, int col, int row);

// 00405360, 00405390 and 0041a680: the distance fill 0041dc60 runs before it
// collects tax.  Reset every cell, shut the fill out of foreign ground, then
// walk it from one cell, leaving distances in each cell's +0x08.  Territory the
// walk cannot reach is territory that stops paying.
void simResetFill(GameState *state);
void simBlockForeign(GameState *state, unsigned faction);
void simFillFrom(GameState *state, int col, int row);

#endif
