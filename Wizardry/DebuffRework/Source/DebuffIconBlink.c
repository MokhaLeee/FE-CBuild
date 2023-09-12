#include "global.h"
#include "bmunit.h"
#include "bmudisp.h"
#include "ctc.h"

#include "common-chax.h"
#include "debuff.h"

STATIC_DECLAR void PutUnitStatusIconCommon(struct Unit * unit, const u16 * obj)
{
    int ix = unit->xPos * 16 - gBmSt.camera.x;
    int iy = unit->yPos * 16 - gBmSt.camera.y;

    if (ix < -16 || ix > DISPLAY_WIDTH)
        return;

    if (iy < -16 || iy > DISPLAY_HEIGHT)
        return;

    CallARM_PushToSecondaryOAM(
        OAM1_X(ix - 1),
        OAM0_Y(iy),
        obj,
        0);
}

STATIC_DECLAR void PutUnitStatusBuffIcon(struct Unit * unit)
{
    const u16 objs[3][4] =
    {
        { 1, 0x8000, 0x00, OAM2_PAL(0) + OAM2_LAYER(0x2) + OAM2_CHR(0x980 / 0x20) },
        { 1, 0x8000, 0x00, OAM2_PAL(0) + OAM2_LAYER(0x2) + OAM2_CHR(0x9A0 / 0x20) },
        { 1, 0x80FF, 0x00, OAM2_PAL(0) + OAM2_LAYER(0x2) + OAM2_CHR(0x9A0 / 0x20) }
    };

    PutUnitStatusIconCommon(unit, objs[(GetGameClock()/8) % 3]);
}

STATIC_DECLAR void PutUnitStatusDebuffIcon(struct Unit * unit)
{
    const u16 objs[3][4] =
    {
        { 1, 0x8000, 0x00, OAM2_PAL(0) + OAM2_LAYER(0x2) + OAM2_CHR(0x9C0 / 0x20) },
        { 1, 0x8000, 0x00, OAM2_PAL(0) + OAM2_LAYER(0x2) + OAM2_CHR(0x9E0 / 0x20) },
        { 1, 0x80FF, 0x00, OAM2_PAL(0) + OAM2_LAYER(0x2) + OAM2_CHR(0x9E0 / 0x20) }
    };

    PutUnitStatusIconCommon(unit, objs[(GetGameClock() >> 3) % 3]);
}

/* Called from HpBar */
void PutUnitStatusIcon(struct Unit * unit)
{
    int status = GetUnitStatusIndex(unit);
    if (status != 0)
    {
        const struct DebuffInfo * info = gDebuffInfos + status;
        if (info->on_draw)
            info->on_draw(unit);
        else
        {
            switch (info->type) {
            case STATUS_INFO_TYPE_DEBUFF:
                PutUnitStatusDebuffIcon(unit);
                break;

            case STATUS_INFO_TYPE_BUFF:
                PutUnitStatusBuffIcon(unit);
                break;
            }
        }
    }
}

/* External on-draw functions */
void PutUnitDanceRingBuffIcon(struct Unit * unit)
{
    const u16 obj[] = {
        2,
        0x4000, 0x0000, OAM2_PAL(0x1) + OAM2_LAYER(0x2) + OAM2_CHR(0x600 / 0x20),
        0x0008, 0x0000, OAM2_PAL(0x1) + OAM2_LAYER(0x2) + OAM2_CHR(0xA00 / 0x20),
    };

    int ix = unit->xPos * 16 - gBmSt.camera.x;
    int iy = unit->yPos * 16 - gBmSt.camera.y;

    if (ix < -16 || ix > DISPLAY_WIDTH)
        return;

    if (iy < -16 || iy > DISPLAY_HEIGHT)
        return;

    if ((GetGameClock() & 0x3F) < 0x28)
        return;

    CallARM_PushToSecondaryOAM(
        OAM1_X(ix - 1),
        OAM0_Y(iy - 5),
        obj,
        0);    
}
