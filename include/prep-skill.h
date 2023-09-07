#pragma once

#include "global.h"
#include "proc.h"
#include "prepscreen.h"

#include "skill-system.h"

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
void PrepSkill_InitTexts(void);

/* On select skills */
enum PrepSkill2ScrollType {
    PREP_SKILL2_SCROLL_NOPE = 0,
    PREP_SKILL2_SCROLL_UP,
    PREP_SKILL2_SCROLL_DOWN,
};

struct ProcPrepSkill2 {
    PROC_HEADER;
    struct Unit * unit;
    u8 hand_pos;
    u8 hand_x, hand_y;
    u8 left_line, right_line;
    u8 scroll; /* 0 = no scroll, 1 = up, 2 = down */
};

enum ProcPrepSkill2Label {
    PL_PREPSKILL2_INIT,
    PL_PREPSKILL2_IDLE,
    PL_PREPSKILL2_PRESS_A_ADD,
    PL_PREPSKILL2_PRESS_A_ADD_FAILED,
    PL_PREPSKILL2_PRESS_A_REMOVE,
    PL_PREPSKILL2_PRESS_A_REMOVE_FAILED,
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

enum PrepSkill2ListConfig {
    PREP_SRLIST_LENGTH = 7,
    PREP_SRLIST_HEIGHT = 4,

    PREP_SLLIST_LENGTH = 5,
    PREP_SLLIST_HEIGHT = 5,
};

#define PREP_SRLIST_OFFSET(x, y) ((y) * PREP_SRLIST_LENGTH + (x))
#define PREP_SLLIST_OFFSET(x, y) ((y) * PREP_SLLIST_LENGTH + (x))

/* PrepSkill objs */
struct ProcPrepSkillObj {
    PROC_HEADER;
    struct Unit * unit;
    bool active;
    bool reload;
};

void NewPrepSkillObj(struct ProcPrepSkill2 * pproc);
void RegisterPrepSkillObjReload(void);
void EndPrepSkillObj(void);
void EnablePrepSkillObj(void);
void DisablePrepSkillObj(void);

extern const u8 Gfx_ObjSkill[];
extern const u16 Pal_ObjSkill[];

extern const u8 Gfx_ObjWindow[];
extern const u16 Pal_ObjWindow[];

void PrepSkill2_DrawDrawSkillDesc(struct ProcPrepSkill2 * proc);

/* Some vanilla declaration */
extern struct Text gPrepUnitTexts[];
void PrepUnit_DrawSMSAndObjs(struct ProcPrepUnit * proc);
void PrepUnit_InitSMS(struct ProcPrepUnit * proc);
void PrepUnit_DrawUnitListNames(struct ProcPrepUnit * proc, int line);
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
