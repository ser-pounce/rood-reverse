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
    char unk0[0xA];
    u_char unkA;
    char unkB;
    short unkC;
    short unkE;
    char unk10[2];
    u_short unk12;
    char unk14[2];
    u_char unk16;
    u_char unk17;
    char unk18[4];
    u_char unk1C;
} D_800F5920_t;

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
void func_800D82CC(func_800E78F4_t*);
void func_800D836C(func_800E78F4_t*);
int func_800DBCB4(func_800E78F4_t*, func_800E78F4_t2*);
void func_800DEEFC(func_800E0850_t*, int);
typedef struct movementRecoveryState movementRecoveryState;
void func_800E2CCC(movementRecoveryState*);
void func_800E4CE8(func_800DEEA4_t2* arg0);
void func_800E678C(func_800E0850_t*);
extern func_800DEEA4_t2* D_800F5878[];
extern D_800F58BC_t* D_800F58BC;
extern D_800F5920_t* D_800F5920;
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
int func_800D954C(func_800D8400_t*, unsigned int);

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

int func_800E4624(short*, short*, int, int);
extern int D_800F58E0;
extern int D_800F16F4;

typedef union {
    unsigned int raw;
    unsigned char bytes[4];
} candidateMovementWord;
typedef struct candidateMovementState {
    char pad0[1];
    unsigned char f1;
    char pad2[74];
    short position[3];
    char pad52[48];
    short height;
    char pad84[47];
    unsigned char maxRange;
    char padB4[122];
    unsigned char mode;
    char pad12F[5];
    candidateMovementWord destination;
    char pad138[36];
    unsigned char target;
    char pad15D[1];
    unsigned short flags;
    char pad160[8];
    candidateMovementWord next;
    char pad16C[56];
    candidateMovementWord targets[16];
    unsigned int distances[16];
    char pad224[588];
    int count;
} candidateMovementState;
int func_800DB8AC(candidateMovementState*, actionCandidateEntry*);
int func_800E42D4(int, int);
int func_800E4624(short*, short*, int, int);
unsigned int func_800E4660(int, int, int);
void func_800DB5B8(candidateMovementState*, unsigned int, int);
void func_800DB5DC(candidateMovementState*, unsigned int, int);
int func_800DB61C(candidateMovementState*, int);
int func_800DB370(actionCandidateState*, int, int, int);
int func_800DB74C(actionCandidateState*, int);
int func_800D9E18(candidateMovementState* state, actionCandidateEntry* entry)
{
    int id, flag;
    unsigned int distance, limit;
    int active = 0;
    short point[3];
    int x, z, y;
    if (!state->count) {
        return 0;
    }
    id = entry->targetId;
    if (id == 16 || !((candidateMovementState**)0x1F80037C)[id]) {
        return 0;
    }
    switch (state->mode) {
    case 1:
    normal:
        limit = 0x1F80;
        if (!(state->flags & 8)) {
            limit = vs_gte_rsqrt(entry->distanceSquared) + (state->maxRange << 5);
        }
        limit = limit * limit;
        if ((state->targets[id].bytes[0] >> 6) == 2) {
            distance = entry->distanceSquared;
            flag = 0;
            active = 1;
        } else {
            if (func_800DB8AC(state, entry)) {
                distance = entry->distanceSquared;
                active = 1;
            } else {
                distance = limit;
                {
                    unsigned int minimum = 0x64000;
                    if (distance < minimum) {
                        distance = minimum;
                    }
                }
            }
            flag = 1;
        }
        distance = vs_gte_rsqrt(distance);
        if (active) {
            D_800F58BC->unk24++;
            if (state->distances[id] < limit
                && (state->targets[entry->targetId].raw & 1)) {
                func_800D836C((void*)state);
            }
        }
    move:
        if (func_800DB370((void*)state, id, distance, flag)) {
            return 1;
        }
        return func_800DB74C((void*)state, id) != 0;
    case 2:
        if (!func_800DBCB4((void*)state, (void*)entry)) {
            goto normal;
        }
        if (entry->flag1) {
            point[0] = (state->destination.bytes[0] << 7) + 64;
            point[2] = (state->destination.bytes[2] << 7) + 64;
            point[1] = func_800E42D4(point[0], point[2]);
            distance =
                vs_gte_rsqrt(func_800E4624(point, (short*)&D_800F4538[id]->unk0.position,
                    state->height, ((candidateMovementState*)D_800F5878[id])->height));
            distance =
                (int)distance < vs_gte_rsqrt(entry->distanceSquared) - entry->range;
            if (distance) {
                goto normal;
            }
        }
        x = (state->next.bytes[0] << 7) + 64;
        z = (state->next.bytes[2] << 7) + 64;
        y = func_800E42D4(x, z);
        if (func_800E4660(
                x - state->position[0], y - state->position[1], z - state->position[2])
            <= 0xFFFF) {
            state->target = id;
            func_800DB5B8(state, state->destination.raw, 2);
        } else {
            state->f1 = 1;
            func_800DB5DC(state, state->destination.raw, 256);
        }
        return 1;
    case 4:
        return func_800DB61C(state, 0);
    case 7:
        func_800D82CC((void*)state);
        id = 0;
        flag = 1;
        if ((state->targets[id].bytes[0] >> 6) == 3) {
            distance = 640;
            goto move;
        }
        break;
    }
    return 0;
}

