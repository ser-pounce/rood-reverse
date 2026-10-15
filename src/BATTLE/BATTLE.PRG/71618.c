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
#include <rand.h>

struct func_800D4910_t;

typedef struct {
    int unk0;
    u_short unk4;
} func_800E5A74_t;

typedef struct {
    char rangeX;
    char rangeY;
    char rangeZ;
    u_char shape : 3;
    u_char angle : 5;
} func_800E5568_t;

typedef struct {
    char unk0[0x38];
    func_800E5568_t unk38;
} func_800E5698_t2;

typedef struct {
    char unk0[0x5C];
    func_800E5698_t2* unk5C;
} func_800E5698_t;

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
    u_int unk0 : 1;
    u_int unk1 : 1;
    u_int unk2 : 1;
    u_int unk3 : 1;
    u_int unk4 : 1;
    u_int unk5 : 1;
    u_int unk6 : 16;
    u_int unk22 : 10;
} func_800DCAA0_t2;

typedef struct {
    int unk0;
    u_int unk4_0 : 3;
    u_int unk4_3 : 2;
    u_int unk4_5 : 8;
    u_int unk4_13 : 16;
    u_int unk4_29 : 3;
    int unk8;
    u_int unkC_0 : 4;
    u_int unkC_4 : 3;
    u_int unkC_7 : 12;
    u_int unkC_19 : 8;
    u_int unkC_27 : 5;
    func_800DCAA0_t2 unk10;
} func_800DCAA0_t;

typedef struct {
    u_int unk0_0 : 2;
    u_int unk0_2 : 1;
    u_int unk0_3 : 2;
    u_int unk0_5 : 1;
    u_int unk0_6 : 1;
    u_int unk0_7 : 1;
    u_int unk0_8 : 16;
    u_int unk0_24 : 8;
    u_int unk4;
} func_800DD604_t;

typedef struct {
    u_int unk0_0 : 1;
    u_int unk0_1 : 5;
    u_int unk0_6 : 2;
    u_int unk0_8 : 7;
    u_int unk0_15 : 5;
    u_int unk0_20 : 7;
    u_int unk0_27 : 1;
    u_int unk0_28 : 2;
    u_int unk0_30 : 2;
} func_800DA1D4_t;

typedef struct {
    int unk0;
    int unk4;
    u_int unk8_0 : 21;
    u_int unk8_21 : 1;
    u_int unk8_22 : 10;
    char unkC[0x10];
    SVECTOR unk1C;
} func_800E1238_t;

typedef struct func_800E78F4_t {
    char unk0[7];
    u_char unk7;
    char unk8[6];
    u_char unkE;
    char unkF[4];
    u_char unk13;
    char unk14[2];
    int unk16 : 8;
    u_char unk17;
    char unk18[3];
    u_char unk1B;
    char unk1C[4];
    u_char unk20;
    u_char unk21;
    char unk22[5];
    u_char unk27;
    char unk28[3];
    u_char unk2B;
    u_char unk2C;
    char unk2D[3];
    u_char unk30;
    char unk31[3];
    u_char unk34;
    char unk35;
    u_char unk36;
    char unk37;
    int unk38;
    char unk3C[0x10];
    SVECTOR unk4C;
    func_800DEB10_t2* unk54;
    func_800E1238_t* unk58;
    vs_battle_actor2* unk5C;
    char unk60[0x22];
    short unk82;
    char unk84[4];
    u_char unk88;
    char unk89[5];
    u_short unk8E;
    char unk90[2];
    u_short unk92;
    char unk94[4];
    u_short unk98;
    u_short unk9A;
    char unk9C[0x17];
    u_char unkB3;
    char unkB4[4];
    short unkB8;
    char unkBA[4];
    short unkBE;
    char unkC0[0x27];
    u_char unkE7;
    u_char unkE8;
    u_char unkE9;
    char unkEA[0x11];
    u_char unkFB;
    char unkFC[0x2E];
    u_char unk12A;
    char unk12B[2];
    u_char unk12D;
    u_char unk12E;
    signed char unk12F;
    signed char unk130;
    u_char unk131;
    char unk132[6];
    u_short unk138;
    char unk13A[5];
    u_char unk13F;
    func_800DCAA0_t unk140;
    char unk154[8];
    u_char unk15C;
    char unk15D[0x1F];
    int unk17C;
    int unk180;
    int unk184;
    short unk188;
    char unk18A[0x10];
    u_char unk19A;
    char unk19B[5];
    struct func_800E78F4_t* unk1A0;
    func_800DA1D4_t unk1A4[16];
    u_int unk1E4[16];
    char unk224[4];
    int unk228;
    func_800DCAA0_t* unk22C;
    func_800DD604_t unk230[6][4];
    char unk2F0[0x140];
    func_800DCAA0_t* unk430[16];
    int unk470;
} func_800E78F4_t;

