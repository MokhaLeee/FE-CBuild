#include "global.h"
#include "bmunit.h"
#include "bmitem.h"

#include "status-getter.h"

int _GetUnitSpeed(struct Unit * unit)
{
    const StatusGetterFunc_t * it;
    int status = unit->spd;

    if (unit->state & US_RESCUING)
        status = unit->spd / 2;

    for (it = gSpdGetters; *it; it++)
        status = (*it)(status, unit);

    return status;
}

/* Hooks */
int SpdGetterWeaponBonus(int status, struct Unit * unit)
{
    u16 weapon = GetUnitEquippedWeapon(unit);
    status += GetItemSpdBonus(weapon);
    return status;
}
