#include "common.h"
#include <rand.h>
#include <abs.h>
#include <inline_c.h>
#include "vs_inline_c.h"
#include "146C.h"
#include "3A1A0.h"
#include "44F14.h"
#include "../../SLUS_010.40/main.h"

void func_8008EB04(int*, int*);
int func_800A91DC(int, int, int);
u_char** func_800AD494(D_800F4538_t*, u_char, u_short**);
/* Some callers supply an ignored fourth argument; the decoder uses state->unk544. */
void func_800AD714(D_800F4538_t*, D_800F4538_unkC54*, int, ...);
void func_800AF844(SVECTOR*, SVECTOR*, int);
void func_800B147C(D_800F4538_unkC54*, D_800F4538_unkC54*, int, int, int);

extern u_char D_800E91A4[];
extern u_char D_800E9278[];

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800AD714);

void func_800AE46C(void) { }

void func_800AE474(void) { }

void func_800AE47C(D_800F4538_t* arg0)
{
    u_short* sp10;
    int var_v1;
    void* var_a3;

    u_char** v0 = func_800AD494(arg0, arg0->animationId, &sp10);
    u_char* temp_a3 = *v0;
    temp_a3 += sp10[2];

    var_v1 = temp_a3[0];

    if (var_v1 == 0xFF) {
        var_a3 = temp_a3 + 2;
        var_v1 = temp_a3[1] + 0xFF;
    } else {
        var_a3 = temp_a3 + 1;
    }

    arg0->unk704.unk542 = var_v1;
    arg0->unk704.unk544 = var_a3;

    func_800AD714(arg0, &arg0->unk704, 2, var_a3);
}

void func_800AE4FC(D_800F4538_unk0* arg0, int arg1)
{
    D_800F4538_t* actor;
    int temp;
    int sp[2];
    int type = arg1;

    if (arg0->position.vy >= 0xBB8) {
        return;
    }

    actor = D_800F4538[arg0->unkF];

    if (actor->unk17E4.unk0 == 2) {
        sp[0] = 0x80;
        sp[1] = 0;
    } else {
        if ((*((int*)&actor->unk0.nQuads + 1) & 0x3F9F00) != 0x8000) {
            func_800A1280(arg0->unkF, 0xFF, &actor->unk6FC, 0);
        }

        temp = vs_main_computeSfxPan(*(int*)&actor->unk6FC, actor->unk6FC.vz);
        sp[0] = temp >> 0x10;

        if (actor->unk17E4.unk1 != 0) {
            sp[0] = actor->unk17E4.unk1;
        }

        sp[1] = temp & 0xFFFF;

        if (actor->unk17E4.unk2 != 0) {
            sp[1] = actor->unk17E4.unk2;
        }
    }

    if (sp[1] == 0) {
        return;
    }

    if (type == 8) {
        func_8006CD60(arg0->unk68->akaoOffset, sp[0], sp[1]);
    } else if (type == 4) {
        func_800461CC(0x7E, arg0->unk68->akaoOffset, rand() % 4 + 4, sp[0], sp[1]);
    } else {
        func_800461CC(0x180, arg0->unk68->akaoOffset, type, sp[0], sp[1]);
    }
}

void func_800AE68C(int arg0, int arg1)
{
    func_800AE4FC(&D_800F4538[arg0]->unk0, arg1 + 4);
}

void func_800AE6C0(D_800F4538_t* arg0, int arg1, int arg2)
{
    int sp10[2];
    D_800F4538_t* temp_s0 = D_800F4538[arg0->unk0.unkF];

    if (temp_s0->unk17E4.unk0 == 2) {
        sp10[0] = 0x80;
        sp10[1] = 0;
    } else {
        int temp_v0;

        if (temp_s0->unk0.unk9_0 || temp_s0->unk0.unk9_4 || !temp_s0->unk0.unk9_7
            || temp_s0->unk0.unkA_0 || temp_s0->unk0.unkA_3 || temp_s0->unk0.unkA_5) {
            func_800A1280(arg0->unk0.unkF, 0xFF, &temp_s0->unk6FC, 0);
        }

        temp_v0 = vs_main_computeSfxPan(*(int*)&temp_s0->unk6FC, temp_s0->unk6FC.vz);
        sp10[0] = temp_v0 >> 0x10;

        if (temp_s0->unk17E4.unk1 != 0) {
            sp10[0] = temp_s0->unk17E4.unk1;
        }

        sp10[1] = temp_v0 & 0xFFFF;

        if (temp_s0->unk17E4.unk2 != 0) {
            sp10[1] = temp_s0->unk17E4.unk2;
        }
    }

    if (sp10[1] != 0) {
        vs_main_playSfx(0x7E, arg1, sp10[0], sp10[1]);
        if (arg2 != 0) {
            vs_main_playSfx(0x7E, arg2, sp10[0], sp10[1]);
        }
    }
}

void func_800AE7D8(void* arg0, int arg1, int arg2)
{
    SVECTOR* temp_s0;

    temp_s0 = arg0 + 0x1C;
    vs_main_panSfx(0x7E, arg1, temp_s0);
    if (arg2 != 0) {
        vs_main_panSfx(0x7E, arg2, temp_s0);
    }
}

