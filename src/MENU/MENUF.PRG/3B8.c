#include "common.h"
#include "../../SLUS_010.40/main.h"
#include "../../SLUS_010.40/31724.h"
#include "../../BATTLE/BATTLE.PRG/146C.h"
#include <stdio.h>
#include <libetc.h>

int func_80102D10(void);
int func_80102C54(void);
int func_8010310C(void);
int func_80103530(void);
int func_801037A0(void);
int func_8010384C(void);
int func_80103D88(void);
int func_8010412C(void);
void func_80105C34(int, int, int, int);
void func_80105DD8(int, int, int, int, int);
void func_80105F6C(int, int, int, int, int);
void func_801064D4(int, int, int, int);
void func_8010664C(int, int, int, char*);
void func_80106A80(int, int, int, char*);
void func_80107140(int, int, int, short*, int);
int func_80107A8C(void);
int func_80107D4C(void);
int func_80107D98(void);
int func_80107FC0(void);
int func_801080E4(void);
int func_801083AC(void);
void func_801084F4(int arg0, int arg1);
void func_80108564(int arg0, int arg1);
void func_801085D4(int arg0, int arg1, int arg2);
void func_8010873C(int arg0, int arg1, int arg2);
void func_80108E40(void);
void func_80108784(int arg0, int arg1, int arg2);
void func_80108E48(void);
void func_80108EA0(void);

extern char D_80102B5C[]; // "%09d"
extern char D_80102B64; // "%03d"

extern char D_801091D8[][8];
extern char D_8010923A;
extern char D_8010951A;
extern char D_8010972C[];
extern char D_80109738[];
extern char D_80109744[];
extern char D_80109754[];
extern char D_80109764[];
extern char D_80109774[];
extern short D_8010977C[];
extern char D_801097CC[];
extern char D_801097D8[];
extern char D_801097E4[];
extern short D_801097EC[];
extern u_int D_8010980C[];
extern int D_8010987C;
extern u_int D_80109884;
extern int D_80109888;
extern int D_8010989C;
extern int D_801098A0;
extern int D_801098A4;
extern int D_801098A8;
extern short D_801099F4;

int func_80102BB8(char* arg0)
{
    switch (*arg0) {
    case 0:
        *arg0 = 1;
        // Fallthrough
    case 1:
        *arg0 += (func_80102C54() != 0);
        break;
    case 2:
        if (func_801037A0() != 0) {
            *arg0 = 0;
            return 1;
        }
        break;
    }
    return 0;
}

INCLUDE_RODATA("build/src/MENU/MENUF.PRG/nonmatchings/3B8", D_80102800);

INCLUDE_RODATA("build/src/MENU/MENUF.PRG/nonmatchings/3B8", D_80102AE0);

int func_80102C54(void)
{
    int ret;

    switch (vs_main_stateFlags.unkB6) {
    case 0:
        ret = func_80102D10();
        break;
    case 1:
        ret = func_80103530();
        break;
    case 2:
        ret = func_8010310C();
        break;
    case 3:
        func_80108E48();
        func_80108EA0();
        ret = 1;
        break;
    case 4:
        ret = func_80107A8C();
        break;
    case 5:
        ret = func_80107D4C();
        break;
    case 6:
        ret = func_80107D98();
        break;
    }
    return ret;
}

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80102D10);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_8010310C);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80103530);

void func_80103748(void)
{
    if ((D_8005E040 != 7) && (((D_8005E040 - 0x1F) < 9) || ((D_8005E040 - 0x2D) < 5))) {
        vs_main_loadMusicSlot(D_8005E040 + 0x64, 2);
    } else {
        vs_main_loadMusicSlot(0x80, 2);
    }
}

int func_801037A0(void)
{
    int ret;

    switch (vs_main_stateFlags.unkB6) {
    case 0:
        ret = func_8010384C();
        break;
    case 1:
        ret = func_8010412C();
        break;
    case 2:
        ret = func_80103D88();
        break;
    case 3:
        ret = 1;
        break;
    case 4:
        ret = func_80107FC0();
        break;
    case 5:
        ret = func_801080E4();
        break;
    case 6:
        ret = func_801083AC();
        break;
    }
    // BUG: potential garbage
    return ret;
}

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_8010384C);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80103D88);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_8010412C);

