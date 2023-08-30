#ifndef CONFIG_SKILLS_INSTALLED
#define CONFIG_SKILLS_INSTALLED

#include "skill-system.h"

enum SkillIndex {
    SID_DEFAULT = 0x0,

    /* Unit status skills */
    SID_HpBonus,
    SID_StrBonus,
    SID_MagBonus,
    SID_SklBonus,
    SID_SpdBonus,
    SID_LckBonus,
    SID_DefBonus,
    SID_ResBonus,
    SID_MovBonus,

    SID_DefiantStr,
    SID_DefiantMag,
    SID_DefiantSkl,
    SID_DefiantSpd,
    SID_DefiantLck,
    SID_DefiantDef,
    SID_DefiantRes,
    SID_DefiantCrit,
    SID_DefiantAvoid,

    SID_Fury,
    SID_FuryPlus,
    SID_FortressDef,
    SID_FortressRes,
    SID_LifeAndDeath,

    /* Battle status skills */
    SID_Lethality,
    SID_Crit,
    SID_WatchfulEye,
    SID_CritSword,
    SID_CritAxe,
    SID_CritLance,
    SID_CritBow,
    SID_FaireSword,
    SID_FaireLance,
    SID_FaireAxe,
    SID_FaireBow,
    SID_FaireBMag,
    SID_Avoid,
    SID_AvoidSword,
    SID_RuinedBlade,
    SID_RuinedBladePlus,
    SID_InfinityEdge,
    SID_HeavyBlade,
    SID_FlashingBlade,
    SID_HeavyBladePlus,
    SID_FlashingBladePlus,
    SID_LunaAttack,
    SID_SorceryBlade,

    /* Weapon triangle */
    SID_SwordBreaker,
    SID_AxeBreaker,
    SID_LanceBreaker,
    SID_BowBreaker,
    SID_BMagBreaker,

    SID_MAX
};

#endif
