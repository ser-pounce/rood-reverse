#include "common.h"
#include "src/BATTLE/BATTLE.PRG/5BF94.h"
#include "src/SLUS_010.40/32154.h"
#include "vs_inline_c.h"
#include "gpu.h"
#include <inline_c.h>
#include <rand.h>

#define VS_CLOSED_RING_FUNCTION func_800F9800
#define VS_CLOSED_RING_COLORS D_800FD190
#define VS_CLOSED_RING_TEXTURE_COLUMNS 4
#include "src/EFFECT/closedRings.h"

#define VS_ROTATING_SURFACE_REPEAT
#define VS_ROTATING_SURFACE_FUNCTION func_800FA770
#include "src/EFFECT/rotatingSurfaces.h"

typedef struct {
    u_char lifetime;
    u_char effect;
    short pad;
    int radius;
    int radiusSpeed;
    int height;
    int heightSpeed;
    int angle;
    int age;
    func_800D6CF_t texture;
} vs_transposedRingState;
typedef struct {
    int tag;
    POLY_GT4 poly;
    int drawMode;
} vs_transposedRingPrim;
typedef struct {
    u_char u;
    u_char v;
} vs_transposedRingUV;
extern u_char D_800FD1B0[][4];

int func_800FB62C(func_800D4910_t* arg0, u_int arg1, int arg2)
{
    int radius[3];
    int height[3];
    SVECTOR vertices[3][16];
    int screen[3][16];
    int depths[3][16];
    int factors[3];
    CVECTOR colors[3];
    u_char u[3];
    u_char v[17];
    MATRIX unusedTransform;
    func_800FB4C0_t child;
    vs_transposedRingState* state;
    func_800FA098_arg1* scratch = (func_800FA098_arg1*)0x1F8001D0;
    func_800FA098_arg0* effect;
    D_800F53B8_t* battle;
    int alive;
    MATRIX* actorMatrix;
    int fraction;
    int radiusValue;
    int baseAngle;
    u_char* factorBytes;
    int cosAngle;
    int sinAngle;
    int speed;
    int maxSpeed;
    int row;
    int oldAngle;
    int column;
    int depth;
    int drawRow;
    int drawColumn;
    vs_transposedRingPrim* prim;
    pFileBlock1Data* texture;
    alive = 1;
    state = arg0->unk8;
    battle = D_800F53BC;
    switch (arg1) {
    case 1:
        state = vs_main_allocHeapR(sizeof(*state));
        arg0->unk8 = state;
        state->lifetime = arg2;
        state->effect = arg2 >> 8;
        state->radiusSpeed = 0;
        state->radius = 0;
        state->heightSpeed = 0;
        state->height = 0;
        state->angle = 0;
        state->age = 0;
        effect = &D_800F569C->block5Data->unk4[state->effect];
        func_800D6CCC((int*)(&state->texture));
        func_800D6CF0(&state->texture, effect->unkCA, effect->unkCB);
        break;

    case 2: {
        effect = &D_800F569C->block5Data->unk4[state->effect];
        scratch->flags = effect->flags;
        actorMatrix = &battle->unk1C[effect->unkC8].unk38;
        effect = &D_800F569C->block5Data->unk4[state->effect];
        column = vs_battle_sampleCurve(effect->unk17, state->age);
        fraction = func_800CFE1C(effect->unk30, column);
        column = ((u_char*)effect)[7];
        factorBytes = ((u_char*)D_800FD1B0) + (column & 0x1C);
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

        radiusValue = (state->radius += scratch->unkF8.vx + state->radiusSpeed);
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
        oldAngle = state->angle;
        if (scratch->unk118[0] != scratch->unk118[1]) {
            if (scratch->unk118[1] < scratch->unk118[0]) {
                speed = (rand() % ((scratch->unk118[0] - scratch->unk118[1]) + 1))
                      + scratch->unk118[1];
            } else {
                speed = (rand() % ((scratch->unk118[1] - scratch->unk118[0]) + 1))
                      + scratch->unk118[0];
            }
        } else {
            speed = scratch->unk118[0];
        }
        maxSpeed = oldAngle + speed;
        baseAngle = (state->angle = maxSpeed);
        for (column = 0; column < 4; ++column) {
            for (row = 0; row < 3; ++row) {
                cosAngle = (radius[row] * rcos(baseAngle + (column * 256))) >> 12;
                vertices[row][column + 12].vz = vertices[row][column + 8].vx =
                    -(vertices[row][column + 4].vz = vertices[row][column].vx = cosAngle);
                sinAngle = (radius[row] * rsin(baseAngle + (column * 256))) >> 12;
                vertices[row][column].vz = sinAngle;
                vertices[row][column + 12].vx = sinAngle;
                vertices[row][column + 8].vz = -sinAngle;
                vertices[row][column + 4].vx = -sinAngle;
                vertices[row][column].vy = height[row];
                vertices[row][column + 4].vy = height[row];
                vertices[row][column + 8].vy = height[row];
                vertices[row][column + 12].vy = height[row];
            }
        }

        for (drawRow = 0; drawRow < 3; ++drawRow) {
            for (drawColumn = 0; drawColumn < 16; ++drawColumn) {
                vertices[drawRow][drawColumn].vx += scratch->unk98.vx;
                vertices[drawRow][drawColumn].vy += scratch->unk98.vy;
                vertices[drawRow][drawColumn].vz += scratch->unk98.vz;
            }

            if (effect->rCurve) {
                colors[drawRow].r =
                    (factors[drawRow] * vs_battle_sampleCurve(effect->rCurve, state->age))
                    / 128;
            } else {
                colors[drawRow].r = factors[drawRow];
            }
            if (effect->gCurve) {
                colors[drawRow].g =
                    (factors[drawRow] * vs_battle_sampleCurve(effect->gCurve, state->age))
                    / 128;
            } else {
                colors[drawRow].g = factors[drawRow];
            }
            if (effect->bCurve) {
                colors[drawRow].b =
                    (factors[drawRow] * vs_battle_sampleCurve(effect->bCurve, state->age))
                    / 128;
            } else {
                colors[drawRow].b = factors[drawRow];
            }
            colors[drawRow].cd = primPolyGT4SemiTrans;
        }

        if (scratch->flags & 0x20000) {
            SetRotMatrix(&battle->unk1C[effect->unkC8].unk58);
            SetTransMatrix(&battle->unk1C[effect->unkC8].unk58);
        } else {
            SetRotMatrix(&vs_scratch.viewMatrix);
            SetTransMatrix(&vs_scratch.viewMatrix);
        }
        for (drawRow = 0; drawRow < 3; ++drawRow) {
            for (drawColumn = 0; drawColumn < 16; ++drawColumn) {
                gte_ldv0(&vertices[drawRow][drawColumn]);
                gte_rtps2();
                gte_stsxy(&screen[drawRow][drawColumn]);
                gte_stszotz(&depths[drawRow][drawColumn]);
            }
        }

        func_800D6D24(&state->texture);
        texture = &D_800F569C->block1Data[state->texture.unk1C->dataIndex];
        for (column = 0; column < 17; ++column) {
            v[column] = texture->v0 + ((texture->v1 * column) / 16);
        }

        u[0] = texture->u0;
        u[2] = u[0] + texture->u1;
        u[1] = texture->u0 + ((texture->u1 * fraction) >> 12);
        for (drawRow = 0; drawRow < 2; ++drawRow) {
            for (drawColumn = 0; drawColumn < 15; ++drawColumn) {
                depth = (((depths[drawRow][drawColumn] + depths[drawRow][drawColumn + 1])
                             + depths[drawRow + 1][drawColumn])
                            + depths[drawRow + 1][drawColumn + 1])
                      / 4;
                if ((depth < 0x800) && (vs_main_nearClip < depth)) {
                    prim = vs_scratch.unk0;
                    vs_scratch.unk0 = prim + 1;
                    prim->poly.tag = 0xE1000000;
                    prim->drawMode = 0xE1000200;
                    *((int*)(&prim->poly.x0)) = screen[drawRow][drawColumn];
                    *((int*)(&prim->poly.x2)) = screen[drawRow][drawColumn + 1];
                    *((int*)(&prim->poly.x1)) = screen[drawRow + 1][drawColumn];
                    *((int*)(&prim->poly.x3)) = screen[drawRow + 1][drawColumn + 1];
                    *((int*)(&prim->poly.r0)) =
                        (*((int*)(&prim->poly.r2)) = *((int*)(&colors[drawRow])));
                    *((int*)(&prim->poly.r1)) =
                        (*((int*)(&prim->poly.r3)) = *((int*)(&colors[drawRow + 1])));
                    prim->poly.u0 = (prim->poly.u2 = u[drawRow]);
                    prim->poly.u1 = (prim->poly.u3 = u[drawRow + 1]);
                    prim->poly.v0 = (prim->poly.v1 = v[drawColumn]);
                    prim->poly.v2 = (prim->poly.v3 = v[drawColumn + 1]);
                    prim->poly.tpage = texture->tpage;
                    prim->poly.clut = texture->clut;
                    prim->tag =
                        (((u_long*)vs_scratch.unk4)[depth] & 0xFFFFFF) | 0x0E000000;
                    ((u_long*)vs_scratch.unk4)[depth] =
                        (((u_long*)vs_scratch.unk4)[depth] & 0xFF000000)
                        | (((u_long)prim) & 0xFFFFFF);
                }
            }

            depth =
                (((depths[drawRow][15] + depths[drawRow][0]) + depths[drawRow + 1][15])
                    + depths[drawRow + 1][0])
                / 4;
            if ((depth < 0x800) && (vs_main_nearClip < depth)) {
                prim = vs_scratch.unk0;
                vs_scratch.unk0 = prim + 1;
                prim->poly.tag = 0xE1000000;
                prim->drawMode = 0xE1000200;
                *((int*)(&prim->poly.x0)) = screen[drawRow][15];
                *((int*)(&prim->poly.x2)) = screen[drawRow][0];
                *((int*)(&prim->poly.x1)) = screen[drawRow + 1][15];
                *((int*)(&prim->poly.x3)) = screen[drawRow + 1][0];
                *((int*)(&prim->poly.r0)) =
                    (*((int*)(&prim->poly.r2)) = *((int*)(&colors[drawRow])));
                *((int*)(&prim->poly.r1)) =
                    (*((int*)(&prim->poly.r3)) = *((int*)(&colors[drawRow + 1])));
                prim->poly.u0 = (prim->poly.u2 = u[drawRow]);
                prim->poly.u1 = (prim->poly.u3 = u[drawRow + 1]);
                prim->poly.v0 = (prim->poly.v1 = v[drawColumn]);
                prim->poly.v2 = (prim->poly.v3 = v[drawColumn + 1]);
                prim->poly.tpage = texture->tpage;
                prim->poly.clut = texture->clut;
                prim->tag = (((u_long*)vs_scratch.unk4)[depth] & 0xFFFFFF) | 0x0E000000;
                ((u_long*)vs_scratch.unk4)[depth] =
                    (((u_long*)vs_scratch.unk4)[depth] & 0xFF000000)
                    | (((u_long)prim) & 0xFFFFFF);
            }
        }

        if (effect->unk3) {
            child.unk60 = 0;
            if (effect->flags & 0x20000) {
                SetRotMatrix(actorMatrix);
                SetTransMatrix(actorMatrix);
                (&scratch->unk2C)->vx = scratch->unk98.vx,
                (&scratch->unk2C)->vy = scratch->unk98.vy,
                (&scratch->unk2C)->vz = scratch->unk98.vz;
                gte_ldv0(&scratch->unk2C);
                gte_rtv0tr2();
                gte_stlvnl(&scratch->unk34);
                (&child.unkC)->vx = scratch->unk34.vx * 4096,
                (&child.unkC)->vy = scratch->unk34.vy * 4096,
                (&child.unkC)->vz = scratch->unk34.vz * 4096;
            } else {
                (&child.unkC)->vx = scratch->unk98.vx * 4096,
                (&child.unkC)->vy = scratch->unk98.vy * 4096,
                (&child.unkC)->vz = scratch->unk98.vz * 4096;
            }
            func_800D2ADC(battle, effect->unk3 - 1, 0, 0, &child);
        }
        ++state->age;
        if (state->lifetime) {
            --state->lifetime;
            if (!state->lifetime) {
                alive = 0;
            }
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

#define VS_RING_FUNCTION func_800FC56C
#define VS_RING_COLORS D_800FD1D0
#define VS_RING_TRANSPOSED
#include "src/EFFECT/rings.h"
