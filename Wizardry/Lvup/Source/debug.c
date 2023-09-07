#include "global.h"
#include "bmunit.h"
#include "bmbattle.h"

#include "common-chax.h"

#if CONFIG_USE_DEBUG
int GetBattleUnitExpGain(struct BattleUnit * actor, struct BattleUnit * target)
{
    if (!CanBattleUnitGainLevels(actor))
        return 0;

    return 100;
}
#endif
