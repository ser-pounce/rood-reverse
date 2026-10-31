#include "common.h"
#include "3A1A0.h"
#include "146C.h"
#include "30DB0.h"
#include "38C1C.h"
#include "40564.h"
#include "44F14.h"
#include "6E4CC.h"
#include "battleUnk.h"
#include "entity.h"
#include "src/SLUS_010.40/main.h"

typedef struct {
    short unk0;
    short unk2;
    short unk4;
} func_800A3054_t;

typedef struct {
    char unk0[6];
    short unk6;
} func_800A6660_t;

typedef struct {
    int words[2];
} func_800A6798_t;

void func_800B64A8(int, int, int);
D_800F4538_t* func_800A3C34(int, int, int, int);
int func_800A3BC4(int, int);
int func_800A3DB4(int, int, int);
int func_800A91DC(int, int, int);
int func_800A92B8(int, int);
int func_800A9378(int, int, int, int);
void func_800AA850(int, short, int);
void func_800ACF54(D_800F4538_t*);
void func_800A70DC(D_800F4538_t*, int);
int func_800A76BC(D_800F4538_t*, SVECTOR*, int*, int);
void func_800A2FBC(D_800F4538_t*);
inline int func_800A3310(int, SVECTOR*);
void func_800A3394(int, SVECTOR*);
int func_800A46A4(D_800F4538_t*);
void func_800A4A88(D_800F4538_t*, int);
int func_800A51A0(int, SVECTOR*);
void func_800A525C(D_800F4538_t*);
int func_800A5280(int, int, int, SVECTOR*);
inline SVECTOR* func_800A4A24(int);
void func_800A9EB4(int, short, int);
void func_800AA454(int, vs_battle_movementPosition*, int);
void func_800AA620(int, SVECTOR*, int);
void func_800AC690(int, D_800F4538_t*);
void* func_800AD494(void*, int, u_short**);
void func_800E4BD8(int);
void func_800E4BE0(int);
void func_800E68A0(D_800F45E0_t*);
int func_800E75EC(void);

extern u_char D_800E8FD0[];
extern int D_800E90A8;
extern u_char D_800E90CC[];
extern u_char D_800E90D0[];
extern int D_800F49E8;
extern _mpdRoomSection3* D_800F49F0;
extern int D_800F49F4;
extern u_char D_800F49F8;
extern u_char D_800F49F9;
extern SVECTOR D_800F4B08;
extern char D_800F4B18;
extern u_char D_800E9278[];

static inline int vs_battleRelativeSampleHeight(
    D_1F8003BC_t* samples, int sector, int offset, int y)
{
    return samples->unk1C[(sector + offset) & 7] - y;
}

