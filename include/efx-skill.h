#pragma once

#include "global.h"
#include "proc.h"

void NewEfxSkill(struct Anim * anim, int sid);
void NewEfxCombatArt(struct Anim * anim, int cid);
bool EfxSkillExists(void);

/* Efx skill box */
void NewEfxSkillBox(struct Anim * anim, int sid);
void NewEfxCombatArtBox(struct Anim * anim, int cid);
bool EfxSkillBoxExists(void);

/* Utils */
void InitEfxSkillRoundData(void);
void RegisterActorEfxSkill(int round, const u8 sid);
void RegisterTargetEfxSkill(int round, const u8 sid);
void RegisterEfxSkillCombatArt(int round, const u8 cid);
u8 GetActorEfxSkill(int round);
u8 GetTargetEfxSkill(int round);
