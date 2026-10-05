#include "common.h"

extern long D_80032154;

long SetVideoMode(long mode)
{
    long prev = D_80032154;
    D_80032154 = mode;
    return prev;
}

long GetVideoMode(void) { return D_80032154; }
