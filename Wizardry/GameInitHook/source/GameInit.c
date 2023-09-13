#include "global.h"
#include "gamecontrol.h"
#include "bm.h"
#include "bmio.h"
#include "hardware.h"

#include "debug-kit.h"
#include "combat-art.h"
#include "battle-system.h"

typedef void (* GameInitHookFunc_t)(void);
extern const GameInitHookFunc_t gGameInitHookTable[];

/* LynJump! */
void StartGame(void)
{
    const GameInitHookFunc_t * it;
    struct GameCtrlProc * proc;

    SetMainUpdateRoutine(OnGameLoopMain);

    SetInterrupt_LCDVBlank(OnVBlank);

    proc = Proc_Start(gProcScr_GameControl, PROC_TREE_3);
    proc->nextAction = GAME_ACTION_0;
    proc->nextChapter = 0;
    proc->unk_2B = 0;

    /* Internal hooks */
#if CONFIG_USE_DEBUG
    LogInit();
#endif

    gBattleGlobalFlag = 0;
    ResetCombatArtStatus();

    /* External hooks */
    for (it = gGameInitHookTable; *it; it++)
        (*it)();

    return;
}

void GameInitHookFuncPad(void)
{
    return;
}
