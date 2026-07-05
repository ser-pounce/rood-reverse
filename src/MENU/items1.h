#include "src/BATTLE/BATTLE.PRG/573B8.h"
#include "src/MENU/MAINMENU.PRG/C48.h"
#include "src/MENU/MAINMENU.PRG/2D10.h"
#include "src/MENU/MAINMENU.PRG/58EC.h"
#include "build/assets/MENU/ITEMHELP.BIN.h"
#include "gpu.h"
#include "vs_string.h"
#include <libetc.h>
#include <limits.h>

static int _itemPaging(int items, int page);
static void _startMenuTransition(int id);
static void _continueMenuTransition(int id);

static int _ashleyYOffset = 0;
static int _ashleyRenderState = 0;
extern char _secondaryTitleEnabled;
extern char _itemCategoryIconsEnabled;
extern char _statusCommandState;

static void _initMenuLayout(int selectedItem, int classAffinityType)
{
    _ashleyRenderState = 1;
    _itemCategoryIconsEnabled = 0;
    _statusCommandState = 0;

    _continueMenuTransition(selectedItem);
    vs_mainMenu_drawClassAffinityType(classAffinityType);
    vs_mainMenu_renderEquipStats(1);
}

/**
 * Updates the UI after a new page is selected with L1 / R1
 */
static void _switchItemStatusPage(int row, char* text[], u_int rowType, int page)
{
    vs_battle_menuItem_t* menuItem;

    vs_battle_playMenuChangeSfx();

    menuItem = vs_battle_setMenuItem(row, 155, 18, 165, 0, text[0]);
    menuItem->selected = 1;
    menuItem->rowIcon = (rowType >> 0x1A);
    menuItem->material = (rowType >> 0x10) & 7;

    vs_mainmenu_setInformationMessage(text[1]);
    vs_battle_getMenuItem(31)->itemPage = page + 1;
}

/**
 * Combined method for setting the cursor memory and mapping the
 * item ID to a row index.
 */
static int _getItemIndex(int itemCategory, int itemId)
{
    // Actually accesses struct at unk3A, might originally have been raw
    // pointer manipulation.
    D_800F4EE8.cursorMemories[(itemCategory + 30) * 2] = 0;
    D_800F4EE8.cursorMemories[(itemCategory + 30) * 2 + 1] = itemId;
    return vs_mainMenu_inventoryIndices[itemCategory][itemId];
}

static char _secondaryTitleAnimationStep;
static char _itemCategoryIconsAnimationStep;
static char _statusCommandAnimationStep;
static char _selectedItemCategoryIconOnTop;
static int _exitToBattle;

/**
 * Restores items view.
 *
 * @param clearDpPp Set to 1 if status view has DP and PP bars
 */
static void _exitStatusView(int clearDpPp)
{
    vs_battle_playMenuLeaveSfx();
    vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
    vs_mainMenu_menuItemFlyoutLeft(-1);
    vs_mainMenu_drawClassAffinityType(-1);
    vs_mainMenu_renderEquipStats(2);

    _selectedItemCategoryIconOnTop = 2;
    _exitToBattle = vs_main_buttonsPressed.all & PADRup;

    if (clearDpPp != 0) {
        vs_mainMenu_renderDpPpBars(4);
    }
}

/**
 * Manages and displays the status view for weapons.
 *
 * @param itemInfo Packed value
 * - Bits 0-7: Inventory index
 * - Bits 8+: Row in current view
 * @return The value of vs_mainmenu_ready if itemInfo == 0, 0 otherwise.
 */
static int _weaponStatusView(int itemInfo)
{
    enum state { init, initWeapon, manageInput, returnMenuReady };

    static char state;
    static char initRow;
    static char itemRow;
    static u_char itemIndex;
    static char _;

    char* menuText[2];
    int rowType;
    int newIndex;
    int i;

    if (itemInfo != 0) {
        itemRow = itemInfo >> 8;
        itemIndex = (itemInfo - 1) & 0xFF;

        _startMenuTransition(itemRow);

        _ = 0;
        initRow = 0;
        state = init;

        return 0;
    }

    switch (state) {
    case init:
        if (vs_mainmenu_ready() != 0) {
            _initMenuLayout(itemRow, 7);
            vs_mainMenu_setStatsFromWeapon(vs_main_inventoryIndices.weapons[itemIndex]);
            vs_mainMenu_renderDpPpBars(3);
            state = initWeapon;
        }
        break;

    case initWeapon:
        if (initRow < 10) {
            if (++initRow < 6) {
                vs_mainMenu_initWeaponDetailsRow(
                    initRow, vs_main_inventoryIndices.weapons[itemIndex], 1);
                return 0;
            }
            break;
        }

        state = manageInput;
        break;

    case manageInput:
        if (vs_main_buttonsPressed.all & (PADRup | PADRdown)) {
            _exitStatusView(1);
            state = 3;
            break;
        }

        newIndex = _itemPaging(0, itemIndex);

        if (newIndex != itemIndex) {
            int weaponToDisplay;

            itemIndex = newIndex;
            weaponToDisplay = _getItemIndex(0, newIndex);

            vs_mainMenu_setWeaponRowFromInventory(
                &vs_main_inventory.weapons[weaponToDisplay - 1], menuText, &rowType,
                vs_battle_stringBuf);

            do {
                vs_mainMenu_setStatsFromWeapon(weaponToDisplay);
                _switchItemStatusPage(itemRow, menuText, rowType, newIndex);

                for (i = 1; i < 6; ++i) {
                    vs_mainMenu_initWeaponDetailsRow(
                        i, vs_main_inventoryIndices.weapons[newIndex], 0);
                }
            } while (0);
        }
        break;

    case returnMenuReady:
        return vs_mainmenu_ready();
    }

    return 0;
}

