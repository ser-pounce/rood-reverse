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

enum interruptMask { VBLANK = 1, TMR0 = 0x10, TMR1 = 0x20, TMR2 = 0x40 };

static int (*_interruptReg)[2] = (int (*)[2])0x1F801070;
static volatile RootCounter (*_rootCounter0)[3] = (RootCounter(*)[3])0x1F801100;
static long _interruptMasks[4] = { TMR0, TMR1, TMR2, VBLANK };

long SetRCnt(u_long counter, u_short targetVal, long mode)
{
    int i;
    u_short newMode;

    i = counter & 0xFFFF;
    newMode = 0x48;

    if (i >= 3) {
        return 0;
    }

    (*_rootCounter0)[i].mode = 0;
    (*_rootCounter0)[i].targetVal = targetVal;

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
    (*_rootCounter0)[i].mode = newMode;
    return 1;
}

long GetRCnt(u_long spec)
{
    int i = spec & 0xFFFF;
    if (i >= 3) {
        return 0;
    }
    return (*_rootCounter0)[i].currentVal;
}

long StartRCnt(u_long spec)
{
    int i;

    i = spec & 0xFFFF;
    (*_interruptReg)[1] |= _interruptMasks[i];
    return i < 3;
}

__asm__("glabel StopRCnt;"
        "and    $a0, 0xFFFF;"
        "sll    $a0, 2;"
        "lw     $a1, _interruptReg;"
        "lw     $v0, _interruptMasks($a0);"
        "lw     $v1, 0x4($a1);"
        "nor    $v0, $zero, $v0;"
        "and    $v1, $v0;"
        "li     $v0, 0x1;"
        "j      $ra;"
        "sw     $v1, 0x4($a1)");

long ResetRCnt(u_long spec)
{
    int i;

    i = spec & 0xFFFF;
    if (i >= 3) {
        return 0;
    }
    (*((RootCounter(*)[3])_rootCounter0))[i].currentVal = 0;
    return 1;
}
