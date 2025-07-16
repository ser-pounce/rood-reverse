#include "common.h"
#include "278.h"
#include "413C.h"
#include "../SLUS_010.40/main.h"
#include "../MENUD.PRG/234.h"
#include "../BATTLE/BATTLE.PRG/146C.h"
#include "../BATTLE/BATTLE.PRG/2842C.h"
#include "../BATTLE/BATTLE.PRG/3A1A0.h"
#include "../BATTLE/BATTLE.PRG/40564.h"
#include "../BATTLE/BATTLE.PRG/44F14.h"
#include "../BATTLE/BATTLE.PRG/573B8.h"
#include "../BATTLE/BATTLE.PRG/5BF94.h"
#include <libetc.h>

typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    char unk10;
    char unk11;
} D_800F4588_t;

typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int unkC[0x168];
    int unk5AC;
    int unk5B0;
    int unk5B4;
    char unk5B8;
    char unk5B9;
    char unk5BA;
    char unk5BB;
    short unk5BC;
    short unk5BE;
    int unk5C0;
    int unk5C4;
    int unk5C8;
    char unk5CC;
    char unk5CD;
    short unk5CE;
    int unk5D0;
    int unk5D4;
    int unk5D8;
    int unk5DC;
    int unk5E0[0x40];
    char unk6E0;
    char unk6E1;
    char unk6E2;
    char unk6E3;
    int unk6E4[8];
    char unk704[0x550];
    char unkC54[0x540];
    short unk1194;
    short unk1196;
    int unk1198[0x1B9];
    int unk187C;
} D_800F4538_t;

int func_800FA238(int arg0, int arg1, int arg2);
void func_800FA3FC(int arg0);
int func_800FA9D0();
void func_800FB3C8(int);
void func_800FBD28(int, int, int, int);
void func_800FC208(int, int, int, int);
void func_800FCAA4(int, u_short**, int*, void*);
void func_800FCC0C(int, u_short**, int*, void*);
void func_800FCCE8(void*, int, int, int);
void func_800FCECC(int*, int, int, int);

extern D_800F4538_t* D_800F4538;
extern D_800F4538_t* D_800F453C;
extern D_800F4588_t* D_800F4588[];
extern char D_800F49DC;
extern int D_80102034;
extern int D_801020F4;
extern u_char D_801020F8;
extern short D_80102134;
extern short D_80102136;
extern short D_80102138;
extern short D_8010213A;
extern D_8010229C_t* D_8010229C;
extern int* D_8010246C;
extern char D_80102480[];
extern short D_801024A8[];
extern char D_801024B9;
extern short D_801024C0[];
extern u_short* D_80102540;
extern char D_80102544;

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/278", func_800F9A78);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/278", func_800F9CB0);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/278", func_800F9E0C);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/278", func_800F9EB8);

int func_800FA188(int arg0, int arg1, int* arg2)
{
    D_800F45E0_t* temp_v1;
    int temp_a3;
    int i;
    int var_t2;
    int var_t3;

    var_t2 = 0;
    var_t3 = 0;
    for (i = 0; i < 16; ++i) {
        temp_v1 = D_800F45E0[i];
        if (temp_v1 != 0) {
            temp_a3 = temp_v1->unk8;
            if (!(temp_v1->unk8 & 1) && !(temp_a3 & 0xF00) && (temp_v1->unk1A == 0)
                && (temp_v1->unk5C == arg0) && (temp_v1->unk5E == arg1)) {
                if ((temp_v1->unk16C & 0x30) == 0x20) {
                    var_t3 = 1;
                } else {
                    var_t2 -= 0x80;
                }
            }
        }
    }
    *arg2 = var_t2;
    return var_t3;
}

// https://decomp.me/scratch/CaaPC
INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/278", func_800FA238);

// https://decomp.me/scratch/Uc9JU
INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/278", func_800FA2CC);

// https://decomp.me/scratch/MADRl
// Seems to require GCC 2.7.2-970404
INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/278", func_800FA3FC);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/278", func_800FA448);

void func_800FA568() { }

void func_800FA570()
{
    func_8009967C();
    func_800995B0();
}

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/278", func_800FA598);

void func_800FA810(int arg0)
{
    func_800C8E5C_t* temp_v0 = func_800C8E48(arg0 + 0x20);
    if (temp_v0->unk0 != 0) {
        temp_v0->unk0 = 5;
        temp_v0->unk18 = -temp_v0->unk1;
    }
}

void func_800FA854(int arg0)
{
    int i;

    for (i = 0; i < 8; ++i) {
        if (i != arg0) {
            func_800FA810(i);
        }
    }
}

void func_800FA8A0(int arg0)
{
    func_800C8E5C_t* temp_v0;

    temp_v0 = func_800C8E48(arg0);
    if (temp_v0->unk0 != 0) {
        temp_v0->unk0 = 2;
        temp_v0->unk18 = 0x140;
    }
}

