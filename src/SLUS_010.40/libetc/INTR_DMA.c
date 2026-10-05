#include "common.h"

extern int* D_80032124;
extern void (*D_80032128[8])();

void func_80020100(void);
void* func_80020280(int ch, void (*func)());
void func_8002032C(long* ptr, long size);
void InterruptCallback(int irq, void (*f)());

void* startIntrDMA(void)
{
    func_8002032C((long*)D_80032128, 8);
    *D_80032124 = 0;
    InterruptCallback(3, func_80020100);
    return func_80020280;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libetc/INTR_DMA", func_80020100);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libetc/INTR_DMA", func_80020280);

void func_8002032C(long* ptr, long size)
{
    long i = size - 1;

    if (size != 0) {
        do {
            *ptr++ = 0;
        } while (--i != -1);
    }
}
