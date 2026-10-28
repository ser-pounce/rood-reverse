#include "common.h"
#include <rand.h>
#include <abs.h>
#include <inline_c.h>
#include "vs_inline_c.h"
#include "146C.h"
#include "38C1C.h"
#include "3A1A0.h"
#include "44F14.h"
#include "4A0A8.h"
#include "../../SLUS_010.40/main.h"
#include "../../SLUS_010.40/31724.h"

typedef struct {
    u_char unk0[8];
    int first;
    int last;
    u_char** data;
} D_1F8003EC_t;

typedef struct {
    MATRIX bones[63];
    VECTOR scale;
} D_800F3C58_t;

void func_8008EB04(int*, int*);
int func_800A91DC(int, int, int);
void func_800AF844(SVECTOR*, SVECTOR*, int);
void func_800B147C(D_800F4538_unkC54*, D_800F4538_unkC54*, int, int, int);
void func_800B17F0(SVECTOR*, MATRIX*);
void func_800B196C(MATRIX*, MATRIX*);
void func_800B396C(MATRIX*, VECTOR*);
int func_800B3A68(void*, MATRIX*, int, void*);
void func_800B3CF0(D_800F2458_t*, vs_battle_wepModels_t*, CVECTOR*, void*);
void func_800B4594(D_800F2458_t*, D_800F45E0_t*, CVECTOR*, void*);
void func_800B516C(D_800F2458_t*, vs_battle_wepModels_t*, CVECTOR*, void*);
void func_800B5C30(D_800F2458_t*, D_800F45E0_t*, CVECTOR*, void*);

extern MATRIX D_8005E218;
extern u_char D_800E91A4[];
extern u_char D_800E9278[];
extern D_800F3C58_t D_800F3C58;
extern MATRIX D_800F3C78;
extern MATRIX D_800F4910;
extern MATRIX D_800F49B8;

void func_800B1A68(D_800F45E0_t* object, MATRIX* camera)
{
    D_1F80035C_t* scratch = (void*)0x1F80035C;
    u_int attachment;
    int value;

    scratch->model = object->unk0.unk68;
    gte_SetRotMatrix(camera);
    gte_SetTransMatrix(camera);
    setVector(&scratch->position, scratch->offset.vx, scratch->offset.vy + 16,
        scratch->offset.vz);
    gte_ldv0(&scratch->position);
    gte_rtv0tr2();
    attachment = object->unk16C.actorId;

    if (attachment >= 4) {
        MATRIX holderRotation;
        SVECTOR anchors[2];
        D_800F4538_t* holder;

        if (object->unk0.unk12 == 0xFF) {
            goto rotate;
        }

        holder = D_800F4538[object->unk0.unk12];
        func_800A190C(object->unk0.unk12, 0xF0, &anchors[0], 1);
        func_800A190C(object->unk0.unk12, 0xF1, &anchors[1], 1);
        gte_SetRotMatrix(camera);
        gte_SetTransMatrix(camera);
        setVector(&scratch->position, (anchors[0].vx + anchors[1].vx) / 2,
            (anchors[0].vy + anchors[1].vy) / 2, (anchors[0].vz + anchors[1].vz) / 2);
        gte_ldv0(&scratch->position);
        gte_rtv0tr2();
        setVector(&scratch->rotation, object->unk10C.vx + object->unk0.unk24,
            object->unk10C.vy + object->unk0.facing,
            object->unk10C.vz + object->unk0.unk28);
        gte_stlvnl(scratch->matrix.t);
        func_800B17F0(&scratch->rotation, &scratch->matrix);
        setVector(&scratch->rotation, holder->unk0.unk24, holder->unk0.facing,
            holder->unk0.unk28);
        func_800B17F0(&scratch->rotation, &holderRotation);
        func_800B196C(&holderRotation, &scratch->matrix);
    } else if (attachment < 2) {
        if (object->unk0.unk1A != 0) {
            setVector(&scratch->rotation, object->unk0.unk24, object->unk0.facing,
                object->unk0.unk28);
            gte_stlvnl(scratch->matrix.t);
            RotMatrixYXZ_gte(&scratch->rotation, &scratch->matrix);
            func_800B196C(camera, &scratch->matrix);
            MulMatrix(&scratch->matrix, &object->bones[4]);
            goto composed;
        }

        scratch->matrix = object->bones[4];
        gte_stlvnl(scratch->matrix.t);
    } else {
    rotate:
        copyVector(&scratch->rotation, &object->unk10C);
        gte_stlvnl(scratch->matrix.t);
        applyVector(&scratch->rotation, object->unk0.unk24, object->unk0.facing,
            object->unk0.unk28, +=);
        *(int*)&scratch->rotation &= 0x0FFF0FFF;
        *(int*)&scratch->rotation.vz &= 0xFFF;
        func_800B17F0(&scratch->rotation, &scratch->matrix);
    }

    func_800B196C(camera, &scratch->matrix);
composed:
    func_800B396C(&scratch->matrix, &D_800F3C58.scale);
    D_800F3C58.bones[0] = scratch->matrix;
    object->bones[0] = scratch->matrix;

    if (object->unk0.unk2C != 64 || object->unk0.unk2E != 64
        || object->unk0.unk30 != 64) {
        setVector(
            &scratch->scale, object->unk0.unk2C, object->unk0.unk2E, object->unk0.unk30);
        applyVector(&scratch->scale, 64, 64, 64, *=);
        func_800B396C(&scratch->matrix, &scratch->scale);
        D_800F3C58.bones[0] = scratch->matrix;
        object->bones[0] = scratch->matrix;
    }

    D_800F3C78 = scratch->matrix;
    object->bones[1] = scratch->matrix;

    if (!object->unk0.visible
        || !func_800B3A68(
            object, &object->bones[0], -vs_main_nearClip * 4, object->unk0.unk68)) {
        return;
    }

    scratch->tpage = GetTPage(0, 0, 64, 256);

    if (object->unk0.unk64.unk0 != 0 || object->unk0.unk9_0 >= 6) {
        scratch->clut = GetClut(object->unk0.unkF * 16 + 768, 255);
    } else {
        scratch->clut = GetClut(object->unk0.unkF * 16 + 768, 237);
    }

    value =
        object->unk0.unk9_0 >= 4 && object->unk0.unk9_0 < 9 && object->unk0.unk9_0 != 6;

    if (object->unk0.unk9_0 >= 12) {
        value = 1;
    }

    if (value) {
        func_800B5C30(&D_800F2458, object, &object->unk0.unk54, scratch->model);
    } else {
        func_800B4594(&D_800F2458, object, &object->unk0.unk54, scratch->model);
    }
}

