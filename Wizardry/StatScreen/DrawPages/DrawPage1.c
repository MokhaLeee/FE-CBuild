#include "global.h"
#include "fontgrp.h"
#include "hardware.h"
#include "bmunit.h"
#include "statscreen.h"

#include "common-chax.h"
#include "stat-screen.h"
#include "strmag.h"
#include "lvup.h"

extern struct Font * gActiveFont;
extern int sStatScreenPage1BarMax;

STATIC_DECLAR void InstallExpandedTextPal(void)
{
    extern const u16 ExpandedTextPals[];
    ApplyPalettes(ExpandedTextPals, 0x8, 2);
};

STATIC_DECLAR void ResetActiveFontPal(void)
{
    gActiveFont->tileref = gActiveFont->tileref & 0xFFF;
}

STATIC_DECLAR void PutDrawTextRework(struct Text * text, u16 * tm, int color, int x, int tile_width, char const * str)
{
    int palid;
    switch (color) {
    case 0 ... 4:
        palid = 0;
        break;

    case 5 ... 9:
        palid = 8;
        color = color - 5;
        break;

    case 10 ... 14:
        palid = 9;
        color = color - 10;
        break;

    default:
        palid = 0;
        color = 0;
    }

    gActiveFont->tileref = TILEREF(gActiveFont->tileref & 0xFFF, palid);
    PutDrawText(text, tm, color, x, tile_width, str);
}

STATIC_DECLAR int GetTextColorFromGrowth(int growth)
{
    int _mod10 = growth / 10;
    LIMIT_AREA(_mod10, 0, 9);
    return (9 - _mod10) + 5;
}

STATIC_DECLAR int SortMax(const int * buf, int size)
{
    int i, max = 0;
    for (i = 0; i < size; i++)
    {
        if (max < buf[i])
            max = buf[i];
    }

    return max;
}

STATIC_DECLAR void DrawStatWithBarReworkExt(int num, int x, int y, int base, int total, int max, int max_ref)
{
    int diff = total - base;

    LIMIT_AREA(base, 0, max);
    LIMIT_AREA(total, 0, max);

    base  = base * STAT_BAR_MAX_INDENTIFIER / max_ref;
    total = total * STAT_BAR_MAX_INDENTIFIER / max_ref;
    max   = max * STAT_BAR_MAX_INDENTIFIER / max_ref;

    diff = total - base;

    DrawStatBarGfx(
        0x401 + num * 6, 6,
        gBmFrameTmap1 + TILEMAP_INDEX(x - 2, y + 1),
        TILEREF(0, STATSCREEN_BGPAL_6),
        max,
        base,
        diff);
}

STATIC_DECLAR void DrawStatWithBarRework(int num, int x, int y, int base, int total, int max)
{
    /**
     * Here the max value maybe more than 35,
     * but we need to fix the bar's length shorter than 35
     */
    int diff = total - base;
    int max_bar = sStatScreenPage1BarMax;

    PutNumberOrBlank(
        gBmFrameTmap0 + TILEMAP_INDEX(x, y),
        base == max
            ? TEXT_COLOR_SYSTEM_GREEN
            : TEXT_COLOR_SYSTEM_BLUE,
        base);

    PutNumberBonus(
        diff,
        gBmFrameTmap0 + TILEMAP_INDEX(x + 1, y));

    DrawStatWithBarReworkExt(num, x, y, base, total, max, max_bar);
}

