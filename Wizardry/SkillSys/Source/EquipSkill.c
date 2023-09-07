#include "global.h"
#include "bmunit.h"

#include "common-chax.h"
#include "skill-system.h"
#include "prep-skill.h"

extern struct PrepEquipSkillList sPrepEquipSkillList;
extern u8 sPrepEquipSkillListExt[MAX_SKILL_NUM + 1];

void ResetPrepEquipSkillList(void)
{
    CpuFill16(0, sPrepEquipSkillListExt, sizeof(sPrepEquipSkillListExt));
    CpuFill16(0, &sPrepEquipSkillList,   sizeof(sPrepEquipSkillList));
}

STATIC_DECLAR void RegisterToPrepEquipSkillListExt(const u8 sid)
{
    sPrepEquipSkillListExt[sid] |= 1;
}

STATIC_DECLAR void SetupPrepEquipReal(void)
{
    int i;
    for (i = 1; i < MAX_SKILL_NUM; i++)
        if (sPrepEquipSkillListExt[i] & 1)
            sPrepEquipSkillList.sid[sPrepEquipSkillList.amt++] = i;
}

STATIC_DECLAR void UpdatePrepEquipSkillList(struct Unit * unit)
{
    int i;

    ResetPrepEquipSkillList();

    /* Todo */
    for (i = 1; i < 0x100; i++)
        RegisterToPrepEquipSkillListExt(i);

    SetupPrepEquipReal();
    sPrepEquipSkillList.uid = unit->index;
}

struct PrepEquipSkillList * GetPrepEquipSkillList(struct Unit * unit)
{
    if (sPrepEquipSkillList.uid != unit->index)
        UpdatePrepEquipSkillList(unit);

    return &sPrepEquipSkillList;
}
