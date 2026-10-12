#include "DSSYS_1_internal.h"

void DS_init(void)
{
    CD_init();
    CD_initvol();
    D_80039E54 = D_80039E58 = NULL;
    D_80039E50 = NULL;
    DS_reset_members();
    DsReadMode(0);
    D_800321FC = func_80024F34;
    D_80032200 = func_8002559C;
    VSyncCallbacks(0, func_80024BDC);
    D_8003221C = 1;
    D_8003267C.active = 1;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1", DS_reset_members);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1", DS_close);

void func_8002480C(void)
{
    D_8003267C.active = 0;
    CD_flush();
    D_800321FC = NULL;
    D_80032200 = NULL;
    VSyncCallbacks(0, NULL);
}
