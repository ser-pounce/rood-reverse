#include "16C.h"
#include "68C4.h"
#include "src/SLUS_010.40/main.h"
#include "src/SLUS_010.40/31724.h"
#include "src/BATTLE/BATTLE.PRG/2842C.h"
#include "src/BATTLE/BATTLE.PRG/30D14.h"
#include "src/BATTLE/BATTLE.PRG/3A1A0.h"
#include "src/BATTLE/BATTLE.PRG/44F14.h"
#include "src/BATTLE/BATTLE.PRG/573B8.h"
#include "src/BATTLE/BATTLE.PRG/5BF94.h"
#include "src/MENU/MAINMENU.PRG/278.h"
#include "src/MENU/MAINMENU.PRG/C48.h"
#include "src/MENU/MAINMENU.PRG/2D10.h"
#include "src/MENU/MAINMENU.PRG/58EC.h"
#include "build/assets/MENU/ITEMHELP.BIN.h"
#include "build/assets/MENU/MENU3.PRG/menuText.h"
#include "vs_string.h"
#include "gpu.h"
#include <memory.h>
#include <libetc.h>
#include <limits.h>

extern void* D_1F800000[];

static char _secondaryTitleEnabled;
static char _itemCategoryIconsEnabled;
static char _statusCommandState;

/**
 * Toggles the display of the secondary title, the category icons,
 * and the status command.
 */
static void _toggleMenuUi(char state)
{
    _secondaryTitleEnabled = state;
    _itemCategoryIconsEnabled = state;
    _statusCommandState = state;
}

/**
 * Handles L1 / R1 button presses in the status view.
 *
 * @return The item to display.
 */
static int _statusViewSwitchItem(int itemCategory, int currentItem)
{
    if ((vs_main_buttonsState & (PADL1 | PADR1)) != (PADL1 | PADR1)) {

        int previousItem = currentItem;
        itemCategory = vs_mainMenu_getItemCount(itemCategory, NULL);

        if (vs_main_buttonRepeat & PADL1) {
            int v = currentItem - 1;
            currentItem = v + itemCategory;
        }

        if (vs_main_buttonRepeat & PADR1) {
            ++currentItem;
        }

        if (currentItem >= itemCategory) {
            currentItem -= itemCategory;
        }

        if ((vs_main_buttonsPressed.all & (PADL1 | PADR1))
            && (currentItem == previousItem)) {
            vs_battle_playInvalidSfx();
        }
    }

    return currentItem;
}

/**
 * Handles the display of the item categories at the top of the screen.
 */
static void _animateItemCategoryBar(int animationStep, int itemCategoryIconOnTop)
{
    int temp_s0;
    int temp_s4;
    int i;
    u_long* texPage;
    int new_var;

    temp_s4 = (D_800F4EE8.unk3A.currentItemCategory - 1) & 7;

    if (animationStep == 4) {
        func_801013F8(0);
    }

    new_var = (animationStep * 8);
    animationStep = new_var - 0x10;

    for (i = 0; i < 8; ++i) {

        temp_s0 = (((i + 1) & 7) * 0x10) + 0x20;

        if (i == temp_s4 && itemCategoryIconOnTop == 1) {

            vs_battle_menuItem_t* menuItem = vs_battle_getMenuItem(31);

            if (temp_s0 >= (menuItem->x - 12)) {
                menuItem->icon = i + 24;
                continue;
            }

            texPage = vs_battle_setSpriteDefault(vs_getWH(16, 16), temp_s0 | 0x100000);
        } else {
            texPage = vs_battle_setSpriteDefaultTexPage(
                128, temp_s0 | (animationStep << 0x10), vs_getWH(16, 16), D_1F800000[1]);
        }

        texPage[4] =
            (0x78 + i * 16) | 0x8000 | ((i == temp_s4) ? 0x37FD0000 : 0x37FE0000);
    }
}

/**
 * Hoists the item category and selected item to the top of the menu
 * during the start of the menu transition animation.
 */
static void _startMenuTransition(int selectedItem)
{
    vs_battle_menuItem_t* menuItem;

    vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);

    menuItem = vs_battle_getMenuItem(31);
    menuItem->state = menuItemTransition_toTop;
    menuItem->targetPosition0 = 18;

    menuItem = vs_battle_getMenuItem(selectedItem);
    menuItem->state = menuItemTransition_toLeft;
    menuItem->targetPosition0 = 155;
    menuItem->selected = 1;
    menuItem->subText = NULL;
}

/**
 * Slides the item category to the left and the selected item
 * to the top.
 */
static void _continueMenuTransition(int selectedItem)
{
    vs_battle_menuItem_t* menuItem = vs_battle_getMenuItem(31);
    menuItem->state = menuItemTransition_toLeft;
    menuItem->targetPosition0 = 16;
    menuItem->w = 164;

    menuItem = vs_battle_getMenuItem(selectedItem);
    menuItem->state = menuItemTransition_toTop;
    menuItem->targetPosition0 = 18;
}

static u_short _menuText[] = {
#include "build/assets/MENU/MENU3.PRG/menuText.vsString"
};

static int _ashleyYOffset = 0;
static int _ashleyRenderState = 0;

static void func_80102C44(int selectedItem, int classAffinityType)
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
    menuItem->icon = (rowType >> 0x1A);
    menuItem->material = (rowType >> 0x10) & 7;

    vs_mainmenu_setInformationMessage(text[1]);
    vs_battle_getMenuItem(31)->itemPage = page + 1;
}

/**
 * Combined method for setting the cursor memory and mapping the
 * item ID to a row index.
 */
