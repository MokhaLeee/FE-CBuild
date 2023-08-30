#include "global.h"
#include "bmunit.h"

#include "common-chax.h"
#include "lvup.h"
#include "strmag.h"

int GetUnitHpGrowth(struct Unit * unit)
{
    int status = unit->pCharacterData->growthHP;
    return status;
}

int GetUnitPowGrowth(struct Unit * unit)
{
    int status = unit->pCharacterData->growthPow;
    return status;
}

int GetUnitMagGrowth(struct Unit * unit)
{
    int status = GetUnitBasicMagGrowth(unit);
    return status;
}

int GetUnitSklGrowth(struct Unit * unit)
{
    int status = unit->pCharacterData->growthSkl;
    return status;
}

int GetUnitSpdGrowth(struct Unit * unit)
{
    int status = unit->pCharacterData->growthSpd;
    return status;
}

int GetUnitLckGrowth(struct Unit * unit)
{
    int status = unit->pCharacterData->growthLck;
    return status;
}

int GetUnitDefGrowth(struct Unit * unit)
{
    int status = unit->pCharacterData->growthDef;
    return status;
}

int GetUnitResGrowth(struct Unit * unit)
{
    int status = unit->pCharacterData->growthRes;
    return status;
}
