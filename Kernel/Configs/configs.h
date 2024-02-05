#ifndef CONFIG_INSTALLED
#define CONFIG_INSTALLED

#include "../config-debug.h"

/* FreeSpace definitions */
#define FreeSpaceMain 0xB2A604
#define FreeSpaceMainSize 0xD5DFC

#define FreeSpaceMain_Magic (FreeSpaceMain + 0x0)
#define FreeSpaceMain_Reloc (FreeSpaceMain_Magic + 0x10)
#define FreeSpaceRelocSize 0x400

#define FreeSpaceMain_TextTable (FreeSpaceMain_Reloc + 0x400)

#define FreeSpaceFontSize 0xE4D20
#define FreeSpaceFont 0xEFB2E0

#define FreeSpaceAlloc 0x1000000

/* Acturally unused */
#define FreeSpace FreeSpaceAlloc

/* Icon sheet amount */
#define ICON_SHEET_AMT 4

/* If comment, CHAX may not verify on FESKILL magic work in SRAM */
#define CONFIG_VERIFY_SKILLSYS_SRAM

#endif /* CONFIG_INSTALLED */
