#include "global.h"
#include "bmunit.h"
#include "bmitem.h"
#include "ekrbattle.h"
#include "constants/classes.h"

#include "common-chax.h"
#include "constants/texts.h"
#include "constants/chax-classes.h"

extern const struct BattleAnimDef LynLord_Anims[];

const struct ClassData JInfo_Baigand = {
    .nameTextId = 0x2DE,
    .descTextId = 0x329,
    .number = CLASS_BRIGAND,
    .promotion = CLASS_BERSERKER,
    .SMSId = 0x33,
    .slowWalking = 0,
    .defaultPortraitId = 0x8B,
    .sort_order = 0,

    .baseHP = 20,
    .basePow = 5,
    .baseSkl = 1,
    .baseSpd = 5,
    .baseDef = 3,
    .baseRes = 0,
    .baseCon = 12,
    .baseMov = 5,

    .maxHP = 60,
    .maxPow = 20,
    .maxSkl = 20,
    .maxSpd = 20,
    .maxDef = 20,
    .maxRes = 20,
    .maxCon = 20,

    .classRelativePower = 3,

    .growthHP = 82,
    .growthPow = 50,
    .growthSkl = 30,
    .growthSpd = 20,
    .growthDef = 10,
    .growthRes = 13,
    .growthLck = 15,

    .attributes = 0,

    .baseRanks = {
        [ITYPE_AXE] = WPN_EXP_D
    },

    .pBattleAnimDef = (void *)0x88AF468,
    .pMovCostTable = {
        (void *)0x880B94D,
        (void *)0x880BD9E,
        (void *)0x880C1AE,
    },

    .pTerrainAvoidLookup = (void *)0x880C479,
    .pTerrainDefenseLookup = (void *)0x880C4BA,
    .pTerrainResistanceLookup = (void *)0x880C4FB,
    ._pU50 = (void *)0x880C5FF
};
