#include "global.h"
#include "proc.h"
#include "bmtrap.h"

#include "common-chax.h"
#include "battle-system.h"

struct ProcPostAction {
    PROC_HEADER;
    int index;
};

typedef void (* PostActionFunc_t)(struct ProcPostAction * proc);
extern const PostActionFunc_t gPostActionFuncs[];

void PostActionExecHooks(struct ProcPostAction * proc);
void PostActionExecVanilla(struct ProcPostAction * proc);

const struct ProcCmd ProcScr_PostActionHook[] = {
    PROC_YIELD,

PROC_LABEL(1),
    PROC_CALL(PostActionExecHooks),
    PROC_YIELD,
    PROC_GOTO(1),

PROC_LABEL(2),
    PROC_CALL(PostActionExecVanilla),
    PROC_YIELD,
    PROC_END
};

void PostActionHook(ProcPtr parent)
{
    struct ProcPostAction * proc;
    proc = Proc_StartBlocking(ProcScr_PostActionHook, parent);
    proc->index = 0;
}

void PostActionExecHooks(struct ProcPostAction * proc)
{
    PostActionFunc_t it = gPostActionFuncs[proc->index++];

    if (it)
    {
        it(proc);
        return;
    }

    /* Some other proc-free routine */
    gBattleGlobalFlag = 0;

    Proc_Goto(proc, 2);
}

void PostActionExecVanilla(struct ProcPostAction * proc)
{
    /* Vanilla function at the hack entry */
    HandlePostActionTraps(proc);
}

void PostActionPadFunc(struct ProcPostAction * proc)
{
    return;
}

/* CHAX hooks */
const struct ProcCmd ProcScr_PostActionHookPlayPhase[] = {
    PROC_YIELD,
    PROC_CALL(PostActionHook),
    PROC_YIELD,
    PROC_JUMP((const struct ProcCmd *)0x0859ABE8),
    PROC_END
};

const struct ProcCmd ProcScr_PostActionHookCpPerform[] = {
    PROC_YIELD,
    PROC_CALL(PostActionHook),
    PROC_YIELD,
    PROC_JUMP((const struct ProcCmd *)0x085A807C),
    PROC_END
};
