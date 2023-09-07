#include "global.h"
#include "bmunit.h"
#include "bmitem.h"
#include "bmmap.h"
#include "bmidoten.h"

#include "common-chax.h"
#include "status-getter.h"
#include "weapon-range.h"

u32 ItemRangeToMask(u16 item, struct Unit * unit)
{
    int i;
    u32 mask = 0;

    int min = GetItemMinRangeRework(item, unit);
    int max = GetItemMaxRangeRework(item, unit);

    for (i = 0; i < 32; i++)
        if (i >= min && i < max)
            mask |= 1 << i;
}

void AddMap(int x, int y, u32 mask, int on, int off)
{
    int ix, iy;

    for (iy = 0; iy < gBmMapSize.y; iy++)
    {
        for (ix = 0; ix < gBmMapSize.x; ix++)
        {
            int distance = RECT_DISTANCE(x, y, ix, iy);
            if (mask & (1 << distance))
                gWorkingBmMap[iy][ix] += on;
            else
                gWorkingBmMap[iy][ix] += off;
        }
    }
}

void ForEachUnit(void (*func)(struct Unit *), u8 ** map, const int off)
{
    int x, y;

    if (gBmMapSize.x < 0 || gBmMapSize.y < 0)
        return;

    for (y = 0; y < gBmMapSize.y; y++)
    {
        for (x = 0; x < gBmMapSize.x; x++)
        {
            if (off == map[y][x])
                continue;

            if (gBmMapUnit[y][x] != 0)
                func(GetUnit(gBmMapUnit[y][x]));
        }
    }
}
