#include "global.h"
#include "bmunit.h"
#include "bmitem.h"
#include "proc.h"
#include "bm.h"
#include "bmtarget.h"
#include "uiselecttarget.h"
#include "bmmap.h"
#include "hardware.h"
#include "soundwrapper.h"
#include "bmio.h"
#include "uiutils.h"
#include "uimenu.h"
#include "bmidoten.h"
#include "face.h"
#include "playerphase.h"

#include "common-chax.h"
#include "weapon-range.h"
#include "combat-art.h"

extern const struct SelectInfo gSelectInfo_0859D3F8;

extern int sSelectedComatArtIndex;

STATIC_DECLAR int GetNextCombatArtIndex(struct Unit * unit, int old, int direction)
{
    struct CombatArtList * list = GetCombatArtList(unit);
    int wtype = gCombatArtInfos[list->cid[old]].wtype;
    int new;

    if (direction == POS_L)
    {
        /* Left */
        for (new = old - 1; new != old; new--)
        {
            if (new < 0)
                new = list->amt - 1;

            if (wtype == gCombatArtInfos[list->cid[new]].wtype)
                break;
        }
        return new;
    }
    else
    {
        /* Right */
        for (new = old + 1; new != old; new++)
        {
            if (new >= list->amt)
                new = 0;

            if (wtype == gCombatArtInfos[list->cid[new]].wtype)
                break;
        }
        return new;
    }
}

STATIC_DECLAR bool TargetSelectionRework_HandleCombatArt(struct SelectTargetProc * proc)
{
    int i, new;
    s8 uid_pre;
    u16 repeated;
    struct SelectTarget * it, * cur = proc->currentTarget;
    struct Unit * unit = gActiveUnit;
    u16 weapon = unit->items[0];
    struct CombatArtList * calist = GetCombatArtList(unit);

    /* We directly judge the first item! */
    if (!CanUnitPlayCombatArt(unit, weapon))
        return false;

    repeated = gKeyStatusPtr->repeatedKeys;

    if (DPAD_LEFT & repeated)
    {
        new = GetNextCombatArtIndex(unit, sSelectedComatArtIndex, POS_L);
        while (new != sSelectedComatArtIndex)
        {
            RegisterCombatArtStatus(unit, calist->cid[new]);

            if (IsItemCoveringRangeRework(weapon, RECT_DISTANCE(unit->xPos, unit->yPos, cur->x, cur->y), unit))
                goto update_combat_art;

            new = GetNextCombatArtIndex(unit, sSelectedComatArtIndex, POS_L);
        }
    }
    else
    {
        new = GetNextCombatArtIndex(unit, sSelectedComatArtIndex, POS_R);
        while (new != sSelectedComatArtIndex)
        {
            RegisterCombatArtStatus(unit, calist->cid[new]);

            if (IsItemCoveringRangeRework(weapon, RECT_DISTANCE(unit->xPos, unit->yPos, cur->x, cur->y), unit))
                goto update_combat_art;

            new = GetNextCombatArtIndex(unit, sSelectedComatArtIndex, POS_R);
        }
    }
    /* We did not find new art, register vanilla */
    RegisterCombatArtStatus(unit, calist->cid[sSelectedComatArtIndex]);
    return false;

update_combat_art:
    sSelectedComatArtIndex = new;

    BmMapFill(gBmMapMovement, -1);
    BmMapFill(gBmMapRange, 0);
    GenerateUnitStandingReachRange(unit, GetUnitWeaponReachBits(unit, 0));
    DisplayMoveRangeGraphics(MOVLIMITV_RMAP_RED);

    uid_pre = proc->currentTarget->uid;
    MakeTargetListForWeapon(unit, weapon);

    /**
     * Here we assume MakeTargetListForWeapon() must result equals to (IsItemCoveringRange() && CanUnitUseWeapon()) 
     */
    for (it = GetLinkedTargets(), i = 0; i < GetSelectTargetCount(); i++, it = it->next)
    {
        if (uid_pre == it->uid)
        {
            proc->currentTarget = it;
            break;
        }
    }

    if (proc->selectRoutines->onSwitchOut)
        proc->selectRoutines->onSwitchOut(proc, it);

    if (proc->selectRoutines->onSwitchIn)
        proc->selectRoutines->onSwitchIn(proc, it);

    PlaySoundEffect(0x67);
    return true;
}

