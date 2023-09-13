#include "global.h"
#include "bmunit.h"
#include "bmbattle.h"

#include "common-chax.h"
#include "combat-art.h"

struct CombatArtStatus {
    u8 cid;
    s8 uid;
    bool hitted;
    u8 _pad_[0x10 - 0x3];
};

extern struct CombatArtStatus sCombatArtStatus;

/* Judge is combat-art effective */
u8 GetCombatArtInForce(struct Unit * unit)
{
    if (sCombatArtStatus.uid != unit->index)
        return 0;

    if (!COMBART_VALID(sCombatArtStatus.cid))
        return 0;

    return sCombatArtStatus.cid;
}

void RegisterCombatArtStatus(struct Unit * unit, u8 cid)
{
    sCombatArtStatus.uid = unit->index;
    sCombatArtStatus.cid = cid;
}

void RegisterCombatArtHitted(void)
{
    sCombatArtStatus.hitted = true;
}

bool IsCombatArtHitted(void)
{
    return sCombatArtStatus.hitted;
}

void ResetCombatArtStatus(void)
{
    CpuFastFill16(0, &sCombatArtStatus, sizeof(sCombatArtStatus));
}
