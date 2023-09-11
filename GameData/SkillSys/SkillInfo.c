#include "global.h"

#include "common-chax.h"
#include "skill-system.h"
#include "constants/skills.h"
#include "constants/texts.h"
#include "constants/gfx.h"

const struct SkillInfo gSkillInfos[0x100] = {
    [SID_HpBonus] = {
        .msg  = MSG_SKILL_HpBonus,
        .icon = GFX_SkillIcon_WIP,
    },
    [SID_StrBonus] = {
        .msg  = MSG_SKILL_StrBonus,
        .icon = GFX_SkillIcon_StrBonus,
    },
    [SID_MagBonus] = {
        .msg  = MSG_SKILL_MagBonus,
        .icon = GFX_SkillIcon_MagBonus,
    },
    [SID_SklBonus] = {
        .msg  = MSG_SKILL_SklBonus,
        .icon = GFX_SkillIcon_SklBonus,
    },
    [SID_SpdBonus] = {
        .msg  = MSG_SKILL_SpdBonus,
        .icon = GFX_SkillIcon_SpdBonus,
    },
    [SID_LckBonus] = {
        .msg  = MSG_SKILL_LukBonus,
        .icon = GFX_SkillIcon_LukBonus,
    },
    [SID_DefBonus] = {
        .msg  = MSG_SKILL_DefBonus,
        .icon = GFX_SkillIcon_DefBonus,
    },
    [SID_ResBonus] = {
        .msg  = MSG_SKILL_ResBonus,
        .icon = GFX_SkillIcon_ResBonus,
    },
    [SID_MovBonus] = {
        .msg  = MSG_SKILL_MovBonus,
        .icon = GFX_SkillIcon_MovBonus,
    },
    [SID_DefiantStr] = {
        .msg  = MSG_SKILL_DefiantStr,
        .icon = GFX_SkillIcon_DefiantStr,
    },
    [SID_DefiantMag] = {
        .msg  = MSG_SKILL_DefiantMag,
        .icon = GFX_SkillIcon_DefiantMag,
    },
    [SID_DefiantSkl] = {
        .msg  = MSG_SKILL_DefiantSkl,
        .icon = GFX_SkillIcon_DefiantSkl,
    },
    [SID_DefiantSpd] = {
        .msg  = MSG_SKILL_DefiantSpd,
        .icon = GFX_SkillIcon_DefiantSpd,
    },
    [SID_DefiantLck] = {
        .msg  = MSG_SKILL_DefiantLck,
        .icon = GFX_SkillIcon_DefiantLck,
    },
    [SID_DefiantDef] = {
        .msg  = MSG_SKILL_DefiantDef,
        .icon = GFX_SkillIcon_DefiantDef,
    },
    [SID_DefiantRes] = {
        .msg  = MSG_SKILL_DefiantRes,
        .icon = GFX_SkillIcon_DefiantRes,
    },
    [SID_DefiantCrit] = {
        .msg  = MSG_SKILL_DefiantCrit,
        .icon = GFX_SkillIcon_WIP,
    },
    [SID_DefiantAvoid] = {
        .msg  = MSG_SKILL_DefiantAvoid,
        .icon = GFX_SkillIcon_WIP,
    },
    [SID_Fury] = {
        .msg  = MSG_SKILL_Fury,
        .icon = GFX_SkillIcon_Fury,
    },
    [SID_FuryPlus] = {
        .msg  = MSG_SKILL_FuryPlus,
        .icon = GFX_SkillIcon_FuryPlus,
    },
    [SID_FortressDef] = {
        .msg  = MSG_SKILL_FortressDef,
        .icon = GFX_SkillIcon_FortressDef,
    },
    [SID_FortressRes] = {
        .msg  = MSG_SKILL_FortressRes,
        .icon = GFX_SkillIcon_FortressRes,
    },
    [SID_LifeAndDeath] = {
        .msg  = MSG_SKILL_LifeAndDeath,
        .icon = GFX_SkillIcon_LifeAndDeath,
    },
    [SID_Lethality] = {
        .msg  = MSG_SKILL_Lethality,
        .icon = GFX_SkillIcon_Lethality,
    },
    [SID_Crit] = {
        .msg  = MSG_SKILL_Crit,
        .icon = GFX_SkillIcon_Crit,
    },
    [SID_WatchfulEye] = {
        .msg  = MSG_SKILL_WatchfulEye,
        .icon = GFX_SkillIcon_WatchfulEye,
    },
    [SID_CritSword] = {
        .msg  = MSG_SKILL_CritSword,
        .icon = GFX_SkillIcon_CritSword,
    },
    [SID_CritAxe] = {
        .msg  = MSG_SKILL_CritAxe,
        .icon = GFX_SkillIcon_CritAxe,
    },
    [SID_CritLance] = {
        .msg  = MSG_SKILL_CritLance,
        .icon = GFX_SkillIcon_CritLance,
    },
    [SID_CritBow] = {
        .msg  = MSG_SKILL_CritBow,
        .icon = GFX_SkillIcon_CritBow,
    },
    [SID_FaireSword] = {
        .msg  = MSG_SKILL_FaireSword,
        .icon = GFX_SkillIcon_FaireSword,
    },
    [SID_FaireLance] = {
        .msg  = MSG_SKILL_FaireLance,
        .icon = GFX_SkillIcon_FaireLance,
    },
    [SID_FaireAxe] = {
        .msg  = MSG_SKILL_FaireAxe,
        .icon = GFX_SkillIcon_FaireAxe,
    },
    [SID_FaireBow] = {
        .msg  = MSG_SKILL_FaireBow,
        .icon = GFX_SkillIcon_FaireBow,
    },
    [SID_FaireBMag] = {
        .msg  = MSG_SKILL_FaireBMag,
        .icon = GFX_SkillIcon_FaireBMag,
    },
    [SID_Avoid] = {
        .msg  = MSG_SKILL_Avoid,
        .icon = GFX_SkillIcon_Avoid,
    },
    [SID_AvoidSword] = {
        .msg  = MSG_SKILL_AvoidSword,
        .icon = GFX_SkillIcon_AvoidSword,
    },
    [SID_RuinedBlade] = {
        .msg  = MSG_SKILL_RuinedBlade,
        .icon = GFX_SkillIcon_RuinedBlade,
    },
    [SID_RuinedBladePlus] = {
        .msg  = MSG_SKILL_RuinedBladePlus,
        .icon = GFX_SkillIcon_WIP,
    },
    [SID_InfinityEdge] = {
        .msg  = MSG_SKILL_InfinityEdge,
        .icon = GFX_SkillIcon_InfinityEdge,
    },
    [SID_HeavyBlade] = {
        .msg  = MSG_SKILL_HeavyBlade,
        .icon = GFX_SkillIcon_HeavyBlade,
    },
    [SID_FlashingBlade] = {
        .msg  = MSG_SKILL_FlashingBlade,
        .icon = GFX_SkillIcon_FlashingBlade,
    },
    [SID_HeavyBladePlus] = {
        .msg  = MSG_SKILL_HeavyBladePlus,
        .icon = GFX_SkillIcon_HeavyBladePlus,
    },
    [SID_FlashingBladePlus] = {
        .msg  = MSG_SKILL_FlashingBladePlus,
        .icon = GFX_SkillIcon_FlashingBladePlus,
    },
    [SID_LunaAttack] = {
        .msg  = MSG_SKILL_LunaAttack,
        .icon = GFX_SkillIcon_LunaAttack,
    },
    [SID_SorceryBlade] = {
        .msg  = MSG_SKILL_SorceryBlade,
        .icon = GFX_SkillIcon_SorceryBlade,
    },
    [SID_SwordBreaker] = {
        .msg  = MSG_SKILL_SwordBreaker,
        .icon = GFX_SkillIcon_SwordBreaker,
    },
    [SID_AxeBreaker] = {
        .msg  = MSG_SKILL_AxeBreaker,
        .icon = GFX_SkillIcon_AxeBreaker,
    },
    [SID_LanceBreaker] = {
        .msg  = MSG_SKILL_LanceBreaker,
        .icon = GFX_SkillIcon_LanceBreaker,
    },
    [SID_BowBreaker] = {
        .msg  = MSG_SKILL_BowBreaker,
        .icon = GFX_SkillIcon_BowBreaker,
    },
    [SID_BMagBreaker] = {
        .msg  = MSG_SKILL_BMagBreaker,
        .icon = GFX_SkillIcon_WIP,
    },
    [SID_Vantage] = {
        .msg  = MSG_SKILL_Vantage,
        .icon = GFX_SkillIcon_Vantage,
    },
    [SID_Desperation] = {
        .msg  = MSG_SKILL_Desperation,
        .icon = GFX_SkillIcon_Desperation,
    },
    [SID_QuickRiposte] = {
        .msg  = MSG_SKILL_QuickRiposte,
        .icon = GFX_SkillIcon_QuickRiposte,
    },
    [SID_WaryFighter] = {
        .msg  = MSG_SKILL_WaryFighter,
        .icon = GFX_SkillIcon_WaryFighter,
    },
    [SID_DoubleLion] = {
        .msg  = MSG_SKILL_DoubleLion,
        .icon = GFX_SkillIcon_DoubleLion,
    },
    [SID_BlowDarting] = {
        .msg  = MSG_SKILL_BlowDarting,
        .icon = GFX_SkillIcon_BlowDarting,
    },
    [SID_BlowDeath] = {
        .msg  = MSG_SKILL_BlowDeath,
        .icon = GFX_SkillIcon_BlowDeath,
    },
    [SID_BlowArmored] = {
        .msg  = MSG_SKILL_BlowArmored,
        .icon = GFX_SkillIcon_BlowArmored,
    },
    [SID_BlowFiendish] = {
        .msg  = MSG_SKILL_BlowFiendish,
        .icon = GFX_SkillIcon_BlowFiendish,
    },
    [SID_BlowWarding] = {
        .msg  = MSG_SKILL_BlowWarding,
        .icon = GFX_SkillIcon_BlowWarding,
    },
    [SID_BlowDuelist] = {
        .msg  = MSG_SKILL_BlowDuelist,
        .icon = GFX_SkillIcon_BlowDuelist,
    },
    [SID_BlowUncanny] = {
        .msg  = MSG_SKILL_BlowUncanny,
        .icon = GFX_SkillIcon_BlowUncanny,
    },
    [SID_StanceBracing] = {
        .msg  = MSG_SKILL_StanceBracing,
        .icon = GFX_SkillIcon_StanceBracing,
    },
    [SID_StanceDarting] = {
        .msg  = MSG_SKILL_StanceDarting,
        .icon = GFX_SkillIcon_StanceDarting,
    },
    [SID_StanceFierce] = {
        .msg  = MSG_SKILL_StanceFierce,
        .icon = GFX_SkillIcon_StanceFierce,
    },
    [SID_StanceKestrel] = {
        .msg  = MSG_SKILL_StanceKestrel,
        .icon = GFX_SkillIcon_StanceKestrel,
    },
    [SID_StanceMirror] = {
        .msg  = MSG_SKILL_StanceMirror,
        .icon = GFX_SkillIcon_StanceMirror,
    },
    [SID_StanceReady] = {
        .msg  = MSG_SKILL_StanceReady,
        .icon = GFX_SkillIcon_StanceReady,
    },
    [SID_StanceSteady] = {
        .msg  = MSG_SKILL_StanceSteady,
        .icon = GFX_SkillIcon_StanceSteady,
    },
    [SID_StanceSturdy] = {
        .msg  = MSG_SKILL_StanceSturdy,
        .icon = GFX_SkillIcon_StanceSturdy,
    },
    [SID_StanceSwift] = {
        .msg  = MSG_SKILL_StanceSwift,
        .icon = GFX_SkillIcon_StanceSwift,
    },
    [SID_StanceWarding] = {
        .msg  = MSG_SKILL_StanceWarding,
        .icon = GFX_SkillIcon_StanceWarding,
    },
    [SID_RangeBonusBMag1] = {
        .msg  = MSG_SKILL_RangeBonusBMag1,
        .icon = GFX_SkillIcon_RangeBonusBMag1,
    },
    [SID_RangeBonusBMag2] = {
        .msg  = MSG_SKILL_RangeBonusBMag2,
        .icon = GFX_SkillIcon_RangeBonusBMag2,
    },
    [SID_RangeBonusBow1] = {
        .msg  = MSG_SKILL_RangeBonusBow1,
        .icon = GFX_SkillIcon_RangeBonusBow1,
    },
    [SID_RangeBonusBow2] = {
        .msg  = MSG_SKILL_RangeBonusBow2,
        .icon = GFX_SkillIcon_RangeBonusBow2,
    },
};

FEB_IDENTIFIER(gSkillInfos);
