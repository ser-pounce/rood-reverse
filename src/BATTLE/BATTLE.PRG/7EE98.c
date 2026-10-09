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
void func_800D82CC(func_800E78F4_t*);
void func_800D836C(func_800E78F4_t*);
int func_800DBCB4(func_800E78F4_t*, func_800E78F4_t2*);
void func_800DEEFC(func_800E0850_t*, int);
typedef struct movementRecoveryState movementRecoveryState;
void func_800E2CCC(movementRecoveryState*);
typedef struct radialMotionState radialMotionState;
int func_800E7698(radialMotionState*);
typedef struct trackingMotionState trackingMotionState;
void func_800E7960(trackingMotionState*);
extern D_800F58BC_t* D_800F58BC;
extern int D_800F5918;
extern int D_800F591C;
extern D_800F5920_t* D_800F5920;

typedef union {
    unsigned int raw;
    struct {
        unsigned int x : 8, y : 8, z : 8, status : 8;
    } p;
} vs_battle_movementPosition;
unsigned int func_800E4660(int, int, int);

typedef struct {
    char prefix[0x13];
    u_char kind;
    char gap[0x12B];
    u_char cooldown;
    char gap2[0xEC];
    func_800DCAA0_t* action;
} actionSetupContext;
int func_800D826C(actionSetupContext*);
unsigned int func_800E4660(int, int, int);

typedef struct {
    char pad0[8];
    unsigned int flags;
    char padC[8];
    short angle14;
    char pad16[0x10];
    short angle26;
} movementRecoveryContext;
struct movementRecoveryState {
    char pad0[9];
    unsigned char flag9;
    char padA[0x2A];
    vs_battle_movementPosition position;
    char pad38[0x14];
    short x;
    char pad4E[2];
    short z;
    char pad52[6];
    movementRecoveryContext* context;
    char pad5C[0xDE];
    unsigned short timer, duration;
    char pad13E[0x1A];
    short targetX, targetZ;
    unsigned char targetActor;
    char pad15D;
    unsigned short flags;
    char pad160[0x28];
    unsigned short facing188, facing18A;
    char pad18C[0x9C];
    int counter;
};
typedef struct {
    unsigned short first, second;
    unsigned char third, pad;
} actorSettingsEntry;
extern unsigned int D_80069C1C[];
extern unsigned char D_800F17D8[], D_80069C18[];
extern actorSettingsEntry D_80069C3C[];
int func_800E7F8C(func_800E78F4_t*);

typedef struct {
    char pad[0x5B0];
    unsigned int a : 4, active : 1, b : 27;
} radialMotionContext;
struct radialMotionState {
    char pad[0x4C];
    short x, y, z;
    char pad52[6];
    radialMotionContext* context;
    char pad5C[0x120];
    int targetX, targetZ, targetY;
    char pad188[0x2E8];
    int field470;
};
typedef struct {
    short facing;
    unsigned char state, flag3;
    char pad4[6];
    unsigned char flagA, frame;
    char padC[4];
    short angle;
    char pad12[6];
    short x, z;
} radialMotion;
typedef struct {
    char pad[8];
    unsigned int flags;
} radialMotionActor;
extern short D_800F17DC[][2];
unsigned int func_800E4660(int, int, int);
int func_800E7698(radialMotionState* state)
{
    radialMotionContext* context = state->context;
    radialMotion* motion = (radialMotion*)D_800F5920;
    int angle;
    state->field470 = 0;
    context->active = motion->frame < 14;
    func_800E4660(0x7C0 - state->x, 0, 0x7C0 - state->z);
    switch (motion->state) {
    case 0:
        motion->flagA = 1;
        angle = ratan2(state->x - 0x7C0, state->z - 0x7C0) & 0xFFF;
        angle = -angle;
        angle += 0xC00;
        motion->angle = angle & 0xFFF;
        motion->frame = 0;
        motion->state++;
        motion->x = state->x;
        motion->z = state->z;
        break;
    case 1:
        if (!D_800F17DC[motion->frame][0] && !D_800F17DC[motion->frame][1]) {
            if (((radialMotionActor*)D_800F4538[0])->flags & 0x70000) {
                func_800E2CCC((void*)state);
                return 0;
            }
            motion->state = 0;
            angle = ratan2(0x7C0 - state->x, 0x7C0 - state->z) & 0xFFF;
            angle = -angle;
            angle += 0xC00;
            motion->facing = angle & 0xFFF;
            context->active = 0;
            return 1;
        }
        break;
    }
    angle = rcos(motion->angle);
    state->targetX = (state->x << 12) + D_800F17DC[motion->frame][0] * angle;
    angle = rsin(motion->angle);
    state->targetZ = (state->z << 12) + D_800F17DC[motion->frame][0] * angle;
    state->targetY = (state->y + D_800F17DC[motion->frame][1]) << 12;
    func_800DEEFC((void*)state, 8);
    motion->flag3 = 0;
    motion->frame++;
    return 0;
}