void func_800B217C(vs_battle_wepModels_t* weapon, MATRIX* source)
{
    CVECTOR color;
    D_1F80035C_t* scratch = (void*)0x1F80035C;
    D_800F4538_t* actor = D_800F4538[weapon->actorId];
    int value;
    int i;

    scratch->model = (D_800F4538_unk68*)weapon->offsets;
    scratch->matrix = *source;

    if (weapon->unk13 != 0) {
        int target = weapon->unk12;
        int current = weapon->unk11;

        value = target - current;
        value /= weapon->unk13;
        weapon->unk11 = current + value;
        --weapon->unk13;

        if (weapon->unk11 == 0 && weapon->unk13 == 0) {
            weapon->unk8_4 = 0;
        }
    }

    if (weapon->unk11 != 64) {
        value = weapon->unk11;
        value *= 64;
        setVector(&scratch->scale, value, value, value);
        func_800B396C(&scratch->matrix, &scratch->scale);
    }

    D_800F3C58.bones[0] = scratch->matrix;
    weapon->unk20[0] = scratch->matrix;
    scratch->position.vx = scratch->position.vy = 0;

    for (i = 1; i < weapon->nBones; ++i) {
        int parentBone = scratch->model->armatures[i].unk4;

        scratch->parent = &weapon->unk20[parentBone];
        gte_SetRotMatrix(scratch->parent);
        gte_SetTransMatrix(scratch->parent);
        setVector(&scratch->position, -scratch->model->armatures[parentBone].unk0, 0, 0);
        gte_ldv0(&scratch->position);
        gte_rtv0tr2();
        scratch->rotation.vx = weapon->unkBoneInfo[i].vx;
        scratch->rotation.vy = weapon->unkBoneInfo[i].vy;
        scratch->rotation.vz = weapon->unkBoneInfo[i].vz;
        gte_stlvnl(scratch->matrix.t);
        *(int*)&scratch->rotation &= 0x0FFF0FFF;
        *(int*)&scratch->rotation.vz &= 0xFFF;
        func_800B17F0(&scratch->rotation, &scratch->matrix);
        func_800B196C(&D_800F3C58.bones[parentBone], &scratch->matrix);
        D_800F3C58.bones[i] = scratch->matrix;
        weapon->unk20[i] = scratch->matrix;
    }

    if (!actor->unk0.visible
        || (actor->unk0.position.vy >= 256
            && (actor->unk0.unkF == 0 || func_800BEB00() != 4))) {
        return;
    }

    if (!func_800B3A68(
            weapon, &weapon->unk20[0], -vs_main_nearClip * 4, weapon->offsets)) {
        return;
    }

    scratch->tpage = vs_battle_wepTextures[weapon->texSlot].tpage;
    scratch->clut = vs_battle_wepTextures[weapon->clutSlotOffset].clut0;
    value = actor->unk0.unk9_0 >= 4 && actor->unk0.unk9_0 < 9 && actor->unk0.unk9_0 != 6;

    if (actor->unk0.unk9_0 == 15) {
        value = 1;
    }

    if (weapon->unk8_6) {
        color.r = weapon->unk5C0;
        color.g = weapon->unk5C0;
        color.b = weapon->unk5C0;
    } else {
        memcpy(&color, &actor->unk0.unk54, sizeof color);
    }

    if (value) {
        func_800B516C(&D_800F2458, weapon, &color, scratch->model);
    } else {
        func_800B3CF0(&D_800F2458, weapon, &color, scratch->model);
    }
}

void func_800B26B8(D_800F4538_t* actor, MATRIX* parent, int bone, int saved)
{
    D_1F80035C_t* scratch = (void*)0x1F80035C;

    scratch->matrix = *(actor->unk1890 + saved - 1);
    func_800B196C(parent, &scratch->matrix);
    gte_SetRotMatrix(parent);
    gte_SetTransMatrix(parent);
    --saved;
    setVector(&scratch->position, actor->unk1890[saved].t[0], actor->unk1890[saved].t[1],
        actor->unk1890[saved].t[2]);
    gte_ldv0(&scratch->position);
    gte_rtv0tr2();
    gte_stlvnl(scratch->matrix.t);
    D_800F3C58.bones[bone] = scratch->matrix;
    actor->bones[bone] = scratch->matrix;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/49268", func_800B28A8);
