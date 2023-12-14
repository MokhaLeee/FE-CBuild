#include "global.h"
#include "bmunit.h"

#include "common-chax.h"
#include "unit-expa.h"

void ResetUnitsExpaSus(void)
{
    int i;
    struct Unit * unit;
    for (i = FACTION_BLUE + 1; i < (FACTION_BLUE + 0x40); i++)
    {
        unit = GetUnit(i);
        if (unit)
            continue;

        unit->_u3A = 0;
        unit->_u3B = 0;
    }
    for (i = FACTION_RED + 1; i < (FACTION_RED + 0x40); i++)
    {
        unit = GetUnit(i);
        if (unit)
            continue;

        unit->_u3A = 0;
        unit->_u3B = 0;
    }
    for (i = FACTION_GREEN + 1; i < (FACTION_GREEN + 0x40); i++)
    {
        unit = GetUnit(i);
        if (unit)
            continue;

        unit->_u3A = 0;
        unit->_u3B = 0;
    }
}