STATIC_DECLAR void DrawPage1TextCommon(void)
{
    struct Unit * unit = gStatScreen.unit;

    PutDrawTextRework(
        &gStatScreen.text[STATSCREEN_TEXT_POWLABEL],
        gBmFrameTmap0 + TILEMAP_INDEX(0x1, 0x1),
        FACTION_BLUE == UNIT_FACTION(unit)
            ? GetTextColorFromGrowth(GetUnitPowGrowth(unit))
            : TEXT_COLOR_SYSTEM_GOLD,
        0, 0,
        GetStringFromIndex(0x4FE)); // Str

    PutDrawTextRework(
        &gStatScreen.text[STATSCREEN_TEXT_ITEM0],
        gBmFrameTmap0 + TILEMAP_INDEX(0x1, 0x3),
        FACTION_BLUE == UNIT_FACTION(unit)
            ? GetTextColorFromGrowth(GetUnitMagGrowth(unit))
            : TEXT_COLOR_SYSTEM_GOLD,
        0, 0,
        GetStringFromIndex(0x4FF)); // Mag

    PutDrawTextRework(
        &gStatScreen.text[STATSCREEN_TEXT_SKLLABEL],
        gBmFrameTmap0 + TILEMAP_INDEX(0x1, 0x5),
        FACTION_BLUE == UNIT_FACTION(unit)
            ? GetTextColorFromGrowth(GetUnitSklGrowth(unit))
            : TEXT_COLOR_SYSTEM_GOLD,
        0, 0,
        GetStringFromIndex(0x4EC)); // Skl

    PutDrawTextRework(
        &gStatScreen.text[STATSCREEN_TEXT_SPDLABEL],
        gBmFrameTmap0 + TILEMAP_INDEX(0x1, 0x7),
        FACTION_BLUE == UNIT_FACTION(unit)
            ? GetTextColorFromGrowth(GetUnitSpdGrowth(unit))
            : TEXT_COLOR_SYSTEM_GOLD,
        0, 0,
        GetStringFromIndex(0x4ED)); // Spd

    PutDrawTextRework(
        &gStatScreen.text[STATSCREEN_TEXT_LCKLABEL],
        gBmFrameTmap0 + TILEMAP_INDEX(0x1, 0x9),
        FACTION_BLUE == UNIT_FACTION(unit)
            ? GetTextColorFromGrowth(GetUnitLckGrowth(unit))
            : TEXT_COLOR_SYSTEM_GOLD,
        0, 0,
        GetStringFromIndex(0x4EE)); // Lck

    PutDrawTextRework(
        &gStatScreen.text[STATSCREEN_TEXT_DEFLABEL],
        gBmFrameTmap0 + TILEMAP_INDEX(0x1, 0xB),
        FACTION_BLUE == UNIT_FACTION(unit)
            ? GetTextColorFromGrowth(GetUnitDefGrowth(unit))
            : TEXT_COLOR_SYSTEM_GOLD,
        0, 0,
        GetStringFromIndex(0x4EF)); // Def

    PutDrawTextRework(
        &gStatScreen.text[STATSCREEN_TEXT_RESLABEL],
        gBmFrameTmap0 + TILEMAP_INDEX(0x1, 0xD),
        FACTION_BLUE == UNIT_FACTION(unit)
            ? GetTextColorFromGrowth(GetUnitResGrowth(unit))
            : TEXT_COLOR_SYSTEM_GOLD,
        0, 0,
        GetStringFromIndex(0x4F0)); // Res

    /* All growth related value done */
    ResetActiveFontPal();

    PutDrawText(
        &gStatScreen.text[STATSCREEN_TEXT_MOVLABEL],
        gBmFrameTmap0 + TILEMAP_INDEX(0x9, 0x1),
        TEXT_COLOR_SYSTEM_GOLD,
        0, 0,
        GetStringFromIndex(0x4F6)); // Mov

    PutDrawText(
        &gStatScreen.text[STATSCREEN_TEXT_CONLABEL],
        gBmFrameTmap0 + TILEMAP_INDEX(0x9, 0x3),
        TEXT_COLOR_SYSTEM_GOLD,
        0, 0,
        GetStringFromIndex(0x4F7)); // Con

    PutDrawText(
        &gStatScreen.text[STATSCREEN_TEXT_AIDLABEL],
        gBmFrameTmap0 + TILEMAP_INDEX(0x9, 0x5),
        TEXT_COLOR_SYSTEM_GOLD,
        0, 0,
        GetStringFromIndex(0x4F8)); // Aid

    PutDrawText(
        &gStatScreen.text[STATSCREEN_TEXT_ITEM1],
        gBmFrameTmap0 + TILEMAP_INDEX(0x9, 0x7),
        TEXT_COLOR_SYSTEM_GOLD,
        0, 0,
        GetStringFromIndex(0xD4C));

    PutDrawText(
        &gStatScreen.text[STATSCREEN_TEXT_SUPPORT4],
        gBmFrameTmap0 + TILEMAP_INDEX(0x9, 0x9),
        TEXT_COLOR_SYSTEM_GOLD,
        0, 0,
        GetStringFromIndex(0x4F1)); // Affin

    PutDrawText(
        &gStatScreen.text[STATSCREEN_TEXT_RESCUENAME],
        gBmFrameTmap0 + TILEMAP_INDEX(0x9, 0xB),
        TEXT_COLOR_SYSTEM_GOLD,
        0, 0,
        GetStringFromIndex(0x4F9)); // Trv

    PutDrawText(
        &gStatScreen.text[STATSCREEN_TEXT_STATUS],
        gBmFrameTmap0 + TILEMAP_INDEX(0x9, 0xD),
        TEXT_COLOR_SYSTEM_GOLD,
        0, 0,
        GetStringFromIndex(0x4FA)); // Cond
}

