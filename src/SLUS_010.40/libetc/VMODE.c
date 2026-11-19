#include "common.h"

extern long D_80032154;

long SetVideoMode(long mode)
{
    long previousMode = D_80032154;

    D_80032154 = mode;
    return previousMode;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libetc/VMODE", GetVideoMode);
