#include "common-chax.h"
#include "bmunit.h"
#include "bmsave.h"
#include "sram-layout.h"
#include "uimenu.h"
#include "bmmind.h"
#include "event.h"

#include "debug-kit.h"
#include "save-data.h"

void MSU_SavePlaySt(u8 * dst, const u32 size)
{
    gPlaySt.time_saved = GetGameClock();
    WriteAndVerifySramFast(&gPlaySt, dst, sizeof(gPlaySt));
}

void MSU_LoadPlaySt(u8 * src, const u32 size)
{
    ReadSramFast(src, &gPlaySt, sizeof(gPlaySt));
    SetGameTime(gPlaySt.time_saved);
}

void MSU_SaveAction(u8 * dst, const u32 size)
{
    StoreRNStateToActionStruct();
    WriteAndVerifySramFast(&gActionData, dst, sizeof(struct ActionData));
}

void MSU_LoadAction(u8 * src, const u32 size)
{
    ReadSramFast(src, &gActionData, sizeof(struct ActionData));
    LoadRNStateFromActionStruct();
}

void MSU_SaveMenuMask(u8 * dst, const u32 size)
{
    u8 list[MENU_OVERRIDE_MAX];
    GetForceDisabledMenuItems(list);
    WriteAndVerifySramFast(list, dst, sizeof(list));
}

void MSU_LoadMenuMask(u8 * src, const u32 size)
{
    u8 list[MENU_OVERRIDE_MAX];
    ReadSramFast(src, list, sizeof(list));
    SetForceDisabledMenuItems(list);
}

void MSU_SaveWorldMap(u8 * dst, const u32 size)
{
    WriteWorldMapStuff(dst, &gGMData);
}

void MSU_LoadWorldMap(u8 * src, const u32 size)
{
    ReadWorldMapStuff(src, &gGMData);
}

void MSU_SaveDungeon(u8 * dst, const u32 size)
{
    struct Dungeon dungeon[2];
    SaveDungeonRecords(dungeon);
    WriteAndVerifySramFast(dungeon, dst, sizeof(dungeon));
}

void MSU_LoadDungeon(u8 * src, const u32 size)
{
    struct Dungeon dungeon[2];
    ReadSramFast(src, dungeon, sizeof(dungeon));
    LoadDungeonRecords(dungeon);
}

void MSU_SaveDungeon2(u8 * dst, const u32 size)
{
    struct Dungeon dungeon;
    SaveDungeonState(&dungeon);
    WriteAndVerifySramFast(&dungeon, dst, sizeof(struct Dungeon));
}

void MSU_LoadDungeon2(u8 * src, const u32 size)
{
    struct Dungeon dungeon;
    ReadSramFast(src, &dungeon, sizeof(struct Dungeon));
    LoadDungeonState(&dungeon);
}

void MSU_SaveEvtCounter(u8 * dst, const u32 size)
{
    int val = GetEventSlotCounter();
    WriteAndVerifySramFast(&val, dst, sizeof(int));
}

void MSU_LoadEvtCounter(u8 * src, const u32 size)
{
    int val;
    ReadSramFast(src, &val, sizeof(int));
    SetEventSlotCounter(val);
}

void MSU_SaveBonusClaim(void)
{
    return;
}

void MSU_LoadBonusClaimWIP(void)
{
    u32 buf;
    void * src = GetSaveReadAddr(gPlaySt.gameSaveSlot);
    ReadSramFast(src + 0x0638, &buf, sizeof(buf));  /* 0x0638 is countered from gEmsSavChunks */
    SetBonusContentClaimFlags(buf);
}

void MSU_SaveBlueUnits(u8 * dst, const u32 size)
{
    return;
}

void MSU_LoadBlueUnits(u8 * src, const u32 size)
{
    return;
}

void MSU_SaveRedUnits(u8 * dst, const u32 size)
{
    return;
}

void MSU_LoadRedUnits(u8 * src, const u32 size)
{
    return;
}

void MSU_SaveGreenUnits(u8 * dst, const u32 size)
{
    return;
}

void MSU_LoadGreenUnits(u8 * src, const u32 size)
{
    return;
}
