#include "global.h"
#include "fontgrp.h"
#include "bksel.h"
#include "statscreen.h"

#include "common-chax.h"
#include "stat-screen.h"
#include "help-box.h"
#include "battle-system.h"
#include "combat-art.h"
#include "constants/texts.h"

extern DECL_INFO * const RTextCombatBkselStandard, * const RTextCombatBkselExtended;

/* LynJump */
int StartBattleForecastHelpBox(ProcPtr parent)
{
    int x;

    struct BattleForecastProc * proc = Proc_Find(gProcScr_BKSEL);
    if (proc == 0)
        return 0;

    if (proc->needContentUpdate != 0)
        return 0;

    if (proc->side < 0)
        x = 0;
    else
        x = 20;

    LoadHelpBoxGfx(0, -1);

    switch (proc->frameKind) {
    case 1:
        StartMovingHelpBoxExt(RTextCombatBkselStandard, parent, x, 0);
        break;

    case 2:
        StartMovingHelpBoxExt(RTextCombatBkselExtended, parent, x, 0);
        break;
    }
    return 0;
}

void DrawHelpBoxCombatArtBkselLabels(void)
{
    Text_InsertDrawString(&gUnknown_0203E794.text[0], 47, 8, GetStringFromIndex(0x503)); // TODO: msg id "Mt"
    Text_InsertDrawString(&gUnknown_0203E794.text[0], 97, 8, GetStringFromIndex(MSG_COMBATART_BKSEL_HB_Cost));
}

void DrawHelpBoxCombatArtBkselStats(void)
{
    int cid = GetCombatArtInForce(gActiveUnit);
    const struct CombatArtInfo * info = gCombatArtInfos + cid;
    Text_InsertDrawNumberOrBlank(&gUnknown_0203E794.text[0], 129, 7, info->battle_status.atk);
    Text_InsertDrawNumberOrBlank(&gUnknown_0203E794.text[0], 129, 7, info->cost);
}
