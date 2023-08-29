#include "global.h"

#include "common-chax.h"
#include "skill-system.h"
#include "constants/skills.h"
#include "constants/texts.h"
#include "constants/icons.h"

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
    [SID_Lethality] = {
        .msg  = MSG_SKILL_Lethality,
        .icon = ICON_SkillIcon_Lethality,
    },
    [SID_Crit] = {
        .msg  = MSG_SKILL_Crit,
        .icon = ICON_SkillIcon_Crit,
    },
    [SID_WatchfulEye] = {
        .msg  = MSG_SKILL_WatchfulEye,
        .icon = ICON_SkillIcon_WatchfulEye,
    },
    [SID_CritSword] = {
        .msg  = MSG_SKILL_CritSword,
        .icon = ICON_SkillIcon_CritSword,
    },
    [SID_CritAxe] = {
        .msg  = MSG_SKILL_CritAxe,
        .icon = ICON_SkillIcon_CritAxe,
    },
    [SID_CritLance] = {
        .msg  = MSG_SKILL_CritLance,
        .icon = ICON_SkillIcon_CritLance,
    },
    [SID_CritBow] = {
        .msg  = MSG_SKILL_CritBow,
        .icon = ICON_SkillIcon_CritBow,
    },
    [SID_FaireSword] = {
        .msg  = MSG_SKILL_FaireSword,
        .icon = ICON_SkillIcon_FaireSword,
    },
    [SID_FaireLance] = {
        .msg  = MSG_SKILL_FaireLance,
        .icon = ICON_SkillIcon_FaireLance,
    },
    [SID_FaireAxe] = {
        .msg  = MSG_SKILL_FaireAxe,
        .icon = ICON_SkillIcon_FaireAxe,
    },
    [SID_FaireBow] = {
        .msg  = MSG_SKILL_FaireBow,
        .icon = ICON_SkillIcon_FaireBow,
    },
    [SID_FaireBMag] = {
        .msg  = MSG_SKILL_FaireBMag,
        .icon = ICON_SkillIcon_FaireBMag,
    },
    [SID_Avoid] = {
        .msg  = MSG_SKILL_Avoid,
        .icon = ICON_SkillIcon_Avoid,
    },
    [SID_AvoidSword] = {
        .msg  = MSG_SKILL_AvoidSword,
        .icon = ICON_SkillIcon_AvoidSword,
    },
    [SID_RuinedBlade] = {
        .msg  = MSG_SKILL_RuinedBlade,
        .icon = ICON_SkillIcon_RuinedBlade,
    },
    [SID_RuinedBladePlus] = {
        .msg  = MSG_SKILL_RuinedBladePlus,
        .icon = ICON_SkillIcon_WIP,
    },
    [SID_InfinityEdge] = {
        .msg  = MSG_SKILL_InfinityEdge,
        .icon = ICON_SkillIcon_InfinityEdge,
    },
    [SID_HeavyBlade] = {
        .msg  = MSG_SKILL_HeavyBlade,
        .icon = ICON_SkillIcon_HeavyBlade,
    },
    [SID_FlashingBlade] = {
        .msg  = MSG_SKILL_FlashingBlade,
        .icon = ICON_SkillIcon_FlashingBlade,
    },
    [SID_HeavyBladePlus] = {
        .msg  = MSG_SKILL_HeavyBladePlus,
        .icon = ICON_SkillIcon_HeavyBladePlus,
    },
    [SID_FlashingBladePlus] = {
        .msg  = MSG_SKILL_FlashingBladePlus,
        .icon = ICON_SkillIcon_FlashingBladePlus,
    },
    [SID_LunaAttack] = {
        .msg  = MSG_SKILL_LunaAttack,
        .icon = ICON_SkillIcon_LunaAttack,
    },
    [SID_SorceryBlade] = {
        .msg  = MSG_SKILL_SorceryBlade,
        .icon = ICON_SkillIcon_SorceryBlade,
    },
};

FEB_IDENTIFIER(gSkillInfos);
