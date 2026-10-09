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
short func_8008DC7C(int, int);
void func_800DEEFC(func_800E0850_t*, int);
void func_800E5EC0(int, int, int);
extern D_800F16EC_t D_800F16EC[8];
extern func_800DEEA4_t2* D_800F5878[];
extern u_short (*D_800F58B8)[32];
extern D_800F58BC_t* D_800F58BC;
extern u_short (*D_800F58D0)[32];
extern unsigned short* D_800F58C8;
void func_800E4288(void*, int);
int func_800DEC88(void* arg0);

int func_800E5568(func_800E5568_t* arg0)
{
    int (*fn)(int);
    int mask;
    int r;
    int v;

    mask = 1 << arg0->shape;
    if (mask & 0x16) {
        r = arg0->rangeZ;
        fn = rcos;
    } else if (mask & 0x8) {
        r = arg0->rangeY;
        fn = rcos;
    } else {
        r = arg0->rangeY;
        fn = rsin;
    }
    v = fn(arg0->angle << 7);
    return ((r << 5) * ABS(v)) >> 12;
}

int func_800E5600(int arg0, int actionId, u_int arg2)
{
    vs_action_t* action = &vs_main_actions[actionId];
    int r = 0;
    int v;

    if (action->flagsE_13 << 0x1D) {
        r = action->aoe_8 << 5;
    } else if (action->flagsE_3 << 0x17) {
        v = func_800E5568((func_800E5568_t*)&action->aoe_0);
        if (v < arg2) {
            r = v;
        }
    }
    return r;
}

int func_800E5698(func_800E5698_t* arg0, int actionId)
{
    vs_action_t* action = &vs_main_actions[actionId];
    func_800E5568_t* range;
    u_int v;

    if (action->rangeX == 0xFF) {
        range = &arg0->unk5C->unk38;
    } else {
        range = (func_800E5568_t*)&action->rangeX;
    }
    v = func_800E5568(range);
    if (v > 0x20) {
        v -= 0x20;
    }
    return v * v;
}

typedef union {
    unsigned int raw;
    unsigned char bytes[4];
} actionMetadataWord;
typedef struct {
    actionMetadataWord flags;
    char pad[8];
    unsigned int flagsC;
    char rest[36];
} actionMetadataAction;
typedef struct {
    unsigned short id, pad;
} actionMetadataSlot;
typedef struct {
    char pad[0x8C0];
    actionMetadataSlot slots[6][4];
} actionMetadataStats;
typedef struct {
    unsigned int f0 : 1, f1 : 1, f2 : 1, kind : 2, longRange : 1, special : 1, f7 : 1,
        radius : 16, high : 8;
    unsigned int rangeSquared;
} actionMetadataEntry;
typedef struct {
    char pad0[0x17];
    unsigned char maxActionCost;
    char pad18[0x44];
    actionMetadataStats* stats;
    char pad60[0x28];
    unsigned char id;
    char pad89[0x1A7];
    actionMetadataEntry entries[6][4];
} actionMetadataState;
void func_800E5710(actionMetadataState* state)
{
    int row, column, id, mask;
    actionMetadataAction* action;
    actionMetadataEntry* entry;
    if (!state->id) {
        state->maxActionCost = 1;
        return;
    }
    for (row = 0; row < 6; row++) {
        for (column = 0; column < 4; column++) {
            id = state->stats->slots[row][column].id;
            action = (void*)&vs_main_actions[id];
            entry = &state->entries[row][column];
            mask = 1 << ((action->flags.raw >> 20) & 15);
            entry->rangeSquared = func_800E5698((void*)state, id);
            entry->radius =
                func_800E5600((int)state, id, vs_gte_rsqrt(entry->rangeSquared));
            entry->longRange =
                entry->rangeSquared > 0x51000 && !(action->flagsC & 0x20000000);
            if (mask & 0x4198) {
                entry->f1 = 1;
            }
            if (mask & 0x154) {
                entry->f2 = 1;
            }
            if (mask & 0xA) {
                entry->kind = 1;
            } else if (mask & 0x40A0) {
                entry->kind = 2;
            } else if (mask & 0x1954) {
                entry->kind = 3;
            }
            entry->special = ((unsigned char*)D_800F58BC)[10]
                          && (action->flags.raw & 0xE0000) != 0x20000
                          && (action->flags.raw & 0xE0000) != 0x60000
                          && (mask & 0x4000) != 0;
            if ((action->flags.raw & 0xE0000) == 0x20000) {
                unsigned int value = action->flags.bytes[3];
                if (state->maxActionCost < value) {
                    state->maxActionCost = value;
                }
            }
        }
    }
}

