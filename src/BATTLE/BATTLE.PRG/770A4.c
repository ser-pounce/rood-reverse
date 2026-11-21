#include "common.h"
#include "6E4CCPrivate.h"
#include "6E4CCShared.h"
#include "146CPrivate.h"
#include "4DEA8.h"
#include "battleUnk.h"
#include "src/SLUS_010.40/32154.h"
#include "src/SLUS_010.40/overlay.h"
#include "build/src/include/lbas.h"
#include "scratch.h"
#include "tilePosition.h"
#include <abs.h>
#include <rand.h>

typedef struct {
    u_short z : 5;
    u_short x : 5;
    u_short unk0_10 : 1;
    u_short direction : 2;
    u_short distance : 2;
    u_short unk0_15 : 1;
} Route;

extern u_char D_800F175C[];

int func_800DFAF8(func_800E78F4_t* arg0, vs_TilePosition arg1, int arg2);
void func_800E1238(func_800E78F4_t*, int);

void func_800DF8A4(func_800E78F4_t* arg0)
{
    vs_TilePosition pos;
    int i;

    if (arg0->unk34.surface < 2) {
        vs_TilePosition none = { 0xFF, 0xFF, 0xFF, 0xFF };

        arg0->unk19C = none;
        func_800E4BD8(arg0->unk19B);
        arg0->unk19B = 0;
        return;
    }

    i = func_800DFAF8(arg0, arg0->unk19C, 0);

    if (i >= 0) {
        pos.x = D_800F5910[i * 2].unk0_0;
        pos.z = D_800F5910[i * 2].unk0_5;
        pos.surface = 0;

        if (func_800D954C(arg0, pos) > 0) {
            vs_TilePosition none = { 0xFF, 0xFF, 0xFF, 0xFF };

            arg0->unk19C = none;
            arg0->unk19B = 0;
            func_800E4BD8((i >> 1) + 2);
            arg0->unk170 = pos;
            func_800DEEFC(arg0, 0xE);
            return;
        }
    }

    func_800E2CCC(arg0);

    // HACK: Bogus return to force match.
    return (void)&pos;
}

void func_800DF9A8(vs_TilePosition* arg0, vs_TilePosition* arg1)
{
    int i;

    for (i = 0; i < 8; i++) {
        if (D_800F5910[i * 2].unk0_0 == arg0->x && D_800F5910[i * 2].unk0_5 == arg0->z) {
            if (i & 1) {
                i--;
            } else {
                i++;
            }
            arg1->x = D_800F5910[i * 2 + 1].unk0_0;
            arg1->z = D_800F5910[i * 2 + 1].unk0_5;
            arg1->surface = i >> 1;
            return;
        }
    }
    *arg1 = *arg0;
}

void func_800DFA54(int arg0, int arg1, int arg2, vs_TilePosition* arg3)
{
    int i;

    arg1 >>= 19;
    arg2 >>= 19;
    for (i = arg0 * 2; i < arg0 * 2 + 2; i++) {
        if (arg1 == D_800F5910[i * 2 + 1].unk0_0
            && arg2 == D_800F5910[i * 2 + 1].unk0_5) {
            goto found;
        }
    }
    i = arg0 * 2;
found:
    arg3->x = D_800F5910[i * 2].unk0_0;
    arg3->z = D_800F5910[i * 2].unk0_5;
}

int func_800DFAF8(UNUSED func_800E78F4_t* arg0, vs_TilePosition arg1, int arg2)
{
    SVECTOR sp10[4];
    SVECTOR* m;
    int i;
    int j;

    func_8008D2C0(sp10);
    for (i = 0; i < 8; ++i) {
        D_800F5910_t* e = &D_800F5910[i * 2];
        j = i >> 1;
        if (arg2 == 0) {
            ++e;
        }
        if (arg1.x == e->unk0_0 && arg1.z == e->unk0_5) {
            m = &sp10[j];
            if (D_800F5910[i * 2 + 1].unk0_0 == m->vx >> 7
                && D_800F5910[i * 2 + 1].unk0_5 == m->vz >> 7) {
                return i;
            }
        }
    }
    return -1;
}

int func_800DFBCC(func_800E78F4_t* arg0, int index, int area)
{
    typedef union {
        Route r[2];
        u_int raw;
    } RoutePair;

    Route routes[2];
    int distances[2];
    vs_TilePosition position;
    int count;
    int i;
    int x;
    Route route;
    RoutePair* pair;

    position = arg0->unk34;
    pair = (RoutePair*)routes;
    pair->raw = (*VS_SCRATCH_AT(u_int**, 0x3F4))[area * 16 + index];

    if ((pair->r[0].x == 0) && (pair->r[0].direction == 0)) {
        return 6;
    }

    arg0->unk154[0] = area;
    count = 1;

    if ((pair->r[1].x != 0) || (pair->r[1].direction != 0)) {
        count = 2;
    }

    for (i = 0; i < count; ++i) {
        vs_TilePosition candidate;
        int result;

        route = (i == 0) ? routes[0] : routes[1];

        if ((route.x != position.x) || (route.z != position.z)) {
            continue;
        }

        candidate = position;

        if (route.unk0_10) {
            int slot;

            if (route.unk0_15) {
                continue;
            }

            result = func_800DFAF8(arg0, position, 1);

            if ((result >= 0) && (func_8008E320(slot = result >> 1) >= 0)) {
                candidate.surface = slot + 2;

                if (!((D_800F58BC->unkE >> candidate.surface) & 1)) {
                    arg0->unk19B = candidate.surface;

                    if (arg0->unk88) {
                        func_800E4BE0(candidate.surface);
                    }

                    func_800DF9A8(&candidate, &arg0->unk19C);
                    arg0->unk170 = candidate;
                    return 14;
                }
            }

            candidate.x = route.x;
            candidate.z = route.z;
        } else if (route.distance) {
            int amount;
            u_char* step;

            arg0->unk154[0] =
                (*VS_SCRATCH_AT(u_short(**)[32], 0x3C0))[candidate.z][candidate.x] % 16;
            arg0->unk5 = 0;
            amount = route.distance + 1;
            step = &D_800F175C[route.direction];
            candidate.x += amount * VS_SCRATCH_AT(D_800F16EC_t*, 0x3EC)[*step].dx;
            candidate.z += amount * VS_SCRATCH_AT(D_800F16EC_t*, 0x3EC)[*step].dz;
            result = func_800D954C(arg0, candidate);

            if (result < 0) {
            center:
                if ((arg0->unk15C != 16)
                    && VS_SCRATCH_AT(func_800E78F4_t**, 0x37C)[arg0->unk15C]) {
                    arg0->unk17C =
                        VS_SCRATCH_AT(func_800E78F4_t**, 0x37C)[arg0->unk15C]->unk60->vx;
                    arg0->unk180 =
                        VS_SCRATCH_AT(func_800E78F4_t**, 0x37C)[arg0->unk15C]->unk60->vz;
                } else {
                    arg0->unk17C = candidate.x * 128 + 64;
                    arg0->unk180 = candidate.z * 128 + 64;
                }

                arg0->unk18A =
                    ratan2(arg0->unk4C.vx - arg0->unk17C, arg0->unk4C.vz - arg0->unk180)
                    & 0xFFF;
                arg0->unk13A = arg0->unk13C;
                return 4;
            }

            if (result <= 0) {
                continue;
            }

        stop:
            candidate.surface = 0;
            arg0->unk170 = candidate;
            return 14;
        } else {
            u_char* table = D_800F175C;
            u_char* direction = &table[route.direction];

            candidate.x += VS_SCRATCH_AT(D_800F16EC_t*, 0x3EC)[*direction].dx;
            candidate.z += VS_SCRATCH_AT(D_800F16EC_t*, 0x3EC)[*direction].dz;

            if (func_800D954C(arg0, candidate) > 0) {
                if (((*VS_SCRATCH_AT(u_short(**)[32], 0x3BC))[candidate.z][candidate.x]
                        & 0x1C00)
                    || (((*VS_SCRATCH_AT(
                             u_char**, 0x3C4))[position.z * *VS_SCRATCH_AT(u_char*, 0x3DC)
                                               + position.x]
                            >> *direction)
                        & 1)) {
                    goto stop;
                }

                arg0->unk188 = *direction;
                return 5;
            }
        }

        goto center;
    }

    pair = (RoutePair*)routes;

    if (pair->r[0].unk0_10 && pair->r[0].unk0_15) {
        if (count == 1) {
        areaOnly:
            arg0->unk154[0] =
                (*VS_SCRATCH_AT(u_short(**)[32], 0x3C0))[position.z][position.x] % 16;
            return 6;
        }

        if (pair->r[1].unk0_10 && pair->r[1].unk0_15) {
            goto areaOnly;
        }

        goto second;
    }

    if (pair->r[1].unk0_10 && pair->r[1].unk0_15) {
        goto first;
    }

    for (i = 0; i < count; ++i) {
        route = (i == 0) ? routes[0] : routes[1];

        if (!((*VS_SCRATCH_AT(u_short(**)[32], 0x3BC))[route.z][route.x] & 0x1C00)) {
            continue;
        }

        route = (i != 0) ? routes[0] : routes[1];

        if (((*VS_SCRATCH_AT(u_short(**)[32], 0x3BC))[route.z][route.x] & 0x1C00)
            || (count == 1)) {
            arg0->unk154[0] =
                (*VS_SCRATCH_AT(u_short(**)[32], 0x3C0))[position.z][position.x] % 16;
            return 6;
        }

        *(u_int*)&arg0->unk168 = (route.z << 16) | route.x;
        return 6;
    }

    x = position.x;

    if (count == 1) {
        *(u_int*)&arg0->unk168 = (routes[0].z << 16) | routes[0].x;
        if ((arg0->unk168.x != arg0->unk34.x) || (arg0->unk168.z != arg0->unk34.z)) {
            return 6;
        }
    } else {
        int z = position.z;

        distances[0] =
            (x - routes[0].x) * (x - routes[0].x) + (z - routes[0].z) * (z - routes[0].z);
        x -= routes[1].x;
        z -= routes[1].z;
        distances[1] = x * x + z * z;

        if (distances[0] < distances[1]) {
        first:
            *(u_int*)&arg0->unk168 = (routes[0].z << 16) | routes[0].x;
        } else {
        second:
            *(u_int*)&arg0->unk168 = (routes[1].z << 16) | routes[1].x;
        }

        if ((arg0->unk168.x != arg0->unk34.x) || (arg0->unk168.z != arg0->unk34.z)) {
            return 6;
        }
    }

    goto center;
}

