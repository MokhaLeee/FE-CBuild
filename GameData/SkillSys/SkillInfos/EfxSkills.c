#include "global.h"
#include "common-chax.h"

#include "efx-anim.h"
#include "skill-system.h"

extern const struct EfxAnimConf EfxSkillVanilla, EfxSkillMokha;

struct EfxAnimConf const * const gEfxSkillAnims[] = {
    [EFX_SKILL_DEFAULT] = &EfxSkillVanilla,
    [EFX_SKILL_MOKHA] = &EfxSkillMokha,
    NULL
};

const struct SkillAnimInfo gSkillAnimInfos[0x100] = {
    [0x01] = {
        .index = EFX_SKILL_DEFAULT,
        .priority = 0x0,
        .sfx = 0x3D1,
    },
    [0x02] = {
        .index = EFX_SKILL_DEFAULT,
        .priority = 0x0,
        .sfx = 0x3D1,
    },
};

FEB_IDENTIFIER(gEfxSkillAnims);
FEB_IDENTIFIER(gSkillAnimInfos);
