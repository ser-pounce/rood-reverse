/* Shared textured particle ribbon renderer. Each particle is a spline through its four
 * control points, drawn as a strip of eight semi-transparent textured quads. The overlay
 * supplies the entry point. */

#include "src/BATTLE/BATTLE.PRG/5BF94.h"
#include "src/SLUS_010.40/main.h"
#include "vs_inline_c.h"
#include "gpu.h"
#include <inline_c.h>
#include <rand.h>

#ifndef VS_CAT
#define VS_CAT_(a, b) a##b
#define VS_CAT(a, b) VS_CAT_(a, b)
#endif

#ifndef VS_PARTICLE_RENDER_FUNCTION
#define VS_PARTICLE_RENDER_FUNCTION VS_CAT(VS_PARTICLE_DISPATCH_FUNCTION, _render)
#endif

typedef struct {
    u_long tag;
    POLY_GT4 poly;
    u_long drawMode;
} vs_particlePrim;

void VS_PARTICLE_RENDER_FUNCTION(func_800FA098_arg0* effect, func_800FA098_arg1* scratch,
    D_800F53B8_t* battle, func_800FA098_arg3* state)
{
    vs_particlePrim quad;
    DVECTOR screen[10];
    int depths[10];
    int angles[8];
    CVECTOR color;
    int samples[10];
    DVECTOR* screenStart;
    int particle;
    int segment;
    pFileTexture* texture;
    int width =
        func_800CFE1C(effect->unk30, vs_battle_sampleCurve(effect->unk17, state->unkC));

    if (width == 0) {
        width = 1;
    }

    vs_battle_lerpSvector(effect->unk34[4],
        vs_battle_sampleCurve(effect->unkE, state->unkC), &scratch->unk108);

    if (effect->rCurve != 0) {
        segment = vs_battle_sampleCurve(effect->rCurve, state->unkC) * 2;
        color.r = segment <= 255 ? segment : 255;
    } else {
        color.r = 128;
    }

    if (effect->gCurve != 0) {
        segment = vs_battle_sampleCurve(effect->gCurve, state->unkC) * 2;
        color.g = segment <= 255 ? segment : 255;
    } else {
        color.g = 128;
    }

    if (effect->bCurve != 0) {
        segment = vs_battle_sampleCurve(effect->bCurve, state->unkC) * 2;
        color.b = segment <= 255 ? segment : 255;
    } else {
        color.b = 128;
    }

    color.cd = primPolyGT4SemiTrans;

    if (scratch->flags & 0x20000) {
        SetRotMatrix(&battle->unk1C[effect->unkC8].view);
        SetTransMatrix(&battle->unk1C[effect->unkC8].view);
    } else {
        SetRotMatrix(&vs_scratch.viewMatrix);
        SetTransMatrix(&vs_scratch.viewMatrix);
    }

    func_800D6D24(&state->unk10);
    texture = &D_800F569C->textures[state->unk10.textureInfo->dataIndex];

    for (particle = 0; particle < state->unk2; ++particle) {
        int topV;
        int bottomV;
        SVECTOR* points = &state->unk4[particle * 4];
        int offsetY;
        int offsetX;
        int value;
        vs_particlePrim* prim;
        DVECTOR* point;

        gte_ldv0(points);
        gte_rtps2();
        gte_stsxy(&screen[0]);
        gte_stszotz(&depths[0]);
        samples[0] = 0;

        for (segment = 1; segment < 8; ++segment) {
            samples[segment] = segment * (ONE * 3 / 8) + rand() % width - width / 2;
            vs_battle_splineInterpolate(points, points + 1, points + 2, points + 3,
                samples[segment] - ONE, &scratch->unk2C);
            gte_ldv0(&scratch->unk2C);
            gte_rtps2();
            gte_stsxy(&screen[segment]);
            gte_stszotz(&depths[segment]);
        }

        gte_ldv0(points + 3);
        gte_rtps2();
        gte_stsxy(&screen[segment]);
        gte_stszotz(&depths[segment]);
        samples[segment] = ONE * 3;

        for (segment = 0; segment < 8; ++segment) {
            point = &screen[segment];
            angles[segment] =
                ratan2(point[1].vy - point[0].vy, point[1].vx - point[0].vx) - ONE / 4;
        }

        width = scratch->unk108.vx / 2;
        screenStart = screen;

        if (scratch->unk108.vy != 0) {
            width += (rand() % scratch->unk108.vy) / 2;
        }

        offsetX = (rcos(angles[0]) * width) >> 12;
        offsetY = (rsin(angles[0]) * width) >> 12;
        quad.poly.x0 = screenStart[0].vx + offsetX;
        quad.poly.y0 = screenStart[0].vy + offsetY;
        quad.poly.x2 = screenStart[0].vx - offsetX;
        quad.poly.y2 = screenStart[0].vy - offsetY;
        quad.poly.u0 = quad.poly.u2 = texture->u;
        topV = texture->v;
        bottomV = topV + texture->h;
        quad.poly.v0 = topV;
        quad.poly.v2 = bottomV;

        for (segment = 0; segment < 7; ++segment) {
            width = scratch->unk108.vx / 2;

            if (scratch->unk108.vy != 0) {
                width += (rand() % scratch->unk108.vy) / 2;
            }

            value = (angles[segment] + angles[segment + 1]) / 2;
            offsetX = (rcos(value) * width) >> 12;
            offsetY = (rsin(value) * width) >> 12;
            point = &screenStart[segment];
            quad.poly.x1 = point[1].vx + offsetX;
            quad.poly.y1 = point[1].vy + offsetY;
            quad.poly.x3 = point[1].vx - offsetX;
            quad.poly.y3 = point[1].vy - offsetY;
            quad.poly.u1 = quad.poly.u3 =
                texture->u + texture->w * samples[segment + 1] / (ONE * 3);
            quad.poly.v1 = topV;
            quad.poly.v3 = bottomV;
            value = (depths[segment] + depths[segment + 1]) / 2;

            if ((value < ONE / 2) && (vs_main_nearClip < value)) {
                switch (effect->unk34[5][0]) {
                case 0:
                    break;

                case 1:
                    value = 2046;
                    break;

                case 2:
                    value = -15;
                    break;

                case 3:
                    value = -13;
                    break;

                case 4:
                    value = -11;
                    break;

                case 5:
                    if (vs_main_nearClip < value - 16) {
                        value -= 16;
                    }
                    break;
                }

                prim = vs_scratch.unk0;
                vs_scratch.unk0 = prim + 1;
                setlen(prim, 14);
                prim->poly.code = primPolyGT4SemiTrans;
                prim->poly.tag = _get_mode(0, 0, 0);
                prim->drawMode = _get_mode(0, 1, 0);
                prim->tag = (((u_long*)vs_scratch.unk4)[value] & 0xFFFFFF) | 0x0E000000;
                ((u_long*)vs_scratch.unk4)[value] =
                    (((u_long*)vs_scratch.unk4)[value] & 0xFF000000)
                    | ((u_long)prim & 0xFFFFFF);
                *(int*)&prim->poly.r0 = *(int*)&color;
                *(int*)&prim->poly.r1 = *(int*)&color;
                *(int*)&prim->poly.r2 = *(int*)&color;
                *(int*)&prim->poly.r3 = *(int*)&color;
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
        }

        width = scratch->unk108.vx / 2;

        if (scratch->unk108.vy != 0) {
            width += (rand() % scratch->unk108.vy) / 2;
        }

        offsetX = (rcos(angles[segment]) * width) >> 12;
        offsetY = (rsin(angles[segment]) * width) >> 12;
        quad.poly.x1 = ((u_short*)screenStart)[segment * 2 + 2] + offsetX;
        quad.poly.y1 = ((u_short*)screenStart)[segment * 2 + 3] + offsetY;
        quad.poly.x3 = ((u_short*)screenStart)[segment * 2 + 2] - offsetX;
        quad.poly.y3 = ((u_short*)screenStart)[segment * 2 + 3] - offsetY;
        quad.poly.u1 = quad.poly.u3 = texture->u + texture->w;
        quad.poly.v1 = topV;
        quad.poly.v3 = bottomV;
        value = (depths[segment] + depths[segment + 1]) / 2;

        if ((value >= ONE / 2) || (value <= vs_main_nearClip)) {
            continue;
        }

        switch (effect->unk34[5][0]) {
        case 0:
            break;

        case 1:
            value = 2046;
            break;

        case 2:
            value = -15;
            break;

        case 3:
            value = -13;
            break;

        case 4:
            value = -11;
            break;

        case 5:
            if (vs_main_nearClip < value - 16) {
                value -= 16;
            }
            break;
        }

        prim = vs_scratch.unk0;
        vs_scratch.unk0 = prim + 1;
        setlen(prim, 14);
        prim->poly.code = primPolyGT4SemiTrans;
        prim->poly.tag = _get_mode(0, 0, 0);
        prim->drawMode = _get_mode(0, 1, 0);
        prim->tag = (((u_long*)vs_scratch.unk4)[value] & 0xFFFFFF) | 0x0E000000;
        ((u_long*)vs_scratch.unk4)[value] =
            (((u_long*)vs_scratch.unk4)[value] & 0xFF000000) | ((u_long)prim & 0xFFFFFF);
        *(int*)&prim->poly.r0 = *(int*)&color;
        *(int*)&prim->poly.r1 = *(int*)&color;
        *(int*)&prim->poly.r2 = *(int*)&color;
        *(int*)&prim->poly.r3 = *(int*)&color;
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
