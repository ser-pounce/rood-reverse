/* SPDX-License-Identifier: MIT (trapIntr)
 * trapIntr (func_8001FB40) from ReGame-Labs/dcb_decomp src/main/psyq/libetc_intr.c
 * (commit 6c9caf124450cafa1b5f402d03d82b90bb02d16e; intr.c 1.75 as here), symbol renames
 * only. Copyright (c) 2026 ReGame Labs. See LICENSES/dcb_decomp-MIT.txt.
 */
#include "common.h"
#include <setjmp.h>
#include <libapi.h>

typedef struct {
    int unk0;
    int (*unk4)(int, void (*)());
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

extern int D_800320E4; /* missed interrupt count */
void* startIntrVSync(void);
void* startIntrDMA(void);
void func_8001FB40(void);
void memzero(long* ptr, long size);
int printf(const char*, ...);

void ResetCallback(void) { D_800320D4->unkC(); }

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libetc/INTR", InterruptCallback);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libetc/INTR", DMACallback);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libetc/INTR", VSyncCallback);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libetc/INTR", VSyncCallbacks);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libetc/INTR", StopCallback);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libetc/INTR", RestartCallback);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libetc/INTR", CheckCallback);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libetc/INTR", GetIntrMask);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libetc/INTR", SetIntrMask);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libetc/INTR", func_8001FA68);

INCLUDE_RODATA("build/src/SLUS_010.40/nonmatchings/libetc/INTR", D_800101E4);

void func_8001FB40(void)
{
    int i;
    u_short mask;
    short pending;

    if (D_8003104C.interruptsInitialized == 0) {
        printf("unexpected interrupt(%04x)\n", *D_800320D8);
        ReturnFromException();
    }
    D_8003104C.inInterrupt = 1;
    while ((mask = D_8003104C.enabledInterruptsMask & *D_800320D8 & *D_800320DC) != 0) {
        for (i = 0; mask != 0 && i < 11; i++, mask >>= 1) {
            if (mask & 1) {
                *D_800320D8 = ~(1 << i);
                if (D_8003104C.handlers[i] != NULL) {
                    D_8003104C.handlers[i]();
                }
            }
        }
    }
    pending = *D_800320D8 & *D_800320DC;
    if (pending) {
        if (D_800320E4++ > 0x800) {
            printf("intr timeout(%04x:%04x)\n", *D_800320D8, *D_800320DC);
            D_800320E4 = 0;
            *D_800320D8 = 0;
        }
    } else {
        D_800320E4 = 0;
    }
    D_8003104C.inInterrupt = 0;
    ReturnFromException();
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libetc/INTR", func_8001FD10);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libetc/INTR", func_8001FE58);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libetc/INTR", func_8001FEF8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libetc/INTR", memzero);
