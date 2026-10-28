#include "common.h"
#include "146C.h"
#include "3A1A0.h"
#include "4A0A8.h"
#include "5BF94.h"
#include "38C1C.h"
#include "6E644.h"
#include "src/SLUS_010.40/32154.h"
#include "src/SLUS_010.40/main.h"
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
    func_800DEB10_t2* unk54;
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
    u_char unk0;
    u_char unk1;
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
int func_800863A4(int, int, int, int, SVECTOR*, SVECTOR*, void*);
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
void func_800DC810(func_800DEEA4_t*);
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
extern func_800DEEA4_t* D_800F5900;
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

int func_800E7698(func_800E78F4_t* arg0)
{
    D_800F4538_t* model = arg0->unk58;
    D_800F5920_t* motion = D_800F5920;
    int angle;

    arg0->unk470 = 0;
    model->unk5B0_4 = motion->unkB < 14;
    func_800E4660(0x7C0 - arg0->unk4C.vx, 0, 0x7C0 - arg0->unk4C.vz);

    switch (motion->unk2) {
    case 0:
        motion->unkA = 1;
        angle = ratan2(arg0->unk4C.vx - 0x7C0, arg0->unk4C.vz - 0x7C0) & 0xFFF;
        motion->unk10 = (-angle + ONE * 3 / 4) & 0xFFF;
        motion->unkB = 0;
        ++motion->unk2;
        motion->unk18 = arg0->unk4C.vx;
        motion->unk1A = arg0->unk4C.vz;
        break;
    case 1:
        if (!D_800F17DC[motion->unkB][0] && !D_800F17DC[motion->unkB][1]) {
            if (D_800F4538[0]->unk0.unkA_0) {
                func_800E2CCC(arg0);
                return 0;
            }

            motion->unk2 = 0;
            angle = ratan2(0x7C0 - arg0->unk4C.vx, 0x7C0 - arg0->unk4C.vz) & 0xFFF;
            motion->unk0 = (-angle + ONE * 3 / 4) & 0xFFF;
            model->unk5B0_4 = 0;
            return 1;
        }
        break;
    }

    arg0->unk17C =
        arg0->unk4C.vx * ONE + D_800F17DC[motion->unkB][0] * rcos(motion->unk10);
    arg0->unk180 =
        arg0->unk4C.vz * ONE + D_800F17DC[motion->unkB][0] * rsin(motion->unk10);
    arg0->unk184 = (arg0->unk4C.vy + D_800F17DC[motion->unkB][1]) * ONE;
    func_800DEEFC(arg0, 8);
    motion->unk3 = 0;
    ++motion->unkB;
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

void func_800E7960(func_800E78F4_t* arg0)
{
    D_800F5920_t* motion = D_800F5920;
    int center[3];
    int playerAngle;
    int currentAngle;
    int tracking;
    int radius;
    int heading;
    int sign;
    int cosCurrent;
    int sinTarget;
    int sinCurrent;
    int cosTarget;
    int aligned;
    int delta;
    int ratio;
    int denominator;
    int scale;
    int magnitude;
    int oppositeAngle;
    int facing;
    int correction;
    int difference;

    if (!motion->unk1C) {
        int initialAngle = ratan2(0x7C0 - arg0->unk4C.vx, 0x7C0 - arg0->unk4C.vz) & 0xFFF;

        motion->unk0 = (-initialAngle + ONE * 3 / 4) & 0xFFF;
        motion->unk12 = arg0->unk4C.vy;
        motion->unk1C = 1;
    }

    if (!motion->unk3) {
        motion->unk4 = func_800E4660(0x7C0 - arg0->unk4C.vx, 0, 0x7C0 - arg0->unk4C.vz);
        ++motion->unk3;
    }

    arg0->unk58->unk5B0_4 = 0;
    radius = vs_gte_rsqrt(motion->unk4);

    if (radius < 1024) {
        radius += 32;
    }

    if (radius > 1024) {
        radius -= 32;
    }

    difference = radius - 1024;
    difference = ABS(difference);

    if (difference < 32) {
        radius = 1024;
    }

    motion->unk4 = radius * radius;
    center[0] = 0x7C0 * ONE;
    difference = motion->unk12 - 160;

    difference = ABS(difference);

    if (difference < 16) {
        motion->unk12 = 160;
    } else if (motion->unk12 < 160) {
        motion->unk12 += 12;
    } else {
        motion->unk12 -= 12;
    }

    center[1] = motion->unk12 * ONE;
    center[2] = 0x7C0 * ONE;
    playerAngle = ratan2(
        0x7C0 - D_800F4538[0]->unk0.position.vx, 0x7C0 - D_800F4538[0]->unk0.position.vz);
    currentAngle = ratan2(0x7C0 - arg0->unk4C.vx, 0x7C0 - arg0->unk4C.vz);

    if (func_800E78F4(arg0) && func_800D826C(arg0)) {
        heading = playerAngle;
        tracking = 1;
    } else {
        tracking = 0;
        heading = playerAngle + ONE / 2;
    }

    sign = D_800F5918 >= 0 ? 1 : -1;
    cosCurrent = rcos(-currentAngle + ONE * 3 / 4);
    sinTarget = rsin(-heading + ONE * 3 / 4);
    sinCurrent = rsin(-currentAngle + ONE * 3 / 4);
    cosTarget = rcos(-heading + ONE * 3 / 4);
    aligned = ((cosCurrent * sinTarget - sinCurrent * cosTarget) * sign) >= 0;

    if (aligned) {
        delta = ABS(D_800F5918) > 0x280000 ? D_800F5918 / 8 + (sign << 16) : sign << 16;
    } else {
        delta = D_800F5918 / 4 + (sign << 16);
    }

    if ((tracking || rcos(currentAngle - heading) < rcos(222)) && !aligned) {
        delta = -delta;
    }

    D_800F5918 += delta;
    sign = D_800F5918 >= 0 ? 1 : -1;

    if (ABS(D_800F5918) > 0x820000) {
        D_800F5918 = sign * 0x820000;
    }

    ratio = (arg0->unk5C->currentHP << 16) / arg0->unk5C->maxHP;

    if (!motion->unkC) {
        if ((!motion->unk14 && ratio < 0xC000)
            || (motion->unk14 == 1 && ratio < 0x4000)) {
            ++motion->unk14;
            do {
                motion->unkE = 1;
            } while (0);
        } else if (ABS(D_800F5918) < 0x40000 && tracking && D_800F591C < 30
                   && !(rand() & 511)) {
            motion->unkE = 1;
        }
    }

    motion->unk0 += D_800F5918 >> 16;
    facing = motion->unk0;
    arg0->unk15C = 0;
    arg0->unk17C = center[0] + radius * rcos(facing);
    arg0->unk180 = center[2] + radius * rsin(facing);

    if (tracking) {
        if (aligned) {
            denominator = currentAngle - playerAngle;
            scale = -80 - D_800F591C;
        } else {
            oppositeAngle = currentAngle - ONE / 2;
            denominator = playerAngle - oppositeAngle;
            scale = 300 - D_800F591C;
        }
    } else if (aligned) {
        oppositeAngle = currentAngle - ONE / 2;
        denominator = playerAngle - oppositeAngle;
        scale = 300 - D_800F591C;
    } else {
        denominator = ABS(D_800F5918) >> 16;
        scale = 10;
    }

    denominator &= 0xFFF;

    if (denominator > ONE / 2) {
        denominator = ONE - denominator;
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

    arg0->unk184 = center[1] - D_800F591C * ONE;

    if (arg0->unk184 >= 0xFF000) {
        arg0->unk184 = 0xFF000;
    }

    func_800DEEFC(arg0, 8);
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
