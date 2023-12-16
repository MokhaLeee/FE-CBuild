#ifndef CONFIG_INSTALLED
#define CONFIG_INSTALLED

#include "../config-debug.h"

/* FreeSpace definitions */
#define FreeSpaceMagic 0xB2A604
#define FreeSpaceReloc 0xB2A620
#define FreeSpaceWizardry 0xB2AE20
#define FreeSpaceFont 0xEFB2E0
#define FreeSpaceAlloc 0x1000000

#define FreeSpaceMagicSize 0x1C
#define FreeSpaceRelocSize 0x400
#define FreeSpaceWizardrySize 0xD55E0
#define FreeSpaceFontSize 0xE4D20

/* Acturally unused */
#define FreeSpace FreeSpaceAlloc

/* Icon sheet amount */
#define ICON_SHEET_AMT 4

/* If comment, CHAX may not verify on FESKILL magic work in SRAM */
#define CONFIG_VERIFY_SKILLSYS_SRAM

#endif /* CONFIG_INSTALLED */
