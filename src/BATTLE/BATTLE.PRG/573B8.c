#include "common.h"
#include "build/src/include/lbas.h"
#include "146C.h"
#include "573B8.h"
#include "../SLUS_010.40/main.h"

extern u_char D_800E9C30[];
extern u_char* D_800EB9B8;
extern vs_main_CdQueueSlot* D_800F4BBC;
extern vs_main_CdFile D_800F4BF0;

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/573B8", func_800BFBB8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/573B8", func_800BFD9C);

short vs_battle_getShort(u_char* arg0)
{
    if (!((long)arg0 & 1)) {
        return *(short*)arg0;
    }
    return arg0[0] | (arg0[1] << 8);
}

int func_800BFE34(u_char* arg0) { return D_800E9C30[arg0[0]]; }

int func_800BFE50(u_short arg0)
{
    switch (arg0 >> 12) {
    case 0:
        return func_8007CF18(arg0 & 0xFFF);
    case 1:
        return arg0 & 0x1F;
    case 2:
        return arg0;
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/573B8", func_800BFEBC);

void func_800C00E8(int arg0, void* arg1)
{
    D_800F4BF0.size = VS_0000_EVT_SIZE;
    D_800F4BF0.lba = (_evtFile * 3) + VS_0000_EVT_LBA; // .EVT files must be sequential
    D_800F4BBC = vs_main_allocateCdQueueSlot(&D_800F4BF0);
    vs_main_cdEnqueue(D_800F4BBC, arg1);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/573B8", func_800C0150);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/573B8", vs_battle_copyAligned);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/573B8", vs_battle_memcpy);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/573B8", func_800C0214);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/573B8", vs_battle_setSprite);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/573B8", func_800C02A8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/573B8", vs_battle_playSfx10);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/573B8", vs_battle_playInvalidSfx);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/573B8", vs_battle_playMenuLeaveSfx);

INCLUDE_ASM(
    "build/src/BATTLE/BATTLE.PRG/nonmatchings/573B8", vs_battle_playMenuSelectSfx);

INCLUDE_ASM(
    "build/src/BATTLE/BATTLE.PRG/nonmatchings/573B8", vs_battle_playMenuChangeSfx);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/573B8", func_800C031C);

void func_800C05B4(void)
{
    if (D_800EB9B8 != NULL) {
        vs_main_freeHeap(D_800EB9B8);
        D_800EB9B8 = NULL;
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/573B8", func_800C05EC);

void func_800C06E0(void)
{
    if (D_800EB9B8 != NULL) {
        D_800EB9B8[0] = 0;
    }
}

u_char* func_800C0700(int* arg0)
{
    register int ptr asm("v1") = (int)D_800EB9B8;
    register u_char* ret asm("v0") = (u_char*)ptr;
    int temp_a1;
    int temp_a2;
    int temp_a3;
    register int temp_t0 asm("t0");

    __asm__("" : "+r"(ptr) : : "memory");

    temp_a1 = arg0[0];
    temp_a2 = arg0[1];
    temp_a3 = arg0[2];
    temp_t0 = arg0[3];

    *(int*)(ptr + 0x10) = temp_a1;
    *(int*)(ptr + 0x14) = temp_a2;
    *(int*)(ptr + 0x18) = temp_a3;
    *(int*)(ptr + 0x1C) = temp_t0;
    *(short*)(ret + 0x2A) = 0;
    return ret;
}

void func_800C0738(void)
{
    if (D_800EB9B8 != NULL) {
        D_800EB9B8[0x10] = 0;
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/573B8", func_800C0758);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/573B8", func_800C085C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/573B8", func_800C0990);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/573B8", func_800C0B50);
