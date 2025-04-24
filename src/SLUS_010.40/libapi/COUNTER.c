#include "common.h"
#include <libapi.h>

typedef struct {
    u_short currentVal;
    short : 16;
    u_short mode;
    short : 16;
    u_short targetVal;
    short : 16;
    int : 32;
} RootCounter;

int (*D_80032834)[2] = (int (*)[2])0x1F801070;
volatile RootCounter (*D_80032838)[4] = (RootCounter(*)[4])0x1F801100;
long D_8003283C[4] = { 0x10, 0x20, 0x40, 1 };

long SetRCnt(u_long counter, u_short targetVal, long mode)
{
    int i;
    u_short newMode;

    i = counter & 0xFFFF;
    newMode = 0x48;

    if (i >= 3) {
        return 0;
    }

    (*D_80032838)[i].mode = 0;
    (*D_80032838)[i].targetVal = targetVal;

    if (i < 2u) {
        if (mode & 0x10) {
            newMode = 0x49;
        }
        if (!(mode & 1)) {
            newMode |= 0x100;
        }
    } else {
        if (i == 2) {
            if (!(mode & 1)) {
                newMode = 0x248;
            }
        }
    }
    if ((mode & 0x1000) != 0) {
        newMode |= 0x10;
    }
    (*D_80032838)[i].mode = newMode;
    return 1;
}

long GetRCnt(u_long spec)
{
    int i = spec & 0xFFFF;
    if (i >= 3) {
        return 0;
    }
    return (*D_80032838)[i].currentVal;
}

long StartRCnt(u_long spec)
{
    int i;

    i = spec & 0xFFFF;
    (*D_80032834)[1] |= D_8003283C[i];
    return i < 3;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libapi/COUNTER", StopRCnt);

long ResetRCnt(u_long spec)
{
    int i;

    i = spec & 0xFFFF;
    if (i >= 3) {
        return 0;
    }
    (*((RootCounter(*)[4])D_80032838))[i].currentVal = 0;
    return 1;
}
