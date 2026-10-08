#include "common.h"
#include "30DB0.h"
#include "3A1A0.h"
#include "../../SLUS_010.40/main.h"
#include <abs.h>

typedef struct {
    int unk0;
    int pad04[5];
    D_800F45E0_t* unk18;
    short unk1C[18];
    int unk40;
} D_1F8003BC_t;

typedef struct {
    short unk0;
    short unk2;
    short unk4;
} func_800A3054_t;

typedef struct {
    short unk0;
    short unk2;
    short unk4;
    short unk6;
} func_8008D2C0_t;

typedef struct {
    char unk0[6];
    short unk6;
} func_800A6660_t;

typedef struct {
    char prefix[0x2C];
    u_char contact, nextContact;
} collisionScratchView;

typedef struct {
    unsigned mode : 2;
    unsigned fast : 1;
    unsigned reserved : 29;
} vs_battleMovementModeFlags;

typedef struct {
    int words[2];
} probePosition;

typedef struct {
    char prefix[0x1C];
    short heights[8];
    u_char blocked[8];
    u_char attributes[8];
    u_char centerAttribute;
} ActorCollisionSamples;

typedef struct {
    char prefix[0x2C];
    u_char contacts[8];
} collisionResponseScratch;

void func_8008C49C(int, int);
int func_8008D2C0(func_8008D2C0_t*);
short func_8008DA24(int, int);
short func_8008DC7C(int, int);
short func_8008DD0C(int arg0, int arg1);
int func_8009E180(D_800F4538_t*, SVECTOR*);
int func_800A190C(int, int, SVECTOR*, int);
void func_800A25EC(D_800F4538_t*);
void func_800A2790(D_800F4538_t*);
void func_800A291C(D_800F4538_t*);
void func_800A29A0(D_800F4538_t*);
void func_800A2CD4(D_800F4538_t*);
void func_800A2FBC(D_800F4538_t*);
inline int func_800A3310(int, SVECTOR*);
void func_800A3394(int, SVECTOR*);
int func_800A3500(int, int);
int func_800A3BC4(int, int);
D_800F4538_t* func_800A3C34(int, int, int, int);
int func_800A3DB4(int x, int z, int minimumHeight);
int func_800A46A4(D_800F4538_t*);
func_8008D2C0_t* func_800A4A24(int);
void func_800A4A88(D_800F4538_t*, int);
int func_800A51A0(int, SVECTOR*);
void func_800A525C(D_800F4538_t*);
int func_800A5280(int, int, int, SVECTOR*);
void func_800A6660(D_800F4538_t*, int, func_800A6660_t*);
int func_800A6798(D_800F4538_t*, SVECTOR*, SVECTOR*);
int func_800A69B4(D_800F4538_t*);
int func_800A6AA0(D_800F4538_t*, int, int);
int func_800A6EE8(SVECTOR*, int, int, int);
void func_800A70DC(D_800F4538_t*, int);
int func_800A76BC(D_800F4538_t*, SVECTOR*, int*, int);
int func_800A8B34(SVECTOR* arg0, int arg1);
u_int* func_800A8D64(SVECTOR*, int);
int func_800A8E84(D_800F45E0_t*, SVECTOR*);
int func_800A8FD4(D_800F4538_t* actor, SVECTOR* motion);
int func_800A91DC(int, int, int);
int func_800A92B8(int, int);
int func_800A9378(int, int, int, int);
int func_800A9530(D_800F4538_t*, SVECTOR*);
u_int func_800A9C54(u_char, void*, int);
void func_800A9EB4(int, short, int);
void func_800AA454(int, func_8006EBF8_t_fields*, int);
void func_800AA600(int, SVECTOR*, int);
void func_800AA620(int, SVECTOR*, int);
void func_800AA698(int, SVECTOR*, int);
void func_800AA850(int, short, int);
void func_800AC690(int, D_800F4538_t*);
void func_800ACF54(D_800F4538_t*);
int func_800AD494(void*, int, u_short**);
void func_800AE4FC(D_800F4538_unk0*, int);
void func_800AE6C0(D_800F4538_t*, int, int);
void func_800AEAE8(D_800F4538_t*);
void func_800AECA0(MATRIX*);
void func_800B0908(D_800F45E0_t*, int);
int func_800B13CC(int, int, int);
void func_800B28A8(void*, MATRIX*, int);
void func_800B64A8(int, int, int);
void func_800E4BD8(int);
void func_800E4BE0(int);
void func_800E4C1C(int, int);
void func_800E4C28();
void func_800E68A0(D_800F45E0_t*);
void func_800E6B24(u_char);
int func_800E75EC(void);

extern u_char D_800E8FD0[];
extern int D_800E90A8;
extern int D_800E90BC;
extern u_char D_800E90C3[];
extern u_char D_800E90C4;
extern u_char D_800E90C6;
extern u_char D_800E90CC[];
extern u_char D_800E90D0[];
extern u_char D_800E91AC[];
extern u_char D_800E9278[];
extern u_char D_800F1D6E[];
extern int D_800F49E8;
extern u_int* D_800F49F0;
extern u_short D_800F49F4;
extern u_char D_800F49F8;
extern u_char D_800F49F9;
extern SVECTOR D_800F4B08;
extern short D_800F4B0A;
extern char D_800F4B18;

void func_800A29A0(D_800F4538_t* arg0)
{
    int busy;

    switch (arg0->unk0.unkB_0) {
    case 1:
        arg0->unk0.unkA_5 = 0;
        func_800A0204(arg0->unk0.unkF, 0x13, 0, 8);
        func_800A01C8(arg0->unk0.unkF, 0x14, 8, 0);
        *((u_char*)arg0 + 0x57) = 0;
        arg0->unk0.unkB_0 = 2;
        arg0->unk0.unk9_0 = 6;
        return;
    case 2:
        if (arg0->unk0.unk9_0 < 8) {
            return;
        }
        if (arg0->unk0.unk13 == 0xFC) {
            busy = D_800F4538[arg0->unk0.unk12]->unk0.unk9_0 < 9;
        } else if (arg0->unkC54.unk548_17) {
            busy = arg0->unk5CC;
        } else {
            return;
        }
        if (busy == 0) {
            arg0->unk0.unk9_0 = 9;
            func_800A9C54(arg0->unk0.unkF, &arg0->unk5EC, 0);
            arg0->unk0.facing = arg0->unk5EC.pad;
            func_800A0204(arg0->unk0.unkF, 0x15, 0, 8);
            func_800A01C8(arg0->unk0.unkF, 0x16, 8, 0);
            arg0->unk0.unkB_0 = 3;
        }
        return;
    case 3:
        if (arg0->unk0.unk9_0) {
            return;
        }
        if (arg0->unk0.unk13 == 0xFC ? D_800F4538[arg0->unk0.unk12]->unk0.unk9_0
                                     : arg0->unk5CC) {
            return;
        }
        func_800A0204(arg0->unk0.unkF, 1, 0, 8);
        // fallthrough
    case 4:
        func_800ACF54(arg0);
        func_800E4C28(arg0->unk0.currentTileX, arg0->unk0.currentTileZ);
        // fallthrough
    case 5:
        if (arg0->unk17FD >= 2 && D_800F4538[arg0->unk17FD]->unk0.unkB_0) {
            arg0->unk0.unkB_0 = 5;
            return;
        }
        arg0->unk0.unkB_0 = 0;
        return;
    }
}

void func_800A2C48(D_800F4538_t* arg0)
{
    func_800A9C54(arg0->unk0.unkF, &arg0->unk5DC[4], 0);
    arg0->unk6E0 = 0;
    arg0->unk0.unkB_0 = 4;
    func_800A29A0(arg0);
    if (arg0->unk17FD >= 2) {
        func_800A2C48(D_800F4538[arg0->unk17FD]);
    }
}

void func_800A2CD4(D_800F4538_t* arg0)
{
    u_short steps;
    u_char animation;

    switch (arg0->unk0.unkB_4) {
    case 1:
        func_800A0204(arg0->unk0.unkF, 9, 0, 8);
        func_800A9C54(arg0->unk0.unkF, &arg0->unk5EC, -1);
        func_800A9EB4(arg0->unk0.unkF, arg0->unk5EC.pad, 8);
        arg0->unk5CA = arg0->unk0.unk1A;
        arg0->unk0.unk1A = 0;
        if (arg0->unk5CA != 0) {
            arg0->unk0.unkB_4 = 2;
            return;
        }
        goto land;
    case 2:
        func_800A2FBC(arg0);
        func_800A9378(
            arg0->unk0.position.vx, arg0->unk0.position.vy, arg0->unk0.position.vz, 2);
        if (*(int*)&D_800F49F4 != 0) {
            arg0->unk0.unkA_5 = 1;
            goto idle;
        }
        if (arg0->unk5CA == 0) {
            func_800A0204(arg0->unk0.unkF, 0xA, 0, 8);
            arg0->unk0.unkA_5 = 0;
            arg0->unk0.unkB_4 = 3;
        }
        return;
    case 3:
        if (arg0->unk0.unk1A == 0 && arg0->unkC54.unk548_17) {
        land:
            arg0->unk0.unkA_5 = 0;
            func_800ACF54(arg0);
            func_800E4C28(arg0->unk0.currentTileX, arg0->unk0.currentTileZ);
            func_800A0204(arg0->unk0.unkF, 1, 0, 8);
            arg0->unk0.unkB_4 = 0;
        }
        return;
    case 4:
        func_800A0204(arg0->unk0.unkF, 7, 0, 8);
        func_800A01C8(arg0->unk0.unkF, 0x25, 8, 0);
        func_800AA620(arg0->unk0.unkF, &arg0->unk5EC, -1);
        func_800A9EB4(arg0->unk0.unkF, arg0->unk5EC.pad, 8);
        steps = arg0->unk0.unk1A;
        arg0->unk0.unk1A = 0;
        arg0->unk5CA = steps;
        arg0->unk0.unkA_5 = 1;
        if (arg0->unk5CA == 0) {
            arg0->unk6E0 = 0;
            goto idle;
        }
        arg0->unk0.unkB_4 = 5;
        return;
    case 5:
        func_800A2FBC(arg0);
        func_800A9378(
            arg0->unk0.position.vx, arg0->unk0.position.vy, arg0->unk0.position.vz, 3);
        if (*(int*)&D_800F49F4 != 0 || arg0->unk5CA == 0) {
        idle:
            func_800A0204(arg0->unk0.unkF, 1, 0, 8);
            arg0->unk0.unkB_4 = 0;
        }
        return;
    case 6:
        animation = arg0->animationId;
        if (animation != 0xC7 && animation != 0xC9 && arg0->unk5CC == 0) {
            arg0->unk0.unkB_4 = 0;
        }
        return;
    }
}

void func_800A2FBC(D_800F4538_t* arg0)
{
    int temp_a1 = arg0->unk0.unk34.vx / arg0->unk5CA;
    arg0->unk0.unk34.vx -= temp_a1;
    arg0->unk0.position.vx += temp_a1;

    temp_a1 = arg0->unk0.unk34.vy / arg0->unk5CA;
    arg0->unk0.unk34.vy -= temp_a1;
    arg0->unk0.position.vy += temp_a1;

    temp_a1 = arg0->unk0.unk34.vz / arg0->unk5CA;
    arg0->unk0.unk34.vz -= temp_a1;
    arg0->unk0.position.vz += temp_a1;

    --arg0->unk5CA;
}

void func_800A3054(D_800F4538_t* arg0, func_800A3054_t* arg1)
{
    int var_a2;
    int var_a3;

    var_a2 = 0x3F;
    var_a3 = 0x3F;
    if (arg1->unk0 < 0) {
        var_a2 = -0x3F;
    }
    if (arg1->unk4 < 0) {
        var_a3 = -0x3F;
    }
    arg0->unk181A = 1;
    arg0->unk1814 = (u_short)arg0->unk0.position.vx + var_a2;
    arg0->unk1818 = (u_short)arg0->unk0.position.vz + var_a3;
}

