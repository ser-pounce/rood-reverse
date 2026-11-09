#include "88.h"
#include "src/SLUS_010.40/gameFlags.h"
#include "src/SLUS_010.40/gameState.h"
#include "src/SLUS_010.40/pad.h"
#include "src/SLUS_010.40/sound.h"
#include "src/BATTLE/BATTLE.PRG/battleUi.h"
#include "src/MENU/MAINMENU.PRG/2D10.h"
#include "src/MENU/MAINMENU.PRG/58EC.h"
#include "src/MENU/MAINMENU.PRG/C48.h"
#include "build/assets/MENU/MENU8.PRG/menu.h"

static u_short menuStringTable[] = {
#include "build/assets/MENU/MENU8.PRG/menu.vsString"
};

static char simpleMapValues[] = { 3, 1, 0 };

/**
 * Runs the simple map setting submenu.
 *
 * @return Zero while initializing or waiting, -2 when returning to battle, or
 * the selected option row plus one.
 */
static int simpleMapOptionMenu(int init)
{
    static int state = 0;
    static int selectedRow = 0;

    char* menuStrings[6];
    int rowTypes[3];
    int i;

    if (init != 0) {
        state = 0;
        return 0;
    }
    switch (state) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            for (i = 0; i < 3; ++i) {
                menuStrings[i * 2] =
                    (char*)&menuStringTable[menuStringTable[i * 2 + VS_menu_INDEX_frame]];
                menuStrings[i * 2 + 1] =
                    (char*)&menuStringTable[menuStringTable[i * 2
                                                            + VS_menu_INDEX_frameDesc]];
                rowTypes[i] = 0;
            }
            for (i = 0; i < 3; ++i) {
                if (vs_main_settings.simpleMap == simpleMapValues[i]) {
                    rowTypes[i] |= 4;
                }
            }
            vs_mainmenu_setMenuRows(3, 0x246, menuStrings, rowTypes);
            state = 1;
        }
        break;
    case 1:
        selectedRow = vs_mainmenu_getSelectedRow() + 1;
        if (selectedRow != 0) {
            if (selectedRow == -2) {
                vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
                vs_mainMenu_dismissInformationBox();
                vs_mainMenu_setMenuCommand(menuActionNone);
            } else {
                vs_mainMenu_clearMenuExcept(7);
            }
            state = 2;
        }
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            return selectedRow;
        }
        break;
    }
    return 0;
}

/**
 * Runs the ability timing setting submenu.
 *
 * @return Zero while initializing or waiting, -2 when returning to battle, or
 * the selected option row plus one.
 */
static int abilityTimingOptionMenu(int init)
{
    static int state = 0;
    static int selectedRow = 0;

    char* menuStrings[4];
    int rowTypes[2];
    int i;

    if (init != 0) {
        state = 0;
        return 0;
    }
    switch (state) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            for (i = 0; i < 2; ++i) {
                menuStrings[i * 2] = (char*)&menuStringTable
                    [menuStringTable[i * 2 + VS_menu_INDEX_abilityTimingOn]];
                menuStrings[i * 2 + 1] = (char*)&menuStringTable
                    [menuStringTable[i * 2 + VS_menu_INDEX_abilityTimingOnDesc]];
                rowTypes[i] = 0;
            }
            i = 1 - vs_main_settings.abilityTimingDisplay;
            rowTypes[i] |= 4;
            vs_mainmenu_setMenuRows(2, 0x247, menuStrings, rowTypes);
            state = 1;
        }
        break;
    case 1:
        selectedRow = vs_mainmenu_getSelectedRow() + 1;
        if (selectedRow != 0) {
            if (selectedRow == -2) {
                vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
                vs_mainMenu_dismissInformationBox();
                vs_mainMenu_setMenuCommand(menuActionNone);
            } else {
                vs_mainMenu_clearMenuExcept(7);
            }
            state = 2;
        }
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            return selectedRow;
        }
        break;
    }
    return 0;
}

/**
 * Runs the weapon status setting submenu.
 *
 * @return Zero while initializing or waiting, -2 when returning to battle, or
 * the selected option row plus one.
 */
