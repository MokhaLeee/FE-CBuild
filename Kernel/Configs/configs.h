#ifndef CONFIG_INSTALLED
#define CONFIG_INSTALLED

#include "../config-debug.h"

/* Memmap */
/**
 * ---------------------------
 * Address  | Size  | Usage
 * ---------------------------
 * 08B2A604 | D5DFC  | Kernel
 * 08EFB2E0 | E4D20  | Fonts 
 * 09000000 | ----   | CHAX
 * ---------------------------
 */
#define FreeSpaceKernel 0xB2A604
#define FreeSpaceKernelSize 0xD5DFC

#define FreeSpaceFont 0xEFB2E0
#define FreeSpaceFontSize 0xE4D20

#define FreeSpaceCHAX 0x1000000
#define FreeSpace FreeSpaceCHAX

/**
 * Kernel memmap
 *
 * ------------------------
 * Name    | Offset | Size
 * ------------------------
 * Magic   | 0000   | 0010
 * Reloc   | 0010   | 0400
 * Repoint | 0410   | ----
 * K_free  | ----   | ----
 * ------------------------
 */
#define FreeSpaceKernel_Magic (FreeSpaceKernel + 0x0)
#define FreeSpaceKernel_Reloc (FreeSpaceKernel_Magic + 0x10)
#define FreeSpaceRelocSize 0x400

#define FreeSpaceKernel_TextTable (FreeSpaceKernel_Reloc + 0x400)

/* Icon sheet amount */
#define ICON_SHEET_AMT 4

/* If comment, CHAX may not verify on FESKILL magic work in SRAM */
#define CONFIG_VERIFY_SKILLSYS_SRAM

/* If uncomment, use zh-cn language */
#define CONFIG_LANG_CHINESE

#endif /* CONFIG_INSTALLED */
