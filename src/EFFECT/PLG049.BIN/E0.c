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
    u_char splineSampleCount;
    u_char trailCollapseCounter;
    u_char currentSplineSample;
    SVECTOR splineSamples[9];
    int splineProgress;
    int speed;
    int unk74;
} _trail;

typedef struct {
    u_char unk0;
    u_char unk1;
    u_char trailcount;
    u_char unk3;
    _trail* trails;
    int unk8;
    func_800D6CF_t unkC;
    int unk1C;
    u_char sampledTransparencyCurve[9];
    u_char unk35[3];
} func_800FA76C_arg3;

extern int D_800FE3D4;

static void func_800F98E0(func_800FA098_arg0* arg0, func_800FA098_arg1* arg1,
    D_800F53B8_t* arg2, func_800FA76C_arg3* arg3)
{
    int sp10;
    int sp14;
    MATRIX* matrix;
    SVECTOR* temp_s1;
    int temp_a1;
    int temp_lo;
    int temp_s0_2;
    int temp_s3;
    int temp_v0;
    int temp_v0_4;
    int i;
    u_short var_a0;
    u_short var_v1;
    u_short var_v1_2;

    vs_battle_lerpVector(
        arg0->unk18, vs_battle_sampleCurve(arg0->unk8, arg3->unk8), &arg1->unk98);

    matrix = &arg2->unk1C[arg0->unkC8].unk38;

    switch (arg1->flags & 7) {
    case 0:
        break;
    case 1:
        vs_battle_addVecToSvec(&arg1->unk98, D_800F5310, &arg1->unk98);
        break;
    case 2:
        arg1->unk98.vx += matrix->t[0];
        arg1->unk98.vy += matrix->t[1];
        arg1->unk98.vz += matrix->t[2];
        break;
    }

    vs_battle_lerpVector(
        arg0->unk24, vs_battle_sampleCurve(arg0->unk9, arg3->unk8), &arg1->unkA8);
    SetRotMatrix(matrix);
    gte_zrtr();

    switch (arg1->flags & 0x38) {
    case 0:
        for (i = 0; i < arg3->trailcount; ++i) {
            temp_s1 = &arg3->trails[i].splinePoints[0];
            temp_v0 = rand();
            arg1->unk170 = rsin(temp_v0);
            arg1->unk178 = rcos(temp_v0);
            temp_v0 = rand();
            arg1->unk174 = rsin(temp_v0);
            arg1->unk17C = rcos(temp_v0);
            temp_s1->vx =
                ((((arg1->unkA8.vx * arg1->unk178) >> 0xC) * arg1->unk17C) >> 0xC);
            temp_s1->vy =
                ((((arg1->unkA8.vy * arg1->unk178) >> 0xC) * arg1->unk174) >> 0xC);
            temp_s1->vz = ((arg1->unkA8.vz * arg1->unk170) >> 0xC);
            if (arg1->flags & 0x40000) {
                ApplyRotMatrix(temp_s1, &arg1->unk34);
                temp_s1->vx = arg1->unk34.vx;
                temp_s1->vy = arg1->unk34.vy;
                temp_s1->vz = arg1->unk34.vz;
            }
            temp_s1->vx += arg1->unk98.vx;
            temp_s1->vy += arg1->unk98.vy;
            temp_s1->vz += arg1->unk98.vz;
        }
        return;

    case 8:
        for (i = 0; i < arg3->trailcount; ++i) {

            temp_s1 = &arg3->trails[i].splinePoints[0];

            switch (arg1->flags & 0x1800) {
            case 0x800:
            case 0x0:
                switch (rand() % 6) {
                case 0:
                    temp_s1->vx = arg1->unkA8.vx;
                    goto jump0;
                case 1:
                    temp_s1->vx = -arg1->unkA8.vx;
                jump0:
                    temp_s1->vy =
                        vs_battle_randUniformInt(arg1->unkA8.vy, -arg1->unkA8.vy);
                    temp_s1->vz =
                        vs_battle_randUniformInt(arg1->unkA8.vz, -arg1->unkA8.vz);
                    break;
                case 2:
                    temp_s1->vy = arg1->unkA8.vy;
                    goto jump1;
                    break;
                case 3:
                    temp_s1->vy = -arg1->unkA8.vy;
                jump1:
                    temp_s1->vx =
                        vs_battle_randUniformInt(arg1->unkA8.vx, -arg1->unkA8.vx);
                    temp_s1->vz =
                        vs_battle_randUniformInt(arg1->unkA8.vz, -arg1->unkA8.vz);
                    break;
                case 4:
                    temp_s1->vz = arg1->unkA8.vz;
                    goto jump2;
                    break;
                case 5:
                    temp_s1->vz = -arg1->unkA8.vz;
                jump2:
                    temp_s1->vx =
                        vs_battle_randUniformInt(arg1->unkA8.vx, -arg1->unkA8.vx);
                    temp_s1->vy =
                        vs_battle_randUniformInt(arg1->unkA8.vy, -arg1->unkA8.vy);
                    break;
                }
                break;

            case 0x1000:
                temp_a1 = D_800FE3D4 + 1;
                D_800FE3D4 = temp_a1 & 7;

                var_a0 = arg1->unkA8.vx;
                if (!(temp_a1 & 1)) {
                    var_a0 = -var_a0;
                }

                temp_s1->vx = var_a0;

                var_v1 = arg1->unkA8.vy;
                if (!(temp_a1 & 2)) {
                    var_v1 = -var_v1;
                }
                temp_s1->vy = var_v1;

                var_v1_2 = arg1->unkA8.vz;
                if (!(temp_a1 & 4)) {
                    var_v1_2 = -var_v1_2;
                }
                temp_s1->vz = var_v1_2;

                break;
            }

            if (arg1->flags & 0x40000) {
                ApplyRotMatrix(temp_s1, &arg1->unk34);
                temp_s1->vx = arg1->unk34.vx;
                temp_s1->vy = arg1->unk34.vy;
                temp_s1->vz = arg1->unk34.vz;
            }

            temp_s1->vx += arg1->unk98.vx;
            temp_s1->vy += arg1->unk98.vy;
            temp_s1->vz += arg1->unk98.vz;
        }

        return;

    case 16:
    case 24:
    case 32:
    case 40:
        arg1->unk184 = 4;
        arg1->unk188 = 4;
        break;

    case 48:
        arg1->unk184 = arg0->unkCA;
        if (arg1->unk184 == 0) {
            arg1->unk184 = 1;
        }
        arg1->unk188 = arg0->unkCB;
        if (arg1->unk188 == 0) {
            arg1->unk188 = arg1->unk184;
        }
        break;

    default:
        return;
    }

    temp_lo = 0x1000 / arg1->unk184;

    if ((arg1->flags & 0x1800) != 0x1000) {
        D_800FE3D4 = D_800FE3D4 % arg1->unk188;
        temp_s0_2 = (D_800FE3D4 * temp_lo) + 0x200;
        sp10 = (rcos(temp_s0_2) * arg1->unkA8.vx) >> 0xC;
        sp14 = (rsin(temp_s0_2) * arg1->unkA8.vz) >> 0xC;
    }

    for (i = 0; i < arg3->trailcount; ++i) {
        temp_s1 = &arg3->trails[i].splinePoints[0];
        D_800FE3D4 = (D_800FE3D4 + 1) % arg1->unk188;
        temp_s0_2 = (D_800FE3D4 * temp_lo) + 0x200;
        temp_s3 = (rcos(temp_s0_2) * arg1->unkA8.vx) >> 0xC;
        temp_s0_2 = (rsin(temp_s0_2) * arg1->unkA8.vz) >> 0xC;

        if ((arg1->flags & 0x1800) == 0x1000) {
            temp_s1->vx = temp_s3;
            temp_s1->vz = temp_s0_2;
        } else {
            temp_v0_4 = rand() >> 3;
            temp_s1->vx = (((temp_s3 - sp10) * temp_v0_4) >> 0xC) + sp10;
            temp_s1->vz = (((temp_s0_2 - sp14) * temp_v0_4) >> 0xC) + sp14;
        }

        temp_s1->vy = 0;

        if (arg1->flags & 0x40000) {
            ApplyRotMatrix(temp_s1, &arg1->unk34);
            temp_s1->vx = arg1->unk34.vx;
            temp_s1->vy = arg1->unk34.vy;
            temp_s1->vz = arg1->unk34.vz;
        }

        temp_s1->vx = temp_s1->vx + arg1->unk98.vx;
        temp_s1->vy = temp_s1->vy + arg1->unk98.vy;
        temp_s1->vz = temp_s1->vz + arg1->unk98.vz;
    }
}

