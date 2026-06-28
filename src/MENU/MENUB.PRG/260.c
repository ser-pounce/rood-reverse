#include "260.h"
#include "src/BATTLE/BATTLE.PRG/146C.h"
#include "src/BATTLE/BATTLE.PRG/30D14.h"
#include "src/BATTLE/BATTLE.PRG/3A1A0.h"
#include "src/BATTLE/BATTLE.PRG/4A0A8.h"
#include "src/BATTLE/BATTLE.PRG/5BF94.h"
#include "src/MENU/MAINMENU.PRG/278.h"
#include "build/assets/MENU/MENUB.PRG/menuText.h"
#include "build/assets/BATTLE/BATTLE.PRG/menuStrings.h"
#include <stddef.h>
#include <memory.h>

#include "src/MENU/items0.h"

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

static char _animationStateBufIndex = 0;
static char _controlsEnabled = 0;

static _lootListItem* _lootList;
static _lootListItem* _lootListWorkingCopy;
static vs_main_inventory_t* _inventory;
static vs_main_inventory_t* _inventoryBackup;
static char _showInventory;
static u_char _inventoryCapacityFlyinTimer;
static char _showLoot;
static u_char _lootLeftEdge;
static char _selectedLoot;
static u_char _lootListOffset;
static u_char _lootListCount;
static char D_8010A6B7;
static char _lootClaimed;

#include "src/MENU/items1.h"
#include "src/MENU/_toggleUi.h"
#include "src/MENU/items2.h"
#include "src/MENU/_renderAshley.h"

