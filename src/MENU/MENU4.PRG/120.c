#include "common.h"
#include "../MAINMENU.PRG/C48.h"
#include "../../BATTLE/BATTLE.PRG/146C.h"
#include "../../BATTLE/BATTLE.PRG/573B8.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"

int func_80104514(int);

extern u_long* D_1F800000[];

extern short D_801024C0[];
extern char D_80102545;
extern int D_801080A8;

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_80102920);

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_80102A64);

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_80102B70);

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_80102CAC);

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_80102D64);

void func_80102E3C(signed char* arg0)
{
    int i;

    D_80102545 = 4;

    for (i = 0; i < 4; ++i) {
        D_801024C0[i + 0x20] = (arg0 + i)[0x1C];
    }
    func_800FBD28(arg0[5], arg0[6], arg0[7], 1);
    func_800FBB8C(4);
    func_800FC268(8);
}

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_80102EC0);

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_80102F64);

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_80103080);

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_80103118);

INCLUDE_RODATA("build/src/MENU/MENU4.PRG/nonmatchings/120", D_80102800);

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_8010317C);

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_801032C4);

int func_801033A4(int* arg0)
{
    int sp10[2];
    int sp18;

    func_800FCECC(arg0, sp10, &sp18, D_800F4E8C);
    return sp10[1];
}

int func_801033D4(u_short* arg0)
{
    int sp10[2];
    int sp18[10];
    int sp30[2];

    func_8006BADC(sp18, arg0);
    func_800FD084(sp18, sp10, sp30, D_800F4E8C);
    return sp10[1];
}

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_8010341C);

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_801034BC);

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_80103608);

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_80103688);

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_80103744);

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_8010399C);

void func_80103A6C(int arg0, int arg1, int arg2)
{

    if (arg2 == 0) {
        arg1 = 0;
        arg2 = 1;
    }

    if ((arg0 >> 8) == 0) {
        arg1 = arg2;
    }

    arg1 <<= 6;

    func_800C99DC(arg0 & 0xFF, ((arg1 + arg2) - 1) / arg2, D_1F800000[1] - 3);
}

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_80103AC8);

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_80103E58);

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_80103EF8);

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_80103FEC);

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_80104134);

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_80104514);

int func_8010455C(void)
{
    return func_80104514(D_801080A8 - 1) + 2
        + (D_800F1928[D_801080A8 - 1]->unk3C->unk338 != 0);
}

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_801045B8);

void func_80104AEC(int id)
{
    vs_battle_menuItem_t* menuItem;

    func_800FA8A0(4);
    menuItem = vs_battle_getMenuItem(id + 10);
    menuItem->state = 2;
    menuItem->x = 155;
    menuItem->selected = 1;
    menuItem->unk3A = 0;
}

void func_80104B38(int arg0);
INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_80104B38);

void func_80104C0C(int arg0, int arg1)
{
    func_80104B38(arg0);
    func_800FBBD4(arg1);
    func_800FBEA4(1);
}

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_80104C40);

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_80104DFC);

void func_80104F2C(int arg0)
{
    vs_battle_playMenuLeaveSfx();
    func_800FA8E0(0x28);
    func_800FA810(0);
    func_800FBBD4(-1);
    func_800FBEA4(2);
    if (arg0 != 0) {
        func_800FC268(4);
    }
}

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_80104F80);

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_80105970);

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_80105E94);

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_80105F60);

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_80106150);

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_80106308);

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_801063F8);

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_801064D4);
