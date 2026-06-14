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

typedef struct {
    u_int unk0 : 8;
    u_int unk1 : 8;
    u_int unk2 : 8;
    u_int unk3 : 8;
} func_800C1564_flags;

typedef struct {
    u_char unk0;
    u_char unk1;
    short unk2;
    union {
        func_800C1564_flags flags;
        u_char values[4];
    } unk4;
    u_short unk8[4];
    u_char unk10;
    u_char unk11;
    u_char unk12;
    u_char unk13;
} func_800C1564_t;

typedef struct {
    SVECTOR unk0;
    SVECTOR unk8;
    short unk10[4];
    short unk18[4];
} func_800C0FA8_t2;

int func_800C1034(func_800C1564_t* arg0, u_short* arg1);
int func_800C123C(func_800C1564_t* arg0, u_short* arg1, int arg2);
int func_800C1384(func_800C1564_t* arg0, u_short* arg1, int arg2);
void func_800C58F8(int);

extern D_800EB9B8_t* D_800EB9B8;

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/58578", func_800C0D78);

void func_800C0FA8(func_800C1564_t* arg0, func_800C0FA8_t2* arg1, MATRIX* arg2)
{
    int temp_v0;
    int i;
    char* new_var;

    for (i = 0; i < 3; ++i) {
        arg1->unk10[i] = arg0->unk8[i];
        arg1->unk18[i] = 0x8000 / *(new_var = &arg0->unk4.values[i]);
    }

    arg1->unk0.vx = arg0->unk4.values[3] * 0x10;
    arg1->unk0.vy = -arg0->unk2;
    arg1->unk0.vz = 0;

    RotMatrix_gte(&arg1->unk0, arg2);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/58578", func_800C1034);

int func_800C110C(func_800C1564_t* arg0, u_short* arg1, int arg2)
{
    func_800C0FA8_t2 work;
    MATRIX matrix;
    int sum;
    int term;
    int i;

    func_800C0FA8(arg0, &work, &matrix);

    {
        short* ptr;
        void* base;
        int offset;

        i = 0;
        ptr = (short*)&work;
        base = &work;
        offset = 0x10;

        for (; i < 3; ++i) {
            *ptr = *arg1++ - *(u_short*)(base + offset);
            offset += 2;
            ++ptr;
        }
    }

    sum = 0;

    ApplyMatrixSV(&matrix, &work.unk0, &work.unk8);

    if (arg2 != 0) {
        work.unk8.vy -= arg0->unk4.flags.unk1 << 4;
    }

    if (!((u_short)-work.unk8.vy > (arg0->unk4.flags.unk1 << 5))) {
        char* base;
        int offset2;
        int offset;

        i = 0;
        base = (char*)&work;
        offset2 = 0x18;
        offset = 8;

        for (; i < 3; i += 2) {
            term = (*(short*)(base + offset) * *(short*)(base + offset2)) >> 12;
            sum += term * term;
            offset2 += 4;
            offset += 4;
        }

        sum = (sum >> 16) < 1u;
    }
    return sum;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/58578", func_800C123C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/58578", func_800C1384);

int func_800C1564(func_800C1564_t* arg0, u_short* arg1)
{
    func_800C1564_flags saved_unk4 = arg0->unk4.flags;
    int ret = 0;

    switch (arg0->unk0) {
    case 1:
        ret = func_800C1034(arg0, arg1);
        break;
    case 2:
        arg0->unk4.flags.unk1 <<= 1;
        ret = func_800C110C(arg0, arg1, 1);
        break;
    case 3:
        ret = func_800C110C(arg0, arg1, 0);
        break;
    case 4:
        ret = func_800C123C(arg0, arg1, 0);
        break;
    case 5:
        arg0->unk4.flags.unk3 = saved_unk4.unk3 + 0x80;
        ret = func_800C123C(arg0, arg1, 1);
        break;
    case 6:
        ret = func_800C1384(arg0, arg1, 1);
        break;
    case 7:
        ret = func_800C1384(arg0, arg1, 0);
        break;
    }

    arg0->unk4.flags = saved_unk4;
    return ret;
}

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
