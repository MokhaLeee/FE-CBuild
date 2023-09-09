#include "global.h"
#include "bmunit.h"
#include "bmitem.h"
#include "bmbattle.h"
#include "constants/items.h"

#include "common-chax.h"
#include "battle-system.h"

bool CheckCanFollowUpAttack(struct BattleUnit * actor, struct BattleUnit * target)
{
    if (target->battleSpeed > 250)
        return false;

    if ((actor->battleSpeed - target->battleSpeed) < BATTLE_FOLLOWUP_SPEED_THRESHOLD)
        return false;

    return true;
}

/* LynJump */
bool BattleGetFollowUpOrder(struct BattleUnit ** outAttacker, struct BattleUnit ** outDefender)
{
    if (CheckCanFollowUpAttack(&gBattleActor, &gBattleTarget))
    {
        *outAttacker = &gBattleActor;
        *outDefender = &gBattleTarget;
    }
    else if (CheckCanFollowUpAttack(&gBattleTarget, &gBattleActor))
    {
        *outAttacker = &gBattleTarget;
        *outDefender = &gBattleActor;
    }
    else
    {
        return false;
    }

    if (GetItemWeaponEffect((*outAttacker)->weaponBefore) == WPN_EFFECT_HPHALVE)
        return false;

    if (GetItemIndex((*outAttacker)->weapon) == ITEM_MONSTER_STONE)
        return false;

    return true;
}

/* LynJump */
int GetBattleUnitHitCount(struct BattleUnit * attacker)
{
    int result = 1;
    result <<= BattleCheckBraveEffect(attacker);
    return result;
}