void func_800AE828(int arg0, D_800F4538_t* arg1, int arg2)
{
    int sp10;
    int sp14;
    int id;
    int floor;
    _mpdRoomSection3* room;

    if ((u_char)(arg1->animationId - 0xCA) < 18) {
        return;
    }
    if (arg0 == 1) {
        return;
    }
    if (*((int*)&arg1->unk5B4 - 2) & 0xF0000000) {
        id = D_800E91A4[D_800F45E0[func_800A91DC(arg1->unk0.currentTileX,
                                       arg1->unk0.currentTileZ, 1)]
                ->unk6C[8]
                .actorId];
    } else {
        floor = arg1->unk0.unk5D;
        id = 0xD;
        if (arg1->unk6E4 != 0) {
            floor = arg1->unk6E4;
        }
        room = func_8008B764(arg1->unk0.currentTileX, arg1->unk0.currentTileZ, floor);
        if (room != NULL) {
            id = D_800E9278[room->unk0_0];
        }
    }
    if (arg2 == 0x41) {
        id += 0x10;
    } else if (arg2 == 0x42) {
        id += 0x18;
    } else {
        func_8008EB04(&sp10, &sp14);
        if (sp14 >= 6 && sp10 > 0 && sp10 < 3) {
            id += 8;
        }
    }
    func_800AE4FC(&arg1->unk0, id);
}

void func_800AE980(D_800F4538_unkC54* dst, D_800F4538_unkC54* src, int count)
{
    int i;

    dst->unk0[41].vx = (dst->unk0[41].vx + src->unk0[41].vx) >> 1;
    dst->unk0[41].vy = (dst->unk0[41].vy + src->unk0[41].vy) >> 1;
    dst->unk0[41].vz = (dst->unk0[41].vz + src->unk0[41].vz) >> 1;

    for (i = 0; i < count; ++i) {
        int x = src->unk0[i].vx - dst->unk0[i].vx;
        int y;
        int z;

        if (x >= ONE) {
            x -= ONE * 2;
        } else if (x < -ONE) {
            x += ONE * 2;
        }

        dst->unk0[i].vx += x >> 1;
        y = src->unk0[i].vy - dst->unk0[i].vy;

        if (y >= ONE) {
            y -= ONE * 2;
        } else if (y < -ONE) {
            y += ONE * 2;
        }

        dst->unk0[i].vy += y >> 1;
        z = src->unk0[i].vz - dst->unk0[i].vz;

        if (z >= ONE) {
            z -= ONE * 2;
        } else if (z < -ONE) {
            z += ONE * 2;
        }

        dst->unk0[i].vz += z >> 1;

        dst->unk150[i].vx = (dst->unk150[i].vx + src->unk150[i].vx) >> 1;
        dst->unk150[i].vy = (dst->unk150[i].vy + src->unk150[i].vy) >> 1;
        dst->unk150[i].vz = (dst->unk150[i].vz + src->unk150[i].vz) >> 1;
    }
}

typedef struct {
    char prefix[0x3A];
    u_short angleX, angleY;
    char padding[0x16];
    SVECTOR offset;
    char padding2[8];
    MATRIX matrix;
    SVECTOR rotation;
} actorTransformScratch;
extern struct {
    char prefix[0x1FD0];
    int scales[3];
} D_800F2458;
void func_800B07DC(D_800F4538_t*);

void func_800AEAE8(D_800F4538_t* actor)
{
    actorTransformScratch* scratch = (void*)0x1F80035C;
    D_800F2458.scales[0] = 64;
    D_800F2458.scales[1] = 64;
    D_800F2458.scales[2] = 64;
    if (*(int*)&actor->unk0.unk2C == 0x10001000 && actor->unk0.unk30 == 4096) {
        scratch->offset.vx = (short)*(u_short*)((char*)actor + 0x84C) >> 1;
        scratch->offset.vy = (short)*(u_short*)((char*)actor + 0x84E) >> 1;
        scratch->offset.vz = (short)*(u_short*)((char*)actor + 0x850) >> 1;
    } else {
        scratch->offset.vx = *(short*)((char*)actor + 0x84C) * actor->unk0.unk2C / 8192;
        scratch->offset.vy = *(short*)((char*)actor + 0x84E) * actor->unk0.unk2E / 8192;
        scratch->offset.vz = *(short*)((char*)actor + 0x850) * actor->unk0.unk30 / 8192;
    }
    scratch->offset.vx = scratch->offset.vx * actor->unk183C / 4096;
    scratch->offset.vy = scratch->offset.vy * actor->unk183C / 4096;
    scratch->offset.vz = scratch->offset.vz * actor->unk183C / 4096;
    func_800B07DC(actor);
    scratch->angleX = actor->unk0.unk14;
    scratch->angleY = actor->unk0.unk16;
}

extern MATRIX D_8005E218;
extern MATRIX D_800F4910;
extern MATRIX D_800F49B8;
void func_8004140C(MATRIX*, VECTOR*);
void func_80041C68(MATRIX*, MATRIX*);
typedef struct {
    char prefix[0x64];
    MATRIX matrix;
    char gap[8];
    VECTOR scale;
} cameraTransformScratch;

void func_800AECA0(MATRIX* source)
{
    MATRIX rotation;
    cameraTransformScratch* scratch = (void*)0x1F80035C;
    struct {
        char prefix[0x5C];
        int angle, unused, zoom;
    }* camera = (void*)0x1F800000;
    int i;
    for (i = 0; i < 3; ++i) {
        scratch->matrix.m[0][i] = D_8005E218.m[i][0];
        scratch->matrix.m[1][i] = D_8005E218.m[i][1];
        scratch->matrix.m[2][i] = D_8005E218.m[i][2];
    }
    rotation.m[1][1] = rotation.m[0][0] = rcos(-camera->angle);
    rotation.m[1][0] = rsin(-camera->angle);
    rotation.m[0][1] = -rotation.m[1][0];
    rotation.m[2][2] = 4096;
    rotation.m[0][2] = rotation.m[1][2] = rotation.m[2][0] = rotation.m[2][1] = 0;
    scratch->scale.vx = 3640;
    scratch->scale.vy = 4096;
    scratch->scale.vz = 4096;
    func_8004140C(&scratch->matrix, &scratch->scale);
    func_80041C68(&scratch->matrix, &rotation);
    scratch->matrix = rotation;
    i = 0x1000000 / camera->zoom;
    scratch->scale.vx = i;
    scratch->scale.vy = i;
    scratch->scale.vz = i;
    func_8004140C(&scratch->matrix, &scratch->scale);
    /* Preserve the original copy from the parameter home area. */
    D_800F4910 = *(MATRIX*)&source;
    D_800F49B8 = scratch->matrix;
    D_800F49B8.t[0] = source->t[0];
    D_800F49B8.t[1] = source->t[1];
    D_800F49B8.t[2] = source->t[2];
}

