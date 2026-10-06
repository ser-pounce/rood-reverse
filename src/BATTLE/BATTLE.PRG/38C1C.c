#include "common.h"
#include "3A1A0.h"
#include <libgpu.h>
#include <inline_c.h>
#include "vs_inline_c.h"
#include <abs.h>

void func_8009DF3C(int, int);
int func_800A152C(int, int, int);
int func_800A17BC(int, int, void*, int*);
int func_800A1C10(int arg0, int arg1, u_short* arg2, int arg3);
MATRIX* func_800A1DE8(int, int, MATRIX*);
void func_800A9EB4(int, int, int);

extern MATRIX D_800F49B8;

int func_800A141C(int arg0, int arg1, int arg2, int arg3)
{
    SVECTOR sp0;
    MATRIX* v0;
    D_800F4538_unk68* temp_v1;
    D_800F4538_t* var_v1 = D_800F4538[arg0];

    if (var_v1 == NULL) {
        var_v1 = (D_800F4538_t*)D_800F45E0[arg0];
        if (var_v1 == NULL) {
            return -1;
        }
    }

    v0 = &var_v1->bones[arg1];
    temp_v1 = var_v1->unk0.unk68;

    __asm__ volatile("lw $t4,0(%0);"
                     "lw $t5,4(%0);"
                     "ctc2 $t4, $0;"
                     "ctc2 $t5, $1;"
                     "lw $t4,8(%0);"
                     "lw $t5,0xc(%0);"
                     "lw $t6,0x10(%0);"
                     "ctc2 $t4, $2;"
                     "ctc2 $t5, $3;"
                     "ctc2 $t6, $4;"
                     "lw $t4,0x14(%0);"
                     "lw $t5,0x18(%0);"
                     "ctc2 $t4, $5;"
                     "lw $t6,0x1c(%0);"
                     "ctc2 $t5, $6;"
                     "ctc2 $t6, $7"
        :
        : "r"(v0));

    if (arg3 == 0) {
        sp0.vx = 0;
    } else {
        if (arg3 == 1) {
            sp0.vx = -(u_short)temp_v1->armatures[arg1].unk0;
        } else {
            sp0.vx = -temp_v1->armatures[arg1].unk0 / 2;
        }
    }

    sp0.vy = 0;
    sp0.vz = 0;
    sp0.pad = 0;

    __asm__ volatile("lwc2	$0,0(%0);"
                     "lwc2	$1,4(%0);"
                     "nop;"
                     "nop;"
                     "rtps;"
                     "swc2 $14,0x0($a2);"
                     "addu $v0,$a2,4;"
                     "swc2 $19,0x0($v0);"
        :
        : "r"(&sp0));

    return 0;
}

int func_800A152C(int arg0, int arg1, int arg2)
{
    D_800F4538_t* var_v0_2;
    D_800F4538_unk68* var_v1;
    int i;
    int nBones;
    int new_var;

    var_v0_2 = D_800F4538[arg0];

    if (var_v0_2 == NULL) {
        var_v0_2 = (D_800F4538_t*)D_800F45E0[arg0];
        if (var_v0_2 == NULL) {
            return -1;
        }
    }

    nBones = var_v0_2->unk0.nBones;
    var_v1 = var_v0_2->unk0.unk68;

    do {
        if (arg1 == 0xFF) {
            return 0;
        }
    } while (0);

    for (i = 0; i < nBones; ++i) {
        switch (arg2) {
        case 0:
            if (var_v1->armatures[i].unk6 == (arg1 & 0xFF)) {
                return i;
            }
            break;

        case 1:
            new_var = (var_v1->armatures[i].unk7 >> 4) == ((arg1 & 0xFF) + 1);
            if (new_var) {
                return i;
            }
            break;

        case 2:
            if ((var_v1->armatures[i].unk7 & 0xF) == ((arg1 & 0xFF) + 1)) {
                return i;
            }
            break;

        case 3:
            if (var_v1->armatures[i].unk8 == (arg1 & 0xFF)) {
                return i;
            }
            break;
        }
    }

    return -4;
}

