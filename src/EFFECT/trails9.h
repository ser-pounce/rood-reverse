/* Shared nine-sample trail effect. The overlay supplies the entry point
 * (VS_TRAIL_DISPATCH_FUNCTION); the helper stages are named after it unless the overlay
 * defines VS_TRAIL_<STAGE>_FUNCTION. */

#ifndef VS_TRAIL_DISPATCH_FUNCTION
#include "src/EFFECT/entry.h"
#define VS_TRAIL_DISPATCH_FUNCTION VS_ENTRY_FUNCTION
#endif

#include "src/EFFECT/trails.h"
#include "src/SLUS_010.40/32154.h"
#include "vs_inline_c.h"
#include "gpu.h"
#include <inline_c.h>
#include <libgte.h>
#include <rand.h>

typedef struct {
    u_long tag;
    POLY_GT4 poly;
    int drawMode;
} vs_trail9Prim;

#ifndef VS_CAT
#define VS_CAT_(a, b) a##b
#define VS_CAT(a, b) VS_CAT_(a, b)
#endif

#ifndef VS_TRAIL_ORIGIN_FUNCTION
#define VS_TRAIL_ORIGIN_FUNCTION VS_CAT(VS_TRAIL_DISPATCH_FUNCTION, _origin)
#endif
#ifndef VS_TRAIL_TARGET_FUNCTION
#define VS_TRAIL_TARGET_FUNCTION VS_CAT(VS_TRAIL_DISPATCH_FUNCTION, _target)
#endif
#ifndef VS_TRAIL_CONTROL_FUNCTION
#define VS_TRAIL_CONTROL_FUNCTION VS_CAT(VS_TRAIL_DISPATCH_FUNCTION, _control)
#endif
#ifndef VS_TRAIL_INIT_FUNCTION
#define VS_TRAIL_INIT_FUNCTION VS_CAT(VS_TRAIL_DISPATCH_FUNCTION, _init)
#endif
#ifndef VS_TRAIL_UPDATE_FUNCTION
#define VS_TRAIL_UPDATE_FUNCTION VS_CAT(VS_TRAIL_DISPATCH_FUNCTION, _update)
#endif
#ifndef VS_TRAIL_RENDER_FUNCTION
#define VS_TRAIL_RENDER_FUNCTION VS_CAT(VS_TRAIL_DISPATCH_FUNCTION, _render)
#endif

#ifdef VS_TRAIL9_CORNER_STATE
extern int VS_TRAIL9_CORNER_STATE;
#else
#define VS_TRAIL9_CORNER_STATE VS_CAT(VS_TRAIL_ORIGIN_FUNCTION, _state)
static int VS_TRAIL9_CORNER_STATE = 0;
#endif