int func_800DB370(actionCandidateState*, int, int, int);
int func_800DB74C(actionCandidateState*, int);
int func_800DA1D4(actionCandidateState* state)
{
    int id = -1, flag, distance, i;
    unsigned int nearest = -1;
    actionCandidateEntry* entry;
    vs_battle_actor* actor;
    switch (state->status) {
    case 0:
        entry = state->entries[0];
        id = entry->targetId;
        if (func_800D9E18((void*)state, entry)) {
            return 1;
        }
        for (i = 1; i < state->count; i++) {
            entry = state->entries[i];
            if (entry->threshold < D_800F58BC->unk18 && entry->targetId != id) {
                return func_800D9E18((void*)state, entry);
            }
        }
        return 0;
    case 1:
        func_800D82CC((void*)state);
        if ((state->targets[0].flags >> 6) == 3) {
            if (func_800DB370(state, 0, 640, 1)) {
                return 1;
            }
            if (func_800DB74C(state, 0)) {
                return 1;
            }
        }
        id = state->entries[0]->targetId;
        if ((state->targets[id].flags >> 6) == 3) {
            flag = 1;
            distance = 640;
        } else {
            if (state->count < 2) {
                return 0;
            }
            flag = 0;
            distance = vs_gte_rsqrt(state->entries[1]->distanceSquared);
        }
        if (func_800DB370(state, id, distance, flag)) {
            return 1;
        }
        if (func_800DB74C(state, id)) {
            return 1;
        }
    case 2:
        func_800D82CC((void*)state);
        if ((state->targets[0].flags >> 6) == 3) {
            if (func_800DB370(state, 0, 640, 1)) {
                return 1;
            }
            if (func_800DB74C(state, 0)) {
                return 1;
            }
        }
        for (actor = vs_battle_actors[0]; actor; actor = actor->next) {
            int candidate = actor->id;
            if ((state->targets[candidate].flags >> 6) == 3) {
                unsigned int d = state->targetDistancesSquared[candidate];
                if (d < nearest) {
                    nearest = d;
                    id = candidate;
                }
            }
        }
        if (id >= 0) {
            if (func_800DB370(state, id, 640, 1)) {
                return 1;
            }
            if (func_800DB74C(state, id)) {
                return 1;
            }
        }
        break;
    }
    return 0;
}

typedef struct {
    unsigned int unk0, unk4, distance, flagsC;
} da4bcEntry;

typedef struct {
    char pad0[14];
    unsigned char flagE, flagF;
    char pad10[6];
    signed int target16 : 8;
    char pad17;
    unsigned char flag18;
    char pad19[27];
    unsigned int tile;
    char pad38[12];
    unsigned char timer44;
    char pad45[7];
    short x;
    char pad4E[2];
    short z;
    char pad52[54];
    unsigned char id;
    char pad89[42];
    unsigned char radius;
    char padB4[53];
    unsigned char mode;
    char padEA[68];
    unsigned char action;
    char pad12F[2];
    unsigned char pending;
    char pad132[42];
    unsigned char target15C;
    char pad15D[71];
    unsigned int targets[16];
    unsigned int distances[16];
    char pad224[524];
    da4bcEntry* entries[16];
} da4bcState;

