#include "30.h"
#include "src/MENU/MAINMENU.PRG/C48.h"
#include "src/MENU/MAINMENU.PRG/2D10.h"
#include "src/MENU/MAINMENU.PRG/58EC.h"
#include "src/BATTLE/BATTLE.PRG/146C.h"
#include "src/BATTLE/BATTLE.PRG/5BF94.h"
#include "build/assets/MENU/MENU1.PRG/strings.h"
#include "build/assets/BATTLE/BATTLE.PRG/menuStrings.h"

/**
 * Prints the HP cost of a Break Art using skill data.
 */
static void _setHPCost(int id)
{
    static char _digitBuffer[16];

    int flags;
    int i;
    int cost;

    flags = vs_battle_getSkillFlags(0, id);
    vs_mainmenu_setSkillCost(1, "HP", 8, (flags >> 1) & 1);

    cost = vs_main_skills[id].cost;
    _digitBuffer[15] = 0;

    i = 15;
    do {
        --i;
        cost = vs_battle_toBCD(cost);
        _digitBuffer[i] = (cost & 0xF) + '0';
        cost >>= 4;
    } while (cost != 0);

    --i;
    _digitBuffer[i] = '#';

    vs_mainmenu_setSkillCost(0, &_digitBuffer[i], 72, (flags >> 1) & 1);
}

/**
 * Prints kills needed to unlock the next Break Art
 * @param row Effectively the count of already unlocked arts
 */
static void _setNextArtUnlockPointsRemaining(int xOffset, int weaponCategory, int row)
{
    char pointsBuf[16];
    int pos;
    int points;
    int i;
    char* pointsStr;

    int category = weaponCategory;
    category %= 10;

    i = vs_main_artsStatus.artsLearned[category];

    if (i == 4) {
        return;
    }

    points = vs_main_artsStatus.kills.weaponCategories[category];
    points = vs_main_artsPointsRequirements[category][i] - points;

    if (points < 0) {
        points = 0;
    }

    pos = (xOffset + 206) | (((row * 16) + 50) << 16);
    pointsBuf[14] = 'T';
    pointsBuf[15] = 0;
    pointsBuf[13] = 'P';

    i = 12;

    do {
        points = vs_battle_toBCD(points);
        pointsBuf[i] = (points & 0xF) + '0';
        points = points >> 4;
        --i;
    } while (points != 0);

    pointsStr = pointsBuf + i;
    pointsStr[0] = '#';

    vs_battle_renderTextRaw("NEXT", pos, NULL);
    vs_battle_renderTextRaw(pointsStr, pos + 96, NULL);
}

static u_short _strings[] = {
#include "build/assets/MENU/MENU1.PRG/strings.vsString"
};

enum drawArtsListOpt { opt_forceCursorMemory = 0x10 };

/**
 * Displays and manages the list of arts for the selected weapon category.
 *
 * @param typeCursorMem Packed value
 * - Bits 0-3: Weapon category
 * - Bits 4-32: Forces cursor memory
 * @return The selected row, negative if user cancelled, 0 otherwise.
 */
