#include "common.h"
#include "../MAINMENU.PRG/C48.h"
#include "../MAINMENU.PRG/413C.h"
#include "../../BATTLE/BATTLE.PRG/146C.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"
#include "../../SLUS_010.40/main.h"

int func_80102B08(int);
int func_80103E30(int);

extern signed char D_80102800;
extern int D_801067DC[];
extern char D_8010689C[];
extern signed char D_80106918[];
extern signed char D_80106928[];

void func_80102884(int arg0)
{
    int temp_v0;
    int var_s1;
    int var_s2;
    int var_a0;

    var_s2 = 0;

    if (arg0 < 0) {
        var_s2 = 1;
        arg0 = -arg0;
    }

    temp_v0 = vs_battle_getSkillFlags(0, arg0);
    vs_mainmenu_setAbilityCost(1, &D_80102800, 8, (temp_v0 >> 1) & 1);
    var_s1 = 0xF;
    var_a0 = vs_main_skills[arg0].cost;
    D_80106918[15] = 0;

    if (var_s2 != 0) {
        var_s1 = 0xD;
        D_80106918[14] = 0x2D;
        D_80106918[13] = 0x5B;
    }

    do {
        var_a0 = vs_battle_toBCD(var_a0);
        D_80106918[--var_s1] = (var_a0 & 0xF) + 0x30;
        var_a0 >>= 4;
        if (var_s2 != 0) {
            D_80106918[--var_s1] = 0x5B;
        }
    } while (var_a0 != 0);

    D_80106918[--var_s1] = 0x23;
    vs_mainmenu_setAbilityCost(
        0, &D_80106918[var_s1], (var_s2 * 4) | 0x48, (temp_v0 >> 1) & 1);
}

void func_801029B8(int arg0, int arg1)
{
    int temp_v0;
    int var_s0;

    vs_mainmenu_setAbilityCost(1, &D_80102800, 8, arg1);
    temp_v0 = arg0;
    var_s0 = 0xF;
    D_80106928[15] = 0;

    do {
        temp_v0 = vs_battle_toBCD(temp_v0);
        D_80106928[--var_s0] = (temp_v0 & 0xF) + 0x30;
        temp_v0 >>= 4;
    } while (temp_v0 != 0);

    D_80106928[--var_s0] = 0x23;
    vs_mainmenu_setAbilityCost(0, &D_80106928[var_s0], 0x48, arg1);
}

int func_80102A68(int arg0)
{
    int temp_a1;
    int temp_v1;
    int i;
    int var_a1;
    int j;

    temp_a1 = func_8007C874();

    do {
        for (i = 0; i < 48; ++i) {
            if ((u_short)D_801067DC[i] == temp_a1) {
                break;
            }
        }
    } while (0);

    temp_v1 = i;
    if (arg0 < i) {
        i = arg0;
        arg0 = temp_v1;
    }

    var_a1 = 15;

    for (j = i; j < arg0; ++j) {
        var_a1 += D_8010689C[j];
    }
    return var_a1;
}

INCLUDE_RODATA("build/src/MENU/MENU0.PRG/nonmatchings/84", D_80102800);

INCLUDE_ASM("build/src/MENU/MENU0.PRG/nonmatchings/84", func_80102B08);

extern u_short D_80104A58[];
extern char D_8004B9F8[];
extern char D_800EBD84[];
extern int D_801068F4;
extern int D_801068F8;
extern int D_801068FC;
extern char D_80106950[];

int _drawMagicList(int arg0)
{
    char* menuStrings[12];
    int rowTypes[6];
    int i;
    int rowCount;
    int skillId;

    if (arg0 != 0) {
        D_801068FC = (arg0 ^ 2) < 1U;
        func_800FA92C(1, 1);
        D_801068F4 = 0;
        return 0;
    }

    switch (D_801068F4) {
    case 0:
        if ((vs_battle_shortcutInvoked == 0) && (vs_mainmenu_ready() == 0)) {
            break;
        }
        rowCount = 0;
        for (i = 0; i < 6; ++i) {
            skillId = D_800EBD84[i];
            if ((vs_main_skills[skillId].flags >> 0xF) & 1) {
                menuStrings[rowCount * 2] = vs_main_skills[skillId].name;
                menuStrings[rowCount * 2 + 1] = (char*)&D_80104A58[D_80104A58[30 + i]];
                rowTypes[rowCount] = 0;
                if (vs_battle_getSkillFlags(0, skillId) != 0) {
                    rowTypes[rowCount] |= 1;
                }
                D_80106950[rowCount] = skillId;
                ++rowCount;
            }
        }

        if (D_800F4EA0 & 0xB7) {
            for (i = 0; i < 6; ++i) {
                rowTypes[i] |= 1;
            }
        }

        i = vs_main_settings.cursorMemory;
        if (D_801068FC != 0) {
            vs_main_settings.cursorMemory = 1;
        }
        vs_mainmenu_setMenuRows(rowCount, 0x208, menuStrings, rowTypes);
        vs_main_settings.cursorMemory = i;
        D_801068F4 = 1;
        break;
    case 1:
        D_801068F8 = vs_mainmenu_getSelectedRow() + 1;
        if (D_801068F8 != 0) {
            D_801022D4 = 0;
            if ((vs_battle_shortcutInvoked != 0) && (D_801068F8 == -1)) {
                D_801068F8 = -2;
            }
            if (D_801068F8 == -1) {
                func_800FA8E0(0);
            } else {
                if (D_801068F8 > 0) {
                    D_801068F8 = D_80106950[D_801068F8 - 1];
                }
                func_800FA8E0(0x28);
                func_800FFBA8();
                func_800FFA88(0);
            }
            D_801068F4 = 2;
        } else {
            char* new_var = D_80106950;
            func_80102884(*(new_var + func_801008B0()));
        }
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            return D_801068F8;
        }
        break;
    }
    return 0;
}

