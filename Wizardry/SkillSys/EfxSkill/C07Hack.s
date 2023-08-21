.include "macros.inc"

THUMB_FUNC_START Banim07Rework
Banim07Rework:
    mov r0, r7
    blh BanimEkrSkillHandler
    ldr r0, =0x080596CC + 1
    bx r0
