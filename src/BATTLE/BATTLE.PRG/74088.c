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
    char unk0[0x88];
    u_char unk88;
} func_800DCAA0_t1;

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
    u_char unk0;
    char unk1;
    u_char unk2;
    char unk3[0x3D];
    int unk40;
} func_800DEB10_t;

typedef struct {
    u_short unk0;
    char unk2[2];
    u_char unk4;
    char unk5[0x3F];
    int unk44;
    char unk48[2];
    u_short unk4A;
    func_800DEB10_t unk4C[0];
} func_800DEEA4_t;

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
int func_8008631C(int, int, int, int, void*);
int func_800863A4(int, int, int, int, SVECTOR*, SVECTOR*, void*);
void func_800DC810(func_800DEEA4_t*);
struct actionStatSnapshot;
void func_800DC888(struct actionStatSnapshot*);
void func_800E4C8C(func_800DEEA4_t2*);
void func_800E4CE8(func_800DEEA4_t2* arg0);
extern func_800DEEA4_t2* D_800F5878[];
extern D_800F58BC_t* D_800F58BC;
extern u_short (*D_800F58D0)[32];
extern func_800DEEA4_t* D_800F5900;
extern D_800F5920_t* D_800F5920;

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
int func_800D85D8(actionCandidateState* state);
struct actorEvaluationState;
void func_800D821C(struct actorEvaluationState*);
void func_800E4F14(void*);
int func_800E42D4(int, int);
unsigned int func_800E4660(int, int, int);
void func_800D820C(int, int);

typedef struct actionStatSnapshot {
    int unknown;
    short hp, maxHP, mp, maxMP;
    unsigned int status;
    short value10, limit10, value14, limit14;
} actionStatSnapshot;
typedef struct {
    unsigned char actor;
    char pad1;
    unsigned char value2;
    char pad3;
    short hp, mp;
    char pad8[12];
    unsigned int addStatus, removeStatus, modes;
    char pad20[24];
    short value10;
    char pad3A[2];
    short value14;
    char pad3E[2];
    int skip;
} actionStatDelta;
typedef struct {
    unsigned short action;
    char pad2[2];
    actionStatDelta first;
    char pad48[2];
    unsigned short count;
    actionStatDelta entries[1];
} actionStatApplication;
typedef struct {
    unsigned int flags;
    char pad4[48];
} actionCostView;

void func_800DC30C(short*, short*, int, int);
void func_800DC888(actionStatSnapshot* stats)
{
    actionStatSnapshot* row;
    actionStatDelta* entry;
    actionCostView* action;
    int i, ok;
    if (!((actionStatApplication*)D_800F5900)->first.skip) {
        action = (actionCostView*)&vs_main_actions[((actionStatApplication*)D_800F5900)
                ->action];
        row = &stats[((actionStatApplication*)D_800F5900)->first.actor];
        switch ((int)((action->flags >> 17) & 7)) {
        case 1:
            func_800DC30C(&row->mp, &row->maxMP, ((unsigned char*)action)[3], 1);
            break;
        case 3:
            func_800DC30C(&row->hp, &row->maxHP, ((unsigned char*)action)[3], 1);
            break;
        case 6:
            func_800DC30C(&row->value10, &row->limit10, ((unsigned char*)action)[3], 1);
            break;
        }
    }
    /* Preserve the original unconditional success guard after applying the cost.
     */
    ok = 1;
    if (ok) {
        for (i = -1; i < ((actionStatApplication*)D_800F5900)->count; i++) {
            if (i < 0) {
                entry = &((actionStatApplication*)D_800F5900)->first;
            } else {
                entry = &((actionStatApplication*)D_800F5900)->entries[i];
            }
            if (!entry->skip) {
                row = &stats[entry->actor];
                func_800DC30C(&row->hp, &row->maxHP, entry->hp, entry->modes & 3);
                func_800DC30C(&row->mp, &row->maxMP, entry->mp, (entry->modes >> 2) & 3);
                func_800DC30C(&row->value10, &row->limit10, entry->value10,
                    (entry->modes >> 18) & 3);
                func_800DC30C(&row->value14, &row->limit14, entry->value14,
                    (entry->modes >> 22) & 3);
                row->status |= entry->addStatus;
                row->status &= ~entry->removeStatus;
            }
        }
    }
}

void func_800DCAA0(func_800DCAA0_t1* arg0, int arg1, func_800DCAA0_t* arg2, int arg3)
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
        func_800DC888((void*)arg1);
    }
}