typedef struct {
    u_char maxX;
    u_char maxZ;
    u_char minX;
    u_char minZ;
    char unk4[4];
    u_char unk8;
    char unk9[0xB];
    int unk14;
    u_short unk18;
    char unk1A[2];
    func_800E78F4_t* unk1C;
    func_800E78F4_t* unk20;
    int unk24;
    vs_battle_actor* unk28[4];
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
    u_char unk0;
    char unk1;
    u_char unk2;
    char unk3;
    short unk4;
    short unk6;
    char unk8[0xC];
    u_int unk14;
    u_int unk18;
    u_int unk1C_0 : 2;
    u_int unk1C_2 : 2;
    u_int unk1C_4 : 14;
    u_int unk1C_18 : 2;
    u_int unk1C_20 : 2;
    u_int unk1C_22 : 2;
    u_int unk1C_24 : 8;
    char unk20[0x18];
    short unk38;
    char unk3A[2];
    short unk3C;
    char unk3E[2];
    int unk40;
} func_800DEB10_t;

typedef struct {
    u_short unk0;
    char unk2[2];
    func_800DEB10_t unk4;
    char unk48[2];
    u_short unk4A;
    func_800DEB10_t unk4C[0];
} func_800DEEA4_t;

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
    int meta;
    u_char data[0];
} p_file_t;

typedef struct {
    u_short x : 5;
    u_short z : 5;
    u_short unk0_10 : 5;
    u_short active : 1;
} D_800F58C8_t2;

typedef struct {
    D_800F58C8_t2 unk0[8];
} D_800F58C8_t;

typedef struct {
    char unk0[2];
    u_char unk2;
    char unk3;
    u_char unk4[8];
} D_1F8003D0_t;

typedef struct {
    func_800DEEA4_t unk0;
    char unk4C[0x980];
    func_800DCAA0_t unk9CC[3][16];
    u_char unkD8C[16][256];
    func_800DCAA0_t unk1D8C[16];
} func_800DEC88_t;

