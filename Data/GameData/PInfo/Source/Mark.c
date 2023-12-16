#include "global.h"
#include "bmunit.h"
#include "bmitem.h"
#include "bmreliance.h"

#include "common-chax.h"
#include "constants/texts.h"
#include "constants/portraits.h"
#include "constants/chax-characters.h"
#include "constants/chax-classes.h"

const struct CharacterData PInfo_Mark = {
    .nameTextId = MSG_TacticianName,
    .descTextId = MSG_PINFO_MarkDesc,
    .number = CHAR_CHAX_Mark,
    .defaultClass = CLASS_CHAX_Mark_T1,
    .portraitId = Mug_Mark,
    .affinity = UNIT_AFFIN_DARK,
    .sort_order = 1,

    .baseLevel = 1,
    .baseHP = 7,
    .basePow = 2,
    .baseSkl = 5,
    .baseSpd = 3,
    .baseDef = 2,
    .baseRes = 3,
    .baseLck = 9,
    .baseCon = 0,
    .baseRanks = {
        [ITYPE_SWORD] = WPN_EXP_D,
        [ITYPE_LANCE] = WPN_EXP_0,
        [ITYPE_AXE]   = WPN_EXP_0,
        [ITYPE_BOW]   = WPN_EXP_0,
        [ITYPE_STAFF] = WPN_EXP_0,
        [ITYPE_ANIMA] = WPN_EXP_0,
        [ITYPE_LIGHT] = WPN_EXP_0,
        [ITYPE_DARK]  = WPN_EXP_0,
    },

    .growthHP = 80,
    .growthPow = 40,
    .growthSkl = 70,
    .growthSpd = 50,
    .growthDef = 40,
    .growthRes = 70,
    .growthLck = 90,

    .attributes = 0,
    .pSupportData = &gSupportData[0],
    .visit_group = 7,
};
