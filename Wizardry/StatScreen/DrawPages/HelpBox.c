#include "global.h"
#include "fontgrp.h"
#include "statscreen.h"

#include "common-chax.h"
#include "stat-screen.h"

/* LynJump */
void StartStatScreenHelp(int pageid, struct Proc * proc)
{
    LoadHelpBoxGfx(NULL, -1); // default

    if (!gStatScreen.help)
    {
        switch (pageid)
        {
        case STATSCREEN_PAGE_0:
            gStatScreen.help = RTextPageUnit;
            break;

        case STATSCREEN_PAGE_1:
            gStatScreen.help = &gHelpInfo_Ss1Item0;
            break;

        case STATSCREEN_PAGE_2:
            gStatScreen.help = &gHelpInfo_Ss2Rank0;
            break;

        } // switch (pageid)
    }

    StartMovingHelpBox(gStatScreen.help, proc);
}