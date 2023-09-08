#include "global.h"
#include "bmitem.h"
#include "bmunit.h"
#include "statscreen.h"

#include "common-chax.h"
#include "weapon-range.h"

extern struct MsgBuffer sMsgString;

/* 996 ---> 9 9 6 */
STATIC_DECLAR void SplitNumberDec3(int in, u8 out[])
{
    out[0] = Div(in, 100);
    out[1] = Div(in - out[0] * 100, 10);
    out[2] = in - out[0] * 100 - out[1] * 10;
}

STATIC_DECLAR char * ItemRangeToString(int min, int max)
{
    int i, count = 0;
    u8 min_splited[3], max_splited[3];

    if (max == 0)
        return GetStringFromIndex(0x522); /* Mag / 2[X] */

    if (min > max || min < 0 || max < 0)
        return GetStringFromIndex(0x52B); /* "--\0" */

    SplitNumberDec3(min, min_splited);
    SplitNumberDec3(max, max_splited);

    for (i = 0; i < 3; i++)
        if (min_splited[i] != 0)
            break;

    for (; i < 3; i++)
        sMsgString.buffer1[count++] = '0' + min_splited[i];

    if (max > min)
    {
        sMsgString.buffer1[count++] = '-';

        for (i = 0; i < 3; i++)
            if (max_splited[i] != 0)
                break;

        for (; i < 3; i++)
            sMsgString.buffer1[count++] = '0' + max_splited[i];
    }

    sMsgString.buffer1[count] = '\0';
    return (char *)sMsgString.buffer1;
}

/* LynJump */
char * GetItemDisplayRangeString(int item)
{
    if ((ITEM_INDEX(item) == 0))
        return GetStringFromIndex(0x52B); /* "--\0" */

    int min = GetItemMinRange(item);
    int max = GetItemMaxRange(item);

    return ItemRangeToString(min, max);
}

const char * GetUnitDisplayRangeString(struct Unit * unit)
{
    u16 item;
    int min, max;

    if (!IS_UNIT_PTR(unit))
    {
        unit = gStatScreen.unit;
        if (!UNIT_IS_VALID(unit))
            return GetStringFromIndex(0x52B); /* "--\0" */
    }

    item = GetUnitEquippedWeaponSlot(unit);
    if ((ITEM_INDEX(item) == 0))
        return GetStringFromIndex(0x52B); /* "--\0" */

    min = GetItemMinRangeRework(item, unit);
    max = GetItemMaxRangeRework(item, unit);

    return ItemRangeToString(min, max);
}