int func_800E02B4(func_800E78F4_t* arg0, int arg1, int arg2)
{
    SVECTOR points[4];
    int x;
    int y;
    int z;
    int i;
    int dx;
    int dy;
    int dz;
    u_int radius;
    u_int height;
    Actor* actor;

    if ((VS_SCRATCH_AT(D_1F8003D0_t*, 0x3D0)->unk2 >> arg1) & 1) {
        return VS_SCRATCH_AT(D_1F8003D0_t*, 0x3D0)->unk4[arg1];
    }

    x = arg0->unk4C.vx
      + arg2 * (arg0->unkB3 * VS_SCRATCH_AT(D_800F16EC_t*, 0x3EC)[arg1].dx);
    y = arg0->unk4C.vy;
    z = arg0->unk4C.vz
      + arg2 * (arg0->unkB3 * VS_SCRATCH_AT(D_800F16EC_t*, 0x3EC)[arg1].dz);

    for (i = func_8008D2C0(points) - 1; i != -1; --i) {
        dx = points[i].vx - x;
        dy = points[i].vy - y;
        dz = points[i].vz - z;

        if (arg2
            && ((VS_SCRATCH_AT(D_800F16EC_t*, 0x3EC)[arg1].dx > 0 && dx < 0)
                || (VS_SCRATCH_AT(D_800F16EC_t*, 0x3EC)[arg1].dx < 0 && dx > 0)
                || (VS_SCRATCH_AT(D_800F16EC_t*, 0x3EC)[arg1].dz > 0 && dz < 0)
                || (VS_SCRATCH_AT(D_800F16EC_t*, 0x3EC)[arg1].dz < 0 && dz > 0))) {
            continue;
        }

        radius = arg0->unk92 + 96;
        height = (arg0->unkB8 + 32) >> 1;

        if (ABS(dx) <= radius && ABS(dz) <= radius && ABS(dy) <= height) {
            VS_SCRATCH_AT(D_1F8003D0_t*, 0x3D0)->unk2 |= 1 << arg1;
            VS_SCRATCH_AT(D_1F8003D0_t*, 0x3D0)->unk4[arg1] = 1;
            return 1;
        }
    }

    for (actor = vs_battle_actors[0]; actor != NULL; actor = actor->next) {
        func_800E78F4_t* other = VS_SCRATCH_AT(func_800E78F4_t**, 0x37C)[actor->slot];
        D_800F4538_t* model = other->unk58;

        if (other->unk88 == arg0->unk88 || other->unk88 == 0) {
            continue;
        }

        dx = model->unk0.position.vx - x;
        dy = model->unk0.position.vy - y;
        dz = model->unk0.position.vz - z;

        if (arg2
            && ((VS_SCRATCH_AT(D_800F16EC_t*, 0x3EC)[arg1].dx > 0 && dx < 0)
                || (VS_SCRATCH_AT(D_800F16EC_t*, 0x3EC)[arg1].dx < 0 && dx > 0)
                || (VS_SCRATCH_AT(D_800F16EC_t*, 0x3EC)[arg1].dz > 0 && dz < 0)
                || (VS_SCRATCH_AT(D_800F16EC_t*, 0x3EC)[arg1].dz < 0 && dz > 0))) {
            continue;
        }

        radius = other->unk92 + arg0->unk92 + other->unkB3;

        if (other->unk88 == 0) {
            height = -1;
        } else {
            height = (arg0->unkB8 + other->unkB8) >> 1;
        }

        if (ABS(dx) <= radius && ABS(dz) <= radius && ABS(dy) <= height) {
            VS_SCRATCH_AT(D_1F8003D0_t*, 0x3D0)->unk2 |= 1 << arg1;
            VS_SCRATCH_AT(D_1F8003D0_t*, 0x3D0)->unk4[arg1] = actor->slot + 1;
            return actor->slot + 1;
        }
    }

    VS_SCRATCH_AT(D_1F8003D0_t*, 0x3D0)->unk2 |= 1 << arg1;
    VS_SCRATCH_AT(D_1F8003D0_t*, 0x3D0)->unk4[arg1] = 0;
    return 0;
}

int func_800E0678(func_800E78F4_t* arg0, int arg1)
{
    if ((VS_SCRATCH_AT(D_1F8003D0_t*, 0x3D0)->unk0 >> arg1) & 1) {
        return (VS_SCRATCH_AT(D_1F8003D0_t*, 0x3D0)->unk1 & (1 << arg1)) > 0;
    }

    if (!func_800E02B4(arg0, arg1, 1)) {
        int x = arg0->unk34.x + VS_SCRATCH_AT(D_800F16EC_t*, 0x3EC)[arg1].dx;
        int z = arg0->unk34.z + VS_SCRATCH_AT(D_800F16EC_t*, 0x3EC)[arg1].dz;

        if (x <= D_800F58BC->unk0 && x >= D_800F58BC->unk2 && z <= D_800F58BC->unk1
            && z >= D_800F58BC->unk3
            && !((*VS_SCRATCH_AT(u_short(**)[32], 0x3C0))[z][x] & 0x40)
            && (arg0->unk38.x != x || arg0->unk38.z != z)) {
            if (D_800F58BC->unk14
                && func_800E42EC(x, z) + arg0->unkBE < D_800F58BC->unk14) {
                return 0;
            }

            VS_SCRATCH_AT(D_1F8003D0_t*, 0x3D0)->unk0 |= 1 << arg1;
            VS_SCRATCH_AT(D_1F8003D0_t*, 0x3D0)->unk1 |= 1 << arg1;
            return 1;
        }
    }

    VS_SCRATCH_AT(D_1F8003D0_t*, 0x3D0)->unk0 |= 1 << arg1;
    VS_SCRATCH_AT(D_1F8003D0_t*, 0x3D0)->unk1 &= ~(1 << arg1);
    return 0;
}

