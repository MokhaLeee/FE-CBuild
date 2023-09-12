#include "global.h"
#include "bmitem.h"

#include "common-chax.h"
#include "combat-art.h"
#include "constants/combat-arts.h"
#include "constants/texts.h"

const struct CombatArtInfo gCombatArtInfos[0x100] = {
    [CID_Grounder] = {
        .name = MSG_COMART_NAME_Grounder,
        .desc = MSG_COMART_DESC_Grounder,
        .wtype = ITYPE_SWORD,
        .cost = 4,
        .mt = 5,
        .hit = 20,
        .crit = 5,
        .effective_fly = true,
    },
    [CID_BaneOfMonsters] = {
        .name = MSG_COMART_NAME_BaneOfMonsters,
        .desc = MSG_COMART_DESC_BaneOfMonsters,
        .wtype = ITYPE_SWORD,
        .cost = 4,
        .mt = 6,
        .crit = 10,
        .effective_monster = true,
    },
    [CID_Hexblade] = {
        .name = MSG_COMART_NAME_Hexblade,
        .desc = MSG_COMART_DESC_Hexblade,
        .wtype = ITYPE_SWORD,
        .cost = 3,
        .mt = 7,
        .hit = 10,
        .magic_attack = true,
    },
    [CID_FoudroyantStrike] = {
        .name = MSG_COMART_NAME_FoudroyantStrike,
        .desc = MSG_COMART_DESC_FoudroyantStrike,
        .wtype = ITYPE_SWORD,
        .cost = 3,
        .mt = 6,
        .hit = 30,
        .crit = 30,
        .effective_armor = true,
    },
};

FEB_IDENTIFIER(gCombatArtInfos);
