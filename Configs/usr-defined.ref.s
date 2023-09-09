.macro SET_FUNC name, value
    .global \name
    .type \name, function
    .set \name, \value
.endm

.macro SET_DATA name, value
    .global \name
    .type \name, object
    .set \name, \value
.endm

/* Free RAM space allocation */
SET_DATA FreeRamSpaceEntry, 0x02026E30

SET_DATA sSkillListNext, FreeRamSpaceEntry + 0
SET_DATA sSkillLists, sSkillListNext + 4
SET_DATA sPrepEquipSkillList, sSkillLists + 0x40
SET_DATA sPrepEquipSkillListExt, sPrepEquipSkillList + 0x100
SET_DATA sStatScreenPage1BarMax, sPrepEquipSkillListExt + 0x100
SET_DATA sLearnedSkillPLists, sStatScreenPage1BarMax + 0x4
SET_DATA sEfxSkillRoundData, sLearnedSkillPLists + 0x46 * 0x20

SET_DATA FreeRamSpaceTail, sEfxSkillRoundData + 4 * 0x21

/* IconDisplay */
SET_DATA gIconReSts, 0x02026A90 @ DrawnIconLookupTable
/* Fall through */
SET_DATA gBattleHitArrayRe, 0x02026AD0   /* 4 * 0x21 */
SET_DATA gAnimRoundDataRe, 0x02026B54    /* 4 * 0x21 */
SET_DATA gEfxHpLutRe, 0x02026BD8         /* 4 * 0x21 */