void func_800DCBD8(func_800DCAA0_t* arg0)
{
    int i;
    int threshold = 0;
    int id = arg0->unkC_0;

    for (i = 0; i < D_800F5900->unk4A; ++i) {
        func_800DEB10_t* entry = &D_800F5900->unk4C[i];
        if ((entry->unk40 == 0) && (id == D_800F5900->unk4C[i].unk0)) {
            threshold = D_800F5900->unk4C[i].unk2;
            break;
        }
    }

    arg0->unkC_19 = threshold + (threshold >> 2) + (threshold >> 5);
}

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/74088", D_80069B68);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/74088", D_80069BBC);

typedef struct {
    char pad0[0x17];
    unsigned char maxActionCost;
    char pad18[0x13];
    unsigned char special;
    char pad2C[0x178];
    struct {
        unsigned char classification;
        char pad[3];
    } targets[16];
} actionScoreState;
typedef struct actionScoreActor {
    struct actionScoreActor* next;
    int id;
} actionScoreActor;
typedef struct {
    char pad[14];
    unsigned short flags;
} actionScoreMetadata;
void func_800DC424(actionStatSnapshot*);
int func_800DC284(int, int, int, int);
const signed char D_80069BD0[] = { -51, -39, -39, -39, -26, -51, 50, -13, 12, -13, 12, 25,
    -51, -26, -45, -26, -39, 76, 19, -13, 12, 12, 12, 12, 12, 12, 12, 12, 12, 0, 0, 0 };
static inline int actionStatusScore(actionStatSnapshot* stats, int id)
{
    int sum = 0, i, noCost;
    actionStatSnapshot* row =
        (actionStatSnapshot*)(id * sizeof(actionStatSnapshot) + (int)stats);
    noCost = ((actionScoreState*)D_800F5878[row->unknown & 15])->maxActionCost == 0;
    for (i = 0; i < 32; i++) {
        if (row->status & (1 << i)) {
            if (i != 12 || !noCost) {
                sum += D_80069BD0[i];
            }
        }
    }
    if (!row->hp) {
        sum -= 128;
    }
    if ((row->hp << 7) < row->maxHP * 44) {
        sum -= 84;
    }
    return sum;
}
static inline int actionHpRatio(actionStatSnapshot* stats, int id)
{
    int d = stats[id].maxHP;
    if (d == 0) {
        return 0;
    }
    return (stats[id].hp << 7) / d;
}
static inline int actionMpRatio(actionStatSnapshot* stats, int id)
{
    int d = stats[id].maxMP;
    if (d == 0) {
        return 0;
    }
    return (stats[id].mp << 7) / d;
}
static inline int actionExtraRatio(actionStatSnapshot* stats, int id)
{
    actionStatSnapshot* row =
        (actionStatSnapshot*)(id * sizeof(actionStatSnapshot) + (int)stats);
    int extra = 0;
    if (row->limit10) {
        extra = (row->value10 << 7) / row->limit10;
    }
    if (row->limit14) {
        extra += (row->value14 << 7) / row->limit14;
    }
    return extra;
}
void func_800DCC94(actionScoreState* state, actionCandidateEntry* candidate, int mode,
    actionScoreMetadata* action)
{
    int special = 0, flags = 0, value;
    actionScoreActor* actor;
    actionStatSnapshot* stats;
    int id;
    unsigned int kind;
    if (action) {
        flags = action->flags;
    }
    if ((flags & 32) && (rand() & 127) < 115) {
        candidate->score = 0x80000000;
        return;
    }
    candidate->score = 0;
    candidate->weight = 128;
    stats = (actionStatSnapshot*)0x1F80018C;
    func_800DC424(stats);
    if (state->special && (flags & 16)) {
        special = 1;
        candidate->weight = 40;
    } else if (mode) {
        func_800DCAA0((void*)state, (int)stats, (void*)candidate, mode);
        func_800DCBD8((void*)candidate);
    }
    for (actor = (void*)vs_battle_actors[0]; actor; actor = actor->next) {
        id = actor->id;
        kind = state->targets[id].classification;
        kind >>= 6;
        if (kind == 1) {
            continue;
        }
        value = func_800DC284(actionStatusScore(stats, id), actionHpRatio(stats, id),
            actionMpRatio(stats, id), actionExtraRatio(stats, id));
        if (kind != 2) {
            value = -value;
        }
        candidate->score += value;
    }
    if (special) {
        candidate->score++;
    }
    candidate->score = (candidate->score << 7) + candidate->weight;
}

