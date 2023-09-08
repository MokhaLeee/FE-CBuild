#pragma once

#include "global.h"
#include "bmunit.h"

#include "../Configs/configs.h"
#include "debug-kit.h"

#define UNIT_LEVEL_MAX_RE UNIT_LEVEL_MAX

/* Add a magic for FEB PATCH to auto find the pointer */
#define FEB_IDENTIFIER(PTR) const char FEB_##PTR##_Identifier[] = #PTR

/* Set static declaration as a macro for debug purpose */
#if CONFIG_USE_DEBUG
#define STATIC_DECLAR
#else
#define STATIC_DECLAR static
#endif

/* Pointer valid judge */
#define IS_IWRAM_PTR(ptr)    ((((u32)ptr) & 0xFF000000) == 0x03000000)
#define IS_EWRAM_PTR(ptr)    ((((u32)ptr) & 0xFF000000) == 0x02000000)
#define IS_ROM_PTR(ptr)      ((((u32)ptr) & 0xFF000000) == 0x08000000)
#define IS_ROM_THUMB(ptr)    ((((u32)ptr) & 0xFF000001) == 0x08000001)
#define IS_ROM_DATA(ptr)     ((((u32)ptr) & 0xFF000001) == 0x08000000)
#define IS_ANTI_HUFFMAN(ptr) ((((u32)ptr) & 0xFF000001) == 0x88000000)