/**
 * Manages and displays the status view for blades.
 *
 * @param itemInfo Packed value
 * - Bits 0-7: Inventory index
 * - Bits 8+: Row in current view
 * @return The value of vs_mainmenu_ready if itemInfo == 0, 0 otherwise.
 */
static int _bladeStatusView(int itemInfo)
{
    enum state { init, wait, manageInput, returnMenuReady };

    static char state;
    static char animationTimer;
    static char itemRow;
    static u_char itemIndex;

    char* meunText[2];
    int rowType;
    int newIndex;

    if (itemInfo != 0) {
        itemRow = itemInfo >> 8;
        itemIndex = (itemInfo - 1) & 0xFF;

        _startMenuTransition(itemRow);

        animationTimer = 10;
        state = init;

        return 0;
    }

    switch (state) {
    case init:
        if ((state == 0) && (vs_mainmenu_ready() != 0)) {
            _initMenuLayout(itemRow, 3);
            vs_mainMenu_setStatsFromBlade(vs_main_inventoryIndices.blades[itemIndex]);
            vs_mainMenu_renderDpPpBars(3);
            state = wait;
        }
        break;

    case wait:
        if (animationTimer != 0) {
            --animationTimer;
        } else {
            state = manageInput;
        }
        break;

    case manageInput:
        if (vs_main_buttonsPressed.all & (PADRup | PADRdown)) {
            _exitStatusView(1);
            state = returnMenuReady;
            break;
        }

        newIndex = _itemPaging(1, (int)itemIndex);

        if (newIndex != itemIndex) {
            int bladeToDisplay;

            itemIndex = newIndex;
            bladeToDisplay = _getItemIndex(1, newIndex);

            vs_mainMenu_setBladeRow(&vs_main_inventory.blades[bladeToDisplay - 1],
                meunText, &rowType, vs_battle_stringBuf);
            vs_mainMenu_setStatsFromBlade(bladeToDisplay);
            _switchItemStatusPage(itemRow, meunText, rowType, newIndex);
        }
        break;

    case returnMenuReady:
        return vs_mainmenu_ready();
    }

    return 0;
}

/**
 * Manages and displays the status view for grips.
 *
 * @param itemInfo Packed value
 * - Bits 0-7: Inventory index
 * - Bits 8+: Row in current view
 * @return The value of vs_mainmenu_ready if itemInfo == 0, 0 otherwise.
 */
static int _gripStatusView(int itemInfo)
{
    enum state { init, wait, manageInput, returnMenuReady };

    static char* gemSlotCountBuf = "X     0";

    static char state;
    static char animationTimer;
    static char itemRow;
    static u_char itemIndex;
    static char _;

    char* menuText[2];
    int rowType;

    if (itemInfo != 0) {
        itemRow = itemInfo >> 8;
        itemIndex = (itemInfo - 1) & 0xFF;

        _startMenuTransition(itemRow);

        _ = 0;
        animationTimer = 0;
        state = init;

        return 0;
    }

    switch (state) {
    case init:
        if (vs_mainmenu_ready() != 0) {
            _initMenuLayout(itemRow, 4);
            vs_mainMenu_setStatsFromGrip(vs_main_inventoryIndices.grips[itemIndex]);
            state = wait;
        }
        break;

    case wait:
        if (animationTimer < 10) {
            ++animationTimer;
        } else {
            state = manageInput;
        }
        break;

    case manageInput:
        if (vs_main_buttonsPressed.all & (PADRup | PADRdown)) {
            _exitStatusView(0);
            state = returnMenuReady;
        } else {
            int newIndex = _itemPaging(2, itemIndex);

            if (newIndex != itemIndex) {
                int gripToDisplay;
                itemIndex = newIndex;
                gripToDisplay = _getItemIndex(2, newIndex);

                vs_mainMenu_setGripRow(&vs_main_inventory.grips[gripToDisplay - 1],
                    menuText, &rowType, vs_battle_stringBuf);

                vs_mainMenu_setStatsFromGrip(gripToDisplay);
                _switchItemStatusPage(itemRow, menuText, rowType, newIndex);
            }
        }

        // BUG: rodata .write
        gemSlotCountBuf[6] =
            vs_main_inventory.grips[vs_main_inventoryIndices.grips[itemIndex] - 1]
                .gemSlots
            + '0';

        vs_mainMenu_renderMenuRowIcon(mainMenuIconGem | (1 << 8), 256, 32);
        vs_battle_renderTextRaw(gemSlotCountBuf, vs_getXY(280, 36), NULL);

        break;

    case 3:
        return vs_mainmenu_ready();
    }
    return 0;
}