typedef union {
    unsigned int raw;
    unsigned char b[4];
} da4bcPoint;

typedef struct {
    char pad0[28];
    short x;
    char pad1E[2];
    short z;
    char pad22[58];
    vs_battle_movementPosition tile;
} da4bcModel;

typedef struct {
    unsigned int pad0 : 6, mode : 2, pad8 : 12, category : 7, pad27 : 1, oldMode : 2,
        pad30 : 2;
} da4bcTargetBits;

typedef struct {
    char pad[0x1A4];
    da4bcTargetBits targets[16];
} da4bcTargetState;

typedef struct da4bcActor {
    struct da4bcActor* next;
    int id;
} da4bcActor;

typedef struct {
    unsigned int target : 4, pad : 28;
} da4bcEntryTarget;

int func_800DBB2C(void*, void*, int);
void func_800DB5B0(void*);
void func_800DB5FC(void*);
void func_800E50A0(void*, int, int);
int func_800E45D4(int);
void func_800E1388(func_800D8400_t*, vs_battle_movementPosition, int, unsigned int);

int func_800DA4BC(da4bcState* state, da4bcEntry* entry)
{
    int target, distance, radius, result;

    result = 0;
    if (func_800DB8AC((void*)state, (void*)entry)) {
        target = entry->flagsC & 15;
        distance = vs_gte_rsqrt(entry->distance);
        radius = distance + (state->radius << 5);
        radius = radius * radius;
        D_800F58BC->unk24++;
        if (state->distances[target] < (unsigned int)radius) {
            if (state->targets[entry->flagsC & 15] & 1) {
                func_800D836C((void*)state);
            }
        }
        if (func_800DB370((void*)state, target, distance, 1)) {
            return 1;
        }
        if (func_800DB74C((void*)state, target)) {
            return 1;
        }
    }
    return result;
}

int func_800DA5CC(da4bcState* state)
{
    da4bcEntry* entry = state->entries[0];
    int target;

    if (!state->pending && func_800DA4BC(state, entry)) {
        return 1;
    }
    target = state->target16;
    if (target < 16) {
        if (func_800DB370((void*)state, target, 288, 1)) {
            if (state->mode == 1 && state->action != 7) {
                state->target15C = ((da4bcEntryTarget*)&entry->flagsC)->target;
                func_800E678C((void*)state);
                func_800E2CCC((void*)state);
            }
            return 1;
        }
        if (func_800DB74C((void*)state, target)) {
            return 1;
        }
    }
    return 0;
}

int func_800DA6A4(da4bcState* state)
{
    int target;

    if (state->flagE) {
        return func_800DB61C((void*)state, 1);
    }
    target = func_800DBB2C(state, 0, 3);
    if (target >= 0 && func_800DBB2C(state, 0, 2) >= 0
        && func_800DB370((void*)state, target, 1024, 1)) {
        return 1;
    }
    return func_800DA1D4((void*)state);
}

