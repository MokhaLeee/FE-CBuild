#include "global.h"
#include "bmunit.h"
#include "bmbattle.h"

#include "common-chax.h"
#include "skill-system.h"
#include "battle-system.h"
#include "strmag.h"
#include "constants/skills.h"

void PreBattleCalcWeaponTriangle(struct BattleUnit * attacker, struct BattleUnit * defender)
{
    struct Unit * unit = GetUnit(attacker->unit.index);
    const struct WeaponTriangleConf * it;

    for (it = gpWeaponTriangleConfs; it->wtype_a != it->wtype_b; it++)
    {
        if (it->wtype_a == attacker->weaponType && it->wtype_b == defender->weaponType)
        {
            if (SkillTester(unit, it->sid))
            {
                attacker->battleAttack       += it->bonus_atk;
                attacker->battleDefense      += it->bonus_def;
                attacker->battleSpeed        += it->bonus_speed;
                attacker->battleHitRate      += it->bonus_hit;
                attacker->battleAvoidRate    += it->bonus_avoid;
                attacker->battleCritRate     += it->bonus_crit;
                attacker->battleDodgeRate    += it->bonus_dodge;
                attacker->battleSilencerRate += it->bonus_silencer;

                /* Just for UI */
                attacker->wTriangleHitBonus = +1;
                attacker->wTriangleDmgBonus = +1;
                defender->wTriangleHitBonus = -1;
                defender->wTriangleDmgBonus = -1;
            }
            break;
        }
    }
}

/* LynJump */
void BattleApplyWeaponTriangleEffect(struct BattleUnit * attacker, struct BattleUnit * defender)
{
    /*
     * Idea:
     * Since vanilla WTA bonus can only get hit & dmg bonus.
     * So here we null the vanilla WTA bonus
     * But just calculate in Pre-Battle calc (PreBattleCalcWeaponTriangle)
     * now WTA-bonus in BattleUnit struct is just for BkSel UI.
     */
    return;
}
