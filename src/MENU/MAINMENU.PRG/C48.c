#include "common.h"
#include "C48.h"
#include "413C.h"
#include "../SLUS_010.40/main.h"
#include "../MENUD.PRG/234.h"
#include "../BATTLE/BATTLE.PRG/146C.h"
#include "../BATTLE/BATTLE.PRG/2842C.h"
#include "../BATTLE/BATTLE.PRG/30D14.h"
#include "../BATTLE/BATTLE.PRG/44F14.h"
#include "../BATTLE/BATTLE.PRG/573B8.h"
#include "../BATTLE/BATTLE.PRG/5BF94.h"
#include <libetc.h>
#include "../../assets/MENU/ITEMHELP.BIN.h"

typedef struct {
    int unk0;
    signed char unk4;
    signed char unk5;
    signed char unk6;
    signed char unk7;
    signed char unk8[8];
} D_80102460_t;

typedef struct {
    int unk0;
    char unk4;
    signed char unk5;
    signed char unk6;
    signed char unk7;
    signed char unk8[8];
    signed char unk10[8];
    int unk18;
} D_80102458_t;

int func_800FA238(int arg0, int arg1, int arg2);
void func_800FA3FC(int arg0);
void func_800FB3C8(int);

extern short D_80102014[];
extern short D_8010202C[];
extern int D_80102034;
extern int D_801020F4;
extern u_char D_801020F8;
extern short _currentDp;
extern short _maxDp;
extern short _currentPp;
extern short _maxPp;
extern D_80102458_t* D_80102458;
extern D_80102460_t* D_80102460;
extern vs_battle_inventoryShield* D_8010246C;
extern vs_battle_inventory_t* D_80102470;
extern char D_80102480[];
extern char D_801024A1;

void func_800FA448(void)
{
    vs_battle_actor2* temp_s1;
    int i;

    temp_s1 = vs_battle_characterState->unk3C;

    if (temp_s1->weapon.unk10D != 0) {
        vs_battle_copyEquippedWeaponStats(
            &vs_battle_inventory.weapons[temp_s1->weapon.unk10D - 1], &temp_s1->weapon);
    }

    if (temp_s1->shield.unkDA != 0) {
        vs_battle_copyEquippedShieldStats(
            &vs_battle_inventory.shields[temp_s1->shield.unkDA - 1], &temp_s1->shield);
    }

    for (i = 0; i < 6; ++i) {
        if (temp_s1->hitLocations[i].armor.unk9A != 0) {
            vs_battle_copyEquippedArmorStats(
                &vs_battle_inventory.armor[temp_s1->hitLocations[i].armor.unk9A - 1],
                &temp_s1->hitLocations[i].armor);
        }
    }

    if (temp_s1->accessory.unk37 != 0) {
        vs_battle_copyEquippedAccessoryStats(
            &vs_battle_inventory.armor[temp_s1->accessory.unk37 - 1],
            &temp_s1->accessory);
    }
}

void func_800FA568(void) { }

void func_800FA570(void)
{
    func_8009967C();
    func_800995B0();
}

