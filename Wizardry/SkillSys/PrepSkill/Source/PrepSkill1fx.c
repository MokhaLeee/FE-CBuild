#include "global.h"
#include "bmunit.h"
#include "hardware.h"
#include "icon.h"
#include "fontgrp.h"
#include "statscreen.h"

#include "common-chax.h"
#include "prep-skill.h"

void PrepSkill_DrawLeftSkillIcon(struct Unit * unit)
{
    int x, y;
    struct SkillList * list = GetUnitSkillList(unit);
    ResetIconGraphics_();
    TileMap_FillRect(TILEMAP_LOCATED(gBG0TilemapBuffer, 1, 5), 0xB, 0xB, 0);

    for (y = 0; y < PREP_SLLIST_HEIGHT; y++)
    {
        for (x = 0; x < PREP_SLLIST_LENGTH; x++)
        {
            int count = x + y * PREP_SLLIST_LENGTH;
            if (count >= list->amt)
                break;

            DrawIcon(
                TILEMAP_LOCATED(gBG0TilemapBuffer, 2 + x * 2, 6 + y * 2),
                SKILL_ICON(list->sid[count]), 
                TILEREF(0, STATSCREEN_BGPAL_ITEMICONS));
        }
    }

    BG_EnableSyncByMask(BG0_SYNC_BIT);
}

void PrepSkill_InitTexts(void)
{
    int i;

    ResetText();

    /* 0x00 ~ 0x0D (size = 14): unit name */
    for (i = 0; i < 14; i++)
        InitText(&gPrepUnitTexts[i], 5);

    /* Vanilla: item, new: skill desc */
    for (i = 0; i < 3; i++)
        InitText(&gPrepUnitTexts[i + 0xE], 0x15);

    /* Left unit name */
    InitText(&gPrepUnitTexts[0x13], 7);
    InitText(&gPrepUnitTexts[0x14], 10);

    /* Right top bar */
    InitText(&gPrepUnitTexts[0x15], 12);
}
