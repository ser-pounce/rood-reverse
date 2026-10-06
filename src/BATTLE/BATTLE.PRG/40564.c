#include "common.h"
#include "40564.h"
#include "146C.h"
#include "3A1A0.h"
#include "src/SLUS_010.40/main.h"
#include "src/SLUS_010.40/32154.h"
#include <abs.h>

typedef struct {
    u_char unk0;
    u_char unk1;
} func_800AAE9C_t;

typedef struct {
    int unk0;
    u_char* unk4;
    u_short unk8[0];
} func_800AD494_t;

typedef struct {
    short x;
    short y;
    short z;
    short id;
} func_8008D2C0_t;

void func_8007A824(DR_MOVE*);
int func_8008D2C0(func_8008D2C0_t*);
void func_800A0204(int, int, int, int);
void func_800A1280(int, int, SVECTOR*, int);
void func_800A1720(int, int, void*, int*);
int func_800A6EE8(SVECTOR*, int, int, int);
void func_800A70DC(void*, int);
void func_800AA698(int arg0, SVECTOR* arg1, int arg2);
void func_800AA984(int, short, int);
void func_800AAA88(int arg0, SVECTOR* arg1, int arg2);
void func_800AA290(int, func_8006EBF8_t_fields*, int, int);
void func_800AA490(int, func_8006EBF8_t_fields*, int, int);
void func_800AB098(D_800F4538_t*, int, int);

extern u_char D_800E8F2C;
extern func_800AAE9C_t D_800E909C[][28];
extern func_800AAE9C_t D_800E916C[][8];
extern u_char D_800F2450[];
extern void* D_800F4768;
extern char D_800F49DC;
extern u_char D_800F49E4;
extern int D_800F49F4;
extern u_char D_800F49F8;
extern u_char D_800F49F9;
extern short D_800F4B00;

_mpdRoomSection3* func_800A8D64(SVECTOR* arg0, int arg1)
{
    int temp_s1 = arg0->vx / 128;
    int temp_s0 = arg0->vz / 128;
    _mpdRoomSection3* temp_v0 = func_8008B764(temp_s1, temp_s0, arg1);

    if (temp_v0 == NULL) {
        return NULL;
    }

    temp_s1 = arg0->vx - (temp_s1 << 7);
    temp_s0 = arg0->vz - (temp_s0 << 7);

    // BUG: potentially unhandled values
    switch (temp_v0->unk0_10) {
    case 0:
        return temp_v0;

    case 1:
        if ((temp_s1 + temp_s0) > 0x80) {
            return NULL;
        }
        return temp_v0;

    case 2:
        if ((temp_s1 - temp_s0) > 0) {
            return NULL;
        }
        return temp_v0;

    case 3:
        if ((temp_s1 + temp_s0) < 0x80) {
            return NULL;
        }
        return temp_v0;

    case 4:
        if ((temp_s1 - temp_s0) < 0) {
            return NULL;
        }
        return temp_v0;

    case 5:
        return NULL;
    }
}

int func_800A8E84(D_800F4538_t* arg0, SVECTOR* arg1);
typedef struct {
    char prefix[4];
    u_char excluded;
} actorCollisionExclusion;

int func_800A8E84(D_800F4538_t* actor, SVECTOR* position)
{
    actorCollisionExclusion* scratch = (void*)0x1F8003BC;
    int i, radius, flags;
    D_800F4538_t* other;
    if (actor->unk0.unkF == 0) {
        if (*(u_int*)((char*)actor + 0x5AC) & 0x800)
            return 1;
        if (*(u_int*)((char*)actor + 0x5AC) & 0x1000)
            return 1;
        for (i = 2; i < 17; ++i) {
            other = D_800F4538[i];
            if (other == NULL || other == actor)
                continue;
            flags = *(u_int*)((char*)other + 8);
            if (flags & 1)
                continue;
            if (*(u_int*)((char*)other + 0x5AC) & 0x1000000)
                continue;
            if (other->unk0.unk13 == 0xFC)
                continue;
            if ((flags & 0xF000000) == 0x2000000)
                continue;
            if (((actorCollisionExclusion*)((char*)scratch + i))->excluded)
                continue;
            radius = *(u_short*)&other->unk640[0];
            if (other->unk0.position.vx + radius < position->vx)
                continue;
            if (position->vx < other->unk0.position.vx - radius)
                continue;
            if (other->unk0.position.vz + radius < position->vz)
                continue;
            if (position->vz < other->unk0.position.vz - radius)
                continue;
            if (other->unk0.position.vy
                < actor->unk0.position.vy - *(u_short*)&actor->unk640[2])
                continue;
            if (actor->unk0.position.vy
                < other->unk0.position.vy - *(u_short*)&other->unk640[2])
                continue;
            return 0;
        }
    }
    return 1;
}

int func_800A8FD4(D_800F4538_t* actor, SVECTOR* motion)
{
    actorCollisionExclusion* scratch = (void*)0x1F8003BC;
    int i, flags, radius, minY, minX, maxX, minZ, maxZ;
    int otherRadius, dx, dz, oldDistance, otherFlags;
    short otherX, otherZ, actorX, actorZ;
    actorCollisionExclusion* clear;
    D_800F4538_t* other;
    D_800F4538_t** entry;
    for (i = 16, clear = (void*)((char*)scratch + 16); i >= 0;
        --i, clear = (void*)((char*)clear - 1))
        clear->excluded = 0;
    flags = *(u_int*)((char*)actor + 0x5AC);
    if (flags & 0x800)
        return flags & 0x800;
    radius = *(u_short*)&actor->unk640[0];
    minY = actor->unk0.position.vy - *(u_short*)&actor->unk640[2];
    minX = actor->unk0.position.vx - radius;
    maxX = actor->unk0.position.vx + radius;
    minZ = actor->unk0.position.vz - radius;
    maxZ = actor->unk0.position.vz + radius;
    i = 2;
    if (flags & 8)
        minY -= 128;
    for (entry = &D_800F4538[i]; i < 17; ++entry) {
        other = *entry;
        if (other == NULL)
            goto next_actor;
        otherFlags = *(u_int*)((char*)other + 8);
        if (otherFlags & 1)
            goto next_actor;
        if (*(u_int*)((char*)other + 0x5AC) & 0x1000000)
            goto next_actor;
        if (other->unk0.unk13 == 0xFC)
            goto next_actor;
        if ((otherFlags & 0xF000000) == 0x2000000)
            goto next_actor;
        otherRadius = *(u_short*)&other->unk640[0];
        if (other->unk0.position.vx + otherRadius < minX)
            goto next_actor;
        if (maxX < other->unk0.position.vx - otherRadius)
            goto next_actor;
        if (other->unk0.position.vz + otherRadius < minZ)
            goto next_actor;
        if (maxZ < other->unk0.position.vz - otherRadius)
            goto next_actor;
        if (other->unk0.position.vy < minY)
            goto next_actor;
        if (actor->unk0.position.vy
            < other->unk0.position.vy - *(u_short*)&other->unk640[2])
            goto next_actor;
        ((actorCollisionExclusion*)((char*)scratch + i))->excluded = 1;
        otherX = other->unk0.position.vx;
        actorX = actor->unk0.position.vx;
        dx = otherX - actorX;
        dx *= dx;
        otherZ = other->unk0.position.vz;
        actorZ = actor->unk0.position.vz;
        dz = otherZ - actorZ;
        dz *= dz;
        oldDistance = dx + dz;
        dx = otherX - (actorX + motion->vx);
        dx *= dx;
        dz = otherZ - (actorZ + motion->vz);
        dz *= dz;
        dx += dz;
        oldDistance = dx < oldDistance;
        ++i;
        if (oldDistance)
            return 0;
        goto increment_entry;
    next_actor:
        ++i;
    increment_entry:;
    }
    return 1;
}

int func_800A91DC(int arg0, int arg1, int arg2)
{
    int _[2] __attribute__((unused));
    int i;

    int var_t2 = ONE;
    int var_t3 = 0;

    for (i = 0; i < 16; ++i) {
        D_800F45E0_t* temp_v1 = D_800F45E0[i];
        if ((temp_v1 != NULL) && !(temp_v1->unk8_0)
            && ((arg2 == 0) || (temp_v1->unk1A == 0)) && (temp_v1->unk12 == 0xFF)
            && (temp_v1->unk6C[8].unk3 == temp_v1->unk12) && (temp_v1->unk5C == arg0)
            && (temp_v1->unk5E == arg1) && (var_t2 >= temp_v1->unk1E)) {
            var_t2 = temp_v1->unk1E;
            var_t3 = i;
        }
    }

    if (var_t3 == 0) {
        return 0;
    }

    return var_t3;
}

