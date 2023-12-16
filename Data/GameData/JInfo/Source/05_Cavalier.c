#include "global.h"
#include "bmunit.h"
#include "bmitem.h"
#include "ekrbattle.h"
#include "constants/classes.h"

#include "common-chax.h"
#include "constants/texts.h"
#include "constants/chax-classes.h"

const struct ClassData JInfo_Cavalier = {
    .nameTextId = 0x2C1,
    .descTextId = 0x30D,
    .number = 0x05,
    .promotion = 0x07,
    .SMSId = 0x04,
    .slowWalking = 0,
    .defaultPortraitId = 0x80,
    .sort_order = 0x20,

    .baseHP = 18,
    .basePow = 9,
    .baseSkl = 3,
    .baseSpd = 8,
    .baseDef = 4,
    .baseRes = 1,
    .baseCon = 10,
    .baseMov = 7,

    .maxHP = 60,
    .maxPow = 29,
    .maxSkl = 23,
    .maxSpd = 28,
    .maxDef = 24,
    .maxRes = 21,
    .maxCon = 25,

    .classRelativePower = 3,

    .growthHP = 100,
    .growthPow = 40,
    .growthSkl = 20,
    .growthSpd = 35,
    .growthDef = 20,
    .growthRes = 15,
    .growthLck = 100,

    .attributes = CA_MOUNTEDAID | CA_CANTO | CA_MOUNTED,

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

    .pBattleAnimDef = (void *)0x88AF008,
    .pMovCostTable = {
        (void *)0x880BA92,
        (void *)0x880BEE3,
        (void *)0x880C2F3,
    },

    .pTerrainAvoidLookup = (void *)0x880C479,
    .pTerrainDefenseLookup = (void *)0x880C4BA,
    .pTerrainResistanceLookup = (void *)0x880C4FB,
    ._pU50 = (void *)0x880C5FF
};
