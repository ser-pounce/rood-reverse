#include "common.h"
#include "168.h"
#include "../MAINMENU.PRG/C48.h"
#include "../MAINMENU.PRG/413C.h"
#include "../../BATTLE/BATTLE.PRG/146C.h"
#include "../../BATTLE/BATTLE.PRG/573B8.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"
#include "vs_string.h"
#include <libetc.h>
#include <memory.h>

void _disassembleWeapon(int);
int func_80103380(int);
void func_80103C20(int, int);
vs_battle_menuItem_t* func_801077DC(int, int);
void func_801087E4(vs_battle_inventoryShield* arg0);
void func_8010B598(vs_battle_inventoryArmor*, vs_battle_inventoryArmor*,
    vs_battle_inventoryArmor*, void*);

extern void* _sydData;
extern int _sydLbas[];
extern int _sydSizes[];
extern vs_main_CdQueueSlot* _sydCdQueueSlot;
extern char _sydFileLoading;

extern char D_8010BB20;
extern u_short D_8010BB24[];
extern char D_8010BBF4;
extern char D_8010BBF5;
extern char D_8010BBF6;
extern char D_8010BBF7;
extern char D_8010BBF8;
extern char D_8010BB21;
extern u_char _combiningItem;
extern u_int D_8010BC84[5];
extern int D_8010BC98;
extern int D_8010BC9C;
extern vs_battle_inventoryShield D_8010BD14;
extern u_char D_8010BD44[];

extern u_long* D_1F800000[];

void func_80102968(int arg0, int arg1)
{
    func_800C6540("OK", (((arg0 * 0x10) + 0x20) << 0x10) | 0xAF,
        ((rsin(arg1 * 8) >> 5) + 0x40) * 0x10101, D_1F800000[1] - 3);
}

void func_801029D0(int arg0, int arg1)
{
    vs_battle_menuItem_t* temp_v0;

    int var_a2 = 0x12;
    if (arg0 != 0) {
        var_a2 = 0x22;
    }
    temp_v0 = vs_battle_setMenuItem(
        arg0, 0x140, var_a2, 0x8C, 8, (char*)&vs_mainMenu_menu12Text[arg1]);
    temp_v0->state = 2;
    temp_v0->x = 0xB4;
    temp_v0->selected = 1;
}

void func_80102A34(int arg0)
{
    u_int i;
    u_int var_t0;

    var_t0 = 0;
    if (arg0 < 5) {
        for (i = 0; i < 5; ++i) {
            if (var_t0 < D_8010BC84[i]) {
                var_t0 = D_8010BC84[i];
            }
        }

        D_8010BC84[arg0] = var_t0 + 1;
        return;
    }
    vs_battle_rMemzero(D_8010BC84, sizeof D_8010BC84);
}

int func_80102AB8(int arg0)
{
    int i;
    int var_a2 = 0;

    if (arg0 < 5) {
        D_8010BC84[arg0] = 0;
    } else {
        for (i = 0; i < 5; ++i) {
            if (D_8010BC84[var_a2] < D_8010BC84[i]) {
                var_a2 = i;
            }
        }

        if (D_8010BC84[var_a2] != 0) {
            D_8010BC84[var_a2] = 0;
            return var_a2 + 1;
        }
    }
    return 0;
}

void func_80102B50(int arg0, int arg1)
{
    vs_battle_menuItem_t* temp_v0 = vs_battle_setMenuItem(
        0x20, -0xA4, 0x12, 0xA4, 8, (char*)&vs_mainMenu_menu12Text[arg0]);
    temp_v0->state = 5;
    temp_v0->x = 0x10;
    temp_v0->selected = 1;
    temp_v0->flags = arg1;
    vs_mainMenu_resetStats();
    arg0 = 7;
    if (arg1 == 0x18) {
        vs_mainMenu_setRangeRisk(0, 0, 0, 1);
        arg0 = 3;
    }
    func_800FBBD4(arg0);
    arg0 = 3;
    if (arg1 == 0x1C) {
        arg0 = 1;
    }
    vs_mainMenu_drawDpPpbars(arg0);
    func_800FBEA4(1);
}

