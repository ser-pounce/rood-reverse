#include "common.h"
#include <libcd.h>

extern u_long* D_80039C48;
extern int D_80039C30;
extern int D_80039C2C;
extern int D_80039C24;
extern int D_80039C80;
extern CdlLOC D_80039C88;
extern u_long D_80039C8C;
extern void (*D_80039C98)(void);

void data_ready_callback(void)
{
    u_long* h;

    h = D_80039C48 + D_80039C30 * HEADER_SIZE;
    *(u_short*)h = StCOMPLETE;
    D_80039C88 = ((StHEADER*)h)->loc;
    D_80039C8C = h[2];
    D_80039C30 = D_80039C2C;
    if (D_80039C98 != NULL) {
        D_80039C98();
    }
    D_80039C24 = 0;
}

int StGetBackloc(CdlLOC* loc)
{
    if (D_80039C80 != 0) {
        return -1;
    }
    CdIntToPos(CdPosToInt(&D_80039C88) + 1, loc);
    return D_80039C8C;
}
