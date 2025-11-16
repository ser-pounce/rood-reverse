#include "common.h"
#include "592C.h"
#include "../../SLUS_010.40/main.h"
#include "../../BATTLE/BATTLE.PRG/146C.h"
#include "../../BATTLE/BATTLE.PRG/2842C.h"

typedef struct {
    char unk0;
    char unk1;
    char unk2;
    char unk3;
    char unk4;
    char unk5;
    short unk6;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
} D_8010A4A8_t;

extern int D_80109904[];
extern int D_80109D04[];
extern char D_8010A104[];
extern char D_8010A204[];
extern char D_8010A20C[];
extern int D_8010A4A0;
extern vs_main_CdQueueSlot* D_8010A4A4;
extern D_8010A4A8_t* D_8010A4A8;
extern int D_8010A4B0;
extern int D_8010A4B4;
extern void* D_8010A4AC;

void func_8010812C(int id)
{
    vs_main_CdFile cdFile;
    int i;

    cdFile.lba = D_80109904[id];
    D_8010A4A0 = id;
    cdFile.size = D_80109D04[id];
    D_8010A4A4 = vs_main_allocateCdQueueSlot(&cdFile);
    D_8010A4A8 = vs_main_allocHeapR(cdFile.size);
    vs_main_cdEnqueueUrgent(D_8010A4A4, D_8010A4A8);
    D_8010A4B4 = D_8010A104[id];
    D_8010A4B0 = 0;

    for (i = 0; i < 6; ++i) {
        if (id == D_8010A204[i]) {
            D_8010A4B0 = i;
            break;
        }
    }

    if (D_8010A4B0 != 0) {
        D_8010A4AC = vs_main_allocHeap(0x3200);
    } else {
        D_8010A4AC = vs_main_allocHeap(0x24D0);
    }
}

int func_8010823C(void)
{
    func_8007C8F8_t sp10;
    int temp_s0;

    if (D_8010A4A4 != NULL) {
        temp_s0 = D_8010A4A4->state;
        if (temp_s0 != 4) {
            return 1;
        }
        vs_main_freeCdQueueSlot(D_8010A4A4);
        D_8010A4A4 = NULL;
        sp10.unk0 = 2;
        sp10.unk1 = 1;
        sp10.unk8 = D_8010A4A8->unk8 + (long)D_8010A4A8;
        sp10.unk2 = D_8010A4A8->unk0;
        sp10.unk4 = D_8010A4AC;
        sp10.unk10 = 0xFF;
        sp10.unk13 = D_8010A4B4 & 1;
        sp10.unk12 = D_8010A4A8->unk6;
        func_800995E8(&sp10);
        if (D_8010A4B0 != 0) {
            sp10.unk0 = 1;
            sp10.unk1 = 0x10;
            sp10.unk2 = D_8010A20C[D_8010A4B0];
            sp10.unk4 = D_8010A4AC + 0x1900;
            sp10.unk10 = 1;
            sp10.unk11 = 0xFC;
            sp10.unk13 = 0;
            func_800995E8(&sp10);
        } else {
            if (D_8010A4A8->unk1 != 0) {
                sp10.unk0 = temp_s0;
                sp10.unk1 = 2;
                sp10.unk8 = D_8010A4A8->unk10 + (long)D_8010A4A8;
                sp10.unk2 = D_8010A4A8->unk1;
                sp10.unk4 = D_8010A4AC + 0x1900;
                sp10.unk10 = 1;
                sp10.unk11 = 0xF0;
                sp10.unk12 = D_8010A4A8->unk3;
                func_800995E8(&sp10);
            }
            if (D_8010A4A8->unk4 != 0) {
                sp10.unk0 = temp_s0;
                sp10.unk1 = 3;
                sp10.unk8 = D_8010A4A8->unk18 + (long)D_8010A4A8;
                sp10.unk2 = D_8010A4A8->unk4;
                sp10.unk4 = D_8010A4AC + 0x1EE8;
                sp10.unk10 = 1;
                sp10.unk11 = 0xF1;
                sp10.unk12 = D_8010A4A8->unk5;
                func_800995E8(&sp10);
            }
        }
        if (D_8010A4A8->unk2C != 0) {
            sp10.unk0 = 8;
            sp10.unk1 = 1;
            sp10.unk8 = D_8010A4A8->unk28 + (long)D_8010A4A8;
            sp10.unk10 = 0;
            sp10.unk2 = D_8010A4A8->unk2;
            func_800995E8(&sp10);
        }
        if (D_8010A4A8->unk24 != 0) {
            sp10.unk0 = 8;
            sp10.unk1 = 1;
            sp10.unk8 = D_8010A4A8->unk20 + (long)D_8010A4A8;
            sp10.unk10 = 0;
            sp10.unk2 = 0;
            func_800995E8(&sp10);
        }
        return 1;
    }
    if (D_8010A4A8 == NULL) {
        return 0;
    }
    func_8009967C();
    if (func_800995B0() == 0) {
        vs_main_freeHeapR(D_8010A4A8);
        D_8010A4A8 = NULL;
    }
    return 1;
}

void func_801084E4(void)
{
    vs_main_freeHeapR(D_8010A4AC);
    D_8010A4AC = NULL;
}

void func_80108514(void) { }
