#include "global.h"
#include "bm.h"

#include "common-chax.h"
#include "rn.h"

typedef void (* ChapterInitHookFunc)(ProcPtr);

ChapterInitHookFunc const ChapterInitHooks[] = {
    (ChapterInitHookFunc)InitRandC,
    NULL,
};

void ChapterInitHook(ProcPtr proc)
{
    int i;
    for (i = 0; ChapterInitHooks[i]; i++)
        ChapterInitHooks[i](proc);

    /* Vanilla */
    BmMain_StartIntroFx(proc);
}
