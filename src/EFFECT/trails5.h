/* Shared five-sample spline trail effect. The overlay supplies the function names of
 * each stage and the corner state that the origin stage cycles through. */

#define TRAIL_SAMPLE_COUNT 5

#include "src/EFFECT/trails.h"
#include "vs_inline_c.h"
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
        VS_TRAIL_CORNER_STATE %= arg1->unk188;
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

#undef VS_TRAIL_ORIGIN_FUNCTION
#undef VS_TRAIL_TARGET_FUNCTION
#undef VS_TRAIL_CORNER_STATE
#undef TRAIL_SAMPLE_COUNT