static void VS_TRAIL_ORIGIN_FUNCTION(func_800FA098_arg0* arg0, func_800FA098_arg1* arg1,
    D_800F53B8_t* arg2, vs_trail9State* arg3)
{
    int startX;
    int startZ;
    MATRIX* matrix;
    SVECTOR* splinePoint;
    int corner;
    int angleStep;
    int cornerAngle;
    int i;
    u_short cornerX;
    u_short cornerY;
    u_short cornerZ;

    vs_battle_lerpVector(arg0->unk18,
        vs_battle_sampleCurve(arg0->unk8, arg3->curveSampleDistance), &arg1->unk98);

    matrix = &arg2->unk1C[arg0->unkC8].world;

    // Determines trail origin:
    switch (arg1->flags & 7) {
    case 0:
        break;
    // Fixed point D_800F5310
    case 1:
        vs_battle_addVecToSvec(&arg1->unk98, D_800F5310, &arg1->unk98);
        break;
    // Caster
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
            int angle;

            splinePoint = &arg3->trails[i].splinePoints[0];

            angle = rand();
            arg1->unk170 = rsin(angle);
            arg1->unk178 = rcos(angle);

            angle = rand();
            arg1->unk174 = rsin(angle);
            arg1->unk17C = rcos(angle);

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
                corner = VS_TRAIL9_CORNER_STATE + 1;
                VS_TRAIL9_CORNER_STATE = corner & 7;

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

    angleStep = ONE / arg1->unk184;

    if ((arg1->flags & 0x1800) != 0x1000) {
        VS_TRAIL9_CORNER_STATE %= arg1->unk188;
        cornerAngle = (VS_TRAIL9_CORNER_STATE * angleStep) + ONE / 8;
        startX = (rcos(cornerAngle) * arg1->unkA8.vx) >> 0xC;
        startZ = (rsin(cornerAngle) * arg1->unkA8.vz) >> 0xC;
    }

    for (i = 0; i < arg3->trailcount; ++i) {
        int x;
        int z;

        splinePoint = &arg3->trails[i].splinePoints[0];
        VS_TRAIL9_CORNER_STATE = (VS_TRAIL9_CORNER_STATE + 1) % arg1->unk188;
        cornerAngle = (VS_TRAIL9_CORNER_STATE * angleStep) + ONE / 8;
        x = (rcos(cornerAngle) * arg1->unkA8.vx) >> 0xC;
        z = (rsin(cornerAngle) * arg1->unkA8.vz) >> 0xC;

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

static void VS_TRAIL_TARGET_FUNCTION(func_800FA098_arg0* arg0, func_800FA098_arg1* arg1,
    D_800F53B8_t* arg2, vs_trail9State* arg3)
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
        SVECTOR* v = &arg3->trails[i].splinePoints[3];
        setVector(v,
            arg1->unk13C.vx + vs_battle_randUniformInt(arg1->unk144.vx, -arg1->unk144.vx),
            arg1->unk13C.vy + vs_battle_randUniformInt(arg1->unk144.vy, -arg1->unk144.vy),
            arg1->unk13C.vz
                + vs_battle_randUniformInt(arg1->unk144.vz, -arg1->unk144.vz));
    }
}

static void VS_TRAIL_CONTROL_FUNCTION(func_800FA098_arg0* arg0, func_800FA098_arg1* arg1,
    D_800F53B8_t* arg2 __attribute__((unused)), vs_trail9State* arg3)
{
    SVECTOR offset1;
    SVECTOR offset2;
    int distance;
    int i;
    int angle1;
    int angle2;
    int radius1;
    int radius2;

    do {
        for (i = 0; i < arg3->trailcount; ++i) {

            SVECTOR* points = arg3->trails[i].splinePoints;

            setVector(&arg1->unk34, points[3].vx - points[0].vx,
                points[3].vy - points[0].vy, points[3].vz - points[0].vz);

            distance = vs_gte_rsqrt((arg1->unk34.vx * arg1->unk34.vx)
                                    + (arg1->unk34.vy * arg1->unk34.vy)
                                    + (arg1->unk34.vz * arg1->unk34.vz));
            vs_battle_lerp2DVector(arg0->unk94[0],
                vs_battle_sampleCurve(arg0->unk12, arg3->curveSampleDistance),
                arg1->unk124);
            vs_battle_lerp2DVector(arg0->unk94[1],
                vs_battle_sampleCurve(arg0->unk13, arg3->curveSampleDistance),
                arg1->unk12C);
            vs_battle_lerp2DVector(arg0->unk94[2],
                vs_battle_sampleCurve(arg0->unkC, arg3->curveSampleDistance),
                arg1->unk118);
            vs_battle_lerpVector(arg0->unk34[1],
                vs_battle_sampleCurve(arg0->unkB, arg3->curveSampleDistance),
                &arg1->unkC8);
            vs_battle_lerpVector(arg0->unk34[0],
                vs_battle_sampleCurve(arg0->unkA, arg3->curveSampleDistance),
                &arg1->unkE8);
            vs_battle_lerpSvector(arg0->unk34[2],
                vs_battle_sampleCurve(arg0->unkD, arg3->curveSampleDistance),
                &arg1->unkF8);

            if (arg1->unkF8.vx != 0) {
                int spread =
                    (arg1->unk118[0] + (rand() % arg1->unkF8.vx)) - (arg1->unkF8.vx / 2);
                offset1.vz = (distance * spread) / 256;
            } else {
                offset1.vz = (distance * arg1->unk118[0]) / 256;
            }

            if (arg1->unkF8.vy != 0) {
                int spread =
                    (arg1->unk118[1] + (rand() % arg1->unkF8.vy)) - (arg1->unkF8.vy / 2);
                offset2.vz = distance + ((distance * spread) / 256);
            } else {
                offset2.vz = distance + ((distance * arg1->unk118[1]) / 256);
            }

            radius1 = arg1->unk124[0];

            angle1 = arg1->unk124[1] != 0;
            if (angle1) {
                radius1 += rand() % arg1->unk124[1];
            }

            radius2 = arg1->unk12C[0];

            if (arg1->unk12C[1] != 0) {
                radius2 += rand() % arg1->unk12C[1];
            }

            angle1 = arg1->unkE8.vx;

            if (arg1->unkC8.vx != 0) {
                angle1 += (rand() % (arg1->unkC8.vx * 2)) - arg1->unkC8.vx;
            }

            angle2 = arg1->unkE8.vy;

            if (arg1->unkC8.vy != 0) {
                if (&arg1->unk34) {
                    angle2 += (rand() % (arg1->unkC8.vy * 2)) - arg1->unkC8.vy;
                } else {
                    angle2 += (rand() % (arg1->unkC8.vy * 2)) - arg1->unkC8.vy;
                }
            }

            offset1.vx = (rcos(angle1) * radius1) >> 0xC;
            offset1.vy = (rsin(angle1) * radius1) >> 0xC;
            offset2.vx = (rcos(angle2) * radius2) >> 0xC;
            offset2.vy = (rsin(angle2) * radius2) >> 0xC;

            vs_battle_svecToVec(points, &arg1->unk34);
            vs_battle_svecToVec(points + 3, &arg1->unk44);
            vs_battle_lookAt(&arg1->unk34, &arg1->unk44, &arg1->unk64);
            gte_SetRotMatrix(&arg1->unk64);
            gte_SetTransVector2(&arg1->unk34);
            gte_ldv0(&offset1);
            gte_rtv0tr2();
            gte_stlvnl(&arg1->unk34);
            vs_battle_vecToSvec(&arg1->unk34, points + 1);
            gte_ldv0(&offset2);
            gte_rtv0tr2();
            gte_stlvnl(&arg1->unk44);
            vs_battle_vecToSvec(&arg1->unk44, points + 2);
        }
    } while (0);
}

static void VS_TRAIL_INIT_FUNCTION(func_800FA098_arg0* arg0, func_800FA098_arg1* arg1,
    D_800F53B8_t* arg2 __attribute__((unused)), vs_trail9State* arg3)
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
        arg3->trails[i].trailCollapseCounter = 8;
        arg3->trails[i].currentSplineSample = 0;
        arg3->trails[i].splineSamples[0] = arg3->trails[i].splinePoints[0];
        arg3->trails[i].splineProgress = 0;
        arg3->trails[i].speed = speed;
        arg3->trails[i].unk =
            ((0x06000000 / (stepCount * stepCount)) - ((speed * 2) / stepCount));
    }
}

