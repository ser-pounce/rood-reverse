#include "common.h"
#include "../MAINMENU.PRG/C48.h"
#include "../MAINMENU.PRG/413C.h"
#include "../../SLUS_010.40/main.h"
#include "../../BATTLE/BATTLE.PRG/2842C.h"
#include "../../BATTLE/BATTLE.PRG/573B8.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"

typedef struct {
    u_short unk0;
    char unk2;
} func_8010406C_t;

void func_80102BE4(int);

extern int D_80109568;
extern void (*D_8010962C[])(int);
extern u_char D_801096A3;
extern char D_80109711;
extern char D_80109712;
extern char D_80109713;
extern char D_80109717;
extern int D_80109718;
extern int D_8010975C;
extern int D_80109760;

void func_8010296C(char arg0)
{
    D_80109711 = arg0;
    D_80109712 = arg0;
    D_80109713 = arg0;
}

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80102988);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80102A3C);

void func_80102B78(int arg0)
{
    vs_battle_menuItem_t* menuItem;

    func_800FA8E0(0x28);
    menuItem = vs_battle_getMenuItem(0x1F);
    menuItem->state = 3;
    menuItem->x = 0x12;
    menuItem = vs_battle_getMenuItem(arg0);
    menuItem->state = 2;
    menuItem->x = 0x9B;
    menuItem->selected = 1;
    menuItem->unk3A = 0;
}

void func_80102BE4(int arg0)
{
    vs_battle_menuItem_t* menuItem;

    menuItem = vs_battle_getMenuItem(0x1F);
    menuItem->state = 2;
    menuItem->x = 0x10;
    menuItem->unk1 = 0xA4;
    menuItem = vs_battle_getMenuItem(arg0);
    menuItem->state = 3;
    menuItem->x = 0x12;
}

void func_80102C44(int arg0, int arg1)
{
    D_80109568 = 1;
    D_80109712 = 0;
    D_80109713 = 0;
    func_80102BE4(arg0);
    func_800FBBD4(arg1);
    func_800FBEA4(1);
}

void func_80102C94(int arg0, char** arg1, u_int arg2, int arg3)
{
    vs_battle_menuItem_t* temp_v0;

    vs_battle_playMenuChangeSfx();
    temp_v0 = vs_battle_setMenuItem(arg0, 0x9B, 0x12, 0xA5, 0, arg1[0]);
    temp_v0->selected = 1;
    temp_v0->flags = (arg2 >> 0x1A);
    temp_v0->unkC = (arg2 >> 0x10) & 7;
    vs_mainmenu_setMessage(arg1[1]);
    vs_battle_getMenuItem(0x1F)->unkE = arg3 + 1;
}

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80102D30);

void func_80102D7C(int arg0)
{
    vs_battle_playMenuLeaveSfx();
    func_800FA8E0(0x28);
    func_800FA810(-1);
    func_800FBBD4(-1);
    func_800FBEA4(2);
    D_80109717 = 2;
    D_80109718 = vs_main_buttonsPressed.all & 0x10;
    if (arg0 != 0) {
        vs_mainMenu_drawDpPpbars(4);
    }
}

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80102DEC);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80103034);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80103220);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80103460);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_801036BC);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_801038E4);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80103AD0);

INCLUDE_RODATA("build/src/MENU/MENU3.PRG/nonmatchings/16C", D_80102800);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80103BE4);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80103CC8);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80103E24);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80103F00);

int func_8010406C(int arg0, func_8010406C_t* arg1)
{
    if (arg0 == 0) {
        return -arg1->unk0;
    }
    return arg1->unk2;
}

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_8010408C);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_801041CC);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_801042C4);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_8010439C);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80104530);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80104788);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80104EC0);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80104F50);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80104F94);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80105314);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_801053EC);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80106390);

int func_80106574(void) { return D_8010975C != 0 ? -1 : D_80109760; }

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_8010659C);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80106BB4);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80106C94);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80107148);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80107620);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80107B14);

void func_80108010(int arg0)
{
    if (arg0 != 0) {
        if (arg0 == 8) {
            D_801096A3 = 3;
        } else {
            if (arg0 >= 3) {
                arg0 -= 2;
                D_801096A3 = 0;
            } else {
                D_801096A3 = arg0;
            }
        }
    }
    D_8010962C[D_801096A3](arg0);
}

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80108088);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80108518);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80108970);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_801090C4);

// https://decomp.me/scratch/g9L6W
// 2.7.2-cdk
INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80109320);

// https://decomp.me/scratch/3TToS
// 2.7.2-cdk
INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80109344);
