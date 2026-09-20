#include "common.h"
#include "src/SLUS_010.40/32154.h"
#include "src/BATTLE/BATTLE.PRG/5BF94.h"
#include "vs_inline_c.h"
#include <inline_c.h>
#include <libgte.h>
#include <rand.h>

typedef struct {
    SVECTOR unk0;
    SVECTOR unk8;
    SVECTOR unk10;
    SVECTOR unk18;
    u_char unk20;
    u_char unk21;
    u_char unk22;
    u_char unk23;
    SVECTOR unk24[2]; // Potentially more
    u_char unk28[0x38];
    int unk6C;
    int unk70;
    int unk74;
} func_800FA76C_t;

typedef struct {
    u_char unk0;
    u_char unk1;
    short unk2;
    func_800FA76C_t* unk4;
    int unk8;
    int unkC;
    func_800D6CF_t unk10;
    func_800FA098_arg3_2* unk2C;
} func_800FA76C_arg3;

INCLUDE_ASM("build/src/EFFECT/PLG049.BIN/nonmatchings/E0", func_800F98E0);

INCLUDE_ASM("build/src/EFFECT/PLG049.BIN/nonmatchings/E0", func_800FA07C);

void func_800FA294(func_800FA098_arg0* arg0, func_800FA098_arg1* arg1,
    int arg2 __attribute__((unused)), func_800FA76C_arg3* arg3)
{
    SVECTOR sp10;
    SVECTOR sp18;
    int temp_s0;
    int i;
    int var_s0;
    int var_s1;
    int var_s3;
    int var_s4;

    do {
        for (i = 0; i < (u_char)arg3->unk2; ++i) {
            SVECTOR* temp_s5 = &arg3->unk4[i].unk0;
            arg1->unk34.vx = temp_s5[3].vx - temp_s5[0].vx;
            arg1->unk34.vy = temp_s5[3].vy - temp_s5[0].vy;
            arg1->unk34.vz = temp_s5[3].vz - temp_s5[0].vz;
            temp_s0 = vs_gte_rsqrt((arg1->unk34.vx * arg1->unk34.vx)
                                   + (arg1->unk34.vy * arg1->unk34.vy)
                                   + (arg1->unk34.vz * arg1->unk34.vz));
            vs_battle_lerp2DVector(
                arg0->unk94[0], func_800D118C(arg0->unk12, arg3->unk8), arg1->unk124);
            vs_battle_lerp2DVector(
                arg0->unk94[1], func_800D118C(arg0->unk13, arg3->unk8), arg1->unk12C);
            vs_battle_lerp2DVector(
                arg0->unk94[2], func_800D118C(arg0->unkC, arg3->unk8), arg1->unk118);
            vs_battle_lerpVector(
                arg0->unk34[1], func_800D118C(arg0->unkB, arg3->unk8), &arg1->unkC8);
            vs_battle_lerpVector(
                arg0->unk34[0], func_800D118C(arg0->unkA, arg3->unk8), &arg1->unkE8);
            vs_battle_lerpSvector(
                arg0->unk34[2], func_800D118C(arg0->unkD, arg3->unk8), &arg1->unkF8);

            if (arg1->unkF8.vx != 0) {
                int var_v0_2 =
                    (arg1->unk118[0] + (rand() % arg1->unkF8.vx)) - (arg1->unkF8.vx / 2);
                sp10.vz = (temp_s0 * var_v0_2) / 256;
            } else {
                sp10.vz = (temp_s0 * arg1->unk118[0]) / 256;
            }

            if (arg1->unkF8.vy != 0) {
                int var_v0_3 =
                    (arg1->unk118[1] + (rand() % arg1->unkF8.vy)) - (arg1->unkF8.vy / 2);
                sp18.vz = temp_s0 + ((temp_s0 * var_v0_3) / 256);
            } else {
                sp18.vz = temp_s0 + ((temp_s0 * arg1->unk118[1]) / 256);
            }

            var_s3 = arg1->unk124[0];

            var_s0 = arg1->unk124[1] != 0;
            if (var_s0) {
                var_s3 += rand() % arg1->unk124[1];
            }

            var_s4 = arg1->unk12C[0];

            if (arg1->unk12C[1] != 0) {
                var_s4 += rand() % arg1->unk12C[1];
            }

            var_s0 = arg1->unkE8.vx;

            if (arg1->unkC8.vx != 0) {
                var_s0 += (rand() % (arg1->unkC8.vx * 2)) - arg1->unkC8.vx;
            }

            var_s1 = arg1->unkE8.vy;

            if (arg1->unkC8.vy != 0) {
                if (&arg1->unk34) {
                    var_s1 += (rand() % (arg1->unkC8.vy * 2)) - arg1->unkC8.vy;
                } else {
                    var_s1 += (rand() % (arg1->unkC8.vy * 2)) - arg1->unkC8.vy;
                }
            }

            sp10.vx = (rcos(var_s0) * var_s3) >> 0xC;
            sp10.vy = (rsin(var_s0) * var_s3) >> 0xC;
            sp18.vx = (rcos(var_s1) * var_s4) >> 0xC;
            sp18.vy = (rsin(var_s1) * var_s4) >> 0xC;

            vs_battle_svecToVec(temp_s5, &arg1->unk34);
            vs_battle_svecToVec(temp_s5 + 3, &arg1->unk44);
            vs_battle_lookAt(&arg1->unk34, &arg1->unk44, &arg1->unk64);
            gte_SetRotMatrix(&arg1->unk64);
            gte_SetTransVector2(&arg1->unk34);
            gte_ldv0(&sp10);
            gte_rtv0tr2();
            gte_stlvnl(&arg1->unk34);
            vs_battle_vecToSvec(&arg1->unk34, temp_s5 + 1);
            gte_ldv0(&sp18);
            gte_rtv0tr2();
            gte_stlvnl(&arg1->unk44);
            vs_battle_vecToSvec(&arg1->unk44, temp_s5 + 2);
        }
    } while (0);
}

