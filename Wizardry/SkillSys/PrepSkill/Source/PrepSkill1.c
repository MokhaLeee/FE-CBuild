/**
 * On select unit
 */

#include "global.h"
#include "proc.h"
#include "prepscreen.h"

#include "common-chax.h"
#include "prep-skill.h"

STATIC_DECLAR void ProcPrepSkill1_OnEnd(struct ProcPrepSkill1 * proc)
{
    struct ProcAtMenu * pproc = proc->proc_parent;
    pproc->state = 1; /* Unit Select */
    pproc->yDiff = proc->yDiff_cur;
    pproc->cur_counter = proc->cur_counter;
    PrepSetLatestCharId(GetUnitFromPrepList(proc->list_num_cur)->pCharacterData->number);
    EndMuralBackground_();
}

STATIC_DECLAR const struct ProcCmd ProcScr_PrepSkillUnitSel[] = {
    PROC_NAME("PrepSkillUnitSel"),
    PROC_YIELD,
    PROC_SET_END_CB(ProcPrepSkill1_OnEnd),
    PROC_END
};

void StartPrepEquipScreen(struct ProcAtMenu * pproc)
{
    struct ProcPrepSkill1 * proc;
    proc = Proc_StartBlocking(ProcScr_PrepSkillUnitSel, pproc);

    proc->list_num_cur = UnitGetIndexInPrepList(PrepGetLatestCharId());
    proc->list_num_pre = proc->list_num_cur;
    proc->max_counter  = pproc->max_counter;
    proc->yDiff_cur    = pproc->yDiff;
}
