#include "common.h"
#include "5BF94.h"
#include "6E644.h"
#include "src/SLUS_010.40/32154.h"
#include "src/SLUS_010.40/main.h"
#include "src/SLUS_010.40/overlay.h"
#include "build/src/include/lbas.h"
#include <abs.h>

struct func_800D4910_t;

typedef struct {
    char unk0[0x38];
    int unk38;
    char unk3C[0xEE];
    u_char unk12A;
    char unk12B[0xD];
    u_short unk138;
} func_800D8260_t;

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
    int unk0;
    u_int unk4;
} func_800E78F4_t2;

typedef struct {
    char unk0[0x430];
    func_800E78F4_t2* unk430;
    char unk434[0x3C];
    int unk470;
} func_800E78F4_t;

typedef struct {
    char unk0[0x18];
    u_short unk18;
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
    char unk0[0x88];
    u_char unk88;
} func_800DCAA0_t1;

typedef struct {
    int unk0;
    u_int unk4_0 : 5;
    u_int unk4_5 : 8;
    u_int unk4_13 : 19;
    int unk8;
    u_int unkC_0 : 4;
    u_int unkC_4 : 3;
    u_int unkC_7 : 12;
    u_int unkC_19 : 13;
} func_800DCAA0_t;

typedef struct {
    char unk0[4];
    u_char unk4;
    char unk5[0x3F];
    int unk44;
} func_800DEEA4_t;

typedef struct {
    char unk0[0x16];
    signed char unk16;
    char unk17[0x83];
    short unk9A;
} func_800DEEA4_t2;

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

void func_800D5260(VECTOR*);
void func_800D5294(int*);
void func_800D7890(int arg0);
void _parsePfileBlock1(pFileBlock1* arg0);
void _parsePfileBlock12(void*);
void _parsePfileBlock13(void*);
void func_800D8038(int);
void vs_battle_setPlgLoadState(int);
void func_800D8060(p_file_t* arg0);
int func_8008631C(int, int, int, int, void*);
int func_800863A4(int, int, int, int, SVECTOR*, SVECTOR*, void*);
int func_8008D2C0(func_8008D2C0_t*);
short func_8008DC7C(int, int);
int func_800DBCB4(func_800E78F4_t*, func_800E78F4_t2*);
void func_800DC810(func_800DEEA4_t*);
void func_800DC888(int);
void func_800DEEFC(func_800E0850_t*, int);
int func_800E0678(func_800E0850_t*, int);
int func_800E0918(func_800E0850_t*, int, int);
void func_800E2CCC(func_800E0850_t*);
void func_800E3600(func_800E0850_t*, int, int);
int func_800E42EC(int, int);
int func_800E4764(func_800E0850_t*, int*, int*);
void func_800E4B18(func_800E0850_t*);
void func_800E5EC0(int, int, int);
void func_800E678C(func_800E0850_t*);

extern p_file_t D_800EC4BC;
extern D_800F16EC_t D_800F16EC[8];
extern int D_800F5330[];
extern char D_800F53C0[];
extern int D_800F5630;
extern D_800F5638_t D_800F5638;
extern u_int D_800F5680;
extern vs_main_CdQueueSlot* D_800F568C;
extern u_int _plgLoadState;
extern _loadFileContext _plgLoadContext;
extern u_long* D_800F56A0;
extern int _plgEntryPointCount;
extern effectExec D_800F56A8[];
extern func_800CF0E8_t* D_800F5798;
extern D_800F569C_t D_800F57A0;
extern int D_800F5874;
extern func_800DEEA4_t2* D_800F5878[];
extern u_short (*D_800F58B8)[32];
extern D_800F58BC_t* D_800F58BC;
extern u_short (*D_800F58D0)[32];
extern void* D_800F5900;
extern D_800F5910_t* D_800F5910;

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D6E44);

void func_800D7814(void)
{
    D_800F568C = NULL;
    vs_battle_pfileBuf = NULL;
    D_800F56A0 = NULL;
    D_800F5874 = 0;
    D_800F5684 = 0;
    D_800F57A0.transparencyCurveBlock = NULL;
    D_800F57A0.unkD0 = D_800F53C0;
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

void _parsepFileTransparencyCurveBlock(pFileTransparencyCurveBlock* block)
{
    u_char* p;
    int i;

    D_800F569C->transparencyCurveBlock = block;
    p = (u_char*)block + block->dataOffset;

    for (i = 0; i < block->count; i++) {
        D_800F569C->transparencyCurves[i] = p;
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
    D_800F569C->block1Data = (void*)block + block->dataOffset;

    for (i = 0; i < D_800F569C->block1TableCount; ++i) {
        D_800F569C->block1Tables[i] = (void*)block + block->tableOffsets[i];
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
            _parsepFileTransparencyCurveBlock((pFileTransparencyCurveBlock*)arg0->data);
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

void func_800D8260(func_800D8260_t* arg0, int arg1, int arg2)
{
    arg0->unk138 = arg1;
    arg0->unk12A = arg2;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D826C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D8280);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D82A8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D82CC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D836C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D8400);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D85D8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D87E8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D954C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D96C8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D98E8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D9DD8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D9E18);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DA1D4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DA4BC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DAC80);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DAD9C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DB0BC);

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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DBF00);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DBFE4);

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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DC888);

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
        func_800DC888(arg1);
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DCBD8);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", D_80069B68);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", D_80069BBC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DCC94);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DD604);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DD918);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DE030);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DE3E4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DEB10);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DEC88);

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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E02B4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E0678);

int func_800E0850(func_800E0850_t* arg0, u_int arg1)
{
    int min = 0;
    int count = 1;

    if (arg1 & 0x3FF) {
        count = 3;
    }
    arg1 = (arg1 >> 9) & 6;
    while (--count != -1) {
        if (func_800E0678(arg0, arg1) != 0) {
            int h = func_800E42EC(arg0->unk34 + ((D_800F16EC_t*)0x1F8003EC)[arg1].dx,
                arg0->unk36 + ((D_800F16EC_t*)0x1F8003EC)[arg1].dz);
            if (h < min) {
                min = h;
            }
        }
        arg1 = (arg1 + 1) & 7;
    }
    return min;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E0918);

void func_800E1238(func_800E0850_t* arg0, int arg1)
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

    if (func_800E0850(arg0, arg1) + arg0->unkBE < arg0->unk4E) {
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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E1388);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E153C);

u_char func_800E1850(u_char arg0, u_int arg1, int arg2)
{
    int x = arg1 & 0xFF;
    int z = (arg1 >> 16) & 0xFF;
    int i;

    for (i = 0; i < 8; ++i) {
        if ((arg0 >> i) & 1) {
            if (func_800E42EC(x + ((D_800F16EC_t*)0x1F8003EC)[i].dx,
                    z + ((D_800F16EC_t*)0x1F8003EC)[i].dz)
                > arg2) {
                arg0 &= ~(1 << i);
            }
        }
    }
    return arg0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E1908);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E1BB8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E24EC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E2B2C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E2CCC);

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

void func_800E4CE8(func_800D8260_t* arg0) { arg0->unk38 = -1; }

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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E5710);

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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E7698);

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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E7960);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E7F8C);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", D_80069C18);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", D_80069C1C);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", D_80069C3C);
