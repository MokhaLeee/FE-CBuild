#include "global.h"
#include "bmunit.h"
#include "bmitem.h"
#include "bmbattle.h"
#include "constants/items.h"

#include "common-chax.h"
#include "status-getter.h"
#include "skill-system.h"
#include "efx-skill.h"
#include "battle-system.h"
#include "constants/skills.h"

enum {
	NOP_ATTACK = 0,
	ACT_ATTACK = 1,
	TAR_ATTACK = 2,
};

enum {
	UNWIND_VANTAGE = 1 << 0,
	UNWIND_DESPERA = 1 << 1,
	UNWIND_DOUBLE_ACT = 1 << 2,
	UNWIND_DOUBLE_TAR = 1 << 3,
};


static const u8 BattleUnwindConfig[14][4] = {
	{ ACT_ATTACK, TAR_ATTACK, NOP_ATTACK, NOP_ATTACK }, // 0:default
	{ TAR_ATTACK, ACT_ATTACK, NOP_ATTACK, NOP_ATTACK }, // 1   = 1
	{ ACT_ATTACK, ACT_ATTACK, TAR_ATTACK, NOP_ATTACK }, // 2   = 2	

	{ TAR_ATTACK, ACT_ATTACK, ACT_ATTACK, NOP_ATTACK }, // 12  = 3
	{ ACT_ATTACK, TAR_ATTACK, ACT_ATTACK, NOP_ATTACK }, // 3   = 4
	{ TAR_ATTACK, ACT_ATTACK, ACT_ATTACK, NOP_ATTACK }, // 13  = 5
	{ ACT_ATTACK, TAR_ATTACK, NOP_ATTACK, NOP_ATTACK }, // 0:default
	{ ACT_ATTACK, TAR_ATTACK, NOP_ATTACK, NOP_ATTACK }, // 0:default
	{ ACT_ATTACK, TAR_ATTACK, TAR_ATTACK, NOP_ATTACK }, // 4   = 8
	{ TAR_ATTACK, ACT_ATTACK, TAR_ATTACK, NOP_ATTACK }, // 14  = 9
	{ ACT_ATTACK, ACT_ATTACK, TAR_ATTACK, TAR_ATTACK }, // 24  = 10

	{ TAR_ATTACK, ACT_ATTACK, ACT_ATTACK, TAR_ATTACK }, // 124 = 11
	{ ACT_ATTACK, TAR_ATTACK, ACT_ATTACK, TAR_ATTACK }, // 34  = 12
	{ TAR_ATTACK, ACT_ATTACK, TAR_ATTACK, ACT_ATTACK }  // 134 = 13
};

/* This function should also be called by BKSEL, so non static */
bool CheckCanTwiceAttackOrder(struct BattleUnit * actor, struct BattleUnit * target)
{
    struct Unit * real_actor = GetUnit(gBattleActor.unit.index);
    struct Unit * real_target = GetUnit(gBattleTarget.unit.index);

    if (target->battleSpeed > 250)
        return false;

    if (GetItemWeaponEffect(actor->weaponBefore) == WPN_EFFECT_HPHALVE)
        return false;

    if (GetItemIndex(actor->weapon) == ITEM_MONSTER_STONE)
        return false;

    if (&gBattleActor == actor)
    {
        if (SkillTester(real_target, SID_WaryFighter))
            if ((GetUnitCurrentHp(real_target) * 2) > HpMaxGetter(real_target))
                return false;

        gBattleTemporaryFlag &= ~TMP_DOUBLE_LION_ORDER_FLAG;

        if (SkillTester(real_actor, SID_DoubleLion))
        {
            if (GetUnitCurrentHp(real_actor) == HpMaxGetter(real_actor))
            {
                gBattleGlobalFlag |= BATTLE_DOUBLE_LION_POST_ACTION_FLAG;
                gBattleTemporaryFlag |= TMP_DOUBLE_LION_ORDER_FLAG;
                return true;
            }
        }
    }
    else if (&gBattleTarget == actor)
    {
        gBattleTemporaryFlag &= ~TMP_QUICK_RIPOSTE_ORDER_FLAG;

        if (SkillTester(real_actor, SID_QuickRiposte))
        {
            if ((GetUnitCurrentHp(real_target) * 2) > HpMaxGetter(real_target))
            {
                gBattleTemporaryFlag |= TMP_QUICK_RIPOSTE_ORDER_FLAG;
                return true;
            }
        }
    }

    if ((actor->battleSpeed - target->battleSpeed) < BATTLE_FOLLOWUP_SPEED_THRESHOLD)
        return false;

    return true;
}

STATIC_DECLAR bool CheckDesperationOrder(void)
{
    struct Unit * actor = GetUnit(gBattleActor.unit.index);

    gBattleTemporaryFlag &= ~TMP_DESPERATION_ORDER_FLAG;

    if (SkillTester(actor, SID_Desperation))
    {
        if ((GetUnitCurrentHp(actor) * 2) < HpMaxGetter(actor))
        {
            gBattleTemporaryFlag |= TMP_DESPERATION_ORDER_FLAG;
            return true;
        }
    }
    return false;
}

STATIC_DECLAR bool CheckVantageOrder(void)
{
    struct Unit * target = GetUnit(gBattleTarget.unit.index);

    gBattleTemporaryFlag &= ~TMP_VANTAGE_ORDER_FLAG;

    if (SkillTester(target, SID_Vantage))
    {
        if ((GetUnitCurrentHp(target) * 2) < HpMaxGetter(target))
        {
            gBattleTemporaryFlag |= TMP_VANTAGE_ORDER_FLAG;
            return true;
        }
    }
    return false;
}

