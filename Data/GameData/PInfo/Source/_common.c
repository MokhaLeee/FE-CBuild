#include "global.h"
#include "bmunit.h"
#include "bmreliance.h"

#include "common-chax.h"
#include "_common.h"
#include "constants/chax-characters.h"

const struct SupportDataPad _SupportData_enemy_boss1 = {
    .data = {
        .characters = { CHAR_CHAX_PrologueBoss },
        .supportExpBase = { SUPPORT_EXP_A },
        .supportCount = 1,
    },
    ._pad_ = { 0 }
};
