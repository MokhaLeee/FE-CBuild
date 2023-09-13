#include "global.h"
#include "bmunit.h"
#include "bmitem.h"
#include "bmbattle.h"

#include "common-chax.h"
#include "combat-art.h"

bool CanUnitPlayCombatArt(struct Unit * unit, u16 item)
{
    int i, wtype = GetItemType(item);
    struct CombatArtList * list = GetCombatArtList(unit);

    for (i = 0; i < list->amt; i++)
        if (gCombatArtInfos[list->cid[i]].wtype == wtype)
            return true;

    return false;
}

/* Weapon range getter */
int WeaponRangeGetterCombatArt(int range, struct Unit * unit, u16 item)
{
    u8 cid = GetCombatArtInForce(unit);

    if (COMBART_VALID(cid))
    {
        const struct CombatArtInfo * info = gCombatArtInfos + cid;
        if (GetItemType(item) == info->wtype)
            range += info->range_bonus;
    }
    return range;
}
