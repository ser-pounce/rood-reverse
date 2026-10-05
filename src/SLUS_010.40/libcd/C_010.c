#include "common.h"
#include <libcd.h>

extern u_long D_80039C40;
extern u_long D_80039C1C;
extern u_long D_80039C3C;

void StSetMask(u_long mask, u_long start, u_long end)
{
    D_80039C40 = mask;
    D_80039C1C = start;
    D_80039C3C = end;
}