extern char D_800EBD8C[];
extern char D_80106958[];
extern int D_80106900;
extern int D_80106904;
extern int D_80106908;

int func_801037A8(int arg0)
{
    char* menuStrings[36];
    int rowTypes[18];
    int i;
    int rowCount;
    int skillId;

    if (arg0 != 0) {
        D_80106908 = (arg0 ^ 2) < 1U;
        func_800FA92C(2, 1);
        D_80106900 = 0;
        return 0;
    }

    switch (D_80106900) {
    case 0:
        if ((vs_battle_shortcutInvoked == 0) && (vs_mainmenu_ready() == 0)) {
            break;
        }
        rowCount = 0;
        for (i = 0; i < 18; ++i) {
            skillId = D_800EBD8C[i];
            if ((vs_main_skills[skillId].flags >> 0xF) & 1) {
                menuStrings[rowCount * 2] = vs_main_skills[skillId].name;
                menuStrings[rowCount * 2 + 1] = (char*)&D_80104A58[D_80104A58[36 + i]];
                rowTypes[rowCount] = 0;
                if (vs_battle_getSkillFlags(0, skillId) != 0) {
                    rowTypes[rowCount] |= 1;
                }
                D_80106958[rowCount] = skillId;
                ++rowCount;
            }
        }

        if (D_800F4EA0 & 0xB7) {
            for (i = 0; i < 18; ++i) {
                rowTypes[i] |= 1;
            }
        }

        i = vs_main_settings.cursorMemory;
        if (D_80106908 != 0) {
            vs_main_settings.cursorMemory = 1;
        }
        vs_mainmenu_setMenuRows(rowCount, 0x209, menuStrings, rowTypes);
        vs_main_settings.cursorMemory = i;
        D_80106900 = 1;
        break;
    case 1:
        D_80106904 = vs_mainmenu_getSelectedRow() + 1;
        if (D_80106904 != 0) {
            D_801022D4 = 0;
            if ((vs_battle_shortcutInvoked != 0) && (D_80106904 == -1)) {
                D_80106904 = -2;
            }
            if (D_80106904 == -1) {
                func_800FA8E0(0);
            } else {
                if (D_80106904 > 0) {
                    D_80106904 = D_80106958[D_80106904 - 1];
                }
                func_800FA8E0(0x28);
                func_800FFBA8();
                func_800FFA88(0);
            }
            D_80106900 = 2;
        } else {
            char* new_var = D_80106958;
            func_80102884(*(new_var + func_801008B0()));
        }
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            return D_80106904;
        }
        break;
    }
    return 0;
}

extern char D_800EBDA0[];
extern int D_8010690C;
extern int D_80106910;
extern int D_80106914;
extern char D_80106970[];

