#ifndef CHAPTER_ASSET_DEFINITIONS
#define CHAPTER_ASSET_DEFINITIONS

/**
 * Now chapter asset is splited into 5 lists
 * 1. events
 * 2. maps
 * 3. objects & palettes (img + pal)
 * 4. tile anims
 * 5. tile change
 * 6. tile configs (TSA)
 */

/* list1: events */
#define CHDATA_L1_EVENT_Prologue 1
#define CHDATA_L1_EVENT_Ch1 2
#define CHDATA_L1_EVENT_Ch2 3

/* list2: maps */
#define CHDATA_L2_MAP_Prologue 1
#define CHDATA_L2_MAP_Ch1 2
#define CHDATA_L2_MAP_Ch2 3

/* list3: objects & palettes */
#define CHDATA_L3_ASSET1_OBJ 3
#define CHDATA_L3_ASSET1_PAL 4
#define CHDATA_L3_ASSET2_OBJ 5
#define CHDATA_L3_ASSET2_PAL 6
#define CHDATA_L3_ASSET3_OBJ 7
#define CHDATA_L3_ASSET3_PAL 8

/* list4: tile anims */
#define AssetWaterAnims         0x05
#define AssetVillageAnims       0x12
#define AssetCastleAnims        0x1C
#define AssetVolcanoPalAnims    0x54
#define AssetInteriorAnims      0x7D
#define CHDATA_L3_TileAnimUnkD4 0xD3

/**
 * list5: tile change
 */
#define CHDATA_L5_MAPCHG_Ch2a 1

/* list6: tile configs */
#define CHDATA_L6_ASSET1_CONF 1
#define CHDATA_L6_ASSET2_CONF 2
#define CHDATA_L6_ASSET3_CONF 4

#endif // CHAPTER_ASSET_DEFINITIONS