/**
 * Manages and displays the status view for shields.
 *
 * @param itemInfo Packed value
 * - Bits 0-7: Inventory index
 * - Bits 8+: Row in current view
 * @return The value of vs_mainmenu_ready if itemInfo == 0, 0 otherwise.
 */
static int _shieldStatusView(int itemInfo)
{
    enum state { init, initShield, manageInput, returnMenuReady };

    static char state;
    static char initRow;
    static char itemRow;
    static u_char itemIndex;
    static char _;

    char* menuText[2];
    int rowType;
    int newIndex;
    int i;

    if (itemInfo != 0) {
        itemRow = itemInfo >> 8;
        itemIndex = (itemInfo - 1) & 0xFF;

        _startMenuTransition(itemRow);

        _ = 0;
        initRow = 0;
        state = init;

        return 0;
    }

    switch (state) {
    case init:
        if (vs_mainmenu_ready() != 0) {
            _initMenuLayout(itemRow, 7);
            vs_mainMenu_setStatsFromShield(vs_main_inventoryIndices.shields[itemIndex]);
            vs_mainMenu_renderDpPpBars(3);

            state = initShield;
        }
        break;

    case initShield:
        if (initRow < 10) {

            ++initRow;

            if (initRow < 4) {
                vs_mainMenu_initShieldDetailsRow(
                    initRow, vs_main_inventoryIndices.shields[itemIndex], 1);
            }
            break;
        }

        if (vs_mainmenu_ready() != 0) {
            state = manageInput;
        }

        break;

    case manageInput:
        if (vs_main_buttonsPressed.all & (PADRup | PADRdown)) {
            _exitStatusView(1);
            state = returnMenuReady;
            break;
        }

        newIndex = _itemPaging(3, itemIndex);

        if (newIndex != itemIndex) {
            itemIndex = newIndex;
            i = _getItemIndex(3, newIndex);

            vs_mainMenu_setShieldRowFromInventory(&vs_main_inventory.shields[i - 1],
                menuText, &rowType, vs_battle_stringBuf);

            vs_mainMenu_setStatsFromShield(i);
            _switchItemStatusPage(itemRow, menuText, rowType, newIndex);

            for (i = 1; i < 4; ++i) {
                vs_mainMenu_initShieldDetailsRow(
                    i, vs_main_inventoryIndices.shields[newIndex], 0);
            }
        }

        break;

    case returnMenuReady:
        return vs_mainmenu_ready();
    }

    return 0;
}

/**
 * Manages and displays the status view for armor.
 *
 * @param itemInfo Packed value
 * - Bits 0-7: Inventory index
 * - Bits 8+: Row in current view
 * @return The value of vs_mainmenu_ready if itemInfo == 0, 0 otherwise.
 */
static int _armorStatusView(int itemInfo)
{
    enum state { init, wait, manageInput, returnMenuReady };

    static char status;
    static char animationTimer;
    static char itemRow;
    static u_char itemIndex;

    char* menuText[2];
    int rowType;
    int newIndex;

    if (itemInfo != 0) {
        itemRow = itemInfo >> 8;
        itemIndex = (itemInfo - 1) & 0xFF;

        _startMenuTransition(itemRow);

        animationTimer = 10;
        status = 0;

        return 0;
    }

    switch (status) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            _initMenuLayout(itemRow, 7);
            vs_mainMenu_setStatsFromArmor(vs_main_inventoryIndices.armor[itemIndex]);
            if (vs_main_inventory.armor[vs_main_inventoryIndices.armor[itemIndex] - 1]
                    .category
                != 7) {
                vs_mainMenu_renderDpPpBars(1);
            }

            status = wait;
        }
        break;

    case wait:
        if (animationTimer != 0) {
            --animationTimer;
        } else {
            status = manageInput;
        }
        break;

    case manageInput:
        if (vs_main_buttonsPressed.all & (PADRup | PADRdown)) {
            _exitStatusView(1);
            status = returnMenuReady;

            break;
        }

        newIndex = _itemPaging(4, itemIndex);

        if (newIndex != itemIndex) {
            int armorToDisplay;

            itemIndex = newIndex;
            armorToDisplay = _getItemIndex(4, newIndex);

            vs_mainMenu_setArmorRowFromInventory(
                &vs_main_inventory.armor[armorToDisplay - 1], menuText, &rowType,
                vs_battle_stringBuf);
            vs_mainMenu_setStatsFromArmor(armorToDisplay);
            _switchItemStatusPage(itemRow, menuText, rowType, newIndex);

            return 0;
        }

        break;

    case returnMenuReady:
        return vs_mainmenu_ready();
    }

    return 0;
}

