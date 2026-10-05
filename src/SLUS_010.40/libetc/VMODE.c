#include "common.h"

extern long D_80032154;

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libetc/VMODE", SetVideoMode);

long GetVideoMode(void) { return D_80032154; }