static int _setCursorMemoryAndGetIndex(int itemCategory, int itemId)
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
static int _menuButtonPressed;

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
    _menuButtonPressed = vs_main_buttonsPressed.all & PADRup;

    if (clearDpPp != 0) {
        vs_mainMenu_drawDpPpbars(4);
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
            func_80102C44(itemRow, 7);
            vs_mainMenu_setUiWeaponStats(vs_main_inventoryIndices.weapons[itemIndex]);
            vs_mainMenu_drawDpPpbars(3);
            state = initWeapon;
        }
        break;

    case initWeapon:
        if (initRow < 10) {
            if (++initRow < 6) {
                vs_mainMenu_initWeaponDetailsMenu(
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

        newIndex = _statusViewSwitchItem(0, itemIndex);

        if (newIndex != itemIndex) {
            int weaponToDisplay;

            itemIndex = newIndex;
            weaponToDisplay = _setCursorMemoryAndGetIndex(0, newIndex);

            vs_mainMenu_initUiWeapon(&vs_battle_inventory.weapons[weaponToDisplay - 1],
                menuText, &rowType, vs_battle_stringBuf);

            do {
                vs_mainMenu_setUiWeaponStats(weaponToDisplay);
                _switchItemStatusPage(itemRow, menuText, rowType, newIndex);

                for (i = 1; i < 6; ++i) {
                    vs_mainMenu_initWeaponDetailsMenu(
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
            func_80102C44(itemRow, 3);
            vs_mainMenu_setUiBladeStats(vs_main_inventoryIndices.blades[itemIndex]);
            vs_mainMenu_drawDpPpbars(3);
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

        newIndex = _statusViewSwitchItem(1, (int)itemIndex);

        if (newIndex != itemIndex) {
            int bladeToDisplay;

            itemIndex = newIndex;
            bladeToDisplay = _setCursorMemoryAndGetIndex(1, newIndex);

            vs_mainMenu_setUiBlade(&vs_battle_inventory.blades[bladeToDisplay - 1],
                meunText, &rowType, vs_battle_stringBuf);
            vs_mainMenu_setUiBladeStats(bladeToDisplay);
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
            func_80102C44(itemRow, 4);
            vs_mainMenu_setUiGripStats(vs_main_inventoryIndices.grips[itemIndex]);
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
            int newIndex = _statusViewSwitchItem(2, itemIndex);

            if (newIndex != itemIndex) {
                int gripToDisplay;
                itemIndex = newIndex;
                gripToDisplay = _setCursorMemoryAndGetIndex(2, newIndex);

                vs_mainMenu_setUiGrip(&vs_battle_inventory.grips[gripToDisplay - 1],
                    menuText, &rowType, vs_battle_stringBuf);

                vs_mainMenu_setUiGripStats(gripToDisplay);
                _switchItemStatusPage(itemRow, menuText, rowType, newIndex);
            }
        }

        // BUG: rodata .write
        gemSlotCountBuf[6] =
            vs_battle_inventory.grips[vs_main_inventoryIndices.grips[itemIndex] - 1]
                .gemSlots
            + '0';

        vs_mainMenu_drawRowIcon(0x116, 0x100, 0x20);
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
            func_80102C44(itemRow, 7);
            vs_mainMenu_setShieldStats(vs_main_inventoryIndices.shields[itemIndex]);
            vs_mainMenu_drawDpPpbars(3);

            state = initShield;
        }
        break;

    case initShield:
        if (initRow < 10) {

            ++initRow;

            if (initRow < 4) {
                vs_mainMenu_initSetShieldGemMenu(
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

        newIndex = _statusViewSwitchItem(3, itemIndex);

        if (newIndex != itemIndex) {
            itemIndex = newIndex;
            i = _setCursorMemoryAndGetIndex(3, newIndex);

            vs_mainMenu_initUiShield(&vs_battle_inventory.shields[i - 1], menuText,
                &rowType, vs_battle_stringBuf);

            vs_mainMenu_setShieldStats(i);
            _switchItemStatusPage(itemRow, menuText, rowType, newIndex);

            for (i = 1; i < 4; ++i) {
                vs_mainMenu_initSetShieldGemMenu(
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
            func_80102C44(itemRow, 7);
            vs_mainMenu_setArmorStats(vs_main_inventoryIndices.armor[itemIndex]);
            if (vs_battle_inventory.armor[vs_main_inventoryIndices.armor[itemIndex] - 1]
                    .category
                != 7) {
                vs_mainMenu_drawDpPpbars(1);
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

        newIndex = _statusViewSwitchItem(4, itemIndex);

        if (newIndex != itemIndex) {
            int armorToDisplay;

            itemIndex = newIndex;
            armorToDisplay = _setCursorMemoryAndGetIndex(4, newIndex);

            vs_mainMenu_initUiArmor(&vs_battle_inventory.armor[armorToDisplay - 1],
                menuText, &rowType, vs_battle_stringBuf);
            vs_mainMenu_setArmorStats(armorToDisplay);
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
            func_80102C44(itemRow, 3);
            vs_mainMenu_setGemStats(vs_main_inventoryIndices.gems[itemIndex]);

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
            _menuButtonPressed = vs_main_buttonsPressed.all & PADRup;

            break;
        }

        newIndex = _statusViewSwitchItem(5, itemIndex);

        if (newIndex != itemIndex) {
            int gemToDisplay;

            itemIndex = newIndex;
            gemToDisplay = _setCursorMemoryAndGetIndex(5, newIndex);

            vs_mainMenu_setUiGem(&vs_battle_inventory.gems[gemToDisplay - 1], menuText,
                &rowType, vs_battle_stringBuf);
            vs_mainMenu_setGemStats(gemToDisplay);
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
static int _itemStatusView(int itemInfo)
{
    static int (*_statusViewDispatchers[])(int) = { _weaponStatusView, _bladeStatusView,
        _gripStatusView, _shieldStatusView, _armorStatusView, _gemStatusView };

    static u_char itemCategory;

    int page = 0;
    int new_var;

    if (itemInfo != 0) {
        page = itemInfo >> 4;
        itemCategory = itemInfo & 0xF;
        _selectedItemCategoryIconOnTop = 1;
        _menuButtonPressed = 0;

        func_800FDD78();
        vs_battle_getMenuItem(31)->itemPage = page & 0xFF;
        vs_mainMenu_setNextMenuAction(menuActionNone);
    }

    page = _statusViewDispatchers[itemCategory](page);
    new_var = page != 0;

    if (new_var) {
        if (_menuButtonPressed == 0) {
            _itemCategoryIconsEnabled = 1;
            _selectedItemCategoryIconOnTop = 0;
            _statusCommandState = 1;
            _ashleyRenderState = 0;

            vs_mainMenu_setNextMenuAction(menuActionMenu);

            return page;
        }

        return -2;
    }

    if (vs_mainmenu_ready() != 0) {

        D_801022D5 = D_801024B8 != 9;

        func_801013F8(1);
        func_800FDEBC();
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

    vs_battle_inventoryWeapon* weapon = vs_battle_inventory.weapons;
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

    vs_battle_inventoryShield* shield = &vs_battle_inventory.shields[0];
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
static int _getMiscStatValue(int stat, vs_battle_inventoryMisc* misc)
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

    vs_battle_inventoryMisc* misc = vs_battle_inventory.misc;
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
static int _getEquipmentStat(int stat, vs_battle_uiEquipment* equipment)
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
            equipment, &vs_battle_inventory.blades[itemIndex]);
        return;
    case itemCategoryGrip:
        vs_battle_copyInventoryGripStats(
            equipment, &vs_battle_inventory.grips[itemIndex]);
        return;
    case itemCategoryArmor:
        vs_battle_copyInventoryArmorStats(
            equipment, &vs_battle_inventory.armor[itemIndex]);
        return;
    case itemCategoryGem:
        vs_battle_copyInventoryGemStats(equipment, &vs_battle_inventory.gems[itemIndex]);
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

                    value = _getEquipmentStat(stat, &uiEquipment);

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

                    if (_getEquipmentStat(stat, &uiEquipment) == maxValue) {
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

            vs_mainMenu_initSortUi(i, itemCategory + 45, menuText, rowTypes);

            state = 1;
        }
        break;

    case sort:
        vs_mainMenu_processItemActionMenu();

        i = vs_mainMenu_getSelectedItemAction();

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

        vs_mainMenu_initSortUi(2, 4, menuText, rowTypes);

        state = discardOne;
        break;

    case discardMultipleInit:
        maxAmount = vs_battle_inventory.misc[selectedItem - 1].count;

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
        vs_mainMenu_processItemActionMenu();

        i = vs_mainMenu_getSelectedItemAction() + 1;

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

            vs_mainMenu_initSortUi(2, 4, menuText, rowTypes);
            state = discardMultiple;
        }

        break;

    case discardMultiple:
        vs_mainMenu_processItemActionMenu();
        i = vs_mainMenu_getSelectedItemAction() + 1;

        if (i != 0) {
            if (i == 1) {
                int count;
                vs_main_playSfxDefault(0x7E, 0x1C);

                count = vs_battle_inventory.misc[selectedItem - 1].count;

                if (count == discardCount) {
                    vs_mainMenu_initItem(itemCategory, selectedItem);
                } else {
                    vs_battle_inventory.misc[selectedItem - 1].count =
                        count - discardCount;
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

/**
 * Finds the weapon from the specified blade, grip, or gem.
 *
 * @return 0 if no parent weapon exists.
 */
static int _getParentWeaponIndex(int itemCategory, int itemIndex)
{
    int index = 0;

    if (itemCategory == itemCategoryBlade) {
        index = vs_battle_inventory.blades[itemIndex].assembledWeaponIndex;
    }

    if (itemCategory == itemCategoryGrip) {
        index = vs_battle_inventory.grips[itemIndex].assembledWeaponIndex;
    }

    if (itemCategory == itemCategoryGem) {
        index = vs_battle_inventory.gems[itemIndex].setItemIndex;
        if (index & gemTargetShield) {
            index = 0;
        }
    }

    return index;
}

/**
 * Finds the shield from the specified gem.
 *
 * @return 0 if no parent shield exists.
 */
static int _getParentShieldIndex(int itemCategory, int itemIndex)
{
    u_short index = 0;

    if (itemCategory == itemCategoryGem) {

        index = vs_battle_inventory.gems[itemIndex].setItemIndex;

        if (!(index & gemTargetShield)) {
            index = 0;
        }
    }

    return index & 0x7F;
}

static char _miscSkills[64];

/**
 * Sets the text and rowtypes for the specified category.
 * Maps skills to misc items if selected.
 *
 * @return Item count
 */
static int _populateItemRows(
    int itemCategory, char* menuText[], int rowTypes[], char* textBuf)
{
    int parentItem;
    int rowType;
    int i;
    char* indices = vs_mainMenu_inventoryIndices[itemCategory];
    int textOffset = 0;

    for (i = 0; i < vs_mainMenu_inventoryItemCapacities[itemCategory];
         ++textOffset, ++i, textBuf += 96) {

        int index = indices[i];

        if (index == 0) {
            break;
        }

        index = indices[i] - 1;
        rowType = 0;

        switch (itemCategory) {
        case itemCategoryWeapon:
            vs_mainMenu_initUiWeapon(&vs_battle_inventory.weapons[index],
                &menuText[textOffset * 2], &rowTypes[i], textBuf);
            if (vs_battle_inventory.weapons[index].isEquipped != 0) {
                rowType = 0xCA00;
            }
            break;
        case itemCategoryBlade:
            vs_mainMenu_setUiBlade(&vs_battle_inventory.blades[index],
                &menuText[textOffset * 2], &rowTypes[i], textBuf);
            break;
        case itemCategoryGrip:
            vs_mainMenu_setUiGrip(&vs_battle_inventory.grips[index],
                &menuText[textOffset * 2], &rowTypes[i], textBuf);
            break;
        case itemCategoryShield:
            vs_mainMenu_initUiShield(&vs_battle_inventory.shields[index],
                &menuText[textOffset * 2], &rowTypes[i], textBuf);
            if (vs_battle_inventory.shields[index].isEquipped != 0) {
                rowType = 0xCA00;
            }
            break;
        case itemCategoryArmor:
            vs_mainMenu_initUiArmor(&vs_battle_inventory.armor[index],
                &menuText[textOffset * 2], &rowTypes[i], textBuf);
            if (vs_battle_inventory.armor[index].bodyPart != 0) {
                rowType = 0xCA00;
            }
            break;
        case itemCategoryGem:
            vs_mainMenu_setUiGem(&vs_battle_inventory.gems[index],
                &menuText[textOffset * 2], &rowTypes[i], textBuf);
            break;
        case itemCategoryMisc: {
            u_int skillId;
            vs_mainMenu_setUiItem(&vs_battle_inventory.misc[index],
                &menuText[textOffset * 2], &rowTypes[i], textBuf);

            skillId =
                vs_mainMenu_miscItemToSkillMap[vs_battle_inventory.misc[index].id - 323];

            if ((skillId - 106) < 28) {
                int j;
                for (j = 0; j < 3; ++j) {
                    if (vs_main_skills[skillId].unlocked) {
                        ++skillId;
                    }
                }
            }

            _miscSkills[textOffset] = skillId;
            break;
        }
        }

        parentItem = _getParentWeaponIndex(itemCategory, index);

        if (parentItem != 0) {
            rowType = 0xCA00;
            if (vs_battle_inventory.weapons[parentItem - 1].isEquipped == 0) {
                rowType = 0xCC00;
            }
        }

        parentItem = _getParentShieldIndex(itemCategory, index);

        if (parentItem != 0) {
            rowType = 0xCA00;
            if (vs_battle_inventory.shields[parentItem - 1].isEquipped == 0) {
                rowType = 0xCC00;
            }
        }

        rowTypes[i] |= rowType;
    }

    return textOffset;
}

/**
 * @brief Waits for MAINMENU handling and restores saved
 * cursor position.
 */
static void _restoreItemMenu(int itemCategory)
{
    int i;

    while (D_801023D0 < 16) {
        func_80100A5C();
    }

    for (i = 20; i < 40; ++i) {
        vs_battle_menuItem_t* menuItem = vs_battle_getMenuItem(i);

        if (menuItem->state == 2) {
            menuItem->state = 1;
            menuItem->x = menuItem->targetPosition0;
        }

        menuItem->selected =
            (i ^ (D_800F4EE8.cursorMemories[(itemCategory + 30) * 2] + 20)) == 0;
    }
}

/**
 * Processes the items menu navigation.
 *
 * @return int
 */
static int _itemsTopLevelHandler(int initialize)
{
    enum state { init };

    static char D_80109674[8];
    static char state;
    static char noItems;
    static char D_8010967E;
    static char _ __attribute__((unused));
    static int previousSelectedRow;

    int rowCount;
    int* rowTypes;
    char* indices;
    char** menuText;
    int i;
    u_char itemCategory;
    void* textBuf;
    int var_a1_2;
    int var_s1;
    int temp_s3_5;

loop_1:
    if (initialize != 0) {
        vs_battle_menuItem_t* menuItem = vs_battle_getMenuItem(3);

        if (menuItem->x > 180) {
            if (menuItem->x > 204) {
                menuItem->x -= 24;
            }
            menuItem->state = 2;
            menuItem->targetPosition0 = 180;
        }

        _toggleMenuUi(1);

        _secondaryTitleAnimationStep = 0;
        D_8010967E = initialize & 1;

        if (D_8010967E) {
            if (vs_main_settings.cursorMemory == 0) {
                memset(&D_800F4EE8.unk3A, 0, sizeof D_800F4EE8.unk3A);
            }
        }

        state = 1;

        return 0;
    }

    itemCategory = (D_800F4EE8.unk3A.currentItemCategory - 1) & 7;
    indices = vs_mainMenu_inventoryIndices[itemCategory];

    switch (state) {
    case init:
    case 1:
        textBuf = vs_main_allocHeapR(0x1B00);
        rowTypes = textBuf + 0x1800;
        menuText = textBuf + 0x1900;
        D_801023E3 = 1;
        for (i = 0; i < 7; ++i) {
            vs_mainMenu_rebuildInventory(i);
        }

        if (itemCategory == itemCategoryManage) {
            for (i = 0; i < 4; ++i) {
                menuText[i] = (char*)&_menuText[_menuText[VS_menuText_INDEX_equip + i]];
                rowTypes[i] = vs_main_stateFlags.introState < 3;
            }

            if (vs_battle_characterState->unk3C->statuses & 0x80000) {
                for (i = 0; i < 2; ++i) {
                    menuText[i * 2 + 1] =
                        (char*)&_menuText[VS_menuText_OFFSET_equipmentTarnished];
                    rowTypes[i] = 1;
                }
            }
            rowCount = 2;
        } else {
            rowCount = _populateItemRows(itemCategory, menuText, rowTypes, textBuf);
        }

        if (D_800F4EA0 & 7) {
            for (i = 0; i < 64; ++i) {
                rowTypes[i] |= 1;
            }
        }

        noItems = rowCount == 0;

        if (noItems) {
            vs_mainmenu_setInformationMessage(
                (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_noItemsInCategory]);
        } else {
            i = vs_main_settings.cursorMemory;

            if (D_8010967E) {
                D_8010967E = 0;
            } else {
                vs_main_settings.cursorMemory = 1;
            }

            var_a1_2 = itemCategory + 30;

            if (itemCategory == 7) {
                var_a1_2 |= 0x200;
            } else {
                var_a1_2 |= 0x19200;
            }

            vs_mainmenu_setMenuRows(rowCount, var_a1_2, menuText, rowTypes);

            if (state == 0) {
                _restoreItemMenu(itemCategory);
            }

            vs_main_settings.cursorMemory = i;
        }

        vs_main_freeHeapR(textBuf);

        state = 2;
        break;

    case 2:
        _statusCommandState = 1;

        if (noItems) {
            if (vs_main_buttonsPressed.all & PADRup) {
                vs_battle_playMenuLeaveSfx();
                return -2;
            }

            if (vs_main_buttonsPressed.all & PADRdown) {
                vs_battle_playMenuLeaveSfx();
                return -1;
            }

            if (vs_main_buttonsPressed.all & (PADRright | PADRleft)) {
                vs_battle_playInvalidSfx();
            }
        } else {
            if (!(D_800F4EA0 & 7)) {
                u_int rowCount = itemCategory;
                rowCount = rowCount < 6;
                _statusCommandState = rowCount + 1;
            }

            previousSelectedRow = vs_mainmenu_getSelectedRow() + 1;

            if (previousSelectedRow == 0) {
                if (vs_main_buttonsPressed.all & PADRleft) {
                    if ((_statusCommandState >= 2) && vs_mainmenu_ready()) {

                        vs_battle_playMenuSelectSfx();

                        var_s1 = func_80100814();

                        vs_battle_getMenuItem(var_s1 >> 8)->itemState = 0;
                        _itemStatusView(itemCategory | ((var_s1 + 1) << 4));

                        _secondaryTitleEnabled = 0;
                        state = 7;
                        break;
                    }

                    vs_battle_playInvalidSfx();
                }
            } else {
                int* rowTypes;
                void* buf;
                char** menuText;
                int count;

                if ((previousSelectedRow <= 0) || (itemCategory == 7)) {
                    return previousSelectedRow;
                }

                buf = vs_main_allocHeapR(0x1B00);

                menuText = buf + 0x1900;
                rowTypes = buf + 0x1800;

                count = _populateItemRows(itemCategory, menuText, rowTypes, buf);

                rowTypes[previousSelectedRow - 1] |= 8;
                i = vs_main_settings.cursorMemory;
                vs_main_settings.cursorMemory = 1;

                vs_mainmenu_setMenuRows(
                    count, (itemCategory + 30) | 0x19200, menuText, rowTypes);

                vs_main_settings.cursorMemory = i;

                _restoreItemMenu(itemCategory);

                _statusCommandState = 1;
                D_801023E3 = 0;

                vs_main_freeHeapR(buf);

                state = 6;
                break;
            }
        }
        // Fallthrough

    case 3: {
        int temp_v0_7;

        i = vs_main_buttonsState & (PADL1 | PADLleft);
        rowCount = vs_main_buttonsState & (PADR1 | PADLright);
        temp_v0_7 = i != 0;

        if (rowCount != 0) {
            var_s1 = temp_v0_7 ^ 1;
        } else {
            var_s1 = temp_v0_7 & 1;
        }

        if (var_s1 != 0) {
            var_a1_2 = PADL1 | PADLleft;

            if (i == (PADL1 | PADLleft)) {
                var_a1_2 = PADLleft;
            }

            if (vs_main_buttonRepeat & var_a1_2) {
                itemCategory = (itemCategory - 1) & 7;
            }

            var_a1_2 = (PADR1 | PADLright);

            if (rowCount == (PADR1 | PADLright)) {
                var_a1_2 = PADLright;
            }

            if (vs_main_buttonRepeat & var_a1_2) {
                itemCategory = (itemCategory + 1) & 7;
            }

            if (itemCategory != ((D_800F4EE8.unk3A.currentItemCategory - 1) & 7)) {

                vs_battle_playMenuChangeSfx();

                D_800F4EE8.unk3A.currentItemCategory = (itemCategory + 1) & 7;

                if (state == 2) {
                    if (noItems == 0) {
                        func_80100814();
                        vs_mainMenu_clearMenuExcept(3);
                    }
                    state = 3;
                }
            }
        }

        if (state == 3) {
            if (vs_mainmenu_ready() != 0) {
                if ((vs_main_buttonsState & (PADL1 | PADR1 | PADLright | PADLleft))
                    && (var_s1 != 0)) {
                    break;
                }

                state = 1;
                initialize = 0;
                goto loop_1;
            }
        }
        break;
    }

    case 4: {
        vs_battle_menuItem_t* menuItem = vs_battle_getMenuItem(3);

        if (menuItem->x > 180) {
            if (menuItem->x > 204) {
                menuItem->x -= 24;
            }

            menuItem->state = 2;
            menuItem->targetPosition0 = 180;
        }

        state = 5;
    }
        /* fallthrough */

    case 5:
        if (vs_mainmenu_ready() != 0) {
            state = 1;
        }
        break;

    case 6:
        if (vs_main_buttonsPressed.all & PADRleft) {
            vs_battle_playInvalidSfx();
        }

        i = vs_mainmenu_getSelectedRow() + 1;

        if (i == 0) {
            break;
        }

        rowCount = previousSelectedRow;

        if (rowCount == i) {
            state = 8;
            break;
        }

        if (i > 0) {

            var_s1 = indices[i - 1];
            var_a1_2 = indices[rowCount - 1];

            if ((itemCategory == 6)
                && ((vs_battle_inventory.misc[var_s1 - 1].id
                     == vs_battle_inventory.misc[var_a1_2 - 1].id))) {

                vs_battle_inventory.misc[var_a1_2 - 1].count +=
                    vs_battle_inventory.misc[var_s1 - 1].count;

                if (vs_battle_inventory.misc[var_a1_2 - 1].count > 100) {
                    vs_battle_inventory.misc[var_s1 - 1].count =
                        vs_battle_inventory.misc[var_a1_2 - 1].count - 100;
                    vs_battle_inventory.misc[var_a1_2 - 1].count = 100;
                } else {
                    vs_mainMenu_initItem(6, var_s1);
                }
            } else {
                indices[i - 1] = var_a1_2;
                indices[rowCount - 1] = var_s1;
            }

            vs_mainMenu_clearMenuExcept(3);

            state = 4;
            break;
        }

        if (i != -1) {
            return -2;
        }

        state = 0;
        break;

    case 7: {
        vs_battle_menuItem_t* menuItem;

        i = _itemStatusView(0);

        if (i == 0) {
            break;
        }

        if (i == -2) {
            return -2;
        }

        _secondaryTitleEnabled = 1;
        menuItem = vs_battle_getMenuItem(3);

        if (menuItem->x > 180) {
            if (menuItem->x > 204) {
                menuItem->x -= 24;
            }
            menuItem->state = 2;
            menuItem->targetPosition0 = 180;
        }

        state = 1;
    } break;

    case 8: {
        char* menuText[12];
        int rowType;

        rowCount = 0;
        temp_s3_5 = indices[previousSelectedRow - 1] - 1;

        vs_battle_rMemzero(vs_battle_rowTypeBuf, sizeof(int) * 6);

        if (itemCategory == 6) {

            menuText[0] = (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_useItem];
            menuText[1] =
                (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_useItemDesc];

            if (vs_battle_inventory.misc[temp_s3_5].id > 457) {
                *vs_battle_rowTypeBuf = 1;
                menuText[1] =
                    (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_cannotUse];
            } else if (vs_battle_getSkillFlags(0, _miscSkills[previousSelectedRow - 1])
                       & 2) {
                *vs_battle_rowTypeBuf = 1;
                menuText[1] = (char*)&_menuText[VS_menuText_OFFSET_insufficientMp];
            }

            ++rowCount;
            D_80109674[rowCount] = 1;
        }

        if (((char)(itemCategory - 1) < 2) || (itemCategory == 5)) {

            int var_s2 = itemCategory & 0xFF;
            menuText[rowCount * 2] =
                (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_searchItem];
            menuText[rowCount * 2 + 1] =
                (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_searchItemDesc];

            if ((_getParentWeaponIndex(var_s2, temp_s3_5) == 0)
                && (_getParentShieldIndex(var_s2, temp_s3_5) == 0)) {
                menuText[rowCount * 2 + 1] =
                    (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_invalidSearch];
                vs_battle_rowTypeBuf[rowCount] = 1;
            }

            ++rowCount;
            D_80109674[rowCount] = 2;
        }

        rowType = 0;
        menuText[rowCount * 2] =
            (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_discardItem];
        menuText[rowCount * 2 + 1] =
            (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_discardItemDesc];

        switch (itemCategory) {
        case itemCategoryWeapon:
            rowType = (char)vs_battle_inventory.weapons[temp_s3_5].isEquipped != 0;
            break;
        case itemCategoryShield:
            rowType = (char)vs_battle_inventory.shields[temp_s3_5].isEquipped != 0;
            break;
        case itemCategoryArmor:
            rowType = vs_battle_inventory.armor[temp_s3_5].bodyPart != 0;
            break;
        case itemCategoryMisc:
            if (vs_battle_inventory.misc[temp_s3_5].id > 457) {
                rowType = 3;
            }
            break;
        }

        var_a1_2 = _getParentWeaponIndex(itemCategory, temp_s3_5);

        if (var_a1_2 != 0) {
            rowType = 1;
            if (vs_battle_inventory.weapons[var_a1_2 - 1].isEquipped == 0) {
                rowType = 2;
            }
        }

        var_a1_2 = _getParentShieldIndex(itemCategory, temp_s3_5);

        if (var_a1_2 != 0) {
            rowType = 1;
            if (vs_battle_inventory.shields[var_a1_2 - 1].isEquipped == 0) {
                rowType = 2;
            }
        }

        if (rowType != 0) {
            menuText[rowCount * 2 + 1] =
                (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp[rowType + 0x297]];
            rowType = 1;
        }

        vs_battle_rowTypeBuf[rowCount] = rowType;
        ++rowCount;
        D_80109674[rowCount] = 3;

        if (itemCategory == 6) {

            menuText[rowCount * 2] =
                (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_discardAll];
            menuText[rowCount * 2 + 1] =
                (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_discardAllDesc];

            if (vs_battle_inventory.misc[temp_s3_5].id > 457) {
                menuText[rowCount * 2 + 1] =
                    (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_cannotDiscard];
                vs_battle_rowTypeBuf[rowCount] = 1;
            }

            ++rowCount;
            D_80109674[rowCount] = 4;
        }

        menuText[rowCount * 2] =
            (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_sortItem];
        menuText[rowCount * 2 + 1] =
            (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_sortItemDesc];

        ++rowCount;
        D_80109674[rowCount] = 5;

        vs_mainMenu_initSortUi(
            rowCount, itemCategory + 38, menuText, vs_battle_rowTypeBuf);

        state = 9;

        break;
    }

    case 9:
        vs_mainMenu_printInformation(func_800FF348(), D_801022C4);
        vs_mainMenu_processItemActionMenu();

        temp_s3_5 = vs_mainMenu_getSelectedItemAction() + 1;

        if (temp_s3_5 != 0) {

            vs_mainMenu_flyoutLeftExcept(0x28);

            if (temp_s3_5 > 0) {

                vs_battle_playMenuSelectSfx();

                switch (D_80109674[temp_s3_5]) {
                case 1:
                    vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);

                    D_800F5210 = indices[previousSelectedRow - 1] - 1;
                    D_800F4E98.executeAbility.s16[0] =
                        (short)_miscSkills[previousSelectedRow - 1];
                    D_800F4E98.executeAbility.s16[1] =
                        (short)vs_battle_inventory.misc[D_800F5210].id;

                    return 3;

                case 2:
                    vs_mainMenu_initTextBox();
                    vs_mainMenu_clearMenuExcept(3);

                    state = 10;
                    break;

                case 3:
                    rowCount = indices[previousSelectedRow - 1] | (itemCategory << 8);

                    if ((itemCategory == 6)
                        && (vs_battle_inventory.misc[indices[previousSelectedRow - 1] - 1]
                                .count
                            >= 2)) {
                        rowCount |= 0x10000;
                    }

                    _discardMenu(rowCount);

                    state = 11;
                    break;

                case 4:
                    _discardMenu(
                        indices[previousSelectedRow - 1] | (itemCategory << 8) | 0x20000);

                    state = 11;
                    break;

                case 5:
                    vs_mainMenu_initTextBox();
                    _sortItems(itemCategory + 1);

                    state = 12;
                    break;
                }
            } else {

                vs_battle_playMenuLeaveSfx();

                if (temp_s3_5 == -2) {
                    vs_mainMenu_clearMenuExcept(3);

                    return -2;
                }

                vs_mainMenu_initTextBox();

                state = 0;
            }
        }
        break;

    case 10:
        if (vs_mainmenu_ready() == 0) {
            break;
        }

        i = _getParentWeaponIndex(itemCategory, indices[previousSelectedRow - 1] - 1);

        if (i == 0) {
            i = _getParentShieldIndex(itemCategory, indices[previousSelectedRow - 1] - 1);
            itemCategory = 3;
        } else {
            itemCategory = 0;
        }

        D_800F4EE8.unk3A.currentItemCategory = (itemCategory + 1) & 7;

        (&D_800F4EE8.unk3A)->unk2[itemCategory].value =
            vs_mainMenu_findItem(itemCategory, i - 1) - 1;

        state = 1;
        break;

    case 11:
        i = _discardMenu(0);

        if (i != 0) {

            vs_mainMenu_initTextBox();
            vs_mainMenu_flyoutLeftExcept(40);
            vs_mainMenu_clearMenuExcept(3);

            if (i == -2) {
                return -2;
            }

            state = 5;
        }

        break;

    case 12:
        i = _sortItems(0);

        if (i != 0) {
            vs_mainMenu_flyoutLeftExcept(40);
            vs_mainMenu_clearMenuExcept(3);

            if (i == -2) {
                return -2;
            }

            state = 5;
        }

        break;
    }

    return 0;
}

typedef struct {
    u_short name[14];
    int menuRowFlags;
    u_short description[48];
} _itemsText_t;

static char* _itemsText;
static int _selectedItemRow;
static u_char state;
static char _menuRowCount;
static char _itemsFirstRow;
static char _equippedItem;

/**
 * Allocates and initializes the menu rows.
 */
static void _populateMenuRows(int count, u_short** menuText, int* rowTypes)
{
    int i;
    int j;
    vs_battle_menuItem_t* menuItem;
    u_short* text;

    _menuRowCount = count;
    _itemsFirstRow = 0;
    _selectedItemRow = 0;
    state = 1;

    if (_itemsText && _itemsText) { }

    _itemsText = vs_main_allocHeapR(count * 128);

    for (i = 0; i < count; ++i) {

        ((_itemsText_t*)_itemsText)[i].menuRowFlags = rowTypes[i];

        text = menuText[i * 2];

        if (text != NULL) {
            for (j = 0; j < 13; j++) {
                ((u_short*)_itemsText)[i * 64 + j] = text[j];
            }
            ((u_short*)(i * 128 + _itemsText))[13] =
                vs_char_terminator << 8 | vs_char_terminator;
        } else {
            ((u_short*)(i * 128 + _itemsText))[0] =
                vs_char_terminator << 8 | vs_char_terminator;
        }

        text = menuText[i * 2 + 1];

        if (text != NULL) {
            ((_itemsText_t*)_itemsText)[i].description[0] = vs_char_chunkSize;
            for (j = 0; j < 46; ++j) {
                ((u_short*)(_itemsText))[i * 64 + j + 17] = text[j];
            }
            ((_itemsText_t*)_itemsText)[i].description[47] =
                vs_char_terminator << 8 | vs_char_terminator;
        } else {
            ((_itemsText_t*)_itemsText)[i].description[0] =
                vs_char_terminator << 8 | vs_char_terminator;
        }
    }

    j = rowTypes[0];
    menuItem = vs_battle_setMenuItem(20, 155, 18, 165, 0, (char*)_itemsText);
    menuItem->unselectable = j & 1;
    menuItem->icon = j >> 0x1A;
    menuItem->material = (j >> 0x10) & 7;
    menuItem->selected = 1;
    _equippedItem = (j >> 19) & 0x7F;
}

/**
 * Indicates if the user selected an item.
 *
 * @return The selected item, or -1 if selection is pending.
 */
static int _getSelectedItemRow(void)
{
    return _itemsText != NULL ? -1 : _selectedItemRow;
}

/**
 * Common method for processing equip submenus.
 *
 * @param hasSfx set to 1 for weapons and shields
 */
static void _processEquipSubMenu(int hasSfx)
{
    static char D_80109620 = 0;

    int temp_s0;
    int temp_s4;
    int i;
    int temp_s6;
    vs_battle_menuItem_t* menuItem;

    if (state < 6) {
        if (state == _menuRowCount) {
            state = 16;
            return;
        }

        menuItem = vs_battle_setMenuItem(
            state + 20, 320, (state * 16) + 18, 151, 0, _itemsText + (state << 7));
        menuItem->state = 2;
        menuItem->targetPosition0 = 0xA9;
        temp_s0 = ((_itemsText_t*)_itemsText)[state].menuRowFlags;
        menuItem->unselectable = temp_s0 & 1;
        menuItem->icon = (temp_s0 >> 0x1A);

        if (((temp_s0 >> 9) & 0x7F) != 0) {
            menuItem->itemState = ((temp_s0 >> 9) & 0x7F) - 100;
        }

        menuItem->material = (temp_s0 >> 0x10) & 7;
        ++state;

        if (state == 6) {
            if (_menuRowCount >= 7) {
                menuItem->fadeEffect = 2;
            }

            state = 16;
        }

        return;
    }

    temp_s6 = _itemsFirstRow;
    temp_s4 = _selectedItemRow + temp_s6;

    menuItem = vs_battle_getMenuItem(_selectedItemRow + 20);
    vs_mainmenu_setInformationMessage(_itemsText + ((temp_s4 << 7) + 0x20));

    switch (state) {
    case 16:
        if (vs_mainmenu_ready()) {
            state = 17;
        }
        break;

    case 17:
        if (vs_main_buttonsPressed.all & PADRup) {

            // Pointless check, value is always 0 in practice
            if (!(hasSfx & 2)) {
                vs_battle_playMenuLeaveSfx();
            }

            vs_main_freeHeapR(_itemsText);

            _itemsText = NULL;
            _selectedItemRow = -3;

            break;
        }

        if (vs_main_buttonsPressed.all & PADRright) {
            if (menuItem->unselectable) {
                vs_battle_playInvalidSfx();
            } else {

                vs_main_freeHeapR(_itemsText);

                _itemsText = NULL;
                _selectedItemRow = temp_s4;

                if (hasSfx != 0) {
                    if (temp_s4 == 0) {
                        vs_main_playSfxDefault(0x7E, 0x22);
                    } else {
                        vs_main_playSfxDefault(0x7E, 0x21);
                    }
                }
                break;
            }
        }

        menuItem->selected = 0;

        if (vs_main_buttonsPressed.all & PADRdown) {

            vs_battle_playMenuLeaveSfx();
            vs_main_freeHeapR(_itemsText);

            _itemsText = NULL;
            _selectedItemRow = -2;

            break;
        }

        if (vs_main_buttonRepeat & PADLup) {
            if (_menuRowCount < 7 || _itemsFirstRow == 0) {
                if (_selectedItemRow != 0) {
                    --_selectedItemRow;
                }
            } else if (_selectedItemRow == 2) {
                --_itemsFirstRow;
            } else {
                --_selectedItemRow;
            }
        }

        if (vs_main_buttonRepeat & PADLdown) {
            if (_menuRowCount < 7) {
                if (_selectedItemRow < (_menuRowCount - 1)) {
                    ++_selectedItemRow;
                }
            } else if (_itemsFirstRow == (_menuRowCount - 6)) {
                if (_selectedItemRow < 5) {
                    ++_selectedItemRow;
                }
            } else if (_selectedItemRow == 4) {
                ++_itemsFirstRow;
            } else {
                ++_selectedItemRow;
            }
        }

        if (temp_s4 != (_selectedItemRow + _itemsFirstRow)) {
            vs_battle_playMenuChangeSfx();

            if (_itemsFirstRow != temp_s6) {
                char buf[_menuRowCount];
                for (i = 0; i < _menuRowCount; ++i) {
                    buf[i] = 0;
                }
                temp_s0 = _menuRowCount;

                if (_menuRowCount >= 7) {
                    temp_s0 = 6;
                }
                for (i = 1; i < temp_s0; ++i) {
                    buf[i + temp_s6] = vs_battle_getMenuItem(i + 0x14)->animationState;
                }

                for (i = 1;;) {
                    menuItem = vs_battle_setMenuItem(i + 0x14, 0xA9, 0x12 + i * 0x10,
                        0x97, 0, _itemsText + ((i + _itemsFirstRow) << 7));
                    menuItem->animationState = buf[i + _itemsFirstRow];
                    temp_s0 =
                        ((_itemsText_t*)_itemsText)[i + _itemsFirstRow].menuRowFlags;
                    menuItem->unselectable = temp_s0 & 1;
                    menuItem->icon = temp_s0 >> 0x1A;

                    if (((temp_s0 >> 9) & 0x7F) != 0) {
                        menuItem->itemState = ((temp_s0 >> 9) & 0x7F) - 0x64;
                    }

                    menuItem->material = (temp_s0 >> 0x10) & 7;
                    i++;

                    if (i == _menuRowCount) {
                        break;
                    }
                    if (i == 6) {
                        if ((_itemsFirstRow + 6) < _menuRowCount) {
                            menuItem->fadeEffect = 2;
                        }
                        break;
                    }
                }

                if (_itemsFirstRow != 0) {
                    vs_battle_getMenuItem(0x15)->fadeEffect = 1;
                }
            }

            temp_s0 = ((_itemsText_t*)_itemsText)[_selectedItemRow + _itemsFirstRow]
                          .menuRowFlags;
            _equippedItem = (temp_s0 >> 0x13) & 0x7F;
        }

        vs_battle_getMenuItem(_selectedItemRow + 0x14)->selected = 1;

        i = (((_selectedItemRow * 0x10) + 0xA) << 0x10) | 0x9B;

        if (_selectedItemRow == 0) {
            i -= 0xE;
        }

        D_80109620 = vs_mainMenu_renderCursor(D_80109620, i);
        break;
    }
}

static void _populateUiAccessory(int accessoryId)
{

    vs_mainMenu_resetStats();

    if (accessoryId != 0) {
        int i;
        vs_battle_uiAccessory accessory;

        vs_battle_applyAccessory(&accessory, &vs_mainMenu_armor[accessoryId - 1]);

        for (i = 0; i < 16; ++i) {
            vs_mainMenu_equipmentStats[i] = accessory.classes[i & 7];
            vs_mainMenu_equipmentStats[i + 16] = accessory.affinities[i & 7];
            vs_mainMenu_equipmentStats[i + 32] = accessory.types[i & 7];
        }

        vs_mainMenu_setStrIntAgi(
            accessory.currentStr, accessory.currentInt, accessory.currentAgility, 2);
    }

    vs_mainMenu_equipmentSubtype = 32;
    vs_mainMenu_currentUiItem = accessoryId;

    func_800FBB8C(7);
}

/**
 * Manages accessory changes.
 *
 * @return The selected accessory, or 0 if pending.
 */
static int _equipAccessoryMenu(int initialize)
{
    enum state { init, handleInput, loadObject, waitMenuReady };

    static int selectedAccessory;
    static char state;
    static char equippedAccessory;
    static char _[2] __attribute__((unused));

    int i;
    int index;

    if (initialize) {

        for (i = 0; i < 16; ++i) {
            index = vs_main_inventoryIndices.armor[i];
            if (index && (vs_battle_inventory.armor[index - 1].bodyPart == 7)) {
                break;
            }
        }

        if (i == 16) {
            index = 0;
        }

        equippedAccessory = index;

        _populateUiAccessory(index);
        vs_mainMenu_drawClassAffinityType(7);
        vs_mainMenu_renderEquipStats(1);

        state = init;
        return 0;
    }

    switch (state) {
    case init: {
        int hasAccessory;
        int itemCount;

        if (vs_mainmenu_ready() == 0) {
            break;
        }

        itemCount = vs_mainMenu_getItemCount(4, NULL);
        hasAccessory = 0;

        for (i = 0; i < 16; ++i) {
            if (vs_battle_inventory.armor[i].bodyPart == 7) {
                hasAccessory = 1;
            }
        }
        {
            int count = itemCount + 1;
            char textBuf[count * 96];
            u_short* menuText[count * 2];
            int rowTypes[count];
            int rowCount;

            if (!hasAccessory) {
                for (i = 0; i < 2; ++i) {
                    menuText[i] = &_menuText[_menuText[VS_menuText_INDEX_none + i]];
                }
                rowTypes[0] = 1;
            } else {
                for (i = 0; i < itemCount; ++i) {

                    index = vs_main_inventoryIndices.armor[i];

                    if (index && (vs_battle_inventory.armor[index - 1].bodyPart == 7)) {

                        vs_mainMenu_initUiArmor(&vs_battle_inventory.armor[index - 1],
                            (char**)menuText, rowTypes, textBuf);

                        rowTypes[0] |= index << 19;
                    }
                }
            }

            rowCount = 1;

            for (i = 0; i < itemCount; ++i) {

                index = vs_main_inventoryIndices.armor[i];

                if ((index != 0) && (vs_battle_inventory.armor[index - 1].category == 7)
                    && (vs_battle_inventory.armor[index - 1].bodyPart == 0)) {

                    vs_mainMenu_initUiArmor(&vs_battle_inventory.armor[index - 1],
                        (char**)&menuText[rowCount * 2], &rowTypes[rowCount],
                        textBuf + rowCount * 96);

                    rowTypes[rowCount] |= index << 19;
                    ++rowCount;
                }
            }

            _populateMenuRows(rowCount, menuText, rowTypes);

            state = handleInput;
        }
        break;
    }
    case handleInput:
        _populateUiAccessory(_equippedItem);
        _processEquipSubMenu(1);

        selectedAccessory = _getSelectedItemRow() + 1;

        if (!selectedAccessory) {
            break;
        }

        vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
        vs_mainMenu_menuItemFlyoutLeft(-1);
        vs_mainMenu_drawClassAffinityType(-1);
        vs_mainMenu_renderEquipStats(2);

        if (selectedAccessory < 0) {
            state = waitMenuReady;
        } else {
            if (equippedAccessory) {
                vs_battle_inventory.armor[equippedAccessory - 1].bodyPart = 0;
            }

            if (selectedAccessory != 1) {
                vs_battle_inventoryArmor* armor =
                    &vs_battle_inventory.armor[_equippedItem - 1];
                armor->bodyPart = 7;

                vs_battle_equipAccessory(armor);
            } else {
                vs_battle_equipAccessory(NULL);
            }

            state = loadObject;
        }
        break;

    case loadObject:
        state = waitMenuReady;
        /* fallthrough */

    case waitMenuReady:
        if (vs_mainmenu_ready()) {
            return selectedAccessory;
        }

        break;
    }
    return 0;
}

/**
 * Manages weapon changes.
 *
 * @return The selected weapon, or 0 if pending.
 */
static int _equipWeaponMenu(int initialize)
{
    enum state { init, handleInput, loadObject, waitMenuReady };

    static int selectedWeapon;
    static char state;
    static char category;
    static char wepId;
    static char material;

    int i;
    int index;
    vs_battle_inventoryWeapon* weapon;

    if (initialize != 0) {
        for (i = 0; i < 8; ++i) {
            index = vs_main_inventoryIndices.weapons[i];
            if ((index != 0)
                && (vs_battle_inventory.weapons[index - 1].isEquipped != 0)) {
                break;
            }
        }

        if (i == 8) {
            index = 0;
        }

        vs_mainMenu_setUiWeaponStats(index);
        vs_mainMenu_drawClassAffinityType(7);
        vs_mainMenu_drawDpPpbars(3);
        vs_mainMenu_renderEquipStats(1);

        state = init;
        return 0;
    }

    switch (state) {
    case init: {
        int count;
        int hasWeapon;
        int rowCount;

        if (!vs_mainmenu_ready()) {
            break;
        }

        count = vs_mainMenu_getItemCount(0, NULL);
        hasWeapon = 0;

        for (i = 0; i < 8; ++i) {
            if (vs_battle_inventory.weapons[i].isEquipped != 0) {
                hasWeapon = 1;
            }
        }
        {
            char textBuf[(count + 1) * 96];
            u_short* menuText[(count + 1) * 2];
            int rowTypes[(count + 1)];

            if (!hasWeapon) {
                for (i = 0; i < 2; ++i) {
                    menuText[i] = &_menuText[_menuText[VS_menuText_INDEX_none + i]];
                }
                rowTypes[0] = 1;
            } else {
                for (i = 0; i < count; ++i) {

                    index = vs_main_inventoryIndices.weapons[i];

                    if ((index != 0)
                        && (vs_battle_inventory.weapons[index - 1].isEquipped != 0)) {

                        vs_mainMenu_initUiWeapon(&vs_battle_inventory.weapons[index - 1],
                            (char**)menuText, rowTypes, textBuf);

                        rowTypes[0] |= index << 0x13;
                    }
                }
            }

            rowCount = 1;

            for (i = 0; i < count; ++i) {

                index = vs_main_inventoryIndices.weapons[i];

                if (index != 0) {

                    vs_battle_inventoryWeapon* weapon =
                        &vs_battle_inventory.weapons[index - 1];

                    if (weapon->isEquipped == 0) {

                        vs_mainMenu_initUiWeapon(weapon, (char**)&menuText[rowCount * 2],
                            &rowTypes[rowCount], textBuf + rowCount * 96);

                        rowTypes[rowCount] |= index << 0x13;
                        ++rowCount;
                    }
                }
            }

            _populateMenuRows(rowCount, menuText, rowTypes);

            state = handleInput;
        }
        break;
    }
    case handleInput:
        vs_mainMenu_setUiWeaponStats(_equippedItem);
        _processEquipSubMenu(0);

        selectedWeapon = _getSelectedItemRow() + 1;

        if (selectedWeapon == 0) {
            break;
        }

        vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
        vs_mainMenu_menuItemFlyoutLeft(-1);
        vs_mainMenu_drawClassAffinityType(-1);
        vs_mainMenu_drawDpPpbars(4);
        vs_mainMenu_renderEquipStats(2);

        if (selectedWeapon < 0) {
            state = waitMenuReady;
        } else {

            vs_mainMenu_unequipAllWeapons();

            if (selectedWeapon == 1) {
                category = 10;
                wepId = 0;
                material = 0;
            } else {
                vs_battle_inventoryBlade* blade;

                weapon = &vs_battle_inventory.weapons[_equippedItem - 1];
                weapon->isEquipped = 1;

                blade = &vs_battle_inventory.blades[weapon->blade - 1];
                category = blade->category;
                wepId = blade->wepId;
                material = blade->material;

                if (vs_mainMenu_weaponHands[category - 1] != 0) {
                    vs_mainMenu_unequipShield();
                }

                vs_battle_equipWeapon(weapon);
            }
            state = loadObject;
        }
        break;

    case loadObject:
        if (_loadObjectData(category, wepId, material)) {
            break;
        }

        state = waitMenuReady;
        // Fallthrough

    case waitMenuReady:
        if (vs_mainmenu_ready() != 0) {
            return selectedWeapon;
        }

        break;
    }

    return 0;
}

/**
 * Manages shield changes.
 *
 * @return The selected shield, or 0 if pending.
 */
static int _equipShieldMenu(int initialize)
{
    enum state { init, handleInput, loadObject, waitMenuReady };

    static int selectedShield;
    static char state;
    static char wepId;
    static char material;
    static char _ __attribute__((unused));

    int i;
    int index;

    if (initialize != 0) {
        for (i = 0; i < 8; ++i) {
            index = vs_main_inventoryIndices.shields[i];

            if (index && vs_battle_inventory.shields[index - 1].isEquipped) {
                break;
            }
        }

        if (i == 8) {
            index = 0;
        }

        vs_mainMenu_setShieldStats(index);
        vs_mainMenu_drawClassAffinityType(7);
        vs_mainMenu_drawDpPpbars(3);
        vs_mainMenu_renderEquipStats(1);

        state = init;

        return 0;
    }

    switch (state) {
    case init: {
        int count;
        int hasShield;
        int rowCount;

        if (!vs_mainmenu_ready()) {
            break;
        }

        count = vs_mainMenu_getItemCount(3, NULL);
        hasShield = 0;

        for (i = 0; i < 8; ++i) {
            if (vs_battle_inventory.shields[i].isEquipped != 0) {
                hasShield = 1;
            }
        }
        {
            char textBuf[(count + 1) * 96];
            u_short* menuText[(count + 1) * 2];
            int rowTypes[(count + 1)];

            if (!hasShield) {
                for (i = 0; i < 2; ++i) {
                    menuText[i] = &_menuText[_menuText[VS_menuText_INDEX_none + i]];
                }
                rowTypes[0] = 1;
            } else {
                for (i = 0; i < count; ++i) {

                    index = vs_main_inventoryIndices.shields[i];

                    if ((index != 0)
                        && (vs_battle_inventory.shields[index - 1].isEquipped != 0)) {

                        vs_mainMenu_initUiShield(&vs_battle_inventory.shields[index - 1],
                            (char**)menuText, rowTypes, textBuf);

                        rowTypes[0] |= index << 0x13;
                    }
                }
            }

            rowCount = 1;

            for (i = 0; i < count; ++i) {
                index = vs_main_inventoryIndices.shields[i];
                if (index != 0) {
                    if (vs_battle_inventory.shields[index - 1].isEquipped == 0) {
                        vs_mainMenu_initUiShield(&vs_battle_inventory.shields[index - 1],
                            (char**)&menuText[rowCount * 2], &rowTypes[rowCount],
                            textBuf + rowCount * 96);
                        rowTypes[rowCount] |= index << 0x13;
                        ++rowCount;
                    }
                }
            }

            _populateMenuRows(rowCount, menuText, rowTypes);

            state = handleInput;
        }
        break;
    }

    case handleInput:
        vs_mainMenu_setShieldStats(_equippedItem);
        _processEquipSubMenu(0);

        selectedShield = _getSelectedItemRow() + 1;

        if (selectedShield == 0) {
            break;
        }

        vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
        vs_mainMenu_menuItemFlyoutLeft(-1);
        vs_mainMenu_drawClassAffinityType(-1);
        vs_mainMenu_drawDpPpbars(4);
        vs_mainMenu_renderEquipStats(2);

        if (selectedShield < 0) {
            state = waitMenuReady;
        } else {

            vs_mainMenu_unequipShield();

            if (selectedShield == 1) {
                wepId = 0;
                material = 0;
            } else {
                vs_battle_actor2* actor;
                vs_battle_inventoryShield* shield =
                    &vs_battle_inventory.shields[_equippedItem - 1];
                shield->isEquipped = 1;

                actor = vs_battle_characterState->unk3C;
                wepId = shield->base.wepId;
                material = shield->base.material;

                if (actor->weapon.blade.id
                    && vs_mainMenu_weaponHands[actor->weapon.blade.category - 1]) {
                    vs_mainMenu_unequipAllWeapons();
                }

                vs_battle_equipShield(shield);
            }
            state = loadObject;
        }
        break;

    case loadObject:
        if (_loadObjectData(0, wepId, material)) {
            break;
        }
        state = waitMenuReady;
        // Fallthrough

    case waitMenuReady:
        if (vs_mainmenu_ready()) {
            return selectedShield;
        }
        break;
    }

    return 0;
}

/**
 * Manages armor changes.
 *
 * @param initBodyPart Target body part for initialization, 0 otherwise.
 * @return The selected armor, or 0 if pending.
 */
static int _equipArmorMenu(int initBodyPart)
{
    enum state { init, handleInput, loadObject, waitMenuReady };

    static char bodyPartCategories[] = { 0, 5, 5, 2, 3, 4, 6, 7 };

    static int selectedArmor;
    static char state;
    static char armorIndex;
    static u_char bodyPart;

    int i;
    int index;

    if (initBodyPart != 0) {

        bodyPart = initBodyPart;

        for (i = 0; i < 16; ++i) {

            index = vs_main_inventoryIndices.armor[i];

            if ((index != 0)
                && (vs_battle_inventory.armor[index - 1].bodyPart == initBodyPart)) {
                break;
            }
        }

        if (i == 16) {
            index = 0;
        }

        armorIndex = index;

        vs_mainMenu_setArmorStats(index);
        vs_mainMenu_drawClassAffinityType(7);
        vs_mainMenu_drawDpPpbars(1);
        vs_mainMenu_renderEquipStats(1);

        state = init;

        return 0;
    }

    switch (state) {
    case init: {
        int hasArmor;
        int count;
        int rowCount;

        if (vs_mainmenu_ready() == 0) {
            break;
        }

        count = vs_mainMenu_getItemCount(4, NULL);
        hasArmor = 0;

        for (i = 0; i < 16; ++i) {
            if (vs_battle_inventory.armor[i].bodyPart == bodyPart) {
                hasArmor = 1;
            }
        }
        {
            char textBuf[(count + 1) * 96];
            u_short* menuText[(count + 1) * 2];
            int rowTypes[(count + 1)];

            if (!hasArmor) {
                for (i = 0; i < 2; ++i) {
                    menuText[i] = &_menuText[_menuText[VS_menuText_INDEX_none + i]];
                }
                rowTypes[0] = 1;
            } else {
                for (i = 0; i < count; ++i) {

                    index = vs_main_inventoryIndices.armor[i];

                    if ((index != 0)
                        && (vs_battle_inventory.armor[index - 1].bodyPart == bodyPart)) {

                        vs_mainMenu_initUiArmor(&vs_battle_inventory.armor[index - 1],
                            (char**)menuText, rowTypes, textBuf);

                        rowTypes[0] |= index << 0x13;
                    }
                }
            }

            rowCount = 1;

            for (i = 0; i < count; ++i) {

                index = vs_main_inventoryIndices.armor[i];

                if ((index != 0)
                    && (vs_battle_inventory.armor[index - 1].category
                        == bodyPartCategories[bodyPart])
                    && (vs_battle_inventory.armor[index - 1].bodyPart == 0)) {

                    vs_mainMenu_initUiArmor(&vs_battle_inventory.armor[index - 1],
                        (char**)&menuText[rowCount * 2], &rowTypes[rowCount],
                        textBuf + rowCount * 0x60);

                    rowTypes[rowCount] |= index << 0x13;
                    ++rowCount;
                }
            }
            _populateMenuRows(rowCount, menuText, rowTypes);

            state = handleInput;
        }

        break;
    }

    case handleInput:
        vs_mainMenu_setArmorStats(_equippedItem);
        _processEquipSubMenu(1);

        selectedArmor = _getSelectedItemRow() + 1;

        if (selectedArmor == 0) {
            break;
        }

        vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
        vs_mainMenu_menuItemFlyoutLeft(-1);
        vs_mainMenu_drawClassAffinityType(-1);
        vs_mainMenu_drawDpPpbars(4);
        vs_mainMenu_renderEquipStats(2);

        if (selectedArmor < 0) {
            state = 3;
        } else {
            if (armorIndex != 0) {
                vs_battle_inventory.armor[armorIndex - 1].bodyPart = 0;
            }
            if (selectedArmor == 1) {
                vs_battle_equipArmor(bodyPart - 1, NULL);
            } else {
                vs_battle_inventoryArmor* armor =
                    &vs_battle_inventory.armor[_equippedItem - 1];
                armor->bodyPart = bodyPart;

                vs_battle_equipArmor(bodyPart - 1, armor);
            }

            state = loadObject;
        }
        break;

    case loadObject:
        state = waitMenuReady;
        // Fallthrough

    case waitMenuReady:
        if (vs_mainmenu_ready() != 0) {
            return selectedArmor;
        }
        break;
    }

    return 0;
}

/**
 * Invokes the selected equip submenu.
 *
 * @return The result of the invoked row.
 */
static int _dispatchEquipMenu(int row)
{
    static int (*equipMenuHandlers[])(int) = { _equipArmorMenu, _equipWeaponMenu,
        _equipShieldMenu, _equipAccessoryMenu };

    static u_char currentEquipMenu;

    if (row != 0) {
        if (row == 8) {
            currentEquipMenu = 3;
        } else if (row > 2) {
            row -= 2;
            currentEquipMenu = 0;
        } else {
            currentEquipMenu = row;
        }
    }

    return equipMenuHandlers[currentEquipMenu](row);
}

/**
 * Top level equip menu handler.
 *
 * @return Negative when user has returned, 0 otherwise.
 */
static int _equipMenu(int initialize)
{
    enum state { init, initMenu, topMenu, quit, initEquipSubMenu, equipSubMenu };

    static char equipMenuRowTypes[] = { 0x78, 0x79, 0x69, 0x6A, 0x68, 0x6D, 0x6B, 0x7A };

    static int selectedRow;
    static char state;
    static char _[3] __attribute__((unused));

    char* rowStrings[16];
    int rowTypes[8];
    char buf[768];
    int j;
    int i;
    vs_battle_menuItem_t* menuItem;
    vs_battle_inventoryShield* shield;
    vs_battle_inventoryWeapon* weapon;

    if (initialize != 0) {
        vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);

        _selectedItemCategoryIconOnTop = 1;
        state = init;

        return 0;
    }

    switch (state) {
    case init:
        if (vs_mainmenu_ready() == 0) {
            break;
        }

        menuItem = vs_battle_setMenuItem(
            31, 320, 18, 126, 8, (char*)&_menuText[VS_menuText_OFFSET_equip]);
        menuItem->state = menuItemTransition_toLeft;
        menuItem->targetPosition0 = 180;
        menuItem->selected = 1;
        state = initMenu;
        // Fallthrough

    case initMenu:
        if (vs_mainmenu_ready() == 0) {
            break;
        }

        _selectedItemCategoryIconOnTop = 1;

        for (i = 0; i < 8; ++i) {
            for (j = 0; j < 2; ++j) {
                rowStrings[i * 2 + j] =
                    (char*)&_menuText[_menuText[VS_menuText_INDEX_none + j]];
            }
            rowTypes[i] = 0;
        }

        weapon = vs_battle_inventory.weapons;

        for (j = 0; j < 8; ++j, ++weapon) {
            if (weapon->isEquipped != 0) {
                vs_mainMenu_initUiWeapon(weapon, (char**)rowStrings, rowTypes, buf);
                break;
            }
        }

        shield = vs_battle_inventory.shields;

        for (j = 0; j < 8; ++j, ++shield) {
            if (shield->isEquipped != 0) {
                vs_mainMenu_initUiShield(shield, &rowStrings[2], &rowTypes[1], buf + 96);
                break;
            }
        }

        for (i = 2; i < 8; ++i) {
            vs_battle_inventoryArmor* armor = vs_battle_inventory.armor;

            for (j = 0; j < 16; ++j, ++armor) {
                if (((i != 7) + armor->bodyPart) == i) {
                    vs_mainMenu_initUiArmor(
                        armor, &rowStrings[i * 2], &rowTypes[i], &buf[i * 96]);
                    break;
                }
            }
        }

        for (i = 0; i < 8; ++i) {
            rowTypes[i] |= equipMenuRowTypes[i] << 9;
        }

        vs_mainmenu_setMenuRows(8, menuRowInfo(4, 3, 401), &rowStrings[0], rowTypes);
        state = topMenu;

        break;

    case topMenu:
        if (vs_main_buttonsPressed.all & PADRleft) {
            vs_battle_playInvalidSfx();
        }

        selectedRow = vs_mainmenu_getSelectedRow() + 1;

        if (selectedRow == menuSelectionConfirm) {
            break;
        }

        if (selectedRow < 0) {
            _selectedItemCategoryIconOnTop = -selectedRow;

            vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);

            state = quit;
        } else {
            _startMenuTransition(selectedRow - 1 + 10);

            state = initEquipSubMenu;
        }
        break;

    case quit:
        if ((selectedRow == menuSelectionQuit) || vs_mainmenu_ready()) {
            return selectedRow;
        }

        break;

    case initEquipSubMenu:
        if (!vs_mainmenu_ready()) {
            break;
        }

        _ashleyRenderState = 1;

        _continueMenuTransition(selectedRow + 9);

        _itemCategoryIconsEnabled = 0;
        _statusCommandState = 0;

        _dispatchEquipMenu(selectedRow);

        state = equipSubMenu;
        break;

    case equipSubMenu:
        selectedRow = _dispatchEquipMenu(0);

        if (selectedRow == 0) {
            break;
        }

        if (selectedRow == menuSelectionQuit) {
            state = quit;
            break;
        }

        _ashleyRenderState = 0;
        _itemCategoryIconsEnabled = 1;
        _selectedItemCategoryIconOnTop = 2;
        _statusCommandState = 1;
        state = init;

        break;
    }

    if (state == topMenu) {
        menuItem = vs_battle_setMenuItem(31, 180, 18, 140, 8,
            (char*)&_menuText[_menuText[VS_menuText_INDEX_equipWeapon
                                        + vs_mainMenu_getConfirmedRow()]]);
        menuItem->selected = 1;
    }

    return 0;
}

enum ashleyRenderMode {
    ashleyRenderModeRender,
    ashleyRenderModeInit,
    ashleyRenderModeRestore
};

/**
 * Responsible for rendering 3D model.
 *
 * @param mode
 * - ashleyRenderModeInit Called when entering menu
 *
 * - ashleyRenderModeRender Called each frame while in menu
 *
 * - ashleyRenderModeRestore Called when leaving menu
 */
static void _renderAshley(int mode)
{
    static int render = 0;
    static char skipFrame = 0;

    static int projectionDistanceBackup;
    static int _[3] __attribute__((unused));
    static vs_unk_gfx_t2 D_801096BC;
    static vs_unk_gfx_t D_801096DC;

    int yOffset;
    vs_unk_gfx_t* p = (vs_unk_gfx_t*)&D_1F800000[13];

    switch (mode) {
    case ashleyRenderModeRender:
        yOffset = _ashleyYOffset;

        switch (_ashleyRenderState) {
        case 0:
            if (yOffset < 10) {
                ++yOffset;
                _ashleyYOffset = yOffset;
            }

            yOffset = 128 - vs_battle_rowAnimationSteps[10 - yOffset];
            break;

        case 1:
            if (yOffset > 0) {
                --yOffset;
                _ashleyYOffset = yOffset;
            }
            yOffset = vs_battle_rowAnimationSteps[yOffset];
            break;

        case 2:
            if (yOffset < 10) {
                ++yOffset;
                _ashleyYOffset = yOffset;
            } else {
                _ashleyRenderState = 0;
            }

            yOffset = vs_battle_rowAnimationSteps[10 - yOffset] + 128;
            break;

        case 3:
            if (yOffset > 0) {
                --yOffset;
                _ashleyYOffset = yOffset;
            }

            yOffset = 608 - yOffset * 48;
            break;
        }

        if (skipFrame != 0) {
            skipFrame = 0;
            return;
        }

        if (render != 0) {
            int temp_s1_2;
            int temp_lo;
            int temp_lo_2;
            int temp_s1 = D_800F4538[1]->cameraDistance;

            p->unk10 = ((-rsin(0xB00) * yOffset) >> 8) * temp_s1;
            p->unk14.unk0 = -(D_800F4538[1]->cameraHeightOffset << 0xB);
            p->unk14.unk4 = ((rcos(0xB00) * yOffset) >> 8) * temp_s1;

            temp_s1_2 = temp_s1 * 4;
            temp_lo = rcos(0xB00) * temp_s1_2;

            p->unk0 = p->unk10 + temp_lo;
            p->unk4 = p->unk14.unk0;

            temp_lo_2 = rsin(0xB00) * temp_s1_2;

            p->unk14.unkC = 0;
            p->unk14.unk10 = 0;
            p->unk14.unk14 = 0;
            p->unk14.unk1C = 0x1000;
            p->unk8 = p->unk14.unk4 + temp_lo_2;

            func_8007ACB0();
            func_800F9EB8(&D_1F800000[5]);
        }
        break;

    case ashleyRenderModeInit:
        if (render == 0) {
            _ashleyYOffset = 0;
            _ashleyRenderState = 2;
            skipFrame = 1;
            render = 1;
            projectionDistanceBackup = vs_main_projectionDistance;

            vs_battle_setProjectionDistance(512);

            D_801096BC = p[-1].unk14;
            D_801096DC = *p;

            p->unk14.unkC = 0;
            p->unk14.unk10 = 0;
            p->unk14.unk14 = 0;
            p->unk14.unk1C = 0x1000;

            func_8007ACB0();
            func_80100414(0x7FE, 0x80);
            func_800F9A24(0);
        }
        break;

    case ashleyRenderModeRestore:
        if (render != 0) {

            func_800F9E0C();
            func_80100414(-4, 0x80);
            vs_battle_setProjectionDistance(projectionDistanceBackup);

            p[-1].unk14 = D_801096BC;
            *p = D_801096DC;
            render = 0;
        }

        break;
    }
}

/**
 * Module entrypoint
 */
int vs_menu3_exec(char* state)
{
    enum state {
        none,
        init = 3,
        loadItemNamesWait,
        itemsTop,
        equip,
        quit = 9,
        quitToBattle
    };

    static char D_80109649 = 0;
    static char D_80109710;

    int category;
    int row;
    char temp_a1;
    char temp_a1_2;

    switch (*state) {
    case init:
        _toggleMenuUi(0);
        func_800FBD80(16);

        _secondaryTitleAnimationStep = 0;
        _itemCategoryIconsAnimationStep = 0;
        _statusCommandAnimationStep = 0;
        _selectedItemCategoryIconOnTop = 0;

        if (vs_mainMenu_itemNames == NULL) {
            vs_mainMenu_loadItemNames(1);
        }

        if (vs_mainmenu_ready() == 0) {
            break;
        }

        func_8008A4DC(0);
        vs_mainMenu_initTextBox();
        func_800CB654(1);

        D_800EB9B0 = 0x200000;

        _renderAshley(1);
        _itemsTopLevelHandler(D_80109649 + 1);

        D_80109649 = 0;
        *state = loadItemNamesWait;
        // Fallthrough

    case loadItemNamesWait:
        if (vs_mainMenu_loadItemNames(0) == 0) {
            break;
        }

        *state = itemsTop;
        // Fallthrough

    case itemsTop:
        row = _itemsTopLevelHandler(0);

        if (row == 0) {
            break;
        }

        if (row > 0) {
            switch (row) {
            case 1:
                _equipMenu(1);

                D_801023E3 = 0;
                *state = equip;

                break;

            case 2:
                _ashleyRenderState = 3;

                vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);

                _secondaryTitleEnabled = 0;
                _itemCategoryIconsEnabled = 0;
                _statusCommandState = 0;
                *state = 7;

                break;

            case 3:
                _toggleMenuUi(0);
                vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
                func_8008A4DC(1);

                vs_battle_menuState.executeAbilityType = 13;
                *state = 12;

                func_800CB654(0);

                D_800EB9B0 = 0;

                _renderAshley(2);

                break;
            }
        } else {
            if (row == menuSelectionQuit) {
                *state = quitToBattle;
            } else {
                *state = quit;

                _toggleMenuUi(0);
                vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
                func_8008A4DC(1);
                func_800CB654(0);

                D_800EB9B0 = 0;

                _renderAshley(2);
            }
        }
        break;

    case equip:
        row = _equipMenu(0);

        if (row != 0) {
            if (row == menuSelectionQuit) {
                _secondaryTitleEnabled = 0;
                _secondaryTitleAnimationStep = 0;
                *state = quitToBattle;
                break;
            }

            _itemCategoryIconsEnabled = 1;
            _selectedItemCategoryIconOnTop = 0;
            _statusCommandState = 1;

            _itemsTopLevelHandler(1);

            *state = itemsTop;
        }

        break;

    case 7:
        if (vs_mainmenu_ready()) {
            _renderAshley(2);

            *state = 8;
            temp_a1 = vs_battle_menuState.currentState;
            vs_battle_menuState.currentState = 13;
            vs_battle_menuState.returnState = temp_a1;
            D_800F4EA0 |= 0x200;
        }
        break;

    case 8:
        if (vs_battle_menuState.returnState != 0) {
            func_80100414(-4, 0x80);
            func_8008A4DC(1);
            _toggleMenuUi(0);
            vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
            func_800CB654(0);

            D_800EB9B0 = 0;
            D_80109710 = 10;

            *state = 11;
        } else if (vs_mainmenu_ready()) {
            _toggleMenuUi(0);

            _secondaryTitleAnimationStep = 0;
            _itemCategoryIconsAnimationStep = 0;
            _statusCommandAnimationStep = 0;
            _selectedItemCategoryIconOnTop = 0;

            _renderAshley(1);
            _itemsTopLevelHandler(1);

            *state = itemsTop;
        }
        break;

    case quit:
        func_800FFB68(0);
        vs_mainMenu_dismissTextBox();
        vs_mainMenu_setNextMenuAction(menuActionNone);

        if (vs_mainmenu_ready() && vs_mainMenu_ensureItemNamesLoaded()) {
            *state = none;
            return 1;
        }

        break;

    case quitToBattle:
        func_8008A4DC(1);
        _toggleMenuUi(0);
        vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
        func_800CB654(0);

        D_800EB9B0 = 0;

        _renderAshley(2);

        D_80109710 = 10;
        *state = 11;

        break;

    case 11:
        func_800FFB68(0);
        vs_mainMenu_dismissTextBox();
        vs_mainMenu_setNextMenuAction(menuActionNone);

        if (D_80109710 != 0) {
            --D_80109710;
            break;
        }

        if (vs_mainmenu_ready() && vs_mainMenu_ensureItemNamesLoaded()) {
            vs_battle_menuState.currentState = 4;
            *state = none;
            return 1;
        }

        break;

    case 12:
        func_800FFB68(0);
        vs_mainMenu_dismissTextBox();
        vs_mainMenu_setNextMenuAction(menuActionNone);

        if ((D_801022D8 == 0) && vs_mainMenu_ensureItemNamesLoaded()) {

            D_800F4E98.unk2 = 8;
            temp_a1_2 = vs_battle_menuState.currentState;
            vs_battle_menuState.currentState = 4;
            vs_battle_menuState.returnState = temp_a1_2;
            *state = none;

            return 1;
        }

        break;

    case 13:
        D_80109649 = 1;
        *state = none;

        break;
    }

    if (_secondaryTitleEnabled != 0) {
        if (_secondaryTitleAnimationStep < 10) {
            ++_secondaryTitleAnimationStep;
        }
        row = vs_battle_rowAnimationSteps[10 - _secondaryTitleAnimationStep];
    } else {
        if (_secondaryTitleAnimationStep != 0) {
            --_secondaryTitleAnimationStep;
        }
        row = (10 - _secondaryTitleAnimationStep) << 5;
    }

    if ((_secondaryTitleAnimationStep != 0) && (_selectedItemCategoryIconOnTop == 0)) {
        vs_battle_menuItem_t* menuitem;

        category = (D_800F4EE8.unk3A.currentItemCategory - 1) & 7;

        menuitem = vs_battle_setMenuItem(
            31, row + 180, 34, 140, 8, (char*)&_menuText[_menuText[category]]);
        menuitem->selected = 1;

        if (category != 7) {
            menuitem->unk12 = vs_mainMenu_inventoryItemCapacities[category];
            menuitem->unk10 = vs_mainMenu_getItemCount(category, 0);
        }
    }

    _renderAshley(0);

    if (_itemCategoryIconsEnabled) {
        if (_itemCategoryIconsAnimationStep < 4) {
            ++_itemCategoryIconsAnimationStep;
        }
    } else if (_itemCategoryIconsAnimationStep != 0) {
        --_itemCategoryIconsAnimationStep;
    }

    _animateItemCategoryBar(
        _itemCategoryIconsAnimationStep, _selectedItemCategoryIconOnTop);

    if (_statusCommandState) {
        if (_statusCommandAnimationStep < 10) {
            ++_statusCommandAnimationStep;
        }
        row = vs_battle_rowAnimationSteps[10 - _statusCommandAnimationStep];
    } else {
        if (_statusCommandAnimationStep != 0) {
            --_statusCommandAnimationStep;
        }
        row = (10 - _statusCommandAnimationStep) << 5;
    }

    if (_statusCommandAnimationStep != 0) {
        vs_mainMenu_drawButtonUiBackground(16 - row, 38, 88, 10);
        vs_mainmenu_drawButton(1, 8 - row, 36, NULL);
        vs_battle_renderTextRawColor("STATUS", vs_getXY(28 - row, 38),
            vs_getRGB888(32, 32, 32) << _statusCommandState, NULL);
    }

    return 0;
}
