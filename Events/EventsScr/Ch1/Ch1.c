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

extern const struct REDA REDA_Ch1_Lyn[];
extern const struct REDA REDA_Ch1_Mark[];
extern const struct REDA REDA_Ch1_Sain[];
extern const struct REDA REDA_Ch1_Kent[];
extern const struct REDA REDA_Ch1_Enemy1[];
extern const struct REDA REDA_Ch1_Enemy2[];
extern const struct REDA REDA_Ch1_Enemy3[];
extern const struct REDA REDA_Ch1_Enemy4[];
extern const struct REDA REDA_Ch1_Enemy5[];

const struct UnitDefinition UnitDef_Ch1_Ally[] = {
    {
        .charIndex = CHAR_CHAX_Lyn,
        .classIndex = CLASS_CHAX_LYN_T1,
        .autolevel = false,
        .allegiance = FACTION_ID_BLUE,
        .level = 1,
        .xPosition = 1,
        .yPosition = 1,
        .redaCount = 1,
        .redas = REDA_Ch1_Lyn,
        .items = {
            ITEM_SWORD_IRON,
            ITEM_SWORD_SHAMSIR,
            ITEM_VULNERARY,
            ITEM_ELIXIR
        },
    },
    {
        .charIndex = CHAR_CHAX_Mark,
        .classIndex = CLASS_CHAX_Mark_T1,
        .autolevel = false,
        .allegiance = FACTION_ID_BLUE,
        .level = 1,
        .xPosition = 1,
        .yPosition = 0,
        .redaCount = 1,
        .redas = REDA_Ch1_Mark,
        .items = {
            ITEM_SWORD_IRON,
            ITEM_VULNERARY,
        },
    },
    { 0 }
};

const struct UnitDefinition UnitDef_AllySain[] = {
    {
        .charIndex = CHAR_CHAX_Sain,
        .classIndex = CLASS_CAVALIER,
        .autolevel = false,
        .allegiance = FACTION_ID_BLUE,
        .level = 1,
        .xPosition = 1,
        .yPosition = 1,
        .redaCount = 1,
        .redas = REDA_Ch1_Sain,
        .items = {
            ITEM_LANCE_IRON,
            ITEM_VULNERARY,
        },
    },
    {
        .charIndex = CHAR_CHAX_Kent,
        .classIndex = CLASS_CAVALIER,
        .autolevel = false,
        .allegiance = FACTION_ID_BLUE,
        .level = 1,
        .xPosition = 1,
        .yPosition = 0,
        .redaCount = 1,
        .redas = REDA_Ch1_Kent,
        .items = {
            ITEM_LANCE_IRON,
            ITEM_VULNERARY,
        },
    },
    { 0 }
};



const struct UnitDefinition UnitDef_AllyKent[] = {
    {
        .charIndex = CHAR_CHAX_Sain,
        .classIndex = CLASS_CAVALIER,
        .autolevel = false,
        .allegiance = FACTION_ID_BLUE,
        .level = 1,
        .xPosition = 0,
        .yPosition = 1,
        .redaCount = 1,
        .redas = REDA_Ch1_Kent,
        .items = {
            ITEM_LANCE_IRON,
            ITEM_VULNERARY,
        },
    },
    { 0 }
};

