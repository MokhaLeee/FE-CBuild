#include "global.h"
#include "anime.h"

#include "skill-system.h"
#include "efx-skill.h"
#include "battle-system.h"

struct EfxSkillRoundData {
    u8 sid_actor;
    u8 sid_target;
};

extern struct EfxSkillRoundData sEfxSkillRoundData[NEW_BATTLE_HIT_MAX];

/* This function should be placed at: ClearBattleHits() */
void InitEfxSkillRoundData(void)
{
    CpuFastFill16(0, sEfxSkillRoundData, sizeof(sEfxSkillRoundData));
}

void RegisterActorEfxSkill(int round, const u8 sid)
{
    if (round < NEW_BATTLE_HIT_MAX)
    {
        u8 sid_old = sEfxSkillRoundData[round].sid_actor;
        if (GetEfxSkillPriority(sid) > GetEfxSkillPriority(sid_old))
            sEfxSkillRoundData[round].sid_actor = sid;
    }
}

void RegisterTargetEfxSkill(int round, const u8 sid)
{
    if (round < NEW_BATTLE_HIT_MAX)
    {
        u8 sid_old = sEfxSkillRoundData[round].sid_target;
        if (GetEfxSkillPriority(sid) > GetEfxSkillPriority(sid_old))
            sEfxSkillRoundData[round].sid_target = sid;
    }
}

u8 GetActorEfxSkill(int round)
{
    if (round < NEW_BATTLE_HIT_MAX)
        return sEfxSkillRoundData[round].sid_actor;

    return 0;
}

u8 GetTargetEfxSkill(int round)
{
    if (round < NEW_BATTLE_HIT_MAX)
        return sEfxSkillRoundData[round].sid_target;

    return 0;
}
