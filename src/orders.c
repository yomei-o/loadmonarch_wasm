#include "orders.h"

// 0x4341af and 0x43425f, read out of the executable.  The original indexes
// them as base + class * 16 - order, so within each sixteen-byte row the order
// number runs backwards; here they are the way round they read.
static const unsigned char kOrderOnA[11][16] = {
    {1,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0},
    {1,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0},
    {1,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0},
    {1,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0},
    {1,1,1,0,0,0,0,0,0,0,1,0,0,0,0,0},
    {1,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
    {1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0},
    {1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
};

static const unsigned char kOrderOnB[11][16] = {
    {1,1,1,1,1,1,1,0,1,0,0,0,0,0,0,0},
    {1,1,1,1,1,1,1,0,1,0,0,0,0,0,0,0},
    {1,1,1,1,1,1,1,0,1,0,0,0,0,0,0,0},
    {1,1,1,1,1,1,0,0,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0},
    {1,1,1,1,1,1,0,0,1,0,1,0,0,0,0,0},
    {1,1,1,1,1,1,0,0,1,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
    {1,1,1,1,1,1,0,0,1,0,0,0,0,0,0,0},
    {1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
};

OrderClass orderClassOf(unsigned char terrain) {
    if (terrain == 0) return ORDER_CLASS_BARE;
    if (terrain >= 8 && terrain <= 0x0b) return ORDER_CLASS_SETTLEMENT;
    if (terrain >= 0x0c && terrain <= 0x0f) return ORDER_CLASS_TERRITORY;
    if (terrain >= 1 && terrain <= 4) return ORDER_CLASS_BUILDING;
    if (terrain == 0x7b) return ORDER_CLASS_WALL;
    if (terrain >= 0x20 && terrain <= 0x2f) return ORDER_CLASS_CLEARED;
    if (terrain == 5) return ORDER_CLASS_DEN;
    if (terrain == 0x7a) return ORDER_CLASS_MINE;
    if (terrain >= 0x30 && terrain < 0x60) return ORDER_CLASS_ROUGH;
    if (terrain >= 0x14 && terrain <= 0x17) return ORDER_CLASS_CASTLE;
    return ORDER_CLASS_OTHER;
}

int orderAllowedOn(OrderClass klass, unsigned order) {
    if (klass < 0 || klass >= ORDER_CLASS_COUNT || order >= 16) return 0;
    return kOrderOnA[klass][order] || kOrderOnB[klass][order];
}

int orderStrengths(unsigned order) {
    // 00423940 skips the "continue" row for one order only: the name it leaves
    // out is at 0x435bfd, which is order name seven.
    return order == 7 ? 2 : 3;
}