int func_800FA598(short* arg0, unsigned int arg1)
{
    int var_a2;
    int var_a3;
    int i;
    int var_t0;
    int var_t1;
    int var_t2;
    int var_v1;

    var_t2 = 0;
    var_t1 = 0;
    var_a3 = 0;
    var_a2 = 0;

    switch (arg1) {
    case 0:
        for (i = 0; i < 6; ++i) {
            if (var_a3 < arg0[156 + i]) {
                var_a2 = var_a3;
                var_a3 = arg0[156 + i];
                var_t1 = i;
            } else if (var_a2 < arg0[156 + i]) {
                var_a2 = arg0[156 + i];
            }
        }
        for (i = 0; i < 7; ++i) {
            if (var_a3 < arg0[172 + i]) {
                var_a2 = var_a3;
                var_a3 = arg0[172 + i];
                var_t1 = i;
                var_t2 = 1;
            } else if (var_a2 < arg0[172 + i]) {
                var_a2 = arg0[172 + i];
            }
        }
        break;

    case 1:
        for (i = 0; i < 6; ++i) {
            if (var_a3 < arg0[130 + i]) {
                var_a2 = var_a3;
                var_a3 = arg0[130 + i];
                var_t1 = i;
            } else if (var_a2 < arg0[130 + i]) {
                var_a2 = arg0[130 + i];
            }
        }

        for (i = 0; i < 7; ++i) {
            if (var_a3 < arg0[146 + i]) {
                var_a2 = var_a3;
                var_a3 = arg0[146 + i];
                var_t1 = i;
                var_t2 = 1;
            } else if (var_a2 < arg0[146 + i]) {
                var_a2 = arg0[146 + i];
            }
        }
        break;

    case 100: // arbitrary
    default:
        for (i = 0; i < 6; ++i) {
            if (var_a3 < arg0[44 + i]) {
                var_a2 = var_a3;
                var_a3 = arg0[44 + i];
                var_t1 = i;
            } else if (var_a2 < arg0[44 + i]) {
                var_a2 = arg0[44 + i];
            }
        }

        for (i = 0; i < 7; ++i) {
            if (var_a3 < arg0[60 + i]) {
                var_a2 = var_a3;
                var_a3 = arg0[60 + i];
                var_t1 = i;
                var_t2 = 1;
            } else if (var_a2 < arg0[60 + i]) {
                var_a2 = arg0[60 + i];
            }
        }
        break;
    }

    var_t0 = 0;
    for (i = 0; i < 11; ++i) {
        if (var_a2 < D_80102014[i]) {
            var_t0 = i;
            break;
        }
    }
    var_v1 = 0;
    for (i = 0; i < 3; ++i) {
        if (var_a3 < D_8010202C[i]) {
            var_v1 = i;
            break;
        }
    }

    {
        int a = (var_t2 * 6) + var_t1;
        int b = var_t0 + (var_v1 * 256);
        return b + (a << 0x10);
    }
}