static int _topLevelMenuTransition(int category)
{
    enum state { init };

    static char state;
    static char D_8010A681;

    int stepValue;
    vs_battle_menuItem_t* menuItem;

    if (category != 0) {
        D_800F4EE8.unk3A.currentItemCategory = category;
        _showInventory = 0;
        _showLoot = 0;
        state = init;
        return 0;
    }

    switch (state) {
    case init:
        if (!vs_mainmenu_ready()) {
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
        _toggleMenuUi(0);

        _secondaryTitleAnimationStep = 0;
        _itemCategoryIconsAnimationStep = 0;
        _statusCommandAnimationStep = 0;
        _selectedItemCategoryIconOnTop = 0;

        if (!vs_mainmenu_ready()) {
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

        _toggleMenuUi(0);
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
            _showInventory = 1;
            _showLoot = 1;
            return 1;
        }

        break;
    }

    if (_secondaryTitleEnabled != 0) {
        if (_secondaryTitleAnimationStep < 10) {
            ++_secondaryTitleAnimationStep;
        }
        stepValue = vs_battle_rowAnimationSteps[10 - _secondaryTitleAnimationStep];
    } else {
        if (_secondaryTitleAnimationStep != 0) {
            --_secondaryTitleAnimationStep;
        }
        stepValue = (10 - _secondaryTitleAnimationStep) << 5;
    }

    if ((_secondaryTitleAnimationStep != 0) && (_selectedItemCategoryIconOnTop == 0)) {

        int itemCategory = (D_800F4EE8.unk3A.currentItemCategory - 1) & 7;

        vs_battle_menuItem_t* menuItem =
            vs_battle_setMenuItem(31, stepValue + 180, 34, 140, 8,
                (char*)&_menuText[_menuText[itemCategory + VS_menuText_INDEX_weapons]]);
        menuItem->selected = 1;

        if (itemCategory != 7) {
            menuItem->unk12 = vs_mainMenu_inventoryItemCapacities[itemCategory];
            menuItem->count = vs_mainMenu_getItemCount(itemCategory, NULL);
        }
    }

    _renderAshley(0);

    if (_itemCategoryIconsEnabled != 0) {
        if (_itemCategoryIconsAnimationStep < 4) {
            ++_itemCategoryIconsAnimationStep;
        }
    } else if (_itemCategoryIconsAnimationStep != 0) {
        --_itemCategoryIconsAnimationStep;
    }

    _renderItemCategory(_itemCategoryIconsAnimationStep, _selectedItemCategoryIconOnTop);

    if (_statusCommandState != 0) {
        if (_statusCommandAnimationStep < 10) {
            ++_statusCommandAnimationStep;
        }
        stepValue = vs_battle_rowAnimationSteps[10 - _statusCommandAnimationStep];
    } else {
        if (_statusCommandAnimationStep != 0) {
            --_statusCommandAnimationStep;
        }
        stepValue = (10 - _statusCommandAnimationStep) << 5;
    }

    if (_statusCommandAnimationStep != 0) {
        vs_mainMenu_drawButtonUiBackground(0x10 - stepValue, 0x26, 0x58, 10);
        vs_mainmenu_drawButton(1, 8 - stepValue, 0x24, NULL);
        vs_battle_renderTextRawColor("STATUS", ((0x1C - stepValue) & 0xFFFF) | 0x260000,
            0x202020 << _statusCommandState, NULL);
    }

    return 0;
}

static void _updateLootList(void);

static int _disassembleItem(int itemIndex)
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
    static char lootCount;
    static u_char targetItemIndex;
    static char disassembleItemCategory;
    static char _ __attribute__((unused));

    int i;
    vs_battle_menuItem_t* menuItem;

    if (itemIndex != 0) {

        vs_battle_memcpy(
            _lootListWorkingCopy, _lootList, 160 * sizeof *_lootListWorkingCopy);

        _showLoot = 0;
        lootCount = _lootListCount;
        targetItemIndex = itemIndex - 1;
        disassembleItemCategory = _lootList[targetItemIndex].itemCategory;
        _selectedLoot = 0;
        _lootListOffset = 0;
        D_8010A683 = 0;
        state = init;

        return 0;
    }

    i = _lootListWorkingCopy[targetItemIndex].itemIndex;

    switch (state) {
    case init:
        if (_lootLeftEdge != 6) {
            break;
        }

        vs_battle_rMemzero(_lootList, 0x280);

        _lootList->itemCategory = _lootListWorkingCopy[targetItemIndex].itemCategory;
        _lootList->itemIndex = i;
        _lootList->state = lootStateNoIndent;

        if (disassembleItemCategory != itemCategoryWeapon) {

            vs_main_inventoryShield* shield = &_inventory->shields[i];
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
            vs_main_inventoryWeapon* weapon = &_inventory->weapons[i];
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
        _showLoot = 1;
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
        vs_battle_getMenuItem(30 + D_8010A683)->selected = 1;
        vs_battle_getMenuItem(31 - D_8010A683)->selected = 0;

        if (vs_main_buttonsPressed.all & (PADRright | PADRdown)) {
            vs_mainMenu_menuItemFlyoutRight(30);
            vs_mainMenu_menuItemFlyoutRight(31);
            _showLoot = 0;
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

        vs_battle_rMemcpy(&_lootListWorkingCopy[lootCount], &_lootList[1],
            (_lootListCount - 1) * sizeof _lootList[1]);

        if (disassembleItemCategory != itemCategoryWeapon) {
            vs_main_inventoryShield* shield = &_inventory->shields[i];
            for (i = 0; i < shield->base.gemSlots; ++i) {
                int gem = shield->gems[i];
                if (gem != 0) {
                    shield->gems[i] = 0;
                    _inventory->gems[gem - 1].setItemIndex = 0;
                }
            }
        } else {
            vs_main_inventoryWeapon* weapon = &_inventory->weapons[i];
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

        lootCount = _lootListCount + (lootCount + 254);

        for (i = targetItemIndex; i < lootCount; ++i) {
            _lootListWorkingCopy[i] = _lootListWorkingCopy[i + 1];
        }
        // Fallthrough

    case finalize:
        if (_lootLeftEdge != 6) {
            break;
        }

        _lootListCount = lootCount;

        vs_battle_memcpy(
            _lootList, _lootListWorkingCopy, 160 * sizeof *_lootListWorkingCopy);
        _updateLootList();

        _lootLeftEdge = 10;
        _showLoot = 1;
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
    static char cursorMemory = 0;

    static u_short totalCount;
    static u_short amountToAdd;
    static u_short itemId;
    static char state;
    static char D_8010A68F;
    static u_char lootCount;

    _lootListItem* loot;
    int i;
    int j;
    int var_v0;
    vs_main_inventoryMisc* item;
    vs_battle_menuItem_t* menuItem;

    if (lootIndex != 0) {

        vs_battle_memcpy(
            _lootListWorkingCopy, _lootList, 160 * sizeof *_lootListWorkingCopy);
        vs_battle_memcpy(_inventoryBackup, _inventory, sizeof *_inventory);

        _showLoot = 0;
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

            amountToAdd = 0;
            item = vs_main_inventory.misc;

            for (i = 0; i < 64; ++i, ++item) {
                if (item->id == itemId) {
                    int v0 = amountToAdd + 100;
                    v0 -= item->count;
                    amountToAdd = v0;
                }
            }

            totalCount = 0;

            for (i = 0; i < _lootListCount; ++i) {
                if (_lootList[i].itemCategory == itemCategoryMisc) {
                    item = &_inventory->misc[_lootList[i].itemIndex];
                    if (item->id == itemId) {

                        totalCount += item->count;

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

            while (totalCount != 0) {

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
                loot->state = amountToAdd != 0;

                if (loot->state != lootStateNone) {
                    if (amountToAdd > 100) {
                        _inventory->misc[i].count = 100;
                        totalCount -= 100;
                        amountToAdd -= 100;
                    } else {
                        _inventory->misc[i].count = amountToAdd;
                        totalCount = totalCount - amountToAdd;
                        amountToAdd = 0;
                    }
                } else if (totalCount > 100) {
                    _inventory->misc[i].count = 100;
                    totalCount -= 100;
                } else {
                    _inventory->misc[i].count = totalCount;
                    totalCount = 0;
                }
            }

            _lootLeftEdge = 10;
            _showLoot = 1;
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

            _showLoot = 0;

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

        cursorMemory = vs_battle_drawCursor(cursorMemory, D_8010A68F + 8);
        break;

    case 5:
        if (_lootLeftEdge != 6) {
            break;
        }

        for (i = 0; i < lootCount; ++i) {
            if (_lootListWorkingCopy[i].itemCategory == 6) {

                item = &_inventoryBackup->misc[_lootListWorkingCopy[i].itemIndex];

                if (item->id == itemId) {

                    vs_battle_rMemzero(item, 4);

                    --lootCount;

                    for (j = i; j < lootCount; ++j) {
                        _lootListWorkingCopy[j] = _lootListWorkingCopy[j + 1];
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

            loot = &_lootListWorkingCopy[lootCount++];
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

            vs_battle_memcpy(_lootList, _lootListWorkingCopy, sizeof *_lootList * 160);
            vs_battle_memcpy(_inventory, _inventoryBackup, sizeof *_inventory);

            _lootLeftEdge = 10;
            _showLoot = 1;
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

static int _copyBladeToInventory(vs_main_inventoryBlade* source, int weapon)
{
    int index = 1;
    vs_main_inventoryBlade* blade = _inventory->blades;

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

static int _copyGripToInventory(vs_main_inventoryGrip* source, int weaponIndex)
{
    int index = 1;
    vs_main_inventoryGrip* grip = _inventory->grips;

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

static int _copyGemToInventory(vs_main_inventoryGem* source, int item)
{
    int index = 1;
    vs_main_inventoryGem* gem = _inventory->gems;

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
    vs_main_inventoryWeapon* slot = _inventory->weapons;
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

static int _copyArmorToInventory(vs_main_inventoryArmor* source)
{
    int index = 1;
    vs_main_inventoryArmor* armor = _inventory->armor;

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

    vs_main_inventoryShield* shield = _inventory->shields;
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

    shield->base.limb = index;

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
    vs_main_inventoryMisc* item = _inventory->misc;

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
        loot->state = vs_mainMenu_copyItem(loot->itemCategory, &vs_main_inventory,
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
    vs_main_inventoryShield* shield;
    vs_main_inventoryWeapon* weapon;

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
        animationStateBuf[i + _animationStateBufIndex] = menuItem->animationState;
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
            vs_main_inventoryWeapon* weapon = &_inventory->weapons[index];
            vs_main_inventoryBlade* blade = &_inventory->blades[weapon->blade - 1];
            menuItem =
                vs_battle_setMenuItem(32 + i, 24 - x, 50 + i * 16, 152, 0, weapon->name);
            menuItem->icon = blade->category;
            menuItem->material = blade->material;
            break;
        }
        case itemCategoryBlade: {
            vs_main_inventoryBlade* blade2 = &_inventory->blades[index];
            menuItem = vs_battle_setMenuItem(
                32 + i, 24 - x, 50 + i * 16, 152, 0, vs_mainMenu_itemNames[blade2->id]);
            menuItem->icon = blade2->category;
            menuItem->material = blade2->material;
            break;
        }
        case itemCategoryGrip: {
            vs_main_inventoryGrip* grip = &_inventory->grips[index];
            menuItem = vs_battle_setMenuItem(
                32 + i, 24 - x, 50 + i * 16, 152, 0, vs_mainMenu_itemNames[grip->id]);
            menuItem->icon = grip->category + 10;
            break;
        }
        case itemCategoryShield: {
            vs_main_inventoryShield* shield = &_inventory->shields[index];
            menuItem = vs_battle_setMenuItem(32 + i, 24 - x, 50 + i * 16, 152, 0,
                vs_mainMenu_itemNames[shield->base.id]);
            menuItem->icon = 15;
            menuItem->material = shield->base.material;
            break;
        }
        case itemCategoryArmor: {
            vs_main_inventoryArmor* armor = &_inventory->armor[index];
            menuItem = vs_battle_setMenuItem(
                32 + i, 24 - x, 50 + i * 16, 152, 0, vs_mainMenu_itemNames[armor->id]);
            menuItem->icon = armor->category + 0xE;
            menuItem->material = armor->material;
            break;
        }
        case itemCategoryGem: {
            vs_main_inventoryGem* gem = &_inventory->gems[index];
            menuItem = vs_battle_setMenuItem(
                32 + i, 24 - x, 50 + i * 16, 152, 0, vs_mainMenu_itemNames[gem->id]);
            menuItem->icon = 22;
            break;
        }
        case itemCategoryMisc: {
            vs_main_inventoryMisc* misc = &_inventory->misc[index];
            menuItem = vs_battle_setMenuItem(
                32 + i, 24 - x, 50 + i * 16, 152, 0, vs_mainMenu_itemNames[misc->id]);
            menuItem->count = misc->count;
            menuItem->fontColor = (misc->id < 458) ^ 1;
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

    _animationStateBufIndex = _lootListOffset;
}

static void _populateLootItem(int lootIndex)
{
    char* menuText[2];
    int rowType;
    int itemIndex = _lootList[lootIndex].itemIndex;

    vs_battle_memcpy(_inventoryBackup, &vs_main_inventory, sizeof *_inventoryBackup);
    vs_battle_memcpy(&vs_main_inventory, _inventory, sizeof vs_main_inventory);

    switch (_lootList[lootIndex].itemCategory) {
    case itemCategoryWeapon:
        vs_mainMenu_initUiWeapon(&vs_main_inventory.weapons[itemIndex], menuText,
            &rowType, vs_battle_stringBuf);
        break;

    case itemCategoryBlade:
        vs_mainMenu_setUiBlade(&vs_main_inventory.blades[itemIndex], menuText, &rowType,
            vs_battle_stringBuf);
        break;

    case itemCategoryGrip:
        vs_mainMenu_setUiGrip(
            &vs_main_inventory.grips[itemIndex], menuText, &rowType, vs_battle_stringBuf);
        break;

    case itemCategoryShield:
        vs_mainMenu_initUiShield(&vs_main_inventory.shields[itemIndex], menuText,
            &rowType, vs_battle_stringBuf);
        break;

    case itemCategoryArmor:
        vs_mainMenu_initUiArmor(
            &vs_main_inventory.armor[itemIndex], menuText, &rowType, vs_battle_stringBuf);
        break;

    case itemCategoryGem:
        vs_mainMenu_setUiGem(
            &vs_main_inventory.gems[itemIndex], menuText, &rowType, vs_battle_stringBuf);
        break;

    case itemCategoryMisc:
        vs_mainMenu_setUiItem(
            &vs_main_inventory.misc[itemIndex], menuText, &rowType, vs_battle_stringBuf);
        break;
    }

    vs_mainmenu_setInformationMessage(menuText[1]);
    vs_battle_memcpy(&vs_main_inventory, _inventoryBackup, sizeof vs_main_inventory);
}

static int _discardItems(int init)
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

        if ((_lootClaimed == 0) && (D_800EB9C8 != NULL)) {
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
            _lootClaimed == 0 ? (char*)(&_menuText[VS_menuText_OFFSET_discardAllConfirm])
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
                if (_lootClaimed == 0) {
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

int _processLootMenu(int initialize)
{
    enum state {
        init,
        processInput,
        discard,
        organize,
        topMenu,
        dissasemble,
        consolidateItems,
        waitForInput,
        waitForTopMenu,
        updateLoot
    };

    static char cursorMemory = 0;

    static char state;
    static char updateLootDelay;

    _lootListItem* loot;
    int lootIndex;
    int temp_s2;
    int i;
    int var_v0_4;

    if (initialize != 0) {
        _selectedLoot = 0;
        state = init;
        return 0;
    }

    switch (state) {
    case init:
        if (vs_mainmenu_ready() == 0) {
            break;
        }

        vs_mainMenu_initTextBox();

        state = processInput;
        // Fallthrough

    case processInput:
        _controlsEnabled = 1;

        if (vs_main_buttonsPressed.all & PADRdown) {

            vs_battle_playMenuLeaveSfx();

            _controlsEnabled = 0;

            _discardItems(1);

            state = discard;
            break;

        } else if (vs_main_buttonsPressed.all & PADRleft) {

            temp_s2 = _lootClaimed;

            for (i = 0; i < _lootListCount; ++i) {

                loot = &_lootList[i];

                if (vs_mainMenu_copyItem(loot->itemCategory | copyItemFlagsWrite,
                        &vs_main_inventory, loot->itemIndex, _inventory)
                    != 0) {
                    if (loot->itemCategory == itemCategoryMisc) {

                        int miscId = _inventory->misc[loot->itemIndex].id;

                        if (miscId > 457) {
                            _setKeyFlag(miscId);
                        }
                    }

                    loot->unk2 = 1;
                    ++_lootClaimed;
                }
            }

            if (temp_s2 != _lootClaimed) {

                vs_main_playSfxDefault(0x7E, 0xD);

                state = updateLoot;
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

                state = organize;
            } else {

                vs_main_playSfxDefault(0x7E, 0xD);

                if (loot->itemCategory == itemCategoryMisc) {

                    i = _inventory->misc[loot->itemIndex].id;

                    if (i > 457) {
                        _setKeyFlag(i);
                    }
                }

                vs_mainMenu_copyItem(loot->itemCategory | 0x10, &vs_main_inventory,
                    loot->itemIndex, _inventory);

                loot->unk2 = 1;
                updateLootDelay = 3;
                ++_lootClaimed;
                state = updateLoot;
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

            cursorMemory = vs_mainMenu_renderCursor(
                cursorMemory, (((_selectedLoot * 0x10) + 0x2A) << 0x10) | 0xA);
        }
        break;

    case discard:
        i = _discardItems(0);

        if (i != 0) {
            if (i < 0) {
                state = waitForTopMenu;
            } else {
                return i;
            }
        }
        break;

    case organize:
        i = _organizeInventory(NULL);

        if (i != 0) {

            if (i < 0) {
                state = init;
                break;
            }

            temp_s2 = _selectedLoot + _lootListOffset;

            switch (i) {
            case 1:
                _topLevelMenuTransition(_lootList[temp_s2].itemCategory + 1);

                state = topMenu;
                break;

            case 2:
                _disassembleItem(temp_s2 + 1);

                state = dissasemble;
                break;

            case 3:
                _consolidateMiscItems(temp_s2 + 1);

                state = consolidateItems;
                break;
            }
        }

        break;

    case topMenu:
        var_v0_4 = _topLevelMenuTransition(0);

        if (var_v0_4 != 0) {
            state = waitForTopMenu;
        }

        break;

    case dissasemble:
        var_v0_4 = _disassembleItem(0);

        if (var_v0_4 != 0) {
            state = waitForTopMenu;
        }

        break;

    case consolidateItems:
        var_v0_4 = _consolidateMiscItems(0);

        if (var_v0_4 != 0) {
            state = waitForTopMenu;
        }

        break;

    case waitForInput:
        if (vs_main_buttonsPressed.all == 0) {
            break;
        }
        // Fallthrough

    case waitForTopMenu:
        if (_lootLeftEdge == 0) {
            _controlsEnabled = 1;
            state = init;
            _updateLootList();
        }
        break;

    case updateLoot:
        if (updateLootDelay != 0) {
            --updateLootDelay;
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

                state = discard;
            } else {
                state = init;
            }
        }
        break;
    }

    D_8010A6B7 = (state & 7) == 1 ? _selectedLoot + 1 : -128;

    return 0;
}

int vs_menuB_exec(char* state)
{
    static char _0 __attribute__((unused));
    static char _ __attribute__((unused));

    int i;
    void* buf;

    D_8010A6B7 = 0;

    switch (*state) {
    case 0:

        vs_battle_playSfx10();
        func_800FBD80(16);

        for (i = 0; i < 7; ++i) {
            vs_mainMenu_rebuildInventory(i);
        }

        buf = vs_main_allocHeapR(
            sizeof *_inventory + sizeof *_inventoryBackup + sizeof *_lootList * 160 * 2);

        _inventory = buf;
        _inventoryBackup = buf + sizeof *_inventory;
        _lootList = buf + sizeof *_inventory + sizeof *_inventoryBackup;
        _lootListWorkingCopy =
            buf + sizeof *_inventory + sizeof *_inventoryBackup + sizeof *_lootList * 160;
        _lootClaimed = 0;
        _lootListCount = 0;
        _lootListOffset = 0;
        _0 = 0;

        vs_mainMenu_loadItemNames(1);
        _applyAllLootLists(D_800EB9C4);

        _controlsEnabled = 0;
        _showInventory = 1;
        _inventoryCapacityFlyinTimer = 10;
        _showLoot = 0;
        _lootLeftEdge = 10;
        *state = 1;
        break;

    case 1:
        if (vs_mainMenu_loadItemNames(0) != 0) {

            _showLoot = 1;

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
        _showInventory = 0;
        _showLoot = 0;

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

    if (_showInventory != 0) {
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

    if (_showLoot != 0) {
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
            vs_battle_getMenuItem(D_8010A6B7 + 31)->selected = 1;
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