int func_800E78F4(func_800E78F4_t* arg0)
{
    int r = 0;
    int a;
    int b;

    if (arg0->unk470 != 0 && func_800DBCB4(arg0, arg0->unk430)) {
        a = (u_short)(arg0->unk430->unk4 >> 13);
        b = D_800F58BC->unk18;
        r = a < b;
    }
    return r;
}

typedef struct {
    char pad[0x18];
    short current, maximum;
} trackingMotionStats;
struct trackingMotionState {
    char pad[0x4C];
    short x, y, z;
    char pad52[6];
    radialMotionContext* context;
    trackingMotionStats* stats;
    char pad60[0xFC];
    unsigned char targetActor;
    char pad15D[0x1F];
    int targetX, targetZ, targetY;
};
typedef struct {
    unsigned short facing;
    unsigned char state, flag3;
    int radiusSquared;
    char pad8[4];
    short stateC, stateE, angle, height;
    unsigned char phase;
    char pad15[7];
    unsigned char initialized;
} trackingMotion;
typedef struct {
    char pad[0x1C];
    short x, y, z;
} trackingMotionActor;
int rand(void);
int vs_gte_rsqrt(int);
unsigned int func_800E4660(int, int, int);
void func_800E7960(trackingMotionState* state)
{
    trackingMotion* motion = (trackingMotion*)D_800F5920;
    int center[3], playerAngle, currentAngle, tracking;
    int radius, heading, sign, cosCurrent, sinTarget, sinCurrent, cosTarget, aligned,
        delta, ratio, angle, adjust, denominator, scale, magnitude;
    int oppositeAngle;
    int initialAngle, currentHeading, targetHeading, facing, trig, correction, difference;
    if (!motion->initialized) {
        initialAngle = ratan2(0x7C0 - state->x, 0x7C0 - state->z) & 0xFFF;
        initialAngle = -initialAngle;
        initialAngle += 0xC00;
        motion->facing = initialAngle & 0xFFF;
        motion->height = state->y;
        motion->initialized = 1;
    }
    if (!motion->flag3) {
        motion->radiusSquared = func_800E4660(0x7C0 - state->x, 0, 0x7C0 - state->z);
        motion->flag3++;
    }
    state->context->active = 0;
    radius = vs_gte_rsqrt(motion->radiusSquared);
    if (radius < 1024) {
        radius += 32;
    }
    if (radius > 1024) {
        radius -= 32;
    }
    difference = radius - 1024;
    if (difference < 0) {
        difference = -difference;
    }
    if (difference < 32) {
        radius = 1024;
    }
    motion->radiusSquared = radius * radius;
    center[0] = 0x7C0000;
    difference = motion->height - 160;
    if (difference < 0) {
        difference = -difference;
    }
    if (difference < 16) {
        motion->height = 160;
    } else if (motion->height < 160) {
        motion->height += 12;
    } else {
        motion->height -= 12;
    }
    center[1] = motion->height << 12;
    center[2] = 0x7C0000;
    playerAngle = ratan2(0x7C0 - ((trackingMotionActor*)D_800F4538[0])->x,
        0x7C0 - ((trackingMotionActor*)D_800F4538[0])->z);
    currentAngle = ratan2(0x7C0 - state->x, 0x7C0 - state->z);
    if (func_800E78F4((void*)state) && func_800D826C((void*)state)) {
        heading = playerAngle;
        tracking = 1;
    } else {
        tracking = 0;
        heading = playerAngle + 0x800;
    }
    sign = -1;
    if (D_800F5918 >= 0) {
        sign = 1;
    }
    cosCurrent = rcos(-currentAngle + 0xC00);
    sinTarget = rsin(-heading + 0xC00);
    sinCurrent = rsin(-currentAngle + 0xC00);
    cosTarget = rcos(-heading + 0xC00);
    aligned = ((cosCurrent * sinTarget - sinCurrent * cosTarget) * sign) >= 0;
    if (aligned) {
        if (ABS(D_800F5918) > 0x280000) {
            delta = D_800F5918 / 8 + (sign << 16);
        } else {
            delta = sign << 16;
        }
    } else {
        delta = D_800F5918 / 4 + (sign << 16);
    }
    if (tracking || rcos(currentAngle - heading) < rcos(222)) {
        if (!aligned) {
            delta = -delta;
        }
    }
    D_800F5918 += delta;
    sign = -1;
    if (D_800F5918 >= 0) {
        sign = 1;
    }
    if (ABS(D_800F5918) > 0x820000) {
        D_800F5918 = sign * 0x820000;
    }
    ratio = (state->stats->current << 16) / state->stats->maximum;
    if (!motion->stateC) {
        if ((!motion->phase && ratio < 0xC000)
            || (motion->phase == 1 && ratio < 0x4000)) {
            motion->phase++;
            goto trigger;
        } else if (ABS(D_800F5918) < 0x40000 && tracking && D_800F591C < 30
                   && !(rand() & 511)) {
        trigger:
            motion->stateE = 1;
        }
    }
    motion->facing += D_800F5918 >> 16;
    facing = motion->facing;
    state->targetActor = 0;
    trig = rcos(facing);
    state->targetX = center[0] + radius * trig;
    trig = rsin(facing);
    state->targetZ = center[2] + radius * trig;
    if (tracking) {
        if (aligned) {
            denominator = currentAngle - playerAngle;
            scale = -80 - D_800F591C;
        } else {
            oppositeAngle = currentAngle - 0x800;
            denominator = playerAngle - oppositeAngle;
            scale = 300 - D_800F591C;
        }
    } else if (aligned) {
        oppositeAngle = currentAngle - 0x800;
        denominator = playerAngle - oppositeAngle;
        scale = 300 - D_800F591C;
    } else {
        denominator = ABS(D_800F5918) >> 16;
        scale = 10;
    }
    denominator &= 0xFFF;
    if (denominator > 0x800) {
        denominator = 0x1000 - denominator;
    }
    if (!denominator) {
        denominator = 1;
        scale = 0;
    }
    magnitude = ABS(D_800F5918);
    correction = magnitude * scale / denominator;
    if (ABS(correction) > magnitude * 4) {
        correction = (correction >> 31) * magnitude * 4;
    }
    D_800F591C += correction >> 16;
    if (D_800F591C < -100) {
        D_800F591C = -100;
    }
    if (D_800F591C > 500) {
        D_800F591C = 500;
    }
    state->targetY = center[1] - (D_800F591C << 12);
    if (state->targetY >= 0xFF000) {
        state->targetY = 0xFF000;
    }
    func_800DEEFC((void*)state, 8);
}

