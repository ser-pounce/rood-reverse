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

typedef union {
    unsigned int raw;
    vs_battle_movementPosition p;
} vs_battle_movementTile;
typedef struct {
    unsigned char pad[7];
    unsigned char disabled;
    unsigned char rest[0x2C];
    vs_battle_movementTile position;
    char unk38[0x130];
    vs_battle_movementTile destination;
} func_800D8400_t;
unsigned int func_800DB93C(func_800D8400_t*, unsigned int, int, unsigned int);
unsigned int func_800D8400(
    func_800D8400_t* state, int first, int second, unsigned int direction)
{
    vs_battle_movementTile dest, source;
    int count, i, result;
    unsigned int directions, quadrant;
    int nearest;
    if (state->disabled) {
        return 0;
    }
    dest.p.status = 1;
    source = state->position;
    if (first == second) {
        directions = direction;
        count = 1;
    } else {
        quadrant = (direction & 0xFFF) >> 10;
        if ((direction & 0x3FF) > 512) {
            nearest = ((quadrant + 1) & 3) * 2;
        } else {
            nearest = quadrant * 2;
        }
        direction = nearest;
        if (direction != first) {
            directions = (first << 16) | direction;
        } else {
            directions = (second << 16) | direction;
        }
        count = 2;
    }
    for (i = 0; i < count; i++) {
        direction = (directions >> (i * 16)) & 0xFFFF;
        dest.p.x = source.p.x + ((D_800F16EC_t*)0x1F8003EC)[direction].dx;
        dest.p.z = source.p.z + ((D_800F16EC_t*)0x1F8003EC)[direction].dz;
        result = func_800D96C8((func_800E78F4_t*)state, source.p, dest.p, direction);
        if (result > 0) {
            result = func_800D954C((func_800E78F4_t*)state, dest.p);
            if (result < 0) {
                goto blocked;
            }
            if (result) {
                goto done;
            }
            return 0;
        }
        if (result < 0) {
            goto blocked;
        }
        dest.raw = func_800DB93C(state, dest.raw, direction, source.raw);
        if (dest.p.status == 1) {
            goto done;
        }
        if (dest.p.status) {
            goto blocked;
        }
    }
    return 0;
blocked:
    dest.p.status = 2;
done:
    return dest.raw & 0xFFFF00FF;
}

int func_800D85D8(func_800E78F4_t* arg0)
{
    int i;
    int changed = 0;
    u_char status;
    vs_battle_actor* actor;

    for (i = 0; i < arg0->unk470; ++i) {
        func_800DCAA0_t* entry = arg0->unk430[i];

        if (entry->unkC_19 && entry->unk4_13 <= D_800F58BC->unk18
            && (!func_800E4CF4(arg0, entry, entry->unkC_0)
                || !func_800E4DF8(arg0, entry->unk4_0, entry->unk4_3))) {
            entry->unkC_19 = 0;
        }
    }

    if (arg0->unk470 > 0 && !arg0->unk430[0]->unkC_19) {
        changed = 1;

        for (i = 1; i < arg0->unk470; ++i) {
            func_800DCAA0_t* entry = arg0->unk430[i];

            if (entry->unkC_19) {
                arg0->unk430[0] = entry;
                func_800D9DD8(arg0);
                goto done;
            }
        }

        arg0->unk470 = 0;
    }

done:
    if (!arg0->unk470) {
        for (actor = vs_battle_actors[0]; actor != NULL; actor = actor->next) {
            if (arg0->unk1A4[actor->id].unk0_6 == 3) {
                break;
            }
        }

        status = actor == NULL ? 3 : 2;
    } else {
        status = D_800F58BC->unk18 + 30 < arg0->unk430[0]->unk4_13;
    }

    arg0->unk131 = status;
    return changed;
}

