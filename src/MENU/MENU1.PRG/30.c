#include "30.h"
#include "../MAINMENU.PRG/C48.h"
#include "../MAINMENU.PRG/413C.h"
#include "../../BATTLE/BATTLE.PRG/146C.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"
#include "../../../build/src/BATTLE/BATTLE.PRG/menuStrings.h"
#include "../../../build/src/MENU/MENU1.PRG/strings.h"

static void _setArtCost(int art)
{
    static char _digitBuffer[16];

    int flags;
    int i;
    int cost;

    flags = vs_battle_getSkillFlags(0, art);
    vs_mainmenu_setAbilityCost(1, "HP", 8, (flags >> 1) & 1);
    cost = vs_main_skills[art].cost;
    _digitBuffer[15] = 0;

    i = 15;
    do {
        --i;
        cost = vs_battle_toBCD(cost);
        _digitBuffer[i] = (cost & 0xF) + 0x30;
        cost >>= 4;
    } while (cost != 0);

    --i;
    _digitBuffer[i] = '#';
    vs_mainmenu_setAbilityCost(0, &_digitBuffer[i], 72, (flags >> 1) & 1);
}

static void _drawPointsRemaining(int xOffset, int weaponCategory, int artsLearned)
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
    pos = (xOffset + 206) | (((artsLearned * 16) + 50) << 16);
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
    *pointsStr = '#';
    vs_battle_renderTextRaw("NEXT", pos, NULL);
    vs_battle_renderTextRaw(pointsStr, pos + 96, NULL);
}

u_short _strings[] = {
#include "../../assets/MENU/MENU1.PRG/strings.dat"
};

enum drawArtsListOpt { opt_forceCursorMemory = 0x10 };

enum menuSelection { selectionBack = -2 };

static int _drawArtsList(int typeCursorMem)
{
    enum state { init };

    static int state = 0;
    static int selectedRow = 0;
    static int forceCursorMemory = 0;
    static int weaponType = 0;
    static char D_8010452C;
    static u_char animationIndex;
    static char artsLearned;
    static char D_8010452F;
    static char _[12];
    static u_short skillIds[4];

    int i;

    if (typeCursorMem != 0) {
        vs_battle_menuItem_t* menuItem;
        D_8010452C = 0;
        animationIndex = 10;
        forceCursorMemory = typeCursorMem >> 4;
        typeCursorMem &= 0xF;
        weaponType = typeCursorMem;
        menuItem = vs_battle_setMenuItem(
            10, 320, 34, 0x7E, 8, (char*)&_strings[_strings[(weaponType - 1) * 3]]);
        menuItem->state = 2;
        menuItem->x = 180;
        menuItem->selected = 1;
        menuItem->weaponType = typeCursorMem;
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
            if ((vs_main_skills[skillId].flags >> 0xF) & 1) {
                menuStrings[rowCount * 2] = (char*)vs_main_skills[skillId].name;
                menuStrings[rowCount * 2 + 1]
                    = (char*)&_strings[_strings[VS_strings_INDEX_daggerArt1 + i
                        + ((weaponType - 1) * 4)]];
                rowTypes[rowCount] = 0;
                if ((weaponType != vs_battle_characterState->equippedWeaponType)
                    || (vs_battle_getSkillFlags(0, skillId) != 0)) {
                    rowTypes[rowCount] = 1;
                }
                skillIds[rowCount] = skillId;
                ++rowCount;
            }
        }

        for (i = 0; i < 4; ++i) {
            if (D_800F4EA0 & 0x15F) {
                rowTypes[i] |= 1;
            }
        }

        if (vs_battle_shortcutInvoked == 0) {
            menuStrings[rowCount * 2] = (char*)&_strings[VS_strings_OFFSET_viewArts];
            menuStrings[rowCount * 2 + 1]
                = (char*)&_strings[VS_strings_OFFSET_viewArtsDesc];
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
        state = 1;
        artsLearned = rowCount;
        D_8010452F = rowCount;
        break;
    }
    case 1:
        if (D_8010452F != 0) {
            --D_8010452F;
        }
        D_8010452C = D_8010452F == 0;
        selectedRow = vs_mainmenu_getSelectedRow() + 1;
        D_801022D4 = 0;
        if (selectedRow != 0) {
            D_8010452C = 0;
            if (selectedRow > 0) {
                selectedRow = skillIds[selectedRow - 1];
            } else if (vs_battle_shortcutInvoked != 0) {
                selectedRow = selectionBack;
            }
            if (selectedRow == 0xFFFF) {
                func_800FA8E0(1);
            } else {
                func_800FA8E0(40);
                func_800FFBA8();
                func_800FFA88(0);
            }
            state = 2;
        } else {
            i = skillIds[func_801008B0()];
            if (i != 0xFFFF) {
                _setArtCost(i);
            }
        }
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            return selectedRow;
        }
        break;
    }

    if (D_8010452C != 0) {
        if (animationIndex != 0) {
            --animationIndex;
        }
    } else {
        animationIndex = D_800EBC7C[animationIndex];
    }
    _drawPointsRemaining(
        vs_battle_rowAnimationSteps[animationIndex], weaponType, artsLearned);
    return 0;
}

