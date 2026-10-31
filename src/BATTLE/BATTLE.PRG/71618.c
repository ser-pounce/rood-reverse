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
typedef struct movementRecoveryState movementRecoveryState;
void func_800D8260(func_800E78F4_t* arg0, int arg1, int arg2);

int func_800D9E18(func_800E78F4_t* arg0, func_800DCAA0_t* arg1)
{
    int id;
    int flag;
    u_int distance;
    u_int limit;
    int active = 0;
    SVECTOR point;
    int x;
    int z;
    int y;

    if (!arg0->unk470) {
        return 0;
    }

    id = arg1->unkC_0;

    if (id == 16 || !((func_800E78F4_t**)0x1F80037C)[id]) {
        return 0;
    }

    switch (arg0->unk12E) {
    case 1:
    normal:
        limit = 0x1F80;

        if (!(arg0->unk15E & 8)) {
            limit = vs_gte_rsqrt(arg1->unk8) + arg0->unkB3 * 32;
        }

        limit = limit * limit;

        if (arg0->unk1A4[id].unk0_6 == 2) {
            distance = arg1->unk8;
            flag = 0;
            active = 1;
        } else {
            if (func_800DB8AC(arg0, arg1)) {
                distance = arg1->unk8;
                active = 1;
            } else {
                u_int minimum;

                distance = limit;
                minimum = 640 * 640;

                if (distance < minimum) {
                    distance = minimum;
                }
            }

            flag = 1;
        }

        distance = vs_gte_rsqrt(distance);

        if (active) {
            ++D_800F58BC->unk24;

            if (arg0->unk1E4[id] < limit && arg0->unk1A4[arg1->unkC_0].unk0_0) {
                func_800D836C(arg0);
            }
        }

    move:
        if (func_800DB370(arg0, id, distance, flag)) {
            return 1;
        }

        return func_800DB74C(arg0, id) != 0;

    case 2:
        if (!func_800DBCB4(arg0, arg1)) {
            goto normal;
        }

        if (arg1->unk10.unk1) {
            point.vx = arg0->unk134.x * 128 + 64;
            point.vz = arg0->unk134.z * 128 + 64;
            point.vy = func_800E42D4(point.vx, point.vz);

            if (vs_gte_rsqrt(func_800E4624(&point, &D_800F4538[id]->unk0.position,
                    arg0->unk82, D_800F5878[id]->unk82))
                < vs_gte_rsqrt(arg1->unk8) - arg1->unk10.unk6) {
                goto normal;
            }
        }

        x = arg0->unk168.x * 128 + 64;
        z = arg0->unk168.z * 128 + 64;
        y = func_800E42D4(x, z);

        if (func_800E4660(x - arg0->unk4C.vx, y - arg0->unk4C.vy, z - arg0->unk4C.vz)
            <= 65535) {
            arg0->unk15C = id;
            func_800DB5B8(arg0, arg0->unk134, 2);
        } else {
            arg0->unk1 = 1;
            func_800DB5DC(arg0, arg0->unk134, 256);
        }

        return 1;

    case 4:
        return func_800DB61C(arg0, 0);

    case 7:
        func_800D82CC(arg0);
        id = 0;
        flag = 1;

        if (arg0->unk1A4[id].unk0_6 == 3) {
            distance = 640;
            goto move;
        }
        break;
    }

    return 0;
}

