#include "global.h"
#include "bmunit.h"
#include "bmitem.h"

#include "status-getter.h"

int _GetUnitResistance(struct Unit * unit)
{
    const StatusGetterFunc_t * it;
    int status = unit->res;

    for (it = gResGetters; *it; it++)
        status = (*it)(status, unit);

    return status;
}

/* Hooks */
int ResGetterWeaponBonus(int status, struct Unit * unit)
{
    u16 weapon = GetUnitEquippedWeapon(unit);
    status += GetItemResBonus(weapon);
    return status;
}