static void func_800FA07C(func_800FA098_arg0* arg0, func_800FA098_arg1* arg1,
    D_800F53B8_t* arg2, func_800FA76C_arg3* arg3)
{
    int i;

    vs_battle_lerpSvector(
        arg0->unk34[6], vs_battle_sampleCurve(arg0->unkF, arg3->unk8), &arg1->unk13C);
    vs_battle_lerpSvector(
        arg0->unk34[7], vs_battle_sampleCurve(arg0->unk10, arg3->unk8), &arg1->unk144);

    switch (arg1->flags & 0x1C0) {
    case 0:
        break;

    case 0xC0:
        arg1->unk13C.vx += arg2->unk1C[arg0->unkC9].unk38.t[0];
        arg1->unk13C.vy += arg2->unk1C[arg0->unkC9].unk38.t[1];
        arg1->unk13C.vz += arg2->unk1C[arg0->unkC9].unk38.t[2];
        break;

    case 0x80:
        arg1->unk13C.vx += D_800F5230.unkE0.vx;
        arg1->unk13C.vy += D_800F5230.unkE0.vy;
        arg1->unk13C.vz += D_800F5230.unkE0.vz;
        break;
    }

    for (i = 0; i < arg3->trailcount; ++i) {
        SVECTOR* v = &arg3->trails[i].splinePoints[3];
        v->vx =
            arg1->unk13C.vx + vs_battle_randUniformInt(arg1->unk144.vx, -arg1->unk144.vx);
        v->vy =
            arg1->unk13C.vy + vs_battle_randUniformInt(arg1->unk144.vy, -arg1->unk144.vy);
        v->vz =
            arg1->unk13C.vz + vs_battle_randUniformInt(arg1->unk144.vz, -arg1->unk144.vz);
    }
}

