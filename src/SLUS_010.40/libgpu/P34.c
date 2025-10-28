#include "common.h"
#include <libgte.h>
#include <libgpu.h>

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/P34", SetDrawMove);

void SetDrawStp(DR_STP* stp, int enable)
{
    ((char*)stp)[3] = 2;
    if (enable) {
        stp->code[0] = 0xE6000001;
    } else {
        stp->code[0] = 0xE6000000;
    }
    stp->code[1] = 0;
}
