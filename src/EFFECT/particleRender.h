/* Shared segmented particle ribbon renderer. */
#include "gpu.h"

#ifndef VS_PARTICLE_PRIM_TYPE
#define VS_PARTICLE_PRIM_TYPE
typedef struct {
    u_char unk0;
    u_char unk1;
    u_char unk2;
    u_char unk3;
    POLY_GT4 unk4;
    int unk38;
} vs_particlePrim;

#endif

void VS_PARTICLE_RENDER_FUNCTION(func_800FA098_arg0* arg0, func_800FA098_arg1* arg1,
    D_800F53B8_t* arg2, func_800FA098_arg3* arg3)
{
    vs_particlePrim quad;
    DVECTOR screenPoints[10];
    int depths[10];
    int angles[8];
    CVECTOR color;
    int curveSamples[10];
    DVECTOR* screenStart;
    int particleIndex;
    int topV;
    int bottomV;
    SVECTOR* controlPoints;
    int offsetY;
    int offsetX;
    int angleOrDepth;
    int segment;
    vs_particlePrim* prim;
    pFileBlock1Data* texture;
    DVECTOR* point;
    int width;

    width = func_800CFE1C(arg0->unk30, vs_battle_sampleCurve(arg0->unk17, arg3->unkC));
    if (!width)
        width = 1;

    vs_battle_lerpSvector(
        arg0->unk34[4], vs_battle_sampleCurve(arg0->unkE, arg3->unkC), &arg1->unk108);

    if (arg0->rCurve != 0) {
        segment = vs_battle_sampleCurve(arg0->rCurve, arg3->unkC) * 2;
        color.r = segment <= 255 ? segment : 255;
    } else {
        color.r = 128;
    }

    if (arg0->gCurve != 0) {
        segment = vs_battle_sampleCurve(arg0->gCurve, arg3->unkC) * 2;
        color.g = segment <= 255 ? segment : 255;
    } else {
        color.g = 128;
    }

    if (arg0->bCurve != 0) {
        segment = vs_battle_sampleCurve(arg0->bCurve, arg3->unkC) * 2;
        color.b = segment <= 255 ? segment : 255;
    } else {
        color.b = 128;
    }

    color.cd = primPolyGT4SemiTrans;

    if (arg1->flags & 0x20000) {
        SetRotMatrix(&arg2->unk1C[arg0->unkC8].unk58);
        SetTransMatrix(&arg2->unk1C[arg0->unkC8].unk58);
    } else {
        SetRotMatrix(&vs_scratch.viewMatrix);
        SetTransMatrix(&vs_scratch.viewMatrix);
    }

    func_800D6D24(&arg3->unk10);

    texture = &D_800F569C->block1Data[arg3->unk10.unk1C->dataIndex];

    for (particleIndex = 0; particleIndex < arg3->unk2; ++particleIndex) {

        controlPoints = &arg3->unk4[particleIndex * 4];
        gte_ldv0(controlPoints);
        gte_rtps2();
        gte_stsxy(&screenPoints[0]);
        gte_stszotz(&depths[0]);
        curveSamples[0] = 0;
        for (segment = 1; segment < 8; ++segment) {
            curveSamples[segment] = segment * 0x600 + rand() % width - width / 2;
            vs_battle_splineInterpolate(controlPoints, controlPoints + 1,
                controlPoints + 2, controlPoints + 3, curveSamples[segment] - 0x1000,
                &arg1->unk2C);
            gte_ldv0(&arg1->unk2C);
            gte_rtps2();
            gte_stsxy(&screenPoints[segment]);
            gte_stszotz(&depths[segment]);
        }
        gte_ldv0(controlPoints + 3);
        gte_rtps2();
        gte_stsxy(&screenPoints[segment]);
        gte_stszotz(&depths[segment]);
        curveSamples[segment] = 0x3000;

        for (segment = 0; segment < 8; ++segment) {
            DVECTOR* p = &screenPoints[segment];
            angles[segment] = ratan2(p[1].vy - p[0].vy, p[1].vx - p[0].vx);
            angles[segment] -= 0x400;
        }

        width = arg1->unk108.vx / 2;
        screenStart = screenPoints;
        if (arg1->unk108.vy)
            width += (rand() % arg1->unk108.vy) / 2;
        offsetX = (rcos(angles[0]) * width) >> 0xC;
        offsetY = (rsin(angles[0]) * width) >> 0xC;
        quad.unk4.x0 = screenStart[0].vx + offsetX;
        quad.unk4.y0 = screenStart[0].vy + offsetY;
        quad.unk4.x2 = screenStart[0].vx - offsetX;
        quad.unk4.y2 = screenStart[0].vy - offsetY;

        quad.unk4.u0 = quad.unk4.u2 = texture->u0;
        topV = texture->v0;
        bottomV = topV + texture->v1;
        quad.unk4.v0 = topV;
        quad.unk4.v2 = bottomV;
        for (segment = 0; segment < 7; ++segment) {
            width = arg1->unk108.vx / 2;
            if (arg1->unk108.vy)
                width += (rand() % arg1->unk108.vy) / 2;
            angleOrDepth = (angles[segment] + angles[segment + 1]) / 2;
            offsetX = (rcos(angleOrDepth) * width) >> 0xC;
            offsetY = (rsin(angleOrDepth) * width) >> 0xC;
            point = &screenStart[segment];
            quad.unk4.x1 = point[1].vx + offsetX;
            quad.unk4.y1 = point[1].vy + offsetY;
            quad.unk4.x3 = point[1].vx - offsetX;
            quad.unk4.y3 = point[1].vy - offsetY;

            quad.unk4.u1 = quad.unk4.u3 =
                texture->u0 + ((texture->u1 * curveSamples[segment + 1]) / 0x3000);
            quad.unk4.v1 = topV;
            quad.unk4.v3 = bottomV;
            angleOrDepth = (depths[segment] + depths[segment + 1]) / 2;

            if ((angleOrDepth < 0x800) && (vs_main_nearClip < angleOrDepth)) {
                switch (arg0->unk34[5][0]) {
                case 0:
                    break;
                case 1:
                    angleOrDepth = 0x7FE;
                    break;
                case 2:
                    angleOrDepth = -15;
                    break;
                case 3:
                    angleOrDepth = -13;
                    break;
                case 4:
                    angleOrDepth = -11;
                    break;
                case 5:
                    if (vs_main_nearClip < angleOrDepth - 16)
                        angleOrDepth -= 16;
                    break;
                }
                prim = vs_scratch.unk0;
                vs_scratch.unk0 = prim + 1;
                prim->unk3 = 0xE;
                prim->unk4.code = primPolyGT4SemiTrans;
                prim->unk4.tag = 0xE1000000;
                prim->unk38 = 0xE1000200;
                *(int*)&prim->unk0 =
                    (((u_long*)vs_scratch.unk4)[angleOrDepth] & 0xFFFFFF) | 0x0E000000;
                ((u_long*)vs_scratch.unk4)[angleOrDepth] =
                    (((u_long*)vs_scratch.unk4)[angleOrDepth] & 0xFF000000)
                    | ((u_long)prim & 0xFFFFFF);
                *(int*)&prim->unk4.r0 = *(int*)&color;
                *(int*)&prim->unk4.r1 = *(int*)&color;
                *(int*)&prim->unk4.r2 = *(int*)&color;
                *(int*)&prim->unk4.r3 = *(int*)&color;
                *(int*)&prim->unk4.x0 = *(int*)&quad.unk4.x0;
                *(int*)&prim->unk4.x1 = *(int*)&quad.unk4.x1;
                *(int*)&prim->unk4.x2 = *(int*)&quad.unk4.x2;
                *(int*)&prim->unk4.x3 = *(int*)&quad.unk4.x3;
                *(short*)&prim->unk4.u0 = *(short*)&quad.unk4.u0;
                *(short*)&prim->unk4.u1 = *(short*)&quad.unk4.u1;
                *(short*)&prim->unk4.u2 = *(short*)&quad.unk4.u2;
                *(short*)&prim->unk4.u3 = *(short*)&quad.unk4.u3;
                *(short*)&prim->unk4.tpage = texture->tpage;
                *(short*)&prim->unk4.clut = texture->clut;
            }
            *(int*)&quad.unk4.x0 = *(int*)&quad.unk4.x1;
            *(int*)&quad.unk4.x2 = *(int*)&quad.unk4.x3;
            *(short*)&quad.unk4.u0 = *(short*)&quad.unk4.u1;
            *(short*)&quad.unk4.u2 = *(short*)&quad.unk4.u3;
        }

        width = arg1->unk108.vx / 2;
        if (arg1->unk108.vy)
            width += (rand() % arg1->unk108.vy) / 2;
        offsetX = (rcos(angles[segment]) * width) >> 0xC;
        offsetY = (rsin(angles[segment]) * width) >> 0xC;
        quad.unk4.x1 = ((u_short*)screenStart)[segment * 2 + 2] + offsetX;
        quad.unk4.y1 = ((u_short*)screenStart)[segment * 2 + 3] + offsetY;
        quad.unk4.x3 = ((u_short*)screenStart)[segment * 2 + 2] - offsetX;
        quad.unk4.y3 = ((u_short*)screenStart)[segment * 2 + 3] - offsetY;
        quad.unk4.u1 = quad.unk4.u3 = texture->u0 + texture->u1;
        quad.unk4.v1 = topV;
        quad.unk4.v3 = bottomV;
        angleOrDepth = (depths[segment] + depths[segment + 1]) / 2;

        if ((angleOrDepth < 0x800) && (vs_main_nearClip < angleOrDepth)) {
            switch (arg0->unk34[5][0]) {
            case 0:
                break;
            case 1:
                angleOrDepth = 0x7FE;
                break;
            case 2:
                angleOrDepth = -15;
                break;
            case 3:
                angleOrDepth = -13;
                break;
            case 4:
                angleOrDepth = -11;
                break;
            case 5:
                if (vs_main_nearClip < angleOrDepth - 16)
                    angleOrDepth -= 16;
                break;
            }
            prim = vs_scratch.unk0;
            vs_scratch.unk0 = prim + 1;
            prim->unk3 = 0xE;
            prim->unk4.code = primPolyGT4SemiTrans;
            prim->unk4.tag = 0xE1000000;
            prim->unk38 = 0xE1000200;
            *(int*)&prim->unk0 =
                (((u_long*)vs_scratch.unk4)[angleOrDepth] & 0xFFFFFF) | 0x0E000000;
            ((u_long*)vs_scratch.unk4)[angleOrDepth] =
                (((u_long*)vs_scratch.unk4)[angleOrDepth] & 0xFF000000)
                | ((u_long)prim & 0xFFFFFF);
            *(int*)&prim->unk4.r0 = *(int*)&color;
            *(int*)&prim->unk4.r1 = *(int*)&color;
            *(int*)&prim->unk4.r2 = *(int*)&color;
            *(int*)&prim->unk4.r3 = *(int*)&color;
            *(int*)&prim->unk4.x0 = *(int*)&quad.unk4.x0;
            *(int*)&prim->unk4.x1 = *(int*)&quad.unk4.x1;
            *(int*)&prim->unk4.x2 = *(int*)&quad.unk4.x2;
            *(int*)&prim->unk4.x3 = *(int*)&quad.unk4.x3;
            *(short*)&prim->unk4.u0 = *(short*)&quad.unk4.u0;
            *(short*)&prim->unk4.u1 = *(short*)&quad.unk4.u1;
            *(short*)&prim->unk4.u2 = *(short*)&quad.unk4.u2;
            *(short*)&prim->unk4.u3 = *(short*)&quad.unk4.u3;
            *(short*)&prim->unk4.tpage = texture->tpage;
            *(short*)&prim->unk4.clut = texture->clut;
        }
    }
}
