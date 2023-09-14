#include "global.h"
#include "bmunit.h"
#include "proc.h"
#include "bmmap.h"
#include "uiselecttarget.h"
#include "bmtarget.h"
#include "bmidoten.h"

#include "common-chax.h"
#include "combat-art.h"
#include "debuff.h"
#include "map-anims.h"

void ForEachUnitInRange(void(* func)(struct Unit * unit));
void AddUnitToTargetListIfNotAllied(struct Unit * unit);

STATIC_DECLAR void ExecCombatArtEffectAnim(ProcPtr proc)
{
    int i;
    struct Unit * unit = gActiveUnit;
    struct Unit * target = GetUnit(gActionData.targetIndex);
    u8 cid = GetCombatArtInForce(unit);
    const struct CombatArtInfo * info;

    if (!COMBART_VALID(cid) || !IsCombatArtHitted() || !UNIT_IS_VALID(target))
    {
        Proc_End(proc);
        return;
    }

    info = gCombatArtInfos + cid;

    if (!info->debuff_gravity &&
        !info->debuff_def &&
        !info->debuff_res &&
        !info->debuff_weaken)
    {
        Proc_End(proc);
        return;
    }

    BmMapFill(gBmMapMovement, -1);
    BmMapFill(gBmMapRange, 0);

    if (info->aoe_debuff)
        GenerateUnitStandingReachRange(target, 0b11);
    else
        GenerateUnitStandingReachRange(target, 0b01);

    InitTargets(unit->xPos, unit->yPos);
    ForEachUnitInRange(AddUnitToTargetListIfNotAllied);

    for (i = 0; i < GetSelectTargetCount(); i++)
    {
        struct SelectTarget * starget = GetTarget(i);
        struct Unit * tunit = GetUnit(starget->uid);
        CallMapAnim_HeavyGravity(proc, starget->x, starget->y);

        if (info->double_attack)
            SetUnitStatusExt(tunit, NEW_UNIT_STATUS_WEAKEN, 1);
        else if (info->debuff_gravity)
            SetUnitStatusExt(tunit, NEW_UNIT_STATUS_HEAVY_GRAVITY, 1);
        else if (info->debuff_def)
            SetUnitStatusExt(tunit, NEW_UNIT_STATUS_PIERCE_ARMOR, 1);
        else if (info->debuff_res)
            SetUnitStatusExt(tunit, NEW_UNIT_STATUS_PIERCE_MAGIC, 1);
        else if (info->debuff_weaken)
            SetUnitStatusExt(tunit, NEW_UNIT_STATUS_WEAKEN, 1);
    }
}

STATIC_DECLAR const struct ProcCmd ProcScr_CombatArtPostActionEffect[] = {
    PROC_NAME("CombatArtPostActionEffect"),
    PROC_YIELD,
    PROC_CALL(ExecCombatArtEffectAnim),
    PROC_WHILE(MapAnimHeavyGravityExists),
    PROC_END
};

void PostActionCombatArtEffect(ProcPtr parent)
{
    Proc_StartBlocking(ProcScr_CombatArtPostActionEffect, parent);
}