int func_800DA738(da4bcState* state)
{
    da4bcPoint point;
    int oldFlag, candidate;
    unsigned char* pointPtr;
    int centerX, centerZ;
    int angleA, angleB, cosA, cosB, sinA, dot;
    vs_battle_movementPosition tile;
    unsigned int valid;
    int target;
    int active = 0;
    da4bcModel** models;
    da4bcModel* first;
    da4bcModel* second;

    candidate = func_800DBB2C(state, &point, 3);
    target = state->target16;
    valid = (unsigned int)~candidate >> 31;
    if (state->id != target && target != 16) {
        if (((da4bcState**)0x1F80037C)[target]) {
            active = ((unsigned char)state->targets[target] >> 6) == 2;
        }
    }
    oldFlag = state->flagF;
    state->flagF = active;
    if (valid) {
        if (active) {
            if ((state->targets[target] >> 5) & 1) {
                models = (da4bcModel**)&D_800F4538[target];
                first = *models;
                pointPtr = point.b;
                tile = first->tile;
                angleA = ratan2((point.b[0] << 7) - (centerX = first->x - 64),
                    (point.b[2] << 7) - (centerZ = first->z - 64));
                second = *models;
                angleB = ratan2(state->x - second->x, state->z - second->z);
                cosA = rcos(angleA);
                cosB = rcos(angleB);
                sinA = rsin(angleA);
                dot = cosA * cosB + sinA * rsin(angleB);
                dot >>= 12;
                if (state->timer44) {
                    state->timer44--;
                }
                if (dot >= -1200 || state->timer44) {
                    func_800E1388((void*)state, tile,
                        ratan2(point.b[0] - (tile.raw & 255),
                            pointPtr[2] - ((tile.raw >> 16) & 255)),
                        320);
                    ((unsigned char*)state)[1] = 1;
                    func_800E50A0(state, 0, 0);
                    if (!state->timer44) {
                        state->timer44 = 10;
                    }
                    return 1;
                }
            }
        } else {
            goto fallback;
        }
    }
    if (active) {
        if (valid
            && ((da4bcState**)0x1F80037C)[target]->distances[candidate] <= 0x23FFF) {
            state->target15C = target;
            func_800E2CCC((void*)state);
            return 1;
        }
        if (func_800DB370((void*)state, target, 320, 1)) {
            return 1;
        }
        if (func_800DB74C((void*)state, target)) {
            return 1;
        }
    }
fallback:
    if (valid) {
        if (oldFlag) {
            if ((unsigned int)func_800E45D4(128) < 128) {
                state->flag18 = 1;
            }
            func_800D8260((void*)state, 6, 0);
        }
        if (func_800DB61C((void*)state, 1)) {
            return 1;
        }
    }
    return func_800DB61C((void*)state, 1);
}

int func_800DAA6C(da4bcState* state)
{
    if (state->flagE) {
        if (!func_800DB61C((void*)state, 1)) {
            func_800DB5B0(state);
        }
        return 1;
    }
    if (!func_800DA1D4((void*)state)) {
        func_800DB5FC(state);
    }
    return 1;
}

