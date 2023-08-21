#include "global.h"
#include "constants/characters.h"

#include "skill-system.h"

const struct SkillRomData gSkillRomPData[0x100] = {
    [CHARACTER_EIRIKA] = {
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
