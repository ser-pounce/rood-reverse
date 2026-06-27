#include "260.h"
#include "src/SLUS_010.40/main.h"
#include "src/BATTLE/BATTLE.PRG/146C.h"
#include "src/BATTLE/BATTLE.PRG/30D14.h"
#include "src/BATTLE/BATTLE.PRG/3A1A0.h"
#include "src/BATTLE/BATTLE.PRG/4A0A8.h"
#include "src/BATTLE/BATTLE.PRG/573B8.h"
#include "src/BATTLE/BATTLE.PRG/5BF94.h"
#include "src/MENU/MAINMENU.PRG/278.h"
#include "src/MENU/MAINMENU.PRG/C48.h"
#include "src/MENU/MAINMENU.PRG/2D10.h"
#include "src/MENU/MAINMENU.PRG/58EC.h"
#include "build/assets/MENU/MENUB.PRG/menuText.h"
#include "build/assets/BATTLE/BATTLE.PRG/menuStrings.h"
#include "build/assets/MENU/ITEMHELP.BIN.h"
#include "vs_string.h"
#include "gpu.h"
#include <libetc.h>
#include <stddef.h>
#include <memory.h>
#include <limits.h>

extern void* D_1F800000[];

/**
 * Process L1/R1 input.
 *
 * @return The new page to display.
 */
static int _itemPaging(int items, int page)
{
    if ((vs_main_buttonsState & (PADL1 | PADR1)) != (PADL1 | PADR1)) {

        int previousPage = page;

        items = vs_mainMenu_getItemCount(items, NULL);

        if (vs_main_buttonRepeat & PADL1) {
            page += items - 1;
        }

        if (vs_main_buttonRepeat & PADR1) {
            ++page;
        }

        if (page >= items) {
            page -= items;
        }

        if ((vs_main_buttonsPressed.all & (PADL1 | PADR1)) && (page == previousPage)) {
            vs_battle_playInvalidSfx();
        }
    }

    return page;
}

/**
 * Draws the item categories, optionally highlighting the selection.
 */
static void _renderItemCategory(int y, int highlightSelected)
{
    int i;

    int selectedCategory = (D_800F4EE8.unk3A.currentItemCategory - 1) & 7;

    if (y == 4) {
        func_801013F8(0);
    }

    y = (y * 8) - 16;

    for (i = 0; i < 8; ++i) {
        u_long* var_v1;
        int x = (((i + 1) & 7) * 16) + 32;

        if (i == selectedCategory && highlightSelected == 1) {

            vs_battle_menuItem_t* menuItem = vs_battle_getMenuItem(31);

            if (x >= (menuItem->x - 12)) {
                menuItem->icon = i + 24;
                continue;
            } else {
                var_v1 = vs_battle_setSpriteDefault(vs_getWH(16, 16), x | (16 << 16));
            }

        } else {
            var_v1 = vs_battle_setSpriteDefaultTexPage(
                128, x | (y << 0x10), vs_getWH(16, 16), D_1F800000[1]);
        }

        var_v1[4] = (120 + i * 16) | (128 << 8)
                  | (i == selectedCategory ? vs_getUV0Clut(0, 0, 976, 223)
                                           : vs_getUV0Clut(0, 0, 992, 223));
    }
}

/**
 * Hoists the category to the top and outdents the seleted row.
 */
static void _selectMenuItem(int id)
{
    vs_battle_menuItem_t* menuItem;

    vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);

    menuItem = vs_battle_getMenuItem(31);
    menuItem->state = menuItemTransition_toTop;
    menuItem->targetPosition0 = 18;

    menuItem = vs_battle_getMenuItem(id);
    menuItem->state = menuItemTransition_toLeft;
    menuItem->targetPosition0 = 155;
    menuItem->selected = 1;
    menuItem->subText = NULL;
}

/**
 * Outdents the category and hoists the selected row to the top.
 */
static void _transitionToSubMenu(int id)
{
    vs_battle_menuItem_t* menuItem = vs_battle_getMenuItem(31);
    menuItem->state = menuItemTransition_toLeft;
    menuItem->targetPosition0 = 16;
    menuItem->w = 164;

    menuItem = vs_battle_getMenuItem(id);
    menuItem->state = menuItemTransition_toTop;
    menuItem->targetPosition0 = 18;
}

enum lootItemState {
    lootStateNone,
    lootStateCopied,
    lootStateNoIndent,
    lootStateIndent1,
    lootStateIndent2,
    lootStateIndent3
};

typedef struct {
    char itemCategory;
    u_char itemIndex;
    char unk2;
    char state;
} _lootListItem;

static u_short _menuText[] = {
#include "build/assets/MENU/MENUB.PRG/menuText.vsString"
};

static char D_8010A504 = 0;
static char _controlsEnabled = 0;
static int _ashleyYOffset = 0;
static int _ashleyRenderState = 0;

static _lootListItem* _lootList;
static _lootListItem* D_8010A6A4;
static vs_battle_inventory_t* _inventory;
static vs_battle_inventory_t* _inventoryBackup;
static char D_8010A6B0;
static u_char _inventoryCapacityFlyinTimer;
static char D_8010A6B2;
static u_char _lootLeftEdge;
static char _selectedLoot;
static u_char _lootListOffset;
static u_char _lootListCount;
static char D_8010A6B7;
static char D_8010A6B8;
static char _menuTitleFlyin;
static char D_8010A6BA;
static char _statusButtonFlyin;

static void _initMenuLayout(int menuItemId, int layout)
{
    _ashleyRenderState = 1;
    D_8010A6BA = 0;
    _statusButtonFlyin = 0;

    _transitionToSubMenu(menuItemId);
    vs_mainMenu_drawClassAffinityType(layout);
    vs_mainMenu_renderEquipStats(1);
}

static void _setSubMenu(int id, char** menuText, u_int rowType, int arg3)
{
    vs_battle_menuItem_t* temp_v0;

    vs_battle_playMenuChangeSfx();

    temp_v0 = vs_battle_setMenuItem(id, 155, 18, 0xA5, 0, menuText[0]);
    temp_v0->selected = 1;
    temp_v0->icon = rowType >> 0x1A;
    temp_v0->material = (rowType >> 0x10) & 7;

    vs_mainmenu_setInformationMessage(menuText[1]);
    vs_battle_getMenuItem(31)->itemPage = arg3 + 1;
}

/**
 * Sets the cursor memory and returns the selected item index.
 */
static int _getItemIndex(int itemCategory, int index)
{
    D_800F4EE8.cursorMemories[(itemCategory + 30) * 2] = 0;
    D_800F4EE8.cursorMemories[(itemCategory + 30) * 2 + 1] = index;
    return vs_mainMenu_inventoryIndices[itemCategory][index];
}

static char menuTitleAnimationStep;
static char D_8010A6BD;
static char statusButtonAnimationStep;
static char D_8010A6BF;
static int _exitToBattle;

/**
 * Sets up the menu close animations.
 */
static void _initMenuLeave(int withDpPpbars)
{
    vs_battle_playMenuLeaveSfx();
    vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
    vs_mainMenu_menuItemFlyoutLeft(-1);
    vs_mainMenu_drawClassAffinityType(-1);
    vs_mainMenu_renderEquipStats(2);

    D_8010A6BF = 2;
    _exitToBattle = vs_main_buttonsPressed.all & PADRup;

    if (withDpPpbars != 0) {
        vs_mainMenu_drawDpPpbars(4);
    }
}

/**
 * Renders the weapon page.
 *
 * @param selectedMenuItem Packed value:
 *
 * - Bits 0-7: Item ID
 *
 * - Bits 8+: Item row in menu
 *
 * @return 1 when menu is closing, 0 otherwise.
 */
static int _weaponDetailsPage(int selectedMenuItem)
{
    enum state { init, initRows, render, leave };
    static char state;
    static char row;
    static char menuItemId;
    static u_char selectedWeapon;
    static char _ __attribute__((unused));

    if (selectedMenuItem != 0) {
        menuItemId = selectedMenuItem >> 8;
        selectedWeapon = selectedMenuItem - 1;

        _selectMenuItem(menuItemId);

        _ = 0;
        row = 0;
        state = init;
        return 0;
    }

    switch (state) {
    case init:
        if (vs_mainmenu_ready() == 0) {
            break;
        }

        _initMenuLayout(menuItemId, 7);
        vs_mainMenu_setUiWeaponStats(vs_main_inventoryIndices.weapons[selectedWeapon]);
        vs_mainMenu_drawDpPpbars(3);

        state = initRows;
        break;

    case initRows:
        if (row < 10) {
            ++row;

            if (row < 6) {
                vs_mainMenu_initWeaponDetailsMenu(
                    row, vs_main_inventoryIndices.weapons[selectedWeapon], 1);
            }

            break;
        }

        state = render;
        break;

    case render:
        if (vs_main_buttonsPressed.all & (PADRup | PADRdown)) {

            _initMenuLeave(1);

            state = leave;
        } else {
            char* text[2];
            int rowType;
            int i;
            int weaponPage = _itemPaging(0, selectedWeapon);

            if (weaponPage == selectedWeapon) {
                break;
            }

            selectedWeapon = weaponPage;

            i = _getItemIndex(0, weaponPage);
            vs_mainMenu_initUiWeapon(
                &vs_battle_inventory.weapons[i - 1], text, &rowType, vs_battle_stringBuf);
            vs_mainMenu_setUiWeaponStats(i);
            _setSubMenu(menuItemId, text, rowType, weaponPage);

            for (i = 1; i < 6; ++i) {
                vs_mainMenu_initWeaponDetailsMenu(
                    i, vs_main_inventoryIndices.weapons[weaponPage], 0);
            }
        }
        break;

    case leave:
        return vs_mainmenu_ready();
    }

    return 0;
}

/**
 * Renders the blade page.
 *
 * @param selectedMenuItem Packed value:
 *
 * - Bits 0-7: Item ID
 *
 * - Bits 8+: Item row in menu
 *
 * @return 1 when menu is closing, 0 otherwise.
 */
static int _bladeDetailsPage(int selectedMenuItem)
{
    enum state { init, animationWait, render, leave };

    static char state;
    static char animationTimer;
    static char menuItemId;
    static u_char selectedBlade;

    if (selectedMenuItem != 0) {
        menuItemId = selectedMenuItem >> 8;
        selectedBlade = selectedMenuItem - 1;
        _selectMenuItem(menuItemId);
        animationTimer = 10;
        state = init;
        return 0;
    }

    switch (state)
    case init: {
        if (vs_mainmenu_ready() != 0) {
            _initMenuLayout(menuItemId, 3);
            vs_mainMenu_setUiBladeStats(vs_main_inventoryIndices.blades[selectedBlade]);
            vs_mainMenu_drawDpPpbars(3);
            state = animationWait;
        }
        break;
    case animationWait:
        if (animationTimer != 0) {
            --animationTimer;
        } else {
            state = render;
        }
        break;
    case render:
        if (vs_main_buttonsPressed.all & (PADRup | PADRdown)) {
            _initMenuLeave(1);
            state = leave;
        } else {
            int selectedBladePage = _itemPaging(1, selectedBlade);
            if (selectedBladePage != selectedBlade) {
                char* text[2];
                int rowType;
                int bladeIndex;
                selectedBlade = selectedBladePage;
                bladeIndex = _getItemIndex(1, selectedBladePage);
                vs_mainMenu_setUiBlade(&vs_battle_inventory.blades[bladeIndex - 1], text,
                    &rowType, vs_battle_stringBuf);
                vs_mainMenu_setUiBladeStats(bladeIndex);
                _setSubMenu(menuItemId, text, rowType, selectedBladePage);
            }
        }
        break;
    case leave:
        return vs_mainmenu_ready();
    }

        return 0;
}

/**
 * Renders the grip page.
 *
 * @param selectedMenuItem Packed value:
 *
 * - Bits 0-7: Item ID
 *
 * - Bits 8+: Item row in menu
 *
 * @return 1 when menu is closing, 0 otherwise.
 */