void func_800FA810(int arg0)
{
    vs_battle_menuItem_t* menuItem = vs_battle_getMenuItem(arg0 + 32);
    if (menuItem->state != 0) {
        menuItem->state = 5;
        menuItem->x = -menuItem->unk1;
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
    vs_battle_menuItem_t* menuItem;

    menuItem = vs_battle_getMenuItem(arg0);
    if (menuItem->state != 0) {
        menuItem->state = 2;
        menuItem->x = 320;
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

void func_800FA92C(int arg0, int arg1)
{
    vs_battle_menuItem_t* menuItem;
    int i;

    for (i = arg1 * 10; i < 30; ++i) {
        func_800FA8A0(i);
    }

    menuItem = vs_battle_getMenuItem(arg0 + (arg1 * 10));
    menuItem->state = 4;
    menuItem->x = 180;
    menuItem->unk1A = (arg1 * 16) + 18;
    if (menuItem->unk2 == 0) {
        menuItem->unk2 = 1;
    }
}

int vs_mainmenu_ready(void)
{
    vs_battle_menuItem_t* menuItem;
    int i;

    menuItem = vs_battle_getMenuItem(0);

    for (i = 0; i < 40; ++i) {
        if (menuItem->state > 1) {
            return 0;
        }
        ++menuItem;
    }
    return 1;
}

int func_800FAA20(void)
{
    int temp_s0 = ++D_80102034;
    func_800FA8E0(0x28);
    return temp_s0 == 5;
}

int func_800FAA5C(int arg0)
{
    if (arg0 & 0x40) {
        vs_battle_menuState.currentState = 0;
        func_800C930C(1);
        return 0;
    }
    if (D_800F4FDB == 0) {
        func_8007E0A8(0x1A, 3, 6);
    }
    vs_battle_menuState.currentState = 0x7F;
    return 1;
}

// https://decomp.me/scratch/b42Kb
INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/C48", func_800FAAC8);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/C48", func_800FAEBC);

INCLUDE_RODATA("build/src/MENU/MAINMENU.PRG/nonmatchings/C48", D_800F9814);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/C48", func_800FB3C8);

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
        var_s1 = -vs_battle_rowAnimationSteps[D_801020F8];
        if (D_801020F8 != 0) {
            --D_801020F8;
        } else if (vs_main_buttonsPressed.all & PADRleft) {
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

void vs_mainMenu_setRangeRisk(int arg0, int arg1, int arg2, int arg3)
{
    D_80102480[0] = arg0;
    D_80102480[1] = arg1;
    D_80102480[2] = arg2;
    D_80102480[3] = arg3;
}

void vs_mainMenu_setStrIntAgi(int strength, int intelligence, int agility, int arg3)
{
    vs_mainMenu_strIntAgi[0].strength = strength;
    vs_mainMenu_strIntAgi[0].intelligence = intelligence;
    vs_mainMenu_strIntAgi[0].agility = agility;
    vs_mainMenu_strIntAgi[0].unk6 = arg3;
    vs_mainMenu_setRangeRisk(0, 0, 0, 0);
    vs_battle_memcpy(&vs_mainMenu_strIntAgi[1], &vs_mainMenu_strIntAgi[0],
        sizeof vs_mainMenu_strIntAgi[0]);
}

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/C48", func_800FBD80);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/C48", func_800FBEA4);

void vs_mainMenu_setDpPp(int currentDp, int maxDp, int currentPp, int maxPp)
{
    _currentPp = currentPp;
    _maxPp = maxPp;
    _currentDp = (currentDp + 99) / 100;
    _maxDp = (maxDp + 99) / 100;
}

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/C48", vs_mainMenu_drawDpPpbars);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/C48", func_800FC510);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/C48", func_800FC704);

void vs_mainMenu_setWeaponStrings(
    vs_battle_equippedWeapon* weapon, char** rowStrings, int* rowTypes, char* description)
{
    int temp_v1;

    vs_battle_equippedItem* blade = &weapon->blade;
    int temp_v0 = func_800FA598((short*)weapon, 0);

    vs_battle_stringContext.strings[0] = (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp
            [(temp_v0 & 0xFF) + VS_ITEMHELP_BIN_INDEX_warriorEquipment - 1]];
    temp_v1 = ((temp_v0 >> 8) & 0xFF);
    vs_battle_stringContext.strings[1] = (char*)&vs_mainMenu_itemHelp
        [temp_v1 != 0
                ? vs_mainMenu_itemHelp[temp_v1 + (temp_v0 >> 0xF) + 0x22D]
                : vs_mainMenu_itemHelp[blade->category
                                       + VS_ITEMHELP_BIN_INDEX_bladeCategoryWeapon - 1]];
    vs_battle_stringContext.strings[9] =
        (char*)&vs_mainMenu_itemNames[blade->material + 253];
    vs_battle_stringContext.strings[8] = (char*)&vs_mainMenu_itemHelp
        [vs_mainMenu_itemHelp[blade->category + VS_ITEMHELP_BIN_INDEX_dagger - 1]];
    vs_battle_stringContext.strings[7] = (char*)&vs_mainMenu_itemHelp
        [vs_mainMenu_itemHelp[blade->damageType + VS_ITEMHELP_BIN_INDEX_blunt - 1]];
    vs_battle_stringContext.strings[6] = (char*)&vs_mainMenu_itemHelp
        [vs_mainMenu_itemHelp[vs_mainMenu_weaponHands[blade->category - 1]
                              + VS_ITEMHELP_BIN_INDEX_oneHanded]];
    vs_battle_printf(
        vs_battle_printf(description,
            (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_classTemplate]),
        (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_weaponDescTemplate]);
    rowStrings[1] = description;
    rowTypes[0] = (blade->category << 0x1A) + (blade->material << 0x10);
}

void func_800FCA08(vs_battle_inventoryWeapon* arg0, char** arg1, int* arg2, char* arg3)
{
    vs_battle_equippedWeapon sp10;

    if (D_80102470 == &vs_battle_inventory) {
        vs_battle_applyWeapon(&sp10, arg0);
    } else {
        func_80102A34(&sp10, arg0, &vs_menuD_containerData->unk0);
    }
    vs_mainMenu_setWeaponStrings(&sp10, arg1, arg2, arg3);
    *arg1 = arg0->name;
}

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/C48", func_800FCAA4);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/C48", func_800FCC0C);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/C48", vs_mainMenu_setShieldStrings);

