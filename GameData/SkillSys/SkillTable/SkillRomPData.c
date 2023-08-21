#include "global.h"
#include "constants/characters.h"

#include "skill-system.h"

const struct SkillRomData gSkillRomPData[0x100] = {
    [CHARACTER_EIRIKA] = {
        .skills = {
            [0] = 0x1,
            [5] = 0x2,
        },
    },
};

FEB_IDENTIFIER(gSkillRomPData);
