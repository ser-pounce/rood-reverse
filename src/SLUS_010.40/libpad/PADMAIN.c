#include "pad.h"
#include "PADMAIN.h"
#include "WAITRC2.h"
#include <libapi.h>

int ChangeClearRCnt(int, int);
int SysDeqIntRP(int, void*);

extern void (*D_800335C4)(void);
extern volatile padIntr* D_800335FC;
extern volatile padSio* D_80033600;
extern int D_8003FC00[];

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADMAIN", PadEnableCom);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADMAIN", _padSetVsyncParam);

int func_8002BDE8(void)
{
    if (!(D_800335FC->mask & 1) || !(D_800335FC->stat & 1)) {
        return 0;
    }

    if (D_800335C4 != NULL) {
        D_800335C4();
    }

    return 1;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADMAIN", func_8002BE50);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADMAIN", _padChkVsync);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADMAIN", _padStartCom);

void _padStopCom(void)
{
    EnterCriticalSection();
    ChangeClearRCnt(3, 1);
    SysDeqIntRP(2, D_8003FC00);
    ExitCriticalSection();
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADMAIN", _padInitSioMode);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADMAIN", func_8002C438);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADMAIN", _padSioRW);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADMAIN", _padSioRW2);

int _padClrIntSio0(void)
{
    D_800335FC->stat = ~0x80;

    while (D_80033600->stat & 0x80) {
        if (chkRC2wait()) {
            return 0;
        }
    }

    D_80033600->ctrl |= 0x10;
    return 1;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADMAIN", _padWaitRXready);