void func_800A30A0(int actorId, func_80089888_t* placement, int height, int mode)
{
    D_800F4538_t* actor;
    SVECTOR* position;
    short z;
    int ceiling;
    int flags;
    int value;
    u_char tileType;
    int* anchor;

    actor = D_800F4538[actorId];
    (*(int*)((char*)actor + 0x5C)) = *(int*)placement;
    actor->unk0.position.vx = ((u_char)placement->unk0_0 << 7) + 0x40;
    z = ((u_char)placement->unk0_16 << 7) + 0x40;
    actor->unk0.position.vz = z;
    actor->unk0.position.vy = func_800A3500(actor->unk0.position.vx, z);
    if (mode == 0x10 || mode == 0x20) {
        ceiling = func_800E75EC();
        if (ceiling == 0) {
            value = -0x180;
        } else {
            value = ceiling - actor->unk0.position.vy;
            if (value >= -0x7F) {
                value = -0x80;
            }
        }
        position = &actor->unk0.position;
        actor->unk0.position.vy = (u_short)actor->unk0.position.vy + value;
        if (func_800A3310(actorId, position) != 0) {
            func_800A3394(actorId, position);
        }
        *(u_int*)((char*)actor + 0x8) |= 0x200000;
        func_800A0204(actorId, 8, 0, 0);
    } else {
        if (mode == 0x40 || mode == 0x80) {
            *(u_int*)((char*)actor + 0x8) |= 0x400000;
        }
        tileType = (u_char)placement->unk0_8;
        if (tileType == 7) {
            actor->unk0.unk5D = 0;
            actor->unk0.position.vy = (short)height;
            actor->unk0.unk34.vy = 0;
            *(u_int*)((char*)actor + 0x8) =
                (int)((*(u_int*)((char*)actor + 0x8) & 0xFFF8FFFF) | 0x30000);
        } else {
            if (tileType >= 2U) {
                anchor = (int*)func_800A4A24((u_char)placement->unk0_8);
                (*(int*)((char*)actor + 0x1C)) = (int)anchor[0];
                (*(int*)((char*)actor + 0x20)) = (int)anchor[1];
                (*(int*)((char*)actor + 0x17EC)) = (int)anchor[0];
                (*(int*)((char*)actor + 0x17F0)) = (int)anchor[1];
                (*(short*)((char*)actor + 0x17F2)) = (short)(u_char)placement->unk0_8;
                flags = (*(u_int*)((char*)actor + 0xC) & ~0xF)
                      | ((u_char)placement->unk0_8 & 0xF);
                *(u_int*)((char*)actor + 0xC) = flags;
                *(u_int*)((char*)actor + 0xC) =
                    (int)((flags & ~0xF0) | (((u_char)placement->unk0_8 & 0xF) * 0x10));
            }
            func_800A0204(actorId, 1, 0, 0);
        }
    }
    func_800ACF54(actor);
    actor->unk0.unk1A = 0;
    value = *((u_char*)placement + 3);
    actor->unk0.unk3E = 0;
    actor->unk0.unk18 = 0;
    (*(short*)((char*)actor + 0x18D2)) = 0;
    (*(short*)((char*)actor + 0x18D4)) = 0;
    (*(short*)((char*)actor + 0x18D6)) = 0;
    (*(short*)((char*)actor + 0x18D8)) = 0;
    value *= 0x10;
    actor->unk0.facing = value;
    func_800A0ABC(actorId);
    actor->unk6E4 = 0;
}

inline int func_800A3310(int arg0, SVECTOR* arg1)
{
    int i;

    for (i = 2; i < arg0; ++i) {
        D_800F4538_t* temp_a2 = D_800F4538[i];
        if (temp_a2 != NULL && temp_a2->unk0.unkA_5
            && *(int*)&temp_a2->unk0.position == *(int*)arg1
            && temp_a2->unk0.position.vz == arg1->vz) {
            return i;
        }
    }
    return 0;
}

void func_800A3394(int arg0, SVECTOR* arg1)
{
    SVECTOR pos;
    int floor;
    int retried;
    D_800F4538_t* actor = D_800F4538[arg0];

    pos.vx = arg1->vx;
    pos.vz = arg1->vz;
    pos.vy = arg1->vy - 0xC0;
    floor = func_800E75EC();
    retried = 0;

    while (1) {
        if (func_800A3310(arg0, &pos) != 0) {
            pos.vy -= 0xC0;
        } else if (floor != 0 && pos.vy - actor->menuCameraHeightOffset < floor) {
            if (retried != 0) {
                return;
            }
            retried = 1;
            pos.vy = arg1->vy - 0x60;
        } else {
            arg1->vy = pos.vy;
            return;
        }
    }
}

int func_800A3500(int arg0, int arg1)
{
    int h;
    int i;
    D_800F45E0_t* actor;

    h = func_8008DA24(arg0, arg1);
    h <<= 17;
    h >>= 17;

    for (i = 0; i < 16; ++i) {
        actor = D_800F45E0[i];
        if (actor != NULL && actor->unk1C == arg0 && actor->unk20 == arg1
            && actor->unk1E - 0x80 < h) {
            h = actor->unk1E - 0x80;
        }
    }
    return h;
}

void func_800A35A8(void)
{
    int i;
    int j;
    int h;
    int x;
    int z;
    D_800F4538_t* actor;
    D_800F45E0_t* obj;

    for (i = 2; i < 17; ++i) {
        actor = D_800F4538[i];

        if (actor != NULL && !actor->unk0.unkA_5 && actor->unk0.unk5D < 2
            && !actor->unk0.unkA_0) {
            x = actor->unk0.position.vx;
            z = actor->unk0.position.vz;
            h = func_8008DA24(x, z);
            h <<= 17;
            h >>= 17;

            for (j = 0; j < 16; ++j) {
                obj = D_800F45E0[j];
                if (obj != NULL && obj->unk1C == x && obj->unk20 == z
                    && obj->unk1E - 0x80 < h) {
                    h = obj->unk1E - 0x80;
                }
            }

            actor->unk0.position.vy = h;
        }
    }
}

void func_800A36E0(int arg0, int arg1, func_8006EBF8_t* arg2)
{
    D_800F4538_t* temp_a0 = D_800F4538[arg0];
    if (temp_a0 != NULL) {
        arg2->unk0.unk0.value = temp_a0->unk1868;
        if (temp_a0->unk0.unkA_5 && ((arg1 == 0x10) || (arg1 == 0x20))) {
            arg2->unk0.unk0.value = *(int*)&temp_a0->unk0.currentTileX;
        }
        arg2->unk0.unk0.fields.unk0_24 = temp_a0->unk0.facing / 16;
    }
}

int func_800A3760(int arg0, int arg1, int arg2)
{
    int i;
    int maxDist;
    int bestDist;
    int best = -1;
    D_800F4538_t* self = D_800F4538[arg0];

    if (self == NULL) {
        return -1;
    }

    maxDist = arg1 * arg1;

    for (i = 0; i < 17; ++i) {
        D_800F4538_t* actor;
        int dx;
        int dy;
        int dz;
        int dist;
        int angle;

        if (i == arg0) {
            continue;
        }
        actor = D_800F4538[i];
        if (actor == NULL || actor->unk0.skip) {
            continue;
        }
        dy = actor->unk0.position.vy - self->unk0.position.vy;
        if (dy < -arg2 || dy > arg2) {
            continue;
        }
        dx = actor->unk0.position.vx - self->unk0.position.vx;
        dz = actor->unk0.position.vz - self->unk0.position.vz;
        dist = dx * dx;
        if (dist < 0) {
            dist = -dist;
        }
        dz = dz * dz;
        if (dz < 0) {
            dz = -dz;
        }
        dist += dz;
        if (dist > maxDist) {
            continue;
        }
        angle = func_8009E180(self, &actor->unk0.position);
        if (angle < -ONE / 4 || angle > ONE / 4) {
            continue;
        }
        if (best == -1) {
            best = i;
            bestDist = dist;
        } else if (dist < bestDist) {
            best = i;
            bestDist = dist;
        }
    }
    return best;
}

int func_800A38E0(int actorId)
{
    D_800F4538_t* actor = D_800F4538[actorId];
    D_800F45E0_t* object;
    int direction;
    int x;
    int z;
    int farX;
    int farZ;
    int objectId;
    int found;
    int oldX;
    int oldZ;

    if (actor == NULL) {
        return -1;
    }
    if (actor->unk5AC_0 != 0) {
        return -1;
    }
    if (actor->unk0.unkA_0 != 0) {
        return -1;
    }
    if (actor->unk0.unkA_3 != 0) {
        return -1;
    }
    direction = actor->unk0.facing + ONE / 8;
    direction &= 0xFFF;
    direction /= ONE / 4;
    D_800F49E8 = direction;
    oldX = farX = x = actor->unk0.currentTileX;
    oldZ = farZ = z = actor->unk0.currentTileZ;
    found = direction < 2 ? -1 : 1;

    if (direction & 1) {
        x += found;
        farX = oldX + (found * 2);
    } else {
        z += found;
        farZ = oldZ + (found * 2);
    }
    if ((x < 0) || (z < 0)) {
        return -1;
    }
    if (actor->unk5AC_3) {
        x = (x * 128) + 64;
        objectId = actor->unk0.unk13;
        object = D_800F45E0[objectId];
        z = (z * 128) + 64;
        if (object->unk1A != 0) {
            return -1;
        }
        if (!func_800A3DB4(x, z, actor->unk0.position.vy - 128)) {
            return -1;
        }
        direction = actor->unk0.position.vy - 384;
        if (direction < func_800A3BC4(actor->unk0.position.vx, actor->unk0.position.vz)) {
            return -1;
        }
        if (direction < func_800A3BC4(x, z)) {
            return -1;
        }
        return objectId;
    } else {
        found = func_800A91DC(x, z, 0);
        if (found == 0) {
            return -1;
        }
        object = D_800F45E0[found];
        objectId = found;
        if (object->unk6C[8].unk0_4 == 1) {
            return -1;
        }
        if (object->unk1A != 0) {
            return -1;
        }
        x = (x * 128) + 64;
        z = (z * 128) + 64;
        farX = (farX * 128) + 64;
        farZ = (farZ * 128) + 64;
        if (object->unk1E < (actor->unk0.position.vy - 128)) {
            return -1;
        }
        if ((actor->unk0.position.vy + 64) < object->unk1E) {
            return -1;
        }
        if (object->unk6C[8].actorId < 4) {

            if (!func_800A3DB4(farX, farZ, object->unk1E)) {
                return -1;
            }
        } else {
            direction = actor->unk0.position.vy - 384;
            if (direction
                < func_800A3BC4(actor->unk0.position.vx, actor->unk0.position.vz)) {
                return -1;
            }
            if (direction < func_800A3BC4(x, z)) {
                return -1;
            }
        }
        if (func_800A3C00(object, 1) == 0) {
            return objectId;
        }
    }
    return -1;
}

int func_800A3BC4(int arg0, int arg1)
{
    short temp_v0 = func_8008DD0C(arg0, arg1);
    if (temp_v0 == 0) {
        return 0;
    }
    return (temp_v0 << 0x11) >> 0x11;
}

D_800F4538_t* func_800A3C00(D_800F45E0_t* arg0, u_int arg1)
{
    return func_800A3C34(arg0->unk5C, arg0->unk5E, arg0->unk1E, arg1);
}

D_800F4538_t* func_800A3C34(int arg0, int arg1, int arg2, int arg3)
{
    int i;

    arg2 -= 192;

    if (arg3 < 2) {
        i = 0;
    } else {
        i = arg3;
    }

    for (; i < 17; ++i) {
        D_800F4538_t* actor = D_800F4538[i];
        if ((actor == NULL) || actor->unk0.skip || (actor->unk6E6 == 0x7F)) {
            continue;
        }
        if ((arg3 == 1)
            && (((actor->unk0.unkB_4 != 0) && (actor->unk0.unkB_4 < 3))
                || actor->unk0.unkA_0 || actor->unk0.unkB_0)) {
            SVECTOR* pos = &actor->unk5EC;
            if (((pos->vx & 0xFF) == arg0) && (arg1 == (pos->vy & 0xFF))) {
                return actor;
            }
            continue;
        }
        if ((i == 0) && (*((int*)&actor->unk5B4 - 2) & 0xF0000000)) {
            D_800F45E0_t* temp_v1 = D_800F45E0[actor->unk5AC_28];
            if ((arg0 == temp_v1->unk5C) && (arg1 == temp_v1->unk5E)) {
                return actor;
            }
            continue;
        }
        if ((actor->unk0.unkA_3 != 2) && (actor->unk0.currentTileX == arg0)
            && (actor->unk0.currentTileZ == arg1) && !actor->unk0.unkA_5
            && (actor->unk0.position.vy >= arg2)) {
            return actor;
        }
    }
    return NULL;
}