void func_800A29A0(D_800F4538_t* arg0)
{
    int busy;

    switch (arg0->unk0.unkB_0) {
    case 1:
        arg0->unk0.unkA_5 = 0;
        func_800A0204(arg0->unk0.unkF, 0x13, 0, 8);
        func_800A01C8(arg0->unk0.unkF, 0x14, 8, 0);
        arg0->unk0.unk54.cd = 0;
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
            func_800A9C54(arg0->unk0.unkF, (vs_battle_movementPosition*)&arg0->unk5EC, 0);
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
        func_800E4C28(arg0->unk0.currentTile.x, arg0->unk0.currentTile.z);
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
    func_800A9C54(arg0->unk0.unkF, (vs_battle_movementPosition*)&arg0->unk5EC, 0);
    arg0->unk6E0 = 0;
    arg0->unk0.unkB_0 = 4;
    func_800A29A0(arg0);
    if (arg0->unk17FD >= 2) {
        func_800A2C48(D_800F4538[arg0->unk17FD]);
    }
}

void func_800A2CD4(D_800F4538_t* arg0)
{
    switch (arg0->unk0.unkB_4) {
    case 1:
        func_800A0204(arg0->unk0.unkF, 9, 0, 8);
        func_800A9C54(arg0->unk0.unkF, (vs_battle_movementPosition*)&arg0->unk5EC, -1);
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

        if (D_800F49F4 != 0) {
            arg0->unk0.unkA_5 = 1;
            goto idle;
        }

        if (arg0->unk5CA == 0) {
            func_800A0204(arg0->unk0.unkF, 10, 0, 8);
            arg0->unk0.unkA_5 = 0;
            arg0->unk0.unkB_4 = 3;
        }

        return;

    case 3:
        if (arg0->unk0.unk1A == 0 && arg0->unkC54.unk548_17) {
        land:
            arg0->unk0.unkA_5 = 0;
            func_800ACF54(arg0);
            func_800E4C28(arg0->unk0.currentTile.x, arg0->unk0.currentTile.z);
            func_800A0204(arg0->unk0.unkF, 1, 0, 8);
            arg0->unk0.unkB_4 = 0;
        }

        return;

    case 4:
        func_800A0204(arg0->unk0.unkF, 7, 0, 8);
        func_800A01C8(arg0->unk0.unkF, 37, 8, 0);
        func_800AA620(arg0->unk0.unkF, &arg0->unk5EC, -1);
        func_800A9EB4(arg0->unk0.unkF, arg0->unk5EC.pad, 8);
        arg0->unk5CA = arg0->unk0.unk1A;
        arg0->unk0.unk1A = 0;
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

        if (D_800F49F4 != 0 || arg0->unk5CA == 0) {
        idle:
            func_800A0204(arg0->unk0.unkF, 1, 0, 8);
            arg0->unk0.unkB_4 = 0;
        }

        return;

    case 6:
        if (arg0->animationId != 199 && arg0->animationId != 201 && arg0->unk5CC == 0) {
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
    D_800F4538_t* actor = D_800F4538[actorId];
    short z;
    int value;

    memcpy(&actor->unk0.currentTile, placement, sizeof(actor->unk0.currentTile));
    actor->unk0.position.vx = placement->unk0_0 * 128 + 64;
    z = placement->unk0_16 * 128 + 64;
    actor->unk0.position.vz = z;
    actor->unk0.position.vy = func_800A3500(actor->unk0.position.vx, z);

    if (mode == 16 || mode == 32) {
        int ceiling = func_800E75EC();
        SVECTOR* position;

        if (ceiling == 0) {
            value = -384;
        } else {
            value = ceiling - actor->unk0.position.vy;

            if (value > -128) {
                value = -128;
            }
        }

        position = &actor->unk0.position;
        actor->unk0.position.vy += value;

        if (func_800A3310(actorId, position) != 0) {
            func_800A3394(actorId, position);
        }

        actor->unk0.unkA_5 = 1;
        func_800A0204(actorId, 8, 0, 0);
    } else {
        u_char tileType;

        if (mode == 64 || mode == 128) {
            actor->unk0.unkA_6 = 1;
        }

        tileType = placement->unk0_8;

        if (tileType == 7) {
            actor->unk0.currentTile.y = 0;
            actor->unk0.position.vy = height;
            actor->unk0.unk34.vy = 0;
            actor->unk0.unkA_0 = 3;
        } else {
            if (tileType >= 2) {
                int* anchor = (int*)func_800A4A24(placement->unk0_8);
                *(int*)&actor->unk0.position.vx = anchor[0];
                *(int*)&actor->unk0.position.vz = anchor[1];
                *(int*)&actor->unk17EC.vx = anchor[0];
                *(int*)&actor->unk17EC.vz = anchor[1];
                actor->unk17EC.pad = placement->unk0_8;
                actor->unk0.unkC_0 = placement->unk0_8;
                actor->unk0.unkC_4 = placement->unk0_8;
            }

            func_800A0204(actorId, 1, 0, 0);
        }
    }

    func_800ACF54(actor);
    actor->unk0.unk1A = 0;
    value = placement->unk0_24;
    actor->unk0.unk3E = 0;
    actor->unk0.unk18 = 0;
    actor->unk18D2 = 0;
    actor->unk18D4 = 0;
    actor->unk18D6 = 0;
    actor->unk18D8 = 0;
    value *= 16;
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
        if (actor != NULL && actor->unk0.position.vx == arg0
            && actor->unk0.position.vz == arg1 && actor->unk0.position.vy - 0x80 < h) {
            h = actor->unk0.position.vy - 0x80;
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

        if (actor != NULL && !actor->unk0.unkA_5 && actor->unk0.currentTile.y < 2
            && !actor->unk0.unkA_0) {
            x = actor->unk0.position.vx;
            z = actor->unk0.position.vz;
            h = func_8008DA24(x, z);
            h <<= 17;
            h >>= 17;

            for (j = 0; j < 16; ++j) {
                obj = D_800F45E0[j];
                if (obj != NULL && obj->unk0.position.vx == x
                    && obj->unk0.position.vz == z && obj->unk0.position.vy - 0x80 < h) {
                    h = obj->unk0.position.vy - 0x80;
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
            arg2->unk0.unk0.value = *(int*)&temp_a0->unk0.currentTile;
        }
        arg2->unk0.unk0.fields.status = temp_a0->unk0.facing / 16;
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
    oldX = farX = x = actor->unk0.currentTile.x;
    oldZ = farZ = z = actor->unk0.currentTile.z;
    found = direction < 2 ? -1 : 1;

    if (direction & 1) {
        x += found;
        farX = oldX + found * 2;
    } else {
        z += found;
        farZ = oldZ + found * 2;
    }

    if (x < 0 || z < 0) {
        return -1;
    }

    if (actor->unk5AC_3) {
        x = x * 128 + 64;
        objectId = actor->unk0.unk13;
        object = D_800F45E0[objectId];
        z = z * 128 + 64;

        if (object->unk0.unk1A != 0) {
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
    }

    found = func_800A91DC(x, z, 0);

    if (found == 0) {
        return -1;
    }

    object = D_800F45E0[found];
    objectId = found;

    if (object->unk16C.unk0_4 == 1) {
        return -1;
    }

    if (object->unk0.unk1A != 0) {
        return -1;
    }

    x = x * 128 + 64;
    z = z * 128 + 64;
    farX = farX * 128 + 64;
    farZ = farZ * 128 + 64;

    if (object->unk0.position.vy < actor->unk0.position.vy - 128) {
        return -1;
    }

    if (actor->unk0.position.vy + 64 < object->unk0.position.vy) {
        return -1;
    }

    if (object->unk16C.actorId < 4) {
        if (!func_800A3DB4(farX, farZ, object->unk0.position.vy)) {
            return -1;
        }
    } else {
        direction = actor->unk0.position.vy - 384;

        if (direction < func_800A3BC4(actor->unk0.position.vx, actor->unk0.position.vz)) {
            return -1;
        }

        if (direction < func_800A3BC4(x, z)) {
            return -1;
        }
    }

    if (func_800A3C00(object, 1) == 0) {
        return objectId;
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
    return func_800A3C34(
        arg0->unk0.currentTile.x, arg0->unk0.currentTile.z, arg0->unk0.position.vy, arg1);
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
        if ((i == 0) && actor->unk5AC_28) {
            D_800F45E0_t* temp_v1 = D_800F45E0[actor->unk5AC_28];
            if ((arg0 == temp_v1->unk0.currentTile.x)
                && (arg1 == temp_v1->unk0.currentTile.z)) {
                return actor;
            }
            continue;
        }
        if ((actor->unk0.unkA_3 != 2) && (actor->unk0.currentTile.x == (u_int)arg0)
            && (actor->unk0.currentTile.z == (u_int)arg1) && !actor->unk0.unkA_5
            && (actor->unk0.position.vy >= arg2)) {
            return actor;
        }
    }
    return NULL;
}

int func_800A3DB4(int x, int z, int minimumHeight)
{
    SVECTOR origin;
    int height;

    *(int*)&origin.vx = 0;
    *(int*)&origin.vz = 0;
    height = func_800A6EE8(&origin, x, z, 1);

    if (height < minimumHeight) {
        return 0;
    }

    if (D_800F49F0->unk0_20 & 1) {
        return 0;
    }

    return func_800A3C34(x / 128, z / 128, height, 1) == NULL;
}

int func_800A3E6C(int actorId)
{
    SVECTOR position;
    vs_battle_movementPosition tile;
    D_800F4538_t* actor = D_800F4538[actorId];
    D_800F45E0_t* object;
    int objectId;
    int height;
    int step;
    int dx;
    int dz;

    if (actor->unk5AC_20) {
        return -1;
    }

    objectId = func_800A38E0(actorId);

    if (objectId == -1) {
        return -1;
    }

    object = D_800F45E0[objectId];
    object->unk0.unk34.pad = D_800F49E8;
    D_800E90A8 = objectId;
    height = actor->unk0.position.vy - object->unk0.position.vy;
    height /= 64;
    ++height;
    object->unk0.unk34.vx = 0;
    object->unk0.unk34.vz = 0;

    switch (object->unk16C.actorId) {
    case 0:
    case 1:
        object->unk16C.unk2 = D_800E8FD0[object->unk16C.unk2 * 4 + D_800F49E8];
        // fallthrough
    case 2:
        step = D_800F49E8 < 2 ? -128 : 128;

        if (D_800F49E8 & 1) {
            object->unk0.unk34.vx = step;
        } else {
            object->unk0.unk34.vz = step;
        }

        goto move;

    case 3:
        object->unk0.unk34.vx = 0;
        object->unk0.unk34.vz = 0;
        step = D_800F49E8 < 2 ? -32 : 32;

        if (D_800F49E8 & 1) {
            object->unk0.unk34.vx = step;
        } else {
            object->unk0.unk34.vz = step;
        }

    move:
        object->unk0.unk34.vy = 0;
        func_800AE6C0(actor, 44, 45);
        func_800A0204(actorId, height + 79, 0, 4);
        actor->unk5AC_20 = 1;
        func_800E4C1C((object->unk0.position.vx + object->unk0.unk34.vx) / 128,
            (object->unk0.position.vz + object->unk0.unk34.vz) / 128);
        break;

    case 4:
    case 5:
    case 6:
        if (actor->unk5AC_3) {
            func_800A0204(actorId, 76, 0, 4);
            func_800AE6C0(actor, 46, 47);
            actor->unk5AC_20 = 1;
        } else {
            func_800A0204(actorId, height + 71, 0, 4);
            func_800AE6C0(actor, 44, 45);
            actor->unk5AC_20 = 1;
        }

        dx = 0;
        dz = 0;
        step = D_800F49E8 < 2 ? -1 : 1;

        if (D_800F49E8 & 1) {
            dx = step;
        } else {
            dz = step;
        }

        func_800E4C1C(actor->unk0.currentTile.x + dx, actor->unk0.currentTile.z + dz);
        break;
    }

    memcpy(&tile, &actor->unk0.currentTile, sizeof tile);
    step = D_800F49E8 < 2 ? -1 : 1;

    if (D_800F49E8 & 1) {
        tile.x += step;
    } else {
        tile.z += step;
    }

    func_800AA454(actorId, &tile, 4);
    position.vx = actor->unk0.currentTile.x * 128 + 64;
    position.vz = actor->unk0.currentTile.z * 128 + 64;
    position.vy = actor->unk0.position.vy;
    func_800AA620(actorId, &position, 4);
}

void func_800A41D0(D_800F4538_t* actor, int mode)
{
    D_800F45E0_t* object = D_800F45E0[D_800E90A8];
    int direction;
    int step;
    int facing;

    if (mode == 2) {
        switch (object->unk16C.actorId) {
        case 0:
        case 1:
            object->unk0.unk1A = 0xF9;
            break;

        case 2:
            object->unk0.unk1A = 0xFF;
            break;

        case 3:
            object->unk0.unk1A = 0xFE;
            break;
        }

        object->unk16C.unk4 = 0;
        func_800E68A0(object);
        return;
    }

    if (mode == 1) {
        SVECTOR points[2];
        int x = actor->unk0.currentTile.x;
        int z = actor->unk0.currentTile.z;
        step = D_800F49E8 < 2 ? -1 : 1;

        if (D_800F49E8 & 1) {
            x += step;
        } else {
            z += step;
        }

        step = D_800F49E8;
        object->unk0.currentTile.x = x;
        object->unk0.currentTile.z = z;
        object->unk0.position.vx = x * 128 + 64;
        object->unk0.position.vz = z * 128 + 64;
        object->unk0.facing = (object->unk0.facing + step * (ONE / 4)) & 0xFFF;
        func_800A190C(object->unk0.unk12, 0xF0, &points[0], 1);
        func_800A190C(object->unk0.unk12, 0xF1, &points[1], 1);
        object->unk0.position.vy = (points[0].vy + points[1].vy) / 2 + 60;
        object->unk0.unk1A = 0xFC;
        object->unk0.unk34.vy = 24;
        object->unk0.unk12 = 0xFF;
        actor->unk5AC_3 = 0;
        return;
    }

    if (object == NULL || object->unk0.unk9_0) {
        func_800A0204(actor->unk0.unkF, 1, 0, 8);
        return;
    }

    func_800E4C28(object->unk0.currentTile.x, object->unk0.currentTile.z);
    func_800E68A0(object);

    if (object->unk16C.unk0_4 == 2) {
        func_800E68A0(object);
    }

    step = D_800F49E8 < 2 ? 128 : -128;

    if (D_800F49E8 & 1) {
        object->unk0.unk34.vx += step;
    } else {
        object->unk0.unk34.vz += step;
    }

    facing = (object->unk0.facing + (4 - D_800F49E8) * (ONE / 4)) & 0xFFF;
    direction = facing + ONE / 8;
    direction &= 0xFFF;
    object->unk0.facing = facing;
    direction /= ONE / 4;
    object->unk0.facing = direction * (ONE / 4);
    object->unk0.currentTile.x = -1;
    object->unk0.unk1A = 8;
    object->unk0.unk12 = actor->unk0.unkF;
    actor->unk0.unk13 = D_800E90A8;
    actor->unk5AC_3 = 1;
}

int func_800A4494(int contact, SVECTOR* point)
{
    int i;

    for (i = 0; i < 17; ++i) {
        D_800F4538_t* actor = D_800F4538[i];

        if (actor == NULL || actor->unk0.skip) {
            continue;
        }

        if (actor->unk0.unkC_0 == contact) {
            int dx;
            int dz;
            int hit;

            if (actor->unk0.unkA_3 != 2) {
                continue;
            }

            dx = point->vx - actor->unk17EC.vx;
            dz = point->vz - actor->unk17EC.vz;
            actor->unk0.position.vx += dx;
            actor->unk0.position.vz += dz;
            hit = func_800A46A4(actor);
            actor->unk0.position.vx -= dx;
            actor->unk0.position.vz -= dz;

            if (!hit) {
                continue;
            }

        transition:
            setVector(&actor->unk0.unk34, 0, 3, 0);
            actor->unk6EE = 0;
            actor->unk6EF = 0;
            actor->unk0.unkA_0 = 3;
            actor->unk0.unkA_3 = 0;
            actor->unk0.unk9_6 = 0;
            actor->unk0.unkC_0 = 0;
            func_800A4A88(actor, 2);
            return 1;
        } else {
            int radius = actor->unk63C;

            if (point->vx + 64 < actor->unk0.position.vx - radius
                || point->vx - 64 > actor->unk0.position.vx + radius) {
                continue;
            }

            if (point->vz + 64 < actor->unk0.position.vz - radius
                || point->vz - 64 > actor->unk0.position.vz + radius) {
                continue;
            }

            if (point->vy < actor->unk0.position.vy - 288
                || point->vy >= actor->unk0.position.vy) {
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
    D_1F8003BC_t* scratch = (D_1F8003BC_t*)0x1F8003BC;
    int saved = actor->unk0.unkC_0;
    int radius = actor->unk63C;
    int direction;

    actor->unk0.unkC_0 = 0;
    actor->unk0.unkA_3 = 0;
    actor->unk0.unk9_6 = 0;
    func_800A70DC(actor, rsin(ONE / 8) * radius / ONE);
    actor->unk0.unkC_0 = saved;
    actor->unk0.unkA_3 = 2;
    direction = actor->unk1800 >> 9;
    scratch->blocked[direction] = 0;
    scratch->blocked[direction + 1] = 0;
    --direction;
    direction &= 7;
    scratch->blocked[direction] = 0;

    for (direction = 0; direction < 8; ++direction) {
        if (scratch->blocked[direction]) {
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
        if ((D_800F45E0[i] != NULL) && !D_800F45E0[i]->unk0.skip && !temp_v1->unk0.unk9_0
            && temp_v1->unk0.unk1A) {
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
        actor->unk5B0_2 = 0;
        actor->unk5B0_0 = 0;
        func_800A0204(index, 0x2F, 0, 4);
        actor->unk0.unk11 = 6;
        actor->unk0.unkA_0 = 2;
    } else {
        actor->unk5B0_2 = 0;
        actor->unk5B0_0 = 1;

        if (distance / ONE >= actor->unk5B9) {
            actor->unk5B0_0 = 2;
            actor->unk5B0_2 = 1;
        }

        actor->unk0.unk11 = 0;
        actor->unk0.unkA_0 = 1;
    }

    actor->unk1848.unk0 = 7;
    actor->unk1848.unk4 = direction;
    actor->unk1848.unk8 = distance;
}

inline SVECTOR* func_800A4A24(int arg0)
{
    SVECTOR sp10[4];
    int temp_v0;
    int i;
    arg0 -= 2;

    temp_v0 = func_8008D2C0(sp10);

    for (i = 0; i < temp_v0; ++i) {
        if (sp10[i].pad == arg0) {
            // BUG: returns stack variable
            return &sp10[i];
        }
    }
    return NULL;
}

void func_800A4A88(D_800F4538_t* actor, int mode)
{
    SVECTOR* contact;
    int contactId;
    int current;
    int previous;

    switch (mode) {
    case 0:
        if (actor->unk0.unkC_0 == 0) {
            return;
        }

        contact = func_800A4A24(actor->unk0.unkC_0);
        actor->unk6EE = contact->vx - actor->unk17EC.vx;
        actor->unk6EF = contact->vz - actor->unk17EC.vz;
        actor->unk0.position.vx += actor->unk6EE;
        actor->unk0.position.vz += actor->unk6EF;
        actor->unk0.position.vy += contact->vy - actor->unk17EC.vy;
        break;

    case 1:
        if (actor->unk0.unkA_0 == 2 || actor->unk0.unkA_0 == 3) {
            return;
        }

        if (actor->unk0.unkC_4 != (contactId = actor->unk0.unkC_0)) {
            if (actor->unk0.unkF == 0 && contactId != 0
                && contactId != actor->unk17EC.pad) {
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
                actor->unk17EC.pad = current;
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
            && actor->unk0.unkC_0 != actor->unk17EC.pad) {
            func_800E4BD8(actor->unk17EC.pad);
            actor->unk17EC.pad = 0;
        }

        actor->unk0.currentTile.y = actor->unk0.unkC_0;
        actor->unk0.unkC_4 = actor->unk0.unkC_0;
        return;
    }

    setVector(&actor->unk17EC, contact->vx, contact->vy, contact->vz);
}

void func_800A4D8C(void)
{
    int i;

    for (i = 0; i < 16; ++i) {
        if ((D_800F45E0[i] != NULL) && (D_800F45E0[i]->unk0.nBones != 0)) {
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

void func_800A4E68(int actorId)
{
    SVECTOR movement;
    D_800F4538_t* actor = D_800F4538[actorId];

    if (actor->unk0.unk9_0 != 0 && actor->unk0.unk9_0 < 6) {
        return;
    }

    if (actorId == 0) {
        func_800A4A88(actor, 0);

        if (actor->unk0.unkA_0 && actor->unk181A != 0) {
            func_800AC690(0, actor);
        } else {
            switch (actor->unk1848.unk0) {
            case 7:
            case 0:
                movement.pad = 0;
                goto move;

            case 1:
                movement.pad = 1;
                movement.vx = actor->unk1848.unk6;
            move:
                func_800A5280(0, actor->unk1848.unk4, actor->unk1848.unk8, &movement);

                if (actor->unk0.unkA_0) {
                    func_800AC690(0, actor);
                }

                break;

            case 2:
                func_800A25EC(actor);
                break;
            }
        }

        func_800A4A88(actor, 1);
        func_800A4A88(actor, 2);
    } else {
        func_800A4A88(actor, 0);

        if (actor->unk1848.unk0 == 2) {
            func_800A25EC(actor);
        } else if (actor->unk0.unkA_0) {
            func_800AC690(actorId, actor);
        } else if (actor->unk0.unkB_0) {
            func_800A29A0(actor);
        } else if (actor->unk0.unkB_4) {
            func_800A2CD4(actor);
        } else {
            switch (actor->unk1848.unk0) {
            case 1:
                if (actor->unk0.unkB_7) {
                    break;
                }

                if (actor->unk0.unkA_5) {
                    break;
                }

                movement.pad = 1;
                movement.vx = actor->unk1848.unk6;
                func_800A5280(
                    actorId, actor->unk1848.unk4, actor->unk1848.unk8, &movement);

                if (actor->unk0.unkA_0) {
                    func_800AC690(actorId, actor);
                }

                break;

            case 3:
                func_800A2790(actor);
                break;

            case 4:
                func_800A291C(actor);
                break;
            }
        }

        if (actor->unk6E4 != 0) {
            if (actor->unk0.unkC_0 == actor->unk6E4) {
                actor->unk0.unkC_0 = 0;
            }

            if (func_800A51A0(actor->unk6E4, &actor->unk0.position) == 0) {
                actor->unk6E4 = 0;
                func_800E6B24(actor->unk0.unkF);
            }

            if (actor->unk181A == 1) {
                actor->unk1814 = actor->unk0.position.vx;
                actor->unk1818 = actor->unk0.position.vz;
            }
        }

        func_800A4A88(actor, 1);
        func_800A4A88(actor, 2);
        actor->unk0.currentTile.x = actor->unk0.position.vx / 128;
        actor->unk0.currentTile.z = actor->unk0.position.vz / 128;
    }

    func_800A525C(actor);
}

int func_800A51A0(int arg0, SVECTOR* arg1)
{
    SVECTOR sp10[4];
    SVECTOR* p;
    int n;
    int i;

    arg0 -= 2;
    n = func_8008D2C0(sp10);
    for (i = 0; i < n; i++) {
        if (sp10[i].pad == arg0) {
            p = &sp10[i];
            goto found;
        }
    }
    p = NULL;
found:
    if (p->vx + 0x40 < arg1->vx) {
        return 0;
    }
    if (arg1->vx < p->vx - 0x40) {
        return 0;
    }
    if (p->vz + 0x40 < arg1->vz) {
        return 0;
    }
    return !(arg1->vz < p->vz - 0x40);
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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A5280);

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
    func_800A6798_t saved;
    int height;
    int valid = 0;

    if (actor->unk6EC <= D_800F4B08.vy) {
        return 0;
    }

    offset->vx = 0;
    offset->vz = 0;
    offset->vy += 236;
    saved = *(func_800A6798_t*)&actor->unk0.position;
    addVector(&actor->unk0.position, offset);
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

        if (height > -64) {
            height = func_800A6EE8(&D_800F4B08, -offset->vx, -offset->vz, 1);
            height -= D_800F4B08.vy;
        }

        if (height > -64) {
            valid = 1;
        }
    }

    actor->unk0.unkA_3 = 0;
    actor->unk0.unk9_6 = 0;
    offset->vx = 0;
    offset->vz = 0;
    *(func_800A6798_t*)&actor->unk0.position = saved;
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

int func_800A6AA0(D_800F4538_t* actor, int speed)
{
    int next;
    int frames;
    int quadrant;
    int animation = actor->animationId;

    if (animation >= 100) {
        animation -= 100;
    }

    quadrant = 0;

    if (actor->unk1848.unk0 == 1) {
        quadrant = actor->unk1848.unk6 - actor->unk1848.unk4 + ONE / 8;
        quadrant &= 0xFFF;
        quadrant /= ONE / 4;
    }

    if (actor->unk5AC_3) {
        next = 84;

        if (speed > 0) {
            frames = 4;
        } else {
            next = 75;
            frames = 10;
        }

        if (animation == 95) {
            return;
        }

        func_800A0204(actor->unk0.unkF, next, 0, frames);
        return;
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

        func_800A0204(actor->unk0.unkF, next, 0, frames);
        return;
    }

    if (actor->unk5AC_15) {
        u_short* entry;

        if (animation >= 25 && animation <= 26) {
            return;
        }

        next = 26;

        if (animation < 18 || animation > 19) {
            if (animation == 20 || animation == 17) {
                next = 25;
            } else {
                actor->unk5AC_15 = 0;
                return;
            }
        }

        func_800AD494(actor, next, &entry);

        if (entry == NULL) {
            next = 6;
        }

        func_800A0204(actor->unk0.unkF, next, 0, 8);
    } else if (speed >= actor->unk5B9 - 1) {
        if (animation >= 19 && animation <= 20) {
            return;
        }

        if ((animation >= 15 && animation <= 18) || (animation >= 46 && animation <= 56)
            || (animation >= 9 && animation <= 12) || animation == 1 || animation == 6) {
            u_int state = actor->unk5AC_25;
            actor->unk5AC_25 ^= 1;
            func_800A0204(actor->unk0.unkF, state + 19, 0, 6);
            return;
        }

        next = 19;

        if (animation == 13 || animation == 15) {
            next = 20;
        }

        func_800A01C8(actor->unk0.unkF, next, 4, 0);
        return;
    } else if (speed > 0) {
        int step;

        if ((animation < 46 || animation > 56) && (animation < 9 || animation > 12)) {
            if (animation >= 13 && animation <= 14) {
                if (quadrant != 2) {
                    return;
                }
            } else if (animation >= 15 && animation <= 16) {
                if (quadrant == 2) {
                    return;
                }
            } else if (animation != 1 && animation != 6 && animation != 17
                       && animation != 18) {
                goto walk_start;
            }
        }

        step = actor->unk5AC_25;
        next = step + 13;
        actor->unk5AC_25 ^= 1;

        if (quadrant == 2) {
            next = step + 15;
        }

        func_800A0204(actor->unk0.unkF, next, 0, 6);
        return;

    walk_start:
        next = 13;

        if (animation == 19 || animation == 15 || animation == 13) {
            ++next;
        }

        if (quadrant == 2) {
            next += 2;
        }

        func_800A01C8(actor->unk0.unkF, next, 4, 0);
        return;
    } else {
        if (animation >= 13 && animation <= 16) {
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
    _mpdRoomSection3* ent;
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

            if (ent->unk0_17 && (h >= 0)) {

                h = 3000;

                if (arg3 == 3) {

                    los = D_800E9278[ent->unk0_0];

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

void func_800A70DC(D_800F4538_t* actor, int diagonal)
{
    D_1F8003BC_t* samples = (D_1F8003BC_t*)0x1F8003BC;
    int i;
    int j;
    int delta;

    actor->unk5AC_12 = 0;

    for (i = 0; i < 8; ++i) {
        samples->blocked[i] = 0;
    }

    if (actor->unk5AC_9 || actor->unk5AC_10) {
        for (i = 0; i < 8; ++i) {
            samples->unk1C[i] = 0;
        }

        return;
    }

    if (actor->unk0.unkA_3 == 2) {
        for (i = 0; i < 8; ++i) {
            samples->unk1C[i] = actor->unk0.position.vy;
        }

        return;
    }

    i = actor->unk63C;
    samples->centerAttribute = func_800A8D64(&actor->unk0.position, 0)->unk0_5;
    samples->unk1C[0] = func_800A6EE8(&actor->unk0.position, 0, -i, 0);
    samples->attributes[0] = D_800F49F0->unk0_5;
    samples->unk1C[6] = func_800A6EE8(&actor->unk0.position, i, 0, 0);
    samples->attributes[6] = D_800F49F0->unk0_5;
    samples->unk1C[2] = func_800A6EE8(&actor->unk0.position, -i, 0, 0);
    samples->attributes[2] = D_800F49F0->unk0_5;
    samples->unk1C[7] = func_800A6EE8(&actor->unk0.position, diagonal, -diagonal, 0);
    samples->attributes[7] = D_800F49F0->unk0_5;
    samples->unk1C[1] = func_800A6EE8(&actor->unk0.position, -diagonal, -diagonal, 0);
    samples->attributes[1] = D_800F49F0->unk0_5;
    samples->unk1C[3] = func_800A6EE8(&actor->unk0.position, -diagonal, diagonal, 0);
    samples->attributes[3] = D_800F49F0->unk0_5;
    samples->unk1C[5] = func_800A6EE8(&actor->unk0.position, diagonal, diagonal, 0);
    samples->attributes[5] = D_800F49F0->unk0_5;
    samples->unk1C[4] = func_800A6EE8(&actor->unk0.position, 0, i, 0);
    samples->attributes[4] = D_800F49F0->unk0_5;

    if (actor->unk0.unkA_0 == 3 && actor->unk0.unk34.vy > 0) {
        j = actor->unk0.position.vy - 32;
    } else if (actor->unk1848.unk8 == 0) {
        j = actor->unk0.position.vy - 64;
    } else {
        j = actor->unk0.position.vy - 96;
    }

    for (i = 0; i < 8; ++i) {
        if (samples->unk1C[i] > actor->unk0.position.vy) {
            samples->unk1C[i] = actor->unk0.position.vy;
        }

        if ((!samples->attributes[i] || !samples->centerAttribute)
            && j >= samples->unk1C[i]) {
            samples->blocked[i] = 1;
            actor->unk5AC_12 = 1;
        }
    }

    if (!actor->unk0.unkA_0) {
        return;
    }

    i = actor->unk1848.unk4 + ONE / 16;
    i /= ONE / 8;

    for (j = 0; j < 3; ++j) {
        delta = vs_battleRelativeSampleHeight(samples, i, j - 1, actor->unk0.position.vy);

        if (delta < -255) {
            return;
        }

        if (delta >= -192) {
            return;
        }
    }

    for (j = 0; j < 5; ++j) {
        delta = vs_battleRelativeSampleHeight(samples, i, j + 2, actor->unk0.position.vy);

        if (delta < -192) {
            return;
        }
    }

    samples->unk1C[i] = actor->unk0.position.vy;
    actor->unk5AC_12 = 0;
}

void func_800A7524(D_800F4538_t* actor, SVECTOR* motion)
{
    D_1F8003BC_t* scratch;
    int x;
    int z;

    if (!actor->unk5AC_12) {
        return;
    }

    scratch = (D_1F8003BC_t*)0x1F8003BC;
    x = 0;
    z = (scratch->blocked[0] != 0) * 16;

    if (scratch->blocked[1]) {
        x = 8;
        z += 8;
    }

    if (scratch->blocked[2]) {
        x += 16;
    }

    if (scratch->blocked[3]) {
        x += 8;
        z -= 8;
    }

    if (scratch->blocked[4]) {
        z -= 16;
    }

    if (scratch->blocked[5]) {
        x -= 8;
        z -= 8;
    }

    if (scratch->blocked[6]) {
        x -= 16;
    }

    if (scratch->blocked[7]) {
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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A76BC);

int func_800A8B34(SVECTOR* arg0, int arg1)
{
    _mpdRoomSection3* ent;
    int h;
    int elev2;
    int gx;
    int gz;
    int r;
    int los;
    int diff;
    int q;
    D_1F8003BC_t* sb = (D_1F8003BC_t*)0x1F8003BC;
    D_800F4538_t* actor = sb->unk18;
    int limit = sb->unk1C[arg1 & 7];

    if (actor->unk5AC_9 || actor->unk5AC_10) {
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

    if (ent->unk0_17) {
        if (h >= 0) {
            h = 0xBB8;
        }
    }

    if (h - actor->unk0.position.vy < -0x17F) {
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
