#include "common.h"
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
    char unkFC[5];
    u_char unk101;
    u_char unk102;
    u_char unk103;
    char unk104[4];
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

int func_800D85D8(func_800E78F4_t*);

typedef struct {
    int unk0;
    u_int unk4;
} func_800E78F4_t2;

typedef struct {
    char unk0[0x88];
    u_char unk88;
} func_800DCAA0_t1;

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

int func_800E42D4(int, int);
unsigned int func_800E4660(int, int, int);

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

void func_800DC888(func_800DC888_t* arg0)
{
    int i;
    func_800DC888_t* row;

    if (D_800F5900->unk4.unk40 == 0) {
        vs_action_t* action = &vs_main_actions[D_800F5900->unk0];

        row = &arg0[D_800F5900->unk4.unk0];

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
        func_800DEB10_t* entry = i < 0 ? &D_800F5900->unk4 : &D_800F5900->unk4C[i];

        if (entry->unk40 == 0) {
            row = &arg0[entry->unk0];
            func_800DC30C(&row->unk4, &row->unk6, entry->unk4, entry->unk1C_0);
            func_800DC30C(&row->unk8, &row->unkA, entry->unk6, entry->unk1C_2);
            func_800DC30C(&row->unk10, &row->unk12, entry->unk38, entry->unk1C_18);
            func_800DC30C(&row->unk14, &row->unk16, entry->unk3C, entry->unk1C_22);
            row->unkC |= entry->unk14;
            row->unkC &= ~entry->unk18;
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

typedef struct actionScoreActor {
    struct actionScoreActor* next;
    int id;
} actionScoreActor;

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
void func_800DD000(func_800E78F4_t* arg0, func_800DEEA4_t* arg1)
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

    info = &vs_main_actions[arg1->unk0];
    skip = info->hitParams[0].prerequisiteFunction == 3
        || info->hitParams[1].prerequisiteFunction == 3;

    if (skip) {
        return;
    }

    source = arg1->unk4.unk0;
    action = arg1->unk0;
    other = D_800F5878[source];

    for (i = 0; i < arg1->unk4A; ++i) {
        func_800DEB10_t* entry = &arg1->unk4C[i];

        if (entry->unk40 || entry->unk0 != id || source == id) {
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

        if (D_800F5920 != NULL && source == 0 && entry->unk1C_0 != 2 && entry->unk4 > 0) {
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

typedef struct {
    char pad0[0x4C];
    short x, y, z;
} nearestWaypointState;
typedef struct {
    unsigned char x, y, z, flags;
} nearestWaypointDestination;
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

static inline vs_battle_uiEquipment_limb* actorLimb(vs_battle_actor2* stats, int limb)
{
    return ((vs_battle_actor2*)(limb * sizeof(vs_battle_uiEquipment_limb) + (int)stats))
        ->limbs;
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

#undef MIN
#undef MAX

void func_800DEB10(func_800DEEA4_t* arg0)
{
    int i;
    int j;
    func_800E78F4_t* entry;
    func_800DEB10_t2* temp_t1;

    if (arg0 == NULL) {
        return;
    }

    if (arg0->unk4.unk40 != 0) {
        return;
    }

    entry = D_800F5878[arg0->unk4.unk0];
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
    func_800DEEA4_t* action = arg0;
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
                && action->unk4.unk0 == state->unk88) {
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

void func_800DEEA4(func_800DEEA4_t* arg0)
{
    if (arg0 != NULL) {
        if (arg0->unk4.unk40 == 0) {
            func_800E78F4_t* entry = D_800F5878[arg0->unk4.unk0];

            if (entry != NULL) {
                entry->unk9A = 0;
            }
        }

        func_800DC810(arg0);
    }
}
