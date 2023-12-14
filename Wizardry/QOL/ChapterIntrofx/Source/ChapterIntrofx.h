#pragma once

#include "global.h"

enum chr_idx {
    BGCHR_CHAPTERINTRO_80 = 0x80,
    BGCHR_CHAPTERINTRO_100 = 0x100,
    BGCHR_CHAPTERINTRO_MOTIF = 0x400,
    BGCHR_CHAPTERINTRO_FOG = 0x500,
};

enum pal_idx {
    BGPAL_CHAPTERINTRO_0 = 0,
    BGPAL_CHAPTERINTRO_1 = 1,
    BGPAL_CHAPTERINTRO_FOG = 4,
    BGPAL_CHAPTERINTRO_MOTIF = 5,
};

void sub_80896A8(int chr);
void sub_8089744(u16* tm, int pal);
void ChapterIntro_InitMapDisplay();
void ChapterIntro_BeginFadeToMap(struct ChapterIntroFXProc* proc);
void ChapterIntro_LoopFadeToMap(struct ChapterIntroFXProc* proc);
void ChapterIntro_BeginFastFadeToMap(struct ChapterIntroFXProc* proc);
void ChapterIntro_LoopFastFadeToMap(struct ChapterIntroFXProc* proc);
void ChapterIntro_80210C8(void);

extern const u8 Img_ChapterIntroFogFE6[];
extern const u16 Pal_ChapterIntroFogFE6[];

extern const u8 Img_ChapterIntroMotifFE6[];
extern const u8 Tm_ChapterIntroMotifFE6[];
extern const u16 Pal_ChapterIntroMotifFE6[];

extern u16 Pal_Unk_0830D5E4[];
