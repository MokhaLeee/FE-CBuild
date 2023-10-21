#include "global.h"
#include "proc.h"
#include "hardware.h"
#include "opanim.h"
#include "gamecontrol.h"

#include "common-chax.h"

/* LynJump! */
void OpAnimfxTerminatorMain(struct Proc * proc)
{
    if (gKeyStatusPtr->newKeys & (A_BUTTON | B_BUTTON | START_BUTTON))
    {
#if CHAX_IDENTIFIER
        SetNextGameActionId(GAME_ACTION_PLAYED_THROUGH);
#else
        SetNextGameActionId(GAME_ACTION_USR_SKIPPED);
#endif
        gOpAnimSt.pal = 0;
        Proc_Goto(proc->proc_parent, 99);
    }
}
