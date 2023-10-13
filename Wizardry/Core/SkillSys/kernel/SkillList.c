#include "global.h"
#include "bmunit.h"
#include "bmbattle.h"

#include "common-chax.h"
#include "skill-system.h"

extern u32 sSkillListNext;

/**
 * 0 & 1: generic usage
 * 2: battle actor
 * 3: battle target
 */
extern struct SkillList sSkillLists[4];

#if 0
/**
 * This function should play the same as:
 * SkillTesterBasic()
 */
STATIC_DECLAR void GenerateSkillListExt(struct Unit * unit, struct SkillList * list)
{
    int i, sid;
    u8 pid = UNIT_CHAR_ID(unit);
    u8 jid = UNIT_CLASS_ID(unit);
    u8 * ram_list = UNIT_RAM_SKILLS(unit);

    list->uid = unit->index;
    list->amt = 0;

    /* ROM tables */
    sid = gConstSkillPTable[pid][0];
    if (SKILL_VALID(sid))
        list->sid[list->amt++] = sid;

    sid = gConstSkillPTable[pid][1];
    if (SKILL_VALID(sid))
        list->sid[list->amt++] = sid;

    sid = gConstSkillJTable[jid][0];
    if (SKILL_VALID(sid))
        list->sid[list->amt++] = sid;

    sid = gConstSkillJTable[jid][1];
    if (SKILL_VALID(sid))
        list->sid[list->amt++] = sid;

    /* RAM table */
    for (i = 0; i < UNIT_RAM_SKILLS_LEN; i++)
        if (SKILL_VALID(ram_list[i]))
            list->sid[list->amt++] = ram_list[i];
}

#else

STATIC_DECLAR void GenerateSkillListExt(struct Unit * unit, struct SkillList * list)
{
    int i;

    list->uid = unit->index;
    list->amt = 0;

    for (i = 1; i < MAX_SKILL_NUM; i++)
    {
        if (SkillTesterBasic(unit, i) == true)
        {
            list->sid[list->amt] = i;

            list->amt++;
            if (list->amt > SKILL_LIST_MAX_AMT)
                break;
        }
    }
}
#endif

STATIC_DECLAR struct SkillList * GetExistingSkillList(struct Unit * unit)
{
    int i;
    for (i = 0; i < 4; i++)
    {
        if (unit->index != sSkillLists[i].uid)
            continue;

        switch (i) {
        case 0:
        case 1:
            sSkillListNext = !i;
            break;
        }
        return &sSkillLists[i];
    }
    return NULL;
}

struct SkillList * GetUnitSkillList(struct Unit * unit)
{
    struct SkillList * list = GetExistingSkillList(unit);

    if (!list)
    {
        if (unit->index == gBattleActor.unit.index)
            list = &sSkillLists[2];
        else if (unit->index == gBattleTarget.unit.index)
            list = &sSkillLists[3];
        else
        {
            list = &sSkillLists[sSkillListNext];
            sSkillListNext = !sSkillListNext;
        }

        GenerateSkillListExt(unit, list);
    }
    return list;
}

void ResetSkillLists(void)
{
    CpuFastFill16(0, sSkillLists, sizeof(sSkillLists));
}

void DisableUnitSkills(struct Unit * unit)
{
    GetUnitSkillList(unit)->amt = 0;
}
