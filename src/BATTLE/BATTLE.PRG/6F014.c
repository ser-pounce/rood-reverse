#include "common.h"
#include "5BF94Private.h"
#include "6E4CCPrivate.h"
#include "6E4CCShared.h"
#include "146CPrivate.h"
#include "4DEA8.h"
#include "battleUnk.h"
#include "src/SLUS_010.40/32154.h"
#include "src/SLUS_010.40/cd.h"
#include "src/SLUS_010.40/memory.h"
#include "src/SLUS_010.40/overlay.h"
#include "src/SLUS_010.40/sound.h"
#include "build/src/include/lbas.h"
#include <abs.h>
#include <rand.h>

void func_800D7814(void)
{
    D_800F568C = NULL;
    pfileBuf = NULL;
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

void parsePfileBlock5(PFileBlock5* block) { D_800F569C->block5Data = block; }

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

void parsePfileBlock3(void* block) { D_800F569C->block3Data = block; }

void parsePfileCurveBlock(PFileCurveBlock* block)
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

void parsePfileBlock8(void* block) { D_800F569C->block8Data = block; }

void parsePfileBlock9(PFileBlock9* arg0) { D_800F569C->block9Data = arg0; }

void parsePfileBlock10(void* arg0) { D_800F569C->block10Data = arg0; }

void parsePfileBlock1(PFileBlock1* block)
{
    int i;

    D_800F569C->block1TableCount = block->tableCount;
    D_800F569C->textures = (void*)block + block->dataOffset;

    for (i = 0; i < D_800F569C->block1TableCount; ++i) {
        D_800F569C->textureInfoTable[i] = (void*)block + block->tableOffsets[i];
    }
}

void parsePfileBlock2(PFileBlock2* block)
{
    D_800F569C->block2Count = block->unk0;
    D_800F569C->block2Data = (void*)block;
}

void* func_800D7A90(int arg0)
{
    return (u_char*)D_800F569C->block2Data + D_800F569C->block2Data[arg0 + 2];
}

void parsePfileBlock11(u_char* arg0) { D_800F569C->block11Data = arg0; }

void parsePfileBlock12(void* arg0)
{
    D_800F569C->block12Data = arg0;
    vs_main_setSfxSlot3Data(arg0);
}

void parsePfileBlock13(void* arg0)
{
    D_800F569C->block13Data = arg0;
    D_800F569C->unkCC = vs_main_setCutsceneStreamSlot3(arg0);
}

static int loadfile(int lba, int size, void* buf)
{
    vs_CdFile cdFile;

    if (D_800F568C == NULL) {
        cdFile.lba = lba;
        cdFile.size = size;
        D_800F568C = vs_main_allocateCdQueueSlot(&cdFile);
        vs_main_cdEnqueue(D_800F568C, buf);
        return 1;
    }

    if (D_800F568C->state == CdQueueStateLoaded) {
        vs_main_freeCdQueueSlot(D_800F568C);
        D_800F568C = NULL;
        return 0;
    }

    return 1;
}

int loadEffPurge(void)
{
    if (D_800F5684 == 0) {
        func_8007E180(2);
        D_800F5684 = 1;
    }

    return loadfile(VS_EFFPURGE_BIN_LBA, VS_EFFPURGE_BIN_SIZE, vs_overlay_slots[3]);
}

int func_800D7BF8(void)
{
    int _[16];

    if (pfileBuf == NULL) {
        pfileBuf = vs_main_allocHeapR(vs_battle_pFileLoadContext.size);
    }

    return loadfile(vs_battle_pFileLoadContext.lba + VS_E000_P_LBA,
        vs_battle_pFileLoadContext.size, pfileBuf);
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
    if (pfileBuf != NULL) {
        vs_main_freeHeapR(pfileBuf);
        pfileBuf = NULL;
    }
}

int func_800D7CFC(void)
{
    UNUSED int _[16];
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

        var_s0 = loadfile(D_800F5638.loadContexts[D_800F5630].lba + VS_E000_P_LBA,
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
    u_int state = plgLoadState;

    switch (state) {
    case 1:
        if (D_800F5684 == 0) {
            func_8007E180(2);
            D_800F5684 = state;
        }
        // Fallthrough

    case 2:
        ret = loadfile(
            plgLoadContext.lba + VS_E000_P_LBA, plgLoadContext.size, vs_overlay_slots[3]);
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

static UNUSED void func_800D7FB4(int arg0, int arg1);
static void func_800D7FB4(int lba, int size)
{
    vs_battle_pFileLoadContext.lba = lba;
    vs_battle_pFileLoadContext.size = size;
}

void vs_battle_configurePlg(int lba, int size, int entryPointCount)
{
    plgLoadContext.lba = lba;
    plgLoadContext.size = size;
    plgEntryPointCount = entryPointCount;
}

void vs_battle_setEffectExec(effectExec func, int index)
{
    effectRenderers[index] = func;
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

void vs_battle_setPlgLoadState(int arg0) { plgLoadState = arg0; }

void func_800D8060(PFile* arg0)
{
    while (1) {
        int meta = arg0->meta;

        switch (meta & 0xFFFF0000) {
        case 0:
            return;

        case 0x10000:
            parsePfileBlock1((PFileBlock1*)arg0->data);
            break;

        case 0x20000:
            parsePfileBlock2((PFileBlock2*)arg0->data);
            break;

        case 0x30000:
            parsePfileBlock3(arg0->data);
            break;

        case 0x40000:
            parsePfileCurveBlock((PFileCurveBlock*)arg0->data);
            break;

        case 0x50000:
            parsePfileBlock5((PFileBlock5*)arg0->data);
            break;

        case 0x80000:
            parsePfileBlock8(arg0->data);
            break;

        case 0x90000:
            parsePfileBlock9((PFileBlock9*)arg0->data);
            break;

        case 0xA0000:
            parsePfileBlock10(arg0->data);
            break;

        case 0xB0000:
            parsePfileBlock11(arg0->data);
            break;

        case 0xC0000:
            parsePfileBlock12(arg0->data);
            break;

        case 0xD0000:
            parsePfileBlock13(arg0->data);
            break;
        }

        arg0 = (void*)arg0 + (meta & 0xFFFF);
    }
}

int getMainMenuLba(void) { return VS_MAINMENU_PRG_LBA; }
