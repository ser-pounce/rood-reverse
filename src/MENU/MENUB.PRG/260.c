#include "common.h"
#include "260.h"
#include "src/SLUS_010.40/gameFlags.h"
#include "src/SLUS_010.40/gameState.h"
#include "src/SLUS_010.40/inventory.h"
#include "src/SLUS_010.40/memory.h"
#include "src/SLUS_010.40/pad.h"
#include "src/SLUS_010.40/sound.h"
#include "src/BATTLE/BATTLE.PRG/battleUi.h"
#include "src/BATTLE/BATTLE.PRG/menuState.h"
#include "src/MENU/items0.h"
#include "src/MENU/MAINMENU.PRG/224.h"
#include "build/assets/BATTLE/BATTLE.PRG/menuStrings.h"
#include "build/assets/MENU/MENUB.PRG/menuText.h"
#include <stddef.h>
#include <memory.h>

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
} LootListItem;

static char gradientStateIndex = 0;
static char controlsEnabled = 0;

static LootListItem* lootList;
static LootListItem* lootListWorkingCopy;
static vs_Inventory* inventory;
static vs_Inventory* inventoryBackup;
static char showInventory;
static u_char inventoryCapacityFlyinTimer;
static char showLoot;
static u_char lootLeftEdge;
static char selectedLoot;
static u_char lootListOffset;
static u_char lootListCount;
static char D_8010A6B7;
static char lootClaimed;

#include "src/MENU/items1.h"
#include "src/MENU/toggleUi.h"
#include "src/MENU/items2.h"
#include "src/MENU/renderAshley.h"

/**
 * Manages transitions between menu categories.
 *
 * Pass a nonzero category to begin changing category; pass zero on later calls
 * to advance the transition already in progress.
 *
 * @return Nonzero when the transition completes.
 */
static int topLevelMenuTransition(int category)
{
    enum state { init };

    static char state;
    static char D_8010A681;

    int stepValue;
    vs_MenuItem* menuItem;

    if (category != 0) {
        D_800F4EE8.unk3A.currentItemCategory = category;
        showInventory = 0;
        showLoot = 0;
        state = init;
        return 0;
    }

    switch (state) {
    case init:
        if (!vs_mainmenu_ready()) {
            break;
        }

        vs_mainMenu_toggleBackgroundFade(1);
        vs_mainMenu_setMenuCommand(menuActionMenu);

        menuItem = vs_battle_setMenuItem(3, 320, 18, 0x7E, 8,
            (char*)&vs_battle_menuStrings
                [vs_battle_menuStrings[VS_menuStrings_INDEX_items]]);
        menuItem->state = 2;
        menuItem->targetPosition0 = 180;
        menuItem->selected = 1;
        state = 1;
        break;

    case 1:
        toggleMenuUi(0);

        secondaryTitleAnimationStep = 0;
        itemCategoryIconsAnimationStep = 0;
        statusCommandAnimationStep = 0;
        selectedItemCategoryIconOnTop = 0;

        if (!vs_mainmenu_ready()) {
            break;
        }

        func_8008A4DC(0);

        D_8010A681 = D_800EB9AF;

        if (!D_8010A681) {
            func_800CB654(1);
            D_800EB9B0 = 0x200000;
        }

        renderAshley(1);
        itemNavigation(1);

        state = 2;
        break;

    case 2:
        if (itemNavigation(0) == 0) {
            break;
        }

        toggleMenuUi(0);
        vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
        func_8008A4DC(1);

        if (D_8010A681 == 0) {
            func_800CB654(0);
            D_800EB9B0 = 0;
        }

        renderAshley(2);

        state = 3;

        if (vs_main_settings.information == 0) {
            vs_mainMenu_dismissInformationBox();
        }

        break;

    case 3:
        vs_mainMenu_toggleBackgroundFade(0);
        vs_mainMenu_setMenuCommand(menuActionNone);

        if (vs_mainmenu_ready() != 0) {
            showInventory = 1;
            showLoot = 1;
            return 1;
        }

        break;
    }

    if (secondaryTitleEnabled != 0) {
        if (secondaryTitleAnimationStep < 10) {
            ++secondaryTitleAnimationStep;
        }
        stepValue = vs_battle_rowAnimationSteps[10 - secondaryTitleAnimationStep];
    } else {
        if (secondaryTitleAnimationStep != 0) {
            --secondaryTitleAnimationStep;
        }
        stepValue = (10 - secondaryTitleAnimationStep) << 5;
    }

    if ((secondaryTitleAnimationStep != 0) && (selectedItemCategoryIconOnTop == 0)) {

        int itemCategory = (D_800F4EE8.unk3A.currentItemCategory - 1) & 7;

        vs_MenuItem* menuItem = vs_battle_setMenuItem(31, stepValue + 180, 34, 140, 8,
            (char*)&menuTextTable[menuTextTable[itemCategory
                                                + VS_menuText_INDEX_weapons]]);
        menuItem->selected = 1;

        if (itemCategory != 7) {
            menuItem->max = vs_mainMenu_inventoryItemCapacities[itemCategory];
            menuItem->count = vs_mainMenu_getItemCount(itemCategory, NULL);
        }
    }

    renderAshley(0);

    if (itemCategoryIconsEnabled != 0) {
        if (itemCategoryIconsAnimationStep < 4) {
            ++itemCategoryIconsAnimationStep;
        }
    } else if (itemCategoryIconsAnimationStep != 0) {
        --itemCategoryIconsAnimationStep;
    }

    renderItemCategory(itemCategoryIconsAnimationStep, selectedItemCategoryIconOnTop);

    if (statusCommandState != 0) {
        if (statusCommandAnimationStep < 10) {
            ++statusCommandAnimationStep;
        }
        stepValue = vs_battle_rowAnimationSteps[10 - statusCommandAnimationStep];
    } else {
        if (statusCommandAnimationStep != 0) {
            --statusCommandAnimationStep;
        }
        stepValue = (10 - statusCommandAnimationStep) << 5;
    }

    if (statusCommandAnimationStep != 0) {
        vs_mainmenu_renderButtonBackground(0x10 - stepValue, 0x26, 0x58, 10);
        vs_mainmenu_renderButton(buttonIdSquare, 8 - stepValue, 0x24, NULL);
        vs_battle_renderTextRawColor("STATUS", ((0x1C - stepValue) & 0xFFFF) | 0x260000,
            0x202020 << statusCommandState, NULL);
    }

    return 0;
}

