#include "global.h"
#include "bmitem.h"

#include "common-chax.h"
#include "battle-system.h"
#include "constants/skills.h"

static const struct WeaponTriangleConf sWeaponTriangleConfs[] = {
    {ITYPE_SWORD, ITYPE_AXE,   SID_AxeBreaker,   0, 0, 0, 0, 20, 20, 0, 0, 0},
    {ITYPE_AXE,   ITYPE_LANCE, SID_LanceBreaker, 0, 0, 0, 0, 20, 20, 0, 0, 0},
    {ITYPE_LANCE, ITYPE_SWORD, SID_SwordBreaker, 0, 0, 0, 0, 20, 20, 0, 0, 0},

    {ITYPE_ANIMA, ITYPE_BOW,   SID_BowBreaker,   0, 0, 0, 0, 20, 20, 0, 0, 0},
    {ITYPE_LIGHT, ITYPE_BOW,   SID_BowBreaker,   0, 0, 0, 0, 20, 20, 0, 0, 0},
    {ITYPE_DARK,  ITYPE_BOW,   SID_BowBreaker,   0, 0, 0, 0, 20, 20, 0, 0, 0},

    {ITYPE_BOW,   ITYPE_ANIMA, SID_BMagBreaker,  0, 0, 0, 0, 20, 20, 0, 0, 0},
    {ITYPE_BOW,   ITYPE_LIGHT, SID_BMagBreaker,  0, 0, 0, 0, 20, 20, 0, 0, 0},
    {ITYPE_BOW,   ITYPE_DARK,  SID_BMagBreaker,  0, 0, 0, 0, 20, 20, 0, 0, 0},

    {ITYPE_SWORD, ITYPE_ANIMA, SID_BMagBreaker,  0, 0, 0, 0, 20, 20, 0, 0, 0},
    {ITYPE_SWORD, ITYPE_LIGHT, SID_BMagBreaker,  0, 0, 0, 0, 20, 20, 0, 0, 0},
    {ITYPE_SWORD, ITYPE_DARK,  SID_BMagBreaker,  0, 0, 0, 0, 20, 20, 0, 0, 0},

    {ITYPE_AXE,   ITYPE_ANIMA, SID_BMagBreaker,  0, 0, 0, 0, 20, 20, 0, 0, 0},
    {ITYPE_AXE,   ITYPE_LIGHT, SID_BMagBreaker,  0, 0, 0, 0, 20, 20, 0, 0, 0},
    {ITYPE_AXE,   ITYPE_DARK,  SID_BMagBreaker,  0, 0, 0, 0, 20, 20, 0, 0, 0},

    {ITYPE_LANCE, ITYPE_ANIMA, SID_BMagBreaker,  0, 0, 0, 0, 20, 20, 0, 0, 0},
    {ITYPE_LANCE, ITYPE_LIGHT, SID_BMagBreaker,  0, 0, 0, 0, 20, 20, 0, 0, 0},
    {ITYPE_LANCE, ITYPE_DARK,  SID_BMagBreaker,  0, 0, 0, 0, 20, 20, 0, 0, 0},
    {0}
};

struct WeaponTriangleConf const * const gpWeaponTriangleConfs = sWeaponTriangleConfs;
FEB_IDENTIFIER(gpWeaponTriangleConfs);
