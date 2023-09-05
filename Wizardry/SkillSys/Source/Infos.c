#include "global.h"

#include "common-chax.h"
#include "skill-system.h"
#include "debug-kit.h"
#include "constants/icons.h"

const u8 * GetSkillIcon(const u8 sid)
{
    const u8 * icon = NULL;
    if (SKILL_VALID(sid))
        icon = gSkillInfos[sid].icon;

    if (!icon)
    {
        LogPrintf("%s: Try get invalid skill info: %#X", __func__, sid);
        icon = ICON_SkillIcon_WIP;
    }
    return icon;
}

u16 GetSkillDesc(const u8 sid)
{
    if (SKILL_VALID(sid))
        return gSkillInfos[sid].msg;

    LogPrintf("%s: Try get invalid skill info: %#X", __func__, sid);
    return 0;
}

const char * GetSkillName(const u8 sid)
{
    char * str, * it;
    u16 msg = GetSkillDesc(sid);
    if (msg == 0)
    {
        LogPrintf("%s: Get invalid desc: %#X", __func__, sid);
        return "W.I.P";
    }

    str = GetStringFromIndex(msg);
    for (it = str; *it; ++it)
    {
        if (*it == ':')
        {
            *it = '\0';
            break;
        }
    }
    return str;
}

int GetEfxSkillIndex(const u8 sid)
{
    if (SKILL_VALID(sid))
        return gSkillAnimInfos[sid].aid;

    LogPrintf("%s: Try get invalid skill info: %#X", __func__, sid);
    return 0;
}

int GetEfxSkillPriority(const u8 sid)
{
    if (SKILL_VALID(sid))
        return gSkillAnimInfos[sid].priority;

    LogPrintf("%s: Try get invalid skill info: %#X", __func__, sid);
    return 0;
}

int GetEfxSkillSfx(const u8 sid)
{
    if (SKILL_VALID(sid))
        return gSkillAnimInfos[sid].sfx;

    LogPrintf("%s: Try get invalid skill info: %#X", __func__, sid);
    return 0;
}

const struct EfxAnimConf * GetEfxSkillConf(const u8 aid)
{
    return gpEfxSkillAnims[GetEfxSkillIndex(aid)];
}
