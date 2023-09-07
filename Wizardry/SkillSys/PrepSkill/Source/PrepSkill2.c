/**
 * On select skills
 */

#include "global.h"
#include "proc.h"
#include "prepscreen.h"
#include "hardware.h"
#include "fontgrp.h"
#include "soundwrapper.h"
#include "statscreen.h"
#include "bm.h"
#include "icon.h"
#include "bmlib.h"
#include "uiutils.h"
#include "constants/video-global.h"

#include "common-chax.h"
#include "skill-system.h"
#include "prep-skill.h"

STATIC_DECLAR void ProcPrepSkill2_OnEnd(struct ProcPrepSkill2 * proc)
{
    PrepSetLatestCharId(proc->unit->pCharacterData->number);
    EndPrepSkillObj();
}

STATIC_DECLAR void ProcPrepSkill2_InitScreen(struct ProcPrepSkill2 * proc)
{
    u16 BgConfig[12] = {
        // tile offset    map offset    screen size
        0x0000,            0xE000,        0,            // BG 0
        0x0000,            0xE800,        0,            // BG 1
        0x0000,            0xF000,        0,            // BG 2
        0x8000,            0xF800,        0,            // BG 3
    };

    SetupBackgrounds(BgConfig);
    SetDispEnable(0, 0, 0, 0, 0);
    BG_Fill(gBG0TilemapBuffer, 0);
    BG_Fill(gBG1TilemapBuffer, 0);
    BG_Fill(gBG2TilemapBuffer, 0);

    gLCDControlBuffer.bg0cnt.priority = 2;
    gLCDControlBuffer.bg1cnt.priority = 2;
    gLCDControlBuffer.bg2cnt.priority = 1;
    gLCDControlBuffer.bg3cnt.priority = 3;

    BG_SetPosition(BG_0, 0, 0);
    BG_SetPosition(BG_1, 0, 0);
    BG_SetPosition(BG_2, 0, 0);
    BG_SetPosition(BG_3, 0, 0);

    /* Init text */
    PrepUnit_InitTexts();

    /* Init gfx */
    ResetIconGraphics_();
    LoadUiFrameGraphics();
    LoadObjUIGfx();
    LoadIconPalettes(BGPAL_ICONS);

    EndGreenText();

    BG_EnableSyncByMask(BG0_SYNC_BIT | BG1_SYNC_BIT | BG2_SYNC_BIT);
    SetDefaultColorEffects();

    /* Init BG gfx */
    ResetIconGraphics_();
    LoadUiFrameGraphics();
    LoadObjUIGfx();

    LoadIconPalettes(4); // item icon

    Decompress(Gfx_PrepSkillScreen2, (void*)0x06006000);
    Decompress(Gfx_PrepPickSkillScreen, (void*)0x06000440);

    Decompress(Tsa_PrepSubPickSkillScreen, gGenericBuffer);
    CallARM_FillTileRect(gBG1TilemapBuffer, gGenericBuffer, 0x1000);

    CopyToPaletteBuffer(Pal_PrepSkillScreen, 0x1E0, 0x20);
    CopyToPaletteBuffer(Pal_PrepSkillScreen, 0x320, 0x20);
    EnablePaletteSync();

    /* Hand cursor */
    ResetPrepScreenHandCursor(proc);
    sub_80AD4A0(0x600, 0x1);

    ShowPrepScreenHandCursor(
        0x74 + 0x10 * proc->hand_x,
        0x20 + 0x10 * proc->hand_y,
        0x0, 0x800);

    NewPrepSkillObj(proc);

    /* Left pannel */
    PrepSkill_DrawLeftSkillIcon(proc->unit);
    PrepUnit_DrawLeftUnitName(proc->unit);

    RestartMuralBackground();
}

