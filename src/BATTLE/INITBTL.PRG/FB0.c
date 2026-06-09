#include "common.h"
#include "../BATTLE.PRG/146C.h"
#include "../BATTLE.PRG/30D14.h"
#include "../BATTLE.PRG/3A1A0.h"
#include <libgte.h>

extern char D_800E8F29;
extern char _loadShpState;
extern char D_800E8F2B;
extern char D_800E8F2C;
extern char _loadEtmState;
extern short D_800E8F30[][2];
extern char D_800E8FC0;
extern char D_800F2450[];
extern int D_800F4528[];
extern void* D_800F4768;
extern void* D_800F4930;
extern char D_800F4B18;
extern char D_800F4B19;

void func_800FA7B0(void)
{
    VECTOR sp10;
    int temp_s0;
    int i;

    D_800E8FC0 = 0;

    for (i = 0; i < 16; ++i) {
        vs_battle_objectDataSlots[i].dataType = 0;
    }

    for (i = 0; i < 12; ++i) {
        short(*new_var)[2];
        D_800F46A8[i].tpage =
            GetTPage(0, 0, D_800E8F30[i][0] << 6, (new_var = D_800E8F30)[i][1] << 8);
        D_800F46A8[i].clut0 = GetClut(768, i + 228);
        D_800F46A8[i].clut1 = GetClut(768, i + 246);
        D_800F46A8[i].refCount = 0;
    }

    for (; i < 24; ++i) {
        short(*new_var)[2];
        D_800F46A8[i].tpage =
            GetTPage(0, 0, D_800E8F30[i][0] << 6, (new_var = D_800E8F30)[i][1] << 8);
        D_800F46A8[i].clut0 = GetClut(768, 229);
        D_800F46A8[i].clut1 = GetClut(768, 247);
        D_800F46A8[i].refCount = 0;
    }

    for (i = 0; i < 17; ++i) {
        D_800F4538[i] = NULL;
    }

    D_800F4930 = vs_main_allocHeap(0x7800);
    D_800F4768 = vs_main_allocHeap(0x4800);

    for (i = 0; i < 20; ++i) {
        temp_s0 = (i / 2);
        vs_battle_wepTextures[i].tpage = GetTPage(1, 0, temp_s0 * 64, 0);
        vs_battle_wepTextures[i].clut0 = GetClut(((i & 1) * 48) + 928, temp_s0 + 228);
        vs_battle_wepTextures[i].refCount = 0;
    }

    for (i = 0; i < 20; ++i) {
        vs_battle_wepModels[i] = NULL;
    }

    for (i = 0; i < 2; ++i) {
        vs_battle_commonWepBuffs[i] =
            vs_main_allocHeap(sizeof *vs_battle_commonWepBuffs[i]);
    }

    for (i = 0; i < 16; ++i) {
        D_800F45E0[i] = NULL;
    }

    D_800E8F2C = 0;
    D_800F2450[0] = 0;
    D_800F2450[1] = 0;
    D_800F2450[2] = 0;
    D_800F4528[0] = 0;
    D_800F4528[1] = 0;
    D_800F4528[2] = 0;
    D_800E8F2B = 0;
    _loadEtmState = 0;
    D_800E8FC0 = 0;
    D_800E8F29 = 0;
    D_800E8F28 = 0;
    _loadShpState = 0;
    D_800E8F2C = 0;
    sp10.vx = 0x1000;
    sp10.vy = 0x1000;
    sp10.vz = 0x1000;
    func_8009FB64(&sp10);
    D_800F4B19 = 0;
    D_800F4B18 = 0;
}
