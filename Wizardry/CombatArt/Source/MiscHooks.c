#include "global.h"
#include "bmunit.h"
#include "bmitem.h"
#include "hardware.h"
#include "bmbattle.h"
#include "uimenu.h"
#include "bmmenu.h"
#include "playerphase.h"
#include "bksel.h"

#include "common-chax.h"
#include "combat-art.h"
#include "constants/combat-arts.h"

bool CanUnitPlayCombatArt(struct Unit * unit, u16 item)
{
    int i, wtype = GetItemType(item);
    struct CombatArtList * list = GetCombatArtList(unit);

    for (i = 0; i < list->amt; i++)
        if (gCombatArtInfos[list->cid[i]].wtype == wtype)
            return true;

    return false;
}

/* Weapon range getter */
int WeaponRangeGetterCombatArt(int range, struct Unit * unit, u16 item)
{
    u8 cid = GetCombatArtInForce(unit);

    if (COMBART_VALID(cid))
    {
        const struct CombatArtInfo * info = gCombatArtInfos + cid;
        if (GetItemType(item) == info->wtype)
            range += info->range_bonus;
    }
    return range;
}

/* Pre-battle calc */
void PreBattleCalcCombatArt(struct BattleUnit * bu, struct BattleUnit * defender)
{
    u8 cid = GetCombatArtInForce(&bu->unit);
    const struct CombatArtInfo * info;
    struct Unit * unit;

    if (!COMBART_VALID(cid))
        return;

    info = gCombatArtInfos + cid;
    unit = GetUnit(bu->unit.index);

    bu->battleAttack       += info->battle_status.atk;
    bu->battleDefense      += info->battle_status.def;
    bu->battleHitRate      += info->battle_status.hit;
    bu->battleAvoidRate    += info->battle_status.avo;
    bu->battleSilencerRate += info->battle_status.silencer;
    bu->battleDodgeRate    += info->battle_status.dodge;

    if (info->external_calc)
    {
        switch (cid) {
        case CID_FrozenLance:
            bu->battleAttack += GetUnitSkill(unit);
            break;

        case CID_Vengeance:
            bu->battleAttack += GetUnitMaxHp(unit) - GetUnitCurrentHp(unit);
            break;

        case CID_LightningAxe:
            bu->battleAttack += GetUnitResistance(unit);
            break;
        };
    }
}

STATIC_DECLAR int SelectTargetInfoOnEndVanilla(void)
{
    BG_Fill(gBG2TilemapBuffer, 0);
    BG_EnableSyncByMask(BG2_SYNC_BIT);

    HideMoveRangeGraphics();
    CloseBattleForecast();
    return 0;
}

/* LynJump */
int sub_8022F10(void)
{
    ResetCombatArtList();
    ResetCombatArtStatus();
    return SelectTargetInfoOnEndVanilla();
}
