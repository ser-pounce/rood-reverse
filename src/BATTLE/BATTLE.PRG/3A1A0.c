#include "common.h"
#include "3A1A0.h"

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A29A0);

u_int func_800A29A0(void*);                             /* extern */
u_int func_800A9C54(u_char, void*, int);                        /* extern */
extern void* D_800F4538[];

typedef struct {
    u_char unk0[0x07];
    u_int  unk8;
    u_char unkC[0x03];
    u_char unkF;
    u_char unk10[0x5DC];
    u_char unk5EC[0xF4];
    u_char unk6E0;
    u_char unk6E4[0x111C];
    u_char unk17FD;
} func_800A2C48_t;

void func_800A2C48(func_800A2C48_t* arg0) {
    func_800A9C54(arg0->unkF, &arg0->unk5EC, 0);
    arg0->unk6E0 = 0;
    arg0->unk8 = (arg0->unk8 & 0xF0FFFFFF) | 0x04000000;
    func_800A29A0(arg0);
    if (arg0->unk17FD >= 2U) {
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

short func_8008DD0C(void);

int func_800A3BC4(void) {
    short temp_v0 = func_8008DD0C();
    if (temp_v0 == 0) {
        return 0;
    }
    return ((int)temp_v0 << 0x11) >> 0x11;
}

typedef struct {
    u_char unk00[0x1E];
    short  unk1E;
    u_char unk20[0x3C];
    u_char unk5C;
    u_char unk5D;
    u_char unk5E;
    u_char unk5F;
} struct_800A3C00;

void func_800A3C34(u_char, u_char, short, u_int);

void func_800A3C00(struct_800A3C00 *arg0, u_int arg1) {
    func_800A3C34(arg0->unk5C, arg0->unk5E, arg0->unk1E, arg1);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A3C34);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A3DB4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A3E6C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A41D0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A4494);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A46A4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A47C4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A4828);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A48CC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A4A24);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A4A88);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A4D8C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A4E68);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A51A0);

typedef struct {
    u_char unk0[0x0F];
    u_char unkF;
    u_int unk10[1550];
    u_char unk1848;
    u_char unk1849;
    u_char unk184A;
    u_char unk184B;
    u_short unk184C;
    u_short unk184E;
    u_int unk1850;
} func_800A525C_t;

void func_800A525C(func_800A525C_t* arg0)
{
    arg0->unk1848 = 1;
    if (arg0->unkF == 0) {
        arg0->unk1848 = 0;
    }
    arg0->unk184C = 0;
    arg0->unk1850 = 0;
    arg0->unk184E = 0;
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
