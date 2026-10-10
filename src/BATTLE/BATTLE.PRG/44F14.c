#include "common.h"
#include <rand.h>
#include <abs.h>
#include <inline_c.h>
#include "vs_inline_c.h"
#include "146C.h"
#include "38C1C.h"
#include "3A1A0.h"
#include "44F14.h"
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
u_char** func_800AD494(D_800F4538_t*, u_char, u_short**);
void func_800AD714(D_800F4538_t*, D_800F4538_unkC54*, int, u_char*);
void func_800AF844(SVECTOR*, SVECTOR*, int);
void func_800B147C(D_800F4538_unkC54*, D_800F4538_unkC54*, int, int, int);
void func_800B17F0(SVECTOR*, MATRIX*);
void func_800B196C(MATRIX*, MATRIX*);
void func_800B396C(MATRIX*, VECTOR*);
int func_800B3A68(void*, MATRIX*, int, void*);
void func_800B4594(D_800F2458_t*, D_800F45E0_t*, int*, void*);
void func_800B5C30(D_800F2458_t*, D_800F45E0_t*, int*, void*);

extern MATRIX D_8005E218;
extern u_char D_800E91A4[];
extern u_char D_800E9278[];
extern D_800F3C58_t D_800F3C58;
extern MATRIX D_800F3C78;
extern MATRIX D_800F4910;
extern MATRIX D_800F49B8;

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
                ->unk16C.actorId];
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

void func_800AEAE8(D_800F4538_t* actor)
{
    D_1F80035C_t* scratch = (void*)0x1F80035C;

    D_800F2458.unk1FD0[0] = 64;
    D_800F2458.unk1FD0[1] = 64;
    D_800F2458.unk1FD0[2] = 64;

    if (actor->unk0.unk2C == ONE && actor->unk0.unk2E == ONE
        && actor->unk0.unk30 == ONE) {
        setVector(&scratch->offset, actor->unk704.unk0[41].vx >> 1,
            actor->unk704.unk0[41].vy >> 1, actor->unk704.unk0[41].vz >> 1);
    } else {
        setVector(&scratch->offset,
            actor->unk704.unk0[41].vx * actor->unk0.unk2C / (ONE * 2),
            actor->unk704.unk0[41].vy * actor->unk0.unk2E / (ONE * 2),
            actor->unk704.unk0[41].vz * actor->unk0.unk30 / (ONE * 2));
    }

    setVector(&scratch->offset, scratch->offset.vx * actor->unk183C / ONE,
        scratch->offset.vy * actor->unk183C / ONE,
        scratch->offset.vz * actor->unk183C / ONE);
    func_800B07DC(actor);
    scratch->unk3A = actor->unk0.unk14;
    scratch->unk3C = actor->unk0.unk16;
}

void func_800AECA0(MATRIX* source)
{
    MATRIX roll;
    D_1F80035C_t* scratch = (void*)0x1F80035C;
    vs_scratch_t* view = (void*)0x1F800000;
    int i;

    for (i = 0; i < 3; ++i) {
        scratch->matrix.m[0][i] = D_8005E218.m[i][0];
        scratch->matrix.m[1][i] = D_8005E218.m[i][1];
        scratch->matrix.m[2][i] = D_8005E218.m[i][2];
    }

    roll.m[1][1] = roll.m[0][0] = rcos(-view->camera.angles.vz);
    roll.m[1][0] = rsin(-view->camera.angles.vz);
    roll.m[0][1] = -roll.m[1][0];
    roll.m[2][2] = ONE;
    roll.m[0][2] = roll.m[1][2] = roll.m[2][0] = roll.m[2][1] = 0;
    setVector(&scratch->scale, 3640, ONE, ONE);
    ScaleMatrix(&scratch->matrix, &scratch->scale);
    func_80041C68(&scratch->matrix, &roll);
    scratch->matrix = roll;
    i = ONE * ONE / view->camera.farClip;
    setVector(&scratch->scale, i, i, i);
    ScaleMatrix(&scratch->matrix, &scratch->scale);
    // BUG: copies from the stack slot of the pointer, not from the matrix it points to
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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800AEF94);

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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800AFA28);

void func_800AFDE8(int offset, SVECTOR* value, int rotation)
{
    D_1F8003EC_t* scratch = (void*)0x1F8003EC;
    SVECTOR* delta = &value[84];
    u_char* data = (u_char*)(u_int)(u_short)value->pad;
    int nextFrame = (u_short)delta->pad;
    int frame;

    data += offset + (int)*scratch->data;

    for (frame = scratch->first; frame <= scratch->last; ++frame) {
        while (1) {
            int flags;
            int count;

            if (nextFrame >= frame) {
                addVector(value, delta);

                if (rotation) {
                    *(int*)value &= 0x1FFF1FFF;
                    value->vz &= 0x1FFF;
                }
                break;
            }

            flags = *data;

            if (flags == 0) {
                return;
            }

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
                int packed;

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
                count = (signed char)data[0];
                count <<= 8;
                count |= data[1];
                data += 2;
                packed = count;
                count >>= 3;

                if (packed & 4) {
                    delta->vx = count;
                    flags &= 0x60;

                    if (packed & 3) {
                        count = (signed char)data[0];
                        count <<= 8;
                        count |= data[1];
                        data += 2;
                    }
                }

                if (packed & 2) {
                    delta->vy = count;
                    flags &= 0xA0;

                    if (packed & 1) {
                        count = (signed char)data[0];
                        count <<= 8;
                        count |= data[1];
                        data += 2;
                    }
                }

                if (packed & 1) {
                    delta->vz = count;
                    flags &= 0xC0;
                }
            }

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
    }

    data -= offset + (int)*scratch->data;
    value->pad = (int)data;
    delta->pad = nextFrame;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800B002C);

