#pragma once

#include "global.h"

#define COMBART_VALID(cid) (((cid) > 0) && ((cid) < 0xFF))

struct CombatArtInfo {
    const u8 * icon;
    u16 name, desc;

    u8 wtype;
    s8 range_bonus;
    s16 cost;

    struct {
        s8 atk, def, hit, avo, crit, silencer, dodge;
    } battle_status;

    /* flags */
    u32 external_calc : 1;
    u32 magic_attack : 1;
    u32 effective_armor : 1;
    u32 effective_ride : 1;
    u32 effective_fly : 1;
    u32 effective_dragon : 1;
    u32 effective_monster : 1;
    u32 effective_all : 1;
    u32 double_attack : 1;
    u32 debuff_gravity : 1;
    u32 debuff_def : 1;
    u32 debuff_res : 1;
    u32 debuff_weaken : 1;
    u32 aoe_debuff : 1;
};

extern const struct CombatArtInfo gCombatArtInfos[0x100];

static inline u16 GetCombatArtName(u8 cid)
{
    return gCombatArtInfos[cid].name;
}

static inline u16 GetCombatArtDesc(u8 cid)
{
    if (0 == gCombatArtInfos[cid].desc)
        return gCombatArtInfos[cid].name;

    return gCombatArtInfos[cid].desc;
}

/* Combat-art status */
u8 GetCombatArtInForce(struct Unit * unit);
void RegisterCombatArtStatus(struct Unit * unit, u8 cid);
void RegisterCombatArtHitted(void);
bool IsCombatArtHitted(void);
void ResetCombatArtStatus(void);

/* Combat-art list */
#define COMBART_LIST_MAX_AMT 6
struct CombatArtList {
    s8 uid;
    u8 amt;
    u8 cid[COMBART_LIST_MAX_AMT];
};

struct CombatArtList * GetCombatArtList(struct Unit * unit);
void ResetCombatArtList(void);

/* TargetSel & BKSEL */
bool CombatArtSelectTargetExist(void);
u8 GetCombatArtByTargetSelIndex(void);

/* Misc */
bool CanUnitPlayCombatArt(struct Unit * unit, u16 item);
int WeaponRangeGetterCombatArt(int range, struct Unit * unit, u16 item);
void PreBattleCalcCombatArt(struct BattleUnit * bu, struct BattleUnit * defender);
