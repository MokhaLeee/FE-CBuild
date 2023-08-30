#include "global.h"

#include "common-chax.h"
#include "skill-system.h"
#include "debug-kit.h"

const u8 * GetSkillInfoIcon(const u8 sid)
{
    if (SKILL_VALID(sid))
        return gSkillInfos[sid].icon;

    LogErrorf("%s: Try get invalid skill info: %#X", __func__, sid);
    return NULL;
}

u16 GetSkillInfoDesc(const u8 sid)
{
    if (SKILL_VALID(sid))
        return gSkillInfos[sid].msg;

    LogErrorf("%s: Try get invalid skill info: %#X", __func__, sid);
    return 0;
}

int GetEfxSkillIndex(const u8 sid)
{
    if (SKILL_VALID(sid))
        return gSkillAnimInfos[sid].aid;

    LogErrorf("%s: Try get invalid skill info: %#X", __func__, sid);
    return 0;
}

int GetEfxSkillPriority(const u8 sid)
{
    if (SKILL_VALID(sid))
        return gSkillAnimInfos[sid].priority;

    LogErrorf("%s: Try get invalid skill info: %#X", __func__, sid);
    return 0;
}

int GetEfxSkillSfx(const u8 sid)
{
    if (SKILL_VALID(sid))
        return gSkillAnimInfos[sid].sfx;

    LogErrorf("%s: Try get invalid skill info: %#X", __func__, sid);
    return 0;
}

const struct EfxAnimConf * GetEfxSkillConf(const u8 aid)
{
    return gpEfxSkillAnims[GetEfxSkillIndex(aid)];
}
