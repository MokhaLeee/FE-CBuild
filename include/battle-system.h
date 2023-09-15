#pragma once

#include "global.h"
#include "bmunit.h"
#include "bmbattle.h"
#include "fontgrp.h"

/* WTA bonus */
struct WeaponTriangleConf {
    s8 wtype_a;
    s8 wtype_b;
    u8 sid;
    u8 _pad_;

    s8 bonus_atk;
    s8 bonus_def;
    s8 bonus_speed;
    s8 bonus_hit;
    s8 bonus_avoid;
    s8 bonus_crit;
    s8 bonus_dodge;
    s8 bonus_silencer;
};

extern struct WeaponTriangleConf const * const gpWeaponTriangleConfs;

/* Battle hit expansion */
#define NEW_BATTLE_HIT_MAX 20 /* This should align to gAnimRoundData */
extern struct BattleHit gBattleHitArrayRe[NEW_BATTLE_HIT_MAX];

int GetBattleHitRound(struct BattleHit * hit);
bool CheckBattleHitOverflow(void);
bool CheckCanTwiceAttackOrder(struct BattleUnit * actor, struct BattleUnit * target);
int CalcBattleRealDamage(struct BattleUnit * attacker, struct BattleUnit * defender);

/* Flags in .data section */
extern struct {
    u32 order_vantage : 1;
    u32 order_desperation : 1;
    u32 order_quick_riposte : 1;
    u32 order_dobule_lion : 1;
    u32 order_ruined_blade_plus : 1;
} gBattleTemporaryFlag;

extern struct BattleGlobalFlags {
    u32 skill_activated_double_lion : 1;
    u32 skill_activated_ather : 1;
    u32 skill_activated_astra : 1;
} gBattleActorGlobalFlag, gBattleTargetGlobalFlag;

void ClearBattleGlobalFlags(void);

/* Port from decomp, need update c-lib later */
struct BattleForecastProc {
    /* 00 */ PROC_HEADER;

    /* 2C */ int unk_2C;
    /* 30 */ s8 x;
    /* 31 */ s8 y;
    /* 32 */ u8 frameKind;
    /* 33 */ s8 ready;
    /* 34 */ s8 needContentUpdate;
    /* 35 */ s8 side; // -1 is left, +1 is right
    /* 36 */ s8 unk_36;
    /* 38 */ struct Text unitNameTextA;
    /* 40 */ struct Text unitNameTextB;
    /* 48 */ struct Text itemNameText;
    /* 50 */ s8 hitCountA;
    /* 51 */ s8 hitCountB;
    /* 52 */ s8 isEffectiveA;
    /* 53 */ s8 isEffectiveB;
};

void BattleForecast_Init(struct BattleForecastProc * proc);
