
#include "global.h"
#include "bmmap.h"
#include "bmunit.h"
#include "proc.h"
#include "mu.h"

#include "common-chax.h"
#include "status-getter.h"
#include "skill-system.h"
#include "constants/skills.h"

STATIC_DECLAR bool CheckCanto(void)
{
    if (gActiveUnit->state & (US_DEAD | US_HAS_MOVED | US_BIT16))
        return false;

    if (!SkillTester(gActiveUnit, SID_Canto))
        return false;

    switch (gActionData.unitActionType) {
        case UNIT_ACTION_WAIT:

/*
        case UNIT_ACTION_COMBAT:
        case UNIT_ACTION_STAFF:
 */
            return false;
    }

    if (MovGetter(gActiveUnit) <= gActionData.moveCount)
        return false;

    if (!CanUnitMove())
        return false;

    return true;
}

/* LynJump */
bool TryMakeCantoUnit(ProcPtr proc)
{
    if (!CheckCanto())
        return false;

    BmMapFill(gBmMapRange, 0);

    UnitBeginCantoAction(gActiveUnit);

    gActiveUnit->state |= US_HAS_MOVED;
    gActiveUnit->state &= ~US_UNSELECTABLE;

    MU_EndAll();
    MU_Create(gActiveUnit);
    MU_SetDefaultFacing_Auto();

    if (gPlaySt.chapterVisionRange != 0)
        Proc_Goto(proc, 4);
    else
        Proc_Goto(proc, 1);

    return true;
}
