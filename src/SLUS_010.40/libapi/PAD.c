#include "common.h"
#include <libapi.h>

extern int D_80033664;
extern void _remove_ChgclrPAD(void);
extern void _patch_pad(void);
extern int PAD_init2(int, int, int, int);
extern long InitPAD2(char*, long, char*, long);
int func_8002EBD8(void);
extern volatile int* D_8003366C;
extern int D_8003FEA8;
extern int (*D_8003FEAC[2])(void);
extern int D_8003FEB4;
extern long StartPAD2(void);
extern void StopPAD2(void);
extern int SysDeqIntRP(int, void*);
extern int SysEnqIntRP(int, void*);
int func_8002EC88(void);
int func_8002ECF0(void);
int func_8002EC50(void);

void SetInitPadFlag(int flag) { D_80033664 = flag; }

int ReadInitPadFlag(void) { return D_80033664; }

int PAD_init(int a0, int a1, int a2, int a3)
{
    _remove_ChgclrPAD();
    EnterCriticalSection();
    _patch_pad();
    ExitCriticalSection();
    ChangeClearPAD(0);
    func_8002EBD8();
    PAD_init2(a0, a1, a2, a3);
    D_80033664 = 1;
    return 1;
}

long func_8002EAE0(char* a0, long a1, char* a2, long a3)
{
    _remove_ChgclrPAD();
    EnterCriticalSection();
    _patch_pad();
    ExitCriticalSection();
    ChangeClearPAD(0);
    func_8002EBD8();
    InitPAD2(a0, a1, a2, a3);
    D_80033664 = 1;
    return 1;
}

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

int func_8002EBD8(void)
{
    EnterCriticalSection();
    D_8003FEAC[0] = func_8002EC88;
    D_8003FEAC[1] = func_8002ECF0;
    D_8003FEA8 = 0;
    D_8003FEB4 = 0;
    SysDeqIntRP(1, &D_8003FEAC[-1]);
    SysEnqIntRP(1, &D_8003FEAC[-1]);
    ExitCriticalSection();
    return 1;
}

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