typedef struct {
    char unk0[8];
    union {
        u_int raw;
        struct {
            u_int unk0 : 16;
            u_int unk16 : 3;
            u_int unk19 : 2;
            u_int unk21 : 10;
            u_int unk31 : 1;
        } bits;
    } flags;
    char unkC[8];
    short unk14;
    char unk16[6];
    SVECTOR position;
    short unk24;
    short facing;
    char unk28[0x34];
    vs_battle_movementTile tile;
    vs_battle_movementTile lastTile;
    char unk64[0x548];
    u_int unk5AC_0 : 15;
    u_int unk5AC_15 : 1;
    u_int unk5AC_16 : 16;
} actorObject;

static inline int _checkExtent(SVECTOR* from, SVECTOR* to, func_800E78F4_t* state, int id)
{
    func_800E78F4_t* other = ((func_800E78F4_t**)0x1F80037C)[id];
    int extent = other != NULL ? other->unkB8 : 128;

    return func_800E44E8(from, to, extent, state->unkB8);
}

static inline int _checkHeight(SVECTOR* from, SVECTOR* to, func_800E78F4_t* state, int id)
{
    func_800E78F4_t* other = ((func_800E78F4_t**)0x1F80037C)[id];
    int height = other != NULL ? ABS(other->unk82) : 64;

    return func_800E44E8(from, to, height, ABS(state->unk82));
}

void func_800D87E8(func_800E78F4_t* arg0, int id)
{
    int height;
    func_800DA1D4_t relation;
    func_800DA1D4_t final;
    D_800F4538_t* object;
    func_800E78F4_t* other;
    vs_battle_actor* actor;
    int owner;
    int blocked;
    int heading;
    int x;
    int z;
    u_int radius;
    u_int targetDistance;

    if (D_800F5878[id] != NULL) {
        D_800F4538_t* target = D_800F4538[id];

        if ((target->unk0.unkA_3 << 19) && (target->unk0.position.vy > arg0->unk4C.vy)) {
            height = -D_800F5878[id]->unkB8;
        } else {
            height = D_800F5878[id]->unk82;
        }
    } else {
        height = -64;
    }

    arg0->unk1E4[id] = func_800E4624(
        &arg0->unk4C, &vs_battle_actors[id]->unk44->unk0.position, arg0->unk82, height);

    if (D_800F45E0[id]
        || ((object = vs_battle_actors[id]->unk44),
            ((object->unk0.currentTile.x == arg0->unk34.x)
                && (object->unk0.currentTile.z == arg0->unk34.z)))
        || ((object->unk0.unkA_3 << 19)
            && ((object->unk0.lastTouchedTile.x == arg0->unk34.x)
                && (object->unk0.lastTouchedTile.z == arg0->unk34.z)))) {
        arg0->unk1A4[id].unk0_2 = 1;
        arg0->unk1A4[id].unk0_30 = 1;
    } else {
        if (++arg0->unk12B & 1) {
            arg0->unk1A4[id].unk0_30 =
                !_checkExtent(&object->unk0.position, &arg0->unk4C, arg0, id);
        } else {
            arg0->unk1A4[id].unk0_2 =
                !_checkHeight(&object->unk0.position, &arg0->unk4C, arg0, id);
        }

        if (arg0->unk1A4[id].unk0_2) {
            arg0->unk1A4[id].unk0_30 = 1;
        }
    }

    arg0->unk1A4[id].unk0_3 =
        func_800E437C(&arg0->unk4C, &vs_battle_actors[id]->unk44->unk0.position,
            arg0->unk58->unk0.facing + arg0->unk58->unk0.unk14, arg0->unk1E4[id])
        >= arg0->unkA8;

    memcpy(&relation, &arg0->unk1A4[id], sizeof relation);

    if (arg0->unk88 == id) {
        relation.unk0_0 = 1;
        relation.unk0_5 = 1;
        relation.unk0_1 = 0;
    } else {
        relation.unk0_0 = (arg0->unk1E4[id] <= arg0->unkAC) && relation.unk0_3
                       && id != arg0->unk88 && (arg0->unk25 || relation.unk0_30);

        if (relation.unk0_15) {
            --relation.unk0_15;
            relation.unk0_0 = 1;
        }

        relation.unk0_1 = !relation.unk0_0 && arg0->unk1A4[id].unk0_0;
        relation.unk0_5 =
            relation.unk0_0 || ((arg0->unk1E4[id] < arg0->unkA4) && relation.unk0_30);
    }

    if ((*(u_short(**)[32])0x1F8003C0)[vs_battle_actors[id]->unk44->unk0.currentTile.z]
                                      [vs_battle_actors[id]->unk44->unk0.currentTile.x]
        & 0x2000) {
        relation.unk0_31 = 1;
    } else {
        relation.unk0_31 = relation.unk0_0;
    }

    memcpy(&arg0->unk1A4[id], &relation, sizeof relation);
    blocked = 0;
    radius = 63;

    x = arg0->unk58->unk0.position.vx;
    z = arg0->unk58->unk0.position.vz;

    owner = arg0->unk88;
    targetDistance = arg0->unk1E4[id];
    heading = ratan2(vs_battle_actors[id]->unk44->unk0.position.vx - x,
        vs_battle_actors[id]->unk44->unk0.position.vz - z);
    other = ((func_800E78F4_t**)0x1F80037C)[id];

    if (other != NULL) {
        radius = other->unk92;
    }

    for (actor = vs_battle_actors[0]; actor != NULL; actor = actor->next) {
        int candidate = actor->id;
        int angle;
        int distance;

        if (candidate == owner || candidate == id
            || (arg0->unk1E4[candidate] > targetDistance)) {
            continue;
        }

        angle = ratan2(D_800F4538[candidate]->unk0.position.vx - x,
                    D_800F4538[candidate]->unk0.position.vz - z)
              - heading;

        if (rcos(angle) < 0) {
            continue;
        }

        distance = (vs_gte_rsqrt(arg0->unk1E4[candidate]) * rsin(angle)) >> 12;
        distance = ABS(distance);

        if (distance < radius) {
            blocked = 1;
            break;
        }
    }

    arg0->unk1A4[id].unk0_27 = blocked;

    if (arg0->unk88 == id || ((func_800E78F4_t**)0x1F80037C)[id] == NULL) {
        return;
    }

    final = arg0->unk1A4[id];

    if (final.unk0_20) {
        --final.unk0_20;

        if (!final.unk0_20) {
            final.unk0_6 = final.unk0_28;
        }
    }

    if (arg0->unk22 && final.unk0_6 == 3) {
        if (final.unk0_0) {
            final.unk0_8 = 0;
        } else {
            ++final.unk0_8;

            if (final.unk0_8 >= 121) {
                final.unk0_6 = 1;
            }
        }
    }

    arg0->unk1A4[id] = final;
}

