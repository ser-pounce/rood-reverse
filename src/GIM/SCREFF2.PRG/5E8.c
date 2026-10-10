#include "common.h"
#include "0.h"
#include "src/SLUS_010.40/31724.h"
#include "src/BATTLE/BATTLE.PRG/146C.h"
#include "src/BATTLE/BATTLE.PRG/573B8.h"
#include <libgte.h>

void func_800F9DE8(int arg0) { D_800EB9B4->unk8 = arg0; }

static int func_800F9DF8(int arg0, int arg1)
{
    int var_s1;

    var_s1 = 8 - ((arg0 + 8) & 0xF);
    if (var_s1 < 0) {
        var_s1 = -var_s1;
    }
    var_s1 += 0x40;
    return ((((((rcos(arg0 << 6) * arg1 * 0xB) >> 0xF) * var_s1) >> 6) + 0xA0) & 0xFFFF)
         | ((((((rsin(arg0 << 6) * arg1) >> 0xC) * var_s1) >> 6) + 0x70) << 0x10);
}

static int* func_800F9EBC(int arg0, int arg1, int* arg2, void** arg3)
{
    int var_s2;

    for (var_s2 = arg1; var_s2 < arg1 + 4; ++var_s2) {
        arg2[0] = ((u_long)*arg3 & 0xFFFFFF) | 0x06000000;
        arg2[1] = 0x32FFFFFF;
        arg2[2] = arg0;
        arg2[3] = 0xA0A0A0;
        arg2[4] = func_800F9DF8(var_s2 + 1, 0x80);
        arg2[5] = 0xA0A0A0;
        arg2[6] = func_800F9DF8(var_s2, 0x80);
        *arg3 = (void*)(((u_long)arg2 << 8) >> 8);
        arg2 += 7;
    }
    return arg2;
}

void func_800F9FB8(void)
{
    int* var_s2;
    int i;
    void** temp_s4;

    temp_s4 = vs_scratch.unk8;
    var_s2 = func_800F9EBC(0xE00140, 6, vs_scratch.unk0, temp_s4);
    var_s2 = func_800F9EBC(0xE00000, 0x16, var_s2, temp_s4);
    var_s2 = func_800F9EBC(0, 0x26, var_s2, temp_s4);
    var_s2 = func_800F9EBC(0x140, 0x36, var_s2, temp_s4);

    for (i = 0; i < 0x40; ++i) {
        var_s2[0] = ((u_long)*temp_s4 & 0xFFFFFF) | 0x09000000;
        var_s2[1] = 0xE1000220;
        var_s2[2] = 0x3AA0A0A0;
        var_s2[3] = func_800F9DF8(i + 1, 0x80);
        var_s2[4] = 0xA0A0A0;
        var_s2[5] = func_800F9DF8(i, 0x80);
        var_s2[6] = 0;
        var_s2[7] = func_800F9DF8(i + 1, 0x60);
        var_s2[8] = 0;
        var_s2[9] = func_800F9DF8(i, 0x60);
        *temp_s4 = (void*)(((u_long)var_s2 << 8) >> 8);
        var_s2 += 10;
    }
    vs_scratch.unk0 = var_s2;
}