int func_80103AEC(int arg0)
{
    char* menuStrings[16];
    int rowTypes[8];
    int i;
    int rowCount;
    int skillId;

    if (arg0 != 0) {
        D_80106914 = (arg0 ^ 2) < 1U;
        func_800FA92C(3, 1);
        D_8010690C = 0;
        return 0;
    }

    switch (D_8010690C) {
    case 0:
        if ((vs_battle_shortcutInvoked == 0) && (vs_mainmenu_ready() == 0)) {
            break;
        }
        rowCount = 0;
        for (i = 0; i < 8; ++i) {
            skillId = D_800EBDA0[i];
            if ((vs_main_skills[skillId].flags >> 0xF) & 1) {
                menuStrings[rowCount * 2] = vs_main_skills[skillId].name;
                menuStrings[rowCount * 2 + 1] = (char*)&D_80104A58[D_80104A58[54 + i]];
                rowTypes[rowCount] = 0;
                if (vs_battle_getSkillFlags(0, skillId) != 0) {
                    rowTypes[rowCount] |= 1;
                }
                D_80106970[rowCount] = skillId;
                ++rowCount;
            }
        }

        if (D_800F4EA0 & 0xB7) {
            for (i = 0; i < 8; ++i) {
                rowTypes[i] |= 1;
            }
        }

        i = vs_main_settings.cursorMemory;
        if (D_80106914 != 0) {
            vs_main_settings.cursorMemory = 1;
        }
        vs_mainmenu_setMenuRows(rowCount, 0x20A, menuStrings, rowTypes);
        vs_main_settings.cursorMemory = i;
        D_8010690C = 1;
        break;
    case 1:
        D_80106910 = vs_mainmenu_getSelectedRow() + 1;
        if (D_80106910 != 0) {
            D_801022D4 = 0;
            if ((vs_battle_shortcutInvoked != 0) && (D_80106910 == -1)) {
                D_80106910 = -2;
            }
            if (D_80106910 == -1) {
                func_800FA8E0(0);
            } else {
                if (D_80106910 > 0) {
                    D_80106910 = D_80106970[D_80106910 - 1];
                }
                func_800FA8E0(0x28);
                func_800FFBA8();
                func_800FFA88(0);
            }
            D_8010690C = 2;
        } else {
            char* new_var = D_80106970;
            func_80102884(*(new_var + func_801008B0()));
        }
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            return D_80106910;
        }
        break;
    }
    return 0;
}

INCLUDE_ASM("build/src/MENU/MENU0.PRG/nonmatchings/84", func_80103E30);

void func_80104254()
{
    vs_battle_menuItem_t* temp_v0;

    temp_v0 = vs_battle_setMenuItem(
        0, 320, 18, 0x8C, 8, (char*)&vs_battle_menuStrings[vs_battle_menuStrings[0]]);
    temp_v0->state = 2;
    temp_v0->x = 180;
    temp_v0->selected = 1;
    func_800FFA88(2);
    func_800FFBC8();
}

extern char D_8006164D;
extern char D_80104AF8;
extern char D_80104B64;
extern char D_80104BEC;
extern char D_80104C8E;
extern char D_80105E5A[];
extern char D_80105E68[];
extern char D_80105EB4[];

