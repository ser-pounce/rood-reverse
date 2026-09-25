#include "common.h"
#include "src/BATTLE/BATTLE.PRG/146C.h"
#include "src/BATTLE/BATTLE.PRG/5BF94.h"
#include "vs_inline_c.h"
#include <inline_c.h>

typedef struct {
    u_char unk0[0x88];
    VECTOR unk88;
    VECTOR unk98;
    MATRIX unkA8;
} func_800FD9A4_t;

typedef struct {
    SVECTOR splinePoints[4];
    u_char stepCount;
    u_char trailCount;
    u_char unk22;
    u_char currentTrail;
    SVECTOR trails[5];
    int splineProgress;
    int speed;
    int unk54;
} func_800FA76C_t;

typedef struct {
    u_char unk0;
    u_char unk1;
    u_char unk2;
    u_char unk3;
    func_800FA76C_t* unk4;
    int unk8;
    func_800D6CF_t unkC;
    int unk1C;
    u_char unk2C[8];
} func_800FA76C_arg3;

void func_800FE3D0(func_800FA098_arg0*, func_800FA098_arg1*, D_800F53B8_t*, func_800FA76C_arg3*);
void func_800FEB6C(func_800FA098_arg0*, func_800FA098_arg1*, D_800F53B8_t*, func_800FA76C_arg3*);
void func_800FED84(func_800FA098_arg0*, func_800FA098_arg1*, D_800F53B8_t*, func_800FA76C_arg3*);
void func_800FF248(func_800FA098_arg0*, func_800FA098_arg1*, D_800F53B8_t*, func_800FA76C_arg3*);
void func_800FF3C0(func_800FA098_arg0*, func_800FA098_arg1*, D_800F53B8_t*, func_800FA76C_arg3*);
void func_800FF54C(func_800FA098_arg0*, func_800FA098_arg1*, D_800F53B8_t*, func_800FA76C_arg3*);

INCLUDE_ASM("build/src/EFFECT/PLG128.BIN/nonmatchings/F8", func_800F98F8);

INCLUDE_ASM("build/src/EFFECT/PLG128.BIN/nonmatchings/F8", func_800FA490);

INCLUDE_ASM("build/src/EFFECT/PLG128.BIN/nonmatchings/F8", func_800FB400);

INCLUDE_ASM("build/src/EFFECT/PLG128.BIN/nonmatchings/F8", func_800FC2BC);

INCLUDE_ASM("build/src/EFFECT/PLG128.BIN/nonmatchings/F8", func_800FCE0C);

void func_800FD9A4(func_800FD9A4_t* arg0, func_800FA098_arg1* arg1)
{
    vs_battle_lookAt(&arg0->unk98, &arg0->unk88, &arg0->unkA8);
    arg0->unkA8.t[0] = arg1->unk0.vx;
    arg0->unkA8.t[1] = arg1->unk0.vy;
    arg0->unkA8.t[2] = arg1->unk0.vz;
}

INCLUDE_ASM("build/src/EFFECT/PLG128.BIN/nonmatchings/F8", func_800FDA04);

INCLUDE_ASM("build/src/EFFECT/PLG128.BIN/nonmatchings/F8", func_800FDC80);

INCLUDE_ASM("build/src/EFFECT/PLG128.BIN/nonmatchings/F8", func_800FDE78);

INCLUDE_ASM("build/src/EFFECT/PLG128.BIN/nonmatchings/F8", func_800FDEC4);

INCLUDE_ASM("build/src/EFFECT/PLG128.BIN/nonmatchings/F8", func_800FE3D0);

INCLUDE_ASM("build/src/EFFECT/PLG128.BIN/nonmatchings/F8", func_800FEB6C);

INCLUDE_ASM("build/src/EFFECT/PLG128.BIN/nonmatchings/F8", func_800FED84);

INCLUDE_ASM("build/src/EFFECT/PLG128.BIN/nonmatchings/F8", func_800FF248);

INCLUDE_ASM("build/src/EFFECT/PLG128.BIN/nonmatchings/F8", func_800FF3C0);

INCLUDE_ASM("build/src/EFFECT/PLG128.BIN/nonmatchings/F8", func_800FF54C);

