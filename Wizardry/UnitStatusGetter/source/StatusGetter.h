#pragma once

#include "global.h"
#include "bmunit.h"

typedef int (*StatusGetterFunc_t)(int old, struct Unit * unit);

extern const StatusGetterFunc_t gHpGetters[],  gPowGetters[];
extern const StatusGetterFunc_t gSklGetters[], gSpdGetters[], gLckGetters[], gDefGetters[], gResGetters[];
extern const StatusGetterFunc_t gMovGetters[], gConGetters[], gAidGetters[];
