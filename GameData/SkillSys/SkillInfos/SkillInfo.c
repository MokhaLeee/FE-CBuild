#include "global.h"
#include "skill-system.h"

const struct SkillInfo gSkillInfos[0x100] = {
    [SID_HpBonus] = {
        .msg  = MSG_SKILL_HpBonus,
        .icon = ICON_SkillIcon_WIP,
    },
    [SID_StrBonus] = {
        .msg  = MSG_SKILL_StrBonus,
        .icon = ICON_SkillIcon_StrBonus,
    },
    [SID_MagBonus] = {
        .msg  = MSG_SKILL_MagBonus,
        .icon = ICON_SkillIcon_MagBonus,
    },
    [SID_SklBonus] = {
        .msg  = MSG_SKILL_SklBonus,
        .icon = ICON_SkillIcon_SklBonus,
    },
    [SID_SpdBonus] = {
        .msg  = MSG_SKILL_SpdBonus,
        .icon = ICON_SkillIcon_SpdBonus,
    },
    [SID_LckBonus] = {
        .msg  = MSG_SKILL_LukBonus,
        .icon = ICON_SkillIcon_LukBonus,
    },
    [SID_DefBonus] = {
        .msg  = MSG_SKILL_DefBonus,
        .icon = ICON_SkillIcon_DefBonus,
    },
    [SID_ResBonus] = {
        .msg  = MSG_SKILL_ResBonus,
        .icon = ICON_SkillIcon_ResBonus,
    },
    [SID_MovBonus] = {
        .msg  = MSG_SKILL_MovBonus,
        .icon = ICON_SkillIcon_MovBonus,
    },
    [SID_DefiantStr] = {
        .msg  = MSG_SKILL_DefiantStr,
        .icon = ICON_SkillIcon_DefiantStr,
    },
    [SID_DefiantMag] = {
        .msg  = MSG_SKILL_DefiantMag,
        .icon = ICON_SkillIcon_DefiantMag,
    },
    [SID_DefiantSkl] = {
        .msg  = MSG_SKILL_DefiantSkl,
        .icon = ICON_SkillIcon_DefiantSkl,
    },
    [SID_DefiantSpd] = {
        .msg  = MSG_SKILL_DefiantSpd,
        .icon = ICON_SkillIcon_DefiantStr,
    },
    [SID_DefiantLck] = {
        .msg  = MSG_SKILL_DefiantLck,
        .icon = ICON_SkillIcon_DefiantLck,
    },
    [SID_DefiantDef] = {
        .msg  = MSG_SKILL_DefiantDef,
        .icon = ICON_SkillIcon_DefiantDef,
    },
    [SID_DefiantRes] = {
        .msg  = MSG_SKILL_DefiantRes,
        .icon = ICON_SkillIcon_DefiantRes,
    },
    [SID_DefiantCrit] = {
        .msg  = MSG_SKILL_DefiantCrit,
        .icon = ICON_SkillIcon_WIP,
    },
    [SID_DefiantAvoid] = {
        .msg  = MSG_SKILL_DefiantAvoid,
        .icon = ICON_SkillIcon_WIP,
    },
    [SID_Fury] = {
        .msg  = MSG_SKILL_Fury,
        .icon = ICON_SkillIcon_Fury,
    },
    [SID_FuryPlus] = {
        .msg  = MSG_SKILL_FuryPlus,
        .icon = ICON_SkillIcon_FuryPlus,
    },
    [SID_FortressDef] = {
        .msg  = MSG_SKILL_FortressDef,
        .icon = ICON_SkillIcon_FortressDef,
    },
    [SID_FortressRes] = {
        .msg  = MSG_SKILL_FortressRes,
        .icon = ICON_SkillIcon_FortressRes,
    },
    [SID_LifeAndDeath] = {
        .msg  = MSG_SKILL_LifeAndDeath,
        .icon = ICON_SkillIcon_LifeAndDeath,
    },
};

FEB_IDENTIFIER(gSkillInfos);