static const struct UnitDefinition UnitDef_Enemy[] = {
    {
        .charIndex = CHAR_CHAX_Ch1Boss,
        .classIndex = CLASS_BRIGAND,
        .autolevel = false,
        .allegiance = FACTION_ID_RED,
        .level = 6,
        .xPosition = 13,
        .yPosition = 0,
        .itemDrop = true,
        .items = {
            ITEM_AXE_IRON,
            ITEM_AXE_HANDAXE,
            ITEM_VULNERARY,
            ITEM_LANCE_JAVELIN,
        },
        .ai = { 0, 3, 9, 0x20 }
    },
    {
        .charIndex = 0x8E,
        .classIndex = CLASS_BRIGAND,
        .leaderCharIndex = CHAR_CHAX_Ch1Boss,
        .autolevel = true,
        .allegiance = FACTION_ID_RED,
        .level = 3,
        .xPosition = 11,
        .yPosition = 6,
        .redaCount = 1,
        .redas = REDA_Ch1_Enemy4,
        .items = {ITEM_AXE_IRON},
        .ai = {0, 3, 9, 0}
    },
    {
        .charIndex = 0x8E,
        .classIndex = CLASS_BRIGAND,
        .leaderCharIndex = CHAR_CHAX_Ch1Boss,
        .autolevel = true,
        .allegiance = FACTION_ID_RED,
        .level = 3,
        .xPosition = 1,
        .yPosition = 0,
        .redaCount = 1,
        .redas = REDA_Ch1_Enemy5,
        .items = {ITEM_AXE_HANDAXE, ITEM_VULNERARY},
        .ai = {0, 3, 9, 0x20}
    },
    {
        .charIndex = 0x8E,
        .classIndex = CLASS_BRIGAND,
        .leaderCharIndex = CHAR_CHAX_Ch1Boss,
        .autolevel = true,
        .allegiance = FACTION_ID_RED,
        .level = 3,
        .xPosition = 6,
        .yPosition = 0,
        .items = {ITEM_AXE_IRON},
        .ai = {0, 3, 9, 0}
    },
    {
        .charIndex = 0x8E,
        .classIndex = CLASS_BRIGAND,
        .leaderCharIndex = CHAR_CHAX_Ch1Boss,
        .autolevel = true,
        .allegiance = FACTION_ID_RED,
        .level = 3,
        .xPosition = 11,
        .yPosition = 2,
        .items = {ITEM_AXE_IRON},
        .ai = {0, 3, 9, 0}
    },
    {
        .charIndex = 0x8E,
        .classIndex = CLASS_BRIGAND,
        .leaderCharIndex = CHAR_CHAX_Ch1Boss,
        .autolevel = true,
        .allegiance = FACTION_ID_RED,
        .level = 3,
        .xPosition = 10,
        .yPosition = 6,
        .items = {ITEM_AXE_IRON},
        .ai = {0, 3, 9, 0}
    },
    { 0 }
};

static const struct UnitDefinition UnitDef_Enemy2[] = {
    {
        .charIndex = 0x8E,
        .classIndex = CLASS_BRIGAND,
        .leaderCharIndex = CHAR_CHAX_Ch1Boss,
        .autolevel = true,
        .allegiance = FACTION_ID_RED,
        .level = 3,
        .xPosition = 7,
        .yPosition = 3,
        .redaCount = 1,
        .redas = REDA_Ch1_Enemy1,
        .items = {ITEM_AXE_IRON},
        .ai = {0, 3, 9, 0}
    },
    {
        .charIndex = 0x8E,
        .classIndex = CLASS_BRIGAND,
        .leaderCharIndex = CHAR_CHAX_Ch1Boss,
        .autolevel = true,
        .allegiance = FACTION_ID_RED,
        .level = 3,
        .xPosition = 13,
        .yPosition = 1,
        .redaCount = 1,
        .redas = REDA_Ch1_Enemy2,
        .items = {ITEM_AXE_IRON},
        .ai = {0, 3, 9, 0}
    },
    {
        .charIndex = 0x8E,
        .classIndex = CLASS_BRIGAND,
        .leaderCharIndex = CHAR_CHAX_Ch1Boss,
        .autolevel = true,
        .allegiance = FACTION_ID_RED,
        .level = 3,
        .xPosition = 11,
        .yPosition = 6,
        .redaCount = 1,
        .redas = REDA_Ch1_Enemy3,
        .items = {ITEM_AXE_IRON},
        .ai = {0, 3, 9, 0}
    },
    {0}
};

const EventListScr EventScr_BegniningScene[] = {
    LOAD2(1, UnitDef_Ch1_Ally)
    ENUN

    LOAD1(1, UnitDef_Enemy)
    LOAD1(1, UnitDef_Enemy2)
    ENUN

    LOAD1(1, UnitDef_AllySain)
    ENUN

    NoFade
    ENDA
};

const EventListScr EventScr_EndingScene[] = {
    MNCH(0x2)
    ENDA
};

const EventListScr LOCA_GiveItem[] = {
    SVAL(EVT_SLOT_3, ITEM_SWORD_SLIM)
    GIVEITEMTO(-1)

    NoFade
    ENDA
};
