#include "global.h"
#include "bmunit.h"
#include "bmitem.h"
#include "bmreliance.h"

#include "common-chax.h"
#include "constants/texts.h"
#include "constants/portraits.h"
#include "constants/chax-characters.h"
#include "constants/chax-classes.h"

const struct CharacterData PInfo_Lyn = {
    .nameTextId = MSG_PINFO_LynName,
    .descTextId = MSG_PINFO_LynDesc,
    .number = CHAR_CHAX_Lyn,
    .defaultClass = CLASS_CHAX_LYN_T1,
    .portraitId = Mug_Lyn,
    .affinity = UNIT_AFFIN_LIGHT,
    .sort_order = 1,

    .baseLevel = 1,
    .baseHP = 7,
    .basePow = 4,
    .baseSkl = 5,
    .baseSpd = 5,
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

    .growthHP = 90,
    .growthPow = 60,
    .growthSkl = 80,
    .growthSpd = 80,
    .growthDef = 40,
    .growthRes = 50,
    .growthLck = 85,

    .attributes = CA_FEMALE,
    .pSupportData = &gSupportData[0],
    .visit_group = 7,
};
