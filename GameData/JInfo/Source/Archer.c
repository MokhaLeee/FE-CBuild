#include "global.h"
#include "bmunit.h"
#include "bmitem.h"
#include "ekrbattle.h"
#include "constants/classes.h"

#include "common-chax.h"
#include "constants/texts.h"
#include "constants/chax-classes.h"

const struct ClassData JInfo_Archer = {
    .nameTextId = 0x2CB,
    .descTextId = 0x317,
    .number = CLASS_ARCHER,
    .promotion = CLASS_SNIPER,
    .SMSId = 0x14,
    .slowWalking = 0,
    .defaultPortraitId = 0x78,
    .sort_order = 0x0F,

    .baseHP = 16,
    .basePow = 7,
    .baseSkl = 9,
    .baseSpd = 5,
    .baseDef = 1,
    .baseRes = 3,
    .baseCon = 5,
    .baseMov = 5,

    .maxHP = 40,
    .maxPow = 27,
    .maxSkl = 29,
    .maxSpd = 26,
    .maxDef = 21,
    .maxRes = 23,
    .maxCon = 20,

    .classRelativePower = 3,

    .growthHP = 100,
    .growthPow = 30,
    .growthSkl = 40,
    .growthSpd = 20,
    .growthDef = 15,
    .growthRes = 20,
    .growthLck = 100,

    .attributes = CA_BALLISTAE,

    .baseRanks = {
        [ITYPE_SWORD] = WPN_EXP_0,
        [ITYPE_LANCE] = WPN_EXP_0,
        [ITYPE_AXE]   = WPN_EXP_0,
        [ITYPE_BOW]   = WPN_EXP_E,
        [ITYPE_STAFF] = WPN_EXP_0,
        [ITYPE_ANIMA] = WPN_EXP_0,
        [ITYPE_LIGHT] = WPN_EXP_0,
        [ITYPE_DARK]  = WPN_EXP_0,
    },

    .pBattleAnimDef = (void *)0x88AF150,
    .pMovCostTable = {
        (void *)0x880B849,
        (void *)0x880BC9A,
        (void *)0x880C0AA,
    },

    .pTerrainAvoidLookup = (void *)0x880C479,
    .pTerrainDefenseLookup = (void *)0x880C4BA,
    .pTerrainResistanceLookup = (void *)0x880C4FB,
    ._pU50 = NULL
};
