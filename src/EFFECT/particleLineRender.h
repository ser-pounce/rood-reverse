/* Shared untextured particle line renderer. Each particle is a spline through its four
 * control points, drawn as eight semi-transparent flat lines. The overlay supplies the
 * entry point. */

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

void VS_PARTICLE_RENDER_FUNCTION(func_800FA098_arg0* effect, func_800FA098_arg1* scratch,
    D_800F53B8_t* battle, func_800FA098_arg3* state)
{
    int screen[10];
    int depths[10];
    CVECTOR color;
    int blendMode = effect->transparencyCurve & 3;
    int particle;
    int segment;
    int width =
        func_800CFE1C(effect->unk30, vs_battle_sampleCurve(effect->unk17, state->unkC));

    if (width == 0) {
        width = 1;
    }

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

    color.cd = primLineF2SemiTrans;

    if (scratch->flags & 0x20000) {
        SetRotMatrix(&battle->unk1C[effect->unkC8].view);
        SetTransMatrix(&battle->unk1C[effect->unkC8].view);
    } else {
        SetRotMatrix(&vs_scratch.viewMatrix);
        SetTransMatrix(&vs_scratch.viewMatrix);
    }

    for (particle = 0; particle < state->unk2; ++particle) {
        SVECTOR* points = &state->unk4[particle * 4];

        gte_ldv0(points);
        gte_rtps2();
        gte_stsxy(&screen[0]);
        gte_stszotz(&depths[0]);

        for (segment = 1; segment < 8; ++segment) {
            vs_battle_splineInterpolate(points, points + 1, points + 2, points + 3,
                segment * (ONE * 3 / 8) - ONE + rand() % width - width / 2,
                &scratch->unk2C);
            gte_ldv0(&scratch->unk2C);
            gte_rtps2();
            gte_stsxy(&screen[segment]);
            gte_stszotz(&depths[segment]);
        }

        gte_ldv0(points + 3);
        gte_rtps2();
        gte_stsxy(&screen[segment]);
        gte_stszotz(&depths[segment]);

        for (segment = 0; segment < 8; ++segment) {
            int depth = (depths[segment] + depths[segment + 1]) / 2;
            func_800CFAAC_t* prim;

            if ((depth >= ONE / 2) || (depth <= vs_main_nearClip)) {
                continue;
            }

            switch (effect->unk34[5][0]) {
            case 0:
                break;

            case 1:
                depth = 2046;
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
            setlen(prim, 5);
            prim->line.code = primLineF2SemiTrans;
            prim->line.tag = _get_mode(0, 0, blendMode << 5);
            prim->drawMode = _get_mode(0, 1, 0);
            prim->tag = (((u_long*)vs_scratch.unk4)[depth] & 0xFFFFFF) | 0x05000000;
            ((u_long*)vs_scratch.unk4)[depth] =
                (((u_long*)vs_scratch.unk4)[depth] & 0xFF000000)
                | ((u_long)prim & 0xFFFFFF);
            *(int*)&prim->line.r0 = *(int*)&color;
            *(int*)&prim->line.x0 = screen[segment];
            *(int*)&prim->line.x1 = screen[segment + 1];
            func_800CFAAC(prim);
        }
    }
}