static int _gripDetailsPage(int selectedMenuItem)
{
    enum state { init, animationWait, render, leave };

    static char* gemCountText = "X     0";
    static char state;
    static char animationTimer;
    static char menuItemId;
    static char selectedGrip;
    static char _ __attribute__((unused));

    if (selectedMenuItem != 0) {
        menuItemId = selectedMenuItem >> 8;
        selectedGrip = selectedMenuItem - 1;
        _selectMenuItem(menuItemId);
        _ = 0;
        animationTimer = 0;
        state = init;
        return 0;
    }

    switch (state) {
    case init:
        if (vs_mainmenu_ready() != 0) {
            _initMenuLayout(menuItemId, 4);
            vs_mainMenu_setUiGripStats(vs_main_inventoryIndices.grips[selectedGrip]);
            state = animationWait;
        }
        break;
    case animationWait:
        if (animationTimer < 10) {
            ++animationTimer;
        } else {
            state = render;
        }
        break;
    case render:
        if (vs_main_buttonsPressed.all & (PADRup | PADRdown)) {
            _initMenuLeave(0);
            state = leave;
        } else {
            int selectedGripPage = _itemPaging(2, selectedGrip);
            if (selectedGripPage != selectedGrip) {
                char* menuText[2];
                int rowType;
                int gripIndex;
                selectedGrip = selectedGripPage;
                gripIndex = _getItemIndex(2, selectedGripPage);
                vs_mainMenu_setUiGrip(&vs_battle_inventory.grips[gripIndex - 1], menuText,
                    &rowType, vs_battle_stringBuf);
                vs_mainMenu_setUiGripStats(gripIndex);
                _setSubMenu(menuItemId, menuText, rowType, selectedGripPage);
            }
        }
        gemCountText[6] =
            (vs_battle_inventory.grips[vs_main_inventoryIndices.grips[selectedGrip] - 1]
                    .gemSlots
                + '0'); // BUG: Write to const char
        vs_mainMenu_drawRowIcon(0x116, 0x100, 0x20);
        vs_battle_renderTextRaw(gemCountText, vs_getXY(280, 36), NULL);
        break;
    case leave:
        return vs_mainmenu_ready();
    }
    return 0;
}

/**
 * Renders the shield page.
 *
 * @param selectedMenuItem Packed value:
 *
 * - Bits 0-7: Item ID
 *
 * - Bits 8+: Item row in menu
 *
 * @return 1 when menu is closing, 0 otherwise.
 */
static int _shieldDetailsPage(int selectedMenuItem)
{
    enum state { init, animationWait, render, leave };

    static char state;
    static char animationTimer;
    static char menuItemId;
    static u_char selectedShield;
    static char _ __attribute__((unused));

    if (selectedMenuItem != 0) {
        menuItemId = selectedMenuItem >> 8;
        selectedShield = selectedMenuItem - 1;
        _selectMenuItem(menuItemId);
        _ = 0;
        animationTimer = 0;
        state = init;
        return 0;
    }

    switch (state) {
    case init:
        if (vs_mainmenu_ready() != 0) {
            _initMenuLayout(menuItemId, 7);
            vs_mainMenu_setShieldStats(vs_main_inventoryIndices.shields[selectedShield]);
            vs_mainMenu_drawDpPpbars(3);
            state = animationWait;
        }
        break;
    case animationWait:
        if (animationTimer < 10) {
            ++animationTimer;
            if (animationTimer < 4) {
                vs_mainMenu_initSetShieldGemMenu(
                    animationTimer, vs_main_inventoryIndices.shields[selectedShield], 1);
            }
            break;
        }
        if (vs_mainmenu_ready() != 0) {
            state = render;
        }
        break;
    case render:
        if (vs_main_buttonsPressed.all & (PADRup | PADRdown)) {
            _initMenuLeave(1);
            state = leave;
        } else {
            int selectedShieldPage = _itemPaging(3, selectedShield);
            if (selectedShieldPage != selectedShield) {
                char* text[2];
                int rowType;
                int i;
                selectedShield = selectedShieldPage;
                i = _getItemIndex(3, selectedShieldPage);
                vs_mainMenu_initUiShield(&vs_battle_inventory.shields[i - 1], text,
                    &rowType, vs_battle_stringBuf);
                vs_mainMenu_setShieldStats(i);
                _setSubMenu(menuItemId, text, rowType, selectedShieldPage);

                for (i = 1; i < 4; ++i) {
                    vs_mainMenu_initSetShieldGemMenu(
                        i, vs_main_inventoryIndices.shields[selectedShieldPage], 0);
                }
            }
        }
        break;
    case leave:
        return vs_mainmenu_ready();
    }
    return 0;
}

/**
 * Renders the armor page.
 *
 * @param selectedMenuItem Packed value:
 *
 * - Bits 0-7: Item ID
 *
 * - Bits 8+: Item row in menu
 *
 * @return 1 when menu is closing, 0 otherwise.
 */
static int _armorDetailsPage(int selectedMenuItem)
{
    enum state { init, animationWait, render, leave };

    static char state;
    static char animationTimer;
    static char menuItemId;
    static char selectedArmor;

    if (selectedMenuItem != 0) {
        menuItemId = selectedMenuItem >> 8;
        selectedArmor = selectedMenuItem - 1;
        _selectMenuItem(menuItemId);
        animationTimer = 10;
        state = init;
        return 0;
    }

    switch (state) {
    case init:
        if (vs_mainmenu_ready() != 0) {
            _initMenuLayout(menuItemId, 7);
            vs_mainMenu_setArmorStats(vs_main_inventoryIndices.armor[selectedArmor]);
            if (vs_battle_inventory
                    .armor[vs_main_inventoryIndices.armor[selectedArmor] - 1]
                    .category
                != 7) {
                vs_mainMenu_drawDpPpbars(1);
            }
            state = animationWait;
        }
        break;
    case animationWait:
        if (animationTimer != 0) {
            --animationTimer;
        } else {
            state = render;
        }
        break;
    case render:
        if (vs_main_buttonsPressed.all & (PADRup | PADRdown)) {
            _initMenuLeave(1);
            state = leave;
        } else {
            int selectedArmorPage = _itemPaging(4, selectedArmor);
            if (selectedArmorPage != selectedArmor) {
                char* text[2];
                int rowType;
                int armorIndex;
                selectedArmor = selectedArmorPage;
                armorIndex = _getItemIndex(4, selectedArmorPage);
                vs_mainMenu_initUiArmor(&vs_battle_inventory.armor[armorIndex - 1], text,
                    &rowType, vs_battle_stringBuf);
                vs_mainMenu_setArmorStats(armorIndex);
                _setSubMenu(menuItemId, text, rowType, selectedArmorPage);
            }
        }
        break;
    case leave:
        return vs_mainmenu_ready();
    }
    return 0;
}

/**
 * Renders the gem page.
 *
 * @param selectedMenuItem Packed value:
 *
 * - Bits 0-7: Item ID
 *
 * - Bits 8+: Item row in menu
 *
 * @return 1 when menu is closing, 0 otherwise.
 */
static int _gemDetailsPage(int selectedMenuItem)
{
    enum state { init, animationWait, render, leave };

    static char state;
    static char animationTimer;
    static char menuItemId;
    static char selectedGem;

    if (selectedMenuItem != 0) {
        menuItemId = selectedMenuItem >> 8;
        selectedGem = selectedMenuItem - 1;
        _selectMenuItem(menuItemId);
        animationTimer = 10;
        state = init;
        return 0;
    }

    switch (state) {
    case init:
        if (vs_mainmenu_ready() != 0) {
            _initMenuLayout(menuItemId, 3);
            vs_mainMenu_setGemStats(vs_main_inventoryIndices.gems[selectedGem]);
            state = animationWait;
        }
        break;
    case animationWait:
        if (animationTimer != 0) {
            --animationTimer;
        } else {
            state = render;
        }
        break;
    case render:
        if (vs_main_buttonsPressed.all & (PADRup | PADRdown)) {
            _initMenuLeave(0);
            state = leave;
            _exitToBattle = vs_main_buttonsPressed.all & PADRup;
        } else {
            int selectedGemPage = _itemPaging(5, selectedGem);
            if (selectedGemPage != selectedGem) {
                char* text[2];
                int rowType;
                int gemIndex;
                selectedGem = selectedGemPage;
                gemIndex = _getItemIndex(5, selectedGemPage);
                vs_mainMenu_setUiGem(&vs_battle_inventory.gems[gemIndex - 1], text,
                    &rowType, vs_battle_stringBuf);
                vs_mainMenu_setGemStats(gemIndex);
                _setSubMenu(menuItemId, text, rowType, selectedGemPage);
            }
        }
        break;
    case leave:
        return vs_mainmenu_ready();
    }
    return 0;
}

/**
 * Invokes the relevant item category page
 *
 * @param selection Packed value:
 *
 * - Bits 0-3: Category
 *
 * - Bits 4-7: Item ID
 *
 * - Bits 8+: Item row in menu
 *
 * @return 1 if item details page is returning, 0 otherwise.
 */
static int _detailsPageDispatcher(int selection)
{
    static int (*detailsPageHandlers[])(int) = { _weaponDetailsPage, _bladeDetailsPage,
        _gripDetailsPage, _shieldDetailsPage, _armorDetailsPage, _gemDetailsPage };

    static u_char currentDetailsPageCategory;

    int handlerResult;
    int selectedMenuItem = 0;

    if (selection != 0) {

        selectedMenuItem = selection >> 4;
        currentDetailsPageCategory = selection & 0xF;
        D_8010A6BF = 1;
        _exitToBattle = 0;

        func_800FDD78();
        vs_battle_getMenuItem(31)->itemPage = selectedMenuItem & 0xFF;
        vs_mainMenu_setNextMenuAction(menuActionNone);
    }

    handlerResult = detailsPageHandlers[currentDetailsPageCategory](selectedMenuItem);

    if (handlerResult != 0) {
        if (_exitToBattle != 0) {
            return -2;
        }
        D_8010A6BA = 1;
        D_8010A6BF = 0;
        _statusButtonFlyin = 1;
        _ashleyRenderState = 0;
        vs_mainMenu_setNextMenuAction(menuActionMenu);
    } else if (vs_mainmenu_ready() != 0) {
        D_801022D5 = D_801024B8 != 9;
        func_801013F8(1);
        func_800FDEBC();
    }

    return handlerResult;
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

static void _sortShields(int stat)
{
    vs_battle_uiShield shield;
    char sortedIndices[8];
    int sortedIndex;
    vs_battle_inventoryShield* shields = &vs_battle_inventory.shields[0];
    char* shieldIndices = vs_main_inventoryIndices.shields;

    vs_battle_rMemzero(sortedIndices, sizeof sortedIndices);
    sortedIndex = 0;

    while (1) {
        int i;
        int index;
        int maxValue = -INT_MAX - 1;

        for (i = 0; i < 8; ++i) {
            index = shieldIndices[i];
            if (index != 0) {
                int value;
                vs_battle_applyShield(&shield, &shields[index - 1]);
                value = _getShieldStatValue(stat, &shield);
                if (maxValue < value) {
                    maxValue = value;
                }
            }
        }

        if (maxValue == -INT_MAX - 1) {
            break;
        }

        for (i = 0; i < 8; ++i) {
            index = shieldIndices[i];
            if (index != 0) {
                vs_battle_applyShield(&shield, &shields[index - 1]);
                if (_getShieldStatValue(stat, &shield) == maxValue) {
                    sortedIndices[sortedIndex++] = index;
                    shieldIndices[i] = 0;
                }
            }
        }
    }
    vs_battle_memcpy(shieldIndices, sortedIndices, 8);
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
        if (stat >= 24) {
            return equipment->types[stat - 23];
        }
        return equipment->affinities[stat - 17];
    }
}

/**
 * Copies equipment for the selected category.
 */
