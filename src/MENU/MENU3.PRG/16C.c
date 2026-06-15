#include "common.h"
#include "../MAINMENU.PRG/278.h"
#include "../MAINMENU.PRG/C48.h"
#include "../MAINMENU.PRG/2D10.h"
#include "../MAINMENU.PRG/58EC.h"
#include "../../SLUS_010.40/main.h"
#include "../../SLUS_010.40/31724.h"
#include "../../BATTLE/BATTLE.PRG/2842C.h"
#include "../../BATTLE/BATTLE.PRG/30D14.h"
#include "../../BATTLE/BATTLE.PRG/3A1A0.h"
#include "../../BATTLE/BATTLE.PRG/44F14.h"
#include "../../BATTLE/BATTLE.PRG/573B8.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"
#include "build/assets/MENU/ITEMHELP.BIN.h"
#include "build/assets/MENU/MENU3.PRG/menuText.h"
#include "vs_string.h"
#include "gpu.h"
#include <memory.h>
#include <libetc.h>

extern void* D_1F800000[];

static char D_80109711;
static char D_80109712;
static char D_80109713;

static void func_8010296C(char arg0)
{
    D_80109711 = arg0;
    D_80109712 = arg0;
    D_80109713 = arg0;
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

static void func_80102A3C(int arg0, int arg1)
{
    int temp_s0;
    int temp_s4;
    int i;
    u_long* texPage;
    int new_var;

    temp_s4 = (D_800F4EE8.cursorMemories[58] - 1) & 7;

    if (arg0 == 4) {
        func_801013F8(0);
    }

    new_var = (arg0 * 8);
    arg0 = new_var - 0x10;

    for (i = 0; i < 8; ++i) {

        temp_s0 = (((i + 1) & 7) * 0x10) + 0x20;

        if (i == temp_s4 && arg1 == 1) {

            vs_battle_menuItem_t* menuItem = vs_battle_getMenuItem(31);

            if (temp_s0 >= (menuItem->initialX - 0xC)) {
                menuItem->icon = i + 24;
                continue;
            }

            texPage = vs_battle_setSpriteDefault(vs_getWH(16, 16), temp_s0 | 0x100000);
        } else {
            texPage = vs_battle_setSpriteDefaultTexPage(
                128, temp_s0 | (arg0 << 0x10), vs_getWH(16, 16), D_1F800000[1]);
        }

        texPage[4] =
            (0x78 + i * 16) | 0x8000 | ((i == temp_s4) ? 0x37FD0000 : 0x37FE0000);
    }
}

/**
 * Hoists the item category and selected item to the top of the menu
 * during the start of the status view transition animation.
 */
static void _statusViewStartTransition(int selectedItem)
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
static void _statusViewContinueTransition(int selectedItem)
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

static int D_80109564 = 0;
static int D_80109568 = 0;

static void func_80102C44(int selectedItem, int arg1)
{
    D_80109568 = 1;
    D_80109712 = 0;
    D_80109713 = 0;
    _statusViewContinueTransition(selectedItem);
    vs_mainMenu_drawClassAffinityType(arg1);
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
    D_800F4EE8.cursorMemories[(itemCategory + 30) * 2] = 0;
    D_800F4EE8.cursorMemories[(itemCategory + 30) * 2 + 1] = itemId;
    return vs_mainMenu_inventoryIndices[itemCategory][itemId];
}

static char D_80109714;
static char D_80109715;
static char D_80109716;
static char D_80109717;
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

    D_80109717 = 2;
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

        _statusViewStartTransition(itemRow);

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

        _statusViewStartTransition(itemRow);

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

        _statusViewStartTransition(itemRow);

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

        _statusViewStartTransition(itemRow);

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

        _statusViewStartTransition(itemRow);

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

        _statusViewStartTransition(itemRow);

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
        D_80109717 = 1;
        _menuButtonPressed = 0;

        func_800FDD78();
        vs_battle_getMenuItem(31)->itemPage = page & 0xFF;
        vs_mainMenu_setNextMenuAction(menuActionNone);
    }

    page = _statusViewDispatchers[itemCategory](page);
    new_var = page != 0;

    if (new_var) {
        if (_menuButtonPressed == 0) {
            D_80109712 = 1;
            D_80109717 = 0;
            D_80109713 = 1;
            D_80109568 = 0;

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
 * Facilitates sorting by mapping stat types to a numerical value.
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
    vs_battle_uiWeapon weapon;
    char sp1A8[8];
    int temp_v0;
    int i;
    int var_s3;
    int var_s4;
    int temp_s0;
    vs_battle_inventoryWeapon* new_var2 = vs_battle_inventory.weapons;
    char* new_var = vs_main_inventoryIndices.weapons;

    vs_battle_rMemzero(sp1A8, 8);
    var_s4 = 0;

    while (1) {
        var_s3 = 0x80000000;

        for (i = 0; i < 8; ++i) {
            temp_s0 = new_var[i];
            if (temp_s0 != 0) {
                vs_battle_applyWeapon(&weapon, &new_var2[temp_s0 - 1]);
                temp_v0 = _getWeaponStatValue(stat, &weapon);
                if (var_s3 < temp_v0) {
                    var_s3 = temp_v0;
                }
            }
        }

        if (var_s3 == 0x80000000) {
            break;
        }

        for (i = 0; i < 8; ++i) {
            temp_s0 = new_var[i];
            if (temp_s0 != 0) {
                vs_battle_applyWeapon(&weapon, &new_var2[temp_s0 - 1]);
                if (_getWeaponStatValue(stat, &weapon) == var_s3) {
                    sp1A8[var_s4++] = temp_s0;
                    new_var[i] = 0;
                }
            }
        }
    }
    vs_battle_memcpy(new_var, sp1A8, 8);
}

static int _getShieldStat(int arg0, vs_battle_uiShield* shield)
{
    switch (arg0) {
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
        if (arg0 < 33) {
            return shield->classAffinityCurrent.class[0][arg0 - 27];
        }
        if (arg0 >= 40) {
            return shield->types[arg0 - 39];
        }
        return shield->classAffinityCurrent.affinity[0][arg0 - 33];
    }
}

static void func_80103F00(int arg0)
{
    vs_battle_uiShield shield;
    char sp1A8[8];
    int temp_v0;
    int i;
    int var_s3;
    int var_s4;
    int temp_s0;
    vs_battle_inventoryShield* new_var2 = &vs_battle_inventory.shields[0];
    char* new_var = vs_main_inventoryIndices.shields;

    vs_battle_rMemzero(sp1A8, sizeof sp1A8);
    var_s4 = 0;

    while (1) {
        var_s3 = 0x80000000;

        for (i = 0; i < 8; ++i) {
            temp_s0 = new_var[i];
            if (temp_s0 != 0) {
                vs_battle_applyShield(&shield, &new_var2[temp_s0 - 1]);
                temp_v0 = _getShieldStat(arg0, &shield);
                if (var_s3 < temp_v0) {
                    var_s3 = temp_v0;
                }
            }
        }

        if (var_s3 == 0x80000000) {
            break;
        }

        for (i = 0; i < 8; ++i) {
            temp_s0 = new_var[i];
            if (temp_s0 != 0) {
                vs_battle_applyShield(&shield, &new_var2[temp_s0 - 1]);
                if (_getShieldStat(arg0, &shield) == var_s3) {
                    sp1A8[var_s4++] = temp_s0;
                    new_var[i] = 0;
                }
            }
        }
    }
    vs_battle_memcpy(new_var, sp1A8, 8);
}

static int func_8010406C(int arg0, vs_battle_inventoryMisc* arg1)
{
    if (arg0 == 0) {
        return -arg1->id;
    }
    return arg1->count;
}

static void func_8010408C(int arg0)
{
    char sp10[0x40];
    int temp_v0;
    int i;
    int var_s3;
    int var_s4;
    int temp_s0;
    vs_battle_inventoryMisc* new_var2 = vs_battle_inventory.misc;
    char* new_var = vs_main_inventoryIndices.misc;

    vs_battle_rMemzero(sp10, 0x40);
    var_s4 = 0;

    while (1) {
        var_s3 = 0x80000000;

        for (i = 0; i < 0x40; ++i) {
            temp_s0 = new_var[i];
            if (temp_s0 != 0) {
                temp_v0 = func_8010406C(arg0, &new_var2[temp_s0 - 1]);
                if (var_s3 < temp_v0) {
                    var_s3 = temp_v0;
                }
            }
        }

        if (var_s3 == 0x80000000) {
            break;
        }

        for (i = 0; i < 0x40; ++i) {
            temp_s0 = new_var[i];
            if (temp_s0 != 0) {
                if (func_8010406C(arg0, &new_var2[temp_s0 - 1]) == var_s3) {
                    sp10[var_s4++] = temp_s0;
                    new_var[i] = 0;
                }
            }
        }
    }
    vs_battle_memcpy(new_var, sp10, 0x40);
}

static int func_801041CC(int arg0, vs_battle_uiEquipment* arg1)
{
    switch (arg0) {
    case 0:
        return -arg1->category;
    case 1:
        return -arg1->material;
    case 2:
        return arg1->range.range;
    case 3:
        return -arg1->damageType;
    case 4:
        return arg1->currentDp;
    case 5:
        return arg1->maxDp;
    case 6:
        return arg1->currentPp;
    case 7:
        return arg1->maxPp;
    case 8:
        return arg1->strength;
    case 9:
        return arg1->intelligence;
    case 10:
        return arg1->agility;
    default:
        if (arg0 >= 0x1B) {
            arg0 -= 0x10;
        }
        if (arg0 < 0x11) {
            return *(((signed char*)&arg1->gemSlots) + arg0);
        }
        if (arg0 >= 0x18) {
            return *(((signed char*)&arg1->strength) + arg0);
        }
        return *(((signed char*)&arg1->index) + arg0);
    }
}

static void func_801042C4(vs_battle_uiEquipment* arg0, int arg1, int arg2)
{
    switch (arg1) {
    case 1:
        vs_battle_copyInventoryBladeStats(arg0, &vs_battle_inventory.blades[arg2]);
        return;
    case 2:
        vs_battle_copyInventoryGripStats(arg0, &vs_battle_inventory.grips[arg2]);
        return;
    case 4:
        vs_battle_copyInventoryArmorStats(arg0, &vs_battle_inventory.armor[arg2]);
        return;
    case 5:
        vs_battle_copyInventoryGemStats(arg0, &vs_battle_inventory.gems[arg2]);
        return;
    }
}

static void _copyEquipmentStats(int arg0, int arg1)
{
    vs_battle_uiEquipment sp10;
    int temp_v0;
    int i;
    int var_s3;
    int var_s5;
    char* temp_s6;
    int temp_s0;
    int temp_s4;

    var_s5 = 0;
    temp_s4 = vs_mainMenu_inventoryItemCapacities[arg0];
    {
        char spVLA[temp_s4];
        temp_s6 = vs_mainMenu_inventoryIndices[arg0];
        vs_battle_rMemzero(spVLA, temp_s4);

        while (1) {
            var_s3 = 0x80000000;
            for (i = 0; i < temp_s4; ++i) {
                temp_s0 = temp_s6[i];
                if (temp_s0 != 0) {
                    func_801042C4(&sp10, arg0, temp_s0 - 1);
                    temp_v0 = func_801041CC(arg1, &sp10);
                    if (var_s3 < temp_v0) {
                        var_s3 = temp_v0;
                    }
                }
            }

            if (var_s3 == 0x80000000) {
                break;
            }

            for (i = 0; i < temp_s4; ++i) {
                temp_s0 = temp_s6[i];
                if (temp_s0 != 0) {
                    func_801042C4(&sp10, arg0, temp_s0 - 1);
                    if (func_801041CC(arg1, &sp10) == var_s3) {
                        spVLA[var_s5++] = temp_s0;
                        temp_s6[i] = 0;
                    }
                }
            }
        }
        vs_battle_memcpy(temp_s6, spVLA, temp_s4);
    }
}

static int func_80104530(int arg0)
{
    static u_char D_80109588[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
        16, 17, 18, 19, 20, 21, 22, 23 };
    static u_char D_801095A0[] = { 0, 8, 9, 10, 24, 25, 26 };
    static u_char D_801095A8[] = { 1, 4, 5, 6, 7, 8, 9, 10, 40, 41, 42, 27, 28, 29, 30,
        31, 32, 33, 34, 35, 36, 37, 38, 39 };
    static u_char D_801095C0[] = { 0, 1, 4, 5, 8, 9, 10, 40, 41, 42, 27, 28, 29, 30, 31,
        32, 33, 34, 35, 36, 37, 38, 39 };
    static u_char D_801095D8[] = { 8, 9, 10, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37,
        38, 39 };
    static u_char D_801095E8[] = { 0, 56 };
    static u_char D_801095EC[] = { 24, 24, 7, 24, 23, 16, 2 };
    static u_char* D_801095F4[] = { D_80109588, D_80109588, D_801095A0, D_801095A8,
        D_801095C0, D_801095D8, D_801095E8 };

    static u_char D_80109668;
    static u_char D_80109669;

    char* sp10[48];
    int spD0[24];
    int i;
    u_char* temp;

    if (arg0 != 0) {
        D_80109669 = arg0 - 1;
        D_80109668 = 0;
        return 0;
    }
    switch (D_80109668) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            temp = D_801095F4[D_80109669];
            for (i = 0; i < D_801095EC[D_80109669]; ++i) {
                sp10[i * 2] =
                    (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp[temp[i] * 2
                                                                      + 0x1B6]];
                sp10[i * 2 + 1] =
                    (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp[temp[i] * 2
                                                                      + 0x1B7]];
                spD0[i] = 0;
            }
            vs_mainMenu_initSortUi(i, D_80109669 + 0x2D, sp10, spD0);
            D_80109668 = 1;
        }
        break;
    case 1:
        vs_mainMenu_processItemActionMenu();
        i = vs_mainMenu_getSelectedItemAction();
        if ((i + 1) != 0) {
            if (i >= 0) {
                vs_battle_playMenuSelectSfx();
                switch (D_80109669) {
                case 0:
                    _sortWeapons(D_80109588[i]);
                    break;
                case 3:
                    func_80103F00(D_801095A8[i]);
                    break;
                case 6:
                    func_8010408C(D_801095E8[i]);
                    break;
                default:
                    _copyEquipmentStats(D_80109669, D_801095F4[D_80109669][i]);
                    break;
                }
            } else {
                vs_battle_playMenuLeaveSfx();
            }
            return i + 1;
        }
        break;
    default:
        break;
    }
    return 0;
}