int func_800DAAD8(da4bcState* state)
{
    da4bcEntry* entry = state->entries[0];
    int target;
    da4bcActor* actor;

    if (!state->pending && func_800DA4BC(state, entry)) {
        return 1;
    }
    target = state->target16;
    if (target < 16) {
        if (func_800DB370((void*)state, target, 384, 0)) {
            if (state->mode == 1 && state->action != 7) {
                state->target15C = ((da4bcEntryTarget*)&entry->flagsC)->target;
                func_800E678C((void*)state);
                func_800E2CCC((void*)state);
            }
            return 1;
        }
        if (func_800DB74C((void*)state, target)) {
            return 1;
        }
    }
    for (actor = (da4bcActor*)vs_battle_actors[0]; actor; actor = actor->next) {
        if (((da4bcTargetState*)state)->targets[actor->id].mode != 3
            && ((da4bcTargetState*)state)->targets[actor->id].category) {
            ((da4bcTargetState*)state)->targets[actor->id].mode = 3;
            if (func_800DB61C((void*)state, 0)) {
                ((da4bcTargetState*)state)->targets[actor->id].mode =
                    ((da4bcTargetState*)state)->targets[actor->id].oldMode;
                return 1;
            }
            ((da4bcTargetState*)state)->targets[actor->id].mode =
                ((da4bcTargetState*)state)->targets[actor->id].oldMode;
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
int func_800DBD80(actionSetupContext*, func_800DCAA0_t*);
int func_800D826C(actionSetupContext*);
int func_800DBC60(actionSetupContext*, func_800DCAA0_t*);
int func_800E45D4(int);
extern int D_800F58E0;

int func_800DAC80(actionSetupContext* context, func_800DCAA0_t* action)
{
    D_800F4538_t* actor;
    if (!func_800DBD80(context, action)) {
        return 0;
    }
    func_800D836C((void*)context);
    if (func_800D826C(context)) {
        context->action = action;
        D_800F58E0 = 1;
        actor = D_800F4538[action->unkC_0];
        if (actor != NULL && (*(u_int*)((char*)actor + 8) & 0x180000)) {
            action->unkC_4 = func_800E45D4(2);
            action->unkC_7 = 217;
        }
        func_800DEEFC((void*)context, 15);
        if (func_800DBC60(context, action)) {
            if (context->kind == 0) {
                context->cooldown = *((u_char*)D_800F58BC + 8);
            } else {
                context->cooldown = 50;
            }
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
int func_800DAD9C(actionDispatchState* state)
{
    int i, j;
    actionDispatchEntry* entry;
    actionDispatchActor* actor;
    actionDispatchModel* model;
    for (i = 0; i < state->count; i++) {
        entry = state->entries[i];
        if (func_800DAC80((void*)state, (void*)entry)) {
            return 1;
        }
    }
    entry = &state->fallback;
    if ((entry->flags4 >> 5) & 255) {
        for (j = 0; j < 4; j++) {
            actor = ((actionDispatchRegistry*)D_800F58BC)->registered[j];
            if (actor) {
                entry->flagsC = (entry->flagsC & ~15) | (actor->id & 15);
                model = (actionDispatchModel*)D_800F45E0[actor->id];
                if (model->id && model->status == 0) {
                    if (func_800DAC80((void*)state, (void*)entry)) {
                        return 1;
                    }
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
                    state->distance = func_800E4624(state->position,
                        ((actionDispatchActor*)vs_battle_actors[0])->model->position,
                        state->height, height);
                    func_800DAD9C(state);
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

typedef union {
    u_int raw;
    struct {
        u_char x, y, z, status;
    } p;
} stuckMovementPosition;

typedef struct {
    char unk0[2];
    u_char stuck;
    char unk3[0x19];
    u_char unk1C;
    char unk1D[0x17];
    stuckMovementPosition position;
    stuckMovementPosition previous;
    char unk3C[0x10];
    short x;
    char unk4E[2];
    short z;
    char unk52[0xA8];
    u_char detourStep;
    u_char unkFB;
    char unkFC[0x1C];
    u_char detourDirections[4];
    char unk11C[0x40];
    u_char unk15C;
    char unk15D[0xB];
    stuckMovementPosition destination;
} stuckMovementState;

int func_800DB0BC(stuckMovementState* state)
{
    u_char directions[4];
    u_int probe;
    u_int angle;
    u_int quadrant;
    int first;
    int second;
    int i;

    if (D_800F5920 == NULL) {
        if ((state->position.raw & 0xFF00FF) == (state->previous.raw & 0xFF00FF)) {
            state->stuck = 1;
            if (state->detourStep == 0) {
                angle = ratan2(state->x - state->destination.p.x * 128 - 64,
                    state->z - state->destination.p.z * 128 - 64);
                angle &= 0xFFF;
                first = (angle >> 9) & 7;
                second = ((angle >> 9) + 2) & 7;
                quadrant = angle >> 10;
                if (((angle & 0x3FF) > 512 ? ((quadrant + 1) & 3) * 2 : quadrant * 2)
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
                *(u_int*)state->detourDirections = *(u_int*)directions;
                probe = 0;
                for (i = 0; i < 4; ++i) {
                    ((u_char*)&probe)[0] = state->position.p.x
                                         + ((D_800F16EC_t*)0x1F8003EC)[directions[i]].dx;
                    ((u_char*)&probe)[2] = state->position.p.z
                                         + ((D_800F16EC_t*)0x1F8003EC)[directions[i]].dz;
                    if (func_800D954C((func_800D8400_t*)state, probe) > 0) {
                        state->detourStep = i;
                        break;
                    }
                }
                state->detourStep++;
            }
            if (state->detourStep >= 5) {
                func_800E4CE8((func_800DEEA4_t2*)state);
                state->unk1C = 0;
                state->detourStep = 0;
                return 0;
            }
            state->destination.p.x =
                state->position.p.x
                + ((D_800F16EC_t*)0x1F8003EC)[state->detourDirections[state->detourStep
                                                                      - 1]]
                      .dx;
            state->destination.p.z =
                state->position.p.z
                + ((D_800F16EC_t*)0x1F8003EC)[state->detourDirections[state->detourStep
                                                                      - 1]]
                      .dz;
            state->unk15C = state->unkFB;
            if (func_800D954C((func_800D8400_t*)state, state->destination.raw) > 0) {
                func_800E50A0(state, 0, 0);
            } else {
                state->detourStep++;
            }
            return 1;
        }
        state->detourStep = 0;
    }
    return 0;
}