int func_800A1648(int arg0, int arg1, int arg2)
{
    D_800F4538_t* actor;
    D_800F4538_unk68* model;
    u_int v;

    actor = D_800F4538[arg0];
    if (actor == NULL) {
        actor = (D_800F4538_t*)D_800F45E0[arg0];
        if (actor == NULL) {
            return -1;
        }
    }
    model = actor->unk0.unk68;
    switch (arg2) {
    case 0:
        v = model->armatures[arg1].unk6;
        break;
    case 1:
        v = model->armatures[arg1].unk7 >> 4;
        if (v == 0) {
            return -3;
        }
        break;
    case 2:
        v = model->armatures[arg1].unk7 & 0xF;
        if (v == 0) {
            return -3;
        }
        break;
    }
    return v;
}

int func_800A1720(int arg0, int arg1, int* arg2, int* arg3)
{
    int var_v0 = arg1;

    if (arg1 == 0xFD) {
        var_v0 = 0;
    }

    var_v0 = func_800A17BC(arg0, var_v0, arg2, arg3);

    if (var_v0 < 0) {
        return var_v0;
    }

    if (arg1 == 0xFD) {
        arg2[6] = D_800F4538[arg0]->unk0.position.vy;
    }

    return 0;
}

int func_800A17BC(int arg0, int arg1, void* arg2, int* arg3)
{
    D_800F4538_t* actor;
    D_800F4538_t* obj;
    vs_battle_wepModels_t* model;
    int _[22] __attribute__((unused));

    *(MATRIX*)arg2 = *func_800A1DE8(arg0, arg1, &D_800F49B8);

    actor = D_800F4538[arg0];
    if (actor == NULL) {
        obj = (D_800F4538_t*)D_800F45E0[arg0];
        if (obj == NULL) {
            return 0;
        }
        *arg3 = obj->unk0.unk68->armatures[arg1].unk0;
    } else if (arg1 == 0xFF) {
        *arg3 = 0;
    } else if ((arg1 & 0xF0) == 0x40) {
        model = vs_battle_wepModels[arg0 * 2];
        if (model == NULL) {
            return 0;
        }
        *arg3 = ((D_800F4538_unk68*)model->offsets)->armatures[arg1 - 0x3F].unk0;
    } else {
        *arg3 = actor->unk0.unk68->armatures[arg1].unk0;
    }
    return 0;
}

int func_800A190C(int arg0, int arg1, SVECTOR* arg2, int arg3)
{
    D_800F4538_t* var_a2;
    int var_v0;

    if (arg1 == 0xFB) {
        var_a2 = D_800F4538[arg0];

        if (var_a2 == NULL) {
            var_a2 = (D_800F4538_t*)D_800F45E0[arg0];
            if (var_a2 == NULL) {
                return -1;
            }

            *arg2 = var_a2->unk0.position;
            arg2->vy -= 0xC0;
        } else {
            *arg2 = var_a2->unk0.position;
            arg2->vy -= var_a2->unk646;
        }

        return 0;
    }

    if (arg1 == 0xFD) {
        *arg2 = D_800F4538[arg0]->unk0.position;
        return 0;
    }

    if ((arg1 & 0xF0) == 0x40) {
        var_v0 = arg1;
    } else if (arg1 == 0xFA) {
        var_a2 = D_800F4538[arg0];
        *arg2 = var_a2->unk0.position;
        var_v0 = var_a2->unk65A * var_a2->unk183C / ONE;
        arg2->vy += var_v0;
        return 0;
    } else {
        var_v0 = func_800A152C(arg0, arg1, 0);

        if (var_v0 < 0) {
            return var_v0;
        }
    }

    var_v0 = func_800A1C10(arg0, var_v0, (u_short*)arg2, arg3);

    if (var_v0 < 0) {
        return var_v0;
    }

    return 0;
}

int func_800A1AF8(int arg0, int arg1, u_short* arg2, int arg3)
{
    int var_v0 = func_800A1C10(arg0, arg1, arg2, arg3);

    if (var_v0 < 0) {
        return var_v0;
    }

    return 0;
}

int func_800A1B28(int arg0, int arg1, u_short* arg2, int arg3)
{
    int var_v0 = func_800A152C(arg0, arg1, 1);

    if (var_v0 < 0) {
        return var_v0;
    }

    var_v0 = func_800A1C10(arg0, var_v0, arg2, arg3);

    if (var_v0 < 0) {
        return var_v0;
    }

    return 0;
}

int func_800A1B9C(int arg0, int arg1, u_short* arg2, int arg3)
{
    int var_v0 = func_800A152C(arg0, arg1, 2);

    if (var_v0 < 0) {
        return var_v0;
    }

    var_v0 = func_800A1C10(arg0, var_v0, arg2, arg3);

    if (var_v0 < 0) {
        return var_v0;
    }

    return 0;
}

