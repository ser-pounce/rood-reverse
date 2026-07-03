#pragma once
#include <stddef.h>
#include "../../SLUS_010.40/main.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"

enum vs_mainMenu_menuItemIds { vs_mainMenu_menuItemIds_none = 40 };

/**
 * Initializes the inventory with Ashley's current equipment.
 */
void vs_mainMenu_initInventory(void);

/**
 * Dismisses the specified row to the left.
 */
void vs_mainMenu_menuItemFlyoutLeft(int row);

/**
 * Dismisses the specified row to the right.
 */
void vs_mainMenu_menuItemFlyoutRight(int row);

/**
 * Ranks the two top class and affinity values.
 *
 * @return Packed value:
 *
 * - Bits 0-7: The rank from 0-10 of the second highest stat.
 *
 * - Bits 8-15: The rank from 0-3 of the highest stat.
 *
 * - Bits 16+: The highest stat identifier, where 0-5 == class, 6-12 == affinity.
 */
int vs_mainMenu_getEquipmentMaxStats(void* item, u_int itemCategory);

/**
 * Dismisses all to the left but one row.
 */
void vs_mainMenu_flyoutLeftExcept(int row);

/**
 * Clears entire menu except for the specified row using vs_mainMenu_menuItemFlyoutRight.
 *
 * @param id Can be set to vs_mainMenu_menuItemIds_none to indicate that
 * all rows are to be cleared.
 */
void vs_mainMenu_clearMenuExcept(enum vs_mainMenu_menuItemIds id);

/**
 * Indicates when the menu is at rest.
 *
 * @return true / false.
 */
int vs_mainmenu_ready(void);

/**
 * Invokes vs_mainMenu_menuItemFlyoutRight for all rows >= offset,
 * with the exception of row which is hoisted to the top of the menu.
 *
 * @param offset 0, 1, or 2 to indicate row 0, 10, or 20 respectively.
 */
void vs_mainMenu_flyoutMenuRightAndHoistSelection(int row, int offset);
void vs_mainMenu_exec(int);
void func_800FAEBC(int);
void func_800FBB8C(int arg0);
void vs_mainMenu_drawClassAffinityType(int);
void vs_mainMenu_setRangeRisk(int arg0, int arg1, int arg2, int arg3);
void vs_mainMenu_setStrIntAgi(int, int, int, int);
void func_800FBD80(int);
void vs_mainMenu_renderEquipStats(int);
void vs_mainMenu_setDpPp(int, int, int, int);

enum vs_mainMenu_renderDpPpBarsTarget {
    renderDpPpBarsTargetNone,
    renderDpPpBarsTargetDp,
    renderDpPpBarsTargetPp,
    renderDpPpBarsTargetBoth
};

enum vs_mainMenu_renderDpPpBarsState {
    renderDpPpBarsStatSlideIn = 0 << 2,
    renderDpPpBarsStatSlideOut = 1 << 2,
    renderDpPpBarsStatStatic = 2 << 2
};

/**
 * Renders and optionally animates the DP and PP bars.
 *
 * @param flags Composed of either or both of vs_mainMenu_renderDpPpBarsTarget,
 * and one of vs_mainMenu_renderDpPpBarsState.
 */
void vs_mainMenu_renderDpPpBars(int flags);
void vs_mainMenu_setUiWeapon(vs_battle_uiWeapon*, char**, int*, char*);
vs_battle_menuItem_t* vs_mainMenu_initWeaponDetailsMenu(int, int, int);
vs_battle_menuItem_t* vs_mainMenu_initSetShieldGemMenu(int, int, int);
void vs_mainMenu_initUiWeapon(
    vs_main_inventoryWeapon* arg0, char** arg1, int* arg2, char* arg3);
void vs_mainMenu_setUiBlade(vs_main_inventoryBlade*, char**, int*, char*);
void vs_mainMenu_setUiGrip(vs_main_inventoryGrip*, char**, int*, char*);
void vs_mainMenu_initUiShield(
    vs_main_inventoryShield* arg0, char** arg1, int* arg2, char* arg3);
void vs_mainMenu_setUiShield(vs_battle_uiShield*, char**, int*, char*);
void vs_mainMenu_setUiArmor(vs_battle_uiArmor*, char**, int*, char*);
void vs_mainMenu_initUiArmor(
    vs_main_inventoryArmor* arg0, char** arg1, int* arg2, char* arg3);
void vs_mainMenu_setUiGem(vs_main_inventoryGem* arg0, char** arg1, int* arg2, void* arg3);
void vs_mainMenu_setUMisc(
    vs_main_inventoryMisc* arg0, char** arg1, int* arg2, void* arg3);
void vs_mainMenu_setUiBladeStats(int);
void vs_mainMenu_setUiGripStats(int);
void vs_mainMenu_setShieldStats(int);
void vs_mainMenu_setArmorStats(int);
void vs_mainMenu_setGemStats(int);
void vs_mainMenu_resetStats(void);
void vs_mainMenu_unpackMenubg(u_int*);

extern char vs_mainMenu_weaponHands[];
extern vs_menu_inventoryStorage_t* vs_menu_inventoryStorage;
extern char D_80102578;