void func_8010459C(int arg0, int arg1, int arg2)
{
    if (arg2 < 0) {
        arg2 = 0;
    }
    if (arg2 > 0x40) {
        arg2 = 0x40;
    }
    if (arg2 > 0) {
        D_8010972C[3] = arg2;
        D_8010972C[7] = arg2;
        arg0 -= (D_801091D8[100][2] + D_801091D8[101][2]) >> 1;
        func_80106A80(arg0, arg1, 0x64, D_8010972C);
        func_80106A80(arg0 + D_801091D8[100][2], arg1, 0x65, D_8010972C + 4);
    }
}

void func_80104650(int arg0, int arg1, int arg2)
{
    int new_var;

    if (arg2 > 0x40) {
        arg2 = 0x40;
    }

    if (arg2 > 0) {
        arg0 -= (D_801091D8[84][2] + 0x18) >> 1;
        func_80105C34(arg0, arg1, 0x54, arg2);
        new_var = arg0 + 0xC;
        func_80105DD8(new_var + D_801091D8[84][2], arg1 - 1, vs_main_stateFlags.unkC4 + 1,
            arg2, 0x7FF4);
    }
}

// https://decomp.me/scratch/whDQr
INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_801046F8);

// https://decomp.me/scratch/zHBmW
INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_801047D4);

void func_8010489C(int arg0, int arg1, int arg2)
{
    int temp_a2 = (arg2 / 15) + 0x60;
    func_80105C34(arg0 - (D_801091D8[temp_a2][2] >> 1),
        arg1 - (D_801091D8[temp_a2][3] >> 1), temp_a2, arg2 % 15);
}

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80104914);

// https://decomp.me/scratch/ZDcyC
INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80104A50);

void func_80104B8C(int arg0, int arg1, int arg2)
{
    if (arg2 < 0) {
        arg2 = 0;
    }
    if (arg2 > 0x40) {
        arg2 = 0x40;
    }
    if (arg2 > 0) {
        D_80109738[3] = arg2;
        D_80109738[7] = arg2;
        arg0 -= (D_801091D8[22][2] + D_801091D8[23][2]) >> 1;
        func_80106A80(arg0, arg1, 0x16, D_80109738);
        func_80106A80(arg0 + D_801091D8[22][2], arg1, 0x17, D_80109738 + 4);
    }
}

void func_80104C40(int arg0, int arg1, int arg2)
{
    char sp10[16];
    int i;
    int new_var;

    if (arg2 < 0) {
        arg2 = 0;
    }
    if (arg2 >= 0x41) {
        arg2 = 0x40;
    }
    if (arg2 > 0) {
        D_80109744[3] = arg2;
        sprintf(sp10, D_80102B5C, D_80109884);
        new_var = D_801091D8[18][2] + D_801091D8[26][2];
        arg0 -= (((D_801091D8[10][2] * 2) + (new_var + D_801091D8[20][2])) + 0x74) >> 1;
        func_8010664C(arg0, arg1, 0x12, D_80109744);
        arg0 += D_801091D8[18][2];
        func_8010664C(arg0, arg1 + 7, 0x1A, D_80109744);
        i = 2;
        arg0 = (arg0 + i) + D_801091D8[26][2];

        for (i = 0; i < 9; ++i) {
            func_8010664C(arg0, arg1 + 3, sp10[i] - 0x30, D_80109744);
            arg0 += 0xC;
            if ((i == 2) || (i == 5)) {
                func_8010664C(arg0, arg1 + 0xE, 0xA, D_80109744);
                arg0 += D_801091D8[10][2] + 3;
            }
        }

        func_8010664C(arg0, arg1 + 8, 0x14, D_80109744);
    }
}

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80104DBC);