void func_800AEEC4(D_800F4538_t* arg0) __attribute__((unused));
void func_800AEEC4(D_800F4538_t* arg0)
{
    int _[2] __attribute__((unused));
    int var_a2;
    int v0;
    int temp_v1 = arg0->unk17E4.unk0;

    if ((temp_v1 != 1) || (arg0->unk17E4.unk3 == 0)) {
        return;
    }

    var_a2 = vs_gametime_tickspeed / 2;

    if (arg0->unk17E4.unk3 < var_a2) {
        var_a2 = arg0->unk17E4.unk3;
    }

    temp_v1 = arg0->unk17E8.unk2 - arg0->unk17E4.unk2;

    if (temp_v1 != 0) {
        temp_v1 *= var_a2;
        v0 = temp_v1 / arg0->unk17E4.unk3;
        arg0->unk17E4.unk2 = arg0->unk17E4.unk2 + v0;
    }

    temp_v1 = arg0->unk17E8.unk1 - arg0->unk17E4.unk1;

    if (temp_v1 != 0) {
        temp_v1 *= var_a2;
        v0 = temp_v1 / arg0->unk17E4.unk3;
        arg0->unk17E4.unk1 = arg0->unk17E4.unk1 + v0;
    }

    arg0->unk17E4.unk3 -= var_a2;
}

void func_800AAE9C(void*);
void func_800AB4F0(void*);
void func_800AB788(void*, void*, int);
void func_800AB9A4(void*);
void func_800AC540(int, D_800F4538_t*);
typedef struct objectAnimationState objectAnimationState;
void func_800B0908(objectAnimationState*, int);
void func_800B1A68(void*, MATRIX*);
void func_800B28A8(void*, MATRIX*, char);
extern int D_800E9308;
extern u_char D_800F4B18, D_800F4B19;

struct frameScratch {
    int unused;
    int depth;
};

