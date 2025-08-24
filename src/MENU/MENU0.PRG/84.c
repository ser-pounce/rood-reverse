#include "common.h"
#include "../MAINMENU.PRG/C48.h"
#include "../MAINMENU.PRG/413C.h"
#include "../../BATTLE/BATTLE.PRG/146C.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"
#include "../../SLUS_010.40/main.h"

extern signed char D_80102800;
extern u_short D_801067DC[][2];
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
            if (D_801067DC[i][0] == temp_a1) {
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

extern char D_8004B9F8[]; // skillname
extern char D_800EBD84[];
extern u_short D_80104A58[];
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

extern char D_80106958[];
extern char D_800EBD8C[];
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

INCLUDE_ASM("build/src/MENU/MENU0.PRG/nonmatchings/84", func_80103AEC);

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

INCLUDE_ASM("build/src/MENU/MENU0.PRG/nonmatchings/84", func_801042C8);
