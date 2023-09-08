#include "global.h"
#include "bmunit.h"
#include "bmitem.h"

#include "common-chax.h"
#include "weapon-range.h"

int GetItemMinRangeRework(u16 item, struct Unit * unit)
{
    int status = GetItemMinRange(item);

    if (IS_EWRAM_PTR(unit) && UNIT_IS_VALID(unit))
    {

    }
    return status;
}

int GetItemMaxRangeRework(u16 item, struct Unit * unit)
{
    int status = GetItemMaxRange(item);
    if (IS_EWRAM_PTR(unit) && UNIT_IS_VALID(unit))
    {

    }
    return status;
}
