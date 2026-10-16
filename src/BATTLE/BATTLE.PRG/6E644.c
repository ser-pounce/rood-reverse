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
#include <rand.h>

#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) < (b) ? (b) : (a))

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
    u_int unk0_1 : 4;
    u_int unk0_5 : 1;
    u_int unk0_6 : 2;
    u_int unk0_8 : 7;
    u_int unk0_15 : 5;
    u_int unk0_20 : 7;
    u_int unk0_27 : 1;
    u_int unk0_28 : 2;
    u_int unk0_30 : 2;
} func_800DA1D4_t;

typedef struct {
    u_int x : 8;
    u_int y : 8;
    u_int z : 8;
    u_int status : 8;
} vs_battle_movementPosition;

typedef struct {
    int unk0;
    int unk4;
    u_int unk8_0 : 21;
    u_int unk8_21 : 1;
    u_int unk8_22 : 10;
    char unkC[8];
    short unk14;
    char unk16[6];
    SVECTOR unk1C;
    char unk24[2];
    short unk26;
    char unk28[0x34];
    vs_battle_movementPosition unk5C;
    char unk60[0x550];
    u_int unk5B0_0 : 4;
    u_int unk5B0_4 : 1;
} func_800E1238_t;

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
    char unk22[4];
    u_char unk26;
    u_char unk27;
    char unk28;
    u_char unk29;
    char unk2A;
    u_char unk2B;
    u_char unk2C;
    char unk2D[3];
    u_char unk30;
    char unk31[3];
    vs_battle_movementPosition unk34;
    int unk38;
    char unk3C[8];
    u_char unk44;
    char unk45[3];
    vs_battle_movementPosition unk48;
    SVECTOR unk4C;
    func_800DEB10_t2* unk54;
    func_800E1238_t* unk58;
    vs_battle_actor2* unk5C;
    char unk60[0x22];
    short unk82;
    char unk84[4];
    u_char unk88;
    char unk89[3];
    u_short unk8C;
    u_short unk8E;
    char unk90[2];
    u_short unk92;
    char unk94[4];
    u_short unk98;
    u_short unk9A;
    char unk9C[0x17];
    u_char unkB3;
    int unkB4;
    short unkB8;
    u_short unkBA;
    char unkBC[2];
    short unkBE;
    u_short unkC0;
    u_short unkC2;
    int unkC4;
    char unkC8[8];
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
    char unkFC[0xC];
    vs_battle_movementPosition unk108;
    u_char unk10C;
    char unk10D[0xB];
    u_char unk118[4];
    vs_battle_movementPosition unk11C;
    char unk120[0xA];
    u_char unk12A;
    char unk12B[2];
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
    char unk18C[0xE];
    u_char unk19A;
    char unk19B[5];
    struct func_800E78F4_t* unk1A0;
    func_800DA1D4_t unk1A4[16];
    u_int unk1E4[16];
    char unk224[4];
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
void func_800E678C(func_800E78F4_t*);
void func_800E685C(int, int, int);
int func_800E7698(func_800E78F4_t*);
void func_800E7960(func_800E78F4_t*);

extern u_int D_80069BBC[];
extern p_file_t D_800EC4BC;
extern D_800F16EC_t D_800F16EC[8];
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
extern D_800F5910_t* D_800F5910;
extern int D_800F5918;
extern int D_800F591C;
extern D_800F5920_t* D_800F5920;

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D6E44);

void func_800D7814(void)
{
    D_800F568C = NULL;
    vs_battle_pfileBuf = NULL;
    D_800F56A0 = NULL;
    D_800F5874 = 0;
    D_800F5684 = 0;
    D_800F57A0.curveBlock = NULL;
    D_800F57A0.unkD0 = &D_800F53C0;
    D_800F5798 = &D_800F5230;
    func_800D7890(0);
    func_800D8060(&D_800EC4BC);
}

void func_800D7890(int arg0)
{
    if (arg0 == 0) {
        D_800F569C = &D_800F57A0;
    } else {
        D_800F569C = &D_800F56C8;
    }
}

extern D_800F569C_t* D_800F5698;

void func_800D78B8(void) { D_800F5698 = D_800F569C; }

void func_800D78CC(void) { D_800F569C = D_800F5698; }

void _parsePfileBlock5(pFileBlock5* block) { D_800F569C->block5Data = block; }

void func_800D78F0(void)
{
    VECTOR sp10;
    int sp20;

    vs_battle_lerpVector(
        D_800F569C->block9Data->unk0, D_800F5330[D_800F569C->block9Data->unk12], &sp10);
    sp20 = func_800CFE1C(
        D_800F569C->block9Data->unkC, D_800F5330[D_800F569C->block9Data->unk13]);
    func_800D5260(&sp10);
    func_800D5294(&sp20);
}

