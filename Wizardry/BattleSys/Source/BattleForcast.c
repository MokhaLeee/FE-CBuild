#include "global.h"
#include "bmunit.h"
#include "bmbattle.h"
#include "proc.h"
#include "bmitem.h"
#include "fontgrp.h"
#include "bmlib.h"

#include "common-chax.h"
#include "battle-system.h"

struct BattleForecastProc {
    /* 00 */ PROC_HEADER;

    /* 2C */ int unk_2C;
    /* 30 */ s8 x;
    /* 31 */ s8 y;
    /* 32 */ u8 frameKind;
    /* 33 */ s8 ready;
    /* 34 */ s8 needContentUpdate;
    /* 35 */ s8 side; // -1 is left, +1 is right
    /* 36 */ s8 unk_36;
    /* 38 */ struct Text unitNameTextA;
    /* 40 */ struct Text unitNameTextB;
    /* 48 */ struct Text itemNameText;
    /* 50 */ s8 hitCountA;
    /* 51 */ s8 hitCountB;
    /* 52 */ s8 isEffectiveA;
    /* 53 */ s8 isEffectiveB;
};

extern const u8 Gfx_BKSEL[12][0x80];

/* LynJump */
void BattleForecastHitCountUpdate(struct BattleUnit * bu, s8 * hitsCounter, int * usesCounter)
{
    int i;
    struct BattleUnit * target = (bu == &gBattleActor) ? &gBattleTarget : &gBattleActor;
    int count  = CheckCanTwiceAttackOrder(bu, target) ? GetBattleUnitHitCount(bu) * 2 : GetBattleUnitHitCount(bu);

    for (i = 0; i < count; i++)
    {
        if (*usesCounter <= 0)
            break;

        *hitsCounter = *hitsCounter + 1;
        *usesCounter = *usesCounter - 1;
    }
}

/* LynJump */
void InitBattleForecastBattleStats(struct BattleForecastProc * proc)
{
    int usesA = GetItemUses(gBattleActor.weaponBefore);
    int usesB = GetItemUses(gBattleTarget.weaponBefore);

    proc->hitCountA = 0;
    proc->isEffectiveA = false;

    if ((gBattleActor.weapon != 0) || (gBattleActor.weaponBroke))
    {
        BattleForecastHitCountUpdate(&gBattleActor, &proc->hitCountA, &usesA);

        if (IsUnitEffectiveAgainst(&gBattleActor.unit, &gBattleTarget.unit))
            proc->isEffectiveA = true;

        if (IsItemEffectiveAgainst(gBattleActor.weaponBefore, &gBattleTarget.unit))
            proc->isEffectiveA = true;
    }

    proc->hitCountB = 0;
    proc->isEffectiveB = false;

    if ((gBattleTarget.weapon != 0) || (gBattleTarget.weaponBroke))
    {
        BattleForecastHitCountUpdate(&gBattleTarget, &proc->hitCountB, &usesB);

        if (IsUnitEffectiveAgainst(&gBattleTarget.unit, &gBattleActor.unit))
            proc->isEffectiveB = true;

        if (IsItemEffectiveAgainst(gBattleTarget.weaponBefore, &gBattleActor.unit))
            proc->isEffectiveB = true;
    }

    /* Prepare GFX here */
    switch (proc->hitCountA)
    {
    case 0 ... 9:
        Copy2dChr(Gfx_BKSEL[proc->hitCountA], OBJ_VRAM0 + 0x5D00, 2, 2);
        break;

    default:
        Copy2dChr(Gfx_BKSEL[10], OBJ_VRAM0 + 0x5D00, 2, 2);
        break;
    }

    switch (proc->hitCountB)
    {
    case 0 ... 9:
        Copy2dChr(Gfx_BKSEL[proc->hitCountB], OBJ_VRAM0 + 0x5D40, 2, 2);
        break;

    default:
        Copy2dChr(Gfx_BKSEL[10], OBJ_VRAM0 + 0x5D40, 2, 2);
        break;
    }
}
