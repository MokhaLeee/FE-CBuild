#pragma once

#include "global.h"
#include "bmunit.h"

#include "common-chax.h"
#include "efx-anim.h"

#define MAX_SKILL_NUM 0xFF
#define SKILL_VALID(sid) ((sid > 0) && (sid < MAX_SKILL_NUM))
#define SKILL_ICON(sid) ((1 << 8) + (sid))

struct SkillInfo {
    const u8 * icon;
    u16 msg;
};

extern const struct SkillInfo gSkillInfos[0x100];
const u8 * GetSkillInfoIcon(const u8 sid);
u16 GetSkillInfoDesc(const u8 sid);

/* Judge list */
#define SKILL_LIST_MAX_AMT 0x1E
struct SkillList {
    s8 uid;
    u8 amt;
    u8 sid[SKILL_LIST_MAX_AMT];
};

struct SkillList * GetUnitSkillList(struct Unit * unit);
void ResetSkillLists(void);
int GetSkillListAmt(struct Unit * unit);
void DisableUnitSkills(struct Unit * unit);

/* Skill tetsers */
bool SkillTesterBasic(struct Unit * unit, const u8 sid);
bool SkillTesterFast(struct Unit * unit, const u8 sid);
extern bool (* const SkillTester)(struct Unit * unit, const u8 sid);

/* Game data */
#define SKILL_ROM_DATA_AMT 5
struct SkillRomData {
    /* Unit can learn 5 skills on lv0/5/10/15/20 */
    u8 skills[SKILL_ROM_DATA_AMT * (UNIT_LEVEL_MAX_RE / 5 + 1)];
};

extern const struct SkillRomData gSkillRomPData[0x100], gSkillRomJData[0x100];

struct SkillAnimInfo {
    u8 aid;
    u8 priority;
    u16 sfx;
};

extern const struct SkillAnimInfo gSkillAnimInfos[0x100];

int GetEfxSkillIndex(const u8 sid);
int GetEfxSkillPriority(const u8 sid);
int GetEfxSkillSfx(const u8 sid);

/* Efx skill */
extern struct EfxAnimConf const * const * const gpEfxSkillAnims;
const struct EfxAnimConf * GetEfxSkillConf(const u8 aid);