int func_800E0850(func_800E78F4_t* arg0, u_int arg1)
{
    int min = 0;
    int count = 1;

    if (arg1 & 0x3FF) {
        count = 3;
    }
    arg1 = (arg1 >> 9) & 6;
    while (--count != -1) {
        if (func_800E0678(arg0, arg1) != 0) {
            int h = func_800E42EC(
                arg0->unk34.x + VS_SCRATCH_AT(D_800F16EC_t*, 0x3EC)[arg1].dx,
                arg0->unk34.z + VS_SCRATCH_AT(D_800F16EC_t*, 0x3EC)[arg1].dz);
            if (h < min) {
                min = h;
            }
        }
        arg1 = (arg1 + 1) & 7;
    }
    return min;
}

int func_800E0918(func_800E78F4_t* arg0, int arg1, int arg2)
{
    void (*callback)(func_800E78F4_t*, int) = arg2 ? func_800E4B2C : func_800E4B70;

    if (arg0->unk15E & 6) {
        u_int distance = func_800E45F4(arg0->unk168, arg0->unk34);

        if (arg2 && distance < 16) {
            if (!(arg0->unk58->unk0.unkA_5 << 21)) {
                callback(arg0, arg1);
                return 1;
            }
        } else if (D_800F58BC->unk14
                   && func_800E42E0(arg0->unk34) + arg0->unkBE < D_800F58BC->unk14) {
            if (arg0->unk58->unk0.unkA_5 << 21) {
                if (func_800D954C(arg0, arg0->unk34) > 0) {
                    func_800E678C(arg0);
                    func_800E4B10(arg0);
                    return 1;
                }
            } else {
                callback(arg0, arg1);
                return 1;
            }
        }
    }

    return 0;
}

void func_800E0A68(func_800E78F4_t* state, int action)
{
    int step;
    int mode;
    int angle;
    int x;
    int z;

    if (func_800E0918(state, action, 1)) {
        return;
    }

    if (!state->unk58->unk0.unkA_5) {
        func_800E4B18(state);
        return;
    }

    state->unk7 = 1;

    if (!func_800E4764(state, &step, &mode)) {
        func_800E2CCC(state);
        return;
    }

    x = state->unk168.x * 128 + 64;
    z = state->unk168.z * 128 + 64;
    angle = ratan2(state->unk4C.vx - x, state->unk4C.vz - z);
    angle &= 0xFFF;

    if (state->unk0 && (func_800E45F4(state->unk34, state->unk168) < 2)
        && ((*VS_SCRATCH_AT(u_short(**)[32], 0x3C0))[state->unk168.z][state->unk168.x]
            & 0x40)) {
        int centerZ;
        int centerAngle;
        int selectedHeight;
        int heading;
        int offsetX;
        int offsetZ;
        int actorY = D_800F4538[state->unkE5]->unk0.position.vy;
        int rise = func_800E42E0(state->unk34);

        if (actorY >= rise) {
            selectedHeight = rise + state->unkBE;
        } else if (D_800F58BC->unk14 && (D_800F58BC->unk14 >= actorY)) {
            selectedHeight = D_800F58BC->unk14;
        } else {
            selectedHeight = (short)actorY;
        }

        rise = selectedHeight - state->unk4C.vy;

        if (ABS(rise) < step) {
            angle = state->unk34.x * 128 + 64;
            centerZ = state->unk34.z * 128 + 64;
            centerAngle = ratan2(state->unk4C.vx - angle, state->unk4C.vz - centerZ);
            state->unk184 = selectedHeight * ONE;
            heading = (-centerAngle + ONE * 3 / 4) & 0xFFF;
            offsetX = state->unk4C.vx - angle;

            if (ABS(offsetX) < step) {
                state->unk17C = angle * ONE;
            } else {
                state->unk17C = (state->unk4C.vx * ONE) + step * rcos(heading);
            }

            offsetZ = state->unk4C.vz - centerZ;
            state->unk180 = ABS(offsetZ) < step
                              ? centerZ * ONE
                              : (state->unk4C.vz * ONE) + step * rsin(heading);
            func_800DEEFC(state, 8);
            return;
        }

        state->unk184 = rise;
        state->unk180 = 0;
        state->unk17C = 0;

        if ((state->unk184 > 0) && func_800E02B4(state, 0, 0)) {
            state->unk184 = 0;
        }

        func_800DEEFC(state, mode);
        return;
    }

    if ((state->unk34.x == state->unk168.x) && (state->unk34.z == state->unk168.z)) {
        int floorY;
        int tileX;
        int deltaX;
        int tileZ;
        int deltaZ;
        D_800F4538_t* actor;

        if (!state->unk0 || func_800E02B4(state, 0, 0)) {
            func_800E2CCC(state);
            return;
        }

        floorY = state->unkBE;
        actor = D_800F4538[state->unkE5];

        if (!((*VS_SCRATCH_AT(u_short(**)[32], 0x3C0))[state->unk168.z][state->unk168.x]
                & 0x20)) {
            floorY += func_800E42E0(state->unk168);
        }

        tileX = state->unk168.x * 128;
        deltaX = state->unk4C.vx - 64;
        state->unk17C = tileX - deltaX;
        tileZ = state->unk168.z * 128;
        deltaZ = state->unk4C.vz - 64;
        state->unk180 = tileZ - deltaZ;
        state->unk184 = floorY - state->unk4C.vy;

        if ((state->unk168.x == actor->unk0.currentTile.x)
            && (state->unk168.z == actor->unk0.currentTile.z)) {
            state->unk184 = actor->unk0.position.vy - (actor->menuCameraHeightOffset >> 1)
                          - state->unk4C.vy;
        }

        if ((state->unk184 > 0) && (floorY < state->unk4C.vy + step)) {
            state->unk184 = 0;
        }

        if (ABS(state->unk17C) < step) {
            state->unk17C = 0;
        }

        if (ABS(state->unk180) < step) {
            state->unk180 = 0;
        }

        func_800DEEFC(state, mode);
        return;
    }

    func_800E3600(state, angle, 2);

    switch (*VS_SCRATCH_AT(int*, 0x3C8)) {
    case 5:
        angle = state->unk188 * (ONE / 8);

        if (func_800E0850(state, angle) + state->unkBE < state->unk4C.vy) {
        fall:
            state->unk184 = -ONE;
            state->unk180 = 0;
            state->unk17C = 0;
        } else {
            angle = -angle;
            angle += ONE * 3 / 4;
            angle &= 0xFFF;
            state->unk184 = 0;
            state->unk17C = rcos(angle);
            state->unk180 = rsin(angle);
        }

        func_800DEEFC(state, mode);
        return;

    case 7: {
        int ground;
        int height;
        int dy;
        int px;
        int py;
        int pz;
        int top;
        unsigned int distance;
        unsigned int denom;
        unsigned int square;
        int value;
        int diff;
        int offset;

        height = func_800E42E0(state->unk168) + state->unkBE;
        px = *(u_int*)&state->unk4C & 0xFFFF;
        py = (int)*(u_int*)&state->unk4C >> 16;
        pz = state->unk4C.vz;
        ground = func_800E6A6C(px, pz, x, z) + state->unkBC;

        if (D_800F58BC->unk14) {
            ground = ground < D_800F58BC->unk14 ? D_800F58BC->unk14 : ground;
        }

        top = func_800E0850(state, angle) + state->unkBE;
        ground = top > ground ? ground : top;
        distance = SquareRoot0(func_800E4660(x - px, 0, z - pz));
        value = height + ground;
        denom = SquareRoot0(((value * ONE) / value) * ONE) + ONE;

        if (denom != 0) {
            value = (distance * ONE) / denom;
            square = value * value;
            diff = py - ground;
            offset = ABS(diff);

            if (py + step < ground) {
                if (step < height - py) {
                    state->unk184 = height - py;
                } else {
                    state->unk184 = 0;
                }

                state->unk17C = x - px;
                state->unk180 = z - pz;
                func_800DEEFC(state, mode);
                state->unk228 = 0;
                return;
            }
        }

        if ((denom == 0) || ((unsigned int)step >= distance)) {
            func_800E1238(state, angle);
            return;
        }

        height =
            (unsigned int)(offset * (step - value) * (step - value)) / square + ground;
        angle = -angle;
        angle += ONE * 3 / 4;
        angle &= 0xFFF;
        x = (px * ONE) + step * rcos(angle);
        z = (pz * ONE) + step * rsin(angle);

        if (height < ground) {
            height = ground;
        } else if (top < height) {
            if (ground < py) {
                goto fall;
            }

            height = top;
        }

        dy = height - py;
        state->unk228 = 0;

        if (step < ABS(dy)) {
            state->unk17C = (x >> 12) - px;
            state->unk180 = (z >> 12) - pz;
            state->unk184 = dy;
            func_800DEEFC(state, mode);
        } else {
            state->unk17C = x;
            state->unk184 = height * ONE;
            state->unk180 = z;
            func_800DEEFC(state, 8);
        }

        return;
    }
    }
}

