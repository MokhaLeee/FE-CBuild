#include "global.h"
#include "bmunit.h"
#include "bmitem.h"

#include "common-chax.h"
#include "skill-system.h"
#include "status-getter.h"

int _GetUnitSkill(struct Unit * unit)
{
    const StatusGetterFunc_t * it;
    int status = unit->skl;

    if (unit->state & US_RESCUING)
        status = unit->skl / 2;

    for (it = gSklGetters; *it; it++)
        status = (*it)(status, unit);

    return status;
}

/* Hooks */
int SklGetterWeaponBonus(int status, struct Unit * unit)
{
    u16 weapon = GetUnitEquippedWeapon(unit);
    status += GetItemSklBonus(weapon);
    return status;
}

int SklGetterSkills(int status, struct Unit * unit)
{
    if (SkillTester(unit, SID_SklBonus))
        status += 2;

    if (SkillTester(unit, SID_DefiantSkl))
        if ((GetUnitCurrentHp(unit) * 4) < GetUnitMaxHp(unit))
            status += 7;

    if (SkillTester(unit, SID_Fury))
        status += 3;

    if (SkillTester(unit, SID_FuryPlus))
        status += 4;

    return status;
}
