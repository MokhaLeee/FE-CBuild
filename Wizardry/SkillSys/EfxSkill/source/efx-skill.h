#pragma once

#include "global.h"
#include "proc.h"

struct ProcEkrSkill {
    PROC_HEADER;
    struct Anim * anim;
    int sid_atk;
    int sid_def;
};

struct ProcEfxSkillRework {
    PROC_HEADER;
    int timer;
    int frame;
    int sid;
    struct Anim * anim;
    const u16 * const * imgs;
    const u16 * const * pals;
    const u16 * const * tsas;
    const s16 * frames;
};

void NewEfxSkill(struct Anim *anim, int sid);
bool EfxSkillExists(void);

/* Utils */
void SortEfxSkills(struct Anim * anim, u8 * sidout_atk, u8 * sidout_def);