void _parsePfileBlock3(void* block) { D_800F569C->block3Data = block; }

void _parsePfileCurveBlock(pFileCurveBlock* block)
{
    u_char* p;
    int i;

    D_800F569C->curveBlock = block;
    p = (u_char*)block + block->dataOffset;

    for (i = 0; i < block->count; i++) {
        D_800F569C->curves[i] = p;
        p += block->curveSizes[i];
    }
}

void _parsePfileBlock8(void* block) { D_800F569C->block8Data = block; }

void _parsePfileBlock9(pFileBlock9* arg0) { D_800F569C->block9Data = arg0; }

void _parsePfileBlock10(void* arg0) { D_800F569C->block10Data = arg0; }

void _parsePfileBlock1(pFileBlock1* block)
{
    int i;

    D_800F569C->block1TableCount = block->tableCount;
    D_800F569C->textures = (void*)block + block->dataOffset;

    for (i = 0; i < D_800F569C->block1TableCount; ++i) {
        D_800F569C->textureInfoTable[i] = (void*)block + block->tableOffsets[i];
    }
}

void _parsePfileBlock2(pFileBlock2* block)
{
    D_800F569C->block2Count = block->unk0;
    D_800F569C->block2Data = (void*)block;
}

void* func_800D7A90(int arg0)
{
    return (u_char*)D_800F569C->block2Data + D_800F569C->block2Data[arg0 + 2];
}

void _parsePfileBlock11(u_char* arg0) { D_800F569C->block11Data = arg0; }

void _parsePfileBlock12(void* arg0)
{
    D_800F569C->block12Data = arg0;
    func_80046168((u_int)arg0);
}

void _parsePfileBlock13(void* arg0)
{
    D_800F569C->block13Data = arg0;
    D_800F569C->unkCC = func_80046608((u_int)arg0);
}

static int _loadfile(int lba, int size, void* buf)
{
    vs_main_CdFile cdFile;

    if (D_800F568C == NULL) {
        cdFile.lba = lba;
        cdFile.size = size;
        D_800F568C = vs_main_allocateCdQueueSlot(&cdFile);
        vs_main_cdEnqueue(D_800F568C, buf);
        return 1;
    }

    if (D_800F568C->state == vs_main_CdQueueStateLoaded) {
        vs_main_freeCdQueueSlot(D_800F568C);
        D_800F568C = NULL;
        return 0;
    }

    return 1;
}

int vs_battle_loadEffPurge(void)
{
    if (D_800F5684 == 0) {
        func_8007E180(2);
        D_800F5684 = 1;
    }

    return _loadfile(VS_EFFPURGE_BIN_LBA, VS_EFFPURGE_BIN_SIZE, vs_overlay_slots[3]);
}

int func_800D7BF8(void)
{
    int _[16];

    if (vs_battle_pfileBuf == NULL) {
        vs_battle_pfileBuf = vs_main_allocHeapR(vs_battle_pFileLoadContext.size);
    }

    return _loadfile(vs_battle_pFileLoadContext.lba + VS_E000_P_LBA,
        vs_battle_pFileLoadContext.size, vs_battle_pfileBuf);
}

void func_800D7C5C(void)
{
    int i;
    int bit;
    int flags;

    for (i = 24; i < 32; i++) {
        flags = D_800F5874;
        bit = 1 << i;
        if (flags & bit) {
            func_8007E0A8(i, 1, 2);
            D_800F5874 &= ~bit;
        }
    }
    if (vs_battle_pfileBuf != NULL) {
        vs_main_freeHeapR(vs_battle_pfileBuf);
        vs_battle_pfileBuf = NULL;
    }
}

int func_800D7CFC(void)
{
    int _[16] __attribute__((unused));
    RECT sp50;
    u_int temp_s1;
    int var_s0;

    if ((D_800F5680 == 0) && (D_800F5638.unk0 != 0)) {
        D_800F5630 = 0;
        func_800D8038(1);
    }

    temp_s1 = D_800F5680;

    switch (temp_s1) {
    case 1:
        if (D_800F56A0 == NULL) {
            // FBT sizes are all equal
            D_800F56A0 = vs_main_allocHeapR(VS_E000_0_FBT_SIZE);
        }

        var_s0 = _loadfile(D_800F5638.loadContexts[D_800F5630].lba + VS_E000_P_LBA,
            D_800F5638.loadContexts[D_800F5630].size, D_800F56A0);

        if (var_s0 == 0) {
            void* temp_v0_3 = (D_800F5630 * 2) + &D_800F5638;
            int slot = D_800F5638.slots[D_800F5630];

            if (D_800F5638.isClut[D_800F5630] == 0) {
                slot += 24;
                func_8007DFF0(slot, 1, 2);
                D_800F5874 |= temp_s1 << slot;
                sp50.x = (slot - (slot / 16 * 16)) << 6;
                sp50.y = slot / 16 << 8;
                sp50.w = 64;
                sp50.h = 256;
                LoadImage(&sp50, D_800F56A0);
            } else {
                sp50.x = 768;
                sp50.y = slot + 240;
                sp50.w = 256;
                sp50.h = 5 - slot;
                LoadImage(&sp50, D_800F56A0);
            }

            ++D_800F5630;

            if (D_800F5638.unk0 == D_800F5630) {
                func_800D8038(2);
            }

            var_s0 = 1;
        }
        break;

    case 2:
        if (D_800F56A0 != NULL) {
            vs_main_freeHeapR(D_800F56A0);
            D_800F56A0 = NULL;
        }
        /* fallthrough */

    case 0:
        var_s0 = 0;
        break;
    }
    return var_s0;
}

