/* Ten-vertex textured effect with independently scaled vertex groups. */
#include "common.h"
#include "src/BATTLE/BATTLE.PRG/5BF94.h"
#include "src/SLUS_010.40/32154.h"
#include "vs_inline_c.h"
#include "gpu.h"
#include <inline_c.h>
#ifndef VS_MESH10_TYPES
#define VS_MESH10_TYPES
typedef struct {
    u_char lifetime, effect;
    short pad;
    int age;
    func_800D6CF_t texture;
    SVECTOR rotation;
} vs_mesh10State;
typedef struct {
    int tag;
    POLY_GT3 poly;
    int drawMode;
} vs_mesh10Prim;
typedef struct {
    u_char u, v;
} vs_mesh10UV;
#endif
extern SVECTOR VS_MESH10_VERTICES[];
extern u_char VS_MESH10_FACES[][6];

int VS_MESH10_FUNCTION(func_800D4910_t* arg0, u_int arg1, int arg2)
{
    SVECTOR vertices[10];
    int screen[10];
    int depths[10];
    CVECTOR colors[2];
    vs_mesh10UV uv[6];
    func_800FB4C0_t child;
    vs_mesh10State* state;
    func_800FA098_arg1* scratch = (void*)0x1F8001D0;
    func_800FA098_arg0* effect;
    D_800F53B8_t* battle;
    int alive;
    MATRIX* actorMatrix;
    int color, index, depth;
    pFileBlock1Data* texture;
    u_char* face;
    vs_mesh10Prim* prim;
    alive = 1;
    state = arg0->unk8;
    battle = D_800F53BC;
    switch (arg1) {
    case 1:
        state = vs_main_allocHeapR(sizeof *state);
        arg0->unk8 = state;
        state->effect = arg2 >> 8;
        state->lifetime = arg2;
        *(int*)&state->rotation.vx = 0;
        *(int*)&state->rotation.vz = 0;
        state->age = 0;
        effect = &D_800F569C->block5Data->unk4[state->effect];
        func_800D6CCC((int*)&state->texture);
        func_800D6CF0(&state->texture, effect->unk1, effect->unk0);
        break;
    case 2: {
        effect = &D_800F569C->block5Data->unk4[state->effect];
        scratch->flags = effect->flags;
        actorMatrix = &battle->unk1C[effect->unkC8].unk38;
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
        vs_battle_lerpSvector(effect->unk34[7],
            vs_battle_sampleCurve(effect->unk10, state->age), &scratch->unk144);
        if (effect->rCurve) {
            index = vs_battle_sampleCurve(effect->rCurve, state->age) * 2;
            color = index;
            if (color >= 256)
                color = 255;
            colors[0].r = color;
        } else
            colors[0].r = 128;
        if (effect->gCurve) {
            index = vs_battle_sampleCurve(effect->gCurve, state->age) * 2;
            color = index;
            if (color >= 256)
                color = 255;
            colors[0].g = color;
        } else
            colors[0].g = 128;
        if (effect->bCurve) {
            index = vs_battle_sampleCurve(effect->bCurve, state->age) * 2;
            color = index;
            if (color >= 256)
                color = 255;
            colors[0].b = color;
        } else
            colors[0].b = 128;
        if (effect->unk34[2][0]) {
            index = vs_battle_sampleCurve(effect->unk34[2][0], state->age) * 2;
            color = index;
            if (index >= 256)
                color = 255;
            colors[1].r = color;
        } else
            colors[1].r = 128;
        if (effect->unk34[2][2]) {
            index = vs_battle_sampleCurve(effect->unk34[2][2], state->age) * 2;
            color = index;
            if (index >= 256)
                color = 255;
            colors[1].g = color;
        } else
            colors[1].g = 128;
        if (effect->unk34[2][4]) {
            index = vs_battle_sampleCurve(effect->unk34[2][4], state->age) * 2;
            color = index;
            if (index >= 256)
                color = 255;
            colors[1].b = color;
        } else
            colors[1].b = 128;
        do {
            colors[0].cd = 0x36;
            colors[1].cd = 0x36;
            for (index = 0; index < 4; ++index) {
                vertices[index].vx =
                    (VS_MESH10_VERTICES[index].vx * scratch->unkA8.vx) >> 12;
                vertices[index].vy =
                    (VS_MESH10_VERTICES[index].vy * scratch->unkA8.vy) >> 12;
                vertices[index].vz =
                    (VS_MESH10_VERTICES[index].vz * scratch->unkA8.vz) >> 12;
            }
        } while (0);
        for (index = 4; index < 10; ++index) {
            vertices[index].vx =
                (VS_MESH10_VERTICES[index].vx * scratch->unk144.vx) >> 12;
            vertices[index].vy =
                (VS_MESH10_VERTICES[index].vy * scratch->unk144.vy) >> 12;
            vertices[index].vz =
                (VS_MESH10_VERTICES[index].vz * scratch->unk144.vz) >> 12;
        }
        vs_battle_lerpVector(effect->unk34[0],
            vs_battle_sampleCurve(effect->unkA, state->age), &scratch->unkE8);
        vs_battle_lerpVector(effect->unk34[1],
            vs_battle_sampleCurve(effect->unkB, state->age), &scratch->unkC8);
        scratch->unk2C.vx = (state->rotation.vx += scratch->unkC8.vx) + scratch->unkE8.vx;
        scratch->unk2C.vy = (state->rotation.vy += scratch->unkC8.vy) + scratch->unkE8.vy;
        scratch->unk2C.vz = (state->rotation.vz += scratch->unkC8.vz) + scratch->unkE8.vz;
        RotMatrix_gte(&scratch->unk2C, &scratch->unk64);
        scratch->unk64.t[0] = scratch->unk98.vx;
        scratch->unk64.t[1] = scratch->unk98.vy;
        scratch->unk64.t[2] = scratch->unk98.vz;
        SetRotMatrix(&scratch->unk64);
        SetTransMatrix(&scratch->unk64);
        for (index = 0; index < 10; ++index) {
            gte_ldv0(&vertices[index]);
            gte_rtv0tr2();
            gte_stsv(&vertices[index]);
        }
        if (scratch->flags & 0x20000) {
            SetRotMatrix(&battle->unk1C[effect->unkC8].unk58);
            SetTransMatrix(&battle->unk1C[effect->unkC8].unk58);
        } else {
            SetRotMatrix(&vs_scratch.viewMatrix);
            SetTransMatrix(&vs_scratch.viewMatrix);
        }
        for (index = 0; index < 10; ++index) {
            gte_ldv0(&vertices[index]);
            gte_rtps2();
            gte_stsxy(&screen[index]);
            gte_stszotz(&depths[index]);
        }
        func_800D6D24(&state->texture);
        texture = &D_800F569C->block1Data[state->texture.unk1C->dataIndex];
        uv[1].u = texture->u0 + texture->u1 / 4;
        uv[2].u = texture->u0 + texture->u1 * 3 / 4;
        uv[0].u = uv[4].u = texture->u0 + texture->u1 / 2;
        uv[3].u = texture->u0;
        uv[5].u = uv[3].u + texture->u1;
        uv[1].v = uv[2].v = texture->v0 + texture->v1 / 2;
        uv[0].v = texture->v0;
        uv[3].v = uv[4].v = uv[5].v = uv[0].v + texture->v1;
        for (index = 0; index < 16; ++index) {
            depth = (depths[VS_MESH10_FACES[index][0]] + depths[VS_MESH10_FACES[index][1]]
                        + depths[VS_MESH10_FACES[index][2]])
                  / 3;
            if (depth < 0x800 && vs_main_nearClip < depth) {
                prim = vs_scratch.unk0;
                vs_scratch.unk0 = prim + 1;
                prim->poly.tag = 0xE1000000;
                prim->drawMode = 0xE1000200;
                *(int*)&prim->poly.x0 = screen[VS_MESH10_FACES[index][0]];
                *(int*)&prim->poly.x1 = screen[VS_MESH10_FACES[index][1]];
                *(int*)&prim->poly.x2 = screen[VS_MESH10_FACES[index][2]];
                *(int*)&prim->poly.r0 =
                    *(int*)&colors[VS_MESH10_VERTICES[VS_MESH10_FACES[index][0]].pad];
                *(int*)&prim->poly.r1 =
                    *(int*)&colors[VS_MESH10_VERTICES[VS_MESH10_FACES[index][1]].pad];
                *(int*)&prim->poly.r2 =
                    *(int*)&colors[VS_MESH10_VERTICES[VS_MESH10_FACES[index][2]].pad];
                *(u_short*)&prim->poly.u0 =
                    *(u_short*)((u_char*)uv + VS_MESH10_FACES[index][3]);
                *(u_short*)&prim->poly.u1 =
                    *(u_short*)((u_char*)uv + VS_MESH10_FACES[index][4]);
                *(u_short*)&prim->poly.u2 =
                    *(u_short*)((u_char*)uv + VS_MESH10_FACES[index][5]);
                prim->poly.tpage = texture->tpage;
                prim->poly.clut = texture->clut;
                prim->tag = (((u_long*)vs_scratch.unk4)[depth] & 0xFFFFFF) | 0x0B000000;
                ((u_long*)vs_scratch.unk4)[depth] =
                    (((u_long*)vs_scratch.unk4)[depth] & 0xFF000000)
                    | ((u_long)prim & 0xFFFFFF);
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

#undef VS_MESH10_FUNCTION
#undef VS_MESH10_VERTICES
#undef VS_MESH10_FACES
