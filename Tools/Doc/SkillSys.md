# Skill lists

Each unit can use no more than 10 skills in battle map as below:

- 2 skills in ROM table binded to character.
- 2 skills in ROM table binded to class.
- 6 skills in RAM table and equipable by player.

---
## 1. ROM table

ROM table can be configured in [./Data/SkillSys/RomTable.c](../Data/SkillSys/RomTable.c).

---
## 2. RAM table API

As for RAM table, developers may use the following API to give unit skills:

```C
#include "skill-system.h"
int AddSkill(struct Unit * unit, const u8 sid);
int RemoveSkill(struct Unit * unit, const u8 sid);
```

<!> Note that it is a little bit complacted if you looked into functions above since we should also consider on skill equipment in prep-screen, which may be discussed later.

We have also offered event macros to add skill from event:

- `EVT_ADD_SKILL(sid, pid)`: give character [**pid**] a skill [**sid**].
- `EVT_ADD_SKILL_AT(sid, x, y)`: give character at position [**x, y**] a skill [**sid**].
- `EVT_ADD_SKILL_SC(sid)`: give character a skill [**sid**], character index is picked from slot-C.

You may also use macro `EVT_REMOVE_SKILL, EVT_REMOVE_SKILL_AT, EVT_REMOVE_SKILL_SC` to remove skills.

RAM table use the support list inside unit struct, and the support data is lied inside BWL table by patch [BwlRework](../Wizardry//BwlRework/BwlRework.event). Although we offered

---
## 3. Learn skills

Every time you `AddSkill` to unit, he may learn that skill permanently. That is to say, he can always select the skill to equip in prep-screen, regardless whether you `RemoveSkill` from him. 

The most important purpose of the modern C-SkillSys is to allow players to load and unload skills in prep-screen. To do this, each character is given a list to store the skills they have learned. This list is saved to SRAM, and may be used during prep-skill list screen.

Character may learn 10 skills when they level-up to lv 5/10/15/20..., 5 from class and 5 from character himself. You may edit on [./Data/SkillSys/PreLoadConfig.c](../Data/SkillSys/PreLoadConfig.c) to configure character/class to learn which skills.

However, the above rules introduce the following problems. Consider such a case:

- **Lute** is promoted to **Sage** when she is level 15. Then she level up to lv-5 as a **Sage**, should she get new lv-20 character skills or lv-5?

To solve such issue, units' gained level is recorded to BWL, and the real level is `recorded level + current level` to judge on which skill should she learn for character table.

But the class skill table is still judged based on current level.
