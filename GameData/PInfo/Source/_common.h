#pragma once

#include "bmunit.h"
#include "bmreliance.h"

struct SupportDataPad {
    struct SupportData data;
    u8 _pad_[2];
};

extern const struct SupportDataPad _SupportData_enemy_boss1;
extern const struct SupportDataPad _SupportData_all_zero;

#define SupportData_all_zero ((const struct SupportData *)&_SupportData_all_zero)
#define SupportData_EnemyBosses1 ((const struct SupportData *)&_SupportData_enemy_boss1)
