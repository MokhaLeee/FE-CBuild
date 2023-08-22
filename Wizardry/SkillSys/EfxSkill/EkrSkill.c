#include "global.h"
#include "anime.h"
#include "ekrbattle.h"
#include "efxbattle.h"

#include "skill-system.h"
#include "efx-skill.h"

static void EfxSkillSetAnimState(struct Anim * anim)
{
    struct Anim * anim1, * anim2;

    anim1 = gAnims[GetAnimPosition(anim) * 2];
    anim2 = gAnims[GetAnimPosition(anim) * 2 + 1];

    anim->state3 |= ANIM_BIT3_BLOCKING;
    anim->state |= ANIM_BIT_FROZEN;

    anim1->state3 |= ANIM_BIT3_BLOCKING;
    anim1->state |= ANIM_BIT_FROZEN;

    anim2->state3 |= ANIM_BIT3_BLOCKING;
    anim2->state |= ANIM_BIT_FROZEN;
}

static void EfxSkillResetAnimState(struct Anim * anim)
{
    struct Anim * anim1, * anim2;

    anim1 = gAnims[GetAnimPosition(anim) * 2];
    anim2 = gAnims[GetAnimPosition(anim) * 2 + 1];

    anim->state3 |= ANIM_BIT3_BLOCKEND;
    anim->state &= ~ANIM_BIT_FROZEN;

    anim1->state3 |= ANIM_BIT3_BLOCKEND;
    anim1->state &= ~ANIM_BIT_FROZEN;

    anim2->state3 |= ANIM_BIT3_BLOCKEND;
    anim2->state &= ~ANIM_BIT_FROZEN;
}

static void EkrSkillOnInit(struct ProcEkrSkill * proc)
{
    EfxSkillSetAnimState(proc->anim);
}

static void EkrSkillOnEnd(struct ProcEkrSkill * proc)
{
    EfxSkillResetAnimState(proc->anim);
}

static void NewEfxSkillForAttacker(struct ProcEkrSkill * proc)
{
    if (SKILL_VALID(proc->sid_atk))
        NewEfxSkill(proc->anim, proc->sid_atk);
}

static void NewEfxSkillForDefener(struct ProcEkrSkill * proc)
{
    /* Todo */
    return;
}

static const struct ProcCmd ProcScr_EkrSkill[] = {
    PROC_NAME("EkrSkill"),
    PROC_CALL(EkrSkillOnInit),
    PROC_YIELD,
    PROC_CALL(NewEfxSkillForAttacker),
    PROC_WHILE(EfxSkillExists),
    PROC_YIELD,
    PROC_CALL(NewEfxSkillForDefener),
    PROC_WHILE(EfxSkillExists),
    PROC_YIELD,
    PROC_CALL(EkrSkillOnEnd),
    PROC_END
};

static void NewEkrSkill(struct Anim * anim)
{
    u8 sid_atk, sid_def;
    struct ProcEkrSkill * proc = Proc_Start(ProcScr_EkrSkill, PROC_TREE_3);
    proc->anim = anim;

    SortEfxSkills(anim, &sid_atk, &sid_def);
    proc->sid_atk = sid_atk;
    proc->sid_def = sid_def;
}

void BanimEkrSkillHandler(struct Anim * anim)
{
    if (!(anim->state3 & ANIM_BIT3_BLOCKING))
    {
        anim->state3 |= ANIM_BIT3_BLOCKING;

        if (GetAISLayerId(anim) == 0)
            NewEkrSkill(anim);
    }

    if (anim->state3 & ANIM_BIT3_BLOCKING)
    {
        if (anim->state3 & ANIM_BIT3_BLOCKEND)
        {
            anim->state3 &= ~ANIM_BIT3_BLOCKING;
            anim->state3 &= ~ANIM_BIT3_BLOCKEND;
            anim->pScrCurrent = anim->pScrCurrent + 1;
        }
    }
}
