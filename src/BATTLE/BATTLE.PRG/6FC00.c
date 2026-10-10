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
void func_800D82CC(func_800E78F4_t*);
typedef struct movementRecoveryState movementRecoveryState;
void func_800E2CCC(movementRecoveryState*);
void func_800E4CE8(func_800DEEA4_t2* arg0);
extern func_800DEEA4_t2* D_800F5878[];
extern D_800F58BC_t* D_800F58BC;

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
unsigned int func_800DB93C(func_800D8400_t*, unsigned int, int, unsigned int);
unsigned int func_800D8400(
    func_800D8400_t* state, int first, int second, unsigned int direction)
{
    vs_battle_movementPosition dest, source;
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
        result = func_800D96C8(state, source.raw, dest.raw, direction);
        if (result > 0) {
            result = func_800D954C(state, dest.raw);
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

typedef struct {
    int score;
    unsigned int row : 3, column : 2, action : 8, threshold : 16, pad29 : 3;
    unsigned int distanceSquared;
    unsigned int targetId : 4, part : 3, heading : 12, weight : 8, padC27 : 5;
    unsigned int low : 1, flag1 : 1, flag2 : 1, flag3 : 1, flag4 : 1, flag5 : 1,
        range : 16, high : 10;
} actionCandidateEntry;
typedef struct {
    unsigned char flags, pad[3];
} actionCandidateTarget;
typedef struct {
    char pad0[0x131];
    unsigned char status;
    char pad132[0x72];
    actionCandidateTarget targets[16];
    unsigned int targetDistancesSquared[16];
    char pad224[0x20C];
    actionCandidateEntry* entries[16];
    int count;
} actionCandidateState;
int func_800E4CF4(actionCandidateState*, actionCandidateEntry*, int);
int func_800E4DF8(actionCandidateState*, int, int);
void func_800D9DD8(actionCandidateState*);
int func_800D85D8(actionCandidateState* state)
{
    int i, changed = 0;
    unsigned char value;
    actionCandidateEntry* entry;
    actionCandidateEntry* candidate;
    vs_battle_actor* actor;
    for (i = 0; i < state->count; i++) {
        entry = state->entries[i];
        if (entry->weight && entry->threshold <= D_800F58BC->unk18) {
            if (!func_800E4CF4(state, entry, entry->targetId)
                || !func_800E4DF8(state, entry->row, entry->column)) {
                entry->weight = 0;
            }
        }
    }
    if (state->count > 0 && !state->entries[0]->weight) {
        changed = 1;
        for (i = 1; i < state->count; i++) {
            candidate = state->entries[i];
            if (candidate->weight) {
                state->entries[0] = candidate;
                func_800D9DD8(state);
                goto done;
            }
        }
        state->count = 0;
    }
done:
    if (!state->count) {
        actor = vs_battle_actors[0];
        while (actor) {
            if ((state->targets[actor->id].flags >> 6) == 3) {
                break;
            }
            actor = actor->next;
        }
        value = 2;
        if (!actor) {
            value = 3;
        }
    } else {
        value = D_800F58BC->unk18 + 30 < state->entries[0]->threshold;
    }
    state->status = value;
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
    vs_battle_movementPosition tile;
    vs_battle_movementPosition lastTile;
    char unk64[0x548];
    u_int unk5AC_0 : 15;
    u_int unk5AC_15 : 1;
    u_int unk5AC_16 : 16;
} actorObject;

typedef union {
    u_int raw;
    struct {
        u_int active : 1;
        u_int previous : 1;
        u_int hidden : 1;
        u_int inView : 1;
        u_int unk4 : 1;
        u_int visible : 1;
        u_int kind : 2;
        u_int counter : 7;
        u_int timer : 5;
        u_int kindTimer : 7;
        u_int blocked : 1;
        u_int previousKind : 2;
        u_int outOfReach : 1;
        u_int unk31 : 1;
    } bits;
} actorRelation;

typedef struct {
    char unk0[0x22];
    u_char unk22;
    char unk23[2];
    u_char unk25;
    char unk26[0xE];
    vs_battle_movementPosition tile;
    char unk38[0x14];
    SVECTOR position;
    char unk54[4];
    actorObject* object;
    char unk5C[0x26];
    short height;
    char unk84[4];
    u_char actorId;
    char unk89[9];
    u_short radius;
    char unk94[0x10];
    u_int nearDistance;
    u_int angleLimit;
    u_int farDistance;
    char unkB0[8];
    short extent;
    char unkBA[0x71];
    u_char phase;
    char unk12C[0x78];
    actorRelation relations[16];
    u_int distances[16];
} actorRelationState;

int func_800E4624(short*, short*, int, int);
int func_800E44E8(SVECTOR*, SVECTOR*, int, int);
int func_800E437C(SVECTOR*, SVECTOR*, int, u_int);

#define RELATION_STATES ((actorRelationState**)0x1F80037C)

static inline int checkExtent(
    SVECTOR* from, SVECTOR* to, actorRelationState* state, int id)
{
    actorRelationState* other = RELATION_STATES[id];
    int extent;

    if (other) {
        extent = other->extent;
    } else {
        extent = 128;
    }
    return func_800E44E8(from, to, extent, state->extent);
}

static inline int checkHeight(
    SVECTOR* from, SVECTOR* to, actorRelationState* state, int id)
{
    actorRelationState* other = RELATION_STATES[id];
    int height;
    int own;

    if (other) {
        height = ABS(other->height);
    } else {
        height = 64;
    }
    own = state->height;
    if (own < 0) {
        own = -own;
    }
    return func_800E44E8(from, to, height, own);
}

void func_800D87E8(actorRelationState* state, int id)
{
    int height;
    int active;
    int previous;
    int visible;
    actorRelation relation;
    actorObject* object;
    actorRelationState* other;
    vs_battle_actor* actor;
    int owner;
    int blocked;
    int heading;
    int angle;
    int distance;
    int x;
    int z;
    u_short radius;
    u_int targetDistance;
    u_int root;

    {
        actorRelationState* target = (actorRelationState*)D_800F5878[id];
        actorObject* targetObject;

        if (target) {
            targetObject = (actorObject*)D_800F4538[id];
            if ((targetObject->flags.raw & 0x180000)
                && targetObject->position.vy > state->position.vy) {
                height = -target->extent;
            } else {
                height = ((actorRelationState*)D_800F5878[id])->height;
            }
        } else {
            height = -64;
        }
    }
    state->distances[id] = func_800E4624((short*)&state->position,
        (short*)&((actorObject*)vs_battle_actors[id]->unk44)->position, state->height,
        height);

    if (D_800F45E0[id]
        || ((object = (actorObject*)vs_battle_actors[id]->unk44),
            (object->tile.raw & 0xFF00FF) == (state->tile.raw & 0xFF00FF))
        || ((object->flags.raw & 0x180000)
            && (object->lastTile.raw & 0xFF00FF) == (state->tile.raw & 0xFF00FF))) {
        state->relations[id].raw |= 0x40000004;
    } else {
        if (++state->phase & 1) {
            state->relations[id].bits.outOfReach =
                !checkExtent(&object->position, &state->position, state, id);
        } else {
            state->relations[id].bits.hidden =
                !checkHeight(&object->position, &state->position, state, id);
        }
        if (state->relations[id].bits.hidden) {
            state->relations[id].bits.outOfReach = 1;
        }
    }

    {
        actorObject* object = state->object;
        state->relations[id].bits.inView =
            func_800E437C(&state->position,
                &((actorObject*)vs_battle_actors[id]->unk44)->position,
                object->facing + object->unk14, state->distances[id])
            >= (int)state->angleLimit;
    }

    /* Copied as a raw word, which keeps the local addressable. */
    *(u_int*)&relation = *(u_int*)&state->relations[id];
    if (state->actorId == id) {
        relation.bits.active = 1;
        relation.bits.visible = 1;
        relation.bits.previous = 0;
    } else {
        active = 0;
        if (state->distances[id] <= state->farDistance && relation.bits.inView
            && id != state->actorId && (state->unk25 || relation.bits.outOfReach)) {
            active = 1;
        }
        relation.bits.active = active;
        {
            int timer = relation.bits.timer;
            if (timer) {
                relation.bits.timer = timer - 1;
                relation.bits.active = 1;
            }
        }
        previous = 0;
        if (!relation.bits.active) {
            previous = state->relations[id].bits.active;
        }
        relation.bits.previous = previous;
        visible = 0;
        if (relation.bits.active
            || (state->distances[id] < state->nearDistance && relation.bits.outOfReach)) {
            visible = 1;
        }
        relation.bits.visible = visible;
    }

    {
        actorObject* object = (actorObject*)vs_battle_actors[id]->unk44;
        if ((*(u_short(**)[32])0x1F8003C0)[object->tile.p.z][object->tile.p.x] & 0x2000) {
            relation.bits.unk31 = 1;
        } else {
            relation.bits.unk31 = relation.bits.active;
        }
    }
    *(u_int*)&state->relations[id] = *(u_int*)&relation;

    blocked = 0;
    radius = 63;
    {
        actorObject* own = state->object;
        x = own->position.vx;
        z = own->position.vz;
    }
    owner = state->actorId;
    targetDistance = state->distances[id];
    heading = ratan2(((actorObject*)vs_battle_actors[id]->unk44)->position.vx - x,
        ((actorObject*)vs_battle_actors[id]->unk44)->position.vz - z);
    other = RELATION_STATES[id];
    if (other) {
        radius = other->radius;
    }
    for (actor = vs_battle_actors[0]; actor != NULL; actor = actor->next) {
        int candidate = actor->id;
        if (candidate == owner || candidate == id
            || state->distances[candidate] > targetDistance) {
            continue;
        }
        {
            actorObject* object = (actorObject*)D_800F4538[candidate];
            angle = ratan2(object->position.vx - x, object->position.vz - z) - heading;
        }
        if (rcos(angle) < 0) {
            continue;
        }
        root = vs_gte_rsqrt(state->distances[candidate]);
        distance = (int)(root * rsin(angle)) >> 12;
        if (distance < 0) {
            distance = -distance;
        }
        if ((u_int)distance < radius) {
            blocked = 1;
            break;
        }
    }

    {
        actorRelation final;

        final.raw = state->relations[id].raw & 0xF7FFFFFF;
        final.raw |= blocked << 27;
        state->relations[id] = final;
        if (state->actorId != id && RELATION_STATES[id]) {
            if (final.bits.kindTimer) {
                final.bits.kindTimer--;
                if (!final.bits.kindTimer) {
                    final.bits.kind = final.bits.previousKind;
                }
            }
            if (state->unk22 && final.bits.kind == 3) {
                if (final.bits.active) {
                    final.bits.counter = 0;
                } else {
                    final.bits.counter++;
                    if (final.bits.counter >= 121) {
                        final.bits.kind = 1;
                    }
                }
            }
            state->relations[id] = final;
        }
    }
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
extern int D_800F58E0;
extern int D_800F16F4;
struct actorEvaluationState;
struct actorTimerState;
void func_800D821C(struct actorEvaluationState*);
void func_800DBF00(func_800E78F4_t*);
void func_800DBFE4(struct actorTimerState*);
void func_800E4F14(void*);
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
            func_800D87E8((actorRelationState*)state, 0);
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
            func_800D87E8((actorRelationState*)state, 0);
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
            func_800D87E8((actorRelationState*)state, arg);
            arg = D_800F58D4;
            if (arg == 0) {
                break;
            }
        }

        func_800E4F14(state);
        if (func_800D85D8((actionCandidateState*)state)) {
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
