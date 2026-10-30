#include "common.h"
#include "6E644.h"
#include "6E644Shared.h"
#include "146C.h"
#include "38C1C.h"
#include "src/SLUS_010.40/32154.h"
#include <abs.h>

#define MAX(a, b) ((a) < (b) ? (b) : (a))

typedef struct {
    int unk0;
    u_short unk4;
} func_800E5A74_t;

typedef struct {
    u_int unk0_0 : 2;
    u_int unk0_2 : 2;
    u_int unk0_4 : 3;
    u_int unk0_7 : 1;
    u_int unk0_8 : 2;
    u_int unk0_10 : 2;
    u_int unk0_12 : 1;
    u_int unk0_13 : 1;
    u_int unk0_14 : 1;
    u_int unk0_15 : 1;
    u_int unk0_16 : 2;
    u_int unk0_18 : 3;
    u_int unk0_21 : 2;
    u_int unk0_23 : 1;
    u_int unk0_24 : 1;
    u_int unk0_25 : 1;
    u_int unk0_26 : 1;
    u_int unk0_27 : 1;
    u_int unk0_28 : 2;
    u_int unk0_30 : 2;
} func_800E5A9C_t;

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

void func_800E5EC0(int, int, int);
void func_800E6828(func_800E78F4_t*);
void func_800E72D0(void);
void func_800E7370(func_800E78F4_t*);
void func_800E7660(func_800E78F4_t*);

extern D_800F16EC_t D_800F16EC[8];
extern int (*D_800F1790[])(func_800E78F4_t*);
extern u_short D_800F17B8[][2];
extern u_short D_800F17C8[][2];
extern u_char D_800F17D8[];
extern u_short (*D_800F58B8)[32];
extern int D_800F58C0;
extern int D_800F590C;

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

