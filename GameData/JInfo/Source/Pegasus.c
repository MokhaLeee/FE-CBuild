#include "global.h"
#include "bmunit.h"
#include "bmitem.h"
#include "ekrbattle.h"
#include "constants/classes.h"

#include "common-chax.h"
#include "constants/texts.h"
#include "constants/chax-classes.h"

const struct ClassData JInfo_Pegasus = {
    .nameTextId = 0x2E7,
    .descTextId = 0x333,
    .number = CLASS_PEGASUS_KNIGHT,
    .promotion = CLASS_FALCON_KNIGHT,
    .SMSId = 0x39,
    .slowWalking = 0,
    .defaultPortraitId = 0x86,
    .sort_order = 0x10,

    .baseHP = 18,
    .basePow = 3,
    .baseSkl = 6,
    .baseSpd = 7,
    .baseDef = 1,
    .baseRes = 9,
    .baseCon = 5,
    .baseMov = 7,

    .maxHP = 40,
    .maxPow = 22,
    .maxSkl = 26,
    .maxSpd = 27,
    .maxDef = 21,
    .maxRes = 29,
    .maxCon = 25,

    .classRelativePower = 3,

    .growthHP = 100,
    .growthPow = 15,
    .growthSkl = 25,
    .growthSpd = 30,
    .growthDef = 15,
    .growthRes = 40,
    .growthLck = 100,

    .attributes = CA_PEGASUS,

    .baseRanks = {
        [ITYPE_SWORD] = WPN_EXP_0,
        [ITYPE_LANCE] = WPN_EXP_E,
        [ITYPE_AXE]   = WPN_EXP_0,
        [ITYPE_BOW]   = WPN_EXP_0,
        [ITYPE_STAFF] = WPN_EXP_0,
        [ITYPE_ANIMA] = WPN_EXP_0,
        [ITYPE_LIGHT] = WPN_EXP_0,
        [ITYPE_DARK]  = WPN_EXP_0,
    },

    .pBattleAnimDef = (void *)0x88AF4DC,
    .pMovCostTable = {
        (void *)0x880BB96,
        (void *)0x880BFE7,
        (void *)0x880C3F7,
    },

    .pTerrainAvoidLookup = (void *)0x880C53C,
    .pTerrainDefenseLookup = (void *)0x880C57D,
    .pTerrainResistanceLookup = (void *)0x880C5BE,
    ._pU50 = NULL
};
