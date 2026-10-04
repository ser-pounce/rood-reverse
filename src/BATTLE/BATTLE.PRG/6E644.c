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
    char unkA[2];
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

typedef struct {
    char unk0[0x4E];
    u_short unk4E;
    char unk50[4];
    func_800DEB10_t2* unk54;
    char unk58[4];
    vs_battle_actor2* unk5C;
    char unk60[0x3D0];
    func_800E78F4_t2* unk430;
    char unk434[0x3C];
    int unk470;
} func_800E78F4_t;

typedef struct {
    u_char maxX, maxZ, minX, minZ;
    char unk4[0x14];
    u_short unk18;
    char unk1A[2];
    void* unk1C;
    char unk20[4];
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
    u_int unkC_19 : 13;
} func_800DCAA0_t;

typedef struct {
    u_char unk0;
    char unk1[0x3F];
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
void func_800DC888(int);
void func_800DEEFC(func_800E0850_t*, int);
int func_800E0678(func_800E0850_t*, int);
int func_800E0918(func_800E0850_t*, int, int);
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
extern void* D_800F5900;
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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D820C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D821C);

void func_800D8260(func_800DEEA4_t2* arg0, int arg1, int arg2)
{
    arg0->unk138 = arg1;
    arg0->unk12A = arg2;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D826C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D8280);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D82A8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D82CC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D836C);

typedef union {
    unsigned int raw;
    struct {
        unsigned int x : 8, y : 8, z : 8, status : 8;
    } p;
} vs_battle_movementPosition;
typedef struct {
    unsigned char pad[7];
    unsigned char disabled;
    unsigned char rest[0x2C];
    vs_battle_movementPosition position;
    char unk38[0x130];
    vs_battle_movementPosition destination;
} func_800D8400_t;
int func_800D96C8(func_800D8400_t*, unsigned int, unsigned int, int);
int func_800D954C(func_800D8400_t*, unsigned int);
unsigned int func_800DB93C(func_800D8400_t*, unsigned int, int, unsigned int);
unsigned int func_800D8400(
    func_800D8400_t* state, int first, int second, unsigned int direction)
{
    vs_battle_movementPosition dest, source;
    int count, i, result;
    unsigned int directions, quadrant;
    int nearest;
    if (state->disabled)
        return 0;
    dest.p.status = 1;
    source = state->position;
    if (first == second) {
        directions = direction;
        count = 1;
    } else {
        quadrant = (direction & 0xFFF) >> 10;
        if ((direction & 0x3FF) > 512)
            nearest = ((quadrant + 1) & 3) * 2;
        else
            nearest = quadrant * 2;
        direction = nearest;
        if (direction != first)
            directions = (first << 16) | direction;
        else
            directions = (second << 16) | direction;
        count = 2;
    }
    for (i = 0; i < count; i++) {
        direction = (directions >> (i * 16)) & 0xFFFF;
        dest.p.x = source.p.x + ((D_800F16EC_t*)0x1F8003EC)[direction].dx;
        dest.p.z = source.p.z + ((D_800F16EC_t*)0x1F8003EC)[direction].dz;
        result = func_800D96C8(state, source.raw, dest.raw, direction);
        if (result > 0) {
            result = func_800D954C(state, dest.raw);
            if (result < 0)
                goto blocked;
            if (result)
                goto done;
            return 0;
        }
        if (result < 0)
            goto blocked;
        dest.raw = func_800DB93C(state, dest.raw, direction, source.raw);
        if (dest.p.status == 1)
            goto done;
        if (dest.p.status)
            goto blocked;
    }
    return 0;
blocked:
    dest.p.status = 2;
done:
    return dest.raw & 0xFFFF00FF;
}

typedef struct {
    int pad0;
    unsigned int row : 3, column : 2, pad5 : 8, threshold : 16, pad29 : 3;
    unsigned int distanceSquared;
    unsigned int targetId : 4, padC4 : 15, weight : 8, padC27 : 5;
    unsigned int low : 1, flag1 : 1, pad2 : 4, range : 16, high : 10;
} actionCandidateEntry;
typedef struct {
    unsigned char flags, pad[3];
} actionCandidateTarget;
typedef struct {
    char pad0[0x131];
    unsigned char status;
    char pad132[0x72];
    actionCandidateTarget targets[16];
    unsigned int targetDistancesSquared[16];
    char pad224[0x20C];
    actionCandidateEntry* entries[16];
    int count;
} actionCandidateState;
int func_800E4CF4(actionCandidateState*, actionCandidateEntry*, int);
int func_800E4DF8(actionCandidateState*, int, int);
void func_800D9DD8(actionCandidateState*);
int func_800D85D8(actionCandidateState* state)
{
    int i, changed = 0;
    unsigned char value;
    actionCandidateEntry* entry;
    actionCandidateEntry* candidate;
    vs_battle_actor* actor;
    for (i = 0; i < state->count; i++) {
        entry = state->entries[i];
        if (entry->weight && entry->threshold <= D_800F58BC->unk18) {
            if (!func_800E4CF4(state, entry, entry->targetId)
                || !func_800E4DF8(state, entry->row, entry->column))
                entry->weight = 0;
        }
    }
    if (state->count > 0 && !state->entries[0]->weight) {
        changed = 1;
        for (i = 1; i < state->count; i++) {
            candidate = state->entries[i];
            if (candidate->weight) {
                state->entries[0] = candidate;
                func_800D9DD8(state);
                goto done;
            }
        }
        state->count = 0;
    }
done:
    if (!state->count) {
        actor = vs_battle_actors[0];
        while (actor) {
            if ((state->targets[actor->id].flags >> 6) == 3)
                break;
            actor = actor->next;
        }
        value = 2;
        if (!actor)
            value = 3;
    } else
        value = D_800F58BC->unk18 + 30 < state->entries[0]->threshold;
    state->status = value;
    return changed;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D87E8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D954C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D96C8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D98E8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D9DD8);

