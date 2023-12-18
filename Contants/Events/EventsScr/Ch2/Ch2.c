#include "global.h"
#include "event.h"
#include "eventinfo.h"
#include "eventscript.h"
#include "ea-stdlib.h"
#include "chapterdata.h"
#include "constants/event-flags.h"
#include "bmunit.h"
#include "bmtrap.h"
#include "muctrl.h"
#include "constants/items.h"
#include "constants/classes.h"

#include "common-chax.h"
#include "strmag.h"
#include "constants/chax-characters.h"
#include "constants/chax-classes.h"

const struct UnitDefinition UnitDef_Ch2_Ally[] = {
    {
        .charIndex = CHAR_CHAX_Lyn,
        .allegiance = FACTION_ID_BLUE,
        .xPosition = 2,
        .yPosition = 0,
    },
    {
        .charIndex = CHAR_CHAX_Mark,
        .allegiance = FACTION_ID_BLUE,
        .xPosition = 3,
        .yPosition = 0,
    },
    {
        .charIndex = CHAR_CHAX_Kent,
        .allegiance = FACTION_ID_BLUE,
        .xPosition = 1,
        .yPosition = 0,
    },
    {
        .charIndex = CHAR_CHAX_Sain,
        .allegiance = FACTION_ID_BLUE,
        .xPosition = 0,
        .yPosition = 0,
    },
    { 0 }
};

static const struct UnitDefinition UnitDef_Ch2_Enemy[] = {
    {
        .charIndex = CHAR_CHAX_Ch2Boss,
        .classIndex = CLASS_MERCENARY,
        .autolevel = true,
        .allegiance = FACTION_ID_RED,
        .level = 8,
        .xPosition = 11,
        .yPosition = 1,
        .itemDrop = false,
        .items = {
            ITEM_BLADE_IRON,
            ITEM_SWORD_ZANBATO,
            ITEM_BLADE_IRON,
            ITEM_VULNERARY,
        },
        .ai = { 0, 3, 9, 0x20 }
    },
    {
        .charIndex = 0x8E,
        .classIndex = CLASS_BRIGAND,
        .leaderCharIndex = CHAR_CHAX_Ch2Boss,
        .autolevel = true,
        .allegiance = FACTION_ID_RED,
        .level = 4,
        .xPosition = 7,
        .yPosition = 0,
        .items = {ITEM_AXE_HANDAXE, ITEM_AXE_IRON},
        .ai = {0, 3, 9, 0}
    },
    {
        .charIndex = 0x8E,
        .classIndex = CLASS_BRIGAND,
        .leaderCharIndex = CHAR_CHAX_Ch2Boss,
        .autolevel = true,
        .allegiance = FACTION_ID_RED,
        .level = 4,
        .xPosition = 11,
        .yPosition = 3,
        .items = {ITEM_AXE_HANDAXE, ITEM_AXE_IRON},
        .ai = {0, 3, 9, 0}
    },
    {
        .charIndex = 0x8E,
        .classIndex = CLASS_BRIGAND,
        .leaderCharIndex = CHAR_CHAX_Ch2Boss,
        .autolevel = true,
        .allegiance = FACTION_ID_RED,
        .level = 4,
        .xPosition = 7,
        .yPosition = 9,
        .items = {ITEM_AXE_HANDAXE, ITEM_AXE_IRON},
        .ai = {0, 3, 9, 0}
    },
    {
        .charIndex = 0x8E,
        .classIndex = CLASS_BRIGAND,
        .leaderCharIndex = CHAR_CHAX_Ch2Boss,
        .autolevel = true,
        .allegiance = FACTION_ID_RED,
        .level = 4,
        .xPosition = 11,
        .yPosition = 9,
        .items = {ITEM_AXE_HANDAXE, ITEM_AXE_IRON},
        .ai = {0, 3, 9, 0}
    },
    {
        .charIndex = 0x8E,
        .classIndex = CLASS_BRIGAND,
        .leaderCharIndex = CHAR_CHAX_Ch2Boss,
        .autolevel = true,
        .allegiance = FACTION_ID_RED,
        .level = 4,
        .xPosition = 13,
        .yPosition = 8,
        .items = {ITEM_AXE_HANDAXE, ITEM_AXE_IRON},
        .ai = {0, 3, 9, 0}
    },
    {
        .charIndex = 0x8E,
        .classIndex = CLASS_BRIGAND,
        .leaderCharIndex = CHAR_CHAX_Ch2Boss,
        .autolevel = true,
        .allegiance = FACTION_ID_RED,
        .level = 4,
        .xPosition = 2,
        .yPosition = 2,
        .items = {ITEM_AXE_HANDAXE, ITEM_AXE_IRON},
        .ai = {0, 3, 9, 0}
    },
    {
        .charIndex = 0x8E,
        .classIndex = CLASS_BRIGAND,
        .leaderCharIndex = CHAR_CHAX_Ch2Boss,
        .autolevel = true,
        .allegiance = FACTION_ID_RED,
        .level = 4,
        .xPosition = 3,
        .yPosition = 2,
        .items = {ITEM_AXE_HANDAXE, ITEM_AXE_IRON},
        .ai = {0, 3, 9, 0}
    },
    {
        .charIndex = 0x8E,
        .classIndex = CLASS_ARCHER,
        .leaderCharIndex = CHAR_CHAX_Ch2Boss,
        .autolevel = true,
        .allegiance = FACTION_ID_RED,
        .level = 5,
        .xPosition = 3,
        .yPosition = 5,
        .items = {ITEM_BOW_IRON, ITEM_BOW_IRON},
        .ai = {0, 0, 9, 0}
    },
    { 0 }
};

const EventListScr EventScr_BegniningScene[] = {
    LOAD2(1, UnitDef_Ch2_Ally)
    ENUN

    LOAD1(1, UnitDef_Ch2_Enemy)
    ENUN

    NoFade
    ENDA
};

const EventListScr EventScr_EndingScene[] = {
    MNC2(0x2)
    ENDA
};

const EventListScr LOCA_GiveKey[] = {
    SVAL(EVT_SLOT_3, ITEM_DOORKEY)
    GIVEITEMTO(-1)

    NoFade
    ENDA
};

const EventListScr LOCA_GiveLance[] = {
    SVAL(EVT_SLOT_3, ITEM_LANCE_AXEREAVER)
    GIVEITEMTO(-1)

    NoFade
    ENDA
};