void func_800AEF94(MATRIX* camera)
{
    /* The original routine reserves 0x30 bytes of unused local storage. */
    int unused[12];
    actorTransformScratch* objectScratch;
    struct frameScratch* frame;
    D_800F4538_t** previous;
    D_800F4538_t** previousAttached;
    D_800F4538_t* actor;
    D_800F4538_t* attached;
    D_800F4538_t** entries;
    D_800F4538_t** weaponActors;
    D_800F45E0_t* object;
    int packedPosition;
    int flags;
    int weaponActorFlags;
    int i;
    int step;
    u_int modelHeight;
    u_char attachmentId;
    vs_battle_wepModels_t** weapons;
    vs_battle_wepModels_t* weapon;

    func_800AECA0(camera);
    i = 0;
    entries = D_800F4538;
    do {
        actor = entries[i];
        if ((actor != NULL) && (actor->unk0.nBones != 0)
            && !((*(u_int*)((char*)actor + 8)) & 1) && (actor->unk0.unk13 != 0xFC)) {
            func_800AAE9C(actor);
            if (actor->unk0.unk64.unk0 != 0) {
                func_800AB788(actor, NULL, 0);
            }
            if ((*(u_int*)((char*)actor + 8)) & 0xF00) {
                func_800AB9A4(actor);
            }
            flags = (*(u_int*)((char*)actor + 8));
            (*(u_int*)((char*)actor + 8)) = (int)(flags & 0x7FFFFFFF);
            if (flags & 4) {
                if ((actor->unk17E4.unk0 == 1) && actor->unk17E4.unk3 != 0) {
                    int delta;
                    step = vs_gametime_tickspeed / 2;
                    if (actor->unk17E4.unk3 < step)
                        step = actor->unk17E4.unk3;
                    delta = actor->unk17E8.unk2 - actor->unk17E4.unk2;
                    if (delta != 0) {
                        delta *= step;
                        delta /= actor->unk17E4.unk3;
                        actor->unk17E4.unk2 = actor->unk17E4.unk2 + delta;
                    }
                    delta = actor->unk17E8.unk1 - actor->unk17E4.unk1;
                    if (delta != 0) {
                        delta *= step;
                        delta /= actor->unk17E4.unk3;
                        actor->unk17E4.unk1 = actor->unk17E4.unk1 + delta;
                    }
                    actor->unk17E4.unk3 -= step;
                }
                step = 0;
                if (i > 0) {
                    int texture = actor->unk6E6;
                    previous = entries;
                    do {
                        ++step;
                        if ((*previous)->unk6E6 == texture)
                            goto texture_ready;
                        ++previous;
                    } while (step < i);
                }
                func_800AB4F0(actor);
            texture_ready:;

                if ((*(u_int*)((char*)actor + 0x5AC)) & 3) {
                    func_800AC540(i, actor);
                }
                if (vs_gametime_tickspeed == 4) {
                    actor->unk5B2 *= 2;
                }
                func_800AF6E8(actor);
                actor->unk5B2 = 1;
                actor->unk5B2 = (((u_int)(*(u_int*)((char*)actor + 0x5B0)) >> 3) & 1) + 1;
            } else {
                func_800AEAE8(actor);
            }
            if ((*(u_int*)((char*)actor + 8)) & 0x2000) {
                func_800B28A8(
                    actor, &entries[actor->unk0.unk12]->bones[actor->unk0.unk13], 0U);
            } else {
                func_800B28A8(actor, camera, 0U);
                attachmentId = actor->unk17FD;
                if (attachmentId != 0) {
                    if (attachmentId >= 2U) {
                        attached = entries[actor->unk17FD];
                        func_800AAE9C(attached);
                        if (attached->unk0.unk64.unk0 != 0) {
                            func_800AB788(attached, NULL, 0);
                        }
                        if ((*(u_int*)((char*)attached + 8)) & 0xF00) {
                            func_800AB9A4(attached);
                        }
                        if ((*(u_int*)((char*)actor + 8)) & 4) {
                            if ((attached->unk17E4.unk0 == 1)
                                && attached->unk17E4.unk3 != 0) {
                                int delta;
                                step = vs_gametime_tickspeed / 2;
                                if (attached->unk17E4.unk3 < step)
                                    step = attached->unk17E4.unk3;
                                delta = attached->unk17E8.unk2 - attached->unk17E4.unk2;
                                if (delta != 0) {
                                    delta *= step;
                                    delta /= attached->unk17E4.unk3;
                                    attached->unk17E4.unk2 =
                                        attached->unk17E4.unk2 + delta;
                                }
                                delta = attached->unk17E8.unk1 - attached->unk17E4.unk1;
                                if (delta != 0) {
                                    delta *= step;
                                    delta /= attached->unk17E4.unk3;
                                    attached->unk17E4.unk1 =
                                        attached->unk17E4.unk1 + delta;
                                }
                                attached->unk17E4.unk3 -= step;
                            }
                            step = 0;
                            if (i > 0) {
                                int texture = attached->unk6E6;
                                previousAttached = entries;
                                do {
                                    ++step;
                                    if ((*previousAttached)->unk6E6 == texture)
                                        goto linked_texture_ready;
                                    ++previousAttached;
                                } while (step < i);
                            }
                            func_800AB4F0(attached);
                        linked_texture_ready:;
                        }
                    }
                    frame = (void*)0x1F800000;
                    frame->depth += actor->unk6F4.unk3 * 4;
                    actor->unk0.position.vx = (u_short)actor->unk0.position.vx
                                            + (signed char)(u_char)actor->unk6F4.unk0;
                    actor->unk0.position.vy = (u_short)actor->unk0.position.vy
                                            + (signed char)(u_char)actor->unk6F4.unk1;
                    actor->unk0.position.vz = (u_short)actor->unk0.position.vz
                                            + (signed char)(u_char)actor->unk6F4.unk2;
                    func_800B002C(actor, (int)actor->unk17FD);
                    func_800B28A8(actor, camera, actor->unk17FD);
                    frame->depth -= actor->unk6F4.unk3 * 4;
                    actor->unk0.position.vx = (u_short)actor->unk0.position.vx
                                            - (signed char)(u_char)actor->unk6F4.unk0;
                    actor->unk0.position.vy = (u_short)actor->unk0.position.vy
                                            - (signed char)(u_char)actor->unk6F4.unk1;
                    actor->unk0.position.vz = (u_short)actor->unk0.position.vz
                                            - (signed char)(u_char)actor->unk6F4.unk2;
                }
            }
            if (((u_short)actor->unk63C >= 0x80U) && ((u_char)actor->unk5CC != 0)) {
                (*(u_int*)((char*)actor + 8)) =
                    (int)((*(u_int*)((char*)actor + 8)) | 0x80000000);
            }
        }
        i += 1;
    } while (i < 0x11);
    i = 0;
    weaponActors = D_800F4538;
    weapons = vs_battle_wepModels;
    do {
        weapon = *weapons;
        if ((weapon != NULL) && ((*(u_int*)((char*)weapon + 8)) & 0x10)
            && (weapon->unkD != 0)) {
            actor = weaponActors[(u_char)(*(u_int*)((char*)weapon + 8)) & 0xF];
            if (actor != NULL) {
                weaponActorFlags = (*(u_int*)((char*)actor + 8));
                if (weaponActorFlags & 1)
                    goto weapon_next;
                if (!(weaponActorFlags & 2))
                    goto weapon_next;
                if (weaponActorFlags & 0x1000)
                    goto weapon_next;
                func_800B217C(weapon, &actor->bones[weapon->unkD]);
            }
        }
    weapon_next:;
        i += 1;
        weapons++;
    } while (i < 0x14);
    objectScratch = (void*)0x1F80035C;
    frame = (void*)0x1F800000;
    i = 0;
    entries = (void*)D_800F45E0;
    frame->depth = (int)(frame->depth + 0x10);
    do {
        object = (void*)*entries;
        if ((object != NULL) && ((u_char)object->unk0 != 0)) {
            if (((i == D_800F4B19) && (D_800F4B18 == 0)) || (object->unk1A == 0xF7)) {
                func_800B0908((objectAnimationState*)object,
                    (int)(vs_gametime_tickspeed + ((u_int)vs_gametime_tickspeed >> 0x1F))
                        >> 1);
            }
            packedPosition = *(int*)&object->unk1C;
            objectScratch->offset.vz = (u_short)object->unk20;
            modelHeight = (*(int*)((char*)object->unk68 + 0x50));
            *(int*)&objectScratch->offset = packedPosition;
            objectScratch->offset.vy =
                (u_short)(objectScratch->offset.vy + ((int)modelHeight / 2));
            if (object->unk64.unk0 != 0) {
                func_800AB788(NULL, (D_800F4538_t*)object, 0);
            }
            if ((*(u_int*)((char*)object + 8)) & 0xF00) {
                func_800AB9A4((D_800F4538_t*)object);
            }
            func_800B1A68((D_800F4538_t*)object, camera);
        }
        i += 1;
        entries++;
    } while (i < 0x10);
    D_800F4B18 = 0;
    frame->depth = (int)(frame->depth - 0x10);
    D_800E9308 += 1;
}

