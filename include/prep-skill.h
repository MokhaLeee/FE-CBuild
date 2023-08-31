#pragma once

#include "global.h"
#include "proc.h"
#include "prepscreen.h"

void StartPrepEquipScreen(struct ProcAtMenu * parent);

/* On select unit */
struct ProcPrepSkill1 {
    PROC_HEADER;
    u8 cur_counter; // Total unit number to be on battle
    u8 max_counter; // Total unit number can be on battle
    u16 list_num_pre; // pre unit index in prep-list(for scroll)
    u16 list_num_cur; // current unit index in prep-list
    u16 yDiff_cur; // y Pos offset of Unit SMS (current)
    u8 scroll_val; // each px to scroll at each frame
    u8 button_blank;
};