void func_80105020(int arg0, int arg1, int arg2)
{
    char sp10[4];
    int i;

    if (arg2 < 0) {
        arg2 = 0;
    }
    if (arg2 > 0x40) {
        arg2 = 0x40;
    }
    if (arg2 > 0) {
        D_80109754[3] = arg2;
        sprintf(sp10, &D_80102B64, D_80109888);
        arg0 -= (D_801091D8[21][2] + D_801091D8[26][2] + D_801091D8[19][2] + 0x26) >> 1;
        i = 2;
        func_8010664C(arg0, arg1, 0x15, D_80109754);
        arg0 += D_801091D8[21][2];
        func_8010664C(arg0, arg1 + 7, 0x1A, D_80109754);
        arg0 = arg0 + i + D_801091D8[26][2];

        for (i = 0; i < 3; ++i) {
            func_8010664C(arg0, arg1 + 3, sp10[i] - 0x30, D_80109754);
            arg0 += 0xC;
        }

        func_8010664C(arg0, arg1 + 8, 0x13, D_80109754);
    }
}

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_8010516C);

void func_801053B0(int arg0, int arg1, int arg2)
{
    if (arg2 < 0) {
        arg2 = 0;
    }
    if (arg2 > 0x40) {
        arg2 = 0x40;
    }
    if (arg2 > 0) {
        D_80109764[3] = arg2;
        func_8010664C(arg0 - (D_8010923A >> 1), arg1, 0xC, D_80109764);
    }
}

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_8010540C);

void func_8010559C(int arg0, int arg1, int arg2)
{
    if (arg2 < 0) {
        arg2 = 0;
    }
    if (arg2 > 0x40) {
        arg2 = 0x40;
    }
    if (arg2 > 0) {
        D_80109774[3] = arg2;
        arg0 -= (D_801091D8[70][2] + D_801091D8[71][2]) >> 1;
        func_80106A80(arg0, arg1, 0x46, D_80109774);
        func_80106A80(arg0 + D_801091D8[70][2], arg1, 0x47, D_80109774);
    }
}

void func_8010564C(int arg0, int arg1, int arg2)
{
    int var_a2;

    if (arg2 < 0) {
        arg2 = 0;
    }
    if (arg2 > 0x40) {
        arg2 = 0x40;
    }
    if (arg2 <= 0) {
        return;
    }
    if (D_801098A8 < 0x1E00) {
        var_a2 = 0;
    } else if (D_801098A8 <= 0xFFFF) {
        var_a2 = 1;
    } else if (D_801098A8 <= 0x11DFF) {
        var_a2 = 2;
    } else if (D_801098A8 <= 0x1FFFF) {
        var_a2 = 3;
    } else {
        var_a2 = 4;
    }
    func_80105C34(arg0, arg1, var_a2 + 0x4E, arg2);
}

void func_801056E8(int arg0, int arg1, int arg2)
{
    int arg3;

    if (arg2 < 0) {
        arg2 = 0;
    }
    if (arg2 > 0x40) {
        arg2 = 0x40;
    }
    if (arg2 <= 0) {
        return;
    }

    arg3 = arg0 + (arg2 * 8);

    if (D_801098A8 < 0x1E00) {
        arg2 = 0;
    } else if (D_801098A8 <= 0xFFFF) {
        arg2 = 1;
    } else if (D_801098A8 <= 0x11DFF) {
        arg2 = 2;
    } else if (D_801098A8 <= 0x1FFFF) {
        arg2 = 3;
    } else {
        arg2 = 4;
    }
    func_80107140(arg0, arg1, arg2 + 0x4E, D_8010977C, arg3);
}

// https://decomp.me/scratch/MzjzI
INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80105790);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_8010581C);

void func_801059B8(int arg0, int arg1, int arg2)
{
    if (arg2 < 0) {
        arg2 = 0;
    }
    if (arg2 > 0x40) {
        arg2 = 0x40;
    }
    if (arg2 > 0) {
        func_80105C34(arg0, arg1, 0x45, arg2);
    }
}