void func_800E1238(func_800E78F4_t* arg0, int arg1)
{
    int sp10;
    int sp14;
    int angle;
    int c;
    int s;

    if (func_800E0918(arg0, arg1, 0) != 0) {
        return;
    }

    if (func_800E4764(arg0, &sp10, &sp14) == 0) {
        func_800E2CCC(arg0);
        return;
    }

    arg0->unk7 = 1;
    func_800E3600(arg0, arg1, 3);

    if (*VS_SCRATCH_AT(int*, 0x3C8) != 5 && *VS_SCRATCH_AT(int*, 0x3C8) != 7) {
        func_800E678C(arg0);
        func_800E2CCC(arg0);
        return;
    }

    if (*VS_SCRATCH_AT(int*, 0x3C8) == 5) {
        arg1 = arg0->unk188 * (ONE / 8);
    }

    angle = (-arg1 + ONE * 3 / 4) & 0xFFF;
    c = rcos(angle);
    s = rsin(angle);

    if (func_800E0850(arg0, arg1) + arg0->unkBE < arg0->unk4C.vy) {
        arg0->unk184 = -ONE;
        arg0->unk180 = 0;
        arg0->unk17C = 0;
    } else {
        arg0->unk184 = 0;
        arg0->unk17C = c;
        arg0->unk180 = s;
    }

    if (!(arg0->unk58->unk0.unkA_5 << 21)) {
        func_800E4B18(arg0);
    } else {
        arg0->unk228 = 0;
        func_800DEEFC(arg0, sp14);
    }
}

void func_800E1388(func_800E78F4_t* arg0, vs_TilePosition arg1, int arg2, u_int arg3)
{
    vs_TilePosition dest;
    int i;
    int angle = (-arg2 + ONE * 3 / 4) & 0xFFF;
    u_int step = arg3 >> 3;

    for (i = 0; i < 8; ++i, arg3 -= step) {
        int x = ((int)(arg3 * rcos(angle)) >> 12) + 64;
        int z;

        dest.x = (arg1.x * 128 + x) >> 7;
        z = ((int)(arg3 * rsin(angle)) >> 12) + 64;
        dest.z = (arg1.z * 128 + z) >> 7;

        if (func_800D954C(arg0, dest) > 0) {
            break;
        }
    }

    if (dest.x < D_800F58BC->unk2) {
        dest.x = D_800F58BC->unk2;
    } else if (dest.x > D_800F58BC->unk0) {
        dest.x = D_800F58BC->unk0;
    }

    if (dest.z < D_800F58BC->unk3) {
        dest.z = D_800F58BC->unk3;
    } else if (dest.z > D_800F58BC->unk1) {
        dest.z = D_800F58BC->unk1;
    }

    arg0->unk168 = dest;
}

void func_800E153C(func_800E78F4_t* arg0, int arg1)
{
    int distance = arg0->unkB4;

    if ((arg0->unk34.x != arg0->unk168.x) || (arg0->unk34.z != arg0->unk168.z)) {
        int angle = ratan2(arg0->unk4C.vx - arg0->unk168.x * 128 - 64,
            arg0->unk4C.vz - arg0->unk168.z * 128 - 64);

        if (func_800E4660(arg0->unk168.x * 128 - arg0->unk4C.vx + 64, 0,
                arg0->unk168.z * 128 - arg0->unk4C.vz + 64)
            > distance * distance) {
            func_800E1388(arg0, arg0->unk34, angle, distance);
        }

        if ((arg0->unk15E & 6)
            && (arg0->unkD || func_800E45F4(arg0->unk168, arg0->unk34) < 16)) {
            vs_TilePosition tile = arg0->unk48;

            if ((int)((tile.x | tile.surface << 8 | tile.z << 16) << 8) >= 0) {
                arg0->unk168 = tile;
            }

            func_800E4B2C(arg0, angle);
            return;
        }

        if (++arg0->unk8C >= 6) {
            int i;
            vs_TilePosition dest = arg0->unk168;

            if (func_800D954C(arg0, dest) <= 0) {
                for (i = 0; i < 4; ++i) {
                    dest.x =
                        arg0->unk168.x + VS_SCRATCH_AT(D_800F16EC_t*, 0x3EC)[i * 2].dx;
                    dest.z =
                        arg0->unk168.z + VS_SCRATCH_AT(D_800F16EC_t*, 0x3EC)[i * 2].dz;

                    if (func_800D954C(arg0, dest) > 0) {
                        arg0->unk168 = dest;
                        goto begin;
                    }
                }

                goto fallback;
            }

        begin:
            arg0->unk8C = 0;
            arg0->unk170 = arg0->unk168;
            func_800DEEFC(arg0, 13);
            return;
        }
    }

fallback:
    func_800E2CCC(arg0);
}

void func_800E1764(func_800E78F4_t* arg0, int arg1)
{
    vs_TilePosition previous[2];
    u_int distance;
    int opposite = (arg1 + ONE / 2) & 0xFFF;

    func_800E1388(arg0, arg0->unk34, arg1, arg0->unkB4);
    previous[0] = arg0->unk168;
    func_800E1388(arg0, arg0->unk34, opposite, arg0->unkB4);
    distance = func_800E4660(arg0->unk168.x * 128 - arg0->unk17C + 64, 0,
        arg0->unk168.z * 128 - arg0->unk180 + 64);

    if (distance < func_800E4660(previous[0].x * 128 - arg0->unk17C + 64, 0,
            previous[0].z * 128 - arg0->unk180 + 64)) {
        arg0->unk168 = previous[0];
    }

    func_800E153C(arg0, arg1);
}

u_char func_800E1850(u_char arg0, vs_TilePosition arg1, int arg2)
{
    int x = arg1.x;
    int z = arg1.z;
    int i;

    int z2 = z;

    for (i = 0; i < 8; ++i) {
        if ((arg0 >> i) & 1) {
            if (func_800E42EC(x + VS_SCRATCH_AT(D_800F16EC_t*, 0x3EC)[i].dx,
                    z2 + VS_SCRATCH_AT(D_800F16EC_t*, 0x3EC)[i].dz)
                > arg2) {
                arg0 &= ~(1 << i);
            }
        }
    }
    return arg0;
}

void func_800E1908(func_800E78F4_t* arg0)
{
    u_char* tile = &(*VS_SCRATCH_AT(
        u_char**, 0x3C4))[arg0->unk34.z * *VS_SCRATCH_AT(u_char*, 0x3DC) + arg0->unk34.x];
    int old = *tile;
    Actor* actor = arg0->unk54;
    int result;

    *tile = func_800E1850(old, arg0->unk34, arg0->unk4C.vy);
    func_800E3600(arg0,
        ratan2(arg0->unk4C.vx - arg0->unk17C, arg0->unk4C.vz - arg0->unk180) & 0xFFF, 0);
    *tile = old;
    result = *VS_SCRATCH_AT(int*, 0x3C8);

    if ((0xA0 >> result) & 1) {
        actor->unk9 = 9;

        if (result == 5) {
            actor->commandArgs.u16[0] = arg0->unk188 << 9;
        } else {
            actor->commandArgs.u16[0] = arg0->unk188;
        }
    }
}

