#include "common.h"
#include "146C.h"
#include "58578.h"
#include "../../SLUS_010.40/main.h"
#include <stddef.h>

typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    short unk20;
    short unk22;
    int unk24;
    short unk28;
    short unk2A;
    char unk2C;
    char unk2D;
    char unk2E;
    char unk2F;
    char unk30;
    char unk31;
    char unk32;
    char unk33;
    int unk34;
    int unk38;
    short unk3C;
    short unk3E;
    int unk40[0x254];
    struct {
        char unk0;
        char unk1;
        char unk2;
        char unk3;
        char unk4;
        char unk5;
        char unk6;
        char unk7;
        char unk8;
        char unk9;
        char unkA;
        char unkB;
        char unkC;
        char unkD;
        char unkE;
        char unkF;
        char unk10;
        char unk11;
        char unk12;
        char unk13;
    } unk990[24];
} D_800EB9B8_t;

extern D_800EB9B8_t* D_800EB9B8;

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/58578", func_800C0D78);

typedef struct {
    short unk0;
    short unk2;
    char unk4[4];
    u_short unk8[4];
} func_800C0FA8_t;

typedef struct {
    SVECTOR unk0;
    int unk8;
    int unkC;
    short unk10[4];
    short unk18[4];
} func_800C0FA8_t2;

void func_800C0FA8(func_800C0FA8_t* arg0, func_800C0FA8_t2* arg1, MATRIX* arg2)
{
    int temp_v0;
    int i;
    char* new_var;

    for (i = 0; i < 3; ++i) {
        arg1->unk10[i] = arg0->unk8[i];
        arg1->unk18[i] = 0x8000 / *(new_var = &arg0->unk4[i]);
    }

    arg1->unk0.vx = arg0->unk4[3] * 0x10;
    arg1->unk0.vy = -arg0->unk2;
    arg1->unk0.vz = 0;

    RotMatrix_gte(&arg1->unk0, arg2);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/58578", func_800C1034);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/58578", func_800C110C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/58578", func_800C123C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/58578", func_800C1384);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/58578", func_800C1564);

void func_800C58F8(int); /* extern */

void func_800C1664(int arg0, int arg1, int arg2)
{
    int var_a0;
    int var_v0;

    var_a0 = arg0;
    if (D_800EB9B8 != NULL) {
        if (var_a0 >= 0x19) {
            var_a0 = 0x18;
        }
        D_800EB9B8->unk2C = var_a0;
        D_800EB9B8->unk40[0] = arg1;
        if (D_800EB9B8->unk2D >= var_a0) {
            var_v0 = 0;
            if (var_a0 == 0) {
                var_v0 = 0xFF;
            }
            D_800EB9B8->unk2D = var_v0;
        }
        D_800EB9B8->unk31 = arg2;
        func_800C58F8(0);
    }
}

void func_800C16DC(void)
{
    if (D_800EB9B8 != NULL) {
        D_800EB9B8->unk2C = 0;
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/58578", func_800C16FC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/58578", func_800C1A40);

int func_800C1D84(void)
{
    int i;
    for (i = 0; i < 24; ++i) {
        if (D_800EB9B8->unk990[i].unk0 > 1) {
            return 0;
        }
    }
    return 1;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/58578", func_800C1DC4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/58578", func_800C20B4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/58578", func_800C2254);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/58578", func_800C2368);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/58578", func_800C253C);

void* func_800C282C(void)
{
    _sphericalCamera camera;
    int temp_a0;
    int temp_s2;
    int yaw;
    short* p = (short*)0x1F800350;
    vs_battle_syncCameraAnglesFromPosition(&camera);
    yaw = camera.values.yaw;
    temp_s2 = rcos(yaw);
    temp_a0 = rsin(yaw);
    p[0] = temp_s2;
    p[2] = temp_a0;
    p[8] = -temp_a0;
    p[10] = temp_s2;
    D_800EB9B8->unk22 = yaw;
    return (void*)0x1F800350;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/58578", func_800C28AC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/58578", func_800C2B0C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/58578", func_800C2E24);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/58578", func_800C4650);

int vs_battle_mapStickDeadZone(int arg0)
{
    if (arg0 < 64) {
        return arg0 - 64;
    }
    if (arg0 >= 192) {
        return arg0 - 192;
    }
    return 0;
}

int func_800C4734(void)
{
    if ((D_800EB9B8 == NULL) || (D_800EB9B8->unk2A != 0)) {
        return 0;
    }
    if ((D_800EB9B8->unk3E == 0) || (vs_main_buttonsState & 0x80)) {
        return 1;
    }
    return 2;
}

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/58578", D_80069860);