/**
 * Manages and displays the status view for gems.
 *
 * @param itemInfo Packed value
 * - Bits 0-7: Inventory index
 * - Bits 8+: Row in current view
 * @return The value of vs_mainmenu_ready if itemInfo == 0, 0 otherwise.
 */
static int _gemStatusView(int itemInfo)
{
    enum state { init, wait, manageInput, returnMenuReady };

    static char state;
    static char animationTimer;
    static char itemRow;
    static u_char itemIndex;

    char* menuText[2];
    int rowType;
    int newIndex;

    if (itemInfo != 0) {
        itemRow = itemInfo >> 8;
        itemIndex = (itemInfo - 1) & 0xFF;

        _startMenuTransition(itemRow);

        animationTimer = 10;
        state = init;

        return 0;
    }

    switch (state) {
    case init:
        if (vs_mainmenu_ready() != 0) {
            _initMenuLayout(itemRow, 3);
            vs_mainMenu_setStatsFromGem(vs_main_inventoryIndices.gems[itemIndex]);

            state = wait;
        }
        break;

    case wait:
        if (animationTimer != 0) {
            --animationTimer;
        } else {
            state = manageInput;
        }
        break;

    case manageInput:
        if (vs_main_buttonsPressed.all & (PADRup | PADRdown)) {
            _exitStatusView(0);

            state = returnMenuReady;
            _exitToBattle = vs_main_buttonsPressed.all & PADRup;

            break;
        }

        newIndex = _itemPaging(5, itemIndex);

        if (newIndex != itemIndex) {
            int gemToDisplay;

            itemIndex = newIndex;
            gemToDisplay = _getItemIndex(5, newIndex);

            vs_mainMenu_setGemRow(&vs_main_inventory.gems[gemToDisplay - 1], menuText,
                &rowType, vs_battle_stringBuf);
            vs_mainMenu_setStatsFromGem(gemToDisplay);
            _switchItemStatusPage(itemRow, menuText, rowType, newIndex);

            return 0;
        }

        break;

    case returnMenuReady:
        return vs_mainmenu_ready();
    }

    return 0;
}

/**
 * Invokes the status view for the selected item category.
 *
 * @param itemInfo Packed value:
 * - Bits 0-3: Item category
 * - Bits 4+: Page to display
 * @return int
 */
static int _itemStatusDispatcher(int itemInfo)
{
    static int (*_statusViewDispatch[])(int) = { _weaponStatusView, _bladeStatusView,
        _gripStatusView, _shieldStatusView, _armorStatusView, _gemStatusView };

    static u_char itemCategory;

    int page = 0;
    int new_var;

    if (itemInfo != 0) {
        page = itemInfo >> 4;
        itemCategory = itemInfo & 0xF;
        _selectedItemCategoryIconOnTop = 1;
        _exitToBattle = 0;

        vs_mainMenu_resetStatusViewCursor();
        vs_battle_getMenuItem(31)->itemPage = page & 0xFF;
        vs_mainMenu_setMenuCommand(menuActionNone);
    }

    page = _statusViewDispatch[itemCategory](page);
    new_var = page != 0;

    if (new_var) {
        if (_exitToBattle == 0) {
            _itemCategoryIconsEnabled = 1;
            _selectedItemCategoryIconOnTop = 0;
            _statusCommandState = 1;
            _ashleyRenderState = 0;

            vs_mainMenu_setMenuCommand(menuActionMenu);

            return page;
        }

        return -2;
    }

    if (vs_mainmenu_ready() != 0) {

        vs_mainMenu_cursorColor = vs_mainMenu_selectedStatusViewElement != 9;

        func_801013F8(1);
        vs_mainMenu_renderStatusView();
    }

    return page;
}

/**
 * Maps a numerical value to a weapon stat.
 *
 * @param stat Must be in the range 0-24
 */
static int _getWeaponStatValue(int stat, vs_battle_uiWeapon* weapon)
{
    switch (stat) {
    case 0:
        return -weapon->blade.category;
    case 1:
        return -weapon->blade.material;
    case 2:
        return weapon->range.range;
    case 3:
        return -weapon->damageType;
    case 4:
        return weapon->currentDp;
    case 5:
        return weapon->maxDp;
    case 6:
        return weapon->currentPp;
    case 7:
        return weapon->maxPp;
    case 8:
        return weapon->currentStr;
    case 9:
        return weapon->currentInt;
    case 10:
        return weapon->currentAgility;
    default:
        if (stat >= 17) {
            return weapon->classAffinityCurrent.affinity[0][stat - 17];
        }
        return weapon->classAffinityCurrent.class[0][stat - 11];
    }
}

