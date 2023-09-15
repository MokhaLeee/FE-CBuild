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

struct SkillList * GetUnitSkillList(struct Unit * unit)
{
    int i;
    struct SkillList * list = NULL;

    if (unit->index == sSkillLists[0].uid)
    {
        list = &sSkillLists[0];
        sSkillListNext = 1;
    }
    else if (unit->index == sSkillLists[1].uid)
    {
        list = &sSkillLists[1];
        sSkillListNext = 0;
    }

    if (!list)
    {
        if (unit->index == gBattleActor.unit.index)
            list = &sSkillLists[3];
        else if (unit->index == gBattleTarget.unit.index)
            list = &sSkillLists[4];
        else
        {
            list = &sSkillLists[sSkillListNext];
            sSkillListNext = !sSkillListNext;
        }

        list->uid = unit->index;
        list->amt = 0;

        for (i = MAX_SKILL_NUM - 1; i >= 1; i--)
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
