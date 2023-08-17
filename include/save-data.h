#pragma once

#include "global.h"
#include "bmsave.h"
#include "bmitem.h"
#include "sram-layout.h"

struct EmsChunk {
    /* 00 */ u16 off;
    /* 02 */ u16 size;

    /* 04 */ void (* save)(u8 * dst, const u32 size);
    /* 08 */ void (* load)(u8 * src, const u32 size);
};

extern const struct EmsChunk gEmsSaveChunks[];
extern const struct EmsChunk gEmsSusChunks[];

struct EmsPackedUnit {
    /* 00 */ u8 jid;
    /* 01 */ u8 pid;
    /* 02 */ u8 max_hp;
    /* 03 */ u8 pow, mag, skl, spd, lck, def, res, mov, con;
    /* 0C */ u32 level : 5;
             u32 exp   : 7;
             u32 xPos  : 6;
             u32 yPos  : 6;
    /* 0F */ u8 wranks[0x8];
    /* 17 */ u8 supports[UNIT_SUPPORT_MAX_COUNT];
    /* 1E */ u16 items[UNIT_ITEM_COUNT];
    /* 28 */ u32 state;
    /* 2C */
} BITPACKED;

struct EmsPackedUnitSusAlly {
    /* 00 */ struct EmsPackedUnit unitp;
    /* 2C */ u8 cur_hp;
    /* 2D */ u8 rescue;
    /* 2E */ u8 ballista;
    /* 2F */ u8 status   : 4;
             u8 duration : 4;
    /* 30 */ u8 torch    : 4;
             u8 barrier  : 4;

    /* 31 */ u8 _pad_[3];
    /* 34 */
} BITPACKED;

struct EmsPackedUnitSusAi {
    /* 00 */ struct EmsPackedUnit unitp;
    /* 2C */ u8 cur_hp;
    /* 2D */ u8 rescue;
    /* 2E */ u8 ballista;
    /* 2F */ u8 status   : 4;
             u8 duration : 4;
    /* 30 */ u8 torch    : 4;
             u8 barrier  : 4;

    /* 31 */ u8 ai1;
    /* 32 */ u8 ai2;
    /* 33 */ u8 ai1_cur;
    /* 34 */ u8 ai2_cur;
    /* 35 */ u8 ai_flag;
    /* 36 */ u16 ai_config;
    /* 38 */
} BITPACKED;