void _copyEquipment(vs_battle_uiEquipment* equipment, int itemCategory, int index)
{
    switch (itemCategory) {
    case itemCategoryBlade:
        vs_battle_copyInventoryBladeStats(equipment, &vs_battle_inventory.blades[index]);
        return;
    case itemCategoryGrip:
        vs_battle_copyInventoryGripStats(equipment, &vs_battle_inventory.grips[index]);
        return;
    case itemCategoryArmor:
        vs_battle_copyInventoryArmorStats(equipment, &vs_battle_inventory.armor[index]);
        return;
    case itemCategoryGem:
        vs_battle_copyInventoryGemStats(equipment, &vs_battle_inventory.gems[index]);
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
        selectedItem = params;

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
            discardTemplate[i] = 0;
        }

        menuItem = vs_battle_setMenuItem(34, -126, 130, 0x7E, 0, discardTemplate);
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
                vs_main_playSfxDefault(0x7E, 0x1C);
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

            discardTemplate[4] = (i & 0xF);

            i = vs_battle_toBCD(i >> 4);

            discardTemplate[3] = (i & 0xF);
            discardTemplate[2] = (i >> 4);

            vs_battle_setMenuItem(34, 0, 130, 126, 0, discardTemplate);

            if (vs_main_buttonsPressed.all & (PADRup | PADRdown)) {

                vs_battle_playMenuLeaveSfx();

                if ((vs_main_buttonsPressed.all & PADRup)) {
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
            i = -1;
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
            cursorBrightness, (54 - (discardStep * 6)) | (114 << 0x10));

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
                vs_main_playSfxDefault(0x7E, 0x1C);
                if (vs_battle_inventory.misc[selectedItem - 1].count == discardCount) {
                    vs_mainMenu_initItem(itemCategory, selectedItem);
                } else {
                    vs_battle_inventory.misc[selectedItem - 1].count =
                        vs_battle_inventory.misc[selectedItem - 1].count - discardCount;
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

static void _setFlyinState(int state)
{
    _menuTitleFlyin = state;
    D_8010A6BA = state;
    _statusButtonFlyin = state;
}

/**
 * Finds the weapon from the specified blade, grip, or gem.
 *
 * @return 0 if no parent weapon exists.
 */
static int _getParentWeaponIndex(int itemCategory, int index)
{
    int parentIndex = 0;

    if (itemCategory == itemCategoryBlade) {
        parentIndex = vs_battle_inventory.blades[index].assembledWeaponIndex;
    }

    if (itemCategory == itemCategoryGrip) {
        parentIndex = vs_battle_inventory.grips[index].assembledWeaponIndex;
    }

    if (itemCategory == itemCategoryGem) {
        parentIndex = vs_battle_inventory.gems[index].setItemIndex;
        if (parentIndex & gemTargetShield) {
            parentIndex = 0;
        }
    }

    return parentIndex;
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

/**
 * Sets the text and rowtypes for the specified category.
 *
 * @return Item count
 */
static int _populateItemRows(
    int itemCategory, char* menuText[], int rowTypes[], char* textBuf)
{
    int i;
    char* indices = vs_mainMenu_inventoryIndices[itemCategory];
    int count = 0;

    for (i = 0; i < vs_mainMenu_inventoryItemCapacities[itemCategory];
         ++count, ++i, textBuf += 96) {

        int parentItem;
        int rowType;
        int index = indices[i];

        if (index == 0) {
            break;
        }

        index = indices[i] - 1;
        rowType = 0;

        switch (itemCategory) {
        case itemCategoryWeapon:
            vs_mainMenu_initUiWeapon(&vs_battle_inventory.weapons[index],
                &menuText[i * 2], &rowTypes[i], textBuf);
            if (vs_battle_inventory.weapons[index].isEquipped != 0) {
                rowType = 0xCA00;
            }
            break;

        case itemCategoryBlade:
            vs_mainMenu_setUiBlade(&vs_battle_inventory.blades[index], &menuText[i * 2],
                &rowTypes[i], textBuf);
            break;

        case itemCategoryGrip:
            vs_mainMenu_setUiGrip(&vs_battle_inventory.grips[index], &menuText[i * 2],
                &rowTypes[i], textBuf);
            break;

        case itemCategoryShield:
            vs_mainMenu_initUiShield(&vs_battle_inventory.shields[index],
                &menuText[i * 2], &rowTypes[i], textBuf);
            if (vs_battle_inventory.shields[index].isEquipped != 0) {
                rowType = 0xCA00;
            }
            break;

        case itemCategoryArmor:
            vs_mainMenu_initUiArmor(&vs_battle_inventory.armor[index], &menuText[i * 2],
                &rowTypes[i], textBuf);
            if (vs_battle_inventory.armor[index].bodyPart != 0) {
                rowType = 0xCA00;
            }
            break;

        case itemCategoryGem:
            vs_mainMenu_setUiGem(&vs_battle_inventory.gems[index], &menuText[i * 2],
                &rowTypes[i], textBuf);
            break;

        case itemCategoryMisc:
            vs_mainMenu_setUiItem(&vs_battle_inventory.misc[index], &menuText[i * 2],
                &rowTypes[i], textBuf);
            break;
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

    return count;
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
static int _itemNavigation(int arg0)
{
    enum state {
        none,
        init,
        waitInit = 5,
        viewDetails = 7,
        populateActions,
        processAction,
        search,
        discard,
        sort,
    };

    enum actions {
        useItem = 1,
        searchItem,
        discardItem,
        discardAllItems,
        sortItems,
    };

    static char availableActions[8];
    static char state;
    static char noItems;
    static char D_8010A61E;
    static char _ __attribute__((unused));
    static int selectedRow;

    char* initMenuText[128];
    int initRowTypes[64];
    char* sp310[128];
    int sp510[64];
    int parent;
    int index;
    int moveBack;
    int var_a1_2;
    int detectRepeat;
    int rowCount;
    int row;
    int noDiscard;
    int i;
    u_char itemCategory;
    int var_v0;
    char* indices;

    if (arg0 != 0) {
        vs_battle_menuItem_t* menuItem = vs_battle_getMenuItem(3);

        if (menuItem->x > 180) {
            if (menuItem->x > 204) {
                menuItem->x -= 24;
            }
            menuItem->state = 2;
            menuItem->targetPosition0 = 180;
        }

        _setFlyinState(1);

        menuTitleAnimationStep = 0;
        D_8010A61E = arg0 & 1;

        if (D_8010A61E != 0) {
            if (vs_main_settings.cursorMemory == 0) {
                memset(&D_800F4EE8.unk3A, 0, sizeof D_800F4EE8.unk3A);
            }
        }

        state = init;
        return 0;
    }

    itemCategory = (D_800F4EE8.unk3A.currentItemCategory - 1) & itemCategoryManage;
    indices = vs_mainMenu_inventoryIndices[itemCategory];

    switch (state) {
    case none:
    case init: {
        char* textBuf = vs_main_allocHeapR(64 * 96);
        D_801023E3 = 1;

        for (i = 0; i < 7; ++i) {
            vs_mainMenu_rebuildInventory(i);
        }

        if (itemCategory == itemCategoryManage) {
            for (i = 0; i < 4; ++i) {
                initMenuText[i] =
                    (char*)&_menuText[_menuText[i + VS_menuText_INDEX_equip]];
                initRowTypes[i] = 1;
            }
            rowCount = 2;
        } else {
            rowCount =
                _populateItemRows(itemCategory, initMenuText, initRowTypes, textBuf);
        }

        noItems = rowCount == 0;

        if (noItems != 0) {
            vs_mainmenu_setInformationMessage(
                (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_noItemsInCategory]);
        } else {

            i = vs_main_settings.cursorMemory;

            if (D_8010A61E != 0) {
                D_8010A61E = 0;
            } else {
                vs_main_settings.cursorMemory = 1;
            }

            parent = itemCategory + 30;

            if (itemCategory == itemCategoryManage) {
                var_a1_2 = parent | 0x200;
            } else {
                var_a1_2 = parent | 0x19200;
            }

            vs_mainmenu_setMenuRows(rowCount, var_a1_2, initMenuText, initRowTypes);

            if (state == none) {
                _restoreItemMenu(itemCategory);
            }

            vs_main_settings.cursorMemory = i;
        }

        vs_main_freeHeapR(textBuf);

        state = 2;
        break;
    }

    case 2:
        _statusButtonFlyin = 1;

        if (noItems != 0) {
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
            int offset;
            u_int category = itemCategory;
            rowCount = category < itemCategoryMisc;
            _statusButtonFlyin = rowCount + 1;

            selectedRow = vs_mainmenu_getSelectedRow() + 1;

            offset = 1;

            if (selectedRow == 0) {
                if (vs_main_buttonsPressed.all & PADRleft) {
                    if ((rowCount != 0) && (vs_mainmenu_ready() != 0)) {

                        vs_battle_playMenuSelectSfx();

                        row = func_80100814();
                        vs_battle_getMenuItem(row >> 8)->itemState = 0;
                        _detailsPageDispatcher(category | ((row + offset) << 4));

                        _menuTitleFlyin = 0;
                        state = 7;
                        break;
                    }

                    vs_battle_playInvalidSfx();
                }
            } else {
                char* textBuf;
                if ((selectedRow <= 0) || (category == itemCategoryManage)) {
                    return selectedRow;
                }

                textBuf = vs_main_allocHeapR(64 * 96);
                row = _populateItemRows(category, sp310, sp510, textBuf);

                sp510[selectedRow - 1] |= 8;
                i = vs_main_settings.cursorMemory;
                vs_main_settings.cursorMemory = 1;

                vs_mainmenu_setMenuRows(row, (category + 30) | 0x19200, sp310, sp510);

                vs_main_settings.cursorMemory = i;

                _restoreItemMenu(category);

                _statusButtonFlyin = 1;
                D_801023E3 = 0;

                vs_main_freeHeapR(textBuf);

                state = 6;
                break;
            }
        }
        // Fallthrough

    case 3:
        i = vs_main_buttonsState & (PADL1 | PADLleft);
        rowCount = vs_main_buttonsState & (PADR1 | PADLright);
        moveBack = i != 0;

        if (rowCount != 0) {
            row = moveBack ^ 1;
        } else {
            row = moveBack & 1;
        }

        if (row != 0) {

            detectRepeat = (PADL1 | PADLleft);

            if (i == (PADL1 | PADLleft)) {
                detectRepeat = PADLleft;
            }

            if (vs_main_buttonRepeat & detectRepeat) {
                itemCategory = (itemCategory - 1) & 7;
            }

            detectRepeat = (PADR1 | PADLright);

            if (rowCount == (PADR1 | PADLright)) {
                detectRepeat = PADLright;
            }

            if (vs_main_buttonRepeat & detectRepeat) {
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

        if ((state == 3) && vs_mainmenu_ready()) {
            if ((vs_main_buttonsState & (PADL1 | PADR1 | PADLleft | PADLright)) && row) {
                break;
            }
            state = init;
            return _itemNavigation(0);
        }
        break;

    case 4: {
        vs_battle_menuItem_t* menuItem = vs_battle_getMenuItem(3);

        if (menuItem->x > 180) {
            if (menuItem->x > 204) {
                menuItem->x -= 24;
            }
            menuItem->state = 2;
            menuItem->targetPosition0 = 180;
        }
    }

        state = waitInit;
        /* fallthrough */

    case waitInit:
        if (vs_mainmenu_ready() != 0) {
            state = init;
        }
        break;

    case 6:
        if (vs_main_buttonsPressed.all & PADRleft) {
            vs_battle_playInvalidSfx();
        }

        i = vs_mainmenu_getSelectedRow() + 1;

        if (i != 0) {

            rowCount = selectedRow;

            if (rowCount == i) {
                state = populateActions;
                break;
            }

            if (i > 0) {

                row = indices[i - 1];
                detectRepeat = indices[rowCount - 1];

                if ((itemCategory == itemCategoryMisc)
                    && (vs_battle_inventory.misc[row - 1].id
                        == vs_battle_inventory.misc[detectRepeat - 1].id)) {
                    vs_battle_inventory.misc[detectRepeat - 1].count =
                        vs_battle_inventory.misc[detectRepeat - 1].count
                        + vs_battle_inventory.misc[row - 1].count;
                    if (vs_battle_inventory.misc[detectRepeat - 1].count > 100) {
                        vs_battle_inventory.misc[row - 1].count =
                            vs_battle_inventory.misc[detectRepeat - 1].count - 100;
                        vs_battle_inventory.misc[detectRepeat - 1].count = 100;
                    } else {
                        vs_mainMenu_initItem(6, detectRepeat);
                    }
                } else {
                    indices[i - 1] = detectRepeat;
                    indices[rowCount - 1] = row;
                }

                vs_mainMenu_clearMenuExcept(3);

                state = 4;
                break;
            }

            if (i != -1) {
                return -2;
            }

            state = none;
        }
        break;

    case viewDetails:
        i = _detailsPageDispatcher(0);

        if (i == 0) {
            break;
        }

        if (i == -2) {
            return -2;
        }

        _menuTitleFlyin = 1;

        {
            vs_battle_menuItem_t* menuItem = vs_battle_getMenuItem(3);

            if (menuItem->x > 180) {
                if (menuItem->x > 204) {
                    menuItem->x -= 24;
                }
                menuItem->state = 2;
                menuItem->targetPosition0 = 180;
            }
        }

        state = init;
        break;

    case populateActions:
        rowCount = 0;
        index = indices[selectedRow - 1] - 1;
        vs_battle_rMemzero(vs_battle_rowTypeBuf, 0x14);

        if (itemCategory == itemCategoryMisc) {
            sp310[0] = (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_useItem];
            sp310[1] = (char*)&_menuText[VS_menuText_OFFSET_itemUseProhibited];
            *vs_battle_rowTypeBuf = 1;
            rowCount = 1;
            availableActions[1] = useItem;
        }

        if (((char)(itemCategory - 1) < (itemCategoryShield - 1))
            || (itemCategory == itemCategoryGem)) {
            sp310[rowCount * 2] =
                (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_searchItem];
            sp310[rowCount * 2 + 1] =
                (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_searchItemDesc];
            if ((_getParentWeaponIndex(itemCategory, index) == 0)
                && (_getParentShieldIndex(itemCategory, index) == 0)) {
                sp310[rowCount * 2 + 1] =
                    (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_invalidSearch];
                vs_battle_rowTypeBuf[rowCount] = 1;
            }
            ++rowCount;
            availableActions[rowCount] = searchItem;
        }

        noDiscard = 0;
        sp310[rowCount * 2] =
            (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_discardItem];
        sp310[rowCount * 2 + 1] =
            (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_discardItemDesc];

        switch (itemCategory) {
        case itemCategoryWeapon:
            noDiscard = vs_battle_inventory.weapons[index].isEquipped != 0;
            break;
        case itemCategoryShield:
            noDiscard = vs_battle_inventory.shields[index].isEquipped != 0;
            break;
        case itemCategoryArmor:
            noDiscard = vs_battle_inventory.armor[index].bodyPart != 0;
            break;
        case itemCategoryMisc:
            if (vs_battle_inventory.misc[index].id > 457) {
                noDiscard = 3;
            }
            break;
        }

        parent = _getParentWeaponIndex(itemCategory, index);

        if (parent != 0) {
            noDiscard = 1;
            if (vs_battle_inventory.weapons[parent - 1].isEquipped == 0) {
                noDiscard = 2;
            }
        }

        parent = _getParentShieldIndex(itemCategory, index);

        if (parent != 0) {
            noDiscard = 1;
            if (vs_battle_inventory.shields[parent - 1].isEquipped == 0) {
                noDiscard = 2;
            }
        }

        if (noDiscard != 0) {
            sp310[rowCount * 2 + 1] = (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp
                    [noDiscard + VS_ITEMHELP_BIN_INDEX_cannotDiscardEquipped - 1]];
            noDiscard = 1;
        }

        vs_battle_rowTypeBuf[rowCount] = noDiscard;
        ++rowCount;
        availableActions[rowCount] = discardItem;

        if (itemCategory == itemCategoryMisc) {
            sp310[rowCount * 2] =
                (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_discardAll];
            sp310[rowCount * 2 + 1] =
                (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_discardAllDesc];
            if (vs_battle_inventory.misc[index].id > 457) {
                sp310[rowCount * 2 + 1] =
                    (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_cannotDiscard];
                vs_battle_rowTypeBuf[rowCount] = 1;
            }
            ++rowCount;
            availableActions[rowCount] = discardAllItems;
        }

        sp310[rowCount * 2] =
            (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_sortItem];
        sp310[rowCount * 2 + 1] =
            (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_sortItemDesc];

        ++rowCount;
        availableActions[rowCount] = sortItems;

        vs_mainMenu_initSortUi(rowCount, itemCategory + 38, sp310, vs_battle_rowTypeBuf);

        state = processAction;
        break;

    case processAction:
        row = func_800FF348();
        vs_mainMenu_printInformation(row, D_801022C4);
        vs_mainMenu_processItemActionMenu();
        i = vs_mainMenu_getSelectedItemAction() + 1;

        var_v0 = 0;

        if (i != 0) {
            if (i > 0) {

                vs_battle_playMenuSelectSfx();
                vs_mainMenu_flyoutLeftExcept(0x28);

                switch (availableActions[i]) {
                case searchItem:
                    vs_mainMenu_initTextBox();
                    vs_mainMenu_clearMenuExcept(3);

                    state = search;
                    break;

                case discardItem:
                    rowCount = indices[selectedRow - 1] | (itemCategory << 8);

                    if ((itemCategory == 6)
                        && (vs_battle_inventory.misc[indices[selectedRow - 1] - 1].count
                            >= 2)) {
                        rowCount |= 0x10000;
                    }

                    _discardMenu(rowCount);

                    state = discard;
                    break;

                case discardAllItems:
                    _discardMenu(
                        indices[selectedRow - 1] | (itemCategory << 8) | 0x20000);

                    state = discard;
                    break;

                case sortItems:
                    vs_mainMenu_initTextBox();
                    _sortItems(itemCategory + 1);

                    state = sort;
                    break;
                }
            } else {
                vs_battle_playMenuLeaveSfx();
                vs_mainMenu_flyoutLeftExcept(0x28);

                if (i == -2) {
                    vs_mainMenu_clearMenuExcept(3);
                    return -2;
                }

                vs_mainMenu_initTextBox();
                state = none;
            }
        }
        break;

    case search:
        if (vs_mainmenu_ready() == 0) {
            break;
        }

        i = _getParentWeaponIndex(itemCategory, indices[selectedRow - 1] - 1);

        if (i == 0) {
            i = _getParentShieldIndex(itemCategory, indices[selectedRow - 1] - 1);
            itemCategory = 3;
        } else {
            itemCategory = 0;
        }

        D_800F4EE8.unk3A.currentItemCategory = (itemCategory + 1) & 7;
        (&D_800F4EE8.unk3A)->unk2[itemCategory].value =
            vs_mainMenu_findItem(itemCategory, i - 1) - 1;

        state = init;
        break;

    case discard:
        i = _discardMenu(0);

        if (i != 0) {
            vs_mainMenu_initTextBox();
            vs_mainMenu_flyoutLeftExcept(0x28);
            vs_mainMenu_clearMenuExcept(3);
            if (i == -2) {
                return -2;
            }
            state = waitInit;
        }
        break;

    case sort:
        i = _sortItems(0);

        if (i != 0) {
            vs_mainMenu_flyoutLeftExcept(40);
            vs_mainMenu_clearMenuExcept(3);
            if (i == -2) {
                return -2;
            }
            state = waitInit;
        }
        break;
    }

    return 0;
}

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

    static int projectionDistance;
    static int _ __attribute__((unused));
    static MATRIX viewMatrixBackup;
    static camera_t2 cameraBackup;

    int yOffset;
    camera_t2* camera = &((camera_t*)&D_1F800000)->t2;

    switch (mode) {
    case 0:
        yOffset = _ashleyYOffset;

        switch (_ashleyRenderState) {
        case 0:
            if (yOffset < 10) {
                _ashleyYOffset = ++yOffset;
            }

            yOffset = 0x80 - vs_battle_rowAnimationSteps[10 - yOffset];
            break;

        case 1:
            if (yOffset > 0) {
                yOffset -= 1;
                _ashleyYOffset = yOffset;
            }

            yOffset = vs_battle_rowAnimationSteps[yOffset];
            break;

        case 2:
            if (yOffset < 10) {
                yOffset += 1;
                _ashleyYOffset = yOffset;
            } else {
                _ashleyRenderState = 0;
            }

            yOffset = vs_battle_rowAnimationSteps[10 - yOffset] + 128;
            break;

        case 3:
            if (yOffset > 0) {
                yOffset -= 1;
                _ashleyYOffset = yOffset;
            }

            yOffset = 0x260 - yOffset * 0x30;
            break;
        }
        if (skipFrame != 0) {
            skipFrame = 0;
            return;
        }

        if (render != 0) {
            int scaledDistance;
            int offsetX;
            int offsetZ;
            int cameraDistance = D_800F4538[1]->cameraDistance;

            setVector(&camera->lookAt, ((-rsin(0xB00) * yOffset) >> 8) * cameraDistance,
                -(D_800F4538[1]->cameraHeightOffset << 0xB),
                ((rcos(0xB00) * yOffset) >> 8) * cameraDistance);

            scaledDistance = cameraDistance * 4;
            offsetX = rcos(0xB00) * scaledDistance;

            camera->position.vx = camera->lookAt.vx + offsetX;
            camera->position.vy = camera->lookAt.vy;

            offsetZ = rsin(0xB00) * scaledDistance;

            setVector(&camera->angles, 0, 0, 0);
            camera->farClip = 0x1000;
            camera->position.vz = camera->lookAt.vz + offsetZ;

            func_8007ACB0();
            func_800F9EB8(&D_1F800000[5]);
        }

        break;

    case 1:
        if (render == 0) {
            _ashleyYOffset = 0;
            _ashleyRenderState = 2;
            skipFrame = mode;
            render = mode;
            projectionDistance = vs_main_projectionDistance;

            vs_battle_setProjectionDistance(0x200);

            viewMatrixBackup = ((camera_t*)((void*)camera - 0x34))->viewMatrix;
            cameraBackup = *camera;
            setVector(&camera->angles, 0, 0, 0);
            camera->farClip = 0x1000;

            func_8007ACB0();
            func_80100414(0x7FE, 0x80);
            func_800F9A24(0);
        }

        break;

    case 2:
        if (render != 0) {

            func_800F9E0C();
            func_80100414(-4, 0x80);
            vs_battle_setProjectionDistance(projectionDistance);

            ((camera_t*)((void*)camera - 0x34))->viewMatrix = viewMatrixBackup;
            *camera = cameraBackup;
            render = 0;
        }

        break;
    }
}

static int _topLevelMenuTransition(int arg0)
{
    static char state;
    static char D_8010A681;

    int stepValue;
    vs_battle_menuItem_t* menuItem;

    if (arg0 != 0) {
        D_800F4EE8.unk3A.currentItemCategory = arg0;
        D_8010A6B0 = 0;
        D_8010A6B2 = 0;
        state = 0;
        return 0;
    }

    switch (state) {
    case 0:
        if (vs_mainmenu_ready() == 0) {
            break;
        }

        func_800FFB68(1);
        vs_mainMenu_setNextMenuAction(menuActionMenu);

        menuItem = vs_battle_setMenuItem(3, 320, 18, 0x7E, 8,
            (char*)&vs_battle_menuStrings
                [vs_battle_menuStrings[VS_menuStrings_INDEX_items]]);
        menuItem->state = 2;
        menuItem->targetPosition0 = 180;
        menuItem->selected = 1;
        state = 1;
        break;

    case 1:
        _setFlyinState(0);

        menuTitleAnimationStep = 0;
        D_8010A6BD = 0;
        statusButtonAnimationStep = 0;
        D_8010A6BF = 0;

        if (vs_mainmenu_ready() == 0) {
            break;
        }

        func_8008A4DC(0);

        D_8010A681 = D_800EB9AF;

        if (!D_8010A681) {
            func_800CB654(1);
            D_800EB9B0 = 0x200000;
        }

        _renderAshley(1);
        _itemNavigation(1);

        state = 2;
        break;

    case 2:
        if (_itemNavigation(0) == 0) {
            break;
        }

        _setFlyinState(0);
        vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
        func_8008A4DC(1);

        if (D_8010A681 == 0) {
            func_800CB654(0);
            D_800EB9B0 = 0;
        }

        _renderAshley(2);

        state = 3;

        if (vs_main_settings.information == 0) {
            vs_mainMenu_dismissTextBox();
        }

        break;

    case 3:
        func_800FFB68(0);
        vs_mainMenu_setNextMenuAction(menuActionNone);

        if (vs_mainmenu_ready() != 0) {
            D_8010A6B0 = 1;
            D_8010A6B2 = 1;
            return 1;
        }

        break;
    }

    if (_menuTitleFlyin != 0) {
        if (menuTitleAnimationStep < 10) {
            ++menuTitleAnimationStep;
        }
        stepValue = vs_battle_rowAnimationSteps[10 - menuTitleAnimationStep];
    } else {
        if (menuTitleAnimationStep != 0) {
            --menuTitleAnimationStep;
        }
        stepValue = (10 - menuTitleAnimationStep) << 5;
    }

    if ((menuTitleAnimationStep != 0) && (D_8010A6BF == 0)) {

        int itemCategory = (D_800F4EE8.unk3A.currentItemCategory - 1) & 7;

        vs_battle_menuItem_t* menuItem =
            vs_battle_setMenuItem(31, stepValue + 180, 34, 140, 8,
                (char*)&_menuText[_menuText[itemCategory + VS_menuText_INDEX_weapons]]);
        menuItem->selected = 1;

        if (itemCategory != 7) {
            menuItem->unk12 = vs_mainMenu_inventoryItemCapacities[itemCategory];
            menuItem->unk10 = vs_mainMenu_getItemCount(itemCategory, NULL);
        }
    }

    _renderAshley(0);

    if (D_8010A6BA != 0) {
        if (D_8010A6BD < 4) {
            ++D_8010A6BD;
        }
    } else if (D_8010A6BD != 0) {
        --D_8010A6BD;
    }

    _renderItemCategory(D_8010A6BD, D_8010A6BF);

    if (_statusButtonFlyin != 0) {
        if (statusButtonAnimationStep < 10) {
            ++statusButtonAnimationStep;
        }
        stepValue = vs_battle_rowAnimationSteps[10 - statusButtonAnimationStep];
    } else {
        if (statusButtonAnimationStep != 0) {
            --statusButtonAnimationStep;
        }
        stepValue = (10 - statusButtonAnimationStep) << 5;
    }

    if (statusButtonAnimationStep != 0) {
        vs_mainMenu_drawButtonUiBackground(0x10 - stepValue, 0x26, 0x58, 10);
        vs_mainmenu_drawButton(1, 8 - stepValue, 0x24, NULL);
        vs_battle_renderTextRawColor("STATUS", ((0x1C - stepValue) & 0xFFFF) | 0x260000,
            0x202020 << _statusButtonFlyin, NULL);
    }

    return 0;
}

static void _updateLootList(void);

static int disassembleItem(int itemIndex)
{
    enum state {
        init,
        initOptionYes,
        initOptionNo,
        waitInit,
        processCommand,
        disassemble,
        finalize,
        leave
    };

    static char cursorMemory = 0;

    static char state;
    static char D_8010A683;
    static char D_8010A684;
    static u_char targetItemIndex;
    static char disassembleItemCategory;
    static char _ __attribute__((unused));

    int i;
    vs_battle_menuItem_t* menuItem;

    if (itemIndex != 0) {

        vs_battle_memcpy(D_8010A6A4, _lootList, 0x280);

        D_8010A6B2 = 0;
        D_8010A684 = _lootListCount;
        targetItemIndex = itemIndex - 1;
        disassembleItemCategory = _lootList[targetItemIndex].itemCategory;
        _selectedLoot = 0;
        _lootListOffset = 0;
        D_8010A683 = 0;
        state = init;

        return 0;
    }

    i = D_8010A6A4[targetItemIndex].itemIndex;

    switch (state) {
    case init:
        if (_lootLeftEdge != 6) {
            break;
        }

        vs_battle_rMemzero(_lootList, 0x280);

        _lootList->itemCategory = D_8010A6A4[targetItemIndex].itemCategory;
        _lootList->itemIndex = i;
        _lootList->state = lootStateNoIndent;

        if (disassembleItemCategory != itemCategoryWeapon) {

            vs_battle_inventoryShield* shield = &_inventory->shields[i];
            _lootList[1].itemCategory = itemCategoryShield;
            _lootList[1].itemIndex = i;
            _lootList[1].state = lootStateIndent1;
            _lootListCount = 2;

            for (i = 0; i < shield->base.gemSlots; ++i) {
                if (shield->gems[i] != 0) {
                    _lootList[_lootListCount].itemCategory = itemCategoryGem;
                    _lootList[_lootListCount].itemIndex = shield->gems[i] - 1;
                    _lootList[_lootListCount].state = lootStateIndent3;
                    ++_lootListCount;
                }
            }
        } else {
            vs_battle_inventoryWeapon* weapon = &_inventory->weapons[i];
            _lootList[1].itemCategory = itemCategoryBlade;
            _lootList[1].itemIndex = weapon->blade - 1;
            _lootList[1].state = lootStateIndent2;
            _lootList[2].itemCategory = itemCategoryGrip;
            _lootList[2].itemIndex = weapon->grip - 1;
            _lootList[2].state = lootStateIndent2;
            _lootListCount = 3;

            for (i = 0; i < _inventory->grips[weapon->grip - 1].gemSlots; ++i) {
                if (weapon->gems[i] != 0) {
                    _lootList[_lootListCount].itemCategory = itemCategoryGem;
                    _lootList[_lootListCount].itemIndex = weapon->gems[i] - 1;
                    _lootList[_lootListCount].state = lootStateIndent3;
                    ++_lootListCount;
                }
            }
        }

        _lootLeftEdge = 10;
        D_8010A6B2 = 1;
        state = initOptionYes;
        break;

    case initOptionYes:
        menuItem = vs_battle_setMenuItem(
            0x1E, 0x140, 0x92, 0x7E, 0, (char*)&_menuText[VS_menuText_OFFSET_optionYes]);
        menuItem->state = 2;
        menuItem->targetPosition0 = 0xC2;
        state = initOptionNo;
        break;

    case initOptionNo:
        menuItem = vs_battle_setMenuItem(
            0x1F, 0x140, 0xA2, 0x7E, 0, (char*)&_menuText[VS_menuText_OFFSET_optionNo]);
        menuItem->state = 2;
        menuItem->targetPosition0 = 0xC2;
        vs_battle_stringContext.strings[0] =
            disassembleItemCategory == 0
                ? _inventory->weapons[i].name
                : vs_mainMenu_itemNames[_inventory->shields[i].base.id];
        vs_battle_initInformationTextBox(1);
        vs_mainmenu_setInformationMessage(
            (char*)&_menuText[VS_menuText_OFFSET_disassembleConfirm]);
        state = waitInit;
        break;

    case waitInit:
        state += vs_mainmenu_ready();
        break;

    case processCommand:
        vs_battle_getMenuItem(D_8010A683 + 30)->selected = 1;
        vs_battle_getMenuItem(31 - D_8010A683)->selected = 0;

        if (vs_main_buttonsPressed.all & (PADRright | PADRdown)) {
            vs_mainMenu_menuItemFlyoutRight(30);
            vs_mainMenu_menuItemFlyoutRight(31);
            D_8010A6B2 = 0;
            if ((D_8010A683 != 0) || (vs_main_buttonsPressed.all & PADRdown)) {
                vs_battle_playMenuLeaveSfx();
                state = finalize;
            } else {
                vs_main_playSfxDefault(0x7E, 0x19);
                state = disassemble;
            }
            if (vs_main_settings.information == 0) {
                vs_mainMenu_dismissTextBox();
            }
            break;
        }

        if (vs_main_buttonRepeat & (PADLup | PADLdown)) {
            vs_battle_playMenuChangeSfx();
            D_8010A683 = (1 - D_8010A683);
        }

        cursorMemory = vs_battle_drawCursor(cursorMemory, D_8010A683 + 8);
        break;

    case disassemble:
        if (_lootLeftEdge != 6) {
            break;
        }

        vs_battle_rMemcpy(&D_8010A6A4[D_8010A684], &_lootList[1],
            (_lootListCount - 1) * sizeof _lootList[1]);

        if (disassembleItemCategory != itemCategoryWeapon) {
            vs_battle_inventoryShield* shield = &_inventory->shields[i];
            for (i = 0; i < shield->base.gemSlots; ++i) {
                int gem = shield->gems[i];
                if (gem != 0) {
                    shield->gems[i] = 0;
                    _inventory->gems[gem - 1].setItemIndex = 0;
                }
            }
        } else {
            vs_battle_inventoryWeapon* weapon = &_inventory->weapons[i];
            _inventory->blades[weapon->blade - 1].assembledWeaponIndex = 0;
            _inventory->grips[weapon->grip - 1].assembledWeaponIndex = 0;

            for (i = 0; i < _inventory->grips[weapon->grip - 1].gemSlots; ++i) {
                int gem = weapon->gems[i];
                if (gem != 0) {
                    weapon->gems[i] = 0;
                    _inventory->gems[gem - 1].setItemIndex = 0;
                }
            }
        }

        D_8010A684 = _lootListCount + (D_8010A684 + 0xFE);

        for (i = targetItemIndex; i < D_8010A684; ++i) {
            D_8010A6A4[i] = D_8010A6A4[i + 1];
        }
        // Fallthrough

    case finalize:
        if (_lootLeftEdge != 6) {
            break;
        }

        _lootListCount = D_8010A684;

        vs_battle_memcpy(_lootList, D_8010A6A4, 0x280);
        _updateLootList();

        _lootLeftEdge = 10;
        D_8010A6B2 = 1;
        state = leave;
        break;

    case leave:
        if (_lootLeftEdge != 0) {
            break;
        }
        return -1;
    }

    return 0;
}

static int _consolidateMiscItems(int lootIndex)
{
    static char D_8010A5CA = 0;

    static u_short D_8010A688;
    static u_short D_8010A68A;
    static u_short itemId;
    static char state;
    static char D_8010A68F;
    static u_char lootCount;

    _lootListItem* loot;
    int i;
    int j;
    int var_v0;
    vs_battle_inventoryMisc* item;
    vs_battle_menuItem_t* menuItem;

    if (lootIndex != 0) {

        vs_battle_memcpy(D_8010A6A4, _lootList, 0x280);
        vs_battle_memcpy(_inventoryBackup, _inventory, sizeof *_inventory);

        D_8010A6B2 = 0;
        lootCount = _lootListCount;
        itemId = _inventory->misc[_lootList[lootIndex - 1].itemIndex].id;
        _selectedLoot = 0;
        _lootListOffset = 0;
        D_8010A68F = 0;
        state = 0;
        return 0;
    }

    switch (state) {
    case 0:
        if (_lootLeftEdge == 6) {

            D_8010A68A = 0;
            item = vs_battle_inventory.misc;

            for (i = 0; i < 64; ++i, ++item) {
                if (item->id == itemId) {
                    int v0 = D_8010A68A + 100;
                    v0 -= item->count;
                    D_8010A68A = v0;
                }
            }

            D_8010A688 = 0;

            for (i = 0; i < _lootListCount; ++i) {
                if (_lootList[i].itemCategory == itemCategoryMisc) {
                    item = &_inventory->misc[_lootList[i].itemIndex];
                    if (item->id == itemId) {

                        D_8010A688 += item->count;

                        vs_battle_rMemzero(item, sizeof *item);

                        --_lootListCount;

                        for (j = i; j < _lootListCount; ++j) {
                            _lootList[j] = _lootList[j + 1];
                        }
                        --i;
                    }
                }
            }

            _lootListCount = 0;

            while (D_8010A688 != 0) {

                for (i = 0; i < 64; ++i) {
                    if (_inventory->misc[i].id == 0) {
                        break;
                    }
                }

                if (i == 64) {
                    break;
                }

                loot = &_lootList[_lootListCount++];
                loot->itemCategory = itemCategoryMisc;
                loot->itemIndex = i;
                loot->unk2 = 0;
                _inventory->misc[i].id = itemId;
                loot->state = D_8010A68A != 0;

                if (loot->state != lootStateNone) {
                    if (D_8010A68A > 100) {
                        _inventory->misc[i].count = 100;
                        D_8010A688 -= 100;
                        D_8010A68A -= 100;
                    } else {
                        _inventory->misc[i].count = D_8010A68A;
                        D_8010A688 = D_8010A688 - D_8010A68A;
                        D_8010A68A = 0;
                    }
                } else if (D_8010A688 > 100) {
                    _inventory->misc[i].count = 100;
                    D_8010A688 -= 100;
                } else {
                    _inventory->misc[i].count = D_8010A688;
                    D_8010A688 = 0;
                }
            }

            _lootLeftEdge = 10;
            D_8010A6B2 = 1;
            state = 1;
        }
        break;

    case 1:
        menuItem = vs_battle_setMenuItem(
            30, 320, 146, 0x7E, 0, (char*)&_menuText[VS_menuText_OFFSET_optionYes]);
        menuItem->state = 2;
        menuItem->targetPosition0 = 194;
        state = 2;
        break;

    case 2:
        menuItem = vs_battle_setMenuItem(
            31, 320, 162, 0x7E, 0, (char*)&_menuText[VS_menuText_OFFSET_optionNo]);
        menuItem->state = 2;
        menuItem->targetPosition0 = 194;
        vs_battle_stringContext.strings[0] = vs_mainMenu_itemNames[itemId];

        vs_battle_initInformationTextBox(1);
        vs_mainmenu_setInformationMessage(
            (char*)&_menuText[VS_menuText_OFFSET_organizeConfirm]);

        state = 3;
        break;

    case 3:
        state += vs_mainmenu_ready();
        break;

    case 4:
        vs_battle_getMenuItem(30 + D_8010A68F)->selected = 1;
        vs_battle_getMenuItem(31 - D_8010A68F)->selected = 0;

        if (vs_main_buttonsPressed.all & 0x60) {

            vs_mainMenu_menuItemFlyoutRight(30);
            vs_mainMenu_menuItemFlyoutRight(31);

            D_8010A6B2 = 0;

            if ((D_8010A68F != 0) || (vs_main_buttonsPressed.all & PADRdown)) {
                vs_battle_playMenuLeaveSfx();
                state = 6;
            } else {
                vs_battle_playMenuSelectSfx();
                state = 5;
            }

            var_v0 = 0;

            if (vs_main_settings.information == 0) {
                vs_mainMenu_dismissTextBox();
            }

            break;
        }

        if (vs_main_buttonRepeat & (PADLup | PADLdown)) {
            vs_battle_playMenuChangeSfx();
            D_8010A68F = 1 - D_8010A68F;
        }

        D_8010A5CA = vs_battle_drawCursor(D_8010A5CA, D_8010A68F + 8);
        break;

    case 5:
        if (_lootLeftEdge != 6) {
            break;
        }

        for (i = 0; i < lootCount; ++i) {
            if (D_8010A6A4[i].itemCategory == 6) {

                item = &_inventoryBackup->misc[D_8010A6A4[i].itemIndex];

                if (item->id == itemId) {

                    vs_battle_rMemzero(item, 4);

                    --lootCount;

                    for (j = i; j < lootCount; ++j) {
                        D_8010A6A4[j] = D_8010A6A4[j + 1];
                    }
                    --i;
                }
            }
        }

        for (i = 0; i < _lootListCount; ++i) {
            for (j = 0; j < 64; ++j) {
                if (_inventoryBackup->misc[j].id == 0) {
                    break;
                }
            }

            if (j == 0x40) {
                break;
            }

            loot = &D_8010A6A4[lootCount++];
            loot->itemCategory = itemCategoryMisc;
            loot->itemIndex = j;
            loot->unk2 = 0;
            loot->state = _lootList[i].state;
            item = &_inventoryBackup->misc[j];
            item->id = itemId;
            item->count = _inventory->misc[_lootList[i].itemIndex].count;
        }
        // Fallthrough

    case 6:
        if (_lootLeftEdge == 6) {

            _lootListCount = lootCount;

            vs_battle_memcpy(_lootList, D_8010A6A4, sizeof *_lootList * 160);
            vs_battle_memcpy(_inventory, _inventoryBackup, sizeof *_inventory);

            _lootLeftEdge = 10;
            D_8010A6B2 = 1;
            state = 7;
        }
        break;

    case 7:
        if (_lootLeftEdge != 0) {
            break;
        }
        return -1;
    }

    return 0;
}

static int _copyBladeToInventory(vs_battle_inventoryBlade* source, int weapon)
{
    int index = 1;
    vs_battle_inventoryBlade* blade = _inventory->blades;

    while (blade->id != 0) {
        ++blade;
        ++index;
        if (index == 16) {
            return 0;
        }
    }

    vs_battle_copyAligned(blade, source, sizeof *blade);

    blade->assembledWeaponIndex = weapon;
    blade->index = index;
    return index;
}

static int _copyGripToInventory(vs_battle_inventoryGrip* source, int weaponIndex)
{
    int index = 1;
    vs_battle_inventoryGrip* grip = _inventory->grips;

    while (grip->id != 0) {
        ++grip;
        ++index;
        if (index == 16) {
            return 0;
        }
    }

    vs_battle_copyAligned(grip, source, sizeof *grip);

    grip->assembledWeaponIndex = weaponIndex;
    grip->index = index;
    return index;
}

static int _copyGemToInventory(vs_battle_inventoryGem* source, int item)
{
    int index = 1;
    vs_battle_inventoryGem* gem = _inventory->gems;

    while (gem->id != 0) {
        ++gem;
        ++index;
        if (index == 0x30) {
            return 0;
        }
    }

    vs_battle_copyAligned(gem, source, sizeof *gem);

    gem->setItemIndex = item;
    gem->index = index;
    return index;
}

static int _copyWeaponToInventory(vs_battle_lootedWeapon* arg0)
{
    int i;
    vs_battle_inventoryWeapon* slot = _inventory->weapons;
    int index = 1;

    while (slot->blade != 0) {
        ++slot;
        if (++index == 8) {
            return 0;
        }
    }

    vs_battle_rMemzero(slot, sizeof *slot);

    slot->index = index;
    slot->blade = _copyBladeToInventory(&arg0->blade, index);
    slot->grip = _copyGripToInventory(&arg0->grip, index);

    for (i = 0; i < 3; i++) {
        if (arg0->gems[i].id != 0)
            slot->gems[i] = _copyGemToInventory(&arg0->gems[i], index);
    }

    vs_battle_rMemcpy(slot->name, arg0->name, sizeof slot->name);

    return index;
}

static int _copyArmorToInventory(vs_battle_inventoryArmor* source)
{
    int index = 1;
    vs_battle_inventoryArmor* armor = _inventory->armor;

    while (armor->id != 0) {
        ++armor;
        ++index;
        if (index == 16) {
            return 0;
        }
    }

    vs_battle_copyAligned(armor, source, sizeof *armor);

    armor->index = index;
    return index;
}

static int _copyShieldToInventory(vs_battle_lootedShield* arg0)
{
    int i;

    vs_battle_inventoryShield* shield = _inventory->shields;
    int index = 1;

    while (shield->base.id != 0) {
        ++shield;
        ++index;
        if (index == 8) {
            return 0;
        }
    }

    vs_battle_rMemzero(shield, sizeof *shield);
    vs_battle_copyAligned(&shield->base, &arg0->shield, sizeof shield->base);

    shield->base.bodyPart = index;

    for (i = 0; i < 3; ++i) {
        if (arg0->gems[i].id != 0) {
            shield->gems[i] = _copyGemToInventory(&arg0->gems[i], index | 0x80);
        }
    }

    return index;
}

static int _copyMiscToInventory(vs_battle_lootedMisc* arg0)
{
    int index = 1;
    vs_battle_inventoryMisc* item = _inventory->misc;

    while (item->id != 0) {
        ++index;
        ++item;
        if (index == 64) {
            return 0;
        }
    }

    item->id = arg0->id;
    item->count = arg0->count;
    return index;
}

static void _updateLootList(void)
{
    int i;
    int newOffset;
    _lootListItem* loot = _lootList;

    for (i = 0; i < _lootListCount; ++i, ++loot) {
        loot->state = vs_mainMenu_copyItem(loot->itemCategory, &vs_battle_inventory,
                          loot->itemIndex, _inventory)
                   != 0;
    }

    i = _selectedLoot + _lootListOffset;

    if (i >= _lootListCount) {
        i = _lootListCount - 1;
        _lootListOffset = _lootListCount - 8;
        _selectedLoot = 7;
    }

    if (_lootListCount < 9) {
        _selectedLoot = i;
        _lootListOffset = 0;
        return;
    }

    newOffset = _lootListCount - 8;
    if (newOffset < _lootListOffset) {
        _lootListOffset = newOffset;
        _selectedLoot = i - newOffset;
    }

    if ((_selectedLoot == 7) && (i != (_lootListCount - 1))) {
        _selectedLoot -= 1;
        _lootListOffset = _lootListOffset + 1;
    }
}

static void _addLootToList(int itemCategory, int itemIndex)
{
    _lootListItem* item = &_lootList[_lootListCount++];
    item->itemCategory = itemCategory;
    item->itemIndex = itemIndex - 1;
    item->unk2 = 0;
}

static char* _itemCategoryHeaders[] = { "WEAPON", "BLADE", "GRIP", "SHIELD", "ARMOR",
    "GEM", "MISC" };

static int _itemIncludesItemsInCategory(int arg0, _lootListItem* arg1)
{
    int i;
    vs_battle_inventoryShield* shield;
    vs_battle_inventoryWeapon* weapon;

    int category = arg1->itemCategory;
    int count = 0;

    switch (arg0) {
    case itemCategoryBlade:
    case itemCategoryGrip:
        count += category == itemCategoryWeapon;
        // Fallthrough

    case itemCategoryWeapon:
    case itemCategoryShield:
    case itemCategoryArmor:
    case itemCategoryMisc:
        count += category == arg0;
        break;

    case itemCategoryGem:
        count += category == itemCategoryGem;

        if (category == itemCategoryWeapon) {
            weapon = &_inventory->weapons[arg1->itemIndex];
            for (i = 0; i < _inventory->grips[weapon->grip - 1].gemSlots; ++i) {
                count += weapon->gems[i] != 0;
            }
        }

        if (category == itemCategoryShield) {
            shield = &_inventory->shields[arg1->itemIndex];
            for (i = 0; i < shield->base.gemSlots; ++i) {
                count += shield->gems[i] != 0;
            }
        }

        break;
    }
    return count;
}

void _displayInventoryCapacities(int edgeX)
{
    int itemCountPos;
    int buttonBgPos;
    int var_a2;
    int var_fp;
    int i;
    int y;
    _lootListItem* item;
    unsigned int xy;
    char* str;

    item = NULL;
    var_fp = 1;

    if (D_8010A6B7 != 0) {

        item = (_lootListItem*)1;

        if (D_8010A6B7 & 0xF) {

            var_fp = 0;
            item = &_lootList[_lootListOffset + D_8010A6B7 - 1];

            for (i = 0; i < _lootListCount; ++i) {
                var_fp += _lootList[i].state;
            }
        }
    }

    vs_battle_renderTextRaw("GADGET BAG", (edgeX + 176) | (12 << 16), NULL);

    itemCountPos = edgeX + 272;

    for (i = 0; i < 7; ++i) {
        int color = vs_getRGB(128, 128, 128);
        int capacity = vs_mainMenu_inventoryItemCapacities[i];
        int itemCount = vs_mainMenu_getItemCount(i, NULL);

        if (item != NULL) {
            color = vs_getRGB(64, 64, 64)
                 << ((item == (_lootListItem*)1)
                        || (_itemIncludesItemsInCategory(i, item) != 0));
        }

        y = (24 + i * 12) << 16;

        vs_battle_renderTextRawColor("/", itemCountPos | y, color, NULL);
        vs_battle_renderTextRawColor(
            _itemCategoryHeaders[i], (edgeX + 192) | y, color, NULL);
        vs_mainMenu_renderIntColor(capacity, (edgeX + 296) | y, color, NULL);

        if (((u_int)color >> 23) != 0) {

            if ((itemCount * 2) < capacity) {
                color = vs_getRGB(32, 64, 128);
            }

            if (((u_long)item >> 1) != 0) {
                if (capacity < (_itemIncludesItemsInCategory(i, item) + itemCount)) {
                    color = vs_getRGB(128, 64, 32);
                }
            }
        }

        vs_mainMenu_renderIntColor(itemCount, itemCountPos | y, color, NULL);
    }

    buttonBgPos = edgeX + 184;

    vs_mainMenu_drawButtonUiBackground(buttonBgPos, 112, 112, 10);
    vs_mainMenu_drawButtonUiBackground(buttonBgPos, 128, 64, 10);
    vs_battle_renderTextRawColor("GET", (edgeX + 196) | (112 << 16),
        vs_getRGB(64, 64, 64) << _controlsEnabled, NULL);
    vs_mainmenu_drawButton(2, edgeX + 176, 110, NULL);

    str = "ALL";
    xy = (edgeX + 252) | (112 << 16);

    if (var_fp != 0) {
        var_a2 = vs_getRGB(64, 64, 64) << (_controlsEnabled & 1);
    } else {
        var_a2 = vs_getRGB(64, 64, 64);
    }

    vs_battle_renderTextRawColor(str, xy, var_a2, NULL);
    vs_mainmenu_drawButton(1, edgeX + 232, 110, NULL);
    vs_battle_renderTextRawColor("END", (edgeX + 196) | (128 << 16),
        vs_getRGB(64, 64, 64) << _controlsEnabled, NULL);
    vs_mainmenu_drawButton(3, edgeX + 176, 126, NULL);
}

static int _droppableUnderCurrentDifficulty(int arg0)
{
    return arg0 & (vs_main_stateFlags.difficulty + 1);
}

void _applyLootList(vs_battle_loot* arg0)
{
    int i;

    if (_droppableUnderCurrentDifficulty(arg0->weapon.difficultyFlags) != 0) {
        _addLootToList(itemCategoryWeapon, _copyWeaponToInventory(&arg0->weapon));
    }

    if (_droppableUnderCurrentDifficulty(arg0->blade.difficultyFlags) != 0) {
        _addLootToList(itemCategoryBlade, _copyBladeToInventory(&arg0->blade.blade, 0));
    }

    if (_droppableUnderCurrentDifficulty(arg0->grip.difficultyFlags) != 0) {
        _addLootToList(itemCategoryGrip, _copyGripToInventory(&arg0->grip.grip, 0));
    }

    if (_droppableUnderCurrentDifficulty(arg0->shield.difficultyFlags) != 0) {
        _addLootToList(itemCategoryShield, _copyShieldToInventory(&arg0->shield));
    }

    for (i = 0; i < 2; ++i) {
        if (_droppableUnderCurrentDifficulty(arg0->armor[i].difficultyFlags) != 0) {
            _addLootToList(
                itemCategoryArmor, _copyArmorToInventory(&arg0->armor[i].armor));
        }
    }

    if (_droppableUnderCurrentDifficulty(arg0->accessory.difficultyFlags) != 0) {
        _addLootToList(
            itemCategoryArmor, _copyArmorToInventory(&arg0->accessory.accessory));
    }

    if (_droppableUnderCurrentDifficulty(arg0->gem.difficultyFlags) != 0) {
        _addLootToList(itemCategoryGem, _copyGemToInventory(&arg0->gem.gem, 0));
    }

    for (i = 0; i < 3; ++i) {
        if ((_droppableUnderCurrentDifficulty(arg0->misc[i].difficultyFlags) != 0)
            && (arg0->misc[i].id != 0) && (arg0->misc[i].count != 0)) {
            _addLootToList(itemCategoryMisc, _copyMiscToInventory(&arg0->misc[i]));
        }
    }

    _updateLootList();
}

static void _applyAllLootLists(vs_battle_lootListNode* node)
{
    vs_battle_rMemzero(_inventory, sizeof *_inventory);

    if (node != NULL) {
        while (node != NULL) {
            _applyLootList(&node->loot);
            node = node->next;
        }
    } else {
        _applyLootList(D_800EB9C8);
    }
}

static void _displayCurrentLoot(int x)
{
    char animationStateBuf[256];
    int i;
    int index;
    int temp_v1_3;
    vs_battle_menuItem_t* menuItem;

    int count = _lootListCount;
    _lootListItem* loot = &_lootList[_lootListOffset];

    vs_battle_rMemzero(&animationStateBuf, sizeof animationStateBuf);

    for (i = 0; i < 8; ++i) {
        menuItem = vs_battle_getMenuItem(i + 32);
        animationStateBuf[i + D_8010A504] = menuItem->animationState;
        menuItem->state = 0;
    }

    if (count > 8) {
        count = 8;
    }

    for (i = 0; i < count;) {
        index = loot->itemIndex;
        menuItem = vs_battle_getMenuItem(32 + i);

        switch (loot->itemCategory) {
        case itemCategoryWeapon: {
            vs_battle_inventoryWeapon* weapon = &_inventory->weapons[index];
            vs_battle_inventoryBlade* blade = &_inventory->blades[weapon->blade - 1];
            menuItem = vs_battle_setMenuItem(
                32 + i, 0x18 - x, 0x32 + i * 0x10, 0x98, 0, weapon->name);
            menuItem->icon = blade->category;
            menuItem->material = blade->material;
            break;
        }
        case itemCategoryBlade: {
            vs_battle_inventoryBlade* blade2 = &_inventory->blades[index];
            menuItem = vs_battle_setMenuItem(32 + i, 0x18 - x, 0x32 + i * 0x10, 0x98, 0,
                vs_mainMenu_itemNames[blade2->id]);
            menuItem->icon = blade2->category;
            menuItem->material = blade2->material;
            break;
        }
        case itemCategoryGrip: {
            vs_battle_inventoryGrip* grip = &_inventory->grips[index];
            menuItem = vs_battle_setMenuItem(32 + i, 0x18 - x, 0x32 + i * 0x10, 0x98, 0,
                vs_mainMenu_itemNames[grip->id]);
            menuItem->icon = grip->category + 10;
            break;
        }
        case itemCategoryShield: {
            vs_battle_inventoryShield* shield = &_inventory->shields[index];
            menuItem = vs_battle_setMenuItem(32 + i, 0x18 - x, 0x32 + i * 0x10, 0x98, 0,
                vs_mainMenu_itemNames[shield->base.id]);
            menuItem->icon = 0xF;
            menuItem->material = shield->base.material;
            break;
        }
        case itemCategoryArmor: {
            vs_battle_inventoryArmor* armor = &_inventory->armor[index];
            menuItem = vs_battle_setMenuItem(32 + i, 0x18 - x, 0x32 + i * 0x10, 0x98, 0,
                vs_mainMenu_itemNames[armor->id]);
            menuItem->icon = armor->category + 0xE;
            menuItem->material = armor->material;
            break;
        }
        case itemCategoryGem: {
            vs_battle_inventoryGem* gem = &_inventory->gems[index];
            menuItem = vs_battle_setMenuItem(32 + i, 0x18 - x, 0x32 + i * 0x10, 0x98, 0,
                vs_mainMenu_itemNames[gem->id]);
            menuItem->icon = 22;
            break;
        }
        case itemCategoryMisc: {
            vs_battle_inventoryMisc* misc = &_inventory->misc[index];
            menuItem = vs_battle_setMenuItem(32 + i, 0x18 - x, 0x32 + i * 0x10, 0x98, 0,
                vs_mainMenu_itemNames[misc->id]);
            menuItem->unk10 = misc->count;
            menuItem->fontColor = (misc->id < 0x1CA) ^ 1;
            break;
        }
        }

        menuItem->animationState = animationStateBuf[i + _lootListOffset];
        menuItem->unselectable = loot->state == 0;

        if (loot->unk2 != 0) {
            menuItem->x -= loot->unk2 * 48;
            ++loot->unk2;
            if (loot->unk2 == 4) {
                menuItem->animationState = 0;
            }
        }

        if (i == 0) {
            if (_lootListOffset != 0) {
                menuItem->fadeEffect = 1;
            }
        }

        if ((i == 7) && (_lootListOffset != (_lootListCount - 8))) {
            menuItem->fadeEffect = 2;
        }

        temp_v1_3 = loot->state;

        if (temp_v1_3 == 2) {
            menuItem->backgroundWidth = 0x18;
        }

        if (temp_v1_3 > 2) {
            menuItem->x += (temp_v1_3 - 3) * 7;
        }

        ++i;
        ++loot;
    }

    D_8010A504 = _lootListOffset;
}

static void _populateLootItem(int lootIndex)
{
    char* menuText[2];
    int rowType;
    int itemIndex = _lootList[lootIndex].itemIndex;

    vs_battle_memcpy(_inventoryBackup, &vs_battle_inventory, sizeof *_inventoryBackup);
    vs_battle_memcpy(&vs_battle_inventory, _inventory, sizeof vs_battle_inventory);

    switch (_lootList[lootIndex].itemCategory) {
    case itemCategoryWeapon:
        vs_mainMenu_initUiWeapon(&vs_battle_inventory.weapons[itemIndex], menuText,
            &rowType, vs_battle_stringBuf);
        break;

    case itemCategoryBlade:
        vs_mainMenu_setUiBlade(&vs_battle_inventory.blades[itemIndex], menuText, &rowType,
            vs_battle_stringBuf);
        break;

    case itemCategoryGrip:
        vs_mainMenu_setUiGrip(&vs_battle_inventory.grips[itemIndex], menuText, &rowType,
            vs_battle_stringBuf);
        break;

    case itemCategoryShield:
        vs_mainMenu_initUiShield(&vs_battle_inventory.shields[itemIndex], menuText,
            &rowType, vs_battle_stringBuf);
        break;

    case itemCategoryArmor:
        vs_mainMenu_initUiArmor(&vs_battle_inventory.armor[itemIndex], menuText, &rowType,
            vs_battle_stringBuf);
        break;

    case itemCategoryGem:
        vs_mainMenu_setUiGem(&vs_battle_inventory.gems[itemIndex], menuText, &rowType,
            vs_battle_stringBuf);
        break;

    case itemCategoryMisc:
        vs_mainMenu_setUiItem(&vs_battle_inventory.misc[itemIndex], menuText, &rowType,
            vs_battle_stringBuf);
        break;
    }

    vs_mainmenu_setInformationMessage(menuText[1]);
    vs_battle_memcpy(&vs_battle_inventory, _inventoryBackup, sizeof vs_battle_inventory);
}

int _discardItems(int init)
{
    static char cursorAnimStep = 0;

    static char state;
    static char D_8010A692;
    static char _ __attribute__((unused));
    static char* itemName;

    vs_battle_menuItem_t* menuItem;

    if (init != 0) {
        int i;

        D_8010A692 = 1;
        state = 0;

        if (_lootListCount == 0) {
            state = 4;
            return 0;
        }

        if ((D_8010A6B8 == 0) && (D_800EB9C8 != NULL)) {
            state = 5;
            return 0;
        }

        for (i = 0; i < _lootListCount; ++i) {
            if ((_lootList[i].itemCategory == itemCategoryMisc)
                && (_inventory->misc[_lootList[i].itemIndex].id > 457)) {
                itemName =
                    vs_mainMenu_itemNames[_inventory->misc[_lootList[i].itemIndex].id];
                state = 6;
            }
        }
        return 0;
    }

    switch (state) {
    case 0:
        menuItem = vs_battle_setMenuItem(
            30, 0x140, 0x92, 0x7E, 0, (char*)&_menuText[VS_menuText_OFFSET_optionYes]);
        menuItem->state = 2;
        menuItem->targetPosition0 = 0xC2;
        state = 1;
        break;

    case 1:
        menuItem = vs_battle_setMenuItem(
            31, 0x140, 0xA2, 0x7E, 0, (char*)&_menuText[VS_menuText_OFFSET_optionNo]);
        menuItem->state = 2;
        menuItem->targetPosition0 = 0xC2;

        vs_battle_initInformationTextBox(1);
        vs_mainmenu_setInformationMessage(
            D_8010A6B8 == 0 ? (char*)(&_menuText[VS_menuText_OFFSET_discardAllConfirm])
                            : (char*)(&_menuText[VS_menuText_OFFSET_itemsRemaining]));
        state = 2;
        break;

    case 2:
        state = (state + vs_mainmenu_ready());
        break;

    case 3:
        vs_battle_getMenuItem(30 + D_8010A692)->selected = 1;
        vs_battle_getMenuItem(31 - D_8010A692)->selected = 0;

        if (vs_main_buttonsPressed.all & (PADRright | PADRdown)) {

            vs_mainMenu_menuItemFlyoutRight(30);
            vs_mainMenu_menuItemFlyoutRight(31);

            if (vs_main_settings.information == 0) {
                vs_mainMenu_dismissTextBox();
            }

            if ((D_8010A692 == 0) && !(vs_main_buttonsPressed.all & PADRdown)) {
                int var_v1;
                vs_main_playSfxDefault(0x7E, 0x1C);
                var_v1 = 1;
                if (D_8010A6B8 == 0) {
                    var_v1 = 2;
                }
                return var_v1;
            }

            vs_battle_playMenuLeaveSfx();

            return -1;
        }

        if (vs_main_buttonRepeat & (PADLup | PADLdown)) {
            vs_battle_playMenuChangeSfx();
            D_8010A692 = (1 - D_8010A692);
        }

        cursorAnimStep = vs_battle_drawCursor(cursorAnimStep, D_8010A692 + 8);
        break;

    case 4:
    case 5:
        return state - 3;

    case 6:
        vs_battle_stringContext.strings[0] = itemName;

        vs_battle_initInformationTextBox(1);
        vs_mainmenu_setInformationMessage(
            (char*)&_menuText[VS_menuText_OFFSET_invalidDiscard]);

        state = 7;
        /* fallthrough */

    case 7:
        if (vs_main_buttonsPressed.pad[0].low != 0) {
            vs_battle_playMenuLeaveSfx();
            return -1;
        }
        break;
    }

    return 0;
}

static int _organizeInventory(_lootListItem* loot)
{
    static char cursorAnimState = 0;

    static char state;
    static char itemCategory;
    static char selectedRow;
    static char availableAction;

    vs_battle_menuItem_t* menuItem;

    if (loot != NULL) {
        vs_mainMenu_initTextBox();

        itemCategory = loot->itemCategory;
        state = 0;
        selectedRow = 0;
        availableAction = 0;

        if (itemCategory == itemCategoryWeapon) {
            availableAction = 1;
        } else if (itemCategory == itemCategoryShield) {
            availableAction = 1;
        } else if ((itemCategory == itemCategoryMisc)
                   && (_inventory->misc[loot->itemIndex].id < 458)) {
            availableAction = 2;
        } else {
            selectedRow = 1;
        }

        if (availableAction != 0) {
            menuItem = vs_battle_setMenuItem(30, 0x140, 0x92, 0x7E, 0,
                (char*)&_menuText[_menuText[(availableAction + 4) * 2]]);
            menuItem->state = 2;
            menuItem->targetPosition0 = 0xC2;
        }

        return 0;
    }

    switch (state) {
    case 0:
        menuItem = vs_battle_setMenuItem(31, 0x140, 0xA2, 0x7E, 0,
            (char*)&_menuText[VS_menuText_OFFSET_organizeInventory]);
        menuItem->state = 2;
        menuItem->targetPosition0 = 0xC2;
        state = 1;
        break;

    case 1:
        state += vs_mainmenu_ready();
        break;

    case 2:
        vs_battle_getMenuItem(30 + selectedRow)->selected = 1;
        vs_battle_getMenuItem(31 - selectedRow)->selected = 0;

        if (vs_main_buttonsPressed.all & (PADRright | PADRdown)) {

            vs_mainMenu_menuItemFlyoutRight(30);
            vs_mainMenu_menuItemFlyoutRight(31);

            if (vs_main_buttonsPressed.all & PADRdown) {
                vs_battle_playMenuLeaveSfx();
                return -1;
            }

            vs_battle_playMenuSelectSfx();

            if (selectedRow == 0) {
                selectedRow = availableAction + 1;
            }

            return selectedRow;
        }

        if (availableAction != 0) {
            if (vs_main_buttonRepeat & (PADLup | PADLdown)) {
                vs_battle_playMenuChangeSfx();
                selectedRow = 1 - selectedRow;
            }
        }

        if (selectedRow != 0) {
            vs_mainmenu_setInformationMessage(
                (char*)&_menuText[VS_menuText_OFFSET_organizeInventoryInfo]);
        } else if (availableAction == 1) {
            vs_mainmenu_setInformationMessage(
                (char*)&_menuText[VS_menuText_OFFSET_disassembleInfo]);
        } else {
            vs_mainmenu_setInformationMessage(
                (char*)&_menuText[VS_menuText_OFFSET_organizeInfo]);
        }

        cursorAnimState = vs_battle_drawCursor(cursorAnimState, selectedRow + 8);
        break;
    }
    return 0;
}

static void _setKeyFlag(int arg0);

int _processLootMenu(int init)
{
    static char D_8010A5EA = 0;

    static char state;
    static char D_8010A69D;

    _lootListItem* loot;
    int lootIndex;
    int temp_s2;
    int i;
    int var_v0_4;

    if (init != 0) {
        _selectedLoot = 0;
        state = 0;
        return 0;
    }

    switch (state) {
    case 0:
        if (vs_mainmenu_ready() == 0) {
            break;
        }

        vs_mainMenu_initTextBox();

        state = 1;
        // Fallthrough

    case 1:
        _controlsEnabled = 1;

        if (vs_main_buttonsPressed.all & PADRdown) {

            vs_battle_playMenuLeaveSfx();

            _controlsEnabled = 0;

            _discardItems(1);

            state = 2;
            break;

        } else if (vs_main_buttonsPressed.all & PADRleft) {

            temp_s2 = D_8010A6B8;

            for (i = 0; i < _lootListCount; ++i) {

                loot = &_lootList[i];

                if (vs_mainMenu_copyItem(loot->itemCategory | copyItemFlagsWrite,
                        &vs_battle_inventory, loot->itemIndex, _inventory)
                    != 0) {
                    if (loot->itemCategory == itemCategoryMisc) {

                        int miscId = _inventory->misc[loot->itemIndex].id;

                        if (miscId > 457) {
                            _setKeyFlag(miscId);
                        }
                    }

                    loot->unk2 = 1;
                    ++D_8010A6B8;
                }
            }

            if (temp_s2 != D_8010A6B8) {

                vs_main_playSfxDefault(0x7E, 0xD);

                state = 9;
                break;
            }

            vs_battle_playInvalidSfx();
        }

        lootIndex = _selectedLoot + _lootListOffset;
        loot = &_lootList[lootIndex];

        if (vs_main_buttonsPressed.all & PADRright) {
            if (loot->state == 0) {

                vs_battle_playMenuSelectSfx();

                _controlsEnabled = 0;

                _organizeInventory(loot);

                state = 3;
            } else {

                vs_main_playSfxDefault(0x7E, 0xD);

                if (loot->itemCategory == itemCategoryMisc) {

                    i = _inventory->misc[loot->itemIndex].id;

                    if (i > 457) {
                        _setKeyFlag(i);
                    }
                }

                vs_mainMenu_copyItem(loot->itemCategory | 0x10, &vs_battle_inventory,
                    loot->itemIndex, _inventory);

                loot->unk2 = 1;
                D_8010A69D = 3;
                ++D_8010A6B8;
                state = 9;
            }
        } else {
            i = lootIndex;

            if (vs_main_buttonRepeat & PADLup) {
                if (_lootListCount < 9) {
                    if (_selectedLoot == 0) {
                        _selectedLoot = _lootListCount - 1;
                    } else {
                        --_selectedLoot;
                    }
                } else {
                    if (_lootListOffset == 0) {
                        if (_selectedLoot == 0) {
                            if (vs_main_buttonsPressed.all & PADLup) {
                                _selectedLoot = 7;
                                _lootListOffset = _lootListCount - 8;
                            }
                        } else {
                            --_selectedLoot;
                        }
                    } else {
                        if (_selectedLoot == 1) {
                            --_lootListOffset;
                        } else {
                            --_selectedLoot;
                        }
                    }
                }
            }

            if (vs_main_buttonRepeat & PADLdown) {
                if (_lootListCount < 9) {
                    if (_selectedLoot == (_lootListCount - 1)) {
                        _selectedLoot = 0;
                    } else {
                        ++_selectedLoot;
                    }
                } else if (_lootListOffset == (_lootListCount - 8)) {
                    if (_selectedLoot == 7) {
                        if (vs_main_buttonsPressed.all & PADLdown) {
                            _selectedLoot = 0;
                            _lootListOffset = 0;
                        }
                    } else {
                        ++_selectedLoot;
                    }
                } else if (_selectedLoot == 6) {
                    ++_lootListOffset;
                } else {
                    ++_selectedLoot;
                }
            }

            if (i != (_selectedLoot + _lootListOffset)) {
                vs_battle_playMenuChangeSfx();
            }

            _populateLootItem(_selectedLoot + _lootListOffset);

            D_8010A5EA = vs_mainMenu_renderCursor(
                D_8010A5EA, (((_selectedLoot * 0x10) + 0x2A) << 0x10) | 0xA);
        }
        break;

    case 2:
        i = _discardItems(0);

        if (i != 0) {
            if (i < 0) {
                state = 8;
            } else {
                return i;
            }
        }
        break;

    case 3:
        i = _organizeInventory(NULL);

        if (i != 0) {

            if (i < 0) {
                state = 0;
                break;
            }

            temp_s2 = _selectedLoot + _lootListOffset;

            switch (i) {
            case 1:
                _topLevelMenuTransition(_lootList[temp_s2].itemCategory + 1);
                state = 4;
                break;

            case 2:
                disassembleItem(temp_s2 + 1);
                state = 5;
                break;

            case 3:
                _consolidateMiscItems(temp_s2 + 1);
                state = 6;
                break;
            }
        }

        break;

    case 4:
        var_v0_4 = _topLevelMenuTransition(0);
        if (var_v0_4 != 0) {
            state = 8;
        }
        break;

    case 5:
        var_v0_4 = disassembleItem(0);
        if (var_v0_4 != 0) {
            state = 8;
        }
        break;

    case 6:
        var_v0_4 = _consolidateMiscItems(0);
        if (var_v0_4 != 0) {
            state = 8;
        }
        break;

    case 7:
        if (vs_main_buttonsPressed.all == 0) {
            break;
        }
        // Fallthrough

    case 8:
        if (_lootLeftEdge == 0) {
            _controlsEnabled = 1;
            state = 0;
            _updateLootList();
        }
        break;

    case 9:
        if (D_8010A69D != 0) {
            D_8010A69D = (D_8010A69D - 1);
        } else {

            while (1) {
                for (i = 0; i < _lootListCount; ++i) {
                    if (_lootList[i].unk2 != 0) {
                        break;
                    }
                }

                if (i == _lootListCount) {
                    break;
                }

                --_lootListCount;
                for (; i < _lootListCount; ++i) {
                    _lootList[i] = _lootList[i + 1];
                }
            }

            _updateLootList();

            if (_lootListCount == 0) {

                _controlsEnabled = 0;

                _discardItems(1);

                state = 2;
            } else {
                state = 0;
            }
        }
        break;
    }

    D_8010A6B7 = (state & 7) == 1 ? _selectedLoot + 1 : -128;

    return 0;
}

int vs_menuB_exec(char* state)
{
    static char D_8010A69E;
    static char _ __attribute__((unused));

    int i;
    void* temp_v0;

    D_8010A6B7 = 0;

    switch (*state) {
    case 0:

        vs_battle_playSfx10();
        func_800FBD80(16);

        for (i = 0; i < 7; ++i) {
            vs_mainMenu_rebuildInventory(i);
        }

        temp_v0 = vs_main_allocHeapR(0x2300);

        _inventory = temp_v0;
        _inventoryBackup = temp_v0 + sizeof *_inventory;
        _lootList = temp_v0 + sizeof *_inventory + sizeof *_inventoryBackup;
        D_8010A6A4 = temp_v0 + 0x2080;
        D_8010A6B8 = 0;
        _lootListCount = 0;
        _lootListOffset = 0;
        D_8010A69E = 0;

        vs_mainMenu_loadItemNames(1);
        _applyAllLootLists(D_800EB9C4);

        _controlsEnabled = 0;
        D_8010A6B0 = 1;
        _inventoryCapacityFlyinTimer = 10;
        D_8010A6B2 = 0;
        _lootLeftEdge = 10;
        *state = 1;
        break;

    case 1:
        if (vs_mainMenu_loadItemNames(0) != 0) {

            D_8010A6B2 = 1;

            if (_lootListCount == 0) {

                vs_battle_initInformationTextBox(1);
                vs_mainmenu_setInformationMessage(
                    (char*)&_menuText[VS_menuText_OFFSET_emptyChest]);

                *state = 4;

            } else {
                vs_mainMenu_initTextBox();
                *state = 2;
            }
        }
        break;

    case 2:
        if (vs_mainmenu_ready() == 0) {
            break;
        }

        if (_lootLeftEdge != 0) {
            break;
        }

        _processLootMenu(1);

        *state = 3;
        // Fallthrough

    case 3:
        i = _processLootMenu(0);
        if (i != 0) {
            D_800F4E98.unk2 = i == 1;
            *state = 5;
        }
        break;

    case 4:
        if ((vs_battle_textBoxes[7].unk0.done)
            && (vs_main_buttonsPressed.pad[0].low != 0)) {
            *state = 5;
        }
        break;

    case 5:
        D_8010A6B0 = 0;
        D_8010A6B2 = 0;

        if ((vs_battle_dismissTextBox(7) != 0)
            || (vs_mainMenu_ensureItemNamesLoaded() == 0)) {
            break;
        }

        vs_main_freeHeapR(_inventory);

        if (D_800EB9C4 != 0) {
            func_8008A6FC();
        }

        *state = 0;
        return 1;
    }

    if (D_8010A6B0 != 0) {
        if (_inventoryCapacityFlyinTimer != 0) {
            --_inventoryCapacityFlyinTimer;
        }
        i = vs_battle_rowAnimationSteps[_inventoryCapacityFlyinTimer];
    } else {
        if (_inventoryCapacityFlyinTimer < 10) {
            ++_inventoryCapacityFlyinTimer;
        }
        i = _inventoryCapacityFlyinTimer << 5;
    }

    if (_inventoryCapacityFlyinTimer < 10) {
        _displayInventoryCapacities(i);
    }

    if (D_8010A6B2 != 0) {
        if (_lootLeftEdge != 0) {
            --_lootLeftEdge;
        }
        i = vs_battle_rowAnimationSteps[_lootLeftEdge];
    } else {
        if (_lootLeftEdge < 10) {
            ++_lootLeftEdge;
        }
        i = _lootLeftEdge << 5;
    }

    if (_lootLeftEdge < 10) {

        _displayCurrentLoot(i);

        if (D_8010A6B7 & 0xF) {
            vs_battle_getMenuItem(D_8010A6B7 + 0x1F)->selected = 1;
        }
    }

    return 0;
}

static void _setKeyFlag(int arg0)
{
    if (arg0 > 457) {
        vs_battle_setStateFlag(arg0 + 438, 1);
    }
}