int func_800A3DB4(int x, int z, int minimumHeight)
{
    SVECTOR offset;
    int height;
    ((int*)&offset)[0] = 0;
    ((int*)&offset)[1] = 0;
    height = func_800A6EE8(&offset, x, z, 1);
    if (height < minimumHeight) {
        return 0;
    }
    if ((*D_800F49F0 >> 20) & 1) {
        return 0;
    }
    return func_800A3C34(x / 128, z / 128, height, 1) == NULL;
}

int func_800A3E6C(int actorId)
{
    SVECTOR position;
    struct {
        u_char x;
        u_char y;
        u_char z;
        u_char direction;
    } tile;
    D_800F4538_t* actor;
    D_800F45E0_t* object;
    int objectId;
    int height;
    int step;
    int dx;
    int dz;

    actor = D_800F4538[actorId];
    if (actor->unk5AC_20) {
        return -1;
    }
    objectId = func_800A38E0(actorId);
    if (objectId == -1) {
        return -1;
    }
    object = D_800F45E0[objectId];
    object->unk3A = D_800F49E8;
    D_800E90A8 = objectId;
    height = actor->unk0.position.vy - object->unk1E;
    height /= 64;
    height++;

    object->unk34 = 0;
    object->unk38 = 0;
    switch ((*(u_char*)((char*)object + 0x16C)) & 7) {
    case 0:
    case 1:
        *(u_char*)((char*)object + 0x16E) =
            D_800E8FD0[*(u_char*)((char*)object + 0x16E) * 4 + D_800F49E8];
        // fallthrough
    case 2:
        step = 0x80;
        if (D_800F49E8 < 2) {
            step = -0x80;
        }
        if (D_800F49E8 & 1) {
            object->unk34 = step;
        } else {
            object->unk38 = step;
        }
        goto move;
    case 3:
        step = 0x20;
        object->unk34 = 0;
        object->unk38 = 0;
        if (D_800F49E8 < 2) {
            step = -0x20;
        }
        if (D_800F49E8 & 1) {
            object->unk34 = step;
        } else {
            object->unk38 = step;
        }
    move:
        object->unk36 = 0;
        func_800AE6C0(actor, 0x2C, 0x2D);
        func_800A0204(actorId, height + 0x4F, 0, 4);
        *(u_int*)((char*)actor + 0x5AC) |= 0x100000;
        func_800E4C1C(
            (object->unk1C + object->unk34) / 128, (object->unk20 + object->unk38) / 128);
        break;
    case 4:
    case 5:
    case 6:
        if (actor->unk5AC_3) {
            func_800A0204(actorId, 0x4C, 0, 4);
            func_800AE6C0(actor, 0x2E, 0x2F);
            *(u_int*)((char*)actor + 0x5AC) |= 0x100000;
        } else {
            func_800A0204(actorId, height + 0x47, 0, 4);
            func_800AE6C0(actor, 0x2C, 0x2D);
            *(u_int*)((char*)actor + 0x5AC) |= 0x100000;
        }
        dx = 0;
        dz = 0;
        step = 1;
        if (D_800F49E8 < 2) {
            step = -1;
        }

        if (D_800F49E8 & 1) {
            dx = step;
        } else {
            dz = step;
        }
        func_800E4C1C(actor->unk0.currentTileX + dx, actor->unk0.currentTileZ + dz);
        break;
    }
    step = 1;
    *(int*)&tile = *(int*)&actor->unk0.currentTileX;
    if (D_800F49E8 < 2) {
        step = -1;
    }
    if (D_800F49E8 & 1) {
        tile.x += step;
    } else {
        tile.z += step;
    }
    func_800AA454(actorId, (func_8006EBF8_t_fields*)&tile, 4);
    position.vx = (actor->unk0.currentTileX << 7) + 0x40;
    position.vz = (actor->unk0.currentTileZ << 7) + 0x40;
    position.vy = actor->unk0.position.vy;
    func_800AA620(actorId, &position, 4);
}

void func_800A41D0(D_800F4538_t* actor, int mode)
{
    SVECTOR points[2];
    D_800F45E0_t* object;
    int direction;
    int step;
    int facing;
    int x;
    int z;

    object = D_800F45E0[D_800E90A8];
    if (mode == 2) {
        switch ((*(u_char*)((char*)object + 0x16C)) & 7) {
        case 0:
        case 1:
            object->unk1A = 0xF9;
            break;
        case 2:
            object->unk1A = 0xFF;
            break;
        case 3:
            object->unk1A = 0xFE;
            break;
        }
        *(u_char*)((char*)object + 0x170) = 0;
        func_800E68A0(object);
        return;
    }
    if (mode == 1) {
        step = 1;
        x = actor->unk0.currentTileX;
        z = actor->unk0.currentTileZ;
        if (D_800F49E8 < 2) {
            step = -1;
        }
        if (D_800F49E8 & 1) {
            x += step;
        } else {
            z += step;
        }
        step = D_800F49E8;
        object->unk5C = x;
        object->unk5E = z;
        object->unk1C = (x << 7) + 0x40;
        object->unk20 = (z << 7) + 0x40;
        object->unk26 = (object->unk26 + (step << 10)) & 0xFFF;
        func_800A190C(object->unk12, 0xF0, &points[0], 1);
        func_800A190C(object->unk12, 0xF1, &points[1], 1);
        object->unk1E = (points[0].vy + points[1].vy) / 2 + 0x3C;
        object->unk1A = 0xFC;
        object->unk36 = 0x18;
        object->unk12 = 0xFF;
        actor->unk5AC_3 = 0;
        return;
    }
    if ((object == NULL) || object->unk9_0) {
        func_800A0204(actor->unk0.unkF, 1, 0, 8);
        return;
    }
    func_800E4C28(object->unk5C, object->unk5E);
    func_800E68A0(object);
    if (((*(int*)((char*)object + 0x16C)) & 0x30) == 0x20) {
        func_800E68A0(object);
    }
    step = -0x80;
    if (D_800F49E8 < 2) {
        step = 0x80;
    }
    if (D_800F49E8 & 1) {
        object->unk34 += step;
    } else {
        object->unk38 += step;
    }
    facing = ((u_short)object->unk26 + ((4 - D_800F49E8) << 10)) & 0xFFF;
    direction = facing + ONE / 8;
    direction &= 0xFFF;
    object->unk26 = facing;
    direction /= ONE / 4;
    object->unk26 = direction * (ONE / 4);
    object->unk5C = -1;
    object->unk1A = 8;
    object->unk12 = actor->unk0.unkF;
    actor->unk0.unk13 = D_800E90A8;
    actor->unk5AC_3 = 1;
}

int func_800A4494(int contact, SVECTOR* point)
{
    int i;
    D_800F4538_t* actor;
    int dx, dz, hit;
    int radius, x, z, y;
    for (i = 0; i < 17; i++) {
        actor = D_800F4538[i];
        if (actor == 0 || actor->unk0.skip) {
            continue;
        }
        if (actor->unk0.unkC_0 == contact) {
            if (actor->unk0.unkA_3 != 2) {
                continue;
            }
            dx = point->vx - *(short*)&actor->unk17EC[0];
            dz = point->vz - *(short*)&actor->unk17EC[4];
            actor->unk0.position.vx += dx;
            actor->unk0.position.vz += dz;
            hit = func_800A46A4(actor);
            actor->unk0.position.vx -= dx;
            actor->unk0.position.vz -= dz;
            if (!hit) {
                continue;
            }
        transition:
            actor->unk0.unk34.vx = 0;
            actor->unk0.unk34.vy = 3;
            actor->unk0.unk34.vz = 0;
            actor->unk6EE = 0;
            actor->unk6EF = 0;
            actor->unk0.unkA_0 = 3;
            actor->unk0.unkA_3 = 0;
            actor->unk0.unk9_6 = 0;
            actor->unk0.unkC_0 = 0;
            func_800A4A88(actor, 2);
            return 1;
        } else {
            radius = actor->unk63C;
            x = point->vx;
            if (x + 64 < actor->unk0.position.vx - radius
                || x - 64 > actor->unk0.position.vx + radius) {
                continue;
            }
            z = point->vz;
            if (z + 64 < actor->unk0.position.vz - radius
                || z - 64 > actor->unk0.position.vz + radius) {
                continue;
            }
            y = actor->unk0.position.vy;
            if (point->vy < y - 288 || point->vy >= y) {
                continue;
            }
            if (actor->unk0.unkA_3 == 2) {
                goto transition;
            }
            return 1;
        }
    }
    return 0;
}

int func_800A46A4(D_800F4538_t* actor)
{
    collisionScratchView* scratch = (void*)0x1F8003BC;
    int saved = actor->unk0.unkC_0;
    int radius = actor->unk63C;
    int direction;
    collisionScratchView *hit, *previous;
    actor->unk0.unkC_0 = 0;
    actor->unk0.unkA_3 = 0;
    actor->unk0.unk9_6 = 0;
    func_800A70DC(actor, rsin(ONE / 8) * radius / ONE);
    actor->unk0.unkC_0 = saved;
    actor->unk0.unkA_3 = 2;
    direction = (u_short)actor->unk1800 >> 9;
    hit = (void*)((char*)scratch + direction);
    hit->contact = 0;
    hit->nextContact = 0;
    --direction;
    direction &= 7;
    previous = (void*)((char*)scratch + direction);
    previous->contact = 0;
    for (direction = 0; direction < 8; ++direction) {
        if (((collisionScratchView*)((char*)scratch + direction))->contact) {
            return 1;
        }
    }
    return 0;
}

int func_800A47C4(void)
{
    int i;

    for (i = 0; i < 16; ++i) {
        D_800F45E0_t* temp_v1 = D_800F45E0[i];
        if ((D_800F45E0[i] != NULL) && !D_800F45E0[i]->unk8_0 && !temp_v1->unk9_0
            && temp_v1->unk1A) {
            return 1;
        }
    }
    return 0;
}

void func_800A4828(int arg0, MATRIX* arg1)
{
    D_800F4538_t* temp_s1 = D_800F4538[arg0];
    int visible = temp_s1->unk0.visible;
    temp_s1->unk0.visible = 0;
    temp_s1->unk5B2 = 1;
    func_800AECA0(arg1);
    func_800AEAE8(temp_s1);
    func_800B28A8(temp_s1, arg1, 0);
    temp_s1->unk0.visible = visible;
}

void func_800A48CC(int index, int direction, int distance)
{
    D_800F4538_t* actor = D_800F4538[index];
    vs_battleMovementModeFlags* flags = (void*)((char*)actor + 0x5B0);
    if (actor->unk5AC_0 != 0) {
        return;
    }
    if (actor->unk0.unkA_3 != 0) {
        return;
    }
    if (actor->unk0.unkA_0 != 0) {
        func_800B64A8(index, direction, distance);
        return;
    }
    if (distance == 0) {
        flags->fast = 0;
        flags->mode = 0;
        func_800A0204(index, 0x2F, 0, 4);
        actor->unk0.unk11 = 6;
        actor->unk0.unkA_0 = 2;
    } else {
        flags->fast = 0;
        flags->mode = 1;
        if (distance / ONE >= actor->unk5B9) {
            flags->mode = 2;
            flags->fast = 1;
        }
        actor->unk0.unk11 = 0;
        actor->unk0.unkA_0 = 1;
    }
    actor->unk1848.unk0 = 7;
    actor->unk1848.unk4 = direction;
    actor->unk1848.unk8 = distance;
}

inline func_8008D2C0_t* func_800A4A24(int arg0)
{
    func_8008D2C0_t sp10[4];
    int temp_v0;
    int i;
    arg0 -= 2;

    temp_v0 = func_8008D2C0(sp10);

    for (i = 0; i < temp_v0; ++i) {
        if (sp10[i].unk6 == arg0) {
            // BUG: returns stack variable
            return &sp10[i];
        }
    }
    return NULL;
}

