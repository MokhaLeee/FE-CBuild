#include "global.h"
#include "bmunit.h"

#include "common-chax.h"
#include "skill-system.h"
#include "prep-skill.h"

extern struct PrepEquipSkillList gPrepEquipSkillList;
extern u8 sPrepEquipSkillListExt[MAX_SKILL_NUM + 1];

STATIC_DECLAR void RegisterToPrepEquipSkillListExt(const u8 sid)
{
    sPrepEquipSkillListExt[sid] |= 1;
}

STATIC_DECLAR void SetupPrepEquipReal(void)
{
    int i;
    for (i = 1; i < MAX_SKILL_NUM; i++)
        if (sPrepEquipSkillListExt[i] & 1)
            gPrepEquipSkillList.sid[gPrepEquipSkillList.amt++] = i;
}

STATIC_DECLAR void UpdatePrepEquipSkillList(struct Unit * unit)
{
    int i;

    CpuFill16(0, sPrepEquipSkillListExt, sizeof(sPrepEquipSkillListExt));
    CpuFill16(0, &gPrepEquipSkillList,   sizeof(gPrepEquipSkillList));

    /* Todo */
    for (i = 1; i < 0x100; i++)
        RegisterToPrepEquipSkillListExt(i);

    SetupPrepEquipReal();
    gPrepEquipSkillList.uid = unit->index;
}

struct PrepEquipSkillList * GetPrepEquipSkillList(struct Unit * unit)
{
    if (gPrepEquipSkillList.uid != unit->index)
        UpdatePrepEquipSkillList(unit);

    return &gPrepEquipSkillList;
}
