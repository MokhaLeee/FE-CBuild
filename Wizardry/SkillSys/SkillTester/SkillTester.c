#include "global.h"
#include "bmunit.h"

#include "common-chax.h"
#include "skill-system.h"

#define BasicJudgeSkill(unit, sid)  \
do {                                \
    if (MAX_SKILL_NUM == sid)       \
        return false;               \
                                    \
    if (0 == sid)                   \
        return true;                \
                                    \
    if (!UNIT_IS_VALID(unit))       \
        return false;               \
} while (0)

static bool SkillTesterROM(struct Unit * unit, const u8 sid)
{
    int i, level;

    for (level = 0; level <= UNIT_LEVEL_MAX_RE; level += 5)
    {
        if (unit->level < level)
            break;

        for (i = 0; i < SKILL_ROM_DATA_AMT; i++)
        {
            const struct SkillRomData * data;

            data = &gSkillRomPData[UNIT_CHAR_ID(unit)];
            if (data->skills[level * 5 + i] == sid)
                return true;

            data = &gSkillRomJData[UNIT_CLASS_ID(unit)];
            if (data->skills[level * 5 + i] == sid)
                return true;
        }
    }

    return false;
}

static bool SkillTesterRAM(struct Unit * unit, const u8 sid)
{
    /* TODO */
    return false;
}

bool SkillTesterBasic(struct Unit * unit, const u8 sid)
{
    int ret;
    BasicJudgeSkill(unit, sid);

    ret = SkillTesterROM(unit, sid);
    if (ret == true)
        return true;

    ret = SkillTesterRAM(unit, sid);
    if (ret == true)
        return true;

    return false;
}

bool SkillTesterFast(struct Unit * unit, const u8 sid)
{
    int i;
    struct SkillList * list = GetUnitSkillList(unit);

    if (list)
    {
        for (i = 0; i < list->amt; i++)
        {
            if (list->data[i] == sid)
                return true;
        }
    }
    return false;
}

bool (* const SkillTester)(struct Unit *, const u8) = SkillTesterFast;
