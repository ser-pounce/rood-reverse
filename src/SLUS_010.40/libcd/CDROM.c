#include "common.h"
#include <libcd.h>

extern StHEADER* D_80039C48;
extern u_long D_80039C4C;

void StSetRing(u_long* ring_addr, u_long ring_size)
{
    D_80039C48 = (StHEADER*)ring_addr;
    D_80039C4C = ring_size;
    StClearRing();
}