int func_800DA1D4(func_800E78F4_t* arg0)
{
    int i;
    int id = -1;
    u_int nearest = -1;
    int flag;
    int distance;
    func_800DCAA0_t* entry;
    vs_battle_actor* actor;

    switch (arg0->unk131) {
    case 0:
        entry = arg0->unk430[0];
        id = entry->unkC_0;

        if (func_800D9E18(arg0, entry)) {
            return 1;
        }

        for (i = 1; i < arg0->unk470; ++i) {
            entry = arg0->unk430[i];

            if (entry->unk4_13 < D_800F58BC->unk18 && entry->unkC_0 != id) {
                return func_800D9E18(arg0, entry);
            }
        }

        return 0;

    case 1:
        func_800D82CC(arg0);

        if (arg0->unk1A4[0].unk0_6 == 3) {
            if (func_800DB370(arg0, 0, 640, 1)) {
                return 1;
            }

            if (func_800DB74C(arg0, 0)) {
                return 1;
            }
        }

        id = arg0->unk430[0]->unkC_0;

        if (arg0->unk1A4[id].unk0_6 == 3) {
            flag = 1;
            distance = 640;
        } else {
            if (arg0->unk470 < 2) {
                return 0;
            }

            flag = 0;
            distance = vs_gte_rsqrt(arg0->unk430[1]->unk8);
        }

        if (func_800DB370(arg0, id, distance, flag)) {
            return 1;
        }

        if (func_800DB74C(arg0, id)) {
            return 1;
        }
        // Fallthrough

    case 2:
        func_800D82CC(arg0);

        if (arg0->unk1A4[0].unk0_6 == 3) {
            if (func_800DB370(arg0, 0, 640, 1)) {
                return 1;
            }

            if (func_800DB74C(arg0, 0)) {
                return 1;
            }
        }

        for (actor = vs_battle_actors[0]; actor != NULL; actor = actor->next) {
            if (arg0->unk1A4[actor->id].unk0_6 == 3
                && arg0->unk1E4[actor->id] < nearest) {
                nearest = arg0->unk1E4[actor->id];
                id = actor->id;
            }
        }

        if (id >= 0) {
            if (func_800DB370(arg0, id, 640, 1)) {
                return 1;
            }

            if (func_800DB74C(arg0, id)) {
                return 1;
            }
        }
        break;
    }

    return 0;
}

int func_800DA4BC(func_800E78F4_t* arg0, func_800DCAA0_t* arg1)
{
    if (func_800DB8AC(arg0, arg1)) {
        int id = arg1->unkC_0;
        int distance = vs_gte_rsqrt(arg1->unk8);
        int range = distance + arg0->unkB3 * 32;

        range *= range;
        ++D_800F58BC->unk24;

        if (arg0->unk1E4[id] < range && arg0->unk1A4[arg1->unkC_0].unk0_0) {
            func_800D836C(arg0);
        }

        if (func_800DB370(arg0, id, distance, 1)) {
            return 1;
        }

        if (func_800DB74C(arg0, id)) {
            return 1;
        }
    }

    return 0;
}

int func_800DA5CC(func_800E78F4_t* arg0)
{
    func_800DCAA0_t* entry = arg0->unk430[0];
    int id;

    if (!arg0->unk131 && func_800DA4BC(arg0, entry)) {
        return 1;
    }

    id = arg0->unk16;

    if (id < 16) {
        if (func_800DB370(arg0, id, 288, 1)) {
            if (arg0->unkE9 == 1 && arg0->unk12E != 7) {
                arg0->unk15C = entry->unkC_0;
                func_800E678C(arg0);
                func_800E2CCC(arg0);
            }

            return 1;
        }

        if (func_800DB74C(arg0, id)) {
            return 1;
        }
    }

    return 0;
}

int func_800DA6A4(func_800E78F4_t* arg0)
{
    int id;

    if (arg0->unkE) {
        return func_800DB61C(arg0, 1);
    }

    id = func_800DBB2C(arg0, NULL, 3);

    if (id >= 0 && func_800DBB2C(arg0, NULL, 2) >= 0
        && func_800DB370(arg0, id, 1024, 1)) {
        return 1;
    }

    return func_800DA1D4(arg0);
}

