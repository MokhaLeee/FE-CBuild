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

    for (y = 0; y < 5; y++)
    {
        for (x = 0; x < 5; x++)
        {
            int count = x + y * 5;
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