STATIC_DECLAR void TargetSelectionRework_HandleMoveInput(struct SelectTargetProc * proc)
{
    struct SelectTarget * current = proc->currentTarget;

    if (TargetSelectionRework_HandleCombatArt(proc))
        return;

    if ((DPAD_LEFT | DPAD_UP) & gKeyStatusPtr->repeatedKeys)
        if (current->next != 0)
            proc->currentTarget = current->next;

    if ((DPAD_RIGHT | DPAD_DOWN) & gKeyStatusPtr->repeatedKeys)
        if (proc->currentTarget->prev)
            proc->currentTarget = proc->currentTarget->prev;

    if (proc->currentTarget == current)
        return;

    if (proc->selectRoutines->onSwitchOut)
        proc->selectRoutines->onSwitchOut(proc, current);

    if (proc->selectRoutines->onSwitchIn)
        proc->selectRoutines->onSwitchIn(proc, proc->currentTarget);

    PlaySoundEffect(0x67);
}

STATIC_DECLAR void TargetSelectionRework_Loop(struct SelectTargetProc * proc)
{
    int x, y;
    int action;

    if ((TARGETSELECTION_FLAG_FROZEN & proc->flags) != 0) {
        TargetSelection_GetRealCursorPosition(proc, &x, &y);
        PutMapCursor(x, y, 4);
        return;
    }

    TargetSelectionRework_HandleMoveInput(proc);

    action = TargetSelection_HandleSelectInput(proc);

    if ((TARGETSELECTION_ACTION_END & action) != 0)
        EndTargetSelection(proc);

    if ((TARGETSELECTION_ACTION_SE_6A & action) != 0)
        PlaySoundEffect(0x6A);

    if ((TARGETSELECTION_ACTION_SE_6B & action) != 0)
        PlaySoundEffect(0x6B);

    if ((TARGETSELECTION_ACTION_CLEARBGS & action) != 0)
        ClearBg0Bg1();

    if ((TARGETSELECTION_ACTION_ENDFACE & action) != 0)
        EndFaceById(0);

    if ((TARGETSELECTION_ACTION_ENDFAST & action) == 0) {
        TargetSelection_GetRealCursorPosition(proc, &x, &y);

        if (EnsureCameraOntoPosition(proc, x >> 4, y >> 4) != 1)
            PutMapCursor(x, y, 2);
    }
}

STATIC_DECLAR const struct ProcCmd ProcScr_TargetSelectionRework[] = {
PROC_LABEL(0),
    PROC_REPEAT(TargetSelectionRework_Loop),
    PROC_SLEEP(1),

    PROC_CALL(RefreshBMapGraphics),
    PROC_GOTO(0),

    PROC_END,
};

STATIC_DECLAR ProcPtr NewTargetSelectionRework(const struct SelectInfo * selectInfo)
{
    struct SelectTargetProc * proc;

    LockGame();
    proc = Proc_Start(ProcScr_TargetSelectionRework, PROC_TREE_3);

    sSelectedComatArtIndex = 0;

    proc->flags = TARGETSELECTION_FLAG_GAMELOCK;
    proc->selectRoutines = selectInfo;
    proc->currentTarget = GetLinkedTargets();
    proc->onAPress = 0;

    if (proc->selectRoutines->onInit)
        proc->selectRoutines->onInit(proc);

    if (proc->selectRoutines->onUnk08)
        proc->selectRoutines->onUnk08(proc);

    if (proc->selectRoutines->onSwitchIn)
        proc->selectRoutines->onSwitchIn(proc, proc->currentTarget);

    gKeyStatusPtr->newKeys = 0;

    return proc;
}

/* LynJump */
u8 UnknownMenu_Selected(struct MenuProc * menu, struct MenuItemProc * menuItem)
{
    EquipUnitItemSlot(gActiveUnit, menuItem->itemNumber);
    gActionData.itemSlotIndex = 0;

    ClearBg0Bg1();
    MakeTargetListForWeapon(gActiveUnit, gActiveUnit->items[0]);
    NewTargetSelectionRework(&gSelectInfo_0859D3F8);
    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SND6A | MENU_ACT_ENDFACE;
}
