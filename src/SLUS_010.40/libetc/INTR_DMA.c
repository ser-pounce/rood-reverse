#include "common.h"

extern volatile u_int* D_80032124;
extern void (*D_80032128[8])();
extern volatile int* D_80032148;
extern int printf(const char*, ...);

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

void func_80020100(void)
{
    int i;
    u_int mask;

    mask = (*D_80032124 >> 24) & 0x7F;
    while (mask != 0) {
        for (i = 0; mask != 0 && i < 7; i++, mask >>= 1) {
            if (mask & 1) {
                *D_80032124 &= 0xFFFFFF | (1 << (i + 24));
                if (D_80032128[i] != NULL) {
                    D_80032128[i]();
                }
            }
        }
        mask = (*D_80032124 >> 24) & 0x7F;
    }
    if ((*D_80032124 & 0xFF000000) == 0x80000000 || (*D_80032124 & 0x8000)) {
        printf("DMA bus error: code=%08x\n", *D_80032124);
        for (i = 0; i < 7; i++) {
            printf("MADR[%d]=%08x\n", i, D_80032148[i * 4]);
        }
    }
}

void* func_80020280(int ch, void (*func)())
{
    void (*prev)() = D_80032128[ch];

    if (func != prev) {
        if (func != NULL) {
            D_80032128[ch] = func;
            *D_80032124 = (*D_80032124 & 0xFFFFFF) | 0x800000 | (1 << (ch + 16));
        } else {
            D_80032128[ch] = NULL;
            *D_80032124 = ((*D_80032124 & 0xFFFFFF) | 0x800000) & ~(1 << (ch + 16));
        }
    }
    return prev;
}

void func_8002032C(long* ptr, long size)
{
    long i = size - 1;

    if (size != 0) {
        do {
            *ptr++ = 0;
        } while (--i != -1);
    }
}
