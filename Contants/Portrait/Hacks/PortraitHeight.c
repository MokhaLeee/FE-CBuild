#include "global.h"
#include "constants/faces.h"

extern const u8 HighPortraitFidLut[];

bool ShouldFaceBeRaised(int fid) {
    const u8 * it;
    for (it = HighPortraitFidLut; *it; it++)
        if (*it == fid)
            return true;

    return false;
}
