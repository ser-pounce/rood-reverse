/* Shared three-row, nine-column textured ring effect. The entry point is named by
 * entry.h. The overlay defines VS_RING_TRANSPOSED when its texture runs along the rows
 * instead of the columns. */

#include "src/EFFECT/entry.h"
#define VS_RING_FUNCTION VS_ENTRY_FUNCTION

#include "src/BATTLE/BATTLE.PRG/5BF94.h"
#include "src/SLUS_010.40/32154.h"
#include "vs_inline_c.h"
#include "gpu.h"
#include <inline_c.h>
#include <rand.h>

#ifndef VS_RING_TYPES
#define VS_RING_TYPES
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
} vs_ringState;
typedef struct {
    int tag;
    POLY_GT4 poly;
    int drawMode;
} vs_ringPrim;
#endif

#define VS_RING_COLORS VS_CAT(VS_RING_FUNCTION, _colors)
static CVECTOR VS_RING_COLORS[] = {
    { 255, 255, 255 },
    { 128, 128, 128 },
    { 255, 128, 0 },
    { 0, 128, 255 },
    { 0, 255, 0 },
    { 255, 0, 255 },
    { 0, 128, 0 },
    { 128, 0, 128 },
};

extern CVECTOR VS_RING_COLORS[];

int VS_RING_FUNCTION(func_800D4910_t* arg0, u_int arg1, int arg2)
{
    int radius[3];
    int height[3];
    SVECTOR vertices[3][9];
    int screen[3][9];
    int depths[3][9];
    int factors[3];
    CVECTOR colors[3];
    u_char columnUV[9];
    u_char rowUV[3];
    func_800D2904_t child;
    vs_ringState* state = arg0->unk8;
    func_800FA098_arg1* scratch = (func_800FA098_arg1*)0x1F8001D0;
    func_800FA098_arg0* effect;
    D_800F53B8_t* battle = D_800F53BC;
    int alive = 1;
    MATRIX* actorMatrix;
    int fraction;
    int radiusValue;
    int baseAngle;
    CVECTOR* factorBytes;
    int speed;
    int maxSpeed;
    int row;
    int column;
    int drawRow;
    int drawColumn;
    pFileTexture* texture;

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

    case 2:
        effect = &D_800F569C->block5Data->unk4[state->effect];
        scratch->flags = effect->flags;
        actorMatrix = &battle->unk1C[effect->unkC8].world;
        effect = &D_800F569C->block5Data->unk4[state->effect];
        fraction = func_800CFE1C(
            effect->unk30, vs_battle_sampleCurve(effect->unk17, state->age));
        column = effect->transparencyCurve & 0x7;
        factorBytes = &VS_RING_COLORS[column];
        factors[0] = factorBytes->r;
        factors[1] = factorBytes->g;
        factors[2] = factorBytes->b;
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

        for (column = 0; column < 9; ++column) {
            int angle;
            int angleA = baseAngle + (scratch->unkC8.vx * column) / 8;
            int angleB =
                -scratch->unkC8.vy / 2 + ((angle = scratch->unkC8.vy) * column) / 8;
            int cosAngle;
            int sinAngle;

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
        }

        for (row = 0; row < 3; ++row) {
            if (effect->rCurve) {
                colors[row].r =
                    (factors[row] * vs_battle_sampleCurve(effect->rCurve, state->age))
                    / 128;
            } else {
                colors[row].r = factors[row];
            }

            if (effect->gCurve) {
                colors[row].g =
                    (factors[row] * vs_battle_sampleCurve(effect->gCurve, state->age))
                    / 128;
            } else {
                colors[row].g = factors[row];
            }

            if (effect->bCurve) {
                colors[row].b =
                    (factors[row] * vs_battle_sampleCurve(effect->bCurve, state->age))
                    / 128;
            } else {
                colors[row].b = factors[row];
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

        for (drawRow = 0; drawRow < 3; ++drawRow) {
            for (drawColumn = 0; drawColumn < 9; ++drawColumn) {
                gte_ldv0(&vertices[drawRow][drawColumn]);
                gte_rtps2();
                gte_stsxy(&screen[drawRow][drawColumn]);
                gte_stszotz(&depths[drawRow][drawColumn]);
            }
        }

        func_800D6D24(&state->texture);
        texture = &D_800F569C->textures[state->texture.textureInfo->dataIndex];

#ifdef VS_RING_TRANSPOSED
        for (column = 0; column < 9; ++column) {
            columnUV[column] = texture->v + texture->h * column / 8;
        }

        rowUV[0] = texture->u;
        rowUV[2] = rowUV[0] + texture->w;
        rowUV[1] = texture->u + ((texture->w * fraction) >> 12);
#else
        for (column = 0; column < 9; ++column) {
            columnUV[column] = texture->u + texture->w * column / 8;
        }

        rowUV[0] = texture->v;
        rowUV[2] = rowUV[0] + texture->h;
        rowUV[1] = texture->v + ((texture->h * fraction) >> 12);
#endif

        for (drawRow = 0; drawRow < 2; ++drawRow) {
            for (drawColumn = 0; drawColumn < 8; ++drawColumn) {
                int depth = (depths[drawRow][drawColumn] + depths[drawRow][drawColumn + 1]
                                + depths[drawRow + 1][drawColumn]
                                + depths[drawRow + 1][drawColumn + 1])
                          / 4;
                vs_ringPrim* prim;

                if (depth >= 0x800 || depth <= vs_main_nearClip) {
                    continue;
                }

                prim = vs_scratch.unk0;
                vs_scratch.unk0 = prim + 1;
                prim->poly.tag = _get_mode(0, 0, 0);
                prim->drawMode = _get_mode(0, 1, 0);
                *(int*)&prim->poly.x0 = screen[drawRow][drawColumn];
#ifdef VS_RING_TRANSPOSED
                *(int*)&prim->poly.x2 = screen[drawRow][drawColumn + 1];
                *(int*)&prim->poly.x1 = screen[drawRow + 1][drawColumn];
                *(int*)&prim->poly.x3 = screen[drawRow + 1][drawColumn + 1];
                *(int*)&prim->poly.r0 = *(int*)&prim->poly.r2 = *(int*)&colors[drawRow];
                *(int*)&prim->poly.r1 = *(int*)&prim->poly.r3 =
                    *(int*)&colors[drawRow + 1];
                prim->poly.u0 = prim->poly.u2 = rowUV[drawRow];
                prim->poly.u1 = prim->poly.u3 = rowUV[drawRow + 1];
                prim->poly.v0 = prim->poly.v1 = columnUV[drawColumn];
                prim->poly.v2 = prim->poly.v3 = columnUV[drawColumn + 1];
#else
                *(int*)&prim->poly.x1 = screen[drawRow][drawColumn + 1];
                *(int*)&prim->poly.x2 = screen[drawRow + 1][drawColumn];
                *(int*)&prim->poly.x3 = screen[drawRow + 1][drawColumn + 1];
                *(int*)&prim->poly.r0 = *(int*)&prim->poly.r1 = *(int*)&colors[drawRow];
                *(int*)&prim->poly.r2 = *(int*)&prim->poly.r3 =
                    *(int*)&colors[drawRow + 1];
                prim->poly.u0 = prim->poly.u2 = columnUV[drawColumn];
                prim->poly.u1 = prim->poly.u3 = columnUV[drawColumn + 1];
                prim->poly.v0 = prim->poly.v1 = rowUV[drawRow];
                prim->poly.v2 = prim->poly.v3 = rowUV[drawRow + 1];
#endif
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
                copyVector(&scratch->unk2C, &scratch->unk98);
                gte_ldv0(&scratch->unk2C);
                gte_rtv0tr2();
                gte_stlvnl(&scratch->unk34);
                setVector(&child.motion.position, scratch->unk34.vx * ONE,
                    scratch->unk34.vy * ONE, scratch->unk34.vz * ONE);
            } else {
                setVector(&child.motion.position, scratch->unk98.vx * ONE,
                    scratch->unk98.vy * ONE, scratch->unk98.vz * ONE);
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
