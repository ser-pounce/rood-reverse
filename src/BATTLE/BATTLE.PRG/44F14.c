#include "common.h"
#include "44F14.h"
#include "../../SLUS_010.40/main.h"

extern void* D_800F4538[];

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800AD714);

void func_800AE46C(void) { }

void func_800AE474(void) { }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800AE47C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800AE4FC);

void func_800AE68C(int arg0, int arg1) { func_800AE4FC(D_800F4538[arg0], arg1 + 4); }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800AE6C0);

void func_800AE7D8(int arg0, int arg1, int arg2)
{
    SVECTOR* temp_s0;

    temp_s0 = arg0 + 0x1C;
    vs_main_panSfx(0x7E, arg1, temp_s0);
    if (arg2 != 0) {
        vs_main_panSfx(0x7E, arg2, temp_s0);
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800AE828);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800AE980);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800AEAE8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800AECA0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800AEEC4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800AEF94);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800AF6E8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800AF844);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800AF960);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800AFA28);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800AFDE8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800B002C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800B07DC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800B0908);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800B101C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800B13CC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800B147C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800B16F4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800B17F0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800B196C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800B1A68);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800B217C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800B26B8);