void func_800A4A88(D_800F4538_t* actor, int mode)
{
    func_8008D2C0_t* contact;
    int contactId;
    int current;
    int previous;
    u_int movement;

    switch (mode) {
    case 0:
        if (actor->unk0.unkC_0 == 0) {
            return;
        }
        contact = func_800A4A24(actor->unk0.unkC_0);
        actor->unk6EE = contact->unk0 - *(short*)&actor->unk17EC[0];
        actor->unk6EF = contact->unk4 - *(short*)&actor->unk17EC[4];
        actor->unk0.position.vx += (signed char)actor->unk6EE;
        actor->unk0.position.vz += (signed char)actor->unk6EF;
        actor->unk0.position.vy += contact->unk2 - *(short*)&actor->unk17EC[2];
        break;
    case 1:
        movement = *(u_int*)((char*)actor + 8) & 0x70000;
        if (movement == 0x20000 || movement == 0x30000) {
            return;
        }
        if (actor->unk0.unkC_4 != (contactId = actor->unk0.unkC_0)) {
            if (actor->unk0.unkF == 0 && contactId != 0
                && contactId != *(short*)&actor->unk17EC[6]) {
                func_800E4BE0(contactId);
            }
            actor->unk6EE = 0;
            actor->unk6EF = 0;
        }
        if (actor->unk0.unkC_0 == 0) {
            return;
        }
        contact = func_800A4A24(actor->unk0.unkC_0);
        break;
    case 2:
        current = actor->unk0.unkC_0;
        previous = actor->unk0.unkC_4;
        if (current != previous) {
            if (actor->unk0.unkC_0 != 0) {
                *(short*)&actor->unk17EC[6] = current;
                func_8008C49C(actor->unk0.unkC_0 - 2, actor->unk0.unkF);
            } else {
                func_8008C49C(previous - 2, -1);
                if (!actor->unk0.unkA_0) {
                    actor->unk6EE = 0;
                    actor->unk6EF = 0;
                }
            }
        }
        if (actor->unk0.unkF == 0 && !actor->unk0.unkA_0
            && actor->unk0.unkC_0 != *(short*)&actor->unk17EC[6]) {
            func_800E4BD8(*(short*)&actor->unk17EC[6]);
            *(short*)&actor->unk17EC[6] = 0;
        }
        actor->unk0.unk5D = actor->unk0.unkC_0;
        actor->unk0.unkC_4 = actor->unk0.unkC_0;
        return;
    }
    *(short*)&actor->unk17EC[0] = contact->unk0;
    *(short*)&actor->unk17EC[2] = contact->unk2;
    *(short*)&actor->unk17EC[4] = contact->unk4;
}

void func_800A4D8C(void)
{
    int i;

    for (i = 0; i < 16; ++i) {
        if ((D_800F45E0[i] != NULL) && (D_800F45E0[i]->unk0 != 0)) {
            func_800B0908(D_800F45E0[i], vs_gametime_tickspeed / 2);
        }
    }
    for (i = 0; i < 17; ++i) {
        if ((D_800F4538[i] != NULL) && (D_800F4538[i]->unk0.skip == 0)) {
            func_800A4E68(i);
        }
    }
    D_800F4B18 = 1;
}

void func_800A4E68(int arg0)
{
    SVECTOR movement;
    D_800F4538_t* temp_s0;
    int var_v0;
    int var_v1;
    u_int temp_a0;
    u_int temp_v1;
    int temp_v1_2;
    int temp_v1_3;
    int temp_v1_4;

    temp_s0 = D_800F4538[arg0];
    temp_v1 = *(u_int*)((char*)temp_s0 + 8);
    if (!(temp_v1 & 0xF00) || ((u_int)((temp_v1 >> 8) & 0xF) >= 6U)) {
        if (arg0 == 0) {
            func_800A4A88(temp_s0, 0);
            if (!temp_s0->unk0.unkA_0 || (temp_s0->unk181A == 0)) {
                temp_v1_2 = temp_s0->unk1848.unk0;
                switch (temp_v1_2) { /* switch 1; irregular */
                case 7: /* switch 1 */
                case 0: /* switch 1 */
                    movement.pad = 0;
                    goto block_13;
                case 1: /* switch 1 */
                    movement.pad = (short)temp_v1_2;
                    movement.vx = (u_short)temp_s0->unk1848.unk6;
                block_13:
                    func_800A5280(0, (short)temp_s0->unk1848.unk4, temp_s0->unk1848.unk8,
                        &movement);
                    if (temp_s0->unk0.unkA_0) {
                    block_14:
                        func_800AC690(0, temp_s0);
                    }
                    break;

                case 2: /* switch 1 */
                    func_800A25EC(temp_s0);
                    break;
                }
            } else {
                goto block_14;
            }
            func_800A4A88(temp_s0, 1);
            func_800A4A88(temp_s0, 2);
        } else {
            func_800A4A88(temp_s0, 0);
            if (temp_s0->unk1848.unk0 == 2) {
                func_800A25EC(temp_s0);
            } else {
                temp_a0 = *(u_int*)((char*)temp_s0 + 8);
                if (!(temp_a0 & 0x70000)) {
                    if (temp_a0 & 0x0F000000) {
                        func_800A29A0(temp_s0);
                    } else if (temp_a0 & 0x70000000) {
                        func_800A2CD4(temp_s0);
                    } else {
                        temp_v1_3 = temp_s0->unk1848.unk0;
                        switch (temp_v1_3) { /* switch 2; irregular */
                        case 1: /* switch 2 */
                            if (((int)temp_a0 >= 0) && !(temp_a0 & 0x200000)) {
                                movement.pad = (short)temp_v1_3;
                                movement.vx = (u_short)temp_s0->unk1848.unk6;
                                func_800A5280(arg0, (short)temp_s0->unk1848.unk4,
                                    temp_s0->unk1848.unk8, &movement);
                                if (temp_s0->unk0.unkA_0) {
                                block_34:
                                    func_800AC690(arg0, temp_s0);
                                }
                            }
                            break;
                        case 3: /* switch 2 */
                            func_800A2790(temp_s0);
                            break;
                        case 4: /* switch 2 */
                            func_800A291C(temp_s0);
                            break;
                        }
                    }
                } else {
                    goto block_34;
                }
            }
            temp_v1_4 = temp_s0->unk6E4;
            if (temp_v1_4 != 0) {
                if (temp_s0->unk0.unkC_0 == temp_v1_4) {
                    temp_s0->unk0.unkC_0 = 0;
                }
                if (func_800A51A0(temp_s0->unk6E4, &temp_s0->unk0.position) == 0) {
                    temp_s0->unk6E4 = 0;
                    func_800E6B24(temp_s0->unk0.unkF);
                }
                if (temp_s0->unk181A == 1) {
                    temp_s0->unk1814 = (short)(u_short)temp_s0->unk0.position.vx;
                    temp_s0->unk1818 = (short)(u_short)temp_s0->unk0.position.vz;
                }
            }
            func_800A4A88(temp_s0, 1);
            func_800A4A88(temp_s0, 2);
            var_v0 = temp_s0->unk0.position.vx;
            if (var_v0 < 0) {
                var_v0 += 0x7F;
            }
            var_v1 = temp_s0->unk0.position.vz;
            temp_s0->unk0.currentTileX = (u_char)(var_v0 >> 7);
            if (var_v1 < 0) {
                var_v1 += 0x7F;
            }
            temp_s0->unk0.currentTileZ = (u_char)(var_v1 >> 7);
        }
        func_800A525C(temp_s0);
    }
}

int func_800A51A0(int arg0, SVECTOR* arg1)
{
    func_8008D2C0_t sp10[4];
    func_8008D2C0_t* p;
    int n;
    int i;

    arg0 -= 2;
    n = func_8008D2C0(sp10);
    for (i = 0; i < n; i++) {
        if (sp10[i].unk6 == arg0) {
            p = &sp10[i];
            goto found;
        }
    }
    p = NULL;
found:
    if (p->unk0 + 0x40 < arg1->vx) {
        return 0;
    }
    if (arg1->vx < p->unk0 - 0x40) {
        return 0;
    }
    if (p->unk4 + 0x40 < arg1->vz) {
        return 0;
    }
    return !(arg1->vz < p->unk4 - 0x40);
}

void func_800A525C(D_800F4538_t* arg0)
{
    arg0->unk1848.unk0 = 1;
    if (arg0->unk0.unkF == 0) {
        arg0->unk1848.unk0 = 0;
    }
    arg0->unk1848.unk4 = 0;
    arg0->unk1848.unk8 = 0;
    arg0->unk1848.unk6 = 0;
}

