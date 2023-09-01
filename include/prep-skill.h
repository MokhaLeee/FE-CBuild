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
    PL_PREPSKILL1_PRESS_START,
    PL_PREPSKILL1_END,
};

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