STATIC_DECLAR void ProcPrepSkill2_Idle(struct ProcPrepSkill2 * proc)
{
    bool hand_moved = false;
    int ret;
    int repeated = gKeyStatusPtr->repeatedKeys;

    /**
     * L-list: struct SkillList * GetUnitSkillList(struct Unit * unit)
     * R-list: struct PrepEquipSkillList * GetPrepEquipSkillList(struct Unit * unit)
     */

    struct SkillList * llist = GetUnitSkillList(proc->unit);
    struct PrepEquipSkillList * rlist = GetPrepEquipSkillList(proc->unit);

    if (B_BUTTON & gKeyStatusPtr->newKeys)
    {
        PlaySoundEffect(0x6B);
        Proc_Goto(proc, PL_PREPSKILL2_PRESS_B);
        return;
    }

    if (A_BUTTON & gKeyStatusPtr->newKeys)
    {
        if (proc->hand_pos == POS_R)
        {
            u8 sid =  rlist->sid[PREP_SRLIST_OFFSET(proc->hand_x, proc->right_line + proc->hand_y)];

            if (!SkillTester(proc->unit, sid))
            {
                ret = AddSkill(proc->unit, sid);
                if (ret)
                {
                    PlaySoundEffect(0x6C);
                    Proc_Goto(proc, PL_PREPSKILL2_PRESS_A_ADD_FAILED);
                }
                else
                {
                    PlaySoundEffect(0x6A);
                    Proc_Goto(proc, PL_PREPSKILL2_PRESS_A_ADD);
                }
                return;
            }
            else
            {
                ret = RemoveSkill(proc->unit, sid);
                if (ret)
                {
                    PlaySoundEffect(0x6C);
                    Proc_Goto(proc, PL_PREPSKILL2_PRESS_A_REMOVE_FAILED);
                }
                else
                {
                    PlaySoundEffect(0x6A);
                    Proc_Goto(proc, PL_PREPSKILL2_PRESS_A_REMOVE);
                }
                return;
            }
        }
    }

    if (R_BUTTON & gKeyStatusPtr->newKeys)
    {
        Proc_Goto(proc, PL_PREPSKILL2_PRESS_R);
        return;
    }

    if (DPAD_LEFT & repeated)
    {
        if (proc->hand_x != 0)
        {
            hand_moved = true;
            proc->hand_x--;
        }
        else if (proc->hand_pos == POS_R)
        {
            if (llist->amt > 0)
            {
                proc->hand_pos = POS_L;
                proc->left_line = 0;
                proc->hand_x = 0;
                proc->hand_y = 0;
                hand_moved = true;
            }
        }
    }

    if (DPAD_RIGHT & repeated)
    {
        if (proc->hand_pos == POS_R)
        {
            int next = PREP_SRLIST_OFFSET(proc->hand_x + 1, proc->right_line + proc->hand_y);
            if (next < rlist->amt)
            {
                if (proc->hand_x < (PREP_SRLIST_LENGTH - 1))
                    proc->hand_x++;
                else
                {
                    proc->hand_x = 0;
                    proc->hand_y++;
                }

                hand_moved = true;
            }
        }
        else if (proc->hand_pos == POS_L)
        {
            if (proc->hand_x == (PREP_SLLIST_LENGTH - 1) && rlist->amt > 0)
            {
                proc->hand_pos = POS_R;
                proc->left_line = 0;
                proc->hand_x = 0;
                proc->hand_y = 0;
                hand_moved = true;
            }
            else
            {
                int next = PREP_SLLIST_OFFSET(proc->hand_x + 1, proc->left_line + proc->hand_y);
                if (next < llist->amt)
                {
                    if (proc->hand_x < (PREP_SLLIST_LENGTH - 1))
                        proc->hand_x++;
                    else
                    {
                        proc->hand_x = 0;
                        proc->hand_y++;
                    }
                    hand_moved = true;
                }
            }
        }
    }

    if (DPAD_UP & repeated)
    {
        if (proc->hand_pos == POS_L)
        {
            if (proc->hand_y > 0)
            {
                hand_moved = true;
                proc->hand_y--;
            }
        }
        else if (proc->hand_pos == POS_R)
        {
            int next = PREP_SRLIST_OFFSET(proc->hand_x, proc->right_line + proc->hand_y - 1);
            if (next >= 0)
            {
                if (proc->hand_y > 0)
                {
                    hand_moved = true;
                    proc->hand_y--;
                }
                else
                {
                    hand_moved = true;
                    proc->right_line--;
                    RegisterPrepSkillObjReload();
                }
            }
        }
    }

    if (DPAD_DOWN & repeated)
    {
        if (proc->hand_pos == POS_L)
        {
            int next = PREP_SRLIST_OFFSET(proc->hand_x, proc->left_line + proc->hand_y + 1);
            if (next < llist->amt)
            {
                proc->hand_y++;
                hand_moved = true;
            }
        }
        else if (proc->hand_pos == POS_R)
        {
            int next = PREP_SRLIST_OFFSET(proc->hand_x, proc->right_line + proc->hand_y + 1);
            if (next < rlist->amt)
            {
                if (proc->hand_y < (PREP_SRLIST_HEIGHT - 1))
                {
                    proc->hand_y++;
                    hand_moved = true;
                }
                else
                {
                    hand_moved = true;
                    proc->right_line++;
                    RegisterPrepSkillObjReload();
                }
            }
        }
    }

    if (!hand_moved)
        return;

    if (proc->hand_pos == POS_R)
        ShowPrepScreenHandCursor(
            0x74 + 0x10 * proc->hand_x,
            0x20 + 0x10 * proc->hand_y,
            0x0, 0x800);
    else
        ShowPrepScreenHandCursor(
            0x10 + 0x10 * proc->hand_x,
            0x30 + 0x10 * proc->hand_y,
            0x0, 0x800);
}