static int func_80104788(int arg0)
{
#pragma vsstring(start)
    static char _buffReels[] = "|>48|000/000\0";
#pragma vsstring(end)

    static char D_8010961C[] = { 1, 10, 100 };
    static char D_8010961F = 0;

    static char D_8010966A;
    static char D_8010966B;
    static char D_8010966C;
    static char D_8010966D;
    static u_char D_8010966E;
    static char D_8010966F;
    static char D_80109670;
    static char _[3] __attribute__((unused));

    char* sp18[4];
    int sp28[2];
    char* sp30[4];
    int sp40[2];
    int i;
    int temp_v1_4;
    vs_battle_menuItem_t* temp_v0_4;
    int a0;
    int a2;

    if (arg0 != 0) {
        D_8010966D = arg0 >> 0x10;
        D_8010966B = arg0 >> 8;
        D_8010966C = arg0;
        vs_battle_initInformationTextBox(1);
        vs_mainmenu_setInformationMessage(
            (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp[D_8010966D + 0x22A]]);
        D_8010966A = 0;
        return 0;
    }

    switch (D_8010966A) {
    case 0:
        if (vs_battle_textBoxes[7].unk0.done) {
            if (vs_mainmenu_ready() != 0) {
                D_8010966A = ((D_8010966D & 1) + 1);
            }
        }
        break;
    case 1:
        for (i = 0; i < 2; ++i) {
            sp18[i * 2] = (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp[i + 0x228]];
            sp18[i * 2 + 1] =
                (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp[D_8010966D + 0x22A]];
            sp28[i] = 0;
        }

        vs_mainMenu_initSortUi(2, 4, sp18, sp28);
        D_8010966A = 3;
        break;
    case 2:
        D_80109670 = vs_battle_inventory.misc[D_8010966C - 1].count;
        i = vs_battle_toBCD(D_80109670);
        _buffReels[8] = (i & 0xF);
        i = vs_battle_toBCD(i >> 4);
        _buffReels[7] = (i & 0xF);
        _buffReels[6] = (i >> 4);
        for (i = 2; i < 5; ++i) {
            _buffReels[i] = 0;
        }
        temp_v0_4 = vs_battle_setMenuItem(0x22, -0x7E, 0x82, 0x7E, 0, _buffReels);
        temp_v0_4->state = 5;
        temp_v0_4->targetPosition0 = 0;
        D_8010966E = 0;
        D_8010966F = 0U;
        D_8010966A = 4U;
        break;
    case 3:
        vs_mainMenu_processItemActionMenu();
        i = vs_mainMenu_getSelectedItemAction() + 1;
        if (i != 0) {
            if (i == 1) {
                vs_main_playSfxDefault(0x7E, 0x1C);
                vs_mainMenu_initItem(D_8010966B, D_8010966C);
            } else {
                vs_battle_playMenuLeaveSfx();
            }
            return i;
        }
        break;
    case 4:
        if (vs_mainmenu_ready() == 0) {
            break;
        }
        for (i = 2; i < 5; ++i) {
            _buffReels[i] = 0x8F;
        }
        vs_battle_setMenuItem(0x22, 0, 0x82, 0x7E, 0, _buffReels);
        D_8010966A = 5;
        // Fallthrough
    case 5:
        if (vs_main_buttonsPressed.all & 0x70) {
            i = vs_battle_toBCD(D_8010966F);
            _buffReels[4] = (i & 0xF);
            i = vs_battle_toBCD(i >> 4);
            _buffReels[3] = (i & 0xF);
            _buffReels[2] = (i >> 4);
            vs_battle_setMenuItem(0x22, 0, 0x82, 0x7E, 0, _buffReels);
            if (vs_main_buttonsPressed.all & 0x50) {
                vs_battle_playMenuLeaveSfx();
                if (vs_main_buttonsPressed.all & 0x10) {
                    return -2;
                }
                return -1;
            }
            if (D_8010966F == 0) {
                vs_battle_playMenuLeaveSfx();
                return -1;
            }
            vs_battle_playMenuSelectSfx();
            D_8010966A = 6;
            break;
        }
        i = 0;
        a0 = a2 = D_8010966F;
        if (vs_main_buttonRepeat & 0x1000) {
            i = 1;
        }
        if (vs_main_buttonRepeat & 0x4000) {
            --i;
        }
        if (i == 1) {
            a0 = a2 + D_8010961C[D_8010966E];
        } else if (i == -1) {
            a0 = a2 - D_8010961C[D_8010966E];
        }
        if (a0 >= 0) {
            if (D_80109670 >= a0) {
                D_8010966F = a0;
            }
        }
        i = 0;
        a0 = D_8010966E;
        if (vs_main_buttonRepeat & 0x2000) {
            --i;
        }
        if (vs_main_buttonRepeat & 0x8000) {
            ++i;
        }
        if (i == 1) {
            if ((a0 & 0xFF) == 2) {
                if (D_8010966F != D_80109670) {
                    D_8010966F = D_80109670;
                }
            } else {
                ++D_8010966E;
            }
        } else if (i == -1) {
            if (!(a0 & 0xFF)) {
                if (D_8010966F != 0) {
                    D_8010966F = 0;
                }
            } else {
                --D_8010966E;
            }
        }
        if ((a0 != D_8010966E) || (a2 != D_8010966F)) {
            vs_battle_playMenuChangeSfx();
        }
        func_800C7210(5);
        i = vs_battle_toBCD(D_8010966F);
        vs_battle_printVariableWidthFontChar(i & 0xF, 0x42, 0x82, D_1F800000[2] - 12);
        i = vs_battle_toBCD(i >> 4);
        vs_battle_printVariableWidthFontChar(i & 0xF, 0x3C, 0x82, D_1F800000[2] - 12);
        vs_battle_printVariableWidthFontChar(i >> 4, 0x36, 0x82, D_1F800000[2] - 12);
        D_8010961F =
            func_800FFCDC((u_int)D_8010961F, (0x36 - (D_8010966E * 6)) | 0x720000);
        break;
    case 6:
        if (vs_mainmenu_ready() != 0) {
            for (i = 0; i < 2; ++i) {
                sp30[i * 2] =
                    (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp[i + 0x228]];
                sp30[i * 2 + 1] = (char*)&vs_mainMenu_itemHelp[0x2E49];
                sp40[i] = 0;
            }
            vs_mainMenu_initSortUi(2, 4, sp30, sp40);
            D_8010966A = 7;
        }
        break;
    case 7:
        vs_mainMenu_processItemActionMenu();
        i = vs_mainMenu_getSelectedItemAction() + 1;
        if (i != 0) {
            if (i == 1) {
                vs_main_playSfxDefault(0x7E, 0x1C);
                temp_v1_4 = vs_battle_inventory.misc[D_8010966C - 1].count;
                if (temp_v1_4 == D_8010966F) {
                    vs_mainMenu_initItem(D_8010966B, D_8010966C);
                } else {
                    vs_battle_inventory.misc[D_8010966C - 1].count =
                        temp_v1_4 - D_8010966F;
                }
            } else {
                vs_battle_playMenuLeaveSfx();
            }
            return i;
        }
        break;
    }
    return 0;
}

