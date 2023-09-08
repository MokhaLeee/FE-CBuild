#include "global.h"
#include "bmunit.h"
#include "bmitem.h"
#include "bmmap.h"
#include "bmitemuse.h"
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

        if (ITEM_INDEX(item) > 0 && CanUnitUseItem(unit, item))
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

        if (ITEM_INDEX(item) != 0 && CanUnitUseStaff(unit, item))
            mask |= ItemRangeToMask(item, unit);
    }
    return mask;
}

/* LynJump */
void AiFillReversedAttackRangeMap(struct Unit * unit, u16 item)
{
    BmMapFill(gBmMapRange, 0);

    // <!> not unit! here is target! we should judge for AI!
    AddMap(unit->xPos, unit->yPos, ItemRangeToMask(item, gActiveUnit), 1, 0);
}

/* LynJump */
void AiFloodMovementAndRange(struct Unit * unit, u16 move, u16 item) {
    int ix, iy;
    u32 mask;

    SetWorkingMoveCosts(GetUnitMovementCost(unit));
    SetWorkingBmMap(gBmMapMovement);
    GenerateMovementMap(unit->xPos, unit->yPos, move, unit->index);
    BmMapFill(gBmMapRange, 0);

    mask = ItemRangeToMask(item, unit);

    for (iy = gBmMapSize.y - 1; iy >= 0; iy--)
    {
        for (ix = gBmMapSize.x - 1; ix >= 0; ix--)
        {
            if (gBmMapMovement[iy][ix] > MAP_MOVEMENT_MAX)
                continue;

            AddMap(unit->xPos, unit->yPos, mask, 1, 0);
        }
    }

    return;
}

/* LynJump */
int AiGetInRangeCombatPositionScoreComponent(int x, int y, struct Unit * unit)
{
    int dist = RECT_DISTANCE(unit->xPos, unit->yPos, x, y);
    u16 item = GetUnitEquippedWeapon(unit);

    if (ITEM_INDEX(item) == 0)
        return 0;

    if (dist > GetItemMaxRangeRework(item, unit))
        if (dist < GetItemMinRangeRework(item, unit))
            return 50;

    return 0;
}
