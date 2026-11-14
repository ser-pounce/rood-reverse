#include "common.h"
#include "6E4CCShared.h"
#include <abs.h>

#ifdef NON_MATCHING

int func_800D954C(func_800E78F4_t* arg0, vs_TilePosition arg1)
{
    int x;
    int z;
    int y;
    int px;
    int pz;
    Actor* actor;

    if (arg0->unk38.x == arg1.x && arg0->unk38.surface == 0 && arg0->unk38.z == arg1.z) {
        return 0;
    }

    x = arg1.x;
    z = arg1.z;
    y = func_800E42EC(x, z);
    px = x * 128 + 64;
    pz = z * 128 + 64;

    if (x >= ((u_char*)0x1F8003DC)[0] || z >= ((u_char*)0x1F8003DC)[1]) {
        return 0;
    }

    if ((*(u_short(**)[32])0x1F8003C0)[z][x] & ((arg0->unk32 << 8) | 0x80B0)) {
        return 0;
    }

    for (actor = vs_battle_actors[0]; actor != NULL; actor = actor->next) {
        func_800E78F4_t* other;
        D_800F4538_t* model;
        SVECTOR* position;
        int dx;
        int dy;
        int dz;
        int radius;

        if (actor->id == arg0->unk88) {
            continue;
        }

        model = D_800F4538[actor->id];
        other = ((func_800E78F4_t**)0x1F80037C)[actor->id];

        if (actor->id == 0 || (model->unk0.unkA_0 == 0 && model->unk0.unkA_3 == 0)) {
            position = &model->unk0.position;
        } else {
            position = &other->unk174;
        }

        // The original zero-extends vx and vz here (vy is signed), probably a bug so they
        // are signed here.
        dx = position->vx - px;
        dy = position->vy - y;
        dz = position->vz - pz;
        radius = other->unk94 + arg0->unk94;

        if (ABS(dx) <= radius && ABS(dy) <= 128 && ABS(dz) <= radius) {
            return -1;
        }
    }

    return 1;
}

int func_800D96C8(
    func_800E78F4_t* arg0, vs_TilePosition arg1, vs_TilePosition arg2, int arg3)
{
    int x;
    int z;
    int tile;
    int dx;
    int dz;
    int from;
    int climb;
    int limit;
    short leftover;
    int adjacent;

    if (arg0->unk7 != 0) {
        return 0;
    }

    x = arg2.x;
    z = arg2.z;

    if (x >= ((u_char*)0x1F8003DC)[0] || z >= ((u_char*)0x1F8003DC)[1]) {
        return 0;
    }

    tile = (*(u_short(**)[32])0x1F8003C0)[z][x];

    if (tile & 0x30) {
        return 0;
    }

    // Potential bug in original, needs investigating.
    // The test against unk154[0] branches to the next instruction, so only unk132[0]
    // counts.
    if (arg0->unk2 == 0 && (tile & 0xF) != arg0->unk132[0]) {
        return 0;
    }

    dx = x - arg1.x;
    dz = z - arg1.z;
    from = func_800E42EC(arg1.x, arg1.z);
    climb = func_800E42EC(x, z) - from;
    leftover = (*(u_short(**)[32])0x1F8003BC)[z][x] << 6;

    // Potential bug in original, needs investigating.
    // When dx is negative the original negates dz instead, so dx keeps its sign.
    dz = ABS(dz);

    adjacent = dx < 2 && dz < 2;

    if (adjacent) {
        if (!((((D_1F8003D0_t*)0x1F8003D0)->unk2 >> arg3) & 1)) {
            leftover = 1 << arg3;
        }
        if (func_800D98E8(arg0, arg3) != 0) {
            return 0;
        }
    }

    if (!adjacent || arg0->unk3 != 0 || climb < 1) {
        if (arg0->unkB2 < dx + dz) {
            return 0;
        }

        limit = (arg0->unk15E & 0xF8) ? 0x2000 : arg0->unkB0;

        if ((limit < climb) & arg0->unk3) {
            return 0;
        }
        if (climb < -limit) {
            return 0;
        }
    }

    if (arg0->unk5 == 0) {
        return 1;
    }

    if (arg0->unk89 == 1) {
        int reach = arg0->unkDC - 96;
        u_short(*halves)[2] = (void*)D_800F4538;
        int distance;

        // Potential bug in original, needs investigating.
        // The point is read from the D_800F4538 pointer array, not from the model an
        // entry points to, and the third argument is whatever the last call left in its
        // register.
        distance = func_800E4660(x * 128 + 64 - halves[arg0->unkE5 + 7][0],
            z * 128 + 64 - halves[arg0->unkE5 + 8][0], leftover);

        if (distance < reach * reach) {
            return -1;
        }
    }

    return func_800E45F4(arg2, arg0->unk168) < func_800E45F4(arg0->unk34, arg0->unk168);
}