void func_80102C0C(int arg0, int arg1)
{
    if (arg0 != arg1) {
        vs_battle_copyAligned(
            &vs_battle_menuItems[arg1], &vs_battle_menuItems[arg0], 0x40);
        func_800FFB90(arg0);
    }
}

int func_80102C58(int arg0)
{
    int i;
    int var_s1;
    vs_battle_menuItem_t* temp_v0_2;

    var_s1 = 0;

    if (arg0 != 0) {
        func_800C8E04(1);
        D_8010BBF5 = 0;
        D_8010BBF4 = 0;
        return 0;
    }

    switch (D_8010BBF4) {
    case 0:
    case 1:
        temp_v0_2 = vs_battle_setMenuItem(D_8010BBF4 + 0x1D, 0x140,
            (D_8010BBF4 * 0x10) + 0x92, 0x7E, 0,
            (char*)&vs_mainMenu_menu12Text[vs_mainMenu_menu12Text[D_8010BBF4 + 0x22]]);
        temp_v0_2->state = 2;
        temp_v0_2->x = 0xC2;
        D_8010BBF4 = (char)(D_8010BBF4 + 1);
        break;
    case 2:
        D_8010BBF4 += vs_mainmenu_ready();
        break;
    case 3:
        for (i = 0; i < 2; ++i) {
            vs_battle_getMenuItem(i + 0x1D)->selected = (i ^ D_8010BBF5) == 0;
        }
        if (vs_main_buttonsPressed.all & 0x10) {
            var_s1 = 3;
        } else if (vs_main_buttonsPressed.all & 0x40) {
            var_s1 = 2;
        } else if (vs_main_buttonsPressed.all & 0x20) {
            var_s1 = D_8010BBF5 + 1;
        } else {
            if (vs_main_buttonRepeat & 0x5000) {
                vs_battle_playMenuChangeSfx();
                D_8010BBF5 = 1 - D_8010BBF5;
            }
            D_8010BB20 = vs_battle_drawCursor(D_8010BB20, D_8010BBF5 + 8);
        }
        break;
    }

    if (var_s1 != 0) {
        if (var_s1 == 2) {
            vs_battle_playMenuLeaveSfx();
        }
        for (i = 0x1D; i < 0x1F; ++i) {
            func_800FA8A0(i);
        }
    }

    return var_s1;
}

int func_80102E40(int arg0)
{
    int i;
    int var_s2;
    u_short* var_v0_2;
    vs_battle_menuItem_t* temp_v0_2;

    var_s2 = 0;
    if (arg0 != 0) {
        func_800C8E04(1);
        D_8010BBF8 = arg0;
        D_8010BBF7 = 0;
        D_8010BBF6 = 0;
        return 0;
    }

    switch (D_8010BBF6) {
    case 0:
    case 1:
    case 2:
        var_v0_2 = &vs_mainMenu_menu12Text[vs_mainMenu_menu12Text[D_8010BBF6 + 0x22]];
        if (D_8010BBF6 == D_8010BBF8) {
            var_v0_2 = vs_mainMenu_menu12Text + 0x49F;
        }
        temp_v0_2 = vs_battle_setMenuItem(D_8010BBF6 + 0x1D, 0x140,
            (D_8010BBF6 * 0x10) + 0x82, 0x7E, 0, (char*)var_v0_2);
        temp_v0_2->state = 2;
        temp_v0_2->x = 0xC2;
        ++D_8010BBF6;
        break;
    case 3:
        D_8010BBF6 += vs_mainmenu_ready();
        break;
    case 4:
        for (i = 0; i < 3; ++i) {
            vs_battle_getMenuItem(i + 0x1D)->selected = (i ^ D_8010BBF7) == 0;
        }
        if (vs_main_buttonsPressed.all & 0x10) {
            var_s2 = 3;
        } else if (vs_main_buttonsPressed.all & 0x40) {
            var_s2 = 2;
        } else if (vs_main_buttonsPressed.all & 0x20) {
            var_s2 = D_8010BBF7 + 1;
        } else {
            i = D_8010BBF7;
            if (vs_main_buttonRepeat & 0x1000) {
                i += 2;
            }
            if (vs_main_buttonRepeat & 0x4000) {
                ++i;
            }
            if (i >= 3) {
                i -= 3;
            }
            if (i != D_8010BBF7) {
                vs_battle_playMenuChangeSfx();
                D_8010BBF7 = i;
            }
            D_8010BB21 = vs_battle_drawCursor(D_8010BB21, D_8010BBF7 + 7);
        }
        break;
    }

    if (var_s2 != 0) {
        if (var_s2 == 2) {
            vs_battle_playMenuLeaveSfx();
        }
        for (i = 0x1D; i < 0x20; ++i) {
            func_800FA8A0(i);
        }
    }
    return var_s2;
}

