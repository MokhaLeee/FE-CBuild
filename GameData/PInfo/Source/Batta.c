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
#include "constants/chax-classes.h"

extern const struct SupportData SupportData_Batta;

const struct CharacterData PInfo_Batta = {
    .nameTextId = MSG_PINFO_BattaName,
    .descTextId = MSG_PINFO_BattaDesc,
    .number = CHAR_CHAX_PrologueBoss,
    .defaultClass = CLASS_BRIGAND,
    .portraitId = Mug_Batta,
    .affinity = UNIT_AFFIN_FIRE,
    .sort_order = 1,

    .baseLevel = 4,
    .baseHP = 12,
    .basePow = 6,
    .baseSkl = 5,
    .baseSpd = 4,
    .baseDef = 3,
    .baseRes = 3,
    .baseLck = 10,
    .baseCon = 0,
    .baseRanks = {
        [ITYPE_SWORD] = WPN_EXP_0,
        [ITYPE_LANCE] = WPN_EXP_0,
        [ITYPE_AXE]   = WPN_EXP_A,
        [ITYPE_BOW]   = WPN_EXP_0,
        [ITYPE_STAFF] = WPN_EXP_0,
        [ITYPE_ANIMA] = WPN_EXP_0,
        [ITYPE_LIGHT] = WPN_EXP_0,
        [ITYPE_DARK]  = WPN_EXP_0,
    },

    .growthHP = 200,
    .growthPow = 90,
    .growthSkl = 80,
    .growthSpd = 50,
    .growthDef = 40,
    .growthRes = 40,
    .growthLck = 50,

    .attributes = CA_BOSS,
    .pSupportData = SupportData_EnemyBosses1,
    .visit_group = 7,
};
