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
    int i;
    struct SkillList * list = GetExistingSkillList(unit);

    if (!list)
    {
        Debugf("Generate skill for %#x, next %d", UNIT_CHAR_ID(unit), sSkillListNext);

        if (unit->index == gBattleActor.unit.index)
            list = &sSkillLists[2];
        else if (unit->index == gBattleTarget.unit.index)
            list = &sSkillLists[3];
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
