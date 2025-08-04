#include "common.h"
#include "../MAINMENU.PRG/C48.h"
#include "../MAINMENU.PRG/413C.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"

extern char D_801022D6;

static void func_80102C94(int arg0)
{
    if (arg0 != 0) {
        func_800FFA88(2);
        D_801022D6 = 0;
        return;
    }
    func_800FFA88(0);
    D_801022D6 = 1;
}

INCLUDE_ASM("build/src/MENU/MENUE.PRG/nonmatchings/494", func_80102CD8);

int func_80102DF0()
{
    int row;

    row = vs_mainmenu_getSelectedRow();
    if (row < -1) {
        func_800FA8E0(5);
        return row;
    }
    if (row >= 0) {
        func_800FA92C(D_800F4EE8.unk0[4], 1);
    }
    return row;
}

static void func_80102E48(char* text)
{
    vs_battle_menuItem_t* menuItem;

    menuItem = vs_battle_setMenuItem(10, 320, 34, 0x8C, 9, text);
    menuItem->state = 2;
    menuItem->x = 180;
    menuItem->selected = 1;
    menuItem->unkA = 1;
}

static void func_80102E9C() { func_800FA8E0(8); }

static void _menuReady() { vs_mainmenu_ready(); }

INCLUDE_ASM("build/src/MENU/MENUE.PRG/nonmatchings/494", func_80102EDC);

INCLUDE_ASM("build/src/MENU/MENUE.PRG/nonmatchings/494", func_801030A4);

INCLUDE_RODATA("build/src/MENU/MENUE.PRG/nonmatchings/494", D_80102818);

INCLUDE_ASM("build/src/MENU/MENUE.PRG/nonmatchings/494", func_80103110);

INCLUDE_ASM("build/src/MENU/MENUE.PRG/nonmatchings/494", func_8010391C);

INCLUDE_ASM("build/src/MENU/MENUE.PRG/nonmatchings/494", func_80103A24);

INCLUDE_ASM("build/src/MENU/MENUE.PRG/nonmatchings/494", func_80103AD8);

INCLUDE_ASM("build/src/MENU/MENUE.PRG/nonmatchings/494", func_80103B6C);

INCLUDE_ASM("build/src/MENU/MENUE.PRG/nonmatchings/494", func_80103BC8);

static char* _vsStringCpy(char* arg0, char* arg1)
{
    char c;

    for (c = *arg1; c != 0xE7; c = *arg1) {
        if (c >= 0xEC) {
            *arg0 = c;
            ++arg1;
            ++arg0;
        }
        *arg0++ = *arg1++;
    }
    *arg0 = 0xE8;
    return arg0 + 1;
}

INCLUDE_ASM("build/src/MENU/MENUE.PRG/nonmatchings/494", func_80103CF0);

INCLUDE_ASM("build/src/MENU/MENUE.PRG/nonmatchings/494", func_80103E6C);

INCLUDE_ASM("build/src/MENU/MENUE.PRG/nonmatchings/494", func_80104204);

INCLUDE_ASM("build/src/MENU/MENUE.PRG/nonmatchings/494", func_8010435C);

INCLUDE_ASM("build/src/MENU/MENUE.PRG/nonmatchings/494", func_80104620);

INCLUDE_ASM("build/src/MENU/MENUE.PRG/nonmatchings/494", func_80104908);

INCLUDE_ASM("build/src/MENU/MENUE.PRG/nonmatchings/494", func_80104A44);

INCLUDE_ASM("build/src/MENU/MENUE.PRG/nonmatchings/494", func_80104C30);

INCLUDE_ASM("build/src/MENU/MENUE.PRG/nonmatchings/494", func_80104CC4);

INCLUDE_RODATA("build/src/MENU/MENUE.PRG/nonmatchings/494", D_80102BF8);

INCLUDE_RODATA("build/src/MENU/MENUE.PRG/nonmatchings/494", D_80102C08);

INCLUDE_RODATA("build/src/MENU/MENUE.PRG/nonmatchings/494", D_80102C10);

INCLUDE_RODATA("build/src/MENU/MENUE.PRG/nonmatchings/494", D_80102C18);

INCLUDE_RODATA("build/src/MENU/MENUE.PRG/nonmatchings/494", D_80102C20);

INCLUDE_RODATA("build/src/MENU/MENUE.PRG/nonmatchings/494", jtbl_80102C28);

INCLUDE_RODATA("build/src/MENU/MENUE.PRG/nonmatchings/494", D_80102C48);

INCLUDE_RODATA("build/src/MENU/MENUE.PRG/nonmatchings/494", D_80102C54);