int func_800D7EF4(void)
{
    int _[16];
    int ret;
    u_int state = _plgLoadState;

    switch (state) {
    case 1:
        if (D_800F5684 == 0) {
            func_8007E180(2);
            D_800F5684 = state;
        }
        // Fallthrough

    case 2:
        ret = _loadfile(_plgLoadContext.lba + VS_E000_P_LBA, _plgLoadContext.size,
            vs_overlay_slots[3]);
        if (ret == 0) {
            vs_battle_setPlgLoadState(3);
        }
        break;
    case 0:
    case 3:
        ret = 0;
        break;
    }

    return ret;
}

static void func_800D7FB4(int arg0, int arg1) __attribute__((unused));
static void func_800D7FB4(int lba, int size)
{
    vs_battle_pFileLoadContext.lba = lba;
    vs_battle_pFileLoadContext.size = size;
}

void vs_battle_configurePlg(int lba, int size, int entryPointCount)
{
    _plgLoadContext.lba = lba;
    _plgLoadContext.size = size;
    _plgEntryPointCount = entryPointCount;
}

void vs_battle_setEffectExec(effectExec func, int index)
{
    vs_battle_effectRenderers[index] = func;
}

void func_800D7FFC(int arg0) { D_800F5638.unk0 = arg0; }

void vs_battle_configureEffectFbLoad(int lba, int size, int slot, int isClut, int index)
{
    D_800F5638.loadContexts[index].lba = lba;
    D_800F5638.loadContexts[index].size = size;
    D_800F5638.slots[index] = slot;
    D_800F5638.isClut[index] = isClut;
}

void func_800D8038(int arg0) { D_800F5680 = arg0; }

u_int func_800D8044(void) { return D_800F5680; }

void vs_battle_setPlgLoadState(int arg0) { _plgLoadState = arg0; }

void func_800D8060(p_file_t* arg0)
{
    while (1) {
        int meta = arg0->meta;

        switch (meta & 0xFFFF0000) {
        case 0:
            return;

        case 0x10000:
            _parsePfileBlock1((pFileBlock1*)arg0->data);
            break;

        case 0x20000:
            _parsePfileBlock2((pFileBlock2*)arg0->data);
            break;

        case 0x30000:
            _parsePfileBlock3(arg0->data);
            break;

        case 0x40000:
            _parsePfileCurveBlock((pFileCurveBlock*)arg0->data);
            break;

        case 0x50000:
            _parsePfileBlock5((pFileBlock5*)arg0->data);
            break;

        case 0x80000:
            _parsePfileBlock8(arg0->data);
            break;

        case 0x90000:
            _parsePfileBlock9((pFileBlock9*)arg0->data);
            break;

        case 0xA0000:
            _parsePfileBlock10(arg0->data);
            break;

        case 0xB0000:
            _parsePfileBlock11(arg0->data);
            break;

        case 0xC0000:
            _parsePfileBlock12(arg0->data);
            break;

        case 0xD0000:
            _parsePfileBlock13(arg0->data);
            break;
        }

        arg0 = (void*)arg0 + (meta & 0xFFFF);
    }
}

int vs_battle_getMainMenuLba(void) { return VS_MAINMENU_PRG_LBA; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D820C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D821C);

void func_800D8260(func_800E78F4_t* arg0, int arg1, int arg2)
{
    arg0->unk138 = arg1;
    arg0->unk12A = arg2;
}

// hasm: func_800D820C and func_800D836C branch into the shared return.
__asm__("glabel func_800D826C;"
        "lhu     $v0, 0x8E($a0);"
        "nop;"
        "slt     $v0, 32;"
        ".L800D8278:;"
        "j       $ra;"
        "xor     $v0, 1;"
        "endlabel func_800D826C;");

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D8280);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D82A8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D82CC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D836C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D8400);

