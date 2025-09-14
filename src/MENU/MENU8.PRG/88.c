#include "common.h"
#include "../../assets/MENU/MENU8.PRG/menu.h"
#include "../MAINMENU.PRG/C48.h"
#include "../MAINMENU.PRG/413C.h"
#include "../../BATTLE/BATTLE.PRG/573B8.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"

static u_short _menuStrings[] = {
#include "../../assets/MENU/MENU8.PRG/menu.vsString"
};

static char _simpleMapValues[] = { 3, 1, 0, 0 };

extern char D_80105F40[];

static int _simpleMapOptionMenu(int arg0)
{
    static int state = 0;
    static int selectedRow = 0;

    char* menuStrings[6];
    int rowTypes[3];
    int i;

    if (arg0 != 0) {
        state = 0;
        return 0;
    }
    switch (state) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            for (i = 0; i < 3; ++i) {
                menuStrings[i * 2]
                    = (char*)&_menuStrings[_menuStrings[i * 2 + VS_menu_INDEX_frame]];
                menuStrings[i * 2 + 1]
                    = (char*)&_menuStrings[_menuStrings[i * 2 + VS_menu_INDEX_frameDesc]];
                rowTypes[i] = 0;
            }
            for (i = 0; i < 3; ++i) {
                if (vs_main_settings.simpleMap == _simpleMapValues[i]) {
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
                func_800FA8E0(0x28);
                func_800FFBA8();
                func_800FFA88(0);
            } else {
                func_800FA8E0(7);
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

static int _abilityTimingOptionMenu(int arg0)
{
    static int state = 0;
    static int selectedRow = 0;

    char* menuStrings[4];
    int rowTypes[2];
    int i;

    if (arg0 != 0) {
        state = 0;
        return 0;
    }
    switch (state) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            for (i = 0; i < 2; ++i) {
                menuStrings[i * 2] = (char*)&_menuStrings[_menuStrings[i * 2
                    + VS_menu_INDEX_abilityTimingOn]];
                menuStrings[i * 2 + 1] = (char*)&_menuStrings[_menuStrings[i * 2
                    + VS_menu_INDEX_abilityTimingOnDesc]];
                rowTypes[i] = 0;
            }
            i = 1 - ((*(u_int*)&vs_main_settings >> 5) & 1);
            rowTypes[i] |= 4;
            vs_mainmenu_setMenuRows(2, 0x247, menuStrings, rowTypes);
            state = 1;
        }
        break;
    case 1:
        selectedRow = vs_mainmenu_getSelectedRow() + 1;
        if (selectedRow != 0) {
            if (selectedRow == -2) {
                func_800FA8E0(0x28);
                func_800FFBA8();
                func_800FFA88(0);
            } else {
                func_800FA8E0(7);
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

static int _weaponStatusOptionMenu(int arg0)
{
    static int state = 0;
    static int selectedRow = 0;

    char* menuStrings[4];
    int rowTypes[2];
    int i;

    if (arg0 != 0) {
        state = 0;
        return 0;
    }
    switch (state) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            for (i = 0; i < 2; ++i) {
                menuStrings[i * 2] = (char*)&_menuStrings[_menuStrings[i * 2
                    + VS_menu_INDEX_weaponStatusOn]];
                menuStrings[i * 2 + 1] = (char*)&_menuStrings[_menuStrings[i * 2
                    + VS_menu_INDEX_weaponStatusOnDesc]];
                rowTypes[i] = 0;
            }
            i = 1 - ((*(u_int*)&vs_main_settings >> 6) & 1);
            rowTypes[i] |= 4;
            vs_mainmenu_setMenuRows(2, 0x248, menuStrings, rowTypes);
            state = 1;
        }
        break;
    case 1:
        selectedRow = vs_mainmenu_getSelectedRow() + 1;
        if (selectedRow != 0) {
            if (selectedRow == -2) {
                func_800FA8E0(0x28);
                func_800FFBA8();
                func_800FFA88(0);
            } else {
                func_800FA8E0(7);
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

static int _armorStatusOptionMenu(int arg0)
{
    static int state = 0;
    static int selectedRow = 0;

    char* menuStrings[4];
    int rowTypes[2];
    int i;

    if (arg0 != 0) {
        state = 0;
        return 0;
    }
    switch (state) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            for (i = 0; i < 2; ++i) {
                menuStrings[i * 2] = (char*)&_menuStrings[_menuStrings[i * 2
                    + VS_menu_INDEX_armorStatusOn]];
                menuStrings[i * 2 + 1] = (char*)&_menuStrings[_menuStrings[i * 2
                    + VS_menu_INDEX_armorStatusOnDesc]];
                rowTypes[i] = 0;
            }
            i = 1 - (vs_main_settings.timingWeaponArmor >> 7);
            rowTypes[i] |= 4;
            vs_mainmenu_setMenuRows(2, 0x249, menuStrings, rowTypes);
            state = 1;
        }
        break;
    case 1:
        selectedRow = vs_mainmenu_getSelectedRow() + 1;
        if (selectedRow != 0) {
            if (selectedRow == -2) {
                func_800FA8E0(0x28);
                func_800FFBA8();
                func_800FFA88(0);
            } else {
                func_800FA8E0(7);
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

static int _cursorMemoryOptionMenu(int arg0)
{
    static int state = 0;
    static int selectedRow = 0;

    char* menuStrings[4];
    int rowTypes[2];
    int i;

    if (arg0 != 0) {
        state = 0;
        return 0;
    }
    switch (state) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            for (i = 0; i < 2; ++i) {
                menuStrings[i * 2] = (char*)&_menuStrings[_menuStrings[i * 2
                    + VS_menu_INDEX_cursorMemoryOn]];
                menuStrings[i * 2 + 1] = (char*)&_menuStrings[_menuStrings[i * 2
                    + VS_menu_INDEX_cursorMemoryOnDesc]];
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
                func_800FA8E0(0x28);
                func_800FFBA8();
                func_800FFA88(0);
            } else {
                func_800FA8E0(7);
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

static int _informationOptionMenu(int arg0)
{
    static int state = 0;
    static int selectedRow = 0;

    char* menuStrings[4];
    int rowTypes[2];
    int i;

    if (arg0 != 0) {
        state = 0;
        return 0;
    }
    switch (state) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            for (i = 0; i < 2; ++i) {
                menuStrings[i * 2]
                    = (char*)&_menuStrings[_menuStrings[i * 2 + VS_menu_INDEX_infoOn]];
                menuStrings[i * 2 + 1] = (char*)&_menuStrings[_menuStrings[i * 2
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
                func_800FA8E0(0x28);
                func_800FFBA8();
                func_800FFA88(0);
            } else {
                func_800FA8E0(7);
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

static int _puzzleModeOptionMenu(int arg0)
{
    static int state = 0;
    static int selectedRow = 0;

    char* menuStrings[4];
    int rowTypes[2];
    int i;

    if (arg0 != 0) {
        state = 0;
        return 0;
    }
    switch (state) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            for (i = 0; i < 2; ++i) {
                menuStrings[i * 2] = (char*)&_menuStrings[_menuStrings[i * 2
                    + VS_menu_INDEX_puzzleModeOn]];
                menuStrings[i * 2 + 1] = (char*)&_menuStrings[_menuStrings[i * 2
                    + VS_menu_INDEX_puzzleModeOnDesc]];
                rowTypes[i] = 0;
            }
            i = ((*(u_int*)&vs_main_settings) >> 3) & 1;
            rowTypes[i] |= 4;
            vs_mainmenu_setMenuRows(2, 0x24C, menuStrings, rowTypes);
            state = 1;
        }
        break;
    case 1:
        selectedRow = vs_mainmenu_getSelectedRow() + 1;
        if (selectedRow != 0) {
            if (selectedRow == -2) {
                func_800FA8E0(0x28);
                func_800FFBA8();
                func_800FFA88(0);
            } else {
                func_800FA8E0(7);
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

static int _soundOptionMenu(int arg0)
{
    static int state = 0;
    static int selectedRow = 0;

    char* menuStrings[4];
    int rowTypes[2];
    int i;

    if (arg0 != 0) {
        state = 0;
        return 0;
    }
    switch (state) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            for (i = 0; i < 2; ++i) {
                menuStrings[i * 2]
                    = (char*)&_menuStrings[_menuStrings[i * 2 + VS_menu_INDEX_stereo]];
                menuStrings[i * 2 + 1] = (char*)&_menuStrings[_menuStrings[i * 2
                    + VS_menu_INDEX_stereoDesc]];
                rowTypes[i] = 0;
            }
            i = vs_main_soundMono;
            rowTypes[i] |= 4;
            vs_mainmenu_setMenuRows(2, 0x24D, menuStrings, rowTypes);
            state = 1;
        }
        break;
    case 1:
        selectedRow = vs_mainmenu_getSelectedRow() + 1;
        if (selectedRow != 0) {
            if (selectedRow == -2) {
                func_800FA8E0(0x28);
                func_800FFBA8();
                func_800FFA88(0);
            } else {
                func_800FA8E0(7);
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

static int _vibrationOptionMenu(int arg0)
{
    static int state = 0;
    static int selectedRow = 0;

    char* menuStrings[4];
    int rowTypes[2];
    int i;
    int currentState;

    if (arg0 != 0) {
        state = 0;
        return 0;
    }
    currentState = state;
    switch (currentState) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            for (i = 0; i < 2; ++i) {
                menuStrings[i * 2] = (char*)&_menuStrings[_menuStrings[i * 2
                    + VS_menu_INDEX_vibrationOn]];
                menuStrings[i * 2 + 1] = (char*)&_menuStrings[_menuStrings[i * 2
                    + VS_menu_INDEX_vibrationOnDesc]];
                rowTypes[i] = 0;
            }
            i = 1 - vs_main_vibrationEnabled;
            rowTypes[i] |= 4;
            vs_mainmenu_setMenuRows(2, 0x24E, menuStrings, rowTypes);
            state = 1;
        }
        break;
    case 1:
        selectedRow = vs_mainmenu_getSelectedRow() + 1;
        if (selectedRow != 0) {
            if (selectedRow == -2) {
                func_800FA8E0(0x28);
                func_800FFBA8();
                func_800FFA88(0);
            } else {
                if (selectedRow == currentState) {
                    func_800438C8(0);
                }
                func_800FA8E0(7);
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

int vs_menu8_exec(char* state)
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
    int var_v1;
    u_int temp_v1_2;

    switch (*state) {
    case waitReady:
        if (vs_mainmenu_ready() == 0) {
            break;
        }
        func_800FFBC8();
        // Fallthrough
    case init:
        for (i = 0; i < 9; ++i) {
            menuStrings[i * 2] = (char*)&_menuStrings[_menuStrings[i * 2]];
            menuStrings[i * 2 + 1] = (char*)&_menuStrings[_menuStrings[i * 2 + 1]];
            rowTypes[i] = 0;
        }

        if (vs_main_stateFlags.puzzleModeDisabled != 0) {
            menuStrings[13]
                = (char*)&_menuStrings[VS_menu_OFFSET_puzzleModeSettingDisabled];
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
                func_800FA92C(D_800F4EE8.unk0[0x8A], 1);
                switch (selectedRow) {
                case 0:
                    *state = simpleMap;
                    _simpleMapOptionMenu(1);
                    return 0;
                case 1:
                    *state = abilityTiming;
                    _abilityTimingOptionMenu(1);
                    return 0;
                case 2:
                    *state = weaponStatus;
                    _weaponStatusOptionMenu(1);
                    return 0;
                case 3:
                    *state = armorStatus;
                    _armorStatusOptionMenu(1);
                    return 0;
                case 4:
                    *state = cursorMemory;
                    _cursorMemoryOptionMenu(1);
                    return 0;
                case 5:
                    *state = information;
                    _informationOptionMenu(1);
                    return 0;
                case 6:
                    *state = puzzleMode;
                    _puzzleModeOptionMenu(1);
                    return 0;
                case 7:
                    *state = sound;
                    _soundOptionMenu(1);
                    return 0;
                case 8:
                    *state = vibration;
                    _vibrationOptionMenu(1);
                    return 0;
                }
            } else if (i == -2) {
                func_800FA8E0(0x28);
                *state = exitToBattle;
            } else {
                func_800FA8E0(0x28);
                *state = exitToMenu;
            }
        } else {
            if (vs_main_stateFlags.puzzleModeDisabled != 0) {
                if (func_801008B0() == 6) {
                    func_800C8E04(1);
                    D_800F514C = 0xB;
                } else if (vs_main_settings.information != 0) {
                    func_800C8E04(2);
                    D_800F514C = 0xB;
                } else {
                    D_800F514C = 0;
                }
            }
            break;
        }
        break;
    case simpleMap:
        i = _simpleMapOptionMenu(0);
        if (i == 0) {
            break;
        }
        if (i == -2) {
            *state = exitToBattle;
            break;
        }
        if (i > 0) {
            vs_main_settings.simpleMap = _simpleMapValues[i - 1];
        }
        *state = init;
        break;
    case abilityTiming:
        i = _abilityTimingOptionMenu(0);
        if (i == 0) {
            break;
        }
        if (i == -2) {
            *state = exitToBattle;
            break;
        }
        if (i > 0) {
            var_v1 = *(int*)&vs_main_settings & ~0x20;
            var_v1 |= ((2 - i) & 1) << 5;
            *(int*)&vs_main_settings = var_v1;
        }
        *state = init;
        break;
    case weaponStatus:
        i = _weaponStatusOptionMenu(0);
        if (i == 0) {
            break;
        }
        if (i == -2) {
            *state = exitToBattle;
            break;
        }
        if (i > 0) {
            var_v1 = *(int*)&vs_main_settings & ~0x40;
            var_v1 |= (((2 - i) & 1) << 6);
            *(int*)&vs_main_settings = var_v1;
        }
        *state = init;
        break;
    case armorStatus:
        i = _armorStatusOptionMenu(0);
        if (i == 0) {
            break;
        }
        if (i == -2) {
            *state = exitToBattle;
            break;
        }
        if (i > 0) {
            var_v1 = *(int*)&vs_main_settings & ~0x80;
            var_v1 |= (((2 - i) & 1) << 7);
            *(int*)&vs_main_settings = var_v1;
        }
        *state = init;
        break;
    case cursorMemory:
        i = _cursorMemoryOptionMenu(0);
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
        i = _informationOptionMenu(0);
        if (i == 0) {
            break;
        }
        if (i == -2) {
            *state = exitToBattle;
            break;
        }
        if (i > 0) {
            vs_main_settings.information = 2 - i;
            func_800FFBC8();
        }
        *state = init;
        break;
    case puzzleMode:
        i = _puzzleModeOptionMenu(0);
        if (i == 0) {
            break;
        }
        if (i == -2) {
            *state = exitToBattle;
            break;
        }
        if (i > 0) {
            temp_v1_2 = (*(int*)&vs_main_settings & ~8) | (((i - 1) & 1) * 8);
            *(int*)&vs_main_settings = temp_v1_2;
            vs_main_stateFlags.puzzleMode = ~(temp_v1_2 >> 3) & 1;
        }
        *state = init;
        break;
    case sound:
        i = _soundOptionMenu(0);
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
        i = _vibrationOptionMenu(0);
        if (i == 0) {
            break;
        }
        if (i == -2) {
            *state = exitToBattle;
            break;
        }
        if (i > 0) {
            vs_main_vibrationEnabled = 2 - i;
        }
        *state = init;
        break;
    case exitToMenu:
        func_800FFBA8();
        func_800FFA88(0);
        if (vs_mainmenu_ready() != 0) {
            *state = none;
            return 1;
        }
        break;
    case exitToBattle:
        func_800FFBA8();
        func_800FFA88(0);
        if (vs_mainmenu_ready() != 0) {
            vs_battle_menuState.currentState = 8;
            *state = none;
            return 1;
        }
        break;
    }
    return 0;
}
