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

void func_800DC888(func_800DC888_t* arg0)
{
    int i;
    func_800DC888_t* row;

    if (D_800F5900->unk4.unk40 == 0) {
        vs_action_t* action = &vs_main_actions[D_800F5900->actionIndex];

        row = &arg0[D_800F5900->unk4.unk0.targetActor];

        switch (action->type) {
        case actionTypeSpell:
            func_800DC30C(&row->unk8, &row->unkA, action->cost, 1);
            break;

        case actionTypeBreakArt:
            func_800DC30C(&row->unk4, &row->unk6, action->cost, 1);
            break;

        case actionTypeBaseAttack:
            func_800DC30C(&row->unk10, &row->unk12, action->cost, 1);
            break;
        }
    }

    for (i = -1; i < D_800F5900->unk4A; ++i) {
        _hitEntity_t* entry = i < 0 ? &D_800F5900->unk4 : &D_800F5900->unk4C[i];

        if (entry->unk40 == 0) {
            row = &arg0[entry->unk0.targetActor];
            func_800DC30C(&row->unk4, &row->unk6, entry->unk0.hp, entry->hpEffect);
            func_800DC30C(&row->unk8, &row->unkA, entry->unk0.mp, entry->mpEffect);
            func_800DC30C(
                &row->unk10, &row->unk12, entry->weaponDp, entry->weaponDpEffect);
            func_800DC30C(&row->unk14, &row->unk16, entry->armorDp, entry->armorDpEffect);
            row->unkC |= entry->removeStatuses;
            row->unkC &= ~entry->inflictStatuses;
        }
    }
}

void func_800DCAA0(
    func_800E78F4_t* arg0, func_800DC888_t* arg1, func_800DCAA0_t* arg2, int arg3)
{
    SVECTOR sp20;
    SVECTOR sp28;
    int temp_s0 = arg2->unkC_0;
    int temp_v0;

    if (arg3 != 3) {
        temp_v0 =
            func_8008631C(arg2->unk4_5, arg0->unk88, temp_s0, arg2->unkC_4, D_800F5900);
    } else {
        D_800F4538_t* actor = D_800F4538[temp_s0];
        sp28.vx = actor->unk0.position.vx;
        sp28.vz = actor->unk0.position.vz;
        sp28.vy = actor->unk0.position.vy - arg2->unkC_7;
        *(int*)&sp20.vx = *(int*)&sp28.vx;
        sp20.vz = sp28.vz + vs_gte_rsqrt(arg2->unk8);
        temp_v0 = func_800863A4(
            arg2->unk4_5, arg0->unk88, temp_s0, arg2->unkC_4, &sp20, &sp28, D_800F5900);
    }
    if (temp_v0 != 0) {
        func_800DC888(arg1);
    }
}

void func_800DCBD8(func_800DCAA0_t* arg0)
{
    int i;
    int threshold = 0;
    int id = arg0->unkC_0;

    for (i = 0; i < D_800F5900->unk4A; ++i) {
        _hitEntity_t* entry = &D_800F5900->unk4C[i];
        if ((entry->unk40 == 0) && (id == D_800F5900->unk4C[i].unk0.targetActor)) {
            threshold = D_800F5900->unk4C[i].unk0.hitThreshold;
            break;
        }
    }

    arg0->unkC_19 = threshold + (threshold >> 2) + (threshold >> 5);
}

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/74088", D_80069B68);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/74088", D_80069BBC);

static inline int _getStatusScore(func_800DC888_t* stats)
{
    static const signed char statusScores[] = { -51, -39, -39, -39, -26, -51, 50, -13, 12,
        -13, 12, 25, -51, -26, -45, -26, -39, 76, 19, -13, 12, 12, 12, 12, 12, 12, 12, 12,
        12, 0, 0, 0 };
    int score = 0;
    int i;
    int noCost = D_800F5878[stats->unk0_0]->unk17 == 0;

    for (i = 0; i < 32; ++i) {
        if (stats->unkC & (1 << i) && (i != 12 || !noCost)) {
            score += statusScores[i];
        }
    }

    if (stats->unk4 == 0) {
        score -= 128;
    }

    if (stats->unk4 * 128 < stats->unk6 * 44) {
        score -= 84;
    }

    return score;
}