int func_800FFFA8(func_800D4910_t* arg0, u_int arg1, int arg2)
{
    func_800FB4C0_t sp18;
    func_800FA098_arg0* temp_s3;
    int i;
    int j;
    func_800FA76C_arg3* temp_v0;

    func_800FA098_arg1* s4 = (func_800FA098_arg1*)0x1F8001D0;
    func_800FA76C_arg3* temp_s0 = arg0->unk8;
    D_800F53B8_t* temp_s5 = D_800F53BC;
    int var_s6 = 1;

    switch (arg1) {
    case 1:
        temp_v0 = vs_main_allocHeapR(sizeof *temp_v0);
        arg0->unk8 = temp_v0;
        temp_v0->unk1 = arg2 >> 8;
        temp_v0->unk0 = arg2;
        temp_v0->unk8 = 0;
        temp_s3 = &D_800F569C->block5Data->unk4[temp_v0->unk1];
        i = temp_s3->unkC0[0];

        if (i > 16) {
            i = 16;
        }

        temp_v0->unk4 = vs_main_allocHeapR(i * sizeof *temp_v0->unk4);
        temp_v0->unk2 = i;
        temp_v0->unk3 = 0;

        if (temp_s3->unk4_26 != 0) {

            i = D_800F569C->block4Data->subBlockSizes[temp_s3->unk4_26];

            if (i >= 2) {
                --i;
            }

            for (j = 0; j < 5; ++j) {
                temp_v0->unk2C[j] =
                    D_800F569C->block4SubBlocks[temp_s3->unk4_26][(j * i) / 4];
            }

        } else {
            for (j = 0; j < 5; ++j) {
                temp_v0->unk2C[j] = 0x80;
            }
        }

        func_800D6CCC((int*)&temp_v0->unkC);
        func_800D6CF0(&temp_v0->unkC, temp_s3->unk1, temp_s3->unk0);
        break;

    case 2:
        temp_s3 = &D_800F569C->block5Data->unk4[temp_s0->unk1];
        s4->unk24 = (temp_s3->unk4_0);

        if (temp_s0->unk3 == 0) {
            func_800FE3D0(temp_s3, s4, temp_s5, temp_s0);
            func_800FEB6C(temp_s3, s4, temp_s5, temp_s0);
            func_800FED84(temp_s3, s4, temp_s5, temp_s0);
            func_800FF248(temp_s3, s4, temp_s5, temp_s0);
            temp_s0->unk3 = 1U;
        }

        func_800FF3C0(temp_s3, s4, temp_s5, temp_s0);
        func_800FF54C(temp_s3, s4, temp_s5, temp_s0);

        if (temp_s3->unk3 != 0) {
            for (i = 0; i < temp_s0->unk2; ++i) {

                sp18.unk60 = 0;

                if (temp_s3->unk4_0 & 0x20000) {
                    SetRotMatrix(&temp_s5->unk1C[temp_s3->unkC8].unk38);
                    SetTransMatrix(&temp_s5->unk1C[temp_s3->unkC8].unk38);
                    s4->unk2C.vx =
                        temp_s0->unk4[i].trails[temp_s0->unk4[i].currentTrail].vx;
                    s4->unk2C.vy =
                        temp_s0->unk4[i].trails[temp_s0->unk4[i].currentTrail].vy;
                    s4->unk2C.vz =
                        temp_s0->unk4[i].trails[temp_s0->unk4[i].currentTrail].vz;

                    gte_ldv0(&s4->unk2C);
                    gte_rtv0tr2();
                    gte_stlvnl(&s4->unk34);

                    sp18.unkC.vx = s4->unk34.vx * ONE;
                    sp18.unkC.vy = s4->unk34.vy * ONE;
                    sp18.unkC.vz = s4->unk34.vz * ONE;
                } else {
                    sp18.unkC.vx =
                        temp_s0->unk4[i].trails[temp_s0->unk4[i].currentTrail].vx * ONE;
                    sp18.unkC.vy =
                        temp_s0->unk4[i].trails[temp_s0->unk4[i].currentTrail].vy * ONE;
                    sp18.unkC.vz =
                        temp_s0->unk4[i].trails[temp_s0->unk4[i].currentTrail].vz * ONE;
                }

                func_800D2ADC(temp_s5, temp_s3->unk3 - 1, 0, 0, &sp18);
            }
        }

        ++temp_s0->unk8;

        if (temp_s0->unk0 != 0) {
            --temp_s0->unk0;
            if (!temp_s0->unk0) {
                var_s6 = 0;
                vs_main_freeHeapR(temp_s0->unk4);
            }
        }
        break;

    case 3:
        temp_s0->unk0 = 1;
        break;

    case 4:
        var_s6 = 0;
        vs_main_freeHeapR(temp_s0->unk4);
        break;
    }

    return var_s6;
}
