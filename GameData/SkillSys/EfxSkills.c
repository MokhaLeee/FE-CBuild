#include "global.h"
#include "common-chax.h"

#include "efx-anim.h"
#include "skill-system.h"
#include "constants/skills.h"
#include "constants/efx-skills.h"

extern const struct EfxAnimConf EfxSkillVanilla, EfxSkillMokha;

static struct EfxAnimConf const * const sEfxSkillAnims[] = {
    [EFX_SKILL_DEFAULT] = &EfxSkillVanilla,
    [EFX_SKILL_MOKHA] = &EfxSkillMokha,
    NULL
};

struct EfxAnimConf const * const * const gpEfxSkillAnims = sEfxSkillAnims;
FEB_IDENTIFIER(gpEfxSkillAnims);

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

FEB_IDENTIFIER(gSkillAnimInfos);