int func_800A92B8(int arg0, int arg1)
{
    int var_t0;
    int i;

    var_t0 = 0xBB8;
    D_800F49F8 = 0;

    for (i = 0; i < 16; ++i) {

        D_800F45E0_t* temp_v1 = D_800F45E0[i];

        if (temp_v1 == NULL) {
            continue;
        }

        if (!temp_v1->unk8_0 && (temp_v1->unk5C == arg0) && (temp_v1->unk5E == arg1)
            && !temp_v1->unk9_0 && (temp_v1->unk1A != 0xFE)
            && (temp_v1->unk1E < var_t0)) {

            var_t0 = temp_v1->unk1E;
            D_800F49F8 = i;
        }
    }

    var_t0 -= 128;

    if (var_t0 > 0) {
        var_t0 = 0;
    }

    return var_t0;
}

int func_800A9378(int x, int y, int z, int mode)
{
    func_8008D2C0_t platforms[4];
    int count;
    int i;

    D_800F49F4 = 0;
    count = func_8008D2C0(platforms);
    if (count == 0) {
        return 0;
    }

    for (i = 0; i < count; ++i) {
        if (x < platforms[i].x + 64 && x >= platforms[i].x - 64 && z < platforms[i].z + 64
            && z >= platforms[i].z - 64) {
            switch (mode) {
            case 0:
                if (platforms[i].y < y - 256) {
                    continue;
                }
                break;
            case 1:
                if (platforms[i].y < y - 256) {
                    return platforms[i].y + 96;
                }
                continue;
            case 2:
                if (platforms[i].y >= y || platforms[i].y < y - 128) {
                    continue;
                }
                break;
            case 3:
                if (platforms[i].y < y && platforms[i].y >= y - D_800F4B00) {
                    return platforms[i].y + 96;
                }
                continue;
            }
            D_800F49F4 = platforms[i].id + 2;
            return platforms[i].y;
        }
    }
    return 0;
}

// Inlined copy of 3A1A0 func_800A4A24.
// BUG: returns the address of a stack variable
static inline func_8008D2C0_t* func_800A4A24(int id)
{
    func_8008D2C0_t platforms[4];
    int count;
    int i;
    id -= 2;

    count = func_8008D2C0(platforms);

    for (i = 0; i < count; ++i) {
        if (platforms[i].id == id) {
            return &platforms[i];
        }
    }
    return NULL;
}

int func_800A9530(D_800F4538_t* actor, SVECTOR* offset)
{
    func_8008D2C0_t* platform;
    int position;
    int edge;
    int surface;
    int distance;
    u_int direction;
    u_int flags;
    int result;

    position = actor->unk63C;
    direction = D_800F49F9 >> 1;
    actor->unk1800 = direction << 10;

    if (actor->unk0.unkC_0) {
        platform = func_800A4A24(actor->unk0.unkC_0);
        edge = 65;
        if ((int)direction < 2) {
            position = -position;
        } else {
            edge = -65;
        }
        if (direction & 1) {
            position += actor->unk0.position.vx;
            edge += platform->x;
            offset->vx = edge - position;
        } else {
            position += actor->unk0.position.vz;
            edge += platform->z;
            offset->vz = edge - position;
        }
    } else {
        edge = 0;
        if ((int)direction < 2) {
            position = -position;
        } else {
            edge = 127;
        }
        if (direction & 1) {
            position += actor->unk0.position.vx;
            offset->vx = edge - (position & 127);
        } else {
            position += actor->unk0.position.vz;
            offset->vz = edge - (position & 127);
        }
        if (offset->vx > 32) {
            offset->vx -= 64;
        }
        if (offset->vx < -32) {
            offset->vx += 64;
        }
        if (offset->vz > 32) {
            offset->vz -= 64;
        }
        if (offset->vz < -32) {
            offset->vz += 64;
        }
        if (*(u_int*)((char*)actor + 0x5AC) & 0xF0000000) {
            offset->vy += 12;
        }
        offset->vy += 8;
    }
    surface = actor->unk0.unkC_0;
    actor->unk0.unkC_0 = 0;
    actor->unk0.position.vx += offset->vx;
    actor->unk0.position.vz += offset->vz;
    distance = rsin(0x200);
    distance *= actor->unk63C;
    distance /= 4096;
    func_800A70DC(actor, distance);
    actor->unk0.position.vx -= offset->vx;
    actor->unk0.position.vz -= offset->vz;
    actor->unk0.unkC_0 = surface;
    flags = *(u_int*)((char*)actor + 0x5AC);
    if (!(flags & 0x1000)) {
        result = 1;
    } else {
        *(u_int*)((char*)actor + 0x5AC) = flags & ~0x1000;
        result = 0;
    }
    return result;
}

void func_800A97EC(int arg0, func_8006EBF8_t_fields* arg1, int arg2, int arg3)
{
    int angle;

    D_800F4538_t* actor = D_800F4538[arg0];

    if (arg2 == 0 && arg3 == 0) {

        func_800AA290(arg0, arg1, -1, 0);

        angle = arg1->unk0_24;
        angle <<= 4;
        angle %= ONE;
        angle -= actor->unk0.facing;

        func_800AA984(arg0, (short)angle, 0);

        actor->unk5AC_0 = 0;
        actor->unk0.currentTileX = arg1->unk0_0;
        actor->unk0.unk5D = arg1->unk0_8;
        actor->unk0.currentTileZ = arg1->unk0_16;
    } else {
        if (arg3 == -1) {
            actor->unk5C6 = actor->unk5C0;
        } else {
            actor->unk5C6 = arg3;
        }

        if (arg2 == -1) {
            actor->unk5C4 = actor->unk5C2;
        } else {
            actor->unk5C4 = arg2;
        }

        func_800AA490(arg0, arg1, -1, actor->unk5C6);

        actor->unk5EC.vx = (arg1->unk0_0 * 128) + 64;
        actor->unk5EC.vz = (arg1->unk0_16 * 128) + 64;
        actor->unk5EC.vy = func_800A6EE8(&actor->unk5EC, 0, 0, 1);
        angle = 0x8000;

        if (arg1->unk0_24 == 0xFF) {
            actor->unk5EC.pad = angle;
        } else {
            actor->unk5EC.pad = arg1->unk0_24 * 16;
        }

        actor->unk5AC_0 = 1;
        actor->unk5AC_2 = 0;
    }
}

short func_8008DA24(int, int);

static inline int scanFloor(int arg0, int arg1)
{
    int var_t0;
    int i;

    var_t0 = 0xBB8;
    D_800F49F8 = 0;

    for (i = 0; i < 16; ++i) {

        D_800F45E0_t* temp_v1 = D_800F45E0[i];

        if (temp_v1 == NULL) {
            continue;
        }

        if (!temp_v1->unk8_0 && (temp_v1->unk5C == arg0) && (temp_v1->unk5E == arg1)
            && !temp_v1->unk9_0 && (temp_v1->unk1A != 0xFE)
            && (temp_v1->unk1E < var_t0)) {

            var_t0 = temp_v1->unk1E;
            D_800F49F8 = i;
        }
    }

    var_t0 -= 128;

    if (var_t0 > 0) {
        var_t0 = 0;
    }

    return var_t0;
}