void func_800AF6E8(D_800F4538_t* arg0)
{
    func_800AFA28(arg0, &arg0->unkC54, 0);

    if (arg0->unk5CC != 0) {
        int v5b2;

        if (arg0->unk5CC == 1) {
            func_800AF844(arg0->unk704.unk0, arg0->unkC54.unk0, arg0->unk0.nBones);
        }

        v5b2 = arg0->unk5B2;

        if (v5b2 != 1) {
            int next = arg0->unk5CC + 0xFF;
            arg0->unk5CC = v5b2 + next;

            if (arg0->unk5CC >= arg0->unk5CD) {
                arg0->unk5CC = 0;
                arg0->unk5CD = 0;
                goto tail;
            }
        }

        func_800B147C(
            &arg0->unk704, &arg0->unkC54, arg0->unk0.nBones, arg0->unk5CC, arg0->unk5CD);

        arg0->unk704.unk548_16 = arg0->unkC54.unk548_16;
        arg0->unk704.unk548_17 = arg0->unkC54.unk548_17;

        func_800B002C(arg0, 0);

        ++arg0->unk5CC;

        if (arg0->unk5CC >= arg0->unk5CD) {
            arg0->unk5CC = 0;
            arg0->unk5CD = 0;
        }
        return;
    }

tail:
    vs_main_memcpy(&arg0->unk704, &arg0->unkC54, sizeof(arg0->unk704));
    func_800B002C(arg0, 0);
}

void func_800AF844(SVECTOR* dst, SVECTOR* src, int count)
{
    int i;

    for (i = 0; i < count; ++i) {
        int x = src[i].vx - dst[i].vx;
        int z;

        if (x >= ONE) {
            x -= ONE * 2;
        } else if (x < -ONE) {
            x += ONE * 2;
        }

        x = ABS(x);
        z = src[i].vz - dst[i].vz;

        if (z >= ONE) {
            z -= ONE * 2;
        } else if (z < -ONE) {
            z += ONE * 2;
        }

        z = ABS(z);

        if (x + z >= ONE) {
            dst[i].vx = (dst[i].vx + ONE) % (ONE * 2);
            dst[i].vz = (dst[i].vz + ONE) % (ONE * 2);
            dst[i].vy = (ONE - dst[i].vy) % (ONE * 2);
        }
    }
}

void func_800AF960(D_800F45E0_t* arg0) __attribute__((unused));
void func_800AF960(D_800F45E0_t* arg0)
{
    int temp_lo;

    D_800F4538_unk1864* a2 = &arg0->unk1864;

    if (a2->unk4 != 0) {
        temp_lo = a2->unkA / a2->unk4;
        a2->unkA -= temp_lo;
        a2->unk8 += temp_lo;
        --a2->unk4;
    }

    a2->unk8 &= 0xFFF;

    if (a2->unk5 != 0) {
        temp_lo = a2->unk10 / a2->unk5;
        a2->unk10 -= temp_lo;
        a2->unkC += temp_lo;
        temp_lo = a2->unk12 / a2->unk5;
        a2->unk12 -= temp_lo;
        a2->unkE += temp_lo;
        --a2->unk5;
    }
}

struct animationFrameScratch {
    char prefix[8];
    int first, last;
    u_char** data;
};
void func_800AFDE8(int, SVECTOR*, int);
void func_800AFA28(D_800F4538_t* actor, D_800F4538_unkC54* state, int mode)
{
    u_short* header;
    struct animationFrameScratch* scratch = (void*)0x1F8003EC;
    D_800F4538_unkC54* boneState;
    D_800F4538_unk1864* shadow;
    int frame;
    int frameOrOffset;
    int x;
    int y;
    int z;
    int delta;
    int lastFrame;
    int i;
    u_short rootTrack;
    u_char** data;
    u_char queuedAnimation;

    (*(int*)((char*)state + 0x548)) = (int)((*(int*)((char*)state + 0x548)) & 0xFFFDFFFF);
    frameOrOffset = (short)state->unk540;
    i = 0;
    if (actor->unk5B2 != 0) {
        shadow = &actor->unk1864;
    advance_frame:
        if (shadow->unk4 != 0) {
            delta = shadow->unkA / shadow->unk4;
            shadow->unkA -= delta;
            shadow->unk8 += delta;
            --shadow->unk4;
        }
        shadow->unk8 &= 0xFFF;
        if (shadow->unk5 != 0) {
            delta = shadow->unk10 / shadow->unk5;
            shadow->unk10 -= delta;
            shadow->unkC += delta;
            delta = shadow->unk12 / shadow->unk5;
            shadow->unk12 -= delta;
            shadow->unkE += delta;
            --shadow->unk5;
        }
        if ((short)state->unk540 >= (int)(u_short)actor->unk5BC) {
            (*(int*)((char*)state + 0x548)) =
                (int)((*(int*)((char*)state + 0x548)) | 0x20000);
            queuedAnimation = actor->unk6E0;
            if (queuedAnimation != 0) {
                func_800A0618((int)actor->unk0.unkF, (int)actor->unk6E0,
                    (int)actor->unk6E1, (int)actor->unk6E2);
                actor->unk6E0 = 0;
                return;
            }
        }
        if ((*(int*)((char*)actor + 8)) & 4) {
            if (state->unk542 == (short)state->unk540) {
                func_800AD714(actor, state, mode);
            }
        }
        if ((short)state->unk540 >= (int)(u_short)actor->unk5BC) {
            state->unk540 -= 1;
            (*(int*)((char*)state + 0x548)) =
                (int)((*(int*)((char*)state + 0x548)) | 0x10000);
        }
        state->unk540 += 1;
        i += 1;
        if (i >= (int)actor->unk5B2) {
            goto update_bones;
        }
        goto advance_frame;
    }
update_bones:
    frame = (short)state->unk540;
    if ((frame != 1) && !((*(int*)((char*)state + 0x548)) & 0x10000)) {
        lastFrame = frame - 1;
        if ((*((u_char*)state + 0x549)) == 0) {
            if (lastFrame < frameOrOffset) {
                frameOrOffset = 1;
            }
            if (frameOrOffset == 0) {
                frameOrOffset = 1;
            }
            data = func_800AD494(actor, actor->animationId, &header);
            if (data != NULL) {
                scratch->first = (int)frameOrOffset;
                scratch->last = lastFrame;
                scratch->data = data;
                rootTrack = header[4];
                if (rootTrack != 0) {
                    func_800AFDE8(rootTrack, &state->unk150[0x29], 0);
                    x = state->unk150[0x29].vx;
                    if (x < 0) {
                        x += 3;
                    }
                    actor->unk0.position.vx = (u_short)actor->unk0.position.vx + (x >> 2);
                    y = state->unk150[0x29].vy;
                    if (y < 0) {
                        y += 3;
                    }
                    actor->unk0.position.vy = (u_short)actor->unk0.position.vy + (y >> 2);
                    z = state->unk150[0x29].vz;
                    if (z < 0) {
                        z += 3;
                    }
                    actor->unk0.position.vz = (u_short)actor->unk0.position.vz + (z >> 2);
                }
                func_800AFDE8(header[3], &state->unk0[0x29], 0);
                i = 0;
                if (actor->unk0.nBones != 0) {
                    frameOrOffset = 0x150;
                    boneState = state;
                    do {
                        func_800AFDE8(header[i + 5], boneState->unk0, 1);
                        if (((u_char*)header)[3] & 2) {
                            func_800AFDE8(header[i + actor->unk0.nBones + 5],
                                (SVECTOR*)((char*)state + frameOrOffset), 0);
                        }
                        frameOrOffset += 8;
                        boneState = (void*)((char*)boneState + 8);
                    } while (++i < (int)actor->unk0.nBones);
                }
            }
        }
    }
}

