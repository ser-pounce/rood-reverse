/* Shared untextured spline-particle line renderer. */
#include "gpu.h"
#ifndef VS_PARTICLE_LINE_TYPE
#define VS_PARTICLE_LINE_TYPE
typedef struct {
    u_char unk0, unk1, unk2, unk3;
    LINE_F2 line;
    int drawMode;
} vs_particleLine;
void func_800CFAAC(vs_particleLine*);
#endif

void VS_PARTICLE_RENDER_FUNCTION(func_800FA098_arg0* arg0, func_800FA098_arg1* arg1,
    D_800F53B8_t* arg2, func_800FA098_arg3* arg3)
{
    int screenPoints[10];
    int depths[10];
    CVECTOR color;
    int blendMode = (((u_int*)arg0)[1] >> 26) & 3;
    int particleIndex;
    int segment;
    int renderSegment;
    int width;
    int depth;
    int screenOffset;
    int* endpoint;
    u_int endpointStep;
    SVECTOR* controlPoints;
    vs_particleLine* prim;
    width = func_800CFE1C(arg0->unk30, vs_battle_sampleCurve(arg0->unk17, arg3->unkC));
    if (!width) {
        width = 1;
    }

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

    color.cd = 0x42;

    if (arg1->flags & 0x20000) {
        SetRotMatrix(&arg2->unk1C[arg0->unkC8].unk58);
        SetTransMatrix(&arg2->unk1C[arg0->unkC8].unk58);
    } else {
        SetRotMatrix(&vs_scratch.viewMatrix);
        SetTransMatrix(&vs_scratch.viewMatrix);
    }

    for (particleIndex = 0; particleIndex < arg3->unk2; ++particleIndex) {
        controlPoints = &arg3->unk4[particleIndex * 4];
        gte_ldv0(controlPoints);
        gte_rtps2();
        gte_stsxy(&screenPoints[0]);
        gte_stszotz(&depths[0]);
        for (segment = 1; segment < 8; ++segment) {
            vs_battle_splineInterpolate(controlPoints, controlPoints + 1,
                controlPoints + 2, controlPoints + 3,
                (segment * 0x600) - 0x1000 + rand() % width - width / 2, &arg1->unk2C);
            gte_ldv0(&arg1->unk2C);
            gte_rtps2();
            gte_stsxy(&screenPoints[segment]);
            gte_stszotz(&depths[segment]);
        }
        gte_ldv0(controlPoints + 3);
        gte_rtps2();
        gte_stsxy(&screenPoints[segment]);
        gte_stszotz(&depths[segment]);
        for (renderSegment = 0; renderSegment < 8; ++renderSegment) {
            depth = (depths[renderSegment] + depths[renderSegment + 1]) / 2;
            if (depth < 0x800 && vs_main_nearClip < depth) {
                switch (arg0->unk34[5][0]) {
                case 0:
                    break;
                case 1:
                    depth = 0x7FE;
                    break;
                case 2:
                    depth = -15;
                    break;
                case 3:
                    depth = -13;
                    break;
                case 4:
                    depth = -11;
                    break;
                case 5:
                    if (vs_main_nearClip < depth - 16) {
                        depth -= 16;
                    }
                    break;
                }
                prim = vs_scratch.unk0;
                vs_scratch.unk0 = prim + 1;
                prim->unk3 = 5;
                prim->line.code = 0x42;
                prim->line.tag = 0xE1000000 | (blendMode << 5);
                prim->drawMode = 0xE1000200;
                *(int*)&prim->unk0 =
                    (((u_long*)vs_scratch.unk4)[depth] & 0xFFFFFF) | 0x05000000;
                endpointStep = 1;
                ((u_long*)vs_scratch.unk4)[depth] =
                    (((u_long*)vs_scratch.unk4)[depth] & 0xFF000000)
                    | ((u_long)prim & 0xFFFFFF);
                *(int*)&prim->line.r0 = *(int*)&color;
                screenOffset = renderSegment * sizeof(screenPoints[0]);
                *(int*)&prim->line.x0 = *(int*)((char*)screenPoints + screenOffset);
                endpoint = &screenPoints[renderSegment + endpointStep];
                *(int*)&prim->line.x1 = *endpoint;
                func_800CFAAC(prim);
            }
        }
    }
}
