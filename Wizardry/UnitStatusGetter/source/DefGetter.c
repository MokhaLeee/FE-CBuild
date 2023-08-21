#include "global.h"
#include "bmunit.h"
#include "bmitem.h"

#include "status-getter.h"

int _GetUnitDefense(struct Unit * unit)
{
    const StatusGetterFunc_t * it;
    int status = unit->def;

    for (it = gDefGetters; *it; it++)
        status = (*it)(status, unit);

    return status;
}

/* Hooks */
int DefGetterWeaponBonus(int status, struct Unit * unit)
{
    u16 weapon = GetUnitEquippedWeapon(unit);
    status += GetItemDefBonus(weapon);
    return status;
}
