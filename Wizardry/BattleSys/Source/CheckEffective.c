#include "global.h"
#include "bmunit.h"
#include "bmbattle.h"
#include "bmitem.h"

#include "common-chax.h"
#include "battle-system.h"
#include "skill-system.h"
#include "constants/skills.h"

STATIC_DECLAR bool CheckUnitNullEffective(struct Unit * unit)
{
    int i;
    u32 attributes = 0;

    /* Check item */
    for (i = 0; i < UNIT_ITEM_COUNT; ++i)
        attributes |= GetItemAttributes(unit->items[i]);

    if (attributes & IA_NEGATE_FLYING)
        return true;

    /* Check unit */
    return false;
}

/* LynJump */
bool IsItemEffectiveAgainst(u16 item, struct Unit * unit)
{
    int i, jid;
    const u8 * list;

    if (!unit->pClassData)
        return false;

    jid = UNIT_CLASS_ID(unit);
    list = GetItemEffectiveness(item);

    if (!list)
        return false;

    for (i = 0; list[i]; i++)
        if (list[i] == jid)
            goto check_null_effective;

    return false;

check_null_effective:
    if (CheckUnitNullEffective(unit))
        return false;

    return true;
}

/* LynJump */
bool IsUnitEffectiveAgainst(struct Unit * actor, struct Unit * target)
{
    if (0)
    {
        goto check_null_effective;
    }
    return false;

check_null_effective:
    if (CheckUnitNullEffective(target))
        return false;

    return true;
}