static int weaponStatusOptionMenu(int init)
{
    static int state = 0;
    static int selectedRow = 0;

    char* menuStrings[4];
    int rowTypes[2];
    int i;

    if (init != 0) {
        state = 0;
        return 0;
    }
    switch (state) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            for (i = 0; i < 2; ++i) {
                menuStrings[i * 2] = (char*)&menuStringTable
                    [menuStringTable[i * 2 + VS_menu_INDEX_weaponStatusOn]];
                menuStrings[i * 2 + 1] = (char*)&menuStringTable
                    [menuStringTable[i * 2 + VS_menu_INDEX_weaponStatusOnDesc]];
                rowTypes[i] = 0;
            }
            i = 1 - vs_main_settings.weaponStatChange;
            rowTypes[i] |= 4;
            vs_mainmenu_setMenuRows(2, 0x248, menuStrings, rowTypes);
            state = 1;
        }
        break;
    case 1:
        selectedRow = vs_mainmenu_getSelectedRow() + 1;
        if (selectedRow != 0) {
            if (selectedRow == -2) {
                vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
                vs_mainMenu_dismissInformationBox();
                vs_mainMenu_setMenuCommand(menuActionNone);
            } else {
                vs_mainMenu_clearMenuExcept(7);
            }
            state = 2;
        }
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            return selectedRow;
        }
        break;
    }
    return 0;
}

/**
 * Runs the armor status setting submenu.
 *
 * @return Zero while initializing or waiting, -2 when returning to battle, or
 * the selected option row plus one.
 */
static int armorStatusOptionMenu(int init)
{
    static int state = 0;
    static int selectedRow = 0;

    char* menuStrings[4];
    int rowTypes[2];
    int i;

    if (init != 0) {
        state = 0;
        return 0;
    }
    switch (state) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            for (i = 0; i < 2; ++i) {
                menuStrings[i * 2] = (char*)&menuStringTable
                    [menuStringTable[i * 2 + VS_menu_INDEX_armorStatusOn]];
                menuStrings[i * 2 + 1] = (char*)&menuStringTable
                    [menuStringTable[i * 2 + VS_menu_INDEX_armorStatusOnDesc]];
                rowTypes[i] = 0;
            }
            i = 1 - vs_main_settings.armorStatChange;
            rowTypes[i] |= 4;
            vs_mainmenu_setMenuRows(2, 0x249, menuStrings, rowTypes);
            state = 1;
        }
        break;
    case 1:
        selectedRow = vs_mainmenu_getSelectedRow() + 1;
        if (selectedRow != 0) {
            if (selectedRow == -2) {
                vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
                vs_mainMenu_dismissInformationBox();
                vs_mainMenu_setMenuCommand(menuActionNone);
            } else {
                vs_mainMenu_clearMenuExcept(7);
            }
            state = 2;
        }
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            return selectedRow;
        }
        break;
    }
    return 0;
}

/**
 * Runs the cursor memory setting submenu.
 *
 * @return Zero while initializing or waiting, -2 when returning to battle, or
 * the selected option row plus one.
 */
static int cursorMemoryOptionMenu(int init)
{
    static int state = 0;
    static int selectedRow = 0;

    char* menuStrings[4];
    int rowTypes[2];
    int i;

    if (init != 0) {
        state = 0;
        return 0;
    }
    switch (state) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            for (i = 0; i < 2; ++i) {
                menuStrings[i * 2] = (char*)&menuStringTable
                    [menuStringTable[i * 2 + VS_menu_INDEX_cursorMemoryOn]];
                menuStrings[i * 2 + 1] = (char*)&menuStringTable
                    [menuStringTable[i * 2 + VS_menu_INDEX_cursorMemoryOnDesc]];
                rowTypes[i] = 0;
            }
            i = 1 - vs_main_settings.cursorMemory;
            rowTypes[i] |= 4;
            vs_mainmenu_setMenuRows(2, 0x24A, menuStrings, rowTypes);
            state = 1;
        }
        break;
    case 1:
        selectedRow = vs_mainmenu_getSelectedRow() + 1;
        if (selectedRow != 0) {
            if (selectedRow == -2) {
                vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
                vs_mainMenu_dismissInformationBox();
                vs_mainMenu_setMenuCommand(menuActionNone);
            } else {
                vs_mainMenu_clearMenuExcept(7);
            }
            state = 2;
        }
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            return selectedRow;
        }
        break;
    }
    return 0;
}

/**
 * Runs the information display setting submenu.
 *
 * @return Zero while initializing or waiting, -2 when returning to battle, or
 * the selected option row plus one.
 */