void func_801059FC(int arg0, int arg1, int arg2)
{
    int temp_v0;
    int i;
    int var_s3;

    if (arg2 < 0) {
        arg2 = 0;
    }

    if (arg2 >= 0x41) {
        arg2 = 0x40;
    }

    for (i = 0; i < 3; ++i) {
        var_s3 = 0x7FF2;
        temp_v0 = D_801098A4 == i;
        if (temp_v0 != 0) {
            var_s3 = 0x7FF8;
        }
        func_80105F6C(arg0 - 0x54, arg1 + i * 0x14 + 2, arg2,
            D_8005FEA0.unk28[0][vs_main_stateFlags.unkC4 * 3 + i] & 0xFFFFFF, temp_v0);
        func_80105DD8((arg0 - D_801091D8[75 + i][2]) - 0x58, arg1 + i * 0x14, i + 0x4B,
            arg2, var_s3);
    }
}

void func_80105B30(int arg0, int arg1, int arg2, int arg3)
{
    int temp_t1;
    int var_s3;

    if (arg3 < 0) {
        arg3 = 0;
    }
    if (arg3 >= 0x41) {
        arg3 = 0x40;
    }
    temp_t1 = D_801098A4 == arg2;
    var_s3 = 0x7FF2;
    if (temp_t1 != 0) {
        var_s3 = 0x7FF8;
    }

    func_80105F6C(arg0 - 0x54, arg1 + (arg2 * 0x14) + 2, arg3,
        D_8005FEA0.unk28[vs_main_stateFlags.unkC4][arg2] & 0xFFFFFF, temp_t1);
    func_80105DD8((arg0 - D_801091D8[arg2 + 0x4B][2]) - 0x58, arg1 + (arg2 * 0x14),
        arg2 + 0x4B, arg3, var_s3);
}

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80105C34);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80105DD8);

INCLUDE_RODATA("build/src/MENU/MENUF.PRG/nonmatchings/3B8", D_80102B5C);

INCLUDE_RODATA("build/src/MENU/MENUF.PRG/nonmatchings/3B8", D_80102B64);

void func_80105F6C(int arg0, int arg1, int arg2, int arg3, int arg4)
{
    char sp18[16];
    int i;
    int s2;

    if (arg3 == 0x800000) {
        sprintf(sp18, "------");
    } else {
        sprintf(
            sp18, "%02d%02d%02d", (arg3 >> 0x10) & 0xFF, (arg3 >> 8) & 0xFF, arg3 & 0xFF);
    }

    s2 = 0x7FF2;
    if (arg4 != 0) {
        s2 = 0x7FF8;
    }

    for (i = 0; i < 6; ++i) {
        if (sp18[i] == 0x2D) {
            func_80105DD8(arg0, arg1, 0x53, arg2, s2);
            arg0 += 0xC;
        } else {
            func_80105DD8(arg0, arg1 - 3, sp18[i] - 0x30, arg2, s2);
            arg0 += 0xC;
        }

        if (i == 1) {
            func_80105DD8(arg0, arg1 - 2, 0x49, arg2, s2);
            arg0 += 6;
        } else if (i == 3) {
            func_80105DD8(arg0, arg1 - 2, 0x4A, arg2, s2);
            arg0 += 6;
        }
    }
}

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_801060A8);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_801064D4);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_8010664C);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80106A80);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80107140);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80107698);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80107A8C);

int func_80107D4C(void)
{
    if (vs_main_stateFlags.unkA3 != 0) {
        vs_main_stateFlags.unkA2 = 0x3B;
        vs_main_stateFlags.unkA1 = 0x3B;
        vs_main_stateFlags.unkA3 = 0;
        vs_main_stateFlags.unkA0 = 0x63;
    }
    return func_80107A8C();
}

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80107D98);

int func_80107FC0(void)
{
    if (D_801098A0 != 0) {
        return 0;
    }
    if (D_8010989C == 0) {
        vs_main_playSfxDefault(0x7E, 0x7D);
    }
    if (D_8010989C == 0x1E) {
        vs_main_playSfxDefault(0x7E, 0x7D);
    }

    func_801085D4(0xA0, 0x40, D_8010989C);
    func_8010873C(0x80, 0x74, D_8010989C - 0xF);
    func_80108784(0xC0, 0x90, D_8010989C - 0x1E);
    func_801064D4(0xD6, 0xBB, D_8010989C - 0x1E, D_8010989C);

    if (D_8010989C < 0x7FFF) {
        ++D_8010989C;
    }

    if (vs_main_buttonsPressed.all & 0x20) {
        if (D_8010989C >= 0x4E) {
            func_80045D64(0x7E, 0);
            func_8007E0A8(0x1D, 2, 5);
            return 1;
        }
        func_80045D64(0x7E, 0);
        D_8010989C = 0x4E;
    }

    return 0;
}

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_801080E4);

