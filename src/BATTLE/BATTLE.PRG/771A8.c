#include "common.h"
#include "3A1A0.h"
#include "4A0A8.h"
#include "5BF94.h"
#include "6E644.h"
#include "src/SLUS_010.40/32154.h"
#include "src/SLUS_010.40/main.h"
#include "src/SLUS_010.40/overlay.h"
#include "build/src/include/lbas.h"
#include <abs.h>
#include <stdlib.h>

typedef struct {
    u_short unk0_0 : 5;
    u_short unk0_5 : 5;
    u_short unk0_10 : 6;
} D_800F5910_t;

typedef struct {
    u_char unk0;
    u_char unk1;
    u_char unk2;
} func_800DFA54_t;

typedef struct {
    short unk0;
    short unk1;
    short unk2;
    short unk3;
} func_8008D2C0_t;

typedef struct {
    signed char dx : 2;
    signed char unk0_2 : 2;
    signed char dz : 2;
    signed char unk0_6 : 2;
} D_800F16EC_t;

typedef struct {
    char unk0[8];
    u_char unk8;
    u_char unk9;
    char unkA;
    u_int unkB_0 : 2;
    u_int unkB_2 : 2;
    u_int unkB_4 : 4;
    u_short unkC;
    u_short unkE;
    SVECTOR unk10;
    char unk18[0x24];
    vs_battle_actor2* unk3C;
} func_800DEB10_t2;

typedef struct {
    int unk0;
    u_int unk4;
} func_800E78F4_t2;

typedef struct func_800E78F4_t {
    char unk0[0x4E];
    u_short unk4E;
    char unk50[4];
    func_800DEB10_t2* unk54;
    char unk58[4];
    vs_battle_actor2* unk5C;
    char unk60[0xCF];
    u_char unk12F;
    char unk130[0x70];
    struct func_800E78F4_t* unk1A0;
    char unk1A4[0x28C];
    func_800E78F4_t2* unk430;
    char unk434[0x3C];
    int unk470;
} func_800E78F4_t;

typedef struct {
    u_char maxX, maxZ, minX, minZ;
    char unk4[0x10];
    int unk14;
    u_short unk18;
    char unk1A[2];
    func_800E78F4_t* unk1C;
    func_800E78F4_t* unk20;
    int unk24;
} D_800F58BC_t;

typedef struct {
    int unk0;
    int unk4;
    u_int unk8_0 : 21;
    u_int unk8_21 : 1;
    u_int unk8_22 : 10;
} func_800E1238_t;

typedef struct {
    char unk0[7];
    u_char unk7;
    char unk8[0x2C];
    u_char unk34;
    char unk35;
    u_char unk36;
    char unk37[0x17];
    short unk4E;
    char unk50[8];
    func_800E1238_t* unk58;
    char unk5C[0x62];
    short unkBE;
    char unkC0[0xBC];
    int unk17C;
    int unk180;
    int unk184;
    short unk188;
    char unk18A[0x9E];
    int unk228;
} func_800E0850_t;

typedef struct {
    int unk0;
    u_int unk4_0 : 3;
    u_int unk4_3 : 2;
    u_int unk4_5 : 8;
    u_int unk4_13 : 19;
    int unk8;
    u_int unkC_0 : 4;
    u_int unkC_4 : 3;
    u_int unkC_7 : 12;
    u_int unkC_19 : 8;
    u_int unkC_27 : 5;
} func_800DCAA0_t;

typedef struct {
    char unk0[0x16];
    signed char unk16;
    char unk17[0x21];
    int unk38;
    char unk3C[0x18];
    func_800DEB10_t2* unk54;
    char unk58[0x42];
    short unk9A;
    char unk9C[0x5F];
    u_char unkFB;
    char unkFC[0x2E];
    u_char unk12A;
    char unk12B[0xD];
    u_short unk138;
    char unk13A[0x2F6];
    func_800DCAA0_t* unk430[16];
    int unk470;
} func_800DEEA4_t2;
int func_8008D2C0(func_8008D2C0_t*);
void func_800DEEFC(func_800E0850_t*, int);
struct directionalCacheState;
int func_800E0678(struct directionalCacheState*, int);
struct movementCheckState;
int func_800E0918(struct movementCheckState*, int, int);
typedef struct movementRecoveryState movementRecoveryState;
void func_800E2CCC(movementRecoveryState*);
void func_800E3600(func_800E0850_t*, int, int);
int func_800E42EC(int, int);
int func_800E4764(func_800E0850_t*, int*, int*);
void func_800E4B18(func_800E0850_t*);
void func_800E678C(func_800E0850_t*);
extern D_800F58BC_t* D_800F58BC;
extern D_800F5910_t* D_800F5910;
void func_800D8260(func_800DEEA4_t2* arg0, int arg1, int arg2);

typedef union {
    unsigned int raw;
    struct {
        unsigned int x : 8, y : 8, z : 8, status : 8;
    } p;
} vs_battle_movementPosition;
typedef struct {
    unsigned char pad[7];
    unsigned char disabled;
    unsigned char rest[0x2C];
    vs_battle_movementPosition position;
    char unk38[0x130];
    vs_battle_movementPosition destination;
} func_800D8400_t;
int func_800D96C8(func_800D8400_t*, unsigned int, unsigned int, int);
int func_800D954C(func_800D8400_t*, unsigned int);
unsigned int func_800E4660(int, int, int);
void func_800E50A0(void*, int, int);
int func_800E45D4(int);
void func_800E1388(func_800D8400_t*, vs_battle_movementPosition, int, unsigned int);
int func_800E45D4(int);

void func_800DF9A8(func_800DFA54_t* arg0, func_800DFA54_t* arg1)
{
    int i;

    for (i = 0; i < 8; i++) {
        if (D_800F5910[i * 2].unk0_0 == arg0->unk0
            && D_800F5910[i * 2].unk0_5 == arg0->unk2) {
            if (i & 1) {
                i--;
            } else {
                i++;
            }
            arg1->unk0 = D_800F5910[i * 2 + 1].unk0_0;
            arg1->unk2 = D_800F5910[i * 2 + 1].unk0_5;
            arg1->unk1 = i >> 1;
            return;
        }
    }
    *(int*)arg1 = *(int*)arg0;
}

void func_800DFA54(int arg0, int arg1, int arg2, func_800DFA54_t* arg3)
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
    arg3->unk0 = D_800F5910[i * 2].unk0_0;
    arg3->unk2 = D_800F5910[i * 2].unk0_5;
}

int func_800DFAF8(int arg0, u_int arg1, int arg2)
{
    func_8008D2C0_t sp10[4];
    func_8008D2C0_t* m;
    int i;
    int j;

    func_8008D2C0(sp10);
    for (i = 0; i < 8; ++i) {
        D_800F5910_t* e = &D_800F5910[i * 2];
        j = i >> 1;
        if (arg2 == 0) {
            ++e;
        }
        if ((u_char)arg1 == e->unk0_0 && (u_char)(arg1 >> 16) == e->unk0_5) {
            m = &sp10[j];
            if (D_800F5910[i * 2 + 1].unk0_0 == m->unk0 >> 7
                && D_800F5910[i * 2 + 1].unk0_5 == m->unk2 >> 7) {
                return i;
            }
        }
    }
    return -1;
}

typedef struct routeEdgeState {
    char unk0[5];
    u_char unk5;
    char unk6[0x2E];
    vs_battle_movementPosition tile;
    char unk38[0x14];
    short x;
    short y;
    short z;
    char unk52[0x36];
    u_char id;
    char unk89[0xB1];
    u_short cooldown;
    u_short period;
    char unk13E[0x16];
    u_char area;
    char unk155[7];
    u_char target;
    char unk15D[0xB];
    vs_battle_movementPosition destination;
    char unk16C[4];
    vs_battle_movementPosition next;
    char unk174[8];
    int moveX;
    int moveZ;
    char unk184[4];
    short heading;
    short angle;
    char unk18C[0xF];
    u_char gate;
    func_800DFA54_t exit;
} routeEdgeState;

