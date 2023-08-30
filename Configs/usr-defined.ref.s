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

SET_DATA sSkillListNext, 0x02026E30
SET_DATA sSkillLists, 0x02026E34

SET_DATA FreeRamSpaceTail, 0x02026E74

/* IconDisplay */
SET_DATA gIconReSts, 0x02026A90 @ DrawnIconLookupTable
