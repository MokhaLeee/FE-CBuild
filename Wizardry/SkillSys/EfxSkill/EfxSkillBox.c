#include "global.h"
#include "icon.h"
#include "ctc.h"
#include "anime.h"
#include "bmlib.h"
#include "ekrbattle.h"

#include "common-chax.h"
#include "icon-rework.h"
#include "combat-art.h"

struct ProcEfxskillbox {
    PROC_HEADER;
    int timer;
    int msg;
    const u8 * icon;
    struct Anim * anim;
    struct Anim * animbox;
};

#define ICON_OBJ_CHR 0x40
#define ICON_OBJ_PAL 0x2

STATIC_DECLAR const u32 instr_unit[6] = {
    0x40000000, 0, 0, 1, 0, 0
};

STATIC_DECLAR const u32 anim_instr[2] = {
    (u32)(instr_unit) + 1,
    0x80000000
};

STATIC_DECLAR void EfxSkillBoxOnDraw(struct ProcEfxskillbox * proc)
{
    struct Anim * animbox;

    LoadIconPalette(0, 0x10 + ICON_OBJ_PAL);
    Copy2dChr(proc->icon, OBJ_VRAM0 + ICON_OBJ_CHR * 0x20, 2, 2);

    animbox = AnimCreate(anim_instr, 0x96);
    proc->animbox = animbox;
    animbox->oam2Base = OAM2_PAL(ICON_OBJ_PAL) + OAM2_LAYER(0b01) + OAM2_CHR(ICON_OBJ_CHR);
    animbox->yPosition = 0x60 - 0x3;

    if (GetAnimPosition(proc->anim) == EKR_POS_L)
        animbox->xPosition = 0xE0;
    else
        animbox->xPosition = 0x00;
}

STATIC_DECLAR void EfxSkillBoxIdle(struct ProcEfxskillbox * proc)
{
    if (++proc->timer > 0x30)
    {
        AnimDelete(proc->animbox);
        Proc_Break(proc);
    }
}

STATIC_DECLAR const struct ProcCmd ProcScr_EfxSkillBox[] = {
    PROC_NAME("EfxSkillBox"),
    PROC_YIELD,
    PROC_CALL(EfxSkillBoxOnDraw),
    PROC_REPEAT(EfxSkillBoxIdle),
    PROC_END
};

void NewEfxSkillBox(struct Anim * anim, int msg, const u8 * icon)
{
    struct ProcEfxskillbox * proc;
    proc = Proc_Start(ProcScr_EfxSkillBox, PROC_TREE_3);
    proc->timer = 0;
    proc->anim = anim;
    proc->msg = msg;
    proc->icon = icon;
}

bool EfxSkillBoxExists(void)
{
    return !!Proc_Find(ProcScr_EfxSkillBox);
}