static inline int _getHpRatio(func_800DC888_t* stats, int id)
{
    if (stats[id].unk6 == 0) {
        return 0;
    }

    return stats[id].unk4 * 128 / stats[id].unk6;
}

static inline int _getMpRatio(func_800DC888_t* stats, int id)
{
    if (stats[id].unkA == 0) {
        return 0;
    }

    return stats[id].unk8 * 128 / stats[id].unkA;
}

static inline int _getExtraRatio(func_800DC888_t* stats, int id)
{
    int ratio = 0;

    if (stats[id].unk12 != 0) {
        ratio = stats[id].unk10 * 128 / stats[id].unk12;
    }

    if (stats[id].unk16 != 0) {
        ratio += stats[id].unk14 * 128 / stats[id].unk16;
    }

    return ratio;
}

void func_800DCC94(
    func_800E78F4_t* arg0, func_800DCAA0_t* arg1, int arg2, vs_action_t* arg3)
{
    int special = 0;
    vs_actionFlags_t flags = { 0 };
    vs_battle_actor* actor;
    func_800DC888_t* stats;

    if (arg3 != NULL) {
        flags = arg3->flagsE;
    }

    if (flags.unk5 && (rand() & 0x7F) < 115) {
        arg1->unk0 = 0x80000000;
        return;
    }

    arg1->unk0 = 0;
    arg1->unkC_19 = 128;
    stats = (func_800DC888_t*)0x1F80018C;
    func_800DC424(stats);

    if (arg0->unk2B && flags.unk4) {
        special = 1;
        arg1->unkC_19 = 40;
    } else if (arg2 != 0) {
        func_800DCAA0(arg0, stats, arg1, arg2);
        func_800DCBD8(arg1);
    }

    for (actor = vs_battle_actors[0]; actor != NULL; actor = actor->next) {
        int id = actor->id;
        int kind = arg0->unk1A4[id].unk0_6;
        int value;

        if (kind == 1) {
            continue;
        }

        value = func_800DC284(_getStatusScore(&stats[id]), _getHpRatio(stats, id),
            _getMpRatio(stats, id), _getExtraRatio(stats, id));

        if (kind != 2) {
            value = -value;
        }

        arg1->unk0 += value;
    }

    if (special) {
        ++arg1->unk0;
    }

    arg1->unk0 = arg1->unk0 * 128 + arg1->unkC_19;
}

void func_800DD000(func_800E78F4_t* arg0, D_800F19CC_t2* arg1)
{
    int id;
    int source;
    int action;
    int i;
    int skip;
    vs_action_t* info;
    func_800E78F4_t* other;

    if (arg1 == NULL || arg1->unk4.unk40) {
        return;
    }

    id = arg0->unk88;

    if (id == 0) {
        return;
    }

    info = &vs_main_actions[arg1->actionIndex];
    skip = info->hitParams[0].prerequisiteFunction == 3
        || info->hitParams[1].prerequisiteFunction == 3;

    if (skip) {
        return;
    }

    source = arg1->unk4.unk0.targetActor;
    action = arg1->actionIndex;
    other = D_800F5878[source];

    for (i = 0; i < arg1->unk4A; ++i) {
        _hitEntity_t* entry = &arg1->unk4C[i];

        if (entry->unk40 || entry->unk0.targetActor != id || source == id) {
            continue;
        }

        if (arg0->unk12D == 1) {
            arg0->unk12D = 2;
        }

        if (func_800DC48C(action, arg0->unk88)) {
            if (source == 0 && arg0->unk13 == 0 && arg0->unk27) {
                func_800DC210(arg0, 0);
            } else if (other->unk1A4[0].unk0_6 == 3) {
                func_800DC19C(arg0);
            }
        }

        arg0->unk1A4[source].unk0_15 = 28;

        if (!func_800DC484(action, arg0->unk88)) {
            continue;
        }

        if (D_800F5920 != NULL && source == 0 && entry->hpEffect != 2
            && entry->unk0.hp > 0) {
            D_800F5920->unkA = 0;
        }

        if (source == 0 && arg0->unk27) {
            func_800DC19C(arg0);
        }

        if (arg0->unk30 && (arg0->unk20 == 0 || source == 0)) {
            func_800DC784(arg0, source);
        } else if (arg0->unk1A4[source].unk0_6 != 3) {
            if (other->unk1A4[id].unk0_20) {
                other->unk1A4[id].unk0_20 = 0;
                other->unk1A4[id].unk0_6 = other->unk1A4[id].unk0_28;
            } else {
                arg0->unk1A4[source].unk0_20 = 127;
                arg0->unk1A4[source].unk0_28 = arg0->unk1A4[source].unk0_6;

                if (arg0->unk20) {
                    func_800DC784(arg0, source);
                }
            }
        }
    }
}

