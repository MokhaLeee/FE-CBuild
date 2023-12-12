#include "global.h"

#include "common-chax.h"
#include "skill-system.h"
#include "debug-kit.h"
#include "constants/gfx.h"

const u8 * GetSkillIcon(const u8 sid)
{
    const u8 * icon = NULL;
    if (SKILL_VALID(sid))
        icon = gSkillInfos[sid].icon;

    if (!icon)
    {
        LogPrintf("%s: Try get invalid skill info: %#X", __func__, sid);
        icon = GFX_SkillIcon_WIP;
    }
    return icon;
}

u16 GetSkillDescMsg(const u8 sid)
{
    if (SKILL_VALID(sid))
        return gSkillInfos[sid].desc;

    LogPrintf("%s: Try get invalid skill info: %#X", __func__, sid);
    return 0;
}

char * GetSkillDescStr(const u8 sid)
{
    u16 msg = GetSkillDescMsg(sid);
    if (msg != 0)
        return GetStringFromIndex(msg);

    return NULL;
}

char * SkillDescToName(char * str)
{
    char * it;
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

char * GetSkillNameStrFormDesc(const u8 sid)
{
    char * str;
    u16 msg = GetSkillDescMsg(sid);
    if (msg == 0)
    {
        LogPrintf("%s: Get invalid desc: %#X", __func__, sid);
        return "W.I.P";
    }

    str = GetStringFromIndex(msg);
    return SkillDescToName(str);
}

char * GetSkillNameStr(const u8 sid)
{
    if (SKILL_VALID(sid) && gSkillInfos[sid].name != 0)
        return GetStringFromIndex(gSkillInfos[sid].name);

    return GetSkillNameStrFormDesc(sid);
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
    u8 priority = gSkillAnimInfos[sid].priority;
    if (priority == 0)
        priority = EFX_PRIORITY_NORMAL;

    return priority;
}

int GetEfxSkillSfx(const u8 sid)
{
    u16 sfx = gSkillAnimInfos[sid].sfx;
    if (sfx == 0)
        sfx = 0x3D1;

    return sfx;
}

const struct EfxAnimConf * GetEfxSkillConf(const u8 aid)
{
    struct EfxAnimConf const * conf = gEfxSkillAnims[aid];
    if (!conf)
        conf = &EfxSkillVanilla;

    return conf;
}
