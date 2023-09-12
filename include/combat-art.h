#pragma once

#include "global.h"

struct CombatArtInfo {
    const u8 * icon;
    u16 name, desc;

    /* flags */
    u32 magic_attack : 1;
    u32 effective_armor : 1;
    u32 effective_ride : 1;
    u32 effective_fly : 1;
    u32 effective_dragon : 1;
    u32 effective_monster : 1;
    u32 effective_all : 1;
    u32 doubel_attack : 1;
    u32 debuff_gravity : 1;
    u32 debuff_def : 1;
    u32 debuff_res : 1;
    u32 debuff_weaken : 1;
    u32 aoe_debuff : 1;

    u8 wtype;
    s8 range_bonus;
    s16 cost;
    s16 mt;
    s16 hit;
    s16 avo;
    s16 crit;
};

extern const struct CombatArtInfo gCombatArtInfos[0x100];