void func_800A9988(int arg0, SVECTOR* arg1, int arg2, int arg3)
{
    int angle;
    D_800F4538_t* temp_s0;
    D_800F45E0_t** var_t0;
    D_800F45E0_t* temp_a2_2;
    short temp_a2_3;
    short temp_v0;
    int var_a0;
    int var_v1;
    int temp_v1_2;
    int temp_v1_3;
    int var_a0_2;
    u_short temp_a2;
    u_short temp_v1;
    int var_a3;

    temp_s0 = D_800F4538[arg0];
    if ((arg2 == 0) && (arg3 == 0)) {
        temp_a2 = arg1->pad;
        if (temp_a2 == 0x8000) {
            angle = arg1->vx - temp_s0->unk0.position.vx;
            var_a0_2 = arg1->vz - temp_s0->unk0.position.vz;
            if ((angle == 0) && (var_a0_2 == 0)) {
                angle = (short)temp_a2;
            } else {
                angle = 0xC00 - ratan2(var_a0_2, angle);
                angle &= 0xFFF;
            }
            angle = (short)angle;
            temp_s0->unk0.facing = angle;
        } else {
            temp_s0->unk0.facing = (short)temp_a2;
        }
        temp_s0->unk0.unk18 = 0;
        func_800A9D90(arg0, arg1, 0);
        return;
    }
    angle = arg1->vx - temp_s0->unk0.position.vx;
    var_a0_2 = arg1->vz - temp_s0->unk0.position.vz;
    if ((angle == 0) && (var_a0_2 == 0)) {
        temp_v1 = (u_short)arg1->pad;
        if (temp_v1 != 0x8000) {
            angle = (short)temp_v1;
            goto block_15;
        }
    } else {
        angle = 0xC00 - ratan2(var_a0_2, angle);
        angle &= 0xFFF;
    block_15:
        angle = (short)angle;
        func_800A9EB4(arg0, angle, arg3);
        if (arg2 == -1) {
            temp_s0->unk5C4 = temp_s0->unk5C2;
        } else {
            temp_s0->unk5C4 = arg2;
        }
        if (arg3 == -1) {
            temp_s0->unk5C6 = temp_s0->unk5C0;
        } else {
            temp_s0->unk5C6 = (u_short)arg3;
        }
        temp_s0->unk5EC.vx = (short)(u_short)arg1->vx;
        temp_s0->unk5EC.vz = (short)(u_short)arg1->vz;
        angle = (u_short)arg1->vy;
        if (angle == 0x8000) {
            angle = func_8008DA24(arg1->vx, arg1->vz);
            angle <<= 17;
            angle >>= 17;
            var_a0_2 = scanFloor(arg1->vx / 128, arg1->vx / 128);
            if (var_a0_2 != 0) {
                angle = var_a0_2;
            }
            temp_s0->unk5EC.vy = (short)angle;
        } else {
            temp_s0->unk5EC.vy = (short)angle;
        }
        temp_s0->unk5EC.pad = (short)(u_short)arg1->pad;
        temp_s0->unk5AC_0 = 1;
        temp_s0->unk5AC_2 = 0;
    }
}

void func_800A9C54(int arg0, func_8006EBF8_t_fields* arg1, int arg2)
{
    D_800F4538_t* temp_s0 = D_800F4538[arg0];

    if (arg2 == -1) {
        func_800AA290(arg0, arg1, -1, temp_s0->unk5C2);
    } else {
        func_800AA290(arg0, arg1, -1, arg2);
    }

    temp_s0->unk0.currentTileX = arg1->unk0_0;
    temp_s0->unk0.unk5D = arg1->unk0_8;
    temp_s0->unk0.currentTileZ = arg1->unk0_16;
}

void func_800A9CDC(int arg0, func_8006EBF8_t_fields* arg1, int arg2)
{
    D_800F4538_t* new_var = D_800F4538[arg0];

    if (arg2 == -1) {
        func_800AA490(arg0, arg1, -1, new_var->unk5C0);
    } else {
        func_800AA490(arg0, arg1, -1, arg2);
    }
}

void func_800A9D24(int arg0, SVECTOR* arg1, int arg2)
{
    u_short temp_s0;
    D_800F4538_t* temp_s1 = D_800F4538[arg0];

    if (arg2 == -1) {
        func_800AA698(arg0, arg1, -1);
        return;
    }

    temp_s0 = temp_s1->unk5C2;
    temp_s1->unk5C2 = arg2;

    func_800AA698(arg0, arg1, -1);

    temp_s1->unk5C2 = temp_s0;
}

void func_800A9D90(int arg0, SVECTOR* arg1, int arg2)
{
    SVECTOR sp10;
    u_short temp_s0;
    D_800F4538_t* temp_s1 = D_800F4538[arg0];

    sp10.vx = arg1->vx - temp_s1->unk0.position.vx;
    sp10.vy = arg1->vy - temp_s1->unk0.position.vy;
    sp10.vz = arg1->vz - temp_s1->unk0.position.vz;

    if (arg2 == -1) {
        func_800AA698(arg0, &sp10, -1);
        return;
    }

    temp_s0 = temp_s1->unk5C2;
    temp_s1->unk5C2 = arg2;

    func_800AA698(arg0, &sp10, -1);

    temp_s1->unk5C2 = temp_s0;
}

void func_800A9E38(int arg0, short arg1, int arg2)
{
    u_short temp_s0;
    D_800F4538_t* temp_s1 = D_800F4538[arg0];

    if (arg2 == -1) {
        func_800AA984(arg0, arg1, -1);
        return;
    }

    temp_s0 = temp_s1->unk5C0;
    temp_s1->unk5C0 = arg2;

    func_800AA984(arg0, arg1, -1);

    temp_s1->unk5C0 = temp_s0;
}

void func_800A9EB4(int arg0, short arg1, int arg2)
{
    u_short temp_s0;
    D_800F4538_t* temp_s1 = D_800F4538[arg0];

    arg1 -= temp_s1->unk0.facing;

    if (arg1 > ONE / 2) {
        arg1 -= ONE;
    }

    if (arg1 < -ONE / 2) {
        arg1 += ONE;
    }

    if (arg2 == -1) {
        func_800AA984(arg0, arg1, -1);
        return;
    }

    temp_s0 = temp_s1->unk5C0;
    temp_s1->unk5C0 = arg2;

    func_800AA984(arg0, arg1, -1);

    temp_s1->unk5C0 = temp_s0;
}

void func_800A9F64(int arg0, SVECTOR* arg1, int arg2)
{
    u_short temp_s0;

    D_800F4538_t* temp_s1 = D_800F4538[arg0];

    if (arg2 == -1) {
        func_800AAA88(arg0, arg1, -1);
        return;
    }

    temp_s0 = temp_s1->unk5C0;
    temp_s1->unk5C0 = arg2;

    func_800AAA88(arg0, arg1, -1);

    temp_s1->unk5C0 = temp_s0;
}

void func_800A9FD0(int arg0, SVECTOR* arg1, int arg2)
{
    SVECTOR sp10;
    int temp_s0;
    D_800F4538_t* temp_s1 = D_800F4538[arg0];

    sp10.vx = arg1->vx - temp_s1->unk0.unk24;

    if (sp10.vx > ONE / 2) {
        sp10.vx -= ONE;
    }

    if (sp10.vx < -ONE / 2) {
        sp10.vx += ONE;
    }

    sp10.vy = arg1->vy - temp_s1->unk0.facing;

    if (sp10.vy > ONE / 2) {
        sp10.vy -= ONE;
    }

    if (sp10.vy < -ONE / 2) {
        sp10.vy += ONE;
    }

    sp10.vz = arg1->vz - temp_s1->unk0.unk28;

    if (sp10.vz > ONE / 2) {
        sp10.vz -= ONE;
    }

    if (sp10.vz < -ONE / 2) {
        sp10.vz += ONE;
    }

    if (arg2 == -1) {
        func_800AAA88(arg0, &sp10, -1);
        return;
    }

    temp_s0 = temp_s1->unk5C0;
    temp_s1->unk5C0 = arg2;

    func_800AAA88(arg0, &sp10, -1);

    temp_s1->unk5C0 = temp_s0;
}

void func_800AA108(int arg0, func_8006EBF8_t_fields* arg1, int arg2, int arg3)
{
    D_800F4538_t* temp_s0 = D_800F4538[arg0];

    if (temp_s0 != NULL) {

        temp_s0->unk5C4 = arg2;

        if ((arg2 == 0) && (arg3 == 0)) {
            int temp_a1;

            func_800AA290(arg0, arg1, -1, 0);

            temp_a1 = arg1->unk0_24;
            temp_a1 *= 0x10;
            temp_a1 %= 0x1000;
            temp_a1 -= temp_s0->unk0.facing;

            func_800AA984(arg0, temp_a1, 0);
            temp_s0->unk5AC_0 = 0;
        } else {
            func_800AA490(arg0, arg1, arg3, temp_s0->unk5C0);
            temp_s0->unk5AC_0 = 1;
        }

        temp_s0->unk0.currentTileX = arg1->unk0_0;
        temp_s0->unk0.unk5D = arg1->unk0_8;
        temp_s0->unk0.currentTileZ = arg1->unk0_16;
        temp_s0->unk5AC_2 = 1;
    }
}

