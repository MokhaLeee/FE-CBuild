#include "global.h"
#include "bmunit.h"
#include "bmitem.h"

#include "StatusGetter.h"

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