static void updateLootList(void);

/**
 * Disassembles the selected weapon or shield.
 *
 * Pass a nonzero item index to initialize the operation; pass zero on later
 * calls to advance the state.
 *
 * @return Nonzero when the operation and its exit animation complete.
 */
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
    static char lootCount;
    static u_char targetItemIndex;
    static char disassembleItemCategory;
    static UNUSED char _;

    int i;
    vs_MenuItem* menuItem;

    if (itemIndex != 0) {

        vs_battle_memcpy(
            lootListWorkingCopy, lootList, 160 * sizeof *lootListWorkingCopy);

        showLoot = 0;
        lootCount = lootListCount;
        targetItemIndex = itemIndex - 1;
        disassembleItemCategory = lootList[targetItemIndex].itemCategory;
        selectedLoot = 0;
        lootListOffset = 0;
        D_8010A683 = 0;
        state = init;

        return 0;
    }

    i = lootListWorkingCopy[targetItemIndex].itemIndex;

    switch (state) {
    case init:
        if (lootLeftEdge != 6) {
            break;
        }

        vs_battle_rMemzero(lootList, 0x280);

        lootList->itemCategory = lootListWorkingCopy[targetItemIndex].itemCategory;
        lootList->itemIndex = i;
        lootList->state = lootStateNoIndent;

        if (disassembleItemCategory != itemCategoryWeapon) {

            vs_InventoryShield* shield = &inventory->shields[i];
            lootList[1].itemCategory = itemCategoryShield;
            lootList[1].itemIndex = i;
            lootList[1].state = lootStateIndent1;
            lootListCount = 2;

            for (i = 0; i < shield->base.gemSlots; ++i) {
                if (shield->gems[i] != 0) {
                    lootList[lootListCount].itemCategory = itemCategoryGem;
                    lootList[lootListCount].itemIndex = shield->gems[i] - 1;
                    lootList[lootListCount].state = lootStateIndent3;
                    ++lootListCount;
                }
            }
        } else {
            vs_InventoryWeapon* weapon = &inventory->weapons[i];
            lootList[1].itemCategory = itemCategoryBlade;
            lootList[1].itemIndex = weapon->blade - 1;
            lootList[1].state = lootStateIndent2;
            lootList[2].itemCategory = itemCategoryGrip;
            lootList[2].itemIndex = weapon->grip - 1;
            lootList[2].state = lootStateIndent2;
            lootListCount = 3;

            for (i = 0; i < inventory->grips[weapon->grip - 1].gemSlots; ++i) {
                if (weapon->gems[i] != 0) {
                    lootList[lootListCount].itemCategory = itemCategoryGem;
                    lootList[lootListCount].itemIndex = weapon->gems[i] - 1;
                    lootList[lootListCount].state = lootStateIndent3;
                    ++lootListCount;
                }
            }
        }

        lootLeftEdge = 10;
        showLoot = 1;
        state = initOptionYes;
        break;

    case initOptionYes:
        menuItem = vs_battle_setMenuItem(0x1E, 0x140, 0x92, 0x7E, 0,
            (char*)&menuTextTable[VS_menuText_OFFSET_optionYes]);
        menuItem->state = 2;
        menuItem->targetPosition0 = 0xC2;
        state = initOptionNo;
        break;

    case initOptionNo:
        menuItem = vs_battle_setMenuItem(0x1F, 0x140, 0xA2, 0x7E, 0,
            (char*)&menuTextTable[VS_menuText_OFFSET_optionNo]);
        menuItem->state = 2;
        menuItem->targetPosition0 = 0xC2;
        vs_battle_printfArgs.strings[0] =
            disassembleItemCategory == 0
                ? inventory->weapons[i].name
                : vs_mainMenu_itemNames[inventory->shields[i].base.id];
        vs_battle_initInformationTextBox(1);
        vs_mainmenu_setInformationMessage(
            (char*)&menuTextTable[VS_menuText_OFFSET_disassembleConfirm]);
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
            showLoot = 0;
            if ((D_8010A683 != 0) || (vs_main_buttonsPressed.all & PADRdown)) {
                vs_battle_playMenuLeaveSfx();
                state = finalize;
            } else {
                vs_main_playSfxDefault(0x7E, 0x19);
                state = disassemble;
            }
            if (vs_main_settings.information == 0) {
                vs_mainMenu_dismissInformationBox();
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
        if (lootLeftEdge != 6) {
            break;
        }

        vs_battle_rMemcpy(&lootListWorkingCopy[lootCount], &lootList[1],
            (lootListCount - 1) * sizeof lootList[1]);

        if (disassembleItemCategory != itemCategoryWeapon) {
            vs_InventoryShield* shield = &inventory->shields[i];
            for (i = 0; i < shield->base.gemSlots; ++i) {
                int gem = shield->gems[i];
                if (gem != 0) {
                    shield->gems[i] = 0;
                    inventory->gems[gem - 1].setItemIndex = 0;
                }
            }
        } else {
            vs_InventoryWeapon* weapon = &inventory->weapons[i];
            inventory->blades[weapon->blade - 1].assembledWeaponIndex = 0;
            inventory->grips[weapon->grip - 1].assembledWeaponIndex = 0;

            for (i = 0; i < inventory->grips[weapon->grip - 1].gemSlots; ++i) {
                int gem = weapon->gems[i];
                if (gem != 0) {
                    weapon->gems[i] = 0;
                    inventory->gems[gem - 1].setItemIndex = 0;
                }
            }
        }

        lootCount = lootListCount + (lootCount + 254);

        for (i = targetItemIndex; i < lootCount; ++i) {
            lootListWorkingCopy[i] = lootListWorkingCopy[i + 1];
        }
        // Fallthrough

    case finalize:
        if (lootLeftEdge != 6) {
            break;
        }

        lootListCount = lootCount;

        vs_battle_memcpy(
            lootList, lootListWorkingCopy, 160 * sizeof *lootListWorkingCopy);
        updateLootList();

        lootLeftEdge = 10;
        showLoot = 1;
        state = leave;
        break;

    case leave:
        if (lootLeftEdge != 0) {
            break;
        }
        return -1;
    }

    return 0;
}

/**
 * Consolidates misc loot stacks, optionally applying the
 * changes after confirmation.
 *
 * Pass a nonzero loot index to initialize the operation; pass zero on later
 * calls to advance it.
 *
 * @return Nonzero when the operation completes.
 */
