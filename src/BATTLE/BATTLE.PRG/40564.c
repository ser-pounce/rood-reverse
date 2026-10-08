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
    u_char* unk0;
    u_char* unk4;
    u_short unk8[0];
} func_800AD494_t;

typedef struct {
    short x;
    short y;
    short z;
    short id;
} func_8008D2C0_t;

typedef struct {
    u_char unk0;
    u_char overlay;
    u_char x;
    u_char y;
} func_800AB358_t;

typedef struct {
    u_char unk0[0xF];
    u_char unkF;
    u_char unk10[0x54];
    D_800F4538_unk64 unk64;
    u_char unk68[0xC4];
    u_short unk12C[16];
    u_short unk14C[16];
} func_800AB788_t;

typedef struct {
    u_int unk0 : 24;
    u_int timer : 8;
} func_800AC690_timer_t;

typedef struct {
    u_int unk0 : 16;
    u_int state : 3;
    u_int unk13 : 13;
} func_800AC690_flags_t;

typedef struct {
    u_int contact : 4;
    u_int unk4 : 28;
} func_800AC690_contact_t;

typedef struct {
    int unk0;
    int unk4;
} func_800ACF54_t;

void func_8006F450(SVECTOR*);
void func_8007A824(DR_MOVE*);
void func_8008C49C(int, int);
int func_8008D2C0(func_8008D2C0_t*);
short func_8008DA24(int, int);
short func_8008DD0C(int, int);
void func_800A0204(int, int, int, int);
void func_800A1280(int, int, SVECTOR*, int);
void func_800A1720(int, int, void*, int*);
void func_800A190C(int, int, SVECTOR*, int);
int func_800A6EE8(SVECTOR*, int, int, int);
void func_800A70DC(D_800F4538_t*, int);
void func_800A7524(void*, void*);
void func_800AA290(int, func_8006EBF8_t_fields*, int, int);
void func_800AA490(int, func_8006EBF8_t_fields*, int, int);
void func_800AA698(int arg0, SVECTOR* arg1, int arg2);
void func_800AA984(int, short, int);
void func_800AAA88(int arg0, SVECTOR* arg1, int arg2);
void func_800AB098(D_800F4538_t*, int, int);
int func_800AC0D4(u_char* arg0, u_char* arg1, int arg2);
int func_800AC168(u_short* colors, int count, int amount, int mode, u_short* reference);
void func_800AC690(int arg0, D_800F4538_t* arg1);
void func_800ACF54(D_800F4538_t*);
void func_800AE47C(D_800F4538_t*);
void func_800AE828(int, D_800F4538_t*, int);
void func_800E4C28();
void func_800E6764(int);
void func_800E6EB0(int);

extern u_char D_800E8F2C;
extern short D_800E8F30[];
extern u_char D_800E8F90[];
extern func_800AAE9C_t D_800E909C[][28];
extern func_800AAE9C_t D_800E916C[][8];
extern u_char D_800E9278[];
extern u_char D_800E92E8[];
extern u_char D_800E92F0[];
extern u_char D_800E92F8[];
extern u_char D_800E9300[];
extern u_char D_800F2450[];
extern void* D_800F4768;
extern char D_800F49DC;
extern u_char D_800F49E4;
extern u_int* D_800F49F0;
extern int D_800F49F4;
extern u_char D_800F49F8;
extern u_char D_800F49F9;
extern short D_800F4B00;
extern u_char D_800F4B19;

#define getActorFlags(actor) (*((int*)&(actor)->unk5B4 - 2))

static inline DR_MOVE* vs_battlePacketBegin(void)
{
    return ((vs_scratch_t*)0x1F800000)->unk0;
}
static inline void vs_battlePacketEnd(DR_MOVE* p)
{
    ((vs_scratch_t*)0x1F800000)->unk0 = p + 1;
}

// Inlined copy of 3A1A0 func_800A4A24
static inline func_8008D2C0_t* func_800A4A24(int id)
{
    func_8008D2C0_t platforms[4];
    int count;
    int i;

    id -= 2;
    count = func_8008D2C0(platforms);

    for (i = 0; i < count; ++i) {
        if (platforms[i].id == id) {
            // BUG: returns stack variable
            return &platforms[i];
        }
    }

    return NULL;
}

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

int func_800A8E84(D_800F4538_t* actor, SVECTOR* position)
{
    D_1F8003BC_t* scratch = (D_1F8003BC_t*)0x1F8003BC;
    int i;

    if (actor->unk0.unkF != 0) {
        return 1;
    }

    if (actor->unk5AC_11 << 11) {
        return 1;
    }

    if (actor->unk5AC_12 << 12) {
        return 1;
    }

    for (i = 2; i < 17; ++i) {
        D_800F4538_t* other = D_800F4538[i];
        int radius;

        if (other == NULL || other == actor) {
            continue;
        }

        if (other->unk0.skip || (getActorFlags(other) & 0x1000000)
            || other->unk0.unk13 == 0xFC || other->unk0.unkB_0 == 2
            || scratch->excluded[i]) {
            continue;
        }

        radius = other->collisionRadius;

        if (other->unk0.position.vx + radius < position->vx
            || position->vx < other->unk0.position.vx - radius
            || other->unk0.position.vz + radius < position->vz
            || position->vz < other->unk0.position.vz - radius
            || other->unk0.position.vy < actor->unk0.position.vy - actor->collisionHeight
            || actor->unk0.position.vy
                   < other->unk0.position.vy - other->collisionHeight) {
            continue;
        }

        return 0;
    }

    return 1;
}

