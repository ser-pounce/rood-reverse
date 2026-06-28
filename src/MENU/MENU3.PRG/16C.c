#include "16C.h"
#include "68C4.h"
#include "src/SLUS_010.40/31724.h"
#include "src/BATTLE/BATTLE.PRG/2842C.h"
#include "src/BATTLE/BATTLE.PRG/30D14.h"
#include "src/BATTLE/BATTLE.PRG/3A1A0.h"
#include "src/BATTLE/BATTLE.PRG/44F14.h"
#include "src/BATTLE/BATTLE.PRG/5BF94.h"
#include "src/MENU/MAINMENU.PRG/278.h"
#include "build/assets/MENU/MENU3.PRG/menuText.h"
#include <memory.h>

#define _ITEMMENU

extern void* D_1F800000[];

#include "src/MENU/_toggleUi.h"
#include "src/MENU/items0.h"
#include "src/MENU/items1.h"

static char _miscSkills[64];

#include "src/MENU/items2.h"

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
            if (index && (vs_battle_inventory.armor[index - 1].limb == 7)) {
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
            if (vs_battle_inventory.armor[i].limb == 7) {
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

                    if (index && (vs_battle_inventory.armor[index - 1].limb == 7)) {

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
                    && (vs_battle_inventory.armor[index - 1].limb == 0)) {

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
                vs_battle_inventory.armor[equippedAccessory - 1].limb = 0;
            }

            if (selectedAccessory != 1) {
                vs_battle_inventoryArmor* armor =
                    &vs_battle_inventory.armor[_equippedItem - 1];
                armor->limb = 7;

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
                && (vs_battle_inventory.armor[index - 1].limb == initBodyPart)) {
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
            if (vs_battle_inventory.armor[i].limb == bodyPart) {
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
                        && (vs_battle_inventory.armor[index - 1].limb == bodyPart)) {

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
                    && (vs_battle_inventory.armor[index - 1].limb == 0)) {

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
                vs_battle_inventory.armor[armorIndex - 1].limb = 0;
            }
            if (selectedArmor == 1) {
                vs_battle_equipArmor(bodyPart - 1, NULL);
            } else {
                vs_battle_inventoryArmor* armor =
                    &vs_battle_inventory.armor[_equippedItem - 1];
                armor->limb = bodyPart;

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
                if (((i != 7) + armor->limb) == i) {
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

#include "src/MENU/_renderAshley.h"

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
        _itemNavigation(D_80109649 + 1);

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
        row = _itemNavigation(0);

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

            _itemNavigation(1);

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
            _itemNavigation(1);

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

        int category = (D_800F4EE8.unk3A.currentItemCategory - 1) & 7;

        vs_battle_menuItem_t* menuitem = vs_battle_setMenuItem(
            31, row + 180, 34, 140, 8, (char*)&_menuText[_menuText[category]]);
        menuitem->selected = 1;

        if (category != 7) {
            menuitem->unk12 = vs_mainMenu_inventoryItemCapacities[category];
            menuitem->count = vs_mainMenu_getItemCount(category, 0);
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

    _renderItemCategory(_itemCategoryIconsAnimationStep, _selectedItemCategoryIconOnTop);

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
