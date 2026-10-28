#include "common.h"
#include "6E644.h"
#include "146C.h"
#include "38C1C.h"
#include "4A0A8.h"
#include "5BF94.h"
#include "battleEffect.h"
#include "battleUnk.h"
#include "entity.h"
#include "src/SLUS_010.40/main.h"
#include "src/SLUS_010.40/32154.h"
#include "src/SLUS_010.40/overlay.h"
#include "build/src/include/lbas.h"
#include <abs.h>
#include <stdlib.h>
#include <rand.h>

#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) < (b) ? (b) : (a))

struct func_800D4910_t;

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
    u_short unk0;
    u_short unk2;
    u_char unk4;
} D_80069C3C_t;

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
    signed char dx : 2;
    signed char unk0_2 : 2;
    signed char dz : 2;
    signed char unk0_6 : 2;
} D_800F16EC_t;

// TODO: Partial view of vs_battle_actor with different fields, maybe merge.
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
    char unk18[2];
    u_short unk1A;
    char unk1C[0x14];
    u_int unk30_0 : 4;
    u_int unk30_4 : 5;
    u_int unk30_9 : 5;
    u_int unk30_14 : 2;
    u_int unk30_16 : 6;
    u_int unk30_22 : 5;
    u_int unk30_27 : 5;
    u_int unk34_0 : 12;
    u_int unk34_12 : 2;
    u_int unk34_14 : 1;
    u_int unk34_15 : 17;
    char unk38[4];
    vs_battle_actor2* unk3C;
} vs_battle_actorView_t;

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
    u_int unk0_0 : 1;
    u_int unk0_1 : 1;
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
    u_int unk0_1 : 1;
    u_int unk0_2 : 1;
    u_int unk0_3 : 1;
    u_int unk0_4 : 1;
    u_int unk0_5 : 1;
    u_int unk0_6 : 2;
    u_int unk0_8 : 7;
    u_int unk0_15 : 5;
    u_int unk0_20 : 7;
    u_int unk0_27 : 1;
    u_int unk0_28 : 2;
    u_int unk0_30 : 1;
    u_int unk0_31 : 1;
} func_800DA1D4_t;

typedef struct func_800E78F4_t {
    char unk0;
    u_char unk1;
    u_char unk2;
    u_char unk3;
    u_char unk4;
    u_char unk5;
    char unk6;
    u_char unk7;
    u_char unk8;
    u_char unk9;
    char unkA[3];
    u_char unkD;
    u_char unkE;
    u_char unkF;
    char unk10[3];
    u_char unk13;
    char unk14[2];
    int unk16 : 8;
    u_char unk17;
    u_char unk18;
    char unk19;
    u_char unk1A;
    u_char unk1B;
    u_char unk1C;
    char unk1D[3];
    u_char unk20;
    u_char unk21;
    u_char unk22;
    u_char unk23;
    u_char unk24;
    u_char unk25;
    u_char unk26;
    u_char unk27;
    char unk28;
    u_char unk29;
    char unk2A;
    u_char unk2B;
    u_char unk2C;
    u_char unk2D;
    char unk2E;
    u_char unk2F;
    u_char unk30;
    u_char unk31;
    u_char unk32;
    u_char unk33;
    vs_battle_movementPosition unk34;
    int unk38;
    char unk3C[6];
    short unk42;
    u_char unk44;
    char unk45[3];
    vs_battle_movementPosition unk48;
    SVECTOR unk4C;
    vs_battle_actorView_t* unk54;
    D_800F4538_t* unk58;
    vs_battle_actor2* unk5C;
    SVECTOR* unk60;
    vs_battle_movementPosition* unk64;
    int (*unk68)(struct func_800E78F4_t*);
    char unk6C[0x16];
    short unk82;
    char unk84[4];
    u_char unk88;
    u_char unk89;
    u_char unk8A;
    char unk8B;
    u_short unk8C;
    u_short unk8E;
    char unk90[2];
    u_short unk92;
    u_short unk94;
    char unk96[2];
    u_short unk98;
    u_short unk9A;
    int unk9C;
    char unkA0[4];
    u_int unkA4;
    int unkA8;
    u_int unkAC;
    u_short unkB0;
    u_char unkB2;
    u_char unkB3;
    int unkB4;
    short unkB8;
    u_short unkBA;
    short unkBC;
    short unkBE;
    u_short unkC0;
    u_short unkC2;
    int unkC4;
    u_int unkC8;
    u_char unkCC;
    char unkCD;
    u_char unkCE;
    char unkCF;
    short unkD0;
    u_short unkD2;
    u_short unkD4;
    u_short unkD6;
    u_char unkD8;
    char unkD9[0xE];
    u_char unkE7;
    u_char unkE8;
    u_char unkE9;
    char unkEA[0x10];
    u_char unkFA;
    u_char unkFB;
    char unkFC[4];
    u_char unk100;
    u_char unk101;
    u_char unk102;
    u_char unk103;
    u_char unk104;
    char unk105[3];
    vs_battle_movementPosition unk108;
    u_char unk10C;
    char unk10D[3];
    vs_battle_movementPosition unk110;
    char unk114[4];
    u_char unk118[4];
    vs_battle_movementPosition unk11C;
    char unk120[4];
    u_char unk124;
    char unk125[3];
    u_short unk128;
    u_char unk12A;
    u_char unk12B;
    char unk12C;
    u_char unk12D;
    u_char unk12E;
    signed char unk12F;
    signed char unk130;
    u_char unk131;
    char unk132[2];
    vs_battle_movementPosition unk134;
    u_short unk138;
    u_short unk13A;
    u_short unk13C;
    char unk13E;
    u_char unk13F;
    func_800DCAA0_t unk140;
    char unk154[4];
    short unk158;
    short unk15A;
    u_char unk15C;
    u_char unk15D;
    u_short unk15E;
    char unk160[8];
    vs_battle_movementPosition unk168;
    char unk16C[4];
    vs_battle_movementPosition unk170;
    char unk174[8];
    int unk17C;
    int unk180;
    int unk184;
    short unk188;
    int unk18A : 16;
    char unk18C[8];
    int unk194;
    char unk198[2];
    u_char unk19A;
    char unk19B[5];
    struct func_800E78F4_t* unk1A0;
    func_800DA1D4_t unk1A4[16];
    u_int unk1E4[16];
    u_char unk224;
    u_char unk225;
    u_char unk226;
    u_char unk227;
    int unk228;
    func_800DCAA0_t* unk22C;
    func_800DD604_t unk230[6][4];
    func_800DCAA0_t unk2F0[16];
    func_800DCAA0_t* unk430[16];
    int unk470;
    char unk474[0xD];
    u_char unk481;
} func_800E78F4_t;