int func_800A1C10(int actorId, int bone, u_short* result, int endpoint)
{
    SVECTOR local;
    VECTOR transformed;
    D_800F4538_t* actor = D_800F4538[actorId];
    D_800F4538_unk68* model = actor->unk0.unk68;
    MATRIX* matrix;
    vs_battle_wepModels_t* weapon;
    if (actor == NULL) {
        actor = (D_800F4538_t*)D_800F45E0[actorId];
        if (actor == NULL)
            return -1;
        model = actor->unk0.unk68;
    }
    matrix = func_800A1DE8(actorId, bone, &D_800F49B8);
    if (endpoint == 0) {
        result[0] = matrix->t[0];
        result[1] = matrix->t[1];
        result[2] = matrix->t[2];
        return 0;
    }
    local.vy = 0;
    local.vz = 0;
    if ((bone & 0xF0) == 0x40) {
        weapon = vs_battle_wepModels[actorId * 2];
        bone -= 0x3F;
        if (weapon == NULL)
            return -1;
        model = *(D_800F4538_unk68**)((char*)weapon + 0x1C);
    }
    if (endpoint == 1)
        local.vx = -(u_short)model->armatures[bone].unk0;
    else
        local.vx = -model->armatures[bone].unk0 / 2;
    gte_SetRotMatrix(matrix);
    gte_SetTransMatrix(matrix);
    gte_ldv0(&local);
    gte_rtv0tr2();
    gte_stlvnl(&transformed);
    result[0] = transformed.vx;
    result[1] = transformed.vy;
    result[2] = transformed.vz;
    return 0;
}

typedef struct {
    char prefix[0x4C];
    SVECTOR position;
    SVECTOR offset;
    char padding[8];
    MATRIX matrix;
} boneMatrixScratch;

void func_800B07DC(D_800F4538_t*);
void func_80041C68(MATRIX*, MATRIX*);

MATRIX* func_800A1DE8(int actorId, int bone, MATRIX* unused)
{
    MATRIX zeroTranslation;
    long flag;
    boneMatrixScratch* scratch = (void*)0x1F80035C;
    D_800F4538_t* actor = D_800F4538[actorId];
    vs_battle_wepModels_t* weapon;
    MATRIX* camera;
    MATRIX* result;
    if (actor == NULL) {
        D_800F45E0_t* object = D_800F45E0[actorId];
        if (object == NULL)
            return NULL;
        scratch->matrix = *(MATRIX*)&object->unk6C[bone];
    } else if ((bone & 0xF0) == 0x40) {
        weapon = vs_battle_wepModels[actorId * 2];
        if (weapon == NULL)
            return NULL;
        scratch->matrix = ((MATRIX*)((char*)weapon + 32))[bone - 63];
    } else if (bone == 255) {
        scratch->offset.vx = (short)*(u_short*)((char*)actor + 0x84C) >> 1;
        scratch->offset.vy = (short)*(u_short*)((char*)actor + 0x84E) >> 1;
        scratch->offset.vz = (short)*(u_short*)((char*)actor + 0x850) >> 1;
        scratch->offset.vx = scratch->offset.vx * actor->unk183C / 4096;
        scratch->offset.vy = scratch->offset.vy * actor->unk183C / 4096;
        scratch->offset.vz = scratch->offset.vz * actor->unk183C / 4096;
        func_800B07DC(actor);
        scratch->matrix.t[0] = scratch->offset.vx;
        scratch->matrix.t[1] = scratch->offset.vy;
        scratch->matrix.t[2] = scratch->offset.vz;
        return &scratch->matrix;
    } else {
        scratch->matrix = actor->bones[bone];
    }
    camera = &D_800F49B8;
    result = &scratch->matrix;
    func_80041C68(camera, result);
    SetRotMatrix(camera);
    zeroTranslation.t[0] = 0;
    zeroTranslation.t[1] = 0;
    zeroTranslation.t[2] = 0;
    SetTransMatrix(&zeroTranslation);
    scratch->position.vx = scratch->matrix.t[0] - camera->t[0];
    scratch->position.vy = scratch->matrix.t[1] - camera->t[1];
    scratch->position.vz = scratch->matrix.t[2] - camera->t[2];
    RotTrans(&scratch->position, (VECTOR*)scratch->matrix.t, &flag);
    return result;
}

SVECTOR* func_800A4A24(int);
int func_800A3500(int, int);
void func_800AE4FC(D_800F4538_unk0*, int);
void func_800A0204(int, int, int, int);

