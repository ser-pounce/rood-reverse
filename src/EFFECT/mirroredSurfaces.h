/* Shared nine-row, sixteen-column surface mirrored about its middle row, with a color
 * factor per row. The texture spans the whole surface once unless the overlay defines
 * VS_MIRROR_SURFACE_REPEAT, in which case it repeats every four columns. The overlay
 * supplies its entry point and vertex table. */

#include "src/BATTLE/BATTLE.PRG/5BF94.h"
#include "src/SLUS_010.40/32154.h"
#include "vs_inline_c.h"
#include "gpu.h"
#include <inline_c.h>

#ifdef VS_MIRROR_SURFACE_REPEAT
#define VS_MIRROR_SURFACE_TEXTURE_COLUMNS 4
#define VS_MIRROR_SURFACE_TEXTURE_COLUMN(column) ((column) & 3)
#else
#define VS_MIRROR_SURFACE_TEXTURE_COLUMNS 16
#define VS_MIRROR_SURFACE_TEXTURE_COLUMN(column) (column)
#endif

typedef struct {
    u_char lifetime;
    u_char effect;
    short pad;
    int radius;
    int radiusSpeed;
    int height;
    int heightSpeed;
    int age;
    int factors[9];
    func_800D6CF_t texture;
} vs_mirrorSurfaceState;
typedef struct {
    int tag;
    POLY_GT4 poly;
    int drawMode;
} vs_mirrorSurfacePrim;

extern SVECTOR VS_SURFACE_VERTICES[5][16];

