#include "common.h"

typedef struct {
    void* next;
    int (*func2)();
    int (*func1)();
    int unk;
} PadIntRP;

extern volatile int* D_800335FC; /* interrupt status/mask registers */
extern volatile u_short* D_80033600; /* SIO0 registers */
extern int (*D_800335C4)();
extern PadIntRP D_8003FC00;
extern int chkRC2wait(void);

extern void EnterCriticalSection(void);
extern void ExitCriticalSection(void);
extern int ChangeClearRCnt(int, int);
extern int SysDeqIntRP(int, PadIntRP*);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADMAIN", PadEnableCom);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADMAIN", _padSetVsyncParam);

int func_8002BDE8(void)
{
    if (!(D_800335FC[1] & 1)) {
        return 0;
    }
    if (!(D_800335FC[0] & 1)) {
        return 0;
    }
    if (D_800335C4) {
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
    SysDeqIntRP(2, &D_8003FC00);
    ExitCriticalSection();
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADMAIN", _padInitSioMode);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADMAIN", func_8002C438);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADMAIN", _padSioRW);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADMAIN", _padSioRW2);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADMAIN", _padClrIntSio0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADMAIN", _padWaitRXready);