void func_800AA218(int arg0, func_8006EBF8_t_fields* arg1, int arg2)
{
    D_800F4538_t* temp_s0 = D_800F4538[arg0];

    if (temp_s0 != NULL) {
        func_800AA290(arg0, arg1, arg2, temp_s0->unk5C2);
        temp_s0->unk0.currentTileX = arg1->unk0_0;
        temp_s0->unk0.unk5D = arg1->unk0_8;
        temp_s0->unk0.currentTileZ = arg1->unk0_16;
    }
}

void func_800AA290(int arg0, func_8006EBF8_t_fields* arg1, int arg2, int arg3)
{
    SVECTOR target;
    int dist;
    int temp;
    D_800F4538_t* actor = D_800F4538[arg0];

    if (actor == NULL) {
        return;
    }

    target.vx = arg1->unk0_0 * 128 + 64;
    target.vz = arg1->unk0_16 * 128 + 64;
    actor->unk0.unk34.vx = target.vx - actor->unk0.position.vx;
    actor->unk0.unk34.vz = target.vz - actor->unk0.position.vz;
    actor->unk0.unk34.vy = func_800A6EE8(&target, 0, 0, 4) - actor->unk0.position.vy;

    if ((actor->unk0.unk34.vx == 0) && (actor->unk0.unk34.vz == 0)
        && (actor->unk0.unk34.vy == 0)) {
        return;
    }

    if (arg2 == 0) {
        actor->unk0.unk1A = 0;
    move:
        addVector(&actor->unk0.position, &actor->unk0.unk34);
        return;
    }

    if (arg2 == -1) {
        temp = actor->unk0.unk34.vx;
        temp *= temp;
        if (temp < 0) {
            temp = -temp;
        }
        dist = temp;
        temp = actor->unk0.unk34.vz;
        temp *= temp;
        if (temp < 0) {
            temp = -temp;
        }
        dist += temp;
        temp = actor->unk0.unk34.vy;
        temp *= temp;
        if (temp < 0) {
            temp = -temp;
        }
        dist = vs_gte_rsqrt(dist + temp) * arg3;
        temp = dist / 128;
        actor->unk0.unk1A = temp;
        if (dist & 0x7F) {
            actor->unk0.unk1A = temp + 1;
        }
        if (actor->unk0.unk1A == 0) {
            goto move;
        }
        return;
    }

    actor->unk0.unk1A = arg2;
}

void func_800AA454(int arg0, func_8006EBF8_t_fields* arg1, int arg2)
{
    func_800AA490(arg0, arg1, arg2, D_800F4538[arg0]->unk5C0);
}

void func_800AA490(int arg0, func_8006EBF8_t_fields* arg1, int arg2, int arg3)
{
    int angle;
    int dz;
    D_800F4538_t* actor = D_800F4538[arg0];

    if (actor == NULL) {
        return;
    }

    angle = arg1->unk0_0 - actor->unk0.currentTileX;
    dz = arg1->unk0_16 - actor->unk0.currentTileZ;

    if (angle == 0 && dz == 0) {
        angle = arg1->unk0_24 * 16;
    } else {
        angle = 0xC00 - ratan2(dz, angle);
        angle %= ONE;
    }

    angle -= actor->unk0.facing;

    if (angle >= ONE / 2) {
        angle -= ONE;
    }

    if (angle < -ONE / 2) {
        angle += ONE;
    }

    actor->unk0.unk3E = angle;
    actor->unk0.unk3C = 0;
    actor->unk0.unk40 = 0;

    if (angle == 0) {
        return;
    }

    if (arg2 == 0) {
        actor->unk0.unk18 = 0;
    turn:
        actor->unk0.facing = (actor->unk0.facing + actor->unk0.unk3E) & 0xFFF;
        return;
    }

    if (arg2 == -1) {
        if (angle < 0) {
            angle = -angle;
        }
        angle *= arg3;
        actor->unk0.unk18 = angle / ONE;
        if (angle & 0xFFF) {
            actor->unk0.unk18 = angle / ONE + 1;
        }
        if (actor->unk0.unk18 == 0) {
            goto turn;
        }
        return;
    }

    actor->unk0.unk18 = arg2;
}

void func_800AA600(int arg0, SVECTOR* arg1, int arg2) { func_800AA698(arg0, arg1, arg2); }

void func_800AA620(int arg0, SVECTOR* arg1, int arg2)
{
    SVECTOR sp10;
    D_800F4538_t* temp_a3 = D_800F4538[arg0];

    if (temp_a3 != NULL) {
        sp10.vx = arg1->vx - temp_a3->unk0.position.vx;
        sp10.vy = arg1->vy - temp_a3->unk0.position.vy;
        sp10.vz = arg1->vz - temp_a3->unk0.position.vz;

        func_800AA698(arg0, &sp10, arg2);
    }
}

void func_800AA698(int arg0, SVECTOR* arg1, int arg2)
{
    int dist;
    int temp;
    D_800F4538_t* actor = D_800F4538[arg0];

    if (actor == NULL) {
        return;
    }

    actor->unk0.unk34.vx = arg1->vx;
    actor->unk0.unk34.vy = arg1->vy;
    actor->unk0.unk34.vz = arg1->vz;

    if (arg2 == 0) {
        actor->unk0.unk1A = 0;
    move:
        actor->unk0.position.vx += arg1->vx;
        actor->unk0.position.vy += arg1->vy;
        actor->unk0.position.vz += arg1->vz;
        actor->unk0.currentTileX = actor->unk0.position.vx / 128;
        actor->unk0.currentTileZ = actor->unk0.position.vz / 128;
        return;
    }

    if (arg2 == -1) {
        temp = actor->unk0.unk34.vx;
        temp *= temp;
        if (temp < 0) {
            temp = -temp;
        }
        dist = temp;
        temp = actor->unk0.unk34.vz;
        temp *= temp;
        if (temp < 0) {
            temp = -temp;
        }
        dist += temp;
        temp = actor->unk0.unk34.vy;
        temp *= temp;
        if (temp < 0) {
            temp = -temp;
        }
        dist = vs_gte_rsqrt(dist + temp) * actor->unk5C2;
        actor->unk0.unk1A = dist / 128;
        if (dist & 0x7F) {
            actor->unk0.unk1A = dist / 128 + 1;
        }
        if (actor->unk0.unk1A == 0) {
            goto move;
        }
        return;
    }

    actor->unk0.unk1A = arg2;
}

void func_800AA82C(int arg0, short arg1, int arg2) { func_800AA984(arg0, arg1, arg2); }

void func_800AA850(int arg0, u_short arg1, int arg2)
{
    short temp_a1;
    short var_v1;
    D_800F4538_t* temp_v0 = D_800F4538[arg0];

    if (temp_v0 == NULL) {
        return;
    }

    temp_a1 = arg1 - temp_v0->unk0.facing;
    var_v1 = temp_a1;

    if (temp_a1 > ONE / 2) {
        var_v1 = temp_a1 - ONE;
    }

    if (var_v1 < -ONE / 2) {
        var_v1 += ONE;
    }

    func_800AA984(arg0, var_v1, arg2);
}

void func_800AA8D0(int arg0, short arg1, int arg2)
{
    int arg2_2;
    int var_v0;
    D_800F4538_t* temp_v0 = D_800F4538[arg0];

    if (temp_v0 == NULL) {
        return;
    }

    arg1 -= temp_v0->unk0.facing;

    if (arg1 > ONE / 2) {
        arg1 -= ONE;
    }

    if (arg1 < -ONE / 2) {
        arg1 += ONE;
    }

    var_v0 = arg1;

    var_v0 = ABS(var_v0);
    arg2 = ABS(arg2);

    arg2_2 = var_v0 / arg2;

    if ((var_v0 % arg2) != 0) {
        ++arg2_2;
    }

    func_800AA984(arg0, arg1, arg2_2);
}

