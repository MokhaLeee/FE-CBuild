#include "global.h"
#include "bmunit.h"
#include "bmbattle.h"

#include "common-chax.h"
#include "skill-system.h"
#include "strmag.h"
#include "constants/skills.h"

typedef void (* PreBattleCalcFunc) (struct BattleUnit * buA, struct BattleUnit * buB);

/* LynJump */
void ComputeBattleUnitDefense(struct BattleUnit * attacker, struct BattleUnit* defender) {
    int status, def, res;
    struct Unit * unit = GetUnit(attacker->unit.index);

    def = attacker->unit.def + attacker->terrainDefense;
    res = attacker->unit.res + attacker->terrainResistance;

    if (IsMagicAttack(defender))
        status = res;
    else
        status = def;

    if (SkillTester(unit, SID_SorceryBlade))
        status = def < res ? def : res;

    attacker->battleDefense = status;
}

STATIC_DECLAR void PreBattleCalcInit(struct BattleUnit * attacker, struct BattleUnit * defender)
{
    ComputeBattleUnitDefense(attacker, defender);
    ComputeBattleUnitAttack(attacker, defender);
    ComputeBattleUnitSpeed(attacker);
    ComputeBattleUnitHitRate(attacker);
    ComputeBattleUnitAvoidRate(attacker);
    ComputeBattleUnitCritRate(attacker);
    ComputeBattleUnitDodgeRate(attacker);
    ComputeBattleUnitSupportBonuses(attacker, defender);
    ComputeBattleUnitWeaponRankBonuses(attacker);
    ComputeBattleUnitStatusBonuses(attacker);

    /* Calc silencer rate at pre-battle-calc rather than battle-calc-real */
    attacker->battleSilencerRate = 0;
}

STATIC_DECLAR void PreBattleCalcEnd(struct BattleUnit * attacker, struct BattleUnit * defender)
{
    if (attacker->battleAttack < 0)
        attacker->battleAttack = 0;

    if (attacker->battleDefense < 0)
        attacker->battleDefense = 0;

    if (attacker->battleSpeed < 0)
        attacker->battleSpeed = 0;

    if (attacker->battleHitRate < 0)
        attacker->battleHitRate = 0;

    if (attacker->battleAvoidRate < 0)
        attacker->battleAvoidRate = 0;

    if (attacker->battleCritRate < 0)
        attacker->battleCritRate = 0;

    if (attacker->battleDodgeRate < 0)
        attacker->battleDodgeRate = 0;

    /* If defender cannot get silencer */
    if (UNIT_CATTRIBUTES(&defender->unit) & CA_NEGATE_LETHALITY)
        attacker->battleSilencerRate = 0;

    if (attacker->battleSilencerRate < 0)
        attacker->battleSilencerRate = 0;
}

