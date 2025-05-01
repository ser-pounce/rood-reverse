#include "common.h"
#include "../../SLUS_010.40/31724.h"

typedef struct {
    u_char unk0;
    u_char unk1;
    short unk2;
    short unk4;
    short unk6;
    int unk8;
} D_800EB9B4_t;

void func_8007DFF0(int, int, int);
void func_8007E0A8(int, int, int);

extern D_800EB9B4_t* D_800EB9B4;
extern int* D_1F800000[];

void func_800F9800(int arg0)
{
    D_800EB9B4->unk2 = arg0;
    if (D_800EB9B4->unk1 == 0) {
        if (arg0 != 0) {
            D_800EB9B4->unk1 = 1U;
            func_8007DFF0(0x1B, 5, 6);
        }
    } else if (arg0 == 0) {
        D_800EB9B4->unk1 = 0U;
        func_8007E0A8(0x1B, 5, 6);
    }
}

INCLUDE_ASM("build/src/GIM/SCREFF2.PRG/nonmatchings/0", func_800F986C);

void func_800F9BC0(short arg0, short arg1)
{
    D_800EB9B4->unk4 = arg0;
    D_800EB9B4->unk6 = arg1;
}

INCLUDE_ASM("build/src/GIM/SCREFF2.PRG/nonmatchings/0", func_800F9BD8);

void func_800F9DE8(int arg0) { D_800EB9B4->unk8 = arg0; }

int func_800F9DF8(int arg0, int arg1)
{
    int var_s1;

    var_s1 = 8 - ((arg0 + 8) & 0xF);
    if (var_s1 < 0) {
        var_s1 = -var_s1;
    }
    var_s1 += 0x40;
    return ((((((vs_math_cosine(arg0 << 6) * arg1 * 0xB) >> 0xF) * var_s1) >> 6) + 0xA0)
               & 0xFFFF)
        | ((((((vs_math_sine(arg0 << 6) * arg1) >> 0xC) * var_s1) >> 6) + 0x70) << 0x10);
}

int* func_800F9EBC(int arg0, int arg1, int* arg2, int* arg3)
{
    int var_s2;

    for (var_s2 = arg1; var_s2 < arg1 + 4; ++var_s2) {
        arg2[0] = (*arg3 & 0xFFFFFF) | 0x06000000;
        arg2[1] = 0x32FFFFFF;
        arg2[2] = arg0;
        arg2[3] = 0xA0A0A0;
        arg2[4] = func_800F9DF8(var_s2 + 1, 0x80);
        arg2[5] = 0xA0A0A0;
        arg2[6] = func_800F9DF8(var_s2, 0x80);
        *arg3 = (u_int)((long)arg2 << 8) >> 8;
        arg2 += 7;
    }
    return arg2;
}

void func_800F9FB8()
{
    int* var_s2;
    int i;
    int* temp_s4;

    temp_s4 = D_1F800000[2];
    var_s2 = func_800F9EBC(0xE00140, 6, D_1F800000[0], temp_s4);
    var_s2 = func_800F9EBC(0xE00000, 0x16, var_s2, temp_s4);
    var_s2 = func_800F9EBC(0, 0x26, var_s2, temp_s4);
    var_s2 = func_800F9EBC(0x140, 0x36, var_s2, temp_s4);

    for (i = 0; i < 0x40; ++i) {
        var_s2[0] = (*temp_s4 & 0xFFFFFF) | 0x09000000;
        var_s2[1] = 0xE1000220;
        var_s2[2] = 0x3AA0A0A0;
        var_s2[3] = func_800F9DF8(i + 1, 0x80);
        var_s2[4] = 0xA0A0A0;
        var_s2[5] = func_800F9DF8(i, 0x80);
        var_s2[6] = 0;
        var_s2[7] = func_800F9DF8(i + 1, 0x60);
        var_s2[8] = 0;
        var_s2[9] = func_800F9DF8(i, 0x60);
        *temp_s4 = (u_int)((long)var_s2 << 8) >> 8;
        var_s2 += 10;
    }
    D_1F800000[0] = var_s2;
}