void _disassembleWeapon(int weaponIndex)
{
    int i;
    int index;
    vs_battle_inventoryWeapon* weapon = &vs_battle_inventory.weapons[weaponIndex];

    if (weapon->blade == 0) {
        return;
    }

    for (i = 0; i < vs_battle_inventory.grips[weapon->grip - 1].gemSlots; ++i) {
        index = weapon->gems[i];
        if (index != 0) {
            vs_battle_inventory.gems[index - 1].setItemIndex = 0;
            weapon->gems[i] = 0;
        }
    }

    vs_battle_inventory.grips[weapon->grip - 1].combinedWeaponIndex = 0;
    vs_battle_inventory.blades[weapon->blade - 1].combinedWeaponIndex = 0;
    index = weapon->index;

    vs_battle_rMemzero(weapon, sizeof *weapon);

    weapon->index = index;

    func_800FE8B0(0);
}

void _assembleWeapon(int bladeIndex, int gripIndex, int gemInfo)
{
    int i;
    int weaponIndex;
    int gemSlots;
    vs_battle_inventoryWeapon* weapon = &vs_battle_inventory.weapons[_combiningItem];
    vs_battle_inventoryBlade* blade = &vs_battle_inventory.blades[bladeIndex];
    vs_battle_inventoryGrip* grip = &vs_battle_inventory.grips[gripIndex];

    gemSlots = grip->gemSlots;

    _disassembleWeapon(_combiningItem);

    weapon->blade = bladeIndex + 1;
    weapon->grip = gripIndex + 1;

    for (i = 0; i < gemSlots; ++i) {
        weapon->gems[i] = gemInfo;
        gemInfo >>= 8;
    }

    weaponIndex = _combiningItem + 1;
    blade->combinedWeaponIndex = weaponIndex;
    grip->combinedWeaponIndex = weaponIndex;

    for (i = 0; i < gemSlots; ++i) {
        gemInfo = weapon->gems[i];
        if (gemInfo != 0) {
            vs_battle_inventory.gems[gemInfo - 1].setItemIndex = weaponIndex;
        }
    }

    memset(weapon->name, vs_char_terminator, sizeof weapon->name);
    func_800FE8B0(0);
}

void _unsetShieldGems(int index)
{
    int i;
    vs_battle_inventoryShield* shield = &vs_battle_inventory.shields[index];
    int slots = shield->base.gemSlots;

    for (i = 0; i < slots; ++i) {
        int gemIndex = shield->gems[i];
        if (gemIndex != 0) {
            vs_battle_inventory.gems[gemIndex - 1].setItemIndex = 0;
            shield->gems[i] = 0;
        }
    }
}

int func_8010333C(char* arg0, u_char* arg1)
{
    if ((arg0 == NULL) || (arg1 == NULL)) {
        return 1;
    }
    return (1 << arg0[3]) & D_8010BB24[arg1[3]];
}

int func_80103380(int arg0)
{

    vs_battle_playMenuLeaveSfx();
    func_800FA8E0(0x28);
    func_800FA810(0);

    if (arg0 != 0) {
        func_800FBBD4(-1);
        func_800FBEA4(2);
        vs_mainMenu_drawDpPpbars(4);
    }

    func_800FFA88(2);

    return vs_main_buttonsPressed.all & PADRup ? -2 : -1;
}

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_801033FC);

int func_801035E0(void) { return D_8010BC98 == 0 ? D_8010BC9C : -1; }

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80103608);

void func_80103C20(int arg0, int arg1)
{
    int var_v1;

    vs_mainMenu_resetStats();
    vs_mainMenu_setRangeRisk(0, 0, 0, 1);
    vs_mainMenu_equipmentSubtype = 0;

    var_v1 = arg0 != 0;
    if (arg1 != 0) {
        var_v1 += 2;
    }

    switch (var_v1) {
    case 1:
        func_800FD404(arg0);
        break;
    case 2:
        func_800FD504(arg1);
        break;
    case 3:
        func_800FD270(_combiningItem + 1);
        break;
    }

    func_800FBB8C(7);
    vs_mainMenu_drawDpPpbars(0xB);
}