static void VS_TRAIL_UPDATE_FUNCTION(func_800FA098_arg0* arg0 __attribute__((unused)),
    func_800FA098_arg1* arg1 __attribute__((unused)),
    D_800F53B8_t* arg2 __attribute__((unused)), vs_trail9State* arg3)
{
    int i;

    for (i = 0; i < arg3->trailcount; ++i) {

        vs_trail9* trail = &arg3->trails[i];

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

            speed +=
                ((0x06000000 - (trail->splineProgress * 2)) / (currentStep * currentStep))
                - ((speed * 2) / currentStep);
            trail->speed = speed;
            trail->splineProgress += speed;
            trail->currentSplineSample = (trail->currentSplineSample + 1) % 9;

            vs_battle_splineInterpolate(&trail->splinePoints[0], &trail->splinePoints[1],
                &trail->splinePoints[2], &trail->splinePoints[3],
                (trail->splineProgress >> 0xC) - ONE,
                &trail->splineSamples[trail->currentSplineSample]);

            if (trail->splineSampleCount < 9) {
                ++trail->splineSampleCount;
            }
        }
    }
}

void VS_TRAIL_RENDER_FUNCTION(func_800FA098_arg0* arg0, func_800FA098_arg1* arg1,
    D_800F53B8_t* arg2, vs_trail9State* arg3)
{
    vs_trail9Prim quad;
    DVECTOR screen[10];
    int depths[10];
    int angles[8];
    CVECTOR color;
    int _[10] __attribute__((unused));
    DVECTOR* points;
    int i;
    int j;
    pFileTexture* texture;

    vs_battle_lerpSvector(arg0->unk34[4],
        vs_battle_sampleCurve(arg0->unkE, arg3->curveSampleDistance), &arg1->unk108);

    if (arg0->rCurve != 0) {
        j = vs_battle_sampleCurve(arg0->rCurve, arg3->curveSampleDistance) * 2;
        color.r = j <= 255 ? j : 255;
    } else {
        color.r = 128;
    }

    if (arg0->gCurve != 0) {
        j = vs_battle_sampleCurve(arg0->gCurve, arg3->curveSampleDistance) * 2;
        color.g = j <= 255 ? j : 255;
    } else {
        color.g = 128;
    }

    if (arg0->bCurve != 0) {
        j = vs_battle_sampleCurve(arg0->bCurve, arg3->curveSampleDistance) * 2;
        color.b = j <= 255 ? j : 255;
    } else {
        color.b = 128;
    }

    color.cd = primPolyGT4SemiTrans;

    if (arg1->flags & 0x20000) {
        SetRotMatrix(&arg2->unk1C[arg0->unkC8].view);
        SetTransMatrix(&arg2->unk1C[arg0->unkC8].view);
    } else {
        SetRotMatrix(&vs_scratch.viewMatrix);
        SetTransMatrix(&vs_scratch.viewMatrix);
    }

    func_800D6D24(&arg3->unkC);

    texture = &D_800F569C->textures[arg3->unkC.textureInfo->dataIndex];

    for (i = 0; i < arg3->trailcount; ++i) {
        vs_trail9* trail = &arg3->trails[i];
        SVECTOR* samples = trail->splineSamples;
        vs_trail9Prim* prim;
        int dx;
        int dy;
        int sample;
        int vTop;
        int vBottom;

        if (trail->splineSampleCount < 2) {
            continue;
        }

        sample = trail->currentSplineSample;

        for (j = 0; j < trail->splineSampleCount; ++j) {
            gte_ldv0(&samples[sample]);
            gte_rtps2();
            gte_stsxy(&screen[j]);
            gte_stszotz(&depths[j]);
            sample = (sample + 8) % 9;
        }

        for (j = 0; j < (trail->splineSampleCount - 1); ++j) {
            DVECTOR* p = &screen[j];
            angles[j] = ratan2(p[1].vy - p[0].vy, p[1].vx - p[0].vx);
            angles[j] -= ONE / 4;
        }

        sample = arg1->unk108.vx / 2;
        dx = (rcos(angles[0]) * sample) >> 0xC;
        dy = (rsin(angles[0]) * sample) >> 0xC;
        points = screen;
        setXY0(&quad.poly, points[0].vx + dx, points[0].vy + dy);
        quad.poly.x2 = points[0].vx - dx;
        quad.poly.y2 = points[0].vy - dy;

        quad.poly.u0 = quad.poly.u2 =
            texture->u + ((texture->w * trail->trailCollapseCounter) / 8);
        vTop = texture->v;
        vBottom = texture->v + texture->h;
        quad.poly.v0 = vTop;
        quad.poly.v2 = vBottom;
        setRGB0(&quad.poly,
            (color.r * arg3->sampledTransparencyCurve[trail->trailCollapseCounter]) >> 7,
            (color.g * arg3->sampledTransparencyCurve[trail->trailCollapseCounter]) >> 7,
            (color.b * arg3->sampledTransparencyCurve[trail->trailCollapseCounter]) >> 7);
        quad.poly.code = color.cd;

        for (j = 0; j < (trail->splineSampleCount - 2); ++j) {
            DVECTOR* point;
            int angle = (angles[j] + angles[j + 1]) / 2;

            if (((angles[j + 1] - angles[j]) + (ONE / 2 - 1)) >= (ONE - 1u)) {
                angle += ONE / 2;
            }

            dx = (rcos(angle) * sample) >> 0xC;
            dy = (rsin(angle) * sample) >> 0xC;
            point = &points[j];
            quad.poly.x1 = point[1].vx + dx;
            quad.poly.y1 = point[1].vy + dy;
            quad.poly.x3 = point[1].vx - dx;
            quad.poly.y3 = point[1].vy - dy;

            quad.poly.u1 = quad.poly.u3 =
                texture->u + ((texture->w * ((trail->trailCollapseCounter - j) - 1)) / 8);
            quad.poly.v1 = vTop;
            quad.poly.v3 = vBottom;
            quad.poly.r1 =
                ((color.r
                     * arg3
                         ->sampledTransparencyCurve[trail->trailCollapseCounter - j - 1])
                    >> 7);
            quad.poly.g1 =
                ((color.g
                     * arg3
                         ->sampledTransparencyCurve[trail->trailCollapseCounter - j - 1])
                    >> 7);
            quad.poly.b1 =
                ((color.b
                     * arg3
                         ->sampledTransparencyCurve[trail->trailCollapseCounter - j - 1])
                    >> 7);
            quad.poly.p1 = color.cd;

            dx = (depths[j] + depths[j + 1]) / 2;

            if ((dx < ONE / 2) && (vs_main_nearClip < dx)) {
                prim = vs_scratch.unk0;
                vs_scratch.unk0 = prim + 1;
                setlen(prim, 0xE);
                prim->poly.code = primPolyGT4SemiTrans;
                prim->poly.tag = _get_mode(0, 0, 0);
                prim->drawMode = _get_mode(0, 1, 0);
                prim->tag = (((u_long*)vs_scratch.unk4)[dx] & 0xFFFFFF) | 0x0E000000;
                ((u_long*)vs_scratch.unk4)[dx] =
                    (((u_long*)vs_scratch.unk4)[dx] & 0xFF000000)
                    | ((u_long)prim & 0xFFFFFF);
                *(int*)&prim->poly.r0 = *(int*)&quad.poly.r0;
                *(int*)&prim->poly.r1 = *(int*)&quad.poly.r1;
                *(int*)&prim->poly.r2 = *(int*)&quad.poly.r0;
                *(int*)&prim->poly.r3 = *(int*)&quad.poly.r1;
                *(int*)&prim->poly.x0 = *(int*)&quad.poly.x0;
                *(int*)&prim->poly.x1 = *(int*)&quad.poly.x1;
                *(int*)&prim->poly.x2 = *(int*)&quad.poly.x2;
                *(int*)&prim->poly.x3 = *(int*)&quad.poly.x3;
                *(short*)&prim->poly.u0 = *(short*)&quad.poly.u0;
                *(short*)&prim->poly.u1 = *(short*)&quad.poly.u1;
                *(short*)&prim->poly.u2 = *(short*)&quad.poly.u2;
                *(short*)&prim->poly.u3 = *(short*)&quad.poly.u3;
                prim->poly.tpage = texture->tpage;
                prim->poly.clut = texture->clut;
            }

            *(int*)&quad.poly.x0 = *(int*)&quad.poly.x1;
            *(int*)&quad.poly.x2 = *(int*)&quad.poly.x3;
            *(short*)&quad.poly.u0 = *(short*)&quad.poly.u1;
            *(short*)&quad.poly.u2 = *(short*)&quad.poly.u3;
            *(int*)&quad.poly.r0 = *(int*)&quad.poly.r1;
        }

        dx = (rcos(angles[j]) * sample) >> 0xC;
        dy = (rsin(angles[j]) * sample) >> 0xC;
        quad.poly.x1 = ((u_short*)points)[j * 2 + 2] + dx;
        quad.poly.y1 = ((u_short*)points)[j * 2 + 3] + dy;
        quad.poly.x3 = ((u_short*)points)[j * 2 + 2] - dx;
        quad.poly.y3 = ((u_short*)points)[j * 2 + 3] - dy;
        quad.poly.u1 = quad.poly.u3 = texture->u;
        quad.poly.v1 = vTop;
        quad.poly.v3 = vBottom;
        setRGB1(&quad.poly, (color.r * arg3->sampledTransparencyCurve[0]) >> 7,
            (color.g * arg3->sampledTransparencyCurve[0]) >> 7,
            (color.b * arg3->sampledTransparencyCurve[0]) >> 7);

        dx = (depths[j] + depths[j + 1]) / 2;

        if ((dx >= ONE / 2) || (dx <= vs_main_nearClip)) {
            continue;
        }

        prim = vs_scratch.unk0;
        vs_scratch.unk0 = prim + 1;
        setlen(prim, 0xE);
        setcode(&prim->poly, primPolyGT4SemiTrans);
        prim->poly.tag = _get_mode(0, 0, 0);
        prim->drawMode = _get_mode(0, 1, 0);
        prim->tag = (((u_long*)vs_scratch.unk4)[dx] & 0xFFFFFF) | 0x0E000000;
        ((u_long*)vs_scratch.unk4)[dx] =
            (((u_long*)vs_scratch.unk4)[dx] & 0xFF000000) | ((u_long)prim & 0xFFFFFF);
        *(int*)&prim->poly.r0 = *(int*)&quad.poly.r0;
        *(int*)&prim->poly.r1 = *(int*)&quad.poly.r1;
        *(int*)&prim->poly.r2 = *(int*)&quad.poly.r0;
        *(int*)&prim->poly.r3 = *(int*)&quad.poly.r1;
        *(int*)&prim->poly.x0 = *(int*)&quad.poly.x0;
        *(int*)&prim->poly.x1 = *(int*)&quad.poly.x1;
        *(int*)&prim->poly.x2 = *(int*)&quad.poly.x2;
        *(int*)&prim->poly.x3 = *(int*)&quad.poly.x3;
        *(short*)&prim->poly.u0 = *(short*)&quad.poly.u0;
        *(short*)&prim->poly.u1 = *(short*)&quad.poly.u1;
        *(short*)&prim->poly.u2 = *(short*)&quad.poly.u2;
        *(short*)&prim->poly.u3 = *(short*)&quad.poly.u3;
        prim->poly.tpage = texture->tpage;
        prim->poly.clut = texture->clut;
    }
}

