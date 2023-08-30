#include "global.h"
#include "constants/classes.h"

#include "skill-system.h"
#include "constants/skills.h"

const struct SkillRomData gSkillRomJData[0x100] = {
    [CLASS_ASSASSIN] = {
        .skills = {
            [0]  = SID_Lethality,
            [10] = SID_DefiantCrit,
        },
    },

    [CLASS_ASSASSIN_F] = {
        .skills = {
            [0]  = SID_Lethality,
            [10] = SID_DefiantCrit,
        },
    },
};

FEB_IDENTIFIER(gSkillRomJData);