static int func_80104EC0(int arg0, int arg1)
{
    int var_v1;

    var_v1 = 0;
    if (arg0 == 1) {
        var_v1 = vs_battle_inventory.blades[arg1].assembledWeaponIndex;
    }
    if (arg0 == 2) {
        var_v1 = vs_battle_inventory.grips[arg1].assembledWeaponIndex;
    }
    if (arg0 == 5) {
        var_v1 = vs_battle_inventory.gems[arg1].setItemIndex;
        if (var_v1 & 0x80) {
            var_v1 = 0;
        }
    }
    return var_v1;
}

static int func_80104F50(int arg0, int arg1)
{
    u_short var_v1;

    var_v1 = 0;
    if (arg0 == 5) {
        var_v1 = vs_battle_inventory.gems[arg1].setItemIndex;
        if (!(var_v1 & 0x80)) {
            var_v1 = 0;
        }
    }
    return var_v1 & 0x7F;
}

static char D_8010971C[64];

static int func_80104F94(int arg0, char** arg1, int* arg2, char* arg3)
{
    int temp_v0;
    int var_s3;
    int i;
    char* sp10 = vs_mainMenu_inventoryIndices[arg0];
    int sp14 = 0;

    for (i = 0; i < vs_mainMenu_inventoryItemCapacities[arg0];
         sp14++, i++, arg3 += 0x60) {

        int temp_s1_2 = sp10[i];

        if (temp_s1_2 == 0) {
            break;
        }

        temp_s1_2 = sp10[i] - 1;
        var_s3 = 0;

        switch (arg0) {
        case 0:
            vs_mainMenu_initUiWeapon(
                &vs_battle_inventory.weapons[temp_s1_2], &arg1[sp14 * 2], &arg2[i], arg3);
            if (vs_battle_inventory.weapons[temp_s1_2].isEquipped != 0) {
                var_s3 = 0xCA00;
            }
            break;
        case 1:
            vs_mainMenu_setUiBlade(
                &vs_battle_inventory.blades[temp_s1_2], &arg1[sp14 * 2], &arg2[i], arg3);
            break;
        case 2:
            vs_mainMenu_setUiGrip(
                &vs_battle_inventory.grips[temp_s1_2], &arg1[sp14 * 2], &arg2[i], arg3);
            break;
        case 3:
            vs_mainMenu_initUiShield(
                &vs_battle_inventory.shields[temp_s1_2], &arg1[sp14 * 2], &arg2[i], arg3);
            if (vs_battle_inventory.shields[temp_s1_2].isEquipped != 0) {
                var_s3 = 0xCA00;
            }
            break;
        case 4:
            vs_mainMenu_initUiArmor(
                &vs_battle_inventory.armor[temp_s1_2], &arg1[sp14 * 2], &arg2[i], arg3);
            if (vs_battle_inventory.armor[temp_s1_2].bodyPart != 0) {
                var_s3 = 0xCA00;
            }
            break;
        case 5:
            vs_mainMenu_setUiGem(
                &vs_battle_inventory.gems[temp_s1_2], &arg1[sp14 * 2], &arg2[i], arg3);
            break;
        case 6: {
            u_int var_a0;
            vs_mainMenu_setUiItem(
                &vs_battle_inventory.misc[temp_s1_2], &arg1[sp14 * 2], &arg2[i], arg3);

            var_a0 = D_80102214[vs_battle_inventory.misc[temp_s1_2].id - 0x143];

            if ((var_a0 - 0x6A) < 0x1C) {
                int j;
                for (j = 0; j < 3; ++j) {
                    if (vs_main_skills[var_a0].unlocked) {
                        ++var_a0;
                    }
                }
            }
            D_8010971C[sp14] = var_a0;
            break;
        }
        }

        temp_v0 = func_80104EC0(arg0, temp_s1_2);
        if (temp_v0 != 0) {
            var_s3 = 0xCA00;
            if (vs_battle_inventory.weapons[temp_v0 - 1].isEquipped == 0) {
                var_s3 = 0xCC00;
            }
        }
        temp_v0 = func_80104F50(arg0, temp_s1_2);
        if (temp_v0 != 0) {
            var_s3 = 0xCA00;
            if (vs_battle_inventory.shields[temp_v0 - 1].isEquipped == 0) {
                var_s3 = 0xCC00;
            }
        }
        arg2[i] |= var_s3;
    }
    return sp14;
}

static void func_80105314(int arg0)
{
    int i;
    vs_battle_menuItem_t* temp_v0;

    while (D_801023D0 < 16) {
        func_80100A5C();
    }

    for (i = 20; i < 40; ++i) {
        temp_v0 = vs_battle_getMenuItem(i);
        if (temp_v0->state == 2) {
            temp_v0->state = 1;
            temp_v0->initialX = temp_v0->targetPosition0;
        }
        temp_v0->selected =
            (i ^ (D_800F4EE8.cursorMemories[(arg0 + 0x1E) * 2] + 0x14)) == 0;
    }
}

