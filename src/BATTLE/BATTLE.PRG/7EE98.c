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
int func_800D9E18(func_800E78F4_t*, func_800DCAA0_t*);
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

typedef struct movementRecoveryState movementRecoveryState;
typedef struct radialMotionState radialMotionState;
int func_800E7698(radialMotionState*);
typedef struct trackingMotionState trackingMotionState;
void func_800E7960(trackingMotionState*);

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

    if (arg0->unk470 != 0 && func_800DBCB4(arg0, arg0->unk430[0])) {
        a = arg0->unk430[0]->unk4_13;
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
        func_800E7960(arg0);

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

        if (func_800E7698(arg0) != 0) {
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

                temp_s0->unk12 = arg0->unk4C.vy;
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