void func_80104A50(int);
extern int D_8010988C;

int func_801083AC(void)
{
    int var_v0;

    var_v0 = vs_math_sine(D_8010988C);
    if (var_v0 < 0) {
        var_v0 += 0x1FF;
    }
    func_80104A50((var_v0 >> 9) + 8);
    D_8010988C = (D_8010988C + 0x40) & 0xFFF;
    if (D_801098A0 != 0) {
        return 0;
    }
    if (D_8010989C == 0) {
        vs_main_playSfxDefault(0x7E, 0x7A);
    }
    if (D_8010989C == 0xF) {
        vs_main_playSfxDefault(0x7E, 0x7A);
    }
    func_801084F4(0x40, D_8010989C);
    func_80108564(0x64, D_8010989C - 0xF);
    func_801064D4(0xD6, 0xBB, D_8010989C - 0xF, D_8010989C);
    if (D_8010989C < 0x7FFF) {
        ++D_8010989C;
    }
    if (vs_main_buttonsPressed.all & PADRright) {
        if (D_8010989C >= 0x3F) {
            func_80045D64(0x7E, 0);
            func_8007E0A8(0x1D, 1, 5);
            func_80108E40();
            return 1;
        }
        D_8010989C = 0x3F;
        func_80045D64(0x7E, 0);
    }
    return 0;
}

void func_801084F4(int arg0, int arg1)
{
    if (arg1 < 0) {
        arg1 = 0;
    }
    if (arg1 > 0x40) {
        arg1 = 0x40;
    }
    if (arg1 > 0) {
        func_80105C34(0, arg0, 0x7B, arg1);
        func_80105C34(0xA0, arg0, 0x7C, arg1);
    }
}

void func_80108564(int arg0, int arg1)
{
    if (arg1 < 0) {
        arg1 = 0;
    }
    if (arg1 > 0x40) {
        arg1 = 0x40;
    }
    if (arg1 > 0) {
        func_80105C34(0, arg0, 0x7D, arg1);
        func_80105C34(0xA0, arg0, 0x7E, arg1);
    }
}

void func_801085D4(int arg0, int arg1, int arg2)
{
    if (arg2 < 0) {
        arg2 = 0;
    }
    if (arg2 > 0x40) {
        arg2 = 0x40;
    }
    if (arg2 > 0) {
        D_801097CC[3] = arg2;
        D_801097CC[7] = arg2;
        arg0 -= (D_801091D8[102][2] + D_801091D8[103][2]) >> 1;
        func_80106A80(arg0, arg1, 0x66, D_801097CC);
        func_80106A80(arg0 + D_801091D8[102][2], arg1, 0x67, D_801097CC + 4);
    }
}

void func_80108688(int arg0, int arg1, int arg2)
{
    if (arg2 < 0) {
        arg2 = 0;
    }
    if (arg2 > 0x40) {
        arg2 = 0x40;
    }
    if (arg2 > 0) {
        D_801097D8[3] = arg2;
        D_801097D8[7] = arg2;
        arg0 -= (D_801091D8[105][2] + D_801091D8[106][2]) >> 1;
        func_80106A80(arg0, arg1, 0x69, D_801097D8);
        func_80106A80(arg0 + D_801091D8[105][2], arg1, 0x6A, D_801097D8 + 4);
    }
}

void func_8010873C(int arg0, int arg1, int arg2)
{
    if (arg2 > 0x40) {
        arg2 = 0x40;
    }
    if (arg2 > 0) {
        func_80105C34(arg0 - (D_8010951A >> 1), arg1, 0x68, arg2);
    }
}

void func_80108784(int arg0, int arg1, int arg2)
{
    if (arg2 > 0x40) {
        arg2 = 0x40;
    }
    if (arg2 > 0) {
        int new_var = (D_801099F4 % 60) << 0x10;
        func_80105F6C(arg0, arg1, arg2, ((D_801099F4 / 60) << 0x10) | (new_var >> 8), 0);
    }
}

