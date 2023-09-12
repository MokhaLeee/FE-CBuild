#pragma once

#include "global.h"
#include "bmunit.h"
#include "bmbattle.h"

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
enum BattleStaticFlags {
    TMP_VANTAGE_ORDER_FLAG = 1 << 0x00,
    TMP_DESPERATION_ORDER_FLAG = 1 << 0x01,
    TMP_QUICK_RIPOSTE_ORDER_FLAG = 1 << 0x02,
    TMP_DOUBLE_LION_ORDER_FLAG = 1 << 0x03,
    TMP_RUINED_BLADE_PLUS_ORDER_FLAG = 1 << 0x04,
};

extern u32 gBattleTemporaryFlag;

enum BattleGlobalFlags {
    BATTLE_DOUBLE_LION_POST_ACTION_FLAG = 1 << 0x00,
};

extern u32 gBattleGlobalFlag;
