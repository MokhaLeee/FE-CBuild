#pragma once

#include "global.h"
#include "bmunit.h"

#include "../Configs/configs.h"
#include "debug-kit.h"

#define UNIT_LEVEL_MAX_RE UNIT_LEVEL_MAX

/* Add a magic for FEB PATCH to auto find the pointer */
#define FEB_IDENTIFIER(PTR) const char FEB_##PTR##_Identifier[] = #PTR

/* Set static declaration as a macro for debug purpose */
#if CONFIG_USE_DEBUG
#define STATIC_DECLAR
#else
#define STATIC_DECLAR static
#endif
