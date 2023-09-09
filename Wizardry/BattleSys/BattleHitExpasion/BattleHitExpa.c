#include "global.h"
#include "bmunit.h"
#include "bmbattle.h"

#include "common-chax.h"
#include "skill-system.h"
#include "battle-system.h"

bool CheckBattleHitOverflow(void)
{
    return (gBattleHitIterator - gBattleHitArrayRe) >= NEW_BATTLE_HIT_MAX;
}

/* LynJump */
bool BattleGenerateRoundHits(struct BattleUnit * attacker, struct BattleUnit * defender)
{
    int i, count;
    u32 attrs;

    if (!attacker->weapon)
        return FALSE;

    attrs = gBattleHitIterator->attributes;
    count = GetBattleUnitHitCount(attacker);

    for (i = 0; i < count; ++i)
    {
        gBattleHitIterator->attributes |= attrs;

        if (BattleGenerateHit(attacker, defender))
            return true;

        /* Hack here: we need avoid hit array overflow */
        if (CheckBattleHitOverflow())
        {
            LogDebugf("%s: battle hit overflowed!", __func__);
            gBattleHitIterator = gBattleHitIterator - 1;
            gBattleHitIterator->info |= (BATTLE_HIT_INFO_FINISHES | BATTLE_HIT_INFO_END);
            return true;
        }
    }
    return false;
}

/* LynJump */
void ClearBattleHits(void)
{
    CpuFastFill16(0, gBattleHitArrayRe, sizeof(gBattleHitArrayRe));
    gBattleHitIterator = gBattleHitArrayRe;
}