int func_800DA738(func_800E78F4_t* arg0)
{
    vs_battle_movementPosition point;
    int active = 0;
    int old;
    int candidate = func_800DBB2C(arg0, &point, 3);
    int target = arg0->unk16;
    int valid = candidate >= 0;

    if (arg0->unk88 != target && target != 16 && ((func_800E78F4_t**)0x1F80037C)[target]
        && arg0->unk1A4[target].unk0_6 == 2) {
        active = 1;
    }

    old = arg0->unkF;
    arg0->unkF = active;

    if (valid && active && arg0->unk1A4[target].unk0_5) {
        int x;
        int z;
        vs_battle_movementPosition tile = D_800F4538[target]->unk0.currentTile;
        int angle =
            ratan2(point.x * 128 - (x = D_800F4538[target]->unk0.position.vx - 64),
                point.z * 128 - (z = D_800F4538[target]->unk0.position.vz - 64));
        int heading = ratan2(arg0->unk4C.vx - D_800F4538[target]->unk0.position.vx,
            arg0->unk4C.vz - D_800F4538[target]->unk0.position.vz);
        int cosAngle = rcos(angle);
        int cosHeading = rcos(heading);
        int sinAngle = rsin(angle);
        int dot = cosAngle * cosHeading + sinAngle * rsin(heading);

        dot >>= 12;

        if (arg0->unk44) {
            --arg0->unk44;
        }

        if (dot >= -1200 || arg0->unk44) {
            func_800E1388(arg0, tile, ratan2(point.x - tile.x, point.z - tile.z), 320);
            arg0->unk1 = 1;
            func_800E50A0(arg0, 0, 0);

            if (!arg0->unk44) {
                arg0->unk44 = 10;
            }

            return 1;
        }
    }

    if (active) {
        if (valid
            && ((func_800E78F4_t**)0x1F80037C)[target]->unk1E4[candidate] < 384 * 384) {
            arg0->unk15C = target;
            func_800E2CCC(arg0);
            return 1;
        }

        if (func_800DB370(arg0, target, 320, 1)) {
            return 1;
        }

        if (func_800DB74C(arg0, target)) {
            return 1;
        }
    }

    if (valid) {
        if (old) {
            if (func_800E45D4(128) < 128u) {
                arg0->unk18 = 1;
            }

            func_800D8260(arg0, 6, 0);
        }

        if (func_800DB61C(arg0, 1)) {
            return 1;
        }
    }

    return func_800DB61C(arg0, 1);
}

int func_800DAA6C(func_800E78F4_t* arg0)
{
    if (arg0->unkE) {
        if (!func_800DB61C(arg0, 1)) {
            func_800DB5B0(arg0);
        }

        return 1;
    }

    if (!func_800DA1D4(arg0)) {
        func_800DB5FC(arg0);
    }

    return 1;
}

int func_800DAAD8(func_800E78F4_t* arg0)
{
    func_800DCAA0_t* entry = arg0->unk430[0];
    int id;
    vs_battle_actor* actor;

    if (!arg0->unk131 && func_800DA4BC(arg0, entry)) {
        return 1;
    }

    id = arg0->unk16;

    if (id < 16) {
        if (func_800DB370(arg0, id, 384, 0)) {
            if (arg0->unkE9 == 1 && arg0->unk12E != 7) {
                arg0->unk15C = entry->unkC_0;
                func_800E678C(arg0);
                func_800E2CCC(arg0);
            }

            return 1;
        }

        if (func_800DB74C(arg0, id)) {
            return 1;
        }
    }

    for (actor = vs_battle_actors[0]; actor != NULL; actor = actor->next) {
        if (arg0->unk1A4[actor->id].unk0_6 != 3 && arg0->unk1A4[actor->id].unk0_20) {
            arg0->unk1A4[actor->id].unk0_6 = 3;

            if (func_800DB61C(arg0, 0)) {
                arg0->unk1A4[actor->id].unk0_6 = arg0->unk1A4[actor->id].unk0_28;
                return 1;
            }

            arg0->unk1A4[actor->id].unk0_6 = arg0->unk1A4[actor->id].unk0_28;
        }
    }

    return 0;
}

typedef struct {
    char prefix[0x13];
    u_char kind;
    char gap[0x12B];
    u_char cooldown;
    char gap2[0xEC];
    func_800DCAA0_t* action;
} actionSetupContext;