static int consolidateMiscItems(int lootIndex)
{
    static char cursorMemory = 0;

    static u_short totalCount;
    static u_short amountToAdd;
    static u_short itemId;
    static char state;
    static char D_8010A68F;
    static u_char lootCount;

    LootListItem* loot;
    int i;
    int j;
    int var_v0;
    vs_InventoryMisc* item;
    vs_MenuItem* menuItem;

    if (lootIndex != 0) {

        vs_battle_memcpy(
            lootListWorkingCopy, lootList, 160 * sizeof *lootListWorkingCopy);
        vs_battle_memcpy(inventoryBackup, inventory, sizeof *inventory);

        showLoot = 0;
        lootCount = lootListCount;
        itemId = inventory->misc[lootList[lootIndex - 1].itemIndex].id;
        selectedLoot = 0;
        lootListOffset = 0;
        D_8010A68F = 0;
        state = 0;
        return 0;
    }

    switch (state) {
    case 0:
        if (lootLeftEdge == 6) {

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

            for (i = 0; i < lootListCount; ++i) {
                if (lootList[i].itemCategory == itemCategoryMisc) {
                    item = &inventory->misc[lootList[i].itemIndex];
                    if (item->id == itemId) {

                        totalCount += item->count;

                        vs_battle_rMemzero(item, sizeof *item);

                        --lootListCount;

                        for (j = i; j < lootListCount; ++j) {
                            lootList[j] = lootList[j + 1];
                        }
                        --i;
                    }
                }
            }

            lootListCount = 0;

            while (totalCount != 0) {

                for (i = 0; i < 64; ++i) {
                    if (inventory->misc[i].id == 0) {
                        break;
                    }
                }

                if (i == 64) {
                    break;
                }

                loot = &lootList[lootListCount++];
                loot->itemCategory = itemCategoryMisc;
                loot->itemIndex = i;
                loot->unk2 = 0;
                inventory->misc[i].id = itemId;
                loot->state = amountToAdd != 0;

                if (loot->state != lootStateNone) {
                    if (amountToAdd > 100) {
                        inventory->misc[i].count = 100;
                        totalCount -= 100;
                        amountToAdd -= 100;
                    } else {
                        inventory->misc[i].count = amountToAdd;
                        totalCount = totalCount - amountToAdd;
                        amountToAdd = 0;
                    }
                } else if (totalCount > 100) {
                    inventory->misc[i].count = 100;
                    totalCount -= 100;
                } else {
                    inventory->misc[i].count = totalCount;
                    totalCount = 0;
                }
            }

            lootLeftEdge = 10;
            showLoot = 1;
            state = 1;
        }
        break;

    case 1:
        menuItem = vs_battle_setMenuItem(
            30, 320, 146, 0x7E, 0, (char*)&menuTextTable[VS_menuText_OFFSET_optionYes]);
        menuItem->state = 2;
        menuItem->targetPosition0 = 194;
        state = 2;
        break;

    case 2:
        menuItem = vs_battle_setMenuItem(
            31, 320, 162, 0x7E, 0, (char*)&menuTextTable[VS_menuText_OFFSET_optionNo]);
        menuItem->state = 2;
        menuItem->targetPosition0 = 194;
        vs_battle_printfArgs.strings[0] = vs_mainMenu_itemNames[itemId];

        vs_battle_initInformationTextBox(1);
        vs_mainmenu_setInformationMessage(
            (char*)&menuTextTable[VS_menuText_OFFSET_organizeConfirm]);

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

            showLoot = 0;

            if ((D_8010A68F != 0) || (vs_main_buttonsPressed.all & PADRdown)) {
                vs_battle_playMenuLeaveSfx();
                state = 6;
            } else {
                vs_battle_playMenuSelectSfx();
                state = 5;
            }

            var_v0 = 0;

            if (vs_main_settings.information == 0) {
                vs_mainMenu_dismissInformationBox();
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
        if (lootLeftEdge != 6) {
            break;
        }

        for (i = 0; i < lootCount; ++i) {
            if (lootListWorkingCopy[i].itemCategory == 6) {

                item = &inventoryBackup->misc[lootListWorkingCopy[i].itemIndex];

                if (item->id == itemId) {

                    vs_battle_rMemzero(item, 4);

                    --lootCount;

                    for (j = i; j < lootCount; ++j) {
                        lootListWorkingCopy[j] = lootListWorkingCopy[j + 1];
                    }
                    --i;
                }
            }
        }

        for (i = 0; i < lootListCount; ++i) {
            for (j = 0; j < 64; ++j) {
                if (inventoryBackup->misc[j].id == 0) {
                    break;
                }
            }

            if (j == 0x40) {
                break;
            }

            loot = &lootListWorkingCopy[lootCount++];
            loot->itemCategory = itemCategoryMisc;
            loot->itemIndex = j;
            loot->unk2 = 0;
            loot->state = lootList[i].state;
            item = &inventoryBackup->misc[j];
            item->id = itemId;
            item->count = inventory->misc[lootList[i].itemIndex].count;
        }
        // Fallthrough

    case 6:
        if (lootLeftEdge == 6) {

            lootListCount = lootCount;

            vs_battle_memcpy(lootList, lootListWorkingCopy, sizeof *lootList * 160);
            vs_battle_memcpy(inventory, inventoryBackup, sizeof *inventory);

            lootLeftEdge = 10;
            showLoot = 1;
            state = 7;
        }
        break;

    case 7:
        if (lootLeftEdge != 0) {
            break;
        }
        return -1;
    }

    return 0;
}

/**
 * Copies a looted blade into the first free inventory slot.
 *
 * @param weapon Associated weapon index, or zero when the blade is not assembled.
 * @return The one-based inventory index, or zero if no slot is available.
 */
static int copyBladeToInventory(vs_InventoryBlade* source, int weapon)
{
    int index = 1;
    vs_InventoryBlade* blade = inventory->blades;

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

/**
 * Copies a looted grip into the first free inventory slot.
 *
 * @param weaponIndex Associated weapon index, or zero when the grip is not
 * assembled.
 * @return The one-based inventory index, or zero if no slot is available.
 */
static int copyGripToInventory(vs_InventoryGrip* source, int weaponIndex)
{
    int index = 1;
    vs_InventoryGrip* grip = inventory->grips;

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

/**
 * Copies a looted gem into the first free inventory slot.
 *
 * @param item Encoded index of the weapon or shield to which the gem is set,
 * or zero when it is not attached.
 * @return The one-based inventory index, or zero if no slot is available.
 */
static int copyGemToInventory(vs_InventoryGem* source, int item)
{
    int index = 1;
    vs_InventoryGem* gem = inventory->gems;

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

/**
 * Adds a looted weapon and its blade, grip, and gems to the inventory.
 *
 * @param arg0 Looted weapon and component data.
 * @return The one-based weapon index, or zero if no weapon slot is available.
 */
static int copyWeaponToInventory(vs_LootedWeapon* arg0)
{
    int i;
    vs_InventoryWeapon* slot = inventory->weapons;
    int index = 1;

    while (slot->blade != 0) {
        ++slot;
        if (++index == 8) {
            return 0;
        }
    }

    vs_battle_rMemzero(slot, sizeof *slot);

    slot->index = index;
    slot->blade = copyBladeToInventory(&arg0->blade, index);
    slot->grip = copyGripToInventory(&arg0->grip, index);

    for (i = 0; i < 3; i++) {
        if (arg0->gems[i].id != 0) {
            slot->gems[i] = copyGemToInventory(&arg0->gems[i], index);
        }
    }

    vs_battle_rMemcpy(slot->name, arg0->name, sizeof slot->name);

    return index;
}

/**
 * Copies a looted armor piece into the first free inventory slot.
 *
 * @return The one-based inventory index, or zero if no slot is available.
 */
static int copyArmorToInventory(vs_InventoryArmor* source)
{
    int index = 1;
    vs_InventoryArmor* armor = inventory->armor;

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

/**
 * Adds a looted shield and its gems to the inventory.
 *
 * @param arg0 Looted shield and attached gem data.
 * @return The one-based shield index, or zero if no shield slot is available.
 */
static int copyShieldToInventory(vs_LootedShield* arg0)
{
    int i;

    vs_InventoryShield* shield = inventory->shields;
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
            shield->gems[i] = copyGemToInventory(&arg0->gems[i], index | 0x80);
        }
    }

    return index;
}

/**
 * Copies a looted miscellaneous item into the first free inventory slot.
 *
 * @return The one-based inventory index, or zero if no slot is available.
 */
static int copyMiscToInventory(vs_LootedMisc* arg0)
{
    int index = 1;
    vs_InventoryMisc* item = inventory->misc;

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

/**
 * Rechecks which loot items can be claimed and updates loot paging.
 */
static void updateLootList(void)
{
    int i;
    int newOffset;
    LootListItem* loot = lootList;

    for (i = 0; i < lootListCount; ++i, ++loot) {
        loot->state = vs_mainMenu_copyItem(loot->itemCategory, &vs_main_inventory,
                          loot->itemIndex, inventory)
                   != 0;
    }

    i = selectedLoot + lootListOffset;

    if (i >= lootListCount) {
        i = lootListCount - 1;
        lootListOffset = lootListCount - 8;
        selectedLoot = 7;
    }

    if (lootListCount < 9) {
        selectedLoot = i;
        lootListOffset = 0;
        return;
    }

    newOffset = lootListCount - 8;
    if (newOffset < lootListOffset) {
        lootListOffset = newOffset;
        selectedLoot = i - newOffset;
    }

    if ((selectedLoot == 7) && (i != (lootListCount - 1))) {
        selectedLoot -= 1;
        lootListOffset = lootListOffset + 1;
    }
}

/**
 * Appends an item to the loot list.
 *
 * @param itemIndex One-based inventory index; stored in the list as zero-based.
 */
static void addLootToList(int itemCategory, int itemIndex)
{
    LootListItem* item = &lootList[lootListCount++];
    item->itemCategory = itemCategory;
    item->itemIndex = itemIndex - 1;
    item->unk2 = 0;
}

static char* itemCategoryHeaders[] = { "WEAPON", "BLADE", "GRIP", "SHIELD", "ARMOR",
    "GEM", "MISC" };

/**
 * Counts items of a category represented by a loot-list entry, including the
 * components of assembled weapons and shields when counting gems.
 *
 * @param arg0 Inventory item category to count.
 * @param arg1 Loot-list entry whose item and components are counted.
 */
static int itemIncludesItemsInCategory(int arg0, LootListItem* arg1)
{
    int i;
    vs_InventoryShield* shield;
    vs_InventoryWeapon* weapon;

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
            weapon = &inventory->weapons[arg1->itemIndex];
            for (i = 0; i < inventory->grips[weapon->grip - 1].gemSlots; ++i) {
                count += weapon->gems[i] != 0;
            }
        }

        if (category == itemCategoryShield) {
            shield = &inventory->shields[arg1->itemIndex];
            for (i = 0; i < shield->base.gemSlots; ++i) {
                count += shield->gems[i] != 0;
            }
        }

        break;
    }
    return count;
}

/**
 * Draws inventory capacities, item counts, and loot-menu controls.
 */
static void displayInventoryCapacities(int edgeX)
{
    int itemCountPos;
    int buttonBgPos;
    int var_a2;
    int var_fp;
    int i;
    int y;
    LootListItem* item;
    unsigned int xy;
    char* str;

    item = NULL;
    var_fp = 1;

    if (D_8010A6B7 != 0) {

        item = (LootListItem*)1;

        if (D_8010A6B7 & 0xF) {

            var_fp = 0;
            item = &lootList[lootListOffset + D_8010A6B7 - 1];

            for (i = 0; i < lootListCount; ++i) {
                var_fp += lootList[i].state;
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
                 << ((item == (LootListItem*)1)
                        || (itemIncludesItemsInCategory(i, item) != 0));
        }

        y = (24 + i * 12) << 16;

        vs_battle_renderTextRawColor("/", itemCountPos | y, color, NULL);
        vs_battle_renderTextRawColor(
            itemCategoryHeaders[i], (edgeX + 192) | y, color, NULL);
        vs_mainMenu_renderIntColor(capacity, (edgeX + 296) | y, color, NULL);

        if (((u_int)color >> 23) != 0) {

            if ((itemCount * 2) < capacity) {
                color = vs_getRGB(32, 64, 128);
            }

            if (((u_long)item >> 1) != 0) {
                if (capacity < (itemIncludesItemsInCategory(i, item) + itemCount)) {
                    color = vs_getRGB(128, 64, 32);
                }
            }
        }

        vs_mainMenu_renderIntColor(itemCount, itemCountPos | y, color, NULL);
    }

    buttonBgPos = edgeX + 184;

    vs_mainmenu_renderButtonBackground(buttonBgPos, 112, 112, 10);
    vs_mainmenu_renderButtonBackground(buttonBgPos, 128, 64, 10);
    vs_battle_renderTextRawColor("GET", (edgeX + 196) | (112 << 16),
        vs_getRGB(64, 64, 64) << controlsEnabled, NULL);
    vs_mainmenu_renderButton(buttonIdCircle, edgeX + 176, 110, NULL);

    str = "ALL";
    xy = (edgeX + 252) | (112 << 16);

    if (var_fp != 0) {
        var_a2 = vs_getRGB(64, 64, 64) << (controlsEnabled & 1);
    } else {
        var_a2 = vs_getRGB(64, 64, 64);
    }

    vs_battle_renderTextRawColor(str, xy, var_a2, NULL);
    vs_mainmenu_renderButton(buttonIdSquare, edgeX + 232, 110, NULL);
    vs_battle_renderTextRawColor("END", (edgeX + 196) | (128 << 16),
        vs_getRGB(64, 64, 64) << controlsEnabled, NULL);
    vs_mainmenu_renderButton(buttonIdCross, edgeX + 176, 126, NULL);
}

/**
 * Tests whether a loot difficulty bitmask allows a drop at the current setting.
 *
 * @param arg0 Difficulty flags from a loot entry.
 * @return Nonzero when the bit corresponding to the current difficulty is set.
 */
static int droppableUnderCurrentDifficulty(int arg0)
{
    return arg0 & (vs_main_stateFlags.difficulty + 1);
}

/**
 * Copies all eligible items from a battle loot record into the working
 * inventory and appends them to the loot list.
 *
 * @param arg0 Battle loot record to apply.
 */
static void applyLootList(vs_Loot* arg0)
{
    int i;

    if (droppableUnderCurrentDifficulty(arg0->weapon.difficultyFlags) != 0) {
        addLootToList(itemCategoryWeapon, copyWeaponToInventory(&arg0->weapon));
    }

    if (droppableUnderCurrentDifficulty(arg0->blade.difficultyFlags) != 0) {
        addLootToList(itemCategoryBlade, copyBladeToInventory(&arg0->blade.blade, 0));
    }

    if (droppableUnderCurrentDifficulty(arg0->grip.difficultyFlags) != 0) {
        addLootToList(itemCategoryGrip, copyGripToInventory(&arg0->grip.grip, 0));
    }

    if (droppableUnderCurrentDifficulty(arg0->shield.difficultyFlags) != 0) {
        addLootToList(itemCategoryShield, copyShieldToInventory(&arg0->shield));
    }

    for (i = 0; i < 2; ++i) {
        if (droppableUnderCurrentDifficulty(arg0->armor[i].difficultyFlags) != 0) {
            addLootToList(itemCategoryArmor, copyArmorToInventory(&arg0->armor[i].armor));
        }
    }

    if (droppableUnderCurrentDifficulty(arg0->accessory.difficultyFlags) != 0) {
        addLootToList(
            itemCategoryArmor, copyArmorToInventory(&arg0->accessory.accessory));
    }

    if (droppableUnderCurrentDifficulty(arg0->gem.difficultyFlags) != 0) {
        addLootToList(itemCategoryGem, copyGemToInventory(&arg0->gem.gem, 0));
    }

    for (i = 0; i < 3; ++i) {
        if ((droppableUnderCurrentDifficulty(arg0->misc[i].difficultyFlags) != 0)
            && (arg0->misc[i].id != 0) && (arg0->misc[i].count != 0)) {
            addLootToList(itemCategoryMisc, copyMiscToInventory(&arg0->misc[i]));
        }
    }

    updateLootList();
}

/**
 * Rebuilds the working inventory from a loot-list chain, or from the current
 * battle loot record when no chain is supplied.
 */
static void applyAllLootLists(vs_LootListNode* node)
{
    vs_battle_rMemzero(inventory, sizeof *inventory);

    if (node != NULL) {
        while (node != NULL) {
            applyLootList(&node->loot);
            node = node->next;
        }
    } else {
        applyLootList(D_800EB9C8);
    }
}

/**
 * Draws the visible page of loot items, preserving their scroll and animation
 * state.
 */
static void displayCurrentLoot(int x)
{
    char gradientStates[256];
    int i;
    int index;
    int temp_v1_3;
    vs_MenuItem* menuItem;

    int count = lootListCount;
    LootListItem* loot = &lootList[lootListOffset];

    vs_battle_rMemzero(&gradientStates, sizeof gradientStates);

    for (i = 0; i < 8; ++i) {
        menuItem = vs_battle_getMenuItem(i + 32);
        gradientStates[i + gradientStateIndex] = menuItem->gradientState;
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
            vs_InventoryWeapon* weapon = &inventory->weapons[index];
            vs_InventoryBlade* blade = &inventory->blades[weapon->blade - 1];
            menuItem =
                vs_battle_setMenuItem(32 + i, 24 - x, 50 + i * 16, 152, 0, weapon->name);
            menuItem->rowIcon = blade->category;
            menuItem->material = blade->material;
            break;
        }
        case itemCategoryBlade: {
            vs_InventoryBlade* blade2 = &inventory->blades[index];
            menuItem = vs_battle_setMenuItem(
                32 + i, 24 - x, 50 + i * 16, 152, 0, vs_mainMenu_itemNames[blade2->id]);
            menuItem->rowIcon = blade2->category;
            menuItem->material = blade2->material;
            break;
        }
        case itemCategoryGrip: {
            vs_InventoryGrip* grip = &inventory->grips[index];
            menuItem = vs_battle_setMenuItem(
                32 + i, 24 - x, 50 + i * 16, 152, 0, vs_mainMenu_itemNames[grip->id]);
            menuItem->rowIcon = grip->category + 10;
            break;
        }
        case itemCategoryShield: {
            vs_InventoryShield* shield = &inventory->shields[index];
            menuItem = vs_battle_setMenuItem(32 + i, 24 - x, 50 + i * 16, 152, 0,
                vs_mainMenu_itemNames[shield->base.id]);
            menuItem->rowIcon = 15;
            menuItem->material = shield->base.material;
            break;
        }
        case itemCategoryArmor: {
            vs_InventoryArmor* armor = &inventory->armor[index];
            menuItem = vs_battle_setMenuItem(
                32 + i, 24 - x, 50 + i * 16, 152, 0, vs_mainMenu_itemNames[armor->id]);
            menuItem->rowIcon = armor->category + 0xE;
            menuItem->material = armor->material;
            break;
        }
        case itemCategoryGem: {
            vs_InventoryGem* gem = &inventory->gems[index];
            menuItem = vs_battle_setMenuItem(
                32 + i, 24 - x, 50 + i * 16, 152, 0, vs_mainMenu_itemNames[gem->id]);
            menuItem->rowIcon = 22;
            break;
        }
        case itemCategoryMisc: {
            vs_InventoryMisc* misc = &inventory->misc[index];
            menuItem = vs_battle_setMenuItem(
                32 + i, 24 - x, 50 + i * 16, 152, 0, vs_mainMenu_itemNames[misc->id]);
            menuItem->count = misc->count;
            menuItem->fontColor = (misc->id < 458) ^ 1;
            break;
        }
        }

        menuItem->gradientState = gradientStates[i + lootListOffset];
        menuItem->unselectable = loot->state == 0;

        if (loot->unk2 != 0) {
            menuItem->x -= loot->unk2 * 48;
            ++loot->unk2;
            if (loot->unk2 == 4) {
                menuItem->gradientState = 0;
            }
        }

        if (i == 0) {
            if (lootListOffset != 0) {
                menuItem->isScrollable = 1;
            }
        }

        if ((i == 7) && (lootListOffset != (lootListCount - 8))) {
            menuItem->isScrollable = 2;
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

    gradientStateIndex = lootListOffset;
}

/**
 * Displays an item's description in the information box using the working
 * inventory data.
 */
static void populateLootItem(int lootIndex)
{
    char* menuText[2];
    int rowType;
    int itemIndex = lootList[lootIndex].itemIndex;

    vs_battle_memcpy(inventoryBackup, &vs_main_inventory, sizeof *inventoryBackup);
    vs_battle_memcpy(&vs_main_inventory, inventory, sizeof vs_main_inventory);

    switch (lootList[lootIndex].itemCategory) {
    case itemCategoryWeapon:
        vs_mainMenu_setWeaponRowFromInventory(&vs_main_inventory.weapons[itemIndex],
            menuText, &rowType, vs_battle_stringBuf);
        break;

    case itemCategoryBlade:
        vs_mainMenu_setBladeRow(&vs_main_inventory.blades[itemIndex], menuText, &rowType,
            vs_battle_stringBuf);
        break;

    case itemCategoryGrip:
        vs_mainMenu_setGripRow(
            &vs_main_inventory.grips[itemIndex], menuText, &rowType, vs_battle_stringBuf);
        break;

    case itemCategoryShield:
        vs_mainMenu_setShieldRowFromInventory(&vs_main_inventory.shields[itemIndex],
            menuText, &rowType, vs_battle_stringBuf);
        break;

    case itemCategoryArmor:
        vs_mainMenu_setArmorRowFromInventory(
            &vs_main_inventory.armor[itemIndex], menuText, &rowType, vs_battle_stringBuf);
        break;

    case itemCategoryGem:
        vs_mainMenu_setGemRow(
            &vs_main_inventory.gems[itemIndex], menuText, &rowType, vs_battle_stringBuf);
        break;

    case itemCategoryMisc:
        vs_mainMenu_setMiscRow(
            &vs_main_inventory.misc[itemIndex], menuText, &rowType, vs_battle_stringBuf);
        break;
    }

    vs_mainmenu_setInformationMessage(menuText[1]);
    vs_battle_memcpy(&vs_main_inventory, inventoryBackup, sizeof vs_main_inventory);
}

/**
 * Runs the discard-loot confirmation.
 *
 * Pass a nonzero value to initialize the prompt; pass zero on subsequent
 * calls. A positive result indicates a completed discard choice.
 *
 * @return Zero while pending, -1 when cancelled, or a positive discard result.
 */
static int discardItems(int init)
{
    static char cursorAnimStep = 0;

    static char state;
    static char D_8010A692;
    static UNUSED char _;
    static char* itemName;

    vs_MenuItem* menuItem;

    if (init != 0) {
        int i;

        D_8010A692 = 1;
        state = 0;

        if (lootListCount == 0) {
            state = 4;
            return 0;
        }

        if ((lootClaimed == 0) && (D_800EB9C8 != NULL)) {
            state = 5;
            return 0;
        }

        for (i = 0; i < lootListCount; ++i) {
            if ((lootList[i].itemCategory == itemCategoryMisc)
                && (inventory->misc[lootList[i].itemIndex].id > 457)) {
                itemName =
                    vs_mainMenu_itemNames[inventory->misc[lootList[i].itemIndex].id];
                state = 6;
            }
        }
        return 0;
    }

    switch (state) {
    case 0:
        menuItem = vs_battle_setMenuItem(30, 0x140, 0x92, 0x7E, 0,
            (char*)&menuTextTable[VS_menuText_OFFSET_optionYes]);
        menuItem->state = 2;
        menuItem->targetPosition0 = 0xC2;
        state = 1;
        break;

    case 1:
        menuItem = vs_battle_setMenuItem(
            31, 0x140, 0xA2, 0x7E, 0, (char*)&menuTextTable[VS_menuText_OFFSET_optionNo]);
        menuItem->state = 2;
        menuItem->targetPosition0 = 0xC2;

        vs_battle_initInformationTextBox(1);
        vs_mainmenu_setInformationMessage(
            lootClaimed == 0
                ? (char*)(&menuTextTable[VS_menuText_OFFSET_discardAllConfirm])
                : (char*)(&menuTextTable[VS_menuText_OFFSET_itemsRemaining]));
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
                vs_mainMenu_dismissInformationBox();
            }

            if ((D_8010A692 == 0) && !(vs_main_buttonsPressed.all & PADRdown)) {
                int var_v1;
                vs_main_playSfxDefault(0x7E, 0x1C);
                var_v1 = 1;
                if (lootClaimed == 0) {
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
        vs_battle_printfArgs.strings[0] = itemName;

        vs_battle_initInformationTextBox(1);
        vs_mainmenu_setInformationMessage(
            (char*)&menuTextTable[VS_menuText_OFFSET_invalidDiscard]);

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

/**
 * Opens the selected item's organization submenu or advances the active menu.
 *
 * Pass an item pointer to initialize the menu; pass NULL to process it.
 *
 * @return Zero while pending, -1 when cancelled, or the selected action:
 * 1 for the category inventory menu, 2 to disassemble, or 3 to consolidate.
 */
static int organizeInventory(LootListItem* loot)
{
    static char cursorAnimState = 0;

    static char state;
    static char itemCategory;
    static char selectedRow;
    static char availableAction;

    vs_MenuItem* menuItem;

    if (loot != NULL) {
        vs_mainMenu_initInformationBox();

        itemCategory = loot->itemCategory;
        state = 0;
        selectedRow = 0;
        availableAction = 0;

        if (itemCategory == itemCategoryWeapon) {
            availableAction = 1;
        } else if (itemCategory == itemCategoryShield) {
            availableAction = 1;
        } else if ((itemCategory == itemCategoryMisc)
                   && (inventory->misc[loot->itemIndex].id < 458)) {
            availableAction = 2;
        } else {
            selectedRow = 1;
        }

        if (availableAction != 0) {
            menuItem = vs_battle_setMenuItem(30, 0x140, 0x92, 0x7E, 0,
                (char*)&menuTextTable[menuTextTable[(availableAction + 4) * 2]]);
            menuItem->state = 2;
            menuItem->targetPosition0 = 0xC2;
        }

        return 0;
    }

    switch (state) {
    case 0:
        menuItem = vs_battle_setMenuItem(31, 0x140, 0xA2, 0x7E, 0,
            (char*)&menuTextTable[VS_menuText_OFFSET_organizeInventory]);
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
                (char*)&menuTextTable[VS_menuText_OFFSET_organizeInventoryInfo]);
        } else if (availableAction == 1) {
            vs_mainmenu_setInformationMessage(
                (char*)&menuTextTable[VS_menuText_OFFSET_disassembleInfo]);
        } else {
            vs_mainmenu_setInformationMessage(
                (char*)&menuTextTable[VS_menuText_OFFSET_organizeInfo]);
        }

        cursorAnimState = vs_battle_drawCursor(cursorAnimState, selectedRow + 8);
        break;
    }
    return 0;
}

static void setKeyFlag(int arg0);

/**
 * Processes loot-menu input and advances discard, organization, and item
 * removal operations.
 *
 * Pass a nonzero value to initialize the menu; pass zero on subsequent calls.
 *
 * @return Zero while the menu is active, or the completed discard result.
 *
 * @param initialize Nonzero to reset the menu state, zero to process it.
 */
static int processLootMenu(int initialize)
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

    LootListItem* loot;
    int lootIndex;
    int temp_s2;
    int i;
    int var_v0_4;

    if (initialize != 0) {
        selectedLoot = 0;
        state = init;
        return 0;
    }

    switch (state) {
    case init:
        if (vs_mainmenu_ready() == 0) {
            break;
        }

        vs_mainMenu_initInformationBox();

        state = processInput;
        // Fallthrough

    case processInput:
        controlsEnabled = 1;

        if (vs_main_buttonsPressed.all & PADRdown) {

            vs_battle_playMenuLeaveSfx();

            controlsEnabled = 0;

            discardItems(1);

            state = discard;
            break;

        } else if (vs_main_buttonsPressed.all & PADRleft) {

            temp_s2 = lootClaimed;

            for (i = 0; i < lootListCount; ++i) {

                loot = &lootList[i];

                if (vs_mainMenu_copyItem(loot->itemCategory | copyItemFlagsWrite,
                        &vs_main_inventory, loot->itemIndex, inventory)
                    != 0) {
                    if (loot->itemCategory == itemCategoryMisc) {

                        int miscId = inventory->misc[loot->itemIndex].id;

                        if (miscId > 457) {
                            setKeyFlag(miscId);
                        }
                    }

                    loot->unk2 = 1;
                    ++lootClaimed;
                }
            }

            if (temp_s2 != lootClaimed) {

                vs_main_playSfxDefault(0x7E, 0xD);

                state = updateLoot;
                break;
            }

            vs_battle_playInvalidSfx();
        }

        lootIndex = selectedLoot + lootListOffset;
        loot = &lootList[lootIndex];

        if (vs_main_buttonsPressed.all & PADRright) {
            if (loot->state == 0) {

                vs_battle_playMenuSelectSfx();

                controlsEnabled = 0;

                organizeInventory(loot);

                state = organize;
            } else {

                vs_main_playSfxDefault(0x7E, 0xD);

                if (loot->itemCategory == itemCategoryMisc) {

                    i = inventory->misc[loot->itemIndex].id;

                    if (i > 457) {
                        setKeyFlag(i);
                    }
                }

                vs_mainMenu_copyItem(loot->itemCategory | 0x10, &vs_main_inventory,
                    loot->itemIndex, inventory);

                loot->unk2 = 1;
                updateLootDelay = 3;
                ++lootClaimed;
                state = updateLoot;
            }
        } else {
            i = lootIndex;

            if (vs_main_buttonRepeat & PADLup) {
                if (lootListCount < 9) {
                    if (selectedLoot == 0) {
                        selectedLoot = lootListCount - 1;
                    } else {
                        --selectedLoot;
                    }
                } else {
                    if (lootListOffset == 0) {
                        if (selectedLoot == 0) {
                            if (vs_main_buttonsPressed.all & PADLup) {
                                selectedLoot = 7;
                                lootListOffset = lootListCount - 8;
                            }
                        } else {
                            --selectedLoot;
                        }
                    } else {
                        if (selectedLoot == 1) {
                            --lootListOffset;
                        } else {
                            --selectedLoot;
                        }
                    }
                }
            }

            if (vs_main_buttonRepeat & PADLdown) {
                if (lootListCount < 9) {
                    if (selectedLoot == (lootListCount - 1)) {
                        selectedLoot = 0;
                    } else {
                        ++selectedLoot;
                    }
                } else if (lootListOffset == (lootListCount - 8)) {
                    if (selectedLoot == 7) {
                        if (vs_main_buttonsPressed.all & PADLdown) {
                            selectedLoot = 0;
                            lootListOffset = 0;
                        }
                    } else {
                        ++selectedLoot;
                    }
                } else if (selectedLoot == 6) {
                    ++lootListOffset;
                } else {
                    ++selectedLoot;
                }
            }

            if (i != (selectedLoot + lootListOffset)) {
                vs_battle_playMenuChangeSfx();
            }

            populateLootItem(selectedLoot + lootListOffset);

            cursorMemory = vs_mainMenu_renderCursor(
                cursorMemory, (((selectedLoot * 0x10) + 0x2A) << 0x10) | 0xA);
        }
        break;

    case discard:
        i = discardItems(0);

        if (i != 0) {
            if (i < 0) {
                state = waitForTopMenu;
            } else {
                return i;
            }
        }
        break;

    case organize:
        i = organizeInventory(NULL);

        if (i != 0) {

            if (i < 0) {
                state = init;
                break;
            }

            temp_s2 = selectedLoot + lootListOffset;

            switch (i) {
            case 1:
                topLevelMenuTransition(lootList[temp_s2].itemCategory + 1);

                state = topMenu;
                break;

            case 2:
                disassembleItem(temp_s2 + 1);

                state = dissasemble;
                break;

            case 3:
                consolidateMiscItems(temp_s2 + 1);

                state = consolidateItems;
                break;
            }
        }

        break;

    case topMenu:
        var_v0_4 = topLevelMenuTransition(0);

        if (var_v0_4 != 0) {
            state = waitForTopMenu;
        }

        break;

    case dissasemble:
        var_v0_4 = disassembleItem(0);

        if (var_v0_4 != 0) {
            state = waitForTopMenu;
        }

        break;

    case consolidateItems:
        var_v0_4 = consolidateMiscItems(0);

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
        if (lootLeftEdge == 0) {
            controlsEnabled = 1;
            state = init;
            updateLootList();
        }
        break;

    case updateLoot:
        if (updateLootDelay != 0) {
            --updateLootDelay;
        } else {

            while (1) {
                for (i = 0; i < lootListCount; ++i) {
                    if (lootList[i].unk2 != 0) {
                        break;
                    }
                }

                if (i == lootListCount) {
                    break;
                }

                --lootListCount;

                for (; i < lootListCount; ++i) {
                    lootList[i] = lootList[i + 1];
                }
            }

            updateLootList();

            if (lootListCount == 0) {

                controlsEnabled = 0;

                discardItems(1);

                state = discard;
            } else {
                state = init;
            }
        }
        break;
    }

    D_8010A6B7 = (state & 7) == 1 ? selectedLoot + 1 : -128;

    return 0;
}

/**
 * Runs the battle loot menu, including initialization, drawing, and teardown.
 *
 * @param state Caller-owned menu state, updated on each call.
 * @return Nonzero when the menu has finished and its resources are released.
 */
int vs_menuB_exec(u_char* state)
{
    static UNUSED char _0;
    static UNUSED char _;

    int i;
    void* buf;

    D_8010A6B7 = 0;

    switch (*state) {
    case 0:

        vs_battle_playSfx10();
        vs_mainMenu_populateBaseStats(16);

        for (i = 0; i < 7; ++i) {
            vs_mainMenu_rebuildInventory(i);
        }

        buf = vs_main_allocHeapR(
            sizeof *inventory + sizeof *inventoryBackup + sizeof *lootList * 160 * 2);

        inventory = buf;
        inventoryBackup = buf + sizeof *inventory;
        lootList = buf + sizeof *inventory + sizeof *inventoryBackup;
        lootListWorkingCopy =
            buf + sizeof *inventory + sizeof *inventoryBackup + sizeof *lootList * 160;
        lootClaimed = 0;
        lootListCount = 0;
        lootListOffset = 0;
        _0 = 0;

        vs_mainMenu_loadItemText(1);
        applyAllLootLists(D_800EB9C4);

        controlsEnabled = 0;
        showInventory = 1;
        inventoryCapacityFlyinTimer = 10;
        showLoot = 0;
        lootLeftEdge = 10;
        *state = 1;
        break;

    case 1:
        if (vs_mainMenu_loadItemText(0) != 0) {

            showLoot = 1;

            if (lootListCount == 0) {

                vs_battle_initInformationTextBox(1);
                vs_mainmenu_setInformationMessage(
                    (char*)&menuTextTable[VS_menuText_OFFSET_emptyChest]);

                *state = 4;

            } else {
                vs_mainMenu_initInformationBox();
                *state = 2;
            }
        }
        break;

    case 2:
        if (vs_mainmenu_ready() == 0) {
            break;
        }

        if (lootLeftEdge != 0) {
            break;
        }

        processLootMenu(1);

        *state = 3;
        // Fallthrough

    case 3:
        i = processLootMenu(0);
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
        showInventory = 0;
        showLoot = 0;

        if ((vs_battle_dismissTextBox(7) != 0)
            || (vs_mainMenu_ensureItemTextUnloaded() == 0)) {
            break;
        }

        vs_main_freeHeapR(inventory);

        if (D_800EB9C4 != 0) {
            func_8008A6FC();
        }

        *state = 0;
        return 1;
    }

    if (showInventory != 0) {
        if (inventoryCapacityFlyinTimer != 0) {
            --inventoryCapacityFlyinTimer;
        }
        i = vs_battle_rowAnimationSteps[inventoryCapacityFlyinTimer];
    } else {
        if (inventoryCapacityFlyinTimer < 10) {
            ++inventoryCapacityFlyinTimer;
        }
        i = inventoryCapacityFlyinTimer << 5;
    }

    if (inventoryCapacityFlyinTimer < 10) {
        displayInventoryCapacities(i);
    }

    if (showLoot != 0) {
        if (lootLeftEdge != 0) {
            --lootLeftEdge;
        }
        i = vs_battle_rowAnimationSteps[lootLeftEdge];
    } else {
        if (lootLeftEdge < 10) {
            ++lootLeftEdge;
        }
        i = lootLeftEdge << 5;
    }

    if (lootLeftEdge < 10) {

        displayCurrentLoot(i);

        if (D_8010A6B7 & 0xF) {
            vs_battle_getMenuItem(D_8010A6B7 + 31)->selected = 1;
        }
    }

    return 0;
}

/**
 * Sets the battle state flag associated with a key.
 *
 * @param arg0 Item ID; only IDs greater than 457 set a flag.
 */
static void setKeyFlag(int arg0)
{
    if (arg0 > 457) {
        vs_battle_setStateFlag(arg0 + 438, 1);
    }
}