typedef union {
    unsigned int raw;
    unsigned char bytes[4];
} candidateMovementWord;
typedef struct candidateMovementState {
    char pad0[1];
    unsigned char f1;
    char pad2[74];
    short position[3];
    char pad52[48];
    short height;
    char pad84[47];
    unsigned char maxRange;
    char padB4[122];
    unsigned char mode;
    char pad12F[5];
    candidateMovementWord destination;
    char pad138[36];
    unsigned char target;
    char pad15D[1];
    unsigned short flags;
    char pad160[8];
    candidateMovementWord next;
    char pad16C[56];
    candidateMovementWord targets[16];
    unsigned int distances[16];
    char pad224[588];
    int count;
} candidateMovementState;
int func_800DB8AC(candidateMovementState*, actionCandidateEntry*);
int func_800E42D4(int, int);
int func_800E4624(short*, short*, int, int);
unsigned int func_800E4660(int, int, int);
void func_800DB5B8(candidateMovementState*, unsigned int, int);
void func_800DB5DC(candidateMovementState*, unsigned int, int);
int func_800DB61C(candidateMovementState*, int);
int func_800DB370(actionCandidateState*, int, int, int);
int func_800DB74C(actionCandidateState*, int);
int func_800D9E18(candidateMovementState* state, actionCandidateEntry* entry)
{
    int id, flag;
    unsigned int distance, limit;
    int active = 0;
    short point[3];
    int x, z, y;
    if (!state->count)
        return 0;
    id = entry->targetId;
    if (id == 16 || !((candidateMovementState**)0x1F80037C)[id])
        return 0;
    switch (state->mode) {
    case 1:
    normal:
        limit = 0x1F80;
        if (!(state->flags & 8))
            limit = vs_gte_rsqrt(entry->distanceSquared) + (state->maxRange << 5);
        limit = limit * limit;
        if ((state->targets[id].bytes[0] >> 6) == 2) {
            distance = entry->distanceSquared;
            flag = 0;
            active = 1;
        } else {
            if (func_800DB8AC(state, entry)) {
                distance = entry->distanceSquared;
                active = 1;
            } else {
                distance = limit;
                {
                    unsigned int minimum = 0x64000;
                    if (distance < minimum)
                        distance = minimum;
                }
            }
            flag = 1;
        }
        distance = vs_gte_rsqrt(distance);
        if (active) {
            D_800F58BC->unk24++;
            if (state->distances[id] < limit && (state->targets[entry->targetId].raw & 1))
                func_800D836C((void*)state);
        }
    move:
        if (func_800DB370((void*)state, id, distance, flag))
            return 1;
        return func_800DB74C((void*)state, id) != 0;
    case 2:
        if (!func_800DBCB4((void*)state, (void*)entry))
            goto normal;
        if (entry->flag1) {
            point[0] = (state->destination.bytes[0] << 7) + 64;
            point[2] = (state->destination.bytes[2] << 7) + 64;
            point[1] = func_800E42D4(point[0], point[2]);
            distance =
                vs_gte_rsqrt(func_800E4624(point, (short*)&D_800F4538[id]->unk0.position,
                    state->height, ((candidateMovementState*)D_800F5878[id])->height));
            distance =
                (int)distance < vs_gte_rsqrt(entry->distanceSquared) - entry->range;
            if (distance)
                goto normal;
        }
        x = (state->next.bytes[0] << 7) + 64;
        z = (state->next.bytes[2] << 7) + 64;
        y = func_800E42D4(x, z);
        if (func_800E4660(
                x - state->position[0], y - state->position[1], z - state->position[2])
            <= 0xFFFF) {
            state->target = id;
            func_800DB5B8(state, state->destination.raw, 2);
        } else {
            state->f1 = 1;
            func_800DB5DC(state, state->destination.raw, 256);
        }
        return 1;
    case 4:
        return func_800DB61C(state, 0);
    case 7:
        func_800D82CC((void*)state);
        id = 0;
        flag = 1;
        if ((state->targets[id].bytes[0] >> 6) == 3) {
            distance = 640;
            goto move;
        }
        break;
    }
    return 0;
}