int func_800DAC80(func_800E78F4_t* arg0, func_800DCAA0_t* arg1)
{
    if (!func_800DBD80(arg0, arg1)) {
        return 0;
    }

    func_800D836C(arg0);

    if (func_800D826C(arg0)) {
        D_800F4538_t* actor;

        arg0->unk22C = arg1;
        D_800F58E0 = 1;
        actor = D_800F4538[arg1->unkC_0];

        if (actor != NULL && actor->unk0.unkA_3) {
            arg1->unkC_4 = func_800E45D4(2);
            arg1->unkC_7 = 217;
        }

        func_800DEEFC(arg0, 15);

        if (func_800DBC60(arg0, arg1)) {
            arg0->unk13F = arg0->unk13 == 0 ? D_800F58BC->unk8 : 50;
        }

        return 1;
    }

    return 0;
}

typedef struct {
    unsigned int pad0, flags4, distance, flagsC;
} actionDispatchEntry;
typedef struct actionDispatchModel {
    char pad0[8];
    unsigned int flags;
    char padC[6];
    unsigned char id;
    char pad13[7];
    short status;
    short position[3];
} actionDispatchModel;
typedef struct actionDispatchActor {
    struct actionDispatchActor* next;
    int id;
    char pad8[0x3C];
    actionDispatchModel* model;
} actionDispatchActor;
typedef struct actionDispatchState {
    unsigned int flags0, flags4, flags8;
    unsigned short flagsC, padE;
    char pad10[4];
    unsigned char f14;
    char pad15[8];
    unsigned char f1D;
    char pad1E[0x16];
    unsigned char tileX, pad35, tileZ;
    char pad37[0x11];
    int target48;
    short position[3];
    char pad52[0x30];
    short height;
    char pad84[0x34];
    short depth;
    char padBA[0x78];
    signed char terrain132;
    char pad133[0xD];
    actionDispatchEntry fallback;
    char pad150[4];
    signed char terrain154;
    char pad155[7];
    unsigned char target;
    char pad15D[0x87];
    unsigned int distance;
    char pad1E8[0x248];
    actionDispatchEntry* entries[16];
    int count;
} actionDispatchState;
typedef struct {
    char pad[0x28];
    actionDispatchActor* registered[4];
} actionDispatchRegistry;
extern int D_800F16F4;
void func_800DB820(actionDispatchState*);
void func_800DB7B4(actionDispatchState*);
int func_800DAD9C(func_800E78F4_t* arg0)
{
    int i;
    int j;
    func_800DCAA0_t* entry;

    for (i = 0; i < arg0->unk470; ++i) {
        entry = arg0->unk430[i];

        if (func_800DAC80(arg0, entry)) {
            return 1;
        }
    }

    entry = &arg0->unk140;

    if (entry->unk4_5) {
        for (j = 0; j < 4; ++j) {
            vs_battle_actor* actor = D_800F58BC->unk28[j];

            if (actor != NULL) {
                D_800F45E0_t* model;

                entry->unkC_0 = actor->id;
                model = D_800F45E0[actor->id];

                if (model->unk0.unk12 && model->unk0.unk1A == 0
                    && func_800DAC80(arg0, entry)) {
                    return 1;
                }
            }
        }
    }

    return 0;
}
void func_800DAED0(void)
{
    actionDispatchActor* actor;
    actionDispatchState* state;
    int value, height, coordinate;
    for (actor = ((actionDispatchActor*)vs_battle_actors[0])->next; actor;
        actor = actor->next) {
        state = ((actionDispatchState**)0x1F80037C)[actor->id];
        if (!state->f14 || state->f1D) {
            value = func_800E45B4();
            if (D_800F16F4 < value) {
                func_800DEEFC((void*)state, 17);
            } else {
                *(int*)0x1F8003FC = value;
                if (state->f14 && state->f1D) {
                    if (D_800F5878[0]) {
                        if ((((actionDispatchModel*)D_800F4538[0])->flags & 0x180000)
                            && (coordinate =
                                    ((actionDispatchModel*)D_800F4538[0])->position[1],
                                state->position[1] < coordinate)) {
                            height = -((actionDispatchState*)D_800F5878[0])->depth;
                        } else {
                            height = ((actionDispatchState*)D_800F5878[0])->height;
                        }
                    } else {
                        height = -64;
                    }
                    state->distance = func_800E4624((SVECTOR*)state->position,
                        (SVECTOR*)((actionDispatchActor*)vs_battle_actors[0])
                            ->model->position,
                        state->height, height);
                    func_800DAD9C((void*)state);
                } else {
                    coordinate = state->tileX;
                    state->target = 16;
                    state->target48 = -1;
                    /* Clear the packed header halfword through its raw address. */
                    *(unsigned short*)((char*)state + 12) = 0;
                    state->flags0 = 0;
                    state->flags4 = 0;
                    state->flags8 = 0;
                    value =
                        (*(unsigned short (**)[32])0x1F8003C0)[state->tileZ][coordinate]
                        & 15;
                    state->terrain154 = value;
                    state->terrain132 = value;
                    *(int*)0x1F8003D0 = 0;
                    func_800DB820(state);
                    func_800DB7B4(state);
                }
            }
        }
    }
}

