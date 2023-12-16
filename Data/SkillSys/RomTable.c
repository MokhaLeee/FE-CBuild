#include "global.h"
#include "constants/characters.h"
#include "constants/classes.h"

#include "common-chax.h"
#include "skill-system.h"
#include "constants/skills.h"
#include "constants/chax-characters.h"
#include "constants/chax-classes.h"

const u8 gConstSkillPTable[0x100][2] = {
    [CHAR_CHAX_PrologueBoss] = {SID_Vantage},
};

FEB_IDENTIFIER(gConstSkillPTable);

const u8 gConstSkillJTable[0x100][2] = {
    [CLASS_CHAX_LYN_T1] = {SID_FlashingBlade, SID_Galeforce},
};

FEB_IDENTIFIER(gConstSkillJTable);
