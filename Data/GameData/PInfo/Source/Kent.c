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

const struct CharacterData PInfos_form_Kent[] = 
{
    [0] = {
        /* CHAR_CHAX_Kent */
        .nameTextId = MSG_PINFO_KentName,
        .descTextId = MSG_PINFO_KentDesc,
        .number = CHAR_CHAX_Kent,
        .defaultClass = CLASS_CAVALIER,
        .portraitId = Mug_Kent,
        .affinity = UNIT_AFFIN_FIRE,
        .sort_order = 2,

        .baseLevel = 2,
        .baseHP = 8,
        .basePow = 3,
        .baseSkl = 3,
        .baseSpd = 2,
        .baseDef = 4,
        .baseRes = 2,
        .baseLck = 4,
        .baseCon = 0,
        .baseRanks = {
            [ITYPE_SWORD] = WPN_EXP_0,
            [ITYPE_LANCE] = WPN_EXP_D,
            [ITYPE_AXE]   = WPN_EXP_0,
            [ITYPE_BOW]   = WPN_EXP_0,
            [ITYPE_STAFF] = WPN_EXP_0,
            [ITYPE_ANIMA] = WPN_EXP_0,
            [ITYPE_LIGHT] = WPN_EXP_0,
            [ITYPE_DARK]  = WPN_EXP_0,
        },

        .growthHP = 95,
        .growthPow = 45,
        .growthSkl = 55,
        .growthSpd = 40,
        .growthDef = 60,
        .growthRes = 35,
        .growthLck = 40,

        .attributes = 0,
        .pSupportData = SupportData_all_zero,
        .visit_group = 7,
    },
    [1] = {
        /* CHAR_CHAX_Sain */
        .nameTextId = MSG_PINFO_SainName,
        .descTextId = MSG_PINFO_SainDesc,
        .number = CHAR_CHAX_Sain,
        .defaultClass = CLASS_CAVALIER,
        .portraitId = Mug_Sain,
        .affinity = UNIT_AFFIN_WIND,
        .sort_order = 2,

        .baseLevel = 2,
        .baseHP = 7,
        .basePow = 4,
        .baseSkl = 3,
        .baseSpd = 3,
        .baseDef = 2,
        .baseRes = 2,
        .baseLck = 6,
        .baseCon = 0,
        .baseRanks = {
            [ITYPE_SWORD] = WPN_EXP_0,
            [ITYPE_LANCE] = WPN_EXP_D,
            [ITYPE_AXE]   = WPN_EXP_0,
            [ITYPE_BOW]   = WPN_EXP_0,
            [ITYPE_STAFF] = WPN_EXP_0,
            [ITYPE_ANIMA] = WPN_EXP_0,
            [ITYPE_LIGHT] = WPN_EXP_0,
            [ITYPE_DARK]  = WPN_EXP_0,
        },

        .growthHP = 90,
        .growthPow = 70,
        .growthSkl = 45,
        .growthSpd = 55,
        .growthDef = 30,
        .growthRes = 30,
        .growthLck = 50,

        .attributes = 0,
        .pSupportData = SupportData_all_zero,
        .visit_group = 7,
    },
    [2] = {
        /* CHAR_CHAX_Wil */
        .nameTextId = MSG_PINFO_WilName,
        .descTextId = MSG_PINFO_WilDesc,
        .number = CHAR_CHAX_Wil,
        .defaultClass = CLASS_ARCHER,
        .portraitId = Mug_Wil,
        .affinity = UNIT_AFFIN_WIND,
        .sort_order = 10,

        .baseLevel = 1,
        .baseHP = 8,
        .basePow = 4,
        .baseSkl = 4,
        .baseSpd = 4,
        .baseDef = 2,
        .baseRes = 2,
        .baseLck = 7,
        .baseCon = 0,
        .baseRanks = {
            [ITYPE_SWORD] = WPN_EXP_0,
            [ITYPE_LANCE] = WPN_EXP_0,
            [ITYPE_AXE]   = WPN_EXP_0,
            [ITYPE_BOW]   = WPN_EXP_D,
            [ITYPE_STAFF] = WPN_EXP_0,
            [ITYPE_ANIMA] = WPN_EXP_0,
            [ITYPE_LIGHT] = WPN_EXP_0,
            [ITYPE_DARK]  = WPN_EXP_0,
        },

        .growthHP = 85,
        .growthPow = 60,
        .growthSkl = 60,
        .growthSpd = 50,
        .growthDef = 50,
        .growthRes = 30,
        .growthLck = 60,

        .attributes = 0,
        .pSupportData = SupportData_all_zero,
        .visit_group = 7,
    },
    [3] = {
        /* CHAR_CHAX_Florina */
        .nameTextId = MSG_PINFO_FlorinaName,
        .descTextId = MSG_PINFO_FlorinaDesc,
        .number = CHAR_CHAX_Florina,
        .defaultClass = CLASS_PEGASUS_KNIGHT,
        .portraitId = Mug_Florina,
        .affinity = UNIT_AFFIN_WIND,
        .sort_order = 0x1E,

        .baseLevel = 8,
        .baseHP = 6,
        .basePow = 3,
        .baseSkl = 4,
        .baseSpd = 4,
        .baseDef = 2,
        .baseRes = 3,
        .baseLck = 8,
        .baseCon = 0,
        .baseRanks = {
            [ITYPE_SWORD] = WPN_EXP_0,
            [ITYPE_LANCE] = WPN_EXP_D,
            [ITYPE_AXE]   = WPN_EXP_0,
            [ITYPE_BOW]   = WPN_EXP_0,
            [ITYPE_STAFF] = WPN_EXP_0,
            [ITYPE_ANIMA] = WPN_EXP_0,
            [ITYPE_LIGHT] = WPN_EXP_0,
            [ITYPE_DARK]  = WPN_EXP_0,
        },

        .growthHP = 70,
        .growthPow = 50,
        .growthSkl = 60,
        .growthSpd = 65,
        .growthDef = 25,
        .growthRes = 45,
        .growthLck = 70,

        .attributes = CA_FEMALE,
        .pSupportData = SupportData_all_zero,
        .visit_group = 7,
    },
};
