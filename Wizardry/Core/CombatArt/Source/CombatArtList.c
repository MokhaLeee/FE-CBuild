#include "global.h"
#include "bmunit.h"
#include "bmitem.h"
#include "bmbattle.h"

#include "common-chax.h"
#include "skill-system.h"
#include "combat-art.h"
#include "constants/combat-arts.h"

extern struct CombatArtList sCombatArtList;

STATIC_DECLAR void CalcCombatArtListExt(struct Unit * unit)
{
    int i;
    u8 cid;
    u16 item_index = ITEM_INDEX(GetUnitEquippedWeapon(unit));
    u8 pid = UNIT_CHAR_ID(unit);
    u8 jid = UNIT_CLASS_ID(unit);
    u8 * tmp_list = gGenericBuffer;

    CpuFastFill16(0, tmp_list, 0x100);

    /* Skill table */
    for (i = 1; i < 0xFF; i++)
    {
        if (COMBART_VALID(gCombatArtSkillTable[i]))
            if (SkillTester(unit, i))
                tmp_list[i] = true;
    }

    /* Weapon table */
    cid = gCombatArtWeaponTable[item_index];
    if (COMBART_VALID(cid))
        tmp_list[cid] = true;

    /* ROM table */
    for (i = WPN_LEVEL_E; i <= WPN_LEVEL_S; i++)
    {
        if (unit->ranks[ITYPE_SWORD] >= i)
        {
            cid = gCombatArtDefaultTable.cid_sword[i];
            if (COMBART_VALID(cid))
                tmp_list[cid] = true;

            cid = gCombatArtRomPTable[pid].cid_sword[i];
            if (COMBART_VALID(cid))
                tmp_list[cid] = true;

            cid = gCombatArtRomJTable[jid].cid_sword[i];
            if (COMBART_VALID(cid))
                tmp_list[cid] = true;
        }

        if (unit->ranks[ITYPE_LANCE] >= i)
        {
            cid = gCombatArtDefaultTable.cid_lance[i];
            if (COMBART_VALID(cid))
                tmp_list[cid] = true;

            cid = gCombatArtRomPTable[pid].cid_lance[i];
            if (COMBART_VALID(cid))
                tmp_list[cid] = true;

            cid = gCombatArtRomJTable[jid].cid_lance[i];
            if (COMBART_VALID(cid))
                tmp_list[cid] = true;
        }

        if (unit->ranks[ITYPE_AXE] >= i)
        {
            cid = gCombatArtDefaultTable.cid_axe[i];
            if (COMBART_VALID(cid))
                tmp_list[cid] = true;

            cid = gCombatArtRomPTable[pid].cid_axe[i];
            if (COMBART_VALID(cid))
                tmp_list[cid] = true;

            cid = gCombatArtRomJTable[jid].cid_axe[i];
            if (COMBART_VALID(cid))
                tmp_list[cid] = true;
        }

        if (unit->ranks[ITYPE_BOW] >= i)
        {
            cid = gCombatArtDefaultTable.cid_bow[i];
            if (COMBART_VALID(cid))
                tmp_list[cid] = true;

            cid = gCombatArtRomPTable[pid].cid_bow[i];
            if (COMBART_VALID(cid))
                tmp_list[cid] = true;

            cid = gCombatArtRomJTable[jid].cid_bow[i];
            if (COMBART_VALID(cid))
                tmp_list[cid] = true;
        }
    }

    sCombatArtList.amt = 0;
    for (i = 1; i < 0xFF; i++)
    {
        if (sCombatArtList.amt >= COMBART_LIST_MAX_AMT)
            break;

        if (tmp_list[i])
            sCombatArtList.cid[sCombatArtList.amt++] = i;
    }
}

struct CombatArtList * GetCombatArtList(struct Unit * unit)
{
    if (unit->index != sCombatArtList.uid)
    {
        sCombatArtList.uid = unit->index;
        CalcCombatArtListExt(unit);
    }
    return &sCombatArtList;
}

void ResetCombatArtList(void)
{
    CpuFastFill16(0, &sCombatArtList, sizeof(sCombatArtList));
}