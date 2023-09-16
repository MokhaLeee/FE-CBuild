#ifndef CONFIG_INSTALLED
#define CONFIG_INSTALLED

/* FreeSpace definitions */
#define FreeSpaceMagic 0xB2A604
#define FreeSpaceMagicSize 0xC

#define FreeSpace 0xB2A624
#define FreeSpaceSize 0xD59F0

#define FreeSpaceFont 0xEFB2E0
#define FreeSpaceFontSize 0xE4D20

#define FreeSpaceEvent 0x1000000

/* If unset, CHAX may run faster without any debug info */
#define CONFIG_USE_DEBUG 1

/* Icon sheet amount */
#define ICON_SHEET_AMT 4

/* If uncomment, CHAX may not verify on FESKILL magic work in SRAM */
#define CONFIG_VERIFY_SKILLSYS_SRAM

#endif /* CONFIG_INSTALLED */