void func_800E5998(void)
{
    vs_battle_actor* actor = vs_battle_actors[0]->next;

    while (actor != NULL) {
        if (D_800F5878[actor->id]->unk16 == 0x10) {
            vs_battle_actor* other = vs_battle_actors[0]->next;

            while (other != NULL) {
                if (other->unk30_0 == actor->unk30_9) {
                    break;
                }
                other = other->next;
            }
            if (other != NULL) {
                D_800F5878[actor->id]->unk16 = other->id;
            }
        }
        actor = actor->next;
    }
}

void func_800E5A74(int* arg0, func_800E5A74_t* arg1)
{
    *arg0 = ((arg1->unk4 & 0xFFE) << 20) | (*arg0 & 0x1FFFFF);
}

typedef union {
    unsigned int raw;
    unsigned short half[2];
    unsigned char byte[4];
} actorSettingsWord;
typedef struct actorSettingsActor {
    char pad0[26];
    unsigned short kind;
    char pad1C[20];
    actorSettingsWord flags;
    union {
        unsigned int raw;
        struct {
            unsigned int low : 12, mode : 2, high : 18;
        } bits;
    } flags34;
} actorSettingsActor;
typedef struct actorSettingsState {
    char pad0[22];
    unsigned char f16;
    char pad17[2];
    unsigned char f19;
    char pad1A[6];
    unsigned char f20;
    unsigned char f21;
    unsigned char f22;
    unsigned char f23;
    unsigned char f24;
    unsigned char f25;
    unsigned char f26;
    unsigned char f27;
    unsigned char f28;
    unsigned char f29;
    unsigned char f2A;
    unsigned char f2B;
    unsigned char f2C;
    unsigned char f2D;
    unsigned char f2E;
    unsigned char f2F;
    unsigned char f30;
    unsigned char f31;
    unsigned char f32;
    unsigned char f33;
    char pad34[32];
    actorSettingsActor* actor;
    char pad58[16];
    int (*callback)(func_800E78F4_t*);
    char pad6C[40];
    unsigned short collisionRadius;
    char pad96[14];
    unsigned int limit;
    int cosine;
    unsigned int rangeSquared;
    unsigned short fB0;
    unsigned char fB2;
    char padB3[7];
    unsigned short fBA;
    char padBC[12];
    unsigned int fC8;
    unsigned char fCC;
    char padCD[1];
    unsigned char fCE;
    char padCF[5];
    unsigned short fD4;
    unsigned short fD6;
    unsigned char fD8;
    char padD9[40];
    unsigned char f101;
    unsigned char f102;
    char pad103[37];
    unsigned short angle;
    char pad12A[52];
    unsigned short flags;
} actorSettingsState;
typedef struct {
    unsigned short first, second;
    unsigned char third, pad;
} actorSettingsEntry;
extern unsigned int D_80069C1C[];
extern unsigned short D_800F17B8[][2], D_800F17C8[][2];
extern unsigned char D_800F17D8[], D_80069C18[];
extern actorSettingsEntry D_80069C3C[];
extern int D_800F58C0;
extern unsigned short* D_800F58C8;
extern int (*D_800F1790[])(func_800E78F4_t*);
const unsigned char D_80069C08[4] = { 9, 7, 0, 0 };
int func_800E7F8C(func_800E78F4_t*);
void func_800E7660(actorSettingsState*);
void func_800E5998(void);

