#include "global.h"
#include "constants/characters.h"
#include "constants/classes.h"

#include "common-chax.h"
#include "skill-system.h"
#include "constants/skills.h"

const u8 gConstSkillPTable[0x100] = {
    [CHARACTER_EIRIKA] = SID_AvoidSword,
};

FEB_IDENTIFIER(gConstSkillPTable);

const u8 gConstSkillJTable[0x100] = {
    [CLASS_EIRIKA_LORD] = SID_FlashingBlade,
};

FEB_IDENTIFIER(gConstSkillJTable);
