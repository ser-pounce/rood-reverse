#include "common.h"
#include "lbas.h"
#include "../SLUS_010.40/main.h"

extern vs_main_CdQueueSlot* D_800F4BBC;
extern vs_main_CdFile D_800F4BF0;
extern short _evtFile;

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/573B8", func_800BFBB8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/573B8", func_800BFD9C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/573B8", func_800BFE00);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/573B8", func_800BFE34);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/573B8", func_800BFE50);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/573B8", func_800BFEBC);

void func_800C00E8(int arg0, void* arg1)
{
    D_800F4BF0.size = VS_0000_EVT_SIZE;
    D_800F4BF0.lba = (_evtFile * 3) + VS_0000_EVT_LBA; // .EVT files must be sequential
    D_800F4BBC = vs_main_allocateCdQueueSlot(&D_800F4BF0);
    vs_main_cdEnqueue(D_800F4BBC, arg1);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/573B8", func_800C0150);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/573B8", func_800C01C0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/573B8", func_800C0214);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/573B8", func_800C0230);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/573B8", func_800C02A8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/573B8", func_800C02D8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/573B8", func_800C02E0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/573B8", func_800C02E8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/573B8", func_800C02F0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/573B8", func_800C02F8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/573B8", func_800C031C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/573B8", func_800C05B4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/573B8", func_800C05EC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/573B8", func_800C06E0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/573B8", func_800C0700);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/573B8", func_800C0738);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/573B8", func_800C0758);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/573B8", func_800C085C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/573B8", func_800C0990);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/573B8", func_800C0B50);
