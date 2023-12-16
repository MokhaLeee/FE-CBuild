#include "global.h"
#include "bmunit.h"
#include "bmitem.h"
#include "ekrbattle.h"

#include "common-chax.h"
#include "constants/texts.h"
#include "constants/chax-classes.h"

extern const struct BattleAnimDef Mark_Anims[];

const struct ClassData JInfo_MarkT0 = {
    .nameTextId = MSG_PINFO_MarkT1Name,
    .descTextId = MSG_PINFO_MarkT1Desc,
    .number = CLASS_CHAX_Mark_T1,
    .promotion = CLASS_CHAX_Mark_T2,
    .SMSId = 0x64,
    .slowWalking = 0,
    .sort_order = 0x29,

    .baseHP = 16,
    .basePow = 2,
    .baseSkl = 9,
    .baseSpd = 5,
    .baseDef = 2,
    .baseRes = 4,
    .baseCon = 6,
    .baseMov = 6,

    .maxHP = 60,
    .maxPow = 25,
    .maxSkl = 30,
    .maxSpd = 30,
    .maxDef = 22,
    .maxRes = 22,
    .maxCon = 20,

    .classRelativePower = 3,

    .growthHP = 100,
    .growthPow = 30,
    .growthSkl = 45,
    .growthSpd = 50,
    .growthDef = 25,
    .growthRes = 25,
    .growthLck = 100,

    .attributes = 0,

    .baseRanks = {
        [ITYPE_SWORD] = WPN_EXP_D
    },

    .pBattleAnimDef = Mark_Anims,
    .pMovCostTable = {
        (void *)0x880B808,
        (void *)0x880BC59,
        (void *)0x880C069,
    },

    .pTerrainAvoidLookup = (void *)0x880C479,
    .pTerrainDefenseLookup = (void *)0x880C4BA,
    .pTerrainResistanceLookup = (void *)0x880C4FB,
};
