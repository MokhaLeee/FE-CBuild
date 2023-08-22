#include "global.h"

#include "common-chax.h"
#include "skill-system.h"

const struct SkillAnimInfo gSkillAnimInfos[0x100] = {
    [0x01] = {
        .index = 0x1,
        .priority = 0x0,
        .sfx = 0x3D1,
    },
    [0x02] = {
        .index = 0x1,
        .priority = 0x0,
        .sfx = 0x3D1,
    },
};

FEB_IDENTIFIER(gSkillAnimInfos);