typedef union {
    unsigned int raw;
    struct {
        unsigned int unk0 : 6, classification : 2, unk8 : 7, timer : 5, counter : 7,
            unk27 : 1, previous : 2, unk30 : 2;
    } p;
    struct {
        unsigned char flags, pad[3];
    } b;
} actionReactionTarget;
typedef struct {
    char pad0[0x13];
    unsigned char flag13;
    char pad14[12];
    unsigned char flag20, flag21;
    char pad22[5];
    unsigned char flag27;
    char pad28[4];
    unsigned char flag2C;
    char pad2D[3];
    unsigned char flag30;
    char pad31[0x57];
    unsigned char id;
    char pad89[0xA4];
    unsigned char mode;
    char pad12E[0x76];
    actionReactionTarget targets[16];
} actionReactionState;
typedef struct {
    char pad0[20];
    unsigned int effect1, effect2;
    char pad1C[24];
} actionReactionAction;
typedef struct {
    char pad0[10];
    unsigned char flag;
} actionReactionMotion;
int func_800DC48C(int, int);
int func_800DC484(int, int);
void func_800DC210(actionReactionState*, int);
void func_800DC19C(actionReactionState*);
void func_800DC784(actionReactionState*, int);
void func_800DD000(actionReactionState* state, actionStatApplication* app)
{
    int own, source, action, i, bad;
    actionReactionState* other;
    actionStatDelta* entry;
    actionReactionAction* info;
    if (!app || app->first.skip) {
        return;
    }
    own = state->id;
    if (!own) {
        return;
    }
    info = (void*)&vs_main_actions[app->action];
    bad = 0;
    if (((info->effect1 >> 7) & 63) == 3 || ((info->effect2 >> 7) & 63) == 3) {
        bad = 1;
    }
    if (bad) {
        return;
    }
    source = app->first.actor;
    action = app->action;
    other = (void*)D_800F5878[source];
    for (i = 0; i < app->count; i++) {
        entry = &app->entries[i];
        if (entry->skip || entry->actor != own || source == own) {
            continue;
        }
        if (state->mode == 1) {
            state->mode = 2;
        }
        if (func_800DC48C(action, state->id)) {
            if (source == 0 && state->flag13 == 0 && state->flag27) {
                func_800DC210(state, 0);
            } else if ((other->targets[0].b.flags >> 6) == 3) {
                func_800DC19C(state);
            }
        }
        state->targets[source].p.timer = 28;
        if (func_800DC484(action, state->id)) {
            if (D_800F5920 && source == 0 && (entry->modes & 3) != 2 && entry->hp > 0) {
                ((actionReactionMotion*)D_800F5920)->flag = 0;
            }
            if (source == 0 && state->flag27) {
                func_800DC19C(state);
            }
            if (state->flag30 && (state->flag20 == 0 || source == 0)) {
                func_800DC784(state, source);
            } else if (state->targets[source].p.classification != 3) {
                if (other->targets[own].p.counter) {
                    other->targets[own].p.counter = 0;
                    other->targets[own].p.classification = other->targets[own].p.previous;
                } else {
                    state->targets[source].p.counter = 127;
                    state->targets[source].p.previous =
                        state->targets[source].p.classification;
                    if (state->flag20) {
                        func_800DC784(state, source);
                    }
                }
            }
        }
    }
}

void func_800DD344(actionReactionState* state)
{
    actionScoreActor* actor;
    actionScoreActor* candidate;
    actionScoreActor* ally;
    actionReactionState* other;
    actionReactionState* firstOther;
    actionReactionState* allyState;
    int id, classification;
    unsigned int otherClass;
    if (state->flag13) {
        for (actor = (void*)vs_battle_actors[0]; actor; actor = actor->next) {
            id = actor->id;
            firstOther = (void*)D_800F5878[id];
            if (id == state->id || id == 0 || firstOther->flag2C == 3) {
                classification = 2;
            } else if (!firstOther->flag13) {
                if ((firstOther->targets[0].b.flags >> 6) == 3) {
                    classification = 3;
                    state->targets[id].p.counter = 0;
                } else {
                    classification = 1;
                }
            } else {
                classification = 1;
            }
            state->targets[id].p.classification = classification;
        }
    } else if (state->flag21) {
        for (actor = (void*)vs_battle_actors[0]; actor; actor = actor->next) {
            otherClass = state->targets[actor->id].b.flags >> 6;
            other = (void*)D_800F5878[actor->id];
            if (otherClass == 2 && (other->targets[state->id].b.flags >> 6) == 2) {
                for (candidate = (void*)vs_battle_actors[0]; candidate;
                    candidate = candidate->next) {
                    id = candidate->id;
                    if (state->targets[id].p.classification == 1
                        && (state->targets[id].raw & 1)
                        && (other->targets[id].b.flags >> 6) == 3) {
                        for (ally = (void*)vs_battle_actors[0]; ally; ally = ally->next) {
                            allyState = (void*)D_800F5878[ally->id];
                            if ((state->targets[ally->id].b.flags >> 6) == 2
                                && (allyState->targets[state->id].b.flags >> 6) == 2
                                && (allyState->targets[id].p.classification == 2
                                    || (allyState->targets[id].p.counter
                                        && allyState->targets[id].p.previous == 2))) {
                                break;
                            }
                        }
                        if (!ally) {
                            func_800DC784(state, id);
                        }
                    }
                }
            }
        }
    }
}

