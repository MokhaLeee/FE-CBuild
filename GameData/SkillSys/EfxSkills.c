#include "global.h"
#include "common-chax.h"

#include "efx-anim.h"
#include "skill-system.h"
#include "constants/skills.h"
#include "constants/efx-skills.h"

extern const struct EfxAnimConf EfxSkillVanilla, EfxSkillMokha;

struct EfxAnimConf const * const gEfxSkillAnims[0x100] = {
    [EFX_SKILL_DEFAULT] = &EfxSkillVanilla,
    [EFX_SKILL_MOKHA] = &EfxSkillMokha,
};

FEB_IDENTIFIER(gEfxSkillAnims);

const struct SkillAnimInfo gSkillAnimInfos[0x100] = {
    [SID_RuinedBlade] = {
        .aid = EFX_SKILL_DEFAULT,
        .priority = 0x1,
        .sfx = 0x3D1,
    },
    [SID_RuinedBladePlus] = {
        .aid = EFX_SKILL_MOKHA,
        .priority = 0x1,
        .sfx = 0x3D1,
    },
};

FEB_IDENTIFIER(gSkillAnimInfos);
