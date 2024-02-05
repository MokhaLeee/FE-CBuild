#include "global.h"

#include "common-chax.h"
#include "battle-system.h"

void ClearBattleGlobalFlags(void)
{
    CpuFastFill16(0, &gBattleActorGlobalFlag, sizeof(gBattleActorGlobalFlag));
    CpuFastFill16(0, &gBattleTargetGlobalFlag, sizeof(gBattleTargetGlobalFlag));
}
