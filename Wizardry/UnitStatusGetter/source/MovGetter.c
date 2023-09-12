#include "global.h"
#include "bmunit.h"
#include "bmitem.h"

#include "common-chax.h"
#include "skill-system.h"
#include "status-getter.h"
#include "debuff.h"
#include "constants/skills.h"

int _GetUnitMov(struct Unit * unit)
{
    const StatusGetterFunc_t * it;
    int status = unit->lck;

    for (it = gMovGetters; *it; it++)
        status = (*it)(status, unit);

    /* Some special effects */
    if (gDebuffInfos[GetUnitStatusIndex(unit)].cannot_move)
        status = 0;

    return status;
}
