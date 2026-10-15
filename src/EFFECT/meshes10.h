/* Shared ten-vertex, sixteen-face textured mesh effect. The first four vertices and the
 * other six are scaled separately before the mesh is rotated into place. The overlay
 * supplies its entry point, vertex table and face table. */

#include "src/BATTLE/BATTLE.PRG/5BF94.h"
#include "src/SLUS_010.40/32154.h"
#include "vs_inline_c.h"
#include "gpu.h"
#include <inline_c.h>

typedef struct {
    u_char lifetime;
    u_char effect;
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
    u_char u;
    u_char v;
} vs_mesh10UV;

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
    vs_mesh10State* state = arg0->unk8;
    func_800FA098_arg1* scratch = (func_800FA098_arg1*)0x1F8001D0;
    func_800FA098_arg0* effect;
    D_800F53B8_t* battle = D_800F53BC;
    int alive = 1;
    MATRIX* actorMatrix;
    int i;
    pFileTexture* texture;

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

    case 2:
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
            applyVector(&scratch->unk98, actorMatrix->t[0], actorMatrix->t[1],
                actorMatrix->t[2], +=);
            break;
        }

        vs_battle_lerpVector(effect->unk24,
            vs_battle_sampleCurve(effect->unk9, state->age), &scratch->unkA8);
        vs_battle_lerpSvector(effect->unk34[7],
            vs_battle_sampleCurve(effect->unk10, state->age), &scratch->unk144);

        if (effect->rCurve) {
            i = vs_battle_sampleCurve(effect->rCurve, state->age) * 2;
            colors[0].r = i < 256 ? i : 255;
        } else {
            colors[0].r = 128;
        }
        if (effect->gCurve) {
            i = vs_battle_sampleCurve(effect->gCurve, state->age) * 2;
            colors[0].g = i < 256 ? i : 255;
        } else {
            colors[0].g = 128;
        }
        if (effect->bCurve) {
            i = vs_battle_sampleCurve(effect->bCurve, state->age) * 2;
            colors[0].b = i < 256 ? i : 255;
        } else {
            colors[0].b = 128;
        }
        if (effect->unk34[2][0]) {
            i = vs_battle_sampleCurve(effect->unk34[2][0], state->age) * 2;
            colors[1].r = i < 256 ? i : 255;
        } else {
            colors[1].r = 128;
        }
        if (effect->unk34[2][2]) {
            i = vs_battle_sampleCurve(effect->unk34[2][2], state->age) * 2;
            colors[1].g = i < 256 ? i : 255;
        } else {
            colors[1].g = 128;
        }
        if (effect->unk34[2][4]) {
            i = vs_battle_sampleCurve(effect->unk34[2][4], state->age) * 2;
            colors[1].b = i < 256 ? i : 255;
        } else {
            colors[1].b = 128;
        }

        colors[0].cd = primPolyGT3SemiTrans;
        colors[1].cd = primPolyGT3SemiTrans;

        for (i = 0; i < 4; ++i) {
            setVector(&vertices[i], (VS_MESH10_VERTICES[i].vx * scratch->unkA8.vx) >> 12,
                (VS_MESH10_VERTICES[i].vy * scratch->unkA8.vy) >> 12,
                (VS_MESH10_VERTICES[i].vz * scratch->unkA8.vz) >> 12);
        }
        for (i = 4; i < 10; ++i) {
            setVector(&vertices[i], (VS_MESH10_VERTICES[i].vx * scratch->unk144.vx) >> 12,
                (VS_MESH10_VERTICES[i].vy * scratch->unk144.vy) >> 12,
                (VS_MESH10_VERTICES[i].vz * scratch->unk144.vz) >> 12);
        }

        vs_battle_lerpVector(effect->unk34[0],
            vs_battle_sampleCurve(effect->unkA, state->age), &scratch->unkE8);
        vs_battle_lerpVector(effect->unk34[1],
            vs_battle_sampleCurve(effect->unkB, state->age), &scratch->unkC8);
        state->rotation.vx += scratch->unkC8.vx;
        scratch->unk2C.vx = state->rotation.vx + scratch->unkE8.vx;
        state->rotation.vy += scratch->unkC8.vy;
        scratch->unk2C.vy = state->rotation.vy + scratch->unkE8.vy;
        state->rotation.vz += scratch->unkC8.vz;
        scratch->unk2C.vz = state->rotation.vz + scratch->unkE8.vz;
        RotMatrix_gte(&scratch->unk2C, &scratch->unk64);
        scratch->unk64.t[0] = scratch->unk98.vx;
        scratch->unk64.t[1] = scratch->unk98.vy;
        scratch->unk64.t[2] = scratch->unk98.vz;
        SetRotMatrix(&scratch->unk64);
        SetTransMatrix(&scratch->unk64);

        do {
            for (i = 0; i < 10; ++i) {
                gte_ldv0(&vertices[i]);
                gte_rtv0tr2();
                gte_stsv(&vertices[i]);
            }
        } while (0);

        if (scratch->flags & 0x20000) {
            SetRotMatrix(&battle->unk1C[effect->unkC8].unk58);
            SetTransMatrix(&battle->unk1C[effect->unkC8].unk58);
        } else {
            SetRotMatrix(&vs_scratch.viewMatrix);
            SetTransMatrix(&vs_scratch.viewMatrix);
        }
        for (i = 0; i < 10; ++i) {
            gte_ldv0(&vertices[i]);
            gte_rtps2();
            gte_stsxy(&screen[i]);
            gte_stszotz(&depths[i]);
        }

        func_800D6D24(&state->texture);
        texture = &D_800F569C->textures[state->texture.textureInfo->dataIndex];
        uv[1].u = texture->u + texture->w / 4;
        uv[2].u = texture->u + texture->w * 3 / 4;
        uv[0].u = uv[4].u = texture->u + texture->w / 2;
        uv[3].u = texture->u;
        uv[5].u = uv[3].u + texture->w;
        uv[1].v = uv[2].v = texture->v + texture->h / 2;
        uv[0].v = texture->v;
        uv[3].v = uv[4].v = uv[5].v = uv[0].v + texture->h;

        for (i = 0; i < 16; ++i) {
            int depth = (depths[VS_MESH10_FACES[i][0]] + depths[VS_MESH10_FACES[i][1]]
                            + depths[VS_MESH10_FACES[i][2]])
                      / 3;

            vs_mesh10Prim* prim;

            if (depth >= ONE / 2 || depth <= vs_main_nearClip) {
                continue;
            }

            prim = vs_scratch.unk0;
            vs_scratch.unk0 = prim + 1;
            prim->poly.tag = _get_mode(0, 0, 0);
            prim->drawMode = _get_mode(0, 1, 0);
            *(int*)&prim->poly.x0 = screen[VS_MESH10_FACES[i][0]];
            *(int*)&prim->poly.x1 = screen[VS_MESH10_FACES[i][1]];
            *(int*)&prim->poly.x2 = screen[VS_MESH10_FACES[i][2]];
            *(int*)&prim->poly.r0 =
                *(int*)&colors[VS_MESH10_VERTICES[VS_MESH10_FACES[i][0]].pad];
            *(int*)&prim->poly.r1 =
                *(int*)&colors[VS_MESH10_VERTICES[VS_MESH10_FACES[i][1]].pad];
            *(int*)&prim->poly.r2 =
                *(int*)&colors[VS_MESH10_VERTICES[VS_MESH10_FACES[i][2]].pad];
            *(u_short*)&prim->poly.u0 = *(u_short*)((u_char*)uv + VS_MESH10_FACES[i][3]);
            *(u_short*)&prim->poly.u1 = *(u_short*)((u_char*)uv + VS_MESH10_FACES[i][4]);
            *(u_short*)&prim->poly.u2 = *(u_short*)((u_char*)uv + VS_MESH10_FACES[i][5]);
            prim->poly.tpage = texture->tpage;
            prim->poly.clut = texture->clut;
            prim->tag = (((u_long*)vs_scratch.unk4)[depth] & 0xFFFFFF) | 0x0B000000;
            ((u_long*)vs_scratch.unk4)[depth] =
                (((u_long*)vs_scratch.unk4)[depth] & 0xFF000000)
                | ((u_long)prim & 0xFFFFFF);
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
#undef VS_MESH10_FUNCTION
#undef VS_MESH10_VERTICES
#undef VS_MESH10_FACES
