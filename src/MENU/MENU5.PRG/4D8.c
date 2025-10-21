#include "common.h"
#include "../MAINMENU.PRG/C48.h"
#include "../MAINMENU.PRG/413C.h"
#include "../MAINMENU.PRG/8170.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"

void func_80102CD8(int arg0)
{
    if (arg0 != 0) {
        func_800FFA88(2);
        D_801022D6 = 0;
        return;
    }
    func_800FFA88(0);
    D_801022D6 = 1;
}

INCLUDE_ASM("build/src/MENU/MENU5.PRG/nonmatchings/4D8", func_80102D1C);

INCLUDE_ASM("build/src/MENU/MENU5.PRG/nonmatchings/4D8", func_80102D90);

int func_80102ED8(void)
{
    int temp_v0;

    temp_v0 = vs_mainmenu_getSelectedRow();
    if (temp_v0 < -1) {
        func_800FA8E0(5);
        return temp_v0;
    }
    if (temp_v0 >= 0) {
        func_800FA92C(D_800F4EE8.unk0[0], 1);
    }
    return temp_v0;
}

void func_80102F30(char* text, char arg1)
{
    vs_battle_menuItem_t* menuItem;

    menuItem = vs_battle_setMenuItem(10, 320, 34, 0x8C, 8, text);
    menuItem->state = 2;
    menuItem->x = 0xB4;
    menuItem->selected = 1;
    menuItem->unkA = arg1;
}

void func_80102F8C(void) { func_800FA8E0(5); }

void func_80102FAC(void) { vs_mainmenu_ready(); }

INCLUDE_ASM("build/src/MENU/MENU5.PRG/nonmatchings/4D8", func_80102FCC);

INCLUDE_ASM("build/src/MENU/MENU5.PRG/nonmatchings/4D8", func_801030F4);

INCLUDE_ASM("build/src/MENU/MENU5.PRG/nonmatchings/4D8", func_80103418);

INCLUDE_RODATA("build/src/MENU/MENU5.PRG/nonmatchings/4D8", D_80102820);

INCLUDE_RODATA("build/src/MENU/MENU5.PRG/nonmatchings/4D8", D_80102B00);

INCLUDE_RODATA("build/src/MENU/MENU5.PRG/nonmatchings/4D8", D_80102C00);
