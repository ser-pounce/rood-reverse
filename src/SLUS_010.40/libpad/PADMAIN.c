#include "PADMAIN.h"
#include "WAITRC2.h"
#include "pad.h"
#include <libapi.h>

int ChangeClearRCnt(int, int);
int SysDeqIntRP(int, void*);

extern void (*D_8003359C)(int);
extern void (*D_800335C4)(void);
extern int D_800335E0;
extern volatile padIntr* D_800335FC;
extern volatile padSio* D_80033600;
extern int (*D_80033624[])(padPort*);
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

void func_8002C438(padPort* port)
{
    int ret;
    int* index;
    int (*func)(padPort*);

    index = &D_800335E0;

    do {
        func = D_80033624[*index];
    } while (0);

    *index += 1;
    ret = func(port);

    if (ret >= 0) {
        if ((D_800335E0 != 0) && ((D_800335E0 != 3) || (*port->unk3C != 128))) {
            setRC2wait(60);

            if (_padClrIntSio0() == 0) {
                D_8003359C(-3);
            }
        }
        if (D_800335E0 >= 5) {
            --D_800335E0;
        }
    } else {
        D_8003359C(ret);
    }
}

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