void func_800E19FC(func_800E78F4_t* arg0)
{
    int current;
    int next;

    arg0->unk4 = 0;
    arg0->unk5 = 1;

    if (arg0->unk1A) {
        func_800E1908(arg0);
        return;
    }

    current = (*VS_SCRATCH_AT(u_short(**)[32], 0x3C0))[arg0->unk34.z][arg0->unk34.x] & 15;
    next = (*VS_SCRATCH_AT(u_short(**)[32], 0x3C0))[arg0->unk168.z][arg0->unk168.x] & 15;

    if (current != next) {
        if (arg0->unk29) {
            int mode = func_800DFBCC(arg0, current, next);

            if (mode == 6) {
                arg0->unk17C = arg0->unk168.x * 128 + 64;
                arg0->unk180 = arg0->unk168.z * 128 + 64;

                if (((*VS_SCRATCH_AT(
                         u_short(**)[32], 0x3C0))[arg0->unk168.z][arg0->unk168.x]
                        & 15)
                    != ((*VS_SCRATCH_AT(
                            u_short(**)[32], 0x3C0))[arg0->unk34.z][arg0->unk34.x]
                        & 15)) {
                    arg0->unk2 = 1;
                    VS_SCRATCH_AT(D_1F8003D0_t*, 0x3D0)->unk0 = 0;
                }
            } else {
                func_800E4BB8(arg0);

                if (mode == 5) {
                    func_800E4B70(arg0, arg0->unk188 * (ONE / 8));
                } else {
                    func_800DEEFC(arg0, mode);
                }

                return;
            }
        } else {
            arg0->unk2 = 1;
            VS_SCRATCH_AT(D_1F8003D0_t*, 0x3D0)->unk0 = 0;
        }
    }

    func_800E3600(arg0,
        ratan2(arg0->unk4C.vx - arg0->unk17C, arg0->unk4C.vz - arg0->unk180) & 0xFFF, 0);
}

int func_800E1BB8(func_800E78F4_t* arg0, vs_TilePosition arg1, u_int arg2, int arg3)
{
    vs_TilePosition candidate;
    u_int count = 0;
    int choices[4];
    int i;
    u_int chosen;

    if (!arg2) {
        return -1;
    }

    if (!arg0->unk15D) {
        arg0->unk11C = arg1;
    }

    candidate = arg0->unk11C;

    for (i = 0; i < 4; ++i) {
        if (!(arg0->unk15E & 8)) {
            if (*VS_SCRATCH_AT(int*, 0x3F4)) {
                candidate.surface =
                    ((*VS_SCRATCH_AT(
                         u_char**, 0x3C4))[arg0->unk11C.z * *VS_SCRATCH_AT(u_char*, 0x3DC)
                                           + arg0->unk11C.x]
                        >> i * 2)
                    & 1;
            } else {
                candidate.surface = func_800E4690(arg0->unk11C, i * 2);
            }

            candidate.x = arg0->unk11C.x + VS_SCRATCH_AT(D_800F16EC_t*, 0x3EC)[i * 2].dx;
            candidate.z = arg0->unk11C.z + VS_SCRATCH_AT(D_800F16EC_t*, 0x3EC)[i * 2].dz;

            if (candidate.surface) {
                if (!func_800D96C8(arg0, arg0->unk11C, candidate, i * 2)) {
                    continue;
                }

                candidate.surface = 0;
            }

            if (!arg0->unk2
                && ((*VS_SCRATCH_AT(u_short(**)[32], 0x3C0))[candidate.z][candidate.x]
                       & 15)
                       != ((*VS_SCRATCH_AT(
                               u_short(**)[32], 0x3C0))[arg0->unk11C.z][arg0->unk11C.x]
                           & 15)) {
                continue;
            }
        }

        if (!((*VS_SCRATCH_AT(u_short(**)[32], 0x3C0))[candidate.z][candidate.x] & 32)) {
            choices[count++] = i * 2;
        }
    }

    if (!count) {
        return -1;
    }

    chosen = func_800E45D4(4096) % count;

    if (arg0->unkD0 > 0 && ((arg0->unkD0 + 4) & 7) == choices[chosen]) {
        chosen = func_800E45D4(4096) % count;
    }

    arg0->unk11C.x += VS_SCRATCH_AT(D_800F16EC_t*, 0x3EC)[choices[chosen]].dx;
    arg0->unk11C.z += VS_SCRATCH_AT(D_800F16EC_t*, 0x3EC)[choices[chosen]].dz;
    arg0->unkD0 = choices[chosen];
    ++arg0->unk15D;
    return arg2 < arg0->unk15D;
}

static inline int randomHeading(int direction)
{
    int offset = func_800E45D4(512);
    int angle = direction * 512;

    offset += 65280;
    return angle + offset;
}

void func_800E1EAC(func_800E78F4_t* arg0, vs_TilePosition arg1, u_int arg2)
{
    int rate = arg0->unkD8;
    u_short rest = arg0->unkD4;
    u_short move = arg0->unkD6;
    int value;
    int (*check)(func_800E78F4_t*, int);

    ++arg0->unkC2;
    check = (arg0->unk58->unk0.unkA_5 << 21) ? func_800E0678 : func_800D9B6C;

    if (arg0->unk12D == 1) {
        if (arg0->unkC2 < 31) {
            return;
        }

        if (func_800E45D4(128) < 44u) {
            arg0->unk12D = 2;
        } else {
            arg0->unkC2 = 0;
            return;
        }
    }

    if (arg0->unkC2 == move) {
        if (func_800E45D4(128) < 44u) {
            arg0->unkC2 = 0;
        }
    } else if (arg0->unkC2 >= rest + move) {
        arg0->unkC2 = func_800E45D4(128) < 44u ? move : 0;
    }

    arg0->unk2 = 1;
    *VS_SCRATCH_AT(u_char*, 0x3D0) = 0;

    value = arg0->unkC2 < move;

    if (value) {
        int heading;
        int result;

        if (arg2 >= 63) {
            int i;
            int side;
            int step;

            if (!arg0->unkC0 || !func_800E45D4(1 << rate) || !arg0->unkD2) {
                value = func_800E45D4(4096) % arg2 + 128;
                arg0->unkC0 = 1;
                arg0->unkD2 = 60;
                arg0->unkC4 = value * value;
                heading = func_800E45D4(4) * 2;

                for (i = 0; i < 4; ++i) {
                    int direction = (heading + i * 2) & 7;

                    if (check(arg0, direction)) {
                        arg0->unkD0 = randomHeading(direction);
                        break;
                    }
                }

                if (i == 4) {
                    arg0->unkD0 = func_800E45D4(4096);
                }
            }

            if (!arg0->unk8) {
                arg0->unkD2 = 60;
            } else if (arg0->unkD2) {
                --arg0->unkD2;
            }

            if (arg0->unk15E & 8) {
                func_800E1388(arg0, arg0->unk34, arg0->unkD0, arg0->unkB4);
            }

            for (side = arg0->unkD0 >> 9, step = 0; step < 2;
                side = (side + 2) & 7, ++step) {
                int x = arg0->unk34.x + VS_SCRATCH_AT(D_800F16EC_t*, 0x3EC)[side].dx;
                int z = arg0->unk34.z + VS_SCRATCH_AT(D_800F16EC_t*, 0x3EC)[side].dz;

                if (D_800F58BC->unk1 < z || z < D_800F58BC->unk3 || D_800F58BC->unk0 < x
                    || x < D_800F58BC->unk2
                    || ((*VS_SCRATCH_AT(u_short(**)[32], 0x3C0))[z][x] & 0x800)) {
                    arg0->unkD2 = 0;
                    break;
                }
            }

            func_800E50A0(arg0, 1, arg0->unkD0);
            return;
        }

        arg0->unk3 = 1;

        if (!func_800E45D4(1 << rate)) {
            arg0->unkC0 = 0;
        }

        switch (arg0->unkC0) {
        case 0:
            arg0->unkD0 = -1;
            arg0->unk15D = 0;
            arg0->unkD2 = 60;
            ++arg0->unkC0;
            func_800E2CCC(arg0);
            return;

        case 1:
            result = func_800E1BB8(arg0, arg1, arg2, 3);

            if (result < 0) {
                arg0->unkC0 = 0;
            } else if (result > 0) {
                ++arg0->unkC0;
                arg0->unk168 = arg0->unk11C;
            }
            break;

        case 2:
            arg0->unk168 = arg0->unk11C;

            if (arg0->unk15E & 8) {
                heading = ratan2(arg0->unk4C.vx - arg0->unk168.x * 128 - 64,
                              arg0->unk4C.vz - arg0->unk168.z * 128 - 64)
                        & 0xFFF;
                arg0->unk48 = arg0->unk168;
                func_800E1388(arg0, arg0->unk34, heading, arg0->unkB4);
            }

            func_800E50A0(arg0, 0, 0);

            if (!arg0->unk8) {
                arg0->unkD2 = 60;
            } else if (arg0->unkD2) {
                --arg0->unkD2;
            }

            if (((arg0->unk168.x == arg0->unk34.x) && (arg0->unk168.z == arg0->unk34.z))
                || !arg0->unkD2) {
                arg0->unkC0 = 0;
            }

            return;

        default:
            arg0->unkC0 = 0;
            break;
        }
    }

    func_800E2CCC(arg0);
}

