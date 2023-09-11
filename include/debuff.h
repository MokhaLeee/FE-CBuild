#pragma once

#include "global.h"
#include "bmunit.h"

#define NEW_UNIT_STATUS_MAX_DURATION 4

enum UNIT_STATUS_IDENTIFIER {
    MEW_UNIT_STATUS_NONE = 0,
    MEW_UNIT_STATUS_POISON,
    MEW_UNIT_STATUS_SLEEP,
    MEW_UNIT_STATUS_SILENCED,
    MEW_UNIT_STATUS_BERSERK,
    MEW_UNIT_STATUS_ATTACK,
    MEW_UNIT_STATUS_DEFENSE,
    MEW_UNIT_STATUS_CRIT,
    MEW_UNIT_STATUS_AVOID,
    MEW_UNIT_STATUS_SICK,
    MEW_UNIT_STATUS_RECOVER,
    MEW_UNIT_STATUS_PETRIFY,
    MEW_UNIT_STATUS_12,
    NEW_UNIT_STATUS_13,

    /* Expand here */

    NEW_UNIT_STATUS_MAX = 64
};

struct DebuffInfo {
    u16 name, desc;
    const u8 * img;
    u8 duration;

    s8 pow, mag, skl, spd, def, res, lck, mov;
    s8 atk, bdef, hit, avo, crit, silencer, dodge;
};

extern const struct DebuffInfo gDebuffInfos[NEW_UNIT_STATUS_MAX];

int GetUnitStatusIndex(struct Unit * unit);
int GetUnitStatusDuration(struct Unit * unit);
void SetUnitStatusIndex(struct Unit * unit, int status);
void SetUnitStatusDuration(struct Unit * unit, int duration);
int TryTickUnitStatusDuration(struct Unit * unit);
