#include "common.h"
#include "234.h"
#include "../MAINMENU.PRG/C48.h"
#include "../MAINMENU.PRG/413C.h"
#include "../../BATTLE/BATTLE.PRG/146C.h"
#include "../../BATTLE/BATTLE.PRG/573B8.h"
#include <libetc.h>

typedef struct {
    char unk0[0x2318];
    u_short unk2318[1][0xE];
} func_80103D14_t;

typedef struct {
    u_short unk0;
    char unk2;
} func_801055D0_t;

typedef struct {
    vs_menu_containerData unk0;
    short unk3C00[1];
} func_80102C94_t;

void func_80102D80(int, int, vs_menu_containerData*);
int func_80102F88(int, int, void*);
int func_80103070(int, void*);
void func_801031A0(void);
void func_801032AC(int, vs_menu_containerData*, int, vs_menu_containerData*);

extern u_short D_80109944[];
extern char D_80109A7A;
extern signed char D_80109A7B;
extern signed char D_80109A7C;
extern signed char D_80109A7D;
extern char D_80109A81;
extern short D_80109A82;
extern int D_80109A84;
extern void* D_80109A88;

void func_80102A34(vs_battle_equippedWeapon* target, vs_battle_inventoryWeapon* source,
    vs_menu_containerData* container)
{
    int i;
    vs_battle_weaponIntermediate* weapon = vs_main_allocHeapR(sizeof *weapon);
    vs_main_bzero(weapon, sizeof *weapon);

    if (source != NULL) {
        weapon->unkF2 = source->unk0;
        if (source->blade != 0) {
            vs_battle_copyInventoryBladeStats(
                &weapon->blade, &container->blades[source->blade - 1]);
            weapon->material = container->blades[source->blade - 1].material;
        }

        if (source->grip != 0) {
            vs_battle_copyInventoryGripStats(
                &weapon->grip, &container->grips[source->grip - 1]);
        }

        for (i = 0; i < 3; ++i) {
            if (source->gems[i] != 0) {
                vs_battle_copyInventoryGemStats(
                    &weapon->gems[i], &container->gems[source->gems[i] - 1]);
            }
        }
    }

    for (i = 0; i < 24; ++i) {
        weapon->name[i] = source->name[i];
    }

    vs_battle_applyWeaponStats(target, weapon);
    vs_main_freeHeapR(weapon);
}

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80102BB0);

static u_short* func_80102C94(int arg0, func_80102C94_t* arg1)
{
    int i;
    int var_a3;

    var_a3 = 0;
    for (i = 0; i < arg0; ++i) {
        var_a3 += D_80109944[i];
    }
    return arg1->unk3C00 + var_a3;
}

static int func_80102CD0(int arg0, int arg1, u_short* arg2)
{
    int i;

    for (i = 0; i < D_80109944[arg0]; ++i) {
        if (arg2[i] == (arg1 + 1)) {
            return i + 1;
        }
    }
    return 0;
}

static void func_80102D28(int arg0, int arg1, u_short* arg2)
{
    int i;

    for (i = 0; i < D_80109944[arg0]; ++i) {
        if (arg2[i] == 0) {
            arg2[i] = arg1 + 1;
            return;
        }
    }
}

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80102D80);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80102F88);

int func_80103070(int arg0, void* arg1)
{
    int i;
    int var_s1 = 0;

    for (i = 0; i < D_80109944[arg0]; ++i) {
        if (func_80102F88(arg0, i, arg1) != 0) {
            ++var_s1;
        }
    }
    return var_s1;
}

int func_80103110(int arg0, void* arg1)
{
    int i;

    for (i = 0; i < D_80109944[arg0]; ++i) {
        if (func_80102F88(arg0, i, arg1) == 0) {
            break;
        }
    }
    return i;
}

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_801031A0);

static void func_80103270(void)
{
    short* s0 = &D_80109A82;
    func_801031A0();
    D_80109A82 = func_80103070(6, &D_8010245C->unk4BB0);
}

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_801032AC);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_801037D8);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_801039AC);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80103B20);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80103C9C);

static int func_80103D14(int arg0, int arg1, func_80103D14_t* arg2)
{
    u_short var_v1;

    var_v1 = 0;
    if (arg0 == 5) {
        var_v1 = arg2->unk2318[arg1][0];
        if (!(var_v1 & 0x80)) {
            var_v1 = 0;
        }
    }
    return var_v1 & 0x7F;
}

static void func_80103D50(signed char arg0)
{
    D_80109A7B = arg0;
    D_80109A7C = arg0;
    D_80109A7D = arg0;
}

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80103D6C);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80103E24);

void func_80103F64(int arg0)
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
    menuItem->unk7 = 0;
}

void func_80103FD4(int arg0)
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