void func_800AA984(int arg0, short arg1, int arg2)
{
    int m;
    D_800F4538_t* a = D_800F4538[arg0];

    if (a == NULL) {
        return;
    }

    m = arg1;
    a->unk0.unk3E = m;
    a->unk0.unk3C = 0;
    a->unk0.unk40 = 0;

    if (arg2 == 0) {
        short sum;
        a->unk0.unk18 = 0;
    recenter:
        sum = (u_short)a->unk0.facing + a->unk0.unk3E;
        a->unk0.facing = sum;
        a->unk0.facing = sum % ONE;
    } else if (arg2 == -1) {
        int speed;

        if (m < 0) {
            m = -m;
        }

        speed = m * a->unk5C0;
        a->unk0.unk18 = speed / ONE;

        if (speed & 0xFFF) {
            a->unk0.unk18 = (speed / ONE) + 1;
        }

        if (a->unk0.unk18 != 0) {
            return;
        }

        goto recenter;

    } else {
        a->unk0.unk18 = arg2;
    }
}

void func_800AAA68(int arg0, SVECTOR* arg1, int arg2) { func_800AAA88(arg0, arg1, arg2); }

void func_800AAA88(int arg0, SVECTOR* arg1, int arg2)
{
    D_800F4538_t* a = D_800F4538[arg0];
    int m;

    a->unk0.unk3C = arg1->vx;
    a->unk0.unk3E = arg1->vy;
    a->unk0.unk40 = arg1->vz;

    if (arg2 == 0) {
        a->unk0.unk18 = 0;
    recenter:
        a->unk0.unk24 += a->unk0.unk3C;
        a->unk0.facing += a->unk0.unk3E;
        a->unk0.unk28 += a->unk0.unk40;
        a->unk0.unk24 &= 0xFFF;
        a->unk0.facing &= 0xFFF;
        a->unk0.unk28 &= 0xFFF;
    } else if (arg2 == -1) {
        m = ABS(a->unk0.unk3C);

        if (m < ABS(a->unk0.unk3E)) {
            m = ABS(a->unk0.unk3E);
        }

        if (m < ABS(a->unk0.unk40)) {
            m = ABS(a->unk0.unk40);
        }

        m *= a->unk5C0;
        a->unk0.unk18 = m / ONE;

        if (m & 0xFFF) {
            a->unk0.unk18 = (m / ONE) + 1;
        }

        if (a->unk0.unk18 != 0) {
            return;
        }

        goto recenter;

    } else {
        a->unk0.unk18 = arg2;
    }
}

void func_800AABD0(int arg0, SVECTOR* arg1, int arg2)
{
    D_800F4538_t* temp_a3 = D_800F4538[arg0];

    if (temp_a3 != NULL) {

        if (arg2 == 0) {
            temp_a3->unk5C8 = 0;
            temp_a3->unk0.unk2C = arg1->vx;
            temp_a3->unk0.unk2E = arg1->vy;
            temp_a3->unk0.unk30 = arg1->vz;
            return;
        }

        temp_a3->unk0.unk44.vx = arg1->vx - temp_a3->unk0.unk2C;
        temp_a3->unk0.unk44.vy = arg1->vy - temp_a3->unk0.unk2E;
        temp_a3->unk0.unk44.vz = arg1->vz - temp_a3->unk0.unk30;

        if ((*(int*)&temp_a3->unk0.unk44 == 0)
            && ((temp_a3->unk0.unk44.vz << 0x10) == 0)) {
            temp_a3->unk5C8 = 0;
            return;
        }

        temp_a3->unk5C8 = arg2;
    }
}

void func_800AAC80(RECT* arg0, int arg1, int arg2)
{
    DR_MOVE* drMove = *(DR_MOVE**)0x1F800000;
    SetDrawMove(drMove, arg0, arg1, arg2);
    func_8007A824(drMove);
    *(DR_MOVE**)0x1F800000 = drMove + 1;
}

void func_800AACDC(void)
{
    void* new_var;
    RECT sp10;
    DR_MOVE* temp_s0;

    sp10.x = 470;
    sp10.y = 384;
    sp10.w = 18;
    sp10.h = 36;

    new_var = (void*)0x1F800000;
    temp_s0 = *((DR_MOVE**)0x1F800000);
    new_var = (void*)0x10;

    SetDrawMove(temp_s0, &sp10, 16, 400);
    func_8007A824(temp_s0);

    *((void**)0x1F800000) = (DR_MOVE*)(temp_s0 + 1);
}

// https://decomp.me/scratch/7lkmC
int func_800AAD4C(int actorId, int index, int value, int mode)
{
    D_800F4538_t* actor = D_800F4538[actorId];
    D_800F4538_unk180C* slot;
    if (actor == NULL)
        return -1;
    if (index >= 2)
        return -1;
    if (mode == 1 && value == 0)
        return 0;
    slot = &actor->unk180C[index];
    switch (mode) {
    case 0:
        slot->unk0_4 = 0;
        break;
    case 1:
        if (slot->unk0_4 == 1 && slot->unk0_0 == value)
            return 0;
        slot->unk0_0 = value;
        slot->unk2 = 0;
        if (index == 1) {
            slot->unk3 = actorId * 10;
        } else {
            slot->unk3 = 0;
        }
        slot->unk0_4 = mode;
        break;
    case 2:
        switch (slot->unk0_4) {
        case 0:
            break;
        case 1:
            slot->unk0_4 = 2;
            break;
        case 2:
            slot->unk0_4 = 1;
            break;
        }
        break;
    }
    return 0;
}

