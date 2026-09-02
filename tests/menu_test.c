// 00423940's menu: what the game offers on each kind of square.
//
// The two tables at 0x4341af and 0x43425f are the rule, and this is the one
// place the whole rule is written out in one screen - which is worth having,
// because it is also the answer to "how do I build a bridge": click water and
// the menu has one item on it.
#include <stdio.h>
#include <string.h>

#include "../src/orders.h"
#include "../src/state.h"
#include "../src/ui.h"

static int failures;

static void expect(const char *what, long got, long want) {
    if (got == want) return;
    printf("  FAIL %s: got %ld want %ld\n", what, got, want);
    failures++;
}

int main(void) {
    // A board with a name table is not needed to ask the tables anything, but
    // the menu wants order names to measure, so it gets a made-up set.
    static GameState game;
    memset(&game, 0, sizeof game);
    for (unsigned i = 0; i < NAME_RECORDS; i++) {
        game.world.names.text[i][0] = (char)('a' + (i % 26));
        game.world.names.text[i][1] = 0;
    }
    game.world.names.loaded = 1;

    static const struct { const char *name; unsigned char terrain; } squares[] = {
        {"bare ground",   0x00},
        {"a settlement",  0x09},
        {"territory",     0x0d},
        {"a building",    0x02},
        {"a wall",        0x7b},
        {"cleared road",  0x24},
        {"a monster den", 0x05},
        {"a mine",        0x7a},
        {"scenery/water", 0x35},
        {"a castle",      0x15},
        {"rock",          0x64},
    };

    for (unsigned s = 0; s < sizeof squares / sizeof squares[0]; s++) {
        game.world.cells[WORLD_INDEX(20, 20)].terrain = squares[s].terrain;
        OrderMenu menu;
        const int any = uiOrderOpen(&menu, &game, 20, 20, 100, 100, 640, 480);
        printf("  %-14s ", squares[s].name);
        if (!any) {
            printf("(nothing)\n");
            continue;
        }
        for (int i = 0; i < menu.count; i++)
            printf(" %d%s", menu.order[i],
                   orderStrengths(menu.order[i]) == 2 ? "*" : "");
        putchar('\n');
        uiOrderClose(&menu);
    }
    printf("  (* means the order has no \"continue\" row)\n");

    // The three the answer turns on.
    {
        OrderMenu menu;
        game.world.cells[WORLD_INDEX(20, 20)].terrain = 0x35;
        uiOrderOpen(&menu, &game, 20, 20, 0, 0, 640, 480);
        expect("water offers one order", menu.count, 1);
        expect("and it is order 7", menu.order[0], 7);
        expect("which has no continue row", orderStrengths(7), 2);
        uiOrderClose(&menu);

        game.world.cells[WORLD_INDEX(20, 20)].terrain = 0x24;
        uiOrderOpen(&menu, &game, 20, 20, 0, 0, 640, 480);
        int hasBlock = 0;
        for (int i = 0; i < menu.count; i++) if (menu.order[i] == 10) hasBlock = 1;
        expect("a road can be blocked again", hasBlock, 1);
        uiOrderClose(&menu);

        game.world.cells[WORLD_INDEX(20, 20)].terrain = 0x7b;
        uiOrderOpen(&menu, &game, 20, 20, 0, 0, 640, 480);
        expect("a wall offers two orders", menu.count, 2);
        expect("build it", menu.order[0], 6);
        expect("and pull it down", menu.order[1], 9);
        uiOrderClose(&menu);
    }

    // And the menu itself: opening it, walking into a submenu, choosing.
    {
        OrderMenu menu;
        game.world.cells[WORLD_INDEX(20, 20)].terrain = 0x35;
        expect("the menu opens", uiOrderOpen(&menu, &game, 20, 20, 40, 40,
                                             640, 480), 1);
        const int rowY = menu.y + 2 + UI_ITEM_H / 2;
        unsigned order = 99;
        int strength = 99;
        expect("clicking the order opens its rows",
               uiOrderClick(&menu, &game, menu.x + 10, rowY, &order,
                            &strength), 0);
        expect("which are there", menu.subOf, 0);
        const int subY = menu.subY + 2 + UI_ITEM_H + UI_ITEM_H / 2;
        expect("and clicking one is the answer",
               uiOrderClick(&menu, &game, menu.subX + 10, subY, &order,
                            &strength), 1);
        expect("the order", (long)order, 7);
        expect("in the second strength", strength, 1);
        expect("and the menu is gone", menu.open, 0);

        uiOrderOpen(&menu, &game, 20, 20, 40, 40, 640, 480);
        expect("a click outside dismisses it",
               uiOrderClick(&menu, &game, 600, 400, &order, &strength), -1);
        expect("so it is gone too", menu.open, 0);
    }

    printf(failures ? "%d menu check(s) failed\n" : "menu checks ok\n",
           failures);
    return failures ? 1 : 0;
}