int func_800D85D8(func_800E78F4_t* arg0)
{
    int i;
    int changed = 0;
    u_char status;
    vs_battle_actor* actor;

    for (i = 0; i < arg0->unk470; ++i) {
        func_800DCAA0_t* entry = arg0->unk430[i];

        if (entry->unkC_19 && entry->unk4_13 <= D_800F58BC->unk18
            && (!func_800E4CF4(arg0, entry, entry->unkC_0)
                || !func_800E4DF8(arg0, entry->unk4_0, entry->unk4_3))) {
            entry->unkC_19 = 0;
        }
    }

    if (arg0->unk470 > 0 && !arg0->unk430[0]->unkC_19) {
        changed = 1;

        for (i = 1; i < arg0->unk470; ++i) {
            func_800DCAA0_t* entry = arg0->unk430[i];

            if (entry->unkC_19) {
                arg0->unk430[0] = entry;
                func_800D9DD8(arg0);
                goto done;
            }
        }

        arg0->unk470 = 0;
    }

done:
    if (!arg0->unk470) {
        for (actor = vs_battle_actors[0]; actor != NULL; actor = actor->next) {
            if (arg0->unk1A4[actor->id].unk0_6 == 3) {
                break;
            }
        }

        status = actor == NULL ? 3 : 2;
    } else {
        status = D_800F58BC->unk18 + 30 < arg0->unk430[0]->unk4_13;
    }

    arg0->unk131 = status;
    return changed;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D87E8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D954C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D96C8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D98E8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D9DD8);

int func_800D9E18(func_800E78F4_t* arg0, func_800DCAA0_t* arg1)
{
    int id;
    int flag;
    u_int distance;
    u_int limit;
    int active = 0;
    SVECTOR point;
    int x;
    int z;
    int y;

    if (!arg0->unk470) {
        return 0;
    }

    id = arg1->unkC_0;

    if (id == 16 || !((func_800E78F4_t**)0x1F80037C)[id]) {
        return 0;
    }

    switch (arg0->unk12E) {
    case 1:
    normal:
        limit = 0x1F80;

        if (!(arg0->unk15E & 8)) {
            limit = vs_gte_rsqrt(arg1->unk8) + arg0->unkB3 * 32;
        }

        limit = limit * limit;

        if (arg0->unk1A4[id].unk0_6 == 2) {
            distance = arg1->unk8;
            flag = 0;
            active = 1;
        } else {
            if (func_800DB8AC(arg0, arg1)) {
                distance = arg1->unk8;
                active = 1;
            } else {
                u_int minimum;

                distance = limit;
                minimum = 640 * 640;

                if (distance < minimum) {
                    distance = minimum;
                }
            }

            flag = 1;
        }

        distance = vs_gte_rsqrt(distance);

        if (active) {
            ++D_800F58BC->unk24;

            if (arg0->unk1E4[id] < limit && arg0->unk1A4[arg1->unkC_0].unk0_0) {
                func_800D836C(arg0);
            }
        }

    move:
        if (func_800DB370(arg0, id, distance, flag)) {
            return 1;
        }

        return func_800DB74C(arg0, id) != 0;

    case 2:
        if (!func_800DBCB4(arg0, arg1)) {
            goto normal;
        }

        if (arg1->unk10.unk1) {
            point.vx = arg0->unk134.x * 128 + 64;
            point.vz = arg0->unk134.z * 128 + 64;
            point.vy = func_800E42D4(point.vx, point.vz);

            if (vs_gte_rsqrt(func_800E4624(&point, &D_800F4538[id]->unk0.position,
                    arg0->unk82, D_800F5878[id]->unk82))
                < vs_gte_rsqrt(arg1->unk8) - arg1->unk10.unk6) {
                goto normal;
            }
        }

        x = arg0->unk168.x * 128 + 64;
        z = arg0->unk168.z * 128 + 64;
        y = func_800E42D4(x, z);

        if (func_800E4660(x - arg0->unk4C.vx, y - arg0->unk4C.vy, z - arg0->unk4C.vz)
            <= 65535) {
            arg0->unk15C = id;
            func_800DB5B8(arg0, arg0->unk134, 2);
        } else {
            arg0->unk1 = 1;
            func_800DB5DC(arg0, arg0->unk134, 256);
        }

        return 1;

    case 4:
        return func_800DB61C(arg0, 0);

    case 7:
        func_800D82CC(arg0);
        id = 0;
        flag = 1;

        if (arg0->unk1A4[id].unk0_6 == 3) {
            distance = 640;
            goto move;
        }
        break;
    }

    return 0;
}

