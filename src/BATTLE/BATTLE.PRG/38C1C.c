#include "common.h"
#include "3A1A0.h"
#include <libgpu.h>

void func_8009DF3C(int, int);
int func_800A152C(int, int, int);
int func_800A17BC(int, int, void*);
int func_800A1C10(int arg0, int arg1, int arg2, int arg3);
void func_800A9EB4(int, int, int);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/38C1C", func_800A141C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/38C1C", func_800A152C);

// https://decomp.me/scratch/N9nFn
INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/38C1C", func_800A1648);

int func_800A1720(int arg0, int arg1, int* arg2)
{
    int var_v0 = arg1;

    if (arg1 == 0xFD) {
        var_v0 = 0;
    }

    var_v0 = func_800A17BC(arg0, var_v0, arg2);

    if (var_v0 < 0) {
        return var_v0;
    }

    if (arg1 == 0xFD) {
        arg2[6] = D_800F4538[arg0]->unk0.position.vy;
    }

    return 0;
}

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

void func_800A0204(int, int, int, int);

void func_800A249C(int arg0, int arg1)
{
    int var_a2;
    int var_a1;
    int v1;
    D_800F4538_t* temp_a3 = D_800F4538[arg0];

    if (temp_a3->unk0.unkA_5) {
        return;
    }

    var_a1 = arg1 - temp_a3->unk0.facing;

    if (var_a1 > 0x800) {
        var_a1 -= 0x1000;
    }

    if (var_a1 < -0x800) {
        var_a1 += 0x1000;
    }

    if (var_a1 == 0) {
        return;
    }

    temp_a3->unk1848.unk0 = 6;

    v1 = temp_a3->animationId;

    if ((v1 == 0x76) || (temp_a3->animationId == 0x75) || temp_a3->unk0.unkC_0) {
        return;
    }

    var_a2 = 0x1F;

    if (!(temp_a3->unk0.unkA_6)) {

        var_a2 = 0x11;

        if (var_a1 < 0) {
            var_a2 = 0x12;
        }
    }

    func_800A0204(arg0, var_a2, 0, 0xA);
}

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
    addVector(&arg0->unk0.position, &arg0->unk1848.unk10);

    arg0->unk0.unk5C = arg0->unk0.position.vx / 128;
    arg0->unk0.unk5E = arg0->unk0.position.vz / 128;

    func_800AA850(arg0->unk0.unkF, arg0->unk1848.unk6, 12);
}
