#include "global.h"
#include "bmunit.h"
#include "bmitem.h"

#include "constants/characters.h"
#include "constants/items.h"

#include "debug-kit.h"

/* LynJump! */
int GetUnitDefense(struct Unit * unit)
{
    u16 weapon = GetUnitEquippedWeapon(unit);
    int status = unit->def;
    status += GetItemDefBonus(weapon);

    LogPrintf("%s: Unit got def +1 bonus!", __func__);
    status += 1;

    if (UNIT_CHAR_ID(unit) == CHARACTER_EIRIKA)
    {
        LogPrintf("%s: Eirika got def +1 bonus!", __func__);
        status += 1;
    }

    if (ITEM_INDEX(weapon) == ITEM_SWORD_RAPIER)
    {
        LogPrintf("%s: Rapier got def +1 bonus!", __func__);
        status += 1;
    }

    return status;
}
