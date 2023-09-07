#pragma once

#include "global.h"
#include "bmunit.h"

int GetItemMinRangeRework(u16 item, struct Unit * unit);
int GetItemMaxRangeRework(u16 item, struct Unit * unit);

u32 ItemRangeToMask(u16 item, struct Unit * unit);
void AddMap(int x, int y, u32 mask, int on, int off);
void ForEachUnit(void (*func)(struct Unit *), u8 ** map, const int off);