static int _weaponArtsMenu(int typeCursorMem)
{
    enum state { init, waitForSelection, returnSelection };

    static int state = 0;
    static int selectedRow = 0;
    static int forceCursorMemory = 0;
    static int weaponType = 0;
    static char isLastRow;
    static u_char animationIndex;
    static char artsLearned;
    static char remainingRows;
    static char _[12];
    static u_short skillIds[4];

    int i;

    if (typeCursorMem != 0) {
        vs_battle_menuItem_t* menuItem;
        isLastRow = 0;
        animationIndex = 10;
        forceCursorMemory = typeCursorMem >> 4;
        typeCursorMem &= 0xF;
        weaponType = typeCursorMem;
        menuItem = vs_battle_setMenuItem(
            10, 320, 34, 0x7E, 8, (char*)&_strings[_strings[(weaponType - 1) * 3]]);
        menuItem->state = 2;
        menuItem->targetX = 180;
        menuItem->selected = 1;
        menuItem->icon = typeCursorMem;
        state = init;
        return 0;
    }

    switch (state) {
    case init: {
        char* menuStrings[10];
        int rowTypes[5];
        int rowCount;
        int cursorMemory;

        if ((vs_battle_shortcutInvoked == 0) && (vs_mainmenu_ready() == 0)) {
            break;
        }

        rowCount = 0;

        for (i = 0; i < 4; ++i) {

            int skillId = vs_main_skills_daggerArt1 + (weaponType - 1) * 4 + i;

            if (vs_main_skills[skillId].unlocked) {
                menuStrings[rowCount * 2] = (char*)vs_main_skills[skillId].name;
                menuStrings[rowCount * 2 + 1] =
                    (char*)&_strings[_strings[VS_strings_INDEX_daggerArt1 + i
                                              + ((weaponType - 1) * 4)]];
                rowTypes[rowCount] = 0;

                if ((weaponType != vs_battle_characterState->equippedWeaponCategory)
                    || (vs_battle_getSkillFlags(0, skillId) != 0)) {
                    rowTypes[rowCount] = 1;
                }

                skillIds[rowCount++] = skillId;
            }
        }

        for (i = 0; i < 4; ++i) {
            if (D_800F4EA0 & 0x15F) {
                rowTypes[i] |= 1;
            }
        }

        if (vs_battle_shortcutInvoked == 0) {
            menuStrings[rowCount * 2] = (char*)&_strings[VS_strings_OFFSET_viewArts];
            menuStrings[rowCount * 2 + 1] =
                (char*)&_strings[VS_strings_OFFSET_viewArtsDesc];
            rowTypes[rowCount] = 2;
            skillIds[rowCount] = 0xFFFF;
            ++rowCount;
        }

        cursorMemory = vs_main_settings.cursorMemory;

        if (forceCursorMemory != 0) {
            vs_main_settings.cursorMemory = 1;
            forceCursorMemory = 0;
        }

        vs_mainmenu_setMenuRows(
            rowCount, (weaponType + 11) | 0x200, menuStrings, rowTypes);

        vs_main_settings.cursorMemory = cursorMemory;
        state = waitForSelection;
        artsLearned = rowCount;
        remainingRows = rowCount;

        break;
    }

    case waitForSelection:
        if (remainingRows != 0) {
            --remainingRows;
        }

        isLastRow = remainingRows == 0;
        selectedRow = vs_mainmenu_getSelectedRow() + 1;
        vs_mainMenu_isLevelledSpell = 0;

        if (selectedRow != menuSelectionConfirm) {

            isLastRow = 0;

            if (selectedRow > 0) {
                selectedRow = skillIds[selectedRow - 1];
            } else if (vs_battle_shortcutInvoked != 0) {
                selectedRow = menuSelectionQuit;
            }

            if (selectedRow == 0xFFFF) {
                vs_mainMenu_clearMenuExcept(1);
            } else {
                vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
                vs_mainMenu_dismissTextBox();
                vs_mainMenu_setNextMenuAction(menuActionNone);
            }

            state = returnSelection;
        } else {
            i = skillIds[vs_mainMenu_getConfirmedRow()];
            if (i != 0xFFFF) {
                _setHPCost(i);
            }
        }
        break;

    case returnSelection:
        if (vs_mainmenu_ready() != 0) {
            return selectedRow;
        }
        break;
    }

    if (isLastRow != 0) {
        if (animationIndex != 0) {
            --animationIndex;
        }
    } else {
        animationIndex = vs_battle_animationIndices[animationIndex];
    }

    _setNextArtUnlockPointsRemaining(
        vs_battle_rowAnimationSteps[animationIndex], weaponType, artsLearned);

    return 0;
}

/**
 * Displays and manages the first level weapon categories menu.
 *
 * @return The selected row, negative if user cancelled, 0 otherwise.
 */
