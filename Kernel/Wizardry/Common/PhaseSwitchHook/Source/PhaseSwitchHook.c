#include "global.h"
#include "bm.h"

#include "common-chax.h"

extern struct {
    void (*func)(ProcPtr proc);
} gPhaseSwitchHooks[];

void BmMain_StartPhaseRe(ProcPtr proc)
{
    int i;
    for (i = 0; !IS_ROM_THUMB(gPhaseSwitchHooks[i].func); i++)
        gPhaseSwitchHooks[i].func(proc);

    BmMain_StartPhase(proc);
}
