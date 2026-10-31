#include "common.h"
#include "6E4CC.h"
#include "6E4CCShared.h"
#include "146C.h"
#include "4DEA8.h"
#include "battleUnk.h"
#include "src/SLUS_010.40/32154.h"
#include "src/SLUS_010.40/overlay.h"
#include "build/src/include/lbas.h"
#include <abs.h>
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
int func_800D9B6C(func_800E78F4_t*, int);
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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6FC00", func_800D8400);

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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6FC00", func_800D8EF4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6FC00", func_800D9538);
