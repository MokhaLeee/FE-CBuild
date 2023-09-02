#include "global.h"
#include "hardware.h"
#include "bmlib.h"
#include "ctc.h"
#include "ap.h"
#include "icon.h"

#include "common-chax.h"
#include "skill-system.h"
#include "prep-skill.h"

enum PrepSkillObjConfigs {
    SKILLOBJ_VOBJ = 0x3000,
    SKILLOBJ_PAL = 0x3,

    OBJWINDOW_VOBJ = 0x4000,
    OBJWINDOW_PAL = 0x6,

    VOBJ_SKILL_ICONS = 0x4400,
};

STATIC_DECLAR void ReloadPrepSkill2IconGfx(struct ProcPrepSkillObj * proc)
{
    int x, y;
    struct ProcPrepSkill2 * pproc = proc->proc_parent;
    struct PrepEquipSkillList * rlist = proc->data;

    for (y = 0; y < PREP_SRLIST_HEIGHT; y++)
    {
        for (x = 0; x < PREP_SRLIST_LENGTH; x++)
        {
            int off  = PREP_SRLIST_OFFSET(x, y);
            int real = PREP_SRLIST_OFFSET(x, pproc->right_line + y);
            u8 sid = rlist->sid[real];
            u8 * dst = real < 0x10
                     ? OBJ_VRAM0 + VOBJ_SKILL_ICONS + 0x40 * off
                     : OBJ_VRAM0 + VOBJ_SKILL_ICONS + 0x40 * (off + 0x10);

            if (real >= rlist->amt)
                break;

            /* Copy gfx to ObjTile */
            Copy2dChr(GetSkillIcon(sid), dst, 2, 2);
        }
    }
    proc->reload = false;
}

STATIC_DECLAR void PutPrepSkill2IconSprits(struct ProcPrepSkillObj * proc)
{
    int x, y;
    struct ProcPrepSkill2 * pproc = proc->proc_parent;
    struct PrepEquipSkillList * rlist = proc->data;

    for (y = 0; y < PREP_SRLIST_HEIGHT; y++)
    {
        for (x = 0; x < PREP_SRLIST_LENGTH; x++)
        {
            int off  = PREP_SRLIST_OFFSET(x, y);
            int real = PREP_SRLIST_OFFSET(x, pproc->right_line + y);
            u8 * src = off < 0x10
                     ? OBJ_VRAM0 + VOBJ_SKILL_ICONS + 0x40 * off
                     : OBJ_VRAM0 + VOBJ_SKILL_ICONS + 0x40 * (off + 0x10);

            int ix = 0x72 + 0x10 * x;
            int iy = 0x1E + 0x10 * y;

            int oam2 = OAM2_PAL(SKILLOBJ_PAL) +
                       OAM2_LAYER(0b01) +
                       OAM2_CHR((u32)src / 0x20);

            if (real >= rlist->amt)
                break;

            PutSprite(5, ix, iy, gObject_16x16, oam2);
        }
    }
}

STATIC_DECLAR void PutPrepSkill2Suffix(struct ProcPrepSkillObj * proc)
{
    int x, y;
    struct ProcPrepSkill2 * pproc = proc->proc_parent;
    struct PrepEquipSkillList * rlist = proc->data;
    struct Unit * unit = pproc->unit;

    /* Draw R-list suffix */
    for (y = 0; y < PREP_SRLIST_HEIGHT; y++)
    {
        for (x = 0; x < PREP_SRLIST_LENGTH; x++)
        {
            int real = PREP_SRLIST_OFFSET(x, pproc->right_line + y);
            u8 sid = rlist->sid[real];

            if (real >= rlist->amt)
                break;

            if (SkillTester(unit, sid))
            {
                int ix = 0x72 + 0x10 * x + 8;
                int iy = 0x1E + 0x10 * y + 0;
                int oam2 = OAM2_PAL(SKILLOBJ_PAL) +
                           OAM2_LAYER(0b01) +
                           OAM2_CHR(SKILLOBJ_VOBJ / 0x20);

                if (CanRemoveSkill(unit, sid))
                    PutSprite(5, ix, iy, gObject_8x16, oam2);
                else
                    PutSprite(5, ix, iy, gObject_8x16, oam2 + 1);
            }
        }
    }
}

STATIC_DECLAR void PrepSkillObj_OnInit(struct ProcPrepSkillObj * proc)
{
    Decompress(Gfx_ObjSkill, OBJ_VRAM0 + SKILLOBJ_VOBJ);
    ApplyPalette(Pal_ObjSkill, SKILLOBJ_PAL + 0x10);

    Decompress(Gfx_ObjWindow, OBJ_VRAM0 + OBJWINDOW_VOBJ);
    ApplyPalette(Pal_ObjWindow, OBJWINDOW_PAL + 0x10);
}

STATIC_DECLAR void PrepSkillObjMain(struct ProcPrepSkillObj * proc)
{
    if (proc->reload)
        ReloadPrepSkill2IconGfx(proc);

    if (!proc->active)
        return;

    PutPrepSkill2IconSprits(proc);

    if(GetGameClock() & (1 << 5))
        PutPrepSkill2Suffix(proc);
}

STATIC_DECLAR const struct ProcCmd ProcScr_PrepSkillObj[] = {
    PROC_NAME("PrepSkillObj"),
    PROC_CALL(PrepSkillObj_OnInit),
    PROC_REPEAT(PrepSkillObjMain),
    PROC_END
};

void NewPrepSkillObj(struct ProcPrepSkill2 * pproc)
{
    struct ProcPrepSkillObj * proc;

    proc = Proc_Find(ProcScr_PrepSkillObj);

    if (!proc)
        proc = Proc_Start(ProcScr_PrepSkillObj, pproc);

    proc->data = GeneratePrepEquipSkillList(pproc->unit);
    proc->reload = true;
    proc->active = true;
}

void EndPrepSkillObj(void)
{
    Proc_EndEach(ProcScr_PrepSkillObj);
}

void RegisterPrepSkillObjReload(void)
{
    struct ProcPrepSkillObj * proc;
    proc = Proc_Find(ProcScr_PrepSkillObj);

    if (proc)
        proc->reload = true;
}

void EnablePrepSkillObj(void)
{
    struct ProcPrepSkillObj * proc;
    proc = Proc_Find(ProcScr_PrepSkillObj);

    if (proc)
        proc->active = true;
}

void DisablePrepSkillObj(void)
{
    struct ProcPrepSkillObj * proc;
    proc = Proc_Find(ProcScr_PrepSkillObj);

    if (proc)
        proc->active = false;
}
