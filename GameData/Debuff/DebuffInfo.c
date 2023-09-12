#include "global.h"
#include "common-chax.h"
#include "debuff.h"
#include "constants/gfx.h"

const struct DebuffInfo gDebuffInfos[NEW_UNIT_STATUS_MAX] = {
    [MEW_UNIT_STATUS_NONE] = {
        .name = 0x536,
        .desc = 0x552,
    },

    [MEW_UNIT_STATUS_POISON] = {
        .name = 0x514,
        .desc = 0x553,
        .type = STATUS_INFO_TYPE_DEBUFF,
        .duration = 3,
        .img = GFX_DebuffMinibox_Posion,
    },

    [MEW_UNIT_STATUS_SLEEP] = {
        .name = 0x515,
        .desc = 0x554,
        .type = STATUS_INFO_TYPE_DEBUFF,
        .duration = 3,
        .img = GFX_DebuffMinibox_Sleep,
    },

    [MEW_UNIT_STATUS_SILENCED] = {
        .name = 0x516,
        .desc = 0x556,
        .type = STATUS_INFO_TYPE_DEBUFF,
        .duration = 3,
        .img = GFX_DebuffMinibox_Silence,
    },

    [MEW_UNIT_STATUS_BERSERK] = {
        .name = 0x517,
        .desc = 0x555,
        .type = STATUS_INFO_TYPE_DEBUFF,
        .duration = 3,
        .img = GFX_DebuffMinibox_Berserk,
    },

    [MEW_UNIT_STATUS_ATTACK] = {
        .name = 0x51B,
        .desc = 0x558,
        .type = STATUS_INFO_TYPE_BUFF,
        .duration = 3,
        .atk = 10,
        .img = GFX_DebuffMinibox_Attack,
        .on_draw = PutUnitDanceRingBuffIcon,
    },

    [MEW_UNIT_STATUS_DEFENSE] = {
        .name = 0x51C,
        .desc = 0x559,
        .type = STATUS_INFO_TYPE_BUFF,
        .duration = 3,
        .img = GFX_DebuffMinibox_Defense,
        .on_draw = PutUnitDanceRingBuffIcon,
    },

    [MEW_UNIT_STATUS_CRIT] = {
        .name = 0x51D,
        .desc = 0x55A,
        .type = STATUS_INFO_TYPE_BUFF,
        .duration = 3,
        .img = GFX_DebuffMinibox_Crit,
        .on_draw = PutUnitDanceRingBuffIcon,
    },

    [MEW_UNIT_STATUS_AVOID] = {
        .name = 0x51E,
        .desc = 0x55B,
        .type = STATUS_INFO_TYPE_BUFF,
        .duration = 3,
        .img = GFX_DebuffMinibox_Aviod,
        .on_draw = PutUnitDanceRingBuffIcon,
    },

    [MEW_UNIT_STATUS_SICK] = {
        .name = 0x518,
        .type = STATUS_INFO_TYPE_DEBUFF,
        .duration = 3,
    },

    [MEW_UNIT_STATUS_RECOVER] = {
        .name = 0x519,
        .duration = 3,
    },

    [MEW_UNIT_STATUS_PETRIFY] = {
        .name = 0x51A,
        .type = STATUS_INFO_TYPE_DEBUFF,
        .duration = 3,
        .img = GFX_DebuffMinibox_Petrify,
    },

    [MEW_UNIT_STATUS_12] = {
        .name = 0,
        .desc = 0,
        .type = STATUS_INFO_TYPE_DEBUFF,
        .duration = 3,
    },

    [NEW_UNIT_STATUS_13] = {
        .name = 0,
        .desc = 0,
        .type = STATUS_INFO_TYPE_DEBUFF,
        .duration = 3,
    },
};