void func_800FA76C(func_800FA098_arg0* arg0, func_800FA098_arg1* arg1, D_800F53B8_t* arg2,
    func_800FA76C_arg3* arg3)
{
    int temp_s3;
    int i;

    vs_battle_lerp2DVector(arg0->unk94[4], 0, &arg1->unk134);
    temp_s3 = func_800CFE1C(&arg0->unk30, 0) << 0xC;

    for (i = 0; i < (u_char)arg3->unk2; ++i) {
        int var_v1 = func_800CFB80(arg1->unk134, arg1->unk138);
        if (var_v1 == 0) {
            var_v1 = 1;
        }
        arg3->unk4[i].unk20 = var_v1;
        arg3->unk4[i].unk21 = 1;
        arg3->unk4[i].unk22 = 8;
        arg3->unk4[i].unk23 = 0;
        arg3->unk4[i].unk24[0] = arg3->unk4[i].unk0;
        arg3->unk4[i].unk6C = 0;
        arg3->unk4[i].unk70 = temp_s3;
        arg3->unk4[i].unk74 =
            ((0x06000000 / (var_v1 * var_v1)) - ((temp_s3 * 2) / var_v1));
    }
}

void func_800FA8E4(func_800FA098_arg0* arg0, func_800FA098_arg1* arg1, D_800F53B8_t* arg2,
    func_800FA76C_arg3* arg3)
{
    int i;

    for (i = 0; i < (u_char)arg3->unk2; ++i) {

        func_800FA76C_t* temp_s0 = &arg3->unk4[i];
        int temp_a1 = temp_s0->unk22;

        if (temp_a1 != 0) {
            if (arg3->unk8 >= temp_s0->unk20) {
                temp_s0->unk22 = temp_a1 - 1;
                if (temp_s0->unk22 < temp_s0->unk20) {
                    --temp_s0->unk21;
                }
            } else {

                int temp_a0_2 = temp_s0->unk20 - arg3->unk8;
                int temp_a2 = temp_s0->unk70;

                temp_a2 += ((0x06000000 - (temp_s0->unk6C * 2)) / (temp_a0_2 * temp_a0_2))
                         - ((temp_a2 * 2) / temp_a0_2);
                temp_s0->unk70 = temp_a2;
                temp_s0->unk6C += temp_a2;
                temp_s0->unk23 = (temp_s0->unk23 + 1) % 9;

                func_800D1390(&temp_s0->unk0, &temp_s0->unk8, &temp_s0->unk10, &temp_s0->unk18,
                    (temp_s0->unk6C >> 0xC) - ONE, &temp_s0->unk24[temp_s0->unk23]);

                if (temp_s0->unk21 < 9) {
                    ++temp_s0->unk21;
                }
            }
        }
    }
}

INCLUDE_ASM("build/src/EFFECT/PLG049.BIN/nonmatchings/E0", func_800FAA70);

INCLUDE_ASM("build/src/EFFECT/PLG049.BIN/nonmatchings/E0", func_800FB4C0);

INCLUDE_ASM("build/src/EFFECT/PLG049.BIN/nonmatchings/E0", func_800FBA00);

INCLUDE_ASM("build/src/EFFECT/PLG049.BIN/nonmatchings/E0", func_800FC624);

INCLUDE_ASM("build/src/EFFECT/PLG049.BIN/nonmatchings/E0", func_800FD51C);
