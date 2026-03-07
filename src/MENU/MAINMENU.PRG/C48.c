#include "common.h"
#include "C48.h"
#include "2D10.h"
#include "58EC.h"
#include "../SLUS_010.40/main.h"
#include "../MENUD.PRG/234.h"
#include "../BATTLE/BATTLE.PRG/146C.h"
#include "../BATTLE/BATTLE.PRG/2842C.h"
#include "../BATTLE/BATTLE.PRG/30D14.h"
#include "../BATTLE/BATTLE.PRG/44F14.h"
#include "../BATTLE/BATTLE.PRG/573B8.h"
#include "../BATTLE/BATTLE.PRG/5BF94.h"
#include "../BATTLE/BATTLE.PRG/func_8006B57C_t.h"
#include "../MENU0.PRG/84.h"
#include "../MENU1.PRG/30.h"
#include "../MENU2.PRG/64.h"
#include "../MENU2.PRG/143C.h"
#include "../MENU3.PRG/16C.h"
#include "../MENU4.PRG/120.h"
#include "../MENU5.PRG/4D8.h"
#include "../MENU7.PRG/260.h"
#include "../MENU8.PRG/88.h"
#include "../MENU8.PRG/21A0.h"
#include "../MENU9.PRG/238.h"
#include "../MENUB.PRG/260.h"
#include "../MENUC.PRG/168.h"
#include "../MENUD.PRG/234.h"
#include "../MENUE.PRG/494.h"
#include "../MENUF.PRG/3B8.h"
#include "gpu.h"
#include "vs_string.h"
#include <libetc.h>
#include <limits.h>

int func_800FA238(int arg0, int arg1, int arg2);
void func_800FA3FC(int arg0);
void func_800FB3C8(int);

extern u_long* D_1F800000[];

