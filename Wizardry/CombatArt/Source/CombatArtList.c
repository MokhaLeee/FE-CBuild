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
        sCombatArtList.cid[1] = CID_Hexblade;
        sCombatArtList.cid[2] = CID_TempestLance;
        sCombatArtList.cid[3] = CID_FrozenLance;
        sCombatArtList.cid[4] = CID_EncloserPlus;
    }
    return &sCombatArtList;
}

void ResetCombatArtList(void)
{
    CpuFastFill16(0, &sCombatArtList, sizeof(sCombatArtList));
}
