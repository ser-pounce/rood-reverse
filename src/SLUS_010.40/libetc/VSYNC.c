#include "common.h"

extern volatile long* D_80030FDC;
extern volatile long* D_80030FE0;
extern volatile long D_80030FE4;
extern long D_80030FE8;
extern volatile long D_80032114;

void func_8001F83C(long count, long timeout);

long VSync(long mode)
{
    volatile long count;
    long status;
    long elapsed;

    status = *D_80030FDC;
    do {
        count = *D_80030FE0;
    } while (count != *D_80030FE0);

    elapsed = (count - D_80030FE4) & 0xFFFF;

    if (mode < 0) {
        return D_80032114;
    }
    if (mode == 1) {
        return elapsed;
    }

    func_8001F83C(
        mode > 0 ? D_80030FE8 + (mode - 1) : D_80030FE8, mode > 0 ? mode - 1 : 0);
    status = *D_80030FDC;
    func_8001F83C(D_80032114 + 1, 1);

    if (status & 0x400000) {
        while (!((status ^ *D_80030FDC) & 0x80000000)) { }
    }

    D_80030FE8 = D_80032114;
    do {
        D_80030FE4 = *D_80030FE0;
    } while (D_80030FE4 != *D_80030FE0);

    return elapsed;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libetc/VSYNC", func_8001F83C);
