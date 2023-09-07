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
} while (0)

static bool SkillTesterROM(struct Unit * unit, const u8 sid)
{
    if (gSkillRomPTable[UNIT_CHAR_ID(unit)] == sid)
        return true;

    if (gSkillRomJTable[UNIT_CLASS_ID(unit)] == sid)
        return true;

    return false;
}

static bool SkillTesterRAM(struct Unit * unit, const u8 sid)
{
    int i;
    u8 * list = UNIT_RAM_SKILLS(unit);
    for (i = 0; i < UNIT_RAM_SKILLS_LEN; i++)
        if (sid == list[i])
            return true;

    return false;
}

bool SkillTesterBasic(struct Unit * unit, const u8 sid)
{
    int ret;

    BasicJudgeSkill(unit, sid);

    if (!UNIT_IS_VALID(unit))
        return false;

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
            if (list->sid[i] == sid)
                return true;
        }
    }
    return false;
}

bool (* const SkillTester)(struct Unit *, const u8) = SkillTesterFast;
