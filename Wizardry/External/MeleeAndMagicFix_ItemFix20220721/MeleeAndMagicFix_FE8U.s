.thumb

.equ origin, 0x08018a58	@UnitHasMagicRank
.equ GetUnitEquippedWeapon, . + 0x08016b28 - origin
.equ GetItemAttributes, . + 0x0801756c - origin

PUSH {r4,lr}
mov r4, r0
BL GetUnitEquippedWeapon
cmp r0, #0x0
bne DependItem
DependClass:
ldr r0, [r4, #0x2c] @Unit->Staff
cmp r0, #0x0        @魔法が使えない
beq Exit
mov r0, #0x1
b   Exit

DependItem:
BL GetItemAttributes
MOV r1, #0x2
AND r0 ,r1
LSR r0 ,r0 ,#0x1
Exit:
POP {r4,pc}
