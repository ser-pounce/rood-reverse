/* Shared three-row, sixteen-column tiled ring effect. The overlay supplies its entry
 * point and color table. */

#include "src/BATTLE/BATTLE.PRG/5BF94.h"
#include "src/SLUS_010.40/32154.h"
#include "vs_inline_c.h"
#include "gpu.h"
#include <inline_c.h>
#include <rand.h>

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
} vs_tiledRingState;
typedef struct {
    int tag;
    POLY_GT4 poly;
    int drawMode;
} vs_tiledRingPrim;
typedef struct {
    u_char u;
    u_char v;
} vs_tiledRingUV;

extern u_char VS_TILED_RING_COLORS[][4];

int VS_TILED_RING_FUNCTION(func_800D4910_t* arg0, u_int arg1, int arg2)
{
    int radius[3];
    int height[3];
    SVECTOR vertices[3][16];
    int screen[3][16];
    int depths[3][16];
    int factors[3];
    CVECTOR colors[3];
    vs_tiledRingUV uv[2][4];
    MATRIX unusedTransform;
    func_800FB4C0_t child;
    vs_tiledRingState* state = arg0->unk8;
    func_800FA098_arg1* scratch = (func_800FA098_arg1*)0x1F8001D0;
    func_800FA098_arg0* effect;
    D_800F53B8_t* battle = D_800F53BC;
    int alive = 1;
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
    vs_tiledRingPrim* prim;
    pFileBlock1Data* texture;
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
        func_800D6CCC((int*)&state->texture);
        func_800D6CF0(&state->texture, effect->unkCA, effect->unkCB);
        break;

    case 2:
        effect = &D_800F569C->block5Data->unk4[state->effect];
        scratch->flags = effect->flags;
        actorMatrix = &battle->unk1C[effect->unkC8].unk38;
        effect = &D_800F569C->block5Data->unk4[state->effect];
        column = vs_battle_sampleCurve(effect->unk17, state->age);
        fraction = func_800CFE1C(effect->unk30, column);
        column = effect->transparencyCurve & 0x7;
        factorBytes = VS_TILED_RING_COLORS[column];
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
        baseAngle = state->angle = maxSpeed;
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
        uv[0][0].u = uv[0][2].u = uv[1][0].u = uv[1][2].u = texture->u0;
        uv[0][1].u = uv[0][3].u = uv[1][1].u = uv[1][3].u = uv[0][0].u + texture->u1;
        uv[0][0].v = uv[0][1].v = texture->v0;
        uv[0][2].v = uv[0][3].v = uv[1][0].v = uv[1][1].v =
            uv[0][0].v + ((texture->v1 * fraction) >> 12);
        uv[1][2].v = uv[1][3].v = texture->v0 + texture->v1;
        for (drawRow = 0; drawRow < 2; ++drawRow) {
            for (drawColumn = 0; drawColumn < 15; ++drawColumn) {
                depth = (depths[drawRow][drawColumn] + depths[drawRow][drawColumn + 1]
                            + depths[drawRow + 1][drawColumn]
                            + depths[drawRow + 1][drawColumn + 1])
                      / 4;
                if (depth < 0x800 && vs_main_nearClip < depth) {
                    prim = vs_scratch.unk0;
                    vs_scratch.unk0 = prim + 1;
                    prim->poly.tag = _get_mode(0, 0, 0);
                    prim->drawMode = _get_mode(0, 1, 0);
                    *(int*)&prim->poly.x0 = screen[drawRow][drawColumn];
                    *(int*)&prim->poly.x1 = screen[drawRow][drawColumn + 1];
                    *(int*)&prim->poly.x2 = screen[drawRow + 1][drawColumn];
                    *(int*)&prim->poly.x3 = screen[drawRow + 1][drawColumn + 1];
                    *(int*)&prim->poly.r0 = *(int*)&prim->poly.r1 =
                        *(int*)&colors[drawRow];
                    *(int*)&prim->poly.r2 = *(int*)&prim->poly.r3 =
                        *(int*)&colors[drawRow + 1];
                    *(u_short*)&prim->poly.u0 = *(u_short*)&uv[drawRow][0];
                    *(u_short*)&prim->poly.u1 = *(u_short*)&uv[drawRow][1];
                    *(u_short*)&prim->poly.u2 = *(u_short*)&uv[drawRow][2];
                    *(u_short*)&prim->poly.u3 = *(u_short*)&uv[drawRow][3];
                    prim->poly.tpage = texture->tpage;
                    prim->poly.clut = texture->clut;
                    prim->tag =
                        (((u_long*)vs_scratch.unk4)[depth] & 0xFFFFFF) | 0x0E000000;
                    ((u_long*)vs_scratch.unk4)[depth] =
                        (((u_long*)vs_scratch.unk4)[depth] & 0xFF000000)
                        | (((u_long)prim) & 0xFFFFFF);
                }
            }

            depth = (depths[drawRow][15] + depths[drawRow][0] + depths[drawRow + 1][15]
                        + depths[drawRow + 1][0])
                  / 4;
            if (depth < 0x800 && vs_main_nearClip < depth) {
                prim = vs_scratch.unk0;
                vs_scratch.unk0 = prim + 1;
                prim->poly.tag = _get_mode(0, 0, 0);
                prim->drawMode = _get_mode(0, 1, 0);
                *(int*)&prim->poly.x0 = screen[drawRow][15];
                *(int*)&prim->poly.x1 = screen[drawRow][0];
                *(int*)&prim->poly.x2 = screen[drawRow + 1][15];
                *(int*)&prim->poly.x3 = screen[drawRow + 1][0];
                *(int*)&prim->poly.r0 = *(int*)&prim->poly.r1 = *(int*)&colors[drawRow];
                *(int*)&prim->poly.r2 = *(int*)&prim->poly.r3 =
                    *(int*)&colors[drawRow + 1];
                *(u_short*)&prim->poly.u0 = *(u_short*)&uv[drawRow][0];
                *(u_short*)&prim->poly.u1 = *(u_short*)&uv[drawRow][1];
                *(u_short*)&prim->poly.u2 = *(u_short*)&uv[drawRow][2];
                *(u_short*)&prim->poly.u3 = *(u_short*)&uv[drawRow][3];
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
#undef VS_TILED_RING_FUNCTION
#undef VS_TILED_RING_COLORS
