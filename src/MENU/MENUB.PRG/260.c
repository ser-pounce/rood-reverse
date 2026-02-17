#include "common.h"
#include "../MAINMENU.PRG/C48.h"
#include "../MAINMENU.PRG/413C.h"
#include "../../SLUS_010.40/main.h"
#include "../../BATTLE/BATTLE.PRG/146C.h"
#include "../../BATTLE/BATTLE.PRG/573B8.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"

void func_800BEC14(short, int);
void func_80102CBC(int);
void func_8010837C(int);
void func_801088D4(int);
void func_80108938(int);
int func_80109750(int);

extern char D_8010A2C4;
extern int D_8010A50C;
extern char D_8010A505;
extern char D_8010A69E;
extern void* D_8010A6A0;
extern void* D_8010A6A4;
extern vs_battle_inventory_t* _inventory;
extern void* D_8010A6AC;
extern char D_8010A6B0;
extern u_char D_8010A6B1;
extern char D_8010A6B2;
extern u_char D_8010A6B3;
extern char D_8010A6B5;
extern char D_8010A6B6;
extern char D_8010A6B7;
extern char D_8010A6B8;
extern char D_8010A6B9;
extern char D_8010A6BA;
extern char D_8010A6BB;

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_80102A60);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_80102B14);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_80102C50);

void func_80102CBC(int arg0)
{
    vs_battle_menuItem_t* menuItem;

    menuItem = vs_battle_getMenuItem(31);
    menuItem->state = 2;
    menuItem->targetX = 16;
    menuItem->w = 164;
    menuItem = vs_battle_getMenuItem(arg0);
    menuItem->state = 3;
    menuItem->targetX = 18;
}

void func_80102D1C(int arg0, int arg1)
{
    D_8010A50C = 1;
    D_8010A6BA = 0;
    D_8010A6BB = 0;
    func_80102CBC(arg0);
    func_800FBBD4(arg1);
    vs_battle_renderEquipStats(1);
}

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_80102D6C);

int func_80102E08(int arg0, int arg1)
{
    D_800F4EE8.unk0[(arg0 + 0x1E) * 2] = 0;
    D_800F4EE8.unk0[(arg0 + 0x1E) * 2 + 1] = arg1;
    return vs_mainMenu_inventoryIndices[arg0][arg1];
}

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_80102E54);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_80102EC4);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_8010310C);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_801032F8);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_80103538);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_80103794);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_801039BC);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_80103BA8);

INCLUDE_RODATA("build/src/MENU/MENUB.PRG/nonmatchings/260", D_80102800);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_80103CBC);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_80103DA0);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_80103EFC);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_80103FD8);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_80104144);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_80104164);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_801042A4);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_8010439C);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_80104474);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_80104608);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_80104860);

void func_80104F98(int arg0)
{
    D_8010A6B9 = arg0;
    D_8010A6BA = arg0;
    D_8010A6BB = arg0;
}

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_80104FB4);

int func_80105044(int arg0, int arg1)
{
    int var_v1 = 0;
    if (arg0 == 5) {
        var_v1 = vs_battle_inventory.gems[arg1].setItemIndex;
        if (!(var_v1 & 0x80)) {
            var_v1 = 0;
        }
    }
    return var_v1 & 0x7F;
}

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_80105088);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_8010537C);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_80105454);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_80106274);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_801066CC);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_80106B80);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_801073E0);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_80107C54);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_80107CE8);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_80107D7C);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_80107E10);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_80107F1C);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_80107F9C);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_8010808C);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_801080F0);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_8010822C);

INCLUDE_RODATA("build/src/MENU/MENUB.PRG/nonmatchings/260", D_80102950);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_80108264);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_8010837C);

int func_801086DC(int arg0) { return arg0 & (vs_main_stateFlags.unk1 + 1); }

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_801086F4);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_801088D4);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_80108938);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_80108E78);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_801090A4);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_80109444);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_80109750);

int func_80109E90(char* state)
{
    int i;
    void* temp_v0;

    D_8010A6B7 = 0;

    switch (*state) {
    case 0:
        vs_battle_playSfx10();
        func_800FBD80(16);
        for (i = 0; i < 7; ++i) {
            vs_mainMenu_rebuildInventory(i);
        }
        temp_v0 = vs_main_allocHeapR(0x2300);
        _inventory = temp_v0;
        D_8010A6AC = temp_v0 + 0xF00;
        D_8010A6A0 = temp_v0 + 0x1E00;
        D_8010A6A4 = temp_v0 + 0x2080;
        D_8010A6B8 = 0;
        D_8010A6B6 = 0;
        D_8010A6B5 = 0;
        D_8010A69E = 0;
        vs_mainMenu_loadItemNames(1);
        func_801088D4(D_800EB9C4);
        D_8010A505 = 0;
        D_8010A6B0 = 1;
        D_8010A6B1 = 10;
        D_8010A6B2 = 0;
        D_8010A6B3 = 10;
        *state = 1;
        break;
    case 1:
        if (vs_mainMenu_loadItemNames(0) != 0) {
            D_8010A6B2 = 1;
            if (D_8010A6B6 == 0) {
                func_800C8E04(1);
                vs_mainmenu_setMessage(&D_8010A2C4);
                *state = 4;
            } else {
                func_800FFBC8();
                *state = 2;
            }
        }
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            if (D_8010A6B3 == 0) {
                func_80109750(1);
                *state = 3;
            case 3:
                i = func_80109750(0);
                if (i != 0) {
                    D_800F4E98.unk2 = i == 1;
                    *state = 5;
                }
            }
        }
        break;
    case 4:
        if ((D_800F5130 >> 0x1E) & 1) {
            if (vs_main_buttonsPressed.pad[0].low != 0) {
                *state = 5;
            }
        }
        break;
    case 5:
        D_8010A6B0 = 0;
        D_8010A6B2 = 0;
        if (func_800CD064(7) == 0) {
            if (vs_mainMenu_ensureItemNamesLoaded() != 0) {
                vs_main_freeHeapR(_inventory);
                if (D_800EB9C4 != 0) {
                    func_8008A6FC();
                }
                *state = 0;
                return 1;
            }
        }
        break;
    }
    if (D_8010A6B0 != 0) {
        if (D_8010A6B1 != 0) {
            --D_8010A6B1;
        }
        i = vs_battle_rowAnimationSteps[D_8010A6B1];
    } else {
        if (D_8010A6B1 < 10) {
            ++D_8010A6B1;
        }
        i = D_8010A6B1 << 5;
    }
    if (D_8010A6B1 < 10) {
        func_8010837C(i);
    }
    if (D_8010A6B2 != 0) {
        if (D_8010A6B3 != 0) {
            --D_8010A6B3;
        }
        i = vs_battle_rowAnimationSteps[D_8010A6B3];
    } else {
        if (D_8010A6B3 < 10) {
            ++D_8010A6B3;
        }
        i = D_8010A6B3 << 5;
    }
    if (D_8010A6B3 < 10) {
        func_80108938(i);
        if (D_8010A6B7 & 0xF) {
            vs_battle_getMenuItem(D_8010A6B7 + 0x1F)->selected = 1;
        }
    }
    return 0;
}

void func_8010A24C(int arg0)
{
    if (arg0 >= 0x1CA) {
        func_800BEC14(arg0 + 0x1B6, 1);
    }
}
