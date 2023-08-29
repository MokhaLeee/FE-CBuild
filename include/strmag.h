#pragma once

#include "global.h"
#include "bmunit.h"
#include "bmitem.h"
#include "bmbattle.h"

static inline bool IsMagicAttack(struct BattleUnit * bu)
{
    u32 attr = bu->weaponAttributes;
    if (IA_MAGICDAMAGE & attr)
        return true;

    if (IA_MAGIC & attr)
        return true;

    return false;
}
