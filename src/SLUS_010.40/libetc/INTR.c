#include "common.h"

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
extern unsigned short* D_800320DC;

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

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libetc/INTR", func_8001FD10);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libetc/INTR", func_8001FE58);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libetc/INTR", func_8001FEF8);

void memzero(long* ptr, long size)
{
    long i = size - 1;

    if (size != 0) {
        do {
            *ptr++ = 0;
        } while (--i != -1);
    }
}