typedef struct {
    u_char unk0;
    u_char unk1;
    u_char unk2;
    u_char unk3;
    char unk4[4];
    u_char unk8;
    char unk9;
    u_char unkA;
    char unkB[9];
    int unk14;
    u_short unk18;
    char unk1A[2];
    func_800E78F4_t* unk1C;
    func_800E78F4_t* unk20;
    int unk24;
    vs_battle_actor* unk28[4];
} D_800F58BC_t;

typedef struct {
    u_short unk0;
    u_char unk2;
    u_char unk3;
    int unk4;
    char unk8[2];
    u_char unkA;
    u_char unkB;
    short unkC;
    short unkE;
    short unk10;
    short unk12;
    u_char unk14;
    char unk15;
    u_char unk16;
    u_char unk17;
    short unk18;
    short unk1A;
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
    short tableCount;
    u_short dataOffset;
    int tableOffsets[0];
} pFileBlock1;

typedef struct {
    int unk0;
    u_char data[0];
} pFileBlock2;

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
int func_800D826C(func_800E78F4_t*);
void func_800D82CC(func_800E78F4_t*);
void func_800D836C(func_800E78F4_t*);
int func_800D954C(func_800E78F4_t*, vs_battle_movementPosition);
int func_800D96C8(
    func_800E78F4_t*, vs_battle_movementPosition, vs_battle_movementPosition, int);
int D_800D9B6C(func_800E78F4_t*, int);
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
int func_800DBCB4(func_800E78F4_t*, func_800DCAA0_t*);
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
void func_800DEEFC(func_800E78F4_t*, int);
int func_800DFBCC(func_800E78F4_t*, int, int);
int func_800E0678(func_800E78F4_t*, int);
int func_800E0918(func_800E78F4_t*, int, int);
void func_800E1388(func_800E78F4_t*, vs_battle_movementPosition, int, u_int);
int func_800E1BB8(func_800E78F4_t*, vs_battle_movementPosition, u_int, int);
void func_800E2CCC(func_800E78F4_t*);
void func_800E3600(func_800E78F4_t*, int, int);
int func_800E4180(func_800E78F4_t*, int, int, int);
void func_800E4288(void*, int);
int func_800E42D4(int, int);
int func_800E42E0(vs_battle_movementPosition);
int func_800E42EC(int, int);
int func_800E4320(int, int);
int func_800E437C(SVECTOR*, SVECTOR*, int, u_int);
int func_800E44E8(SVECTOR*, SVECTOR*, int, int);
int func_800E45D4(int);
u_int func_800E45F4(vs_battle_movementPosition, vs_battle_movementPosition);
int func_800E4624(SVECTOR*, SVECTOR*, int, int);
u_int func_800E4660(int, int, int);
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
void func_800E5EC0(int, int, int);
void func_800E6828(func_800E78F4_t*);
void func_800E678C(func_800E78F4_t*);
void func_800E685C(int, int, int);
void func_800E72D0(void);
void func_800E7370(func_800E78F4_t*);
void func_800E7660(func_800E78F4_t*);
int func_800E7698(func_800E78F4_t*);
void func_800E7960(func_800E78F4_t*);
int func_800E7F8C(func_800E78F4_t*);

extern u_int D_80069BBC[];
extern u_char D_80069C18[];
extern u_int D_80069C1C[];
extern D_80069C3C_t D_80069C3C[];
extern p_file_t D_800EC4BC;
extern D_800F16EC_t D_800F16EC[8];
extern int (*D_800F1790[])(func_800E78F4_t*);
extern u_short D_800F17B8[][2];
extern u_short D_800F17C8[][2];
extern u_char D_800F17D8[];
extern short D_800F17DC[][2];
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
extern int D_800F58C0;
extern D_800F58C8_t* D_800F58C8;
extern u_short (*D_800F58D0)[32];
extern D_800F58C8_t* D_800F58D8;
extern int D_800F58E0;
extern vs_battle_actor2* D_800F58E8;
extern func_800DCAA0_t (*D_800F58EC)[16];
extern int D_800F58F0;
extern int D_800F58F4;
extern func_800DCAA0_t* D_800F58F8;
extern D_800F19CC_t2* D_800F5900;
extern u_char (*D_800F5904)[256];
extern int D_800F590C;
extern D_800F5910_t* D_800F5910;
extern int D_800F5918;
extern int D_800F591C;
extern D_800F5920_t* D_800F5920;

typedef struct {
    int unk0;
    u_int unk4;
} func_800E78F4_t2;

typedef struct {
    char unk0[0x16];
    signed char unk16;
    char unk17[0x21];
    int unk38;
    char unk3C[0x18];
    vs_battle_actorView_t* unk54;
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