static int informationOptionMenu(int init)
{
    static int state = 0;
    static int selectedRow = 0;

    char* menuStrings[4];
    int rowTypes[2];
    int i;

    if (init != 0) {
        state = 0;
        return 0;
    }
    switch (state) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            for (i = 0; i < 2; ++i) {
                menuStrings[i * 2] =
                    (char*)&menuStringTable[menuStringTable[i * 2
                                                            + VS_menu_INDEX_infoOn]];
                menuStrings[i * 2 + 1] =
                    (char*)&menuStringTable[menuStringTable[i * 2
                                                            + VS_menu_INDEX_infoOnDesc]];
                rowTypes[i] = 0;
            }
            i = 1 - vs_main_settings.information;
            rowTypes[i] |= 4;
            vs_mainmenu_setMenuRows(2, 0x24B, menuStrings, rowTypes);
            state = 1;
        }
        break;
    case 1:
        selectedRow = vs_mainmenu_getSelectedRow() + 1;
        if (selectedRow != 0) {
            if (selectedRow == -2) {
                vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
                vs_mainMenu_dismissInformationBox();
                vs_mainMenu_setMenuCommand(menuActionNone);
            } else {
                vs_mainMenu_clearMenuExcept(7);
            }
            state = 2;
        }
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            return selectedRow;
        }
        break;
    }
    return 0;
}

/**
 * Runs the puzzle mode setting submenu.
 *
 * @return Zero while initializing or waiting, -2 when returning to battle, or
 * the selected option row plus one.
 */
static int puzzleModeOptionMenu(int init)
{
    static int state = 0;
    static int selectedRow = 0;

    char* menuStrings[4];
    int rowTypes[2];
    int i;

    if (init != 0) {
        state = 0;
        return 0;
    }
    switch (state) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            for (i = 0; i < 2; ++i) {
                menuStrings[i * 2] = (char*)&menuStringTable
                    [menuStringTable[i * 2 + VS_menu_INDEX_puzzleModeOn]];
                menuStrings[i * 2 + 1] = (char*)&menuStringTable
                    [menuStringTable[i * 2 + VS_menu_INDEX_puzzleModeOnDesc]];
                rowTypes[i] = 0;
            }
            i = vs_main_settings.puzzleModeOff;
            rowTypes[i] |= 4;
            vs_mainmenu_setMenuRows(2, 0x24C, menuStrings, rowTypes);
            state = 1;
        }
        break;
    case 1:
        selectedRow = vs_mainmenu_getSelectedRow() + 1;
        if (selectedRow != 0) {
            if (selectedRow == -2) {
                vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
                vs_mainMenu_dismissInformationBox();
                vs_mainMenu_setMenuCommand(menuActionNone);
            } else {
                vs_mainMenu_clearMenuExcept(7);
            }
            state = 2;
        }
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            return selectedRow;
        }
        break;
    }
    return 0;
}

/**
 * Runs the sound mode setting submenu.
 *
 * @return Zero while initializing or waiting, -2 when returning to battle, or
 * the selected option row plus one.
 */
static int soundOptionMenu(int init)
{
    static int state = 0;
    static int selectedRow = 0;

    char* menuStrings[4];
    int rowTypes[2];
    int i;

    if (init != 0) {
        state = 0;
        return 0;
    }
    switch (state) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            for (i = 0; i < 2; ++i) {
                menuStrings[i * 2] =
                    (char*)&menuStringTable[menuStringTable[i * 2
                                                            + VS_menu_INDEX_stereo]];
                menuStrings[i * 2 + 1] =
                    (char*)&menuStringTable[menuStringTable[i * 2
                                                            + VS_menu_INDEX_stereoDesc]];
                rowTypes[i] = 0;
            }
            i = vs_main_settings.monoSound;
            rowTypes[i] |= 4;
            vs_mainmenu_setMenuRows(2, 0x24D, menuStrings, rowTypes);
            state = 1;
        }
        break;
    case 1:
        selectedRow = vs_mainmenu_getSelectedRow() + 1;
        if (selectedRow != 0) {
            if (selectedRow == -2) {
                vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
                vs_mainMenu_dismissInformationBox();
                vs_mainMenu_setMenuCommand(menuActionNone);
            } else {
                vs_mainMenu_clearMenuExcept(7);
            }
            state = 2;
        }
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            return selectedRow;
        }
        break;
    }
    return 0;
}

