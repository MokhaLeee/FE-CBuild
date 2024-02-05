#include "global.h"
#include "bmunit.h"
#include "bmitem.h"
#include "bmreliance.h"
#include "constants/classes.h"

#include "common-chax.h"
#include "_common.h"
#include "constants/texts.h"
#include "constants/portraits.h"
#include "constants/chax-characters.h"

extern const struct SupportData SupportData_Batta;

const struct CharacterData PInfo_Glass = {
    .nameTextId = MSG_PINFO_GlassName,
    .descTextId = MSG_PINFO_GlassDesc,
    .number = CHAR_CHAX_Ch2Boss,
    .defaultClass = CLASS_MERCENARY,
    .portraitId = Mug_Glass,
    .affinity = UNIT_AFFIN_FIRE,
    .sort_order = 1,

    .baseLevel = 1,
    .baseHP = 0,
    .basePow = 0,
    .baseSkl = 0,
    .baseSpd = 0,
    .baseDef = 0,
    .baseRes = 0,
    .baseLck = 0,
    .baseCon = 0,
    .baseRanks = {
        [ITYPE_SWORD] = WPN_EXP_A,
        [ITYPE_LANCE] = WPN_EXP_0,
        [ITYPE_AXE]   = WPN_EXP_0,
        [ITYPE_BOW]   = WPN_EXP_0,
        [ITYPE_STAFF] = WPN_EXP_0,
        [ITYPE_ANIMA] = WPN_EXP_0,
        [ITYPE_LIGHT] = WPN_EXP_0,
        [ITYPE_DARK]  = WPN_EXP_0,
    },

    .growthHP = 100,
    .growthPow = 20,
    .growthSkl = 25,
    .growthSpd = 20,
    .growthDef = 25,
    .growthRes = 25,
    .growthLck = 100,

    .attributes = CA_BOSS,
    .pSupportData = SupportData_EnemyBosses1,
    .visit_group = 7,
};
