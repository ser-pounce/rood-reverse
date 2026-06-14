#include "15AC.h"
#include "84.h"
#include "src/SLUS_010.40/main.h"
#include "src/MENU/MAINMENU.PRG/C48.h"
#include "src/MENU/MAINMENU.PRG/2D10.h"
#include "src/MENU/MAINMENU.PRG/58EC.h"
#include "build/assets/BATTLE/BATTLE.PRG/menuStrings.h"
#include "build/assets/MENU/MENU0.PRG/magic.h"
#include "build/assets/MENU/MENU0.PRG/teleportation.h"

/**
 * Displays and manages Teleport menu.
 *
 * @param init 0 = Process menu, initialize otherwise
 * @return Packed teleport info
 *   Bits 0 - 9: Destination room id
 *   Bits 10 - 14: Value from savePointData bits 16-21
 *   Bits 14 - 19: Value from savePointData bits 24-29
 *   Bits 19 - 32: Teleport cost
 * Negative values for user cancellation, 0 otherwise
 */
static int _teleportMenu(int init)
{
    enum state { initTeleport, handleInput, returnIfReady };

    static u_char availableSavePoints[48];
    static u_short teleportCosts[48];
    static int selectedRow;
    static int currentMp;
    static char state;

    char* menuStrings[96];
    int rowTypes[48];
    int nearestSavePoint;
    int i;
    int rowCount;
    int savePointState;

    if (init != 0) {
        vs_mainMenu_flyoutMenuRightAndHoistSelection(4, 1);
        state = initTeleport;
        currentMp = vs_battle_characterState->unk3C->currentMP;
        return 0;
    }

    switch (state) {
    case initTeleport:
        if (vs_mainmenu_ready() == 0) {
            break;
        }
        rowCount = 0;
        for (i = 0; i < 48; ++i) {
            savePointState = vs_main_stateFlags.savePointStates[i];
            if (savePointState == 0) {
                continue;
            }
            menuStrings[2 * rowCount] =
                (char*)(&_teleportationStrings[_teleportationStrings
                        [i * 2 + VS_teleportation_INDEX_locations]]);
            menuStrings[(rowCount * 2) + 1] =
                (char*)(&_teleportationStrings[_teleportationStrings
                        [i * 2 + VS_teleportation_INDEX_locations + 1]]);
            teleportCosts[rowCount] = _getTeleportCost(i);
            rowTypes[rowCount] =
                (savePointState == 2) | (currentMp < teleportCosts[rowCount]);
            if (teleportCosts[rowCount] == 15) {
                rowTypes[rowCount] |= 4;
                nearestSavePoint = rowCount;
            }
            if (savePointState == 2) {
                menuStrings[(rowCount * 2) + 1] =
                    (char*)(_teleportationStrings
                            + VS_teleportation_OFFSET_teleportationDisabled);
            }
            availableSavePoints[rowCount] = i;
            ++rowCount;
        }

        if (D_800F4EA0 & 0xB7) {
            for (i = 0; i < 48; ++i) {
                rowTypes[i] |= 1;
            }
        }
        if ((rowCount < 9) || (nearestSavePoint < 8)) {
            D_800F4EE8.cursorMemories[22] = nearestSavePoint;
            D_800F4EE8.cursorMemories[23] = 0;
        } else if (nearestSavePoint >= (rowCount - 7)) {
            D_800F4EE8.cursorMemories[22] = nearestSavePoint - (rowCount - 8);
            D_800F4EE8.cursorMemories[23] = rowCount - 8;
        } else {
            D_800F4EE8.cursorMemories[22] = 3;
            D_800F4EE8.cursorMemories[23] = nearestSavePoint - 3;
        }
        savePointState = vs_main_settings.cursorMemory;
        vs_main_settings.cursorMemory = 1;
        vs_mainmenu_setMenuRows(rowCount, (2 << 8) | 11, menuStrings, rowTypes);
        state = handleInput;
        vs_main_settings.cursorMemory = savePointState;
        break;

    case handleInput:
        selectedRow = vs_mainmenu_getSelectedRow() + 1;
        if (selectedRow != 0) {
            vs_mainMenu_isLevelledSpell = 0;
            if (selectedRow == (-1)) {
                vs_mainMenu_clearMenuExcept(0);
            } else {
                vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
                vs_mainMenu_dismissTextBox();
                vs_mainMenu_setNextMenuAction(menuActionNone);
            }
            state = returnIfReady;
        } else {
            i = teleportCosts[vs_mainMenu_getConfirmedRow()];
            _setMPCostDirect(i, currentMp < i);
        }
        break;

    case returnIfReady:
        if (vs_mainmenu_ready() != 0) {
            if (selectedRow > 0) {
                int v1;
                int v0;
                int a0;
                int a2 = availableSavePoints[selectedRow - 1];
                i = _savePointData[a2] + 1;
                v1 = i & 0x1FF;
                init = ~0x3E00;
                v0 = (rowCount & ~0x1FF) | v1;
                v1 = (i >> 7) & 0x3E00;
                v0 &= init;
                v0 |= v1;
                a0 = (i >> 0x18) & 0x1F;
                a0 <<= 0xE;
                v1 = teleportCosts[selectedRow - 1] << 0x13;
                v0 &= 0x3FFF;
                return v0 | a0 | v1;
            }
            return selectedRow;
        }
        break;
    }
    return 0;
}

