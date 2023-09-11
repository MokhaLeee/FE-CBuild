#include "global.h"
#include "bmunit.h"
#include "chapterdata.h"
#include "bmudisp.h"
#include "ctc.h"

#include "common-chax.h"
#include "debuff.h"

#if CONFIG_USE_DEBUG
STATIC_DECLAR int GetUnitHpBarIndex(struct Unit * unit)
{
    int cur = unit->curHP;
    int max = unit->maxHP;

    return Div(cur * 11, max);
}
#else

/* Fasten game */
NAKEDFUNC
STATIC_DECLAR int GetUnitHpBarIndex(struct Unit * unit)
{
    asm("\n\
    .syntax unified\n\
        push {lr}\n\
        ldrb r2, [r0, #0x13]\n\
        ldrb r1, [r0, #0x12]\n\
        lsls r0, r2, #3\n\
        lsls r3, r2, #1\n\
        adds r0, r3\n\
        adds r0, r2\n\
        swi #6\n\
        pop {pc}\n\
    .syntax divided");
}

#endif

static const int objvram_offsets[] = {
    0x240, 0x280, 0x2C0,
    0x640, 0x680, 0x6C0,
    0xA40, 0xA80, 0xAC0,
    0xE40, 0xE80
};

void PutUnitHpBar(struct Unit * unit)
{
    int ix = unit->xPos * 16 - gBmSt.camera.x;
    int iy = unit->yPos * 16 - gBmSt.camera.y;
    int index;

    if (ix < -16 || ix > DISPLAY_WIDTH)
        return;

    if (iy < -16 || iy > DISPLAY_HEIGHT)
        return;

    index = GetUnitHpBarIndex(unit);

    CallARM_PushToSecondaryOAM(
        OAM1_X(0x200 + ix),
        OAM0_Y(0x100 + iy + 10),
        gObject_16x8,
        OAM2_PAL(0) + OAM2_LAYER(2) + OAM2_CHR(objvram_offsets[11 - index] / 0x20));
}