static int _drawWeaponTypeList(int init)
{
    enum state { init_e, handle_input, returnRow };

    static int state = 0;
    static int selectedRow = 0;

    if (init != 0) {
        vs_battle_menuItem_t* menuItem = vs_battle_setMenuItem(
            10, 320, 34, 0x7E, 8, (char*)(_strings + VS_strings_OFFSET_viewArts));
        menuItem->state = 2;
        menuItem->x = 180;
        menuItem->selected = 1;
        state = init_e;
        return 0;
    }

    switch (state) {
    case init_e: {
        char* menuStrings[20];
        int rowType[10];
        int i;
        int j;

        if (vs_mainmenu_ready() == 0) {
            break;
        }
        for (i = 0; i < 10; ++i) {
            menuStrings[i * 2] = (char*)&_strings[_strings[i * 3]];
            menuStrings[i * 2 + 1] = (char*)&_strings[_strings[i * 3 + 1]];
            rowType[i] = 0x04000000 * (i + 1);
            for (j = 0; j < 4; ++j) {
                if ((vs_main_skills[i * 4 + vs_main_skills_daggerArt1 + j].flags >> 0xF)
                    & 1) {
                    break;
                }
            }
            if (j == 4) {
                menuStrings[i * 2 + 1] = (char*)&_strings[_strings[i * 3 + 2]];
                rowType[i] |= 1;
            } else if (i == (vs_battle_characterState->equippedWeaponType - 1)) {
                rowType[i] |= 4;
            }
        }
        vs_mainmenu_setMenuRows(10, 0x216, (char**)menuStrings, rowType);
        state = handle_input;
        break;
    }
    case handle_input:
        selectedRow = vs_mainmenu_getSelectedRow() + 1;
        if (selectedRow != 0) {
            if (selectedRow == selectionBack) {
                func_800FA8E0(40);
                func_800FFBA8();
                func_800FFA88(0);
            } else {
                func_800FA8E0(1);
            }
            state = returnRow;
        }
        break;
    case returnRow:
        if (vs_mainmenu_ready() != 0) {
            return selectedRow;
        }
        break;
    }
    return 0;
}

static void _setMenuTitle()
{
    vs_battle_menuItem_t* menuItem = vs_battle_setMenuItem(1, 320, 18, 0x8C, 8,
        (char*)&vs_battle_menuStrings
            [vs_battle_menuStrings[VS_menuStrings_INDEX_breakArts]]);
    menuItem->state = 2;
    menuItem->x = 180;
    menuItem->selected = 1;
    func_800FFA88(2);
    func_800FFBC8();
}

int vs_menu1_exec(char* state)
{
    enum state {
        none,
        init = 3,
        artsInit,
        artsInitWithTitle,
        drawArts,
        drawWeaponTypes,
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
        func_800FFBC8();
        weaponType = vs_battle_characterState->equippedWeaponType;
        // Fallthrough
    case artsInit:
        _drawArtsList(weaponType);
        *state = drawArts;
        break;
    case artsInitWithTitle:
        _setMenuTitle();
        _drawArtsList(weaponType | opt_forceCursorMemory);
        *state = drawArts;
        break;
    case drawArts: {
        int row = _drawArtsList(0);
        if (row == 0) {
            break;
        }
        if (row > 0) {
            if (row == 0xFFFF) {
                *state = drawWeaponTypes;
                _drawWeaponTypeList(1);
            } else {
                vs_battle_executeAbility = row;
                vs_battle_executeAbilityType = 5;
                *state = executeArt;
            }
        } else if (row != selectionBack) {
            *state = exitToMainMenu;
        } else {
            *state = exit;
        }
        break;
    }
    case drawWeaponTypes: {
        int row = _drawWeaponTypeList(0);
        if (row == 0) {
            break;
        }
        if (row == selectionBack) {
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
        func_800FFBA8();
        func_800FFA88(0);
        if (vs_mainmenu_ready() != 0) {
            *state = none;
            return 1;
        }
        break;
    case executeArt:
        if (vs_mainmenu_ready() != 0) {
            D_800F4E9A = 6;
            vs_battle_menuState.returnState = vs_battle_menuState.currentState;
            vs_battle_menuState.currentState = 2;
            *state = none;
            return 1;
        }
        break;
    case exit:
        func_800FFBA8();
        func_800FFA88(0);
        if (vs_mainmenu_ready() != 0) {
            vs_battle_menuState.currentState = 2;
            *state = none;
            return 1;
        }
        break;
    }
    return 0;
}
