#include "global.h"
#include "bmunit.h"
#include "constants/characters.h"
#include "constants/classes.h"

#include "common-chax.h"
#include "strmag.h"

const struct UnitMagicInfo gMagicPInfos[0x100] = {
    [CHARACTER_EIRIKA] = {
        .base = 5,
        .growth = 40,
    },
};

FEB_IDENTIFIER(gMagicPInfos);

const struct UnitMagicInfo gMagicJInfos[0x100] = {
    [CLASS_EIRIKA_LORD] = {
        .base = 5,
        .growth = 40,
        .cap = 20,
        .bonus = 0,
    },
};

FEB_IDENTIFIER(gMagicJInfos);
