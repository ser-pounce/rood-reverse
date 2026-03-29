#include "common.h"
#include "../BATTLE.PRG/146C.h"
#include "../BATTLE.PRG/30D14.h"
#include <libgte.h>

typedef struct {
    char unk0;
    char unk1;
    char unk2;
    char unk3;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
} D_800F2310_t;

typedef struct {
    short unk0;
    short unk2;
    short unk4;
    char unk6;
    char unk7;
} D_800F46A8_t;

extern char D_800E8F29;
extern char D_800E8F2A;
extern char D_800E8F2B;
extern char D_800E8F2C;
extern char D_800E8F2D;
extern short D_800E8F30[][2];
extern char D_800E8FC0;
extern D_800F2310_t D_800F2310[16];
extern char D_800F2450[];
extern int D_800F4528[];
extern void* D_800F45E0[];
extern void* D_800F4620[];
extern D_800F46A8_t D_800F46A8[];
extern void* D_800F4768;
extern D_800F46A8_t D_800F4770[];
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
        D_800F2310[i].unk0 = 0;
    }

    for (i = 0; i < 12; ++i) {
        short(*new_var)[2];
        D_800F46A8[i].unk0 =
            GetTPage(0, 0, D_800E8F30[i][0] << 6, (new_var = D_800E8F30)[i][1] << 8);
        D_800F46A8[i].unk2 = GetClut(0x300, i + 0xE4);
        D_800F46A8[i].unk4 = GetClut(0x300, i + 0xF6);
        D_800F46A8[i].unk6 = 0;
    }

    for (; i < 24; ++i) {
        short(*new_var)[2];
        D_800F46A8[i].unk0 =
            GetTPage(0, 0, D_800E8F30[i][0] << 6, (new_var = D_800E8F30)[i][1] << 8);
        D_800F46A8[i].unk2 = GetClut(0x300, 0xE5);
        D_800F46A8[i].unk4 = GetClut(0x300, 0xF7);
        D_800F46A8[i].unk6 = 0;
    }

    for (i = 0; i < 17; ++i) {
        D_800F4538[i] = NULL;
    }

    D_800F4930 = vs_main_allocHeap(0x7800);
    D_800F4768 = vs_main_allocHeap(0x4800);

    for (i = 0; i < 20; ++i) {
        temp_s0 = (i / 2);
        D_800F4770[i].unk0 = GetTPage(1, 0, temp_s0 << 6, 0);
        D_800F4770[i].unk2 = GetClut(((i & 1) * 0x30) + 0x3A0, temp_s0 + 0xE4);
        D_800F4770[i].unk6 = 0;
    }

    for (i = 0; i < 20; ++i) {
        D_800F4588[i] = NULL;
    }

    for (i = 0; i < 2; ++i) {
        D_800F4620[i] = vs_main_allocHeap(0x800);
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
    D_800E8F2D = 0;
    D_800E8FC0 = 0;
    D_800E8F29 = 0;
    D_800E8F28 = 0;
    D_800E8F2A = 0;
    D_800E8F2C = 0;
    sp10.vx = 0x1000;
    sp10.vy = 0x1000;
    sp10.vz = 0x1000;
    func_8009FB64(&sp10);
    D_800F4B19 = 0;
    D_800F4B18 = 0;
}
