#include "common.h"
#include "src/SLUS_010.40/32154.h"
#include "src/BATTLE/BATTLE.PRG/5BF94.h"
#include "vs_inline_c.h"
#include <rand.h>
#include <inline_c.h>

INCLUDE_ASM("build/src/EFFECT/PLG049.BIN/nonmatchings/E0", func_800F98E0);

INCLUDE_ASM("build/src/EFFECT/PLG049.BIN/nonmatchings/E0", func_800FA07C);

typedef struct {
    int unk0;
    int unk4;
    u_char unk8;
    u_char unk9;
    u_char unkA;
    u_char unkB;
    u_char unkC;
    u_char unkD;
    u_char unkE;
    u_char unkF;
    u_char unk10;
    u_char unk11;
    u_char unk12;
    u_char unk13;
    u_char unk14[0x20];
    short unk34[8][6];
    short unk94[8][4];
} func_800FA294_arg0;

typedef struct {
    u_char unk0[0x34];
    VECTOR unk34;
    VECTOR unk44;
    u_char unk54[0x10];
    MATRIX unk64;
    u_char unk84[0x44];
    VECTOR unkC8;
    VECTOR unkD8;
    VECTOR unkE8;
    SVECTOR unkF8;
    u_char unk100[0x18];
    int unk118[2];
    int unk120;
    int unk124[2];
    int unk12C[2];
} func_800FA294_arg1;

typedef struct {
    u_char unk0;
    u_char unk1;
    u_char unk2;
    u_char unk3;
    SVECTOR (*unk4)[15];
    int unk8;
} func_800FA294_arg3;

void func_800FA294(func_800FA294_arg0* arg0, func_800FA294_arg1* arg1,
    int arg2 __attribute__((unused)), func_800FA294_arg3* arg3)
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
        for (i = 0; i < arg3->unk2; ++i) {
            SVECTOR* temp_s5 = arg3->unk4[i];
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

INCLUDE_ASM("build/src/EFFECT/PLG049.BIN/nonmatchings/E0", func_800FA76C);

INCLUDE_ASM("build/src/EFFECT/PLG049.BIN/nonmatchings/E0", func_800FA8E4);

INCLUDE_ASM("build/src/EFFECT/PLG049.BIN/nonmatchings/E0", func_800FAA70);

INCLUDE_ASM("build/src/EFFECT/PLG049.BIN/nonmatchings/E0", func_800FB4C0);

INCLUDE_ASM("build/src/EFFECT/PLG049.BIN/nonmatchings/E0", func_800FBA00);

INCLUDE_ASM("build/src/EFFECT/PLG049.BIN/nonmatchings/E0", func_800FC624);

INCLUDE_ASM("build/src/EFFECT/PLG049.BIN/nonmatchings/E0", func_800FD51C);