/**
 * Sorts weapons by the selected stat.
 */
static void _sortWeapons(int stat)
{
    vs_battle_uiWeapon uiWeapon;
    char sortedIndices[8];
    int i;
    int sortedPos;

    vs_main_inventoryWeapon* weapon = vs_main_inventory.weapons;
    char* indices = vs_main_inventoryIndices.weapons;

    vs_battle_rMemzero(sortedIndices, 8);

    sortedPos = 0;

    while (1) {
        int index;
        int maxValue = -INT_MAX - 1;

        for (i = 0; i < 8; ++i) {
            index = indices[i];

            if (index != 0) {
                int value;

                vs_battle_applyWeapon(&uiWeapon, &weapon[index - 1]);

                value = _getWeaponStatValue(stat, &uiWeapon);

                if (maxValue < value) {
                    maxValue = value;
                }
            }
        }

        if (maxValue == -INT_MAX - 1) {
            break;
        }

        for (i = 0; i < 8; ++i) {
            index = indices[i];

            if (index != 0) {

                vs_battle_applyWeapon(&uiWeapon, &weapon[index - 1]);

                if (_getWeaponStatValue(stat, &uiWeapon) == maxValue) {
                    sortedIndices[sortedPos++] = index;
                    indices[i] = 0;
                }
            }
        }
    }

    vs_battle_memcpy(indices, sortedIndices, 8);
}

/**
 * Maps a numerical value to a shield stat.
 *
 * @param stat Must be in the disjoint range 0-10 | 27-43
 */
static int _getShieldStatValue(int stat, vs_battle_uiShield* shield)
{
    switch (stat) {
    case 1:
        return -shield->base.material;
    case 4:
        return shield->currentPp;
    case 5:
        return shield->maxPp;
    case 6:
        return shield->currentDp;
    case 7:
        return shield->maxDp;
    case 8:
        return shield->currentStr;
    case 9:
        return shield->currentInt;
    case 10:
        return shield->currentAgility;
    default:
        if (stat < 33) {
            return shield->classAffinityCurrent.class[0][stat - 27];
        }

        if (stat > 39) {
            return shield->types[stat - 39];
        }

        return shield->classAffinityCurrent.affinity[0][stat - 33];
    }
}

/**
 * Sorts shields by the selected stat.
 */
static void _sortShields(int stat)
{
    vs_battle_uiShield uiShield;
    char sortedIndices[8];
    int i;
    int sortedPos;

    vs_main_inventoryShield* shield = &vs_main_inventory.shields[0];
    char* indices = vs_main_inventoryIndices.shields;

    vs_battle_rMemzero(sortedIndices, sizeof sortedIndices);

    sortedPos = 0;

    while (1) {
        int index;
        int maxValue = -INT_MAX - 1;

        for (i = 0; i < 8; ++i) {
            int value;
            index = indices[i];

            if (index != 0) {

                vs_battle_applyShield(&uiShield, &shield[index - 1]);

                value = _getShieldStatValue(stat, &uiShield);

                if (maxValue < value) {
                    maxValue = value;
                }
            }
        }

        if (maxValue == -INT_MAX - 1) {
            break;
        }

        for (i = 0; i < 8; ++i) {
            index = indices[i];

            if (index != 0) {

                vs_battle_applyShield(&uiShield, &shield[index - 1]);

                if (_getShieldStatValue(stat, &uiShield) == maxValue) {
                    sortedIndices[sortedPos++] = index;
                    indices[i] = 0;
                }
            }
        }
    }

    vs_battle_memcpy(indices, sortedIndices, 8);
}

/**
 * Maps a numerical value to a misc item stat.
 *
 * @param stat 0 = ID, count otherwise.
 */
static int _getMiscStatValue(int stat, vs_main_inventoryMisc* misc)
{
    if (stat == 0) {
        return -misc->id;
    }
    return misc->count;
}

/**
 * Sorts misc items by the selected stat.
 */
static void _sortMisc(int stat)
{
    char sortedIndices[64];
    int i;
    int sortedPos;

    vs_main_inventoryMisc* misc = vs_main_inventory.misc;
    char* indices = vs_main_inventoryIndices.misc;

    vs_battle_rMemzero(sortedIndices, sizeof sortedIndices);
    sortedPos = 0;

    while (1) {
        int index;
        int maxValue = -INT_MAX - 1;

        for (i = 0; i < 0x40; ++i) {
            index = indices[i];

            if (index != 0) {
                int value = _getMiscStatValue(stat, &misc[index - 1]);

                if (maxValue < value) {
                    maxValue = value;
                }
            }
        }

        if (maxValue == -INT_MAX - 1) {
            break;
        }

        for (i = 0; i < 0x40; ++i) {
            index = indices[i];

            if ((index != 0) && (_getMiscStatValue(stat, &misc[index - 1]) == maxValue)) {
                sortedIndices[sortedPos++] = index;
                indices[i] = 0;
            }
        }
    }

    vs_battle_memcpy(indices, sortedIndices, sizeof sortedIndices);
}