void DrawPage1ValueReal(void)
{
    struct Unit * unit = gStatScreen.unit;

    DrawStatWithBarRework(0, 0x5, 0x1,
                    unit->pow,
                    GetUnitPower(unit),
                    UNIT_POW_MAX(unit));

    DrawStatWithBarRework(1, 0x5, 0x3,
                    unit->_u3A,
                    GetUnitMagic(unit),
                    GetUnitMaxMagic(unit));

    DrawStatWithBarRework(2, 0x5, 0x5,
                    unit->skl,
                    GetUnitSkill(unit),
                    UNIT_SKL_MAX(unit));

    DrawStatWithBarRework(3, 0x5, 0x7,
                    unit->spd,
                    GetUnitSpeed(unit),
                    UNIT_SPD_MAX(unit));

    DrawStatWithBarRework(4, 0x5, 0x9,
                    unit->lck,
                    GetUnitLuck(unit),
                    UNIT_LCK_MAX(unit));

    DrawStatWithBarRework(5, 0x5, 0xB,
                    unit->def,
                    GetUnitDefense(unit),
                    UNIT_DEF_MAX(unit));

    DrawStatWithBarRework(6, 0x5, 0xD,
                    unit->res,
                    GetUnitResistance(unit),
                    UNIT_RES_MAX(unit));
}

/* LynJump */
void DisplayPage0(void)
{
    struct Unit * unit = gStatScreen.unit;

    int i, max_vals[] = {
        UNIT_POW_MAX(unit),
        GetUnitMaxMagic(unit),
        UNIT_SKL_MAX(unit),
        UNIT_SPD_MAX(unit),
        UNIT_LCK_MAX(unit),
        UNIT_DEF_MAX(unit),
        UNIT_RES_MAX(unit),
    };

    sStatScreenPage1BarMax = SortMax(max_vals, sizeof(max_vals) / sizeof(int));

    for (i = STATSCREEN_TEXT_POWLABEL; i < STATSCREEN_TEXT_BSRANGE; i++)
        ClearText(&gStatScreen.text[i]);

    ClearText(&gStatScreen.text[STATSCREEN_TEXT_SUPPORT3]);
    ClearText(&gStatScreen.text[STATSCREEN_TEXT_SUPPORT4]);

    InstallExpandedTextPal();
    DrawPage1TextCommon();
    DrawPage1ValueReal();
}