typedef struct {
    u_int unk0_0 : 2;
    u_int flag2 : 1;
    u_int mode : 2;
    u_int flag5 : 1;
    u_int usable : 1;
    u_int enabled : 1;
    u_int range : 16;
    u_int unk0_24 : 8;
    u_int value;
} actionSlotConfig;

typedef struct {
    u_int flag0 : 1;
    u_int flag1 : 1;
    u_int flag2 : 1;
    u_int flag3 : 1;
    u_int unk4 : 28;
} actionChoiceFlags;

typedef struct {
    int unk0;
    u_int category : 3;
    u_int slot : 2;
    u_int action : 8;
    u_int unk4_13 : 19;
    u_int score;
    u_int unkC_0 : 19;
    u_int targetWeight : 8;
    u_int unkC_27 : 5;
    actionChoiceFlags flags;
} actionChoice;

typedef struct {
    char unk0[0x1B];
    u_char dead;
    char unk1C[0x40];
    vs_battle_actor2* stats;
    char unk60[0x22];
    short heading;
    char unk84[0xBC];
    actionChoice choice;
    char unk154[0xDC];
    actionSlotConfig configs[6][4];
} actionChoiceState;

/* Local view of the vs_main_actions flag word at 0xC */
typedef struct {
    char unk0[0xC];
    u_int unkC_0 : 23;
    u_int flag23 : 1;
    u_int unkC_24 : 4;
    u_int flag28 : 1;
    u_int flag29 : 1;
    u_int unkC_30 : 2;
    char unk10[0x24];
} actionChoiceInfo;

void func_800DD604(actionChoiceState* state)
{
    vs_battle_actor2* stats;
    actionChoice* choice;
    actionSlotConfig* config;
    u_int best;
    int row;
    int col;
    int action;
    actionChoiceFlags flags;

    best = 0;
    choice = &state->choice;
    stats = state->stats;
    for (row = 0; row < 6; ++row) {
        for (col = 0; col < 4; ++col) {
            config = &state->configs[row][col];
            action = (u_short)stats->armor[row][col].id;
            if (func_800E4DF8((actionCandidateState*)state, row, col) && config->usable
                && best < config->value) {
                best = config->value;
                choice->score = best;
                choice->slot = col;
                choice->category = row;
                choice->action = action;
                choice->flags.flag1 = 0;
                flags = choice->flags;
                flags.flag2 = ((actionChoiceInfo*)vs_main_actions)[action].flag28;
                choice->targetWeight = 128;
                flags.flag0 = 0;
                flags.flag3 = 0;
                choice->flags = flags;
            }
        }
    }
    if (best == 0) {
        choice->action = 0;
    }
}

typedef struct {
    char pad0[0x4C];
    short x, y, z;
} nearestWaypointState;
typedef struct {
    unsigned char x, y, z, flags;
} nearestWaypointDestination;
extern unsigned short* D_800F58C8;
static inline unsigned int nearestWaypointValue(unsigned short* row, int index)
{
    unsigned short* p = row;
    p += index;
    return *p;
}
static inline unsigned short* nearestWaypointAddress(unsigned short* row, int index)
{
    row += index;
    return row;
}
void func_800DD7CC(nearestWaypointState* state, nearestWaypointDestination* destination)
{
    int x;
    int z;
    int savedMap;
    int dx;
    int dz;
    int index;
    unsigned short entry;
    unsigned int packed;
    unsigned int distance;
    unsigned int closest;

    closest = -1U;
    {
        int* scratch = (int*)0x1F8003BC;
        index = 0;
        savedMap = *scratch;
    }
    *(int*)0x1F8003BC = (int)D_800F58D0;
    do {
        entry = *nearestWaypointAddress(D_800F58C8, index);
        packed = entry & 0xFFFF;
        if ((packed >> 0xF) != 0) {
            x = ((entry & 0x1F) << 7) + 0x40;
            z = ((packed * 4) & 0xF80) + 0x40;
            dx = state->x - x;
            dz = state->z - z;
            distance = func_800E4660(dx, state->y - func_800E42D4(x, z), dz);
            if (distance < closest) {
                destination->x =
                    (signed char)(nearestWaypointValue(D_800F58C8, index) & 0x1F);
                closest = distance;
                destination->z =
                    (signed char)(((unsigned short)nearestWaypointValue(D_800F58C8, index)
                                      >> 5)
                                  & 0x1F);
            }
        }
        index += 1;
    } while (index < 8);
    *(int*)0x1F8003BC = savedMap;
}