int VS_MIRROR_SURFACE_FUNCTION(func_800D4910_t* arg0, u_int arg1, int arg2)
{
    SVECTOR vertices[9][16];
    int screen[9][16];
    int depths[9][16];
    CVECTOR colors[9];
    u_char u[VS_MIRROR_SURFACE_TEXTURE_COLUMNS + 1];
    u_char v[9];
    D_800F53B8_t* battle;
    int alive;
    int heightStep;
    int row;
    int column;
    int radiusStep;
    int radiusValue;
    int heightValue;
    int sample;
    int curveIndex;
    int initIndex;
    vs_mirrorSurfaceState* state;
    func_800FA098_arg1* scratch = (func_800FA098_arg1*)0x1F8001D0;
    func_800FA098_arg0* effect;
    MATRIX* actorMatrix;
    pFileTexture* texture;

    alive = 1;
    state = arg0->unk8;
    battle = D_800F53BC;

    switch (arg1) {
    case 1:
        state = vs_main_allocHeapR(sizeof *state);
        arg0->unk8 = state;
        state->effect = arg2 >> 8;
        state->lifetime = arg2;
        state->radiusSpeed = 0;
        state->radius = 0;
        state->heightSpeed = 0;
        state->height = 0;
        state->age = 0;
        effect = &D_800F569C->block5Data->unk4[state->effect];
        curveIndex = effect->transparencyCurve;

        if (curveIndex) {
            sample = D_800F569C->curveBlock->curveSizes[curveIndex];

            if (sample >= 2) {
                --sample;
            }

            for (initIndex = 0; initIndex < 9; ++initIndex) {
                state->factors[initIndex] =
                    D_800F569C->curves[effect->transparencyCurve][sample * initIndex / 8]
                    * 2;

                if (state->factors[initIndex] == 256) {
                    state->factors[initIndex] = 255;
                }
            }
        } else {
            int maxFactor = 255;

            for (initIndex = 8; initIndex >= 0; --initIndex) {
                state->factors[initIndex] = maxFactor;
            }
        }

        func_800D6CCC((int*)&state->texture);
        func_800D6CF0(&state->texture, effect->unkCA, effect->unkCB);
        break;

    case 2:
        effect = &D_800F569C->block5Data->unk4[state->effect];
        scratch->flags = effect->flags;
        actorMatrix = &battle->unk1C[effect->unkC8].world;
        vs_battle_lerpVector(effect->unk18,
            vs_battle_sampleCurve(effect->unk8, state->age), &scratch->unk98);

        switch (scratch->flags & 7) {
        case 0:
            break;

        case 1:
            vs_battle_addVecToSvec(&scratch->unk98, D_800F5310, &scratch->unk98);
            break;

        case 2:
            applyVector(&scratch->unk98, actorMatrix->t[0], actorMatrix->t[1],
                actorMatrix->t[2], +=);
            break;
        }

        vs_battle_lerpVector(effect->unk24,
            vs_battle_sampleCurve(effect->unk9, state->age), &scratch->unkA8);
        sample = vs_battle_sampleCurve(effect->unkD, state->age);
        vs_battle_lerpSvector(effect->unk34[2], sample, &scratch->unkF8);
        vs_battle_lerpSvector(effect->unk34[3], sample, &scratch->unk100);
        sample = vs_battle_sampleCurve(effect->unkE, state->age);
        vs_battle_lerpSvector(effect->unk34[4], sample, &scratch->unk108);
        vs_battle_lerpSvector(effect->unk34[5], sample, &scratch->unk110);
        vs_battle_lerpVector(effect->unk34[1],
            vs_battle_sampleCurve(effect->unkB, state->age), &scratch->unkC8);
        vs_battle_lerp2DVector(effect->unk94[2],
            vs_battle_sampleCurve(effect->unkC, state->age), scratch->unk118);
        state->heightSpeed += scratch->unk108.vy;
        state->height += scratch->unkF8.vy + state->heightSpeed;
        heightValue = state->height + scratch->unkA8.vy;
        state->radiusSpeed += scratch->unk108.vx;
        state->radius += scratch->unkF8.vx + state->radiusSpeed;
        radiusValue = state->radius + scratch->unkA8.vx;
        heightStep = 0;
        radiusStep = 0;

        for (row = 0; row < 9; ++row) {
            if (row < 5) {
                for (column = 0; column < 16; ++column) {
                    vertices[row][column].vx =
                        scratch->unk98.vx
                        + ((VS_SURFACE_VERTICES[4 - row][column].vx * radiusValue) >> 12);
                    vertices[row][column].vz =
                        scratch->unk98.vz
                        + ((VS_SURFACE_VERTICES[4 - row][column].vz * radiusValue) >> 12);
                    vertices[row][column].vy =
                        scratch->unk98.vy
                        + ((VS_SURFACE_VERTICES[4 - row][column].vy * heightValue) >> 12);
                }
            } else {
                for (column = 0; column < 16; ++column) {
                    vertices[row][column].vx =
                        scratch->unk98.vx
                        + ((VS_SURFACE_VERTICES[row - 4][column].vx * radiusValue) >> 12);
                    vertices[row][column].vz =
                        scratch->unk98.vz
                        + ((VS_SURFACE_VERTICES[row - 4][column].vz * radiusValue) >> 12);
                    vertices[row][column].vy =
                        scratch->unk98.vy
                        + ((-VS_SURFACE_VERTICES[row - 4][column].vy * heightValue)
                            >> 12);
                }
            }

            radiusStep += scratch->unk110.vx;
            radiusValue += radiusStep + scratch->unk100.vx;
            heightStep += scratch->unk110.vy;
            heightValue += heightStep + scratch->unk100.vy;

            if (effect->rCurve) {
                colors[row].r = state->factors[row]
                              * vs_battle_sampleCurve(effect->rCurve, state->age) / 128;
            } else {
                colors[row].r = state->factors[row];
            }
            if (effect->gCurve) {
                colors[row].g = state->factors[row]
                              * vs_battle_sampleCurve(effect->gCurve, state->age) / 128;
            } else {
                colors[row].g = state->factors[row];
            }
            if (effect->bCurve) {
                colors[row].b = state->factors[row]
                              * vs_battle_sampleCurve(effect->bCurve, state->age) / 128;
            } else {
                colors[row].b = state->factors[row];
            }

            colors[row].cd = primPolyGT4SemiTrans;
        }

        if (scratch->flags & 0x20000) {
            SetRotMatrix(&battle->unk1C[effect->unkC8].view);
            SetTransMatrix(&battle->unk1C[effect->unkC8].view);
        } else {
            SetRotMatrix(&vs_scratch.viewMatrix);
            SetTransMatrix(&vs_scratch.viewMatrix);
        }
        for (row = 0; row < 9; ++row) {
            for (column = 0; column < 16; ++column) {
                gte_ldv0(&vertices[row][column]);
                gte_rtps2();
                gte_stsxy(&screen[row][column]);
                gte_stszotz(&depths[row][column]);
            }
        }

        func_800D6D24(&state->texture);
        texture = &D_800F569C->textures[state->texture.textureInfo->dataIndex];

        for (sample = 0; sample < VS_MIRROR_SURFACE_TEXTURE_COLUMNS + 1; ++sample) {
            u[sample] =
                texture->u + texture->w * sample / VS_MIRROR_SURFACE_TEXTURE_COLUMNS;
        }
        for (sample = 0; sample < 9; ++sample) {
            v[sample] = texture->v + texture->h * sample / 8;
        }

        for (row = 0; row < 8; ++row) {
            int depth;
            vs_mirrorSurfacePrim* prim;

            for (column = 0; column < 15; ++column) {
                depth = (depths[row][column] + depths[row][column + 1]
                            + depths[row + 1][column] + depths[row + 1][column + 1])
                      / 4;

                if (depth >= ONE / 2 || depth <= vs_main_nearClip) {
                    continue;
                }

                prim = vs_scratch.unk0;
                vs_scratch.unk0 = prim + 1;
                prim->poly.tag = _get_mode(0, 0, 0);
                prim->drawMode = _get_mode(0, 1, 0);
                *(int*)&prim->poly.x0 = screen[row][column];
                *(int*)&prim->poly.x1 = screen[row][column + 1];
                *(int*)&prim->poly.x2 = screen[row + 1][column];
                *(int*)&prim->poly.x3 = screen[row + 1][column + 1];
                *(int*)&prim->poly.r0 = *(int*)&prim->poly.r1 = *(int*)&colors[row];
                *(int*)&prim->poly.r2 = *(int*)&prim->poly.r3 = *(int*)&colors[row + 1];
                prim->poly.u0 = prim->poly.u2 =
                    u[VS_MIRROR_SURFACE_TEXTURE_COLUMN(column)];
                prim->poly.u1 = prim->poly.u3 =
                    u[VS_MIRROR_SURFACE_TEXTURE_COLUMN(column) + 1];
                prim->poly.v0 = prim->poly.v1 = v[row];
                prim->poly.v2 = prim->poly.v3 = v[row + 1];
                prim->poly.tpage = texture->tpage;
                prim->poly.clut = texture->clut;
                prim->tag = (((u_long*)vs_scratch.unk4)[depth] & 0xFFFFFF) | 0x0E000000;
                ((u_long*)vs_scratch.unk4)[depth] =
                    (((u_long*)vs_scratch.unk4)[depth] & 0xFF000000)
                    | ((u_long)prim & 0xFFFFFF);
            }

            depth = (depths[row][15] + depths[row][0] + depths[row + 1][15]
                        + depths[row + 1][0])
                  / 4;

            if (depth >= ONE / 2 || depth <= vs_main_nearClip) {
                continue;
            }

            prim = vs_scratch.unk0;
            vs_scratch.unk0 = prim + 1;
            prim->poly.tag = _get_mode(0, 0, 0);
            prim->drawMode = _get_mode(0, 1, 0);
            *(int*)&prim->poly.x0 = screen[row][15];
            *(int*)&prim->poly.x1 = screen[row][0];
            *(int*)&prim->poly.x2 = screen[row + 1][15];
            *(int*)&prim->poly.x3 = screen[row + 1][0];
            *(int*)&prim->poly.r0 = *(int*)&prim->poly.r1 = *(int*)&colors[row];
            *(int*)&prim->poly.r2 = *(int*)&prim->poly.r3 = *(int*)&colors[row + 1];
            prim->poly.u0 = prim->poly.u2 = u[VS_MIRROR_SURFACE_TEXTURE_COLUMN(column)];
            prim->poly.u1 = prim->poly.u3 =
                u[VS_MIRROR_SURFACE_TEXTURE_COLUMN(column) + 1];
            prim->poly.v0 = prim->poly.v1 = v[row];
            prim->poly.v2 = prim->poly.v3 = v[row + 1];
            prim->poly.tpage = texture->tpage;
            prim->poly.clut = texture->clut;
            prim->tag = (((u_long*)vs_scratch.unk4)[depth] & 0xFFFFFF) | 0x0E000000;
            ((u_long*)vs_scratch.unk4)[depth] =
                (((u_long*)vs_scratch.unk4)[depth] & 0xFF000000)
                | ((u_long)prim & 0xFFFFFF);
        }

        ++state->age;

        if (state->lifetime) {
            --state->lifetime;

            if (!state->lifetime) {
                alive = 0;
            }
        }
        break;

    case 3:
        state->lifetime = 1;
        break;

    case 4:
        alive = 0;
        break;
    }

    return alive;
}
#undef VS_MIRROR_SURFACE_FUNCTION
#undef VS_SURFACE_VERTICES
#undef VS_MIRROR_SURFACE_REPEAT
#undef VS_MIRROR_SURFACE_TEXTURE_COLUMNS
#undef VS_MIRROR_SURFACE_TEXTURE_COLUMN
