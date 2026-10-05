#include "common.h"
#include <libds.h>

extern int D_800327E0;
extern DslCB D_800327F8;

void func_80025DB8(u_char intr, u_char* result, u_long* buf);
void func_800260A8(int abort);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSREAD", DsRead);

void func_80025D84(u_char intr, u_char* result)
{
    if (intr == DslComplete) {
        DsStartReadySystem((DslRCB)func_80025DB8, -1);
    }
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSREAD", func_80025DB8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSREAD", func_80025F30);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSREAD", DsReadSync);

DslCB DsReadCallback(DslCB func)
{
    DslCB old = D_800327F8;
    D_800327F8 = func;
    return old;
}

void DsReadBreak(void) { func_800260A8(0); }

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSREAD", func_800260A8);

void DsReadMode(u_int mode)
{
    if (mode < 2) {
        D_800327E0 = mode;
    }
}
