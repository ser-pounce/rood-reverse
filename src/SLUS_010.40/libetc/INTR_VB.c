#include "common.h"
#include <libetc.h>

void func_8001FFEC(void);
void func_80020058(int, void (*)(void));
void func_80020084(void*, int);

extern void (*D_800320F4[8])(void);
extern int D_80032114;
extern int* D_80032118;

void* startIntrVSync(void)
{
    *D_80032118 = 0x100;
    D_80032114 = 0;
    func_80020084(D_800320F4, 8);
    InterruptCallback(0, func_8001FFEC);
    return func_80020058;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libetc/INTR_VB", func_8001FFEC);

void func_80020058(int index, void (*callback)(void))
{
    if (callback != D_800320F4[index]) {
        D_800320F4[index] = callback;
    }
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libetc/INTR_VB", func_80020084);