int func_800E7F8C(func_800E78F4_t* arg0)
{
    D_800F5920_t* temp_s0;
    char state;

    if (func_800E78F4(arg0) != 0) {
        func_800D836C(arg0);
    }

    state = vs_battle_getStateFlag(0xA6);
    temp_s0 = D_800F5920;

    if (temp_s0->unkC > 0) {
        --temp_s0->unkC;
    }

    switch (state) {
    case 0:
        if (temp_s0->unk16 != 0) {
            temp_s0->unk16 = 0;
            arg0->unk470 = temp_s0->unk17;
        }

        temp_s0->unkA = 0;
        func_800E7960((void*)arg0);

        if ((temp_s0->unkE != 0) && (temp_s0->unkC == 0)
            && (arg0->unk5C->limbs[4].hp >= 2)) {
            temp_s0->unkC = 900;
            temp_s0->unkE = 0;
            temp_s0->unk17 = arg0->unk470;
            state = 1;
            arg0->unk470 = 0;
            temp_s0->unk16 = 1;
        }
        break;

    case 4:
        temp_s0->unk1C = 0;
        func_800D82CC(arg0);

        if (func_800E7698((void*)arg0) != 0) {
            if (temp_s0->unkA != 0) {
                func_800DEB10_t2* temp_a1 = arg0->unk54;

                if (temp_a1->unk3C->limbs[4].hp >= 2) {
                    temp_a1->unkC = 4;
                    temp_a1->unkE = 0;
                    setVector(&temp_a1->unk10, D_800F4538[0]->unk0.position.vx,
                        D_800F4538[0]->unk0.position.vy
                            - (D_800F4538[0]->menuCameraHeightOffset >> 1),
                        D_800F4538[0]->unk0.position.vz);
                    temp_a1->unk9 = 24;
                    temp_a1->unk8 = 0x80;
                }

                temp_s0->unk12 = arg0->unk4E;
                arg0->unk470 = temp_s0->unk17;
                temp_s0->unk16 = 0;
            } else {
                state = 6;
            }

            D_800F591C = 0;
            temp_s0->unkE = 0;
            D_800F5918 = 0;
        }
        break;
    }

    vs_battle_setStateFlag(0xA6, state);
    return 1;
}

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/7EE98", D_80069C18);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/7EE98", D_80069C1C);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/7EE98", D_80069C3C);