void func_800DD344(func_800E78F4_t* arg0)
{
    vs_battle_actor* actor;
    vs_battle_actor* target;
    vs_battle_actor* ally;

    if (arg0->unk13) {
        for (actor = vs_battle_actors[0]; actor != NULL; actor = actor->next) {
            int id = actor->id;
            func_800E78F4_t* other = D_800F5878[id];
            int kind;

            if (id == arg0->unk88 || id == 0 || other->unk2C == 3) {
                kind = 2;
            } else if (!other->unk13) {
                if (other->unk1A4[0].unk0_6 == 3) {
                    kind = 3;
                    arg0->unk1A4[id].unk0_20 = 0;
                } else {
                    kind = 1;
                }
            } else {
                kind = 1;
            }

            arg0->unk1A4[id].unk0_6 = kind;
        }
    } else if (arg0->unk21) {
        for (actor = vs_battle_actors[0]; actor != NULL; actor = actor->next) {
            func_800E78F4_t* other = D_800F5878[actor->id];

            if (arg0->unk1A4[actor->id].unk0_6 != 2
                || other->unk1A4[arg0->unk88].unk0_6 != 2) {
                continue;
            }

            for (target = vs_battle_actors[0]; target != NULL; target = target->next) {
                int id = target->id;

                if (arg0->unk1A4[id].unk0_6 != 1 || !arg0->unk1A4[id].unk0_0
                    || other->unk1A4[id].unk0_6 != 3) {
                    continue;
                }

                for (ally = vs_battle_actors[0]; ally != NULL; ally = ally->next) {
                    func_800E78F4_t* allyState = D_800F5878[ally->id];

                    if (arg0->unk1A4[ally->id].unk0_6 == 2
                        && allyState->unk1A4[arg0->unk88].unk0_6 == 2
                        && (allyState->unk1A4[id].unk0_6 == 2
                            || (allyState->unk1A4[id].unk0_20
                                && allyState->unk1A4[id].unk0_28 == 2))) {
                        break;
                    }
                }

                if (ally == NULL) {
                    func_800DC784(arg0, id);
                }
            }
        }
    }
}

void func_800DD604(func_800E78F4_t* arg0)
{
    u_int best = 0;
    int row;
    int col;
    func_800DCAA0_t* choice = &arg0->unk140;
    vs_battle_actor2* stats = arg0->unk5C;

    for (row = 0; row < 6; ++row) {
        for (col = 0; col < 4; ++col) {
            int action = stats->armor[row][col].id;
            func_800DD604_t* config = &arg0->unk230[row][col];
            func_800DCAA0_t2 flags;

            if (!func_800E4DF8(arg0, row, col) || !config->unk0_6
                || best >= config->unk4) {
                continue;
            }

            best = config->unk4;
            choice->unk8 = best;
            choice->unk4_3 = col;
            choice->unk4_0 = row;
            choice->unk4_5 = action;
            choice->unk10.unk1 = 0;
            flags = choice->unk10;
            flags.unk2 = vs_main_actions[action].flagsE.unk12;
            choice->unkC_19 = 128;
            flags.unk0 = 0;
            flags.unk3 = 0;
            choice->unk10 = flags;
        }
    }

    if (best == 0) {
        choice->unk4_5 = 0;
    }
}

