#include "global.h"
#include "bmitem.h"

#include "common-chax.h"
#include "combat-art.h"
#include "constants/combat-arts.h"
#include "constants/texts.h"
#include "constants/gfx.h"

const struct CombatArtInfo gCombatArtInfos[0x100] = {
    /* Sword arts */
    [CID_Grounder] = {
        .name = MSG_COMART_NAME_Grounder,
        .desc = MSG_COMART_DESC_Grounder,
        .icon = GFX_CombatArtIcon_SwordArtAtk,
        .wtype = ITYPE_SWORD,
        .cost = 4,
        .battle_status.atk = 5,
        .battle_status.hit = 20,
        .battle_status.crit = 5,
        .effective_fly = true,
    },
    [CID_BaneOfMonsters] = {
        .name = MSG_COMART_NAME_BaneOfMonsters,
        .desc = MSG_COMART_DESC_BaneOfMonsters,
        .icon = GFX_CombatArtIcon_SwordArtAtk,
        .wtype = ITYPE_SWORD,
        .cost = 4,
        .battle_status.atk = 6,
        .battle_status.crit = 10,
        .effective_monster = true,
    },
    [CID_Hexblade] = {
        .name = MSG_COMART_NAME_Hexblade,
        .desc = MSG_COMART_DESC_Hexblade,
        .icon = GFX_CombatArtIcon_SwordArtMag,
        .wtype = ITYPE_SWORD,
        .cost = 3,
        .battle_status.atk = 7,
        .battle_status.hit = 10,
        .magic_attack = true,
    },
    [CID_FoudroyantStrike] = {
        .name = MSG_COMART_NAME_FoudroyantStrike,
        .desc = MSG_COMART_DESC_FoudroyantStrike,
        .icon = GFX_CombatArtIcon_SwordArtCrit,
        .wtype = ITYPE_SWORD,
        .cost = 3,
        .battle_status.atk = 6,
        .battle_status.hit = 30,
        .battle_status.crit = 30,
        .effective_armor = true,
    },

    /* Lance arts */
    [CID_TempestLance] = {
        .name = MSG_COMART_NAME_TempestLance,
        .desc = 0,
        .icon = GFX_CombatArtIcon_LanceArtAtk,
        .wtype = ITYPE_LANCE,
        .cost = 5,
        .battle_status.atk = 8,
        .battle_status.hit = 10,
    },
    [CID_SwiftStrikes] = {
        .name = MSG_COMART_NAME_SwiftStrikes,
        .desc = MSG_COMART_DESC_SwiftStrikes,
        .icon = GFX_CombatArtIcon_LanceArtAtk,
        .wtype = ITYPE_LANCE,
        .cost = 2,
        .battle_status.atk = 2,
        .battle_status.crit = 5,
        .doubel_attack = true,
    },
    [CID_FrozenLance] = {
        .name = MSG_COMART_NAME_FrozenLance,
        .desc = MSG_COMART_DESC_FrozenLance,
        .icon = GFX_CombatArtIcon_LanceArtMag,
        .wtype = ITYPE_LANCE,
        .cost = 4,
        .battle_status.atk = 2,
        .battle_status.crit = 10,
        .external_calc = true,
        .magic_attack = true,
    },
    [CID_Vengeance] = {
        .name = MSG_COMART_NAME_Vengeance,
        .desc = MSG_COMART_DESC_Vengeance,
        .icon = GFX_CombatArtIcon_LanceArtCrit,
        .wtype = ITYPE_LANCE,
        .cost = 4,
        .battle_status.atk = 5,
        .battle_status.hit = 20,
        .battle_status.crit = 5,
        .external_calc = true,
    },

    /* Axe arts */
    [CID_HelmSplitter] = {
        .name = MSG_COMART_NAME_HelmSplitter,
        .desc = MSG_COMART_DESC_HelmSplitter,
        .icon = GFX_CombatArtIcon_AxeArtAtk,
        .wtype = ITYPE_AXE,
        .cost = 5,
        .battle_status.atk = 7,
        .battle_status.crit = 5,
        .effective_armor = true,
    },
    [CID_LightningAxe] = {
        .name = MSG_COMART_NAME_LightningAxe,
        .desc = MSG_COMART_DESC_LightningAxe,
        .icon = GFX_CombatArtIcon_AxeArtMag,
        .wtype = ITYPE_AXE,
        .cost = 3,
        .battle_status.atk = 4,
        .magic_attack = true,
        .external_calc = true
    },
    [CID_WarMasterStrike] = {
        .name = MSG_COMART_NAME_WarMasterStrike,
        .desc = MSG_COMART_DESC_WarMasterStrike,
        .icon = GFX_CombatArtIcon_AxeArtCrit,
        .wtype = ITYPE_AXE,
        .cost = 5,
        .battle_status.atk = 3,
        .battle_status.hit = 30,
        .battle_status.crit = 10,
        .effective_all = true,
    },

    /* Bow arts */
    [CID_CurvedShot] = {
        .name = MSG_COMART_NAME_CurvedShot,
        .icon = GFX_CombatArtIcon_BowArtAtk,
        .desc = 0,
        .wtype = ITYPE_BOW,
        .cost = 3,
        .range_bonus = 1,
        .battle_status.atk = 1,
        .battle_status.crit = 30,
    },
    [CID_Deadeye] = {
        .name = MSG_COMART_NAME_Deadeye,
        .icon = GFX_CombatArtIcon_BowArtAtk,
        .desc = 0,
        .wtype = ITYPE_BOW,
        .cost = 5,
        .range_bonus = 3,
        .battle_status.atk = 6,
    },
    [CID_Encloser] = {
        .name = MSG_COMART_NAME_Encloser,
        .desc = MSG_COMART_DESC_Encloser,
        .icon = GFX_CombatArtIcon_BowArtDebuff,
        .wtype = ITYPE_BOW,
        .cost = 5,
        .range_bonus = 1,
        .battle_status.hit = 10,
        .debuff_gravity = true,
    },
    [CID_EncloserPlus] = {
        .name = MSG_COMART_NAME_EncloserPlus,
        .desc = MSG_COMART_DESC_EncloserPlus,
        .icon = GFX_CombatArtIcon_BowArtDebuff,
        .wtype = ITYPE_BOW,
        .cost = 7,
        .range_bonus = 2,
        .battle_status.hit = 20,
        .debuff_gravity = true,
        .aoe_debuff = true,
    },
    [CID_MonsterBlast] = {
        .name = MSG_COMART_NAME_MonsterBlast,
        .desc = MSG_COMART_DESC_MonsterBlast,
        .icon = GFX_CombatArtIcon_BowArtCrit,
        .wtype = ITYPE_BOW,
        .cost = 4,
        .battle_status.atk = 5,
        .battle_status.crit = 10,
        .effective_monster = true,
    },
    [CID_SchismShot] = {
        .name = MSG_COMART_NAME_SchismShot,
        .desc = MSG_COMART_DESC_SchismShot,
        .icon = GFX_CombatArtIcon_BowArtMag,
        .wtype = ITYPE_BOW,
        .cost = 3,
        .range_bonus = 1,
        .battle_status.atk = 4,
        .battle_status.hit = 15,
        .magic_attack = true,
        .debuff_res = true,
    },
    [CID_BreakShot] = {
        .name = MSG_COMART_NAME_BaneOfMonsters,
        .desc = MSG_COMART_DESC_BaneOfMonsters,
        .icon = GFX_CombatArtIcon_BowArtDebuff,
        .wtype = ITYPE_BOW,
        .cost = 3,
        .range_bonus = 1,
        .battle_status.hit = 10,
        .debuff_def = true,
    },
    [CID_BreakShotPlus] = {
        .name = MSG_COMART_NAME_BreakShotPlus,
        .desc = MSG_COMART_DESC_BreakShotPlus,
        .icon = GFX_CombatArtIcon_BowArtDebuff,
        .wtype = ITYPE_BOW,
        .cost = 5,
        .range_bonus = 2,
        .battle_status.hit = 20,
        .debuff_def = true,
        .aoe_debuff = true,
    },
    [CID_WaningShot] = {
        .name = MSG_COMART_NAME_WaningShot,
        .desc = MSG_COMART_DESC_WaningShot,
        .icon = GFX_CombatArtIcon_BowArtDebuff,
        .wtype = ITYPE_BOW,
        .cost = 3,
        .range_bonus = 1,
        .battle_status.atk = 4,
        .battle_status.hit = 10,
        .debuff_weaken = true,
    },
    [CID_WaningShotPlus] = {
        .name = MSG_COMART_NAME_WaningShotPlus,
        .desc = MSG_COMART_DESC_WaningShotPlus,
        .icon = GFX_CombatArtIcon_BowArtDebuff,
        .wtype = ITYPE_BOW,
        .cost = 5,
        .range_bonus = 2,
        .battle_status.hit = 20,
        .debuff_weaken = true,
        .aoe_debuff = true,
    },
    [CID_HuntersVolley] = {
        .name = MSG_COMART_NAME_HuntersVolley,
        .desc = MSG_COMART_DESC_HuntersVolley,
        .icon = GFX_CombatArtIcon_BowArtAtk,
        .wtype = ITYPE_BOW,
        .cost = 2,
        .range_bonus = 1,
        .battle_status.atk = 1,
        .battle_status.hit = 15,
        .battle_status.crit = 10,
        .doubel_attack = true,
    },
};

FEB_IDENTIFIER(gCombatArtInfos);
