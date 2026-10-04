/* Shared three-row textured ring effect. The overlay supplies its entry point and color
 * table. */
#include "common.h"
#include "src/BATTLE/BATTLE.PRG/5BF94.h"
#include "src/SLUS_010.40/32154.h"
#include "vs_inline_c.h"
#include "gpu.h"
#include <inline_c.h>
#include <rand.h>
#ifndef VS_RING_TYPES
#define VS_RING_TYPES
typedef struct {
    u_char lifetime, effect;
    short pad;
    int radius, radiusSpeed, height, heightSpeed, angle, age;
    func_800D6CF_t texture;
} vs_ringState;
typedef struct {
    int tag;
    POLY_GT4 poly;
    int drawMode;
} vs_ringPrim;
#endif
extern u_char VS_RING_COLORS[][4];

int VS_RING_FUNCTION(func_800D4910_t* arg0, u_int arg1, int arg2)
{
    int radius[3];
    int height[3];
    SVECTOR vertices[3][9];
    int screen[3][9];
    int depths[3][9];
    int factors[3];
    CVECTOR colors[3];
    u_char u[9];
    u_char v[3];
    func_800FB4C0_t child;
    D_800F53B8_t* battle;
    int alive;
    MATRIX* actorMatrix;
    int fraction;
    int radiusValue;
    int baseAngle;
    u_char* factorBytes;
    int baseAngleCopy;
    int angle;
    int angleA, angleB;
    int cosAngle;
    int sinAngle;
    int speed;
    int maxSpeed;
    int row;
    int column;
    int depth;
    int drawRow;
    int drawColumn;
    int* factor;
    u_char* colorStart;
    u_char* color;
    vs_ringPrim* prim;
    pFileBlock1Data* texture;
    func_800FA098_arg0* effect;
    vs_ringState* state;
    func_800FA098_arg1* scratch = (func_800FA098_arg1*)0x1F8001D0;

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
        state->angle = 0;
        state->age = 0;
        effect = &D_800F569C->block5Data->unk4[state->effect];
        func_800D6CCC((int*)&state->texture);
        func_800D6CF0(&state->texture, effect->unk1, effect->unk0);
        break;
    case 2: {
        effect = &D_800F569C->block5Data->unk4[state->effect];
        scratch->flags = effect->flags;
        actorMatrix = &battle->unk1C[effect->unkC8].unk38;
        effect = &D_800F569C->block5Data->unk4[state->effect];
        fraction = func_800CFE1C(
            effect->unk30, vs_battle_sampleCurve(effect->unk17, state->age));
        column = ((u_char*)effect)[7];
        factorBytes = (u_char*)VS_RING_COLORS + (column & 0x1C);
        factors[0] = factorBytes[0];
        factors[1] = factorBytes[1];
        factors[2] = factorBytes[2];
        vs_battle_lerpVector(effect->unk18,
            vs_battle_sampleCurve(effect->unk8, state->age), &scratch->unk98);
        switch (scratch->flags & 7) {
        case 0:
            break;
        case 1:
            vs_battle_addVecToSvec(&scratch->unk98, D_800F5310, &scratch->unk98);
            break;
        case 2:
            scratch->unk98.vx += actorMatrix->t[0];
            scratch->unk98.vy += actorMatrix->t[1];
            scratch->unk98.vz += actorMatrix->t[2];
            break;
        }
        vs_battle_lerpVector(effect->unk24,
            vs_battle_sampleCurve(effect->unk9, state->age), &scratch->unkA8);
        column = vs_battle_sampleCurve(effect->unkD, state->age);
        vs_battle_lerpSvector(effect->unk34[2], column, &scratch->unkF8);
        vs_battle_lerpSvector(effect->unk34[3], column, &scratch->unk100);
        column = vs_battle_sampleCurve(effect->unkE, state->age);
        vs_battle_lerpSvector(effect->unk34[4], column, &scratch->unk108);
        vs_battle_lerpSvector(effect->unk34[5], column, &scratch->unk110);
        vs_battle_lerpVector(effect->unk34[0],
            vs_battle_sampleCurve(effect->unkA, state->age), &scratch->unkE8);
        vs_battle_lerp2DVector(effect->unk94[2],
            vs_battle_sampleCurve(effect->unkC, state->age), scratch->unk118);
        state->radiusSpeed += scratch->unk108.vx;
        radiusValue = state->radius += scratch->unkF8.vx + state->radiusSpeed;
        height[0] = 0;
        radius[0] = radiusValue + scratch->unkA8.vx;
        state->heightSpeed += scratch->unk108.vy;
        state->height += scratch->unkF8.vy + state->heightSpeed;
        radius[2] = state->height + scratch->unkA8.vy;
        column = rsin(scratch->unkE8.vx);
        height[2] = (radius[2] * column) >> 12;
        radius[1] = (radius[2] * fraction) >> 12;
        height[1] = (radius[1] * column) >> 12;
        row = rcos(scratch->unkE8.vx);
        radius[1] = ((radius[1] * row) >> 12) + radius[0];
        radius[2] = ((radius[2] * row) >> 12) + radius[0];
        do {
            speed = scratch->unk118[0];
            maxSpeed = scratch->unk118[1];
        } while (0);
        row = state->angle;
        if (speed != maxSpeed) {
            if (maxSpeed < speed) {
                speed = rand() % (scratch->unk118[0] - scratch->unk118[1] + 1)
                      + scratch->unk118[1];
            } else {
                speed = rand() % (scratch->unk118[1] - scratch->unk118[0] + 1)
                      + scratch->unk118[0];
            }
        }
        maxSpeed = row + speed;
        baseAngle = state->angle = maxSpeed;
        vs_battle_lerpVector(effect->unk34[1],
            vs_battle_sampleCurve(effect->unkB, state->age), &scratch->unkC8);
        column = 0;
        do {
            baseAngleCopy = baseAngle;
            angleA = baseAngleCopy + (scratch->unkC8.vx * column) / 8;
            angleB = -scratch->unkC8.vy / 2 + ((angle = scratch->unkC8.vy) * column) / 8;
            angle = angleA + angleB;
            cosAngle = rcos(angle);
            sinAngle = rsin(angle);
            for (row = 0; row < 3; ++row) {
                vertices[row][column].vx =
                    scratch->unk98.vx + ((radius[row] * cosAngle) >> 12);
                vertices[row][column].vz =
                    scratch->unk98.vz + ((radius[row] * sinAngle) >> 12);
                vertices[row][column].vy = height[row] + scratch->unk98.vy;
            }
            ++column;
        } while (column < 9);
        colorStart = (u_char*)colors;
        color = colorStart;
        factor = &factors[0];
        do {
            if (effect->rCurve)
                maxSpeed =
                    *factor * vs_battle_sampleCurve(effect->rCurve, state->age) / 128;
            else
                maxSpeed = (u_char)*factor;
            color[0] = maxSpeed;
            if (effect->gCurve)
                maxSpeed =
                    *factor * vs_battle_sampleCurve(effect->gCurve, state->age) / 128;
            else
                maxSpeed = (u_char)*factor;
            color[1] = maxSpeed;
            if (effect->bCurve)
                maxSpeed =
                    *factor * vs_battle_sampleCurve(effect->bCurve, state->age) / 128;
            else
                maxSpeed = (u_char)*factor;
            color[2] = maxSpeed;
            {
                *(color++ + 3) = primPolyGT4SemiTrans;
                color += 3;
            }
            ++factor;
        } while ((column = (int)color) < (int)(colorStart + 12));
        if (scratch->flags & 0x20000) {
            SetRotMatrix(&battle->unk1C[effect->unkC8].unk58);
            SetTransMatrix(&battle->unk1C[effect->unkC8].unk58);
        } else {
            SetRotMatrix(&vs_scratch.viewMatrix);
            SetTransMatrix(&vs_scratch.viewMatrix);
        }
        for (drawRow = 0; drawRow < 3; ++drawRow) {
            for (drawColumn = 0; drawColumn < 9; ++drawColumn) {
                gte_ldv0(&vertices[drawRow][drawColumn]);
                gte_rtps2();
                gte_stsxy(&screen[drawRow][drawColumn]);
                gte_stszotz(&depths[drawRow][drawColumn]);
            }
        }
        func_800D6D24(&state->texture);
        texture = &D_800F569C->block1Data[state->texture.unk1C->dataIndex];
#ifdef VS_RING_TRANSPOSED
        for (column = 0; column < 9; ++column)
            u[column] = texture->v0 + texture->v1 * column / 8;
        v[0] = texture->u0;
        v[2] = v[0] + texture->u1;
        v[1] = texture->u0 + ((texture->u1 * fraction) >> 12);
#else
        for (column = 0; column < 9; ++column)
            u[column] = texture->u0 + texture->u1 * column / 8;
        v[0] = texture->v0;
        v[2] = v[0] + texture->v1;
        v[1] = texture->v0 + ((texture->v1 * fraction) >> 12);
#endif
        for (drawRow = 0; drawRow < 2; ++drawRow) {
            for (drawColumn = 0; drawColumn < 8; ++drawColumn) {
                depth = (depths[drawRow][drawColumn] + depths[drawRow][drawColumn + 1]
                            + depths[drawRow + 1][drawColumn]
                            + depths[drawRow + 1][drawColumn + 1])
                      / 4;
                if (depth < 0x800 && vs_main_nearClip < depth) {
                    prim = vs_scratch.unk0;
                    vs_scratch.unk0 = prim + 1;
                    prim->poly.tag = 0xE1000000;
                    prim->drawMode = 0xE1000200;
                    *(int*)&prim->poly.x0 = screen[drawRow][drawColumn];
#ifdef VS_RING_TRANSPOSED
                    *(int*)&prim->poly.x2 = screen[drawRow][drawColumn + 1];
                    *(int*)&prim->poly.x1 = screen[drawRow + 1][drawColumn];
#else
                    *(int*)&prim->poly.x1 = screen[drawRow][drawColumn + 1];
                    *(int*)&prim->poly.x2 = screen[drawRow + 1][drawColumn];
#endif
                    *(int*)&prim->poly.x3 = screen[drawRow + 1][drawColumn + 1];
#ifdef VS_RING_TRANSPOSED
                    *(int*)&prim->poly.r0 = *(int*)&prim->poly.r2 =
                        *(int*)&colors[drawRow];
                    *(int*)&prim->poly.r1 = *(int*)&prim->poly.r3 =
                        *(int*)&colors[drawRow + 1];
                    prim->poly.u0 = prim->poly.u2 = v[drawRow];
                    prim->poly.u1 = prim->poly.u3 = v[drawRow + 1];
                    prim->poly.v0 = prim->poly.v1 = u[drawColumn];
                    prim->poly.v2 = prim->poly.v3 = u[drawColumn + 1];
#else
                    *(int*)&prim->poly.r0 = *(int*)&prim->poly.r1 =
                        *(int*)&colors[drawRow];
                    *(int*)&prim->poly.r2 = *(int*)&prim->poly.r3 =
                        *(int*)&colors[drawRow + 1];
                    prim->poly.u0 = prim->poly.u2 = u[drawColumn];
                    prim->poly.u1 = prim->poly.u3 = u[drawColumn + 1];
                    prim->poly.v0 = prim->poly.v1 = v[drawRow];
                    prim->poly.v2 = prim->poly.v3 = v[drawRow + 1];
#endif
                    prim->poly.tpage = texture->tpage;
                    prim->poly.clut = texture->clut;
                    prim->tag =
                        (((u_long*)vs_scratch.unk4)[depth] & 0xFFFFFF) | 0x0E000000;
                    ((u_long*)vs_scratch.unk4)[depth] =
                        (((u_long*)vs_scratch.unk4)[depth] & 0xFF000000)
                        | ((u_long)prim & 0xFFFFFF);
                }
            }
        }
        if (effect->unk3) {
            child.unk60 = 0;
            if (effect->flags & 0x20000) {
                SetRotMatrix(actorMatrix);
                SetTransMatrix(actorMatrix);
                setVector(&scratch->unk2C, scratch->unk98.vx, scratch->unk98.vy,
                    scratch->unk98.vz);
                gte_ldv0(&scratch->unk2C);
                gte_rtv0tr2();
                gte_stlvnl(&scratch->unk34);
                setVector(&child.unkC, scratch->unk34.vx * ONE, scratch->unk34.vy * ONE,
                    scratch->unk34.vz * ONE);
            } else {
                setVector(&child.unkC, scratch->unk98.vx * ONE, scratch->unk98.vy * ONE,
                    scratch->unk98.vz * ONE);
            }
            func_800D2ADC(battle, effect->unk3 - 1, 0, 0, &child);
        }
        ++state->age;
        if (state->lifetime) {
            --state->lifetime;
            if (!state->lifetime)
                alive = 0;
        }
        break;
    }
    case 3:
        state->lifetime = 1;
        break;
    case 4:
        alive = 0;
        break;
    }
    return alive;
}
#undef VS_RING_FUNCTION
#undef VS_RING_COLORS

#undef VS_RING_TRANSPOSED