void func_800DD7CC(func_800E78F4_t* arg0, func_800DFA54_t* arg1)
{
    int i;
    u_int nearest = -1;
    u_short(*map)[32] = *(u_short(**)[32])0x1F8003BC;

    *(u_short(**)[32])0x1F8003BC = D_800F58D0;

    for (i = 0; i < 8; ++i) {
        int x;
        int z;
        int dx;
        int dz;
        u_int distance;

        if (!D_800F58C8->unk0[i].active) {
            continue;
        }

        x = D_800F58C8->unk0[i].x * 128 + 64;
        z = D_800F58C8->unk0[i].z * 128 + 64;
        dx = arg0->unk4C.vx - x;
        dz = arg0->unk4C.vz - z;
        distance = func_800E4660(dx, arg0->unk4C.vy - func_800E42D4(x, z), dz);

        if (distance < nearest) {
            arg1->unk0 = D_800F58C8->unk0[i].x;
            nearest = distance;
            arg1->unk2 = D_800F58C8->unk0[i].z;
        }
    }

    *(u_short(**)[32])0x1F8003BC = map;
}

void func_800DD918(func_800E78F4_t* arg0, int arg1)
{
    func_800DCAA0_t* list = (func_800DCAA0_t*)0x1F80030C;
    func_800DCAA0_t* candidate;
    int pass;
    int row;
    int col;
    int limb;
    int part;
    int last;
    vs_battle_actor* actor;
    func_800E78F4_t* target;

    func_800E4288(list, sizeof *list);
    list[0].unk8 = 256;
    list[0].unk4_13 = arg1;
    func_800DCC94(arg0, list, 0, NULL);
    func_800DC2E0(&list[1], list);
    list[1].unk4_13 = arg1;
    candidate = &list[1];

    for (row = 0; row < 6; ++row) {
        for (col = 0; col < 4; ++col) {
            int action = arg0->unk5C->armor[row][col].id;
            func_800DD604_t* config = &arg0->unk230[row][col];
            vs_action_t* info = &vs_main_actions[action];
            int flag;

            if (action == 0 || !config->unk0_7) {
                continue;
            }

            list[1].unk4_3 = col;
            list[1].unk4_0 = row;
            list[1].unk4_5 = action;
            flag = info->flagsE.unk13;
            list[1].unk10.unk1 = info->flagsE.unk7 | flag;
            list[1].unk10.unk2 = info->flagsE.unk12;
            list[1].unk10.unk3 = config->unk0_2;
            list[1].unk10.unk6 = config->unk0_8;
            list[1].unk8 = config->unk4;

            for (actor = vs_battle_actors[0]; actor != NULL; actor = actor->next) {
                u_int id = actor->id;

                if (D_800F5878[id]->unk1B) {
                    continue;
                }

                list[1].unkC_0 = id;
                list[1].unk10.unk4 = func_800DC484(action, id);
                list[1].unk10.unk5 = func_800DC48C(action, id);
                list[1].unk10.unk0 = config->unk0_5 && list[1].unk10.unk4;

                if (!func_800E4CF4(arg0, candidate, id) || D_800F5904[id][action]) {
                    continue;
                }

                switch (config->unk0_3) {
                case 1:
                    func_800DCC94(arg0, candidate, 1, info);
                    func_800DC4F0(candidate, info);

                    if (list[1].unk0 > list[0].unk0) {
                        func_800DC344(arg0, candidate);
                    }
                    break;

                case 2:
                    last = -1;
                    func_800DC2E0(&list[2], list);
                    func_800DC2E0(&list[3], list);

                    for (limb = 0; limb < 6; ++limb) {
                        int chance;

                        if ((actor->unk3C->limbs + limb)->maxHp == 0) {
                            continue;
                        }

                        last = limb;
                        list[1].unkC_4 = last;
                        func_800DCC94(arg0, candidate, 2, info);
                        chance = list[1].unkC_19;

                        if ((rand() & 0x7F) < chance && list[1].unk0 > list[2].unk0) {
                            func_800DC2E0(&list[2], candidate);
                        }

                        if (list[1].unk0 > list[3].unk0) {
                            func_800DC2E0(&list[3], &list[1]);
                        }
                    }

                    part = rand();
                    part = (part & 3) + ((part >> 2) & 1) + ((part >> 3) & 1);

                    if ((actor->unk3C->limbs + part)->maxHp == 0 && last >= 0) {
                        part = last;
                    }

                    if (part >= 0) {
                        list[1].unkC_4 = part;
                        func_800DC4F0(&list[1], info);
                    }

                    if (list[2].unk0 > list[0].unk0) {
                        func_800DC344(arg0, &list[2]);
                    } else if (list[0].unk0 < list[3].unk0) {
                        func_800DC344(arg0, &list[3]);
                    }
                    break;

                case 3:
                    target = D_800F5878[actor->id];
                    func_800DC2E0(&list[2], list);
                    func_800DC2E0(&list[3], list);
                    list[1].unkC_7 = 0;

                    for (pass = 0; pass < 1; ++pass) {
                        int chance;

                        list[1].unkC_7 = ABS(target->unk82);
                        func_800DCC94(arg0, candidate, 3, info);
                        chance = list[1].unkC_19;

                        if ((rand() & 0x7F) < chance && list[1].unk0 > list[2].unk0) {
                            func_800DC2E0(&list[2], candidate);
                        }

                        if (list[1].unk0 > list[3].unk0) {
                            func_800DC2E0(&list[3], &list[1]);
                        }
                    }

                    func_800DC4F0(&list[1], info);

                    if (list[2].unk0 > list[0].unk0) {
                        func_800DC344(arg0, &list[2]);
                    } else if (list[0].unk0 < list[3].unk0) {
                        func_800DC344(arg0, &list[3]);
                    }
                    break;
                }
            }
        }
    }
}

