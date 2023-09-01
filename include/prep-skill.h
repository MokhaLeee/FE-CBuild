#pragma once

#include "global.h"
#include "proc.h"
#include "prepscreen.h"

void StartPrepEquipScreen(struct ProcAtMenu * parent);

/* On select unit */
#define ProcPrepSkill1 ProcPrepUnit /* Yeah, we directlt use PrepUnitList */

enum ProcPrepSkill1Label {
    PL_PREPSKILL1_INIT,
    PL_PREPSKILL1_IDLE,
    PL_PREPSKILL1_PRESS_A,
    PL_PREPSKILL1_PRESS_B,
    PL_PREPSKILL1_PRESS_R,
    PL_PREPSKILL1_PRESS_START,
    PL_PREPSKILL1_END,
};

void PrepSkill_DrawLeftSkillIcon(struct Unit * unit);

/* On select skills */
struct ProcPrepSkill2 {
    PROC_HEADER;
    struct Unit * unit;
    u8 pos;
};

enum ProcPrepSkill2Label {
    PL_PREPSKILL2_INIT,
    PL_PREPSKILL2_IDLE,
    PL_PREPSKILL2_PRESS_A,
    PL_PREPSKILL2_PRESS_B,
    PL_PREPSKILL2_PRESS_R,
    PL_PREPSKILL2_PRESS_START,
    PL_PREPSKILL2_END,
};

void StartPrepSelectSkillScreen(struct ProcPrepSkill1 * pproc);

extern const u8 Gfx_PrepPickSkillScreen[];
extern const u8 Gfx_PrepSkillScreen[];
extern const u8 Gfx_PrepSkillScreen2[];
extern const u8 Tsa_PrepSubPickSkillScreen[];
extern const u16 Pal_PrepSkillScreen[];

/* Some vanilla declaration */
extern struct Text gPrepUnitTexts[];
void PrepUnit_DrawSMSAndObjs(struct ProcPrepUnit * proc);
void PrepUnit_InitSMS(struct ProcPrepUnit * proc);
void PrepUnit_DrawUnitListNames(struct ProcPrepUnit * proc, int line);
void PrepUnit_InitTexts(void);
void PrepUnit_InitGfx(void);
void PrepUnit_DrawUnitItems(struct Unit * unit);
void PrepUnit_DrawLeftUnitName(struct Unit * unit);
void PrepUnit_DrawLeftUnitNameCur(struct ProcPrepUnit * proc);
s8 ShouldPrepUnitMenuScroll(struct ProcPrepUnit * proc);
void sub_809AE10(struct ProcPrepUnit * proc);
void PrepUpdateMenuTsaScroll(int val);
void PrepUnitDisableDisp(void);
void PrepUnitEnableDisp(void);
void sub_809B504(struct ProcPrepUnit * proc);
void sub_809B014(void);
void sub_809B520(struct ProcPrepUnit * proc);
