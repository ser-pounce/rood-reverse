/* Animated nine-by-nine textured effect grid. */
#include "common.h"
#include "src/BATTLE/BATTLE.PRG/5BF94.h"
#include "src/SLUS_010.40/main.h"
#include "vs_inline_c.h"
#include "gpu.h"
#include <inline_c.h>

typedef struct {
    u_char lifetime, effect, u, v, uScroll, vScroll;
    short tpage, clut;
    short xSpacing, xSpeed, zSpacing, zSpeed, xPhase, zPhase;
    int age;
} vs_gridState;
typedef struct {
    int tag;
    POLY_FT4 poly;
    int drawMode;
    /* Effect packets reserve 60 bytes even for the shorter flat-textured quad. */
    int padding[3];
} vs_gridPrim;

int VS_GRID_FUNCTION(func_800D4910_t* arg0, u_int arg1, int arg2)
{
    int x[9];
    int z[9];
    SVECTOR vertices[9][9];
    int screen[9][9];
    int depths[9][9];
    CVECTOR color;
    u_char u[9];
    u_char v[9];
    D_800F53B8_t* battle;
    int alive;
    int depthMode;
    int xPhase;
    int zPhase;
    int row;
    int column;
    int xSpacing;
    int zSpacing;
    int acceleration;
    int zAcceleration;
    int uvBase;
    int angleX;
    int angleZ;
    int sample;
    int scroll;
    int depth;
    vs_gridState* state;
    func_800FA098_arg1* scratch = (void*)0x1F8001D0;
    func_800FA098_arg0* effect;
    MATRIX* matrix;
    vs_gridPrim* prim;
    alive = 1;
    state = arg0->unk8;
    battle = D_800F53BC;
    switch (arg1) {
    case 1:
        state = arg0->unk8 = vs_main_allocHeapR(sizeof(*state));
        state->effect = arg2 >> 8;
        state->lifetime = arg2;
        state->age = 0;
        state->xSpacing = state->xSpeed = 0;
        state->zSpacing = state->zSpeed = 0;
        state->xPhase = state->zPhase = 0;
        effect = &D_800F569C->block5Data->unk4[state->effect];
        state->tpage =
            ((effect->unkCA & 7) | ((((u_int*)effect)[1] >> 21) & 0xE0)) + 0x18;
        state->clut = ((effect->unkCB & 7) << 6) | 0x3C30;
        state->u = ((u_char*)effect)[0xAC];
        state->v = ((u_char*)effect)[0xB0];
        state->uScroll = state->vScroll = 0;
        break;
    case 2:
        effect = &D_800F569C->block5Data->unk4[state->effect];
        scratch->flags = effect->flags;
        matrix = &battle->unk1C[effect->unkC8].unk38;
        vs_battle_lerpVector(effect->unk18,
            vs_battle_sampleCurve(effect->unk8, state->age), &scratch->unk98);
        switch (scratch->flags & 7) {
        case 0:
            break;
        case 1:
            vs_battle_addVecToSvec(&scratch->unk98, D_800F5310, &scratch->unk98);
            break;
        case 2:
            scratch->unk98.vx += matrix->t[0];
            scratch->unk98.vy += matrix->t[1];
            scratch->unk98.vz += matrix->t[2];
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
        vs_battle_lerpVector(effect->unk34[0],
            vs_battle_sampleCurve(effect->unkA, state->age), &scratch->unkE8);
        vs_battle_lerpVector(effect->unk34[1],
            vs_battle_sampleCurve(effect->unkB, state->age), &scratch->unkC8);
        vs_battle_lerp2DVector(effect->unk94[2],
            vs_battle_sampleCurve(effect->unkC, state->age), scratch->unk118);
        vs_battle_lerp2DVector(effect->unk94[0],
            vs_battle_sampleCurve(effect->unk12, state->age), scratch->unk124);
        vs_battle_lerp2DVector(effect->unk94[1],
            vs_battle_sampleCurve(effect->unk13, state->age), scratch->unk12C);
        depthMode = func_800CFE1C(
            effect->unk30, vs_battle_sampleCurve(effect->unk17, state->age));
        state->xSpeed += scratch->unk108.vx;
        state->xSpacing += scratch->unkF8.vx + state->xSpeed;
        xSpacing = scratch->unkA8.vx + state->xSpacing;
        state->zSpeed += scratch->unk108.vy;
        state->zSpacing += scratch->unkF8.vy + state->zSpeed;
        zSpacing = scratch->unkA8.vy + state->zSpacing;
        xPhase = state->xPhase += scratch->unkC8.vx;
        zPhase = state->zPhase += scratch->unkC8.vy;
        column = acceleration = 0;
        for (sample = 0; sample < 5; ++sample) {
            x[4 - sample] = scratch->unk98.vx - column;
            x[4 + sample] = column + scratch->unk98.vx;
            column += xSpacing;
            xSpacing += acceleration + scratch->unk100.vx;
            acceleration += scratch->unk110.vx;
        }
        row = zAcceleration = 0;
        for (sample = 0; sample < 5; ++sample) {
            z[4 - sample] = scratch->unk98.vz - row;
            z[4 + sample] = row + scratch->unk98.vz;
            row += zSpacing;
            zSpacing += zAcceleration + scratch->unk100.vy;
            zAcceleration += scratch->unk110.vy;
        }
        for (row = 0; row < 9; ++row) {
            angleX = xPhase;
            angleZ = zPhase;
            xPhase += scratch->unk118[0];
            zPhase += scratch->unk118[1];
            for (column = 0; column < 9; ++column) {
                vertices[row][column].vx =
                    x[column] + ((rsin(angleX) * scratch->unkE8.vx) >> 12);
                vertices[row][column].vz =
                    z[row] + ((rcos(angleZ) * scratch->unkE8.vy) >> 12);
                vertices[row][column].vy = scratch->unk98.vy;
                angleX += scratch->unkC8.vx;
                angleZ += scratch->unkC8.vy;
            }
        }
        if (effect->rCurve) {
            sample = vs_battle_sampleCurve(effect->rCurve, state->age) * 2;
            if (sample < 256)
                color.r = sample;
            else
                color.r = 255;
        } else
            color.r = 128;
        if (effect->gCurve) {
            sample = vs_battle_sampleCurve(effect->gCurve, state->age) * 2;
            if (sample < 256)
                color.g = sample;
            else
                color.g = 255;
        } else
            color.g = 128;
        if (effect->bCurve) {
            sample = vs_battle_sampleCurve(effect->bCurve, state->age) * 2;
            if (sample < 256)
                color.b = sample;
            else
                color.b = 255;
        } else
            color.b = 128;
        color.cd = 0x2E;
        scroll = state->uScroll;
        state->uScroll = (scroll + scratch->unk12C[0]) % effect->unk94[0][0];
        uvBase = state->u + scroll;
        for (sample = 0; sample < 9; ++sample)
            u[sample] = uvBase + effect->unk94[0][0] * sample / 8;
        scroll = state->vScroll;
        state->vScroll = (scroll + scratch->unk12C[1]) % effect->unk94[0][2];
        uvBase = state->v + scroll;
        for (sample = 0; sample < 9; ++sample)
            v[sample] = uvBase + effect->unk94[0][2] * sample / 8;
        if (scratch->flags & 0x20000) {
            SetRotMatrix(&battle->unk1C[effect->unkC8].unk58);
            SetTransMatrix(&battle->unk1C[effect->unkC8].unk58);
        } else {
            SetRotMatrix(&vs_scratch.viewMatrix);
            SetTransMatrix(&vs_scratch.viewMatrix);
        }
        for (row = 0; row < 9; ++row) {
            for (column = 0; column < 9; ++column) {
                gte_ldv0(&vertices[row][column]);
                gte_rtps2();
                gte_stsxy(&screen[row][column]);
                gte_stszotz(&depths[row][column]);
            }
        }
        for (row = 0; row < 8; ++row) {
            for (column = 0; column < 8; ++column) {
                depth = (depths[row][column] + depths[row][column + 1]
                            + depths[row + 1][column] + depths[row + 1][column + 1])
                          / 4
                      + scratch->unkA8.vz;
                if (depth < 0x800 && vs_main_nearClip < depth) {
                    switch (depthMode) {
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
                        if (depth - 16 > vs_main_nearClip)
                            depth -= 16;
                        break;
                    }
                    prim = vs_scratch.unk0;
                    vs_scratch.unk0 = prim + 1;
                    prim->poly.tag = 0xE1000000;
                    prim->drawMode = 0xE1000200;
                    *(int*)&prim->poly.x0 = screen[row][column];
                    *(int*)&prim->poly.x1 = screen[row][column + 1];
                    *(int*)&prim->poly.x2 = screen[row + 1][column];
                    *(int*)&prim->poly.x3 = screen[row + 1][column + 1];
                    *(int*)&prim->poly.r0 = *(int*)&color;
                    prim->poly.u0 = prim->poly.u2 = u[column];
                    prim->poly.u1 = prim->poly.u3 = u[column + 1];
                    prim->poly.v0 = prim->poly.v1 = v[row];
                    prim->poly.v2 = prim->poly.v3 = v[row + 1];
                    prim->poly.tpage = state->tpage;
                    prim->poly.clut = state->clut;
                    prim->tag =
                        (((u_long*)vs_scratch.unk4)[depth] & 0xFFFFFF) | 0x0B000000;
                    ((u_long*)vs_scratch.unk4)[depth] =
                        (((u_long*)vs_scratch.unk4)[depth] & 0xFF000000)
                        | ((u_long)prim & 0xFFFFFF);
                }
            }
        }
        ++state->age;
        if (state->lifetime) {
            --state->lifetime;
            if (!state->lifetime)
                alive = 0;
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
#undef VS_GRID_FUNCTION
