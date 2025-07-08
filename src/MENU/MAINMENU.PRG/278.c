#include "common.h"
#include "278.h"
#include "../BATTLE/BATTLE.PRG/146C.h"
#include "../BATTLE/BATTLE.PRG/2842C.h"
#include "../BATTLE/BATTLE.PRG/573B8.h"
#include "../BATTLE/BATTLE.PRG/5BF94.h"

void func_800FA3FC(int arg0);
int func_800FA9D0();
void func_800FBD28(int, int, int, int);
void func_800FC208(int, int, int, int);
void func_800FCECC(int*, int, int, int);

extern int D_80102034;
extern short D_80102134;
extern short D_80102136;
extern short D_80102138;
extern short D_8010213A;
extern char D_80102480[];
extern short D_801024A8[];
extern char D_801024B9;
extern char D_801024C0[];
extern char D_80102544;

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/278", func_800F9A78);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/278", func_800F9CB0);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/278", func_800F9E0C);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/278", func_800F9EB8);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/278", func_800FA188);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/278", func_800FA238);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/278", func_800FA2CC);

// https://decomp.me/scratch/MADRl
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
    func_800C8E48_t* temp_v0 = func_800C8E48(arg0 + 0x20);
    if (temp_v0->unk0 != 0) {
        temp_v0->unk0 = 5;
        temp_v0->unk18 = -temp_v0->unk2[0];
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
    func_800C8E48_t* temp_v0;

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

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/278", func_800FAA5C);

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

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/278", func_800FBBD4);

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

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/278", func_800FCE40);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/278", func_800FCECC);

void func_800FD084(int arg0, int arg1, int arg2, int arg3)
{
    int sp10[48];

    func_8006B110(sp10, arg0);
    func_800FCECC(sp10, arg1, arg2, arg3);
}

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/278", func_800FD0E0);

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
