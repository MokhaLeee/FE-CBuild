.include "macros.inc"
.include "gba_sprites.inc"

.section .rodata

.align 2
.global Sprite_TitleScreenUpper
Sprite_TitleScreenUpper:
    .short 12
    .short ATTR0_WIDE   + 0x00, ATTR1_SIZE_64 + 0x00, 0x00
    .short ATTR0_WIDE   + 0x00, ATTR1_SIZE_64 + 0x40, 0x08
    .short ATTR0_WIDE   + 0x00, ATTR1_SIZE_64 + 0x80, 0x10
    .short ATTR0_SQUARE + 0x00, ATTR1_SIZE_32 + 0xC0, 0x18

    .short ATTR0_WIDE   + 0x20, ATTR1_SIZE_32 + 0x00, 0x80
    .short ATTR0_WIDE   + 0x20, ATTR1_SIZE_32 + 0x20, 0x84
    .short ATTR0_WIDE   + 0x20, ATTR1_SIZE_32 + 0x40, 0x88
    .short ATTR0_WIDE   + 0x20, ATTR1_SIZE_32 + 0x60, 0x8C
    .short ATTR0_WIDE   + 0x20, ATTR1_SIZE_32 + 0x80, 0x90
    .short ATTR0_WIDE   + 0x20, ATTR1_SIZE_32 + 0xA0, 0x94
    .short ATTR0_WIDE   + 0x20, ATTR1_SIZE_32 + 0xC0, 0x98
    .short ATTR0_SQUARE + 0x20, ATTR1_SIZE_16 + 0xE0, 0x9C
