/* Shared five-sample spline trail effect. The overlay supplies the function names of
 * each stage and the corner state that the origin stage cycles through. */

#define TRAIL_SAMPLE_COUNT 5

#include "src/EFFECT/trails.h"
#include "src/SLUS_010.40/32154.h"
#include "vs_inline_c.h"
#include <inline_c.h>
#include <rand.h>

extern int VS_TRAIL_CORNER_STATE;

void VS_TRAIL_ORIGIN_FUNCTION(func_800FA098_arg0* arg0, func_800FA098_arg1* arg1,
    D_800F53B8_t* arg2, func_800FA76C_arg3* arg3)
{
    int startX;
    int startZ;
    MATRIX* matrix;
    SVECTOR* splinePoint;
    int corner;
    int step;
    int angle;
    int i;
    u_short cornerX;
    u_short cornerY;
    u_short cornerZ;

    vs_battle_lerpVector(arg0->unk18,
        vs_battle_sampleCurve(arg0->unk8, arg3->curveSampleDistance), &arg1->unk98);

    matrix = &arg2->unk1C[arg0->unkC8].world;

    switch (arg1->flags & 7) {
    case 0:
        break;

    case 1:
        vs_battle_addVecToSvec(&arg1->unk98, D_800F5310, &arg1->unk98);
        break;

    case 2:
        applyVector(&arg1->unk98, matrix->t[0], matrix->t[1], matrix->t[2], +=);
        break;
    }

    vs_battle_lerpVector(arg0->unk24,
        vs_battle_sampleCurve(arg0->unk9, arg3->curveSampleDistance), &arg1->unkA8);
    SetRotMatrix(matrix);
    gte_zrtr();

    switch (arg1->flags & 0x38) {
    case 0:
        for (i = 0; i < arg3->trailcount; ++i) {
            int random;

            splinePoint = &arg3->trails[i].splinePoints[0];

            random = rand();
            arg1->unk170 = rsin(random);
            arg1->unk178 = rcos(random);

            random = rand();
            arg1->unk174 = rsin(random);
            arg1->unk17C = rcos(random);

            setVector(splinePoint,
                ((((arg1->unkA8.vx * arg1->unk178) >> 0xC) * arg1->unk17C) >> 0xC),
                ((((arg1->unkA8.vy * arg1->unk178) >> 0xC) * arg1->unk174) >> 0xC),
                ((arg1->unkA8.vz * arg1->unk170) >> 0xC));

            if (arg1->flags & 0x40000) {
                ApplyRotMatrix(splinePoint, &arg1->unk34);
                copyVector(splinePoint, &arg1->unk34);
            }

            addVector(splinePoint, &arg1->unk98);
        }

        return;

    case 8:
        for (i = 0; i < arg3->trailcount; ++i) {
            splinePoint = &arg3->trails[i].splinePoints[0];

            switch (arg1->flags & 0x1800) {
            case 0x0:
            case 0x800:
                switch (rand() % 6) {
                case 0:
                    splinePoint->vx = arg1->unkA8.vx;

                    if (0) {
                    case 1:
                        splinePoint->vx = -arg1->unkA8.vx;
                    }

                    splinePoint->vy =
                        vs_battle_randUniformInt(arg1->unkA8.vy, -arg1->unkA8.vy);
                    splinePoint->vz =
                        vs_battle_randUniformInt(arg1->unkA8.vz, -arg1->unkA8.vz);
                    break;

                case 2:
                    splinePoint->vy = arg1->unkA8.vy;

                    if (0) {
                    case 3:
                        splinePoint->vy = -arg1->unkA8.vy;
                    }

                    splinePoint->vx =
                        vs_battle_randUniformInt(arg1->unkA8.vx, -arg1->unkA8.vx);
                    splinePoint->vz =
                        vs_battle_randUniformInt(arg1->unkA8.vz, -arg1->unkA8.vz);
                    break;

                case 4:
                    splinePoint->vz = arg1->unkA8.vz;

                    if (0) {
                    case 5:
                        splinePoint->vz = -arg1->unkA8.vz;
                    }

                    splinePoint->vx =
                        vs_battle_randUniformInt(arg1->unkA8.vx, -arg1->unkA8.vx);
                    splinePoint->vy =
                        vs_battle_randUniformInt(arg1->unkA8.vy, -arg1->unkA8.vy);
                    break;
                }

                break;

            case 0x1000:
                corner = VS_TRAIL_CORNER_STATE + 1;
                VS_TRAIL_CORNER_STATE = corner & 7;

                cornerX = arg1->unkA8.vx;

                if (!(corner & 1)) {
                    cornerX = -cornerX;
                }

                splinePoint->vx = cornerX;

                cornerY = arg1->unkA8.vy;

                if (!(corner & 2)) {
                    cornerY = -cornerY;
                }

                splinePoint->vy = cornerY;

                cornerZ = arg1->unkA8.vz;

                if (!(corner & 4)) {
                    cornerZ = -cornerZ;
                }

                splinePoint->vz = cornerZ;
                break;
            }

            if (arg1->flags & 0x40000) {
                ApplyRotMatrix(splinePoint, &arg1->unk34);
                copyVector(splinePoint, &arg1->unk34);
            }

            addVector(splinePoint, &arg1->unk98);
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

    step = ONE / arg1->unk184;

    if ((arg1->flags & 0x1800) != 0x1000) {
        VS_TRAIL_CORNER_STATE = VS_TRAIL_CORNER_STATE % arg1->unk188;
        angle = (VS_TRAIL_CORNER_STATE * step) + ONE / 8;
        startX = (rcos(angle) * arg1->unkA8.vx) >> 0xC;
        startZ = (rsin(angle) * arg1->unkA8.vz) >> 0xC;
    }

    for (i = 0; i < arg3->trailcount; ++i) {
        int x;
        int z;

        splinePoint = &arg3->trails[i].splinePoints[0];
        VS_TRAIL_CORNER_STATE = (VS_TRAIL_CORNER_STATE + 1) % arg1->unk188;
        angle = (VS_TRAIL_CORNER_STATE * step) + ONE / 8;
        x = (rcos(angle) * arg1->unkA8.vx) >> 0xC;
        z = (rsin(angle) * arg1->unkA8.vz) >> 0xC;

        if ((arg1->flags & 0x1800) == 0x1000) {
            splinePoint->vx = x;
            splinePoint->vz = z;
        } else {
            int blend = rand() >> 3;

            splinePoint->vx = (((x - startX) * blend) >> 0xC) + startX;
            splinePoint->vz = (((z - startZ) * blend) >> 0xC) + startZ;
        }

        splinePoint->vy = 0;

        if (arg1->flags & 0x40000) {
            ApplyRotMatrix(splinePoint, &arg1->unk34);
            copyVector(splinePoint, &arg1->unk34);
        }

        addVector(splinePoint, &arg1->unk98);
    }
}

void VS_TRAIL_TARGET_FUNCTION(func_800FA098_arg0* arg0, func_800FA098_arg1* arg1,
    D_800F53B8_t* arg2, func_800FA76C_arg3* arg3)
{
    int i;

    vs_battle_lerpSvector(arg0->unk34[6],
        vs_battle_sampleCurve(arg0->unkF, arg3->curveSampleDistance), &arg1->unk13C);
    vs_battle_lerpSvector(arg0->unk34[7],
        vs_battle_sampleCurve(arg0->unk10, arg3->curveSampleDistance), &arg1->unk144);

    switch (arg1->flags & 0x1C0) {
    case 0:
        break;

    case 0xC0:
        applyVector(&arg1->unk13C, arg2->unk1C[arg0->unkC9].world.t[0],
            arg2->unk1C[arg0->unkC9].world.t[1], arg2->unk1C[arg0->unkC9].world.t[2], +=);
        break;

    case 0x80:
        applyVector(&arg1->unk13C, D_800F5230.position.vx, D_800F5230.position.vy,
            D_800F5230.position.vz, +=);
        break;
    }

    for (i = 0; i < arg3->trailcount; ++i) {
        SVECTOR* target = &arg3->trails[i].splinePoints[3];

        setVector(target,
            arg1->unk13C.vx + vs_battle_randUniformInt(arg1->unk144.vx, -arg1->unk144.vx),
            arg1->unk13C.vy + vs_battle_randUniformInt(arg1->unk144.vy, -arg1->unk144.vy),
            arg1->unk13C.vz
                + vs_battle_randUniformInt(arg1->unk144.vz, -arg1->unk144.vz));
    }
}

void VS_TRAIL_CONTROL_FUNCTION(func_800FA098_arg0* arg0, func_800FA098_arg1* arg1,
    D_800F53B8_t* arg2 __attribute__((unused)), func_800FA76C_arg3* arg3)
{
    SVECTOR control0;
    SVECTOR control1;
    int i;
    int length;
    int angle0;
    int angle1;
    int radius0;
    int radius1;

    for (i = 0; i < arg3->trailcount; ++i) {
        SVECTOR* points = arg3->trails[i].splinePoints;

        setVector(&arg1->unk34, points[3].vx - points[0].vx, points[3].vy - points[0].vy,
            points[3].vz - points[0].vz);

        length = vs_gte_rsqrt((arg1->unk34.vx * arg1->unk34.vx)
                              + (arg1->unk34.vy * arg1->unk34.vy)
                              + (arg1->unk34.vz * arg1->unk34.vz));

        vs_battle_lerp2DVector(arg0->unk94[0],
            vs_battle_sampleCurve(arg0->unk12, arg3->curveSampleDistance), arg1->unk124);
        vs_battle_lerp2DVector(arg0->unk94[1],
            vs_battle_sampleCurve(arg0->unk13, arg3->curveSampleDistance), arg1->unk12C);
        vs_battle_lerp2DVector(arg0->unk94[2],
            vs_battle_sampleCurve(arg0->unkC, arg3->curveSampleDistance), arg1->unk118);
        vs_battle_lerpVector(arg0->unk34[1],
            vs_battle_sampleCurve(arg0->unkB, arg3->curveSampleDistance), &arg1->unkC8);
        vs_battle_lerpVector(arg0->unk34[0],
            vs_battle_sampleCurve(arg0->unkA, arg3->curveSampleDistance), &arg1->unkE8);
        vs_battle_lerpSvector(arg0->unk34[2],
            vs_battle_sampleCurve(arg0->unkD, arg3->curveSampleDistance), &arg1->unkF8);

        if (arg1->unkF8.vx != 0) {
            int offset =
                (arg1->unk118[0] + (rand() % arg1->unkF8.vx)) - (arg1->unkF8.vx / 2);
            if (&arg1->unk34) {
                control0.vz = (length * offset) / 256;
            } else {
                control0.vz = (length * offset) / 256;
            }
        } else {
            control0.vz = (length * arg1->unk118[0]) / 256;
        }

        if (arg1->unkF8.vy != 0) {
            int offset =
                (arg1->unk118[1] + (rand() % arg1->unkF8.vy)) - (arg1->unkF8.vy / 2);
            control1.vz = length + ((length * offset) / 256);
        } else {
            control1.vz = length + ((length * arg1->unk118[1]) / 256);
        }

        radius0 = arg1->unk124[0];

        if (arg1->unk124[1] != 0) {
            radius0 += rand() % arg1->unk124[1];
        }

        radius1 = arg1->unk12C[0];

        if (arg1->unk12C[1] != 0) {
            radius1 += rand() % arg1->unk12C[1];
        }

        angle0 = arg1->unkE8.vx;

        if (arg1->unkC8.vx != 0) {
            angle0 += (rand() % (arg1->unkC8.vx * 2)) - arg1->unkC8.vx;
        }

        angle1 = arg1->unkE8.vy;

        if (arg1->unkC8.vy != 0) {
            angle1 += (rand() % (arg1->unkC8.vy * 2)) - arg1->unkC8.vy;
        }

        control0.vx = (rcos(angle0) * radius0) >> 0xC;
        control0.vy = (rsin(angle0) * radius0) >> 0xC;
        control1.vx = (rcos(angle1) * radius1) >> 0xC;
        control1.vy = (rsin(angle1) * radius1) >> 0xC;

        vs_battle_svecToVec(points, &arg1->unk34);
        vs_battle_svecToVec(points + 3, &arg1->unk44);
        vs_battle_lookAt(&arg1->unk34, &arg1->unk44, &arg1->unk64);
        gte_SetRotMatrix(&arg1->unk64);
        gte_SetTransVector2(&arg1->unk34);
        gte_ldv0(&control0);
        gte_rtv0tr2();
        gte_stlvnl(&arg1->unk34);
        vs_battle_vecToSvec(&arg1->unk34, points + 1);
        gte_ldv0(&control1);
        gte_rtv0tr2();
        gte_stlvnl(&arg1->unk44);
        vs_battle_vecToSvec(&arg1->unk44, points + 2);
    }
}

void VS_TRAIL_INIT_FUNCTION(func_800FA098_arg0* arg0, func_800FA098_arg1* arg1,
    D_800F53B8_t* arg2 __attribute__((unused)), func_800FA76C_arg3* arg3)
{
    int speed;
    int i;

    vs_battle_lerp2DVector(arg0->unk94[4], 0, arg1->unk134);

    speed = func_800CFE1C(arg0->unk30, 0) * ONE;

    for (i = 0; i < arg3->trailcount; ++i) {
        int stepCount = vs_battle_randUniformInt(arg1->unk134[0], arg1->unk134[1]);

        if (stepCount == 0) {
            stepCount = 1;
        }

        arg3->trails[i].stepCount = stepCount;
        arg3->trails[i].splineSampleCount = 1;
        arg3->trails[i].trailCollapseCounter = TRAIL_SAMPLE_COUNT - 1;
        arg3->trails[i].currentSplineSample = 0;
        arg3->trails[i].splineSamples[0] = arg3->trails[i].splinePoints[0];
        arg3->trails[i].splineProgress = 0;
        arg3->trails[i].speed = speed;
        arg3->trails[i].unk =
            ((6 * ONE * ONE / (stepCount * stepCount)) - ((speed * 2) / stepCount));
    }
}

void VS_TRAIL_UPDATE_FUNCTION(func_800FA098_arg0* arg0 __attribute__((unused)),
    func_800FA098_arg1* arg1 __attribute__((unused)),
    D_800F53B8_t* arg2 __attribute__((unused)), func_800FA76C_arg3* arg3)
{
    int i;

    for (i = 0; i < arg3->trailcount; ++i) {
        _trail* trail = &arg3->trails[i];

        if (trail->trailCollapseCounter == 0) {
            continue;
        }

        if (arg3->curveSampleDistance >= trail->stepCount) {
            --trail->trailCollapseCounter;

            if (trail->trailCollapseCounter < trail->stepCount) {
                --trail->splineSampleCount;
            }
        } else {
            int currentStep = trail->stepCount - arg3->curveSampleDistance;
            int speed = trail->speed;

            speed += ((6 * ONE * ONE - (trail->splineProgress * 2))
                         / (currentStep * currentStep))
                   - ((speed * 2) / currentStep);
            trail->speed = speed;
            trail->splineProgress += speed;
            trail->currentSplineSample =
                (trail->currentSplineSample + 1) % TRAIL_SAMPLE_COUNT;

            vs_battle_splineInterpolate(&trail->splinePoints[0], &trail->splinePoints[1],
                &trail->splinePoints[2], &trail->splinePoints[3],
                (trail->splineProgress >> 0xC) - ONE,
                &trail->splineSamples[trail->currentSplineSample]);

            if (trail->splineSampleCount < TRAIL_SAMPLE_COUNT) {
                ++trail->splineSampleCount;
            }
        }
    }
}

#undef VS_TRAIL_ORIGIN_FUNCTION
#undef VS_TRAIL_TARGET_FUNCTION
#undef VS_TRAIL_CONTROL_FUNCTION
#undef VS_TRAIL_INIT_FUNCTION
#undef VS_TRAIL_UPDATE_FUNCTION
#undef VS_TRAIL_CORNER_STATE
#undef TRAIL_SAMPLE_COUNT