void func_800FA8E0(int arg0)
{
    int i;

    for (i = 0; i < 32; ++i) {
        if (i != arg0) {
            func_800FA8A0(i);
        }
    }
}

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/278", func_800FA92C);

// https://decomp.me/scratch/qPGiA
INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/278", func_800FA9D0);

int func_800FAA20()
{
    int temp_s0 = ++D_80102034;
    func_800FA8E0(0x28);
    return temp_s0 == 5;
}

int func_800FAA5C(int arg0)
{
    if (arg0 & 0x40) {
        D_800F51C0.unk0 = 0;
        func_800C930C(1);
        return 0;
    }
    if (D_800F4FDB == 0) {
        func_8007E0A8(0x1A, 3, 6);
    }
    D_800F51C0.unk0 = 0x7F;
    return 1;
}

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/278", func_800FAAC8);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/278", func_800FAEBC);

INCLUDE_RODATA("build/src/MENU/MAINMENU.PRG/nonmatchings/278", D_800F9814);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/278", func_800FB3C8);

int func_800FBB64(int arg0)
{
    do {
        arg0 = (arg0 + 1) & 3;
    } while (!((D_80102544 >> arg0) & 1));
    return arg0;
}

void func_800FBB8C(int arg0)
{
    D_80102544 = arg0;
    if (!((arg0 >> D_801024B9) & 1)) {
        D_801024B9 = func_800FBB64(D_801024B9);
    }
}

void func_800FBBD4(int arg0)
{
    int var_s1;
    int var_s0;

    var_s1 = 1;
    if (arg0 != 0) {
        if (arg0 > 0) {
            D_801024B9 = 3;
            func_800FBB8C(arg0);
        }
        D_801020F4 = arg0;
        D_801020F8 = 10;
        return;
    }
    var_s0 = D_801024B9;
    if (D_801020F4 > 0) {
        var_s1 = -D_800EBBC8[D_801020F8];
        if (D_801020F8 != 0) {
            --D_801020F8;
        } else if (vs_main_buttonsPressed & PADRleft) {
            var_s0 = func_800FBB64(var_s0);
            if (var_s0 != D_801024B9) {
                vs_main_playSfxDefault(0x7E, 14);
            } else {
                func_800C02E0();
            }
        }
    } else {
        if (D_801020F8 != 0) {
            --D_801020F8;
            var_s1 = (D_801020F8 - 10) * 24;
        }
    }
    if (var_s1 <= 0) {
        func_800FB3C8(var_s1);
    }
    D_801024B9 = var_s0;
}

void func_800FBD0C(int arg0, int arg1, int arg2, int arg3)
{
    D_80102480[0] = arg0;
    D_80102480[1] = arg1;
    D_80102480[2] = arg2;
    D_80102480[3] = arg3;
}

void func_800FBD28(int arg0, int arg1, int arg2, int arg3)
{
    D_801024A8[0] = arg0;
    D_801024A8[1] = arg1;
    D_801024A8[2] = arg2;
    D_801024A8[3] = arg3;
    func_800FBD0C(0, 0, 0, 0);
    vs_battle_memcpy(D_801024A8 + 4, D_801024A8, 8);
}

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/278", func_800FBD80);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/278", func_800FBEA4);

void func_800FC208(int arg0, int arg1, int arg2, int arg3)
{
    D_80102138 = arg2;
    D_8010213A = arg3;
    D_80102134 = (arg0 + 0x63) / 100;
    D_80102136 = (arg1 + 0x63) / 100;
}

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/278", func_800FC268);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/278", func_800FC510);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/278", func_800FC704);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/278", func_800FC85C);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/278", func_800FCA08);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/278", func_800FCAA4);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/278", func_800FCC0C);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/278", func_800FCCE8);

void func_800FCE40(int arg0, int arg1, int arg2, int arg3)
{
    int sp10[90];

    if (D_8010246C == &D_80060268) {
        func_8006B02C(sp10, arg0);
    } else {
        func_80102BB0(sp10, arg0, D_80109A8C);
    }
    func_800FCCE8(sp10, arg1, arg2, arg3);
}

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/278", func_800FCECC);

void func_800FD084(int arg0, int arg1, int arg2, int arg3)
{
    int sp10[48];

    func_8006B110(sp10, arg0);
    func_800FCECC(sp10, arg1, arg2, arg3);
}

void func_800FD0E0(u_short* arg0, func_800FD0E0_t* arg1, int* arg2, void* arg3)
{
    vs_battle_memcpy(arg3, D_80102540 + ((*arg0 + D_80102540)[-0x8C]), 0x60);
    arg1->unk0 = (D_8010229C + *arg0);
    arg1->unk4 = arg3;
    *arg2 = 0x58000000;
}

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/278", func_800FD17C);

void func_800FD220()
{
    vs_battle_rMemzero(D_801024C0, 0x80);
    func_800FC208(0, 0, 0, 0);
    func_800FBD28(0, 0, 0, 1);
}

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/278", func_800FD270);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/278", func_800FD404);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/278", func_800FD504);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/278", func_800FD5A0);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/278", func_800FD700);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/278", func_800FD878);