static int func_801053EC(int arg0)
{
    static char D_80109674[8];
    static char state;
    static char D_8010967D;
    static char D_8010967E;
    static char _ __attribute__((unused));
    static int D_80109680;

    char* sp10[12];
    int var_v0_3;
    int temp_v0_7;
    void* temp_v0_8;
    int* var_v1_4;
    int temp_v1_5;
    int temp_a0_2;
    int var_a1_2;
    int var_s0_2;
    char** temp_s0_2;
    int var_s1;
    int var_s1_2;
    int* temp_s1;
    int* temp_s1_2;
    int var_s2;
    char* temp_s2;
    char** temp_s2_2;
    int temp_s3_5;
    int i;
    u_char var_s4;
    void* temp_s5;
    vs_battle_menuItem_t* temp_v0;
    vs_battle_menuItem_t* temp_v0_14;
    vs_battle_menuItem_t* temp_v0_9;

loop_1:
    if (arg0 != 0) {
        temp_v0 = vs_battle_getMenuItem(3);
        if (temp_v0->initialX >= 0xB5) {
            if (temp_v0->initialX >= 0xCD) {
                temp_v0->initialX -= 0x18;
            }
            temp_v0->state = 2;
            temp_v0->targetPosition0 = 0xB4;
        }
        func_8010296C(1);
        D_80109714 = 0;
        D_8010967E = arg0 & 1;
        if (D_8010967E != 0) {
            if (vs_main_settings.cursorMemory == 0) {
                memset(&D_800F4EE8.unk3A, 0, 0x12);
            }
        }
        state = 1;
        return 0;
    }

    var_s4 = (D_800F4EE8.unk3A.itemCategory - 1) & 7;
    temp_s2 = vs_mainMenu_inventoryIndices[var_s4];

    switch (state) { /* switch 1 */
    case 0:
    case 1:
        temp_s5 = vs_main_allocHeapR(0x1B00);
        temp_s1 = temp_s5 + 0x1800;
        temp_s2_2 = temp_s5 + 0x1900;
        D_801023E3 = 1;
        for (i = 0; i < 7; ++i) {
            vs_mainMenu_rebuildInventory(i);
        }

        if (var_s4 == 7) {
            for (i = 0; i < 4; ++i) {
                temp_s2_2[i] = (char*)&_menuText[_menuText[VS_menuText_INDEX_equip + i]];
                temp_s1[i] = vs_main_stateFlags.introState < 3;
            }

            if (vs_battle_characterState->unk3C->unk948 & 0x80000) {
                for (i = 0; i < 2; ++i) {
                    temp_s2_2[i * 2 + 1] =
                        (char*)&_menuText[VS_menuText_OFFSET_equipmentTarnished];
                    temp_s1[i] = 1;
                }
            }
            var_s0_2 = 2;
        } else {
            var_s0_2 = func_80104F94(var_s4, temp_s2_2, temp_s1, temp_s5);
        }

        if (D_800F4EA0 & 7) {
            var_v1_4 = temp_s1;
            for (i = 0; i < 64; ++i) {
                temp_s1[i] |= 1;
            }
        }

        D_8010967D = var_s0_2 == 0;
        if (D_8010967D != 0) {
            vs_mainmenu_setInformationMessage(
                (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_noItemsInCategory]);
        } else {
            i = vs_main_settings.cursorMemory;
            if (D_8010967E != 0) {
                D_8010967E = 0;
            } else {
                vs_main_settings.cursorMemory = 1;
            }
            var_a1_2 = var_s4 + 0x1E;
            if (var_s4 == 7) {
                var_a1_2 |= 0x200;
            } else {
                var_a1_2 |= 0x19200;
            }
            vs_mainmenu_setMenuRows(var_s0_2, var_a1_2, temp_s2_2, temp_s1);
            if (state == 0) {
                func_80105314(var_s4);
            }
            vs_main_settings.cursorMemory = i;
        }
        vs_main_freeHeapR(temp_s5);
        state = 2;
        break;
    case 2:
        D_80109713 = 1;
        if (D_8010967D != 0) {
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
                u_int var_s0_2 = var_s4;
                var_s0_2 = var_s0_2 < 6;
                D_80109713 = var_s0_2 + 1;
            }

            D_80109680 = vs_mainmenu_getSelectedRow() + 1;

            if (D_80109680 == 0) {
                if (vs_main_buttonsPressed.all & 0x80) {
                    if ((D_80109713 >= 2) && (vs_mainmenu_ready() != 0)) {
                        vs_battle_playMenuSelectSfx();
                        var_s1 = func_80100814();
                        vs_battle_getMenuItem(var_s1 >> 8)->itemState = 0;
                        _itemStatusView(var_s4 | ((var_s1 + 1) * 0x10));
                        D_80109711 = 0;
                        state = 7;
                        break;
                    }
                    vs_battle_playInvalidSfx();
                }
            } else {
                if ((D_80109680 <= 0) || (var_s4 == 7)) {
                    return D_80109680;
                }

                temp_v0_8 = vs_main_allocHeapR(0x1B00);
                temp_s0_2 = temp_v0_8 + 0x1900;
                temp_s1_2 = temp_v0_8 + 0x1800;
                temp_a0_2 = func_80104F94(var_s4, temp_s0_2, temp_s1_2, temp_v0_8);
                temp_s1_2[D_80109680 - 1] |= 8;
                i = vs_main_settings.cursorMemory;
                vs_main_settings.cursorMemory = 1;
                vs_mainmenu_setMenuRows(
                    temp_a0_2, (var_s4 + 0x1E) | 0x19200, temp_s0_2, temp_s1_2);
                vs_main_settings.cursorMemory = i;
                func_80105314(var_s4);
                D_80109713 = 1;
                D_801023E3 = 0;
                vs_main_freeHeapR(temp_v0_8);
                state = 6;
                break;
            }
        }
    case 3:
        i = vs_main_buttonsState & (PADL1 | PADLleft);
        var_s0_2 = vs_main_buttonsState & (PADR1 | PADLright);
        temp_v0_7 = i != 0;

        if (var_s0_2 != 0) {
            var_s1 = temp_v0_7 ^ 1;
        } else {
            var_s1 = temp_v0_7 & 1;
        }
        if (var_s1 != 0) {
            var_a1_2 = (PADL1 | PADLleft);
            if (i == (PADL1 | PADLleft)) {
                var_a1_2 = PADLleft;
            }
            if (vs_main_buttonRepeat & var_a1_2) {
                var_s4 = (var_s4 - 1) & 7;
            }

            var_a1_2 = 0x2008;
            if (var_s0_2 == 0x2008) {
                var_a1_2 = 0x2000;
            }

            var_v0_3 = vs_main_buttonRepeat & var_a1_2;

            if (var_v0_3 != 0) {
                var_s4 = (var_s4 + 1) & 7;
            }
            if (var_s4 != ((D_800F4EE8.unk3A.itemCategory - 1) & 7)) {
                vs_battle_playMenuChangeSfx();
                D_800F4EE8.unk3A.itemCategory = (var_s4 + 1) & 7;
                if (state == 2) {
                    if (D_8010967D == 0) {
                        func_80100814();
                        vs_mainMenu_clearMenuExcept(3);
                    }
                    state = 3;
                }
            }
        }

        if (state == 3) {
            if (vs_mainmenu_ready() != 0) {
                if ((vs_main_buttonsState & 0xA00C) && (var_s1 != 0)) {
                    break;
                }
                state = 1;
                arg0 = 0;
                goto loop_1;
            }
        }
        break;
    case 4:
        temp_v0_9 = vs_battle_getMenuItem(3);
        if (temp_v0_9->initialX >= 0xB5) {
            if (temp_v0_9->initialX >= 0xCD) {
                temp_v0_9->initialX -= 0x18;
            }
            temp_v0_9->state = 2;
            temp_v0_9->targetPosition0 = 0xB4;
        }
        state = 5;
        /* fallthrough */
    case 5:
        if (vs_mainmenu_ready() != 0) {
            state = 1;
            break;
        }
        break;
    case 6:
        if (vs_main_buttonsPressed.all & 0x80) {
            vs_battle_playInvalidSfx();
        }

        i = vs_mainmenu_getSelectedRow() + 1;

        if (i != 0) {
            var_s0_2 = D_80109680;
            if (var_s0_2 == i) {
                state = 8;
                break;
            }
            if (i > 0) {
                var_s1 = temp_s2[i - 1];
                var_a1_2 = temp_s2[var_s0_2 - 1];
                if ((var_s4 == 6)
                    && ((vs_battle_inventory.misc[var_s1 - 1].id
                         == vs_battle_inventory.misc[var_a1_2 - 1].id))) {
                    vs_battle_inventory.misc[var_a1_2 - 1].count =
                        vs_battle_inventory.misc[var_a1_2 - 1].count
                        + vs_battle_inventory.misc[var_s1 - 1].count;
                    if (vs_battle_inventory.misc[var_a1_2 - 1].count > 100) {
                        vs_battle_inventory.misc[var_s1 - 1].count =
                            vs_battle_inventory.misc[var_a1_2 - 1].count - 100;
                        vs_battle_inventory.misc[var_a1_2 - 1].count = 100;
                    } else {
                        vs_mainMenu_initItem(6, var_s1);
                    }
                } else {
                    temp_s2[i - 1] = var_a1_2;
                    temp_s2[var_s0_2 - 1] = var_s1;
                }
                vs_mainMenu_clearMenuExcept(3);
                state = 4;
                break;
            }
            if (i != -1) {
                return -2;
            }
            state = 0;
        }
        break;
    case 7:
        i = _itemStatusView(0);
        if (i == 0) {
            break;
        }

        if (i == -2) {
            return -2;
        }

        D_80109711 = 1;
        temp_v0_14 = vs_battle_getMenuItem(3);
        if (temp_v0_14->initialX >= 0xB5) {
            if (temp_v0_14->initialX >= 0xCD) {
                temp_v0_14->initialX -= 0x18;
            }
            temp_v0_14->state = 2;
            temp_v0_14->targetPosition0 = 0xB4;
        }
        state = 1;
        break;
    case 8:
        var_s0_2 = 0;
        temp_s3_5 = temp_s2[D_80109680 - 1] - 1;
        vs_battle_rMemzero(vs_battle_rowTypeBuf, 0x18);
        if (var_s4 == 6) {
            sp10[0] = (char*)&vs_mainMenu_itemHelp[0x351D];
            sp10[1] = (char*)&vs_mainMenu_itemHelp[0x3520];
            if (vs_battle_inventory.misc[temp_s3_5].id >= 0x1CA) {
                *vs_battle_rowTypeBuf = 1;
                sp10[1] = (char*)&vs_mainMenu_itemHelp[0x35D1];
            } else if (vs_battle_getSkillFlags(0, (int)D_8010971C[D_80109680 - 1]) & 2) {
                *vs_battle_rowTypeBuf = 1;
                sp10[1] = (char*)&_menuText[VS_menuText_OFFSET_insufficientMp];
            }
            ++var_s0_2;
            D_80109674[var_s0_2] = 1;
        }

        if (((char)(var_s4 - 1) < 2U) || (var_s4 == 5)) {
            var_s2 = var_s4 & 0xFF;
            sp10[var_s0_2 * 2] = (char*)&vs_mainMenu_itemHelp[0x3527];
            sp10[var_s0_2 * 2 + 1] = (char*)&vs_mainMenu_itemHelp[0x352C];
            if ((func_80104EC0(var_s2, temp_s3_5) == 0)
                && (func_80104F50(var_s2, temp_s3_5) == 0)) {
                sp10[var_s0_2 * 2 + 1] = (char*)&vs_mainMenu_itemHelp[0x35B2];
                vs_battle_rowTypeBuf[var_s0_2] = 1;
            }
            ++var_s0_2;
            D_80109674[var_s0_2] = 2;
        }

        var_s1_2 = 0;
        sp10[var_s0_2 * 2] = (char*)&vs_mainMenu_itemHelp[0x354A];
        sp10[var_s0_2 * 2 + 1] = (char*)&vs_mainMenu_itemHelp[0x354F];

        temp_v1_5 = var_s4 & 0xFF;

        switch (temp_v1_5) { /* switch 2; irregular */
        case 0: /* switch 2 */
            var_s1_2 = (char)vs_battle_inventory.weapons[temp_s3_5].isEquipped != 0;
            break;
        case 3: /* switch 2 */
            var_s1_2 = (char)vs_battle_inventory.shields[temp_s3_5].isEquipped != 0;
            break;
        case 4: /* switch 2 */
            var_s1_2 = vs_battle_inventory.armor[temp_s3_5].bodyPart != 0;
            break;
        case 6: /* switch 2 */
            if (vs_battle_inventory.misc[temp_s3_5].id >= 0x1CAU) {
                var_s1_2 = 3;
            }
            break;
        }
        var_a1_2 = func_80104EC0(var_s4, temp_s3_5);
        if (var_a1_2 != 0) {
            var_s1_2 = 1;
            if (vs_battle_inventory.weapons[var_a1_2 - 1].isEquipped == 0) {
                var_s1_2 = 2;
            }
        }
        var_a1_2 = func_80104F50(var_s4, temp_s3_5);
        if (var_a1_2 != 0) {
            var_s1_2 = 1;
            if (vs_battle_inventory.shields[var_a1_2 - 1].isEquipped == 0) {
                var_s1_2 = 2;
            }
        }

        if (var_s1_2 != 0) {
            sp10[var_s0_2 * 2 + 1] =
                (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp[var_s1_2 + 0x297]];
            var_s1_2 = 1;
        }

        vs_battle_rowTypeBuf[var_s0_2] = var_s1_2;
        ++var_s0_2;
        D_80109674[var_s0_2] = 3;
        if (var_s4 == 6) {
            sp10[var_s0_2 * 2] = (char*)&vs_mainMenu_itemHelp[0x356D];
            sp10[var_s0_2 * 2 + 1] = (char*)&vs_mainMenu_itemHelp[0x3574];
            if (vs_battle_inventory.misc[temp_s3_5].id >= 0x1CAU) {
                sp10[var_s0_2 * 2 + 1] = (char*)&vs_mainMenu_itemHelp[0x350E];
                vs_battle_rowTypeBuf[var_s0_2] = 1;
            }
            ++var_s0_2;
            D_80109674[var_s0_2] = 4;
        }

        sp10[var_s0_2 * 2] = (char*)&vs_mainMenu_itemHelp[0x3586];
        sp10[var_s0_2 * 2 + 1] = (char*)&vs_mainMenu_itemHelp[0x358A];

        ++var_s0_2;

        D_80109674[var_s0_2] = 5;
        vs_mainMenu_initSortUi(
            var_s0_2, var_s4 + 0x26, (char**)sp10, vs_battle_rowTypeBuf);
        state = 9;
        break;
    case 9:
        vs_mainMenu_printInformation(func_800FF348(), (int)(char)D_801022C4);
        vs_mainMenu_processItemActionMenu();
        temp_s3_5 = vs_mainMenu_getSelectedItemAction() + 1;
        if (temp_s3_5 != 0) {
            func_800FA854(0x28);
            if (temp_s3_5 > 0) {
                vs_battle_playMenuSelectSfx();
                switch (D_80109674[temp_s3_5]) {
                case 1:
                    vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
                    D_800F5210 = temp_s2[D_80109680 - 1] - 1;
                    D_800F4E98.executeAbility.s16[0] = (short)D_8010971C[D_80109680 - 1];
                    D_800F4E98.executeAbility.s16[1] =
                        (short)vs_battle_inventory.misc[D_800F5210].id;
                    return 3;
                case 2:
                    vs_mainMenu_initTextBox();
                    vs_mainMenu_clearMenuExcept(3);
                    state = 10;
                    break;
                case 3:
                    var_s0_2 = temp_s2[D_80109680 - 1] | (var_s4 << 8);
                    if ((var_s4 == 6)
                        && ((char)vs_battle_inventory.misc[temp_s2[D_80109680 - 1] - 1]
                                .count
                            >= 2U)) {
                        var_s0_2 |= 0x10000;
                    }
                    func_80104788(var_s0_2);
                    state = 11;
                    break;
                case 4:
                    func_80104788(temp_s2[D_80109680 - 1] | (var_s4 << 8) | 0x20000);
                    state = 11;
                    break;
                case 5:
                    vs_mainMenu_initTextBox();
                    func_80104530(var_s4 + 1);
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
        i = func_80104EC0(var_s4, temp_s2[D_80109680 - 1] - 1);
        if (i == 0) {
            i = func_80104F50(var_s4, temp_s2[D_80109680 - 1] - 1);
            var_s4 = 3;
        } else {
            var_s4 = 0;
        }
        D_800F4EE8.unk3A.itemCategory = (var_s4 + 1) & 7;
        (&D_800F4EE8.unk3A)->unk2[var_s4] = vs_mainMenu_findItem(var_s4, i - 1) - 1;
        state = 1;
        break;
    case 11:
        i = func_80104788(0);
        if (i != 0) {
            vs_mainMenu_initTextBox();
            func_800FA854(0x28);
            vs_mainMenu_clearMenuExcept(3);
            if (i == -2) {
                return -2;
            }
            state = 5;
        }
        break;
    case 12:
        i = func_80104530(0);
        if (i != 0) {
            func_800FA854(0x28);
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
static int D_80109760;
static u_char D_80109764;
static char _menuRowCount;
static char D_80109766;
static char D_80109767;

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
    D_80109766 = 0;
    D_80109760 = 0;
    D_80109764 = 1;

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
    menuItem->unk7 = j & 1;
    menuItem->icon = j >> 0x1A;
    menuItem->material = (j >> 0x10) & 7;
    menuItem->selected = 1;
    D_80109767 = (j >> 19) & 0x7F;
}

static int func_80106574(void) { return _itemsText != NULL ? -1 : D_80109760; }

static void func_8010659C(int arg0)
{
    static char D_80109620 = 0;

    int temp_s0;
    int temp_s4;
    int i;
    int temp_s6;
    vs_battle_menuItem_t* temp_v0;

    if (D_80109764 < 6) {
        if (D_80109764 == _menuRowCount) {
            D_80109764 = 0x10;
        } else {
            temp_v0 = vs_battle_setMenuItem(D_80109764 + 0x14, 0x140,
                (D_80109764 * 0x10) + 0x12, 0x97, 0, _itemsText + (D_80109764 << 7));
            temp_v0->state = 2;
            temp_v0->targetPosition0 = 0xA9;
            temp_s0 = ((_itemsText_t*)_itemsText)[D_80109764].menuRowFlags;
            temp_v0->unk7 = temp_s0 & 1;
            temp_v0->icon = (temp_s0 >> 0x1A);
            if (((temp_s0 >> 9) & 0x7F) != 0) {
                temp_v0->itemState = ((temp_s0 >> 9) & 0x7F) - 0x64;
            }
            temp_v0->material = (temp_s0 >> 0x10) & 7;
            ++D_80109764;
            if (D_80109764 == 6) {
                if (_menuRowCount >= 7) {
                    temp_v0->fadeEffect = 2;
                }
                D_80109764 = 0x10;
            }
        }
    } else {
        temp_s6 = D_80109766;
        temp_s4 = D_80109760 + temp_s6;
        temp_v0 = vs_battle_getMenuItem(D_80109760 + 0x14);
        vs_mainmenu_setInformationMessage(_itemsText + ((temp_s4 << 7) + 0x20));

        switch (D_80109764) {
        case 16:
            if (vs_mainmenu_ready() != 0) {
                D_80109764 = 0x11;
                return;
            }
            return;
        case 17:
            if (vs_main_buttonsPressed.all & 0x10) {
                if (!(arg0 & 2)) {
                    vs_battle_playMenuLeaveSfx();
                }
                vs_main_freeHeapR(_itemsText);
                _itemsText = NULL;
                D_80109760 = -3;
                return;
            }
            if (vs_main_buttonsPressed.all & 0x20) {
                if (temp_v0->unk7 != 0) {
                    vs_battle_playInvalidSfx();
                } else {
                    vs_main_freeHeapR(_itemsText);
                    _itemsText = NULL;
                    D_80109760 = temp_s4;
                    if (arg0 != 0) {
                        if (temp_s4 == 0) {
                            vs_main_playSfxDefault(0x7E, 0x22);
                        } else {
                            vs_main_playSfxDefault(0x7E, 0x21);
                        }
                    }
                    return;
                }
            }
            temp_v0->selected = 0;
            if (vs_main_buttonsPressed.all & 0x40) {
                vs_battle_playMenuLeaveSfx();
                vs_main_freeHeapR(_itemsText);
                _itemsText = NULL;
                D_80109760 = -2;
                return;
            }
            if (vs_main_buttonRepeat & 0x1000) {
                if (_menuRowCount < 7 || D_80109766 == 0) {
                    if (D_80109760 != 0) {
                        --D_80109760;
                    }
                } else if (D_80109760 == 2) {
                    --D_80109766;
                } else {
                    --D_80109760;
                }
            }
            if (vs_main_buttonRepeat & 0x4000) {
                if (_menuRowCount < 7) {
                    if (D_80109760 < (_menuRowCount - 1)) {
                        ++D_80109760;
                    }
                } else if (D_80109766 == (_menuRowCount - 6)) {
                    if (D_80109760 < 5) {
                        ++D_80109760;
                    }
                } else if (D_80109760 == 4) {
                    ++D_80109766;
                } else {
                    ++D_80109760;
                }
            }
            if (temp_s4 != (D_80109760 + D_80109766)) {
                vs_battle_playMenuChangeSfx();

                if (D_80109766 != temp_s6) {
                    char buf[_menuRowCount];
                    for (i = 0; i < _menuRowCount; ++i) {
                        buf[i] = 0;
                    }
                    temp_s0 = _menuRowCount;

                    if (_menuRowCount >= 7) {
                        temp_s0 = 6;
                    }
                    for (i = 1; i < temp_s0; ++i) {
                        buf[i + temp_s6] =
                            vs_battle_getMenuItem(i + 0x14)->animationState;
                    }

                    for (i = 1;;) {
                        temp_v0 = vs_battle_setMenuItem(i + 0x14, 0xA9, 0x12 + i * 0x10,
                            0x97, 0, _itemsText + ((i + D_80109766) << 7));
                        temp_v0->animationState = buf[i + D_80109766];
                        temp_s0 =
                            ((_itemsText_t*)_itemsText)[i + D_80109766].menuRowFlags;
                        temp_v0->unk7 = temp_s0 & 1;
                        temp_v0->icon = temp_s0 >> 0x1A;

                        if (((temp_s0 >> 9) & 0x7F) != 0) {
                            temp_v0->itemState = ((temp_s0 >> 9) & 0x7F) - 0x64;
                        }

                        temp_v0->material = (temp_s0 >> 0x10) & 7;
                        i++;

                        if (i == _menuRowCount) {
                            break;
                        }
                        if (i == 6) {
                            if ((D_80109766 + 6) < _menuRowCount) {
                                temp_v0->fadeEffect = 2;
                            }
                            break;
                        }
                    }

                    if (D_80109766 != 0) {
                        vs_battle_getMenuItem(0x15)->fadeEffect = 1;
                    }
                }
                temp_s0 =
                    ((_itemsText_t*)_itemsText)[D_80109760 + D_80109766].menuRowFlags;
                D_80109767 = (temp_s0 >> 0x13) & 0x7F;
            }
            vs_battle_getMenuItem(D_80109760 + 0x14)->selected = 1;
            i = (((D_80109760 * 0x10) + 0xA) << 0x10) | 0x9B;
            if (D_80109760 == 0) {
                i -= 0xE;
            }
            D_80109620 = func_800FFCDC(D_80109620, i);
            break;
        }
    }
}

static void func_80106BB4(int arg0)
{
    vs_battle_uiAccessory accessory;
    int i;

    vs_mainMenu_resetStats();

    if (arg0 != 0) {
        vs_battle_applyAccessory(&accessory, &vs_mainMenu_armor[arg0 - 1]);

        for (i = 0; i < 16; ++i) {
            vs_mainMenu_equipmentStats[i] = accessory.classes[i & 7];
            vs_mainMenu_equipmentStats[i + 16] = accessory.affinities[i & 7];
            vs_mainMenu_equipmentStats[i + 32] = accessory.types[i & 7];
        }
        vs_mainMenu_setStrIntAgi(
            accessory.currentStr, accessory.currentInt, accessory.currentAgility, 2);
    }
    vs_mainMenu_equipmentSubtype = 0x20;
    D_801024A1 = arg0;
    func_800FBB8C(7);
}

static int func_80106C94(int arg0)
{
    static int D_80109684;
    static char D_80109688;
    static char D_80109689;
    static char _[2] __attribute__((unused));

    int var_a0_2;
    int i;
    int var_s6;
    int temp_s0_2;
    int var_a0;
    vs_battle_inventoryArmor* armor;
    int temp_s7;

    if (arg0 != 0) {
        for (i = 0; i < 16; ++i) {
            var_a0 = vs_main_inventoryIndices.armor[i];
            if ((var_a0 != 0) && (vs_battle_inventory.armor[var_a0 - 1].bodyPart == 7)) {
                break;
            }
        }
        if (i == 16) {
            var_a0 = 0;
        }
        D_80109689 = var_a0;
        func_80106BB4(var_a0);
        vs_mainMenu_drawClassAffinityType(7);
        vs_mainMenu_renderEquipStats(1);
        D_80109688 = 0;
        return 0;
    }

    temp_s0_2 = D_80109688;

    switch (temp_s0_2) {
    case 0:
        if (vs_mainmenu_ready() == 0) {
            break;
        }
        temp_s7 = vs_mainMenu_getItemCount(4, NULL);
        var_a0_2 = 0;
        for (i = 0; i < 16; ++i) {
            if (vs_battle_inventory.armor[i].bodyPart == 7) {
                var_a0_2 = 1;
            }
        }
        {
            int count = temp_s7 + 1;
            char textBuf[count * 96];
            u_short* menuText[count * 2];
            int rowTypes[count];

            if (var_a0_2 == 0) {
                for (i = 0; i < 2; ++i) {
                    menuText[i] = &_menuText[_menuText[VS_menuText_INDEX_none + i]];
                }
                rowTypes[0] = 1;
            } else {
                for (i = 0; i < temp_s7; ++i) {
                    var_a0 = vs_main_inventoryIndices.armor[i];
                    if ((var_a0 != 0)
                        && (vs_battle_inventory.armor[var_a0 - 1].bodyPart == 7)) {
                        vs_mainMenu_initUiArmor(&vs_battle_inventory.armor[var_a0 - 1],
                            (char**)menuText, rowTypes, textBuf);
                        rowTypes[0] |= var_a0 << 0x13;
                    }
                }
            }

            var_s6 = 1;

            for (i = 0; i < temp_s7; ++i) {
                var_a0 = vs_main_inventoryIndices.armor[i];
                if ((var_a0 != 0) && (vs_battle_inventory.armor[var_a0 - 1].category == 7)
                    && (vs_battle_inventory.armor[var_a0 - 1].bodyPart == 0)) {
                    vs_mainMenu_initUiArmor(&vs_battle_inventory.armor[var_a0 - 1],
                        (char**)&menuText[var_s6 * 2], &rowTypes[var_s6],
                        textBuf + var_s6 * 96);
                    rowTypes[var_s6] |= var_a0 << 0x13;
                    ++var_s6;
                }
            }
            _populateMenuRows(var_s6, menuText, rowTypes);
            D_80109688 = 1;
        }
        break;
    case 1:
        func_80106BB4(D_80109767);
        func_8010659C(1);
        D_80109684 = func_80106574() + 1;
        if (D_80109684 != 0) {
            vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
            vs_mainMenu_menuItemFlyoutLeft(-1);
            vs_mainMenu_drawClassAffinityType(-1);
            vs_mainMenu_renderEquipStats(2);
            if (D_80109684 < 0) {
                D_80109688 = 3;
            } else {
                if (D_80109689 != 0) {
                    vs_battle_inventory.armor[D_80109689 - 1].bodyPart = 0;
                }
                if (D_80109684 != temp_s0_2) {
                    armor = &vs_battle_inventory.armor[D_80109767 - 1];
                    armor->bodyPart = 7;
                    vs_battle_equipAccessory(armor);
                } else {
                    vs_battle_equipAccessory(NULL);
                }
                D_80109688 = 2;
            }
        }
        break;
    case 2:
        D_80109688 = 3;
        /* fallthrough */
    case 3:
        if (vs_mainmenu_ready() != 0) {
            return D_80109684;
        }
        break;
    }
    return 0;
}

int func_801090C4(int, int, int);

static int func_80107148(int arg0)
{
    static int D_8010968C;
    static char D_80109690;
    static char D_80109691;
    static char D_80109692;
    static char D_80109693;

    int var_a0;
    int i;
    int var_s5;
    int var_s0;
    int var_s0_2;
    vs_battle_inventoryBlade* blade;
    vs_battle_inventoryWeapon* weapon;

    if (arg0 != 0) {
        for (i = 0; i < 8; ++i) {
            var_s0 = vs_main_inventoryIndices.weapons[i];
            if ((var_s0 != 0)
                && (vs_battle_inventory.weapons[var_s0 - 1].isEquipped != 0)) {
                break;
            }
        }

        if (i == 8) {
            var_s0 = 0;
        }

        vs_mainMenu_setUiWeaponStats(var_s0);
        vs_mainMenu_drawClassAffinityType(7);
        vs_mainMenu_drawDpPpbars(3);
        vs_mainMenu_renderEquipStats(1);
        D_80109690 = 0;
        return 0;
    }

    var_s0 = D_80109690;

    switch (var_s0) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            int temp_s7 = vs_mainMenu_getItemCount(0, NULL);
            var_a0 = 0;

            for (i = 0; i < 8; ++i) {
                if (vs_battle_inventory.weapons[i].isEquipped != 0) {
                    var_a0 = 1;
                }
            }
            {
                char textBuf[(temp_s7 + 1) * 96];
                u_short* menuText[(temp_s7 + 1) * 2];
                int rowTypes[(temp_s7 + 1)];

                if (var_a0 == 0) {
                    for (i = 0; i < 2; ++i) {
                        menuText[i] = &_menuText[_menuText[VS_menuText_INDEX_none + i]];
                    }
                    rowTypes[0] = 1;
                } else {
                    for (i = 0; i < temp_s7; ++i) {
                        var_s0_2 = vs_main_inventoryIndices.weapons[i];
                        if ((var_s0_2 != 0)
                            && (vs_battle_inventory.weapons[var_s0_2 - 1].isEquipped
                                != 0)) {
                            vs_mainMenu_initUiWeapon(
                                &vs_battle_inventory.weapons[var_s0_2 - 1],
                                (char**)menuText, rowTypes, textBuf);
                            rowTypes[0] |= var_s0_2 << 0x13;
                        }
                    }
                }

                var_s5 = 1;

                for (i = 0; i < temp_s7; ++i) {
                    var_s0_2 = vs_main_inventoryIndices.weapons[i];
                    if (var_s0_2 != 0) {
                        vs_battle_inventoryWeapon* weapon =
                            &vs_battle_inventory.weapons[var_s0_2 - 1];
                        if (weapon->isEquipped == 0) {
                            vs_mainMenu_initUiWeapon(weapon,
                                (char**)&menuText[var_s5 * 2], &rowTypes[var_s5],
                                textBuf + var_s5 * 0x60);
                            rowTypes[var_s5] |= var_s0_2 << 0x13;
                            ++var_s5;
                        }
                    }
                }
                _populateMenuRows(var_s5, menuText, rowTypes);
                D_80109690 = 1;
            }
        }
        break;
    case 1:
        vs_mainMenu_setUiWeaponStats(D_80109767);
        func_8010659C(0);
        D_8010968C = func_80106574() + 1;
        if (D_8010968C != 0) {
            vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
            vs_mainMenu_menuItemFlyoutLeft(-1);
            vs_mainMenu_drawClassAffinityType(-1);
            vs_mainMenu_drawDpPpbars(4);
            vs_mainMenu_renderEquipStats(2);
            if (D_8010968C < 0) {
                D_80109690 = 3;
            } else {
                vs_mainMenu_unequipAllWeapons();
                if (D_8010968C == var_s0) {
                    D_80109691 = 10;
                    D_80109692 = 0;
                    D_80109693 = 0;
                } else {
                    weapon = &vs_battle_inventory.weapons[D_80109767 - 1];
                    weapon->isEquipped = var_s0;
                    blade = &vs_battle_inventory.blades[weapon->blade - 1];
                    D_80109691 = blade->category;
                    D_80109692 = blade->wepId;
                    D_80109693 = blade->material;
                    if (vs_mainMenu_weaponHands[D_80109691 - 1] != 0) {
                        vs_mainMenu_unequipShield();
                    }
                    vs_battle_equipWeapon(weapon);
                }
                D_80109690 = 2;
            }
        }
        break;
    case 2:
        if (func_801090C4(D_80109691, D_80109692, D_80109693) != 0) {
            break;
        }
        D_80109690 = 3;
        // Fallthrough
    case 3:
        if (vs_mainmenu_ready() != 0) {
            return D_8010968C;
        }
        break;
    }
    return 0;
}

static int func_80107620(int arg0)
{
    static int D_80109694;
    static char D_80109698;
    static char D_80109699;
    static char D_8010969A;
    static char _ __attribute__((unused));

    int temp_s7;
    int var_a0;
    int i;
    int var_s6;
    int var_s0;
    int var_s0_2;
    vs_battle_actor2* temp_a1;
    vs_battle_inventoryShield* temp_s1;

    if (arg0 != 0) {
        for (i = 0; i < 8; ++i) {
            var_s0 = vs_main_inventoryIndices.shields[i];
            if ((var_s0 != 0)
                && (vs_battle_inventory.shields[var_s0 - 1].isEquipped != 0)) {
                break;
            }
        }
        if (i == 8) {
            var_s0 = 0;
        }
        vs_mainMenu_setShieldStats(var_s0);
        vs_mainMenu_drawClassAffinityType(7);
        vs_mainMenu_drawDpPpbars(3);
        vs_mainMenu_renderEquipStats(1);
        D_80109698 = 0;
        return 0;
    }

    var_s0 = D_80109698;

    switch (var_s0) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            temp_s7 = vs_mainMenu_getItemCount(3, NULL);
            var_a0 = 0;

            for (i = 0; i < 8; ++i) {
                if (vs_battle_inventory.shields[i].isEquipped != 0) {
                    var_a0 = 1;
                }
            }
            {
                char textBuf[(temp_s7 + 1) * 96];
                u_short* menuText[(temp_s7 + 1) * 2];
                int rowTypes[(temp_s7 + 1)];

                if (var_a0 == 0) {
                    for (i = 0; i < 2; ++i) {
                        menuText[i] = &_menuText[_menuText[VS_menuText_INDEX_none + i]];
                    }
                    rowTypes[0] = 1;
                } else {
                    for (i = 0; i < temp_s7; ++i) {
                        var_s0_2 = vs_main_inventoryIndices.shields[i];
                        if ((var_s0_2 != 0)
                            && (vs_battle_inventory.shields[var_s0_2 - 1].isEquipped
                                != 0)) {
                            vs_mainMenu_initUiShield(
                                &vs_battle_inventory.shields[var_s0_2 - 1],
                                (char**)menuText, rowTypes, textBuf);
                            rowTypes[0] |= var_s0_2 << 0x13;
                        }
                    }
                }

                var_s6 = 1;

                for (i = 0; i < temp_s7; ++i) {
                    var_s0_2 = vs_main_inventoryIndices.shields[i];
                    if (var_s0_2 != 0) {
                        if (vs_battle_inventory.shields[var_s0_2 - 1].isEquipped == 0) {
                            vs_mainMenu_initUiShield(
                                &vs_battle_inventory.shields[var_s0_2 - 1],
                                (char**)&menuText[var_s6 * 2], &rowTypes[var_s6],
                                textBuf + var_s6 * 0x60);
                            rowTypes[var_s6] |= var_s0_2 << 0x13;
                            ++var_s6;
                        }
                    }
                }
                _populateMenuRows(var_s6, menuText, rowTypes);
                D_80109698 = 1;
            }
        }
        break;
    case 1:
        vs_mainMenu_setShieldStats(D_80109767);
        func_8010659C(0);
        D_80109694 = func_80106574() + 1;
        if (D_80109694 != 0) {
            vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
            vs_mainMenu_menuItemFlyoutLeft(-1);
            vs_mainMenu_drawClassAffinityType(-1);
            vs_mainMenu_drawDpPpbars(4);
            vs_mainMenu_renderEquipStats(2);
            if (D_80109694 < 0) {
                D_80109698 = 3;
            } else {
                vs_mainMenu_unequipShield();
                if (D_80109694 == var_s0) {
                    D_80109699 = 0;
                    D_8010969A = 0;
                } else {
                    temp_s1 = &vs_battle_inventory.shields[D_80109767 - 1];
                    temp_s1->isEquipped = var_s0;
                    temp_a1 = vs_battle_characterState->unk3C;
                    D_80109699 = temp_s1->base.wepId;
                    D_8010969A = temp_s1->base.material;
                    if ((temp_a1->weapon.blade.id != 0)
                        && (vs_mainMenu_weaponHands[temp_a1->weapon.blade.category - 1]
                            != 0)) {
                        vs_mainMenu_unequipAllWeapons();
                    }
                    vs_battle_equipShield(temp_s1);
                }
                D_80109698 = 2;
            }
        }
        break;
    case 2:
        if (func_801090C4(0, D_80109699, D_8010969A) != 0) {
            break;
        }
        D_80109698 = 3;
        // Fallthrough
    case 3:
        if (vs_mainmenu_ready() != 0) {
            return D_80109694;
        }
        break;
    }
    return 0;
}