typedef struct {
    char unk0[0x60];
    short* position;
} routeEdgeActor;

typedef struct {
    char unk0[14];
    u_char closedGates;
} routeEdgeGlobals;

typedef u_short routeEdgePair[2];

extern u_char D_800F175C[];
int func_8008E320(int);
void func_800E4BE0(int);

static inline u_int routeWord(routeEdgePair* pair) { return *(u_int*)pair; }

static inline u_short routeHalf(routeEdgePair* pair, int index) { return (*pair)[index]; }

static inline u_int routeTile(int z, int x)
{
    return (*(u_short(**)[32])0x1F8003C0)[z][x];
}

static inline int routeSetArea(routeEdgeState* state, vs_battle_movementPosition position)
{
    state->area = routeTile(position.p.z, position.p.x) & 15;
    return 6;
}

int func_800DFBCC(routeEdgeState* state, int index, int area)
{
    routeEdgePair routes;
    int distances[2];
    vs_battle_movementPosition position;
    vs_battle_movementPosition candidate;
    int count;
    int i;
    int result;
    int amount;
    int x;
    int z;
    u_short route;
    u_char* direction;
    u_char* table;

    /* Both packed words are copied through u_int views. */
    position.raw = *(u_int*)&state->tile;
    *(u_int*)routes = (*(u_int**)0x1F8003F4)[area * 16 + index];
    if (!(routeWord(&routes) & 0x1BE0)) {
        return 6;
    }
    state->area = area;
    count = 1;
    if (routeWord(&routes) & 0x1BE00000) {
        count = 2;
    }

    for (i = 0; i < count; i++) {
        if (!i) {
            route = routeHalf(&routes, 0);
        } else {
            route = routeHalf(&routes, 1);
        }
        if (((route >> 5) & 31) != position.p.x || (route & 31) != position.p.z) {
            continue;
        }
        candidate = position;
        if (route & 0x400) {
            if (route & 0x8000) {
                continue;
            }
            result = func_800DFAF8((int)state, position.raw, 1);
            if (result >= 0 && func_8008E320(i = result >> 1) >= 0) {
                candidate.p.y = i + 2;
                if (!((((routeEdgeGlobals*)D_800F58BC)->closedGates >> candidate.p.y)
                        & 1)) {
                    state->gate = candidate.p.y;
                    if (state->id) {
                        func_800E4BE0(candidate.p.y);
                    }
                    func_800DF9A8((func_800DFA54_t*)&candidate, &state->exit);
                    goto accept;
                }
            }
            candidate.p.x = (route >> 5) & 31;
            candidate.p.z = route & 31;
            goto center;
        }
        if (route & 0x6000) {
            u_char* step;

            state->area = routeTile(candidate.p.z, candidate.p.x) & 15;
            state->unk5 = 0;
            amount = ((route >> 13) & 3) + 1;
            step = &D_800F175C[(route >> 11) & 3];
            candidate.p.x += amount * ((D_800F16EC_t*)0x1F8003EC)[*step].dx;
            candidate.p.z += amount * ((D_800F16EC_t*)0x1F8003EC)[*step].dz;
            result = func_800D954C((func_800D8400_t*)state, candidate.raw);
            if (result < 0) {
            center:
                if (state->target != 16
                    && ((routeEdgeActor**)0x1F80037C)[state->target]) {
                    state->moveX =
                        ((routeEdgeActor**)0x1F80037C)[state->target]->position[0];
                    state->moveZ =
                        ((routeEdgeActor**)0x1F80037C)[state->target]->position[2];
                } else {
                    state->moveX = candidate.p.x * 128 + 64;
                    state->moveZ = candidate.p.z * 128 + 64;
                }
                state->angle =
                    ratan2(state->x - state->moveX, state->z - state->moveZ) & 0xFFF;
                state->cooldown = state->period;
                return 4;
            }
            if (result <= 0) {
                continue;
            }
        stop:
            candidate.p.y = 0;
        accept:
            state->next = candidate;
            return 14;
        }
        table = D_800F175C;
        direction = &table[(route >> 11) & 3];
        candidate.p.x += ((D_800F16EC_t*)0x1F8003EC)[*direction].dx;
        candidate.p.z += ((D_800F16EC_t*)0x1F8003EC)[*direction].dz;
        if (func_800D954C((func_800D8400_t*)state, candidate.raw) <= 0) {
            goto center;
        }
        if ((*(u_short(**)[32])0x1F8003BC)[candidate.p.z][candidate.p.x] & 0x1C00) {
            goto stop;
        }
        if (((*(u_char**)0x1F8003C4)[position.p.z * *(u_char*)0x1F8003DC + position.p.x]
                >> *direction)
            & 1) {
            goto stop;
        }
        state->heading = *direction;
        return 5;
    }

    if ((routeWord(&routes) & 0x8400) == 0x8400) {
        if (count == 1) {
        areaOnly:
            return routeSetArea(state, position);
        }
        if ((routeWord(&routes) & 0x84000000) == 0x84000000) {
            goto areaOnly;
        }
        goto second;
    }
    if ((routeWord(&routes) & 0x84000000) == 0x84000000) {
        goto first;
    }

    for (i = 0; i < count; i++) {
        if (!i) {
            route = routeHalf(&routes, 0);
        } else {
            route = routeHalf(&routes, 1);
        }
        if (!((*(u_short(**)[32])0x1F8003BC)[route & 31][(route >> 5) & 31] & 0x1C00)) {
            continue;
        }
        if (i) {
            route = routeHalf(&routes, 0);
        } else {
            route = routeHalf(&routes, 1);
        }
        if (((*(u_short(**)[32])0x1F8003BC)[route & 31][(route >> 5) & 31] & 0x1C00)
            || count == 1) {
            state->area = (*(u_short(**)[32])0x1F8003C0)[position.p.z][position.p.x] % 16;
            return 6;
        }
        state->destination.raw = ((route & 31) << 16) | ((route >> 5) & 31);
        return 6;
    }

    x = position.p.x;
    if (count == 1) {
        if (((state->destination.raw = ((routeHalf(&routes, 0) & 31) << 16)
                                     | ((routeWord(&routes) >> 5) & 31))
                & 0xFF00FF)
            == (state->tile.raw & 0xFF00FF)) {
            goto center;
        }
        return 6;
    }
    z = position.p.z;
    distances[0] =
        (x - ((routeWord(&routes) >> 5) & 31)) * (x - ((routeWord(&routes) >> 5) & 31))
        + (z - (routeHalf(&routes, 0) & 31)) * (z - (routeHalf(&routes, 0) & 31));
    x -= (routeWord(&routes) >> 21) & 31;
    z -= (routeWord(&routes) >> 16) & 31;
    distances[1] = x * x + z * z;
    if (distances[0] < distances[1]) {
    first:
        state->destination.raw =
            ((routeHalf(&routes, 0) & 31) << 16) | ((routeWord(&routes) >> 5) & 31);
    } else {
    second:
        state->destination.raw =
            (routeWord(&routes) & 0x1F0000) | ((routeWord(&routes) >> 21) & 31);
    }
    if ((state->destination.raw & 0xFF00FF) == (state->tile.raw & 0xFF00FF)) {
        goto center;
    }
    return 6;
}

typedef struct {
    short x, y, z, pad;
} obstructionVector;
typedef struct {
    char pad[0x1C];
    obstructionVector position;
} obstructionModel;
typedef struct {
    char pad0[0x4C];
    obstructionVector position;
    char pad54[4];
    obstructionModel* model;
    char pad5C[0x2C];
    unsigned char id;
    char pad89[9];
    unsigned short radius;
    char pad94[0x1F];
    unsigned char step;
    char padB4[4];
    short height;
} obstructionState;
typedef struct {
    unsigned char p0, p1, tested, p3, result[8];
} obstructionCache;
#define OBSTRUCTION_CACHE ((obstructionCache*)0x1F8003D0)
#define OBSTRUCTION_DIRECTIONS ((D_800F16EC_t*)0x1F8003EC)
#define OBSTRUCTION_STATES ((obstructionState**)0x1F80037C)