/**
 * Runs the vibration setting submenu.
 *
 * @return Zero while initializing or waiting, -2 when returning to battle, or
 * the selected option row plus one.
 */
static int vibrationOptionMenu(int init)
{
    static int state = 0;
    static int selectedRow = 0;

    char* menuStrings[4];
    int rowTypes[2];
    int i;
    int currentState;

    if (init != 0) {
        state = 0;
        return 0;
    }
    currentState = state;
    switch (currentState) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            for (i = 0; i < 2; ++i) {
                menuStrings[i * 2] =
                    (char*)&menuStringTable[menuStringTable[i * 2
                                                            + VS_menu_INDEX_vibrationOn]];
                menuStrings[i * 2 + 1] = (char*)&menuStringTable
                    [menuStringTable[i * 2 + VS_menu_INDEX_vibrationOnDesc]];
                rowTypes[i] = 0;
            }
            i = 1 - vs_main_settings.vibrationOn;
            rowTypes[i] |= 4;
            vs_mainmenu_setMenuRows(2, 0x24E, menuStrings, rowTypes);
            state = 1;
        }
        break;
    case 1:
        selectedRow = vs_mainmenu_getSelectedRow() + 1;
        if (selectedRow != 0) {
            if (selectedRow == -2) {
                vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
                vs_mainMenu_dismissInformationBox();
                vs_mainMenu_setMenuCommand(menuActionNone);
            } else {
                if (selectedRow == currentState) {
                    vs_main_vibrationOnEffect(0);
                }
                vs_mainMenu_clearMenuExcept(7);
            }
            state = 2;
        }
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            return selectedRow;
        }
        break;
    }
    return 0;
}

/**
 * Handles the settings menu and its option submenus.
 *
 * Advances the menu state over successive calls, applying chosen
 * settings and handling exits to either the main menu or battle.
 *
 * @return One when an exit transition completes, otherwise zero.
 */
