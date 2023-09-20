#include "global.h"
#include "bmunit.h"

#include "common-chax.h"
#include "lvup.h"
#include "skill-system.h"
#include "strmag.h"
#include "constants/skills.h"

STATIC_DECLAR int GetUnitCommonGrowthBonus(int status, struct Unit * unit)
{
    int new = status;

    if (SkillTester(unit, SID_Blossom))
        new = new + status * 2;

    if (SkillTester(unit, SID_Aptitude))
        new = new + Div(status * 2, 10);

    return new;
}

int GetUnitHpGrowth(struct Unit * unit)
{
    int status = unit->pCharacterData->growthHP;
    status = status + GetUnitCommonGrowthBonus(status, unit);
    return status;
}

int GetUnitPowGrowth(struct Unit * unit)
{
    int status = unit->pCharacterData->growthPow;
    status = status + GetUnitCommonGrowthBonus(status, unit);
    return status;
}

int GetUnitMagGrowth(struct Unit * unit)
{
    int status = GetUnitBasicMagGrowth(unit);
    status = status + GetUnitCommonGrowthBonus(status, unit);
    return status;
}

int GetUnitSklGrowth(struct Unit * unit)
{
    int status = unit->pCharacterData->growthSkl;
    status = status + GetUnitCommonGrowthBonus(status, unit);
    return status;
}

int GetUnitSpdGrowth(struct Unit * unit)
{
    int status = unit->pCharacterData->growthSpd;
    status = status + GetUnitCommonGrowthBonus(status, unit);
    return status;
}

int GetUnitLckGrowth(struct Unit * unit)
{
    int status = unit->pCharacterData->growthLck;
    status = status + GetUnitCommonGrowthBonus(status, unit);
    return status;
}

int GetUnitDefGrowth(struct Unit * unit)
{
    int status = unit->pCharacterData->growthDef;
    status = status + GetUnitCommonGrowthBonus(status, unit);
    return status;
}

int GetUnitResGrowth(struct Unit * unit)
{
    int status = unit->pCharacterData->growthRes;
    status = status + GetUnitCommonGrowthBonus(status, unit);
    return status;
}
