#include "common.h"
#include "src/BATTLE/BATTLE.PRG/5BF94.h"
#include "src/BATTLE/BATTLE.PRG/6E644.h"

void func_800FAC4C(void);
void func_800FAD7C(void);

INCLUDE_ASM("build/src/EFFECT/EFFPURGE.BIN/nonmatchings/0", func_800F9800);

INCLUDE_ASM("build/src/EFFECT/EFFPURGE.BIN/nonmatchings/0", func_800F9818);

INCLUDE_ASM("build/src/EFFECT/EFFPURGE.BIN/nonmatchings/0", func_800F98E0);

INCLUDE_ASM("build/src/EFFECT/EFFPURGE.BIN/nonmatchings/0", func_800F98F8);

INCLUDE_ASM("build/src/EFFECT/EFFPURGE.BIN/nonmatchings/0", func_800F9910);

INCLUDE_ASM("build/src/EFFECT/EFFPURGE.BIN/nonmatchings/0", func_800F9928);

INCLUDE_ASM("build/src/EFFECT/EFFPURGE.BIN/nonmatchings/0", func_800F99D8);

INCLUDE_ASM("build/src/EFFECT/EFFPURGE.BIN/nonmatchings/0", func_800F99F0);

INCLUDE_ASM("build/src/EFFECT/EFFPURGE.BIN/nonmatchings/0", func_800F9AE8);

INCLUDE_ASM("build/src/EFFECT/EFFPURGE.BIN/nonmatchings/0", func_800FA30C);

INCLUDE_ASM("build/src/EFFECT/EFFPURGE.BIN/nonmatchings/0", func_800FA324);

INCLUDE_ASM("build/src/EFFECT/EFFPURGE.BIN/nonmatchings/0", func_800FA368);

INCLUDE_ASM("build/src/EFFECT/EFFPURGE.BIN/nonmatchings/0", func_800FA398);

INCLUDE_ASM("build/src/EFFECT/EFFPURGE.BIN/nonmatchings/0", func_800FA3B0);

INCLUDE_ASM("build/src/EFFECT/EFFPURGE.BIN/nonmatchings/0", func_800FA41C);

INCLUDE_ASM("build/src/EFFECT/EFFPURGE.BIN/nonmatchings/0", func_800FA424);

INCLUDE_ASM("build/src/EFFECT/EFFPURGE.BIN/nonmatchings/0", func_800FA48C);

INCLUDE_ASM("build/src/EFFECT/EFFPURGE.BIN/nonmatchings/0", func_800FA490);

INCLUDE_ASM("build/src/EFFECT/EFFPURGE.BIN/nonmatchings/0", func_800FA4A8);

INCLUDE_ASM("build/src/EFFECT/EFFPURGE.BIN/nonmatchings/0", func_800FA588);

INCLUDE_ASM("build/src/EFFECT/EFFPURGE.BIN/nonmatchings/0", func_800FA6B8);

INCLUDE_ASM("build/src/EFFECT/EFFPURGE.BIN/nonmatchings/0", func_800FA6BC);

INCLUDE_ASM("build/src/EFFECT/EFFPURGE.BIN/nonmatchings/0", func_800FA6D0);

INCLUDE_ASM("build/src/EFFECT/EFFPURGE.BIN/nonmatchings/0", func_800FA6F8);

INCLUDE_ASM("build/src/EFFECT/EFFPURGE.BIN/nonmatchings/0", func_800FA710);

INCLUDE_ASM("build/src/EFFECT/EFFPURGE.BIN/nonmatchings/0", func_800FA740);

INCLUDE_ASM("build/src/EFFECT/EFFPURGE.BIN/nonmatchings/0", func_800FA770);

INCLUDE_ASM("build/src/EFFECT/EFFPURGE.BIN/nonmatchings/0", func_800FA7B0);

INCLUDE_ASM("build/src/EFFECT/EFFPURGE.BIN/nonmatchings/0", func_800FA7F0);

INCLUDE_ASM("build/src/EFFECT/EFFPURGE.BIN/nonmatchings/0", func_800FA84C);

INCLUDE_ASM("build/src/EFFECT/EFFPURGE.BIN/nonmatchings/0", func_800FA868);

INCLUDE_ASM("build/src/EFFECT/EFFPURGE.BIN/nonmatchings/0", func_800FA8D0);

void func_800FABB8(void)
{
    func_800D8038(0);
    func_800FAC4C();
    func_800FAD7C();
    _loadEffContext = D_800FC7FC[D_800F5230.unk0];
    func_800D2698(0xFF);
    D_800F569C->unkB4 = 0;
    D_800F56C8.unk8C = 0;
    D_800F56C8.unkC0 = 0;
    D_800F56C8.unkC4 = 0;
    D_800F56C8.unkC8 = 0;
}

INCLUDE_ASM("build/src/EFFECT/EFFPURGE.BIN/nonmatchings/0", func_800FAC4C);

void func_800FAD7C(void)
{
    int temp_s1;
    int i;
    int temp_s2;

    temp_s2 = D_800FCE3C[D_800F5230.unk0];
    temp_s1 = D_800FCE3C[D_800F5230.unk0 + 1] - temp_s2;

    func_800D7FC8(
        D_800FD6B8[D_800F5230.unk0].lba, D_800FD6B8[D_800F5230.unk0].size, temp_s1);

    for (i = 0; i < temp_s1; ++i) {
        func_800D7FE4(D_800FD15C[temp_s2 + i], i);
    }

    if (temp_s1 != 0) {
        func_800D8054(1);
    } else {
        func_800D8054(0);
    }
}