static void func_80104034(int arg0, int arg1)
{
    D_80109A7C = 0;
    D_80109A7D = 0;
    func_80103FD4(arg0);
    func_800FBBD4(arg1);
    func_800FBEA4(1);
}

void func_80104078(int arg0, char** arg1, u_int arg2, int arg3)
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

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80104114);

void func_80104170(int arg0)
{
    vs_battle_playMenuLeaveSfx();
    func_800FA8E0(0x28);
    func_800FA810(-1);
    func_800FBBD4(-1);
    func_800FBEA4(2);
    D_80109A81 = 2;
    D_80109A84 = vs_main_buttonsPressed.all & PADRup;
    if (arg0 != 0) {
        vs_mainMenu_drawDpPpbars(4);
    }
}

void func_801041E0(
    vs_menu_containerData* arg0, char** arg1, int* arg2, char* arg3, int arg4)
{
    vs_battle_equippedWeapon sp10;

    func_80102A34(&sp10, &arg0->weapons[arg4], arg0);
    vs_mainMenu_setWeaponStrings(&sp10, arg1, arg2, arg3);
    *arg1 = arg0->weapons[arg4].name;
}

void func_8010425C(
    vs_menu_containerData* arg0, char** arg1, int* arg2, char* arg3, int arg4)
{
    vs_battle_equippedShield sp10;

    func_80102BB0(&sp10, &arg0->shields[arg4], arg0);
    vs_mainMenu_setShieldStrings(&sp10, arg1, arg2, arg3);
}

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_801042D0);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80104534);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80104728);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_8010496C);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80104BDC);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80104E14);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80105008);

INCLUDE_RODATA("build/src/MENU/MENUD.PRG/nonmatchings/234", D_8010285C);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80105114);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_801051F8);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80105378);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80105454);

static int func_801055D0(int arg0, func_801055D0_t* arg1)
{
    if (arg0 == 0) {
        return -arg1->unk0;
    }
    return arg1->unk2;
}

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_801055F0);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_8010574C);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80105844);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_8010592C);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80105ACC);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80105D24);

INCLUDE_RODATA("build/src/MENU/MENUD.PRG/nonmatchings/234", D_80102910);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80106464);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80106504);

int _getWeaponGemSlotCount(int arg0)
{
    int i;
    vs_battle_inventoryWeapon* weapon = &vs_menuD_containerData->weapons[arg0];
    int count = 0;

    for (i = 0; i < vs_menuD_containerData->grips[weapon->grip - 1].gemSlots; ++i) {
        count += weapon->gems[i] != 0;
    }
    return count;
}

int _getShieldGemSlotCount(int arg0)
{
    int i;
    vs_battle_inventoryShield* shield = &vs_menuD_containerData->shields[arg0];
    int count = 0;

    for (i = 0; i < shield->unk4.gemSlots; ++i) {
        count += shield->gems[i] != 0;
    }
    return count;
}

int func_801066DC(int arg0, int arg1)
{
    int temp_s0 = func_80103070(arg0, D_80109A88);
    int temp_s1 = arg1 + (temp_s0 + func_80103070(arg0, &D_8010245C->unk87B0));

    if (D_80109A7A != 0) {
        return D_80109944[arg0] < temp_s1;
    }
    return D_801022A0[arg0] < temp_s1;
}

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80106784);

void func_801068BC(int arg0)
{
    int temp_s0_2;
    int temp_s2;
    int temp_s0;

    temp_s0 = D_8010245C->unkC3B0[arg0];
    temp_s2 = temp_s0 >> 8;
    temp_s0_2 = (temp_s0 - 1) & 0xFF;
    func_801032AC(
        temp_s2 | 0x10, vs_menuD_containerData, temp_s0_2, &D_8010245C->unk87B0);
    func_80102D80(temp_s2, temp_s0_2, &D_8010245C->unk87B0);
}

void func_80106948(int arg0, int arg1)
{
    func_801032AC(arg0 | 0x10, &D_8010245C->unk87B0, arg1, vs_menuD_containerData);
    func_80102D80(arg0, arg1, vs_menuD_containerData);
}

static int func_801069B0(int arg0, int arg1)
{
    int i;

    for (i = 0; i < 64; ++i) {
        if (D_8010245C->unkC3B0[i] == ((arg0 << 8) | (arg1 + 1))) {
            return i + 1;
        }
    }
    return 0;
}

static void func_80106A04(int arg0, int arg1)
{
    int i;
    u_short* var_v1;

    i = 0;
    var_v1 = (u_short*)D_8010245C + 0x61D8;
    for (i = 0; i < 64; ++i) {
        if (var_v1[i] == 0) {
            var_v1[i] = ((arg0 << 8) | (arg1 + 1));
            return;
        }
    }
}

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80106A50);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80106C64);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_801071D8);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_801072B0);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80107490);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_801089BC);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80108C6C);