static int func_80107B14(int arg0)
{
    static char D_80109624[] = { 0, 5, 5, 2, 3, 4, 6, 7 };

    static int D_8010969C;
    static char D_801096A0;
    static char D_801096A1;
    static u_char D_801096A2;

    int temp_s7;
    int temp_v0_3;
    int var_a1;
    int i;
    int var_s6;
    int temp_s0;
    int temp_s0_3;
    vs_battle_inventoryArmor* var_a1_2;

    if (arg0 != 0) {
        D_801096A2 = arg0;
        for (i = 0; i < 16; ++i) {
            temp_s0 = vs_main_inventoryIndices.armor[i];
            if ((temp_s0 != 0)
                && (vs_battle_inventory.armor[temp_s0 - 1].bodyPart == arg0)) {
                break;
            }
        }

        if (i == 0x10) {
            temp_s0 = 0;
        }

        D_801096A1 = temp_s0;
        vs_mainMenu_setArmorStats(temp_s0);
        vs_mainMenu_drawClassAffinityType(7);
        vs_mainMenu_drawDpPpbars(1);
        vs_mainMenu_renderEquipStats(1);
        D_801096A0 = 0;
        return 0;
    }

    temp_s0 = D_801096A0;

    switch (temp_s0) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            temp_s7 = vs_mainMenu_getItemCount(4, NULL);
            var_a1 = 0;

            for (i = 0; i < 16; ++i) {
                if (vs_battle_inventory.armor[i].bodyPart == D_801096A2) {
                    var_a1 = 1;
                }
            }
            {
                char textBuf[(temp_s7 + 1) * 96];
                u_short* menuText[(temp_s7 + 1) * 2];
                int rowTypes[(temp_s7 + 1)];

                if (var_a1 == 0) {
                    for (i = 0; i < 2; ++i) {
                        menuText[i] = &_menuText[_menuText[VS_menuText_INDEX_none + i]];
                    }
                    rowTypes[0] = 1;
                } else {
                    for (i = 0; i < temp_s7; ++i) {
                        temp_s0_3 = vs_main_inventoryIndices.armor[i];
                        if ((temp_s0_3 != 0)
                            && (vs_battle_inventory.armor[temp_s0_3 - 1].bodyPart
                                == D_801096A2)) {
                            vs_mainMenu_initUiArmor(
                                &vs_battle_inventory.armor[temp_s0_3 - 1],
                                (char**)menuText, rowTypes, textBuf);
                            rowTypes[0] |= temp_s0_3 << 0x13;
                        }
                    }
                }
                var_s6 = 1;
                for (i = 0; i < temp_s7; ++i) {
                    temp_s0_3 = vs_main_inventoryIndices.armor[i];
                    if ((temp_s0_3 != 0)
                        && (vs_battle_inventory.armor[temp_s0_3 - 1].category
                            == D_80109624[D_801096A2])
                        && (vs_battle_inventory.armor[temp_s0_3 - 1].bodyPart == 0)) {
                        vs_mainMenu_initUiArmor(&vs_battle_inventory.armor[temp_s0_3 - 1],
                            (char**)&menuText[var_s6 * 2], &rowTypes[var_s6],
                            textBuf + var_s6 * 0x60);
                        rowTypes[var_s6] |= temp_s0_3 << 0x13;
                        ++var_s6;
                    }
                }
                _populateMenuRows(var_s6, menuText, rowTypes);
                D_801096A0 = 1;
            }
        }
        break;
    case 1:
        vs_mainMenu_setArmorStats(D_80109767);
        func_8010659C(1);
        temp_v0_3 = func_80106574() + 1;
        D_8010969C = temp_v0_3;
        if (temp_v0_3 != 0) {
            vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
            vs_mainMenu_menuItemFlyoutLeft(-1);
            vs_mainMenu_drawClassAffinityType(-1);
            vs_mainMenu_drawDpPpbars(4);
            vs_mainMenu_renderEquipStats(2);
            if (D_8010969C < 0) {
                D_801096A0 = 3;
            } else {
                if (D_801096A1 != 0) {
                    vs_battle_inventory.armor[D_801096A1 - 1].bodyPart = 0;
                }
                if (D_8010969C == temp_s0) {
                    vs_battle_equipArmor(D_801096A2 - 1, NULL);
                } else {
                    var_a1_2 = &vs_battle_inventory.armor[D_80109767 - 1];
                    var_a1_2->bodyPart = D_801096A2;
                    vs_battle_equipArmor(D_801096A2 - 1, var_a1_2);
                }
                D_801096A0 = 2;
            }
        }
        break;
    case 2:
        D_801096A0 = 3;
        // Fallthrough
    case 3:
        if (vs_mainmenu_ready() != 0) {
            return D_8010969C;
        }
        break;
    }
    return 0;
}