/**
 * Draws header when cancelling back before casting.
 */
static void _setMenuHeader(void)
{
    vs_battle_menuItem_t* menuItem;

    menuItem = vs_battle_setMenuItem(0, 320, 18, 0x8C, 8,
        (char*)&vs_battle_menuStrings[vs_battle_menuStrings[VS_menuStrings_INDEX_magic]]);
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
int vs_menu0_exec(char* state)
{
    enum state {
        none,
        handleShortcut = 3,
        initSubmenu,
        handleSubmenu,
        initWarlockMenu,
        warlockMenu,
        initShamanMenu,
        shamanMenu,
        initSorcererMenu,
        sorcererMenu,
        initEnchanterMenu,
        enchanterMenu,
        teleportMenu,
        exitToMainMenu,
        executeMagic,
        exit
    };

    char* menuStrings[10];
    int rowTypes[5];
    int selectedRow;
    int j;
    int i;

    switch (*state) {
    case handleShortcut:
        if (vs_mainmenu_ready() == 0) {
            break;
        }

        vs_mainMenu_initTextBox();

        i = vs_battle_shortcutInvoked;

        if (i != 0) {
            enum shortcutMagicMenu { warlock = 1, shaman, sorcerer, enchanter };
            vs_battle_setMenuItem(i + 9, 0x140, 0x22, 0x8C, 8,
                (char*)&_magicStrings[_magicStrings[(i * 3) - 3]])
                ->selected = 1;
            switch (i) {
            case warlock:
                *state = warlockMenu;
                _warlockMagicMenu(1);
                break;
            case shaman:
                *state = shamanMenu;
                _shamanMagicMenu(1);
                break;
            case sorcerer:
                *state = sorcererMenu;
                _sorcererMagicMenu(1);
                break;
            case enchanter:
                *state = enchanterMenu;
                _enchanterMagicMenu(1);
                break;
            }
            break;
        }
        // Fallthrough

    case initSubmenu:
        for (i = 0; i < 4; ++i) {
            menuStrings[i * 2] =
                (char*)&_magicStrings[_magicStrings[i * 3 + VS_magic_INDEX_warlock]];
            menuStrings[i * 2 + 1] =
                (char*)&_magicStrings[_magicStrings[i * 3 + VS_magic_INDEX_warlockDesc]];
            rowTypes[i] = 0;

            if (vs_battle_isSpellClassUnlocked(i) == 0) {
                rowTypes[i] |= 1;
                menuStrings[i * 2 + 1] =
                    (char*)&_magicStrings[_magicStrings[i * 3
                                                        + VS_magic_INDEX_warlockLocked]];
            }
        }

        if (vs_main_stateFlags.unkB5 != 0) {
            for (j = 0; j < 48; ++j) {
                if (vs_main_stateFlags.savePointStates[j] != 0) {
                    break;
                }
            }

            menuStrings[i * 2] =
                (char*)(_teleportationStrings + VS_teleportation_OFFSET_teleportation);

            menuStrings[i * 2 + 1] =
                (func_8008A4FC() != 0) && (vs_main_stateFlags.unkB5 == 2)
                    ? (char*)(_teleportationStrings
                              + VS_teleportation_OFFSET_teleportationDisabled)
                    : (char*)(_teleportationStrings
                              + VS_teleportation_OFFSET_teleportationDesc);

            if ((func_8008A4FC() != 0) && (vs_main_stateFlags.unkB5 == 2)) {
                menuStrings[i * 2 + 1] =
                    (char*)(_teleportationStrings
                            + VS_teleportation_OFFSET_teleportationDisabled);
            }

            rowTypes[i++] =
                ((j == 48) || (vs_main_stateFlags.unkB5 == 2) || (func_8008A4FC() == 0));
        }

        j = vs_main_settings.cursorMemory;

        if (*state != handleShortcut) {
            vs_main_settings.cursorMemory = 1;
        }

        vs_mainmenu_setMenuRows(i, (1 << 8) | 5, menuStrings, rowTypes);
        vs_main_settings.cursorMemory = j;
        *state = handleSubmenu;

        break;

    case handleSubmenu:
        selectedRow = vs_mainmenu_getSelectedRow();
        i = selectedRow + 1;

        if (i == 0) {
            break;
        }

        if (i > 0) {
            enum magicSubMenu { warlock, shaman, sorcerer, enchanter, teleport };
            switch (selectedRow) {
            case warlock:
                *state = warlockMenu;
                _warlockMagicMenu(1);
                break;
            case shaman:
                *state = shamanMenu;
                _shamanMagicMenu(1);
                break;
            case sorcerer:
                *state = sorcererMenu;
                _sorcererMagicMenu(1);
                break;
            case enchanter:
                *state = enchanterMenu;
                _enchanterMagicMenu(1);
                break;
            case teleport:
                *state = teleportMenu;
                _teleportMenu(1);
                break;
            }
        } else {
            if (i == menuSelectionQuit) {
                vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
                *state = exit;
            } else {
                vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
                *state = exitToMainMenu;
            }
        }

        break;

    case initWarlockMenu:
        _setMenuHeader();
        vs_battle_setMenuItem(
            0xA, 0x140, 0x22, 0x7E, 8, (char*)(_magicStrings + VS_magic_OFFSET_warlock))
            ->selected = 1;
        _warlockMagicMenu(2);

        *state = warlockMenu;
        break;

    case warlockMenu:
        i = _warlockMagicMenu(0);

        if (i == 0) {
            break;
        }

        if (i > 0) {
            D_800F4E98.executeAbility.s32 = i;
            vs_battle_executeAbilityType = 6;
            *state = executeMagic;
        } else {
            if (i == -2) {
                *state = exit;
            } else {
                *state = initSubmenu;
            }
        }

        break;

    case initShamanMenu:
        _setMenuHeader();
        vs_battle_setMenuItem(
            11, 320, 34, 0x7E, 8, (char*)(_magicStrings + VS_magic_OFFSET_shaman))
            ->selected = 1;
        _shamanMagicMenu(2);

        *state = shamanMenu;
        break;

    case shamanMenu:
        i = _shamanMagicMenu(0);

        if (i == 0) {
            break;
        }

        if (i > 0) {
            D_800F4E98.executeAbility.s32 = i;
            vs_battle_executeAbilityType = 8;
            *state = executeMagic;
        } else {
            if (i == -2) {
                *state = exit;
            } else {
                *state = initSubmenu;
            }
        }

        break;

    case initSorcererMenu:
        _setMenuHeader();
        vs_battle_setMenuItem(
            12, 320, 34, 0x7E, 8, (char*)(_magicStrings + VS_magic_OFFSET_sorcerer))
            ->selected = 1;
        _sorcererMagicMenu(2);

        *state = sorcererMenu;
        break;

    case sorcererMenu:
        i = _sorcererMagicMenu(0);

        if (i == 0) {
            break;
        }

        if (i > 0) {
            D_800F4E98.executeAbility.s32 = i;
            vs_battle_executeAbilityType = 10;
            *state = executeMagic;
        } else {
            if (i == -2) {
                *state = exit;
            } else {
                *state = initSubmenu;
            }
        }

        break;

    case initEnchanterMenu:
        _setMenuHeader();
        vs_battle_setMenuItem(
            13, 320, 34, 0x7E, 8, (char*)(_magicStrings + VS_magic_OFFSET_enchanter))
            ->selected = 1;
        _enchanterMagicMenu(2);

        *state = enchanterMenu;
        break;

    case enchanterMenu:
        i = _enchanterMagicMenu(0);

        if (i == 0) {
            break;
        }

        if (i > 0) {
            D_800F4E98.executeAbility.s32 = i;
            vs_battle_executeAbilityType = 12;
            *state = executeMagic;
        } else {
            if (i == -2) {
                *state = exit;
            } else {
                *state = initSubmenu;
            }
        }

        break;

    case teleportMenu:
        i = _teleportMenu(0);

        if (i == 0) {
            break;
        }

        if (i > 0) {
            D_800F4E98.unk2 = 0xA;
            D_800F4E98.executeAbility.s32 = i - 1;
            *state = exit;
        } else {
            if (i == -2) {
                *state = exit;
            } else {
                *state = initSubmenu;
            }
        }

        break;

    case exitToMainMenu:
        vs_mainMenu_dismissTextBox();
        vs_mainMenu_setNextMenuAction(menuActionNone);

        if (vs_mainmenu_ready() != 0) {
            *state = none;
            return 1;
        }

        break;

    case executeMagic:
        if (vs_mainmenu_ready() != 0) {
            D_800F4E98.unk2 = 7;
            vs_battle_menuState.returnState = vs_battle_menuState.currentState;
            vs_battle_menuState.currentState = 1;
            *state = none;
            return 1;
        }

        break;

    case exit:
        vs_mainMenu_dismissTextBox();
        vs_mainMenu_setNextMenuAction(menuActionNone);

        if (vs_mainmenu_ready() != 0) {
            vs_battle_menuState.currentState = 1;
            *state = none;
            return 1;
        }

        break;
    }
    return 0;
}
