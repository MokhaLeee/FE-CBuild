#include "global.h"
#include "bmunit.h"
#include "bmitem.h"

#include "status-getter.h"

int _GetUnitMagic(struct Unit * unit)
{
    const StatusGetterFunc_t * it;
    int status = unit->_u3A;

    for (it = gMagGetters; *it; it++)
        status = (*it)(status, unit);

    return status;
}
