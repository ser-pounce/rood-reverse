#include "common.h"
#include <rand.h>
#include <abs.h>
#include <inline_c.h>
#include "vs_inline_c.h"
#include "146C.h"
#include "3A1A0.h"
#include "44F14.h"
#include "../../SLUS_010.40/main.h"

extern struct {
    char prefix[0x1FD0];
    int scales[3];
} D_800F2458;

typedef struct {
    char prefix[0x34];
    u_short tpage, clut;
    char pad38[0x14];
    SVECTOR translation, position;
    MATRIX* parent;
    int pad60;
    MATRIX matrix;
    SVECTOR rotation;
    VECTOR scale;
    char* model;
} weaponTransformScratch;
extern MATRIX D_800F3C58[];
extern MATRIX D_800F3C78;
void func_800B17F0(SVECTOR*, MATRIX*);
void func_800B196C(MATRIX*, MATRIX*);
void func_800B396C(MATRIX*, VECTOR*);
int func_800B3A68(void*, MATRIX*, int, void*);
void func_800B4594(void*, void*, void*, void*);
void func_800B5C30(void*, void*, void*, void*);
int func_800A190C(int, int, SVECTOR*, int);

void func_800B1A68(D_800F45E0_t* object, MATRIX* camera)
{
    MATRIX local;
    SVECTOR points[2];
    weaponTransformScratch* scratch = (void*)0x1F80035C;
    D_800F4538_t* actor;
    u_int kind;
    u_int flags;
    int value;

    scratch->model = (char*)object->unk68;
    gte_SetRotMatrix(camera);
    gte_SetTransMatrix(camera);
    scratch->translation.vx = scratch->position.vx;
    scratch->translation.vy = scratch->position.vy + 16;
    scratch->translation.vz = scratch->position.vz;
    gte_ldv0((void*)0x1F8003A8);
    gte_rtv0tr2();
    kind = object->unk6C[8].actorId;
    if (kind >= 4) {
        if (object->unk12 == 0xFF) {
            goto rotate;
        }
        actor = D_800F4538[object->unk12];
        func_800A190C(object->unk12, 0xF0, &points[0], 1);
        func_800A190C(object->unk12, 0xF1, &points[1], 1);
        gte_SetRotMatrix(camera);
        gte_SetTransMatrix(camera);
        scratch->translation.vx = (points[0].vx + points[1].vx) / 2;
        scratch->translation.vy = (points[0].vy + points[1].vy) / 2;
        scratch->translation.vz = (points[0].vz + points[1].vz) / 2;
        gte_ldv0((void*)0x1F8003A8);
        gte_rtv0tr2();
        scratch->rotation.vx = ((SVECTOR*)&object->unk6C[5])->vx + object->unk24;
        scratch->rotation.vy = ((SVECTOR*)&object->unk6C[5])->vy + object->unk26;
        scratch->rotation.vz =
            ((SVECTOR*)&object->unk6C[5])->vz + *(short*)&object->unk28;
        gte_stlvnl((void*)0x1F8003D4);
        func_800B17F0((SVECTOR*)0x1F8003E0, (MATRIX*)0x1F8003C0);
        scratch->rotation.vx = actor->unk0.unk24;
        scratch->rotation.vy = actor->unk0.facing;
        scratch->rotation.vz = actor->unk0.unk28;
        func_800B17F0((SVECTOR*)0x1F8003E0, &local);
        func_800B196C(&local, (MATRIX*)0x1F8003C0);
    } else if (kind < 2) {
        if (object->unk1A != 0) {
            scratch->rotation.vx = object->unk24;
            scratch->rotation.vy = object->unk26;
            scratch->rotation.vz = *(short*)&object->unk28;
            gte_stlvnl((void*)0x1F8003D4);
            RotMatrixYXZ_gte((SVECTOR*)0x1F8003E0, (MATRIX*)0x1F8003C0);
            func_800B196C(camera, (MATRIX*)0x1F8003C0);
            ((void (*)(MATRIX*, MATRIX*))CompMatrixLV)(
                (MATRIX*)0x1F8003C0, (MATRIX*)&object->unk6C[4]);
            goto composed;
        }
        *(MATRIX*)0x1F8003C0 = *(MATRIX*)&object->unk6C[4];
        gte_stlvnl((void*)0x1F8003D4);
    } else {
    rotate:
        scratch->rotation.vx = ((SVECTOR*)&object->unk6C[5])->vx;
        scratch->rotation.vy = ((SVECTOR*)&object->unk6C[5])->vy;
        scratch->rotation.vz = ((SVECTOR*)&object->unk6C[5])->vz;
        gte_stlvnl(scratch->matrix.t);
        scratch->rotation.vx += object->unk24;
        scratch->rotation.vy += object->unk26;
        scratch->rotation.vz += *(short*)&object->unk28;
        *(int*)&scratch->rotation &= 0x0FFF0FFF;
        *(int*)&scratch->rotation.vz &= 0xFFF;
        func_800B17F0(&scratch->rotation, &scratch->matrix);
    }
    func_800B196C(camera, &scratch->matrix);
composed:
    func_800B396C(&scratch->matrix, (VECTOR*)&D_800F3C58[63]);
    D_800F3C58[0] = scratch->matrix;
    *(MATRIX*)&object->unk6C[0] = scratch->matrix;
    if (*(int*)&object->unk2C != 0x400040 || object->unk30 != 64) {
        scratch->scale.vx = object->unk2C;
        scratch->scale.vy = object->unk2E;
        scratch->scale.vz = object->unk30;
        scratch->scale.vx <<= 6;
        scratch->scale.vy <<= 6;
        scratch->scale.vz <<= 6;
        func_800B396C(&scratch->matrix, &scratch->scale);
        D_800F3C58[0] = scratch->matrix;
        *(MATRIX*)&object->unk6C[0] = scratch->matrix;
    }
    D_800F3C78 = scratch->matrix;
    *(MATRIX*)&object->unk6C[1] = scratch->matrix;
    if (*(int*)((char*)object + 8) & 2) {
        if (func_800B3A68(object, (MATRIX*)&object->unk6C[0], (-vs_main_nearClip) << 2,
                object->unk68)) {
            scratch->tpage = GetTPage(0, 0, 0x40, 0x100);
            if (object->unk64.unk0 != 0
                || ((*(u_int*)((char*)object + 8) >> 8) & 0xF) >= 6) {
                scratch->clut = GetClut((object->unkF << 4) + 0x300, 0xFF);
            } else {
                scratch->clut = GetClut((object->unkF << 4) + 0x300, 0xED);
            }
            flags = *(u_int*)((char*)object + 8);
            value = 0;
            if (((flags >> 8) & 0xF) - 4 < 5) {
                if ((flags & 0xF00) != 0x600)
                    value = 1;
            }
            if (((flags >> 8) & 0xF) >= 12) {
                value = 1;
            }
            if (value) {
                func_800B5C30(&D_800F2458, object, &object->unk54, scratch->model);
                return;
            }
            func_800B4594(&D_800F2458, object, &object->unk54, scratch->model);
        }
    }
}

