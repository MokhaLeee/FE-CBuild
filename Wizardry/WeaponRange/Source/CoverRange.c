#include "global.h"
#include "bmunit.h"
#include "bmitem.h"

#include "common-chax.h"
#include "status-getter.h"
#include "weapon-range.h"

/* LynJump */
bool IsItemCoveringRangeRework(int item, int range, struct Unit * unit)
{
    int min = GetItemMinRangeRework(item, unit);
    int max = GetItemMaxRangeRework(item, unit);

    if ((min <= range) && (range <= max))
        return true;

    return false;
}

/* LynJump */
bool AiReachesByBirdsEyeDistance(struct Unit * unit, struct Unit * other, u16 item)
{
    int distance = RECT_DISTANCE(unit->xPos, unit->yPos, other->xPos, other->yPos);
    if (distance <= MovGetter(unit) + GetItemMaxRangeRework(item, unit))
        return true;

    return false;
}
