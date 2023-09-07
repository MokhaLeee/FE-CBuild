#include "global.h"
#include "bmunit.h"
#include "bmitem.h"
#include "bmmap.h"
#include "bmidoten.h"

#include "common-chax.h"
#include "status-getter.h"
#include "weapon-range.h"

/* LynJump */
int GetUnitWeaponReachBits(struct Unit * unit, int slot)
{
    int i, item, result = 0;

    if (slot >= 0)
        return ItemRangeToMask(unit->items[slot], unit);

    for (i = 0; (i < UNIT_ITEM_COUNT) && (item = unit->items[i]); ++i)
        if (CanUnitUseWeapon(unit, item))
            result |= ItemRangeToMask(item, unit);

    return result;
}

/* LynJump */
int GetUnitItemUseReachBits(struct Unit * unit, int slot)
{
    int i;
    u16 item;
    u32 mask = 0;

    if (slot >= 0)
    {
        item = unit->items[slot];

        if (!CanUnitUseItem(unit, item))
            return REACH_NONE;

        return ItemRangeToMask(item, unit);
    }

    for (i = 0; i < UNIT_ITEM_COUNT; i++)
    {
        item = unit->items[i];

        if (ITEM_INDEX(item) > 0 && CanUnitUseItem(item))
            mask |= ItemRangeToMask(item, unit);
    }
    return mask;
}

/* LynJump */
int GetUnitStaffReachBits(struct Unit * unit)
{
    int i;
    u16 item;
    u32 mask = 0;

    for (i = 0; i < UNIT_ITEM_COUNT; i++)
    {
        item = unit->items[i];

        if (ITEM_INDEX(item) > 0 && CanUnitUseStaff(item))
            mask |= ItemRangeToMask(item, unit);
    }
    return mask;
}