int func_800DB370(actionCandidateState*, int, int, int);
int func_800DB74C(actionCandidateState*, int);
int func_800DA1D4(actionCandidateState* state)
{
    int id = -1, flag, distance, i;
    unsigned int nearest = -1;
    actionCandidateEntry* entry;
    vs_battle_actor* actor;
    switch (state->status) {
    case 0:
        entry = state->entries[0];
        id = entry->targetId;
        if (func_800D9E18((void*)state, entry))
            return 1;
        for (i = 1; i < state->count; i++) {
            entry = state->entries[i];
            if (entry->threshold < D_800F58BC->unk18 && entry->targetId != id)
                return func_800D9E18((void*)state, entry);
        }
        return 0;
    case 1:
        func_800D82CC((void*)state);
        if ((state->targets[0].flags >> 6) == 3) {
            if (func_800DB370(state, 0, 640, 1))
                return 1;
            if (func_800DB74C(state, 0))
                return 1;
        }
        id = state->entries[0]->targetId;
        if ((state->targets[id].flags >> 6) == 3) {
            flag = 1;
            distance = 640;
        } else {
            if (state->count < 2)
                return 0;
            flag = 0;
            distance = vs_gte_rsqrt(state->entries[1]->distanceSquared);
        }
        if (func_800DB370(state, id, distance, flag))
            return 1;
        if (func_800DB74C(state, id))
            return 1;
    case 2:
        func_800D82CC((void*)state);
        if ((state->targets[0].flags >> 6) == 3) {
            if (func_800DB370(state, 0, 640, 1))
                return 1;
            if (func_800DB74C(state, 0))
                return 1;
        }
        for (actor = vs_battle_actors[0]; actor; actor = actor->next) {
            int candidate = actor->id;
            if ((state->targets[candidate].flags >> 6) == 3) {
                unsigned int d = state->targetDistancesSquared[candidate];
                if (d < nearest) {
                    nearest = d;
                    id = candidate;
                }
            }
        }
        if (id >= 0) {
            if (func_800DB370(state, id, 640, 1))
                return 1;
            if (func_800DB74C(state, id))
                return 1;
        }
        break;
    }
    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DA4BC);

typedef struct {
    char prefix[0x13];
    u_char kind;
    char gap[0x12B];
    u_char cooldown;
    char gap2[0xEC];
    func_800DCAA0_t* action;
} actionSetupContext;
int func_800DBD80(actionSetupContext*, func_800DCAA0_t*);
int func_800D826C(actionSetupContext*);
int func_800DBC60(actionSetupContext*, func_800DCAA0_t*);
int func_800E45D4(int);
extern int D_800F58E0;

int func_800DAC80(actionSetupContext* context, func_800DCAA0_t* action)
{
    D_800F4538_t* actor;
    if (!func_800DBD80(context, action))
        return 0;
    func_800D836C((void*)context);
    if (func_800D826C(context)) {
        context->action = action;
        D_800F58E0 = 1;
        actor = D_800F4538[action->unkC_0];
        if (actor != NULL && (*(u_int*)((char*)actor + 8) & 0x180000)) {
            action->unkC_4 = func_800E45D4(2);
            action->unkC_7 = 217;
        }
        func_800DEEFC((void*)context, 15);
        if (func_800DBC60(context, action)) {
            if (context->kind == 0)
                context->cooldown = *((u_char*)D_800F58BC + 8);
            else
                context->cooldown = 50;
        }
        return 1;
    }
    return 0;
}

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
        if (state->timer8E < 8)
            value = 0;
        else if (state->timer8E < 16)
            value = 1;
        else if (state->timer8E < 24)
            value = 2;
        else
            value = 3;
        if (state->timer8E <= 120) {
            func_800D820C(state->id, value + 1);
            return;
        }
        func_800E4C8C((void*)state);
        func_800D82CC((void*)state);
    }
    if (state->timer9A) {
        if (--state->timer9A)
            func_800D820C(state->id, 4);
        else
            func_800D820C(state->id, 0);
    }
    if (state->timer98)
        state->timer98--;
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
                if (changed)
                    break;
            }
            state = state->next;
        } while (state);
    }
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