STATIC_DECLAR void PreBattleCalcSkills(struct BattleUnit * attacker, struct BattleUnit * defender)
{
    struct Unit * unit = GetUnit(attacker->unit.index);

    /* Defiant skills */
    if ((GetUnitCurrentHp(unit) * 4) < GetUnitMaxHp(unit))
    {
        if (SkillTester(unit, SID_DefiantCrit))
            attacker->battleCritRate += 50;

        if (SkillTester(unit, SID_DefiantAvoid))
            attacker->battleAvoidRate += 30;
    }

    /* Blow skills */

    /* Stance skills */

    /* Misc */
    if (SkillTester(unit, SID_Lethality))
        attacker->battleSilencerRate += GetUnitSkill(unit);

    if (SkillTester(unit, SID_WatchfulEye))
        attacker->battleHitRate += 20;

    if (SkillTester(unit, SID_Crit))
        attacker->battleCritRate += 15;

    if (SkillTester(unit, SID_Avoid))
        attacker->battleAvoidRate += 10;

    /* wType related */
    switch (attacker->weaponType)
    {
    case ITYPE_SWORD:
        if (SkillTester(unit, SID_CritSword))
            attacker->battleCritRate += 10;

        if (SkillTester(unit, SID_FaireSword))
            attacker->battleAttack += 5;

        if (SkillTester(unit, SID_AvoidSword))
            attacker->battleAvoidRate += 20;
        break;

    case ITYPE_LANCE:
        if (SkillTester(unit, SID_CritLance))
            attacker->battleCritRate += 10;

        if (SkillTester(unit, SID_FaireLance))
            attacker->battleAttack += 5;
        break;

    case ITYPE_AXE:
        if (SkillTester(unit, SID_CritAxe))
            attacker->battleCritRate += 10;

        if (SkillTester(unit, SID_FaireAxe))
            attacker->battleAttack += 5;
        break;

    case ITYPE_BOW:
        if (SkillTester(unit, SID_CritBow))
            attacker->battleCritRate += 10;

        if (SkillTester(unit, SID_FaireBow))
            attacker->battleAttack += 5;
        break;

    case ITYPE_ANIMA:
    case ITYPE_LIGHT:
    case ITYPE_DARK:
        if (SkillTester(unit, SID_FaireBMag))
            attacker->battleAttack += 5;
        break;

    case ITYPE_STAFF:
    case ITYPE_BLLST:
    case ITYPE_ITEM:
    case ITYPE_DRAGN:
    default:
        break;
    }
}

STATIC_DECLAR void PreBattlePostCalcSkills(struct BattleUnit * attacker, struct BattleUnit * defender)
{
    struct Unit * unit = GetUnit(attacker->unit.index);

    if (attacker->battleAttack > defender->battleAttack)
    {
        if (SkillTester(unit, SID_HeavyBlade))
            attacker->battleCritRate += 15;

        if (SkillTester(unit, SID_HeavyBladePlus))
            attacker->battleCritRate += 25;
    }

    if (attacker->battleSpeed > defender->battleSpeed)
    {
        if (SkillTester(unit, SID_FlashingBlade))
            attacker->battleCritRate += 15;

        if (SkillTester(unit, SID_FlashingBladePlus))
            attacker->battleCritRate += 25;
    }
}

STATIC_DECLAR void PreBattleCalcWeaponTriangle(struct BattleUnit * attacker, struct BattleUnit * defender)
{
    int atk_weight = 0;
    int def_weight = 0;

    /* Just a UI identifier for BattleForcase UI */
    if (atk_weight > def_weight)
    {
        attacker->wTriangleHitBonus = +1;
        attacker->wTriangleDmgBonus = +1;
        defender->wTriangleHitBonus = -1;
        defender->wTriangleDmgBonus = -1;
    }
    else
    {
        attacker->wTriangleHitBonus = -1;
        attacker->wTriangleDmgBonus = -1;
        defender->wTriangleHitBonus = +1;
        defender->wTriangleDmgBonus = +1;
    }
}

STATIC_DECLAR void PreBattleCalcSilencerRate(struct BattleUnit * attacker, struct BattleUnit * defender)
{
    if (UNIT_CATTRIBUTES(&defender->unit) & CA_BOSS)
        attacker->battleSilencerRate -= 25;
}

STATIC_DECLAR const PreBattleCalcFunc PreBattleCalcFuncs[] = {
    PreBattleCalcInit,

    /* Usr defined funcs */
    PreBattleCalcSilencerRate,
    PreBattleCalcWeaponTriangle,
    PreBattleCalcSkills,

    PreBattleCalcEnd,
    NULL,
};

/* LynJump */
void ComputeBattleUnitStats(struct BattleUnit * attacker, struct BattleUnit * defender)
{
    const PreBattleCalcFunc * it;
    for (it = PreBattleCalcFuncs; *it; it++)
        (*it)(attacker, defender);
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

/* LynJump */
void ComputeBattleUnitSilencerRate(struct BattleUnit * attacker, struct BattleUnit * defender)
{
    return;
}
