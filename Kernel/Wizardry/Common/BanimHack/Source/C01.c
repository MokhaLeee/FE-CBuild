#include "global.h"
#include "bmunit.h"
#include "bmbattle.h"
#include "anime.h"
#include "ekrbattle.h"
#include "efxbattle.h"

#include "common-chax.h"
#include "battle-system.h"

STATIC_DECLAR bool IsAttackerAnim(struct Anim * anim)
{
    int round = anim->nextRoundId - 1;
    bool is_retal = !!(gBattleHitArrayRe[round].info & BATTLE_HIT_INFO_RETALIATION);
    bool init_pos = (GetAnimPosition(anim) == gEkrInitialPosition[0]);

    if (is_retal && !init_pos)
        return true;

    if (!is_retal && init_pos)
        return true;

    return false;
}

STATIC_DECLAR int GetBattleActorHpAtRound(int round)
{
    int i, ret = 0;

    if (round > NEW_BATTLE_HIT_MAX)
        round = NEW_BATTLE_HIT_MAX;

    ret = GetUnitCurrentHp(GetUnit(gBattleActor.unit.index));

    for (i = 0; i < round; i++)
    {
        struct BattleHit * hit = &gBattleHitArrayRe[i];

        if (hit->info & BATTLE_HIT_INFO_RETALIATION)
            ret += hit->hpChange;

        if (hit->info & BATTLE_HIT_INFO_END)
            break;
    }
    return ret;
}

STATIC_DECLAR int GetBattleTargetHpAtRound(int round)
{
    int i, ret = 0;

    if (round > NEW_BATTLE_HIT_MAX)
        round = NEW_BATTLE_HIT_MAX;

    ret = GetUnitCurrentHp(GetUnit(gBattleTarget.unit.index));

    for (i = 0; i < round; i++)
    {
        struct BattleHit * hit = &gBattleHitArrayRe[i];

        if (!(hit->info & BATTLE_HIT_INFO_RETALIATION))
            ret += hit->hpChange;

        if (hit->info & BATTLE_HIT_INFO_END)
            break;
    }
    return ret;
}

STATIC_DECLAR void UpdateHpDrainForEkrGauge(struct Anim * anim)
{
    int round = anim->nextRoundId - 1;

    /**
     * Defender auto advance the hpbar-offset, so we just need judge on attacker.
     * 
     * BTW, since this function is called after EfxHpBar, so we may not care on Devil weapon effect.
     */
    if (!IsAttackerAnim(anim))
        return;

    if (GetAISLayerId(anim) != 0)
        return;

    /**
     * For now, we just care about hp-drain.
     */
    if (gBattleHitArrayRe[round].info & BATTLE_HIT_ATTR_HPSTEAL)
    {
        int pos, real_hp;

        pos = GetAnimPosition(anim);
        if (pos == POS_L)
        {
            if (gpEkrBattleUnitLeft == &gBattleActor)
                real_hp = GetBattleActorHpAtRound(round);
            else
                real_hp = GetBattleTargetHpAtRound(round);
        }
        else
        {
            if (gpEkrBattleUnitRight == &gBattleActor)
                real_hp = GetBattleActorHpAtRound(round);
            else
                real_hp = GetBattleTargetHpAtRound(round);
        }

        /**
         * HpBar offset may also change during HP-Darin anim
         * such as StartSpellAnimNosferatu()
         */
        if (GetEfxHp(gEfxHpLutOff[pos] * 2 + pos) != real_hp)
        {
            gEfxHpLutOff[pos] = gEfxHpLutOff[pos] + 1;
            gEkrGaugeHp[pos] = GetEfxHp(gEfxHpLutOff[pos] * 2 + pos);
        }
    }
}

/**
 * C01
 * Wait for HP to deplete: CheckEkrHitDone()
 */
void Banim_C01(struct Anim * anim)
{
    if (C01_BLOCKING_PRE_BATTLE(anim))
    {
        anim->pScrCurrent = anim->pScrStart;
    }
    else if (!C01_BLOCKING_IN_BATTLE(anim))
    {
        anim->pScrCurrent = anim->pScrCurrent + 1;
    }
    else if (anim->state3 & ANIM_BIT3_HIT_EFFECT_APPLIED)
    {
        if (CheckEkrHitDone() == true)
        {
#if CHAX
            UpdateHpDrainForEkrGauge(anim);
#endif
            anim->state3 &= ~(ANIM_BIT3_TAKE_BACK_ENABLE |
                                ANIM_BIT3_C01_BLOCKING_IN_BATTLE |
                                ANIM_BIT3_HIT_EFFECT_APPLIED);

            anim->pScrCurrent = anim->pScrCurrent + 1;

            if (Get0201FAC8() != 0)
                Set0201FAC8(0);
        }
    }
}