int func_800A5280(int index, int direction, int distance, SVECTOR* input)
{
    SVECTOR motion;
    SVECTOR saved;
    int result;
    int previousArea;
    D_800F4538_t* actor;
    int turning;
    int speed;
    int facing;
    int status;
    int angle;
    int animation;
    int i;
    int previousX;
    int previousZ;
    int moveType;
    int state;
    D_800F45E0_t* object;
    vs_battleMovementModeFlags* flags;

    turning = 0;
    if (index >= 17) {
        return 3;
    }
    actor = D_800F4538[index];
    if (actor == NULL) {
        return 3;
    }
    if (actor->unk5AC_0 != 0) {
        return 3;
    }
    if (actor->unk0.unkB_0) {
        return 3;
    }
    if (actor->unk5AC_20) {
        return 3;
    }
    if ((signed char)actor->unk0.unk11 > 0) {
        return 3;
    }
    if (actor->unk0.unkA_3 == 2) {
        if (actor->unk0.unkC_0) {
            func_800ACF54(actor);
            if (D_800F1D6E[actor->unk0.unkC_0] == 7
                && func_800A6EE8(&actor->unk0.position, 0, 0, 1)
                       <= actor->unk0.position.vy) {
            fall:
                actor->unk0.unk34.vy = 3;
                actor->unk6E3 = 0xFF;
                actor->unk0.unkA_0 = 3;
                actor->unk0.unkA_3 = 0;
                actor->unk0.unk9_6 = 0;
                actor->unk0.unkC_0 = 0;
                actor->unk5AC_28 = 0;
                return 3;
            }
        }
        if (distance == 0) {
            return 3;
        }
        i = (direction - (u_short)actor->unk1800) & 0xFFF;
        if ((u_int)(i - ONE / 4) <= ONE / 2) {
            goto fall;
        }
        if (actor->unk0.unk1A != 0) {
            return 3;
        }
        direction = (u_short)actor->unk1800;
        if (distance >= actor->unk5B9 << 12) {
            distance = actor->unk5BA << 12;
        }
    } else if (actor->unk0.unkA_3) {
        i = (direction - (u_short)actor->unk1800) & 0xFFF;
        if (distance == 0) {
            return 3;
        }
        if (i <= ONE / 4) {
            return 3;
        }
        if (i >= ONE * 3 / 4) {
            return 3;
        }
        turning = 1;
        actor->unk0.unkA_3 = 0;
        actor->unk0.unk9_6 = 0;
        actor->unk0.unk1A = 0;
        actor->unk0.unk34.vx = 0;
        actor->unk0.unk34.vy = 0;
        actor->unk0.unk34.vz = 0;
        actor->unk6EC = 0;
        func_800A0204(index, 1, 0, 10);
    }

    if (actor->unk0.unkA_0) {
        if (index != 0) {
            return 3;
        }
        flags = (void*)((char*)actor + 0x5B0);
        if (distance / ONE >= actor->unk5B9) {
            if (!(*(u_int*)flags & 4)) {
                distance = actor->unk5BA << 12;
            }
        } else {
            flags->fast = 0;
        }
        moveType = *(u_short*)((char*)actor + 0xA) & 7;
        if (moveType != 0) {
            if (moveType < 4) {
                if (distance == 0) {
                    goto stop;
                }
            } else if (moveType == 4) {
                return 3;
            }
        }
    }

    if (distance == -1) {
        if (input->vx == 0 && input->vz == 0) {
            animation = actor->animationId;
            if (animation >= 100) {
                animation -= 100;
            }
            if (animation == 1) {
                goto halt;
            }
            if ((u_int)(animation - 13) >= 14) {
                return 3;
            }
        }
        motion.vx = input->vx;
        motion.vz = input->vz;
        speed = actor->unk5BA << 12;
        goto move;
    }
    if (distance == 0) {
        if (actor->unk5AC_15 && input->pad == 0) {
        coast:
            distance = actor->unk1840;
            direction = actor->unk1842;
            distance -= vs_gametime_tickspeed;
            actor->unk1840 = distance;
            if (distance <= 0) {
                actor->unk5AC_15 = 0;
                distance = 0;
            }
            distance <<= 12;
            goto scale;
        }
        if (actor->unk1840 >= actor->unk5B9) {
            if (actor->unk1846 >= 20 && actor->unk1847 < 9) {
                actor->unk1846 = 0;
                actor->unk5AC_15 = 1;
                if (input->pad == 0) {
                    goto coast;
                }
                goto done;
            }
            actor->unk1846 = 0;
        }
        if (actor->unk6E4 == 0) {
            if (actor->unk1840 != 0 || actor->unk0.unkC_0) {
                actor->unk1840 = 0;
            } else if (!actor->unk5AC_12) {
                animation = actor->animationId;
                if (animation >= 100) {
                    animation -= 100;
                }
                if (animation != 0x54) {
                    if (animation == 1) {
                        return 3;
                    }
                    if ((u_int)(animation - 13) >= 14) {
                        return 3;
                    }
                }
            }
        }
    halt:
        speed = 0;
    stop:
        actor->unk0.unk34.vx = 0;
        actor->unk0.unk34.vz = 0;
        motion.vx = 0;
        motion.vz = 0;
        goto move;
    }

    actor->unk5AC_15 = 0;
    actor->unk1840 = distance / ONE;
    if (distance >= actor->unk5B9 << 12) {
        i = actor->unk1846;
        i += vs_gametime_tickspeed / 2;
        actor->unk1842 = direction;
        if (i >= 0x100) {
            i = 0xFF;
        }
        actor->unk1846 = i;
        actor->unk1847 = 0;
    } else {
        i = actor->unk1847;
        i += vs_gametime_tickspeed / 2;
        if (i >= 0x100) {
            i = 0xFF;
        }
        actor->unk1847 = i;
    }
    facing = direction;
    if (input->pad == 1) {
        facing = input->vx;
    }
    facing &= 0xFFF;
    if (distance != 0 && !actor->unk0.unkA_3) {
        func_800A6660(actor, facing, (func_800A6660_t*)input);
    }

scale:
    speed = distance;
    if (actor->unk5BE != 4) {
        speed = distance * actor->unk5BE / 4;
        if (input->pad == 0 && speed > 0x1EFFF) {
            speed = 0x1F000;
        }
    }
    if (speed <= 0) {
        goto done;
    }
    angle = ONE * 3 / 4 - direction;
    motion.vx = rcos(angle) * speed / 0x1000000;
    motion.vz = rsin(angle) * speed / 0x1000000;

move:
    if (actor->unk0.unkA_0 == 3) {
        if (actor->unk0.position.vy > 0) {
            actor->unk6EE = 0;
            actor->unk6EF = 0;
        }
        motion.vx += (signed char)actor->unk6EE;
        motion.vz += (signed char)actor->unk6EF;
    }
    if (actor->unk5AC_12) {
        motion.vx /= 4;
        motion.vz /= 4;
    }
    D_800E90BC = 0;
    status = func_800A76BC(actor, &motion, &result, input->pad);
    switch (status) {
    case 0:
        distance = speed / ONE;
        break;
    case 1:
        distance = motion.vx;
        if (distance < 0) {
            distance = -distance;
        }
        break;
    case 2:
        distance = motion.vz;
        if (distance < 0) {
            distance = -distance;
        }
        break;
    case 3:
        distance = 0;
        if (actor->unk0.unkA_3 == 2) {
            return 3;
        }
        if (turning) {
            actor->unk0.unkA_0 = 3;
        }
        if (actor->unk0.unkA_0) {
            actor->unk0.unk34.vx = 0;
            actor->unk0.unk34.vz = 0;
            if (actor->unk0.unkA_0 == 1) {
                func_800A0204(index, 0x30, 0, 2);
                actor->unk0.unkA_0 = 2;
            }
            return 3;
        }
        motion.vx = 0;
        motion.vz = 0;
        break;
    }

    motion.vy = func_800A6EE8(&actor->unk0.position, motion.vx, motion.vz, 1);
    motion.vy = motion.vy - actor->unk0.position.vy;
    if (!(*(u_int*)((char*)actor + 8) & 0x1F0000)) {
        previousArea = actor->unk5AC_28;
        actor->unk5AC_28 = D_800F49F8;
        actor->unk0.unkC_0 = D_800F49F4;
    }
    if (input->pad == 0) {
        if (motion.vy < -0x20 || status == 3) {
            i = -(motion.vy / 64);
            if (motion.vy & 0x3F) {
                i++;
            }
            if (result < i) {
                result = i;
            }
        } else if (result == 4) {
            motion.vy = motion.vy + actor->unk0.position.vy;
            motion.vy = D_800F4B0A - motion.vy;
            if (motion.vy >= -0xEC) {
                result = 3;
            }
        } else if (D_800F4B0A - actor->unk0.position.vy < -0x5F
                   && actor->unk0.position.vy < 0) {
            result = 2;
        }
        if (status == 3 && result >= 0) {
            result = 5;
        }
    }

    if (actor->unk5AC_12 && speed == 0) {
        if (*(u_short*)((char*)actor + 0x18D6) == actor->unk0.position.vx + motion.vx
            && *(u_short*)((char*)actor + 0x18D8)
                   == actor->unk0.position.vz + motion.vz) {
            distance = 0;
            goto done;
        }
        *(u_short*)((char*)actor + 0x18D6) = *(u_short*)((char*)actor + 0x18D2);
        *(u_short*)((char*)actor + 0x18D8) = *(u_short*)((char*)actor + 0x18D4);
        *(u_short*)((char*)actor + 0x18D2) = actor->unk0.position.vx + motion.vx;
        *(u_short*)((char*)actor + 0x18D4) = actor->unk0.position.vz + motion.vz;
    } else {
        previousX = *(u_short*)((char*)actor + 0x18D2);
        previousZ = *(u_short*)((char*)actor + 0x18D4);
        *(u_short*)((char*)actor + 0x18D2) = 0;
        *(u_short*)((char*)actor + 0x18D4) = 0;
        *(u_short*)((char*)actor + 0x18D6) = previousX;
        *(u_short*)((char*)actor + 0x18D8) = previousZ;
    }

    actor->unk5BE = 4;
    state = *(u_int*)((char*)actor + 8) & 0x70000;
    if (state != 0) {
        if (state == 0x10000) {
            actor->unk0.unk34.vx = motion.vx;
            actor->unk0.unk34.vz = motion.vz;
            func_800A0204(index, 0x30, 0, 4);
            actor->unk0.unkA_0 = 2;
            return 3;
        }
        if (result < 2) {
            if (motion.vy > 0) {
                actor->unk0.unk34.vx = motion.vx;
                actor->unk0.unk34.vz = motion.vz;
                return 3;
            }
            actor->unk0.unk34.vx = 0;
            actor->unk0.unk34.vz = 0;
            return 3;
        }
        if (result != 2) {
            if (result != 3) {
                if (result != 4) {
                    actor->unk0.unk34.vx = 0;
                    actor->unk0.unk34.vz = 0;
                    return 3;
                }
            }
        }
    }

    if (result > 0) {
        if (((*D_800F49F0 >> 5) & 1) && result == 1) {
            actor->unk5BE = 2;
            func_800AA698(index, &motion, 0);
            goto done;
        }
        if (result >= 5) {
            actor->unk17FF = 0;
        blocked:
            if (actor->unk0.unkA_3) {
                return 3;
            }
        reject:
            actor->unk0.unk34.vx = 0;
            actor->unk0.unk34.vz = 0;
            if (turning) {
                actor->unk0.unk34.vy = 0;
                actor->unk0.unkA_0 = 3;
                return 3;
            }
            actor->unk0.unkC_0 = actor->unk0.unkC_4;
            actor->unk5AC_28 = previousArea;
            distance = 0;
            status = 3;
            goto done;
        }
        if (result >= 2 && (actor->unk0.weaponDrawn || actor->unk5AC_3)) {
            goto blocked;
        }
        if (!actor->unk0.unkA_0 && input->pad == 0 && result != 1 && actor->unk17FF < 8) {
            actor->unk17FF++;
            if (actor->unk0.unkA_3 != 2) {
                goto blocked;
            }
            return 3;
        }
        *(probePosition*)&saved = *(probePosition*)&motion;
        motion.vx = D_800F4B08.vx - actor->unk0.position.vx;
        motion.vy = D_800F4B08.vy - actor->unk0.position.vy;
        motion.vz = D_800F4B08.vz - actor->unk0.position.vz;
        actor->unk0.unkC_0 = D_800F4B08.pad;
        if (result == 4) {
            if (actor->unk0.unkA_3 == 2) {
                goto fallStep;
            }
            if (func_800A6798(actor, &motion, &saved) == 0) {
                goto reject;
            }
            actor->unk5AC_28 = (u_short)D_800F4B08.pad >> 8;
            actor->unk6EC = D_800F4B08.vy;
            if (actor->unk5AC_28) {
                object = D_800F45E0[*(u_int*)((char*)actor + 0x5AC) >> 28];
                if (object->unk1A == 0xFD) {
                    for (i = object->unk6C[8].unk4; i < 15; i++) {
                        motion.vy += (signed char)D_800E91AC[i];
                        actor->unk6EC += (signed char)D_800E91AC[i];
                    }
                }
            }
            if (func_800A9530(actor, &motion) == 0) {
                goto reject;
            }
            func_800AA600(index, &motion, 4);
            func_800AA850(index, D_800F49F9 << 9, 4);
            actor->unk17FF = 0;
            actor->unk0.currentTileX = actor->unk0.position.vx / 128;
            actor->unk0.currentTileZ = actor->unk0.position.vz / 128;
            if ((*(int*)((char*)actor + 0x60) & 0xFF00FF)
                    != (*(int*)((char*)actor + 0x5C) & 0xFF00FF)
                || actor->unk0.unk61 != actor->unk0.unkC_0) {
                actor->unk0.lastTouchedTileX = D_800F4B08.vx / 128;
                actor->unk0.lastTouchedTileZ = D_800F4B08.vz / 128;
                actor->unk0.unk61 = actor->unk0.unkC_0;
            }
        } else if (actor->unk0.unkA_3 == 2) {
        fallStep:
            if (actor->unk5AC_12) {
                motion.vx = 0;
                motion.vz = 0;
            }
            func_800AA600(index, &motion, 0x18);
            actor->unk6EC = 0;
        } else {
            if (input->pad == 0) {
                if ((u_short)(motion.vy + 0xFF) >= 0x100) {
                    goto blocked;
                }
                if (distance == 0) {
                    goto blocked;
                }
            }
            if (result >= 2) {
                if (actor->unk0.unkA_0 && actor->unk5AC_12) {
                    goto reject;
                }
                if (func_800A69B4(actor) == 0) {
                    goto reject;
                }
            }
            func_800AA600(index, &motion, result * 8);
        }
        if (result == 1) {
            animation = actor->animationId;
            if (animation >= 100) {
                animation -= 100;
            }
            if ((u_int)(animation - 13) >= 2 && animation != 0x13 && animation != 0x14
                && animation != 0x54) {
                func_800A0204(index, D_800E90C4, 0, 4);
            }
            actor->unk0.unkA_3 = 1;
            actor->unk1800 = (actor->unk0.facing + actor->unk0.unk3E) & 0xFFF;
            actor->unk0.unk9_6 = 1;
        } else if (actor->unk0.unkA_3 == 2) {
            func_800A0204(index, D_800E90C6, 0, 4);
            if (index == 0) {
                func_800AE6C0(actor, 0x2A, 0x2B);
            } else {
                func_800AE4FC(&actor->unk0, 0xC);
            }
            func_800A6660(actor, facing, (func_800A6660_t*)input);
        } else {
            if (result == 4) {
                actor->unk0.unkA_3 = 2;
            }
            func_800A0204(index, D_800E90C3[result], 0, 4);
            actor->unk1800 = (actor->unk0.facing + actor->unk0.unk3E) & 0xFFF;
            if (index == 0) {
                func_800AE6C0(actor, 0x29, 0);
            } else {
                func_800AE4FC(&actor->unk0, 0xC);
            }
        }
        actor->unk0.unk11 = 0;
        actor->unk6EE = 0;
        actor->unk6EF = 0;
        actor->unk0.unkA_0 = 0;
        return 3;
    }

    if (motion.vy > 0) {
        if (actor->unk0.unkA_3 == 2) {
            motion.vx = 0;
            motion.vz = 0;
            goto fall;
        }
        if (actor->unk0.unkC_0) {
            func_800A9378(actor->unk0.position.vx, actor->unk0.position.vy,
                actor->unk0.position.vz, 0);
            actor->unk0.unkC_0 = D_800F49F4;
        }
        if (motion.vy >= 0x40) {
            if (input->pad == 0) {
                if (motion.vy >= 0x100) {
                    if (actor->unk0.unkA_3 != 2 && actor->unk17FF < 8) {
                        actor->unk17FF++;
                        goto blocked;
                    }
                    actor->unk0.unk11 = 0;
                }
            } else {
                func_800A3054(actor, (func_800A3054_t*)&motion);
            }
            actor->unk0.unk34.vx = motion.vx;
            actor->unk0.unk34.vz = motion.vz;
            actor->unk0.unk34.vy = 0;
            func_800A0204(index, 0x2F, 0, 4);
            actor->unk0.unkA_0 = 3;
            flags = (void*)((char*)actor + 0x5B0);
            flags->fast = 0;
            flags->mode = 1;
            if (distance >= actor->unk5B9) {
                flags->mode = 2;
                flags->fast = 1;
            }
            actor->unk0.unkC_0 = 0;
            return 3;
        }
        actor->unk17FF = 0;
        if (!((*D_800F49F0 >> 5) & 1)) {
            actor->unk5BE = 5;
        }
        goto land;
    }
    actor->unk6EC = 0;
    actor->unk0.unkA_3 = 0;
    actor->unk0.unk9_6 = 0;
    if (motion.vy < -2) {
        actor->unk5BE = 2;
    }
    actor->unk17FF = 0;
land:
    func_800AA698(index, &motion, 0);

done:
    if (!actor->unk0.unkA_0) {
        func_800A6AA0(actor, distance, direction);
    }
    return status;
}