int func_800DB0BC(func_800E78F4_t* arg0)
{
    if (D_800F5920 != NULL) {
        return 0;
    }

    if ((*(u_int*)&arg0->unk34 & 0xFF00FF) == (arg0->unk38 & 0xFF00FF)) {
        arg0->unk2 = 1;

        if (!arg0->unkFA) {
            u_char directions[4];
            vs_battle_movementPosition probe;
            u_int angle = ratan2(arg0->unk4C.vx - arg0->unk168.x * 128 - 64,
                arg0->unk4C.vz - arg0->unk168.z * 128 - 64);
            u_int quadrant;
            int first;
            int second;
            int i;

            angle &= 0xFFF;
            first = (angle >> 9) & 7;
            second = ((angle >> 9) + 2) & 7;
            quadrant = angle / (ONE / 4);

            if (((angle & 0x3FF) > ONE / 8 ? ((quadrant + 1) & 3) * 2 : quadrant * 2)
                == first) {
                directions[0] = first;
                directions[1] = second;
            } else {
                directions[0] = second;
                directions[1] = first;
            }

            if (func_800E45D4(2)) {
                directions[2] = (first + 4) & 7;
                directions[3] = (second + 4) & 7;
            } else {
                directions[2] = (second + 4) & 7;
                directions[3] = (first + 4) & 7;
            }

            memcpy(arg0->unk118, directions, sizeof(directions));
            *(u_int*)&probe = 0;

            for (i = 0; i < 4; ++i) {
                probe.x = arg0->unk34.x + ((D_800F16EC_t*)0x1F8003EC)[directions[i]].dx;
                probe.z = arg0->unk34.z + ((D_800F16EC_t*)0x1F8003EC)[directions[i]].dz;

                if (func_800D954C(arg0, probe) > 0) {
                    arg0->unkFA = i;
                    break;
                }
            }

            ++arg0->unkFA;
        }

        if (arg0->unkFA >= 5) {
            func_800E4CE8(arg0);
            arg0->unk1C = 0;
            arg0->unkFA = 0;
            return 0;
        }

        arg0->unk168.x =
            arg0->unk34.x + ((D_800F16EC_t*)0x1F8003EC)[arg0->unk118[arg0->unkFA - 1]].dx;
        arg0->unk168.z =
            arg0->unk34.z + ((D_800F16EC_t*)0x1F8003EC)[arg0->unk118[arg0->unkFA - 1]].dz;
        arg0->unk15C = arg0->unkFB;

        if (func_800D954C(arg0, arg0->unk168) > 0) {
            func_800E50A0(arg0, 0, 0);
        } else {
            ++arg0->unkFA;
        }

        return 1;
    }

    arg0->unkFA = 0;
    return 0;
}
