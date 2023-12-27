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

extern struct ProcCmd gUnknown_08A01678[];
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
