#pragma once

#include "global.h"
#include "bmunit.h"

#include "debug-kit.h"
#include "../Texts/TextDefs.h"
#include "../Configs/configs.h"

#define UNIT_LEVEL_MAX_RE UNIT_LEVEL_MAX

/* Add a magic for FEB PATCH to auto find the pointer */
#define FEB_IDENTIFIER(PTR)     \
const struct {                  \
    char magic[sizeof(#PTR)];   \
    const void * addr;          \
} FEB_##PTR##_Identifier = {    \
    .magic = #PTR,              \
    .addr = PTR,                \
};