void func_800DE030(int arg0)
{
    vs_battle_actor* actor;
    int ticks = (arg0 >> 5) + (arg0 >> 9);

    D_800F58BC->unk18 += arg0;

    for (actor = vs_battle_actors[0]; actor != NULL; actor = actor->next) {
        vs_battle_actor2* stats = actor->unk3C;
        int statuses = stats->statuses;
        func_800E78F4_t* state;
        int i;
        int limb;
        int amount;
        int row;
        int column;

        if (D_800F58BC->unk18 > 2880) {
            for (limb = 0; limb < 6; ++limb) {
                vs_battle_uiEquipment_limb* limbs = &stats->limbs[limb];

                limbs->hp += 2;

                if (limbs->hp > limbs->maxHp) {
                    limbs->hp = limbs->maxHp;
                }
            }
        }

        if (stats->limbs[stats->unk34].hp >= 2 || stats->limbs[stats->unk35].hp >= 2) {
            statuses &= ~0x10;
        }

        amount = arg0 / 240;

        if (amount > 0) {
            stats->currentHP += amount - 1;
        }

        if (stats->currentHP > stats->maxHP) {
            stats->currentHP = stats->maxHP;
        }

        amount = arg0 / 180;

        if (amount > 0) {
            stats->currentMP += amount - 1;
        }

        if (stats->currentMP > stats->maxMP) {
            stats->currentMP = stats->maxMP;
        }

        if (statuses & 0x4000) {
            int scale = stats->maxHP * 5;

            stats->currentHP -= ticks / vs_main_statusEffectParams[14].unk6 * scale / 100;

            if (stats->currentHP < 0) {
                stats->currentHP = 0;
            }
        }

        if (statuses & 0x20000) {
            int scale = stats->maxHP * 5;

            stats->currentHP += ticks / vs_main_statusEffectParams[17].unk6 * scale / 100;

            if (stats->currentHP < 0) {
                stats->currentHP = 0;
            }
        }

        for (i = 0; i < 5; ++i) {
            if (statuses & D_80069BBC[i]) {
                int duration = stats->statusTimers[i];

                duration = duration * 32 - duration * 2;

                if (D_800F58BC->unk18 >= duration) {
                    statuses &= ~D_80069BBC[i];
                }
            }
        }

        stats->statuses = statuses;
        state = D_800F5878[actor->id];
        func_800E4F14(state);

        for (row = 0; row < 6; ++row) {
            for (column = 0; column < 4; ++column) {
                func_800E4DF8(state, row, column);
            }
        }
    }
}

static inline int _snapshotActorStats(void)
{
    vs_battle_actor* actor;

    D_800F58E8 = vs_main_allocHeapR(sizeof *D_800F58E8 * 16);

    if (D_800F58E8 == NULL) {
        return 0;
    }

    for (actor = vs_battle_actors[0]; actor != NULL; actor = actor->next) {
        func_800DC3E8(actor->unk3C, &D_800F58E8[actor->id]);
    }

    return 1;
}

