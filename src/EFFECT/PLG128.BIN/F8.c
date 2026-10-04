#define TRAIL_SAMPLE_COUNT 5

#include "common.h"
#include "src/EFFECT/trails.h"
#include "src/BATTLE/BATTLE.PRG/146C.h"
#include "src/BATTLE/BATTLE.PRG/5BF94.h"
#include "vs_inline_c.h"
#include <inline_c.h>

typedef struct {
    u_char lifetime, effect;
    short mode;
    int age;
    D_800F54D8_t startCamera;
    D_800F54D8_t endCamera;
    VECTOR unk88;
    VECTOR unk98;
    MATRIX unkA8;
    int nearClip;
    int padCC;
} func_800FD9A4_t;

void func_800D1B18(D_800F54D8_t*);
void func_800D1E20(int);
extern short D_800F54D0;
extern short D_800F55A0;
extern D_800F54D8_t D_800F5520[2];

void func_800FE3D0(
    func_800FA098_arg0*, func_800FA098_arg1*, D_800F53B8_t*, func_800FA76C_arg3*);
void func_800FEB6C(
    func_800FA098_arg0*, func_800FA098_arg1*, D_800F53B8_t*, func_800FA76C_arg3*);
void func_800FED84(
    func_800FA098_arg0*, func_800FA098_arg1*, D_800F53B8_t*, func_800FA76C_arg3*);
void func_800FF248(
    func_800FA098_arg0*, func_800FA098_arg1*, D_800F53B8_t*, func_800FA76C_arg3*);
void func_800FF3C0(
    func_800FA098_arg0*, func_800FA098_arg1*, D_800F53B8_t*, func_800FA76C_arg3*);
void func_800FF54C(
    func_800FA098_arg0*, func_800FA098_arg1*, D_800F53B8_t*, func_800FA76C_arg3*);

#define VS_SURFACE_FUNCTION func_800F98F8
#define VS_SURFACE_VERTICES D_801004F0
#define VS_SURFACE_REPEAT
#include "src/EFFECT/surfaces.h"

INCLUDE_ASM("build/src/EFFECT/PLG128.BIN/nonmatchings/F8", func_800FA490);

INCLUDE_ASM("build/src/EFFECT/PLG128.BIN/nonmatchings/F8", func_800FB400);

#define VS_GRID_FUNCTION func_800FC2BC
#include "src/EFFECT/grids.h"

#define VS_SURFACE_FUNCTION func_800FCE0C
#define VS_SURFACE_VERTICES D_80100790
#include "src/EFFECT/surfaces.h"

void func_800FD9A4(func_800FD9A4_t* arg0, VECTOR* arg1)
{
    vs_battle_lookAt(&arg0->unk98, &arg0->unk88, &arg0->unkA8);
    arg0->unkA8.t[0] = arg1->vx;
    arg0->unkA8.t[1] = arg1->vy;
    arg0->unkA8.t[2] = arg1->vz;
}

void func_800FDA04(func_800FD9A4_t* arg0, func_800FA098_arg1* arg1, D_800F53B8_t* arg2,
    func_800FA098_arg0* arg3)
{
    switch (arg1->flags & 7) {
    case 0:
        break;
    case 1:
        vs_battle_addVecToSvec(&arg1->unk98, D_800F5310, &arg1->unk98);
        break;
    case 2:
        arg1->unk98.vx += arg2->unk1C[arg3->unkC8].unk38.t[0];
        arg1->unk98.vy += arg2->unk1C[arg3->unkC8].unk38.t[1];
        arg1->unk98.vz += arg2->unk1C[arg3->unkC8].unk38.t[2];
        break;
    }
    arg0->unk88.vx = arg1->unk98.vx;
    arg0->unk88.vy = arg1->unk98.vy;
    arg0->unk88.vz = arg1->unk98.vz;
    switch (arg1->flags & 0x1C0) {
    case 0:
        break;
    case 0xC0:
        arg1->unk13C.vx += arg2->unk1C[arg3->unkC9].unk38.t[0];
        arg1->unk13C.vy += arg2->unk1C[arg3->unkC9].unk38.t[1];
        arg1->unk13C.vz += arg2->unk1C[arg3->unkC9].unk38.t[2];
        break;
    case 0x80:
        arg1->unk13C.vx += D_800F5230.unkE0.vx;
        arg1->unk13C.vy += D_800F5230.unkE0.vy;
        arg1->unk13C.vz += D_800F5230.unkE0.vz;
        break;
    }
    arg0->unk98.vx = arg1->unk13C.vx;
    arg0->unk98.vy = arg1->unk13C.vy;
    arg0->unk98.vz = arg1->unk13C.vz;
}

void func_800FDC80(func_800FD9A4_t* arg0, func_800FA098_arg1* arg1, D_800F53B8_t* arg2,
    func_800FA098_arg0* arg3)
{
    switch (arg1->flags & 7) {
    case 0:
        break;
    case 1:
        vs_battle_addVecToSvec(&arg1->unk98, D_800F5310, &arg1->unk98);
        break;
    case 2:
        arg1->unk98.vx += arg2->unk1C[arg3->unkC8].unk38.t[0];
        arg1->unk98.vy += arg2->unk1C[arg3->unkC8].unk38.t[1];
        arg1->unk98.vz += arg2->unk1C[arg3->unkC8].unk38.t[2];
        break;
    }
    arg0->unk98.vx = arg1->unk98.vx;
    arg0->unk98.vy = arg1->unk98.vy;
    arg0->unk98.vz = arg1->unk98.vz;
    arg0->unk88.vx = arg1->unk98.vx
                   + ((-arg1->unk144.vx * rsin(arg2->unk1C[arg3->unkC8].unkBE)) >> 12);
    arg0->unk88.vz = arg1->unk98.vz
                   + ((-arg1->unk144.vx * rcos(arg2->unk1C[arg3->unkC8].unkBE)) >> 12);
    arg0->unk88.vy = arg1->unk98.vy;
}