static void func_800FA294(func_800FA098_arg0* arg0, func_800FA098_arg1* arg1,
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
        for (i = 0; i < arg3->trailcount; ++i) {
            SVECTOR* temp_s5 = arg3->trails[i].splinePoints;
            arg1->unk34.vx = temp_s5[3].vx - temp_s5[0].vx;
            arg1->unk34.vy = temp_s5[3].vy - temp_s5[0].vy;
            arg1->unk34.vz = temp_s5[3].vz - temp_s5[0].vz;
            temp_s0 = vs_gte_rsqrt((arg1->unk34.vx * arg1->unk34.vx)
                                   + (arg1->unk34.vy * arg1->unk34.vy)
                                   + (arg1->unk34.vz * arg1->unk34.vz));
            vs_battle_lerp2DVector(arg0->unk94[0],
                vs_battle_sampleCurve(arg0->unk12, arg3->unk8), arg1->unk124);
            vs_battle_lerp2DVector(arg0->unk94[1],
                vs_battle_sampleCurve(arg0->unk13, arg3->unk8), arg1->unk12C);
            vs_battle_lerp2DVector(arg0->unk94[2],
                vs_battle_sampleCurve(arg0->unkC, arg3->unk8), arg1->unk118);
            vs_battle_lerpVector(arg0->unk34[1],
                vs_battle_sampleCurve(arg0->unkB, arg3->unk8), &arg1->unkC8);
            vs_battle_lerpVector(arg0->unk34[0],
                vs_battle_sampleCurve(arg0->unkA, arg3->unk8), &arg1->unkE8);
            vs_battle_lerpSvector(arg0->unk34[2],
                vs_battle_sampleCurve(arg0->unkD, arg3->unk8), &arg1->unkF8);

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

static void func_800FA76C(func_800FA098_arg0* arg0, func_800FA098_arg1* arg1,
    D_800F53B8_t* arg2 __attribute__((unused)), func_800FA76C_arg3* arg3)
{
    int speed;
    int i;

    vs_battle_lerp2DVector(arg0->unk94[4], 0, arg1->unk134);

    speed = func_800CFE1C(arg0->unk30, 0) << 0xC;

    for (i = 0; i < arg3->trailcount; ++i) {
        int stepCount = vs_battle_randUniformInt(arg1->unk134[0], arg1->unk134[1]);
        if (stepCount == 0) {
            stepCount = 1;
        }
        arg3->trails[i].stepCount = stepCount;
        arg3->trails[i].splineSampleCount = 1;
        arg3->trails[i].trailCollapseCounter = 8;
        arg3->trails[i].currentSplineSample = 0;
        arg3->trails[i].splineSamples[0] = arg3->trails[i].splinePoints[0];
        arg3->trails[i].splineProgress = 0;
        arg3->trails[i].speed = speed;
        arg3->trails[i].unk74 =
            ((0x06000000 / (stepCount * stepCount)) - ((speed * 2) / stepCount));
    }
}

static void func_800FA8E4(func_800FA098_arg0* arg0 __attribute__((unused)),
    func_800FA098_arg1* arg1 __attribute__((unused)),
    D_800F53B8_t* arg2 __attribute__((unused)), func_800FA76C_arg3* arg3)
{
    int i;

    for (i = 0; i < arg3->trailcount; ++i) {

        _trail* temp_s0 = &arg3->trails[i];

        if (temp_s0->trailCollapseCounter == 0) {
            continue;
        }

        if (arg3->unk8 >= temp_s0->stepCount) {
            --temp_s0->trailCollapseCounter;
            if (temp_s0->trailCollapseCounter < temp_s0->stepCount) {
                --temp_s0->splineSampleCount;
            }
        } else {
            int currentStep = temp_s0->stepCount - arg3->unk8;
            int speed = temp_s0->speed;

            speed += ((0x06000000 - (temp_s0->splineProgress * 2))
                         / (currentStep * currentStep))
                   - ((speed * 2) / currentStep);
            temp_s0->speed = speed;
            temp_s0->splineProgress += speed;
            temp_s0->currentSplineSample = (temp_s0->currentSplineSample + 1) % 9;

            vs_battle_splineInterpolate(&temp_s0->splinePoints[0],
                &temp_s0->splinePoints[1], &temp_s0->splinePoints[2],
                &temp_s0->splinePoints[3], (temp_s0->splineProgress >> 0xC) - ONE,
                &temp_s0->splineSamples[temp_s0->currentSplineSample]);

            if (temp_s0->splineSampleCount < 9) {
                ++temp_s0->splineSampleCount;
            }
        }
    }
}

void func_800FAA70(
    func_800FA098_arg0*, func_800FA098_arg1*, D_800F53B8_t*, func_800FA76C_arg3*);
INCLUDE_ASM("build/src/EFFECT/PLG049.BIN/nonmatchings/E0", func_800FAA70);

/**
 * Text rays from caster to target
 */
int vs_spiritSurge_renderTrails(func_800D4910_t* arg0, u_int arg1, int arg2)
{
    func_800FB4C0_t sp18;
    func_800FA098_arg0* temp_s3;
    int trail;
    int j;
    func_800FA76C_arg3* temp_v0;

    func_800FA098_arg1* s4 = (func_800FA098_arg1*)0x1F8001D0;
    func_800FA76C_arg3* temp_s0 = arg0->unk8;
    D_800F53B8_t* temp_s5 = D_800F53BC;
    int s6 = 1;

    switch (arg1) {
    case 1:
        temp_v0 = vs_main_allocHeapR(sizeof *temp_v0);
        arg0->unk8 = temp_v0;
        temp_v0->unk1 = arg2 >> 8;
        temp_v0->unk0 = arg2;
        temp_v0->unk8 = 0;
        temp_s3 = &D_800F569C->block5Data->unk4[temp_v0->unk1];
        trail = temp_s3->unkC0[0];

        if (trail > 8) {
            trail = 8;
        }

        temp_v0->trails = vs_main_allocHeapR(trail * sizeof *temp_v0->trails);
        temp_v0->trailcount = trail;
        temp_v0->unk3 = 0;

        if (temp_s3->transparencyCurve != 0) {

            // bad var reuse, trail = length of curve
            trail = D_800F569C->curveBlock->curveSizes[temp_s3->transparencyCurve];

            if (trail > 1) {
                --trail;
            }

            for (j = 0; j < (int)sizeof temp_v0->sampledTransparencyCurve; ++j) {
                temp_v0->sampledTransparencyCurve[j] =
                    D_800F569C->curves[temp_s3->transparencyCurve][(j * trail) / 8];
            }

        } else {
            for (j = 0; j < (int)sizeof temp_v0->sampledTransparencyCurve; ++j) {
                temp_v0->sampledTransparencyCurve[j] = 128;
            }
        }

        func_800D6CCC((int*)&temp_v0->unkC);
        func_800D6CF0(&temp_v0->unkC, temp_s3->unk1, temp_s3->unk0);

        break;

    case 2:
        temp_s3 = &D_800F569C->block5Data->unk4[temp_s0->unk1];
        s4->flags = temp_s3->flags;

        if (temp_s0->unk3 == 0) {
            func_800F98E0(temp_s3, s4, temp_s5, temp_s0);
            func_800FA07C(temp_s3, s4, temp_s5, temp_s0);
            func_800FA294(temp_s3, s4, temp_s5, temp_s0);
            func_800FA76C(temp_s3, s4, temp_s5, temp_s0);
            temp_s0->unk3 = 1;
        }

        func_800FA8E4(temp_s3, s4, temp_s5, temp_s0);
        func_800FAA70(temp_s3, s4, temp_s5, temp_s0);

        if (temp_s3->unk3 != 0) {
            for (trail = 0; trail < temp_s0->trailcount; ++trail) {

                sp18.unk60 = 0;

                if (temp_s3->flags & 0x20000) {

                    SetRotMatrix(&temp_s5->unk1C[temp_s3->unkC8].unk38);
                    SetTransMatrix(&temp_s5->unk1C[temp_s3->unkC8].unk38);

                    s4->unk2C.vx =
                        temp_s0->trails[trail]
                            .splineSamples[temp_s0->trails[trail].currentSplineSample]
                            .vx;
                    s4->unk2C.vy =
                        temp_s0->trails[trail]
                            .splineSamples[temp_s0->trails[trail].currentSplineSample]
                            .vy;
                    s4->unk2C.vz =
                        temp_s0->trails[trail]
                            .splineSamples[temp_s0->trails[trail].currentSplineSample]
                            .vz;

                    gte_ldv0(&s4->unk2C);
                    gte_rtv0tr2();
                    gte_stlvnl(&s4->unk34);

                    sp18.unkC.vx = s4->unk34.vx * ONE;
                    sp18.unkC.vy = s4->unk34.vy * ONE;
                    sp18.unkC.vz = s4->unk34.vz * ONE;
                } else {
                    sp18.unkC.vx =
                        temp_s0->trails[trail]
                            .splineSamples[temp_s0->trails[trail].currentSplineSample]
                            .vx
                        * ONE;
                    sp18.unkC.vy =
                        temp_s0->trails[trail]
                            .splineSamples[temp_s0->trails[trail].currentSplineSample]
                            .vy
                        * ONE;
                    sp18.unkC.vz =
                        temp_s0->trails[trail]
                            .splineSamples[temp_s0->trails[trail].currentSplineSample]
                            .vz
                        * ONE;
                }
                func_800D2ADC(temp_s5, temp_s3->unk3 - 1, 0, 0, &sp18);
            }
        }

        ++temp_s0->unk8;

        if (temp_s0->unk0 != 0) {
            --temp_s0->unk0;
            if (!temp_s0->unk0) {
                vs_main_freeHeapR(temp_s0->trails);
                s6 = 0;
            }
        }
        break;

    case 3:
        temp_s0->unk0 = 1;
        break;

    case 4:
        vs_main_freeHeapR(temp_s0->trails);
        s6 = 0;
        break;
    }

    return s6;
}

/**
 * Concentric text circles over caster
 */
INCLUDE_ASM("build/src/EFFECT/PLG049.BIN/nonmatchings/E0", func_800FBA00);

/**
 * Target impact
 */
INCLUDE_ASM("build/src/EFFECT/PLG049.BIN/nonmatchings/E0", func_800FC624);

/**
 * Column of light and particles on cast
 */
INCLUDE_ASM("build/src/EFFECT/PLG049.BIN/nonmatchings/E0", func_800FD51C);
