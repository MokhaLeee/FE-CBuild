#pragma once

#include "global.h"
#include "bmunit.h"

#include "common-chax.h"
#include "efx-anim.h"

#define MAX_SKILL_NUM 0xFF
#define SKILL_VALID(sid) ((sid > 0) && (sid < MAX_SKILL_NUM))
#define SKILL_ICON(sid) ((1 << 8) + (sid))

#define UNIT_RAM_SKILLS_LEN 6
#define UNIT_RAM_SKILLS(unit) ((u8 *)((unit)->supports))

#define STAT_SKILL_NUM_MAX 8

struct SkillInfo {
    const u8 * icon;
    u16 msg;
};

extern const struct SkillInfo gSkillInfos[0x100];
const u8 * GetSkillIcon(const u8 sid);
u16 GetSkillDesc(const u8 sid);
const char * GetSkillName(const u8 sid);

/* Judge list */
#define SKILL_LIST_MAX_AMT 15
struct SkillList {
    s8 uid;
    u8 amt;
    u8 sid[SKILL_LIST_MAX_AMT];
};

struct SkillList * GetUnitSkillList(struct Unit * unit);
void ResetSkillLists(void);
void DisableUnitSkills(struct Unit * unit);

/* Skill tetsers */
bool SkillTesterBasic(struct Unit * unit, const u8 sid);
bool SkillTesterFast(struct Unit * unit, const u8 sid);
extern bool (* const SkillTester)(struct Unit * unit, const u8 sid);

/* Prep equip skill list */
struct PrepEquipSkillList {
    s8 uid;
    u8 amt;
    u8 sid[0xFE];
};

void ResetPrepEquipSkillList(void);
struct PrepEquipSkillList * GetPrepEquipSkillList(struct Unit * unit);

/* Game data */
#define SKILL_ROM_DATA_AMT 5
struct SkillPreloadConf {
    /* Unit can learn 5 skills on lv0/5/10/15/20 */
    u8 skills[SKILL_ROM_DATA_AMT * (UNIT_RECORDED_LEVEL_MAX / 5 + 1)];
};

extern const struct SkillPreloadConf gSkillPreloadPData[0x100], gSkillPreloadJData[0x100];

extern const u8 gConstSkillPTable[0x100];
extern const u8 gConstSkillJTable[0x100];

struct SkillAnimInfo {
    u8 aid;
    u8 priority;
    u16 sfx;
};

enum SkillAnimPriorityConfig {
    EFX_PRIORITY_LOW = 0x1,
    EFX_PRIORITY_NORMAL,
    EFX_PRIORITY_HIGH,
    EFX_PRIORITY_HIGHHIGH,
};

extern const struct SkillAnimInfo gSkillAnimInfos[0x100];

int GetEfxSkillIndex(const u8 sid);
int GetEfxSkillPriority(const u8 sid);
int GetEfxSkillSfx(const u8 sid);

/* Efx skill */
extern struct EfxAnimConf const * const gEfxSkillAnims[0x100];
const struct EfxAnimConf * GetEfxSkillConf(const u8 aid);

/* Miscs */
bool IsSkillLearned(struct Unit * unit, const u8 sid);
void LearnSkill(struct Unit * unit, const u8 sid);
void ForgetSkill(struct Unit * unit, const u8 sid);
void ResetUnitLearnedSkillLists(void);                      /* GameInitHook */
void SaveUnitLearnedSkillLists(u8 * dst, const u32 size);   /* SaveData */
void LoadUnitLearnedSkillLists(u8 * src, const u32 size);   /* LoadData */

void UnitAutoLoadSkills(struct Unit * unit);
bool CanRemoveSkill(struct Unit * unit, const u8 sid);
int RemoveSkill(struct Unit * unit, const u8 sid);
int AddSkill(struct Unit * unit, const u8 sid);
