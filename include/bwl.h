#pragma once

#include "global.h"
#include "bmsave.h"
#include "bmunit.h"
#include "bmreliance.h"

#define NEW_BWL_ARRAY_NUM BWL_ARRAY_NUM

struct NewBwl {
    /* vanilla */
    u32 battleAmt : 12;
    u32 winAmt    : 12;
    u32 lossAmt   : 8;

    /* bwl support */
    u8 supports[UNIT_SUPPORT_MAX_COUNT];

    u8 _pad_[0x10 - 0x0B];

} BITPACKED;

static inline bool CheckHasBwl(u8 pid)
{
    if (pid >= NEW_BWL_ARRAY_NUM)
        return false;

    if (GetCharacterData(pid)->affinity == 0)
        return false;

    return true;
}

static inline struct NewBwl * GetNewBwl(u8 pid)
{
    struct NewBwl * entry = (struct NewBwl *)gPidStatsData;
    if (!CheckHasBwl(pid))
        return NULL;

    return entry + (pid - 1);
}
