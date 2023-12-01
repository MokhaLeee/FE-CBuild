#include "global.h"
#include "proc.h"
#include "gamecontrol.h"

#include "common-chax.h"

void AutoSkilOpAnim(struct Proc * proc)
{
    SetNextGameActionId(GAME_ACTION_USR_SKIPPED);
    Proc_Goto(proc->proc_parent, 99);
}

/* LynJump */
void GameControl_PostIntro(struct GameCtrlProc * proc)
{
    int tmp;

    switch (proc->nextAction) {
    case GAME_ACTION_USR_SKIPPED:
        Proc_Goto(proc, LGAMECTRL_TITLE_DIRECT);
        break;

    case GAME_ACTION_EVENT_RETURN:
        Proc_Goto(proc, LGAMECTRL_EXEC_SAVEMENU);
        sub_8009AD8(proc);
        break;

    case GAME_ACTION_CLASS_REEL:
        tmp = proc->idle_status;
        switch (tmp & 1) {
        case 0:

/* we need to remove class reel since it may cause crash on none-en langage */
#if !CHAX
            Proc_Goto(proc, LGAMECTRL_CLASS_REEL);
            break;
#endif
        case 1:
            Proc_Goto(proc, LGAMECTRL_OP_ANIM);
            break;
        }

        proc->idle_status++;
        break;

    case GAME_ACTION_PLAYED_THROUGH:
        Proc_Goto(proc, 24);
        break;
    }
}
