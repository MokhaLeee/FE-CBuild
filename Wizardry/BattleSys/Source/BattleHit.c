#include "global.h"
#include "bmunit.h"
#include "bmbattle.h"

#include "common-chax.h"
#include "skill-system.h"
#include "efx-skill.h"
#include "battle-system.h"
#include "strmag.h"
#include "constants/skills.h"

/* LynJump */
void BattleGenerateHitAttributes(struct BattleUnit * attacker, struct BattleUnit * defender)
{
    int attack, defense;

    struct Unit * unit = GetUnit(attacker->unit.index);

    if (!BattleRoll2RN(gBattleStats.hitRate, TRUE))
    {
        gBattleHitIterator->attributes |= BATTLE_HIT_ATTR_MISS;
        return;
    }

    attack = gBattleStats.attack;
    defense = gBattleStats.defense;

    gBattleStats.damage = attack - defense;

    if (SkillTester(unit, SID_FlashingBladePlus))
        gBattleStats.damage += 3;

    if (BattleRoll1RN(gBattleStats.critRate, FALSE) == TRUE)
    {
        if (BattleRoll1RN(gBattleStats.silencerRate, FALSE))
        {
            /* Silencer */
            gBattleHitIterator->attributes |= BATTLE_HIT_ATTR_SILENCER;
            gBattleStats.damage = BATTLE_MAX_DAMAGE;
        }
        else
        {
            gBattleHitIterator->attributes |= BATTLE_HIT_ATTR_CRIT;

            /* InfinityEdge */
            if (SkillTester(unit, SID_InfinityEdge))
                gBattleStats.damage = gBattleStats.damage * 3;
            else
                gBattleStats.damage = gBattleStats.damage * 2;
        }
    }

    /* Minus zero */
    if (gBattleStats.damage < 0)
        gBattleStats.damage = 0;

    /* Real damage */
    if (SkillTester(unit, SID_RuinedBlade))
        gBattleStats.damage += 5;

    if (SkillTester(unit, SID_RuinedBladePlus))
        gBattleStats.damage += 5;

    if (SkillTester(unit, SID_LunaAttack))
        gBattleStats.damage += defender->battleDefense / 4;

    /* Post calc */
    if (gBattleStats.damage > BATTLE_MAX_DAMAGE)
        gBattleStats.damage = BATTLE_MAX_DAMAGE;

    BattleCheckPetrify(attacker, defender);

    if (gBattleStats.damage != 0)
        attacker->nonZeroDamage = TRUE;
}