static int func_80108010(int arg0)
{
    static int (*D_8010962C[])(
        int) = { func_80107B14, func_80107148, func_80107620, func_80106C94 };

    static u_char D_801096A3;

    if (arg0 != 0) {
        if (arg0 == 8) {
            D_801096A3 = 3;
        } else {
            if (arg0 >= 3) {
                arg0 -= 2;
                D_801096A3 = 0;
            } else {
                D_801096A3 = arg0;
            }
        }
    }
    return D_8010962C[D_801096A3](arg0);
}

static int func_80108088(int arg0)
{
    static char D_8010963C[] = { 0x78, 0x79, 0x69, 0x6A, 0x68, 0x6D, 0x6B, 0x7A };

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

    if (arg0 != 0) {
        vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
        D_80109717 = 1;
        state = 0;
        return 0;
    }

    switch (state) {
    case 0:
        if (vs_mainmenu_ready() == 0) {
            break;
        }
        menuItem = vs_battle_setMenuItem(
            0x1F, 0x140, 0x12, 0x7E, 8, (char*)&_menuText[VS_menuText_OFFSET_equip]);
        menuItem->state = 2;
        menuItem->targetPosition0 = 0xB4;
        menuItem->selected = 1;
        state = 1;
        // Fallthrough
    case 1:
        if (vs_mainmenu_ready() == 0) {
            break;
        }

        D_80109717 = 1;

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
            rowTypes[i] |= D_8010963C[i] << 9;
        }
        vs_mainmenu_setMenuRows(8, 0x19134, &rowStrings[0], rowTypes);
        state = 2;
        break;
    case 2:
        if (vs_main_buttonsPressed.all & PADRleft) {
            vs_battle_playInvalidSfx();
        }
        selectedRow = vs_mainmenu_getSelectedRow() + 1;
        if (selectedRow != 0) {
            if (selectedRow < 0) {
                D_80109717 = -selectedRow;
                vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
                state = 3;
            } else {
                _statusViewStartTransition(selectedRow - 1 + 10);
                state = 4;
            }
        }
        break;
    case 3:
        if ((selectedRow == -2) || (vs_mainmenu_ready() != 0)) {
            return selectedRow;
        }
        break;
    case 4:
        if (vs_mainmenu_ready() != 0) {
            D_80109568 = 1;
            _statusViewContinueTransition(selectedRow + 9);
            D_80109712 = 0;
            D_80109713 = 0;
            func_80108010(selectedRow);
            state = 5;
        }
        break;
    case 5:
        selectedRow = func_80108010(0);
        if (selectedRow != 0) {
            if (selectedRow == -2) {
                state = 3;
                break;
            }
            D_80109568 = 0;
            D_80109712 = 1;
            D_80109717 = 2;
            D_80109713 = 1;
            state = 0;
        }
        break;
    }

    if (state == 2) {
        menuItem = vs_battle_setMenuItem(0x1F, 0xB4, 0x12, 0x8C, 8,
            (char*)&_menuText[_menuText[VS_menuText_INDEX_equipWeapon
                                        + vs_mainMenu_getConfirmedRow()]]);
        menuItem->selected = 1;
    }

    return 0;
}

