// Which order may be given on which square, and how the three strengths are
// worded - both straight out of 00423940 and the two tables it reads.
//
// This is the piece that says how the game is played.  The original's flow is:
// choose units, click the square you want something done to, and a popup comes
// up *at the cursor* listing the orders that make sense there.  Click water and
// the only thing offered is order 7, which is how a bridge gets built.
#ifndef ORDERS_H
#define ORDERS_H

// The eleven kinds of square 00423940 sorts terrain into, in its own order.
typedef enum {
    ORDER_CLASS_BARE = 0,       // terrain 0
    ORDER_CLASS_SETTLEMENT,     // 8..0x0b
    ORDER_CLASS_TERRITORY,      // 0x0c..0x0f
    ORDER_CLASS_BUILDING,       // 1..4
    ORDER_CLASS_WALL,           // 0x7b
    ORDER_CLASS_CLEARED,        // 0x20..0x2f
    ORDER_CLASS_DEN,            // 5
    ORDER_CLASS_MINE,           // 0x7a
    ORDER_CLASS_ROUGH,          // 0x30..0x5f - scenery on land, water at sea
    ORDER_CLASS_CASTLE,         // 0x14..0x17
    ORDER_CLASS_OTHER,          // everything else, which is rock
    ORDER_CLASS_COUNT
} OrderClass;

// 00423940's opening ladder.
OrderClass orderClassOf(unsigned char terrain);

// Whether the popup offers this order on that kind of square.  The original
// keeps two tables and enables an item when either says so.
int orderAllowedOn(OrderClass klass, unsigned order);

// The three rows every order gets, except one: order 7 has no "continue".
// 0 is "go back to Auto when it is done", 1 "stop where you are" (+0x40) and
// 2 "look for another one like it" (+0x80).
int orderStrengths(unsigned order);

#endif
