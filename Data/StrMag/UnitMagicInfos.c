#include "global.h"
#include "bmunit.h"
#include "constants/characters.h"
#include "constants/classes.h"

#include "common-chax.h"
#include "strmag.h"
#include "constants/chax-characters.h"
#include "constants/chax-classes.h"

const struct UnitMagicInfo gMagicPInfos[0x100] = {
    [CHAR_CHAX_Lyn] = {
        .base = 0,
        .growth = 40,
    },
    [CHAR_CHAX_Mark] = {
        .base = 5,
        .growth = 75,
    }
};

FEB_IDENTIFIER(gMagicPInfos);

const struct UnitMagicInfo gMagicJInfos[0x100] = {
    [CLASS_CHAX_LYN_T1] = {
        .base = 3,
        .growth = 40,
        .cap = 20,
        .bonus = 0,
    },
    [CLASS_CHAX_Mark_T1] = {
        .base = 4,
        .growth = 60,
        .cap = 27,
    },
};

FEB_IDENTIFIER(gMagicJInfos);
