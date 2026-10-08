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
    short unk0;
    short unk2;
    short unk4;
    short unk6;
} func_8008D2C0_t;

void func_8007A824(DR_MOVE*);
int func_8008D2C0(func_8008D2C0_t*);
void func_800A0204(int, int, int, int);
void func_800A1280(int, int, SVECTOR*, int);
void func_800A1720(int, int, void*, int*);
int func_800A6EE8(SVECTOR*, int, int, int);
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
extern short D_800F4B00;

#define getActorFlags(actor) (*((int*)&(actor)->unk5B4 - 2))

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

        radius = other->unk640;

        if (other->unk0.position.vx + radius < position->vx
            || position->vx < other->unk0.position.vx - radius
            || other->unk0.position.vz + radius < position->vz
            || position->vz < other->unk0.position.vz - radius
            || other->unk0.position.vy < actor->unk0.position.vy - actor->unk642
            || actor->unk0.position.vy < other->unk0.position.vy - other->unk642) {
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

    radius = actor->unk640;
    minY = actor->unk0.position.vy - actor->unk642;
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
            otherRadius = other->unk640;

            if (!(other->unk0.position.vx + otherRadius < minX
                    || maxX < other->unk0.position.vx - otherRadius
                    || other->unk0.position.vz + otherRadius < minZ
                    || maxZ < other->unk0.position.vz - otherRadius
                    || other->unk0.position.vy < minY
                    || actor->unk0.position.vy
                           < other->unk0.position.vy - other->unk642)) {
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
        if ((arg0 >= sp10[i].unk0 + 64) || (arg0 < sp10[i].unk0 - 64)) {
            continue;
        }

        if ((arg2 >= sp10[i].unk4 + 64) || (arg2 < sp10[i].unk4 - 64)) {
            continue;
        }

        switch (arg3) {
        case 0:
            if (sp10[i].unk2 < arg1 - 256) {
                continue;
            }
            break;

        case 1:
            if (sp10[i].unk2 < arg1 - 256) {
                return sp10[i].unk2 + 96;
            }
            continue;

        case 2:
            if ((sp10[i].unk2 >= arg1) || (sp10[i].unk2 < arg1 - 128)) {
                continue;
            }
            break;

        case 3:
            if ((sp10[i].unk2 >= arg1) || (sp10[i].unk2 < arg1 - D_800F4B00)) {
                continue;
            }
            return sp10[i].unk2 + 96;
        }

        D_800F49F4 = sp10[i].unk6 + 2;
        return sp10[i].unk2;
    }

    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/40564", func_800A9530);

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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/40564", func_800A9988);

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
INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/40564", func_800AAD4C);

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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/40564", func_800AB358);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/40564", func_800AB4F0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/40564", func_800AB788);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/40564", func_800AB9A4);

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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/40564", func_800AC168);

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