STATIC_DECLAR void ProcPrepSkill2_EndMiscEffectForStatScreen(struct ProcPrepSkill2 * proc)
{
    EndMenuScrollBar();
    EndAllParallelWorkers();
	sub_80AD2D4();
	EndPrepScreenHandCursor();
	EndHelpPromptSprite();
	sub_80ACDDC();
	EndMuralBackground_();

    EndPrepSkillObj();
}

STATIC_DECLAR void ProcPrepSkill2_NewStatScreen(struct ProcPrepSkill2 * proc)
{
    SetStatScreenConfig(STATSCREEN_CONFIG_NONUNK16 | STATSCREEN_CONFIG_NONDEAD);
    StartStatScreen(proc->unit, proc);
}

STATIC_DECLAR void ProcPrepSkill2_UpdateListFromStatScreen(struct ProcPrepSkill2 * proc)
{
    int num;
    struct ProcPrepSkill1 * pproc = proc->proc_parent;

    MakePrepUnitList();
    num = GetLatestUnitIndexInPrepListByUId();
    pproc->list_num_pre = num;
    pproc->list_num_cur = num;

    /* Reset */
    if (proc->unit != GetUnit(GetLastStatScreenUid()))
    {
        proc->unit = GetUnit(GetLastStatScreenUid());
        proc->hand_pos = POS_R;
        proc->hand_x = 0;
        proc->hand_y = 0;
        proc->left_line = 0;
        proc->right_line = 0;
        proc->scroll = PREP_SKILL2_SCROLL_NOPE;
    }
}

STATIC_DECLAR const struct ProcCmd ProcScr_PrepSkillSkillSel[] = {
    PROC_NAME("PrepSkillSkillSel"),
    PROC_YIELD,
    PROC_SET_END_CB(ProcPrepSkill2_OnEnd),

PROC_LABEL(PL_PREPSKILL2_INIT),
    PROC_CALL(ProcPrepSkill2_InitScreen),
    PROC_CALL_ARG(NewFadeIn, 0x10),
    PROC_WHILE(FadeInExists),

PROC_LABEL(PL_PREPSKILL2_IDLE),
    PROC_REPEAT(ProcPrepSkill2_Idle),

PROC_LABEL(PL_PREPSKILL2_PRESS_A_ADD_FAILED),
PROC_LABEL(PL_PREPSKILL2_PRESS_A_REMOVE_FAILED),
    PROC_GOTO(PL_PREPSKILL2_IDLE),

PROC_LABEL(PL_PREPSKILL2_PRESS_A_ADD),
PROC_LABEL(PL_PREPSKILL2_PRESS_A_REMOVE),
    PROC_GOTO(PL_PREPSKILL2_INIT),

PROC_LABEL(PL_PREPSKILL2_PRESS_R),
    PROC_CALL(PrepUnitDisableDisp),
    PROC_SLEEP(0x2),
    PROC_CALL(ProcPrepSkill2_EndMiscEffectForStatScreen),
    PROC_CALL(ProcPrepSkill2_NewStatScreen),
    PROC_YIELD,
    PROC_CALL(ProcPrepSkill2_UpdateListFromStatScreen),
    PROC_CALL(ProcPrepSkill2_InitScreen),
    PROC_SLEEP(0x2),
    PROC_CALL(PrepUnitEnableDisp),
    PROC_GOTO(PL_PREPSKILL2_IDLE),

PROC_LABEL(PL_PREPSKILL2_PRESS_B),
    PROC_CALL_ARG(NewFadeOut, 0x10),
    PROC_WHILE(FadeOutExists),

PROC_LABEL(PL_PREPSKILL2_END),
    PROC_END
};

void StartPrepSelectSkillScreen(struct ProcPrepSkill1 * pproc)
{
    struct ProcPrepSkill2 * proc;
    EndAllParallelWorkers();
    proc = Proc_StartBlocking(ProcScr_PrepSkillSkillSel, pproc);
    proc->unit = GetUnitFromPrepList(pproc->list_num_cur);
    proc->hand_pos = POS_R;
    proc->hand_x = 0;
    proc->hand_y = 0;
    proc->left_line = 0;
    proc->right_line = 0;
    proc->scroll = PREP_SKILL2_SCROLL_NOPE;
}