void func_800E5A9C(actorSettingsState* state, actorSettingsWord* settings)
{
    actorSettingsActor* actor = state->actor;
    unsigned int rangeSquared, step;
    int i, temp;
    rangeSquared = D_80069C1C[(settings->half[1] & 28) >> 2];
    state->rangeSquared = rangeSquared;
    if (rangeSquared > 0x23FFFF) {
        rangeSquared = 0x240000;
    }
    state->limit = rangeSquared;
    state->angle = D_800F17B8[settings->half[1] & 3][0];
    state->cosine = rcos((state->angle / 2) * 4096 / 360);
    state->f25 = (settings->raw >> 15) & 1;
    state->f29 = (settings->raw >> 14) & 1;
    state->f24 = (settings->raw >> 13) & 1;
    state->f2D = 0;
    if (D_800F58C0) {
        for (i = 0; i < 8; i++) {
            if (D_800F58C8[i] >> 15) {
                break;
            }
        }
        if (i != 8) {
            state->f2D = (settings->raw >> 12) & 1;
        }
    }
    state->fB2 = ((settings->raw >> 10) & 3) + 1;
    state->fB0 = D_800F17C8[(settings->raw >> 8) & 3][0];
    step = 128;
    if (state->collisionRadius > 128) {
        step = 32;
    }
    state->fBA = (step * D_800F17D8[(settings->raw >> 2) & 3]) >> 4;
    state->f23 = 1;
    state->f21 = settings->byte[3] & 1;
    state->f22 = (settings->raw >> 23) & 1;
    state->f2C = (settings->raw >> 21) & 3;
    state->f2F = (settings->raw >> 28) & 3;
    state->f31 = settings->raw >> 30;
    state->f20 = (settings->raw >> 26) & 1;
    state->fD6 = D_80069C3C[(settings->raw >> 4) & 7].first;
    state->fD4 = D_80069C3C[(settings->raw >> 4) & 7].second;
    state->fD8 = D_80069C3C[(settings->raw >> 4) & 7].third;
    state->f27 = (settings->raw >> 27) & 1;
    state->f30 = (settings->raw >> 25) & 1;
    if (!(state->flags & 0xC0)) {
        state->f32 = D_80069C18[state->f31];
    }
    state->f33 = settings->byte[0] >> 7;
    temp = actor->flags34.bits.mode;
    state->f26 = temp >> 1;
    temp &= 1;
    state->f2B = temp;
    state->f102 = D_80069C08[(actor->flags34.raw >> 14) & 1];
    state->f101 = (actor->flags.raw >> 14) & 3;
    state->fC8 = actor->flags.half[1] & 63;
    state->fCC = (actor->flags.raw >> 22) & 31;
    state->fCE = actor->flags.raw >> 27;
    if ((unsigned int)(actor->kind - 0xAC) < 2) {
        state->callback = func_800E7F8C;
        state->f19 = 1;
        func_800E7660(state);
    } else {
        state->callback = D_800F1790[(actor->flags.raw >> 4) & 31];
    }
    state->f16 = 16;
    func_800E5998();
    func_800E5710((void*)state);
}

void func_800E5EC0(int arg0, int arg1, int arg2)
{
    D_800F16EC_t* step;
    int i;
    int value = arg2 & 0x3FF;

    D_800F58D0[arg1][arg0] = (D_800F58D0[arg1][arg0] & 0xFC00) | value | 0x2000;

    for (i = 0, step = D_800F16EC; i < 4; ++i, step += 2) {
        u_int x = arg0 + step->dx;
        u_int z = arg1 + step->dz;

        if (x < 32 && z < 32 && (D_800F58B8[z][x] & 0x20)
            && !(D_800F58D0[z][x] & 0x2000)) {
            func_800E5EC0(x, z, arg2);
        }
    }
}

