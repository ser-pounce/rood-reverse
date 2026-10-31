#include "common.h"
#include "6E644.h"
#include "6E644Shared.h"
#include "146C.h"
#include "4DEA8.h"
#include "battleUnk.h"
#include "src/SLUS_010.40/32154.h"
#include "src/SLUS_010.40/overlay.h"
#include "build/src/include/lbas.h"
#include <abs.h>
#include <stdlib.h>
#include <rand.h>

#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) < (b) ? (b) : (a))

struct func_800D4910_t;

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
    int unk0;
    _loadFileContext loadContexts[8];
    u_short slots[8];
    u_short isClut[8];
} D_800F5638_t;

typedef struct {
    u_int unk0_0 : 4;
    u_int unk0_4 : 28;
    short unk4;
    short unk6;
    short unk8;
    short unkA;
    u_int unkC;
    short unk10;
    short unk12;
    short unk14;
    short unk16;
} func_800DC888_t;

typedef struct {
    short tableCount;
    u_short dataOffset;
    int tableOffsets[0];
} pFileBlock1;

typedef struct {
    int unk0;
    u_char data[0];
} pFileBlock2;

typedef struct {
    u_char unk0;
    u_char unk1;
    u_char unk2;
    char unk3;
    u_char unk4[8];
} D_1F8003D0_t;

typedef struct {
    D_800F19CC_t2 unk0;
    char unk84C[0x180];
    func_800DCAA0_t unk9CC[3][16];
    u_char unkD8C[16][256];
    func_800DCAA0_t unk1D8C[16];
} func_800DEC88_t;

void func_800D7890(int arg0);
void _parsePfileBlock1(pFileBlock1* arg0);
void _parsePfileBlock12(void*);
void _parsePfileBlock13(void*);
void func_800D8038(int);
void vs_battle_setPlgLoadState(int);
void func_800D820C(int, int);
void func_800D821C(func_800E78F4_t*);
int func_800D954C(func_800E78F4_t*, vs_battle_movementPosition);
int func_800D96C8(
    func_800E78F4_t*, vs_battle_movementPosition, vs_battle_movementPosition, int);
int D_800D9B6C(func_800E78F4_t*, int);
void func_800D9DD8(func_800E78F4_t*);
int func_800D9E18(func_800E78F4_t*, func_800DCAA0_t*);
int func_800DB370(func_800E78F4_t*, int, int, int);
void func_800DB5B0(func_800E78F4_t*);
void func_800DB5B8(func_800E78F4_t*, vs_battle_movementPosition, int);
void func_800DB5DC(func_800E78F4_t*, vs_battle_movementPosition, int);
void func_800DB5FC(func_800E78F4_t*);
int func_800DB61C(func_800E78F4_t*, int);
int func_800DB74C(func_800E78F4_t*, int);
int func_800DB8AC(func_800E78F4_t*, func_800DCAA0_t*);
int func_800DBB2C(func_800E78F4_t*, void*, int);
int func_800DBC60(func_800E78F4_t*, func_800DCAA0_t*);
int func_800DBD80(func_800E78F4_t*, func_800DCAA0_t*);
void func_800DC19C(func_800E78F4_t*);
void func_800DC210(func_800E78F4_t*, int);
int func_800DC284(int, int, int, int);
void func_800DC2E0(func_800DCAA0_t*, func_800DCAA0_t*);
void func_800DC30C(short*, short*, int, int);
void func_800DC344(func_800E78F4_t*, func_800DCAA0_t*);
void func_800DC3CC(func_800E78F4_t*);
void func_800DC3E8(vs_battle_actor2*, vs_battle_actor2*);
void func_800DC424(func_800DC888_t*);
int func_800DC484(int, int);
int func_800DC48C(int, int);
void func_800DC4F0(func_800DCAA0_t*, vs_action_t*);
void func_800DC574(func_800E78F4_t*, int);
void func_800DC784(func_800E78F4_t*, int);
void func_800DC810(D_800F19CC_t2*);
void func_800DC888(func_800DC888_t*);
void func_800DE3E4(func_800E78F4_t*);
int func_800DFBCC(func_800E78F4_t*, int, int);
int func_800E0678(func_800E78F4_t*, int);
int func_800E0918(func_800E78F4_t*, int, int);
void func_800E1388(func_800E78F4_t*, vs_battle_movementPosition, int, u_int);
int func_800E1BB8(func_800E78F4_t*, vs_battle_movementPosition, u_int, int);
void func_800E3600(func_800E78F4_t*, int, int);
int func_800E4180(func_800E78F4_t*, int, int, int);
int func_800E42D4(int, int);
int func_800E42E0(vs_battle_movementPosition);
int func_800E42EC(int, int);
int func_800E4320(int, int);
int func_800E437C(SVECTOR*, SVECTOR*, int, u_int);
int func_800E44E8(SVECTOR*, SVECTOR*, int, int);
int func_800E45D4(int);
u_int func_800E45F4(vs_battle_movementPosition, vs_battle_movementPosition);
int func_800E4624(SVECTOR*, SVECTOR*, int, int);
int func_800E4690(vs_battle_movementPosition, int);
int func_800E4764(func_800E78F4_t*, int*, int*);
void func_800E4B10(func_800E78F4_t*);
void func_800E4B18(func_800E78F4_t*);
void func_800E4B2C(func_800E78F4_t*, int);
void func_800E4B70(func_800E78F4_t*, int);
void func_800E4BB8(func_800E78F4_t*);
void func_800E4C8C(func_800E78F4_t*);
void func_800E4CE8(func_800E78F4_t* arg0);
int func_800E4CF4(func_800E78F4_t*, func_800DCAA0_t*, int);
int func_800E4DF8(func_800E78F4_t*, int, int);
void func_800E4F14(func_800E78F4_t*);
void func_800E50A0(func_800E78F4_t*, int, int);
void func_800E678C(func_800E78F4_t*);
void func_800E685C(int, int, int);