int func_800DA1D4(func_800E78F4_t* arg0)
{
    int i;
    int id = -1;
    u_int nearest = -1;
    int flag;
    int distance;
    func_800DCAA0_t* entry;
    vs_battle_actor* actor;

    switch (arg0->unk131) {
    case 0:
        entry = arg0->unk430[0];
        id = entry->unkC_0;

        if (func_800D9E18(arg0, entry)) {
            return 1;
        }

        for (i = 1; i < arg0->unk470; ++i) {
            entry = arg0->unk430[i];

            if (entry->unk4_13 < D_800F58BC->unk18 && entry->unkC_0 != id) {
                return func_800D9E18(arg0, entry);
            }
        }

        return 0;

    case 1:
        func_800D82CC(arg0);

        if (arg0->unk1A4[0].unk0_6 == 3) {
            if (func_800DB370(arg0, 0, 640, 1)) {
                return 1;
            }

            if (func_800DB74C(arg0, 0)) {
                return 1;
            }
        }

        id = arg0->unk430[0]->unkC_0;

        if (arg0->unk1A4[id].unk0_6 == 3) {
            flag = 1;
            distance = 640;
        } else {
            if (arg0->unk470 < 2) {
                return 0;
            }

            flag = 0;
            distance = vs_gte_rsqrt(arg0->unk430[1]->unk8);
        }

        if (func_800DB370(arg0, id, distance, flag)) {
            return 1;
        }

        if (func_800DB74C(arg0, id)) {
            return 1;
        }
        // Fallthrough

    case 2:
        func_800D82CC(arg0);

        if (arg0->unk1A4[0].unk0_6 == 3) {
            if (func_800DB370(arg0, 0, 640, 1)) {
                return 1;
            }

            if (func_800DB74C(arg0, 0)) {
                return 1;
            }
        }

        for (actor = vs_battle_actors[0]; actor != NULL; actor = actor->next) {
            if (arg0->unk1A4[actor->id].unk0_6 == 3
                && arg0->unk1E4[actor->id] < nearest) {
                nearest = arg0->unk1E4[actor->id];
                id = actor->id;
            }
        }

        if (id >= 0) {
            if (func_800DB370(arg0, id, 640, 1)) {
                return 1;
            }

            if (func_800DB74C(arg0, id)) {
                return 1;
            }
        }
        break;
    }

    return 0;
}

int func_800DA4BC(func_800E78F4_t* arg0, func_800DCAA0_t* arg1)
{
    if (func_800DB8AC(arg0, arg1)) {
        int id = arg1->unkC_0;
        int distance = vs_gte_rsqrt(arg1->unk8);
        int range = distance + arg0->unkB3 * 32;

        range *= range;
        ++D_800F58BC->unk24;

        if (arg0->unk1E4[id] < range && arg0->unk1A4[arg1->unkC_0].unk0_0) {
            func_800D836C(arg0);
        }

        if (func_800DB370(arg0, id, distance, 1)) {
            return 1;
        }

        if (func_800DB74C(arg0, id)) {
            return 1;
        }
    }

    return 0;
}

int func_800DA5CC(func_800E78F4_t* arg0)
{
    func_800DCAA0_t* entry = arg0->unk430[0];
    int id;

    if (!arg0->unk131 && func_800DA4BC(arg0, entry)) {
        return 1;
    }

    id = arg0->unk16;

    if (id < 16) {
        if (func_800DB370(arg0, id, 288, 1)) {
            if (arg0->unkE9 == 1 && arg0->unk12E != 7) {
                arg0->unk15C = entry->unkC_0;
                func_800E678C(arg0);
                func_800E2CCC(arg0);
            }

            return 1;
        }

        if (func_800DB74C(arg0, id)) {
            return 1;
        }
    }

    return 0;
}

int func_800DA6A4(func_800E78F4_t* arg0)
{
    int id;

    if (arg0->unkE) {
        return func_800DB61C(arg0, 1);
    }

    id = func_800DBB2C(arg0, NULL, 3);

    if (id >= 0 && func_800DBB2C(arg0, NULL, 2) >= 0
        && func_800DB370(arg0, id, 1024, 1)) {
        return 1;
    }

    return func_800DA1D4(arg0);
}

