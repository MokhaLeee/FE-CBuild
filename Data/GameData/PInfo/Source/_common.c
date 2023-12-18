#include "global.h"
#include "bmunit.h"
#include "bmreliance.h"

#include "common-chax.h"
#include "_common.h"
#include "constants/chax-characters.h"

const struct SupportDataPad _SupportData_all_zero = { 0 };

const struct SupportDataPad _SupportData_enemy_boss1 = {
    .data = {
        .characters = {
            CHAR_CHAX_PrologueBoss,
            CHAR_CHAX_Ch1Boss,
            CHAR_CHAX_Ch2Boss,
        },
        .supportExpBase = {
            SUPPORT_EXP_A,
            SUPPORT_EXP_A,
            SUPPORT_EXP_A,
        },
        .supportCount = 3,
    },
    ._pad_ = { 0 }
};