int func_800E5FDC(int arg0, int arg1)
{
    int i;
    u_int x;
    u_int z;

    for (i = 0; i < 4; i++) {
        x = arg0 + D_800F16EC[i * 2].dx;
        z = arg1 + D_800F16EC[i * 2].dz;
        if (x < 32 && z < 32 && !(D_800F58B8[z][x] & 0x70)) {
            return func_8008DC7C(x << 7 | 0x40, z << 7 | 0x40) >> 6;
        }
    }
    return -1;
}

void func_800E6098(void)
{
    int x;
    int z;

    for (z = 0; z < 32; ++z) {
        for (x = 0; x < 32; ++x) {
            if ((D_800F58B8[z][x] & 0x20) && !(D_800F58D0[z][x] & 0x2000)) {
                int r = func_800E5FDC(x, z);
                if (r >= 0) {
                    func_800E5EC0(x, z, r);
                }
            }
        }
    }
}

void func_800E6F9C(void);

void func_800E6158(void) { func_800E6F9C(); }

extern int D_800F590C;
void func_800A190C(unsigned char, int, void*, int);
int func_800A152C(int, int, int);
typedef union {
    unsigned int raw;
    struct {
        unsigned char b0, b1, b2, b3;
    } bytes;
    struct {
        unsigned int low : 24, f24 : 2, f26 : 2, high : 4;
    } bits;
} actorInitializationFlags;
typedef union {
    unsigned int raw;
    struct {
        unsigned char x, y, z, w;
    } p;
} actorInitializationPoint;
typedef struct actorInitializationStats {
    char pad0[48];
    unsigned char field30;
    unsigned char field31;
    unsigned char field32;
    unsigned char field33;
} actorInitializationStats;
typedef struct actorInitializationModel {
    char pad0[8];
    unsigned int flags;
    char padC[16];
    short position[3];
    char pad22[58];
    actorInitializationPoint tile;
    char pad60[268];
    unsigned int kind;
    char pad170[1228];
    unsigned short radius;
    unsigned short field63E;
} actorInitializationModel;
typedef struct actorInitializationActor {
    char pad0[4];
    int id;
    actorInitializationFlags flags;
    char padC[16];
    unsigned short attributes;
    char pad1E[1];
    unsigned char field1F;
    char pad20[16];
    int field30;
    unsigned int field34;
    int field38;
    actorInitializationStats* stats;
    int field40;
    actorInitializationModel* model;
} actorInitializationActor;
typedef struct actorInitializationState {
    char pad0[42];
    unsigned char field2A;
    char pad2B[9];
    int tile;
    int previous;
    char pad3C[6];
    short options;
    char pad44[16];
    actorInitializationActor* actor;
    actorInitializationModel* model;
    actorInitializationStats* stats;
    short* position;
    unsigned int* tilePointer;
    char pad68[26];
    unsigned short field82;
    char pad84[4];
    unsigned char id;
    unsigned char field89;
    unsigned char field8A;
    char pad8B[7];
    unsigned short radius;
    unsigned short collisionRadius;
    char pad96[6];
    int field9C;
    char padA0[12];
    unsigned int rangeSquared;
    char padB0[3];
    unsigned char maxRange;
    int distance;
    unsigned short fieldB8;
    char padBA[2];
    short fieldBC;
    short fieldBE;
    char padC0[67];
    unsigned char field103;
    char pad104[12];
    int field110;
    char pad114[16];
    unsigned char field124;
    char pad125[8];
    unsigned char field12D;
    char pad12E[14];
    unsigned short stepHeight;
    char pad13E[32];
    unsigned short flags;
    char pad160[16];
    int next;
    char pad174[16];
    int targetY;
    char pad188[12];
    int field194;
    char pad198[140];
    unsigned char field224;
    unsigned char field225;
    unsigned char field226;
    unsigned char field227;
} actorInitializationState;

void func_800E4288(void*, int);
void func_800E6828(actorInitializationState*);