extern u_char (*D_800F5904)[256];
void func_800E4288(void*, int);
void func_800DC2E0(actionCandidateEntry*, actionCandidateEntry*);
void func_800DC344(actionChoiceState*, actionCandidateEntry*);
void func_800DC4F0(actionCandidateEntry*, actionChoiceInfo*);

static inline vs_battle_uiEquipment_limb* actorLimb(vs_battle_actor2* stats, int limb)
{
    return ((vs_battle_actor2*)(limb * sizeof(vs_battle_uiEquipment_limb) + (int)stats))
        ->limbs;
}

void func_800DD918(actionChoiceState* state, int threshold)
{
    actionCandidateEntry* list = (actionCandidateEntry*)0x1F80030C;
    actionCandidateEntry* candidate;
    int pass;
    int row;
    int col;
    int action;
    int limb;
    int part;
    int last;
    int flag;
    u_int id;
    actionSlotConfig* config;
    actionChoiceInfo* info;
    vs_battle_actor* actor;
    actionChoiceState* target;

    func_800E4288(list, sizeof(actionCandidateEntry));
    list[0].distanceSquared = 256;
    list[0].threshold = threshold;
    func_800DCC94((actionScoreState*)state, list, 0, NULL);
    func_800DC2E0(&list[1], list);
    list[1].threshold = threshold;
    candidate = &list[1];

    for (row = 0; row < 6; ++row) {
        for (col = 0; col < 4; ++col) {
            action = (u_short)state->stats->armor[row][col].id;
            config = &state->configs[row][col];
            info = &((actionChoiceInfo*)vs_main_actions)[action];
            if (action == 0 || !config->enabled) {
                continue;
            }
            list[1].column = col;
            list[1].row = row;
            list[1].action = action;
            flag = info->flag29;
            list[1].flag1 = info->flag23 | flag;
            list[1].flag2 = info->flag28;
            list[1].flag3 = config->flag2;
            list[1].range = config->range;
            list[1].distanceSquared = config->value;

            for (actor = vs_battle_actors[0]; actor != NULL; actor = actor->next) {
                id = actor->id;
                if (((actionChoiceState*)D_800F5878[id])->dead) {
                    continue;
                }
                list[1].targetId = id;
                list[1].flag4 = func_800DC484(action, id);
                list[1].flag5 = func_800DC48C(action, id);
                list[1].low = config->flag5 && list[1].flag4;
                if (!func_800E4CF4((actionCandidateState*)state, candidate, id)
                    || D_800F5904[id][action]) {
                    continue;
                }

                switch ((int)config->mode) {
                case 1:
                    func_800DCC94((actionScoreState*)state, candidate, 1,
                        (actionScoreMetadata*)info);
                    func_800DC4F0(candidate, info);
                    if (list[1].score > list[0].score) {
                        func_800DC344(state, candidate);
                    }
                    break;

                case 2:
                    last = -1;
                    func_800DC2E0(&list[2], list);
                    func_800DC2E0(&list[3], list);
                    for (limb = 0; limb < 6; ++limb) {
                        if (actorLimb(actor->unk3C, limb)->maxHp != 0) {
                            last = limb;
                            list[1].part = last;
                            func_800DCC94((actionScoreState*)state, candidate, 2,
                                (actionScoreMetadata*)info);
                            {
                                int chance = list[1].weight;
                                if ((rand() & 127) < chance
                                    && list[1].score > list[2].score) {
                                    func_800DC2E0(&list[2], candidate);
                                }
                            }
                            if (list[1].score > list[3].score) {
                                func_800DC2E0(&list[3], &list[1]);
                            }
                        }
                    }
                    part = rand();
                    part = (part & 3) + ((part >> 2) & 1) + ((part >> 3) & 1);
                    if (actorLimb(actor->unk3C, part)->maxHp == 0 && last >= 0) {
                        part = last;
                    }
                    if (part >= 0) {
                        list[1].part = part;
                        func_800DC4F0(&list[1], info);
                    }
                    if (list[2].score > list[0].score) {
                        func_800DC344(state, &list[2]);
                    } else if (list[0].score < list[3].score) {
                        func_800DC344(state, &list[3]);
                    }
                    break;

                case 3:
                    target = (actionChoiceState*)D_800F5878[actor->id];
                    func_800DC2E0(&list[2], list);
                    func_800DC2E0(&list[3], list);
                    list[1].heading = 0;
                    for (pass = 0; pass < 1; ++pass) {
                        list[1].heading = ABS(target->heading);
                        func_800DCC94((actionScoreState*)state, candidate, 3,
                            (actionScoreMetadata*)info);
                        {
                            int chance = list[1].weight;
                            if ((rand() & 127) < chance
                                && list[1].score > list[2].score) {
                                func_800DC2E0(&list[2], candidate);
                            }
                        }
                        if (list[1].score > list[3].score) {
                            func_800DC2E0(&list[3], &list[1]);
                        }
                    }
                    func_800DC4F0(&list[1], info);
                    if (list[2].score > list[0].score) {
                        func_800DC344(state, &list[2]);
                    } else if (list[0].score < list[3].score) {
                        func_800DC344(state, &list[3]);
                    }
                    break;
                }
            }
        }
    }
}