void func_800A6660(D_800F4538_t* arg0, int arg1, func_800A6660_t* arg2)
{
    int delta;

    if (arg1 == arg0->unk0.facing) {
        return;
    }
    if (arg0->unk0.unk18 != 0) {
        if (arg2->unk6 == 0) {
            delta = arg1 - ((arg0->unk0.facing + arg0->unk0.unk3E) & 0xFFF);
            if (delta >= ONE / 2) {
                delta -= ONE;
            } else if (delta < -ONE / 2) {
                delta += ONE;
            }
            arg0->unk0.unk3E += delta;
        } else {
            delta = arg1 - arg0->unk0.facing;
            if (delta >= ONE / 2) {
                delta -= ONE;
            } else if (delta < -ONE / 2) {
                delta += ONE;
            }
            arg0->unk0.unk3E = delta;
            arg0->unk0.unk18 = 12;
        }
    } else {
        func_800AA850(arg0->unk0.unkF, arg1, 12);
    }
    if (arg0->unk63C > 0x80) {
        delta = arg0->unk0.unk3E / 32;
        if (delta < 0) {
            delta = -delta;
        }
        if (arg0->unk0.unk18 < delta) {
            arg0->unk0.unk18 = delta;
        }
    }
}

int func_800A6798(D_800F4538_t* actor, SVECTOR* offset, SVECTOR* motion)
{
    probePosition saved;
    int height;
    int valid = 0;
    if (actor->unk6EC <= D_800F4B0A) {
        return 0;
    }
    offset->vx = 0;
    offset->vz = 0;
    offset->vy += 0xEC;
    saved = *(probePosition*)&actor->unk0.position;
    actor->unk0.position.vx += offset->vx;
    actor->unk0.position.vy += offset->vy;
    actor->unk0.position.vz += offset->vz;
    actor->unk0.unkA_3 = 2;
    if (func_800A76BC(actor, motion, &height, 0) != 3 && !actor->unk5AC_13
        && height < 5) {
        height = rsin(ONE / 8);
        height = height * actor->unk63C / ONE;
        if ((D_800F49F9 >> 1) & 1) {
            offset->vz = height;
        } else {
            offset->vx = height;
        }
        height = func_800A6EE8(&D_800F4B08, offset->vx, offset->vz, 1);
        height -= D_800F4B08.vy;
        if (height >= -0x3F) {
            height = func_800A6EE8(&D_800F4B08, -offset->vx, -offset->vz, 1);
            height -= D_800F4B08.vy;
            if (height >= -0x3F) {
                valid = 1;
            }
        }
    }
    actor->unk0.unkA_3 = 0;
    actor->unk0.unk9_6 = 0;
    offset->vx = 0;
    offset->vz = 0;
    *(probePosition*)&actor->unk0.position = saved;
    return valid;
}

int func_800A69B4(D_800F4538_t* arg0)
{
    SVECTOR v;
    int ret = 0;
    int h = rsin(ONE / 8) * arg0->unk63C / ONE;

    v.vx = 0;
    v.vz = 0;
    if ((D_800F49F9 >> 1) & 1) {
        v.vz = h;
    } else {
        v.vx = h;
    }
    h = func_800A6EE8(&D_800F4B08, v.vx, v.vz, 1) - D_800F4B08.vy;
    if (h > -64) {
        h = func_800A6EE8(&D_800F4B08, -v.vx, -v.vz, 1) - D_800F4B08.vy;
        if (h > -64) {
            ret = 1;
        }
    }
    return ret;
}

int func_800A6AA0(D_800F4538_t* actor, int speed, int direction)
{
    u_short* entry;
    int next;
    int frames;
    int quadrant;
    int animation;
    u_int flags;
    u_int state;
    u_int walkState;
    int phase;
    int step;
    u_int result;

    animation = actor->animationId;
    if (animation >= 100) {
        animation -= 100;
    }
    quadrant = 0;
    if (actor->unk1848.unk0 == 1) {
        quadrant = (short)actor->unk1848.unk6 - (short)actor->unk1848.unk4 + ONE / 8;
        quadrant &= 0xFFF;
        quadrant /= ONE / 4;
    }
    flags = *(u_int*)((char*)actor + 0x5AC);
    if (flags & 8) {
        next = 0x54;
        if (speed > 0) {
            frames = 4;
        } else {
            next = 0x4B;
            frames = 10;
        }
        if (animation == 0x5F) {
            return;
        }
        goto play;
    }
    if (actor->unk0.unkA_6) {
        if (speed >= actor->unk5B9) {
            next = D_800E90D0[quadrant];
            frames = 20;
        } else if (speed > 0) {
            next = D_800E90CC[quadrant];
            frames = 20;
        } else {
            next = 1;
            frames = 10;
        }
    play:
        func_800A0204(actor->unk0.unkF, next, 0, frames);
        return;
    }
    if (flags & 0x8000) {
        if ((u_int)(animation - 0x19) < 2) {
            return;
        }
        next = 0x1A;
        if ((u_int)(animation - 0x12) >= 2) {
            if (animation == 0x14 || animation == 0x11) {
                next = 0x19;
                goto queue;
            }
            *(u_int*)((char*)actor + 0x5AC) = flags & ~0x8000;
            return;
        }
    queue:
        func_800AD494(actor, next, &entry);
        if (entry == NULL) {
            next = 6;
        }
        func_800A0204(actor->unk0.unkF, next, 0, 8);
    } else if (speed >= actor->unk5B9 - 1) {
        if ((u_int)(animation - 0x13) < 2) {
            return;
        }
        if ((u_int)(animation - 0xF) < 4 || (u_int)(animation - 0x2E) < 11
            || (u_int)(animation - 9) < 4 || animation == 1 || animation == 6) {
            state = *(u_int*)((char*)actor + 0x5AC);
            result = state & ~0x02000000;
            state >>= 25;
            state &= 1;
            result |= (state ^ 1) << 25;
            *(u_int*)((char*)actor + 0x5AC) = result;
            func_800A0204(actor->unk0.unkF, state + 0x13, 0, 6);
            return;
        }
        next = 0x13;
        if (animation == 0xD || animation == 0xF) {
            next = 0x14;
        }
        func_800A01C8(actor->unk0.unkF, next, 4, 0);
        return;
    } else if (speed > 0) {
        if ((u_int)(animation - 0x2E) >= 11 && (u_int)(animation - 9) >= 4) {
            if ((u_int)(animation - 0xD) < 2) {
                if (quadrant != 2) {
                    return;
                }
                goto walk_toggle;
            } else if ((u_int)(animation - 0xF) < 2) {
                if (quadrant == 2) {
                    return;
                }
                goto walk_toggle;
            } else {
                if (animation == 1 || animation == 6 || animation == 0x11
                    || animation == 0x12) {
                    goto walk_toggle;
                }
                goto walk_start;
            }
        } else {
        walk_toggle:
            walkState = *(u_int*)((char*)actor + 0x5AC);
            phase = (walkState >> 25) & 1;
            step = (u_char)phase;
            next = step + 0xD;
            *(u_int*)((char*)actor + 0x5AC) =
                (walkState & ~0x02000000) | ((phase ^ 1) << 25);
            if (quadrant == 2) {
                next = step + 0xF;
            }
            func_800A0204(actor->unk0.unkF, next, 0, 6);
            return;
        walk_start:
            next = 0xD;
            if (animation == 0x13 || animation == 0xF || animation == 0xD) {
                next += 1;
            }
            if (quadrant == 2) {
                next += 2;
            }
            func_800A01C8(actor->unk0.unkF, next, 4, 0);
            return;
        }
    } else {
        if ((u_int)(animation - 0xD) < 4) {
            func_800A0204(actor->unk0.unkF, 6, 0, 10);
            func_800A01C8(actor->unk0.unkF, 1, 10, 0);
            return;
        }
        if (animation != 1 && actor->unk1848.unk0 != 6) {
            func_800A0204(actor->unk0.unkF, 1, 0, 10);
            actor->unk5B3 = 0;
        }
        actor->unk5B3 += vs_gametime_tickspeed / 2;
        if (actor->unk5B3 >= 250) {
            actor->unk5B3 = 250;
        }
    }
}

int func_800A6EE8(SVECTOR* arg0, int arg1, int arg2, int arg3)
{
    SVECTOR sp;
    u_int* ent;
    int h;
    int r;
    int los;

    int x = arg1 + arg0->vx;
    int z = arg2 + arg0->vz;

    sp.vx = x;
    sp.vz = z;

    ent = func_800A8D64(&sp, 0);

    if (ent != NULL) {

        D_800F49F0 = ent;

        if (arg3 == 0) {
            h = func_8008DC7C(x, z);
        } else {
            h = func_8008DA24(x, z);
        }

        if (h >= 0) {

            h <<= 17;
            h >>= 17;

            if (arg3 == 2) {
                r = func_800B13CC(x / 128, z / 128, arg0->vy);
            } else {
                r = func_800A92B8(x / 128, z / 128);
            }

            if (r != 0) {
                h = r;
            }

            if (((*ent >> 17) & 1) && (h >= 0)) {

                h = 3000;

                if (arg3 == 3) {

                    los = D_800E9278[*ent & 0x1F];

                    if (los == 0x14) {
                        h = 0;
                    }
                }
            }

            if (arg3 != 2 && arg3 != 4) {

                los = func_800A9378(x, arg0->vy, z, 0);

                r = h;

                if ((los != 0) && (los < h)) {
                    h = los;
                }

                if (arg3 == 3 && h < arg0->vy - 64) {
                    h = r;
                }
            }

            return h;
        }
    }

    if (arg3 == 3) {
        return arg0->vy;
    }

    return -3000;
}

