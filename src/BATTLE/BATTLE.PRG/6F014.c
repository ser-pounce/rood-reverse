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
    char unk0[0x88];
    u_char unk88;
} func_800DCAA0_t1;

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
    u_char unk0;
    char unk1;
    u_char unk2;
    char unk3[0x3D];
    int unk40;
} func_800DEB10_t;

typedef struct {
    u_short unk0;
    char unk2[2];
    u_char unk4;
    char unk5[0x3F];
    int unk44;
    char unk48[2];
    u_short unk4A;
    func_800DEB10_t unk4C[0];
} func_800DEEA4_t;

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
void func_800D82CC(func_800E78F4_t*);
void func_800D836C(func_800E78F4_t*);
int func_8008631C(int, int, int, int, void*);
int func_800863A4(int, int, int, int, SVECTOR*, SVECTOR*, void*);
int func_8008D2C0(func_8008D2C0_t*);
short func_8008DC7C(int, int);
int func_800DBCB4(func_800E78F4_t*, func_800E78F4_t2*);
void func_800DC810(func_800DEEA4_t*);
struct actionStatSnapshot;
void func_800DC888(struct actionStatSnapshot*);
void func_800DEEFC(func_800E0850_t*, int);
struct directionalCacheState;
int func_800E0678(struct directionalCacheState*, int);
struct movementCheckState;
int func_800E0918(struct movementCheckState*, int, int);
typedef struct movementRecoveryState movementRecoveryState;
void func_800E2CCC(movementRecoveryState*);
void func_800E3600(func_800E0850_t*, int, int);
int func_800E42EC(int, int);
int func_800E4764(func_800E0850_t*, int*, int*);
void func_800E4B18(func_800E0850_t*);
void func_800E4C8C(func_800DEEA4_t2*);
void func_800E4CE8(func_800DEEA4_t2* arg0);
void func_800E5EC0(int, int, int);
void func_800E678C(func_800E0850_t*);
typedef struct radialMotionState radialMotionState;
int func_800E7698(radialMotionState*);
typedef struct trackingMotionState trackingMotionState;
void func_800E7960(trackingMotionState*);

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
extern func_800DEEA4_t* D_800F5900;
extern D_800F5910_t* D_800F5910;
extern int D_800F5918;
extern int D_800F591C;
extern D_800F5920_t* D_800F5920;

void func_800D7814(void)
{
    D_800F568C = NULL;
    vs_battle_pfileBuf = NULL;
    D_800F56A0 = NULL;
    D_800F5874 = 0;
    D_800F5684 = 0;
    D_800F57A0.curveBlock = NULL;
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
