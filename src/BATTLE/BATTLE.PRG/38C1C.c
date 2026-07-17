#include "common.h"
#include "3A1A0.h"
#include <libgpu.h>

void func_8009DF3C(int, int);
int func_800A152C(int, int, int);
int func_800A1C10(int arg0, int arg1, int arg2, int arg3);
void func_800A9EB4(int, int, int);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/38C1C", func_800A141C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/38C1C", func_800A152C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/38C1C", func_800A1648);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/38C1C", func_800A1720);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/38C1C", func_800A17BC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/38C1C", func_800A190C);

int func_800A1AF8(int arg0, int arg1, int arg2, int arg3)
{
    int var_v0 = func_800A1C10(arg0, arg1, arg2, arg3);

    if (var_v0 < 0) {
        return var_v0;
    }

    return 0;
}

int func_800A1B28(int arg0, int arg1, int arg2, int arg3)
{
    int var_v0 = func_800A152C(arg0, arg1, 1);

    if (var_v0 < 0) {
        return var_v0;
    }

    var_v0 = func_800A1C10(arg0, var_v0, arg2, arg3);

    if (var_v0 < 0) {
        return var_v0;
    }

    return 0;
}

int func_800A1B9C(int arg0, int arg1, int arg2, int arg3)
{
    int var_v0 = func_800A152C(arg0, arg1, 2);

    if (var_v0 < 0) {
        return var_v0;
    }

    var_v0 = func_800A1C10(arg0, var_v0, arg2, arg3);

    if (var_v0 < 0) {
        return var_v0;
    }

    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/38C1C", func_800A1C10);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/38C1C", func_800A1DE8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/38C1C", func_800A208C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/38C1C", func_800A249C);

void func_800A2574(int arg0, short arg1)
{
    D_800F4538_t* temp_s1 = D_800F4538[arg0];
    func_800A9EB4(arg0, arg1, 8);
    func_8009DF3C(arg0, 3);
    temp_s1->unk0.unkB_4 = 6;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/38C1C", func_800A25EC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/38C1C", func_800A2790);

void func_800AA850(int, int, int);

void func_800A291C(D_800F4538_t* arg0)
{
    addVector(&arg0->unk0.unk1C, &arg0->unk1848.unk10);

    arg0->unk0.unk5C = arg0->unk0.unk1C.vx / 128;
    arg0->unk0.unk5E = arg0->unk0.unk1C.vz / 128;

    func_800AA850(arg0->unk0.unkF, arg0->unk1848.unk6, 12);
}
