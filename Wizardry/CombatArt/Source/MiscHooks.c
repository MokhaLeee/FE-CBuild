#include "global.h"
#include "bmunit.h"
#include "bmitem.h"
#include "bmbattle.h"

#include "common-chax.h"
#include "combat-art.h"

/* Weapon range getter */
int WeaponRangeGetterCombatArt(int range, struct Unit * unit, u16 item)
{
    u8 cid = GetCombatArtInForce(unit);

    if (COMBART_VALID(cid))
    {
        const struct CombatArtInfo * info = gCombatArtInfos + cid;
        if (GetItemType(item == info->wtype))
            range += info->range_bonus;
    }

    return range;
}
