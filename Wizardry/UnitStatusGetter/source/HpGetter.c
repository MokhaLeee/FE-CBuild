#include "global.h"
#include "bmunit.h"
#include "bmitem.h"

#include "status-getter.h"

int _GetUnitMaxHp(struct Unit * unit)
{
    const StatusGetterFunc_t * it;
    int status = unit->maxHP;

    for (it = gHpGetters; *it; it++)
        status = (*it)(status, unit);

    return status;
}

/* Hooks */
int HpGetterWeaponBonus(int status, struct Unit * unit)
{
    u16 weapon = GetUnitEquippedWeapon(unit);
    status += GetItemHpBonus(weapon);
    return status;
}