static inline int vs_battleRelativeSampleHeight(
    ActorCollisionSamples* samples, int sector, int offset, int y)
{
    return samples->heights[(sector + offset) & 7] - y;
}
void func_800A70DC(D_800F4538_t* actor, int diagonal)
{
    ActorCollisionSamples* samples = (void*)0x1F8003BC;
    ActorCollisionSamples* clearCursor;
    int i, j, negativeRadius, negativeDiagonal, delta;
    actor->unk5AC_12 = 0;
    i = 7;
    clearCursor = (void*)((char*)samples + i);
    for (; i >= 0; i--) {
        clearCursor->blocked[0] = 0;
        clearCursor = (void*)((char*)clearCursor - 1);
    }
    if (*(u_int*)((char*)actor + 0x5AC) & 0x600) {
        for (i = 7; i >= 0; i--) {
            samples->heights[i] = 0;
        }
        return;
    }
    if (actor->unk0.unkA_3 == 2) {
        for (i = 0; i < 8; i++) {
            samples->heights[i] = actor->unk0.position.vy;
        }
        return;
    }
    i = actor->unk63C;
    negativeRadius = -i;
    samples->centerAttribute = (*func_800A8D64((&actor->unk0.position), 0) >> 5) & 1;
    samples->heights[0] = func_800A6EE8((&actor->unk0.position), 0, negativeRadius, 0);
    samples->attributes[0] = (*D_800F49F0 >> 5) & 1;
    samples->heights[6] = func_800A6EE8((&actor->unk0.position), i, 0, 0);
    samples->attributes[6] = (*D_800F49F0 >> 5) & 1;
    samples->heights[2] = func_800A6EE8((&actor->unk0.position), negativeRadius, 0, 0);
    samples->attributes[2] = (*D_800F49F0 >> 5) & 1;
    negativeDiagonal = -diagonal;
    samples->heights[7] =
        func_800A6EE8((&actor->unk0.position), diagonal, negativeDiagonal, 0);
    samples->attributes[7] = (*D_800F49F0 >> 5) & 1;
    samples->heights[1] =
        func_800A6EE8((&actor->unk0.position), negativeDiagonal, negativeDiagonal, 0);
    samples->attributes[1] = (*D_800F49F0 >> 5) & 1;
    samples->heights[3] =
        func_800A6EE8((&actor->unk0.position), negativeDiagonal, diagonal, 0);
    samples->attributes[3] = (*D_800F49F0 >> 5) & 1;
    samples->heights[5] = func_800A6EE8((&actor->unk0.position), diagonal, diagonal, 0);
    samples->attributes[5] = (*D_800F49F0 >> 5) & 1;
    samples->heights[4] = func_800A6EE8((&actor->unk0.position), 0, i, 0);
    samples->attributes[4] = (*D_800F49F0 >> 5) & 1;
    if (actor->unk0.unkA_0 == 3 && actor->unk0.unk34.vy > 0) {
        j = actor->unk0.position.vy - 32;
    } else if (actor->unk1848.unk8 == 0) {
        j = actor->unk0.position.vy - 64;
    } else {
        j = actor->unk0.position.vy - 96;
    }
    for (i = 0; i < 8; i++) {
        if (samples->heights[i] > actor->unk0.position.vy) {
            samples->heights[i] = actor->unk0.position.vy;
        }
        if ((!samples->attributes[i] || !samples->centerAttribute)
            && j >= samples->heights[i]) {
            samples->blocked[i] = 1;
            actor->unk5AC_12 = 1;
        }
    }
    if (actor->unk0.unkA_0) {
        i = (short)actor->unk1848.unk4 + ONE / 16;
        i /= ONE / 8;
        j = 0;
        do {
            delta =
                vs_battleRelativeSampleHeight(samples, i, j - 1, actor->unk0.position.vy);
            if (delta < -255) {
                return;
            }
            ++j;
            if (delta >= -192) {
                return;
            }
        } while (j < 3);
        j = 0;
        do {
            delta =
                vs_battleRelativeSampleHeight(samples, i, j + 2, actor->unk0.position.vy);
            ++j;
            if (delta < -192) {
                return;
            }
        } while (j < 5);
        samples->heights[i] = actor->unk0.position.vy;
        actor->unk5AC_12 = 0;
    }
}

void func_800A7524(D_800F4538_t* actor, SVECTOR* motion)
{
    collisionResponseScratch* scratch;
    int x, z;
    if (actor->unk5AC_12) {
        scratch = (void*)0x1F8003BC;
        x = 0;
        z = (scratch->contacts[0] != 0) * 16;
        if (scratch->contacts[1]) {
            x = 8;
            z += 8;
        }
        if (scratch->contacts[2]) {
            x += 16;
        }
        if (scratch->contacts[3]) {
            x += 8;
            z -= 8;
        }
        if (scratch->contacts[4]) {
            z -= 16;
        }
        if (scratch->contacts[5]) {
            x -= 8;
            z -= 8;
        }
        if (scratch->contacts[6]) {
            x -= 16;
        }
        if (scratch->contacts[7]) {
            x -= 8;
            z += 8;
        }
        if (x > 16) {
            x = 16;
        }
        if (x < -16) {
            x = -16;
        }
        if (z > 16) {
            z = 16;
        }
        if (z < -16) {
            z = -16;
        }
        if (x != 0) {
            if (x < 0) {
                if (motion->vx > 0) {
                    motion->vx = 0;
                }
            } else if (motion->vx < 0) {
                motion->vx = 0;
            }
        }
        if (z != 0) {
            if (z < 0) {
                if (motion->vz > 0) {
                    motion->vz = 0;
                }
            } else if (motion->vz < 0) {
                motion->vz = 0;
            }
        }
        motion->vx += x;
        motion->vz += z;
        actor->unk6EE = 0;
        actor->unk6EF = 0;
    }
}

