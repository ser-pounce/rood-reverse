#pragma once
#include "src/SLUS_010.40/main.h"
#include "src/BATTLE/BATTLE.PRG/5BF94.h"

/**
 * Initializes the specified weapon details row.
 *
 * @param row 1 == blade, 2 == grip, 3+ == gem
 * @param slide Whether the row should slide to a fixed x position (320)
 */
vs_battle_menuItem_t* vs_mainMenu_initWeaponDetailsRow(
    int gem, int weaponIndex, int slide);

/**
 * Initializes the specified shield details row.
 *
 * @param row The gem row
 * @param slide Whether the row should slide to a fixed x position (320)
 */
vs_battle_menuItem_t* vs_mainMenu_initShieldDetailsRow(
    int row, int shieldIndex, int slide);

/**
 * Prints the weapon's description to `buf` and assigns it to `menuText[1]`,
 * and sets the row type to display the correct category and material.
 */
void vs_mainMenu_setWeaponRow(
    vs_battle_uiWeapon* weapon, char* menuText[], int* rowType, void* buf);

/**
 * Identical to `vs_mainMenu_setWeaponRow`, but operates on a
 * `vs_main_inventoryWeapon`. Also sets `menuText[0]` to the weapon name.
 */
void vs_mainMenu_setWeaponRowFromInventory(
    vs_main_inventoryWeapon* weapon, char* menuText[], int* rowType, void* buf);

/**
 * Assigns the blade name to `menuText[0]`, prints the blade's description
 * to `buf` and assigns it to `menuText[1]`, and sets the row type to
 * display the correct category and material.
 */
void vs_mainMenu_setBladeRow(
    vs_main_inventoryBlade* blade, char* menuText[], int* rowType, void* buf);

/**
 * Assigns the grip name to `menuText[0]`, prints the grip's description
 * to `buf` and assigns it to `menuText[1]`, and sets the row type to
 * display the correct category.
 */
void vs_mainMenu_setGripRow(
    vs_main_inventoryGrip* grip, char* menuText[], int* rowType, void* buf);

/**
 * Assigns the shield name to `menuText[0]`, prints the shield's description
 * to `buf` and assigns it to `menuText[1]`, and sets the row type to
 * display the correct category and material.
 */
void vs_mainMenu_setShieldRow(
    vs_battle_uiShield* shield, char* menuText[], int* rowType, void* buf);

/**
 * Identical to `vs_mainMenu_setShieldRow`, but operates on a
 * `vs_main_inventoryShield`.
 */
void vs_mainMenu_setShieldRowFromInventory(
    vs_main_inventoryShield* shield, char* menuText[], int* rowType, void* buf);

/**
 * Assigns the armor name to `menuText[0]`, prints the armor's description
 * to `buf` and assigns it to `menuText[1]`, and sets the row type to
 * display the correct category and material.
 */
void vs_mainMenu_setArmorRow(
    vs_battle_uiArmor* armor, char* menuText[], int* rowType, void* buf);

/**
 * Identical to `vs_mainMenu_setArmorRow`, but operates on a
 * `vs_main_inventoryArmor`.
 */
void vs_mainMenu_setArmorRowFromInventory(
    vs_main_inventoryArmor* shield, char* menuText[], int* rowType, void* buf);

/**
 * Assigns the gem name to `menuText[0]`, prints the gem's description
 * to `buf` and assigns it to `menuText[1]`, and sets the row type to
 * display the correct category.
 */
void vs_mainMenu_setGemRow(
    vs_main_inventoryGem* gem, char* menuText[], int* rowType, void* buf);

/**
 * Assigns the item name to `menuText[0]`, prints the item's description
 * to `buf` and assigns it to `menuText[1]`, and sets the row type to
 * display the item count.
 */
void vs_mainMenu_setMiscRow(
    vs_main_inventoryMisc* misc, char* menuText[], int* rowType, void* buf);

/**
 * Resets the Dp/Pp bars, and the numeric stats on the bottom right.
 */
void vs_mainMenu_resetStats(void);

void vs_mainMenu_setWeaponRowStats(int);
void vs_mainMenu_setBladeRowStats(int);
void vs_mainMenu_setGripRowStats(int);
void vs_mainMenu_setShieldStats(int);
void vs_mainMenu_setArmorStats(int);
void vs_mainMenu_setGemStats(int);
void vs_mainMenu_resetStatusViewCursor(void);
void vs_mainMenu_renderStatusView(void);
void vs_mainMenu_unequipAllWeapons(void);
void vs_mainMenu_unequipShield(void);
void vs_mainMenu_initItem(int, int);
int vs_mainMenu_loadItemNames(int);
int vs_mainMenu_ensureItemNamesLoaded(void);
int vs_mainMenu_findItem(int category, int id);
void vs_mainMenu_rebuildInventory(int);
int vs_mainMenu_getItemCount(int itemCategory, vs_main_inventory_t* inventory);
int vs_mainMenu_getFirstEmptyItemSlot(int, vs_main_inventory_t*);

enum vs_mainMenu_copyItem_flags { copyItemFlagsWrite = 0x10 };

int vs_mainMenu_copyItem(
    int arg0, vs_main_inventory_t* arg1, int arg2, vs_main_inventory_t* arg3);

extern char vs_mainMenu_weaponHands[];
extern char vs_mainMenu_equipmentDetailNavigationMap[][4];
extern int vs_mainMenu_statCursorPositions[];
extern int vs_mainMenu_mainCursorXY[];
extern char vs_mainMenu_miscItemToSkillMap[];
extern char (*vs_mainMenu_itemNames)[24];
extern char vs_mainMenu_inventoryItemCapacities[];
extern char* vs_mainMenu_inventoryIndices[];
