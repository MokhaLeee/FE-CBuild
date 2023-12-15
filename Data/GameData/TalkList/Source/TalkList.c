#include "global.h"
#include "eventinfo.h"
#include "constants/event-flags.h"

#include "common-chax.h"
#include "constants/texts.h"
#include "constants/chax-characters.h"
#include "constants/chax-chapters.h"

const struct BattleTalkExtEnt gBattleTalkListRe[] = {
    {
        .pidA = 0,
        .pidB = CHAR_CHAX_PrologueBoss,
        .chapter = ChPrologue,
        .flag = EVFLAG_BATTLE_QUOTES,
        .msg = MSG_EvtCh0_BoosQuote
    },
    {
        .pidA = CHAR_CHAX_PrologueBoss,
        .pidB = 0,
        .chapter = ChPrologue,
        .flag = EVFLAG_BATTLE_QUOTES,
        .msg = MSG_EvtCh0_BoosQuote
    },
    { .pidA = -1 }
};

const struct DefeatTalkEnt gDefeatTalkListRe[] = {
    {
        .pid = CHAR_CHAX_PrologueBoss,
        .route = 0xFF,
        .chapter = ChPrologue,
        .flag = EVFLAG_DEFEAT_BOSS,
        .msg = MSG_EvtCh0_BoosDefeat
    },
    { .pid = -1 },
};