typedef struct actorUpdateActor {
    struct actorUpdateActor* next;
    int id;
    u_char flags;
    u_char unk9;
    char unkA;
    u_int unkB_0 : 2;
    u_int unkB_2 : 6;
    char unkC[0x30];
    vs_battle_actor2* stats;
} actorUpdateActor;

typedef struct {
    u_int position;
    u_int unk4;
} actorUpdatePoint;

typedef struct {
    u_int current : 16;
    u_int max : 16;
} actorUpdateHp;

typedef struct {
    char unk0[0x18];
    actorUpdateHp hp;
    int current;
    int max;
} actorUpdateStats;

typedef struct {
    char unk0[8];
    u_char unk8;
    char unk9[5];
    u_char unkE;
    char unkF[5];
    u_char unk14;
    char unk15[3];
    u_char unk18;
    char unk19[3];
    u_char unk1C;
    u_char unk1D;
    char unk1E[0x11];
    u_char unk2F;
    char unk30[4];
    u_int unk34;
    union {
        int value;
        u_char b[4];
    } unk38;
    u_int unk3C;
    u_short unk40;
    char unk42[3];
    u_char unk45;
    u_short unk46;
    char unk48[4];
    int unk4C;
    int unk50;
    vs_battle_actor* actor;
    actorObject* object;
    actorUpdatePoint* unk5C;
    actorUpdatePoint* unk60;
    actorUpdatePoint* unk64;
    char unk68[8];
    union {
        u_char b[8];
        int w[2];
    } historyX;
    union {
        u_char b[8];
        int w[2];
    } historyZ;
    u_char historyIndex;
    u_char historyMask;
    char unk82[0xE];
    u_short unk90;
    char unk92[0x68];
    u_char unkFA;
    u_char unkFB;
    char unkFC[0x18];
    u_short unk114;
    char unk116[0xA];
    u_int unk120;
    u_char unk124;
    char unk125[5];
    u_char unk12A;
    char unk12B[6];
    u_char unk131;
    char unk132[6];
    u_short unk138;
    char unk13A[0x1C];
    u_short unk156;
    char unk158[0x34];
    int unk18C;
    u_int unk190_0 : 5;
    u_int unk190_5 : 7;
    u_int unk190_12 : 20;
    char unk194[6];
    u_char unk19A;
    char unk19B[9];
    u_int targets[16];
} actorUpdateState;

