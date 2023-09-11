#pragma once

#include "global.h"
#include "bmmap.h"
#include "bmunit.h"

bool IsPositionValid(s8 x, s8 y);
struct Unit * GetUnitAtPosition(s8 x, s8 y);
