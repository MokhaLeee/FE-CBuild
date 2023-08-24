#include "global.h"
#include "common-chax.h"

#include "efx-anim.h"

extern const struct EfxAnimConf EfxSkillVanilla, EfxSkillMokha;

struct EfxAnimConf const * const gEfxSkillAnims[] = {
    [EFX_SKILL_DEFAULT] = &EfxSkillVanilla,
    [EFX_SKILL_MOKHA] = &EfxSkillMokha,
    NULL
};

FEB_IDENTIFIER(gEfxSkillAnims);