/* LynJump */
void BattleUnwind(void)
{
    int i, ret;
    u8 round_mask = 0;
    const u8 * config;

    /* Identifier to record attack amount for skill anim triger */
    int actor_count = 0;
    int target_count = 0;

    ClearBattleHits();
    gBattleHitIterator->info |= BATTLE_HIT_INFO_BEGIN;

    /**
     * gBattleGlobalFlag should not clear in battle routine
     * because combat art flag is configured in pre-combat.
     * It is cleared in:
     *  a). post action
     *  b). game init
     */

    // gBattleGlobalFlag = 0;

    if (CheckDesperationOrder())
        round_mask |= UNWIND_DESPERA;

    if (CheckVantageOrder())
        round_mask |= UNWIND_VANTAGE;

    if (CheckCanTwiceAttackOrder(&gBattleActor, &gBattleTarget))
        round_mask |= UNWIND_DOUBLE_ACT;

    if (CheckCanTwiceAttackOrder(&gBattleTarget, &gBattleActor))
        round_mask |= UNWIND_DOUBLE_TAR;

    config = BattleUnwindConfig[round_mask];

    for (i = 0; i < 4; i++)
    {
        struct BattleHit * old = gBattleHitIterator;

        if (ACT_ATTACK == config[i])
        {
            ret = BattleGenerateRoundHits(&gBattleActor, &gBattleTarget);
            actor_count++;
        }
        else if (TAR_ATTACK == config[i])
        {
            gBattleHitIterator->attributes |= BATTLE_HIT_ATTR_RETALIATE;
            ret = BattleGenerateRoundHits(&gBattleTarget, &gBattleActor);
            target_count++;
        }
        else if (NOP_ATTACK == config[i])
        {
            break;
        }

        if (i != 0 && config[i - 1] == config[i])
            gBattleHitIterator->attributes = BATTLE_HIT_ATTR_FOLLOWUP;

        /* Vantage */
        if (i == 0 && (round_mask & UNWIND_VANTAGE))
        {
            if (gBattleTemporaryFlag & TMP_VANTAGE_ORDER_FLAG)
                RegisterActorEfxSkill(GetBattleHitRound(old), SID_Vantage);
        }

        /* Desperation */
        if (i == 1 && (round_mask & UNWIND_DESPERA))
        {
            if (config[0] == ACT_ATTACK && config[1] == ACT_ATTACK && config[2] == TAR_ATTACK)
            {
                if (gBattleTemporaryFlag & TMP_DESPERATION_ORDER_FLAG)
                    RegisterActorEfxSkill(GetBattleHitRound(old), SID_Desperation);
            }
        }

        /* Target double attack */
        if (target_count > 1 && config[i] == TAR_ATTACK)
        {
            if (gBattleTemporaryFlag & TMP_QUICK_RIPOSTE_ORDER_FLAG)
                RegisterActorEfxSkill(GetBattleHitRound(old), SID_QuickRiposte);
        }

        /* Actor double attack */
        if (actor_count > 1 && config[i] == ACT_ATTACK)
        {
            if (gBattleTemporaryFlag & TMP_DOUBLE_LION_ORDER_FLAG)
                RegisterActorEfxSkill(GetBattleHitRound(old), SID_DoubleLion);
        }

        if (ret)
            break;
    }
    gBattleHitIterator->info |= BATTLE_HIT_INFO_END;
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

        /* RuinedBladePlus */
        if (i == 1 && (gBattleTemporaryFlag & TMP_RUINED_BLADE_PLUS_ORDER_FLAG))
            RegisterActorEfxSkill(GetBattleHitRound(gBattleHitIterator), SID_RuinedBladePlus);

        if (BattleGenerateHit(attacker, defender))
            return true;

        /* Hack here: we need avoid hit array overflow */
        if (CheckBattleHitOverflow())
        {
            Error("Battle hit overflowed!");
            gBattleHitIterator = gBattleHitIterator - 1;
            gBattleHitIterator->info |= (BATTLE_HIT_INFO_FINISHES | BATTLE_HIT_INFO_END);
            return true;
        }
    }
    return false;
}

/* LynJump */
bool BattleGetFollowUpOrder(struct BattleUnit ** outAttacker, struct BattleUnit ** outDefender)
{
    if (CheckCanTwiceAttackOrder(&gBattleActor, &gBattleTarget))
    {
        *outAttacker = &gBattleActor;
        *outDefender = &gBattleTarget;
        return true;
    }
    else if (CheckCanTwiceAttackOrder(&gBattleTarget, &gBattleActor))
    {
        *outAttacker = &gBattleTarget;
        *outDefender = &gBattleActor;
        return true;
    }
    return false;
}

/* LynJump */
int GetBattleUnitHitCount(struct BattleUnit * actor)
{
    int result = 1;

    gBattleTemporaryFlag &= ~TMP_RUINED_BLADE_PLUS_ORDER_FLAG;

    if (BattleCheckBraveEffect(actor))
        result = result + 1;

    if (SkillTester(&actor->unit, SID_RuinedBladePlus))
    {
        gBattleTemporaryFlag |= TMP_RUINED_BLADE_PLUS_ORDER_FLAG;
        result = result + 1;
    }
    return result;
}
