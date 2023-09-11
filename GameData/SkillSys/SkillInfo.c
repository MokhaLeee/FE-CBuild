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
        .icon = ICON_SkillIcon_DefiantSpd,
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
    [SID_SwordBreaker] = {
        .msg  = MSG_SKILL_SwordBreaker,
        .icon = ICON_SkillIcon_SwordBreaker,
    },
    [SID_AxeBreaker] = {
        .msg  = MSG_SKILL_AxeBreaker,
        .icon = ICON_SkillIcon_AxeBreaker,
    },
    [SID_LanceBreaker] = {
        .msg  = MSG_SKILL_LanceBreaker,
        .icon = ICON_SkillIcon_LanceBreaker,
    },
    [SID_BowBreaker] = {
        .msg  = MSG_SKILL_BowBreaker,
        .icon = ICON_SkillIcon_BowBreaker,
    },
    [SID_BMagBreaker] = {
        .msg  = MSG_SKILL_BMagBreaker,
        .icon = ICON_SkillIcon_WIP,
    },
    [SID_Vantage] = {
        .msg  = MSG_SKILL_Vantage,
        .icon = ICON_SkillIcon_Vantage,
    },
    [SID_Desperation] = {
        .msg  = MSG_SKILL_Desperation,
        .icon = ICON_SkillIcon_Desperation,
    },
    [SID_QuickRiposte] = {
        .msg  = MSG_SKILL_QuickRiposte,
        .icon = ICON_SkillIcon_QuickRiposte,
    },
    [SID_WaryFighter] = {
        .msg  = MSG_SKILL_WaryFighter,
        .icon = ICON_SkillIcon_WaryFighter,
    },
    [SID_DoubleLion] = {
        .msg  = MSG_SKILL_DoubleLion,
        .icon = ICON_SkillIcon_DoubleLion,
    },
    [SID_BlowDarting] = {
        .msg  = MSG_SKILL_BlowDarting,
        .icon = ICON_SkillIcon_BlowDarting,
    },
    [SID_BlowDeath] = {
        .msg  = MSG_SKILL_BlowDeath,
        .icon = ICON_SkillIcon_BlowDeath,
    },
    [SID_BlowArmored] = {
        .msg  = MSG_SKILL_BlowArmored,
        .icon = ICON_SkillIcon_BlowArmored,
    },
    [SID_BlowFiendish] = {
        .msg  = MSG_SKILL_BlowFiendish,
        .icon = ICON_SkillIcon_BlowFiendish,
    },
    [SID_BlowWarding] = {
        .msg  = MSG_SKILL_BlowWarding,
        .icon = ICON_SkillIcon_BlowWarding,
    },
    [SID_BlowDuelist] = {
        .msg  = MSG_SKILL_BlowDuelist,
        .icon = ICON_SkillIcon_BlowDuelist,
    },
    [SID_BlowUncanny] = {
        .msg  = MSG_SKILL_BlowUncanny,
        .icon = ICON_SkillIcon_BlowUncanny,
    },
    [SID_StanceBracing] = {
        .msg  = MSG_SKILL_StanceBracing,
        .icon = ICON_SkillIcon_StanceBracing,
    },
    [SID_StanceDarting] = {
        .msg  = MSG_SKILL_StanceDarting,
        .icon = ICON_SkillIcon_StanceDarting,
    },
    [SID_StanceFierce] = {
        .msg  = MSG_SKILL_StanceFierce,
        .icon = ICON_SkillIcon_StanceFierce,
    },
    [SID_StanceKestrel] = {
        .msg  = MSG_SKILL_StanceKestrel,
        .icon = ICON_SkillIcon_StanceKestrel,
    },
    [SID_StanceMirror] = {
        .msg  = MSG_SKILL_StanceMirror,
        .icon = ICON_SkillIcon_StanceMirror,
    },
    [SID_StanceReady] = {
        .msg  = MSG_SKILL_StanceReady,
        .icon = ICON_SkillIcon_StanceReady,
    },
    [SID_StanceSteady] = {
        .msg  = MSG_SKILL_StanceSteady,
        .icon = ICON_SkillIcon_StanceSteady,
    },
    [SID_StanceSturdy] = {
        .msg  = MSG_SKILL_StanceSturdy,
        .icon = ICON_SkillIcon_StanceSturdy,
    },
    [SID_StanceSwift] = {
        .msg  = MSG_SKILL_StanceSwift,
        .icon = ICON_SkillIcon_StanceSwift,
    },
    [SID_StanceWarding] = {
        .msg  = MSG_SKILL_StanceWarding,
        .icon = ICON_SkillIcon_StanceWarding,
    },
    [SID_RangeBonusBMag1] = {
        .msg  = MSG_SKILL_RangeBonusBMag1,
        .icon = ICON_SkillIcon_RangeBonusBMag1,
    },
    [SID_RangeBonusBMag2] = {
        .msg  = MSG_SKILL_RangeBonusBMag2,
        .icon = ICON_SkillIcon_RangeBonusBMag2,
    },
    [SID_RangeBonusBow1] = {
        .msg  = MSG_SKILL_RangeBonusBow1,
        .icon = ICON_SkillIcon_RangeBonusBow1,
    },
    [SID_RangeBonusBow2] = {
        .msg  = MSG_SKILL_RangeBonusBow2,
        .icon = ICON_SkillIcon_RangeBonusBow2,
    },
};

FEB_IDENTIFIER(gSkillInfos);
