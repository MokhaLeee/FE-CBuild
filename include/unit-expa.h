#pragma once

#include "global.h"
#include "bmunit.h"

/**
 * We use unit->_u3A and unit->_u3B
 * These 16 bits is saved in suspand data
 */

enum unit_expa_sus_bitfile_idx {
    UNIT_EXPA_SUS_BIT_LEGENDARY_SKILL_USED,
    UNIT_EXPA_SUS_BIT_LEGENDARY_SKILL_ACTIVE,
    UNIT_EXPA_SUS_BIT2,
    UNIT_EXPA_SUS_BIT3,
    UNIT_EXPA_SUS_BIT4,
    UNIT_EXPA_SUS_BIT5,
    UNIT_EXPA_SUS_BIT6,
    UNIT_EXPA_SUS_BIT7,
    UNIT_EXPA_SUS_BIT8,
    UNIT_EXPA_SUS_BIT9,
    UNIT_EXPA_SUS_BIT10,
    UNIT_EXPA_SUS_BIT11,
    UNIT_EXPA_SUS_BIT12,
    UNIT_EXPA_SUS_BIT13,
    UNIT_EXPA_SUS_BIT14,
    UNIT_EXPA_SUS_BIT15,

    UNIT_EXPA_SUS_BIT_MAX
};

void ResetUnitsExpaSus(void);

static inline void SetBit_UnitExpaSus(struct Unit * unit, int bit)
{
    if (bit < 8)
        unit->_u3A |= 1 << bit;

    if (bit < 16)
        unit->_u3B |= 1 << bit;
}

static inline void ClearBit_UnitExpaSus(struct Unit * unit, int bit)
{
    if (bit < 8)
        unit->_u3A &= ~(1 << bit);

    if (bit < 16)
        unit->_u3B &= ~(1 << bit);
}

static inline bool CheckBit_UnitExpaSus(struct Unit * unit, int bit)
{
    if (bit < 8)
        return !!(unit->_u3A & (1 << bit));

    if (bit < 16)
        return !!(unit->_u3B & (1 << bit));

    return false;
}
