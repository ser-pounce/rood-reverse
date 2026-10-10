#include "common.h"
#include <libcd.h>

extern int StCdIntrFlag;
extern u_long D_80039C4C;
extern int D_80039C34;
extern int D_80039C30;
extern int D_80039C2C;
extern int D_80039C24;
extern u_short D_80039C0C;
extern int D_80039C08;

void init_ring_status(int start, u_int count);

void StClearRing(void)
{
    D_80039C34 = 0;
    D_80039C30 = 0;
    D_80039C2C = 0;
    D_80039C24 = 0;
    init_ring_status(0, D_80039C4C);
    StCdIntrFlag = 0;
    D_80039C0C = 0;
    D_80039C08 = 0;
}