static void func_80108518(int arg0)
{
    static int D_80109644 = 0;
    static char D_80109648 = 0;

    static int D_801096AC;
    static int _[3] __attribute__((unused));
    static vs_unk_gfx_t2 D_801096BC;
    static vs_unk_gfx_t D_801096DC;

    int temp_lo;
    int temp_lo_2;
    int temp_s1_2;
    int var_s2;
    vs_unk_gfx_t* p = (vs_unk_gfx_t*)&D_1F800000[13];

    switch (arg0) {
    case 0:
        var_s2 = D_80109564;
        switch (D_80109568) {
        case 0:
            if (var_s2 < 0xA) {
                ++var_s2;
                D_80109564 = var_s2;
            }
            var_s2 = 0x80 - vs_battle_rowAnimationSteps[0xA - var_s2];
            break;
        case 1:
            if (var_s2 > 0) {
                --var_s2;
                D_80109564 = var_s2;
            }
            var_s2 = vs_battle_rowAnimationSteps[var_s2];
            break;
        case 2:
            if (var_s2 < 0xA) {
                ++var_s2;
                D_80109564 = var_s2;
            } else {
                D_80109568 = 0;
            }
            var_s2 = vs_battle_rowAnimationSteps[0xA - var_s2] + 0x80;
            break;
        case 3:
            if (var_s2 > 0) {
                --var_s2;
                D_80109564 = var_s2;
            }
            var_s2 = 0x260 - var_s2 * 0x30;
            break;
        }
        if (D_80109648 != 0) {
            D_80109648 = 0;
            return;
        }
        if (D_80109644 != 0) {
            int temp_s1 = D_800F4538[1]->unk656;
            p->unk10 = ((-rsin(0xB00) * var_s2) >> 8) * temp_s1;
            p->unk14.unk0 = -(D_800F4538[1]->unk63E << 0xB);
            p->unk14.unk4 = ((rcos(0xB00) * var_s2) >> 8) * temp_s1;
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
            return;
        }
        return;
    case 1:
        if (D_80109644 == 0) {
            D_80109564 = 0;
            D_80109568 = 2;
            D_80109648 = arg0;
            D_80109644 = arg0;
            D_801096AC = vs_main_projectionDistance;
            vs_battle_setProjectionDistance(0x200);

            D_801096BC = p[-1].unk14;
            D_801096DC = *p;

            p->unk14.unkC = 0;
            p->unk14.unk10 = 0;
            p->unk14.unk14 = 0;
            p->unk14.unk1C = 0x1000;
            func_8007ACB0();
            func_80100414(0x7FE, 0x80);
            func_800F9A24(0);
            return;
        }
        break;
    case 2:
        if (D_80109644 != 0) {
            func_800F9E0C();
            func_80100414(-4, 0x80);
            vs_battle_setProjectionDistance(D_801096AC);
            p[-1].unk14 = D_801096BC;
            *p = D_801096DC;
            D_80109644 = 0;
        }
        break;
    }
}