int func_800E5600(func_800E78F4_t* arg0, int actionId, u_int arg2)
{
    vs_action_t* action = &vs_main_actions[actionId];
    int r = 0;
    int v;

    if (action->flagsE.unk13 << 0x1D) {
        r = action->aoe_8 << 5;
    } else if (action->flagsE.unk7 << 0x17) {
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

void func_800E5710(func_800E78F4_t* arg0)
{
    int row;
    int column;

    if (!arg0->unk88) {
        arg0->unk17 = 1;
        return;
    }

    for (row = 0; row < 6; ++row) {
        for (column = 0; column < 4; ++column) {
            int id = arg0->unk5C->armor[row][column].id;
            vs_action_t* action = &vs_main_actions[id];
            func_800DD604_t* entry = &arg0->unk230[row][column];
            int mask = 1 << action->unk2_4;

            entry->unk4 = func_800E5698((func_800E5698_t*)arg0, id);
            entry->unk0_8 = func_800E5600(arg0, id, vs_gte_rsqrt(entry->unk4));
            entry->unk0_5 = entry->unk4 > 0x51000 && !action->flagsE.unk13;

            if (mask & 0x4198) {
                entry->unk0_1 = 1;
            }

            if (mask & 0x154) {
                entry->unk0_2 = 1;
            }

            if (mask & 0xA) {
                entry->unk0_3 = 1;
            } else if (mask & 0x40A0) {
                entry->unk0_3 = 2;
            } else if (mask & 0x1954) {
                entry->unk0_3 = 3;
            }

            entry->unk0_6 = D_800F58BC->unkA && action->type != actionTypeSpell
                         && action->type != actionTypeBreakArt && (mask & 0x4000) != 0;

            if (action->type == actionTypeSpell && arg0->unk17 < action->cost) {
                arg0->unk17 = action->cost;
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

void func_800E5A9C(func_800E78F4_t* arg0, func_800E5A9C_t* arg1)
{
    static const u_char D_80069C08[] = { 9, 7, 0, 0 };
    vs_battle_actorView_t* actor = arg0->unk54;
    u_int range = D_80069C1C[arg1->unk0_18];
    u_int step;
    int mode;

    arg0->unkAC = range;

    if (range >= 1536 * 1536) {
        range = 1536 * 1536;
    }

    arg0->unkA4 = range;
    arg0->unk128 = D_800F17B8[arg1->unk0_16][0];
    arg0->unkA8 = rcos(arg0->unk128 / 2 * ONE / 360);
    arg0->unk25 = arg1->unk0_15;
    arg0->unk29 = arg1->unk0_14;
    arg0->unk24 = arg1->unk0_13;
    arg0->unk2D = 0;

    if (D_800F58C0) {
        int i;

        for (i = 0; i < 8; ++i) {
            if (D_800F58C8->unk0[i].active) {
                break;
            }
        }

        if (i != 8) {
            arg0->unk2D = arg1->unk0_12;
        }
    }

    arg0->unkB2 = arg1->unk0_10 + 1;
    arg0->unkB0 = D_800F17C8[arg1->unk0_8][0];
    step = arg0->unk94 > 128 ? 32 : 128;

    arg0->unkBA = step * D_800F17D8[arg1->unk0_2] / 16;
    arg0->unk23 = 1;
    arg0->unk21 = arg1->unk0_24;
    arg0->unk22 = arg1->unk0_23;
    arg0->unk2C = arg1->unk0_21;
    arg0->unk2F = arg1->unk0_28;
    arg0->unk31 = arg1->unk0_30;
    arg0->unk20 = arg1->unk0_26;
    arg0->unkD6 = D_80069C3C[arg1->unk0_4].unk0;
    arg0->unkD4 = D_80069C3C[arg1->unk0_4].unk2;
    arg0->unkD8 = D_80069C3C[arg1->unk0_4].unk4;
    arg0->unk27 = arg1->unk0_27;
    arg0->unk30 = arg1->unk0_25;

    if (!(arg0->unk15E & 0xC0)) {
        arg0->unk32 = D_80069C18[arg0->unk31];
    }

    arg0->unk33 = arg1->unk0_7;
    mode = actor->unk34_12;
    arg0->unk26 = mode >> 1;
    arg0->unk2B = mode & 1;
    arg0->unk102 = D_80069C08[actor->unk34_14];
    arg0->unk101 = actor->unk30_14;
    arg0->unkC8 = actor->unk30_16;
    arg0->unkCC = actor->unk30_22;
    arg0->unkCE = actor->unk30_27;

    if (actor->unk1A == 172 || actor->unk1A == 173) {
        arg0->unk68 = func_800E7F8C;
        arg0->unk19 = 1;
        func_800E7660(arg0);
    } else {
        arg0->unk68 = D_800F1790[actor->unk30_4];
    }

    arg0->unk16 = 16;
    func_800E5998();
    func_800E5710(arg0);
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

int func_800E6178(vs_battle_actor* actor, short arg1)
{
    func_800E78F4_t* state;
    D_800F4538_t* model;
    vs_battle_actor2* stats;
    int id = actor->id;
    int packed;
    u_int radius;
    SVECTOR result;

    if (actor->unk1C & 0x15) {
        D_800F590C |= 1 << id;
    }

    if (!actor->unk40) {

        if (actor->unk44->unk16C.actorId == 2 || actor->unk44->unk16C.actorId == 4) {
            int i;

            for (i = 0; i < 4; ++i) {
                if (D_800F58BC->unk28[i] == NULL) {
                    D_800F58BC->unk28[i] = actor;
                    break;
                }
            }
        }
    }

    if (!(actor->unk1C & 5)) {
        return 0;
    }

    state = vs_main_allocHeap(sizeof *state);
    D_800F5878[id] = state;
    func_800E4288(state, sizeof *state);
    state->unk88 = id;
    state->unk54 = (vs_battle_actorView_t*)actor;
    model = actor->unk44;
    state->unk58 = model;
    state->unk5C = actor->unk3C;
    func_800A190C(state->unk88, 250, &result, 0);
    state->unk82 = result.vy - model->unk0.position.vy;
    radius = model->unk63C;

    if (!id) {
        state->unk92 = 40;
    } else if (radius < 63) {
        state->unk92 = radius;
    } else {
        state->unk92 = 62;
    }

    if (radius > 128) {
        state->unk13C = 32;
        state->unk94 = radius;
    } else {
        radius = state->unk92;
        state->unk13C = 128;
        state->unk94 = radius;
    }

    state->unk60 = &model->unk0.position;
    state->unk64 = &model->unk0.currentTile;
    state->unk89 = 0;
    state->unk8A = 0;
    state->unk103 = 1;
    state->unk2A = func_800A152C(id, 2, 3) >= 0;
    stats = actor->unk3C;
    state->unk224 = stats->unk30;
    state->unk225 = stats->unk32;
    state->unk226 = stats->unk31;
    state->unk227 = stats->unk33;

    if (state->unk224 & 8) {
        state->unkB4 = state->unk226 * 128;
    } else if (state->unk225 & 8) {
        state->unkB4 = state->unk227 * 128;
    }

    func_800E6828(state);
    state->unkB3 = MAX(state->unk226, state->unk227);
    packed = actor->unk38;

    if (actor->unk34 & 1) {
        func_800E5A74(&packed, (void*)actor + 0x30);
    }

    func_800E5A9C(state, (func_800E5A9C_t*)&packed);
    func_800E7370(state);

    if (state->unkAC < (state->unkB4 - 64) * (state->unkB4 - 64)) {
        state->unkB4 = vs_gte_rsqrt(state->unkAC) - 64;
    }

    state->unkBC = -256;
    state->unkBE = -128;
    state->unkB8 = model->menuCameraHeightOffset;
    state->unk34 = *state->unk64;
    state->unk110 = *state->unk64;
    state->unk194 = -1;
    state->unk9C = -1;
    state->unk184 = state->unk60->vy * ONE;

    if (id) {
        if ((state->unk15E & 0x30) && (state->unk15E & 0xC6)
            && (D_800F58B8[model->unk0.currentTile.z][model->unk0.currentTile.x] & 0x10)
            && !(model->unk0.unkA_5 << 21)) {
            state->unk170 = model->unk0.currentTile;
            func_800DEEFC(state, 12);
        } else if ((arg1 < 0) || ((arg1 << 26) >= 0)) {
            if (actor->unk1F) {
                func_800DEEFC(state, 1);
                state->unk12D = 1;
            }
        }
    }

    actor->command.fields.unk9 = 0;
    actor->command.fields.unkB_2 = 0;
    actor->command.fields.unkB_0 = 0;
    state->unk124 = actor->command.fields.unk9;
    state->unk38 = -1;
    state->unk42 = arg1;
    func_800E72D0();

    if (state->unk88) {
        while (func_800DEC88(NULL)) { }
    }

    return (arg1 >= 0) && ((arg1 << 26) < 0);
}