int func_800AAE9C(D_800F4538_t* actor)
{
    int i;

    if (D_800F2450[D_800E8F2C] == 0) {
        return 0;
    }

    for (i = 0; i < 2; ++i) {
        D_800F4538_unk180C* slot = &actor->unk180C[i];
        func_800AAE9C_t* p;

        if (slot->unk0_0 == 0) {
            continue;
        }

        switch (slot->unk0_4) {
        case 2:
            continue;

        case 0:
            if (slot->unk1 == 1) {
                slot->unk0_0 = 0;
                continue;
            }
            // Fallthrough
        case 1:
            if (i == 0) {
                p = &D_800E909C[slot->unk0_0][slot->unk2];
            } else {
                p = &D_800E916C[slot->unk0_0][slot->unk2];
            }

            ++slot->unk3;

            if (p->unk1 < slot->unk3) {
                slot->unk3 = 0;
                ++slot->unk2;
                ++p;

                if (p->unk0 == 0) {
                    slot->unk2 = 0;
                    p = (i == 0) ? D_800E909C[slot->unk0_0] : D_800E916C[slot->unk0_0];
                }
            }

            if (p->unk0 == 0) {
                return;
            }

            slot->unk1 = p->unk0;
            break;
        }

        func_800AB098(actor, i, slot->unk1 - 1);
    }

    // BUG: no return value, in practice it isn't read by the only caller.
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/40564", func_800AB098);

void func_800AB2AC(int arg0)
{

    if (arg0 == D_800E8F2C) {
        int i;

        for (i = 0; i < 17; ++i) {
            D_800F4538_t* temp_s0 = D_800F4538[i];
            if ((temp_s0 != NULL) && (temp_s0->unk183E[arg0] != 0xFF)) {
                func_800AB098(temp_s0, 0, 0);
                func_800AB098(temp_s0, 1, 0);
            }
        }
    }
}

extern u_char D_800E8F30[];
extern u_char D_800E8F90[];

static inline DR_MOVE* vs_battlePacketBegin(void) { return *(DR_MOVE**)0x1F800000; }
static inline void vs_battlePacketEnd(DR_MOVE* p) { *(DR_MOVE**)0x1F800000 = p + 1; }
void func_800AB358(int index, u_char* arg)
{
    RECT rect;
    DR_MOVE* packet;
    int srcX, srcY, dstX, width, height, slot;
    int x, y, row, py, page;
    u_char *actor, *part;
    actor = (u_char*)D_800F4538[index];
    if (D_800F2450[D_800E8F2C]) {
        srcX = arg[2];
        srcY = arg[3];
        srcY += (actor + D_800E8F2C)[0x183E];
        part = actor + 0x5F4 + arg[1] * 4;
        dstX = part[0];
        width = part[2];
        height = part[3];
        if (!(*(int*)(actor + 0x5AC) & 0x8000000)) {
            srcX /= 4;
            width /= 4;
            dstX /= 4;
        } else {
            srcX /= 2;
            width /= 2;
            dstX /= 2;
        }
        packet = vs_battlePacketBegin();
        slot = actor[0x5BB];
        x = *(short*)(D_800E8F30 + slot * 4);
        y = *(short*)(D_800E8F30 + slot * 4 + 2);
        row = D_800E8F90[slot];
        py = part[1];
        page = D_800F2450[D_800E8F2C];
        rect.y = srcY + 256;
        rect.w = width;
        rect.h = height;
        rect.x = ((page & 15) << 6) + srcX;
        SetDrawMove(packet, &rect, dstX + (x << 6), (y << 8) + (row << 6) + py);
        func_8007A824(packet);
        vs_battlePacketEnd(packet);
    }
}

void func_800AB4F0(void* actor)
{
    RECT rect;
    u_char *bounds, *state, *part;
    // Original code reads height before its first assignment (incoming saved S2).
    // Preserve this defect for exact original-compiler matching.
    int i, page, originX, originY, x, y, width, height;
    int dx, sx, sy, limitX, limitY, destX, px, py, dy;
    DR_MOVE* packet;
    page = ((u_char*)actor)[0x5BB];
    originX = *(short*)(D_800E8F30 + page * 4) << 6;
    originY = (*(short*)(D_800E8F30 + page * 4 + 2) << 8) + (D_800E8F90[page] << 6);
    for (i = 0; i < 4; ++i) {
        bounds = actor + 0x61C + i * 8;
        if (bounds[2]) {
            state = actor + 0x181C + i * 8;
            state[5] += vs_gametime_tickspeed / 2;
            if (state[4] < state[5]) {
                state[5] = 0;
                part = actor + 0x5F4 + i * 4;
                if (bounds[2] && bounds[2] != height) {
                    width = part[2];
                    px = state[0];
                    dx = (signed char)state[2];
                    py = state[1];
                    dy = (signed char)state[3];
                    sx = bounds[0];
                    height = part[3];
                    x = px + dx;
                    y = py + dy;
                    limitX = sx + bounds[2];
                    limitY = bounds[1] + bounds[3];
                    if (limitX < x + width || x < sx) {
                        if (bounds[6] & 1) {
                            x -= dx * 2;
                            state[2] = -state[2];
                        } else
                            x = sx;
                    }
                    if (limitY < y + height || y < bounds[1]) {
                        if (bounds[6] & 1) {
                            y -= (signed char)state[3] * 2;
                            state[3] = -state[3];
                        } else
                            y = bounds[1];
                    }
                    state[0] = x;
                    state[1] = y;
                    if (!(*(int*)(actor + 0x5AC) & 0x8000000)) {
                        x /= 4;
                        width /= 4;
                        destX = part[0] >> 2;
                    } else {
                        x /= 2;
                        width /= 2;
                        destX = part[0] >> 1;
                    }
                    rect.x = originX + x;
                    packet = vs_battlePacketBegin();
                    rect.y = originY + y;
                    rect.w = width;
                    rect.h = height;
                    SetDrawMove(packet, &rect, originX + destX, originY + part[1]);
                    func_8007A824(packet);
                    vs_battlePacketEnd(packet);
                }
            }
        }
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/40564", func_800AB788);

void func_800A190C(int, int, SVECTOR*, int);
void func_800A7524(void*, void*);
int func_800AC0D4(u_char* arg0, u_char* arg1, int arg2);
int func_800AC168(u_short* colors, int count, int amount, int mode, u_short* reference);
void func_800AC690(int arg0, D_800F45E0_t* arg1);
extern u_char D_800F4B19;

void func_800AB9A4(D_800F45E0_t* arg0)
{
    SVECTOR sp18;
    SVECTOR sp20;
    u_short* sp28;
    int sp2C;
    u_short* sp30;
    u_short* reference;
    int var_s2;
    int clutOffset;
    D_800F45E0_t* var_s5;
    int temp_v0;
    int temp_v0_2;
    int var_a1;
    int angle;
    int var_s0;
    int var_s3;
    int var_s4;
    int var_s6;
    int var_v0;
    signed char temp_v1_5;
    int var_v1;
    u_short* var_fp;
    u_short temp_a2;
    u_int temp_v0_3;
    u_int temp_v1;
    u_int temp_v1_2;
    u_int temp_v1_3;
    u_int var_t0;
    vs_battle_wepModels_t* weapon0;

    temp_v1 = *(u_int*)((char*)arg0 + 8);
    if ((u_int)((temp_v1 >> 8) & 0xF) < 6U) {
        if (temp_v1 & 0x70000) {
            var_v0 = rsin(0x200) * *(u_short*)((char*)arg0 + 0x63C);
            var_a1 = var_v0;
            if (var_v0 < 0) {
                var_a1 = var_v0 + 0xFFF;
            }
            func_800A70DC(arg0, var_a1 >> 0xC);
            func_800A7524(arg0, &arg0->unk34);
            temp_a2 = arg0->unk38;
            arg0->unk34 = (short)((short)(u_short)arg0->unk34 / 2);
            *(short*)((char*)arg0 + 0x38) = (short)temp_a2 / 2;
            func_800AC690(arg0->unkF, arg0);
            if ((u_int)(*(u_short*)((char*)arg0 + 0xA) & 7) >= 4U) {
                if (arg0->unkF != 0) {
                    func_800AD494(arg0, 0xAB, &sp28);
                    if (sp28 != NULL) {
                        *(int*)((char*)arg0 + 0x5AC) =
                            (int)(*(int*)((char*)arg0 + 0x5AC) & 0xFEFFFFFF);
                        func_800A0204((int)arg0->unkF, 0x47, 0, 8);
                        *(int*)((char*)arg0 + 0x5AC) =
                            (int)(*(int*)((char*)arg0 + 0x5AC) | 0x01000000);
                    }
                }
            }
        }
    }
    temp_v1_2 = *(u_int*)((char*)arg0 + 8);
    var_s4 = (int)(vs_gametime_tickspeed + ((u_int)vs_gametime_tickspeed >> 0x1F)) >> 1;
    var_s6 = 0;
    if (temp_v1_2 & 0x80) {
        var_s6 = 1;
        if (*(int*)((char*)arg0 + 0x5AC) & 0x08000000) {
            sp2C = 0xA0;
        } else {
            var_s6 = 0;
            sp2C = 0x10;
        }
        temp_v0 = var_s6 * 2;
        var_fp = (void*)((char*)arg0 + (temp_v0 + 0x1564));
        sp30 = (void*)((char*)arg0 + (temp_v0 + 0x1424));
    } else {
        var_s5 = arg0;
        sp2C = 0x10;
        var_fp = (void*)((char*)arg0 + 0x14C);
        sp30 = (void*)((char*)arg0 + 0x12C);
        if ((temp_v1_2 & 0xF00) == 0x200) {
            var_s4 *= 2;
        }
    }
    temp_v0_2 = ((u_int) * (u_int*)((char*)arg0 + 8) >> 8) & 0xF;
    switch (temp_v0_2) {
    case 2:
        var_s2 = 0;
    block_19:
        var_s3 = 0;
    block_20:
        var_s3 = var_s3 | func_800AC168(var_fp, sp2C - var_s6, var_s4, var_s2, sp30);
        if (*(u_int*)((char*)arg0 + 8) & 0x80) {
            var_s0 = 0;
            do {
                weapon0 = vs_battle_wepModels[(arg0->unkF * 2) + var_s0];
                if (weapon0 != NULL) {
                    reference = weapon0->unk440;
                    var_s3 |= func_800AC168(
                        weapon0->unk500, weapon0->nClutColors, var_s4, var_s2, reference);
                }
                var_s0 += 1;
            } while (var_s0 < 2);
        }
        if (((*(u_int*)((char*)arg0 + 8) & 0xF00) == 0x300) && (var_s3 == 0)) {
            arg0->unk54 = 0x404040;
            func_800AC168(var_fp, sp2C - var_s6, var_s4, 2, sp30);
            var_s0 = 0;
            if (*(u_int*)((char*)arg0 + 8) & 0x80) {
                do {
                    weapon0 = vs_battle_wepModels[(arg0->unkF * 2) + var_s0];
                    if (weapon0 != NULL) {
                        reference = weapon0->unk440;
                        func_800AC168(
                            weapon0->unk500, weapon0->nClutColors, var_s4, 2, reference);
                    }
                    var_s0 += 1;
                } while (var_s0 < 2);
                goto block_32;
            }
            goto block_38;
        }
    block_32:
        if (*(u_int*)((char*)arg0 + 8) & 0x80) {
            vs_main_loadClut((u_short*)&arg0->unk11A4[0x3C0], arg0->unkF + 4, 0, sp2C);
            var_s0 = 0;
            clutOffset = 0xA0;
            do {
                weapon0 = vs_battle_wepModels[(arg0->unkF * 2) + var_s0];
                if (weapon0 != NULL) {
                    *(u_int*)((char*)weapon0 + 8) =
                        (int)((*(u_int*)((char*)weapon0 + 8) & ~0xF00)
                              | (*(u_int*)((char*)arg0 + 8) & 0xF00));
                    vs_main_loadClut(weapon0->unk500, arg0->unkF + 4, clutOffset,
                        (u_int)weapon0->nClutColors);
                }
                var_s0 += 1;
                clutOffset += 0x30;
            } while (var_s0 < 2);
        } else {
        block_38:
            vs_main_loadClut(
                (u_short*)((char*)var_s5 + 0x14C), 0x1FU, var_s5->unkF * 0x10, 0x10U);
        }
        if (var_s3 == 0) {
            temp_v0_3 = *(u_int*)((char*)arg0 + 8);
            temp_v1_3 =
                (temp_v0_3 & ~0xF00) | (((((temp_v0_3 >> 8) & 0xF) + 1) & 0xF) << 8);
            *(u_int*)((char*)arg0 + 8) = temp_v1_3;
            var_s0 = 0;
            if (temp_v1_3 & 0x80) {
                do {
                    weapon0 = vs_battle_wepModels[(arg0->unkF * 2) + var_s0];
                    if (weapon0 != NULL) {
                        *(u_int*)((char*)weapon0 + 8) =
                            (int)((*(u_int*)((char*)weapon0 + 8) & ~0xF00)
                                  | (*(u_int*)((char*)arg0 + 8) & 0xF00));
                    }
                    var_s0 += 1;
                } while (var_s0 < 2);
            }
        }
    case 1:
    case 15:
    default:
        return;
    case 3:
        var_s3 = 0;
        var_s2 = 1;
        goto block_20;
    case 4:
        if (*(int*)((char*)arg0 + 0x5AC) & 8) {
            var_s5 = D_800F45E0[arg0->unk13];
            func_800A190C(var_s5->unk12, 0xF0, &sp18, 1);
            func_800A190C(var_s5->unk12, 0xF1, &sp20, 1);
            var_s5->unk1C = (short)(u_short)arg0->unk1C;
            var_s5->unk20 = (short)(u_short)arg0->unk20;
            var_s5->unk1E = ((int)(sp18.vy + sp20.vy) / 2) + 0x3C;
            angle = (u_short)arg0->unk26;
            var_s5->unk1A = 0xFC;
            *(int*)((char*)var_s5 + 0x34) = 0;
            var_s5->unk12 = 0xFF;
            var_s5->unk26 = ((u_short)var_s5->unk26 + angle) & 0xFFF;
            *(int*)((char*)arg0 + 0x5AC) = (int)(*(int*)((char*)arg0 + 0x5AC) & ~8);
            D_800F4B19 = arg0->unk13;
        }
        var_v1 = (u_char)arg0->unk54 - (var_s4 * 4);
        var_s3 = 0;
        if (var_v1 < 0) {
            var_v1 = 0;
        }
        if (var_v1 != 0) {
            var_s3 = 1;
        }
        *(u_char*)&arg0->unk54 = var_v1;
        *((signed char*)arg0 + 0x55) = var_v1;
        var_s0 = (signed char)arg0->unk6F2;
        var_s0 += var_s4 * 2;
        *((signed char*)arg0 + 0x56) = var_v1;
        if (var_s0 >= 0x41) {
            var_s0 = 0x40;
        }
        if (var_s0 != 0x40) {
            var_s3 = 1;
        }
        arg0->unk6F2 = (u_char)var_s0;
        goto block_32;
    case 6:
        var_s2 = 3;
        var_v1 = *((u_char*)arg0 + 0x57);
        var_v1 += 1;
        var_v0 = var_v1 & 255;
        var_s3 = (u_int)var_v0 < 15;
        var_s0 = (signed char)arg0->unk6F2;
        var_s0 += var_s4 * 2;
        var_v0 = var_s0 < 0x41;
        *((u_char*)arg0 + 0x57) = var_v1;
        goto block_60;
    case 7:
        var_s3 = 0;
        var_s2 = 1;
        var_s0 = (signed char)arg0->unk6F2;
        var_s0 += var_s4 * 2;
        var_v0 = var_s0 < 0x41;
        goto block_60;
    block_60:
        if (var_v0 == 0) {
            var_s0 = 0x40;
        }
        arg0->unk6F2 = (u_char)var_s0;
        goto block_20;
    case 9:
        var_s3 = 0;
        var_s2 = 2;
        *(u_char*)&arg0->unk54 = 0xFF;
        *((u_char*)arg0 + 0x55) = 255;
        *((u_char*)arg0 + 0x56) = 255;
        goto block_20;
    case 10:
        var_s3 = 0;
        temp_v1_5 = (signed char)arg0->unk6F1;
        var_s0 = (signed char)arg0->unk6F2;
        var_s0 -= var_s4 * 2;
        var_s2 = 4;
        if (var_s0 < temp_v1_5) {
            var_s0 = temp_v1_5;
        }
        if (var_s0 != temp_v1_5) {
            var_s3 = 1;
        }
        arg0->unk6F2 = (u_char)var_s0;
        var_s3 = var_s3 | func_800AC0D4(&arg0->unk54, &arg0->unk58, (-var_s4) << 3);
        goto block_20;
    case 11:
        *(u_int*)((char*)arg0 + 8) = (u_int)(*(u_int*)((char*)arg0 + 8) & ~0xF00);
        return;
    case 12:
        var_s3 = 0;
        var_s2 = 5;
        goto block_20;
    case 14:
        arg0->unk6F2 = 0x40;
        var_s2 = 6;
        goto block_19;
    }
}

int func_800AC0D4(u_char* arg0, u_char* arg1, int arg2)
{
    int i;
    int var_t0 = 0;

    for (i = 0; i < 3; ++i) {
        if (arg2 < 0) {
            if (*arg1 < *arg0) {
                var_t0 = 1;
                *arg0 += arg2;
                if (*arg0 < *arg1) {
                    *arg0 = *arg1;
                }
            }
        } else {
            if (*arg0 < *arg1) {
                var_t0 = 1;
                *arg0 += arg2;
                if (*arg1 < *arg0) {
                    *arg0 = *arg1;
                }
            }
        }
        ++arg0;
        ++arg1;
    }

    return var_t0;
}

int func_800AC168(u_short* colors, int count, int amount, int mode, u_short* reference)
{
    int i = 0;
    int changed = 0;
    int r, g, b;
    int baseR, baseG;
    int color, delta;
    int output;
    if (count > 0) {
        do {
            b = *colors;
            r = b & 31;
            g = (b >> 5) & 31;
            b = (b >> 10) & 31;
            switch (mode) {
            case 0:
                delta = amount * 2;
                r -= delta;
                if (r < 0)
                    r = 0;
                g -= delta;
                if (g < 0)
                    g = 0;
                r |= g << 5;
                if (r != 0)
                    changed = 1;
                r |= b << 10;
                output = r | ~0x7FFF;
                *colors = output;
                break;
            case 1:
                delta = amount * 4;
            fade:
                b -= delta;
                if (b < 0)
                    b = 0;
                r -= delta;
                if (r < 0)
                    r = 0;
                g -= delta;
                if (g < 0)
                    g = 0;
                r |= g << 5;
                r |= b << 10;
                if (r != 0)
                    changed = 1;
                output = r | ~0x7FFF;
                *colors = output;
                break;
            case 2:
                output = 0xFFFF;
                *colors = output;
                break;
            case 3:
                r += amount;
                if (r >= 32)
                    r = 31;
                g += amount * 2;
                if (g >= 32)
                    g = 31;
                b += amount * 2;
                if (b >= 32)
                    b = 31;
                r |= g << 5;
                r |= b << 10;
                output = r | ~0x7FFF;
                *colors = output;
                break;
            case 4:
                color = *reference;
                r -= amount * 2;
                baseR = color & 31;
                baseG = (color >> 5) & 31;
                color = (color >> 10) & 31;
                if (r < baseR)
                    r = baseR;
                g -= amount * 2;
                if (g < baseG)
                    g = baseG;
                b -= amount * 2;
                if (b < color)
                    b = color;
                r |= g << 5;
                delta = b << 10;
                color = *reference;
                r |= delta;
                do {
                    if (r != (color & 0x7FFF)) {
                        changed = 1;
                    }
                } while (0);
                output = (color & 0x8000) | r;
                *colors = output;
                break;
            case 5:
                delta = amount;
                goto fade;
            case 6:
                output = 0x8000;
                *colors = output;
            }
            ++i;
            ++colors;
            ++reference;
        } while (i < count);
    }
    return changed;
}

void func_800AC37C(int arg0, int arg1)
{
    D_800F4538_t* temp_a0 = D_800F4538[arg0];

    switch (arg1) {
    case 0:
        temp_a0->unk0.unk9_0 = 14;
        break;
    case 1:
        temp_a0->unk0.unk9_0 = 6;
        break;
    case 2:
        temp_a0->unk0.unk9_0 = 9;
        break;
    }
    if (temp_a0->unk17FD > 1) {
        func_800AC37C(temp_a0->unk17FD, arg1);
    }
}

void func_800AC440(D_800F4538_t* arg0, int arg1, int arg2)
{
    int sp10;
    int i;
    _armature_t* temp_s2 = &arg0->unk0.unk68->armatures[arg1];

    for (i = 0; i < 2; ++i) {
        if (arg2 == 0) {
            if (arg0->unk18D0[i] == arg1) {
                arg0->unk18D0[i] = 0;
                temp_s2->unkC = 0;
                return;
            }
        } else if (arg0->unk18D0[i] == 0) {
            func_800A1720(arg0->unk0.unkF, arg1, arg0->unk1890[i], &sp10);
            temp_s2->unkC = i + 1;
            arg0->unk18D0[i] = arg1;
            return;
        }
    }
}

void func_800AC500(D_800F4538_t* arg0)
{
    int i;

    arg0->unk18D0[0] = 0;
    arg0->unk18D0[1] = 0;

    for (i = 0; i < arg0->unk0.nBones; ++i) {
        arg0->unk0.unk68->armatures[i].unkC = 0;
    }
}

void func_800AC540(int arg0, D_800F4538_t* arg1)
{

    switch (arg1->unk5AC_0) {
    case 1:
        if (arg1->unk0.unk18 == 0) {

            if (arg1->unk0.unkA_5) {
                func_800A0204(arg0, 0x1F, 0, 8);
            } else {
                func_800A0204(arg0, arg1->unk6E5, 0, 8);
            }

            if (!(arg1->unk5AC_2 << 2)) {
                func_800A9D90(arg0, &arg1->unk5EC, arg1->unk5C4);
            } else {
                func_800AA620(arg0, &arg1->unk5EC, arg1->unk5C4);
            }

            arg1->unk5AC_0 = 2;
        }
        break;

    case 2:
        if (arg1->unk0.unk1A == 0) {
            int temp_a1;

            func_800A0204(arg0, 1, 0, 8);

            temp_a1 = (u_short)arg1->unk5EC.pad;

            if (temp_a1 != 0x8000) {
                temp_a1 = temp_a1 & 0xFFF;
                if ((arg1->unk5AC_2 << 2) == 0) {
                    func_800A9EB4(arg0, temp_a1, arg1->unk5C6);
                } else {
                    func_800AA850(arg0, temp_a1, arg1->unk5C6);
                }
            }
            arg1->unk5AC_0 = 0;
        }
        break;
    }
}

void func_800AC690(int arg0, D_800F45E0_t* arg1);
INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/40564", func_800AC690);

typedef struct {
    int unk0;
    int unk4;
} func_800ACF54_t;

void func_800ACF54(D_800F45E0_t* arg0)
{

    arg0->unk60 = *(int*)&arg0->unk5C;
    *(func_800ACF54_t*)&arg0->unk4C = *(func_800ACF54_t*)&arg0->unk1C;

    if (!(arg0->unkC_0)) {
        arg0->unk1868 = *(int*)&arg0->unk5C;
    }

    arg0->unk52 = arg0->unk26;
}

void func_800ACFA0(short* arg0, u_char* arg1, int arg2)
{
    int a3;
    a3 = arg1[0];
    a3 <<= 8;
    a3 |= arg1[1];
    a3 *= 2;
    arg0[0] = a3;

    a3 = arg1[2];
    a3 <<= 8;
    a3 |= arg1[3];
    a3 *= 2;
    arg0[1] = a3;

    a3 = arg1[4];
    a3 <<= 8;
    a3 |= arg1[5];
    a3 *= 2;
    arg0[2] = a3;

    arg0[3] = 6;

    if (arg2 != 0xFF) {
        arg0[3] = 0;
    }

    arg0[339] = 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/40564", func_800AD008);

int func_800AD494(void* arg0, int arg1, u_short** arg2)
{
    D_800F4538_t* actor = arg0;
    func_800AD494_t* p;
    int idx;

    *arg2 = NULL;

    if (arg1 == 0) {
        p = actor->unk5D0;
        idx = 0;
    } else if (arg1 == 0xFF) {
        p = actor->unk5DC[3];
        if ((actor->unk0.unkF == 0) || (actor->unk6E6 == 2)) {
            idx = D_800F49E4;
        } else {
            if (actor->unk5B1 == 0) {
                return 0;
            }
            idx = actor->unk5B1 - 1;
            idx = idx * 3 + D_800F49E4;
        }
        if (idx >= actor->unk5B6) {
            return 0;
        }
    } else if (arg1 == 0xFE) {
        p = actor->unk5DC[3];
        if (actor->unk5B1 == 0) {
            return 0;
        }
        idx = actor->unk5B1 - 1;
        idx = idx * 3 + 31;
        if (idx >= actor->unk5B6) {
            return 0;
        }
    } else if (arg1 >= 0xDC) {
        p = actor->unk5DC[D_800E8F2C];
        idx = arg1 - 0xDC;
    } else if (arg1 >= 0xCA) {
        p = D_800F4768;
        idx = arg1 - 0xCA;
    } else if (arg1 >= 100) {
        p = actor->unk5D8;
        idx = arg1 - 100;
        if (idx >= actor->unk5B5) {
            return 0;
        }
    } else {
        p = actor->unk5D4;
        idx = arg1;
        if (idx >= actor->unk5B4) {
            return 0;
        }
    }

    if (p == NULL) {
        return 0;
    }

    idx = p->unk4[idx];
    D_800F49DC = idx;

    if (idx == 0xFF) {
        *arg2 = NULL;
    } else {
        *arg2 = &p->unk8[(((actor->unk0.nBones * 4) + 10) * idx) >> 1];
    }
    return (int)p;
}

void func_800AD62C(int arg0, int* arg1, int* arg2)
{
    int temp_v0;
    D_800F4538_t* temp_s0 = D_800F4538[arg0];

    if (temp_s0->unk17E4.unk0 == 2) {
        *arg1 = 0x80;
        if (arg2 != NULL) {
            *arg2 = 0;
        }
    } else {
        if (temp_s0->unk0.unk9_0 || temp_s0->unk0.unk9_4 || !temp_s0->unk0.unk9_7
            || temp_s0->unk0.unkA_0 || temp_s0->unk0.unkA_3 || temp_s0->unk0.unkA_5) {
            func_800A1280(arg0, 0xFF, &temp_s0->unk6FC, 0);
        }

        temp_v0 = vs_main_computeSfxPan(*(int*)&temp_s0->unk6FC, temp_s0->unk6FC.vz);
        *arg1 = temp_v0 >> 0x10;

        if (temp_s0->unk17E4.unk1 != 0) {
            *arg1 = temp_s0->unk17E4.unk1;
        }

        if (arg2 != NULL) {
            *arg2 = temp_v0 & 0xFFFF;
            if (temp_s0->unk17E4.unk2 != 0) {
                *arg2 = temp_s0->unk17E4.unk2;
            }
        }
    }
}