void func_800B07DC(D_800F4538_t* actor)
{
    D_1F80035C_t* scratch = (void*)0x1F80035C;

    setVector(
        &scratch->rotation, actor->unk0.unk24, actor->unk0.facing, actor->unk0.unk28);
    RotMatrixYXZ_gte(&scratch->rotation, &scratch->matrix);
    scratch->matrix.t[0] = 0;
    scratch->matrix.t[1] = 0;
    scratch->matrix.t[2] = 0;
    gte_SetRotMatrix(&scratch->matrix);
    gte_SetTransMatrix(&scratch->matrix);
    gte_ldv0(&scratch->offset);
    gte_rtv0tr2();
    gte_stlvnl(scratch->matrix.t);
    setVector(&scratch->offset, scratch->matrix.t[0], scratch->matrix.t[1],
        scratch->matrix.t[2]);
    scratch->offset.vx += actor->unk0.position.vx;
    scratch->offset.vz += actor->unk0.position.vz;
    scratch->offset.vy += actor->unk0.position.vy;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800B0908);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800B101C);

int func_800B13CC(int arg0, int arg1, int arg2)
{
    int i;
    int var_a3 = 0xBB8;

    for (i = 0; i < 16; ++i) {

        D_800F45E0_t* temp_v1 = D_800F45E0[i];

        if ((temp_v1 != NULL) && !(temp_v1->unk8_0) && !(temp_v1->unk16C.unk0_3)
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

void func_800B1A68(D_800F45E0_t* object, MATRIX* camera)
{
    D_1F80035C_t* scratch = (void*)0x1F80035C;
    u_int attachment;
    int value;

    scratch->model = object->unk68;
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

        if (object->unk12 == 0xFF) {
            goto rotate;
        }

        holder = D_800F4538[object->unk12];
        func_800A190C(object->unk12, 0xF0, &anchors[0], 1);
        func_800A190C(object->unk12, 0xF1, &anchors[1], 1);
        gte_SetRotMatrix(camera);
        gte_SetTransMatrix(camera);
        setVector(&scratch->position, (anchors[0].vx + anchors[1].vx) / 2,
            (anchors[0].vy + anchors[1].vy) / 2, (anchors[0].vz + anchors[1].vz) / 2);
        gte_ldv0(&scratch->position);
        gte_rtv0tr2();
        setVector(&scratch->rotation, object->unk10C.vx + object->unk24,
            object->unk10C.vy + object->unk26, object->unk10C.vz + object->unk28);
        gte_stlvnl(scratch->matrix.t);
        func_800B17F0(&scratch->rotation, &scratch->matrix);
        setVector(&scratch->rotation, holder->unk0.unk24, holder->unk0.facing,
            holder->unk0.unk28);
        func_800B17F0(&scratch->rotation, &holderRotation);
        func_800B196C(&holderRotation, &scratch->matrix);
    } else if (attachment < 2) {
        if (object->unk1A != 0) {
            setVector(&scratch->rotation, object->unk24, object->unk26, object->unk28);
            gte_stlvnl(scratch->matrix.t);
            RotMatrixYXZ_gte(&scratch->rotation, &scratch->matrix);
            func_800B196C(camera, &scratch->matrix);
            MulMatrix(&scratch->matrix, &object->unk6C[4]);
            goto composed;
        }

        scratch->matrix = object->unk6C[4];
        gte_stlvnl(scratch->matrix.t);
    } else {
    rotate:
        copyVector(&scratch->rotation, &object->unk10C);
        gte_stlvnl(scratch->matrix.t);
        applyVector(&scratch->rotation, object->unk24, object->unk26, object->unk28, +=);
        *(int*)&scratch->rotation &= 0x0FFF0FFF;
        *(int*)&scratch->rotation.vz &= 0xFFF;
        func_800B17F0(&scratch->rotation, &scratch->matrix);
    }

    func_800B196C(camera, &scratch->matrix);
composed:
    func_800B396C(&scratch->matrix, &D_800F3C58.scale);
    D_800F3C58.bones[0] = scratch->matrix;
    object->unk6C[0] = scratch->matrix;

    if (object->unk2C != 64 || object->unk2E != 64 || object->unk30 != 64) {
        setVector(&scratch->scale, object->unk2C, object->unk2E, object->unk30);
        applyVector(&scratch->scale, 64, 64, 64, *=);
        func_800B396C(&scratch->matrix, &scratch->scale);
        D_800F3C58.bones[0] = scratch->matrix;
        object->unk6C[0] = scratch->matrix;
    }

    D_800F3C78 = scratch->matrix;
    object->unk6C[1] = scratch->matrix;

    if (!object->unk8_1
        || !func_800B3A68(
            object, &object->unk6C[0], -vs_main_nearClip * 4, object->unk68)) {
        return;
    }

    scratch->tpage = GetTPage(0, 0, 64, 256);

    if (object->unk64.unk0 != 0 || object->unk9_0 >= 6) {
        scratch->clut = GetClut(object->unkF * 16 + 768, 255);
    } else {
        scratch->clut = GetClut(object->unkF * 16 + 768, 237);
    }

    value = object->unk9_0 >= 4 && object->unk9_0 < 9 && object->unk9_0 != 6;

    if (object->unk9_0 >= 12) {
        value = 1;
    }

    if (value) {
        func_800B5C30(&D_800F2458, object, &object->unk54, scratch->model);
    } else {
        func_800B4594(&D_800F2458, object, &object->unk54, scratch->model);
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800B217C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800B26B8);