void func_800FDE78(func_800FD9A4_t* arg0, func_800FA098_arg1* scratch)
{
    arg0->endCamera.position.vx = arg0->unk88.vx << 12;
    arg0->endCamera.position.vy = arg0->unk88.vy << 12;
    arg0->endCamera.position.vz = arg0->unk88.vz << 12;
    arg0->endCamera.lookAt.vx = arg0->unk98.vx << 12;
    arg0->endCamera.lookAt.vy = arg0->unk98.vy << 12;
    arg0->endCamera.lookAt.vz = arg0->unk98.vz << 12;
}

int func_800FDEC4(func_800D4910_t* arg0, u_int arg1, int arg2)
{
    func_800FD9A4_t* state = arg0->unk8;
    D_800F53B8_t* battle = D_800F53BC;
    func_800FA098_arg1* scratch = (void*)0x1F8001D0;
    func_800FA098_arg0* effect;
    int alive = 1;
    int curve;
    switch (arg1) {
    case 1:
        state = arg0->unk8 = vs_main_allocHeapR(sizeof(*state));
        state->effect = arg2 >> 8;
        state->lifetime = arg2;
        state->mode = arg2 >> 16;
        state->age = 0;
        func_800D1B18(&state->startCamera);
        func_800D1B18(&state->endCamera);
        D_800F54D0 = 0;
        D_800F55A0 = arg2 & 0xFF;
        switch (state->mode) {
        case 0:
        case 1:
            func_800D1E20(2);
            break;
        }
        break;
    case 2:
        effect = &D_800F569C->block5Data->unk4[state->effect];
        scratch->flags = effect->flags;
        curve = effect->unk8;
        vs_battle_lerpVector(
            effect->unk18, vs_battle_sampleCurve(curve, state->age), &scratch->unk98);
        vs_battle_lerpVector(
            effect->unk24, vs_battle_sampleCurve(curve, state->age), &scratch->unkA8);
        vs_battle_lerpVector(effect->unk34[0],
            vs_battle_sampleCurve(effect->unkA, state->age), &scratch->unkE8);
        vs_battle_lerp2DVector(effect->unk94[2],
            vs_battle_sampleCurve(effect->unkC, state->age), scratch->unk118);
        vs_battle_lerpSvector(effect->unk34[6],
            vs_battle_sampleCurve(effect->unkF, state->age), &scratch->unk13C);
        vs_battle_lerpSvector(effect->unk34[7],
            vs_battle_sampleCurve(effect->unk10, state->age), &scratch->unk144);
        state->nearClip = func_800CFE1C(
            effect->unk30, vs_battle_sampleCurve(effect->unk17, state->age));
        switch (state->mode) {
        case 0:
            func_800FDA04(state, scratch, battle, effect);
            break;
        case 1:
            func_800FDC80(state, scratch, battle, effect);
            break;
        }
        switch (scratch->flags & 0x38) {
        case 0:
            func_800FD9A4(state, &state->unk88);
            scratch->unk170 = rsin(scratch->unkE8.vx);
            if (scratch->unk170 > 0)
                scratch->unk170 = -scratch->unk170;
            scratch->unk178 = rcos(scratch->unkE8.vx);
            scratch->unk174 = rsin(scratch->unkE8.vy);
            scratch->unk17C = rcos(scratch->unkE8.vy);
            scratch->unk2C.vx =
                (((scratch->unkA8.vx * scratch->unk178) >> 12) * scratch->unk17C) >> 12;
            scratch->unk2C.vy =
                (((scratch->unkA8.vy * scratch->unk178) >> 12) * scratch->unk174) >> 12;
            scratch->unk2C.vz = (scratch->unkA8.vz * scratch->unk170) >> 12;
            break;
        case 0x20:
            func_800FD9A4(state, &state->unk88);
            scratch->unk170 = rsin(scratch->unkE8.vx);
            scratch->unk178 = rcos(scratch->unkE8.vx);
            scratch->unk2C.vx = (scratch->unkA8.vx * scratch->unk178) >> 12;
            scratch->unk2C.vz = scratch->unkA8.vz;
            scratch->unk2C.vy = (scratch->unkA8.vy * scratch->unk170) >> 12;
            break;
        }
        SetRotMatrix(&state->unkA8);
        SetTransMatrix(&state->unkA8);
        gte_ldv0(&scratch->unk2C);
        gte_rtv0tr2();
        gte_stlvnl(&state->unk88);
        switch (state->mode) {
        case 0:
        case 1:
            func_800FDE78(state, scratch);
            break;
        }
        state->endCamera.nearClip = state->nearClip;
        state->endCamera.farClip = scratch->unk118[0];
        D_800F5520[0] = state->startCamera;
        D_800F5520[1] = state->endCamera;
        ++state->age;
        if (!--state->lifetime)
            alive = 0;
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

#define VS_TRAIL_ORIGIN_FUNCTION func_800FE3D0
#define VS_TRAIL_TARGET_FUNCTION func_800FEB6C
#define VS_TRAIL_CONTROL_FUNCTION func_800FED84
#define VS_TRAIL_INIT_FUNCTION func_800FF248
#define VS_TRAIL_UPDATE_FUNCTION func_800FF3C0
#define VS_TRAIL_RENDER_FUNCTION func_800FF54C
#define VS_TRAIL_DISPATCH_FUNCTION func_800FFFA8
#define VS_TRAIL_CORNER_STATE D_80100A10
#include "src/EFFECT/trails5.h"
