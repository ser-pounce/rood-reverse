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
            vs_mainMenu_initUiWeapon(&vs_battle_inventory.weapons[index],
                &menuText[count * 2], &rowTypes[i], textBuf);

            if (vs_battle_inventory.weapons[index].isEquipped != 0) {
                rowType = 0xCA00;
            }
            break;

        case itemCategoryBlade:
            vs_mainMenu_setUiBlade(&vs_battle_inventory.blades[index],
                &menuText[count * 2], &rowTypes[i], textBuf);
            break;

        case itemCategoryGrip:
            vs_mainMenu_setUiGrip(&vs_battle_inventory.grips[index], &menuText[count * 2],
                &rowTypes[i], textBuf);
            break;

        case itemCategoryShield:
            vs_mainMenu_initUiShield(&vs_battle_inventory.shields[index],
                &menuText[count * 2], &rowTypes[i], textBuf);

            if (vs_battle_inventory.shields[index].isEquipped != 0) {
                rowType = 0xCA00;
            }
            break;

        case itemCategoryArmor:
            vs_mainMenu_initUiArmor(&vs_battle_inventory.armor[index],
                &menuText[count * 2], &rowTypes[i], textBuf);

            if (vs_battle_inventory.armor[index].bodyPart != 0) {
                rowType = 0xCA00;
            }
            break;

        case itemCategoryGem:
            vs_mainMenu_setUiGem(&vs_battle_inventory.gems[index], &menuText[count * 2],
                &rowTypes[i], textBuf);
            break;

        case itemCategoryMisc: {
            u_int skillId;
            vs_mainMenu_setUiItem(&vs_battle_inventory.misc[index], &menuText[count * 2],
                &rowTypes[i], textBuf);
#ifdef _ITEMMENU
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

            _miscSkills[count] = skillId;
#endif
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