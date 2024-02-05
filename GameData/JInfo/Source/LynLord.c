#include "global.h"
#include "bmunit.h"
#include "bmitem.h"
#include "ekrbattle.h"

#include "common-chax.h"
#include "constants/texts.h"
#include "constants/chax-classes.h"

extern const struct BattleAnimDef LynLord_Anims[];

const struct ClassData JInfo_LynLord = {
    .nameTextId = MSG_JINFO_LynLordName,
    .descTextId = MSG_JINFO_LynLordDesc,
    .number = CLASS_CHAX_LYN_T1,
    .promotion = CLASS_CHAX_LYN_T2,
    .SMSId = 0x1,
    .slowWalking = 0,
    .sort_order = 0x29,

    .baseHP = 16,
    .basePow = 5,
    .baseSkl = 8,
    .baseSpd = 9,
    .baseDef = 2,
    .baseRes = 2,
    .baseCon = 6,
    .baseMov = 6,

    .maxHP = 60,
    .maxPow = 24,
    .maxSkl = 28,
    .maxSpd = 29,
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

    .attributes = CA_FEMALE | CA_LOCK_1 | CA_LOCK_2 | CA_LOCK_4,

    .baseRanks = {
        [ITYPE_SWORD] = WPN_EXP_D
    },

    .pBattleAnimDef = LynLord_Anims,
    .pMovCostTable = {
        (void *)0x880B808,
        (void *)0x880BC59,
        (void *)0x880C069,
    },

    .pTerrainAvoidLookup = (void *)0x880C479,
    .pTerrainDefenseLookup = (void *)0x880C4BA,
    .pTerrainResistanceLookup = (void *)0x880C4FB,
};