/**
 * Maps a numerical value to an equipment stat.
 *
 * @param stat Must be in the range 0-42
 */
static int _getEquipmentStatValue(int stat, vs_battle_uiEquipment* equipment)
{
    switch (stat) {
    case 0:
        return -equipment->category;
    case 1:
        return -equipment->material;
    case 2:
        return equipment->range.range;
    case 3:
        return -equipment->damageType;
    case 4:
        return equipment->currentDp;
    case 5:
        return equipment->maxDp;
    case 6:
        return equipment->currentPp;
    case 7:
        return equipment->maxPp;
    case 8:
        return equipment->strength;
    case 9:
        return equipment->intelligence;
    case 10:
        return equipment->agility;
    default:
        if (stat >= 27) {
            stat -= 16;
        }

        if (stat < 17) {
            return equipment->classes[stat - 11];
        }

        if (stat > 23) {
            return equipment->types[stat - 23];
        }

        return equipment->affinities[stat - 17];
    }
}

/**
 * Copies equipment for the selected category.
 */
static void _copyEquipment(
    vs_battle_uiEquipment* equipment, int itemCategory, int itemIndex)
{
    switch (itemCategory) {
    case itemCategoryBlade:
        vs_battle_copyInventoryBladeStats(
            equipment, &vs_main_inventory.blades[itemIndex]);
        return;
    case itemCategoryGrip:
        vs_battle_copyInventoryGripStats(equipment, &vs_main_inventory.grips[itemIndex]);
        return;
    case itemCategoryArmor:
        vs_battle_copyInventoryArmorStats(equipment, &vs_main_inventory.armor[itemIndex]);
        return;
    case itemCategoryGem:
        vs_battle_copyInventoryGemStats(equipment, &vs_main_inventory.gems[itemIndex]);
        return;
    }
}

/**
 * Sorts equipment by the selected stat.
 */
static void _sortEquipment(int itemCategory, int stat)
{
    vs_battle_uiEquipment uiEquipment;
    int i;
    int sortedPos = 0;
    int capacity = vs_mainMenu_inventoryItemCapacities[itemCategory];
    {
        char sortedIndices[capacity];
        char* indices = vs_mainMenu_inventoryIndices[itemCategory];

        vs_battle_rMemzero(sortedIndices, capacity);

        while (1) {
            int index;
            int maxValue = -INT_MAX - 1;

            for (i = 0; i < capacity; ++i) {
                index = indices[i];

                if (index != 0) {
                    int value;

                    _copyEquipment(&uiEquipment, itemCategory, index - 1);

                    value = _getEquipmentStatValue(stat, &uiEquipment);

                    if (maxValue < value) {
                        maxValue = value;
                    }
                }
            }

            if (maxValue == -INT_MAX - 1) {
                break;
            }

            for (i = 0; i < capacity; ++i) {
                index = indices[i];

                if (index != 0) {

                    _copyEquipment(&uiEquipment, itemCategory, index - 1);

                    if (_getEquipmentStatValue(stat, &uiEquipment) == maxValue) {
                        sortedIndices[sortedPos++] = index;
                        indices[i] = 0;
                    }
                }
            }
        }

        vs_battle_memcpy(indices, sortedIndices, capacity);
    }
}

/**
 * Dispatches category-based sort.
 *
 * @return The stat used for sorting, negative if user cancelled, 0 otherwise.
 */
