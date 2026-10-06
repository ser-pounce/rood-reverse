#include "common.h"
#include <setjmp.h>
#include <libapi.h>

typedef struct {
    int unk0;
    void* (*unk4)(int, void (*)());
    void (*unk8)(int, void (*)());
    void (*unkC)(void);
    void (*unk10)(void);
    int (*unk14)(int, void (*)());
    void (*unk18)(void);
} D_800320D4_t;

extern D_800320D4_t* D_800320D4;
extern unsigned short D_8003104E;
extern volatile unsigned short* D_800320DC;
extern volatile unsigned short* D_800320D8;
extern volatile int* D_800320E0;

typedef struct {
    unsigned short interruptsInitialized;
    unsigned short inInterrupt;
    void (*handlers[11])();
    unsigned short enabledInterruptsMask;
    unsigned short savedMask;
    int savedPcr;
    jmp_buf buf;
    int stack[1024];
} IntrEnv;

extern IntrEnv D_8003104C;

extern void HookEntryInt(jmp_buf);
extern void ResetEntryInt(void);
extern void ChangeClearRCnt(int, int);

void ResetCallback(void) { D_800320D4->unkC(); }

void InterruptCallback(int irq, void (*f)()) { D_800320D4->unk8(irq, f); }

void* DMACallback(int dma, void (*f)()) { return D_800320D4->unk4(dma, f); }

int VSyncCallback(void (*f)()) { return D_800320D4->unk14(4, f); }

int VSyncCallbacks(int ch, void (*f)()) { return D_800320D4->unk14(ch, f); }

void StopCallback(void) { D_800320D4->unk10(); }

void RestartCallback(void) { D_800320D4->unk18(); }

int CheckCallback(void) { return D_8003104E; }

int GetIntrMask(void) { return *D_800320DC; }

int SetIntrMask(int mask)
{
    unsigned short old = *D_800320DC;
    *D_800320DC = mask;
    return old;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libetc/INTR", func_8001FA68);

INCLUDE_RODATA("build/src/SLUS_010.40/nonmatchings/libetc/INTR", D_800101E4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libetc/INTR", func_8001FB40);

void* func_8001FD10(int irq, void (*handler)())
{
    void (*prev)() = D_8003104C.handlers[irq];
    int mask;

    if (handler != prev && D_8003104C.interruptsInitialized != 0) {
        mask = *D_800320DC;
        *D_800320DC = 0;
        if (handler != NULL) {
            D_8003104C.handlers[irq] = handler;
            mask |= 1 << irq;
            D_8003104C.enabledInterruptsMask |= 1 << irq;
        } else {
            D_8003104C.handlers[irq] = NULL;
            mask &= ~(1 << irq);
            D_8003104C.enabledInterruptsMask &= ~(1 << irq);
        }
        if (irq == 0) {
            ChangeClearPAD(handler == NULL);
            ChangeClearRCnt(3, handler == NULL);
        }
        if (irq == 4) {
            ChangeClearRCnt(0, handler == NULL);
        }
        if (irq == 5) {
            ChangeClearRCnt(1, handler == NULL);
        }
        if (irq == 6) {
            ChangeClearRCnt(2, handler == NULL);
        }
        *D_800320DC = mask;
    }
    return prev;
}

void* func_8001FE58(void)
{
    if (D_8003104C.interruptsInitialized == 0) {
        return NULL;
    }
    EnterCriticalSection();
    D_8003104C.savedMask = *D_800320DC;
    D_8003104C.savedPcr = *D_800320E0;
    *D_800320D8 = *D_800320DC = 0;
    *D_800320E0 &= 0x77777777;
    ResetEntryInt();
    D_8003104C.interruptsInitialized = 0;
    return &D_8003104C;
}

void* func_8001FEF8(void)
{
    if (D_8003104C.interruptsInitialized != 0) {
        return NULL;
    }
    HookEntryInt(D_8003104C.buf);
    D_8003104C.interruptsInitialized = 1;
    *D_800320DC = D_8003104C.savedMask;
    *D_800320E0 = D_8003104C.savedPcr;
    ExitCriticalSection();
    return &D_8003104C;
}

void memzero(long* ptr, long size)
{
    long i = size - 1;

    if (size != 0) {
        do {
            *ptr++ = 0;
        } while (--i != -1);
    }
}
