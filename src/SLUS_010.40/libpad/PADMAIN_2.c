#include "PADMAIN_internal.h"

int func_8002BDE8(void)
{
    if (!(D_800335FC->mask & 1)) {
        return 0;
    }
    if (!(D_800335FC->stat & 1)) {
        return 0;
    }
    if (D_800335C4) {
        D_800335C4();
    }
    return 1;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADMAIN_2", func_8002BE50);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADMAIN_2", _padChkVsync);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADMAIN_2", _padStartCom);

void _padStopCom(void)
{
    EnterCriticalSection();
    ChangeClearRCnt(3, 1);
    SysDeqIntRP(2, &D_8003FC00);
    ExitCriticalSection();
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADMAIN_2", _padInitSioMode);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADMAIN_2", func_8002C438);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADMAIN_2", _padSioRW);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADMAIN_2", _padSioRW2);

int _padClrIntSio0(void)
{
    D_800335FC->stat = ~0x80;
    while (D_80033600[2] & 0x80) {
        if (chkRC2wait()) {
            return 0;
        }
    }
    D_80033600[5] |= 0x10;
    return 1;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADMAIN_2", _padWaitRXready);
