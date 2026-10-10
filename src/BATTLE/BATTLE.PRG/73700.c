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
void func_800E4C8C(func_800DEEA4_t2*);
extern D_800F58BC_t* D_800F58BC;
struct actorTimerState;
void func_800DBF00(func_800E78F4_t*);
void func_800DBFE4(struct actorTimerState*);

void func_800DBF00(func_800E78F4_t* arg0)
{
    func_800DEB10_t2* data = arg0->unk54;
    func_800E78F4_t* node;

    arg0->unk12F = 0;
    data->unkB_2 = 2;

    if (arg0 == D_800F58BC->unk20) {
        data->unkB_2 = 2;
        D_800F58BC->unk20 = D_800F58BC->unk20->unk1A0 != NULL ? D_800F58BC->unk20->unk1A0
                                                              : D_800F58BC->unk1C;
    }

    if (D_800F58BC->unk1C == arg0) {
        D_800F58BC->unk1C = arg0->unk1A0;
    } else {
        for (node = D_800F58BC->unk1C; node != NULL; node = node->unk1A0) {
            if (node->unk1A0 == arg0) {
                node->unk1A0 = arg0->unk1A0;
                return;
            }
        }
    }

    if (D_800F58BC->unk1C == NULL) {
        D_800F58BC->unk20 = NULL;
    }
}

typedef struct {
    char pad[8];
    unsigned int low : 26, mode : 2, high : 4;
} actorPhaseFlags;
typedef struct actorTimerState {
    char pad0[0x54];
    actorPhaseFlags* actor;
    char pad58[0x30];
    unsigned char id;
    char pad89[5];
    unsigned short timer8E;
    char pad90[8];
    unsigned short timer98, timer9A;
    char pad9C[0x93];
    signed char phase, direction;
    char pad131[0x6F];
    struct actorTimerState* next;
    unsigned char targetFlags;
} actorTimerState;
void func_800D820C(int, int);
void func_800DBFE4(actorTimerState* state)
{
    int value;
    if (state->timer8E && ++state->timer8E) {
        if (state->timer8E < 8) {
            value = 0;
        } else if (state->timer8E < 16) {
            value = 1;
        } else if (state->timer8E < 24) {
            value = 2;
        } else {
            value = 3;
        }
        if (state->timer8E <= 120) {
            func_800D820C(state->id, value + 1);
            return;
        }
        func_800E4C8C((void*)state);
        func_800D82CC((void*)state);
    }
    if (state->timer9A) {
        if (--state->timer9A) {
            func_800D820C(state->id, 4);
        } else {
            func_800D820C(state->id, 0);
        }
    }
    if (state->timer98) {
        state->timer98--;
    }
}
void func_800DC0D0(void)
{
    actorTimerState* head = (actorTimerState*)D_800F58BC->unk1C;
    actorTimerState* state;
    int changed = 0;
    actorPhaseFlags* actor;
    if (head) {
        state = head;
        do {
            actor = state->actor;
            if ((state->targetFlags >> 6) != 2) {
                if (state->phase == 0) {
                    state->direction = 1;
                    actor->mode = 1;
                    changed = 1;
                } else if (state->phase == 16) {
                    state->direction = -1;
                    actor->mode = 2;
                    changed = 1;
                }
                state->phase += state->direction;
                if (changed) {
                    break;
                }
            }
            state = state->next;
        } while (state);
    }
}
