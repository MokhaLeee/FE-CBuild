#include "global.h"
#include "bmunit.h"
#include "bmitem.h"
#include "bmreliance.h"
#include "constants/classes.h"

#include "common-chax.h"
#include "_common.h"
#include "constants/texts.h"
#include "constants/portraits.h"

const struct CharacterData PInfo_Cutthroat_8E = {
    .nameTextId = 0x254,
    .descTextId = 0x2AE,
    .number = 0x8E,
    .defaultClass = CLASS_BRIGAND,
    .portraitId = 0,
    .miniPortrait = 0x6,
    .affinity = 0,
    .sort_order = 0,

    .baseLevel = 1,
    .baseHP = 4,
    .basePow = 1,
    .baseSkl = 1,
    .baseSpd = 1,
    .baseDef = 1,
    .baseRes = 1,
    .baseLck = 0,
    .baseCon = 0,
    .baseRanks = {
        [ITYPE_SWORD] = WPN_EXP_0,
        [ITYPE_LANCE] = WPN_EXP_0,
        [ITYPE_AXE]   = WPN_EXP_0,
        [ITYPE_BOW]   = WPN_EXP_0,
        [ITYPE_STAFF] = WPN_EXP_0,
        [ITYPE_ANIMA] = WPN_EXP_0,
        [ITYPE_LIGHT] = WPN_EXP_0,
        [ITYPE_DARK]  = WPN_EXP_0,
    },

    .growthHP = 60,
    .growthPow = 20,
    .growthSkl = 30,
    .growthSpd = 35,
    .growthDef = 15,
    .growthRes = 15,
    .growthLck = 25,

    .attributes = 0,
    .pSupportData = SupportData_EnemyBosses1,
    .visit_group = 0,
};