void func_800AFDE8(int offset, SVECTOR* value, int rotation)
{
    struct animationFrameScratch* scratch = (void*)0x1F8003EC;
    SVECTOR* delta = (void*)((char*)value + 0x2A0);
    u_char* data = (u_char*)(u_int)(u_short)value->pad;
    int nextFrame = (u_short)delta->pad;
    int frame = scratch->first;
    int flags, count, packed;
    data += (int)((u_char*)(offset + (int)*scratch->data));
    if (frame <= scratch->last) {
    decode:
        if (nextFrame >= frame) {
            value->vx += delta->vx;
            value->vy += delta->vy;
            value->vz += delta->vz;
            if (rotation) {
                *(int*)value &= 0x1FFF1FFF;
                value->vz &= 0x1FFF;
            }
            goto advance;
        } else {
            flags = *data;
            if (flags == 0)
                return;
            if (flags & 0xE0) {
                count = flags & 0x1F;
                if (count == 0x1F) {
                    nextFrame += 0x20;
                    nextFrame += data[1];
                    data += 2;
                } else {
                    nextFrame += count + 1;
                    ++data;
                }
            } else {
                count = flags & 3;
                if (count == 3) {
                    nextFrame += 4;
                    nextFrame += data[1];
                    data += 2;
                } else {
                    nextFrame += count + 1;
                    ++data;
                }
                flags <<= 3;
                {
                    count = ((signed char*)data)[0];
                    count <<= 8;
                    count |= data[1];
                    data += 2;
                }
                packed = count;
                count >>= 3;
                if (packed & 4) {
                    delta->vx = count;
                    flags &= 0x60;
                    if (packed & 3) {
                        {
                            count = ((signed char*)data)[0];
                            count <<= 8;
                            count |= data[1];
                            data += 2;
                        }
                    }
                }
                if (packed & 2) {
                    delta->vy = count;
                    flags &= 0xA0;
                    if (packed & 1) {
                        {
                            count = ((signed char*)data)[0];
                            count <<= 8;
                            count |= data[1];
                            data += 2;
                        }
                    } else
                        goto bytes;
                }
                if (packed & 1) {
                    delta->vz = count;
                    flags &= 0xC0;
                }
            }
        bytes:
            if (flags & 0x80) {
                delta->vx = (signed char)*data++;
            }
            if (flags & 0x40) {
                delta->vy = (signed char)*data++;
            }
            if (flags & 0x20) {
                delta->vz = (signed char)*data++;
            }
        }
        goto decode;
    advance:
        ++frame;
        if (frame <= scratch->last)
            goto decode;
    }
    data -= (int)((u_char*)(offset + (int)*scratch->data));
    value->pad = (int)data;
    delta->pad = nextFrame;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800B002C);

void func_80040F8C(SVECTOR*, MATRIX*);

void func_800B07DC(D_800F4538_t* actor)
{
    actorTransformScratch* scratch = (void*)0x1F80035C;
    scratch->rotation.vx = actor->unk0.unk24;
    scratch->rotation.vy = actor->unk0.facing;
    scratch->rotation.vz = actor->unk0.unk28;
    func_80040F8C(&scratch->rotation, &scratch->matrix);
    scratch->matrix.t[0] = 0;
    scratch->matrix.t[1] = 0;
    scratch->matrix.t[2] = 0;
    gte_SetRotMatrix(&scratch->matrix);
    gte_SetTransMatrix(&scratch->matrix);
    gte_ldv0(&scratch->offset);
    gte_rtv0tr2();
    gte_stlvnl(scratch->matrix.t);
    scratch->offset.vx = scratch->matrix.t[0];
    scratch->offset.vy = scratch->matrix.t[1];
    scratch->offset.vz = scratch->matrix.t[2];
    scratch->offset.vx += actor->unk0.position.vx;
    scratch->offset.vz += actor->unk0.position.vz;
    scratch->offset.vy += actor->unk0.position.vy;
}

