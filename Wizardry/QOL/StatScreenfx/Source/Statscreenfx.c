#include "global.h"
#include "statscreen.h"
#include "hardware.h"
#include "bmlib.h"

#include "common-chax.h"

extern const u8 TSA_StatscreenBG1[];
extern const u8 TSA_StatscreenBG1_Uncompressed[];

void StatScreen_InitDisplayRework(struct Proc * proc)
{
    StatScreen_InitDisplay(proc);

    StartMuralBackground(NULL, (void *)VRAM + 0xB000, -1);

    CpuFastCopy(TSA_StatscreenBG1_Uncompressed, gBG1TilemapBuffer, 0x500);
    // Decompress(TSA_StatscreenBG1, gGenericBuffer);
    // CallARM_FillTileRect(gBG1TilemapBuffer, gGenericBuffer, TILEREF(0, 1));
}
