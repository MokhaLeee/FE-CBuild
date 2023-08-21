#include "global.h"
#include "constants/classes.h"

#include "skill-system.h"

const struct SkillRomData gSkillRomJData[0x100] = {
    [CLASS_EPHRAIM_LORD] = {
        .skills = {
            [0] = 0x1,
            [5] = 0x2,
        },
    },
};

FEB_IDENTIFIER(gSkillRomJData);