int func_800E02B4(obstructionState* state, int direction, int ahead)
{
    obstructionVector points[4];
    int x, y, z, i, dx, dy, dz;
    unsigned int radius, height;
    vs_battle_actor* actor;
    obstructionState* other;
    obstructionModel* model;
    if ((OBSTRUCTION_CACHE->tested >> direction) & 1)
        return OBSTRUCTION_CACHE->result[direction];
    x = state->position.x + ahead * (state->step * OBSTRUCTION_DIRECTIONS[direction].dx);
    y = state->position.y;
    z = state->position.z + ahead * (state->step * OBSTRUCTION_DIRECTIONS[direction].dz);
    i = func_8008D2C0((void*)points);
    for (i = i - 1; i != -1; i--) {
        dx = points[i].x - x;
        dy = points[i].y - y;
        dz = points[i].z - z;
        if (ahead) {
            if (OBSTRUCTION_DIRECTIONS[direction].dx > 0 && dx < 0)
                continue;
            if (OBSTRUCTION_DIRECTIONS[direction].dx < 0 && dx > 0)
                continue;
            if (OBSTRUCTION_DIRECTIONS[direction].dz > 0 && dz < 0)
                continue;
            if (OBSTRUCTION_DIRECTIONS[direction].dz < 0 && dz > 0)
                continue;
        }
        radius = state->radius + 96;
        height = (state->height + 32) >> 1;
        if ((unsigned int)ABS(dx) <= radius && (unsigned int)ABS(dz) <= radius
            && (unsigned int)ABS(dy) <= height) {
            OBSTRUCTION_CACHE->tested |= 1 << direction;
            OBSTRUCTION_CACHE->result[direction] = 1;
            return 1;
        }
    }
    for (actor = vs_battle_actors[0]; actor; actor = actor->next) {
        other = OBSTRUCTION_STATES[actor->id];
        model = other->model;
        if (other->id == state->id || !other->id)
            continue;
        dx = model->position.x - x;
        dy = model->position.y - y;
        dz = model->position.z - z;
        if (ahead) {
            if (OBSTRUCTION_DIRECTIONS[direction].dx > 0 && dx < 0)
                continue;
            if (OBSTRUCTION_DIRECTIONS[direction].dx < 0 && dx > 0)
                continue;
            if (OBSTRUCTION_DIRECTIONS[direction].dz > 0 && dz < 0)
                continue;
            if (OBSTRUCTION_DIRECTIONS[direction].dz < 0 && dz > 0)
                continue;
        }
        radius = other->radius + state->radius + other->step;
        if (!other->id)
            height = -1;
        else
            height = (state->height + other->height) >> 1;
        if ((unsigned int)ABS(dx) <= radius && (unsigned int)ABS(dz) <= radius
            && (unsigned int)ABS(dy) <= height) {
            OBSTRUCTION_CACHE->tested |= 1 << direction;
            OBSTRUCTION_CACHE->result[direction] = actor->id + 1;
            return actor->id + 1;
        }
    }
    OBSTRUCTION_CACHE->tested |= 1 << direction;
    OBSTRUCTION_CACHE->result[direction] = 0;
    return 0;
}

#undef OBSTRUCTION_CACHE
#undef OBSTRUCTION_DIRECTIONS
#undef OBSTRUCTION_STATES

typedef union {
    unsigned int raw;
    struct {
        unsigned char x, y, z, w;
    } p;
} directionalCachePoint;
typedef struct directionalCacheState {
    char pad[0x34];
    directionalCachePoint tile, previous;
    char pad3C[0x82];
    short minimumHeight;
} directionalCacheState;

int func_800E42EC(int, int);
typedef struct {
    unsigned char tested, valid;
} directionalCacheBits;
#define MOVEMENT_CHECK_CACHE ((directionalCacheBits*)0x1F8003D0)
#define MOVEMENT_CHECK_DIRECTIONS ((D_800F16EC_t*)0x1F8003EC)
#define MOVEMENT_CHECK_TILES (*(unsigned short(**)[32])0x1F8003C0)
int func_800E0678(directionalCacheState* state, int direction)
{
    int x, z;
    if ((MOVEMENT_CHECK_CACHE->tested >> direction) & 1)
        return (MOVEMENT_CHECK_CACHE->valid & (1 << direction)) > 0;
    if (func_800E02B4((void*)state, direction, 1))
        goto invalid;
    x = state->tile.p.x + MOVEMENT_CHECK_DIRECTIONS[direction].dx;
    z = state->tile.p.z + MOVEMENT_CHECK_DIRECTIONS[direction].dz;
    if (x > D_800F58BC->maxX || x < D_800F58BC->minX || z > D_800F58BC->maxZ
        || z < D_800F58BC->minZ)
        goto invalid;
    if (MOVEMENT_CHECK_TILES[z][x] & 0x40)
        goto invalid;
    if (state->previous.p.x == x && state->previous.p.z == z)
        goto invalid;
    if (D_800F58BC->unk14
        && func_800E42EC(x, z) + state->minimumHeight < D_800F58BC->unk14)
        return 0;
    MOVEMENT_CHECK_CACHE->tested |= 1 << direction;
    MOVEMENT_CHECK_CACHE->valid |= 1 << direction;
    return 1;
invalid:
    MOVEMENT_CHECK_CACHE->tested |= 1 << direction;
    MOVEMENT_CHECK_CACHE->valid &= ~(1 << direction);
    return 0;
}

#undef MOVEMENT_CHECK_CACHE
#undef MOVEMENT_CHECK_DIRECTIONS
#undef MOVEMENT_CHECK_TILES

int func_800E0850(func_800E0850_t* arg0, u_int arg1)
{
    int min = 0;
    int count = 1;

    if (arg1 & 0x3FF) {
        count = 3;
    }
    arg1 = (arg1 >> 9) & 6;
    while (--count != -1) {
        if (func_800E0678((void*)arg0, arg1) != 0) {
            int h = func_800E42EC(arg0->unk34 + ((D_800F16EC_t*)0x1F8003EC)[arg1].dx,
                arg0->unk36 + ((D_800F16EC_t*)0x1F8003EC)[arg1].dz);
            if (h < min) {
                min = h;
            }
        }
        arg1 = (arg1 + 1) & 7;
    }
    return min;
}

