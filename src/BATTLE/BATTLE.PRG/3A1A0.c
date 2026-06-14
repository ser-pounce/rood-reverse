#include "common.h"
#include "30D14.h"
#include "3A1A0.h"

u_int func_800A29A0(void*);
u_int func_800A9C54(u_char, void*, int);
void func_800AEAE8(void*);
void func_800AECA0(MATRIX*);
void func_800B28A8(void*, MATRIX*, int);
short func_8008DD0C(int arg0, int arg1);
D_800F4538_t* func_800A3C34(u_char, u_char, short, u_int);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A29A0);

void func_800A2C48(D_800F4538_t* arg0)
{
    func_800A9C54(arg0->unk0.unkF, &arg0->unk5DC[4], 0);
    arg0->unk6E0 = 0;
    arg0->unk0.unkB_0 = 4;
    func_800A29A0(arg0);
    if (arg0->unk17FD >= 2) {
        func_800A2C48(D_800F4538[arg0->unk17FD]);
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A2CD4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A2FBC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A3054);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A30A0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A3310);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A3394);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A3500);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A35A8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A36E0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A3760);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A38E0);

int func_800A3BC4(int arg0, int arg1)
{
    short temp_v0 = func_8008DD0C(arg0, arg1);
    if (temp_v0 == 0) {
        return 0;
    }
    return (temp_v0 << 0x11) >> 0x11;
}

D_800F4538_t* func_800A3C00(D_800F45E0_t* arg0, u_int arg1)
{
    return func_800A3C34(arg0->unk5C, arg0->unk5E, arg0->unk1E, arg1);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A3C34);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A3DB4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A3E6C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A41D0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A4494);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A46A4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A47C4);

void func_800A4828(int arg0, MATRIX* arg1)
{
    D_800F4538_t* temp_s1 = D_800F4538[arg0];
    int temp_s0 = temp_s1->unk0.unk8_1;
    temp_s1->unk0.unk8_1 = 0;
    temp_s1->unk5B2 = 1;
    func_800AECA0(arg1);
    func_800AEAE8(temp_s1);
    func_800B28A8(temp_s1, arg1, 0);
    temp_s1->unk0.unk8_1 = temp_s0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A48CC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A4A24);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A4A88);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A4D8C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A4E68);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A51A0);

void func_800A525C(D_800F4538_t* arg0)
{
    arg0->unk1848.unk0 = 1;
    if (arg0->unk0.unkF == 0) {
        arg0->unk1848.unk0 = 0;
    }
    arg0->unk1848.unk4 = 0;
    arg0->unk1848.unk8 = 0;
    arg0->unk1848.unk6 = 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A5280);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A6660);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A6798);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A69B4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A6AA0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A6EE8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A70DC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A7524);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A76BC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A8B34);