struct objectAnimationState {
    char prefix[8];
    int flags;
    char padC[3];
    u_char id, pad10;
    signed char delay;
    u_char parent, pad13;
    int pad14;
    short rotationTicks, mode;
    SVECTOR position;
    short rx, ry, rz, pad2A;
    short sx, sy, sz, pad32;
    short dx, dy, dz, orientation;
    short drx, dry, drz;
    char pad42[0x1A];
    u_char tileX, pad5D, tileZ, pad5F;
    char pad60[0x10C];
    u_char material, durability, pad16E, parentObject, frame;
};
int func_800B101C();
int func_800A3DB4(int, int, int);
int func_800A6EE8(SVECTOR*, int, int, int);
void func_800E6898(void*);
void func_800E4C28(int, int);
void func_800B0908(objectAnimationState* object, int unused)
{
    actorTransformScratch* scratch = (void*)0x1F80035C;
    int step, mode, other;
    objectAnimationState* child;
    if (object->delay) {
        --object->delay;
        return;
    }
    if (object->rotationTicks) {
        step = object->drx / object->rotationTicks;
        object->drx -= step;
        object->rx = (object->rx + step) & 0xFFF;
        step = object->dry / object->rotationTicks;
        object->dry -= step;
        object->ry = (object->ry + step) & 0xFFF;
        step = object->drz / object->rotationTicks;
        object->drz -= step;
        object->rz = (object->rz + step) & 0xFFF;
        --object->rotationTicks;
    }
    mode = object->mode;
    if (!mode)
        return;
    if (mode == 0xFF) {
        if (!object->dx && !object->dz) {
            object->frame = 0;
            goto fall;
        }
        object->frame = 1;
        step = (short)(u_short)object->dx / 2;
        object->dx -= step;
        object->position.vx += step;
        if (object->dx < 0) {
            if (object->dx >= -1) {
                object->position.vx += object->dx;
                object->dx = 0;
            }
        } else if (object->dx < 2) {
            object->position.vx += object->dx;
            object->dx = 0;
        }
        step = (short)(u_short)object->dz / 2;
        object->dz -= step;
        object->position.vz += step;
        if (object->dz < 0) {
            if (object->dz >= -1) {
                object->position.vz += object->dz;
                object->dz = 0;
            }
        } else if (object->dz < 2) {
            object->position.vz += object->dz;
            object->dz = 0;
        }
        return;
    } else if (mode == 0xFE) {
        if ((object->position.vx & 0x7F) == 0x40
            && (object->position.vz & 0x7F) == 0x40) {
            scratch->rotation.vx = object->position.vx;
            scratch->rotation.vz = object->position.vz;
            step = object->orientation;
            other = 128;
            if (step < 2)
                other = -128;
            if (step & 1)
                scratch->rotation.vx += other;
            else
                scratch->rotation.vz += other;
            if (func_800A3DB4(
                    scratch->rotation.vx, scratch->rotation.vz, object->position.vy)
                && func_800A6EE8(&object->position, 0, 0, 1) == object->position.vy) {
                object->tileX = 0xFF;
                object->tileZ = 0xFF;
            } else
                goto fall;
        }
        object->position.vx += object->dx;
        object->position.vz += object->dz;
        return;
    } else if (mode == 0xFD) {
        if (!func_800B101C(object)) {
            func_800E6898(object);
            func_800E6898(object);
            func_800E4C28(object->tileX, object->tileZ);
        }
        return;
    } else if (mode == 0xFC) {
    fall:
        object->tileX = object->position.vx / 128;
        object->tileZ = object->position.vz / 128;
        step = func_800A6EE8(&object->position, 0, 0, 2);
        if (object->position.vy < step) {
            object->dy += 3;
            object->position.vy += object->dy;
            if (object->position.vy < step) {
                object->mode = 0xFC;
                goto children;
            }
        }
        {
            int previousY = (u_short)object->position.vy;
            object->position.vy = step;
            object->dy += step - previousY;
        }
        other = object->material & 7;
        if (other >= 5) {
            *(int*)&object->material &= ~0x30;
            other = func_800A91DC(object->tileX, object->tileZ, 1);
            if (other) {
                other = *(u_char*)((char*)D_800F45E0[other] + 0x16C) & 7;
                if (other >= 5) {
                    if (other == (object->material & 7)) {
                        object->mode = 0xFD;
                        object->frame = 0;
                        *(int*)&object->material =
                            (*(int*)&object->material & ~0x30) | 0x20;
                        vs_main_panSfx(0x7E, 0x30, &object->position);
                    } else {
                        *(int*)&object->material =
                            (*(int*)&object->material & ~0x30) | 0x10;
                        vs_main_panSfx(0x7E, 0x31, &object->position);
                        object->mode = 0;
                        func_800E6898(object);
                        func_800E4C28(object->tileX, object->tileZ);
                    }
                    goto children;
                }
            }
        }
        object->tileX = object->position.vx / 128;
        object->tileZ = object->position.vz / 128;
        func_800E6898(object);
        func_800E4C28(object->tileX, object->tileZ);
        if ((*(int*)&object->material & 7) == 1) {
            --object->durability;
            if (!object->durability) {
                object->mode = 0xF8;
                object->frame = 0;
                return;
            }
        }
        step = object->mode;
        if (step == 0xFE) {
            vs_main_panSfx(0x7E, 0x30, &object->position);
            object->mode = 0xFB;
            object->frame = 0;
        } else if (step == 0xFF || step == 0xF9) {
            object->mode = 0;
        } else {
            vs_main_panSfx(0x7E, 0x30, &object->position);
            object->mode = 0xFA;
            object->frame = 0;
        }
    children:
        step = 0;
        do {
            child = (void*)D_800F45E0[step];
            if (child && !(child->flags & 1) && child->parentObject == object->id) {
                child->position.vy += object->dy;
                if (!object->mode)
                    child->parentObject = 0xFF;
            }
            ++step;
        } while (step < 16);
        return;
    } else if (mode == 0xFB) {
        goto animate;
    } else if (mode == 0xFA) {
        func_800B101C(object);
        goto children;
    } else if (mode == 0xF9) {
        if (func_800B101C(object))
            return;
        goto fall;
    } else if (mode == 0xF7) {
        goto animate;
    } else if (mode == 0xF8) {
    animate:
        func_800B101C(object);
        return;
    }
    step = object->dx / object->mode;
    object->dx -= step;
    object->position.vx += step;
    step = object->dy / object->mode;
    object->dy -= step;
    object->position.vy += step;
    step = object->dz / object->mode;
    object->dz -= step;
    object->position.vz += step;
    --object->mode;
    if (!object->mode && object->parent == 0xFF)
        goto fall;
}