int func_800D98E8(func_800E78F4_t* arg0, int arg1)
{
    D_800F16EC_t step;
    int x;
    int y;
    int z;
    int dir;
    int blocked;
    int result;
    Actor* actor;

    if ((((D_1F8003D0_t*)0x1F8003D0)->unk2 >> arg1) & 1) {
        return ((D_1F8003D0_t*)0x1F8003D0)->unk4[arg1];
    }

    step = ((D_800F16EC_t*)0x1F8003EC)[arg1];

    // The original zero-extends vx and vz here and shifts them unsigned, probably a bug
    // so they are signed here.
    x = arg0->unk4C.vx + arg0->unkB3 * step.dx;
    z = arg0->unk4C.vz + arg0->unkB3 * step.dz;
    dir = ((signed char (*)[4])0x1F8003E0)[(z >> 7) - arg0->unk34.z + 1]
                                          [(x >> 7) - arg0->unk34.x + 1];

    if (dir < 0) {
        blocked = 1;
    } else if (*(u_int**)0x1F8003F4 != NULL) {
        blocked = ((*(u_char**)0x1F8003C4)[arg0->unk34.z * ((u_char*)0x1F8003DC)[0]
                                           + arg0->unk34.x]
                      >> dir)
                & 1;
    } else {
        blocked = func_800E4690(arg0->unk34, dir);
    }

    y = blocked ? arg0->unk4C.vy : func_800E42D4(x, z);
    result = 0;

    for (actor = vs_battle_actors[0]; actor != NULL; actor = actor->next) {
        func_800E78F4_t* other;
        D_800F4538_t* model;
        SVECTOR* position;
        int dx;
        int dy;
        int dz;
        int radius;

        if (actor->id == arg0->unk88) {
            continue;
        }

        model = D_800F4538[actor->id];
        other = ((func_800E78F4_t**)0x1F80037C)[actor->id];

        if (actor->id == 0 || (model->unk0.unkA_0 == 0 && model->unk0.unkA_3 == 0)) {
            position = &model->unk0.position;
        } else {
            position = &other->unk174;
        }

        dx = position->vx - x;
        dy = position->vy - y;
        dz = position->vz - z;

        if ((step.dx > 0 && dx < 0) || (step.dx < 0 && dx > 0) || (step.dz > 0 && dz < 0)
            || (step.dz < 0 && dz > 0)) {
            continue;
        }

        radius = other->unk94 + other->unkB3 + arg0->unk94;

        if (ABS(dx) <= radius && ABS(dz) <= radius
            && ABS(dy) <= (arg0->unkB8 + other->unkB8) >> 1) {
            result = actor->id + 1;
            break;
        }
    }

    ((D_1F8003D0_t*)0x1F8003D0)->unk4[arg1] = result;
    ((D_1F8003D0_t*)0x1F8003D0)->unk2 |= 1 << arg1;
    return result;
}

int func_800D9B6C(func_800E78F4_t* arg0, int arg1)
{
    D_800F16EC_t step;
    int x;
    int z;
    int nx;
    int nz;
    int dir;
    int tile;
    int cell;
    int blocked;

    if ((((D_1F8003D0_t*)0x1F8003D0)->unk0 >> arg1) & 1) {
        return (((D_1F8003D0_t*)0x1F8003D0)->unk1 >> arg1) & 1;
    }

    blocked = func_800D98E8(arg0, arg1);

    if (!blocked) {
        step = ((D_800F16EC_t*)0x1F8003EC)[arg1];
        x = arg0->unk34.x;
        z = arg0->unk34.z;
        nx = arg0->unk120 & 0xFF;
        nz = (arg0->unk120 >> 16) & 0xFF;
        nx = (nx + step.dx) >> 1;
        nz = (nz + step.dz) >> 1;

        if (nx != x || nz != z) {
            dir = arg1;

            if (arg1 & 1) {
                dir = ((signed char (*)[4])0x1F8003E0)[nz - z + 1][nx - x + 1];
            }

            if (*(u_int**)0x1F8003F4 == NULL) {
                blocked = func_800E4690(arg0->unk34, dir);
            } else if (arg0->unk38.x == nx && arg0->unk38.z == nz) {
                blocked = 1;
            } else {
                blocked =
                    ((*(u_char**)0x1F8003C4)[z * ((u_char*)0x1F8003DC)[0] + x] >> dir)
                    & 1;
            }

            if (!blocked) {
                tile = (*(u_short(**)[32])0x1F8003C0)[nz][nx];
                cell = tile & 0xF;

                if (((tile >> 4) & (arg0->unk6 ^ 1)) || (tile & 0xA0)
                    || (arg0->unk32 & (tile >> 8))) {
                    blocked = 1;
                } else if ((arg0->unk29 & (arg0->unk2 ^ 1))
                           && ((*(u_short(**)[32])0x1F8003C0)[z][x] & 0xF) != cell
                           && (arg0->unk154[0] & 0xF) != cell) {
                    blocked = 1;
                } else {
                    blocked = ((*(u_short(**)[32])0x1F8003BC)[z][x] & 0x1C00)
                            < ((*(u_short(**)[32])0x1F8003BC)[nz][nx] & 0x1C00);
                }
            }
        }
    }

    ((D_1F8003D0_t*)0x1F8003D0)->unk0 |= 1 << arg1;

    if (blocked) {
        ((D_1F8003D0_t*)0x1F8003D0)->unk1 &= ~(1 << arg1);
    } else {
        ((D_1F8003D0_t*)0x1F8003D0)->unk1 |= 1 << arg1;
    }

    return (((D_1F8003D0_t*)0x1F8003D0)->unk1 >> arg1) & 1;
}

void func_800D9DD8(func_800E78F4_t* arg0)
{
    if (arg0->unk68 != func_800DAA6C
        && (*(u_int*)&arg0->unk430[0]->unk10 & arg0->unk2D)) {
        arg0->unk12E = 2;
        func_800DD7CC(arg0, &arg0->unk134);
        return;
    }

    arg0->unk12E = 1;
}

#endif