int func_800DA738(func_800E78F4_t* arg0)
{
    vs_battle_movementPosition point;
    int active = 0;
    int old;
    int candidate = func_800DBB2C(arg0, &point, 3);
    int target = arg0->unk16;
    int valid = candidate >= 0;

    if (arg0->unk88 != target && target != 16 && ((func_800E78F4_t**)0x1F80037C)[target]
        && arg0->unk1A4[target].unk0_6 == 2) {
        active = 1;
    }

    old = arg0->unkF;
    arg0->unkF = active;

    if (valid && active && arg0->unk1A4[target].unk0_5) {
        int x;
        int z;
        vs_battle_movementPosition tile = ((func_800E1238_t*)D_800F4538[target])->unk5C;
        int angle =
            ratan2(point.x * 128 - (x = D_800F4538[target]->unk0.position.vx - 64),
                point.z * 128 - (z = D_800F4538[target]->unk0.position.vz - 64));
        int heading = ratan2(arg0->unk4C.vx - D_800F4538[target]->unk0.position.vx,
            arg0->unk4C.vz - D_800F4538[target]->unk0.position.vz);
        int cosAngle = rcos(angle);
        int cosHeading = rcos(heading);
        int sinAngle = rsin(angle);
        int dot = cosAngle * cosHeading + sinAngle * rsin(heading);

        dot >>= 12;

        if (arg0->unk44) {
            --arg0->unk44;
        }

        if (dot >= -1200 || arg0->unk44) {
            func_800E1388(arg0, tile, ratan2(point.x - tile.x, point.z - tile.z), 320);
            arg0->unk1 = 1;
            func_800E50A0(arg0, 0, 0);

            if (!arg0->unk44) {
                arg0->unk44 = 10;
            }

            return 1;
        }
    }

    if (active) {
        if (valid
            && ((func_800E78F4_t**)0x1F80037C)[target]->unk1E4[candidate] < 384 * 384) {
            arg0->unk15C = target;
            func_800E2CCC(arg0);
            return 1;
        }

        if (func_800DB370(arg0, target, 320, 1)) {
            return 1;
        }

        if (func_800DB74C(arg0, target)) {
            return 1;
        }
    }

    if (valid) {
        if (old) {
            if (func_800E45D4(128) < 128u) {
                arg0->unk18 = 1;
            }

            func_800D8260(arg0, 6, 0);
        }

        if (func_800DB61C(arg0, 1)) {
            return 1;
        }
    }

    return func_800DB61C(arg0, 1);
}

int func_800DAA6C(func_800E78F4_t* arg0)
{
    if (arg0->unkE) {
        if (!func_800DB61C(arg0, 1)) {
            func_800DB5B0(arg0);
        }

        return 1;
    }

    if (!func_800DA1D4(arg0)) {
        func_800DB5FC(arg0);
    }

    return 1;
}

int func_800DAAD8(func_800E78F4_t* arg0)
{
    func_800DCAA0_t* entry = arg0->unk430[0];
    int id;
    vs_battle_actor* actor;

    if (!arg0->unk131 && func_800DA4BC(arg0, entry)) {
        return 1;
    }

    id = arg0->unk16;

    if (id < 16) {
        if (func_800DB370(arg0, id, 384, 0)) {
            if (arg0->unkE9 == 1 && arg0->unk12E != 7) {
                arg0->unk15C = entry->unkC_0;
                func_800E678C(arg0);
                func_800E2CCC(arg0);
            }

            return 1;
        }

        if (func_800DB74C(arg0, id)) {
            return 1;
        }
    }

    for (actor = vs_battle_actors[0]; actor != NULL; actor = actor->next) {
        if (arg0->unk1A4[actor->id].unk0_6 != 3 && arg0->unk1A4[actor->id].unk0_20) {
            arg0->unk1A4[actor->id].unk0_6 = 3;

            if (func_800DB61C(arg0, 0)) {
                arg0->unk1A4[actor->id].unk0_6 = arg0->unk1A4[actor->id].unk0_28;
                return 1;
            }

            arg0->unk1A4[actor->id].unk0_6 = arg0->unk1A4[actor->id].unk0_28;
        }
    }

    return 0;
}

int func_800DAC80(func_800E78F4_t* arg0, func_800DCAA0_t* arg1)
{
    if (!func_800DBD80(arg0, arg1)) {
        return 0;
    }

    func_800D836C(arg0);

    if (func_800D826C(arg0)) {
        D_800F4538_t* actor;

        arg0->unk22C = arg1;
        D_800F58E0 = 1;
        actor = D_800F4538[arg1->unkC_0];

        if (actor != NULL && actor->unk0.unkA_3) {
            arg1->unkC_4 = func_800E45D4(2);
            arg1->unkC_7 = 217;
        }

        func_800DEEFC(arg0, 15);

        if (func_800DBC60(arg0, arg1)) {
            arg0->unk13F = arg0->unk13 == 0 ? D_800F58BC->unk8 : 50;
        }

        return 1;
    }

    return 0;
}

int func_800DAD9C(func_800E78F4_t* arg0)
{
    int i;
    int j;
    func_800DCAA0_t* entry;

    for (i = 0; i < arg0->unk470; ++i) {
        entry = arg0->unk430[i];

        if (func_800DAC80(arg0, entry)) {
            return 1;
        }
    }

    entry = &arg0->unk140;

    if (entry->unk4_5) {
        for (j = 0; j < 4; ++j) {
            vs_battle_actor* actor = D_800F58BC->unk28[j];

            if (actor != NULL) {
                D_800F45E0_t* model;

                entry->unkC_0 = actor->id;
                model = D_800F45E0[actor->id];

                if (model->unk12 && model->unk1A == 0 && func_800DAC80(arg0, entry)) {
                    return 1;
                }
            }
        }
    }

    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DAED0);

