#include "global.h"
#include "bmunit.h"
#include "agb_sram.h"

#include "common-chax.h"
#include "bwl.h"
#include "skill-system.h"

struct LearnedSkillList {
    u16 data[0x10];
};

extern struct LearnedSkillList sLearnedSkillPLists[NEW_BWL_ARRAY_NUM];

/* GameInitHook */
void ResetUnitLearnedSkillLists(void)
{
    CpuFastFill16(0, sLearnedSkillPLists, sizeof(sLearnedSkillPLists));
}

/* SaveData */
void SaveUnitLearnedSkillLists(u8 * dst, const u32 size)
{
    size_t _size = size > sizeof(sLearnedSkillPLists) ? sizeof(sLearnedSkillPLists) : size;
    WriteAndVerifySramFast(sLearnedSkillPLists, dst, _size);
}

/* LoadData */
void LoadUnitLearnedSkillLists(u8 * src, const u32 size)
{
    size_t _size = size > sizeof(sLearnedSkillPLists) ? sizeof(sLearnedSkillPLists) : size;
    ReadSramFast(src, sLearnedSkillPLists, _size);
}

bool IsSkillLearned(struct Unit * unit, const u8 sid)
{
    u8 lo = sid & 0xF;
    u8 hi = (sid >> 4) & 0xF;
    struct LearnedSkillList * list = &sLearnedSkillPLists[UNIT_CHAR_ID(unit)];

    return !!(list->data[hi] & (1 << lo));
}

void UnitLearnSkill(struct Unit * unit, const u8 sid)
{
    u8 lo = (sid & 0x0F);
    u8 hi = (sid & 0xF0) >> 4;
    struct LearnedSkillList * list = &sLearnedSkillPLists[UNIT_CHAR_ID(unit)];

    list->data[hi] |= 1 << lo;
}

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
                UnitLearnSkill(unit, sid);

            sid = jConf->skills[level + i];
            if (SKILL_VALID(sid))
                UnitLearnSkill(unit, sid);
        }
        level = level - 5;
    }

    count = 0;
    for (i = 1; i < MAX_SKILL_NUM; i++)
    {
        if (IsSkillLearned(unit, i))
        {
            UNIT_RAM_SKILLS(unit)[count++] = i;
            if (count >= UNIT_RAM_SKILLS_LEN)
                break;
        }
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
            UnitLearnSkill(unit, sid);
            list[i] = sid;
            ResetSkillLists();
            return 0;
        }
    }
    return -1;
}