static int _weaponCategoriesMenu(int initialize)
{
    enum state { init, waitForSelection, returnSelection };

    static int state = init;
    static int selectedRow = 0;

    if (initialize != 0) {
        vs_battle_menuItem_t* menuItem = vs_battle_setMenuItem(
            10, 320, 34, 0x7E, 8, (char*)&_strings[VS_strings_OFFSET_viewArts]);
        menuItem->state = 2;
        menuItem->targetX = 180;
        menuItem->selected = 1;
        state = init;
        return 0;
    }

    switch (state) {
    case init: {
        char* menuStrings[20];
        int rowTypes[10];
        int i;
        int j;

        if (vs_mainmenu_ready() == 0) {
            break;
        }

        for (i = 0; i < 10; ++i) {
            menuStrings[i * 2] = (char*)&_strings[_strings[i * 3]];
            menuStrings[i * 2 + 1] = (char*)&_strings[_strings[i * 3 + 1]];
            rowTypes[i] = 0x04000000 * (i + 1);
            for (j = 0; j < 4; ++j) {
                if (vs_main_skills[i * 4 + vs_main_skills_daggerArt1 + j].unlocked) {
                    break;
                }
            }
            if (j == 4) {
                menuStrings[i * 2 + 1] = (char*)&_strings[_strings[i * 3 + 2]];
                rowTypes[i] |= 1;
            } else if (i == (vs_battle_characterState->equippedWeaponCategory - 1)) {
                rowTypes[i] |= 4;
            }
        }

        vs_mainmenu_setMenuRows(10, (2 << 8) | 22, menuStrings, rowTypes);

        state = waitForSelection;
        break;
    }

    case waitForSelection:
        selectedRow = vs_mainmenu_getSelectedRow() + 1;

        if (selectedRow != menuSelectionConfirm) {
            if (selectedRow == menuSelectionQuit) {
                vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
                vs_mainMenu_dismissTextBox();
                vs_mainMenu_setNextMenuAction(menuActionNone);
            } else {
                vs_mainMenu_clearMenuExcept(1);
            }
            state = returnSelection;
        }
        break;

    case returnSelection:
        if (vs_mainmenu_ready() != 0) {
            return selectedRow;
        }
        break;
    }
    return 0;
}

/**
 * Draws header
 */
static void _setMenuHeader(void)
{
    vs_battle_menuItem_t* menuItem = vs_battle_setMenuItem(1, 320, 18, 0x8C, 8,
        (char*)&vs_battle_menuStrings
            [vs_battle_menuStrings[VS_menuStrings_INDEX_breakArts]]);

    menuItem->state = 2;
    menuItem->targetX = 180;
    menuItem->selected = 1;

    vs_mainMenu_setNextMenuAction(menuActionMenu);
    vs_mainMenu_initTextBox();
}

/**
 * Module entrypoint.
 *
 * @return Returns 1 if menu is exiting for any reason, 0 otherwise
 */
int vs_menu1_exec(char* state)
{
    enum state {
        none,
        init = 3,
        artsInit,
        artsInitWithTitle,
        artsMenu,
        weaponCategoryMenu,
        exitToMainMenu,
        executeArt,
        exit
    };

    static int weaponType = 0;

    switch (*state) {
    case init:
        if (vs_mainmenu_ready() == 0) {
            break;
        }

        vs_mainMenu_initTextBox();

        weaponType = vs_battle_characterState->equippedWeaponCategory;
        // Fallthrough

    case artsInit:
        _weaponArtsMenu(weaponType);
        *state = artsMenu;
        break;

    case artsInitWithTitle:
        _setMenuHeader();
        _weaponArtsMenu(weaponType | opt_forceCursorMemory);
        *state = artsMenu;
        break;

    case artsMenu: {
        int selectedRow = _weaponArtsMenu(0);

        if (selectedRow == menuSelectionConfirm) {
            break;
        }

        if (selectedRow > 0) {
            if (selectedRow == menuSelectionBack) {
                *state = weaponCategoryMenu;
                _weaponCategoriesMenu(1);
            } else {
                D_800F4E98.executeAbility.s32 = selectedRow;
                vs_battle_executeAbilityType = 5;
                *state = executeArt;
            }
        } else if (selectedRow != menuSelectionQuit) {
            *state = exitToMainMenu;
        } else {
            *state = exit;
        }

        break;
    }

    case weaponCategoryMenu: {
        int row = _weaponCategoriesMenu(0);

        if (row == 0) {
            break;
        }

        if (row == menuSelectionQuit) {
            *state = exit;
        } else {
            if (row > 0) {
                weaponType = row;
            }

            *state = artsInit;
        }

        break;
    }

    case exitToMainMenu:
        vs_mainMenu_dismissTextBox();
        vs_mainMenu_setNextMenuAction(menuActionNone);

        if (vs_mainmenu_ready() != 0) {
            *state = none;
            return 1;
        }

        break;

    case executeArt:
        if (vs_mainmenu_ready() != 0) {
            D_800F4E98.unk2 = 6;
            vs_battle_menuState.returnState = vs_battle_menuState.currentState;
            vs_battle_menuState.currentState = 2;
            *state = none;
            return 1;
        }

        break;

    case exit:
        vs_mainMenu_dismissTextBox();
        vs_mainMenu_setNextMenuAction(menuActionNone);

        if (vs_mainmenu_ready() != 0) {
            vs_battle_menuState.currentState = 2;
            *state = none;
            return 1;
        }

        break;
    }

    return 0;
}

static char _ __attribute__((unused));
