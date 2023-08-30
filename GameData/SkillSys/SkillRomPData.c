#include "global.h"
#include "constants/characters.h"

#include "skill-system.h"
#include "constants/skills.h"

const struct SkillRomData gSkillRomPData[0x100] = {
    [CHARACTER_EIRIKA] = {
        .skills = {
            [0] = SID_SpdBonus,
            [5] = SID_DefiantAvoid,
        },
    },
};

FEB_IDENTIFIER(gSkillRomPData);
