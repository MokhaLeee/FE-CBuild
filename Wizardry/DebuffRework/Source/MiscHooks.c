#include "global.h"
#include "bmunit.h"
#include "fontgrp.h"
#include "statscreen.h"

#include "common-chax.h"
#include "debuff.h"

/* LynJump */
void SetUnitStatus(struct Unit * unit, int status)
{
    if (status == 0 || status >= NEW_UNIT_STATUS_MAX)
    {
        Errorf("Status error: %d", status);

        SetUnitStatusIndex(unit, 0);
        SetUnitStatusDuration(unit, 0);
    }
    else
    {
        int duration = gDebuffInfos[status].duration;
        if (duration == 0)
            duration = 3;

        SetUnitStatusIndex(unit, status);
        SetUnitStatusDuration(unit, duration);
    }
}

/* LynJump */
void SetUnitStatusExt(struct Unit * unit, int status, int duration)
{
    if (status >= NEW_UNIT_STATUS_MAX)
    {
        Errorf("Status overflow: %d", status);
        return;
    }

    if (duration == 0)
        duration = 3;

    SetUnitStatusIndex(unit, status);
    SetUnitStatusDuration(unit, duration);
}

/* LynJump */
char * GetUnitStatusName(struct Unit * unit)
{
    int msg = gDebuffInfos[GetUnitStatusIndex(unit)].name;

    if (msg == 0)
        msg = 0x52B; /* --[X] */

    return GetStringFromIndex(msg);
}

/* LynJump */
char * GetUnitRescueName(struct Unit * unit)
{
    if (!unit->rescue)
        return GetStringFromIndex(gDebuffInfos[MEW_UNIT_STATUS_NONE].name);

    return GetStringFromIndex(GetUnit(unit->rescue)->pCharacterData->nameTextId);
}

/* LynJump */
void HbPopulate_SSStatus(struct HelpBoxProc * proc)
{
	u8 index = GetUnitStatusIndex(gStatScreen.unit);
	proc->mid = gDebuffInfos[index].desc;
}
