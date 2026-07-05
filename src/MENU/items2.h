#include "src/SLUS_010.40/main.h"
#include "src/BATTLE/BATTLE.PRG/func_8006B57C_t.h"
#include "src/MENU/MAINMENU.PRG/C48.h"
#include "src/MENU/MAINMENU.PRG/2D10.h"

/**
 * Finds the weapon from the specified blade, grip, or gem.
 *
 * @return 0 if no parent weapon exists.
 */
static int _getParentWeaponIndex(int itemCategory, int index)
{
    int parentIndex = 0;

    if (itemCategory == itemCategoryBlade) {
        parentIndex = vs_main_inventory.blades[index].assembledWeaponIndex;
    }

    if (itemCategory == itemCategoryGrip) {
        parentIndex = vs_main_inventory.grips[index].assembledWeaponIndex;
    }

    if (itemCategory == itemCategoryGem) {
        parentIndex = vs_main_inventory.gems[index].setItemIndex;
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

        index = vs_main_inventory.gems[itemIndex].setItemIndex;

        if (!(index & gemTargetShield)) {
            index = 0;
        }
    }

    return index & 0x7F;
}

/**
 * Sets the text and rowtypes for the specified category.
 * Maps skills to misc items if selected.
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
            vs_mainMenu_setWeaponRowFromInventory(&vs_main_inventory.weapons[index],
                &menuText[count * 2], &rowTypes[i], textBuf);

            if (vs_main_inventory.weapons[index].isEquipped != 0) {
                rowType = 0xCA00;
            }
            break;

        case itemCategoryBlade:
            vs_mainMenu_setBladeRow(&vs_main_inventory.blades[index],
                &menuText[count * 2], &rowTypes[i], textBuf);
            break;

        case itemCategoryGrip:
            vs_mainMenu_setGripRow(&vs_main_inventory.grips[index], &menuText[count * 2],
                &rowTypes[i], textBuf);
            break;

        case itemCategoryShield:
            vs_mainMenu_setShieldRowFromInventory(&vs_main_inventory.shields[index],
                &menuText[count * 2], &rowTypes[i], textBuf);

            if (vs_main_inventory.shields[index].isEquipped != 0) {
                rowType = 0xCA00;
            }
            break;

        case itemCategoryArmor:
            vs_mainMenu_setArmorRowFromInventory(&vs_main_inventory.armor[index],
                &menuText[count * 2], &rowTypes[i], textBuf);

            if (vs_main_inventory.armor[index].limb != 0) {
                rowType = 0xCA00;
            }
            break;

        case itemCategoryGem:
            vs_mainMenu_setGemRow(&vs_main_inventory.gems[index], &menuText[count * 2],
                &rowTypes[i], textBuf);
            break;

        case itemCategoryMisc: {
            u_int skillId;
            vs_mainMenu_setMiscRow(&vs_main_inventory.misc[index], &menuText[count * 2],
                &rowTypes[i], textBuf);
#ifdef _ITEMMENU
            skillId =
                vs_mainMenu_miscItemToSkillMap[vs_main_inventory.misc[index].id - 323];

            if ((skillId - 106) < 28) {
                int j;
                for (j = 0; j < 3; ++j) {
                    if (vs_main_skills[skillId].unlocked) {
                        ++skillId;
                    }
                }
            }

            _miscSkills[count] = skillId;
#endif
            break;
        }
        }

        parentItem = _getParentWeaponIndex(itemCategory, index);

        if (parentItem != 0) {
            rowType = 0xCA00;
            if (vs_main_inventory.weapons[parentItem - 1].isEquipped == 0) {
                rowType = 0xCC00;
            }
        }

        parentItem = _getParentShieldIndex(itemCategory, index);

        if (parentItem != 0) {
            rowType = 0xCA00;
            if (vs_main_inventory.shields[parentItem - 1].isEquipped == 0) {
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
static int _itemNavigation(int initialize)
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
    static char _ignoreCursorMemory;
    static char _ __attribute__((unused));
    static int selectedRow;

#ifdef _ITEMMENU
    char** menuText;
    int* rowTypes;
    char** sp310;
#else
    char* menuText[128];
    int rowTypes[64];
    char* sp310[128];
#endif
    int rowCount;
    char* indices;
    int i;
    u_char itemCategory;
    int var_a1_2;
    int row;
    int index;

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
        _ignoreCursorMemory = initialize & 1;

        if (_ignoreCursorMemory) {
            if (vs_main_settings.cursorMemory == 0) {
                memset(&D_800F4EE8.unk3A, 0, sizeof D_800F4EE8.unk3A);
            }
        }

        state = init;
        return 0;
    }

    itemCategory = (D_800F4EE8.unk3A.currentItemCategory - 1) & 7;
    indices = vs_mainMenu_inventoryIndices[itemCategory];

    switch (state) {
    case none:
    case init: {
#ifdef _ITEMMENU
        void* textBuf = vs_main_allocHeapR(72 * 96);
        rowTypes = textBuf + 0x1800;
        menuText = textBuf + 0x1900;
#else
        void* textBuf = vs_main_allocHeapR(64 * 96);
#endif

        D_801023E3 = 1;

        for (i = 0; i < 7; ++i) {
            vs_mainMenu_rebuildInventory(i);
        }

        if (itemCategory == itemCategoryManage) {
#ifdef _ITEMMENU
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
#else
            for (i = 0; i < 4; ++i) {
                menuText[i] = (char*)&_menuText[_menuText[VS_menuText_INDEX_equip + i]];
                rowTypes[i] = 1;
            }
#endif
            rowCount = 2;
        } else {
            rowCount = _populateItemRows(itemCategory, menuText, rowTypes, textBuf);
        }

#ifdef _ITEMMENU
        if (D_800F4EA0 & 7) {
            for (i = 0; i < 64; ++i) {
                rowTypes[i] |= 1;
            }
        }
#endif

        noItems = rowCount == 0;

        if (noItems) {
            vs_mainmenu_setInformationMessage(
                (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_noItemsInCategory]);
        } else {

            i = vs_main_settings.cursorMemory;

            if (_ignoreCursorMemory) {
                _ignoreCursorMemory = 0;
            } else {
                vs_main_settings.cursorMemory = 1;
            }

            var_a1_2 = itemCategory + 30;

            if (itemCategory == itemCategoryManage) {
                var_a1_2 |= 0x200;
            } else {
                var_a1_2 |= 0x19200;
            }

            vs_mainmenu_setMenuRows(rowCount, var_a1_2, menuText, rowTypes);

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

#ifdef _ITEMMENU
            if (!(D_800F4EA0 & 7)) {
                u_int rowCount = itemCategory;
                rowCount = rowCount < itemCategoryMisc;
                _statusCommandState = rowCount + 1;
            }
#else
            int offset;
            rowCount = itemCategory < itemCategoryMisc;
            _statusCommandState = rowCount + 1;
#endif

            selectedRow = vs_mainmenu_getSelectedRow() + 1;

#ifdef _ITEMMENU
#define offset 1
#else
            offset = 1;
#endif

            if (selectedRow == 0) {
                if (vs_main_buttonsPressed.all & PADRleft) {
#ifdef _ITEMMENU
                    if ((_statusCommandState >= 2) && vs_mainmenu_ready()) {
#else
                    if ((rowCount != 0) && (vs_mainmenu_ready())) {
#endif

                        vs_battle_playMenuSelectSfx();

                        row = func_80100814();

                        vs_battle_getMenuItem(row >> 8)->outsetIcon = 0;
                        _itemStatusDispatcher(itemCategory | ((row + offset) << 4));
#undef offset
                        _secondaryTitleEnabled = 0;
                        state = 7;
                        break;
                    }

                    vs_battle_playInvalidSfx();
                }
            } else {
                void* textBuf;
#ifdef _ITEMMENU
                int* rowTypes;
#else
                int rowTypes[64];
#endif
                int count;

                if ((selectedRow <= 0) || (itemCategory == itemCategoryManage)) {
                    return selectedRow;
                }

#ifdef _ITEMMENU
                textBuf = vs_main_allocHeapR(72 * 96);
                sp310 = textBuf + 0x1900;
                rowTypes = textBuf + 0x1800;
#else
                textBuf = vs_main_allocHeapR(64 * 96);
#endif

                count = _populateItemRows(itemCategory, sp310, rowTypes, textBuf);

                rowTypes[selectedRow - 1] |= 8;
                i = vs_main_settings.cursorMemory;
                vs_main_settings.cursorMemory = 1;

                vs_mainmenu_setMenuRows(
                    count, (itemCategory + 30) | 0x19200, sp310, rowTypes);

                vs_main_settings.cursorMemory = i;

                _restoreItemMenu(itemCategory);

                _statusCommandState = 1;
                D_801023E3 = 0;

                vs_main_freeHeapR(textBuf);

                state = 6;
                break;
            }
        }
        // Fallthrough

    case 3: {
        int moveBack;

        i = vs_main_buttonsState & (PADL1 | PADLleft);
        rowCount = vs_main_buttonsState & (PADR1 | PADLright);
        moveBack = i != 0;

        if (rowCount != 0) {
            row = moveBack ^ 1;
        } else {
            row = moveBack & 1;
        }

        if (row != 0) {

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

        if ((state == 3) && vs_mainmenu_ready()) {
            if ((vs_main_buttonsState & (PADL1 | PADR1 | PADLleft | PADLright)) && row) {
                break;
            }

            state = init;

#ifdef _ITEMMENU
            initialize = 0;
            goto loop_1;
#else
            return _itemNavigation(0);
#endif
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

        state = waitInit;
    }
        /* fallthrough */

    case waitInit:
        if (vs_mainmenu_ready()) {
            state = init;
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

        rowCount = selectedRow;

        if (rowCount == i) {
            state = populateActions;
            break;
        }

        if (i > 0) {

            row = indices[i - 1];
            var_a1_2 = indices[rowCount - 1];

            if ((itemCategory == itemCategoryMisc)
                && (vs_main_inventory.misc[row - 1].id
                    == vs_main_inventory.misc[var_a1_2 - 1].id)) {

                vs_main_inventory.misc[var_a1_2 - 1].count +=
                    vs_main_inventory.misc[row - 1].count;

                if (vs_main_inventory.misc[var_a1_2 - 1].count > 100) {
                    vs_main_inventory.misc[row - 1].count =
                        vs_main_inventory.misc[var_a1_2 - 1].count - 100;
                    vs_main_inventory.misc[var_a1_2 - 1].count = 100;
                } else {
#ifdef _ITEMMENU
                    vs_mainMenu_initItem(itemCategoryMisc, row);
#else
                    vs_mainMenu_initItem(itemCategoryMisc, var_a1_2);
#endif
                }
            } else {
                indices[i - 1] = var_a1_2;
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
        break;

    case viewDetails:
        i = _itemStatusDispatcher(0);

        if (i == 0) {
            break;
        }

        if (i == -2) {
            return -2;
        }

        _secondaryTitleEnabled = 1;

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

    case populateActions: {
#ifdef _ITEMMENU
        char* sp310[12];
#endif
        int rowType;

        rowCount = 0;
        index = indices[selectedRow - 1] - 1;

#ifdef _ITEMMENU
        vs_battle_rMemzero(vs_battle_rowTypeBuf, sizeof(int) * 6);

        if (itemCategory == itemCategoryMisc) {

            sp310[0] = (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_useItem];
            sp310[1] = (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_useItemDesc];

            if (vs_main_inventory.misc[index].id > 457) {
                *vs_battle_rowTypeBuf = 1;
                sp310[1] = (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_cannotUse];
            } else if (vs_battle_getSkillFlags(0, _miscSkills[selectedRow - 1]) & 2) {
                *vs_battle_rowTypeBuf = 1;
                sp310[1] = (char*)&_menuText[VS_menuText_OFFSET_insufficientMp];
            }

            ++rowCount;
            availableActions[rowCount] = 1;
        }

        if (((char)(itemCategory - 1) < 2) || (itemCategory == itemCategoryGem)) {

            int var_s2 = itemCategory & 0xFF;
            sp310[rowCount * 2] =
                (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_searchItem];
            sp310[rowCount * 2 + 1] =
                (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_searchItemDesc];

            if ((_getParentWeaponIndex(var_s2, index) == 0)
                && (_getParentShieldIndex(var_s2, index) == 0)) {
                sp310[rowCount * 2 + 1] =
                    (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_invalidSearch];
                vs_battle_rowTypeBuf[rowCount] = 1;
            }

            ++rowCount;
            availableActions[rowCount] = 2;
        }
#else
        vs_battle_rMemzero(vs_battle_rowTypeBuf, sizeof(int) * 5);

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
#endif

        rowType = 0;
        sp310[rowCount * 2] =
            (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_discardItem];
        sp310[rowCount * 2 + 1] =
            (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_discardItemDesc];

        switch (itemCategory) {
        case itemCategoryWeapon:
            rowType = vs_main_inventory.weapons[index].isEquipped != 0;
            break;
        case itemCategoryShield:
            rowType = vs_main_inventory.shields[index].isEquipped != 0;
            break;
        case itemCategoryArmor:
            rowType = vs_main_inventory.armor[index].limb != 0;
            break;
        case itemCategoryMisc:
            if (vs_main_inventory.misc[index].id > 457) {
                rowType = 3;
            }
            break;
        }

        var_a1_2 = _getParentWeaponIndex(itemCategory, index);

        if (var_a1_2 != 0) {
            rowType = 1;
            if (vs_main_inventory.weapons[var_a1_2 - 1].isEquipped == 0) {
                rowType = 2;
            }
        }

        var_a1_2 = _getParentShieldIndex(itemCategory, index);

        if (var_a1_2 != 0) {
            rowType = 1;
            if (vs_main_inventory.shields[var_a1_2 - 1].isEquipped == 0) {
                rowType = 2;
            }
        }

        if (rowType != 0) {
            sp310[rowCount * 2 + 1] = (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp
                    [rowType + VS_ITEMHELP_BIN_INDEX_cannotDiscardEquipped - 1]];
            rowType = 1;
        }

        vs_battle_rowTypeBuf[rowCount] = rowType;
        ++rowCount;
        availableActions[rowCount] = discardItem;

        if (itemCategory == itemCategoryMisc) {

            sp310[rowCount * 2] =
                (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_discardAll];
            sp310[rowCount * 2 + 1] =
                (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_discardAllDesc];

            if (vs_main_inventory.misc[index].id > 457) {
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

        vs_mainMenu_addMenuActions(rowCount, itemCategory + 38, sp310, vs_battle_rowTypeBuf);

        state = processAction;
        break;
    }

    case processAction:
#ifdef _ITEMMENU
        vs_mainMenu_printInformation(vs_mainMenu_getSelectedAction(), vs_mainMenu_actionMenuState);
#else
        row = vs_mainMenu_getSelectedAction();
        vs_mainMenu_printInformation(row, vs_mainMenu_actionMenuState);
#define index i
#endif

        vs_mainMenu_renderItemActionMenu();
        index = vs_mainMenu_actionInputProcessed() + 1;

        if (index != 0) {

#ifdef _ITEMMENU
            vs_mainMenu_flyoutLeftExcept(0x28);
#endif

            if (index > 0) {

                vs_battle_playMenuSelectSfx();

#ifndef _ITEMMENU
                vs_mainMenu_flyoutLeftExcept(0x28);
#endif

                switch (availableActions[index]) {
#ifdef _ITEMMENU
                case useItem:
                    vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);

                    D_800F5210 = indices[selectedRow - 1] - 1;
                    D_800F4E98.executeAbility.s16[0] =
                        (short)_miscSkills[selectedRow - 1];
                    D_800F4E98.executeAbility.s16[1] =
                        (short)vs_main_inventory.misc[D_800F5210].id;

                    return 3;

#endif
                case searchItem:
                    vs_mainMenu_initInformationBox();
                    vs_mainMenu_clearMenuExcept(3);

                    state = search;
                    break;

                case discardItem:
                    rowCount = indices[selectedRow - 1] | (itemCategory << 8);

                    if ((itemCategory == itemCategoryMisc)
                        && (vs_main_inventory.misc[indices[selectedRow - 1] - 1].count
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
                    vs_mainMenu_initInformationBox();
                    _sortItems(itemCategory + 1);

                    state = sort;
                    break;
                }
            } else {

                vs_battle_playMenuLeaveSfx();

#ifndef _ITEMMENU
                vs_mainMenu_flyoutLeftExcept(0x28);
#endif

                if (index == -2) {
                    vs_mainMenu_clearMenuExcept(3);

                    return -2;
                }

                vs_mainMenu_initInformationBox();

                state = none;
            }
        }

#undef index

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

            vs_mainMenu_initInformationBox();
            vs_mainMenu_flyoutLeftExcept(40);
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