void func_80103CEC(int arg0)
{
    vs_battle_menuItem_t* menuItem;
    int s1 = arg0 >> 4;
    int s2 = (arg0 >> 10);
    int new_var = s1 & 0x3F;
    int new_var2 = s2 & 0x3F;
    arg0 &= 0xF;
    menuItem = vs_battle_setMenuItem(0x20, 0x10, 0x12, 0xA4, 8,
        (char*)(&vs_mainMenu_menu12Text[vs_mainMenu_menu12Text[arg0 + 13]]));
    menuItem->flags = 0x18;
    menuItem->selected = 1;
    if (arg0 == 0) {
        func_80103C20(new_var, new_var2);
    }
}

void func_80103D8C(int arg0)
{
    vs_battle_menuItem_t* temp_v0;

    temp_v0 = vs_battle_getMenuItem(arg0);
    temp_v0->state = 4;
    temp_v0->x = 0x9B;
    temp_v0->unk1A = 0x12;
}

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80103DC4);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_8010418C);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80104534);

void func_80104868(void)
{
    _disassembleWeapon(_combiningItem);
    func_80103380(1);
}

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80104898);

void func_80105618(int arg0 __attribute__((unused)), int arg1)
{
    vs_battle_menuItem_t* temp_v0 = vs_battle_setMenuItem(arg1 + 0xA, 0x140,
        (arg1 * 0x10) + 0x12, 0x97, 0, (char*)(vs_mainMenu_menu12Text + 0x421));
    temp_v0->state = 2;
    temp_v0->x = 0xA9;
    temp_v0->unkA = 1;
}

void func_80105674(char* arg0, int arg1)
{
    int i;
    int gem;
    u_char* var_t1;
    vs_battle_inventoryShield* temp_a0;
    vs_battle_inventoryWeapon* temp_t2;

    temp_t2 = &vs_battle_inventory.weapons[_combiningItem];
    temp_a0 = &vs_battle_inventory.shields[_combiningItem];

    if (arg1 != 0) {
        var_t1 = temp_a0->gems;
    } else {
        var_t1 = temp_t2->gems;
    }

    for (i = 0; i < 3; ++i) {
        gem = var_t1[i];
        if (gem != 0) {
            vs_battle_inventory.gems[gem - 1].setItemIndex = 0;
            var_t1[i] = 0;
        }
    }

    for (i = 0; i < 3; ++i) {
        gem = arg0[i];
        if (gem != 0) {
            vs_battle_inventory.gems[gem - 1].setItemIndex =
                _combiningItem + ((arg1 << 7) + 1);
            var_t1[i] = gem;
        }
    }
    if (arg1 != 0) {
        if (temp_a0->unk1 != 0) {
            vs_battle_equipShield(temp_a0);
        }
    } else if (temp_t2->unk3 != 0) {
        vs_battle_equipWeapon(temp_t2);
    }
    func_80103380(1);
}

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_801057BC);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_801063E4);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80106610);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80106C64);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80106ECC);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_801072FC);

int vs_menuC_loadSyd(int id)
{
    vs_main_CdFile cdFile;

    if (id != 0) {
        --id;
        _sydData = vs_main_allocHeapR(_sydSizes[id]);
        cdFile.lba = _sydLbas[id];
        cdFile.size = _sydSizes[id];
        _sydCdQueueSlot = vs_main_allocateCdQueueSlot(&cdFile);
        vs_main_cdEnqueue(_sydCdQueueSlot, _sydData);
        _sydFileLoading = 1;
        return 0;
    }
    if (_sydFileLoading == 0) {
        return 1;
    }

    if (_sydCdQueueSlot->state == 4) {
        vs_main_freeCdQueueSlot(_sydCdQueueSlot);
        _sydFileLoading = 0;
        return 1;
    }
    return 0;
}

// https://decomp.me/scratch/3biiU
INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_801077DC);

