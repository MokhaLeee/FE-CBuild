#include "global.h"
#include "bmunit.h"

#include "common-chax.h"
#include "skill-system.h"

void UnitAutoLoadSkills(struct Unit * unit)
{
    u8 sid;
    int i, count = 0;
    const struct SkillConf * pConf = &gSkillPData[UNIT_CHAR_ID(unit)];
    const struct SkillConf * jConf = &gSkillJData[UNIT_CLASS_ID(unit)];
    int level = Div(unit->level, 5) * 5;

    LIMIT_AREA(level, 0, UNIT_LEVEL_MAX_RE);

    while (level >= 0)
    {
        for (i = 0; i < 5; i++)
        {
            sid = pConf->skills[level + i];
            if (SKILL_VALID(sid))
            {
                UNIT_RAM_SKILLS(unit)[count++] = sid;

                if (count >= UNIT_RAM_SKILLS_LEN)
                    return;
            }

            sid = jConf->skills[level + i];
            if (SKILL_VALID(sid))
            {
                UNIT_RAM_SKILLS(unit)[count++] = sid;

                if (count >= UNIT_RAM_SKILLS_LEN)
                    return;
            }
        }
        level = level - 5;
    }
    ResetSkillLists();
}

bool CanRemoveSkill(struct Unit * unit, const u8 sid)
{
    int i;
    u8 * list = UNIT_RAM_SKILLS(unit);
    for (i = 0; i < UNIT_RAM_SKILLS_LEN; i++)
        if (sid == list[i])
            return true;

    return false;
}

int RemoveSkill(struct Unit * unit, const u8 sid)
{
    int i;
    u8 * list = UNIT_RAM_SKILLS(unit);
    for (i = 0; i < UNIT_RAM_SKILLS_LEN; i++)
        if (sid == list[i])
        {
            list[i] = 0;
            ResetSkillLists();
            return 0;
        }

    return -1;
}

int AddSkill(struct Unit * unit, const u8 sid)
{
    int i;
    u8 * list = UNIT_RAM_SKILLS(unit);

    for (i = 0; i < UNIT_RAM_SKILLS_LEN; i++)
    {
        if (!SKILL_VALID(list[i]))
        {
            list[i] = sid;
            ResetSkillLists();
            return 0;
        }
    }
    return -1;
}