int VS_TRAIL_DISPATCH_FUNCTION(func_800D4910_t* arg0, u_int arg1, int arg2)
{
    func_800D2904_t child;
    func_800FA098_arg0* effect;
    int trail;
    int j;
    vs_trail9State* newState;

    func_800FA098_arg1* scratch = (func_800FA098_arg1*)0x1F8001D0;
    vs_trail9State* state = arg0->unk8;
    D_800F53B8_t* battle = D_800F53BC;
    int alive = 1;

    switch (arg1) {
    case 1:
        newState = vs_main_allocHeapR(sizeof *newState + 12);
        arg0->unk8 = newState;
        newState->unk1 = arg2 >> 8;
        newState->unk0 = arg2;
        newState->curveSampleDistance = 0;
        effect = &D_800F569C->block5Data->unk4[newState->unk1];
        trail = effect->unkC0[0];

        if (trail > 8) {
            trail = 8;
        }

        newState->trails = vs_main_allocHeapR(sizeof *newState->trails * trail);
        newState->trailcount = trail;
        newState->unk3 = 0;

        if (effect->transparencyCurve != 0) {

            // bad var reuse, trail = length of curve
            trail = D_800F569C->curveBlock->curveSizes[effect->transparencyCurve];

            if (trail > 1) {
                --trail;
            }

            for (j = 0; j < 9; ++j) {
                newState->sampledTransparencyCurve[j] =
                    D_800F569C->curves[effect->transparencyCurve][(j * trail) / 8];
            }

        } else {
            for (j = 0; j < 9; ++j) {
                newState->sampledTransparencyCurve[j] = 128;
            }
        }

        func_800D6CCC((int*)&newState->unkC);
        func_800D6CF0(&newState->unkC, effect->unk1, effect->unk0);

        break;

    case 2:
        effect = &D_800F569C->block5Data->unk4[state->unk1];
        scratch->flags = effect->flags;

        if (state->unk3 == 0) {
            VS_TRAIL_ORIGIN_FUNCTION(effect, scratch, battle, state);
            VS_TRAIL_TARGET_FUNCTION(effect, scratch, battle, state);
            VS_TRAIL_CONTROL_FUNCTION(effect, scratch, battle, state);
            VS_TRAIL_INIT_FUNCTION(effect, scratch, battle, state);
            state->unk3 = 1;
        }

        VS_TRAIL_UPDATE_FUNCTION(effect, scratch, battle, state);
        VS_TRAIL_RENDER_FUNCTION(effect, scratch, battle, state);

        if (effect->unk3 != 0) {
            for (trail = 0; trail < state->trailcount; ++trail) {

                child.unk60 = 0;

                if (effect->flags & 0x20000) {

                    SetRotMatrix(&battle->unk1C[effect->unkC8].world);
                    SetTransMatrix(&battle->unk1C[effect->unkC8].world);

                    setVector(&scratch->unk2C,
                        state->trails[trail]
                            .splineSamples[state->trails[trail].currentSplineSample]
                            .vx,
                        state->trails[trail]
                            .splineSamples[state->trails[trail].currentSplineSample]
                            .vy,
                        state->trails[trail]
                            .splineSamples[state->trails[trail].currentSplineSample]
                            .vz);

                    gte_ldv0(&scratch->unk2C);
                    gte_rtv0tr2();
                    gte_stlvnl(&scratch->unk34);

                    setVector(&child.motion.position, scratch->unk34.vx * ONE,
                        scratch->unk34.vy * ONE, scratch->unk34.vz * ONE);
                } else {
                    setVector(&child.motion.position,
                        state->trails[trail]
                                .splineSamples[state->trails[trail].currentSplineSample]
                                .vx
                            * ONE,
                        state->trails[trail]
                                .splineSamples[state->trails[trail].currentSplineSample]
                                .vy
                            * ONE,
                        state->trails[trail]
                                .splineSamples[state->trails[trail].currentSplineSample]
                                .vz
                            * ONE);
                }

                func_800D2ADC(battle, effect->unk3 - 1, 0, 0, &child);
            }
        }

        ++state->curveSampleDistance;

        if (state->unk0 != 0) {
            --state->unk0;

            if (!state->unk0) {
                vs_main_freeHeapR(state->trails);
                alive = 0;
            }
        }
        break;

    case 3:
        state->unk0 = 1;
        break;

    case 4:
        vs_main_freeHeapR(state->trails);
        alive = 0;
        break;
    }

    return alive;
}

#undef VS_TRAIL_ORIGIN_FUNCTION
#undef VS_TRAIL_TARGET_FUNCTION
#undef VS_TRAIL_CONTROL_FUNCTION
#undef VS_TRAIL_INIT_FUNCTION
#undef VS_TRAIL_UPDATE_FUNCTION
#undef VS_TRAIL_RENDER_FUNCTION
#undef VS_TRAIL_DISPATCH_FUNCTION
#undef VS_TRAIL9_CORNER_STATE