extern u_char D_800E90AC[];
extern u_char D_800E90B4[];

void func_800A208C(D_800F4538_t* actor, u_char* target, int speed, short facing)
{
    int x;
    int y;
    int z;
    int i;
    int dz;
    int minFrames;
    int accel;
    int animation;
    int hangFrames;
    int frames;
    int fall;
    int velocity;
    SVECTOR* anchor;
    int _[2] __attribute__((unused));

    if (*(u_int*)((char*)actor + 8) & 0x70000) {
        return;
    }

    actor->unk0.unk11 = 6;
    *(u_int*)((char*)actor + 0x5AC) &= ~0x4000000;
    if (speed >= actor->unk5B9) {
        actor->unk0.unk11 = 2;
    }
    if (speed < 18) {
        speed = 18;
        *(u_int*)((char*)actor + 0x5AC) |= 0x4000000;
    }

    if (target[1] >= 2) {
        anchor = func_800A4A24(target[1]);
        x = anchor->vx;
        y = anchor->vy;
        z = anchor->vz;
    } else {
        x = target[0] * 128 + 64;
        z = target[2] * 128 + 64;
        y = func_800A3500(x, z);
    }

    *(int*)&actor->unk5EC = *(int*)target;
    actor->unk1814 = x;
    actor->unk1818 = z;
    x -= actor->unk0.position.vx;
    y -= actor->unk0.position.vy;
    z -= actor->unk0.position.vz;

    i = x;
    if (x < 0) {
        i = -x;
    }
    dz = z;
    if (z < 0) {
        dz = -z;
    }
    if (i < dz) {
        i = dz;
    }
    minFrames = i / speed;

    if (*(u_int*)((char*)actor + 8) & 0x400000) {
        accel = 1;
        animation = 33;
    } else {
        accel = 6;
        animation = 47;
    }

    if (y <= 0) {
        if (actor->unk0.unkF != 0) {
            func_800AE4FC(&actor->unk0, 12);
        }
        i = y >= -64;
        if (*(u_int*)((char*)actor + 8) & 0x400000) {
            i += 3;
        }
        hangFrames = D_800E90AC[i];
        y -= D_800E90B4[i];
    retry:
        for (frames = 0, fall = 0, velocity = 0; y < fall; ++frames) {
            velocity += accel;
            fall -= velocity / 2;
        }
        frames += hangFrames;
        actor->unk0.unk34.vx = x / frames;
        actor->unk0.unk34.vz = z / frames;
        actor->unk0.unk34.vy = -velocity / 2;
        if (ABS(actor->unk0.unk34.vx) > speed || ABS(actor->unk0.unk34.vz) > speed) {
            ++hangFrames;
            y -= ((hangFrames + 1) * accel) / 2;
            goto retry;
        }
    } else {
        i = 2;
        if (*(u_int*)((char*)actor + 8) & 0x400000) {
            i = 5;
        }
        hangFrames = D_800E90AC[i];
        y += D_800E90B4[i];
        if ((*(u_int*)((char*)actor + 8) & 0x400000) && (y > 128)) {
            y = 128;
        }
        for (frames = 0, fall = 0, velocity = 0; fall < y; ++frames) {
            velocity += accel;
            fall += velocity / 2;
        }
        frames += hangFrames;
        if (frames < minFrames) {
            hangFrames += (minFrames - frames) / 2 + 1;
            frames = minFrames;
        }
        actor->unk0.unk34.vx = x / frames;
        actor->unk0.unk34.vz = z / frames;
        actor->unk0.unk34.vy = (-(hangFrames + 1) * accel) / 2;
        if (*(u_int*)((char*)actor + 8) & 0x400000) {
            animation = 35;
        }
    }

    actor->unk1816 = frames;
    actor->unk181A = 2;
    func_800A0204(actor->unk0.unkF, animation, 0, 4);
    *(u_int*)((char*)actor + 8) = (*(u_int*)((char*)actor + 8) & ~0x70000) | 0x20000;
    func_800A9EB4(actor->unk0.unkF, facing, 8);
}