extern u_int D_80069BBC[];
extern p_file_t D_800EC4BC;
extern int D_800F5330[];
extern int D_800F5630;
extern D_800F5638_t D_800F5638;
extern u_int D_800F5680;
extern vs_main_CdQueueSlot* D_800F568C;
extern u_int _plgLoadState;
extern _loadFileContext _plgLoadContext;
extern u_long* D_800F56A0;
extern int _plgEntryPointCount;
extern effectExec D_800F56A8[];
extern actionEffectRequest* D_800F5798;
extern D_800F569C_t D_800F57A0;
extern int D_800F5874;
extern D_800F58C8_t* D_800F58D8;
extern int D_800F58E0;
extern vs_battle_actor2* D_800F58E8;
extern func_800DCAA0_t (*D_800F58EC)[16];
extern int D_800F58F0;
extern int D_800F58F4;
extern func_800DCAA0_t* D_800F58F8;
extern D_800F19CC_t2* D_800F5900;
extern u_char (*D_800F5904)[256];
extern D_800F5910_t* D_800F5910;

void func_800E1238(func_800E78F4_t*, int);

typedef struct {
    int unk0;
    u_int unk4;
} func_800E78F4_t2;

typedef struct {
    char unk0[0x16];
    signed char unk16;
    char unk17[0x21];
    int unk38;
    char unk3C[0x18];
    vs_battle_actorView_t* unk54;
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
void func_800D8260(func_800DEEA4_t2* arg0, int arg1, int arg2);

typedef union {
    unsigned int raw;
    vs_battle_movementPosition p;
} vs_battle_movementTile;
unsigned int func_800E4660(int, int, int);

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
        if ((u_char)arg1 == e->unk0_0 && (u_char)(arg1 >> 16) == e->unk0_5) {
            m = &sp10[j];
            if (D_800F5910[i * 2 + 1].unk0_0 == m->vx >> 7
                && D_800F5910[i * 2 + 1].unk0_5 == m->vz >> 7) {
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
    vs_battle_movementTile tile;
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
    vs_battle_movementTile destination;
    char unk16C[4];
    vs_battle_movementTile next;
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

static inline int routeSetArea(routeEdgeState* state, vs_battle_movementTile position)
{
    state->area = routeTile(position.p.z, position.p.x) & 15;
    return 6;
}

int func_800DFBCC(func_800E78F4_t* arg0, int index, int area)
{
    routeEdgeState* state = (routeEdgeState*)arg0;
    routeEdgePair routes;
    int distances[2];
    vs_battle_movementTile position;
    vs_battle_movementTile candidate;
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
            result = func_800D954C((func_800E78F4_t*)state, candidate.p);
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
        if (func_800D954C((func_800E78F4_t*)state, candidate.p) <= 0) {
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
    vs_battle_actor* actor;

    if ((((D_1F8003D0_t*)0x1F8003D0)->unk2 >> arg1) & 1) {
        return ((D_1F8003D0_t*)0x1F8003D0)->unk4[arg1];
    }

    x = arg0->unk4C.vx + arg2 * (arg0->unkB3 * ((D_800F16EC_t*)0x1F8003EC)[arg1].dx);
    y = arg0->unk4C.vy;
    z = arg0->unk4C.vz + arg2 * (arg0->unkB3 * ((D_800F16EC_t*)0x1F8003EC)[arg1].dz);

    for (i = func_8008D2C0(points) - 1; i != -1; --i) {
        dx = points[i].vx - x;
        dy = points[i].vy - y;
        dz = points[i].vz - z;

        if (arg2
            && ((((D_800F16EC_t*)0x1F8003EC)[arg1].dx > 0 && dx < 0)
                || (((D_800F16EC_t*)0x1F8003EC)[arg1].dx < 0 && dx > 0)
                || (((D_800F16EC_t*)0x1F8003EC)[arg1].dz > 0 && dz < 0)
                || (((D_800F16EC_t*)0x1F8003EC)[arg1].dz < 0 && dz > 0))) {
            continue;
        }

        radius = arg0->unk92 + 96;
        height = (arg0->unkB8 + 32) >> 1;

        if (ABS(dx) <= radius && ABS(dz) <= radius && ABS(dy) <= height) {
            ((D_1F8003D0_t*)0x1F8003D0)->unk2 |= 1 << arg1;
            ((D_1F8003D0_t*)0x1F8003D0)->unk4[arg1] = 1;
            return 1;
        }
    }

    for (actor = vs_battle_actors[0]; actor != NULL; actor = actor->next) {
        func_800E78F4_t* other = ((func_800E78F4_t**)0x1F80037C)[actor->id];
        D_800F4538_t* model = other->unk58;

        if (other->unk88 == arg0->unk88 || other->unk88 == 0) {
            continue;
        }

        dx = model->unk0.position.vx - x;
        dy = model->unk0.position.vy - y;
        dz = model->unk0.position.vz - z;

        if (arg2
            && ((((D_800F16EC_t*)0x1F8003EC)[arg1].dx > 0 && dx < 0)
                || (((D_800F16EC_t*)0x1F8003EC)[arg1].dx < 0 && dx > 0)
                || (((D_800F16EC_t*)0x1F8003EC)[arg1].dz > 0 && dz < 0)
                || (((D_800F16EC_t*)0x1F8003EC)[arg1].dz < 0 && dz > 0))) {
            continue;
        }

        radius = other->unk92 + arg0->unk92 + other->unkB3;

        if (other->unk88 == 0) {
            height = -1;
        } else {
            height = (arg0->unkB8 + other->unkB8) >> 1;
        }

        if (ABS(dx) <= radius && ABS(dz) <= radius && ABS(dy) <= height) {
            ((D_1F8003D0_t*)0x1F8003D0)->unk2 |= 1 << arg1;
            ((D_1F8003D0_t*)0x1F8003D0)->unk4[arg1] = actor->id + 1;
            return actor->id + 1;
        }
    }

    ((D_1F8003D0_t*)0x1F8003D0)->unk2 |= 1 << arg1;
    ((D_1F8003D0_t*)0x1F8003D0)->unk4[arg1] = 0;
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
    vs_battle_movementPosition pos;
} directionalCachePoint;
int func_800E0678(func_800E78F4_t* arg0, int arg1)
{
    if ((((D_1F8003D0_t*)0x1F8003D0)->unk0 >> arg1) & 1) {
        return (((D_1F8003D0_t*)0x1F8003D0)->unk1 & (1 << arg1)) > 0;
    }

    if (!func_800E02B4(arg0, arg1, 1)) {
        int x = arg0->unk34.x + ((D_800F16EC_t*)0x1F8003EC)[arg1].dx;
        int z = arg0->unk34.z + ((D_800F16EC_t*)0x1F8003EC)[arg1].dz;

        if (x <= D_800F58BC->unk0 && x >= D_800F58BC->unk2 && z <= D_800F58BC->unk1
            && z >= D_800F58BC->unk3 && !((*(u_short(**)[32])0x1F8003C0)[z][x] & 0x40)
            && (((vs_battle_movementPosition*)&arg0->unk38)->x != x
                || ((vs_battle_movementPosition*)&arg0->unk38)->z != z)) {
            if (D_800F58BC->unk14
                && func_800E42EC(x, z) + arg0->unkBE < D_800F58BC->unk14) {
                return 0;
            }

            ((D_1F8003D0_t*)0x1F8003D0)->unk0 |= 1 << arg1;
            ((D_1F8003D0_t*)0x1F8003D0)->unk1 |= 1 << arg1;
            return 1;
        }
    }

    ((D_1F8003D0_t*)0x1F8003D0)->unk0 |= 1 << arg1;
    ((D_1F8003D0_t*)0x1F8003D0)->unk1 &= ~(1 << arg1);
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
            int h = func_800E42EC(arg0->unk34.x + ((D_800F16EC_t*)0x1F8003EC)[arg1].dx,
                arg0->unk34.z + ((D_800F16EC_t*)0x1F8003EC)[arg1].dz);
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

typedef union {
    unsigned int raw;
    struct {
        short x;
        short y;
    } p;
} movementStepPosition;
typedef struct {
    unsigned char unk0;
    char pad1[6];
    unsigned char unk7;
    char pad8[0x2C];
    directionalCachePoint tile;
    char pad38[0x14];
    movementStepPosition position;
    short z;
    char pad52[6];
    movementCheckObject* object;
    char pad5C[0x60];
    short clearance;
    short height;
    char padC0[0x25];
    unsigned char actorId;
    char padE6[0x82];
    directionalCachePoint destination;
    char pad16C[0x10];
    int moveX;
    int moveZ;
    int moveY;
    short angle;
    char pad18A[0x9E];
    int unk228;
} movementStepState;
typedef struct {
    char pad0[0x1E];
    short y;
    char pad20[0x3C];
    directionalCachePoint tile;
    char pad60[0x5DE];
    unsigned short height;
} movementStepActor;
int func_800E6A6C(int, int, int, int);
#define MOVEMENT_STEP_TILES (*(unsigned short(**)[32])0x1F8003C0)
#define MOVEMENT_STEP_RESULT (*(int*)0x1F8003C8)
void func_800E0A68(movementStepState* state, int action)
{
    int step;
    int mode;
    int angle;
    int x;
    int z;
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
    movementStepActor* actor;

    if (func_800E0918((void*)state, action, 1)) {
        return;
    }
    if (!(state->object->flags & 0x200000)) {
        func_800E4B18((void*)state);
        return;
    }
    state->unk7 = 1;
    if (!func_800E4764((void*)state, &step, &mode)) {
        goto recover;
    }
    x = state->destination.p.x * 128 + 64;
    z = state->destination.p.z * 128 + 64;
    angle = ratan2(state->position.p.x - x, state->z - z);
    angle &= 0xFFF;
    if (state->unk0 && func_800E45F4(state->tile.pos, state->destination.pos) < 2
        && (MOVEMENT_STEP_TILES[state->destination.p.z][state->destination.p.x] & 0x40)) {
        int centerZ;
        int centerAngle;
        int selectedHeight;
        int heading;
        int rise;
        int offsetX;
        int offsetZ;
        int actorY;
        actorY = ((movementStepActor*)D_800F4538[state->actorId])->y;
        rise = func_800E42E0(state->tile.pos);
        if (actorY >= rise) {
            selectedHeight = rise + state->height;
        } else if (D_800F58BC->unk14 && D_800F58BC->unk14 >= actorY) {
            selectedHeight = D_800F58BC->unk14;
        } else {
            selectedHeight = (short)actorY;
        }
        rise = selectedHeight - state->position.p.y;
        if (ABS(rise) < step) {
            angle = state->tile.p.x * 128 + 64;
            centerZ = state->tile.p.z * 128 + 64;
            centerAngle = ratan2(state->position.p.x - angle, state->z - centerZ);
            state->moveY = selectedHeight << 12;
            heading = (-centerAngle + ONE * 3 / 4) & 0xFFF;
            offsetX = state->position.p.x - angle;
            if (ABS(offsetX) < step) {
                state->moveX = angle << 12;
            } else {
                state->moveX = (state->position.p.x << 12) + step * rcos(heading);
            }
            offsetZ = state->z - centerZ;
            state->moveZ = ABS(offsetZ) < step ? centerZ << 12
                                               : (state->z << 12) + step * rsin(heading);
            func_800DEEFC((void*)state, 8);
            return;
        }
        state->moveY = rise;
        state->moveZ = 0;
        state->moveX = 0;
        if (state->moveY > 0 && func_800E02B4((void*)state, 0, 0)) {
            state->moveY = 0;
        }
        func_800DEEFC((void*)state, mode);
        return;
    }
    if ((state->tile.raw & 0xFF00FF) == (state->destination.raw & 0xFF00FF)) {
        int floorY;
        int tileX;
        int deltaX;
        int tileZ;
        int deltaZ;
        if (!state->unk0 || func_800E02B4((void*)state, 0, 0)) {
        recover:
            func_800E2CCC((void*)state);
            return;
        }
        floorY = state->height;
        actor = (movementStepActor*)D_800F4538[state->actorId];
        if (!(MOVEMENT_STEP_TILES[state->destination.p.z][state->destination.p.x]
                & 0x20)) {
            floorY += func_800E42E0(state->destination.pos);
        }
        tileX = state->destination.p.x * 128;
        deltaX = state->position.p.x - 64;
        state->moveX = tileX - deltaX;
        tileZ = state->destination.p.z * 128;
        deltaZ = state->z - 64;
        state->moveZ = tileZ - deltaZ;
        state->moveY = floorY - state->position.p.y;
        if ((state->destination.raw & 0xFF00FF) == (actor->tile.raw & 0xFF00FF)) {
            state->moveY = actor->y - (actor->height >> 1) - state->position.p.y;
        }
        if (state->moveY > 0 && floorY < state->position.p.y + step) {
            state->moveY = 0;
        }
        if (ABS(state->moveX) < step) {
            state->moveX = 0;
        }
        if (ABS(state->moveZ) < step) {
            state->moveZ = 0;
        }
        func_800DEEFC((void*)state, mode);
        return;
    }
    func_800E3600((void*)state, angle, 2);
    switch (MOVEMENT_STEP_RESULT) {
    case 5:
        angle = state->angle * (ONE / 8);
        if (func_800E0850((void*)state, angle) + state->height < state->position.p.y) {
        fall:
            state->moveY = -ONE;
            state->moveZ = 0;
            state->moveX = 0;
        } else {
            angle = -angle;
            angle += ONE * 3 / 4;
            angle &= 0xFFF;
            state->moveY = 0;
            state->moveX = rcos(angle);
            state->moveZ = rsin(angle);
        }
        func_800DEEFC((void*)state, mode);
        return;
    case 7:
        height = func_800E42E0(state->destination.pos) + state->height;
        px = state->position.raw & 0xFFFF;
        py = (int)state->position.raw >> 16;
        pz = state->z;
        ground = func_800E6A6C(px, pz, x, z) + state->clearance;
        if (D_800F58BC->unk14) {
            ground = ground < D_800F58BC->unk14 ? D_800F58BC->unk14 : ground;
        }
        top = func_800E0850((void*)state, angle) + state->height;
        ground = top > ground ? ground : top;
        distance = vs_gte_rsqrt(func_800E4660(x - px, 0, z - pz));
        value = height + ground;
        denom = vs_gte_rsqrt(((value << 12) / value) << 12) + ONE;
        if (!denom) {
            goto fallback;
        }
        value = (distance << 12) / denom;
        square = value * value;
        diff = py - ground;
        offset = ABS(diff);
        if (py + step < ground) {
            if (step < height - py) {
                state->moveY = height - py;
            } else {
                state->moveY = 0;
            }
            state->moveX = x - px;
            state->moveZ = z - pz;
            func_800DEEFC((void*)state, mode);
            state->unk228 = 0;
            return;
        }
        if ((unsigned int)step >= distance) {
        fallback:
            func_800E1238((void*)state, angle);
            return;
        }
        height =
            (unsigned int)(offset * (step - value) * (step - value)) / square + ground;
        angle = -angle;
        angle += ONE * 3 / 4;
        angle &= 0xFFF;
        x = (px << 12) + step * rcos(angle);
        z = (pz << 12) + step * rsin(angle);
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
            state->moveX = (x >> 12) - px;
            state->moveZ = (z >> 12) - pz;
            state->moveY = dy;
            func_800DEEFC((void*)state, mode);
        } else {
            state->moveX = x;
            state->moveY = height << 12;
            state->moveZ = z;
            func_800DEEFC((void*)state, 8);
        }
        return;
    }
}
#undef MOVEMENT_STEP_TILES
#undef MOVEMENT_STEP_RESULT

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

    if (*(int*)0x1F8003C8 != 5 && *(int*)0x1F8003C8 != 7) {
        func_800E678C(arg0);
        func_800E2CCC(arg0);
        return;
    }

    if (*(int*)0x1F8003C8 == 5) {
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

void func_800E1388(
    func_800E78F4_t* arg0, vs_battle_movementPosition arg1, int arg2, u_int arg3)
{
    vs_battle_movementPosition dest;
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

unsigned int func_800E4660(int, int, int);
void func_800E153C(func_800E78F4_t* arg0, int arg1)
{
    int distance = arg0->unkB4;

    if ((*(u_int*)&arg0->unk34 & 0xFF00FF) != (*(u_int*)&arg0->unk168 & 0xFF00FF)) {
        int angle = ratan2(arg0->unk4C.vx - arg0->unk168.x * 128 - 64,
            arg0->unk4C.vz - arg0->unk168.z * 128 - 64);

        if (func_800E4660(arg0->unk168.x * 128 - arg0->unk4C.vx + 64, 0,
                arg0->unk168.z * 128 - arg0->unk4C.vz + 64)
            > distance * distance) {
            func_800E1388(arg0, arg0->unk34, angle, distance);
        }

        if ((arg0->unk15E & 6)
            && (arg0->unkD || func_800E45F4(arg0->unk168, arg0->unk34) < 16)) {
            if ((int)(*(u_int*)&arg0->unk48 << 8) >= 0) {
                arg0->unk168 = arg0->unk48;
            }

            func_800E4B2C(arg0, angle);
            return;
        }

        if (++arg0->unk8C >= 6) {
            int i;
            vs_battle_movementPosition dest = arg0->unk168;

            if (func_800D954C(arg0, dest) <= 0) {
                for (i = 0; i < 4; ++i) {
                    dest.x = arg0->unk168.x + ((D_800F16EC_t*)0x1F8003EC)[i * 2].dx;
                    dest.z = arg0->unk168.z + ((D_800F16EC_t*)0x1F8003EC)[i * 2].dz;

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
    vs_battle_movementPosition previous[2];
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

u_char func_800E1850(u_char arg0, vs_battle_movementPosition arg1, int arg2)
{
    int x = arg1.x;
    int z = arg1.z;
    int i;

    int z2 = z;

    for (i = 0; i < 8; ++i) {
        if ((arg0 >> i) & 1) {
            if (func_800E42EC(x + ((D_800F16EC_t*)0x1F8003EC)[i].dx,
                    z2 + ((D_800F16EC_t*)0x1F8003EC)[i].dz)
                > arg2) {
                arg0 &= ~(1 << i);
            }
        }
    }
    return arg0;
}

void func_800E1908(func_800E78F4_t* arg0)
{
    u_char* tile =
        &(*(u_char**)0x1F8003C4)[arg0->unk34.z * *(u_char*)0x1F8003DC + arg0->unk34.x];
    int old = *tile;
    vs_battle_actorView_t* actor = arg0->unk54;
    int result;

    *tile = func_800E1850(old, arg0->unk34, arg0->unk4C.vy);
    func_800E3600(arg0,
        ratan2(arg0->unk4C.vx - arg0->unk17C, arg0->unk4C.vz - arg0->unk180) & 0xFFF, 0);
    *tile = old;
    result = *(int*)0x1F8003C8;

    if ((0xA0 >> result) & 1) {
        actor->unk9 = 9;

        if (result == 5) {
            actor->unkC = arg0->unk188 << 9;
        } else {
            actor->unkC = arg0->unk188;
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

    current = (*(u_short(**)[32])0x1F8003C0)[arg0->unk34.z][arg0->unk34.x] & 15;
    next = (*(u_short(**)[32])0x1F8003C0)[arg0->unk168.z][arg0->unk168.x] & 15;

    if (current != next) {
        if (arg0->unk29) {
            int mode = func_800DFBCC(arg0, current, next);

            if (mode == 6) {
                arg0->unk17C = arg0->unk168.x * 128 + 64;
                arg0->unk180 = arg0->unk168.z * 128 + 64;

                if (((*(u_short(**)[32])0x1F8003C0)[arg0->unk168.z][arg0->unk168.x] & 15)
                    != ((*(u_short(**)[32])0x1F8003C0)[arg0->unk34.z][arg0->unk34.x]
                        & 15)) {
                    arg0->unk2 = 1;
                    ((D_1F8003D0_t*)0x1F8003D0)->unk0 = 0;
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
            ((D_1F8003D0_t*)0x1F8003D0)->unk0 = 0;
        }
    }

    func_800E3600(arg0,
        ratan2(arg0->unk4C.vx - arg0->unk17C, arg0->unk4C.vz - arg0->unk180) & 0xFFF, 0);
}

int func_800E1BB8(
    func_800E78F4_t* arg0, vs_battle_movementPosition arg1, u_int arg2, int arg3)
{
    vs_battle_movementPosition candidate;
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
            if (*(int*)0x1F8003F4) {
                candidate.y =
                    ((*(u_char**)0x1F8003C4)[arg0->unk11C.z * *(u_char*)0x1F8003DC
                                             + arg0->unk11C.x]
                        >> i * 2)
                    & 1;
            } else {
                candidate.y = func_800E4690(arg0->unk11C, i * 2);
            }

            candidate.x = arg0->unk11C.x + ((D_800F16EC_t*)0x1F8003EC)[i * 2].dx;
            candidate.z = arg0->unk11C.z + ((D_800F16EC_t*)0x1F8003EC)[i * 2].dz;

            if (candidate.y) {
                if (!func_800D96C8(arg0, arg0->unk11C, candidate, i * 2)) {
                    continue;
                }

                candidate.y = 0;
            }

            if (!arg0->unk2
                && ((*(u_short(**)[32])0x1F8003C0)[candidate.z][candidate.x] & 15)
                       != ((*(u_short(**)[32])0x1F8003C0)[arg0->unk11C.z][arg0->unk11C.x]
                           & 15)) {
                continue;
            }
        }

        if (!((*(u_short(**)[32])0x1F8003C0)[candidate.z][candidate.x] & 32)) {
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

    arg0->unk11C.x += ((D_800F16EC_t*)0x1F8003EC)[choices[chosen]].dx;
    arg0->unk11C.z += ((D_800F16EC_t*)0x1F8003EC)[choices[chosen]].dz;
    arg0->unkD0 = choices[chosen];
    ++arg0->unk15D;
    return arg2 < arg0->unk15D;
}

static inline int _randomHeading(int direction)
{
    int offset = func_800E45D4(512);
    int angle = direction * 512;

    offset += 65280;
    return angle + offset;
}

void func_800E1EAC(func_800E78F4_t* arg0, vs_battle_movementPosition arg1, u_int arg2)
{
    int rate = arg0->unkD8;
    u_short rest = arg0->unkD4;
    u_short move = arg0->unkD6;
    int value;
    int (*check)(func_800E78F4_t*, int);

    ++arg0->unkC2;
    check = (arg0->unk58->unk0.unkA_5 << 21) ? func_800E0678 : D_800D9B6C;

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
    *(u_char*)0x1F8003D0 = 0;

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
                        arg0->unkD0 = _randomHeading(direction);
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
                int x = arg0->unk34.x + ((D_800F16EC_t*)0x1F8003EC)[side].dx;
                int z = arg0->unk34.z + ((D_800F16EC_t*)0x1F8003EC)[side].dz;

                if (D_800F58BC->unk1 < z || z < D_800F58BC->unk3 || D_800F58BC->unk0 < x
                    || x < D_800F58BC->unk2
                    || ((*(u_short(**)[32])0x1F8003C0)[z][x] & 0x800)) {
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

            if ((*(u_int*)&arg0->unk168 & 0xFF00FF) == (*(u_int*)&arg0->unk34 & 0xFF00FF)
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

static inline void _nextWaypoint(func_800E78F4_t* arg0, D_800F58C8_t2* waypoints)
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

    _nextWaypoint(arg0, waypoints);
    waypointX = &waypoints[arg0->unk100];
    arg0->unk168.x = waypointX->x;
    waypointZ = &waypoints[arg0->unk100];
    arg0->unk168.z = waypointZ->z;
    func_800E50A0(arg0, 0, 0);
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
    vs_battle_movementTile tile;
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
    if (s->model->flags & 0x200000) {
        option = 1;
    }
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
                    < s->distances[target]) {
                    s->rangeMode = 0;
                } else {
                    s->rangeMode = 1;
                }
                break;
            case 1:
                value = s->range;
                if ((unsigned int)(value * value) < s->distances[target]) {
                out_of_range:
                    s->rangeMode = 0;
                } else {
                    if ((unsigned int)((value - 128) * (value - 128))
                        >= s->distances[target]) {
                        s->rangeMode = 2;
                    } else {
                        s->rangeMode = mode;
                    }
                }
                break;
            case 2:
                if ((unsigned int)((s->range - 32) * (s->range - 32))
                    < s->distances[target]) {
                    s->rangeMode = 1;
                } else {
                    s->rangeMode = mode;
                }
                break;
            }
        } else {
            goto out_of_range;
        }
        if ((s->rangeMode != 2 && s->bE8) || (s->rangeMode != 0 && s->bE7)) {
            goto recover;
        }
        if (option == 0 && s->rangeMode == 2) {
            s->rangeMode = 1;
        }
        one = 1;
        switch (s->rangeMode) {
        case 0:
            if (option == one) {
                s->b0 = one;
            }
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
                func_800E1388((func_800E78F4_t*)s, s->tile.p, angle,
                    distance - (radius >= 0 ? radius : -radius));
                if ((s->destination.raw & 0xFF00FF) == (s->tile.raw & 0xFF00FF)) {
                    s->bD = one;
                    s->destination.raw = oldPosition;
                }
            }
            s->movementTargetId = s->targetId;
            func_800E50A0((func_800E78F4_t*)s, 0, 0);
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
            } else {
                s->movementTargetId = target;
            }
            angle = ratan2(s->targetX - s->x, s->targetZ - s->z);
            func_800E50A0((func_800E78F4_t*)s, 1, angle);
            if (s->actor->id >= 9) {
                s->bE8 = 1;
            }
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
                if (!func_800E4180((func_800E78F4_t*)s, 128, 1, 1)) {
                    result = 0;
                }
                goto done;
            }
        }
        if (s->bE8) {
            goto recover;
        }
        if (s->bE4) {
            s->destination.raw = s->cachedDestination.raw;
            if (s->timeout) {
                s->timeout--;
            }
            if ((s->destination.raw & 0xFF00FF) == (s->tile.raw & 0xFF00FF)) {
                if (s->targets[target].f5) {
                    result = 0;
                    goto done;
                }
                func_800D8260((void*)s, 7, 40);
                if (!func_800E4180((func_800E78F4_t*)s, 128, 1, 1)) {
                cancel:
                    s->bE4 = 0;
                    result = 0;
                }
            } else if (s->timeout) {
                s->b1 = 1;
                s->bC = 1;
                func_800E50A0((func_800E78F4_t*)s, 0, 0);
            } else {
                goto cancel;
            }
        } else if (!func_800E4180((func_800E78F4_t*)s, 0, 3, 1)) {
            result = 0;
        }
    }
    goto done;

done:
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

    if ((*(u_int*)&arg0->unk168 & 0xFF00FF) != (*(u_int*)&arg0->unk108 & 0xFF00FF)
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
        vs_battle_movementPosition source = arg0->unk34;
        u_int x = source.x;
        u_int z = source.z;
        u_int z2 = z;
        u_int angle = model->unk0.facing + model->unk0.unk14;
        u_int quadrant = (angle & 0xFFF) / (ONE / 4);
        direction = (angle & 0x3FF) > ONE / 8 ? ((quadrant + 1) & 3) * 2 : quadrant * 2;

        for (i = 0, bounds = (u_char*)0x1F8003DC; i < 4; ++i) {
            direction = (direction + i * 2) & 7;
            nx = (x + ((D_800F16EC_t*)0x1F8003EC)[direction].dx) & 0xFF;
            nz = (z2 + ((D_800F16EC_t*)0x1F8003EC)[direction].dz) & 0xFF;

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
    vs_battle_movementTile tile;
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
    vs_battle_movementTile destination;
    char unk16C[4];
    vs_battle_movementTile next;
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
    vs_battle_movementTile ahead;
    vs_battle_movementTile point;

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
                (func_800E78F4_t*)state, state->tile.p, ahead.p, path.bits.direction)
            || func_800D954C((func_800E78F4_t*)state, ahead.p) <= 0) {
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
            || x > D_800F58BC->unk0 || z > D_800F58BC->unk1 || x < D_800F58BC->unk2
            || z < D_800F58BC->unk3) {
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
        if (func_800D96C8((func_800E78F4_t*)state, state->tile.p,
                *(vs_battle_movementPosition*)&point, direction)
            && func_800D954C(
                   (func_800E78F4_t*)state, *(vs_battle_movementPosition*)&point)
                   > 0) {
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
