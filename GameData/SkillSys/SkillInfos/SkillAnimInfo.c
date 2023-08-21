#include "global.h"

#include "common-chax.h"
#include "skill-system.h"

const struct SkillAnimInfo gSkillAnimInfos[0x100] = {
    [0x01] = {
        .index = 0x0,
        .priority = 0x0,
        .sfx = 0x3DC,
    },
};

FEB_IDENTIFIER(gSkillAnimInfos);
