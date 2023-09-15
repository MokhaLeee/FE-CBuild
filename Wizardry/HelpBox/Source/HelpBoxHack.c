#include "global.h"
#include "fontgrp.h"
#include "statscreen.h"
#include "soundwrapper.h"

#include "common-chax.h"
#include "help-box.h"
#include "combat-art.h"

STATIC_DECLAR void sub_808A200_vanilla(const struct HelpBoxInfo * info)
{
    int wTextBox;
    int hTextBox;

    struct HelpBoxProc * proc = Proc_Find(gUnknown_08A01678);

    if (!proc)
    {
        proc = Proc_Start(gUnknown_08A01678, PROC_TREE_3);

        PlaySoundEffect(0x70);
        sub_808A43C(proc, info->xDisplay, info->yDisplay);
        sub_808A444(proc);
    }
    else
    {
        proc->xBoxInit = proc->xBox;
        proc->yBoxInit = proc->yBox;
        proc->wBoxInit = proc->wBoxFinal;
        proc->hBoxInit = proc->hBoxFinal;
    }

    proc->info = info;
    proc->timer = 0;
    proc->timerMax = 12;

    proc->mid = info->mid;

    SetTextFontGlyphs(1);
    GetStringTextBox(GetStringFromIndex(proc->mid), &wTextBox, &hTextBox);
    SetTextFontGlyphs(0);

    sub_808A384(proc, wTextBox, hTextBox);
    sub_808A3C4(proc, info->xDisplay, info->yDisplay);

    ClearHelpBoxText();
    StartHelpBoxTextInit(proc->item, proc->mid);

    gUnknown_0203E7E4 = info;
}

/* LynJump */
void sub_808A200(const struct HelpBoxInfo * info)
{
    sHelpBoxType = 0;
    sub_808A200_vanilla(info);
}

/* LynJump */
void sub_8089F58(struct HelpBox8A01650Proc * proc)
{
    int item = proc->unk_58;

    SetTextFont(&gUnknown_0203E794.font);
    SetTextFontGlyphs(0);

    if (sHelpBoxType == 0)
    {
        /* Vanilla */
        switch (GetHelpBoxItemInfoKind(item)) {
        case 0:
            proc->unk_64 = 0;
            break;

        case 1:
            DrawHelpBoxWeaponLabels(item);
            proc->unk_64 = 2;
            break;

        case 2:
            DrawHelpBoxStaffLabels(item);
            proc->unk_64 = 1;
            break;

        case 3:
            DrawHelpBoxSaveMenuLabels();
            proc->unk_64 = 1;
            break;
        }
    }
    else
    {
        /* Hack here */
        if (NEW_HB_COMBAT_ART_BKSEL == sHelpBoxType)
        {
            DrawHelpBoxCombatArtBkselLabels();
            proc->unk_64 = 1;
        }
    }

    SetTextFont(0);
    Proc_Break(proc);
}

/* LynJump */
void sub_8089FCC(struct HelpBox8A01650Proc * proc)
{
    int item = proc->unk_58;
    SetTextFont(&gUnknown_0203E794.font);

    if (sHelpBoxType == 0)
    {
        /* Vanilla */
        switch (GetHelpBoxItemInfoKind(item)) {
        case 1:
            DrawHelpBoxWeaponStats(item);
            break;

        case 3:
            DrawHelpBoxSaveMenuStats();
            break;
        }
    }
    else
    {
        /* Hack here */
        if (NEW_HB_COMBAT_ART_BKSEL == sHelpBoxType)
        {
            DrawHelpBoxCombatArtBkselStats();
        }
    }

    SetTextFont(0);
    Proc_Break(proc);
}