void func_800FCE40(vs_battle_inventoryShield* arg0, char** arg1, int* arg2, char* arg3)
{
    vs_battle_equippedShield shield;

    if (D_8010246C == &vs_battle_inventory.shields[0]) {
        vs_battle_applyShield(&shield, arg0);
    } else {
        func_80102BB0(&shield, arg0, &vs_menuD_containerData->unk0);
    }
    vs_mainMenu_setShieldStrings(&shield, arg1, arg2, arg3);
}

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/C48", vs_mainMenu_setArmorStrings);

void vs_mainMenu_setAccessoryStrings(
    vs_battle_inventoryArmor* arg0, char** arg1, int* arg2, char* arg3)
{
    vs_battle_equippedArmor sp10;

    vs_battle_applyArmor(&sp10, arg0);
    vs_mainMenu_setArmorStrings(&sp10, arg1, arg2, arg3);
}

void func_800FD0E0(
    vs_battle_inventoryGem* arg0, func_800FD0E0_t* arg1, int* arg2, void* arg3)
{
    vs_battle_memcpy(
        arg3, vs_mainMenu_itemHelp + (arg0->id + vs_mainMenu_itemHelp)[-140], 96);
    arg1->unk0 = vs_mainMenu_itemNames[arg0->id];
    arg1->unk4 = arg3;
    *arg2 = 0x58000000;
}

void func_800FD17C(
    vs_battle_inventoryGem* arg0, func_800FD0E0_t* arg1, int* arg2, void* arg3)
{
    vs_battle_memcpy(
        arg3, vs_mainMenu_itemHelp + (arg0->id + vs_mainMenu_itemHelp)[-140], 96);
    arg1->unk0 = vs_mainMenu_itemNames[arg0->id];
    arg1->unk4 = arg3;
    *arg2 = arg0->unk2 << 9;
}

void vs_mainMenu_resetStats(void)
{
    vs_battle_rMemzero(vs_mainMenu_equipmentStats, sizeof vs_mainMenu_equipmentStats);
    vs_mainMenu_setDpPp(0, 0, 0, 0);
    vs_mainMenu_setStrIntAgi(0, 0, 0, 1);
}

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/C48", func_800FD270);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/C48", func_800FD404);

void func_800FD504(int arg0)
{
    int i;
    D_80102460_t* temp_a2 = &D_80102460[arg0 - 1];

    for (i = 0; i < 4; ++i) {
        vs_mainMenu_equipmentStats[i + 0x20] = temp_a2->unk8[i];
    }
    vs_mainMenu_setStrIntAgi(temp_a2->unk5, temp_a2->unk6, temp_a2->unk7, 1);
    vs_mainMenu_equipmentSubtype = 4;
    D_801024A1 = arg0;
    func_800FBB8C(4);
}

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/C48", func_800FD5A0);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/C48", func_800FD700);

void func_800FD878(int arg0)
{
    int i;
    D_80102458_t* temp_a2 = &D_80102458[arg0 - 1];

    for (i = 0; i < 16; ++i) {
        vs_mainMenu_equipmentStats[i] = temp_a2->unk8[i & 7];
        vs_mainMenu_equipmentStats[i + 0x10] = temp_a2->unk10[i & 7];
    }

    vs_mainMenu_setStrIntAgi(temp_a2->unk5, temp_a2->unk6, temp_a2->unk7, 1);
    vs_mainMenu_equipmentSubtype = 0x40;
    D_801024A1 = arg0;
    func_800FBB8C(3);
}
