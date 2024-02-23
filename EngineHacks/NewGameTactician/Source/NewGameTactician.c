#include "global.h"
#include "bmlib.h"
#include "gamecontrol.h"

#include "common-chax.h"

void StartTacticianNameSelect(ProcPtr);

static void TacticianPreload(void)
{
    CopyString(gPlaySt.playerName, "Mokha\0");
}

/* LynJump */
void GameCtrlStartIntroMonologue(struct GameCtrlProc * proc)
{
    if (gPlaySt.chapterStateBits & PLAY_FLAG_POSTGAME)
        return;

    if (gPlaySt.chapterIndex != 0)
        return;

#if !CHAX
    StartIntroMonologue(proc);
#else
    TacticianPreload();
    StartTacticianNameSelect(proc);
#endif
}
