#include "global.h"
#include "bmunit.h"
#include "bmitem.h"
#include "ekrbattle.h"
#include "constants/classes.h"

#include "common-chax.h"
#include "constants/texts.h"
#include "constants/chax-classes.h"

const struct ClassData JInfo_Mercenary = {
    .nameTextId = 0x2C6,
    .descTextId = 0x312,
    .number = CLASS_MERCENARY,
    .promotion = CLASS_HERO,
    .SMSId = 0x0A,
    .slowWalking = 0,
    .defaultPortraitId = 0x90,
    .sort_order = 0x3,

    .baseHP  = 18,
    .basePow = 4,
    .baseSkl = 6,
    .baseSpd = 4,
    .baseDef = 6,
    .baseRes = 6,
    .baseCon = 10,
    .baseMov = 5,

    .maxHP  = 40,
    .maxPow = 23,
    .maxSkl = 26,
    .maxSpd = 24,
    .maxDef = 26,
    .maxRes = 26,
    .maxCon = 20,

    .classRelativePower = 3,

    .growthHP = 100,
    .growthPow = 20,
    .growthSkl = 25,
    .growthSpd = 20,
    .growthDef = 25,
    .growthRes = 25,
    .growthLck = 100,

    .attributes = CA_LOCK_6,

    .baseRanks = {
        [ITYPE_SWORD] = WPN_EXP_E,
        [ITYPE_LANCE] = WPN_EXP_0,
        [ITYPE_AXE]   = WPN_EXP_0,
        [ITYPE_BOW]   = WPN_EXP_0,
        [ITYPE_STAFF] = WPN_EXP_0,
        [ITYPE_ANIMA] = WPN_EXP_0,
        [ITYPE_LIGHT] = WPN_EXP_0,
        [ITYPE_DARK]  = WPN_EXP_0,
    },

    .pBattleAnimDef = (void *)0x88AF0B8,
    .pMovCostTable = {
        (void *)0x880B849,
        (void *)0x880BC9A,
        (void *)0x880C0AA,
    },

    .pTerrainAvoidLookup = (void *)0x880C479,
    .pTerrainDefenseLookup = (void *)0x880C4BA,
    .pTerrainResistanceLookup = (void *)0x880C4FB,
    ._pU50 = (void *)NULL
};