void func_800D5260(VECTOR*);
void func_800D5294(int*);
void func_800D7890(int arg0);
void _parsePfileBlock1(pFileBlock1* arg0);
void _parsePfileBlock12(void*);
void _parsePfileBlock13(void*);
void func_800D8038(int);
void vs_battle_setPlgLoadState(int);
void func_800D8060(p_file_t* arg0);
void func_800D820C(int, int);
void func_800D821C(func_800E78F4_t*);
int func_800D826C(func_800E78F4_t*);
void func_800D82CC(func_800E78F4_t*);
void func_800D836C(func_800E78F4_t*);
int func_8008631C(int, int, int, int, void*);
int func_800863A4(int, int, int, int, SVECTOR*, SVECTOR*, void*);
int func_8008D2C0(func_8008D2C0_t*);
short func_8008DC7C(int, int);
int func_800DB370(func_800E78F4_t*, int, int, int);
void func_800DB5B0(func_800E78F4_t*);
void func_800DB5FC(func_800E78F4_t*);
int func_800DB61C(func_800E78F4_t*, int);
int func_800DB74C(func_800E78F4_t*, int);
int func_800DB8AC(func_800E78F4_t*, func_800DCAA0_t*);
int func_800DBB2C(func_800E78F4_t*, void*, int);
int func_800DBC60(func_800E78F4_t*, func_800DCAA0_t*);
int func_800DBCB4(func_800E78F4_t*, func_800DCAA0_t*);
int func_800DBD80(func_800E78F4_t*, func_800DCAA0_t*);
void func_800DC19C(func_800E78F4_t*);
void func_800DC210(func_800E78F4_t*, int);
int func_800DC284(int, int, int, int);
void func_800DC2E0(func_800DCAA0_t*, func_800DCAA0_t*);
void func_800DC30C(short*, short*, int, int);
void func_800DC344(func_800E78F4_t*, func_800DCAA0_t*);
void func_800DC424(func_800DC888_t*);
int func_800DC484(int, int);
int func_800DC48C(int, int);
void func_800DC4F0(func_800DCAA0_t*, vs_action_t*);
void func_800DC784(func_800E78F4_t*, int);
void func_800DC810(func_800DEEA4_t*);
void func_800DC888(func_800DC888_t*);
void func_800DE3E4(func_800E78F4_t*);
void func_800DEEFC(func_800E78F4_t*, int);
int func_800E0678(func_800E78F4_t*, int);
int func_800E0918(func_800E78F4_t*, int, int);
void func_800E2CCC(func_800E78F4_t*);
void func_800E3600(func_800E78F4_t*, int, int);
void func_800E4288(void*, int);
int func_800E42D4(int, int);
int func_800E42EC(int, int);
int func_800E45D4(int);
u_int func_800E4660(int, int, int);
int func_800E4764(func_800E78F4_t*, int*, int*);
void func_800E4B18(func_800E78F4_t*);
void func_800E4C8C(func_800E78F4_t*);
void func_800E4CE8(func_800E78F4_t* arg0);
int func_800E4CF4(func_800E78F4_t*, func_800DCAA0_t*, int);
int func_800E4DF8(func_800E78F4_t*, int, int);
void func_800E4F14(func_800E78F4_t*);
void func_800E5EC0(int, int, int);
void func_800E678C(func_800E78F4_t*);
void func_800E685C(int, int, int);
int func_800E7698(func_800E78F4_t*);
void func_800E7960(func_800E78F4_t*);

extern u_int D_80069BBC[];
extern p_file_t D_800EC4BC;
extern D_800F16EC_t D_800F16EC[8];
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
extern func_800E78F4_t* D_800F5878[];
extern u_short (*D_800F58B8)[32];
extern D_800F58BC_t* D_800F58BC;
extern D_800F58C8_t* D_800F58C8;
extern u_short (*D_800F58D0)[32];
extern int D_800F58E0;
extern func_800DCAA0_t (*D_800F58EC)[16];
extern func_800DCAA0_t* D_800F58F8;
extern func_800DEEA4_t* D_800F5900;
extern u_char (*D_800F5904)[256];
extern D_800F5910_t* D_800F5910;
extern int D_800F5918;
extern int D_800F591C;
extern D_800F5920_t* D_800F5920;

typedef struct {
    int unk0;
    u_int unk4;
} func_800E78F4_t2;

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
typedef struct movementRecoveryState movementRecoveryState;
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
int func_800E42D4(int, int);
int func_800E4624(short*, short*, int, int);
unsigned int func_800E4660(int, int, int);
void func_800DB5B8(candidateMovementState*, unsigned int, int);
void func_800DB5DC(candidateMovementState*, unsigned int, int);
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
            if (func_800DB8AC((void*)state, (void*)entry)) {
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

void func_800E50A0(void*, int, int);
void func_800E1388(func_800D8400_t*, vs_battle_movementPosition, int, unsigned int);

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

                if (model->unk12 && model->unk1A == 0 && func_800DAC80(arg0, entry)) {
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
                    state->distance = func_800E4624(state->position,
                        ((actionDispatchActor*)vs_battle_actors[0])->model->position,
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
                func_800E4CE8((void*)state);
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
