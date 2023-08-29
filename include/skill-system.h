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

static inline const u8 * GetSkillInfoIcon(const u8 sid)
{
    return gSkillInfos[sid].icon;
}

static inline u16 GetSkillInfoDesc(const u8 sid)
{
    return gSkillInfos[sid].msg;
}

/* Judge list */
#define SKILL_LIST_MAX_AMT 0x1E
struct SkillList {
    u8 uid;
    u8 amt;
    u8 data[SKILL_LIST_MAX_AMT];
};

struct SkillList * GetUnitSkillList(struct Unit * unit);
void ResetSkillLists(void);

static inline int GetSkillListAmt(struct Unit * unit)
{
    return GetUnitSkillList(unit)->amt;
}

static inline void DisableUnitSkills(struct Unit * unit)
{
    GetUnitSkillList(unit)->amt = 0;
}

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

/* Efx skill */
extern struct EfxAnimConf const * const gEfxSkillAnims[];

struct SkillAnimInfo {
    u8 index;
    u8 priority;
    u16 sfx;
};

extern const struct SkillAnimInfo gSkillAnimInfos[0x100];

static inline int GetEfxSkillIndex(const u8 sid)
{
    return gSkillAnimInfos[sid].index;
}

static inline const struct EfxAnimConf * GetEfxSkillConf(const u8 sid)
{
    return gEfxSkillAnims[GetEfxSkillIndex(sid)];
}

static inline int GetEfxSkillPriority(const u8 sid)
{
    return gSkillAnimInfos[sid].priority;
}

static inline int GetEfxSkillSfx(const u8 sid)
{
    return gSkillAnimInfos[sid].sfx;
}
