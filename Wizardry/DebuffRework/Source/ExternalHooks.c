#include "global.h"
#include "bmunit.h"
#include "bmbattle.h"

#include "common-chax.h"
#include "debuff.h"

/* Pre-battle calc */
void PreBattleCalcDebuffs(struct BattleUnit * attacker, struct BattleUnit * defender)
{
    struct Unit * unit = GetUnit(attacker->unit.index);
    int debuff = GetUnitStatusIndex(unit);
    const struct DebuffInfo * info = gDebuffInfos + debuff;

    attacker->battleAttack       += info->battle_status.atk;
    attacker->battleDefense      += info->battle_status.def;
    attacker->battleHitRate      += info->battle_status.hit;
    attacker->battleAvoidRate    += info->battle_status.avo;
    attacker->battleCritRate     += info->battle_status.crit;
    attacker->battleSilencerRate += info->battle_status.silencer;
    attacker->battleDodgeRate    += info->battle_status.dodge;
}

/* Unit status getter */
int PowGetterDebuff(int status, struct Unit * unit)
{
    return status + gDebuffInfos[GetUnitStatusIndex(unit)].unit_status.pow;
}

int MagGetterDebuff(int status, struct Unit * unit)
{
    return status + gDebuffInfos[GetUnitStatusIndex(unit)].unit_status.mag;
}

int SklGetterDebuff(int status, struct Unit * unit)
{
    return status + gDebuffInfos[GetUnitStatusIndex(unit)].unit_status.skl;
}

int SpdGetterDebuff(int status, struct Unit * unit)
{
    return status + gDebuffInfos[GetUnitStatusIndex(unit)].unit_status.spd;
}

int DefGetterDebuff(int status, struct Unit * unit)
{
    return status + gDebuffInfos[GetUnitStatusIndex(unit)].unit_status.def;
}

int ResGetterDebuff(int status, struct Unit * unit)
{
    return status + gDebuffInfos[GetUnitStatusIndex(unit)].unit_status.res;
}

int LckGetterDebuff(int status, struct Unit * unit)
{
    return status + gDebuffInfos[GetUnitStatusIndex(unit)].unit_status.lck;
}

int MovGetterDebuff(int status, struct Unit * unit)
{
    return status + gDebuffInfos[GetUnitStatusIndex(unit)].unit_status.mov;
}