void func_8010880C(int arg0, int arg1, int arg2, int arg3)
{
    if (arg2 < 0) {
        arg2 = 0;
    }
    if (arg2 > 0x40) {
        arg2 = 0x40;
    }
    if (arg2 > 0) {
        D_801097E4[3] = arg2;
        func_80106A80(
            arg0 - (D_801091D8[arg3 + 0x6B][2] >> 1), arg1, arg3 + 0x6B, D_801097E4);
    }
}

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_8010887C);

void func_80108A0C(void)
{
    int var_a2;
    int i;
    int a1;

    for (i = 0, var_a2 = 0, a1 = 1; i < 16; ++i) {
        if (D_8005FEA0.unk0 & (a1 << i)) {
            ++var_a2;
        }
    }

    for (i = 0; i < 16; ++i) {
        if (var_a2 >= D_801097EC[i]) {
            if (D_80109884 >= D_8010980C[i]) {
                D_8010987C = i;
                return;
            }
        }
    }
}

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80108AB0);

void func_80108E38(void) { }

void func_80108E40(void) { }

void func_80108E48(void)
{
    int new_var = D_8005FEA0.unk108 + 0x186A0;
    D_8005FEA0.unk108 = new_var - (D_8005FEA0.unk112 * 0x64);
    if (D_8005FEA0.unk108 > 0x3B9AC9FF) {
        D_8005FEA0.unk108 = 0x3B9AC9FF;
    }
    D_8005FEA0.unk112 = 0;
}

void func_80108EA0(void) { }

int func_80108EA8(void) { return vs_battle_characterState->unk3C->unk24; }

int func_80108EC8(void) { return vs_battle_characterState->unk3C->unk28; }

int func_80108EE8(void) { return vs_battle_characterState->unk3C->unk2C; }

void func_80108F08(int amount)
{
    vs_battle_characterState->unk3C->unk24 += amount;
    if (vs_battle_characterState->unk3C->unk24 > 999) {
        vs_battle_characterState->unk3C->unk24 = 999;
    }
    vs_battle_characterState->unk3C->unk22 += amount;
    if (vs_battle_characterState->unk3C->unk22 > 999) {
        vs_battle_characterState->unk3C->unk22 = 999;
    }
}

void func_80108F98(int amount)
{
    vs_battle_characterState->unk3C->unk28 += amount;
    if (vs_battle_characterState->unk3C->unk28 > 999) {
        vs_battle_characterState->unk3C->unk28 = 999;
    }
    vs_battle_characterState->unk3C->unk26 += amount;
    if (vs_battle_characterState->unk3C->unk26 > 999) {
        vs_battle_characterState->unk3C->unk26 = 999;
    }
}

void func_80109028(int amount)
{
    vs_battle_characterState->unk3C->unk2C += amount;
    if (vs_battle_characterState->unk3C->unk2C > 999) {
        vs_battle_characterState->unk3C->unk2C = 999;
    }
    vs_battle_characterState->unk3C->unk2A += amount;
    if (vs_battle_characterState->unk3C->unk2A > 999) {
        vs_battle_characterState->unk3C->unk2A = 999;
    }
}

void _raiseMaxHP(int amount)
{
    vs_battle_characterState->unk3C->maxHP += amount;
    if (vs_battle_characterState->unk3C->maxHP > 999) {
        vs_battle_characterState->unk3C->maxHP = 999;
    }
    vs_battle_characterState->unk3C->currentHP += amount;
    if (vs_battle_characterState->unk3C->currentHP > 999) {
        vs_battle_characterState->unk3C->currentHP = 999;
    }
}

void _raiseMaxMP(int amount)
{
    vs_battle_characterState->unk3C->maxMP += amount;
    if (vs_battle_characterState->unk3C->maxMP > 999) {
        vs_battle_characterState->unk3C->maxMP = 999;
    }
    vs_battle_characterState->unk3C->currentMP += amount;
    if (vs_battle_characterState->unk3C->currentMP > 999) {
        vs_battle_characterState->unk3C->currentMP = 999;
    }
}