typedef struct {
    char prefix[0x20];
    MATRIX matrix;
} weaponMatrix;
typedef struct {
    char prefix[0xA0];
    SVECTOR rotation;
} weaponRotation;
extern MATRIX D_800F3C58[];
void func_800B17F0(SVECTOR*, MATRIX*);
void func_800B196C(MATRIX*, MATRIX*);
void func_800B396C(MATRIX*, VECTOR*);
int func_800B3A68(void*, MATRIX*, int, void*);
short func_800BEB00(void);
void func_800B516C(void*, void*, void*, void*);
void func_800B3CF0(void*, void*, void*, void*);

void func_800B217C(vs_battle_wepModels_t* weapon, MATRIX* source)
{
    CVECTOR color;
    weaponTransformScratch* scratch = (void*)0x1F80035C;
    D_800F4538_t* actor = D_800F4538[weapon->actorId];
    int value, i, parentOffset, parentBone, current, target, length;
    weaponRotation* rotation;
    unsigned int flags;
    scratch->model = (char*)weapon->offsets;
    *(MATRIX*)0x1F8003C0 = *source;
    if (weapon->unk13 != 0) {
        target = weapon->unk12;
        current = weapon->unk11;
        value = target - current;
        value /= weapon->unk13;
        weapon->unk11 = current + value;
        --weapon->unk13;
        if ((*(int*)&weapon->clutSlotOffset & 0xFF00FF00) == 0)
            *(int*)((char*)weapon + 8) &= ~0x10;
    }
    if (weapon->unk11 != 64) {
        value = weapon->unk11;
        value <<= 6;
        scratch->scale.vx = value;
        scratch->scale.vy = value;
        scratch->scale.vz = value;
        func_800B396C(&scratch->matrix, &scratch->scale);
    }
    D_800F3C58[0] = scratch->matrix;
    ((weaponMatrix*)weapon)->matrix = scratch->matrix;
    scratch->translation.vx = scratch->translation.vy = 0;
    for (i = 1; i < weapon->nBones; ++i) {
        parentBone = *(u_char*)(scratch->model + (i << 4) + 0x44);
        parentOffset = parentBone << 5;
        scratch->parent = (MATRIX*)((char*)weapon + (parentOffset + 0x20));
        gte_SetRotMatrix(scratch->parent);
        gte_SetTransMatrix(scratch->parent);
        length = *(u_short*)(scratch->model + (parentBone << 4) + 0x40);
        scratch->translation.vy = 0;
        scratch->translation.vz = 0;
        scratch->translation.vx = -length;
        gte_ldv0(&scratch->translation);
        gte_rtv0tr2();
        rotation = (weaponRotation*)((char*)weapon + (i << 3));
        scratch->rotation.vx = rotation->rotation.vx;
        scratch->rotation.vy = rotation->rotation.vy;
        scratch->rotation.vz = rotation->rotation.vz;
        gte_stlvnl(scratch->matrix.t);
        *(int*)&scratch->rotation &= 0x0FFF0FFF;
        *(int*)&scratch->rotation.vz &= 0xFFF;
        func_800B17F0(&scratch->rotation, &scratch->matrix);
        func_800B196C((MATRIX*)(parentOffset + (int)D_800F3C58), &scratch->matrix);
        D_800F3C58[i] = scratch->matrix;
        ((weaponMatrix*)((char*)weapon + (i << 5)))->matrix = scratch->matrix;
    }
    if (*(int*)((char*)actor + 8) & 2) {
        if (*(short*)((char*)actor + 0x1E) >= 256) {
            if (actor->unk0.unkF == 0 || func_800BEB00() != 4)
                return;
        }
        if (func_800B3A68(weapon, &((weaponMatrix*)weapon)->matrix,
                (-vs_main_nearClip) << 2, weapon->offsets)) {
            scratch->tpage = vs_battle_wepTextures[weapon->texSlot].tpage;
            scratch->clut = vs_battle_wepTextures[weapon->clutSlotOffset].clut0;
            flags = *(u_int*)((char*)actor + 8);
            value = 0;
            if (((flags >> 8 & 15) - 4) < 5) {
                value = 1;
                if ((flags & 0xF00) == 0x600)
                    value = 0;
            }
            if ((flags & 0xF00) == 0xF00)
                value = 1;
            if (*(int*)((char*)weapon + 8) & 0x40) {
                color.r = weapon->unk5C0;
                color.g = weapon->unk5C0;
                color.b = weapon->unk5C0;
            } else {
                *(int*)&color = *(int*)((char*)actor + 0x54);
            }
            if (value) {
                func_800B516C(&D_800F2458, weapon, &color, scratch->model);
                return;
            }
            func_800B3CF0(&D_800F2458, weapon, &color, scratch->model);
        }
    }
}