void func_800DEB10(func_800DEEA4_t* arg0)
{
    int i;
    int j;
    func_800DEEA4_t2* entry;
    func_800DEB10_t2* temp_t1;

    if (arg0 == NULL) {
        return;
    }

    if (arg0->unk44 != 0) {
        return;
    }

    entry = D_800F5878[arg0->unk4];
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

                    if ((actor == NULL) || ((0x14 >> actor->unk6C[8].actorId) & 1)) {
                        func_800E4CE8(entry);
                        return;
                    }
                }
            }
        }
    }

    func_800E4C8C(entry);
}

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
        func_800E2CCC((void*)arg0);
        return;
    }

    arg0->unk7 = 1;
    func_800E3600(arg0, arg1, 3);

    if (*(int*)0x1F8003C8 != 5 && *(int*)0x1F8003C8 != 7) {
        func_800E678C(arg0);
        func_800E2CCC((void*)arg0);
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

void func_800E1388(func_800D8400_t* state, vs_battle_movementPosition source, int angle,
    unsigned int distance)
{
    vs_battle_movementPosition dest;
    int i, x, z, heading;
    unsigned int step;
    angle = -angle;
    angle += 0xC00;
    heading = angle & 0xFFF;
    step = distance >> 3;

    for (i = 0; i < 8; i++, distance -= step) {
        x = ((int)(distance * rcos(heading)) >> 12) + 64;
        dest.p.x = (int)(source.p.x * 128 + x) >> 7;
        z = ((int)(distance * rsin(heading)) >> 12) + 64;
        dest.p.z = (int)(source.p.z * 128 + z) >> 7;
        if (func_800D954C(state, dest.raw) > 0)
            break;
    }
    if (dest.p.x < D_800F58BC->minX)
        dest.p.x = D_800F58BC->minX;
    else if (dest.p.x > D_800F58BC->maxX)
        dest.p.x = D_800F58BC->maxX;
    if (dest.p.z < D_800F58BC->minZ)
        dest.p.z = D_800F58BC->minZ;
    else if (dest.p.z > D_800F58BC->maxZ)
        dest.p.z = D_800F58BC->maxZ;
    state->destination = dest;
}

typedef struct {
    char pad0[0xD];
    unsigned char flagD;
    char padE[0x26];
    vs_battle_movementPosition position;
    char pad38[0x10];
    vs_battle_movementPosition previous;
    short x;
    char pad4E[2];
    short z;
    char pad52[0x3A];
    unsigned short attempts;
    char pad8E[0x26];
    int distance;
    char padB8[0xA6];
    unsigned short flags;
    char pad160[8];
    vs_battle_movementPosition destination;
    char pad16C[4];
    vs_battle_movementPosition next;
    char pad174[8];
    int referenceX, referenceZ;
} movementDestinationState;
unsigned int func_800E4660(int, int, int);
unsigned int func_800E45F4(unsigned int, unsigned int);
void func_800E4B2C(movementDestinationState*, int);
void func_800E153C(movementDestinationState* state, int unused)
{
    int distance = state->distance;
    int angle, i;
    vs_battle_movementPosition dest;
    if ((state->position.raw & 0xFF00FF) == (state->destination.raw & 0xFF00FF))
        goto fallback;
    angle = ratan2(state->x - state->destination.p.x * 128 - 64,
        state->z - state->destination.p.z * 128 - 64);
    if (func_800E4660(state->destination.p.x * 128 - state->x + 64, 0,
            state->destination.p.z * 128 - state->z + 64)
        > (unsigned int)(distance * distance))
        func_800E1388((void*)state, state->position, angle, distance);
    if ((state->flags & 6)
        && (state->flagD
            || func_800E45F4(state->destination.raw, state->position.raw) < 16)) {
        if ((int)(state->previous.raw << 8) >= 0)
            state->destination = state->previous;
        func_800E4B2C(state, angle);
        return;
    }
    if (++state->attempts < 6)
        goto fallback;
    dest = state->destination;
    if (func_800D954C((void*)state, dest.raw) > 0)
        goto begin;
    for (i = 0; i < 4; i++) {
        dest.p.x = state->destination.p.x + ((D_800F16EC_t*)0x1F8003EC)[i * 2].dx;
        dest.p.z = state->destination.p.z + ((D_800F16EC_t*)0x1F8003EC)[i * 2].dz;
        if (func_800D954C((void*)state, dest.raw) > 0) {
            state->destination = dest;
            goto begin;
        }
    }
    goto fallback;
begin:
    state->attempts = 0;
    state->next = state->destination;
    func_800DEEFC((void*)state, 13);
    return;
fallback:
    func_800E2CCC((void*)state);
}
void func_800E1764(movementDestinationState* state, int angle)
{
    unsigned int previous[1];
    unsigned int distance;
    int opposite = (angle + 0x800) & 0xFFF;
    func_800E1388((void*)state, state->position, angle, state->distance);
    previous[0] = state->destination.raw;
    func_800E1388((void*)state, state->position, opposite, state->distance);
    distance = func_800E4660(state->destination.p.x * 128 - state->referenceX + 64, 0,
        state->destination.p.z * 128 - state->referenceZ + 64);
    if (distance
        < func_800E4660(((unsigned char*)&previous)[0] * 128 - state->referenceX + 64, 0,
            ((unsigned char*)&previous)[2] * 128 - state->referenceZ + 64))
        state->destination.raw = previous[0];
    func_800E153C(state, angle);
}

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

typedef struct {
    char prefix[0x4C];
    short x;
    short padding4E;
    short z;
    char padding52[6];
    D_800F4538_t* actor;
    char padding5C[0x2C];
    u_char actorId;
    char padding89[0x31];
    u_short delay;
    char paddingBC[0x4C];
    int previousDestination;
    u_char pending;
    char padding10D[0x2D];
    u_short timer;
    char padding13C[0x2C];
    int destination;
    char padding16C[0x10];
    int targetX;
    int targetZ;
    char padding184[4];
    u_int padding188 : 16;
    int angle : 16;
    char padding18C[0x18];
    u_int targetFlags[17];
    char padding1E8[0x299];
    u_char reaction;
} movementDecisionContext;
int func_800E4180(void*, int, int, int);

int func_800E2B2C(movementDecisionContext* context, int targetId)
{
    D_800F4538_t* actor = context->actor;
    int angle;
    if (targetId == context->actorId) {
        func_800DEEFC((void*)context, 0);
        return 1;
    }
    if (context->delay == 0)
        return 0;
    if (context->reaction != 0) {
        if (func_800E4180(context, 128, 3, 6))
            return 1;
        context->pending = 0;
        goto failed;
    }
    angle = ratan2(context->x - context->targetX, context->z - context->targetZ);
    if ((context->destination & 0xFF00FF) != (context->previousDestination & 0xFF00FF)
        && ((context->targetFlags[targetId] >> 5) & 1)) {
        if (context->pending == 0) {
            context->pending = 1;
            context->angle = angle;
            context->previousDestination = context->destination;
        }
    }
    if (context->pending == 0)
        return 0;
    context->timer = context->delay;
    if (((actor->unk0.facing + (short)actor->unk0.unk14) & 0xFFF)
        == (context->angle & 0xFFF)) {
        if (!((context->targetFlags[targetId] >> 5) & 1)) {
            if (func_800E4180(context, 128, 1, 6))
                return 1;
            context->pending = 0;
            goto failed;
        }
        context->pending = 1;
        context->angle = angle & 0xFFF;
        context->previousDestination = context->destination;
    }
    func_800DEEFC((void*)context, 4);
    return 1;
failed:
    return 0;
}

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
    char pad0[0x1C];
    short x, y, z;
} movementActorPosition;
void func_800E4B10(void*);
int func_800E4320(int, int);
void func_800E2CCC(movementRecoveryState* state)
{
    movementRecoveryContext* context = state->context;
    int direction, i, bestHeight, bestDirection, height;
    unsigned int x, z;
    unsigned int angle, quadrant;
    int nx, nz;
    vs_battle_movementPosition source;
    unsigned char* bounds;
    if ((context->flags & 0x200000) && state->counter++ > 120 && (state->flags & 6)
        && (state->flags & 0x30)
        && func_800D954C((void*)state, state->position.raw) > 0) {
        func_800E678C((void*)state);
        func_800E4B10(state);
        return;
    }
    if (state->targetActor != 16) {
        movementActorPosition* actor =
            (movementActorPosition*)D_800F4538[state->targetActor];
        direction = ratan2(state->x - actor->x, state->z - actor->z) & 0xFFF;
        state->facing18A = direction;
        state->timer = state->duration;
        func_800DEEFC((void*)state, 4);
    } else if (state->flag9) {
        direction = ratan2(state->x - state->targetX, state->z - state->targetZ) & 0xFFF;
        state->facing188 = direction;
        state->timer = state->duration;
        func_800DEEFC((void*)state, 3);
    } else {
        bestHeight = (-2147483647 - 1);
        bestDirection = -1;
        source = state->position;
        x = source.raw & 255;
        z = (source.raw >> 16) & 255;
        angle = context->angle26 + context->angle14;
        quadrant = (angle & 0xFFF) >> 10;
        if ((angle & 0x3FF) > 512)
            direction = ((quadrant + 1) & 3) * 2;
        else
            direction = quadrant * 2;
        i = 0;
        bounds = (unsigned char*)0x1F8003DC;
        for (; i < 4; i++) {
            direction = (direction + i * 2) & 7;
            nx = (unsigned char)(x + ((D_800F16EC_t*)0x1F8003EC)[direction].dx);
            nz = (unsigned char)(z + ((D_800F16EC_t*)0x1F8003EC)[direction].dz);
            if (nx < bounds[0] && nz < bounds[1]) {
                height = (func_800E4320(nx, nz) << 17) >> 17;
                if (height > bestHeight) {
                    bestDirection = direction;
                    bestHeight = height;
                }
            }
        }
        if (bestDirection < 0)
            func_800DEEFC((void*)state, 0);
        else {
            state->facing18A = bestDirection << 9;
            state->timer = state->duration;
            func_800DEEFC((void*)state, 4);
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

void func_800E4CE8(func_800DEEA4_t2* arg0) { arg0->unk38 = -1; }

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

typedef union {
    unsigned int raw;
    unsigned char bytes[4];
} actionMetadataWord;
typedef struct {
    actionMetadataWord flags;
    char pad[8];
    unsigned int flagsC;
    char rest[36];
} actionMetadataAction;
typedef struct {
    unsigned short id, pad;
} actionMetadataSlot;
typedef struct {
    char pad[0x8C0];
    actionMetadataSlot slots[6][4];
} actionMetadataStats;
typedef struct {
    unsigned int f0 : 1, f1 : 1, f2 : 1, kind : 2, longRange : 1, special : 1, f7 : 1,
        radius : 16, high : 8;
    unsigned int rangeSquared;
} actionMetadataEntry;
typedef struct {
    char pad0[0x17];
    unsigned char maxActionCost;
    char pad18[0x44];
    actionMetadataStats* stats;
    char pad60[0x28];
    unsigned char id;
    char pad89[0x1A7];
    actionMetadataEntry entries[6][4];
} actionMetadataState;
void func_800E5710(actionMetadataState* state)
{
    int row, column, id, mask;
    actionMetadataAction* action;
    actionMetadataEntry* entry;
    if (!state->id) {
        state->maxActionCost = 1;
        return;
    }
    for (row = 0; row < 6; row++)
        for (column = 0; column < 4; column++) {
            id = state->stats->slots[row][column].id;
            action = (void*)&vs_main_actions[id];
            entry = &state->entries[row][column];
            mask = 1 << ((action->flags.raw >> 20) & 15);
            entry->rangeSquared = func_800E5698((void*)state, id);
            entry->radius =
                func_800E5600((int)state, id, vs_gte_rsqrt(entry->rangeSquared));
            entry->longRange =
                entry->rangeSquared > 0x51000 && !(action->flagsC & 0x20000000);
            if (mask & 0x4198)
                entry->f1 = 1;
            if (mask & 0x154)
                entry->f2 = 1;
            if (mask & 0xA)
                entry->kind = 1;
            else if (mask & 0x40A0)
                entry->kind = 2;
            else if (mask & 0x1954)
                entry->kind = 3;
            entry->special = ((unsigned char*)D_800F58BC)[10]
                          && (action->flags.raw & 0xE0000) != 0x20000
                          && (action->flags.raw & 0xE0000) != 0x60000
                          && (mask & 0x4000) != 0;
            if ((action->flags.raw & 0xE0000) == 0x20000) {
                unsigned int value = action->flags.bytes[3];
                if (state->maxActionCost < value)
                    state->maxActionCost = value;
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

typedef union {
    unsigned int raw;
    unsigned short half[2];
    unsigned char byte[4];
} actorSettingsWord;
typedef struct actorSettingsActor {
    char pad0[26];
    unsigned short kind;
    char pad1C[20];
    actorSettingsWord flags;
    union {
        unsigned int raw;
        struct {
            unsigned int low : 12, mode : 2, high : 18;
        } bits;
    } flags34;
} actorSettingsActor;
typedef struct actorSettingsState {
    char pad0[22];
    unsigned char f16;
    char pad17[2];
    unsigned char f19;
    char pad1A[6];
    unsigned char f20;
    unsigned char f21;
    unsigned char f22;
    unsigned char f23;
    unsigned char f24;
    unsigned char f25;
    unsigned char f26;
    unsigned char f27;
    unsigned char f28;
    unsigned char f29;
    unsigned char f2A;
    unsigned char f2B;
    unsigned char f2C;
    unsigned char f2D;
    unsigned char f2E;
    unsigned char f2F;
    unsigned char f30;
    unsigned char f31;
    unsigned char f32;
    unsigned char f33;
    char pad34[32];
    actorSettingsActor* actor;
    char pad58[16];
    int (*callback)(func_800E78F4_t*);
    char pad6C[40];
    unsigned short collisionRadius;
    char pad96[14];
    unsigned int limit;
    int cosine;
    unsigned int rangeSquared;
    unsigned short fB0;
    unsigned char fB2;
    char padB3[7];
    unsigned short fBA;
    char padBC[12];
    unsigned int fC8;
    unsigned char fCC;
    char padCD[1];
    unsigned char fCE;
    char padCF[5];
    unsigned short fD4;
    unsigned short fD6;
    unsigned char fD8;
    char padD9[40];
    unsigned char f101;
    unsigned char f102;
    char pad103[37];
    unsigned short angle;
    char pad12A[52];
    unsigned short flags;
} actorSettingsState;
typedef struct {
    unsigned short first, second;
    unsigned char third, pad;
} actorSettingsEntry;
extern unsigned int D_80069C1C[];
extern unsigned short D_800F17B8[][2], D_800F17C8[][2];
extern unsigned char D_800F17D8[], D_80069C18[];
extern actorSettingsEntry D_80069C3C[];
extern int D_800F58C0;
extern unsigned short* D_800F58C8;
extern int (*D_800F1790[])(func_800E78F4_t*);
const unsigned char D_80069C08[4] = { 9, 7, 0, 0 };
int func_800E7F8C(func_800E78F4_t*);
void func_800E7660(actorSettingsState*);
void func_800E5998(void);

void func_800E5A9C(actorSettingsState* state, actorSettingsWord* settings)
{
    actorSettingsActor* actor = state->actor;
    unsigned int rangeSquared, step;
    int i, temp;
    rangeSquared = D_80069C1C[(settings->half[1] & 28) >> 2];
    state->rangeSquared = rangeSquared;
    if (rangeSquared > 0x23FFFF)
        rangeSquared = 0x240000;
    state->limit = rangeSquared;
    state->angle = D_800F17B8[settings->half[1] & 3][0];
    state->cosine = rcos((state->angle / 2) * 4096 / 360);
    state->f25 = (settings->raw >> 15) & 1;
    state->f29 = (settings->raw >> 14) & 1;
    state->f24 = (settings->raw >> 13) & 1;
    state->f2D = 0;
    if (D_800F58C0) {
        for (i = 0; i < 8; i++) {
            if (D_800F58C8[i] >> 15)
                break;
        }
        if (i != 8)
            state->f2D = (settings->raw >> 12) & 1;
    }
    state->fB2 = ((settings->raw >> 10) & 3) + 1;
    state->fB0 = D_800F17C8[(settings->raw >> 8) & 3][0];
    step = 128;
    if (state->collisionRadius > 128)
        step = 32;
    state->fBA = (step * D_800F17D8[(settings->raw >> 2) & 3]) >> 4;
    state->f23 = 1;
    state->f21 = settings->byte[3] & 1;
    state->f22 = (settings->raw >> 23) & 1;
    state->f2C = (settings->raw >> 21) & 3;
    state->f2F = (settings->raw >> 28) & 3;
    state->f31 = settings->raw >> 30;
    state->f20 = (settings->raw >> 26) & 1;
    state->fD6 = D_80069C3C[(settings->raw >> 4) & 7].first;
    state->fD4 = D_80069C3C[(settings->raw >> 4) & 7].second;
    state->fD8 = D_80069C3C[(settings->raw >> 4) & 7].third;
    state->f27 = (settings->raw >> 27) & 1;
    state->f30 = (settings->raw >> 25) & 1;
    if (!(state->flags & 0xC0))
        state->f32 = D_80069C18[state->f31];
    state->f33 = settings->byte[0] >> 7;
    temp = actor->flags34.bits.mode;
    state->f26 = temp >> 1;
    temp &= 1;
    state->f2B = temp;
    state->f102 = D_80069C08[(actor->flags34.raw >> 14) & 1];
    state->f101 = (actor->flags.raw >> 14) & 3;
    state->fC8 = actor->flags.half[1] & 63;
    state->fCC = (actor->flags.raw >> 22) & 31;
    state->fCE = actor->flags.raw >> 27;
    if ((unsigned int)(actor->kind - 0xAC) < 2) {
        state->callback = func_800E7F8C;
        state->f19 = 1;
        func_800E7660(state);
    } else
        state->callback = D_800F1790[(actor->flags.raw >> 4) & 31];
    state->f16 = 16;
    func_800E5998();
    func_800E5710((void*)state);
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

extern int D_800F590C;
void func_800A190C(unsigned char, int, void*, int);
int func_800A152C(int, int, int);
typedef union {
    unsigned int raw;
    struct {
        unsigned char b0, b1, b2, b3;
    } bytes;
    struct {
        unsigned int low : 24, f24 : 2, f26 : 2, high : 4;
    } bits;
} actorInitializationFlags;
typedef union {
    unsigned int raw;
    struct {
        unsigned char x, y, z, w;
    } p;
} actorInitializationPoint;
typedef struct actorInitializationStats {
    char pad0[48];
    unsigned char field30;
    unsigned char field31;
    unsigned char field32;
    unsigned char field33;
} actorInitializationStats;
typedef struct actorInitializationModel {
    char pad0[8];
    unsigned int flags;
    char padC[16];
    short position[3];
    char pad22[58];
    actorInitializationPoint tile;
    char pad60[268];
    unsigned int kind;
    char pad170[1228];
    unsigned short radius;
    unsigned short field63E;
} actorInitializationModel;
typedef struct actorInitializationActor {
    char pad0[4];
    int id;
    actorInitializationFlags flags;
    char padC[16];
    unsigned short attributes;
    char pad1E[1];
    unsigned char field1F;
    char pad20[16];
    int field30;
    unsigned int field34;
    int field38;
    actorInitializationStats* stats;
    int field40;
    actorInitializationModel* model;
} actorInitializationActor;
typedef struct actorInitializationState {
    char pad0[42];
    unsigned char field2A;
    char pad2B[9];
    int tile;
    int previous;
    char pad3C[6];
    short options;
    char pad44[16];
    actorInitializationActor* actor;
    actorInitializationModel* model;
    actorInitializationStats* stats;
    short* position;
    unsigned int* tilePointer;
    char pad68[26];
    unsigned short field82;
    char pad84[4];
    unsigned char id;
    unsigned char field89;
    unsigned char field8A;
    char pad8B[7];
    unsigned short radius;
    unsigned short collisionRadius;
    char pad96[6];
    int field9C;
    char padA0[12];
    unsigned int rangeSquared;
    char padB0[3];
    unsigned char maxRange;
    int distance;
    unsigned short fieldB8;
    char padBA[2];
    short fieldBC;
    short fieldBE;
    char padC0[67];
    unsigned char field103;
    char pad104[12];
    int field110;
    char pad114[16];
    unsigned char field124;
    char pad125[8];
    unsigned char field12D;
    char pad12E[14];
    unsigned short stepHeight;
    char pad13E[32];
    unsigned short flags;
    char pad160[16];
    int next;
    char pad174[16];
    int targetY;
    char pad188[12];
    int field194;
    char pad198[140];
    unsigned char field224;
    unsigned char field225;
    unsigned char field226;
    unsigned char field227;
} actorInitializationState;

void func_800E4288(void*, int);
void func_800E6828(actorInitializationState*);

void func_800E7370(actorInitializationState*);
void func_800E72D0(void);

int func_800E6178(actorInitializationActor* actor, int options)
{
    actorInitializationState* state;
    actorInitializationModel* model;
    actorInitializationStats* stats;
    int id = actor->id;
    int i, kind, temp, packed;
    unsigned int radius, range;
    unsigned short result[4];
    if (actor->attributes & 0x15)
        D_800F590C |= 1 << id;
    if (!actor->field40) {
        kind = actor->model->kind & 7;
        if (kind == 2 || kind == 4) {
            for (i = 0; i < 4; i++) {
                if (!((int*)D_800F58BC)[10 + i]) {
                    ((int*)D_800F58BC)[10 + i] = (int)actor;
                    break;
                }
            }
        }
    }
    if (!(actor->attributes & 5))
        return 0;
    state = vs_main_allocHeap(0x484);
    D_800F5878[id] = (void*)state;
    func_800E4288(state, 0x484);
    state->id = id;
    state->actor = actor;
    model = actor->model;
    state->model = model;
    state->stats = actor->stats;
    func_800A190C(state->id, 250, result, 0);
    state->field82 = result[1] - model->position[1];
    radius = model->radius;
    if (!id)
        state->radius = 40;
    else if (radius < 63)
        state->radius = radius;
    else
        state->radius = 62;
    if (radius > 128) {
        state->stepHeight = 32;
        state->collisionRadius = radius;
    } else {
        radius = state->radius;
        state->stepHeight = 128;
        state->collisionRadius = radius;
    }
    state->position = model->position;
    state->tilePointer = &model->tile.raw;
    state->field89 = 0;
    state->field8A = 0;
    state->field103 = 1;
    state->field2A = func_800A152C(id, 2, 3) >= 0;
    stats = actor->stats;
    state->field224 = stats->field30;
    state->field225 = stats->field32;
    state->field226 = stats->field31;
    state->field227 = stats->field33;
    if (state->field224 & 8)
        state->distance = state->field226 << 7;
    else if (state->field225 & 8)
        state->distance = state->field227 << 7;
    func_800E6828(state);
    range = state->field226;
    if (range < state->field227)
        range = state->field227;
    state->maxRange = range;
    packed = actor->field38;
    if (actor->field34 & 1)
        func_800E5A74(&packed, (void*)&actor->field30);
    func_800E5A9C((void*)state, (void*)&packed);
    func_800E7370(state);
    temp = state->distance - 64;
    if (state->rangeSquared < (unsigned int)(temp * temp))
        state->distance = vs_gte_rsqrt(state->rangeSquared) - 64;
    state->fieldBC = -256;
    state->fieldBE = -128;
    state->fieldB8 = model->field63E;
    state->tile = *state->tilePointer;
    state->field110 = *state->tilePointer;
    state->field194 = -1;
    state->field9C = -1;
    state->targetY = state->position[1] << 12;
    if (id) {
        if ((state->flags & 0x30) && (state->flags & 0xC6)
            && (D_800F58B8[model->tile.p.z][model->tile.p.x] & 0x10)
            && !(model->flags & 0x200000)) {
            state->next = model->tile.raw;
            func_800DEEFC((void*)state, 12);
        } else if ((short)options < 0 || !(((int)(short)options << 26) < 0)) {
            if (actor->field1F) {
                func_800DEEFC((void*)state, 1);
                state->field12D = 1;
            }
        }
    }
    actor->flags.bytes.b1 = 0;
    actor->flags.bits.f26 = 0;
    actor->flags.bits.f24 = 0;
    state->field124 = actor->flags.bytes.b1;
    state->previous = -1;
    state->options = (short)options;
    func_800E72D0();
    if (state->id) {
        while (func_800DEC88(0))
            ;
    }
    return (short)options >= 0 && (((int)(short)options << 26) < 0);
}

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
    if (radius < 1024)
        radius += 32;
    if (radius > 1024)
        radius -= 32;
    difference = radius - 1024;
    if (difference < 0)
        difference = -difference;
    if (difference < 32)
        radius = 1024;
    motion->radiusSquared = radius * radius;
    center[0] = 0x7C0000;
    difference = motion->height - 160;
    if (difference < 0)
        difference = -difference;
    if (difference < 16)
        motion->height = 160;
    else if (motion->height < 160)
        motion->height += 12;
    else
        motion->height -= 12;
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
    if (D_800F5918 >= 0)
        sign = 1;
    cosCurrent = rcos(-currentAngle + 0xC00);
    sinTarget = rsin(-heading + 0xC00);
    sinCurrent = rsin(-currentAngle + 0xC00);
    cosTarget = rcos(-heading + 0xC00);
    aligned = ((cosCurrent * sinTarget - sinCurrent * cosTarget) * sign) >= 0;
    if (aligned) {
        if (ABS(D_800F5918) > 0x280000)
            delta = D_800F5918 / 8 + (sign << 16);
        else
            delta = sign << 16;
    } else
        delta = D_800F5918 / 4 + (sign << 16);
    if (tracking || rcos(currentAngle - heading) < rcos(222)) {
        if (!aligned)
            delta = -delta;
    }
    D_800F5918 += delta;
    sign = -1;
    if (D_800F5918 >= 0)
        sign = 1;
    if (ABS(D_800F5918) > 0x820000)
        D_800F5918 = sign * 0x820000;
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
    if (denominator > 0x800)
        denominator = 0x1000 - denominator;
    if (!denominator) {
        denominator = 1;
        scale = 0;
    }
    magnitude = ABS(D_800F5918);
    correction = magnitude * scale / denominator;
    if (ABS(correction) > magnitude * 4)
        correction = (correction >> 31) * magnitude * 4;
    D_800F591C += correction >> 16;
    if (D_800F591C < -100)
        D_800F591C = -100;
    if (D_800F591C > 500)
        D_800F591C = 500;
    state->targetY = center[1] - (D_800F591C << 12);
    if (state->targetY >= 0xFF000)
        state->targetY = 0xFF000;
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

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", D_80069C18);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", D_80069C1C);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", D_80069C3C);