static inline void _restoreActorStats(void)
{
    vs_battle_actor* actor;

    for (actor = vs_battle_actors[0]; actor != NULL; actor = actor->next) {
        func_800DC3E8(&D_800F58E8[actor->id], actor->unk3C);
    }

    vs_main_freeHeapR(D_800F58E8);
}

void func_800DE3E4(func_800E78F4_t* arg0)
{
    int delays[3] = { 0, 455, 2900 };
    int quotas[3] = { 10, 3, 3 };
    int selected[3];
    int row;
    int column;
    int pass;
    int i;
    int j;
    int delay;
    int minDelay;
    vs_battle_actor* actor;
    vs_battle_actor2* stats = arg0->unk5C;
    vs_battle_actor* self;

    D_800F58F0 = 0;
    D_800F58F4 = 0;

    for (row = 0; row < 6; ++row) {
        for (column = 0; column < 4; ++column) {
            for (actor = vs_battle_actors[0]; actor != NULL; actor = actor->next) {
                D_800F5904[actor->id][stats->armor[row][column].id] = 0;
            }
        }
    }

    arg0->unk470 = 0;

    if (arg0->unk88 == 0) {
        return;
    }

    if (_snapshotActorStats()) {
        minDelay = MAX(arg0->unk13F, arg0->unk5C->unk954 / 35);
        D_800F58BC->unk18 = 0;

        for (pass = 0; pass < 3; ++pass) {
            delay = MAX(delays[pass], minDelay);
            func_800DE030(delay);
            func_800DD918(arg0, (short)delay);
            func_800DC3CC(arg0);

            if (pass == 1) {
                selected[1] = MAX(16 - selected[0] - quotas[2], 0);
                selected[pass] = MIN(selected[1], arg0->unk470);
            } else {
                selected[pass] = MIN(arg0->unk470, quotas[pass]);
            }

            for (i = 0; i < selected[pass]; ++i) {
                func_800DC2E0(&D_800F58EC[pass][i], arg0->unk430[i]);
            }

            for (i = selected[pass]; i < arg0->unk470; ++i) {
                D_800F5904[arg0->unk430[i]->unkC_0][arg0->unk430[i]->unk4_5] = 0;
            }

            arg0->unk470 = 0;
        }

        for (pass = 0; pass < 3; ++pass) {
            for (j = 0; j < selected[pass]; ++j) {
                int index = arg0->unk470;
                func_800DCAA0_t* entry = &arg0->unk2F0[index];

                func_800DC2E0(entry, &D_800F58EC[pass][j]);
                arg0->unk430[index] = entry;
                arg0->unk470 = index + 1;

                if (index + 1 >= 16) {
                    goto restore;
                }
            }
        }

        if (arg0->unk470 == 0 && arg0->unk26) {
            for (i = 0; i < D_800F58F0; ++i) {
                func_800DCAA0_t* fallback = &arg0->unk2F0[i];

                func_800DC2E0(fallback, &D_800F58F8[i]);
                fallback->unkC_19 = 128;
                arg0->unk430[i] = fallback;
            }

            arg0->unk470 = D_800F58F0;
            func_800DC3CC(arg0);
        }

    restore:
        _restoreActorStats();
        D_800F58BC->unk18 = 0;
    } else {
        func_800DD918(arg0, 0);
        func_800DC3CC(arg0);
    }

    if (arg0->unk470 >= 2) {
        for (pass = 0; pass < 3; ++pass) {
            if (selected[pass] != 0) {
                func_800DC574(arg0, selected[pass]);
                break;
            }
        }
    }

    for (i = 0; i < arg0->unk470; ++i) {
        if (i > 0 && arg0->unk430[i]->unk4_13 - arg0->unk430[0]->unk4_13 < 80) {
            arg0->unk430[i]->unk4_13 = arg0->unk430[0]->unk4_13 + 80;
        }

        arg0->unk430[i]->unk4_13 += rand() & 7;
    }

    func_800D85D8(arg0);

    if (arg0->unk470 == 0) {
        arg0->unk12E = 7;
    } else {
        func_800D9DD8(arg0);
    }

    if (D_800F5920 == NULL) {
        return;
    }

    self = (vs_battle_actor*)arg0->unk54;

    if (vs_battle_getStateFlag(0xA6) == 4 && self->command.fields.unk9 == 24
        && self->unkC == 4) {
        vs_battle_setStateFlag(0xA6, 5);
    }

    if (D_800F5920->unk16 && self->subType - 172 < 2u) {
        D_800F5920->unk17 = arg0->unk470;
        arg0->unk470 = 0;
    }
}