typedef struct {
    char pad0[8];
    unsigned int flags;
} movementCheckObject;
typedef struct movementCheckState {
    char pad0[0x34];
    int position;
    char pad38[0x20];
    movementCheckObject* object;
    char pad5C[0x62];
    short height;
    char padC0[0x9E];
    unsigned short flags;
    char pad160[8];
    int target;
} movementCheckState;
void func_800E4B2C();
void func_800E4B70();
unsigned int func_800E45F4(unsigned int, unsigned int);
int func_800E42E0(unsigned int);
void func_800E4B10(void*);
int func_800E0918(movementCheckState* state, int action, int mode)
{
    void (*callback)(movementCheckState*, int);
    unsigned int distance;
    if (mode)
        callback = (void (*)(movementCheckState*, int))func_800E4B2C;
    else
        callback = (void (*)(movementCheckState*, int))func_800E4B70;
    if (state->flags & 6) {
        distance = func_800E45F4(state->target, state->position);
        if (mode && distance < 16) {
            if (!(state->object->flags & 0x200000)) {
                callback(state, action);
                return 1;
            }
        } else if (D_800F58BC->unk14) {
            if (func_800E42E0(state->position) + state->height < D_800F58BC->unk14) {
                if (state->object->flags & 0x200000) {
                    if (func_800D954C((void*)state, state->position) > 0) {
                        func_800E678C((void*)state);
                        func_800E4B10(state);
                        return 1;
                    }
                } else {
                    callback(state, action);
                    return 1;
                }
            }
        }
    }
    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/771A8", func_800E0A68);

void func_800E1238(func_800E0850_t* arg0, int arg1)
{
    int sp10;
    int sp14;
    int angle;
    int c;
    int s;

    if (func_800E0918((void*)arg0, arg1, 0) != 0) {
        return;
    }

    if (func_800E4764(arg0, &sp10, &sp14) == 0) {
        func_800E2CCC((void*)arg0);
        return;
    }

    arg0->unk7 = 1;
    func_800E3600(arg0, arg1, 3);

    if (*(int*)0x1F8003C8 != 5 && *(int*)0x1F8003C8 != 7) {
        func_800E678C(arg0);
        func_800E2CCC((void*)arg0);
        return;
    }

    if (*(int*)0x1F8003C8 == 5) {
        arg1 = arg0->unk188 * (ONE / 8);
    }

    angle = (-arg1 + ONE * 3 / 4) & 0xFFF;
    c = rcos(angle);
    s = rsin(angle);

    if (func_800E0850(arg0, arg1) + arg0->unkBE < arg0->unk4E) {
        arg0->unk184 = -ONE;
        arg0->unk180 = 0;
        arg0->unk17C = 0;
    } else {
        arg0->unk184 = 0;
        arg0->unk17C = c;
        arg0->unk180 = s;
    }

    if (!(arg0->unk58->unk8_21 << 21)) {
        func_800E4B18(arg0);
    } else {
        arg0->unk228 = 0;
        func_800DEEFC(arg0, sp14);
    }
}

void func_800E1388(func_800D8400_t* state, vs_battle_movementPosition source, int angle,
    unsigned int distance)
{
    vs_battle_movementPosition dest;
    int i, x, z, heading;
    unsigned int step;
    angle = -angle;
    angle += 0xC00;
    heading = angle & 0xFFF;
    step = distance >> 3;

    for (i = 0; i < 8; i++, distance -= step) {
        x = ((int)(distance * rcos(heading)) >> 12) + 64;
        dest.p.x = (int)(source.p.x * 128 + x) >> 7;
        z = ((int)(distance * rsin(heading)) >> 12) + 64;
        dest.p.z = (int)(source.p.z * 128 + z) >> 7;
        if (func_800D954C(state, dest.raw) > 0)
            break;
    }
    if (dest.p.x < D_800F58BC->minX)
        dest.p.x = D_800F58BC->minX;
    else if (dest.p.x > D_800F58BC->maxX)
        dest.p.x = D_800F58BC->maxX;
    if (dest.p.z < D_800F58BC->minZ)
        dest.p.z = D_800F58BC->minZ;
    else if (dest.p.z > D_800F58BC->maxZ)
        dest.p.z = D_800F58BC->maxZ;
    state->destination = dest;
}

typedef struct {
    char pad0[0xD];
    unsigned char flagD;
    char padE[0x26];
    vs_battle_movementPosition position;
    char pad38[0x10];
    vs_battle_movementPosition previous;
    short x;
    char pad4E[2];
    short z;
    char pad52[0x3A];
    unsigned short attempts;
    char pad8E[0x26];
    int distance;
    char padB8[0xA6];
    unsigned short flags;
    char pad160[8];
    vs_battle_movementPosition destination;
    char pad16C[4];
    vs_battle_movementPosition next;
    char pad174[8];
    int referenceX, referenceZ;
} movementDestinationState;
unsigned int func_800E4660(int, int, int);
unsigned int func_800E45F4(unsigned int, unsigned int);
void func_800E4B2C(movementDestinationState*, int);
void func_800E153C(movementDestinationState* state, int unused)
{
    int distance = state->distance;
    int angle, i;
    vs_battle_movementPosition dest;
    if ((state->position.raw & 0xFF00FF) == (state->destination.raw & 0xFF00FF))
        goto fallback;
    angle = ratan2(state->x - state->destination.p.x * 128 - 64,
        state->z - state->destination.p.z * 128 - 64);
    if (func_800E4660(state->destination.p.x * 128 - state->x + 64, 0,
            state->destination.p.z * 128 - state->z + 64)
        > (unsigned int)(distance * distance))
        func_800E1388((void*)state, state->position, angle, distance);
    if ((state->flags & 6)
        && (state->flagD
            || func_800E45F4(state->destination.raw, state->position.raw) < 16)) {
        if ((int)(state->previous.raw << 8) >= 0)
            state->destination = state->previous;
        func_800E4B2C(state, angle);
        return;
    }
    if (++state->attempts < 6)
        goto fallback;
    dest = state->destination;
    if (func_800D954C((void*)state, dest.raw) > 0)
        goto begin;
    for (i = 0; i < 4; i++) {
        dest.p.x = state->destination.p.x + ((D_800F16EC_t*)0x1F8003EC)[i * 2].dx;
        dest.p.z = state->destination.p.z + ((D_800F16EC_t*)0x1F8003EC)[i * 2].dz;
        if (func_800D954C((void*)state, dest.raw) > 0) {
            state->destination = dest;
            goto begin;
        }
    }
    goto fallback;
begin:
    state->attempts = 0;
    state->next = state->destination;
    func_800DEEFC((void*)state, 13);
    return;
fallback:
    func_800E2CCC((void*)state);
}
void func_800E1764(movementDestinationState* state, int angle)
{
    unsigned int previous[1];
    unsigned int distance;
    int opposite = (angle + 0x800) & 0xFFF;
    func_800E1388((void*)state, state->position, angle, state->distance);
    previous[0] = state->destination.raw;
    func_800E1388((void*)state, state->position, opposite, state->distance);
    distance = func_800E4660(state->destination.p.x * 128 - state->referenceX + 64, 0,
        state->destination.p.z * 128 - state->referenceZ + 64);
    if (distance
        < func_800E4660(((unsigned char*)&previous)[0] * 128 - state->referenceX + 64, 0,
            ((unsigned char*)&previous)[2] * 128 - state->referenceZ + 64))
        state->destination.raw = previous[0];
    func_800E153C(state, angle);
}

u_char func_800E1850(u_char arg0, u_int arg1, int arg2)
{
    int x = arg1 & 0xFF;
    int z = (arg1 >> 16) & 0xFF;
    int i;

    for (i = 0; i < 8; ++i) {
        if ((arg0 >> i) & 1) {
            if (func_800E42EC(x + ((D_800F16EC_t*)0x1F8003EC)[i].dx,
                    z + ((D_800F16EC_t*)0x1F8003EC)[i].dz)
                > arg2) {
                arg0 &= ~(1 << i);
            }
        }
    }
    return arg0;
}

typedef union {
    unsigned int raw;
    struct {
        unsigned char x, y, z, w;
    } p;
} terrainMovementPoint;
typedef struct terrainMovementActor {
    char pad0[9];
    unsigned char mode;
    char padA[2];
    unsigned short angle;
} terrainMovementActor;
typedef struct terrainMovementState {
    char pad0[2];
    unsigned char f2;
    char pad3[1];
    unsigned char f4;
    unsigned char f5;
    char pad6[20];
    unsigned char f1A;
    char pad1B[14];
    unsigned char f29;
    char pad2A[10];
    terrainMovementPoint tile;
    char pad38[20];
    short position[3];
    char pad52[2];
    terrainMovementActor* actor;
    char pad58[272];
    terrainMovementPoint destination;
    char pad16C[16];
    int targetX;
    int targetZ;
    char pad184[4];
    short angle;
} terrainMovementState;
#define TERRAIN_TILE_MASK (*(unsigned char**)0x1F8003C4)
#define TERRAIN_MAP_WIDTH (*(unsigned char*)0x1F8003DC)
#define TERRAIN_MOVE_RESULT (*(int*)0x1F8003C8)
#define TERRAIN_TILES (*(unsigned short(**)[32])0x1F8003C0)
struct routeEdgeState;
int func_800DFBCC(struct routeEdgeState*, int, int);
void func_800E4BB8(terrainMovementState*);
void func_800E4B70(terrainMovementState*, int);
void func_800E1908(terrainMovementState* state)
{
    unsigned char* tile =
        &TERRAIN_TILE_MASK[state->tile.p.z * TERRAIN_MAP_WIDTH + state->tile.p.x];
    int old = *tile;
    terrainMovementActor* actor = state->actor;
    int mode;
    *tile = func_800E1850(old, state->tile.raw, state->position[1]);
    func_800E3600((void*)state,
        ratan2(state->position[0] - state->targetX, state->position[2] - state->targetZ)
            & 0xFFF,
        0);
    *tile = old;
    mode = TERRAIN_MOVE_RESULT;
    if ((0xA0 >> mode) & 1) {
        actor->mode = 9;
        if (mode == 5)
            actor->angle = state->angle << 9;
        else
            actor->angle = state->angle;
    }
}
void func_800E19FC(terrainMovementState* state)
{
    int current, next, mode;
    int active = 1;
    state->f4 = 0;
    state->f5 = active;
    if (state->f1A) {
        func_800E1908(state);
        return;
    }
    current = TERRAIN_TILES[state->tile.p.z][state->tile.p.x] & 15;
    next = TERRAIN_TILES[state->destination.p.z][state->destination.p.x] & 15;
    if (current != next) {
        if (state->f29) {
            mode = func_800DFBCC((struct routeEdgeState*)state, current, next);
            if (mode == 6) {
                state->targetX = (state->destination.p.x << 7) + 64;
                state->targetZ = (state->destination.p.z << 7) + 64;
                if ((TERRAIN_TILES[state->destination.p.z][state->destination.p.x] & 15)
                    == (TERRAIN_TILES[state->tile.p.z][state->tile.p.x] & 15))
                    goto move;
            } else {
                func_800E4BB8(state);
                if (mode == 5)
                    func_800E4B70(state, state->angle << 9);
                else
                    func_800DEEFC((void*)state, mode);
                return;
            }
        }
        state->f2 = active;
        *(unsigned char*)0x1F8003D0 = 0;
    }
move:
    func_800E3600((void*)state,
        ratan2(state->position[0] - state->targetX, state->position[2] - state->targetZ)
            & 0xFFF,
        0);
}

#undef TERRAIN_TILE_MASK
#undef TERRAIN_MAP_WIDTH
#undef TERRAIN_MOVE_RESULT
#undef TERRAIN_TILES

typedef struct {
    char pad0[8];
    unsigned int flags;
} wanderObject;
typedef struct wanderState {
    char pad0[2];
    unsigned char flag2;
    unsigned char flag3;
    char pad4[4];
    unsigned char flag8;
    char pad9[0x2B];
    vs_battle_movementPosition tile;
    char pad38[0x10];
    vs_battle_movementPosition saved;
    short x, y, z;
    char pad52[6];
    wanderObject* object;
    char pad5C[0x58];
    unsigned int moveArg;
    char padB8[8];
    unsigned short mode;
    unsigned short timer;
    int rangeSquared;
    char padC8[8];
    short angle;
    unsigned short cooldown;
    unsigned short restPeriod;
    unsigned short movePeriod;
    unsigned char rate;
    char padD9[0x43];
    vs_battle_movementPosition goal;
    char pad120[13];
    unsigned char mode12D;
    char pad12E[0x2F];
    unsigned char count;
    unsigned short flags;
    char pad160[8];
    vs_battle_movementPosition dest;
} wanderState;

#define WANDER_DIRECTIONS ((D_800F16EC_t*)0x1F8003EC)
#define WANDER_TILES (*(unsigned short(**)[32])0x1F8003C0)

int func_800E4690(unsigned int, int);
int D_800D9B6C(wanderState*, int);

static inline D_800F16EC_t* wanderDirection(int index)
{
    return WANDER_DIRECTIONS + index;
}

int func_800E1BB8(wanderState* state, unsigned int tile, unsigned int maxCount, int arg3)
{
    vs_battle_movementPosition candidate;
    int count = 0;
    int choices[4];
    int i;
    unsigned int chosen;

    if (!maxCount)
        return -1;
    if (!state->count)
        state->goal.raw = tile;
    candidate = state->goal;
    for (i = 0; i < 4; i++) {
        if (!(state->flags & 8)) {
            D_800F16EC_t offset;
            if (*(int*)0x1F8003F4)
                candidate.p.y =
                    (*(unsigned char**)0x1F8003C4)[state->goal.p.z
                                                       * (*(unsigned char*)0x1F8003DC)
                                                   + state->goal.p.x]
                        >> i * 2
                    & 1;
            else
                candidate.p.y = func_800E4690(state->goal.raw, i * 2);
            offset = *wanderDirection(i * 2);
            candidate.p.x = state->goal.p.x + offset.dx;
            candidate.p.z = state->goal.p.z + offset.dz;
            if (candidate.p.y) {
                if (!func_800D96C8(
                        (func_800D8400_t*)state, state->goal.raw, candidate.raw, i * 2))
                    continue;
                candidate.p.y = 0;
            }
            if (!state->flag2
                && (WANDER_TILES[candidate.p.z][candidate.p.x] & 15)
                       != (WANDER_TILES[state->goal.p.z][state->goal.p.x] & 15))
                continue;
        }
        if (!(WANDER_TILES[candidate.p.z][candidate.p.x] & 32))
            choices[count++] = i * 2;
    }
    if (!count)
        return -1;
    chosen = (unsigned int)func_800E45D4(4096) % count;
    if (state->angle > 0 && ((state->angle + 4) & 7) == choices[chosen])
        chosen = (unsigned int)func_800E45D4(4096) % count;
    state->goal.p.x += WANDER_DIRECTIONS[choices[chosen]].dx;
    state->goal.p.z += WANDER_DIRECTIONS[choices[chosen]].dz;
    state->angle = choices[chosen];
    state->count++;
    return maxCount < state->count;
}

static inline int wanderRandomHeading(int direction)
{
    int offset = func_800E45D4(512);
    int angle = direction << 9;
    offset += 0xFF00;
    return angle + offset;
}

static inline void wanderStartWalk(wanderState* s)
{
    s->angle = -1;
    s->count = 0;
    s->cooldown = 60;
    s->mode++;
    func_800E2CCC((movementRecoveryState*)s);
}

void func_800E1EAC(wanderState* state, unsigned int tile, unsigned int range)
{
    unsigned short rest, move;
    int rate, i, heading, x, z, value, result;
    int (*check)(wanderState*, int);

    state->timer++;
    rate = state->rate;
    rest = state->restPeriod;
    move = state->movePeriod;
    if (state->object->flags & 0x200000)
        check = (int (*)(wanderState*, int))func_800E0678;
    else
        check = D_800D9B6C;
    if (state->mode12D == 1) {
        if (state->timer < 31)
            return;
        if ((unsigned int)func_800E45D4(128) < 44)
            state->mode12D = 2;
        else {
            state->timer = 0;
            return;
        }
    }
    if (state->timer == move) {
        if ((unsigned int)func_800E45D4(128) < 44)
            state->timer = 0;
    } else if (state->timer >= rest + move) {
        state->timer = (unsigned int)func_800E45D4(128) < 44 ? move : 0;
    }
    state->flag2 = 1;
    *(unsigned char*)0x1F8003D0 = 0;
    value = state->timer < move;
    if (!value)
        goto recover;
    if (range >= 63) {
        if (!state->mode || !func_800E45D4(1 << rate) || !state->cooldown) {
            value = (unsigned int)func_800E45D4(4096) % range + 128;
            state->mode = 1;
            state->cooldown = 60;
            state->rangeSquared = value * value;
            heading = func_800E45D4(4) * 2;
            for (i = 0; i < 4; i++) {
                int direction = (heading + i * 2) & 7;
                if (check(state, direction)) {
                    state->angle = wanderRandomHeading(direction);
                    break;
                }
            }
            if (i == 4)
                state->angle = func_800E45D4(4096);
        }
        if (!state->flag8)
            state->cooldown = 60;
        else if (state->cooldown)
            state->cooldown--;
        if (state->flags & 8)
            func_800E1388(
                (func_800D8400_t*)state, state->tile, state->angle, state->moveArg);
        {
            int boundsHeading = state->angle >> 9;
            int boundsIndex;
            for (boundsIndex = 0; boundsIndex < 2;
                boundsHeading = (boundsHeading + 2) & 7, boundsIndex++) {
                x = state->tile.p.x + WANDER_DIRECTIONS[boundsHeading].dx;
                z = state->tile.p.z + WANDER_DIRECTIONS[boundsHeading].dz;
                if (D_800F58BC->maxZ < z || z < D_800F58BC->minZ || D_800F58BC->maxX < x
                    || x < D_800F58BC->minX || (WANDER_TILES[z][x] & 0x800)) {
                    state->cooldown = 0;
                    break;
                }
            }
        }
        func_800E50A0(state, 1, state->angle);
        return;
    }
    state->flag3 = 1;
    if (!func_800E45D4(1 << rate))
        state->mode = 0;
    switch (state->mode) {
    case 0:
        wanderStartWalk(state);
        return;
    case 1:
        result = func_800E1BB8(state, tile, range, 3);
        if (result < 0)
            state->mode = 0;
        else if (result > 0) {
            state->mode++;
            state->dest = state->goal;
        }
        break;
    case 2:
        state->dest = state->goal;
        if (state->flags & 8) {
            heading = ratan2(state->x - state->dest.p.x * 128 - 64,
                          state->z - state->dest.p.z * 128 - 64)
                    & 4095;
            state->saved = state->dest;
            func_800E1388((func_800D8400_t*)state, state->tile, heading, state->moveArg);
        }
        func_800E50A0(state, 0, 0);
        if (!state->flag8)
            state->cooldown = 60;
        else if (state->cooldown)
            state->cooldown--;
        if ((state->dest.raw & 0xFF00FF) == (state->tile.raw & 0xFF00FF)
            || !state->cooldown)
            state->mode = 0;
        return;
    default:
        state->mode = 0;
    }
recover:
    func_800E2CCC((movementRecoveryState*)state);
}

#undef WANDER_DIRECTIONS
#undef WANDER_TILES

typedef struct {
    char pad0[0x34];
    vs_battle_movementPosition tile;
    char pad38[0xC8];
    unsigned char index, row, rate, direction, timer;
    char pad105[0x63];
    vs_battle_movementPosition dest;
} patrolWaypointState;
extern unsigned short (*D_800F58D8)[8];
void func_800E50A0(void*, int, int);
static inline unsigned int patrolWaypoint(unsigned short* row, int index)
{
    unsigned short* ptr = row;
    ptr += index;
    return *ptr;
}
void func_800E23AC(patrolWaypointState* state)
{
    unsigned short* row;
    unsigned int entry;
    int step;
    row = D_800F58D8[state->row];
    entry = patrolWaypoint(row, state->index);
    if (state->tile.p.x != (entry & 31) || state->tile.p.z != ((entry >> 5) & 31)) {
        if (state->timer)
            state->timer--;
        if (func_800E45D4(1 << state->rate) || state->timer)
            goto move;
        state->direction = -state->direction;
    }
    step = state->direction + 8;
    do {
        state->index = (state->index + step) & 7;
    } while (!(patrolWaypoint(row, state->index) >> 15));
    state->timer = 10;
move:
    state->dest.p.x = patrolWaypoint(row, state->index) & 31;
    state->dest.p.z = (patrolWaypoint(row, state->index) >> 5) & 31;
    func_800E50A0(state, 0, 0);
}

typedef union {
    unsigned int raw;
    unsigned char b[4];
} targetMovementPoint;
typedef struct {
    unsigned int f0 : 1, f1 : 1, f2 : 1, pad3 : 2, f5 : 1, pad6 : 26;
} targetMovementFlags;
typedef struct {
    char pad[9];
    unsigned char id;
} targetMovementActor;
typedef struct {
    char pad0[8];
    unsigned int flags;
    char padC[16];
    short x;
    char pad1E[2];
    short z;
} targetMovementModel;
typedef struct targetMovementState {
    unsigned char b0;
    unsigned char b1;
    char pad2[1];
    unsigned char b3;
    unsigned char b4;
    char pad5[4];
    unsigned char b9;
    char padA[2];
    unsigned char bC;
    unsigned char bD;
    char padE[22];
    unsigned char b24;
    char pad25[14];
    unsigned char b33;
    vs_battle_movementPosition tile;
    char pad38[16];
    targetMovementPoint previousDestination;
    short x;
    char pad4E[2];
    short z;
    char pad52[2];
    targetMovementActor* actor;
    targetMovementModel* model;
    char pad5C[44];
    unsigned char id;
    char pad89[83];
    int range;
    int previousRange;
    unsigned char bE4;
    unsigned char targetId;
    unsigned char timeout;
    unsigned char bE7;
    unsigned char bE8;
    unsigned char rangeMode;
    unsigned char previousOption;
    unsigned char previousTargetId;
    targetMovementPoint cachedDestination;
    char padF0[4];
    unsigned char targetTileX;
    char padF5[1];
    unsigned char targetTileZ;
    char padF7[1];
    unsigned short timer;
    char padFA[94];
    short destinationX;
    short destinationZ;
    unsigned char movementTargetId;
    char pad15D[1];
    unsigned short flags15E;
    char pad160[8];
    targetMovementPoint destination;
    char pad16C[16];
    int targetX;
    int targetZ;
    char pad184[32];
    targetMovementFlags targets[16];
    unsigned int distances[16];
} targetMovementState;
int func_800E4FB0(void*, int, int);
void func_800E50A0(void*, int, int);
int func_800E4180(void*, int, int, int);
void func_800E4904(void*);

int func_800E24EC(targetMovementState* s, int option)
{
    int result = 1, target = s->targetId, mode, value, angle, distance, one, radius;
    unsigned int oldPosition;
    targetMovementModel* model;
    if (target == s->id) {
        func_800DEEFC((void*)s, 0);
        goto done;
    }
    model = (targetMovementModel*)D_800F4538[target];
    if (s->model->flags & 0x200000)
        option = 1;
    if ((!(model->flags & 0x1F0000)
                ? ((model->x >> 6) != s->targetTileX || (model->z >> 6) != s->targetTileZ)
                : (s->destination.b[0] != (s->targetTileX >> 1)
                      || s->destination.b[2] != (s->targetTileZ >> 1)))
        || s->range != s->previousRange || target != s->previousTargetId
        || option != s->previousOption || s->timer++ > 180) {
        s->timer = 0;
        s->bE8 = 0;
        s->bE7 = 0;
    }
    s->previousOption = option;
    s->previousTargetId = target;
    s->previousRange = s->range;
    if (s->targets[target].f0) {
        s->bE4 = 0;
        if (s->targets[target].f2) {
            mode = s->rangeMode;
            switch (mode) {
            case 0:
                if ((unsigned int)((s->range - 96) * (s->range - 96))
                    < s->distances[target])
                    s->rangeMode = 0;
                else
                    s->rangeMode = 1;
                break;
            case 1:
                value = s->range;
                if ((unsigned int)(value * value) < s->distances[target]) {
                out_of_range:
                    s->rangeMode = 0;
                } else {
                    if ((unsigned int)((value - 128) * (value - 128))
                        >= s->distances[target])
                        s->rangeMode = 2;
                    else
                        s->rangeMode = mode;
                }
                break;
            case 2:
                if ((unsigned int)((s->range - 32) * (s->range - 32))
                    < s->distances[target])
                    s->rangeMode = 1;
                else
                    s->rangeMode = mode;
                break;
            }
        } else
            goto out_of_range;
        if ((s->rangeMode != 2 && s->bE8) || (s->rangeMode != 0 && s->bE7))
            goto recover;
        if (option == 0 && s->rangeMode == 2)
            s->rangeMode = 1;
        one = 1;
        switch (s->rangeMode) {
        case 0:
            if (option == one)
                s->b0 = one;
            s->bC = one;
            s->b1 = func_800E4FB0(s, target, s->range);
            if (s->flags15E & 8) {
                oldPosition = s->destination.raw;
                angle = ratan2(s->x - (s->destination.b[0] << 7) - 64,
                            s->z - (s->destination.b[2] << 7) - 64)
                      & 4095;
                distance = func_800E4660(s->x - (s->destination.b[0] << 7) - 64, 0,
                    s->z - (s->destination.b[2] << 7) - 64);
                s->previousDestination.raw = oldPosition;
                distance = vs_gte_rsqrt(distance);
                radius = s->range - 96;
                func_800E1388((void*)s, s->tile, angle,
                    distance - (radius >= 0 ? radius : -radius));
                if ((s->destination.raw & 0xFF00FF) == (s->tile.raw & 0xFF00FF)) {
                    s->bD = one;
                    s->destination.raw = oldPosition;
                }
            }
            s->movementTargetId = s->targetId;
            func_800E50A0(s, 0, 0);
            break;
        case 1:
        recover:
            s->movementTargetId = target;
            func_800E2CCC((void*)s);
            break;
        case 2:
            s->b3 = one;
            *(unsigned char*)0x1F8003D0 = 0;
            s->b4 = one;
            s->targetX = model->x;
            s->targetZ = model->z;
            if (s->b33) {
                s->b1 = one;
                s->b9 = one;
                s->destinationX = s->targetX;
                s->destinationZ = s->targetZ;
            } else
                s->movementTargetId = target;
            angle = ratan2(s->targetX - s->x, s->targetZ - s->z);
            func_800E50A0(s, 1, angle);
            if (s->actor->id >= 9)
                s->bE8 = 1;
            break;
        }
    } else {
        if (!s->bE4 && s->targets[target].f1) {
            if (s->b24) {
                s->bE4 = 1;
                s->timeout = 255;
                s->cachedDestination.b[0] = s->targetTileX >> 1;
                s->cachedDestination.b[2] = s->targetTileZ >> 1;
            } else {
                if (s->targets[target].f5) {
                    result = 0;
                    goto done;
                }
                func_800D8260((void*)s, 7, 40);
                if (!func_800E4180(s, 128, 1, 1))
                    result = 0;
                goto done;
            }
        }
        if (s->bE8)
            goto recover;
        if (s->bE4) {
            s->destination.raw = s->cachedDestination.raw;
            if (s->timeout)
                s->timeout--;
            if ((s->destination.raw & 0xFF00FF) == (s->tile.raw & 0xFF00FF)) {
                if (s->targets[target].f5) {
                    result = 0;
                    goto done;
                }
                func_800D8260((void*)s, 7, 40);
                if (!func_800E4180(s, 128, 1, 1)) {
                cancel:
                    s->bE4 = 0;
                    result = 0;
                }
            } else if (s->timeout) {
                s->b1 = 1;
                s->bC = 1;
                func_800E50A0(s, 0, 0);
            } else
                goto cancel;
        } else if (!func_800E4180(s, 0, 3, 1))
            result = 0;
    }
    goto done;

done:
    func_800E4904(s);
    return result;
}

typedef struct {
    char prefix[0x4C];
    short x;
    short padding4E;
    short z;
    char padding52[6];
    D_800F4538_t* actor;
    char padding5C[0x2C];
    u_char actorId;
    char padding89[0x31];
    u_short delay;
    char paddingBC[0x4C];
    int previousDestination;
    u_char pending;
    char padding10D[0x2D];
    u_short timer;
    char padding13C[0x2C];
    int destination;
    char padding16C[0x10];
    int targetX;
    int targetZ;
    char padding184[4];
    u_int padding188 : 16;
    int angle : 16;
    char padding18C[0x18];
    u_int targetFlags[17];
    char padding1E8[0x299];
    u_char reaction;
} movementDecisionContext;
int func_800E4180(void*, int, int, int);

int func_800E2B2C(movementDecisionContext* context, int targetId)
{
    D_800F4538_t* actor = context->actor;
    int angle;
    if (targetId == context->actorId) {
        func_800DEEFC((void*)context, 0);
        return 1;
    }
    if (context->delay == 0)
        return 0;
    if (context->reaction != 0) {
        if (func_800E4180(context, 128, 3, 6))
            return 1;
        context->pending = 0;
        goto failed;
    }
    angle = ratan2(context->x - context->targetX, context->z - context->targetZ);
    if ((context->destination & 0xFF00FF) != (context->previousDestination & 0xFF00FF)
        && ((context->targetFlags[targetId] >> 5) & 1)) {
        if (context->pending == 0) {
            context->pending = 1;
            context->angle = angle;
            context->previousDestination = context->destination;
        }
    }
    if (context->pending == 0)
        return 0;
    context->timer = context->delay;
    if (((actor->unk0.facing + (short)actor->unk0.unk14) & 0xFFF)
        == (context->angle & 0xFFF)) {
        if (!((context->targetFlags[targetId] >> 5) & 1)) {
            if (func_800E4180(context, 128, 1, 6))
                return 1;
            context->pending = 0;
            goto failed;
        }
        context->pending = 1;
        context->angle = angle & 0xFFF;
        context->previousDestination = context->destination;
    }
    func_800DEEFC((void*)context, 4);
    return 1;
failed:
    return 0;
}

typedef struct {
    char pad0[8];
    unsigned int flags;
    char padC[8];
    short angle14;
    char pad16[0x10];
    short angle26;
} movementRecoveryContext;
struct movementRecoveryState {
    char pad0[9];
    unsigned char flag9;
    char padA[0x2A];
    vs_battle_movementPosition position;
    char pad38[0x14];
    short x;
    char pad4E[2];
    short z;
    char pad52[6];
    movementRecoveryContext* context;
    char pad5C[0xDE];
    unsigned short timer, duration;
    char pad13E[0x1A];
    short targetX, targetZ;
    unsigned char targetActor;
    char pad15D;
    unsigned short flags;
    char pad160[0x28];
    unsigned short facing188, facing18A;
    char pad18C[0x9C];
    int counter;
};
typedef struct {
    char pad0[0x1C];
    short x, y, z;
} movementActorPosition;
void func_800E4B10(void*);
int func_800E4320(int, int);
void func_800E2CCC(movementRecoveryState* state)
{
    movementRecoveryContext* context = state->context;
    int direction, i, bestHeight, bestDirection, height;
    unsigned int x, z;
    unsigned int angle, quadrant;
    int nx, nz;
    vs_battle_movementPosition source;
    unsigned char* bounds;
    if ((context->flags & 0x200000) && state->counter++ > 120 && (state->flags & 6)
        && (state->flags & 0x30)
        && func_800D954C((void*)state, state->position.raw) > 0) {
        func_800E678C((void*)state);
        func_800E4B10(state);
        return;
    }
    if (state->targetActor != 16) {
        movementActorPosition* actor =
            (movementActorPosition*)D_800F4538[state->targetActor];
        direction = ratan2(state->x - actor->x, state->z - actor->z) & 0xFFF;
        state->facing18A = direction;
        state->timer = state->duration;
        func_800DEEFC((void*)state, 4);
    } else if (state->flag9) {
        direction = ratan2(state->x - state->targetX, state->z - state->targetZ) & 0xFFF;
        state->facing188 = direction;
        state->timer = state->duration;
        func_800DEEFC((void*)state, 3);
    } else {
        bestHeight = (-2147483647 - 1);
        bestDirection = -1;
        source = state->position;
        x = source.raw & 255;
        z = (source.raw >> 16) & 255;
        angle = context->angle26 + context->angle14;
        quadrant = (angle & 0xFFF) >> 10;
        if ((angle & 0x3FF) > 512)
            direction = ((quadrant + 1) & 3) * 2;
        else
            direction = quadrant * 2;
        i = 0;
        bounds = (unsigned char*)0x1F8003DC;
        for (; i < 4; i++) {
            direction = (direction + i * 2) & 7;
            nx = (unsigned char)(x + ((D_800F16EC_t*)0x1F8003EC)[direction].dx);
            nz = (unsigned char)(z + ((D_800F16EC_t*)0x1F8003EC)[direction].dz);
            if (nx < bounds[0] && nz < bounds[1]) {
                height = (func_800E4320(nx, nz) << 17) >> 17;
                if (height > bestHeight) {
                    bestDirection = direction;
                    bestHeight = height;
                }
            }
        }
        if (bestDirection < 0)
            func_800DEEFC((void*)state, 0);
        else {
            state->facing18A = bestDirection << 9;
            state->timer = state->duration;
            func_800DEEFC((void*)state, 4);
        }
    }
}

typedef union {
    u_int raw;
    struct {
        u_int unk0 : 1;
        u_int direction : 3;
        u_int clockwise : 1;
        u_int count : 7;
        u_int visited : 4;
        u_int stop : 1;
        u_int changed : 1;
        u_int cell : 4;
        u_int boundX : 5;
        u_int boundZ : 5;
    } bits;
} movementPath;

typedef struct {
    char unk0;
    u_char unk1;
    char unk2[2];
    u_char unk4;
    u_char unk5;
    char unk6[0x2E];
    vs_battle_movementPosition tile;
    char unk38[0x14];
    short x;
    char unk4E[2];
    short z;
    char unk52[0x92];
    u_char unkE4;
    char unkE5[2];
    u_char unkE7;
    u_char unkE8;
    char unkE9[0x75];
    u_short flags;
    char unk160[8];
    vs_battle_movementPosition destination;
    char unk16C[4];
    vs_battle_movementPosition next;
    char unk174[0x1C];
    movementPath path;
    char unk194[5];
    u_char unk199;
    u_char waitTimer;
} movementPathState;

typedef int (*movementPathTest)(movementPathState*, int);

int func_800D98E8(movementPathState*, int);
int func_800E3D5C(movementPathState*, movementPathTest);

int func_800E2F5C(movementPathState* state, movementPathTest test, int mask)
{
    movementPath path;
    u_int direction;
    int heading;
    int blocker;
    int i;
    int cell;
    int turn;
    int x;
    int z;
    int boundX;
    int boundZ;
    int center;
    int hit;
    vs_battle_movementPosition ahead;
    vs_battle_movementPosition point;

    path = state->path;
    state->unk5 = 0;
    state->unk1 = state->unk199;
    if (path.bits.count == 0) {
        goto done;
    }

    heading = path.bits.direction;
    direction = (path.bits.clockwise ? heading - 2 : heading + 2) & 7;
    hit = func_800D98E8(state, direction);
    blocker = hit - 1;
    if (hit) {
        if (!(((movementPathState**)0x1F80037C)[blocker]->flags & 0x30)
            && !((movementPathState**)0x1F80037C)[blocker]->waitTimer) {
            ((movementPathState**)0x1F80037C)[blocker]->waitTimer = func_800E45D4(4) + 4;
        }
    }

    if (!state->unk4 && !path.bits.changed && !test(state, path.bits.direction)) {
        ahead.p.x = state->tile.p.x + ((D_800F16EC_t*)0x1F8003EC)[path.bits.direction].dx;
        ahead.p.z = state->tile.p.z + ((D_800F16EC_t*)0x1F8003EC)[path.bits.direction].dz;
        ahead.p.y = 0;
        if (!func_800D96C8(
                (func_800D8400_t*)state, state->tile.raw, ahead.raw, path.bits.direction)
            || func_800D954C((func_800D8400_t*)state, ahead.raw) <= 0) {
            path.bits.changed = 1;
            path.bits.clockwise = !path.bits.clockwise;
            path.bits.visited = 0;
            path.bits.direction += 4;
        }
    }

    boundX = path.bits.boundX << 7;
    boundZ = path.bits.boundZ << 7;
    if (!state->unk4) {
        x = state->tile.p.x + ((D_800F16EC_t*)0x1F8003EC)[direction].dx;
        z = state->tile.p.z + ((D_800F16EC_t*)0x1F8003EC)[direction].dz;
        if (((*(unsigned short (**)[32])0x1F8003C0)[z][x] >> mask) & 1
            || x > D_800F58BC->maxX || z > D_800F58BC->maxZ || x < D_800F58BC->minX
            || z < D_800F58BC->minZ) {
            state->unkE8 = 0;
            state->unkE7 = 0;
            state->unkE4 = 0;
            goto stop;
        }
        if (boundZ > 0) {
            center = (state->destination.p.z << 7) + 64;
            if ((center < boundZ && state->z < boundZ)
                || (boundZ < center && boundZ < state->z)) {
                goto done;
            }
        }
        if (boundX > 0) {
            center = (state->destination.p.x << 7) + 64;
            if ((center < boundX && state->x < boundX)
                || (boundX < center && boundX < state->x)) {
                goto done;
            }
        }
    } else {
        if (boundZ > 0) {
            center = (state->destination.p.z << 7) + 64;
            if ((boundZ < center && state->z < boundZ)
                || (center < boundZ && boundZ < state->z)) {
                goto done;
            }
        }
        if (boundX > 0) {
            center = (state->destination.p.x << 7) + 64;
            if ((boundX < center && state->x < boundX)
                || (center < boundX && boundX < state->x)) {
                goto done;
            }
        }
    }

    cell = func_800E3D5C(state, test);
    if (cell == path.bits.cell) {
        goto keep;
    }
    path.bits.cell = cell;

    turn = -1;
    if (path.bits.clockwise) {
        turn = 1;
    }
    if (test(state, (path.bits.direction - turn * 2 - turn) & 7)
        && test(state, (path.bits.direction - turn * 2) & 7)) {
        if (!(state->flags & 0x30) && !state->waitTimer) {
            state->waitTimer = func_800E45D4(4) + 4;
        }
        goto stop;
    }

    path.bits.visited |= 1 << (path.bits.direction >> 1);
    if (path.bits.visited == 15) {
        goto stop;
    }

    direction = (path.bits.direction - turn * 2) & 7;
    for (i = 0; i < 4; i++) {
        if (test(state, direction)) {
            if (path.bits.direction != direction) {
                path.bits.changed = 1;
            }
            path.bits.direction = direction;
            goto keep;
        }
        point.p.x = state->tile.p.x + ((D_800F16EC_t*)0x1F8003EC)[direction].dx;
        point.p.z = state->tile.p.z + ((D_800F16EC_t*)0x1F8003EC)[direction].dz;
        point.p.y = 0;
        /* Passed through its address: the status byte is left over from the previous
         * probe. */
        if (func_800D96C8(
                (func_800D8400_t*)state, state->tile.raw, *(u_int*)&point, direction)
            && func_800D954C((func_800D8400_t*)state, *(u_int*)&point) > 0) {
            state->next = point;
            if (path.bits.direction != direction) {
                path.bits.changed = 1;
            }
            path.bits.direction = direction;
            goto detour;
        }
        direction = (direction + turn * 2) & 7;
    }
    state->path = path;
    return -1;

detour:
    state->path = path;
    return 14;

keep:
    state->path = path;
    return 5;

stop:
    path.bits.stop = 1;
done:
    state->path = path;
    return -1;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/771A8", func_800E3600);
