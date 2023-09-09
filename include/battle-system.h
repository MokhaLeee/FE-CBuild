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

bool CheckBattleHitOverflow(void);
bool CheckCanFollowUpAttack(struct BattleUnit * actor, struct BattleUnit * target);
