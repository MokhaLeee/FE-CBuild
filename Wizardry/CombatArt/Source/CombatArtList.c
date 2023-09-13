#include "global.h"
#include "bmunit.h"
#include "bmbattle.h"

#include "common-chax.h"
#include "combat-art.h"
#include "constants/combat-arts.h"

extern struct CombatArtList sCombatArtList;

struct CombatArtList * GetCombatArtList(struct Unit * unit)
{
    if (unit->index != sCombatArtList.uid)
    {
        sCombatArtList.uid = unit->index;

        /* Todo */
        sCombatArtList.amt = 5;
        sCombatArtList.cid[0] = CID_Grounder;
        sCombatArtList.cid[0] = CID_Hexblade;
        sCombatArtList.cid[0] = CID_TempestLance;
        sCombatArtList.cid[0] = CID_FrozenLance;
        sCombatArtList.cid[0] = CID_EncloserPlus;
    }
    return &sCombatArtList;
}

void ResetCombatArtList(void)
{
    CpuFastFill16(0, &sCombatArtList, sizeof(sCombatArtList));
}
