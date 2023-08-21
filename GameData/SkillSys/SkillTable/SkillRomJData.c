#include "global.h"
#include "constants/classes.h"

#include "skill-system.h"

const struct SkillRomData gSkillRomJData[0x100] = {
    [CLASS_EPHRAIM_LORD] = {
        .alloc = {
            [0] = {
                .skills = {0x1},
            },
            [1] = {
                .skills = {0x2},
            },
        }
    },
};