void func_800A249C(int arg0, int arg1)
{
    int var_a2;
    int var_a1;
    int v1;
    D_800F4538_t* temp_a3 = D_800F4538[arg0];

    if (temp_a3->unk0.unkA_5) {
        return;
    }

    var_a1 = arg1 - temp_a3->unk0.facing;

    if (var_a1 > 0x800) {
        var_a1 -= 0x1000;
    }

    if (var_a1 < -0x800) {
        var_a1 += 0x1000;
    }

    if (var_a1 == 0) {
        return;
    }

    temp_a3->unk1848.unk0 = 6;

    v1 = temp_a3->animationId;

    if ((v1 == 0x76) || (temp_a3->animationId == 0x75) || temp_a3->unk0.unkC_0) {
        return;
    }

    var_a2 = 0x1F;

    if (!(temp_a3->unk0.unkA_6)) {

        var_a2 = 0x11;

        if (var_a1 < 0) {
            var_a2 = 0x12;
        }
    }

    func_800A0204(arg0, var_a2, 0, 0xA);
}

void func_800A2574(int arg0, short arg1)
{
    D_800F4538_t* temp_s1 = D_800F4538[arg0];
    func_800A9EB4(arg0, arg1, 8);
    func_8009DF3C(arg0, 3);
    temp_s1->unk0.unkB_4 = 6;
}

int func_800A6EE8(SVECTOR*, int, int, int);
void* func_800A8D64(SVECTOR*, int);
void func_800AC690(int, void*);

void func_800A25EC(D_800F4538_t* actor)
{
    SVECTOR next;
    actor->unk0.unkA_5 = 0;
    next.vx = actor->unk1848.unk10.vx;
    next.vy = 0;
    next.vz = actor->unk1848.unk10.vz;
    next.vy = func_800A6EE8(&actor->unk0.position, next.vx, next.vz, 1);
    if (next.vy == -3000)
        return;
    next.vx += actor->unk0.position.vx;
    next.vz += actor->unk0.position.vz;
    if (func_800A8D64(&next, 0) == NULL)
        return;
    actor->unk0.position.vx = next.vx;
    actor->unk0.position.vz = next.vz;
    if (*(u_int*)((char*)actor + 8) & 0x70000) {
        func_800AC690(actor->unk0.unkF, actor);
    } else {
        short height = next.vy;
        if (height > actor->unk0.position.vy && height - actor->unk0.position.vy >= 64) {
            actor->unk0.unk34.vx = 0;
            actor->unk0.unk34.vy = 0;
            actor->unk0.unk34.vz = 0;
            func_800A0204(actor->unk0.unkF, 47, 0, 4);
            actor->unk181A = 0;
            actor->unk0.unkA_3 = 0;
            actor->unk0.unk9_6 = 0;
            actor->unk0.unkA_0 = 3;
        } else {
            actor->unk0.position.vy = height;
        }
    }
    actor->unk0.currentTileX = actor->unk0.position.vx / 128;
    actor->unk0.currentTileZ = actor->unk0.position.vz / 128;
    actor->unk0.unk5D = 0;
}

void func_800AA850(int, int, int);

void func_800A2790(D_800F4538_t* actor)
{
    VECTOR delta;
    int speed = actor->unk1848.unk8;
    int animation;
    delta.vx = actor->unk1848.unk10.vx * speed / 0x1000000;
    delta.vy = actor->unk1848.unk10.vy * speed / 0x1000000;
    delta.vz = actor->unk1848.unk10.vz * speed / 0x1000000;
    actor->unk0.position.vx += delta.vx;
    actor->unk0.position.vy += delta.vy;
    actor->unk0.position.vz += delta.vz;
    actor->unk0.currentTileX = actor->unk0.position.vx / 128;
    actor->unk0.currentTileZ = actor->unk0.position.vz / 128;
    *(u_int*)((char*)actor + 8) |= 0x200000;
    func_800AA850(actor->unk0.unkF, actor->unk1848.unk6, 12);
    animation = 1;
    if (speed > 0) {
        if (delta.vy < -2)
            animation = 32;
        else {
            animation = 31;
            if (delta.vy >= 3)
                animation = 34;
        }
        if (speed >= 12)
            animation += 6;
    }
    if (actor->animationId != animation) {
        func_800A0204(actor->unk0.unkF, animation, 0, 4);
    }
}

void func_800A291C(D_800F4538_t* arg0)
{
    addVector(&arg0->unk0.position, &arg0->unk1848.unk10);

    arg0->unk0.currentTileX = arg0->unk0.position.vx / 128;
    arg0->unk0.currentTileZ = arg0->unk0.position.vz / 128;

    func_800AA850(arg0->unk0.unkF, arg0->unk1848.unk6, 12);
}