int func_801042C8(char* arg0)
{
    char* menuStrings[10];
    int rowTypes[5];
    int selectedRow;
    int j;
    int i;

    switch (*arg0) {
    case 3:
        if (vs_mainmenu_ready() == 0) {
            break;
        }
        func_800FFBC8();
        i = vs_battle_shortcutInvoked;
        if (i != 0) {
            vs_battle_setMenuItem(
                i + 9, 0x140, 0x22, 0x8C, 8, (char*)&D_80104A58[D_80104A58[(i * 3) - 3]])
                ->selected
                = 1;
            switch (i) {
            case 1:
                *arg0 = 7;
                func_80102B08(1);
                break;
            case 2:
                *arg0 = 9;
                _drawMagicList(1);
                break;
            case 3:
                *arg0 = 0xB;
                func_801037A8(1);
                break;
            case 4:
                *arg0 = 0xD;
                func_80103AEC(1);
                break;
            }
            break;
        }
        // Fallthrough
    case 4:
        for (i = 0; i < 4; ++i) {
            menuStrings[i * 2] = (char*)&D_80104A58[D_80104A58[i * 3]];
            menuStrings[i * 2 + 1] = (char*)&D_80104A58[D_80104A58[i * 3 + 1]];
            rowTypes[i] = 0;
            if (func_800CAEAC(i) == 0) {
                rowTypes[i] |= 1;
                menuStrings[i * 2 + 1] = (char*)&D_80104A58[D_80104A58[i * 3 + 2]];
            }
        }

        if (vs_main_stateFlags.unkB5 != 0) {
            for (j = 0; j < 0x30; ++j) {
                if (vs_main_stateFlags.unk156[j] != 0) {
                    break;
                }
            }

            menuStrings[i * 2] = D_80105E5A; // TELEPORTATION

            menuStrings[i * 2 + 1]
                = (func_8008A4FC() != 0) && (vs_main_stateFlags.unkB5 == 2)
                ? D_80105E5A + 0x5A
                : // The spirit paling prevents teleportation.
                D_80105E5A + 0xE; // Teleport to any Circle of Magic.

            if ((func_8008A4FC() != 0) && (vs_main_stateFlags.unkB5 == 2)) {
                menuStrings[i * 2 + 1]
                    = D_80105E5A + 0x5A; // The spirit paling prevents teleportation.
            }

            rowTypes[i++] = ((j == 0x30) || (vs_main_stateFlags.unkB5 == 2)
                || (func_8008A4FC() == 0));
        }

        j = vs_main_settings.cursorMemory;
        if (*arg0 != 3) {
            vs_main_settings.cursorMemory = 1;
        }
        vs_mainmenu_setMenuRows(i, 0x105, menuStrings, rowTypes);
        vs_main_settings.cursorMemory = j;
        *arg0 = 5;
        break;
    case 5:
        selectedRow = vs_mainmenu_getSelectedRow();
        i = selectedRow + 1;
        if (i != 0) {
            if (i > 0) {
                switch (selectedRow) {
                case 0:
                    *arg0 = 7;
                    func_80102B08(1);
                    break;
                case 1:
                    *arg0 = 9;
                    _drawMagicList(1);
                    break;
                case 2:
                    *arg0 = 0xB;
                    func_801037A8(1);
                    break;
                case 3:
                    *arg0 = 0xD;
                    func_80103AEC(1);
                    break;
                case 4:
                    *arg0 = 0xE;
                    func_80103E30(1);
                    break;
                }
            } else {
                if (i == -2) {
                    func_800FA8E0(0x28);
                    *arg0 = 0x11;
                } else {
                    func_800FA8E0(0x28);
                    *arg0 = 0xF;
                }
            }
        }
        break;
    case 6:
        func_80104254();
        vs_battle_setMenuItem(0xA, 0x140, 0x22, 0x7E, 8, &D_80104AF8)->selected = 1;
        func_80102B08(2);
        *arg0 = 7;
        break;
    case 7:
        i = func_80102B08(0);
        if (i != 0) {
            if (i > 0) {
                D_800F4E98.executeAbility = i;
                vs_battle_executeAbilityType = 6;
                *arg0 = 0x10;
            } else {
                if (i == -2) {
                    *arg0 = 0x11;
                } else {
                    *arg0 = 4;
                }
            }
        }
        break;
    case 8:
        func_80104254();
        vs_battle_setMenuItem(0xB, 0x140, 0x22, 0x7E, 8, &D_80104B64)->selected = 1;
        _drawMagicList(2);
        *arg0 = 9;
        break;
    case 9:
        i = _drawMagicList(0);
        if (i != 0) {
            if (i > 0) {
                D_800F4E98.executeAbility = i;
                vs_battle_executeAbilityType = 8;
                *arg0 = 0x10;
            } else {
                if (i == -2) {
                    *arg0 = 0x11;
                } else {
                    *arg0 = 4;
                }
            }
        }
        break;
    case 10:
        func_80104254();
        vs_battle_setMenuItem(0xC, 0x140, 0x22, 0x7E, 8, &D_80104BEC)->selected = 1;
        func_801037A8(2);
        *arg0 = 0xB;
        break;
    case 11:
        i = func_801037A8(0);
        if (i != 0) {
            if (i > 0) {
                D_800F4E98.executeAbility = i;
                vs_battle_executeAbilityType = 10;
                *arg0 = 0x10;
            } else {
                if (i == -2) {
                    *arg0 = 0x11;
                } else {
                    *arg0 = 4;
                }
            }
        }
        break;
    case 12:
        func_80104254();
        vs_battle_setMenuItem(0xD, 0x140, 0x22, 0x7E, 8, &D_80104C8E)->selected = 1;
        func_80103AEC(2);
        *arg0 = 0xD;
        break;
    case 13:
        i = func_80103AEC(0);
        if (i != 0) {
            if (i > 0) {
                D_800F4E98.executeAbility = i;
                vs_battle_executeAbilityType = 12;
                *arg0 = 0x10;
            } else {
                if (i == -2) {
                    *arg0 = 0x11;
                } else {
                    *arg0 = 4;
                }
            }
        }
        break;
    case 14:
        i = func_80103E30(0);
        if (i != 0) {
            if (i > 0) {
                D_800F4E98.unk2 = 0xA;
                D_800F4E98.executeAbility = i - 1;
                *arg0 = 0x11;
            } else {
                if (i == -2) {
                    *arg0 = 0x11;
                } else {
                    *arg0 = 4;
                }
            }
        }
        break;
    case 15:
        func_800FFBA8();
        func_800FFA88(0);
        if (vs_mainmenu_ready() != 0) {
            *arg0 = 0;
            return 1;
        }
        break;
    case 16:
        if (vs_mainmenu_ready() != 0) {
            D_800F4E9A = 7;
            vs_battle_menuState.returnState = vs_battle_menuState.currentState;
            vs_battle_menuState.currentState = 1;
            *arg0 = 0;
            return 1;
        }
        break;
    case 17:
        func_800FFBA8();
        func_800FFA88(0);
        if (vs_mainmenu_ready() != 0) {
            vs_battle_menuState.currentState = 1;
            *arg0 = 0;
            return 1;
        }
        break;
    }
    return 0;
}