extern short D_801024AE;

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
        if (temp_s1->bodyParts[i].armor.unk9A != 0) {
            vs_battle_copyEquippedArmorStats(
                &vs_battle_inventory.armor[temp_s1->bodyParts[i].armor.unk9A - 1],
                &temp_s1->bodyParts[i].armor);
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

int vs_mainMenu_getEquipmentMaxStats(void* item, u_int itemCategory)
{
    static short _weaponTitleSubmaxThresholds[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90,
        100, SHRT_MAX };

    static short _weaponTitleMaxThresholds[] = { 50, 95, SHRT_MAX,
        8192 }; // Last one junk?

    int i;
    int subMaxRank;
    int maxRank;
    int isAffinity = 0;
    int param = 0;
    int maxParam = 0;
    int subMaxParam = 0;

    switch (itemCategory) {
    case 0:
        for (i = 0; i < 6; ++i) {
            if (maxParam
                < ((vs_battle_uiWeapon*)(item))->classAffinityCurrent.class[1][i]) {
                subMaxParam = maxParam;
                maxParam =
                    ((vs_battle_uiWeapon*)(item))->classAffinityCurrent.class[1][i];
                param = i;
            } else if (subMaxParam < ((vs_battle_uiWeapon*)(item))
                                         ->classAffinityCurrent.class[1][i]) {
                subMaxParam =
                    ((vs_battle_uiWeapon*)(item))->classAffinityCurrent.class[1][i];
            }
        }

        for (i = 0; i < 7; ++i) {
            if (maxParam
                < ((vs_battle_uiWeapon*)(item))->classAffinityCurrent.affinity[1][i]) {
                subMaxParam = maxParam;
                maxParam =
                    ((vs_battle_uiWeapon*)(item))->classAffinityCurrent.affinity[1][i];
                param = i;
                isAffinity = 1;
            } else if (subMaxParam < ((vs_battle_uiWeapon*)(item))
                                         ->classAffinityCurrent.affinity[1][i]) {
                subMaxParam =
                    ((vs_battle_uiWeapon*)(item))->classAffinityCurrent.affinity[1][i];
            }
        }

        break;

    case 1:
        for (i = 0; i < 6; ++i) {
            if (maxParam
                < ((vs_battle_uiShield*)(item))->classAffinityCurrent.class[1][i]) {
                subMaxParam = maxParam;
                maxParam =
                    ((vs_battle_uiShield*)(item))->classAffinityCurrent.class[1][i];
                param = i;
            } else if (subMaxParam < ((vs_battle_uiShield*)(item))
                                         ->classAffinityCurrent.class[1][i]) {
                subMaxParam =
                    ((vs_battle_uiShield*)(item))->classAffinityCurrent.class[1][i];
            }
        }

        for (i = 0; i < 7; ++i) {
            if (maxParam
                < ((vs_battle_uiShield*)(item))->classAffinityCurrent.affinity[1][i]) {
                subMaxParam = maxParam;
                maxParam =
                    ((vs_battle_uiShield*)(item))->classAffinityCurrent.affinity[1][i];
                param = i;
                isAffinity = 1;
            } else if (subMaxParam < ((vs_battle_uiShield*)(item))
                                         ->classAffinityCurrent.affinity[1][i]) {
                subMaxParam =
                    ((vs_battle_uiShield*)(item))->classAffinityCurrent.affinity[1][i];
            }
        }

        break;

    case 2:
    default:
        for (i = 0; i < 6; ++i) {
            if (maxParam
                < ((vs_battle_uiArmor*)(item))->classAffinityCurrent.class[1][i]) {
                subMaxParam = maxParam;
                maxParam = ((vs_battle_uiArmor*)(item))->classAffinityCurrent.class[1][i];
                param = i;
            } else if (subMaxParam
                       < ((vs_battle_uiArmor*)(item))->classAffinityCurrent.class[1][i]) {
                subMaxParam =
                    ((vs_battle_uiArmor*)(item))->classAffinityCurrent.class[1][i];
            }
        }

        for (i = 0; i < 7; ++i) {
            if (maxParam
                < ((vs_battle_uiArmor*)(item))->classAffinityCurrent.affinity[1][i]) {
                subMaxParam = maxParam;
                maxParam =
                    ((vs_battle_uiArmor*)(item))->classAffinityCurrent.affinity[1][i];
                param = i;
                isAffinity = 1;
            } else if (subMaxParam < ((vs_battle_uiArmor*)(item))
                                         ->classAffinityCurrent.affinity[1][i]) {
                subMaxParam =
                    ((vs_battle_uiArmor*)(item))->classAffinityCurrent.affinity[1][i];
            }
        }

        break;
    }

    subMaxRank = 0;
    for (i = 0; i < 11; ++i) {
        if (subMaxParam < _weaponTitleSubmaxThresholds[i]) {
            subMaxRank = i;
            break;
        }
    }

    maxRank = 0;
    for (i = 0; i < 3; ++i) {
        if (maxParam < _weaponTitleMaxThresholds[i]) {
            maxRank = i;
            break;
        }
    }

    {
        int a = (isAffinity * 6) + param;
        int b = subMaxRank + (maxRank << 8);
        return b + (a << 16);
    }
}

void vs_mainMenu_menuItemLeaveLeft(int arg0)
{
    vs_battle_menuItem_t* menuItem = vs_battle_getMenuItem(arg0 + 32);
    if (menuItem->state != 0) {
        menuItem->state = 5;
        menuItem->targetX = -menuItem->w;
    }
}

void func_800FA854(int arg0)
{
    int i;

    for (i = 0; i < 8; ++i) {
        if (i != arg0) {
            vs_mainMenu_menuItemLeaveLeft(i);
        }
    }
}

void vs_mainMenu_menuItemLeaveRight(int arg0)
{
    vs_battle_menuItem_t* menuItem;

    menuItem = vs_battle_getMenuItem(arg0);
    if (menuItem->state != 0) {
        menuItem->state = 2;
        menuItem->targetX = 320;
    }
}

void vs_mainMenu_clearMenuExcept(enum vs_mainMenu_menuItemIds id)
{
    int i;

    for (i = 0; i < 32; ++i) {
        if (i != id) {
            vs_mainMenu_menuItemLeaveRight(i);
        }
    }
}

void func_800FA92C(int arg0, int arg1)
{
    vs_battle_menuItem_t* menuItem;
    int i;

    for (i = arg1 * 10; i < 30; ++i) {
        vs_mainMenu_menuItemLeaveRight(i);
    }

    menuItem = vs_battle_getMenuItem(arg0 + (arg1 * 10));
    menuItem->state = 4;
    menuItem->targetX = 180;
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
    static int D_80102034 = 0;

    int temp_s0 = ++D_80102034;
    vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
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

void func_800FAAC8(int arg0)
{
    static int (*_submenuEntrypoints[])(char*) = { vs_menu0_exec, vs_menu1_exec,
        vs_menu2_exec, vs_menu3_exec, vs_menu4_exec, vs_menu5_exec, vs_menu7_dataMenu,
        vs_menu8_exec, vs_menu9_exec, vs_menuE_exec };

    int selectedMenu;
    int temp_s5;
    int var_s0;
    char* temp_s3;
    int temp_v1;
    vs_battle_menuState_t* ptr = &vs_battle_menuState;
    vs_battle_menuItem_t* menuItem = vs_battle_getMenuItem((arg0 - 1) & 0xF);
    int var_s4 = 0;
    vs_battle_inventory_t* inventory = &vs_battle_inventory;

    D_80102470 = inventory->weapons;
    D_80102464 = inventory->blades;
    D_80102460 = inventory->grips;
    D_8010246C = inventory->shields;
    D_80102468 = inventory->armor;
    D_80102458 = inventory->gems;

    temp_s3 = &D_800F4E70[arg0 & 0xF];
    temp_s5 = func_800C8C50(arg0);
    selectedMenu = arg0 & 0x3F;

    if (selectedMenu != 0) {
        if (selectedMenu == 31) {
            var_s4 = func_800FAA20();
        } else if (D_800F4EA0 & 0x200) {
            if (temp_s5 != 0) {
                if (selectedMenu == 15) {
                    var_s4 = func_80102BB8(temp_s3);
                } else if (selectedMenu == 3) {
                    var_s4 = vs_menu2_skillUnlock(temp_s3);
                } else if (selectedMenu == 14) {
                    var_s4 = func_80108C6C(temp_s3);
                } else if (selectedMenu == 8) {
                    var_s4 = vs_menu8_execRename(temp_s3);
                } else if (selectedMenu == 13) {
                    var_s4 = vs_menuC_exec(temp_s3);
                } else if (selectedMenu == 12) {
                    var_s4 = func_80109E90(temp_s3);
                } else if (selectedMenu == 7 && (D_800F4EA0 & 0x400)) {
                    var_s4 = vs_menu7_saveContainerMenu(temp_s3);
                } else if (selectedMenu == 7 && vs_main_stateFlags.gameOver == 1) {
                    var_s4 = vs_menu7_gameOver(temp_s3);
                } else {
                    D_800F4EA0 = 0;
                }
            }
        } else {
            temp_v1 = *temp_s3;
            switch (temp_v1) {
            case 0:
                if (!(arg0 & 0x40)) {
                    var_s0 = 0;
                    if (selectedMenu == 1) {
                        var_s0 = (D_800F4EA0 & 0xB7) != 0;
                    }
                    if (selectedMenu == 2) {
                        var_s0 = (D_800F4EA0 & 0x15F) != 0;
                    }
                    vs_battle_setMenuItem(selectedMenu - 1, 0x140, 0x12, 0x8C, 8,
                        (char*)&vs_battle_menuStrings[vs_battle_menuStrings[selectedMenu
                                                                            - 1]])
                        ->unk7 = var_s0;
                }
                if (((selectedMenu - 4) < 2U) || (selectedMenu == 7)
                    || (selectedMenu == 9)) {
                    func_800FFB68(1);
                }
                func_800FFA88(2);
                vs_mainMenu_clearMenuExcept(selectedMenu - 1);
                menuItem->state = 2;
                menuItem->targetX = 0xB4;
                menuItem->selected = 1;
                if (selectedMenu == 5) {
                    func_80100414(-2, 0x80);
                    menuItem->targetX = 0x140;
                }
                *temp_s3 = 1;
                break;
            case 1:
                var_s0 = menuItem->state;
                if (var_s0 == temp_v1) {
                    menuItem->state = 3;
                    menuItem->targetX = 0x12;
                    if (selectedMenu == 5) {
                        menuItem = vs_battle_setMenuItem(4, 0x140, 0x12, 0x8C, 8,
                            vs_battle_characterState->unk3C->name);
                        menuItem->state = 2;
                        menuItem->targetX = 0xB4;
                        menuItem->selected = var_s0;
                    }
                    *temp_s3 = 3;
                default:
                    if (temp_s5 != 0) {
                        var_s4 = _submenuEntrypoints[selectedMenu - 1](temp_s3);
                    }
                }
                break;
            }
        }
    } else {
        func_800FFA88(1);
        var_s0 = func_800C930C(0);
        if (var_s0 != 0) {
            if (var_s0 > 0) {
                var_s0 |= 0x40;
            } else {
                var_s0 = 0x1F;
                func_800FFA88(0);
            }
            ptr->currentState = var_s0;
        }
    }

    if ((var_s4 == 0) || (func_800FAA5C(ptr->currentState) == 0)) {
        func_80101F38();
    }
}

void func_800FAEBC(int arg0)
{
#pragma vsstring(start)
    // Fixed size to force truncation of final (junk) byte
    static char D_80102060[8] = "MISC\00000|!0|";
#pragma vsstring(end)

    int j;
    int i;
    int var_s5;
    int* temp_fp;
    char** temp_s7;
    int temp_v0_3;
    u_int var_a0;
    void* temp_s6;
    vs_battle_inventoryMisc* temp_s0;
    vs_battle_menuItem_t* temp_v0;

    if (arg0 != 0) {
        func_800FFBC8();
        if (arg0 & 1) {
            D_80102456 = 1;
        }
        D_80102454 = 0;
        return;
    }
    switch (D_80102454) {
    case 0:
        temp_v0 = vs_battle_setMenuItem(0, 0x140, 0x12, 0x8C, 8,
            (char*)&vs_battle_menuStrings[vs_battle_menuStrings[3]]);
        temp_v0->state = 2;
        temp_v0->selected = 1;
        temp_v0->targetX = 0xB4;
        temp_v0->unk7 = (D_800F4EA0 & 7) != 0;
        D_80102454 = 1;
        vs_mainMenu_loadItemNames(1);
        break;
    case 1:
        if ((vs_mainmenu_ready() != 0) && (vs_mainMenu_loadItemNames(0) != 0)) {
            temp_v0 = vs_battle_setMenuItem(0xA, 0x140, 0x22, 0x8C, 8, D_80102060);
            temp_v0->state = 2;
            temp_v0->targetX = 0xB4;
            temp_v0->selected = 1;
            D_80102454 = 2;
        }
        break;
    case 2:
        temp_s6 = vs_main_allocHeapR(0x1B00U);
        var_s5 = 0;
        vs_mainMenu_rebuildInventory(6);
        temp_fp = temp_s6 + 0x1800;
        temp_s7 = temp_s6 + 0x1900;

        for (i = 0; i < 64; ++i, ++var_s5) {
            temp_v0_3 = D_800619D8.unk70[i];
            if (temp_v0_3 == 0) {
                break;
            }
            temp_s0 = &vs_battle_inventory.items[temp_v0_3 - 1];
            vs_mainMenu_setItemUi(
                temp_s0, &temp_s7[i * 2], temp_fp - -i, temp_s6 + i * 96);
            if (temp_s0->id < 0x1CA) {
                var_a0 = D_80102214[temp_s0->id - 0x143];
                if ((var_a0 - 0x6A) < 0x1C) {
                    for (j = 0; j < 3; ++j) {
                        if (vs_main_skills[var_a0].unlocked) {
                            ++var_a0;
                        }
                    }
                }
                D_80102410[i] = var_a0;
            }
            if ((D_800F4EA0 & 7) || (temp_s0->id >= 0x1CA)
                || (vs_battle_getSkillFlags(0, D_80102410[i]) & 2)) {
                temp_fp[i] |= 1;
            }
        }
        D_80102455 = var_s5 == 0;
        if (D_80102455 != 0) {
            vs_mainmenu_setInformationMessage((char*)&vs_mainMenu_itemHelp[0x33E3]);
        } else {
            i = vs_main_settings.cursorMemory;
            if (D_80102456 != 0) {
                D_80102456 = 0;
            } else {
                vs_main_settings.cursorMemory = 1;
            }
            vs_mainmenu_setMenuRows(var_s5, 0x19224, temp_s7, temp_fp);
            vs_main_settings.cursorMemory = i;
        }
        vs_main_freeHeapR(temp_s6);
        D_80102454 = 3;
        break;
    case 3:
        if (D_80102455 != 0) {
            if (vs_main_buttonsPressed.all & 0x70) {
                if (vs_main_buttonsPressed.all & 0x20) {
                    func_800C02E0();
                } else {
                    vs_battle_playMenuLeaveSfx();
                    vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
                    func_800FFBA8();
                    D_80102450 = -1;
                    D_80102454 = 4;
                }
            }
        } else {
            D_80102450 = vs_mainmenu_getSelectedRow() + 1;
            if (D_80102450 != 0) {
                vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
                func_800FFBA8();
                if (D_80102450 > 0) {
                    D_800F5210 = D_800619D8.unk70[D_80102450 - 1] - 1;
                    D_800F4E98.executeAbility.s16[0] = D_80102410[D_80102450 - 1];
                    D_800F4E98.executeAbility.s16[1] =
                        vs_battle_inventory.items[D_800F5210].id;
                }
                D_80102454 = 4;
            }
        }
        break;
    case 4:
        if ((vs_mainmenu_ready() != 0) && (vs_mainMenu_ensureItemNamesLoaded() != 0)) {
            if (D_80102450 > 0) {
                D_800F4E98.unk2 = 8;
            }
            vs_battle_menuState.currentState = 0x3F;
            D_800F4E98.unk0 = 2;
            return;
        }
        break;
    }
    func_80101F38();
    return;
}

static inline int inline_fn(int a0, int a1, int a2) { return (a0 - (a1 - a2)) & 0xFFFF; }

void func_800FB3C8(int arg0)
{
    static char const* D_80102068[] = { "#HUMAN", "#BEAST", "#UNDEAD", "#PHANTOM",
        "#DRAGON", "#EVIL", NULL, NULL, "#PHYSICAL", "#AIR", "#FIRE", "#EARTH", "#WATER",
        "#LIGHT", "#DARK", NULL, "#BLUNT", "#EDGED", "#PIERCING" };
    static int D_801020B4[] = { 0x40817318, 0x40D0E030, 0x40D0E030, 0x40817318 };
    static int D_801020C4[] = { 0x40693F6E, 0x409F78DC, 0x409F78DC, 0x40693F6E };
#pragma vsstring(start)
    static char D_801020D4[] = "|f0|CLASS|f0|/|f0|AFFINITY|f0|/|f0|TYPE";
#pragma vsstring(end)

    int sp10;
    int sp14;
    int sp18;
    int sp1C;
    short* sp20;
    short* sp24;
    int sp28;
    short* var_s7;
    int temp_a0;
    int temp_a0_2;
    int i;
    int i_2;
    int j;
    int temp_v0_2;
    int temp_v0_3;
    int temp_v1_3;
    int var_s6;
    u_long* var_a2_2;
    u_long* temp_s4;
    int a0;

    temp_s4 = D_1F800000[1] - 3;
    sp10 = D_801024B9;

    switch (sp10) {
    case 0:
        var_s7 = vs_mainMenu_equipmentStats;
        sp20 = &var_s7[8];
        sp24 = &var_s7[0x30];
        sp18 = 0x60;
        break;
    case 1:
        var_s7 = vs_mainMenu_equipmentStats + 16;
        sp20 = &var_s7[8];
        sp24 = &var_s7[0x28];
        sp18 = 0x70;
        sp1C = var_s7[0];
        for (i = 0; i < 7; ++i) {
            if (sp1C < var_s7[i]) {
                sp1C = var_s7[i];
            }
        }
        break;
    case 2:
        var_s7 = vs_mainMenu_equipmentStats + 33;
        sp20 = var_s7;
        sp18 = 0x30;
        break;
    }

    for (var_s6 = 0; var_s6 < sp18; var_s6 += 0x10) {

        sp14 = (arg0 + 0x74) & 0xFFFF;
        sp28 = (arg0 + 0x58) & 0xFFFF;

        j = var_s6 >> 4;

        if (vs_mainMenu_equipmentStats[63] != 0) {
            if ((D_80102544 == 7) && (sp10 != 2)) {
                i = func_800FFE20(var_s7[j] - sp24[j],
                    ((arg0 + 0xA4) & 0xFFFF) | (0x400000 + var_s6 * 0x10000), 0, temp_s4);
                if (var_s7[j] > sp24[j]) {
                    vs_battle_renderTextRawColor("#+", i + 1, 0x804020, temp_s4);
                }
                if (var_s7[j] == sp24[j]) {
                    vs_battle_renderTextRawColor("#*", i + 1, 0x808080, temp_s4);
                }
            }
        }

        i = 0x808080;
        a0 = vs_mainMenu_equipmentSubtype;

        if ((a0 == 1) && ((D_80102544 == 7) && (sp10 != 0))) {
            if (sp10 == a0) {
                if (sp20[j] != var_s7[j]) {
                    if (sp20[j] < var_s7[j]) {
                        i = 0x804020;
                    } else {
                        i = 0x204080;
                    }
                } else {
                    i = 0x808080;
                    if (sp20[j] != sp1C) {
                        i = 0x404040;
                    }
                }
                vs_mainMenu_printIntColor(
                    var_s7[j], sp28 | (0x400000 + var_s6 * 0x10000), i, temp_s4);
                i = 0x404040;
                if (var_s7[j] == sp1C) {
                    i = 0x808080;
                    sp1C = 0xFFFF;
                }
            } else {
                if (j != (vs_mainMenu_equipmentStats[36] - 1)) {
                    i = 0x404040;
                }
                vs_mainMenu_printIntColor(
                    var_s7[j], sp28 | (0x400000 + var_s6 * 0x10000), i, temp_s4);
            }
        } else {
            func_800FFE20(
                var_s7[j], sp28 | (0x400000 + var_s6 * 0x10000), sp20[j], temp_s4);
        }
        vs_battle_renderTextRawColor(D_80102068[j + (sp10 * 8)],
            ((arg0 + 0x40) & 0xFFFF) | (0x400000 + var_s6 * 0x10000), i, temp_s4);
        func_800CCCB8(temp_s4, 0x40D0E030, sp14 | ((var_s6 + 0x42) << 0x10),
            sp14 | ((var_s6 + 0x45) << 0x10));
        func_800CCCB8(temp_s4, 0x40978918, sp14 | (0x400000 + var_s6 * 0x10000),
            sp14 | ((var_s6 + 0x47) << 0x10));
        j = (var_s7[j] * 0x18) / 100;

        if (j > 0x18) {
            j = 0x18;
        }
        if (j < -0x18) {
            j = -0x18;
        }

        if (j >= 0) {
            for (i = 0; i < 4; ++i) {
                temp_v0_2 = (var_s6 + i + 0x42) << 0x10;
                func_800CCCB8(temp_s4, D_801020B4[i], sp14 | temp_v0_2,
                    ((arg0 + j + 0x74) & 0xFFFF) | temp_v0_2);
                if (j == (0x18 - i)) {
                    --j;
                }
            }
        } else {
            for (i = 0; i < 4; ++i) {
                temp_v0_3 = ((var_s6 - i) + 0x45) << 0x10;
                func_800CCCB8(temp_s4, D_801020C4[i], sp14 | temp_v0_3,
                    ((arg0 + j + 0x74) & 0xFFFF) | temp_v0_3);
                if (j == (i - 0x18)) {
                    j = i - 0x17;
                }
            }
        }

        for (j = 2; j < 6; ++j) {
            func_800CCCB8(temp_s4, 0x40330500,
                inline_fn(arg0, j, 0x61) | ((var_s6 + j + 0x40) << 0x10),
                inline_fn(arg0, j, 0x8E) | ((var_s6 + j + 0x40) << 0x10));
        }

        for (j = 0; j < 8; ++j) {
            func_800CCCB8(temp_s4, 0x405D3200,
                inline_fn(arg0, j, 0x61) | ((var_s6 + j + 0x40) << 0x10),
                inline_fn(arg0, j, 0x91) | ((var_s6 + j + 0x40) << 0x10));
        }

        func_800CCD00(0xE1000000, temp_s4);
        var_a2_2 = D_1F800000[0];

        for (j = 0; j < 11; ++j) {
            temp_a0 = var_s6 + j;
            temp_v1_3 = j - 0x60;
            temp_a0_2 = (temp_a0 + 0x40) << 0x10;
            var_a2_2[0] = (*temp_s4 & 0xFFFFFF) | 0x04000000;
            var_a2_2[1] = 0x50330500;
            var_a2_2[2] = ((arg0 & 0xFFFF) | temp_a0_2);
            var_a2_2[3] = 0x5D3200;
            var_a2_2[4] = (((arg0 - temp_v1_3) & 0xFFFF) | temp_a0_2);
            *temp_s4 = ((u_long)var_a2_2 << 8) >> 8;
            var_a2_2 += 5;
        }

        D_1F800000[0] = var_a2_2;
        func_800CCD00(0xE1000200, temp_s4);
    }

    vs_mainMenu_drawButtonUiBackground(arg0 + 0x18, 0x30, 0x87, 0xC);
    vs_mainmenu_drawButton(1, arg0 + 0x10, 0x2E, temp_s4 - 1);

    arg0 = (arg0 & 0xFFFF) + 0x22;

    for (j = 0; j < 3; ++j) {
        D_801020D4[(0x180B01 >> (j * 8)) & 0xFF] = ((D_80102544 >> j) & 1) ? 0 : 3;
    }

    D_801020D4[(0x180B01 >> (D_801024B9 * 8)) & 0xFF] = 1;

    for (i_2 = 0; i_2 < 29; ++i_2) {
        i = D_801020D4[i_2];
        if (i == 0xFB) {
            ++i_2;
            func_800C7210(D_801020D4[i_2] + 4);
        } else {
            arg0 = func_800C70F8(i, arg0, 0x30, temp_s4 - 4);
        }
    }
}

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

void vs_mainMenu_drawClassAffinityType(int arg0)
{
    static int D_801020F4 = 0;
    static u_char D_801020F8 = 0;

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
    vs_mainMenu_strIntAgi[0] = strength;
    vs_mainMenu_strIntAgi[1] = intelligence;
    vs_mainMenu_strIntAgi[2] = agility;
    vs_mainMenu_strIntAgi[3] = arg3;
    vs_mainMenu_setRangeRisk(0, 0, 0, 0);
    vs_battle_memcpy(&vs_mainMenu_strIntAgi[4], &vs_mainMenu_strIntAgi[0], 8);
}

void func_800FBD80(int arg0)
{
    vs_battle_actor2* temp_t0 = vs_battle_actors[arg0 & 0xF]->unk3C;
    D_80102488[3] = arg0 & 0xF;
    D_80102498[0] = temp_t0->accessory.currentStr;
    D_80102498[1] = temp_t0->accessory.currentInt;
    D_80102498[2] = temp_t0->accessory.currentAgility;
    D_80102488[0] = temp_t0->strength;
    D_80102488[1] = temp_t0->intelligence;
    D_80102488[2] = temp_t0->agility;
    D_80102488[4] = temp_t0->totalStrength;
    D_80102488[5] = temp_t0->totalIntelligence;
    vs_mainMenu_equipmentSubtype = 0;
    D_80102488[6] = temp_t0->totalAgility;

    if (arg0 < 16) {
        int i;
        for (i = 0; i < 3; ++i) {
            D_80102488[i] -= D_80102488[4 + i];
        }
        vs_mainMenu_setStrIntAgi(temp_t0->totalStrength, temp_t0->totalIntelligence,
            temp_t0->totalAgility, temp_t0->flags.fields.unk2_1 | (arg0 == 0));
        vs_battle_rMemzero(&D_80102490, 8);
    }
}

// arg0: 0 = render, 1 = slide in, 2 = slide out
void vs_mainMenu_renderEquipStats(int arg0)
{
    static char const* D_801020FC[] = { "#RANGE", "#RISK" };
    static char const* D_80102104[] = { "#STRENGTH", "#INTELLIGENCE", "#AGILITY", NULL,
        "#ATTACK/STR", "#ATTACK/INT", "#AGILITY", NULL, "#DEFENSE/STR", "#DEFENSE/INT",
        "#AGILITY" };
    static char D_80102130 = 0;
    static u_char D_80102131 = 0;

    int temp_fp;
    int temp_s0;
    int var_a3;
    int statName;
    int i;
    u_long* temp_s4;
    int position;
    vs_battle_actor2* actor;

    position = vs_getXY(248, 126);
    actor = vs_battle_actors[D_80102488[3]]->unk3C;
    temp_s4 = D_1F800000[1] - 6;

    if (arg0 != 0) {
        if (D_80102130 != arg0) {
            D_80102130 = arg0;
            D_80102131 = 0xF - (arg0 * 4);
        }
        return;
    }

    temp_fp = D_801024AE;

    if (D_80102130 == 1) {
        if (D_80102131 != 0) {
            position += vs_battle_rowAnimationSteps[D_80102131];
            --D_80102131;
        }
    } else if (D_80102131 == 0) {
        return;
    } else {
        position += ((8 - D_80102131) << 5);
        --D_80102131;
    }

    if (D_80102480[3] != 0) {
        vs_battle_renderTextRaw("ORG/EQP", position + 4, temp_s4);

        for (i = 0; i < 2; ++i) {
            position += vs_getXY(0, 10);
            vs_battle_renderTextRaw(D_801020FC[i], position, temp_s4);
            if (temp_fp != 0) {
                temp_s0 = D_80102480[i];
                func_800FFE70(temp_s0, position + 28, temp_s4);
                if (i == 0) {
                    temp_s0 += actor->unk38 - actor->weapon.range.unk0;
                }
                func_800FFE70(temp_s0, position + 60, temp_s4);
            } else {
                vs_battle_renderTextRaw("#??", position + 28, temp_s4);
                vs_battle_renderTextRaw("#??", position + 60, temp_s4);
            }
        }
    } else {
        position += vs_getXY(0, 20);
        vs_battle_renderTextRaw("ORG/EQP", position + 4, temp_s4);
    }
    for (i = 0; i < 3; ++i) {
        position += vs_getXY(0, 10);
        statName = ((vs_mainMenu_equipmentSubtype & 7) != 0) * 4;
        vs_battle_renderTextRaw(
            D_80102104[vs_mainMenu_equipmentSubtype & 0x18 ? 8 + statName + i
                                                           : statName + i],
            position, temp_s4);

        if (temp_fp != 0) {
            int new_var2;
            temp_s0 = vs_mainMenu_strIntAgi[i];
            func_800FFE20(temp_s0, position + 28, vs_mainMenu_strIntAgi[i + 4], temp_s4);
            new_var2 = temp_s0 + D_80102488[i + 4];
            temp_s0 += D_80102488[i];
            var_a3 = temp_fp & 1;
            if (var_a3 != 0) {
                var_a3 = D_80102498[i];
            }
            func_800FFE20(temp_s0 + var_a3, position + 60, new_var2 + var_a3, temp_s4);
        } else {
            vs_battle_renderTextRaw("#??", position + 28, temp_s4);
            vs_battle_renderTextRaw("#??", position + 60, temp_s4);
        }
    }
}

static u_short D_80102132 = 0;
static u_short _currentDp = 0;
static u_short _maxDp = 0;
static u_short _currentPp = 0;
static u_short _maxPp = 0;

void vs_mainMenu_setDpPp(int currentDp, int maxDp, int currentPp, int maxPp)
{
    _currentPp = currentPp;
    _maxPp = maxPp;
    _currentDp = (currentDp + 99) / 100;
    _maxDp = (maxDp + 99) / 100;
}

void vs_mainMenu_drawDpPpbars(int arg0)
{
    static char D_8010213C = 1;
    static char D_8010213D = 0;

    int temp_s1;
    void* temp_s2 = D_1F800000[1] - 3;

    if (arg0 != 0) {
        D_8010213C = arg0 >> 2;
        if (!(D_8010213C & 1)) {
            D_8010213D = arg0 & 3;
        }
    } else {
        int var_s0 = D_80102132;

        switch (D_8010213C) {
        case 0:
            if (var_s0 < 5) {
                ++D_80102132;
            }
            break;
        case 1:
            if (var_s0 != 0) {
                --D_80102132;
            }
            break;
        case 2:
            D_80102132 = 5;
            break;
        }

        if (D_80102132 != 0) {

            temp_s1 = ((D_80102132 * 8) - 8) << 0x10;

            if (D_8010213D & 1) {
                vs_battle_renderTextRaw("DP", (temp_s1 + 0xFFFF0000) | 0xA, temp_s2);
                var_s0 = vs_battle_renderValue(0, temp_s1 | 0x42, _maxDp, temp_s2);
                vs_battle_renderValue(2, var_s0, 0, temp_s2);
                vs_battle_renderValue(1, var_s0 + 0xFFFEFFF9, _currentDp, temp_s2);
            }
            if (D_8010213D & 2) {
                vs_battle_renderTextRaw("PP", (temp_s1 + 0xFFFF0000) | 0x50, temp_s2);
                var_s0 = vs_battle_renderValue(0, temp_s1 | 0x88, _maxPp, temp_s2);
                vs_battle_renderValue(2, var_s0, 0, temp_s2);
                vs_battle_renderValue(1, var_s0 + 0xFFFEFFF9, _currentPp, temp_s2);
            }

            temp_s1 = temp_s1 + 0x80000;

            if (D_8010213D & 1) {
                var_s0 = _maxDp;
                if (var_s0 == 0) {
                    var_s0 = 1;
                }
                vs_battle_drawStatBar(0, (((_currentDp << 6) + var_s0) - 1) / var_s0,
                    temp_s2, temp_s1 | 0xA);
            }
            if (D_8010213D & 2) {
                var_s0 = _maxPp;
                if (var_s0 == 0) {
                    var_s0 = 1;
                }
                vs_battle_drawStatBar(1, (((_currentPp << 6) + var_s0) - 1) / var_s0,
                    temp_s2, temp_s1 | 0x50);
            }
        }
    }
}