int func_800A8FD4(D_800F4538_t* actor, SVECTOR* motion)
{
    D_1F8003BC_t* scratch = (D_1F8003BC_t*)0x1F8003BC;
    D_1F8003BC_t* clear;
    D_800F4538_t** entry;
    int flags;
    int i;
    int radius;
    int minX;
    int maxX;
    int minY;
    int minZ;
    int maxZ;

    for (i = 16, clear = (D_1F8003BC_t*)((u_char*)scratch + 16); i >= 0; --i) {
        clear->excluded[0] = 0;
        clear = (D_1F8003BC_t*)((u_char*)clear - 1);
    }

    flags = getActorFlags(actor);

    if (flags & 0x800) {
        return flags & 0x800;
    }

    radius = actor->collisionRadius;
    minY = actor->unk0.position.vy - actor->collisionHeight;
    minX = actor->unk0.position.vx - radius;
    maxX = actor->unk0.position.vx + radius;
    minZ = actor->unk0.position.vz - radius;
    maxZ = actor->unk0.position.vz + radius;
    i = 2;

    if (flags & 8) {
        minY -= 128;
    }

    for (entry = &D_800F4538[i]; i < 17; ++entry) {
        D_800F4538_t* other = *entry;
        int otherRadius;
        int dx;
        int dz;
        int oldDistance;

        if (other != NULL
            && !(other->unk0.skip || (getActorFlags(other) & 0x1000000)
                 || other->unk0.unk13 == 0xFC || other->unk0.unkB_0 == 2)) {
            otherRadius = other->collisionRadius;

            if (!(other->unk0.position.vx + otherRadius < minX
                    || maxX < other->unk0.position.vx - otherRadius
                    || other->unk0.position.vz + otherRadius < minZ
                    || maxZ < other->unk0.position.vz - otherRadius
                    || other->unk0.position.vy < minY
                    || actor->unk0.position.vy
                           < other->unk0.position.vy - other->collisionHeight)) {
                scratch->excluded[i] = 1;
                dx = other->unk0.position.vx - actor->unk0.position.vx;
                dx *= dx;
                dz = other->unk0.position.vz - actor->unk0.position.vz;
                dz *= dz;
                oldDistance = dx + dz;
                dx = other->unk0.position.vx - (actor->unk0.position.vx + motion->vx);
                dx *= dx;
                dz = other->unk0.position.vz - (actor->unk0.position.vz + motion->vz);
                dz *= dz;
                dx += dz;
                ++i;

                if (dx < oldDistance) {
                    return 0;
                }

                continue;
            }
        }

        ++i;
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

inline int func_800A92B8(int arg0, int arg1)
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

int func_800A9378(int arg0, int arg1, int arg2, int arg3)
{
    func_8008D2C0_t sp10[4];
    int count;
    int i;

    D_800F49F4 = 0;
    count = func_8008D2C0(sp10);

    if (count == 0) {
        return 0;
    }

    for (i = 0; i < count; ++i) {
        if ((arg0 >= sp10[i].x + 64) || (arg0 < sp10[i].x - 64)) {
            continue;
        }

        if ((arg2 >= sp10[i].z + 64) || (arg2 < sp10[i].z - 64)) {
            continue;
        }

        switch (arg3) {
        case 0:
            if (sp10[i].y < arg1 - 256) {
                continue;
            }
            break;

        case 1:
            if (sp10[i].y < arg1 - 256) {
                return sp10[i].y + 96;
            }
            continue;

        case 2:
            if ((sp10[i].y >= arg1) || (sp10[i].y < arg1 - 128)) {
                continue;
            }
            break;

        case 3:
            if ((sp10[i].y >= arg1) || (sp10[i].y < arg1 - D_800F4B00)) {
                continue;
            }
            return sp10[i].y + 96;
        }

        D_800F49F4 = sp10[i].id + 2;
        return sp10[i].y;
    }

    return 0;
}

int func_800A9530(D_800F4538_t* actor, SVECTOR* offset)
{
    int position = actor->unk63C;
    int direction = D_800F49F9 >> 1;
    int edge;
    int surface;
    int distance;

    actor->unk1800 = direction * (ONE / 4);

    if (actor->unk0.unkC_0) {
        func_8008D2C0_t* platform = func_800A4A24(actor->unk0.unkC_0);

        edge = 65;

        if (direction < 2) {
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

        if (direction < 2) {
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

        if (getActorFlags(actor) & 0xF0000000) {
            offset->vy += 12;
        }

        offset->vy += 8;
    }

    surface = actor->unk0.unkC_0;
    actor->unk0.unkC_0 = 0;
    actor->unk0.position.vx += offset->vx;
    actor->unk0.position.vz += offset->vz;
    distance = rsin(ONE / 8);
    distance *= actor->unk63C;
    distance /= ONE;
    func_800A70DC(actor, distance);
    actor->unk0.position.vx -= offset->vx;
    actor->unk0.position.vz -= offset->vz;
    actor->unk0.unkC_0 = surface;

    if (actor->unk5AC_12 << 12) {
        actor->unk5AC_12 = 0;
        return 0;
    }

    return 1;
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

void func_800A9988(int id, SVECTOR* target, int arg2, int arg3)
{
    D_800F4538_t* actor = D_800F4538[id];
    int angle;
    int dz;

    if (arg2 == 0 && arg3 == 0) {
        u_short facing = target->pad;

        if (facing == 0x8000) {
            angle = target->vx - actor->unk0.position.vx;
            dz = target->vz - actor->unk0.position.vz;

            if (angle == 0 && dz == 0) {
                angle = (short)facing;
            } else {
                angle = ONE * 3 / 4 - ratan2(dz, angle);
                angle &= 0xFFF;
            }

            angle = (short)angle;
            actor->unk0.facing = angle;
        } else {
            actor->unk0.facing = facing;
        }

        actor->unk0.unk18 = 0;
        func_800A9D90(id, target, 0);
        return;
    }

    angle = target->vx - actor->unk0.position.vx;
    dz = target->vz - actor->unk0.position.vz;

    if (angle == 0 && dz == 0) {
        u_short facing = target->pad;

        if (facing == 0x8000) {
            return;
        }

        angle = (short)facing;
    } else {
        angle = ONE * 3 / 4 - ratan2(dz, angle);
        angle &= 0xFFF;
    }

    angle = (short)angle;
    func_800A9EB4(id, angle, arg3);

    if (arg2 == -1) {
        actor->unk5C4 = actor->unk5C2;
    } else {
        actor->unk5C4 = arg2;
    }

    if (arg3 == -1) {
        actor->unk5C6 = actor->unk5C0;
    } else {
        actor->unk5C6 = arg3;
    }

    actor->unk5EC.vx = target->vx;
    actor->unk5EC.vz = target->vz;
    angle = (u_short)target->vy;

    if (angle == 0x8000) {
        angle = func_8008DA24(target->vx, target->vz);
        angle <<= 17;
        angle >>= 17;
        // BUG: passes the x tile twice
        dz = func_800A92B8(target->vx / 128, target->vx / 128);

        if (dz != 0) {
            angle = dz;
        }

        actor->unk5EC.vy = angle;
    } else {
        actor->unk5EC.vy = angle;
    }

    actor->unk5EC.pad = target->pad;
    actor->unk5AC_0 = 1;
    actor->unk5AC_2 = 0;
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
            temp_a1 %= ONE;
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
        angle = ONE * 3 / 4 - ratan2(dz, angle);
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
    D_800F4538_t* actor = D_800F4538[arg0];

    if (actor != NULL) {

        if (arg2 == 0) {
            actor->unk5C8 = 0;
            actor->unk0.unk2C = arg1->vx;
            actor->unk0.unk2E = arg1->vy;
            actor->unk0.unk30 = arg1->vz;
            return;
        }

        actor->unk0.unk44.vx = arg1->vx - actor->unk0.unk2C;
        actor->unk0.unk44.vy = arg1->vy - actor->unk0.unk2E;
        actor->unk0.unk44.vz = arg1->vz - actor->unk0.unk30;

        if (actor->unk0.unk44.vx == 0 && actor->unk0.unk44.vy == 0
            && actor->unk0.unk44.vz == 0) {
            actor->unk5C8 = 0;
            return;
        }

        actor->unk5C8 = arg2;
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
    RECT rect;
    DR_MOVE* packet;

    rect.x = 470;
    rect.y = 384;
    rect.w = 18;
    rect.h = 36;

    packet = vs_battlePacketBegin();
    SetDrawMove(packet, &rect, 16, 400);
    func_8007A824(packet);
    vs_battlePacketEnd(packet);
}

int func_800AAD4C(int actorId, int index, int value, int mode)
{
    D_800F4538_t* actor = D_800F4538[actorId];
    D_800F4538_unk180C* slot;

    if (actor == NULL) {
        return -1;
    }

    if (index >= 2) {
        return -1;
    }

    if (mode == 1 && value == 0) {
        return 0;
    }

    slot = &actor->unk180C[index];

    switch (mode) {
    case 0:
        slot->unk0_4 = 0;
        break;

    case 1:
        if (slot->unk0_4 == 1 && slot->unk0_0 == value) {
            return 0;
        }

        slot->unk0_0 = value;
        slot->unk2 = 0;

        slot->unk3 = (index == 1) ? actorId * 10 : 0;

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

void func_800AB098(D_800F4538_t* actor, int index, int frame)
{
    texMapAnimation_t fallback;
    RECT rect;
    DR_MOVE* packet;
    texMapAnimation_t* animation;
    texMapOverlay_t* overlay;
    int srcX;
    int srcY;
    int dstX;
    int width;
    int height;
    int x;
    int y;
    int row;
    int py;

    if (actor->unk183E[D_800E8F2C] == 0xFF) {
        return;
    }

    animation = &actor->unk1804[index];

    if (animation->columns == 0) {
        fallback.overlay = index ? 7 : 5;
        fallback.x = actor->unk614[index].x;
        fallback.y = actor->unk614[index].y;
        fallback.columns = actor->unk614[index].columns;

        if (fallback.columns == 0) {
            return;
        }

        animation = &fallback;
    }

    srcX = animation->x;
    srcY = animation->y;
    overlay = &actor->texMapOverlays[animation->overlay - 1];
    dstX = overlay->x;
    width = overlay->w;
    height = overlay->h;

    if (!(getActorFlags(actor) & 0x8000000)) {
        srcX /= 4;
        width /= 4;
        dstX /= 4;
    } else {
        srcX /= 2;
        width /= 2;
        dstX /= 2;
    }

    srcX += (frame % animation->columns) * width;
    srcY += (frame / animation->columns) * height;
    srcY += actor->unk183E[D_800E8F2C];
    packet = vs_battlePacketBegin();
    x = D_800E8F30[actor->unk5BB * 2];
    y = D_800E8F30[actor->unk5BB * 2 + 1];
    row = D_800E8F90[actor->unk5BB];
    py = overlay->y;
    frame = D_800F2450[D_800E8F2C] & 15;
    setRECT(&rect, (frame * 64) + srcX, srcY + 256, width, height);
    srcY = (y * 256) + (row * 64) + py;
    SetDrawMove(packet, &rect, dstX + (x * 64), srcY);
    func_8007A824(packet);
    vs_battlePacketEnd(packet);
}

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

void func_800AB358(int index, func_800AB358_t* arg)
{
    RECT rect;
    DR_MOVE* packet;
    D_800F4538_t* actor = D_800F4538[index];
    texMapOverlay_t* overlay;
    int srcX;
    int srcY;
    int dstX;
    int width;
    int height;
    int x;
    int y;
    int row;
    int py;

    if (D_800F2450[D_800E8F2C] == 0) {
        return;
    }

    srcX = arg->x;
    srcY = arg->y;
    srcY += actor->unk183E[D_800E8F2C];
    overlay = &actor->texMapOverlays[arg->overlay];
    dstX = overlay->x;
    width = overlay->w;
    height = overlay->h;

    if (!(getActorFlags(actor) & 0x8000000)) {
        srcX /= 4;
        width /= 4;
        dstX /= 4;
    } else {
        srcX /= 2;
        width /= 2;
        dstX /= 2;
    }

    packet = vs_battlePacketBegin();
    x = D_800E8F30[actor->unk5BB * 2];
    y = D_800E8F30[actor->unk5BB * 2 + 1];
    row = D_800E8F90[actor->unk5BB];
    py = overlay->y;
    setRECT(
        &rect, ((D_800F2450[D_800E8F2C] & 15) * 64) + srcX, srcY + 256, width, height);
    SetDrawMove(packet, &rect, dstX + (x * 64), (y * 256) + (row * 64) + py);
    func_8007A824(packet);
    vs_battlePacketEnd(packet);
}

void func_800AB4F0(D_800F4538_t* actor)
{
    int originX = D_800E8F30[actor->unk5BB * 2] * 64;
    int originY =
        (D_800E8F30[actor->unk5BB * 2 + 1] * 256) + (D_800E8F90[actor->unk5BB] * 64);
    int i;
    int height;

    for (i = 0; i < 4; ++i) {
        D_800F4538_unk61C* bounds = &actor->unk61C[i];
        D_800F4538_unk181C* scroll;
        texMapOverlay_t* overlay;
        RECT rect;
        DR_MOVE* packet;
        int x;
        int y;
        int width;
        int scrollX;
        int scrollY;
        int dx;
        int dy;
        int minX;
        int maxX;
        int maxY;
        int dstX;

        if (bounds->w == 0) {
            continue;
        }

        scroll = &actor->unk181C[i];
        scroll->timer += vs_gametime_tickspeed / 2;

        if (scroll->timer <= scroll->interval) {
            continue;
        }

        scroll->timer = 0;
        overlay = &actor->texMapOverlays[i];

        // BUG: height is read before it is first set
        if (bounds->w == 0 || bounds->w == height) {
            continue;
        }

        width = overlay->w;
        scrollX = scroll->x;
        dx = scroll->dx;
        scrollY = scroll->y;
        dy = scroll->dy;
        minX = bounds->x;
        height = overlay->h;
        x = scrollX + dx;
        y = scrollY + dy;
        maxX = minX + bounds->w;
        maxY = bounds->y + bounds->h;

        if (maxX < x + width || x < minX) {
            if (bounds->unk6_0) {
                x -= dx * 2;
                scroll->dx = -scroll->dx;
            } else {
                x = minX;
            }
        }

        if (maxY < y + height || y < bounds->y) {
            if (bounds->unk6_0) {
                y -= scroll->dy * 2;
                scroll->dy = -scroll->dy;
            } else {
                y = bounds->y;
            }
        }

        scroll->x = x;
        scroll->y = y;

        if (!(getActorFlags(actor) & 0x8000000)) {
            x /= 4;
            width /= 4;
            dstX = overlay->x >> 2;
        } else {
            x /= 2;
            width /= 2;
            dstX = overlay->x >> 1;
        }

        rect.x = originX + x;
        packet = vs_battlePacketBegin();
        rect.y = originY + y;
        rect.w = width;
        rect.h = height;
        SetDrawMove(packet, &rect, originX + dstX, originY + overlay->y);
        func_8007A824(packet);
        vs_battlePacketEnd(packet);
    }
}

void func_800AB788(D_800F4538_t* actor, func_800AB788_t* object, int arg2)
{
    D_800F4538_unk64* state;
    int count;
    int value;
    int i;
    int _[2] __attribute__((unused));

    if (actor == NULL) {
        count = 16;
        state = &object->unk64;
    } else {
        count = 160;

        if (!(getActorFlags(actor) & 0x8000000)) {
            count = 16;
        }

        state = &actor->unk0.unk64;
    }

    value = state->unk1;

    if (vs_gametime_tickspeed == 4) {
        if (!(state->unk2 & 2)) {
            value += 2;

            if (value >= 16) {
                state->unk2 |= 2;
            }
        } else {
            value -= 2;

            if (value <= 0) {
                state->unk2 &= ~2;
            }
        }
    }

    if (!(state->unk2 & 2)) {
        value += 2;

        if (value >= 16) {
            state->unk2 |= 2;
        }
    } else {
        value -= 2;

        if (value <= 0) {
            state->unk2 &= ~2;
        }
    }

    state->unk1 = value;

    for (i = 0; i < count; ++i) {
        int r;
        int g;
        int b;
        int color = (actor == NULL) ? object->unk12C[i] : actor->unk1424[i];

        if (color == 0) {
            continue;
        }

        r = color & 31;
        g = (color >> 5) & 31;
        b = (color >> 10) & 31;
        color &= 0x8000;

        if (value == 16) {
            r += 8;

            if (r > 31) {
                r = 31;
            }

            g += 18;

            if (g > 31) {
                g = 31;
            }

            b += 30;
        } else {
            r -= value / 2;

            if (r < 0) {
                r = 0;
            }

            g += value / 2;

            if (g > 31) {
                g = 31;
            }

            b += value;
        }

        if (b > 31) {
            b = 31;
        }

        if (actor == NULL) {
            object->unk14C[i] = color | (b << 10) | (g << 5) | r;
        } else {
            actor->unk16A4[i] = color | (b << 10) | (g << 5) | r;
        }
    }

    if (actor == NULL) {
        vs_main_loadClut(object->unk14C, 31, object->unkF * 16, count);
    } else {
        vs_main_loadClut(actor->unk16A4, actor->unk0.unkF + 22, 0, count);
    }
}

void func_800AB9A4(D_800F45E0_t* arg0)
{
    SVECTOR boneA;
    SVECTOR boneB;
    u_short* header;
    int count;
    u_short* reference;
    u_short* weaponReference;
    int mode;
    int clutOffset;
    D_800F45E0_t* object;
    int state;
    int distance;
    int angle;
    int i;
    int changed;
    int speed;
    int skip;
    int capped;
    signed char target;
    int value;
    u_short* colors;
    u_int flags;
    vs_battle_wepModels_t* weapon;

    if (arg0->unk9_0 < 6) {
        if (arg0->unkA_0) {
            distance = rsin(0x200);
            distance *= arg0->unk63C;
            distance /= ONE;
            func_800A70DC(arg0, distance);
            func_800A7524(arg0, &arg0->unk34);
            arg0->unk34 /= 2;
            arg0->unk38 /= 2;
            func_800AC690(arg0->unkF, (D_800F4538_t*)arg0);
            if (arg0->unkA_0 >= 4) {
                if (arg0->unkF != 0) {
                    func_800AD494(arg0, 0xAB, &header);
                    if (header != NULL) {
                        arg0->unk5AC_24 = 0;
                        func_800A0204(arg0->unkF, 0x47, 0, 8);
                        arg0->unk5AC_24 = 1;
                    }
                }
            }
        }
    }
    flags = *(u_int*)((char*)arg0 + 8);
    speed = vs_gametime_tickspeed / 2;
    skip = 0;
    if (flags & 0x80) {
        skip = 1;
        if (*(int*)((char*)arg0 + 0x5AC) & 0x08000000) {
            count = 160;
        } else {
            skip = 0;
            count = 16;
        }
        colors = arg0->unk1564 + skip;
        reference = arg0->unk1424 + skip;
    } else {
        object = arg0;
        count = 16;
        colors = (void*)((char*)arg0 + 0x14C);
        reference = (void*)((char*)arg0 + 0x12C);
        if (arg0->unk9_0 == 2) {
            speed *= 2;
        }
    }
    state = arg0->unk9_0;
    switch (state) {
    case 2:
        mode = 0;
    start_fade:
        changed = 0;
    fade:
        changed |= func_800AC168(colors, count - skip, speed, mode, reference);
        if (arg0->unk8_7) {
            for (i = 0; i < 2; ++i) {
                weapon = vs_battle_wepModels[arg0->unkF * 2 + i];
                if (weapon != NULL) {
                    weaponReference = weapon->unk440;
                    changed |= func_800AC168(weapon->unk500, weapon->nClutColors, speed,
                        mode, weaponReference);
                }
            }
        }
        if (arg0->unk9_0 == 3 && changed == 0) {
            arg0->unk54 = 0x404040;
            func_800AC168(colors, count - skip, speed, 2, reference);
            if (arg0->unk8_7) {
                for (i = 0; i < 2; ++i) {
                    weapon = vs_battle_wepModels[arg0->unkF * 2 + i];
                    if (weapon != NULL) {
                        weaponReference = weapon->unk440;
                        func_800AC168(weapon->unk500, weapon->nClutColors, speed, 2,
                            weaponReference);
                    }
                }
            }
        }
    load_cluts:
        if (arg0->unk8_7) {
            vs_main_loadClut(arg0->unk1564, arg0->unkF + 4, 0, count);
            for (i = 0, clutOffset = 160; i < 2; ++i, clutOffset += 48) {
                weapon = vs_battle_wepModels[arg0->unkF * 2 + i];
                if (weapon != NULL) {
                    weapon->unk9_0 = arg0->unk9_0;
                    vs_main_loadClut(
                        weapon->unk500, arg0->unkF + 4, clutOffset, weapon->nClutColors);
                }
            }
        } else {
            vs_main_loadClut(
                (u_short*)((char*)object + 0x14C), 31, object->unkF * 16, 16);
        }
        if (changed == 0) {
            ++arg0->unk9_0;
            if (arg0->unk8_7) {
                for (i = 0; i < 2; ++i) {
                    weapon = vs_battle_wepModels[arg0->unkF * 2 + i];
                    if (weapon != NULL) {
                        weapon->unk9_0 = arg0->unk9_0;
                    }
                }
            }
        }
    case 1:
    case 15:
    default:
        return;
    case 3:
        changed = 0;
        mode = 1;
        goto fade;
    case 4:
        if (*(int*)((char*)arg0 + 0x5AC) & 8) {
            object = D_800F45E0[arg0->unk13];
            func_800A190C(object->unk12, 0xF0, &boneA, 1);
            func_800A190C(object->unk12, 0xF1, &boneB, 1);
            object->unk1C = arg0->unk1C;
            object->unk20 = arg0->unk20;
            object->unk1E = (boneA.vy + boneB.vy) / 2 + 60;
            angle = (u_short)arg0->unk26;
            object->unk1A = 0xFC;
            *(int*)((char*)object + 0x34) = 0;
            object->unk12 = 0xFF;
            object->unk26 = (object->unk26 + angle) & 0xFFF;
            arg0->unk5AC_3 = 0;
            D_800F4B19 = arg0->unk13;
        }
        value = (u_char)arg0->unk54 - speed * 4;
        changed = 0;
        if (value < 0) {
            value = 0;
        }
        if (value != 0) {
            changed = 1;
        }
        *(u_char*)&arg0->unk54 = value;
        *((signed char*)arg0 + 0x55) = value;
        i = (signed char)arg0->unk6F2;
        i += speed * 2;
        *((signed char*)arg0 + 0x56) = value;
        if (i > 64) {
            i = 64;
        }
        if (i != 64) {
            changed = 1;
        }
        arg0->unk6F2 = i;
        goto load_cluts;
    case 6:
        mode = 3;
        value = *((u_char*)arg0 + 0x57);
        value += 1;
        capped = value & 0xFF;
        changed = capped < 15u;
        i = (signed char)arg0->unk6F2;
        i += speed * 2;
        capped = i < 65;
        *((u_char*)arg0 + 0x57) = value;
        if (capped == 0) {
            i = 64;
        }
        arg0->unk6F2 = i;
        goto fade;
    case 7:
        changed = 0;
        mode = 1;
        i = (signed char)arg0->unk6F2;
        i += speed * 2;
        capped = i < 65;
        if (capped == 0) {
            i = 64;
        }
        arg0->unk6F2 = i;
        goto fade;
    case 9:
        changed = 0;
        mode = 2;
        *(u_char*)&arg0->unk54 = 0xFF;
        *((u_char*)arg0 + 0x55) = 0xFF;
        *((u_char*)arg0 + 0x56) = 0xFF;
        goto fade;
    case 10:
        changed = 0;
        target = arg0->unk6F1;
        i = (signed char)arg0->unk6F2;
        i -= speed * 2;
        mode = 4;
        if (i < target) {
            i = target;
        }
        if (i != target) {
            changed = 1;
        }
        arg0->unk6F2 = i;
        changed |= func_800AC0D4(&arg0->unk54, &arg0->unk58, -speed * 8);
        goto fade;
    case 11:
        arg0->unk9_0 = 0;
        return;
    case 12:
        changed = 0;
        mode = 5;
        goto fade;
    case 14:
        arg0->unk6F2 = 64;
        mode = 6;
        goto start_fade;
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
    int i;
    int changed = 0;
    int baseR;
    int baseG;
    int baseB;
    int delta;

    for (i = 0; i < count; ++i, ++colors, ++reference) {
        int b = *colors;
        int r = b & 31;
        int g = (b >> 5) & 31;

        b = (b >> 10) & 31;

        switch (mode) {
        case 0:
            delta = amount * 2;
            r -= delta;

            if (r < 0) {
                r = 0;
            }

            g -= delta;

            if (g < 0) {
                g = 0;
            }

            r |= g << 5;

            if (r != 0) {
                changed = 1;
            }

            r |= b << 10;
            *colors = r | ~0x7FFF;
            break;

        case 1:
            delta = amount * 4;
        fade:
            b -= delta;

            if (b < 0) {
                b = 0;
            }

            r -= delta;

            if (r < 0) {
                r = 0;
            }

            g -= delta;

            if (g < 0) {
                g = 0;
            }

            r |= g << 5;
            r |= b << 10;

            if (r != 0) {
                changed = 1;
            }

            *colors = r | ~0x7FFF;
            break;

        case 2:
            *colors = 0xFFFF;
            break;

        case 3:
            r += amount;

            if (r >= 32) {
                r = 31;
            }

            g += amount * 2;

            if (g >= 32) {
                g = 31;
            }

            b += amount * 2;

            if (b >= 32) {
                b = 31;
            }

            r |= g << 5;
            r |= b << 10;
            *colors = r | ~0x7FFF;
            break;

        case 4:
            baseB = *reference;
            r -= amount * 2;
            baseR = baseB & 31;
            baseG = (baseB >> 5) & 31;
            baseB = (baseB >> 10) & 31;

            if (r < baseR) {
                r = baseR;
            }

            g -= amount * 2;

            if (g < baseG) {
                g = baseG;
            }

            b -= amount * 2;

            if (b < baseB) {
                b = baseB;
            }

            r |= g << 5;
            r |= b << 10;

            if (r != (*reference & 0x7FFF)) {
                changed = 1;
            }

            *colors = (*reference & 0x8000) | r;
            break;

        case 5:
            delta = amount;
            goto fade;

        case 6:
            *colors = 0x8000;
            break;
        }
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

static inline int func_800AC690_getProfile(D_800F4538_t* actor)
{
    u_int flags = *(u_int*)((char*)actor + 8);

    if (flags & 0xF00) {
        return 3;
    }
    if (flags & 0x400000) {
        return 4;
    }
    if (flags & 0x200000) {
        return 5;
    }
    if (actor->unk5AC_3) {
        return 6;
    }
    return actor->unk5B0_0 & 3;
}

void func_800AC690(int arg0, D_800F4538_t* actor)
{
    D_800F45E0_t* platform;
    SVECTOR* position;
    int profile;
    int state;
    int limit;
    int floor;
    int y;
    int ground;
    int top;
    int vy;
    int nextX;
    int nextZ;
    int hit;
    short speed;
    u_short velocity;
    signed char timer;
    u_int flags;

    profile = func_800AC690_getProfile(actor);
    flags = *(u_int*)((char*)actor + 8);
    state = (flags >> 16) & 7;

    switch (state) {
    case 2:
        if ((signed char)actor->unk0.unk11 > 0) {
            timer = actor->unk0.unk11 - vs_gametime_tickspeed / 2;
            actor->unk0.unk11 = timer;
            if (timer < 2) {
                func_800A0204(arg0, D_800E92E8[profile], 0, 8);
                actor->unk0.unk11 = 0;
            }
        } else {
            if (actor->unk181A == 0) {
                actor->unk0.unk34.vy = -30;
            }
            actor->unk5B7 = 0;
            actor->unk0.unkA_0 = 3;
            if (actor->unk0.unkC_0) {
                func_8008C49C(actor->unk0.unkC_0 - 2, -1);
                actor->unk0.unkC_0 = 0;
            }
        }
        break;
    case 3:
        if ((signed char)actor->unk0.unk11 > 0) {
            timer = actor->unk0.unk11 - vs_gametime_tickspeed / 2;
            actor->unk0.unk11 = timer;
            if (timer > 0) {
                break;
            }
            func_800A0204(actor->unk0.unkF, 0x2F, 0, 8);
            actor->unk0.unk11 = 0;
        }
        if (actor->unk0.unkA_6) {
            y = vs_gametime_tickspeed / 2;
            ((func_800AC690_timer_t*)&actor->unk5B4)->timer += y;
            limit = 7;
            y = ((func_800AC690_timer_t*)&actor->unk5B4)->timer >> 1;
            ((func_800AC690_timer_t*)&actor->unk5B4)->timer -= y * 2;
        } else {
            limit = 9;
            y = (vs_gametime_tickspeed / 2) * state;
        }
        velocity = actor->unk0.unk34.vy + y;
        actor->unk0.unk34.vy = velocity;
        if ((short)velocity < 0) {
            y = 1;
            floor = func_8008DD0C(actor->unk0.position.vx, actor->unk0.position.vz);
            floor <<= 17;
            floor >>= 17;
            if (arg0 != 0) {
                y = 3;
                D_800F4B00 = actor->menuCameraHeightOffset + 0x40;
            }
            ground = func_800A9378(actor->unk0.position.vx, actor->unk0.position.vy,
                actor->unk0.position.vz, y);
            if (ground != 0 && floor < ground) {
                floor = ground;
            }
            top = actor->unk0.position.vy + actor->unk0.unk34.vy - 0xC0;
            if (top < floor) {
                actor->unk0.unk34.vy = -actor->unk0.unk34.vy;
                if (arg0 != 0) {
                    actor->unk0.unk34.vx = 0;
                    actor->unk0.unk34.vz = 0;
                    actor->unk181A = 0;
                    func_800E4C28(
                        ((u_char*)&actor->unk5EC)[0], ((u_char*)&actor->unk5EC)[2]);
                }
            }
        }
        y = actor->unk0.unk34.vy;
        if (y <= limit) {
            if (y >= -limit) {
                func_800A0204(arg0, D_800E92F0[profile], 0, 16);
            }
        } else {
            func_800A0204(arg0, D_800E92F8[profile], 0, 8);
        }
        switch (actor->unk181A) {
        case 0:
            if (actor->unk0.unk34.vy < 0) {
                goto fall;
            }
            break;
        case 1:
        slide:
            speed = actor->unk0.unk34.vx;
            if (speed != 0) {
                nextX = actor->unk0.position.vx + speed;
                if (speed > 0) {
                    hit = actor->unk1814 < nextX;
                } else {
                    hit = nextX < actor->unk1814;
                }
                if (hit) {
                    actor->unk0.unk34.vx = 0;
                }
            }
            speed = actor->unk0.unk34.vz;
            if (speed != 0) {
                nextZ = actor->unk0.position.vz + speed;
                if (speed > 0) {
                    hit = actor->unk1818 < nextZ;
                } else {
                    hit = nextZ < actor->unk1818;
                }
                if (hit) {
                    actor->unk0.unk34.vz = 0;
                }
            }
            break;
        case 2:
            vy = actor->unk0.unk34.vy;
            --actor->unk1816;
            if (vy < 0) {
                goto fall;
            }
            y = func_800A9378(actor->unk0.position.vx + actor->unk0.unk34.vx,
                actor->unk0.position.vy + vy,
                actor->unk0.position.vz + actor->unk0.unk34.vz, 2);
            if (D_800F49F4 != 0 && D_800F49F4 != ((u_char*)&actor->unk5EC)[1]) {
                actor->unk6E4 = D_800F49F4;
                actor->unk0.currentTileX = actor->unk0.position.vx / 128;
                actor->unk0.currentTileZ = actor->unk0.position.vz / 128;
                actor->unk0.unk5D = 0;
                func_8008C49C(D_800F49F4 - 2, arg0);
                func_8008C49C(D_800F49F4 - 2, -1);
                D_800F49F4 = 0;
                func_800E6764(arg0);
                goto land;
            }
            if (actor->unk1816 > 0) {
                goto fall;
            }
            goto slide;
        default:
            break;
        }
        position = &actor->unk0.position;
        y = func_800A6EE8(position, actor->unk0.unk34.vx, actor->unk0.unk34.vz, 1);
        if (y == 3000 && D_800E9278[*D_800F49F0 & 0x1F] == 20) {
            if (actor->unk0.position.vy <= 0
                && actor->unk0.position.vy + actor->unk0.unk34.vy >= 0) {
                func_8006F450(position);
            }
        }
        top = actor->unk0.position.vy + actor->unk0.unk34.vy;
        if (top < y) {
            goto fall;
        }
        if (D_800F49F4 != 0) {
            if (y - top < -0x80) {
                actor->unk0.unk34.vx = 0;
                actor->unk0.unk34.vz = 0;
                goto fall;
            }
        }
    land:
        if (D_800F49F8 != 0) {
            platform = D_800F45E0[D_800F49F8];
            if (platform->unk1A != 0) {
                actor->unk0.position.vy = platform->unk1E - 0x80;
                break;
            }
        }
        *(short*)&actor->unk6EE = 0;
        actor->unk0.unkC_0 = D_800F49F4;
        actor->unk0.unk5D = D_800F49F4;
        actor->unk5AC_28 = D_800F49F8;
        actor->unk0.unk34.vy = y - actor->unk0.position.vy;
        actor->unk0.unkA_0 = 4;
        func_800AA698(arg0, &actor->unk0.unk34, 0);
        floor = actor->unk0.position.vy - ((SVECTOR*)&actor->unk0.unk4C)->vy;
        floor /= 64;
        actor->unk0.unk11 = 0;
        if (y < 3000) {
            if (actor->unk0.unkF != 0 || !actor->unk0.unk9_0 || actor->unk0.unk9_0 >= 6) {
                if (floor >= 4) {
                    func_800AE828(arg0, actor, 0x42);
                    if (floor >= 6 && arg0 == 0) {
                        actor->unk0.unk11 = 8;
                    }
                } else {
                    func_800AE828(arg0, actor, 0x41);
                }
            }
        }
        actor->unk181A = 0;
        actor->unk5AC_26 = 0;
        func_800A0204(arg0, D_800E9300[profile], 0, 8);
        break;
    fall:
        func_800AA698(arg0, &actor->unk0.unk34, 0);
        break;
    case 4:
        if (flags & 0x200000) {
            actor->unk0.unkA_5 = 0;
            actor->unk0.unkA_6 = 0;
        }
        func_800ACF54(actor);
        actor->unk0.unk11 -= vs_gametime_tickspeed / 2;
        if ((signed char)actor->unk0.unk11 < 0) {
            actor->unk0.unk11 = 0;
        }
        if ((signed char)actor->unk0.unk11 == 0) {
            actor->unk6EC = 0;
            if (actor->unk0.unkF != 0) {
                if (!actor->unk0.unkA_6 && actor->unk5CC != 0) {
                    break;
                }
                if (profile != 3) {
                    func_800A0204(arg0, 1, 0, 8);
                }
                func_800E4C28(actor->unk0.currentTileX, actor->unk0.currentTileZ);
                func_800E6EB0(actor->unk0.unkF);
            }
            actor->unk1846 = 0;
            actor->unk0.unkA_0 = 0;
        }
        break;
    }
}

void func_800ACF54(D_800F4538_t* actor)
{
    *(int*)&actor->unk0.lastTouchedTileX = *(int*)&actor->unk0.currentTileX;
    *(func_800ACF54_t*)&actor->unk0.unk4C = *(func_800ACF54_t*)&actor->unk0.position;

    if (!actor->unk0.unkC_0) {
        actor->unk1868 = *(int*)&actor->unk0.currentTileX;
    }

    actor->unk0.unk52 = actor->unk0.facing;
}

inline void func_800ACFA0(SVECTOR* arg0, u_char* arg1, int arg2)
{
    int a3;
    a3 = arg1[0];
    a3 <<= 8;
    a3 |= arg1[1];
    a3 *= 2;
    arg0->vx = a3;

    a3 = arg1[2];
    a3 <<= 8;
    a3 |= arg1[3];
    a3 *= 2;
    arg0->vy = a3;

    a3 = arg1[4];
    a3 <<= 8;
    a3 |= arg1[5];
    a3 *= 2;
    arg0->vz = a3;

    arg0->pad = 6;

    if (arg2 != 0xFF) {
        arg0->pad = 0;
    }

    arg0 += 84;
    arg0->pad = 0;
}

void func_800AD008(D_800F4538_t* actor, D_800F4538_unkC54* pose)
{
    u_short* header;
    func_800AD494_t* anim;
    u_char* data;
    SVECTOR* key;
    int frame;
    int i;

    if (*(int*)((u_char*)actor + 0x5AC) & 0x800000) {
        func_800AE47C(actor);
    }
    actor->unk5AC_23 = 0;
    pose->unk540 = 0;
    pose->unk549 = 0;
    *(int*)&pose->unk150[41].vx = 0;
    *(int*)&pose->unk150[41].vz = 0;
    pose->unk3F0[41].pad = 0;

    anim = (func_800AD494_t*)func_800AD494(actor, actor->animationId, &header);
    if (anim == NULL) {
        return;
    }
    if (header[2] == 0) {
        pose->unk542 = 0xFFFF;
    } else {
        data = anim->unk0;
        data += header[2];
        i = data[0];
        if (i == 0xFF) {
            i = data[1] + 0xFF;
            data += 2;
        } else {
            data += 1;
        }
        pose->unk542 = i;
        pose->unk544 = data;
    }
    pose->unk548_16 = 0;
    pose->animationId = actor->animationId;
    if (header[4] != 0) {
        key = &pose->unk150[41];
        data = anim->unk0;
        data += header[4];
        func_800ACFA0(key, data, 0xFF);
    }
    frame = ((u_char*)header)[2];
    if (frame != 0xFF) {
        header = (u_short*)((u_char*)anim + ((actor->unk0.nBones * 4 + 10) * frame + 8));
    }
    key = &pose->unk0[41];
    data = anim->unk0;
    data += header[3];
    func_800ACFA0(key, data, frame);
    for (i = 0; i < actor->unk0.nBones; ++i) {
        key = &pose->unk0[i];
        data = anim->unk0;
        data += header[5 + i];
        func_800ACFA0(key, data, frame);
    }
    if (((u_char*)header)[3] & 1) {
        for (i = 0; i < actor->unk0.nBones; ++i) {
            data = anim->unk0;
            data += header[actor->unk0.nBones + i + 5];
            if (data[0] == 0xFE && data[1] == 1) {
                data += 2;
                key = &pose->unk150[i];
                func_800ACFA0(key, data, frame);
                pose->unk150[i].pad = 0;
                pose->unk150[i].vx >>= 1;
                pose->unk150[i].vy >>= 1;
                pose->unk150[i].vz >>= 1;
                if (frame == 0xFF) {
                    pose->unk150[i].pad = 8;
                }
            } else {
                pose->unk150[i].vx = data[0];
                pose->unk150[i].vy = data[1];
                pose->unk150[i].vz = data[2];
                pose->unk150[i].pad = 0;
                if (frame == 0xFF) {
                    pose->unk150[i].pad = 3;
                }
            }
            pose->unk3F0[i].pad = 0;
        }
    } else {
        for (i = 0; i < actor->unk0.nBones; ++i) {
            *(int*)&pose->unk150[i].vx = 0x400040;
            *(int*)&pose->unk150[i].vz = 0x40;
            pose->unk150[i].pad = 0;
            pose->unk3F0[i].pad = 0;
        }
    }
}

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