static inline void nextWaypoint(func_800E78F4_t* arg0, D_800F58C8_t2* waypoints)
{
    D_800F58C8_t2* waypoint = &waypoints[arg0->unk100];
    int step;
    int active;

    if ((arg0->unk34.x != waypoint->x) || (arg0->unk34.z != waypoint->z)) {
        if (arg0->unk104 != 0) {
            --arg0->unk104;
        }

        if (func_800E45D4(1 << arg0->unk102) || (arg0->unk104 != 0)) {
            return;
        }

        arg0->unk103 = -arg0->unk103;
    }

    step = arg0->unk103 + 8;

    do {
        arg0->unk100 = (arg0->unk100 + step) & 7;
        waypoint = &waypoints[arg0->unk100];
        active = waypoint->active;
    } while (!active);

    arg0->unk104 = 10;
}

void func_800E23AC(func_800E78F4_t* arg0)
{
    D_800F58C8_t2* waypoints = D_800F58D8[arg0->unk101].unk0;
    D_800F58C8_t2* waypointX;
    D_800F58C8_t2* waypointZ;

    nextWaypoint(arg0, waypoints);
    waypointX = &waypoints[arg0->unk100];
    arg0->unk168.x = waypointX->x;
    waypointZ = &waypoints[arg0->unk100];
    arg0->unk168.z = waypointZ->z;
    func_800E50A0(arg0, 0, 0);
}

int func_800E24EC(func_800E78F4_t* s, int option)
{
    int result = 1;
    int target = s->unkE5;

    if (target == s->unk88) {
        func_800DEEFC(s, 0);
    } else {
        D_800F4538_t* model = D_800F4538[target];

        if (s->unk58->unk0.unkA_5) {
            option = 1;
        }

        if ((!model->unk0.unkA_0 && !model->unk0.unkA_3
                    ? (((model->unk0.position.vx >> 6) != s->unkF4)
                          || ((model->unk0.position.vz >> 6) != s->unkF6))
                    : ((s->unk168.x != (s->unkF4 >> 1))
                          || (s->unk168.z != (s->unkF6 >> 1))))
            || (s->unkDC != s->unkE0) || (target != s->unkEB) || (option != s->unkEA)
            || (s->unkF8++ > 180)) {
            s->unkF8 = 0;
            s->unkE8 = 0;
            s->unkE7 = 0;
        }

        s->unkEA = option;
        s->unkEB = target;
        s->unkE0 = s->unkDC;

        if (s->unk1A4[target].unk0_0) {
            s->unkE4 = 0;

            if (!s->unk1A4[target].unk0_2) {
                s->unkE9 = 0;
            } else {
                int mode = s->unkE9;
                int value;

                switch (mode) {
                case 0:
                    if ((s->unkDC - 96) * (s->unkDC - 96) < s->unk1E4[target]) {
                        s->unkE9 = 0;
                    } else {
                        s->unkE9 = 1;
                    }
                    break;

                case 1:
                    value = s->unkDC;

                    if (value * value < s->unk1E4[target]) {
                        s->unkE9 = 0;
                    } else if ((value - 128) * (value - 128) >= s->unk1E4[target]) {
                        s->unkE9 = 2;
                    } else {
                        s->unkE9 = mode;
                    }
                    break;

                case 2:
                    if ((s->unkDC - 32) * (s->unkDC - 32) < s->unk1E4[target]) {
                        s->unkE9 = 1;
                    } else {
                        s->unkE9 = mode;
                    }
                    break;
                }
            }

            if (((s->unkE9 != 2) && s->unkE8) || ((s->unkE9 != 0) && s->unkE7)) {
                goto recover;
            }

            if ((option == 0) && (s->unkE9 == 2)) {
                s->unkE9 = 1;
            }

            switch (s->unkE9) {
            case 0:
                if (option == 1) {
                    s->unk0 = 1;
                }

                s->unkA[2] = 1;
                s->unk1 = func_800E4FB0(s, target, s->unkDC);

                if (s->unk15E & 8) {
                    vs_TilePosition oldPosition = s->unk168;
                    int angle = ratan2(s->unk4C.vx - (s->unk168.x * 128) - 64,
                                    s->unk4C.vz - (s->unk168.z * 128) - 64)
                              & 0xFFF;
                    int distance = func_800E4660(s->unk4C.vx - (s->unk168.x * 128) - 64,
                        0, s->unk4C.vz - (s->unk168.z * 128) - 64);
                    int radius;

                    s->unk48 = oldPosition;
                    distance = SquareRoot0(distance);
                    radius = s->unkDC - 96;
                    func_800E1388(s, s->unk34, angle, distance - ABS(radius));

                    if ((s->unk168.x == s->unk34.x) && (s->unk168.z == s->unk34.z)) {
                        s->unkD = 1;
                        s->unk168 = oldPosition;
                    }
                }

                s->unk15C = s->unkE5;
                func_800E50A0(s, 0, 0);
                break;

            case 1:
            recover:
                s->unk15C = target;
                func_800E2CCC(s);
                break;

            case 2:
                s->unk3 = 1;
                *VS_SCRATCH_AT(unsigned char*, 0x3D0) = 0;
                s->unk4 = 1;
                s->unk17C = model->unk0.position.vx;
                s->unk180 = model->unk0.position.vz;

                if (s->unk33) {
                    s->unk1 = 1;
                    s->unk9 = 1;
                    s->unk158 = s->unk17C;
                    s->unk15A = s->unk180;
                } else {
                    s->unk15C = target;
                }

                func_800E50A0(
                    s, 1, ratan2(s->unk17C - s->unk4C.vx, s->unk180 - s->unk4C.vz));

                if (s->unk54->unk9 >= 9) {
                    s->unkE8 = 1;
                }
                break;
            }
        } else {
            if (!s->unkE4 && s->unk1A4[target].unk0_1) {
                if (s->unk24) {
                    s->unkE4 = 1;
                    s->unkE6 = 255;
                    s->unkEC.x = s->unkF4 >> 1;
                    s->unkEC.z = s->unkF6 >> 1;
                } else {
                    if (s->unk1A4[target].unk0_5) {
                        result = 0;
                    } else {
                        func_800D8260(s, 7, 40);

                        if (!func_800E4180(s, 128, 1, 1)) {
                            result = 0;
                        }
                    }

                    func_800E4904(s);
                    return result;
                }
            }

            if (s->unkE8) {
                goto recover;
            }

            if (s->unkE4) {
                s->unk168 = s->unkEC;

                if (s->unkE6 != 0) {
                    --s->unkE6;
                }

                if ((s->unk168.x == s->unk34.x) && (s->unk168.z == s->unk34.z)) {
                    if (s->unk1A4[target].unk0_5) {
                        result = 0;
                    } else {
                        func_800D8260(s, 7, 40);

                        if (!func_800E4180(s, 128, 1, 1)) {
                        cancel:
                            s->unkE4 = 0;
                            result = 0;
                        }
                    }
                } else if (s->unkE6 != 0) {
                    s->unk1 = 1;
                    s->unkA[2] = 1;
                    func_800E50A0(s, 0, 0);
                } else {
                    goto cancel;
                }
            } else if (!func_800E4180(s, 0, 3, 1)) {
                result = 0;
            }
        }
    }

    func_800E4904(s);
    return result;
}