int func_800DB0BC(func_800E78F4_t* arg0)
{
    if (D_800F5920 != NULL) {
        return 0;
    }

    if ((*(u_int*)&arg0->unk34 & 0xFF00FF) == (arg0->unk38 & 0xFF00FF)) {
        arg0->unk2 = 1;

        if (!arg0->unkFA) {
            u_char directions[4];
            vs_battle_movementPosition probe;
            u_int angle = ratan2(arg0->unk4C.vx - arg0->unk168.x * 128 - 64,
                arg0->unk4C.vz - arg0->unk168.z * 128 - 64);
            u_int quadrant;
            int first;
            int second;
            int i;

            angle &= 0xFFF;
            first = (angle >> 9) & 7;
            second = ((angle >> 9) + 2) & 7;
            quadrant = angle / (ONE / 4);

            if (((angle & 0x3FF) > ONE / 8 ? ((quadrant + 1) & 3) * 2 : quadrant * 2)
                == first) {
                directions[0] = first;
                directions[1] = second;
            } else {
                directions[0] = second;
                directions[1] = first;
            }

            if (func_800E45D4(2)) {
                directions[2] = (first + 4) & 7;
                directions[3] = (second + 4) & 7;
            } else {
                directions[2] = (second + 4) & 7;
                directions[3] = (first + 4) & 7;
            }

            *(u_int*)arg0->unk118 = *(u_int*)directions;
            *(u_int*)&probe = 0;

            for (i = 0; i < 4; ++i) {
                probe.x = arg0->unk34.x + ((D_800F16EC_t*)0x1F8003EC)[directions[i]].dx;
                probe.z = arg0->unk34.z + ((D_800F16EC_t*)0x1F8003EC)[directions[i]].dz;

                if (func_800D954C(arg0, probe) > 0) {
                    arg0->unkFA = i;
                    break;
                }
            }

            ++arg0->unkFA;
        }

        if (arg0->unkFA >= 5) {
            func_800E4CE8(arg0);
            arg0->unk1C = 0;
            arg0->unkFA = 0;
            return 0;
        }

        arg0->unk168.x =
            arg0->unk34.x + ((D_800F16EC_t*)0x1F8003EC)[arg0->unk118[arg0->unkFA - 1]].dx;
        arg0->unk168.z =
            arg0->unk34.z + ((D_800F16EC_t*)0x1F8003EC)[arg0->unk118[arg0->unkFA - 1]].dz;
        arg0->unk15C = arg0->unkFB;

        if (func_800D954C(arg0, arg0->unk168) > 0) {
            func_800E50A0(arg0, 0, 0);
        } else {
            ++arg0->unkFA;
        }

        return 1;
    }

    arg0->unkFA = 0;
    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DB370);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DB4AC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DB5B0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DB5B8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DB5DC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DB5FC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DB61C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DB74C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DB7B4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DB820);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DB8AC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DB93C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DBB2C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DBC60);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DBCB4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DBCEC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DBD80);

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

void func_800DBFE4(func_800E78F4_t* arg0)
{
    if (arg0->unk8E != 0 && ++arg0->unk8E != 0) {
        int frame;

        if (arg0->unk8E < 8) {
            frame = 0;
        } else if (arg0->unk8E < 16) {
            frame = 1;
        } else if (arg0->unk8E < 24) {
            frame = 2;
        } else {
            frame = 3;
        }

        if (arg0->unk8E <= 120) {
            func_800D820C(arg0->unk88, frame + 1);
            return;
        }

        func_800E4C8C(arg0);
        func_800D82CC(arg0);
    }

    if (arg0->unk9A != 0) {
        if (--arg0->unk9A != 0) {
            func_800D820C(arg0->unk88, 4);
        } else {
            func_800D820C(arg0->unk88, 0);
        }
    }

    if (arg0->unk98 != 0) {
        --arg0->unk98;
    }
}

