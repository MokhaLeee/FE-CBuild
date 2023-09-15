#pragma once

#include "global.h"
#include "proc.h"
#include "fontgrp.h"
#include "statscreen.h"

/* Hack */
enum NewHelpBoxType {
    NEW_HB_DEFAULT = 0,
    NEW_HB_COMBAT_ART_BKSEL = 1,
};
extern int sHelpBoxType;

/* From decomp */
struct HelpBox8A01650Proc {
    /* 00 */ PROC_HEADER;

    /* 29 */ u8 _pad[0x58-0x29];

    /* 58 */ int unk_58;
    /* 5C */ int unk_5c;
    /* 60 */ int unk_60;
    /* 64 */ s16 unk_64;
};

struct Struct203E794 {
    /* 00 */ struct Font font;
    /* 16 */ struct Text text[3];
    /* 30 */ u16 unk_30;
};

extern struct Struct203E794 gUnknown_0203E794;

extern struct ProcCmd gUnknown_08A01678[];
extern const struct HelpBoxInfo * gUnknown_0203E7E4;
void sub_808A43C(struct HelpBoxProc *, int, int);
void sub_808A444(struct HelpBoxProc *);
void sub_808A384(struct HelpBoxProc * proc, int w, int h);
void sub_808A3C4(struct HelpBoxProc * proc, int x, int y);
int DrawHelpBoxWeaponLabels(int item);
void DrawHelpBoxWeaponStats(int item);
int DrawHelpBoxStaffLabels(int item);
void DrawHelpBoxSaveMenuLabels(void);
void DrawHelpBoxWeaponStats(int item);
void DrawHelpBoxSaveMenuStats(void);