typedef struct {
    int mask;
    u_short unk4;
    u_short interval;
    int unk8;
    int unkC;
} statusEffectTick;
typedef struct {
    statusEffectTick entries[1];
} statusEffectTable;

extern u_int D_80069BBC[];
void func_800E4F14(void*);

void func_800DE030(int elapsed)
{
    vs_battle_actor* actor;
    vs_battle_actor2* stats;
    void* state;
    int statuses;
    int ticks;
    int i;
    int limb;
    int duration;
    int scale;
    int amount;
    int row;
    int column;
    vs_battle_uiEquipment_limb* limbs;

    ticks = (elapsed >> 5) + (elapsed >> 9);
    D_800F58BC->unk18 += elapsed;

    for (actor = vs_battle_actors[0]; actor != NULL; actor = actor->next) {
        stats = actor->unk3C;
        statuses = stats->statuses;

        if (D_800F58BC->unk18 > 2880) {
            for (limb = 0; limb < 6; ++limb) {
                limbs = &stats->limbs[limb];
                limbs->hp += 2;
                if (limbs->hp > limbs->maxHp) {
                    limbs->hp = limbs->maxHp;
                }
            }
        }

        if (stats->limbs[stats->unk34].hp >= 2 || stats->limbs[stats->unk35].hp >= 2) {
            statuses &= ~0x10;
        }

        amount = elapsed / 240;
        if (amount > 0) {
            stats->currentHP += amount - 1;
        }
        if (stats->currentHP > stats->maxHP) {
            stats->currentHP = stats->maxHP;
        }

        amount = elapsed / 180;
        if (amount > 0) {
            stats->currentMP += amount - 1;
        }
        if (stats->currentMP > stats->maxMP) {
            stats->currentMP = stats->maxMP;
        }

        if (statuses & 0x4000) {
            scale = stats->maxHP * 5;
            stats->currentHP -= (ticks
                                    / (*(statusEffectTable*)vs_main_statusEffectParams)
                                        .entries[14]
                                        .interval)
                              * scale / 100;
            if (stats->currentHP < 0) {
                stats->currentHP = 0;
            }
        }

        if (statuses & 0x20000) {
            scale = stats->maxHP * 5;
            stats->currentHP += (ticks
                                    / (*(statusEffectTable*)vs_main_statusEffectParams)
                                        .entries[17]
                                        .interval)
                              * scale / 100;
            if (stats->currentHP < 0) {
                stats->currentHP = 0;
            }
        }

        for (i = 0; i < 5; ++i) {
            if (statuses & D_80069BBC[i]) {
                duration = stats->statusTimers[i];
                duration = (duration << 5) - (duration << 1);
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

#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) < (b) ? (b) : (a))

typedef struct {
    char unk0[0x26];
    u_char allowFallback;
    char unk27[0x2D];
    vs_battle_actor* actor;
    char unk58[4];
    vs_battle_actor2* stats;
    char unk60[0x28];
    u_char id;
    char unk89[0xA5];
    u_char mode;
    char unk12F[0x10];
    u_char minDelay;
    char unk140[0x1B0];
    actionCandidateEntry candidates[16];
    actionCandidateEntry* entries[16];
    int count;
} actionPlanState;

extern int D_800F58F0;
extern int D_800F58F4;
extern vs_battle_actor2* D_800F58E8;
extern actionCandidateEntry (*D_800F58EC)[16];
extern actionCandidateEntry* D_800F58F8;
void func_800DC3E8(vs_battle_actor2* src, vs_battle_actor2* dst);
void func_800DC3CC(actionPlanState*);
void func_800DC574(actionPlanState*, int);

static inline int snapshotActorStats(void)
{
    vs_battle_actor* actor;

    D_800F58E8 = vs_main_allocHeapR(sizeof(vs_battle_actor2) * 16);
    if (D_800F58E8 == NULL) {
        return 0;
    }
    for (actor = vs_battle_actors[0]; actor != NULL; actor = actor->next) {
        func_800DC3E8(actor->unk3C, &D_800F58E8[actor->id]);
    }
    return 1;
}

static inline void restoreActorStats(void)
{
    vs_battle_actor* actor;

    for (actor = vs_battle_actors[0]; actor != NULL; actor = actor->next) {
        func_800DC3E8(&D_800F58E8[actor->id], actor->unk3C);
    }
    vs_main_freeHeapR(D_800F58E8);
}

void func_800DE3E4(actionPlanState* state)
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
    int index;
    int minDelay;
    vs_battle_actor* actor;
    vs_battle_actor2* stats = state->stats;
    int remaining;
    actionCandidateEntry* entry;
    actionCandidateEntry* rejected;
    actionCandidateEntry* fallback;
    vs_battle_actor* self;

    D_800F58F0 = 0;
    D_800F58F4 = 0;

    for (row = 0; row < 6; ++row) {
        for (column = 0; column < 4; ++column) {
            for (actor = vs_battle_actors[0]; actor != NULL; actor = actor->next) {
                D_800F5904[actor->id][(u_short)stats->armor[row][column].id] = 0;
            }
        }
    }

    state->count = 0;
    if (state->id == 0) {
        return;
    }

    if (snapshotActorStats()) {
        minDelay = MAX(state->minDelay, (u_short)(state->stats->unk954 / 35));
        D_800F58BC->unk18 = 0;

        for (pass = 0; pass < 3; ++pass) {
            delay = MAX(delays[pass], minDelay);
            func_800DE030(delay);
            func_800DD918((actionChoiceState*)state, (short)delay);
            func_800DC3CC(state);

            if (pass == 1) {
                remaining = 16 - selected[0] - quotas[2];
                if (remaining < 0) {
                    remaining = 0;
                }
                selected[1] = remaining;
                selected[pass] = MIN(selected[1], state->count);
            } else {
                selected[pass] = MIN(state->count, quotas[pass]);
            }

            for (i = 0; i < selected[pass]; ++i) {
                func_800DC2E0(&D_800F58EC[pass][i], state->entries[i]);
            }
            for (i = selected[pass]; i < state->count; ++i) {
                rejected = state->entries[i];
                D_800F5904[rejected->targetId][rejected->action] = 0;
            }
            state->count = 0;
        }

        for (pass = 0; pass < 3; ++pass) {
            for (j = 0; j < selected[pass]; ++j) {
                index = state->count;
                entry = &state->candidates[index];
                func_800DC2E0(entry, &D_800F58EC[pass][j]);
                state->entries[index] = entry;
                state->count = index + 1;
                if (index + 1 >= 16) {
                    goto restore;
                }
            }
        }

        if (state->count == 0 && state->allowFallback) {
            for (i = 0; i < D_800F58F0; ++i) {
                fallback = &state->candidates[i];
                func_800DC2E0(fallback, &D_800F58F8[i]);
                fallback->weight = 128;
                state->entries[i] = fallback;
            }
            state->count = D_800F58F0;
            func_800DC3CC(state);
        }
    restore:
        restoreActorStats();
        D_800F58BC->unk18 = 0;
    } else {
        func_800DD918((actionChoiceState*)state, 0);
        func_800DC3CC(state);
    }

    if (state->count >= 2) {
        for (pass = 0; pass < 3; ++pass) {
            if (selected[pass] != 0) {
                func_800DC574(state, selected[pass]);
                break;
            }
        }
    }

    for (i = 0; i < state->count; ++i) {
        if (i > 0
            && (int)state->entries[i]->threshold - (int)state->entries[0]->threshold
                   < 80) {
            state->entries[i]->threshold = state->entries[0]->threshold + 80;
        }
        state->entries[i]->threshold += rand() & 7;
    }

    func_800D85D8((actionCandidateState*)state);
    if (state->count == 0) {
        state->mode = 7;
    } else {
        func_800D9DD8((actionCandidateState*)state);
    }

    if (D_800F5920 != NULL) {
        self = state->actor;
        if (vs_battle_getStateFlag(0xA6) == 4 && self->unk9 == 24 && self->unkC == 4) {
            vs_battle_setStateFlag(0xA6, 5);
        }
        if (D_800F5920->unk16 && (u_int)(self->subType - 172) < 2) {
            D_800F5920->unk17 = state->count;
            state->count = 0;
        }
    }
}

#undef MIN
#undef MAX

void func_800DEB10(func_800DEEA4_t* arg0)
{
    int i;
    int j;
    func_800DEEA4_t2* entry;
    func_800DEB10_t2* temp_t1;

    if (arg0 == NULL) {
        return;
    }

    if (arg0->unk44 != 0) {
        return;
    }

    entry = D_800F5878[arg0->unk4];
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

        if ((arg0->unk0 == temp_a2->unk4_5) && (temp_t1->unkC == temp_a2->unk4_0)
            && (temp_t1->unkE == temp_a2->unk4_3)) {
            entry->unkFB = temp_a2->unkC_0;
            for (j = 0; j < arg0->unk4A; ++j) {
                func_800DEB10_t* elem = &arg0->unk4C[j];

                if (elem->unk40 == 0) {
                    D_800F45E0_t* actor = D_800F45E0[elem->unk0];

                    if ((actor == NULL) || ((0x14 >> actor->unk6C[8].actorId) & 1)) {
                        func_800E4CE8(entry);
                        return;
                    }
                }
            }
        }
    }

    func_800E4C8C(entry);
}

typedef struct actorEvaluationStats {
    char pad0[24];
    short hp;
    char pad1A[23];
    unsigned char f31;
    char pad32[1];
    unsigned char f33;
} actorEvaluationStats;
typedef struct actorEvaluationActor {
    struct actorEvaluationActor* next;
    int id;
    unsigned char flags;
    char pad9[51];
    actorEvaluationStats* stats;
} actorEvaluationActor;
typedef struct actorEvaluationState {
    char pad0[19];
    unsigned char f13;
    char pad14[7];
    unsigned char dead;
    char pad1C[108];
    unsigned char id;
    char pad89[17];
    unsigned short timer;
    char pad9C[75];
    unsigned char fE7;
    unsigned char fE8;
    char padE9[177];
    unsigned char f19A;
} actorEvaluationState;
typedef struct actorEvaluationContext {
    char pad0[4];
    unsigned char id;
    char pad5[63];
    int f44;
} actorEvaluationContext;
extern u_char (*D_800F5904)[256];
void func_800E685C(int, int, int);
void func_800D821C(actorEvaluationState*);
int func_800DEC88(void* arg0)
{
    actorEvaluationContext* context = arg0;
    actorEvaluationActor* actor;
    actorEvaluationState* state;
    D_800F58BC->unk18 = 0;
    D_800F5900 = vs_main_allocHeapR(0x1ECC);
    D_800F58EC = (void*)((char*)D_800F5900 + 0x9CC);
    D_800F5904 = (void*)((char*)D_800F5900 + 0xD8C);
    D_800F58F8 = (void*)((char*)D_800F5900 + 0x1D8C);
    if (D_800F5900) {
        func_800DEB10((void*)context);
        for (actor = (actorEvaluationActor*)vs_battle_actors[0]; actor;
            actor = actor->next) {
            state = (actorEvaluationState*)D_800F5878[actor->id];
            state->fE8 = 0;
            state->fE7 = 0;
            state->f19A = 0;
            func_800E685C(state->id, actor->stats->f31, actor->stats->f33);
            func_800DD604((actionChoiceState*)state);
            if (context && !context->f44 && context->id == state->id) {
                state->timer = 0;
            }
        }
        func_800DC810((void*)context);
        for (actor = (actorEvaluationActor*)vs_battle_actors[0]; actor;
            actor = actor->next) {
            ((actorEvaluationState*)D_800F5878[actor->id])->dead = actor->stats->hp == 0;
        }
        for (actor = (actorEvaluationActor*)vs_battle_actors[0]; actor;
            actor = actor->next) {
            state = (actorEvaluationState*)D_800F5878[actor->id];
            func_800DE3E4((actionPlanState*)state);
            if (state->f13) {
                if (actor->flags & 32) {
                    func_800D821C(state);
                } else {
                    func_800D820C(state->id, 128);
                }
            }
        }
        D_800F58BC->unk18 = 0;
        if (D_800F5900) {
            vs_main_freeHeapR(D_800F5900);
        }
    }
    return 0;
}

void func_800DEEA4(func_800DEEA4_t* arg0)
{
    if (arg0 != NULL) {
        if (arg0->unk44 == 0) {
            func_800DEEA4_t2* entry = D_800F5878[arg0->unk4];

            if (entry != NULL) {
                entry->unk9A = 0;
            }
        }

        func_800DC810(arg0);
    }
}
