#include "common.h"
#include "src/BATTLE/BATTLE.PRG/5BF94.h"
#include "src/BATTLE/BATTLE.PRG/6E644.h"

INCLUDE_ASM("build/src/EFFECT/PLG045.BIN/nonmatchings/110", func_800F9910);

int func_800CFB80(int, int);

typedef struct {
    u_char unk0[0x24];
    u_int unk24;
    u_char unk28[0x114];
    SVECTOR unk13C;
    SVECTOR unk144;
} func_800FA098_arg1;

typedef struct {
    u_char unk0;
    u_char unk1;
    short unk2;
    SVECTOR* unk4;
    int unk8;
    int unkC;
} func_800FA098_arg3;

typedef struct {
    u_char unk0;
    u_char unk1;
    u_char unk2;
    u_char unk3;
    void* unk4;
    int unk8;
    int unkC;
} func_800FB320_t;

typedef struct {
    u_char unk0;
    u_char unk1;
    short unk2;
    void* unk4;
    int unk8;
    int unkC;
} func_800D4910_unk8;

void func_800F9910(func_800FA098_arg0*, func_800FA098_arg1*, D_800F53B8_t*, void*);
void func_800FA2B0(func_800FA098_arg0*, func_800FA098_arg1*, D_800F53B8_t*, void*);
void func_800FA760(func_800FA098_arg0*, func_800FA098_arg1*, D_800F53B8_t*, void*);

void func_800FA098(func_800FA098_arg0* arg0, func_800FA098_arg1* arg1, D_800F53B8_t* arg2,
    func_800FA098_arg3* arg3)
{
    int i;

    vs_battle_lerpSvector(
        arg0->unk7C, func_800D118C(arg0->unkF, arg3->unkC), &arg1->unk13C);
    vs_battle_lerpSvector(
        arg0->unk88, func_800D118C(arg0->unk10, arg3->unkC), &arg1->unk144);

    switch (arg1->unk24 & 0x1C0) {
    case 0xC0:
        arg1->unk13C.vx += arg2->unk1C[arg0->unkC9].unk4C.vx;
        arg1->unk13C.vy += arg2->unk1C[arg0->unkC9].unk4C.vy;
        arg1->unk13C.vz += arg2->unk1C[arg0->unkC9].unk4C.vz;
        break;
    case 0x80:
        arg1->unk13C.vx += D_800F5230.unkE0;
        arg1->unk13C.vy += D_800F5230.unkE2;
        arg1->unk13C.vz += D_800F5230.unkE4;
        break;
    case 0:
        break;
    }

    for (i = 0; i < arg3->unk2; ++i) {
        SVECTOR* temp_s0 = &arg3->unk4[i * 4 + 3];
        temp_s0->vx = arg1->unk13C.vx + func_800CFB80(arg1->unk144.vx, -arg1->unk144.vx);
        temp_s0->vy = arg1->unk13C.vy + func_800CFB80(arg1->unk144.vy, -arg1->unk144.vy);
        temp_s0->vz = arg1->unk13C.vz + func_800CFB80(arg1->unk144.vz, -arg1->unk144.vz);
    }
}

INCLUDE_ASM("build/src/EFFECT/PLG045.BIN/nonmatchings/110", func_800FA2B0);

INCLUDE_ASM("build/src/EFFECT/PLG045.BIN/nonmatchings/110", func_800FA760);

int func_800FB320(func_800D4910_t* arg0, u_int arg1, int arg2)
{
    func_800FA098_arg0* temp_s2;
    int var_a0;
    short var_v0;
    func_800FA098_arg1* a2 = (func_800FA098_arg1*)0x1F8001D0;
    func_800D4910_unk8* temp_s1 = arg0->unk8;
    D_800F53B8_t* temp_s0 = D_800F53BC;
    int s3 = 1;

    switch (arg1) {
    case 1:
        temp_s1 = vs_main_allocHeapR(0x30);
        arg0->unk8 = temp_s1;
        temp_s1->unk1 = arg2 >> 8;
        temp_s1->unk0 = arg2;
        temp_s1->unkC = 0;
        temp_s1->unk8 = 0;
        temp_s2 = (func_800FA098_arg0*)(D_800F569C->unk8 + ((temp_s1->unk1 * 0xCC) + 4));

        var_v0 = temp_s2->unkC2;
        if (temp_s2->unkC2 < temp_s2->unkC0) {
            var_v0 = temp_s2->unkC0;
        }

        var_a0 = var_v0;

        if (var_a0 >= 9) {
            var_a0 = 8;
        }

        temp_s1->unk4 = vs_main_allocHeapR(var_a0 << 5);
        func_800D6CCC((int*)(temp_s1 + 1));
        func_800D6CF0((func_800D6CF_t*)(temp_s1 + 1), temp_s2->unk1, temp_s2->unk0);
        break;

    case 2:
        temp_s2 = (func_800FA098_arg0*)(D_800F569C->unk8 + ((temp_s1->unk1 * 0xCC) + 4));
        a2->unk24 = temp_s2->unk4 & 0x03FFFFFF;
        temp_s1->unk2 = func_800CFE1C((func_800CFE1C_t*)&temp_s2->unkC0,
            func_800D118C(temp_s2->unk14[2], temp_s1->unkC));

        if (temp_s1->unk2 >= 9) {
            temp_s1->unk2 = 8;
        }

        if (temp_s1->unk8 <= 0) {
            func_800F9910(temp_s2, a2, temp_s0, temp_s1);
            func_800FA098(temp_s2, a2, temp_s0, (func_800FA098_arg3*)temp_s1);
            temp_s1->unk8 = temp_s2->unk74;
        }

        temp_s1->unk8 = (temp_s1->unk8 - 1);

        func_800FA2B0(temp_s2, a2, temp_s0, temp_s1);
        func_800FA760(temp_s2, a2, temp_s0, temp_s1);

        ++temp_s1->unkC;

        if (temp_s1->unk0 != 0) {
            --temp_s1->unk0;
            if (!temp_s1->unk0) {
                vs_main_freeHeapR(temp_s1->unk4);
                s3 = 0;
            }
        }
        break;

    case 3:
        temp_s1->unk0 = 1;
        break;

    case 4:
        vs_main_freeHeapR(temp_s1->unk4);
        s3 = 0;
        break;
    }

    return s3;
}
