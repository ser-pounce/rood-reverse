#include "common.h"

extern long D_80032114;
extern int* D_80032118;
extern void (*D_800320F4[8])();

void func_8001FFEC(void);
void func_80020058(int index, void (*func)());
void func_80020084(long* ptr, long size);
void InterruptCallback(int irq, void (*f)());

void* startIntrVSync(void)
{
    *D_80032118 = 0x100;
    D_80032114 = 0;
    func_80020084((long*)D_800320F4, 8);
    InterruptCallback(0, func_8001FFEC);
    return func_80020058;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libetc/INTR_VB", func_8001FFEC);

void func_80020058(int index, void (*func)())
{
    if (func != D_800320F4[index]) {
        D_800320F4[index] = func;
    }
}

void func_80020084(long* ptr, long size)
{
    long i = size - 1;

    if (size != 0) {
        do {
            *ptr++ = 0;
        } while (--i != -1);
    }
}
