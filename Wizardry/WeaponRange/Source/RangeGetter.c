#include "global.h"
#include "bmunit.h"
#include "bmitem.h"
#include "bmmap.h"
#include "bmidoten.h"

#include "common-chax.h"
#include "status-getter.h"
#include "weapon-range.h"

typedef int (* WeaponRangeGetterFunc_t)(int old, struct Unit * unit, u16 item);
extern const WeaponRangeGetterFunc_t gWeaponRangeGetters[];

int GetItemMinRangeRework(u16 item, struct Unit * unit)
{
    int status = GetItemMinRange(item);

    if (IS_UNIT_PTR(unit))
    {

    }
    return status;
}

int GetItemMaxRangeRework(u16 item, struct Unit * unit)
{
    const WeaponRangeGetterFunc_t * it;
    int status = GetItemMaxRange(item);
    if (IS_UNIT_PTR(unit))
    {
        for (it = gWeaponRangeGetters; *it; it++)
            status = (*it)(status, unit, item);
    }
    return status;
}

int WeaponRangeGetterSkills(int status, struct Unit * unit, u16 item)
{
    return status;
}