int vs_menu3_exec(char* arg0)
{
    static char D_80109649 = 0;

    static char D_80109710;

    int temp_s1;
    int var_s0;
    char temp_a1;
    char temp_a1_2;
    char temp_v0;
    vs_battle_menuItem_t* temp_v0_3;

    temp_v0 = *arg0;
    switch (temp_v0) {
    case 3:
        func_8010296C(0);
        func_800FBD80(0x10);
        D_80109714 = 0;
        D_80109715 = 0;
        D_80109716 = 0;
        D_80109717 = 0;
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
        func_80108518(1);
        func_801053EC(D_80109649 + 1);
        D_80109649 = 0;
        *arg0 = 4;
        // Fallthrough
    case 4:
        if (vs_mainMenu_loadItemNames(0) == 0) {
            break;
        }
        *arg0 = 5;
        // Fallthrough
    case 5:
        var_s0 = func_801053EC(0);
        if (var_s0 == 0) {
            break;
        }
        if (var_s0 > 0) {
            switch (var_s0) {
            case 1:
                func_80108088(1);
                D_801023E3 = 0;
                *arg0 = 6;
                break;
            case 2:
                D_80109568 = 3;
                vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
                D_80109711 = 0;
                D_80109712 = 0;
                D_80109713 = 0;
                *arg0 = 7;
                break;
            case 3:
                func_8010296C(0);
                vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
                func_8008A4DC(1);
                vs_battle_executeAbilityType = 0xD;
                *arg0 = 0xC;
                func_800CB654(0);
                D_800EB9B0 = 0;
                func_80108518(2);
                break;
            }
        } else {
            if (var_s0 == -2) {
                *arg0 = 0xA;
                break;
            } else {
                *arg0 = 9;
                func_8010296C(0);
                vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
                func_8008A4DC(1);
                func_800CB654(0);
                D_800EB9B0 = 0;
                func_80108518(2);
                break;
            }
        }
        break;
    case 6:
        var_s0 = func_80108088(0);
        if (var_s0 != 0) {
            if (var_s0 == -2) {
                D_80109711 = 0;
                D_80109714 = 0;
                *arg0 = 10;
                break;
            }
            D_80109712 = 1;
            D_80109717 = 0;
            D_80109713 = 1;
            func_801053EC(1);
            *arg0 = 5;
        }
        break;
    case 7:
        if (vs_mainmenu_ready() != 0) {
            func_80108518(2);
            *arg0 = 8;
            temp_a1 = vs_battle_menuState.currentState;
            vs_battle_menuState.currentState = 0xD;
            vs_battle_menuState.returnState = temp_a1;
            D_800F4EA0 |= 0x200;
        }
        break;
    case 8:
        if (D_800F51C1 != 0) {
            func_80100414(-4, 0x80);
            func_8008A4DC(1);
            func_8010296C(0);
            vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
            func_800CB654(0);
            D_800EB9B0 = 0;
            D_80109710 = 0xA;
            *arg0 = 0xB;
        } else if (vs_mainmenu_ready() != 0) {
            func_8010296C(0);
            D_80109714 = 0;
            D_80109715 = 0;
            D_80109716 = 0;
            D_80109717 = 0;
            func_80108518(1);
            func_801053EC(1);
            *arg0 = 5;
        }
        break;
    case 9:
        func_800FFB68(0);
        vs_mainMenu_dismissTextBox();
        vs_mainMenu_setNextMenuAction(menuActionNone);
        if (vs_mainmenu_ready() != 0) {
            if (vs_mainMenu_ensureItemNamesLoaded() != 0) {
                *arg0 = 0;
                return 1;
            }
        }
        break;
    case 10:
        func_8008A4DC(1);
        func_8010296C(0);
        vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
        func_800CB654(0);
        D_800EB9B0 = 0;
        func_80108518(2);
        D_80109710 = 10;
        *arg0 = 11;
        break;
    case 11:
        func_800FFB68(0);
        vs_mainMenu_dismissTextBox();
        vs_mainMenu_setNextMenuAction(menuActionNone);
        if (D_80109710 != 0) {
            D_80109710 -= 1;
            break;
        }
        if (vs_mainmenu_ready() != 0) {
            if (vs_mainMenu_ensureItemNamesLoaded() != 0) {
                vs_battle_menuState.currentState = 4;
                *arg0 = 0;
                return 1;
            }
        }
        break;
    case 12:
        func_800FFB68(0);
        vs_mainMenu_dismissTextBox();
        vs_mainMenu_setNextMenuAction(menuActionNone);
        if (D_801022D8 == 0) {
            if (vs_mainMenu_ensureItemNamesLoaded() != 0) {
                D_800F4E98.unk2 = 8;
                temp_a1_2 = (char)vs_battle_menuState.currentState;
                vs_battle_menuState.currentState = 4;
                vs_battle_menuState.returnState = (char)temp_a1_2;
                *arg0 = 0;
                return 1;
            }
        }
        break;
    case 13:
        D_80109649 = 1;
        *arg0 = 0;
        break;
    }
    if (D_80109711 != 0) {
        if (D_80109714 < 0xAU) {
            D_80109714 += 1;
        }
        var_s0 = vs_battle_rowAnimationSteps[0xA - D_80109714];
    } else {
        if (D_80109714 != 0) {
            D_80109714 -= 1;
        }
        var_s0 = (0xA - D_80109714) << 5;
    }
    if ((D_80109714 != 0) && (D_80109717 == 0)) {
        temp_s1 = (D_800F4EE8.unk3A.itemCategory - 1) & 7;
        temp_v0_3 = vs_battle_setMenuItem(
            0x1F, var_s0 + 0xB4, 0x22, 0x8C, 8, (char*)&_menuText[_menuText[temp_s1]]);
        temp_v0_3->selected = 1;
        if (temp_s1 != 7) {
            temp_v0_3->unk12 = vs_mainMenu_inventoryItemCapacities[temp_s1];
            temp_v0_3->unk10 = vs_mainMenu_getItemCount(temp_s1, 0);
        }
    }
    func_80108518(0);
    if (D_80109712 != 0) {
        if (D_80109715 < 4U) {
            D_80109715 += 1;
        }
    } else if (D_80109715 != 0) {
        D_80109715 -= 1;
    }
    func_80102A3C(D_80109715, D_80109717);
    if (D_80109713 != 0) {
        if (D_80109716 < 0xAU) {
            D_80109716 += 1;
        }
        var_s0 = vs_battle_rowAnimationSteps[0xA - D_80109716];
    } else {
        if (D_80109716 != 0) {
            D_80109716 -= 1;
        }
        var_s0 = (0xA - D_80109716) << 5;
    }
    if (D_80109716 != 0) {
        vs_mainMenu_drawButtonUiBackground(0x10 - var_s0, 0x26, 0x58, 0xA);
        vs_mainmenu_drawButton(1, 8 - var_s0, 0x24, NULL);
        vs_battle_renderTextRawColor("STATUS", ((0x1C - var_s0) & 0xFFFF) | 0x260000,
            0x202020 << D_80109713, NULL);
    }
    return 0;
}