int func_800E2B2C(func_800E78F4_t* arg0, int arg1)
{
    D_800F4538_t* model = arg0->unk58;
    int angle;

    if (arg1 == arg0->unk88) {
        func_800DEEFC(arg0, 0);
        return 1;
    }

    if (!arg0->unkBA) {
        return 0;
    }

    if (arg0->unk481) {
        if (func_800E4180(arg0, 128, 3, 6)) {
            return 1;
        }

        arg0->unk10C = 0;
        return 0;
    }

    angle = ratan2(arg0->unk4C.vx - arg0->unk17C, arg0->unk4C.vz - arg0->unk180);

    if (((arg0->unk168.x != arg0->unk108.x) || (arg0->unk168.z != arg0->unk108.z))
        && arg0->unk1A4[arg1].unk0_5 && !arg0->unk10C) {
        arg0->unk10C = 1;
        arg0->unk18A = angle;
        arg0->unk108 = arg0->unk168;
    }

    if (!arg0->unk10C) {
        return 0;
    }

    arg0->unk13A = arg0->unkBA;

    if (((model->unk0.facing + model->unk0.unk14) & 0xFFF) == (arg0->unk18A & 0xFFF)) {
        if (!arg0->unk1A4[arg1].unk0_5) {
            if (func_800E4180(arg0, 128, 1, 6)) {
                return 1;
            }

            arg0->unk10C = 0;
            goto failed;
        } else {
            arg0->unk10C = 1;
            arg0->unk18A = angle & 0xFFF;
            arg0->unk108 = arg0->unk168;
        }
    }

    func_800DEEFC(arg0, 4);
    return 1;

failed:
    return 0;
}

void func_800E2CCC(func_800E78F4_t* arg0)
{
    D_800F4538_t* model = arg0->unk58;
    int direction;

    if ((model->unk0.unkA_5 << 21) && arg0->unk228++ > 120 && (arg0->unk15E & 6)
        && (arg0->unk15E & 0x30) && func_800D954C(arg0, arg0->unk34) > 0) {
        func_800E678C(arg0);
        func_800E4B10(arg0);
        return;
    }

    if (arg0->unk15C != 16) {
        direction = ratan2(arg0->unk4C.vx - D_800F4538[arg0->unk15C]->unk0.position.vx,
                        arg0->unk4C.vz - D_800F4538[arg0->unk15C]->unk0.position.vz)
                  & 0xFFF;
        arg0->unk18A = direction;
        arg0->unk13A = arg0->unk13C;
        func_800DEEFC(arg0, 4);
    } else if (arg0->unk9) {
        direction =
            ratan2(arg0->unk4C.vx - arg0->unk158, arg0->unk4C.vz - arg0->unk15A) & 0xFFF;
        arg0->unk188 = direction;
        arg0->unk13A = arg0->unk13C;
        func_800DEEFC(arg0, 3);
    } else {
        int i;
        int nx;
        int nz;
        u_char* bounds;
        int bestHeight = 0x80000000;
        int bestDirection = -1;
        vs_TilePosition source = arg0->unk34;
        u_int x = source.x;
        u_int z = source.z;
        u_int z2 = z;
        u_int angle = model->unk0.facing + model->unk0.unk14;
        u_int quadrant = (angle & 0xFFF) / (ONE / 4);
        direction = (angle & 0x3FF) > ONE / 8 ? ((quadrant + 1) & 3) * 2 : quadrant * 2;

        for (i = 0, bounds = VS_SCRATCH_AT(u_char*, 0x3DC); i < 4; ++i) {
            direction = (direction + i * 2) & 7;
            nx = (x + VS_SCRATCH_AT(D_800F16EC_t*, 0x3EC)[direction].dx) & 0xFF;
            nz = (z2 + VS_SCRATCH_AT(D_800F16EC_t*, 0x3EC)[direction].dz) & 0xFF;

            if (nx < bounds[0] && nz < bounds[1]) {
                int height = (func_800E4320(nx, nz) << 17) >> 17;

                if (height > bestHeight) {
                    bestDirection = direction;
                    bestHeight = height;
                }
            }
        }

        if (bestDirection < 0) {
            func_800DEEFC(arg0, 0);
        } else {
            arg0->unk18A = bestDirection * (ONE / 8);
            arg0->unk13A = arg0->unk13C;
            func_800DEEFC(arg0, 4);
        }
    }
}

int func_800E2F5C(func_800E78F4_t* state, int (*test)(func_800E78F4_t*, int), int mask)
{
    func_800E78F4_path_t path = state->unk190;

    state->unk5 = 0;
    state->unk1 = state->unk199;

    if (path.count != 0) {
        int heading = path.direction;
        u_int direction = (path.clockwise ? heading - 2 : heading + 2) & 7;
        int hit = func_800D98E8(state, direction);
        int blocker = hit - 1;
        int boundX;
        int boundZ;
        int cell;

        if (hit != 0 && !(VS_SCRATCH_AT(func_800E78F4_t**, 0x37C)[blocker]->unk15E & 0x30)
            && !VS_SCRATCH_AT(func_800E78F4_t**, 0x37C)[blocker]->unk19A) {
            VS_SCRATCH_AT(func_800E78F4_t**, 0x37C)
            [blocker]->unk19A = func_800E45D4(4) + 4;
        }

        if (!state->unk4 && !path.changed && !test(state, path.direction)) {
            vs_TilePosition ahead;

            ahead.x =
                state->unk34.x + VS_SCRATCH_AT(D_800F16EC_t*, 0x3EC)[path.direction].dx;
            ahead.z =
                state->unk34.z + VS_SCRATCH_AT(D_800F16EC_t*, 0x3EC)[path.direction].dz;
            ahead.surface = 0;

            if (!func_800D96C8(state, state->unk34, ahead, path.direction)
                || (func_800D954C(state, ahead) <= 0)) {
                path.changed = 1;
                path.clockwise = !path.clockwise;
                path.visited = 0;
                path.direction += 4;
            }
        }

        boundX = path.boundX * 128;
        boundZ = path.boundZ * 128;

        if (!state->unk4) {
            int x = state->unk34.x + VS_SCRATCH_AT(D_800F16EC_t*, 0x3EC)[direction].dx;
            int z = state->unk34.z + VS_SCRATCH_AT(D_800F16EC_t*, 0x3EC)[direction].dz;

            if ((((*VS_SCRATCH_AT(u_short(**)[32], 0x3C0))[z][x] >> mask) & 1)
                || (x > D_800F58BC->unk0) || (z > D_800F58BC->unk1)
                || (x < D_800F58BC->unk2) || (z < D_800F58BC->unk3)) {
                state->unkE8 = 0;
                state->unkE7 = 0;
                state->unkE4 = 0;
                goto stop;
            }
        }

        if (!state->unk4) {
            if (boundZ > 0) {
                int center = state->unk168.z * 128 + 64;

                if ((center < boundZ && state->unk4C.vz < boundZ)
                    || (boundZ < center && boundZ < state->unk4C.vz)) {
                    state->unk190 = path;
                    return -1;
                }
            }

            if (boundX > 0) {
                int center = state->unk168.x * 128 + 64;

                if ((center < boundX && state->unk4C.vx < boundX)
                    || (boundX < center && boundX < state->unk4C.vx)) {
                    state->unk190 = path;
                    return -1;
                }
            }
        } else {
            if (boundZ > 0) {
                int center = state->unk168.z * 128 + 64;

                if ((boundZ < center && state->unk4C.vz < boundZ)
                    || (center < boundZ && boundZ < state->unk4C.vz)) {
                    state->unk190 = path;
                    return -1;
                }
            }

            if (boundX > 0) {
                int center = state->unk168.x * 128 + 64;

                if ((boundX < center && state->unk4C.vx < boundX)
                    || (center < boundX && boundX < state->unk4C.vx)) {
                    state->unk190 = path;
                    return -1;
                }
            }
        }

        cell = func_800E3D5C(state, test);

        if (cell != path.cell) {
            int turn = -1;
            int i;
            vs_TilePosition point;

            path.cell = cell;

            if (path.clockwise) {
                turn = 1;
            }

            if (test(state, (path.direction - turn * 2 - turn) & 7)
                && test(state, (path.direction - turn * 2) & 7)) {
                if (!(state->unk15E & 0x30) && !state->unk19A) {
                    state->unk19A = func_800E45D4(4) + 4;
                }

                path.stop = 1;
                state->unk190 = path;
                return -1;
            }

            path.visited |= 1 << (path.direction >> 1);

            if (path.visited == 15) {
                path.stop = 1;
                state->unk190 = path;
                return -1;
            }

            direction = (path.direction - turn * 2) & 7;
            i = 0;

            while (1) {
                if (test(state, direction)) {
                    if (path.direction != direction) {
                        path.changed = 1;
                    }

                    path.direction = direction;
                    state->unk190 = path;
                    return 5;
                }

                point.x =
                    state->unk34.x + VS_SCRATCH_AT(D_800F16EC_t*, 0x3EC)[direction].dx;
                point.z =
                    state->unk34.z + VS_SCRATCH_AT(D_800F16EC_t*, 0x3EC)[direction].dz;
                point.surface = 0;

                if (func_800D96C8(state, state->unk34, point, direction)
                    && (func_800D954C(state, point) > 0)) {
                    memcpy(&state->unk170, &point, sizeof point);

                    if (path.direction != direction) {
                        path.changed = 1;
                    }

                    path.direction = direction;
                    break;
                }

                direction = (direction + turn * 2) & 7;

                if (++i >= 4) {
                    state->unk190 = path;
                    return -1;
                }
            }

            state->unk190 = path;
            return 14;
        }

        state->unk190 = path;
        return 5;

    stop:
        path.stop = 1;
    }

    state->unk190 = path;
    return -1;
}

