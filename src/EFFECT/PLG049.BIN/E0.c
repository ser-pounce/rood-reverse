#include "common.h"
#include "src/SLUS_010.40/32154.h"
#include "src/BATTLE/BATTLE.PRG/5BF94.h"
#include "vs_inline_c.h"
#include <inline_c.h>
#include <libgte.h>
#include <rand.h>

typedef struct {
    SVECTOR splinePoints[4];
    u_char stepCount;
    u_char trailCount;
    u_char unk22;
    u_char currentTrail;
    SVECTOR trails[9];
    int splineProgress;
    int speed;
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

void func_800FA07C(func_800FA098_arg0* arg0, func_800FA098_arg1* arg1, D_800F53B8_t* arg2,
    func_800FA76C_arg3* arg3)
{
    int i;

    vs_battle_lerpSvector(
        arg0->unk7C, func_800D118C(arg0->unkF, arg3->unk8), &arg1->unk13C);
    vs_battle_lerpSvector(
        arg0->unk88, func_800D118C(arg0->unk10, arg3->unk8), &arg1->unk144);

    switch (arg1->unk24 & 0x1C0) {
    case 0:
        break;

    case 0xC0:
        arg1->unk13C.vx += arg2->unk1C[arg0->unkC9].unk4C.vx;
        arg1->unk13C.vy += arg2->unk1C[arg0->unkC9].unk4C.vy;
        arg1->unk13C.vz += arg2->unk1C[arg0->unkC9].unk4C.vz;
        break;

    case 0x80:
        arg1->unk13C.vx += D_800F5230.unkE0.vx;
        arg1->unk13C.vy += D_800F5230.unkE0.vy;
        arg1->unk13C.vz += D_800F5230.unkE0.vz;
        break;
    }

    for (i = 0; i < (u_char)arg3->unk2; ++i) {
        SVECTOR* v = &arg3->unk4[i].splinePoints[3];
        v->vx = arg1->unk13C.vx + func_800CFB80(arg1->unk144.vx, -arg1->unk144.vx);
        v->vy = arg1->unk13C.vy + func_800CFB80(arg1->unk144.vy, -arg1->unk144.vy);
        v->vz = arg1->unk13C.vz + func_800CFB80(arg1->unk144.vz, -arg1->unk144.vz);
    }
}

void func_800FA294(func_800FA098_arg0* arg0, func_800FA098_arg1* arg1,
    D_800F53B8_t* arg2 __attribute__((unused)), func_800FA76C_arg3* arg3)
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
            SVECTOR* temp_s5 = arg3->unk4[i].splinePoints;
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

void func_800FA76C(func_800FA098_arg0* arg0, func_800FA098_arg1* arg1,
    D_800F53B8_t* arg2 __attribute__((unused)), func_800FA76C_arg3* arg3)
{
    int speed;
    int i;

    vs_battle_lerp2DVector(arg0->unk94[4], 0, &arg1->unk134);
    speed = func_800CFE1C(&arg0->unk30, 0) << 0xC;

    for (i = 0; i < (u_char)arg3->unk2; ++i) {
        int stepCount = func_800CFB80(arg1->unk134, arg1->unk138);
        if (stepCount == 0) {
            stepCount = 1;
        }
        arg3->unk4[i].stepCount = stepCount;
        arg3->unk4[i].trailCount = 1;
        arg3->unk4[i].unk22 = 8;
        arg3->unk4[i].currentTrail = 0;
        arg3->unk4[i].trails[0] = arg3->unk4[i].splinePoints[0];
        arg3->unk4[i].splineProgress = 0;
        arg3->unk4[i].speed = speed;
        arg3->unk4[i].unk74 =
            ((0x06000000 / (stepCount * stepCount)) - ((speed * 2) / stepCount));
    }
}

void func_800FA8E4(func_800FA098_arg0* arg0 __attribute__((unused)),
    func_800FA098_arg1* arg1 __attribute__((unused)),
    D_800F53B8_t* arg2 __attribute__((unused)), func_800FA76C_arg3* arg3)
{
    int i;

    for (i = 0; i < (u_char)arg3->unk2; ++i) {

        func_800FA76C_t* temp_s0 = &arg3->unk4[i];

        if (temp_s0->unk22 == 0) {
            continue;
        }

        if (arg3->unk8 >= temp_s0->stepCount) {
            --temp_s0->unk22;
            if (temp_s0->unk22 < temp_s0->stepCount) {
                --temp_s0->trailCount;
            }
        } else {
            int currentStep = temp_s0->stepCount - arg3->unk8;
            int speed = temp_s0->speed;

            speed += ((0x06000000 - (temp_s0->splineProgress * 2))
                         / (currentStep * currentStep))
                   - ((speed * 2) / currentStep);
            temp_s0->speed = speed;
            temp_s0->splineProgress += speed;
            temp_s0->currentTrail = (temp_s0->currentTrail + 1) % 9;

            vs_battle_splineInterpolate(&temp_s0->splinePoints[0],
                &temp_s0->splinePoints[1], &temp_s0->splinePoints[2],
                &temp_s0->splinePoints[3], (temp_s0->splineProgress >> 0xC) - ONE,
                &temp_s0->trails[temp_s0->currentTrail]);

            if (temp_s0->trailCount < 9) {
                ++temp_s0->trailCount;
            }
        }
    }
}

INCLUDE_ASM("build/src/EFFECT/PLG049.BIN/nonmatchings/E0", func_800FAA70);

INCLUDE_ASM("build/src/EFFECT/PLG049.BIN/nonmatchings/E0", func_800FB4C0);

INCLUDE_ASM("build/src/EFFECT/PLG049.BIN/nonmatchings/E0", func_800FBA00);

INCLUDE_ASM("build/src/EFFECT/PLG049.BIN/nonmatchings/E0", func_800FC624);

INCLUDE_ASM("build/src/EFFECT/PLG049.BIN/nonmatchings/E0", func_800FD51C);