void func_8010785C(int arg0, int arg1)
{
    vs_battle_menuItem_t* temp_v0;

    temp_v0 = func_801077DC(arg0, arg1);
    temp_v0->state = 2;
    temp_v0->x = 0x9B;
    temp_v0->animSpeed = 0x140;
}

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80107894);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80107AD4);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80107EBC);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80107F14);

void func_801087E4(vs_battle_inventoryShield* shield)
{
    int i;
    vs_battle_inventoryArmor* base = &shield->base;

    vs_mainMenu_resetStats();

    for (i = 0; i < 16; ++i) {
        vs_mainMenu_equipmentStats[i] = base->classes[i & 7];
        vs_mainMenu_equipmentStats[16 + i] = base->affinities[i & 7];
    }

    for (i = 0; i < 4; ++i) {
        vs_mainMenu_equipmentStats[32 + i] = base->types[i];
    }

    vs_mainMenu_setDpPp(base->currentDp, base->maxDp, 0, 0);
    vs_mainMenu_setStrIntAgi(base->strength, base->intelligence, base->agility, 1);
    vs_mainMenu_strIntAgi[1].strength = base->strength;
    vs_mainMenu_strIntAgi[1].intelligence = base->intelligence;
    vs_mainMenu_strIntAgi[1].agility = base->agility;
    vs_mainMenu_equipmentSubtype = 8;
}

void func_80108908(int arg0)
{
    int var_s2;
    u_int temp_v1;
    int temp_s1;
    int temp_s3;
    vs_battle_inventoryShield* var_s0;

    temp_s1 = D_8010BD44[0];
    temp_s3 = D_8010BD44[1];

    var_s2 = temp_s1 > 0;

    if (temp_s3 != 0) {
        var_s2 += 2;
    }

    switch (var_s2) {
    case 0:
        vs_battle_rMemzero(&D_8010BD14, sizeof D_8010BD14);
        break;
    case 1:
    case 2:
        vs_battle_copyAligned(&D_8010BD14,
            &vs_battle_inventory.shields[temp_s1 + temp_s3 - 1], sizeof D_8010BD14);
        break;
    case 3:
        vs_battle_rMemzero(&D_8010BD14, sizeof D_8010BD14);
        func_8010B598(&vs_battle_inventory.shields[temp_s1 - 1].base,
            &vs_battle_inventory.shields[temp_s3 - 1].base, &D_8010BD14.base, _sydData);
        break;
    }

    var_s0 = &D_8010BD14;
    var_s0->unk1 = 0;

    vs_mainMenu_resetStats();

    temp_v1 = arg0 - 1;

    if (temp_v1 > 1) {
        if (var_s0->base.id != 0) {
            func_801087E4(var_s0);
        }
    } else if (var_s2 & arg0) {
        func_801087E4(&vs_battle_inventory.shields[D_8010BD44[temp_v1] - 1]);
    }
}

void func_80108A9C(vs_battle_inventoryShield* arg0, char** arg1, int* arg2, char* arg3)
{
    int temp_s1;

    temp_s1 = *(int*)arg0->gems;
    *(int*)arg0->gems = 0;
    func_800FCE40(arg0, arg1, arg2, arg3);
    *(int*)arg0->gems = temp_s1;
}

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80108AD4);

void func_80108E9C(char* arg0, char* arg1)
{
    arg0[9] = 0xF;
    arg0[12] = arg1[40];
    arg0[13] = arg1[1] != 0;
}

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80108EC4);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80109790);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_801099FC);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80109DBC);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80109DEC);

int func_8010A63C(int arg0)
{
    int i;
    vs_battle_inventoryArmor* var_a1 = vs_battle_inventory.armor;
    int var_a2 = 0;

    if (arg0 == 2) {
        for (i = 0; i < 16; ++i, ++var_a1) {
            int var_v1 = 0;
            if (var_a1->id != 0) {
                var_v1 = (var_a1->category ^ 7) > 0;
            }
            var_a2 += var_v1;
        }
    } else {
        var_a2 = func_800FEA6C((arg0 * 2) | 1, 0);
    }
    return var_a2;
}

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_8010A6BC);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_8010A978);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_8010AE38);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_8010B150);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_8010B2B4);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_8010B598);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_8010B80C);

// Potentially 2.7.2
// https://decomp.me/scratch/yg4QQ
INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_8010BA58);
