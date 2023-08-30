#pragma once

#include "global.h"
#include "bmunit.h"
#include "bmbattle.h"

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

extern const struct WeaponTriangleConf gWeaponTriangleConfs[];
extern struct WeaponTriangleConf const * const gpWeaponTriangleConfs;
