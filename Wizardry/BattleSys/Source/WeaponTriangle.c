#include "global.h"
#include "bmunit.h"
#include "bmbattle.h"

#include "common-chax.h"
#include "skill-system.h"
#include "strmag.h"
#include "constants/skills.h"

struct WeaponTriangleConf {
    s8 wtype_a;
    s8 wtype_b;
    u8 sid;
    u8 _pad_;

    s8 bonus_atk;
    s8 bonus_def;
    s8 bonus_speed;
    s8 bonus_hit;
    s8 bonus_avoid;
    s8 bonus_crit;
    s8 bonus_dodge;
    s8 bonus_silencer;
};

const struct WeaponTriangleConf WeaponTriangleConfs[] = {
    {ITYPE_SWORD, ITYPE_AXE,   SID_AxeBreaker,   0, 0, 0, 0, 20, 20, 0, 0, 0},
    {ITYPE_AXE,   ITYPE_LANCE, SID_LanceBreaker, 0, 0, 0, 0, 20, 20, 0, 0, 0},
    {ITYPE_LANCE, ITYPE_SWORD, SID_SwordBreaker, 0, 0, 0, 0, 20, 20, 0, 0, 0},

    {ITYPE_ANIMA, ITYPE_BOW,   SID_BowBreaker,   0, 0, 0, 0, 20, 20, 0, 0, 0},
    {ITYPE_LIGHT, ITYPE_BOW,   SID_BowBreaker,   0, 0, 0, 0, 20, 20, 0, 0, 0},
    {ITYPE_DARK,  ITYPE_BOW,   SID_BowBreaker,   0, 0, 0, 0, 20, 20, 0, 0, 0},

    {ITYPE_BOW,   ITYPE_ANIMA, SID_BMagBreaker,  0, 0, 0, 0, 20, 20, 0, 0, 0},
    {ITYPE_BOW,   ITYPE_LIGHT, SID_BMagBreaker,  0, 0, 0, 0, 20, 20, 0, 0, 0},
    {ITYPE_BOW,   ITYPE_DARK,  SID_BMagBreaker,  0, 0, 0, 0, 20, 20, 0, 0, 0},

    {ITYPE_SWORD, ITYPE_ANIMA, SID_BMagBreaker,  0, 0, 0, 0, 20, 20, 0, 0, 0},
    {ITYPE_SWORD, ITYPE_LIGHT, SID_BMagBreaker,  0, 0, 0, 0, 20, 20, 0, 0, 0},
    {ITYPE_SWORD, ITYPE_DARK,  SID_BMagBreaker,  0, 0, 0, 0, 20, 20, 0, 0, 0},

    {ITYPE_AXE,   ITYPE_ANIMA, SID_BMagBreaker,  0, 0, 0, 0, 20, 20, 0, 0, 0},
    {ITYPE_AXE,   ITYPE_LIGHT, SID_BMagBreaker,  0, 0, 0, 0, 20, 20, 0, 0, 0},
    {ITYPE_AXE,   ITYPE_DARK,  SID_BMagBreaker,  0, 0, 0, 0, 20, 20, 0, 0, 0},

    {ITYPE_LANCE, ITYPE_ANIMA, SID_BMagBreaker,  0, 0, 0, 0, 20, 20, 0, 0, 0},
    {ITYPE_LANCE, ITYPE_LIGHT, SID_BMagBreaker,  0, 0, 0, 0, 20, 20, 0, 0, 0},
    {ITYPE_LANCE, ITYPE_DARK,  SID_BMagBreaker,  0, 0, 0, 0, 20, 20, 0, 0, 0},
    {0}
};

void PreBattleCalcWeaponTriangle(struct BattleUnit * attacker, struct BattleUnit * defender)
{
    struct Unit * unit = GetUnit(attacker->unit.index);
    const struct WeaponTriangleConf * it;

    for (it = WeaponTriangleConfs; it->wtype_a != it->wtype_b; it++)
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