int func_800A76BC(D_800F4538_t* actor, SVECTOR* motion, int* result, int probeOnly)
{
    int xResults[5];
    int zResults[5];
    int probeDirections[2];
    SVECTOR probe;
    SVECTOR opposite;
    SVECTOR xProbe;
    SVECTOR zProbe;
    u_int* probeTiles[2];
    int sideOffset;
    int cornerStep;
    int diagonal;
    int radius;
    D_1F8003BC_t* scratch;
    int direction;
    int offset;
    int diagonalOffset;
    int crossOffset;
    int crossDiagonalOffset;
    int cross;
    int crossDiagonal;
    int expected;
    int facing;
    int x;
    int z;

    scratch = (D_1F8003BC_t*)0x1F8003BC;
    scratch->unk18 = (D_800F45E0_t*)actor;
    actor->unk5AC_14 = actor->unk5AC_13;
    actor->unk5AC_13 = 0;
    radius = actor->unk63C;
    diagonal = rsin(ONE / 8) * radius / ONE;
    scratch->unk0 = -0xC0;
    if (actor->unk0.weaponDrawn) {
        scratch->unk40 = -0x40;
    } else if (actor->unk5AC_3) {
        scratch->unk0 = -0x140;
        scratch->unk40 = -0x40;
    } else {
        scratch->unk40 = -0x100;
    }

    if (probeOnly) {
        scratch->unk40 = -0x100;
        actor->unk5AC_10 = 0;
        actor->unk5AC_12 = 0;
        if (!actor->unk0.unkC_0) {
            probeTiles[0] = func_800A8D64(&actor->unk0.position, actor->unk0.unk5D);
            if (probeTiles[0] == NULL) {
                actor->unk5AC_10 = 1;
            }
        }
        probe.vx = actor->unk0.position.vx + motion->vx;
        probe.vz = actor->unk0.position.vz + motion->vz;
        scratch->unk1C[0] = actor->unk0.position.vy;
        scratch->unk0 = 0;
        xResults[0] = func_800A8B34(&probe, 0);
        D_800F4B08 = probe;
        if (xResults[0] == 0xFF) {
            *result = 0;
            return 3;
        }
        D_800F49F0 = probeTiles[0];
        *result = xResults[0];
        if (*result >= 2) {
            *result = 1;
        }
        return 0;
    }

    if (func_800A8FD4(actor, motion) == 0) {
        return 3;
    }
    func_800A70DC(actor, diagonal);
    func_800A7524(actor, motion);
    actor->unk5AC_10 = 0;
    if (!actor->unk0.unkC_0) {
        probeTiles[0] = func_800A8D64(&actor->unk0.position, actor->unk0.unk5D);
        if (probeTiles[0] == NULL) {
            actor->unk5AC_10 = 1;
        } else {
            actor->unk5AC_10 = 0;
        }
    }

    if (motion->vx == 0) {
        xResults[0] = 0xFF;
        goto probeZ;
    }
    if (motion->vz == 0) {
        zResults[0] = 0xFF;
        goto probeX;
    }

    direction = 6;
    if (motion->vx < 0) {
        offset = -radius;
        direction = 2;
        diagonalOffset = -diagonal;
    } else {
        offset = radius;
        diagonalOffset = diagonal;
    }
    if (motion->vz < 0) {
        crossOffset = -radius;
        crossDiagonalOffset = -diagonal;
        if (direction == 2) {
            direction = 1;
        } else {
            direction = 7;
        }
    } else {
        crossOffset = radius;
        crossDiagonalOffset = diagonal;
        if (direction == 2) {
            direction = 3;
        } else {
            direction = 5;
        }
    }
    probe.vx = actor->unk0.position.vx + motion->vx + diagonalOffset;
    probe.vz = actor->unk0.position.vz + motion->vz + crossDiagonalOffset;
    xResults[0] = func_800A8B34(&probe, direction);
    D_800F4B08 = probe;
    probeTiles[0] = D_800F49F0;
    probe.vx -= diagonalOffset * 2;
    direction -= 2;
    xResults[1] = func_800A8B34(&probe, direction);
    probe.vx += diagonalOffset * 2;
    probe.vz -= crossDiagonalOffset * 2;
    direction += 4;
    xResults[2] = func_800A8B34(&probe, direction);
    probe.vx -= diagonalOffset;
    probe.vz += crossDiagonalOffset + crossOffset;
    direction -= 3;
    xResults[3] = func_800A8B34(&probe, direction);
    probe.vx += offset;
    probe.vz -= crossOffset;
    direction += 2;
    xResults[4] = func_800A8B34(&probe, direction);
    // offset/diagonalOffset are reused for the height delta and the climb limit
    offset = D_800F4B08.vy - actor->unk0.position.vy;
    diagonalOffset = offset / 64;
    if (offset & 0x3F) {
        diagonalOffset--;
    }
    diagonalOffset = -diagonalOffset;
    if (diagonalOffset <= 0) {
        diagonalOffset = 1;
    }
    if (xResults[0] != 0xFF && xResults[1] <= diagonalOffset
        && xResults[2] <= diagonalOffset && xResults[3] <= diagonalOffset
        && xResults[4] <= diagonalOffset && (xResults[0] < 4 || (direction & 1))) {
        D_800F49F0 = probeTiles[0];
        D_800F49F9 = (direction - 1) & 7;
        *result = xResults[0];
        return 0;
    }

    if (motion->vx != 0) {
    probeX:
        direction = 6;
        if (motion->vx < 0) {
            offset = -radius;
            direction = 2;
            diagonalOffset = -diagonal;
        } else {
            offset = radius;
            diagonalOffset = diagonal;
        }
        probe.vx = actor->unk0.position.vx + motion->vx + offset;
        probe.vz = actor->unk0.position.vz;
        xResults[0] = func_800A8B34(&probe, direction);
        *(probePosition*)&xProbe = *(probePosition*)&probe;
        probeDirections[0] = direction;
        direction -= 2;
        probeTiles[0] = D_800F49F0;
        probe.vx -= offset;
        probe.vz += offset;
        xResults[1] = func_800A8B34(&probe, direction);
        direction += 4;
        probe.vz -= offset * 2;
        xResults[2] = func_800A8B34(&probe, direction);
        direction -= 3;
        probe.vx += diagonalOffset;
        probe.vz += offset + diagonalOffset;
        xResults[3] = func_800A8B34(&probe, direction);
        probe.vz -= diagonalOffset * 2;
        xResults[4] = func_800A8B34(&probe, direction + 2);
    } else {
        xResults[0] = 0xFF;
    }

    if (motion->vz != 0) {
    probeZ:
        direction = 4;
        if (motion->vz < 0) {
            offset = -radius;
            direction = 0;
            diagonalOffset = -diagonal;
        } else {
            offset = radius;
            diagonalOffset = diagonal;
        }
        probe.vx = actor->unk0.position.vx;
        probe.vz = actor->unk0.position.vz + motion->vz + offset;
        zResults[0] = func_800A8B34(&probe, direction);
        *(probePosition*)&zProbe = *(probePosition*)&probe;
        probeDirections[1] = direction;
        direction -= 2;
        probeTiles[1] = D_800F49F0;
        probe.vx -= offset;
        probe.vz -= offset;
        zResults[1] = func_800A8B34(&probe, direction);
        direction += 4;
        probe.vx += offset * 2;
        zResults[2] = func_800A8B34(&probe, direction);
        direction -= 3;
        probe.vx -= offset + diagonalOffset;
        probe.vz += diagonalOffset;
        zResults[3] = func_800A8B34(&probe, direction);
        probe.vx += diagonalOffset * 2;
        zResults[4] = func_800A8B34(&probe, direction + 2);
    } else {
        zResults[0] = 0xFF;
    }

    x = motion->vx;
    z = motion->vz;

    if (ABS(x) == ABS(z) || ABS(x) >= ABS(z)) {
        offset = xProbe.vy - actor->unk0.position.vy;
        diagonalOffset = offset / 64;
        if (offset & 0x3F) {
            diagonalOffset--;
        }
        diagonalOffset = -diagonalOffset;
        if (diagonalOffset <= 0) {
            diagonalOffset = 1;
        }
        if (xResults[0] != 0xFF && xResults[1] <= diagonalOffset
            && xResults[2] <= diagonalOffset && xResults[3] <= diagonalOffset
            && xResults[4] <= diagonalOffset) {
            if (actor->unk5AC_14) {
                if (x < 0) {
                    facing = actor->unk17FE;
                    expected = 6;
                } else {
                    facing = actor->unk17FE;
                    expected = 2;
                }
                if (facing == expected) {
                    goto slideX;
                }
            }
            goto acceptX;
        }
        if (zResults[0] != 0xFF && zResults[1] < 2 && zResults[2] < 2 && zResults[3] < 2
            && zResults[4] < 2) {
            if (actor->unk5AC_14) {
                if (motion->vz < 0) {
                    if (actor->unk17FE == 4) {
                        goto slideX;
                    }
                } else if (actor->unk17FE == 0) {
                    goto slideX;
                }
            }
            motion->vx = 0;
            *result = zResults[0];
            D_800F4B08 = zProbe;
            D_800F49F0 = probeTiles[1];
            D_800F49F9 = probeDirections[1];
            return 2;
        }
    slideX:
        if (actor->unk0.unkA_0) {
            return 3;
        }
        direction = 6;
        if (motion->vx < 0) {
            offset = -radius;
            direction = 2;
            diagonalOffset = -diagonal;
        } else {
            offset = radius;
            diagonalOffset = diagonal;
        }
        direction -= 1;
        probe.vx = actor->unk0.position.vx + motion->vx + offset;
        probe.vz = actor->unk0.position.vz + offset;
        zResults[0] = func_800A8B34(&probe, direction);
        direction += 2;
        opposite.vx = probe.vx;
        opposite.vz = actor->unk0.position.vz - offset;
        zResults[1] = func_800A8B34(&opposite, direction);
        if (zResults[0] == 0xFF && zResults[1] == 0xFF) {
            return 3;
        }
        // crossOffset/crossDiagonalOffset are reused for the half step and the turn
        crossOffset = motion->vx / 2;
        if (zResults[0] < 2) {
            if (zResults[1] < 2) {
                direction -= 2;
                probe.vx = actor->unk0.position.vx + motion->vx;
                probe.vz = actor->unk0.position.vz + offset;
                zResults[2] = func_800A8B34(&probe, direction);
                direction += 2;
                opposite.vx = probe.vx;
                opposite.vz = actor->unk0.position.vz - offset;
                zResults[3] = func_800A8B34(&opposite, direction);
                if (zResults[2] == 0xFF && zResults[3] == 0xFF) {
                    return 3;
                }
                if (zResults[2] > 0) {
                    goto slideXBack;
                }
                if (zResults[3] <= 0 && (zResults[0] != 0 || zResults[1] != 1)) {
                    if (zResults[0] == 1 && zResults[1] == 1) {
                        goto slideXBack;
                    }
                    if (probe.vy <= opposite.vy) {
                        goto slideXBack;
                    }
                }
            }
            sideOffset = offset;
            crossDiagonal = -diagonalOffset;
            cross = crossOffset;
            crossDiagonalOffset = 1;
            cornerStep = -3;
        slideXProbe:
            direction -= crossDiagonalOffset;
            probe.vx = actor->unk0.position.vx + crossOffset + offset;
            probe.vz = actor->unk0.position.vz + cross;
            zResults[1] = func_800A8B34(&probe, direction);
            if (zResults[1] < scratch->unk40) {
                zResults[1] = 0xFF;
            }
            direction += crossDiagonalOffset;
            probe.vx = actor->unk0.position.vx + crossOffset + diagonalOffset;
            probe.vz = actor->unk0.position.vz + cross + crossDiagonal;
            zResults[2] = func_800A8B34(&probe, direction);
            if (zResults[2] < scratch->unk40) {
                zResults[2] = 0xFF;
            }
            direction += cornerStep;
            probe.vx = actor->unk0.position.vx;
            probe.vz = actor->unk0.position.vz + crossOffset + sideOffset;
            zResults[3] = func_800A8B34(&probe, direction);
            if (zResults[3] < scratch->unk40) {
                zResults[3] = 0xFF;
            }
            D_800F4B08 = probe;
            if (zResults[1] < 2 && zResults[2] < 2) {
                if (zResults[3] >= 2) {
                    return 3;
                }
                probe.vx = actor->unk0.position.vx + crossOffset;
                probe.vz = actor->unk0.position.vz + cross + sideOffset;
                zResults[0] = func_800A8B34(&probe, direction);
                if (zResults[0] >= 2) {
                    return 3;
                }
                direction += crossDiagonalOffset;
                offset = 0;
            slideXMove:
                motion->vx = crossOffset;
                motion->vz = cross;
                goto moved;
            }
            if (zResults[3] >= 2) {
                return 3;
            }
            crossOffset = 0;
            offset = 2;
            goto slideXMove;
        }
        if (zResults[1] >= 2) {
            return 3;
        }
    slideXBack:
        direction -= 2;
        sideOffset = -offset;
        crossDiagonal = diagonalOffset;
        cross = -crossOffset;
        crossDiagonalOffset = -1;
        cornerStep = 3;
        goto slideXProbe;
    }

    offset = zProbe.vy - actor->unk0.position.vy;
    diagonalOffset = offset / 64;
    if (offset & 0x3F) {
        diagonalOffset--;
    }
    diagonalOffset = -diagonalOffset;
    if (diagonalOffset <= 0) {
        diagonalOffset = 1;
    }
    if (zResults[0] != 0xFF && zResults[1] <= diagonalOffset
        && zResults[2] <= diagonalOffset && zResults[3] <= diagonalOffset
        && zResults[4] <= diagonalOffset) {
        if (actor->unk5AC_14) {
            if (z < 0) {
                if (actor->unk17FE == 4) {
                    goto slideZ;
                }
            } else if (actor->unk17FE == 0) {
                goto slideZ;
            }
        }
        motion->vx = 0;
        *result = zResults[0];
        D_800F4B08 = zProbe;
        D_800F49F0 = probeTiles[1];
        D_800F49F9 = probeDirections[1];
        return 2;
    }
    if (xResults[0] != 0xFF && xResults[1] < 2 && xResults[2] < 2 && xResults[3] < 2
        && xResults[4] < 2) {
        if (actor->unk5AC_14) {
            if (motion->vx < 0) {
                facing = actor->unk17FE;
                expected = 6;
            } else {
                facing = actor->unk17FE;
                expected = 2;
            }
            if (facing == expected) {
                goto slideZ;
            }
        }
    acceptX:
        motion->vz = 0;
        *result = xResults[0];
        D_800F4B08 = xProbe;
        D_800F49F0 = probeTiles[0];
        D_800F49F9 = probeDirections[0];
        return 1;
    }
slideZ:
    if (actor->unk0.unkA_0) {
        return 3;
    }
    direction = 4;
    if (motion->vz < 0) {
        offset = -radius;
        direction = 0;
        diagonalOffset = -diagonal;
    } else {
        offset = radius;
        diagonalOffset = diagonal;
    }
    direction -= 1;
    probe.vz = actor->unk0.position.vz + motion->vz + offset;
    probe.vx = actor->unk0.position.vx - offset;
    zResults[0] = func_800A8B34(&probe, direction);
    direction += 2;
    opposite.vz = probe.vz;
    opposite.vx = actor->unk0.position.vx + offset;
    zResults[1] = func_800A8B34(&opposite, direction);
    if (zResults[0] == 0xFF && zResults[1] == 0xFF) {
        return 3;
    }
    crossOffset = motion->vz / 2;
    if (zResults[0] < 2) {
        if (zResults[1] < 2) {
            direction -= 2;
            probe.vz = actor->unk0.position.vz + motion->vz;
            probe.vx = actor->unk0.position.vx - offset;
            zResults[2] = func_800A8B34(&probe, direction);
            direction += 2;
            opposite.vz = probe.vz;
            opposite.vx = actor->unk0.position.vx + offset;
            zResults[3] = func_800A8B34(&opposite, direction);
            if (zResults[2] == 0xFF && zResults[3] == 0xFF) {
                return 3;
            }
            if (zResults[2] > 0) {
                goto slideZBack;
            }
            if (zResults[3] <= 0 && (zResults[0] != 0 || zResults[1] != 1)) {
                if (zResults[0] == 1 && zResults[1] == 1) {
                    goto slideZBack;
                }
                if (probe.vy <= opposite.vy) {
                    goto slideZBack;
                }
            }
        }
        sideOffset = -offset;
        crossDiagonal = diagonalOffset;
        cross = -crossOffset;
        crossDiagonalOffset = 1;
        cornerStep = -3;
    slideZProbe:
        direction -= crossDiagonalOffset;
        probe.vz = actor->unk0.position.vz + crossOffset + offset;
        probe.vx = actor->unk0.position.vx + cross;
        zResults[1] = func_800A8B34(&probe, direction);
        if (zResults[1] < scratch->unk40) {
            zResults[1] = 0xFF;
        }
        direction += crossDiagonalOffset;
        probe.vz = actor->unk0.position.vz + crossOffset + diagonalOffset;
        probe.vx = actor->unk0.position.vx + cross + crossDiagonal;
        zResults[2] = func_800A8B34(&probe, direction);
        if (zResults[2] < scratch->unk40) {
            zResults[2] = 0xFF;
        }
        direction += cornerStep;
        probe.vz = actor->unk0.position.vz;
        probe.vx = actor->unk0.position.vx + cross + sideOffset;
        zResults[3] = func_800A8B34(&probe, direction);
        if (zResults[3] < scratch->unk40) {
            zResults[3] = 0xFF;
        }
        D_800F4B08 = probe;
        if (zResults[1] < 2 && zResults[2] < 2) {
            if (zResults[3] >= 2) {
                return 3;
            }
            probe.vx = actor->unk0.position.vx + cross + sideOffset;
            probe.vz = actor->unk0.position.vz + crossOffset;
            zResults[0] = func_800A8B34(&probe, direction);
            if (zResults[0] >= 2) {
                return 3;
            }
            direction += crossDiagonalOffset;
            offset = 0;
        slideZMove:
            motion->vz = crossOffset;
            motion->vx = cross;
        moved:
            *result = zResults[3];
            actor->unk17FE = direction & 7;
            actor->unk5AC_13 = 1;
            return offset;
        }
        if (zResults[3] >= 2) {
            return 3;
        }
        crossOffset = 0;
        offset = 1;
        goto slideZMove;
    }
    if (zResults[1] < 2) {
    slideZBack:
        direction -= 2;
        crossDiagonal = -diagonalOffset;
        cross = crossOffset;
        crossDiagonalOffset = -1;
        sideOffset = offset;
        cornerStep = 3;
        goto slideZProbe;
    }
    return 3;
}

int func_800A8B34(SVECTOR* arg0, int arg1)
{
    u_int* ent;
    int h;
    int elev2;
    int gx;
    int gz;
    int r;
    int los;
    int diff;
    int q;
    D_1F8003BC_t* sb = (D_1F8003BC_t*)0x1F8003BC;
    D_800F45E0_t* actor = sb->unk18;
    int limit = sb->unk1C[arg1 & 7];

    if (actor->unk5AC_9 << 9) {
        return 0;
    }

    gx = arg0->vx / 128;
    gz = arg0->vz / 128;
    elev2 = func_8008DD0C(arg0->vx, arg0->vz);
    elev2 <<= 17;
    elev2 >>= 17;

    if (limit + sb->unk0 < elev2) {
        return 0xFF;
    }

    ent = func_800A8D64(arg0, 0);

    if (ent == NULL) {
        return 0xFF;
    }

    h = func_8008DC7C(arg0->vx, arg0->vz);

    if (h < 0) {
        return 0xFF;
    }

    h <<= 17;
    h >>= 17;

    r = func_800A92B8(gx, gz);

    if (r != 0) {
        h = r;
    }

    if ((*ent >> 17) & 1) {
        if (h >= 0) {
            h = 0xBB8;
        }
    }

    if (h - actor->unk1E < -0x17F) {
        return 0xFF;
    }

    los = func_800A9378(arg0->vx, limit, arg0->vz, 0);

    if (los == 0) {
        arg0->pad = 0;
    } else {
        arg0->pad = D_800F49F4;
        h = los;
    }

    arg0->pad |= D_800F49F8 << 8;

    if (sb->unk0 < elev2 - h) {
        return 0xFF;
    }

    if (h < sb->unk40 + limit) {
        return 0xFF;
    }

    if (func_800A8E84(actor, arg0) == 0) {
        return 0xFF;
    }

    arg0->vy = h;
    diff = h - limit;
    q = diff / 64;

    if (q >= 0) {
        return 0;
    }

    if (diff & 0x3F) {
        --q;
    }

    return -q;
}