void func_800DC0D0(void)
{
    func_800E78F4_t* state;
    int changed = 0;

    if (D_800F58BC->unk1C == NULL) {
        return;
    }

    state = D_800F58BC->unk1C;

    do {
        func_800DEB10_t2* data = state->unk54;

        if (state->unk1A4[0].unk0_6 != 2) {
            if (state->unk12F == 0) {
                state->unk130 = 1;
                data->unkB_2 = 1;
                changed = 1;
            } else if (state->unk12F == 16) {
                state->unk130 = -1;
                data->unkB_2 = 2;
                changed = 1;
            }

            state->unk12F += state->unk130;

            if (changed) {
                break;
            }
        }

        state = state->unk1A0;
    } while (state != NULL);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DC19C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DC210);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DC284);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DC2E0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DC30C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DC344);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DC3CC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DC3E8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DC424);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DC484);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DC48C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DC4F0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DC574);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DC638);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DC784);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DC810);

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

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", D_80069B68);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", D_80069BBC);

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

    if (vs_battle_getStateFlag(0xA6) == 4 && self->unk9 == 24 && self->unkC == 4) {
        vs_battle_setStateFlag(0xA6, 5);
    }

    if (D_800F5920->unk16 && self->subType - 172 < 2u) {
        D_800F5920->unk17 = arg0->unk470;
        arg0->unk470 = 0;
    }
}

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
                if (actor->unk8 & 0x20) {
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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DEEFC);

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
    func_8008D2C0_t sp10[4];
    func_8008D2C0_t* m;
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
            if (D_800F5910[i * 2 + 1].unk0_0 == m->unk0 >> 7
                && D_800F5910[i * 2 + 1].unk0_5 == m->unk2 >> 7) {
                return i;
            }
        }
    }
    return -1;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DFBCC);

int func_800E02B4(func_800E78F4_t* arg0, int arg1, int arg2)
{
    func_8008D2C0_t points[4];
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
        dx = points[i].unk0 - x;
        dy = points[i].unk1 - y;
        dz = points[i].unk2 - z;

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
        func_800E1238_t* model = other->unk58;

        if (other->unk88 == arg0->unk88 || other->unk88 == 0) {
            continue;
        }

        dx = model->unk1C.vx - x;
        dy = model->unk1C.vy - y;
        dz = model->unk1C.vz - z;

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
            if (!(arg0->unk58->unk8_21 << 21)) {
                callback(arg0, arg1);
                return 1;
            }
        } else if (D_800F58BC->unk14
                   && func_800E42E0(arg0->unk34) + arg0->unkBE < D_800F58BC->unk14) {
            if (arg0->unk58->unk8_21 << 21) {
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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E0A68);

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

    if (!(arg0->unk58->unk8_21 << 21)) {
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

void func_800E153C(func_800E78F4_t* arg0)
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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E1764);

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
    func_800DEB10_t2* actor = arg0->unk54;
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
    check = (arg0->unk58->unk8_21 << 21) ? func_800E0678 : D_800D9B6C;

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
        }
    }

    func_800E2CCC(arg0);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E23AC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E24EC);

int func_800E2B2C(func_800E78F4_t* arg0, int arg1)
{
    func_800E1238_t* model = arg0->unk58;
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
        goto failed;
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

    if (((model->unk26 + model->unk14) & 0xFFF) == (arg0->unk18A & 0xFFF)) {
        if (!arg0->unk1A4[arg1].unk0_5) {
            if (func_800E4180(arg0, 128, 1, 6)) {
                return 1;
            }

            arg0->unk10C = 0;
            goto failed;
        }

        arg0->unk10C = 1;
        arg0->unk18A = angle & 0xFFF;
        arg0->unk108 = arg0->unk168;
    }

    func_800DEEFC(arg0, 4);
    return 1;

failed:
    return 0;
}

void func_800E2CCC(func_800E78F4_t* arg0)
{
    func_800E1238_t* model = arg0->unk58;
    int direction;

    if ((model->unk8_21 << 21) && arg0->unk228++ > 120 && (arg0->unk15E & 6)
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
        u_int angle = model->unk26 + model->unk14;
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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E2F5C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E3600);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E3BC8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E3CDC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E3D5C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E3DDC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4180);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4288);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E42D4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E42E0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E42EC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4308);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4318);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4320);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4358);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E437C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4478);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E44E8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E45B4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E45D4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E45F4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4604);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4624);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4660);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4690);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4764);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E47E4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E48A8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E48F8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4904);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E49D8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4B10);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4B18);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4B2C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4B70);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4BB8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4BD8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4BE0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4C1C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4C28);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4C64);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4C8C);

void func_800E4CE8(func_800E78F4_t* arg0) { arg0->unk38 = -1; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4CF4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4DF8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4F14);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4FB0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4FE0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E50A0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E511C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E5154);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E5158);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E51C8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E5240);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E527C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E5308);

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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E5A9C);

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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E6178);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E65DC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E6694);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E6700);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E6764);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E678C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E6828);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E685C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E6898);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E68A0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E68EC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E6974);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E6A6C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E6B24);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E6B4C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E6BA0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E6C34);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E6EAC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E6EB0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E6F1C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E6F9C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E71DC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E72D0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E7370);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E7454);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E75EC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E7608);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E7660);

int func_800E7698(func_800E78F4_t* arg0)
{
    func_800E1238_t* model = arg0->unk58;
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

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", D_80069C18);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", D_80069C1C);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", D_80069C3C);