int vs_menu8_exec(u_char* state)
{
    enum state {
        none,
        waitReady = 3,
        init,
        handleInput,
        simpleMap,
        abilityTiming,
        weaponStatus,
        armorStatus,
        cursorMemory,
        information,
        puzzleMode,
        sound,
        vibration,
        exitToMenu,
        exitToBattle
    };

    char* menuStrings[18];
    int rowTypes[9];
    int selectedRow;
    int i;

    switch (*state) {
    case waitReady:
        if (vs_mainmenu_ready() == 0) {
            break;
        }
        vs_mainMenu_initInformationBox();
        // Fallthrough
    case init:
        for (i = 0; i < 9; ++i) {
            menuStrings[i * 2] = (char*)&menuStringTable[menuStringTable[i * 2]];
            menuStrings[i * 2 + 1] = (char*)&menuStringTable[menuStringTable[i * 2 + 1]];
            rowTypes[i] = 0;
        }

        if (vs_main_stateFlags.puzzleModeDisabled != 0) {
            menuStrings[13] =
                (char*)&menuStringTable[VS_menu_OFFSET_puzzleModeSettingDisabled];
            rowTypes[6] = 1;
        }
        i = vs_main_settings.cursorMemory;
        if (*state != waitReady) {
            vs_main_settings.cursorMemory = 1;
        }
        vs_mainmenu_setMenuRows(9, 0x145, menuStrings, rowTypes);
        vs_main_settings.cursorMemory = i;
        *state = 5;
        break;
    case handleInput:
        selectedRow = vs_mainmenu_getSelectedRow();
        i = selectedRow + 1;
        if (i != 0) {
            if (i > 0) {
                vs_mainMenu_flyoutMenuRightAndHoistSelection(D_800F4EE8.unk85[5], 1);
                switch (selectedRow) {
                case 0:
                    *state = simpleMap;
                    simpleMapOptionMenu(1);
                    return 0;
                case 1:
                    *state = abilityTiming;
                    abilityTimingOptionMenu(1);
                    return 0;
                case 2:
                    *state = weaponStatus;
                    weaponStatusOptionMenu(1);
                    return 0;
                case 3:
                    *state = armorStatus;
                    armorStatusOptionMenu(1);
                    return 0;
                case 4:
                    *state = cursorMemory;
                    cursorMemoryOptionMenu(1);
                    return 0;
                case 5:
                    *state = information;
                    informationOptionMenu(1);
                    return 0;
                case 6:
                    *state = puzzleMode;
                    puzzleModeOptionMenu(1);
                    return 0;
                case 7:
                    *state = sound;
                    soundOptionMenu(1);
                    return 0;
                case 8:
                    *state = vibration;
                    vibrationOptionMenu(1);
                    return 0;
                }
            } else if (i == -2) {
                vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
                *state = exitToBattle;
            } else {
                vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
                *state = exitToMenu;
            }
        } else {
            if (vs_main_stateFlags.puzzleModeDisabled != 0) {
                if (vs_mainMenu_getConfirmedRow() == 6) {
                    vs_battle_initInformationTextBox(1);
                    vs_battle_textBoxes[7].state = 0xB;
                } else if (vs_main_settings.information != 0) {
                    vs_battle_initInformationTextBox(2);
                    vs_battle_textBoxes[7].state = 0xB;
                } else {
                    vs_battle_textBoxes[7].state = 0;
                }
            }
            break;
        }
        break;
    case simpleMap:
        i = simpleMapOptionMenu(0);
        if (i == 0) {
            break;
        }
        if (i == -2) {
            *state = exitToBattle;
            break;
        }
        if (i > 0) {
            vs_main_settings.simpleMap = simpleMapValues[i - 1];
        }
        *state = init;
        break;
    case abilityTiming:
        i = abilityTimingOptionMenu(0);
        if (i == 0) {
            break;
        }
        if (i == -2) {
            *state = exitToBattle;
            break;
        }
        if (i > 0) {
            vs_main_settings.abilityTimingDisplay = 2 - i;
        }
        *state = init;
        break;
    case weaponStatus:
        i = weaponStatusOptionMenu(0);
        if (i == 0) {
            break;
        }
        if (i == -2) {
            *state = exitToBattle;
            break;
        }
        if (i > 0) {
            vs_main_settings.weaponStatChange = 2 - i;
        }
        *state = init;
        break;
    case armorStatus:
        i = armorStatusOptionMenu(0);
        if (i == 0) {
            break;
        }
        if (i == -2) {
            *state = exitToBattle;
            break;
        }
        if (i > 0) {
            vs_main_settings.armorStatChange = 2 - i;
        }
        *state = init;
        break;
    case cursorMemory:
        i = cursorMemoryOptionMenu(0);
        if (i == 0) {
            break;
        }
        if (i == -2) {
            *state = exitToBattle;
            break;
        }
        if (i > 0) {
            vs_main_settings.cursorMemory = 2 - i;
        }
        *state = init;
        break;
    case information:
        i = informationOptionMenu(0);
        if (i == 0) {
            break;
        }
        if (i == -2) {
            *state = exitToBattle;
            break;
        }
        if (i > 0) {
            vs_main_settings.information = 2 - i;
            vs_mainMenu_initInformationBox();
        }
        *state = init;
        break;
    case puzzleMode:
        i = puzzleModeOptionMenu(0);
        if (i == 0) {
            break;
        }
        if (i == -2) {
            *state = exitToBattle;
            break;
        }
        if (i > 0) {
            vs_main_settings.puzzleModeOff = i - 1;
            vs_main_stateFlags.puzzleMode = 1 - vs_main_settings.puzzleModeOff;
        }
        *state = init;
        break;
    case sound:
        i = soundOptionMenu(0);
        if (i == 0) {
            break;
        }
        if (i == -2) {
            *state = exitToBattle;
            break;
        }
        if (i > 0) {
            vs_main_settings.monoSound = i - 1;
            vs_main_setMonoSound(vs_main_settings.monoSound);
        }
        *state = init;
        break;
    case vibration:
        i = vibrationOptionMenu(0);
        if (i == 0) {
            break;
        }
        if (i == -2) {
            *state = exitToBattle;
            break;
        }
        if (i > 0) {
            vs_main_settings.vibrationOn = 2 - i;
        }
        *state = init;
        break;
    case exitToMenu:
        vs_mainMenu_dismissInformationBox();
        vs_mainMenu_setMenuCommand(menuActionNone);
        if (vs_mainmenu_ready() != 0) {
            *state = none;
            return 1;
        }
        break;
    case exitToBattle:
        vs_mainMenu_dismissInformationBox();
        vs_mainMenu_setMenuCommand(menuActionNone);
        if (vs_mainmenu_ready() != 0) {
            vs_battle_menuState.currentMenu = 8;
            *state = none;
            return 1;
        }
        break;
    }
    return 0;
}