static int _sortItems(int initItemCategory)
{
    enum state { init, sort };

    static u_char weaponSortStats[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
        15, 16, 17, 18, 19, 20, 21, 22, 23 };
    static u_char bladeSortStats[] = { 0, 8, 9, 10, 24, 25, 26 };
    static u_char gripSortStats[] = { 1, 4, 5, 6, 7, 8, 9, 10, 40, 41, 42, 27, 28, 29, 30,
        31, 32, 33, 34, 35, 36, 37, 38, 39 };
    static u_char shieldSortStats[] = { 0, 1, 4, 5, 8, 9, 10, 40, 41, 42, 27, 28, 29, 30,
        31, 32, 33, 34, 35, 36, 37, 38, 39 };
    static u_char equipmentSortStats[] = { 8, 9, 10, 27, 28, 29, 30, 31, 32, 33, 34, 35,
        36, 37, 38, 39 };
    static u_char miscSortStats[] = { 0, 56 };

    static u_char sortStatSizes[] = { sizeof weaponSortStats, sizeof weaponSortStats,
        sizeof bladeSortStats, sizeof gripSortStats, sizeof shieldSortStats,
        sizeof equipmentSortStats, sizeof miscSortStats };

    static u_char* sortStats[] = { weaponSortStats, weaponSortStats, bladeSortStats,
        gripSortStats, shieldSortStats, equipmentSortStats, miscSortStats };

    static u_char state;
    static u_char itemCategory;

    char* menuText[48];
    int rowTypes[24];
    int i;

    if (initItemCategory != 0) {
        itemCategory = initItemCategory - 1;
        state = init;

        return 0;
    }

    switch (state) {
    case init:
        if (vs_mainmenu_ready() != 0) {
            u_char* categoryStats = sortStats[itemCategory];

            for (i = 0; i < sortStatSizes[itemCategory]; ++i) {
                menuText[i * 2] = (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp
                        [categoryStats[i] * 2 + VS_ITEMHELP_BIN_INDEX_sortRange - 4]];
                menuText[i * 2 + 1] = (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp
                        [categoryStats[i] * 2 + VS_ITEMHELP_BIN_INDEX_sortRangeDesc - 4]];
                rowTypes[i] = 0;
            }

            vs_mainMenu_addMenuActions(
                i, itemCategory + actionMenuSort, menuText, rowTypes);

            state = 1;
        }
        break;

    case sort:
        vs_mainMenu_renderItemActionMenu();

        i = vs_mainMenu_actionInputProcessed();

        if ((i + 1) != 0) {
            if (i >= 0) {
                vs_battle_playMenuSelectSfx();

                switch (itemCategory) {
                case itemCategoryWeapon:
                    _sortWeapons(weaponSortStats[i]);
                    break;

                case itemCategoryShield:
                    _sortShields(gripSortStats[i]);
                    break;

                case itemCategoryMisc:
                    _sortMisc(miscSortStats[i]);
                    break;

                default:
                    _sortEquipment(itemCategory, sortStats[itemCategory][i]);
                    break;
                }
            } else {
                vs_battle_playMenuLeaveSfx();
            }

            return i + 1;
        }

        break;
    }

    return 0;
}

/**
 * Sets up and processes discarding one or more items.
 *
 * @param params Packed value for initialization:
 *
 * - Bits 0-7: Selected item
 *
 * - Bits 8-15: Item category
 *
 * - Bit 16: Type of discard: 0 = single, 1 = multiple
 *
 * @return Row discarded, negative on user cancel, 0 otherwise.
 */
