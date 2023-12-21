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

static const struct REDA REDA_Lyn[] = {
    {
        .x = 13,
        .y = 7,
    },
    { 0 },
};

static const struct REDA REDA_Mark[] = {
    {
        .x = 14,
        .y = 7,
    },
    { 0 },
};

const struct UnitDefinition UnitDef_Ally[] = {
    {
        .charIndex = CHAR_CHAX_Lyn,
        .classIndex = CLASS_CHAX_LYN_T1,
        .autolevel = false,
        .allegiance = FACTION_ID_BLUE,
        .level = 1,
        .xPosition = 14,
        .yPosition = 9,
        .redaCount = 1,
        .redas = REDA_Lyn,
        .items = {
            ITEM_SWORD_IRON,
            ITEM_SWORD_SHAMSIR,
            ITEM_VULNERARY,
            ITEM_ELIXIR
        },
    },
    { 0 }
};

const struct UnitDefinition UnitDef_AllyMark[] = {
    {
        .charIndex = CHAR_CHAX_Mark,
        .classIndex = CLASS_CHAX_Mark_T1,
        .autolevel = false,
        .allegiance = FACTION_ID_BLUE,
        .level = 1,
        .xPosition = 14,
        .yPosition = 9,
        .redaCount = 1,
        .redas = REDA_Mark,
        .items = {
            ITEM_SWORD_IRON,
            ITEM_VULNERARY,
        },
    },
    { 0 }
};

static const struct UnitDefinition UnitDef_Enemy[] = {
    {
        .charIndex = CHAR_CHAX_PrologueBoss,
        .classIndex = CLASS_BRIGAND,
        .autolevel = false,
        .allegiance = FACTION_ID_RED,
        .level = 5,
        .xPosition = 3,
        .yPosition = 2,
        .itemDrop = true,
        .items = {
            ITEM_AXE_IRON,
            ITEM_SWORD_IRON
        },
        .ai = { 3, 3, 9, 0 }
    },
    {
        .charIndex = 0x8E,
        .classIndex = CLASS_BRIGAND,
        .leaderCharIndex = CHAR_CHAX_PrologueBoss,
        .autolevel = true,
        .allegiance = FACTION_ID_RED,
        .level = 3,
        .xPosition = 2,
        .yPosition = 6,
        .items = {ITEM_AXE_HANDAXE},
        .ai = {0, 0, 9, 0}
    },
    {
        .charIndex = 0x8E,
        .classIndex = CLASS_BRIGAND,
        .leaderCharIndex = CHAR_CHAX_PrologueBoss,
        .autolevel = true,
        .allegiance = FACTION_ID_RED,
        .level = 3,
        .xPosition = 7,
        .yPosition = 1,
        .items = {ITEM_AXE_HANDAXE},
        .ai = {0, 0, 9, 0}
    },
    { 0 }
};

static void SetUnit(struct Unit * unit,
        int hp, int lv,
        int pow, int mag, int skl,
        int spd, int lck, int def, int res)
{
    unit->maxHP = hp;
    unit->curHP = hp;
    unit->level = lv;
    unit->pow = pow;
    UNIT_MAG(unit) = mag;
    unit->skl = skl;
    unit->spd = spd;
    unit->lck = lck;
    unit->def = def;
    unit->res = res;
}

static void SetEnemyInfo(void)
{
    SetUnit(
        GetUnitAtPosition(3, 2),
        30, 5,
        15, 0, 13,
        9, 10, 5, 4);

    SetUnit(
        GetUnitAtPosition(2, 6),
        24, 3,
        10, 0, 9,
        6, 6, 3, 1);

    SetUnit(
        GetUnitAtPosition(7, 1),
        24, 3,
        10, 0, 9,
        6, 6, 3, 1);
}

const EventListScr EventScr_BegniningScene[] = {
    LOAD1(1, UnitDef_Enemy)
    ENUN

    FADU(16)

    ASMC(SetEnemyInfo)

    CAMERA(14, 9)

    CURSOR_FLASHING(14, 9)
    STAL(60)
    CURE

    LOAD1(1, UnitDef_Ally)

    STAL(10)
    LOAD1(1, UnitDef_AllyMark)
    ENUN

    // _EvtAutoCmdLen2(0x3E),

    NoFade
    ENDA
};

const EventListScr EventScr_EndingScene[] = {
    MNC2(0x1)
    ENDA
};
