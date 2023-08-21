#pragma once

#include "global.h"
#include "bmunit.h"

#include "efx-anim.h"

#define MAX_SKILL_NUM 0xFF
#define SKILL_VALID(sid) ((sid > 0) && (sid < MAX_SKILL_NUM))
#define SKILL_ICON(index) ((1 << 8) + (index))

struct SkillInfo {
    const u8 * icon;
    u16 msg_desc;
};

extern const struct SkillInfo gSkillInfos[0x100];

struct SkillAnimInfo {
    u8 index;
    u8 priority;
    u16 sfx;
};

extern const struct SkillAnimInfo gSkillAnimInfos[0x100];

extern struct EfxAnimConf const * const gEfxSkillAnims[];

/* Judge list */
#define SKILL_MAX_AMT 0x1E
struct SkillList {
    u8 pid;
    u8 cnt;
    u8 data[SKILL_MAX_AMT];
};

void RegisterSyncSkillList(void);
struct SkillList * GetUnitSkillList(struct Unit * unit);
int GetSkillListAmt(struct Unit * unit);
void DisableUnitSkills(struct Unit * unit);

/* Skill tetsers */
bool SkillTesterBasic(struct Unit * unit, const u8 skill);
bool SkillTesterFast(struct Unit * unit, const u8 skill);
extern bool (* const SkillTester)(struct Unit * unit, const u8 skill);

/* Game data */
#define SKILL_ROM_DATA_AMT 5
struct SkillRomData {
    /* Unit can learn 5 skills on lv0/5/10/15/20 */
    u8 skills[SKILL_ROM_DATA_AMT * (UNIT_LEVEL_MAX / 5 + 1)];
};

extern const struct SkillRomData gSkillRomPData[0x100], gSkillRomJData[0x100];
