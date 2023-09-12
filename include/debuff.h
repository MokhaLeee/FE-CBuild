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

enum DEBUFF_INFO_TYPE {
    STATUS_INFO_TYPE_DEFAULT = 0,
    STATUS_INFO_TYPE_DEBUFF = 1,
    STATUS_INFO_TYPE_BUFF = 2,
};

enum DEBUFF_INFO_EFX_SPEED {
    EFX_DEBUFF_LOWLOW,
    EFX_DEBUFF_LOW,
    EFX_DEBUFF_NORMAL,
    EFX_DEBUFF_FAST,
};

struct DebuffInfo {
    u16 name, desc;
    const u8 * img;
    void (* on_draw)(struct Unit * unit);

    u8 type;
    u8 duration;

    struct {
        u8 speed;
        u8 r, g, b;
    } efx_config;

    struct {
        s8 pow, mag, skl, spd, def, res, lck, mov;
    } unit_status;

    struct {
        s8 atk, def, hit, avo, crit, silencer, dodge;
    } battle_status;
};

extern const struct DebuffInfo gDebuffInfos[NEW_UNIT_STATUS_MAX];

int GetUnitStatusIndex(struct Unit * unit);
int GetUnitStatusDuration(struct Unit * unit);
void SetUnitStatusIndex(struct Unit * unit, int status);
void SetUnitStatusDuration(struct Unit * unit, int duration);
int TryTickUnitStatusDuration(struct Unit * unit);

void PutUnitStatusIcon(struct Unit * unit);
void PutUnitDanceRingBuffIcon(struct Unit * unit);