typedef struct {
    char prefix[0x1870];
    MATRIX matrix;
} savedBoneMatrix;
typedef struct {
    char prefix[0x6C];
    MATRIX matrix;
} actorBoneMatrix;
typedef struct {
    char prefix[0x4C];
    SVECTOR translation;
} boneTransformScratch;
extern MATRIX D_800F3C58[];
void func_800B196C(MATRIX*, MATRIX*);
void func_800B26B8(void* actor, MATRIX* parent, int bone, int saved)
{
    boneTransformScratch* scratch = (void*)0x1F80035C;
    MATRIX* matrix = (void*)0x1F8003C0;
    char* savedAddress;
    int boneOffset;
    actorBoneMatrix* destination;
    MATRIX* table;
    *matrix = ((savedBoneMatrix*)((saved << 5) + (int)actor))->matrix;
    func_800B196C(parent, matrix);
    gte_SetRotMatrix(parent);
    gte_SetTransMatrix(parent);
    savedAddress = (char*)actor + ((saved - 1) << 5);
    scratch->translation.vx = *(u_short*)(savedAddress + 0x18A4);
    scratch->translation.vy = *(u_short*)(savedAddress + 0x18A8);
    scratch->translation.vz = *(u_short*)(savedAddress + 0x18AC);
    gte_ldv0((void*)0x1F8003A8);
    gte_rtv0tr2();
    gte_stlvnl((void*)0x1F8003D4);
    table = D_800F3C58;
    boneOffset = bone << 5;
    *(MATRIX*)(boneOffset + (int)table) = *matrix;
    destination = (void*)(boneOffset + (int)actor);
    destination->matrix = *matrix;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/49268", func_800B28A8);