static inline int historyRepeats(actorUpdateState* state)
{
    return state->historyX.w[0] == state->historyX.w[1]
        && state->historyZ.w[0] == state->historyZ.w[1];
}

static inline int historyStalled(actorUpdateState* state)
{
    return state->historyMask == 0xFF ? historyRepeats(state) : 0;
}

extern int D_800F58D4;
extern int D_800F16F4;
struct actorEvaluationState;
struct actorTimerState;
void func_800DBF00(func_800E78F4_t*);
void func_800DBFE4(struct actorTimerState*);
void func_800D8280(actorUpdateState*);
void func_800E4358(actorUpdateState*);
void func_800E48F8(actorUpdateState*);
void func_800E48A8(actorUpdateState*, int, int);

void func_800D8EF4(void)
{
    actorUpdateActor* actor;
    actorUpdateState* state;
    actorObject* object;
    int flags;
    int id;
    int targetId;
    int i;
    int arg;
    int alert;
    vs_battle_actor* other;
    u_int target;
    actorUpdateStats* stats;
    u_int x;
    actorUpdateHp hp;
    int current;
    int max;
    u_int z;

    D_800F58E0 = 0;
    D_800F58BC->unk24 = 0;
    if (D_800F58BC->unk18 < 0xFFFE) {
        D_800F58BC->unk18++;
    }

    for (actor = (actorUpdateActor*)vs_battle_actors[0]; actor != NULL;
        actor = actor->next) {
        flags = actor->flags;
        actor->unkB_0 = 0;
        id = actor->id;
        state = ((actorUpdateState**)0x1F80037C)[id];
        state->unk1D = 0;
        object = state->object;
        state->unk90 = actor->stats->unk954;

        if (flags & 0x20) {
            func_800D82CC((func_800E78F4_t*)state);
            func_800D821C((struct actorEvaluationState*)state);
            func_800DBF00((func_800E78F4_t*)state);
        skip:
            state->unk14 = 1;
            continue;
        }
        func_800D8280(state);
        func_800E4358(state);
        if (flags & 0x80) {
            goto skip;
        }
        func_800DBFE4((struct actorTimerState*)state);
        if ((flags & 0x40) || state->unk18C
            || (object->flags.bits.unk16 | object->flags.bits.unk19 | object->unk5AC_15)
            || id == 0) {
            goto skip;
        }
        if (object->flags.bits.unk31) {
            state->unk1D = 1;
            func_800D87E8((func_800E78F4_t*)state, 0);
            goto skip;
        }

        arg = func_800E45B4();
        if (D_800F16F4 < arg) {
            goto idle;
        }
        *(int*)0x1F8003FC = arg;
        if (state->unk18) {
            if (state->unk12A != 0 && state->unk138 == 6) {
            idle:
                func_800E48F8(state);
                goto skip;
            }
            state->unk18 = 0;
        }
        if (state->unk19A) {
            state->unk19A--;
            func_800E2CCC((movementRecoveryState*)state);
            func_800D87E8((func_800E78F4_t*)state, 0);
            state->unk1D = 1;
            if (state->unk46 >= 2) {
                state->unk46--;
            }
            goto idle;
        }

        state->unk14 = 0;
        if ((state->unk64->position & 0xFF00FF) == (state->unk34 & 0xFF00FF)) {
            if (state->unk46 && --state->unk46 == 0) {
                state->unk38.value = state->unk64->position;
                state->unkFB = 16;
                state->unk1C = 1;
                state->unk45 = 40;
            }
            if (state->unk45 && --state->unk45 == 0) {
                if (++state->unkFA >= 5) {
                    state->unkFA = 1;
                }
                state->unk45 = 40;
            }
            state->unk8 = 1;
        } else {
            state->unk46 = 0xA8C;
            state->unk8 = 0;
            if (state->unk1C) {
                func_800E4CE8((func_800DEEA4_t2*)state);
                state->unk1C = 0;
            }
        }

        if (state->unk124 != 8 && actor->unk9 != 8 && state->unk124 != actor->unk9) {
            func_800E48A8(state, 1, 64);
        }
        state->unk124 = actor->unk9;
        state->unk34 = state->object->tile.raw;
        x = state->unk60->position;
        z = state->unk60->unk4;
        state->unk4C = x;
        state->unk50 = z;
        state->unk120 = (((z & 0xFFFF) >> 6) << 16) | ((x & 0xFFFF) >> 6);
        if ((0x12600 >> state->unk124) & 1) {
            if (historyStalled(state)) {
                state->historyMask = 0;
                state->unk19A = 30;
                goto idle;
            }
            state->historyX.b[state->historyIndex] = state->unk4C;
            state->historyZ.b[state->historyIndex] = state->unk50;
            state->historyMask |= 1 << state->historyIndex;
            state->historyIndex = (state->historyIndex + 1) & 7;
        } else {
            state->historyMask = 0;
        }

        if (state->unk190_5 > 0) {
            state->unk190_5--;
        }

        arg = 0;
        for (i = 0; i < 2; i++) {
            func_800D87E8((func_800E78F4_t*)state, arg);
            arg = D_800F58D4;
            if (arg == 0) {
                break;
            }
        }

        func_800E4F14(state);
        if (func_800D85D8((func_800E78F4_t*)state)) {
            goto idle;
        }

        alert = 0;
        stats = (actorUpdateStats*)state->actor->unk3C;
        hp = stats->hp;
        current = hp.current;
        max = hp.max;
        if (state->unk2F != 0) {
            if (state->unk2F == 1) {
                alert = current * 4 < max;
            } else if (state->unk2F == 2) {
                if (current * 2 < max) {
                    alert = 1;
                }
            } else if (state->unk114) {
                alert = 1;
            } else {
                for (other = vs_battle_actors[0]; other != NULL; other = other->next) {
                    target = state->targets[other->id];
                    if (((target >> 5) & 1) && ((target >> 6) & 3) == 3) {
                        alert = 1;
                        break;
                    }
                }
            }
            if (state->unk131 == 2) {
                alert = 1;
            }
        }
        state->unkE = alert;
        if (state->unk156) {
            state->unk156--;
        }
        if (state->unk1C == 0 && state->unk38.value >= 0) {
            targetId = state->unk38.b[3];
            if (state->unk40 == 0 || --state->unk40 == 0 || D_800F4538[targetId] == NULL
                || (((actorObject*)D_800F4538[targetId])->tile.raw & 0xFF00FF)
                       != (state->unk3C & 0xFF00FF)) {
                func_800E4CE8((func_800DEEA4_t2*)state);
            }
        }
    }
}

extern int D_800F58C4;

void func_800D9538(void) { D_800F58C4 = *(int*)0x1F8003F8; }