void func_800DEB10(D_800F19CC_t2* arg0)
{
    int i;
    int j;
    func_800E78F4_t* entry;
    vs_battle_actorView_t* temp_t1;

    if (arg0 == NULL) {
        return;
    }

    if (arg0->unk4.unk40 != 0) {
        return;
    }

    entry = D_800F5878[arg0->unk4.unk0.targetActor];
    temp_t1 = entry->unk54;

    if (entry == NULL) {
        return;
    }

    if (temp_t1->unk9 != 24) {
        return;
    }

    for (i = 0; i < entry->unk470; ++i) {
        func_800DCAA0_t** list = entry->unk430;
        func_800DCAA0_t* temp_a2 = list[i];

        if ((arg0->actionIndex == temp_a2->unk4_5) && (temp_t1->unkC == temp_a2->unk4_0)
            && (temp_t1->unkE == temp_a2->unk4_3)) {
            entry->unkFB = temp_a2->unkC_0;
            for (j = 0; j < arg0->unk4A; ++j) {
                _hitEntity_t* elem = &arg0->unk4C[j];

                if (elem->unk40 == 0) {
                    D_800F45E0_t* actor = D_800F45E0[elem->unk0.targetActor];

                    if ((actor == NULL) || ((0x14 >> actor->unk16C.actorId) & 1)) {
                        func_800E4CE8(entry);
                        return;
                    }
                }
            }
        }
    }

    func_800E4C8C(entry);
}

int func_800DEC88(void* arg0)
{
    D_800F19CC_t2* action = arg0;
    func_800DEC88_t* heap;
    vs_battle_actor* actor;

    D_800F58BC->unk18 = 0;
    heap = vs_main_allocHeapR(sizeof *heap);
    D_800F5900 = &heap->unk0;
    D_800F58EC = heap->unk9CC;
    D_800F5904 = heap->unkD8C;
    D_800F58F8 = heap->unk1D8C;

    if (heap != NULL) {
        func_800DEB10(action);

        for (actor = vs_battle_actors[0]; actor != NULL; actor = actor->next) {
            func_800E78F4_t* state = D_800F5878[actor->id];

            state->unkE8 = 0;
            state->unkE7 = 0;
            state->unk19A = 0;
            func_800E685C(state->unk88, actor->unk3C->unk31, actor->unk3C->unk33);
            func_800DD604(state);

            if (action != NULL && action->unk4.unk40 == 0
                && action->unk4.unk0.targetActor == state->unk88) {
                state->unk9A = 0;
            }
        }

        func_800DC810(action);

        for (actor = vs_battle_actors[0]; actor != NULL; actor = actor->next) {
            D_800F5878[actor->id]->unk1B = actor->unk3C->currentHP == 0;
        }

        for (actor = vs_battle_actors[0]; actor != NULL; actor = actor->next) {
            func_800E78F4_t* state = D_800F5878[actor->id];

            func_800DE3E4(state);

            if (state->unk13) {
                if (actor->command.fields.unk8 & 0x20) {
                    func_800D821C(state);
                } else {
                    func_800D820C(state->unk88, 128);
                }
            }
        }

        D_800F58BC->unk18 = 0;

        if (D_800F5900 != NULL) {
            vs_main_freeHeapR(D_800F5900);
        }
    }

    return 0;
}

void func_800DEEA4(D_800F19CC_t2* arg0)
{
    if (arg0 != NULL) {
        if (arg0->unk4.unk40 == 0) {
            func_800E78F4_t* entry = D_800F5878[arg0->unk4.unk0.targetActor];

            if (entry != NULL) {
                entry->unk9A = 0;
            }
        }

        func_800DC810(arg0);
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/74088", func_800DEEFC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/74088", func_800DF8A4);

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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/74088", func_800DFBCC);

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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/74088", func_800E0A68);

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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/74088", func_800E24EC);

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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/74088", func_800E2F5C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/74088", func_800E3600);