typedef struct {
    char prefix[8];
    u_int flags;
    char paddingC[3];
    u_char objectId;
    char padding10[0xA];
    short mode;
    short x, y, z, padding22;
    short rotationX, rotationY, rotationZ, padding2A;
    short scaleX, scaleY, scaleZ, padding32, padding34;
    short deltaY, padding38, orientation;
    char padding3C[0xF0];
    char savedState[32];
    char state[32];
    char padding16C[2];
    u_char material, padding16F, frame;
} objectMotionContext;
extern u_char D_800E91AC[], D_800E91BC[], D_800E91CC[], D_800E91DC[];
extern u_char D_800E91EC[], D_800E91F0[], D_800E91FC[], D_800E9208[];
extern u_char D_800E9218[], D_800E9228[], D_800E9238[], D_800E9248[];
extern u_char D_800E9258[], D_800E9268[];
int func_800A0104(int, int);

int func_800B101C(objectMotionContext* object)
{
    int frame = object->frame;
    int value;
    int value2;
    if (frame == 0)
        frame = 1;
    value = object->mode;
    if (value == 0xFD) {
        object->y += (signed char)D_800E91AC[frame];
        object->rotationX += (signed char)D_800E91BC[frame];
        object->rotationY += (signed char)D_800E91CC[frame];
        object->rotationZ += (signed char)D_800E91DC[frame];
        if (frame == 14)
            goto complete;
        goto next;
    } else if (value == 0xFB) {
        value = object->orientation;
        object->z += (signed char)D_800E91F0[frame];
        value2 = (signed char)D_800E91FC[frame];
        if (value == 0 || value == 3)
            value2 = -value2;
        if (value & 1)
            object->rotationZ += value2;
        else
            object->rotationX += value2;
        if (frame == 9)
            goto complete;
        goto next;
    } else if (value == 0xFA) {
        object->y += (signed char)D_800E91EC[frame];
        object->deltaY = (signed char)D_800E91EC[frame];
        if (frame == 3)
            goto complete;
        goto next;
    } else if (value == 0xF9) {
        int orientation;
        object->y += (signed char)D_800E9208[frame];
        value = (signed char)D_800E9218[frame];
        orientation = object->orientation;
        value2 = D_800E9228[frame];
        if (orientation >= 2)
            value = -value;
        if ((u_int)(orientation - 1) < 2)
            value2 = -value2;
        if (orientation & 1) {
            object->x += value;
            object->rotationZ += value2;
        } else {
            object->z += value;
            object->rotationX += value2;
        }
        if (frame == 14) {
            func_800A0104(object->objectId, object->material);
            object->mode = 0;
            goto done;
        }
        goto next;
    } else if (value == 0xF8) {
        if (frame >= 9) {
            object->y += 3;
            if (frame == 9) {
                vs_main_memcpy(object->state, object->savedState, 32);
                object->flags = (object->flags & ~0xF00) | 0xC00;
            }
            if (frame == 40) {
                func_80099D6C(object->objectId);
                object->mode = 0;
                goto done;
            }
        }
        goto next;
    } else if (value == 0xF7) {
        object->y += (signed char)D_800E9238[frame];
        object->scaleX = (signed char)D_800E9248[frame];
        object->scaleY = (signed char)D_800E9258[frame];
        object->scaleZ = (signed char)D_800E9268[frame];
        if (frame == 14)
            goto complete;
        goto next;
    } else
        goto next;
next:
    object->frame = frame + 1;
    return 1;
complete:
    object->mode = 0;
done:
    return 0;
}

int func_800B13CC(int arg0, int arg1, int arg2)
{
    int i;
    int var_a3 = 0xBB8;

    for (i = 0; i < 16; ++i) {

        D_800F45E0_t* temp_v1 = D_800F45E0[i];

        if ((temp_v1 != NULL) && !(temp_v1->unk8_0) && !(temp_v1->unk6C[8].unk0_3)
            && (temp_v1->unk5C == arg0) && (temp_v1->unk5E == arg1)) {

            int temp_v1_2 = temp_v1->unk1E;

            if ((arg2 < temp_v1_2) && (temp_v1_2 < var_a3)) {
                var_a3 = temp_v1_2;
            }
        }
    }

    var_a3 -= 128;

    if (var_a3 > 0) {
        var_a3 = 0;
    }

    return var_a3;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800B147C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800B16F4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800B17F0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800B196C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800B1A68);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800B217C);

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