#ifdef NON_MATCHING
#define VS_REG_VAR(type, name, reg) type name
#else
#define VS_REG_VAR(type, name, reg) register type name __asm__(reg)
#endif

extern int (*D_800F1760[][4])();

void func_800E3600(func_800E78F4_t* state, u_int angle, int type)
{
    int (*test)(func_800E78F4_t*, int);
    int mask;
    int mode;
    int diagonal;
    int direction;
    int clockwise;
    int counter;
    int blockedCw;
    int blockedCcw;
    VS_REG_VAR(int, step, "$5");
    int distance;
    VS_REG_VAR(int, limit, "$3");
    VS_REG_VAR(u_int, value, "$2");
    VS_REG_VAR(func_800E78F4_t*, self, "$4");
    vs_TileWord point;
    vs_TilePosition* pointer;
    vs_TileWord probe1;
    vs_TileWord probe2;
    vs_TileWord probe3;

    if ((type - 2) < 2u) {
        test = func_800E0678;
        mask = 12;
    } else {
        test = func_800D9B6C;
        mask = 11;
    }

    if (state->unk190.unk0) {
        mode = func_800E2F5C(state, test, mask);

        if (mode < 0) {
            func_800E4BB8(state);
            goto stop;
        }

        state->unk188 = state->unk190.direction;
        func_800DEEFC(state, mode);
        return;
    }

    {
        u_int quadrant = (angle & 0xFFF) >> 10;

        direction =
            (angle & 0x3FF) > 0x200 ? ((quadrant + 1) & 3) * 2 : quadrant * 2;
    }

    point.fields = state->unk34;
    pointer = &point.fields;
    pointer->x += VS_SCRATCH_AT(D_800F16EC_t*, 0x3EC)[direction].dx;
    pointer->z += VS_SCRATCH_AT(D_800F16EC_t*, 0x3EC)[direction].dz;

    {
        int from;
        int to;

        if (direction & 2) {
            to = state->unk168.x;
            from = state->unk34.x;
        } else {
            to = state->unk168.z;
            from = state->unk34.z;
        }

        distance = abs(to - from);
    }

    limit = state->unkB2;

    if (distance <= limit) {
        limit = distance;
    }

    point.value = func_800E49D8(state, point.fields, direction, limit);

    if (point.value) {
        point.fields.surface = 0;
        state->unk170 = point.fields;
        func_800DEEFC(state, 14);
        return;
    }

    self = state;

    if (angle & 0x3FF) {
        u_int quadrant = angle >> 10;

        clockwise = ((quadrant + 1) * 2) & 7;
        counter = (quadrant * 2) & 7;
        diagonal = (quadrant * 2 + 1) & 7;
        blockedCw = test(self, clockwise);
        blockedCcw = test(state, counter);

        if (!blockedCw && !blockedCcw) {
            if (state->unk156 - 1u >= 0x7E) {
                value = func_800D8400(state, clockwise, counter, angle);
                probe1.value = value;

                if ((&probe1)->fields.extra == 2) {
                    if (!state->unk156) {
                        state->unk156 = 0xFE;
                    }

                    goto stop;
                }

                if (value) {
                    if (!func_800E47E4(state, value)
                        || !func_800E4180(state, 0x80, 2, state->unk89)) {
                        state->unk170 = probe1.fields;
                        func_800DEEFC(state, 14);
                        return;
                    }

                    return;
                }
            }

            if (D_800F1760[0][type](state, clockwise, counter, test)) {
                state->unk188 = state->unk190.direction;
                func_800DEEFC(state, 5);
                return;
            }

            goto stop;
        }

        if (blockedCw) {
            if (blockedCcw) {
                if (!test(state, diagonal)) {
                    if (direction == clockwise) {
                        state->unk188 = clockwise;
                    } else {
                        state->unk188 = counter;
                    }

                    func_800DEEFC(state, 5);
                    return;
                } else {
                    state->unk188 = angle;
                    func_800DEEFC(state, 7);
                    return;
                }
            }

            state->unk188 = clockwise;
        } else {
            state->unk188 = counter;
        }

        if (state->unk156 - 1u >= 0x7E) {
            value = func_800D8400(state, 0, 0, blockedCw ? counter : clockwise);
            probe2.value = value;

            if ((&probe2)->fields.extra == 2) {
                if (!state->unk156) {
                    state->unk156 = 0xFE;
                }

                goto stop;
            }

            if (value) {
                if (!func_800E47E4(state, value)
                    || !func_800E4180(state, 0x80, 2, state->unk89)) {
                    state->unk170 = probe2.fields;
                    func_800DEEFC(state, 14);
                    return;
                }

                return;
            }
        }

        if (type == 0 || type == 2) {
            step = 0;

            if ((state->unk188 & 2) ? state->unk34.x == state->unk168.x
                                    : state->unk34.z == state->unk168.z) {
                step = 1;
            }
        } else {
            step = 0;

            if (state->unk4) {
                step = rcos(((blockedCw ? counter : clockwise) * 512 - angle) & 0xFFF)
                    >= 0xF77;
            }
        }

        if (step) {
            if (D_800F1760[1][type](state, state->unk188, blockedCw ? 1 : -1, test)) {
                state->unk188 = state->unk190.direction;
                func_800DEEFC(state, 5);
                return;
            }

            goto stop;
        }

        func_800DEEFC(state, 5);
        return;
    }

    clockwise = (angle >> 9) & 6;

    if (test(self, clockwise)) {
        state->unk188 = angle;
        func_800DEEFC(state, 7);
        return;
    }

    if (state->unk156 - 1u >= 0x7E) {
        value = func_800D8400(state, 0, 0, clockwise);
        probe3.value = value;

        if ((&probe3)->fields.extra == 2) {
#ifdef NON_MATCHING
            if (!state->unk156) {
#else
            // Comparing against $zero assembles like bnez but keeps gcc from merging this
            // body with the two identical ones above.
            register int zero __asm__("$0");

            if (state->unk156 == zero) {
#endif
                state->unk156 = 0xFE;
            }

            goto stop;
        }

        if (value) {
            if (!func_800E47E4(state, value)
                || !func_800E4180(state, 0x80, 2, state->unk89)) {
                state->unk170 = probe3.fields;
                func_800DEEFC(state, 14);
                return;
            }

            return;
        }
    }

    if (type != 1 || state->unk4) {
        if (D_800F1760[2][type](state, clockwise, test)) {
            goto found;
        }
    }

stop:
    func_800E2CCC(state);
    return;

found:
    state->unk188 = state->unk190.direction;
    func_800DEEFC(state, 5);
}

#undef VS_REG_VAR
