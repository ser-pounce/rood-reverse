#include "common.h"
#include <libapi.h>

extern int D_80033664;
extern volatile int* D_8003366C;
extern int D_8003FEA8;
extern long StartPAD2(void);
extern void StopPAD2(void);
extern int SysDeqIntRP(int, void*);
int func_8002EC50(void);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libapi/PAD", SetInitPadFlag);

int ReadInitPadFlag(void) { return D_80033664; }

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libapi/PAD", PAD_init);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libapi/PAD", func_8002EAE0);

long StartPAD(void)
{
    StartPAD2();
    ChangeClearPAD(0);
    EnablePAD();
    return 1;
}

void StopPAD(void)
{
    DisablePAD();
    StopPAD2();
    func_8002EC50();
    D_80033664 = 0;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libapi/PAD", func_8002EBD8);

int func_8002EC50(void)
{
    EnterCriticalSection();
    SysDeqIntRP(1, &D_8003FEA8);
    ExitCriticalSection();
    return 1;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libapi/PAD", func_8002EC88);

int func_8002ECF0(void)
{
    int ret;

    ret = D_8003366C[1] & 1;
    if (ret == 0) {
        return 0;
    }
    if ((D_8003366C[0] & 1) == 0) {
        return 0;
    }
    ret = 1;
    return ret;
}