void func_800E7370(actorInitializationState*);
void func_800E72D0(void);

int func_800E6178(actorInitializationActor* actor, int options)
{
    actorInitializationState* state;
    actorInitializationModel* model;
    actorInitializationStats* stats;
    int id = actor->id;
    int i, kind, temp, packed;
    unsigned int radius, range;
    unsigned short result[4];
    if (actor->attributes & 0x15) {
        D_800F590C |= 1 << id;
    }
    if (!actor->field40) {
        kind = actor->model->kind & 7;
        if (kind == 2 || kind == 4) {
            for (i = 0; i < 4; i++) {
                if (!((int*)D_800F58BC)[10 + i]) {
                    ((int*)D_800F58BC)[10 + i] = (int)actor;
                    break;
                }
            }
        }
    }
    if (!(actor->attributes & 5)) {
        return 0;
    }
    state = vs_main_allocHeap(0x484);
    D_800F5878[id] = (void*)state;
    func_800E4288(state, 0x484);
    state->id = id;
    state->actor = actor;
    model = actor->model;
    state->model = model;
    state->stats = actor->stats;
    func_800A190C(state->id, 250, result, 0);
    state->field82 = result[1] - model->position[1];
    radius = model->radius;
    if (!id) {
        state->radius = 40;
    } else if (radius < 63) {
        state->radius = radius;
    } else {
        state->radius = 62;
    }
    if (radius > 128) {
        state->stepHeight = 32;
        state->collisionRadius = radius;
    } else {
        radius = state->radius;
        state->stepHeight = 128;
        state->collisionRadius = radius;
    }
    state->position = model->position;
    state->tilePointer = &model->tile.raw;
    state->field89 = 0;
    state->field8A = 0;
    state->field103 = 1;
    state->field2A = func_800A152C(id, 2, 3) >= 0;
    stats = actor->stats;
    state->field224 = stats->field30;
    state->field225 = stats->field32;
    state->field226 = stats->field31;
    state->field227 = stats->field33;
    if (state->field224 & 8) {
        state->distance = state->field226 << 7;
    } else if (state->field225 & 8) {
        state->distance = state->field227 << 7;
    }
    func_800E6828(state);
    range = state->field226;
    if (range < state->field227) {
        range = state->field227;
    }
    state->maxRange = range;
    packed = actor->field38;
    if (actor->field34 & 1) {
        func_800E5A74(&packed, (void*)&actor->field30);
    }
    func_800E5A9C((void*)state, (void*)&packed);
    func_800E7370(state);
    temp = state->distance - 64;
    if (state->rangeSquared < (unsigned int)(temp * temp)) {
        state->distance = vs_gte_rsqrt(state->rangeSquared) - 64;
    }
    state->fieldBC = -256;
    state->fieldBE = -128;
    state->fieldB8 = model->field63E;
    state->tile = *state->tilePointer;
    state->field110 = *state->tilePointer;
    state->field194 = -1;
    state->field9C = -1;
    state->targetY = state->position[1] << 12;
    if (id) {
        if ((state->flags & 0x30) && (state->flags & 0xC6)
            && (D_800F58B8[model->tile.p.z][model->tile.p.x] & 0x10)
            && !(model->flags & 0x200000)) {
            state->next = model->tile.raw;
            func_800DEEFC((void*)state, 12);
        } else if ((short)options < 0 || !(((int)(short)options << 26) < 0)) {
            if (actor->field1F) {
                func_800DEEFC((void*)state, 1);
                state->field12D = 1;
            }
        }
    }
    actor->flags.bytes.b1 = 0;
    actor->flags.bits.f26 = 0;
    actor->flags.bits.f24 = 0;
    state->field124 = actor->flags.bytes.b1;
    state->previous = -1;
    state->options = (short)options;
    func_800E72D0();
    if (state->id) {
        while (func_800DEC88(0))
            ;
    }
    return (short)options >= 0 && (((int)(short)options << 26) < 0);
}
