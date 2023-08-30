#pragma once

#include "global.h"
#include "bmunit.h"
#include "bmitem.h"
#include "bmbattle.h"

#include "common-chax.h"
#include "status-getter.h"

#define UNIT_MAG(unit) ((unit)->_u3A)
#define BU_CHG_MAG(bu) (*((u8 *)(bu) + 0x7F))

static inline bool IsMagicAttack(struct BattleUnit * bu)
{
    return !!((IA_MAGICDAMAGE | IA_MAGIC) & bu->weaponAttributes);
}

static inline int GetUnitMaxMagic(struct Unit * unit)
{
    return 30;
}

static inline int GetUnitBasicMagGrowth(struct Unit * unit)
{
    return 50;
}

static inline int GetUnitMagic(struct Unit * unit)
{
    return MagGetter(unit);
}
