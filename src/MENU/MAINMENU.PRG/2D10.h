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

/**
 * Sets up the stats UI using the specified weapon.
 */
void vs_mainMenu_setStatsFromWeapon(int weaponIndex);

/**
 * Sets up the stats UI using the specified blade.
 */
void vs_mainMenu_setStatsFromBlade(int bladeIndex);

/**
 * Sets up the stats UI using the specified grip.
 */
void vs_mainMenu_setStatsFromGrip(int gripIndex);

/**
 * Sets up the stats UI using the specified shield.
 */
void vs_mainMenu_setStatsFromShield(int shieldIndex);

/**
 * Sets up the stats UI using the specified armor.
 */
void vs_mainMenu_setStatsFromArmor(int armorIndex);

/**
 * Sets up the stats UI using the specified gem.
 */
void vs_mainMenu_setStatsFromGem(int gemIndex);

/**
 * Returns the cursor the priciple item.
 */
void vs_mainMenu_resetStatusViewCursor(void);

/**
 * Updates the status view based on user input.
 */
void vs_mainMenu_renderStatusView(void);

/**
 * Unequips the current weapon (if any) and ensures that
 * the equipped flag on all weapons is reset.
 */
void vs_mainMenu_unequipWeapon(void);

/**
 * Unequips the current shield (if any) and ensures that
 * the equipped flag on all shields is reset.
 */
void vs_mainMenu_unequipShield(void);

/**
 * Resets and initializes inventory slots for
 * the desired category. Shields and Weapons call this
 * recursively to initialize subcomponents.
 */
void vs_mainMenu_initItem(int itemCategory, int index);

/**
 * Loads ITEMNAME.BIN, ITEMHELP.BIN, and MENU12.BIN from disk.
 *
 * @param load True to dispatch a CD load request.
 * @return True if loading complete.
 */
int vs_mainMenu_loadItemText(int load);

/**
 * Frees the item text if still loaded.
 *
 * @return True if unloaded.
 */
int vs_mainMenu_ensureItemTextUnloaded(void);

/**
 * Finds the requested item ID
 */
int vs_mainMenu_findItem(int category, int id);

/**
 * Normalizes the inventory indices, used before displaying an item menu
 * or after operations that modify the inventory such as combine or
 * disassemble.
 */
void vs_mainMenu_rebuildInventory(int itemCategory);

/**
 * Returns the total number of items in the selected category.
 */
int vs_mainMenu_getItemCount(int itemCategory, vs_main_inventory_t* inventory);

/**
 * Finds an empty inventory slot.
 */
int vs_mainMenu_getFirstEmptyItemSlot(int itemCategory, vs_main_inventory_t*);

enum vs_mainMenu_copyItem_flags { copyItemFlagsWrite = 0x10 };

/**
 * Used for copying between inventories, in practice only invoked by
 * the loot menu.
 *
 * @param itemCategory Without copyItemFlagsWrite, the method will perform a dry run.
 * @return The index of the copied item.
 */
int vs_mainMenu_copyItem(int itemCategory, vs_main_inventory_t* targetInventory,
    int sourceItemIndex, vs_main_inventory_t* sourceInventory);

/**
 * Indicates which weapon categories are two-handed.
 */
extern u_char vs_mainMenu_weaponHands[];

/**
 * Maps dpad input for navigation on the status view.
 */
extern u_char vs_mainMenu_statusViewNavigationMap[][4];

/**
 * Screen coordinates for the cursor on the status view.
 */
extern int vs_mainMenu_statusViewCursorPositions[];

/**
 * Maps useable items to "skills".
 */
extern u_char vs_mainMenu_miscItemToSkillMap[];

/**
 * A flat list of every item name. Cannot be used before invoking
 * `vs_mainMenu_loadItemText`.
 */
extern char (*vs_mainMenu_itemNames)[24];

/**
 * The item limit for each category.
 */
extern u_char vs_mainMenu_inventoryItemCapacities[];

/**
 * Convenience map into the inventory index map in SLUS_010.40
 */
extern u_char* vs_mainMenu_inventoryIndices[];