static int _discardMenu(int params)
{
#pragma vsstring(start)

    enum state {
        init,
        discardOneInit,
        discardMultipleInit,
        discardOne,
        clearTemplate,
        determineDiscardAmount,
        discardMultipleConfirm,
        discardMultiple
    };

    static char discardTemplate[] = "|>48|000/000\0";
    static char discardSteps[] = { 1, 10, 100 };
    static char cursorBrightness = 0;

    static char state;
    static char itemCategory;
    static char selectedItem;
    static char discardType;
    static u_char discardStep;
    static char discardCount;
    static char maxAmount;
    static char _[3] __attribute__((unused));

    char* menuText[4];
    int rowTypes[2];
    int i;
    vs_battle_menuItem_t* menuItem;
    int nextStep;
    int nextCount;

    if (params != 0) {
        discardType = params >> 16;
        itemCategory = params >> 8;
        selectedItem = params & 0xFF;

        vs_battle_initInformationTextBox(1);
        vs_mainmenu_setInformationMessage(
            (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp
                    [discardType + VS_ITEMHELP_BIN_INDEX_discardConfirm]]);

        state = init;

        return 0;
    }

    switch (state) {
    case init:
        if (vs_battle_textBoxes[7].unk0.done) {
            if (vs_mainmenu_ready() != 0) {
                state = ((discardType & 1) + discardOneInit);
            }
        }
        break;

    case discardOneInit:
        for (i = 0; i < 2; ++i) {

            menuText[i * 2] = (char*)&vs_mainMenu_itemHelp
                [vs_mainMenu_itemHelp[i + VS_ITEMHELP_BIN_INDEX_confirmYes]];
            menuText[i * 2 + 1] = (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp
                    [discardType + VS_ITEMHELP_BIN_INDEX_discardConfirm]];
            rowTypes[i] = 0;
        }

        vs_mainMenu_addMenuActions(2, actionMenuDiscard, menuText, rowTypes);

        state = discardOne;
        break;

    case discardMultipleInit:
        maxAmount = vs_main_inventory.misc[selectedItem - 1].count;

        i = vs_battle_toBCD(maxAmount);

        discardTemplate[8] = i & 0xF;

        i = vs_battle_toBCD(i >> 4);

        discardTemplate[7] = i & 0xF;
        discardTemplate[6] = i >> 4;

        for (i = 2; i < 5; ++i) {
            discardTemplate[i] = '0';
        }

        menuItem = vs_battle_setMenuItem(34, -126, 130, 126, 0, discardTemplate);
        menuItem->state = 5;
        menuItem->targetPosition0 = 0;

        discardStep = 0;
        discardCount = 0;
        state = clearTemplate;
        break;

    case discardOne:
        vs_mainMenu_renderItemActionMenu();
        i = vs_mainMenu_actionInputProcessed() + 1;

        if (i != 0) {
            if (i == 1) {
                vs_main_playSfxDefault(0x7E, 28);
                vs_mainMenu_initItem(itemCategory, selectedItem);
            } else {
                vs_battle_playMenuLeaveSfx();
            }
            return i;
        }

        break;

    case clearTemplate:
        if (vs_mainmenu_ready() == 0) {
            break;
        }

        for (i = 2; i < 5; ++i) {
            discardTemplate[i] = ' ';
        }

        vs_battle_setMenuItem(34, 0, 130, 126, 0, discardTemplate);

        state = determineDiscardAmount;
        // Fallthrough

    case determineDiscardAmount:
        if (vs_main_buttonsPressed.all & (PADRup | PADRright | PADRdown)) {

            i = vs_battle_toBCD(discardCount);

            discardTemplate[4] = i & 0xF;

            i = vs_battle_toBCD(i >> 4);

            discardTemplate[3] = i & 0xF;
            discardTemplate[2] = i >> 4;

            vs_battle_setMenuItem(34, 0, 130, 126, 0, discardTemplate);

            if (vs_main_buttonsPressed.all & (PADRup | PADRdown)) {

                vs_battle_playMenuLeaveSfx();

                if (vs_main_buttonsPressed.all & PADRup) {
                    return -2;
                }

                return -1;
            }
            if (discardCount == 0) {
                vs_battle_playMenuLeaveSfx();

                return -1;
            }

            vs_battle_playMenuSelectSfx();

            state = discardMultipleConfirm;
            break;
        }

        i = 0;
        nextStep = nextCount = discardCount;

        if (vs_main_buttonRepeat & PADLup) {
            i = 1;
        }

        if (vs_main_buttonRepeat & PADLdown) {
            --i;
        }

        if (i == 1) {
            nextStep = nextCount + discardSteps[discardStep];
        } else if (i == -1) {
            nextStep = nextCount - discardSteps[discardStep];
        }

        if (nextStep >= 0) {
            if (maxAmount >= nextStep) {
                discardCount = nextStep;
            }
        }

        i = 0;
        nextStep = discardStep;

        if (vs_main_buttonRepeat & PADLright) {
            --i;
        }

        if (vs_main_buttonRepeat & PADLleft) {
            ++i;
        }

        if (i == 1) {
            if ((nextStep & 0xFF) == 2) {
                if (discardCount != maxAmount) {
                    discardCount = maxAmount;
                }
            } else {
                ++discardStep;
            }
        } else if (i == -1) {
            if (!(nextStep & 0xFF)) {
                if (discardCount != 0) {
                    discardCount = 0;
                }
            } else {
                --discardStep;
            }
        }

        if ((nextStep != discardStep) || (nextCount != discardCount)) {
            vs_battle_playMenuChangeSfx();
        }

        vs_battle_setFontStyle(5);

        i = vs_battle_toBCD(discardCount);
        vs_battle_printVariableWidthFontChar(i & 0xF, 66, 130, D_1F800000[2] - 12);
        i = vs_battle_toBCD(i >> 4);
        vs_battle_printVariableWidthFontChar(i & 0xF, 60, 130, D_1F800000[2] - 12);
        vs_battle_printVariableWidthFontChar(i >> 4, 54, 130, D_1F800000[2] - 12);

        cursorBrightness = vs_mainMenu_renderCursor(
            cursorBrightness, (54 - (discardStep * 6)) | (114 << 16));

        break;

    case discardMultipleConfirm:
        if (vs_mainmenu_ready() != 0) {

            char* menuText[4];
            int rowTypes[2];

            for (i = 0; i < 2; ++i) {
                menuText[i * 2] = (char*)&vs_mainMenu_itemHelp
                    [vs_mainMenu_itemHelp[i + VS_ITEMHELP_BIN_INDEX_confirmYes]];
                menuText[i * 2 + 1] =
                    (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_discardConfirm];
                rowTypes[i] = 0;
            }

            vs_mainMenu_addMenuActions(2, actionMenuDiscard, menuText, rowTypes);
            state = discardMultiple;
        }

        break;

    case discardMultiple:
        vs_mainMenu_renderItemActionMenu();
        i = vs_mainMenu_actionInputProcessed() + 1;

        if (i != 0) {
            if (i == 1) {
                vs_main_playSfxDefault(0x7E, 0x1C);

                if (vs_main_inventory.misc[selectedItem - 1].count == discardCount) {
                    vs_mainMenu_initItem(itemCategory, selectedItem);
                } else {
                    vs_main_inventory.misc[selectedItem - 1].count =
                        vs_main_inventory.misc[selectedItem - 1].count - discardCount;
                }
            } else {
                vs_battle_playMenuLeaveSfx();
            }

            return i;
        }

        break;
    }

    return 0;

#pragma vsstring(end)
}
