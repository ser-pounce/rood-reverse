#include "common.h"
#include "src/BATTLE/BATTLE.PRG/5BF94.h"
#include "src/BATTLE/BATTLE.PRG/6E644.h"

INCLUDE_ASM("build/src/EFFECT/PLG045.BIN/nonmatchings/110", func_800F9910);

int func_800CFB80(int, int);

typedef struct {
    int unk0;
    int unk4;
    int unk8;
    u_char unkC;
    u_char unkD;
    u_char unkE;
    u_char unkF;
    u_char unk10;
    u_char unk11;
    u_char unk12;
    u_char unk13;
    u_char unk14[0x68];
    short unk7C[6];
    short unk88[6];
    u_char unk94[0x35];
    u_char unkC9;
} func_800FA098_arg0;

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

void func_800FB320(func_800D4910_t*, int, int);
INCLUDE_ASM("build/src/EFFECT/PLG045.BIN/nonmatchings/110", func_800FB320);
