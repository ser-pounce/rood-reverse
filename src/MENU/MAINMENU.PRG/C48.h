#pragma once
#include "src/SLUS_010.40/main.h"
#include "src/BATTLE/BATTLE.PRG/5BF94.h"
#include <stddef.h>

enum vs_mainMenu_menuItemIds { vs_mainMenu_menuItemIds_none = 40 };

/**
 * Initializes the inventory with Ashley's current equipment.
 */
void vs_mainMenu_initInventory(void);

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
 * Dismisses the specified row to the left.
 */
void vs_mainMenu_menuItemFlyoutLeft(int row);

/**
 * Dismisses all to the left but one row.
 */
void vs_mainMenu_flyoutLeftExcept(int row);

/**
 * Dismisses the specified row to the right.
 */
void vs_mainMenu_menuItemFlyoutRight(int row);

/**
 * Clears entire menu except for the specified row using vs_mainMenu_menuItemFlyoutRight.
 *
 * @param id Can be set to vs_mainMenu_menuItemIds_none to indicate that
 * all rows are to be cleared.
 */
void vs_mainMenu_clearMenuExcept(enum vs_mainMenu_menuItemIds id);

/**
 * Invokes vs_mainMenu_menuItemFlyoutRight for all rows >= offset,
 * with the exception of row which is hoisted to the top of the menu.
 *
 * @param offset 0, 1, or 2 to indicate row 0, 10, or 20 respectively.
 */
void vs_mainMenu_flyoutMenuRightAndHoistSelection(int row, int offset);

/**
 * Indicates when the menu is at rest.
 *
 * @return true / false.
 */
int vs_mainmenu_ready(void);

/**
 * Main entrypoint.
 */
void vs_mainMenu_exec(int);

/**
 * Invoked from the shortcut menu in BATTLE.PRG.
 *
 * @param initialize +ive to trigger initialization, if == 1
 * then additionally prevent forced cursor memory.
 */
void vs_mainMenu_miscItemsShortcutMenu(int initialize);

enum vs_mainMenu_statPageEnabled {
    statPageEnabledClass = 1 << 0,
    statPageEnabledAffinity = 1 << 1,
    statPageEnabledType = 1 << 2,
    statPageEnabledAll =
        statPageEnabledClass | statPageEnabledAffinity | statPageEnabledType
};

/**
 * Flips between the class / affinity / type pages
 */
void vs_mainMenu_updateStatPage(int arg0);

void vs_mainMenu_drawClassAffinityType(int);
void vs_mainMenu_setRangeRisk(int arg0, int arg1, int arg2, int arg3);
void vs_mainMenu_setStrIntAgi(int, int, int, int);
void vs_mainMenu_populateBaseStats(int);
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

extern vs_main_inventoryGem* vs_mainMenu_gems;
extern vs_menu_inventoryStorage_t* vs_menu_inventoryStorage;
extern vs_main_inventoryGrip* vs_mainMenu_grips;
extern vs_main_inventoryBlade* vs_mainMenu_blades;
extern vs_main_inventoryArmor* vs_mainMenu_armor;
extern vs_main_inventoryShield* vs_mainMenu_shields;
extern vs_main_inventoryWeapon* vs_mainMenu_weapons;
