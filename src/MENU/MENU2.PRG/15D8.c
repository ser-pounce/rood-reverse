#include "../../assets/MENU/MENU2.PRG/battleAbilitiesMenu.h"
#include "../MAINMENU.PRG/C48.h"
#include "../MAINMENU.PRG/413C.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"
#include <memory.h>

int func_80103C3C(int);
char* func_80103DD8(int arg0);

extern u_short D_80104ED8[];

static char D_80105060[]
    = { 0x18, 0x19, 0x22, 0x25, 0x23, 0x1E, 0x1A, 0x1B, 0x20, 0x1D, 0x1F };
static char D_8010506C[]
    = { 0x2F, 0x30, 0x31, 0x32, 0x29, 0x2A, 0x33, 0x34, 0x2C, 0x2D, 0x35 };
char D_80105078[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08,
    0x09, 0x0A, 0x0B, 0x00, 0x0D, 0x0E, 0x0F, 0x10, 0x00, 0x11, 0x12, 0x00, 0x13, 0x00,
    0x00, 0x00, 0x15, 0x16, 0x00, 0x18, 0x19, 0x00, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F, 0x20,
    0x21, 0x00, 0x00 };

static u_char D_80105100[16];
static u_char D_80105110[11];
static u_char D_8010511B;
static u_char D_8010511C;
static char D_8010511D;
static char D_8010511E;
static char D_8010511F;

extern u_short _battleAbilityStrings[];

char* func_80103DD8(int arg0)
{
    u_char temp_v1;

    temp_v1 = D_80105078[arg0];
    if (D_80105078[arg0] == 0) {
        return (char*)&D_80104ED8[VS_battleAbilitiesMenu_OFFSET_unknown1];
    }
    return (char*)&_battleAbilityStrings[_battleAbilityStrings[temp_v1]];
}

int func_80103E20(int arg0)
{
    char* sp18[4];
    int sp28[2];
    char* sp30[22];
    int sp88[11];
    char* spB8[22];
    int sp110[11];
    int temp_v0_5;
    int var_a0;
    int var_s0_5;
    int i;
    int var_s0;
    vs_battle_menuItem_t* temp_v0_4;
    int skill;

    if (arg0 != 0) {
        i = vs_main_artsStatus.kills.battleAbilitiesUnlocked;
        if (i != 22) {
            if (vs_main_artsStatus.kills.total
                >= vs_main_battleAbilitiesPointsRequirements[i]) {

                ++vs_main_artsStatus.kills.battleAbilitiesUnlocked;
                memset(D_800F4F1C, 0, 6);

                D_8010511B = 0;
                for (i = 0; i < 11; ++i) {
                    int a0 = D_80105060[i];
                    if (!((vs_main_skills[a0].flags >> 0xF) & 1)) {
                        D_80105100[D_8010511B++] = a0;
                    }
                }

                D_8010511C = 0;
                for (i = 0; i < 11; ++i) {
                    int a0 = D_8010506C[i];
                    if (!((vs_main_skills[a0].flags >> 0xF) & 1)) {
                        D_80105110[D_8010511C++] = a0;
                    }
                }
                D_8010511F = 3;
                D_8010511E = 120;
                D_8010511D = 0;
                return 0;
            }
        }
        return 1;
    }

    switch (D_8010511D) {
    case 0:
        var_s0 = D_8010511B != 0;
        if (D_8010511C != 0) {
            var_s0 += 2;
        }
        switch (var_s0) {
        case 0:
            vs_mainmenu_setMessage(
                (char*)&D_80104ED8[VS_battleAbilitiesMenu_OFFSET_allAbilitiesUnlocked]);
            D_8010511D = 6;
            break;
        case 1:
            temp_v0_4 = vs_battle_setMenuItem(0, 0x140, 0x12, 0x8C, 8,
                (char*)&D_80104ED8[VS_battleAbilitiesMenu_OFFSET_chainAbilities]);
            temp_v0_4->state = 2;
            temp_v0_4->x = 0xB4;
            temp_v0_4->selected = 1;
            D_8010511D = 2;
            break;
        case 2:
            temp_v0_4 = vs_battle_setMenuItem(1, 0x140, 0x12, 0x8C, 8,
                (char*)&D_80104ED8[VS_battleAbilitiesMenu_OFFSET_defenseAbilities]);
            temp_v0_4->x = 0xB4;
            temp_v0_4->state = var_s0;
            temp_v0_4->selected = 1;
            D_8010511D = 3;
            break;
        case 3:
            i = vs_main_settings.cursorMemory;
            sp18[0] = (char*)&D_80104ED8[VS_battleAbilitiesMenu_OFFSET_chainAbilities];
            sp18[1] = (char*)(&D_80104ED8[VS_battleAbilitiesMenu_OFFSET_select]);
            sp18[2]
                = (char*)(&D_80104ED8[VS_battleAbilitiesMenu_OFFSET_defenseAbilities]);
            sp18[3] = sp18[1];
            sp28[0] = 0;
            sp28[1] = 0;
            vs_main_settings.cursorMemory = 1;
            vs_mainmenu_setMenuRows(2, 0x1A, sp18, sp28);
            D_8010511D = 1;
            vs_main_settings.cursorMemory = i;
            break;
        default:
            return 0;
        }
        break;
    case 1:
        temp_v0_5 = vs_mainmenu_getSelectedRow();
        i = temp_v0_5 + 1;
        if (i != 0) {
            if (i < 0) {
                func_800FA8E0(0x28);
                D_8010511D = 7;
            } else {
                func_800FA92C(temp_v0_5, 0);
                D_8010511D += i;
            }
        }
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            for (i = 0; i < D_8010511B; ++i) {
                sp30[i * 2] = vs_main_skills[D_80105100[i]].name;
                sp30[i * 2 + 1] = func_80103DD8(D_80105100[i]);
                sp88[i] = 0;
            }
            var_a0 = 4;
            if (D_8010511B == 1) {
                var_a0 = 1;
            } else if (D_8010511B < 5) {
                var_a0 = D_8010511B - 1;
            }
            i = vs_main_settings.cursorMemory;
            if (D_8010511F & 1) {
                --D_8010511F;
                vs_main_settings.cursorMemory = 1;
            }
            vs_mainmenu_setMenuRows(var_a0, 0x11B, sp30, sp88);
            vs_main_settings.cursorMemory = i;
            D_8010511D = 4;
        }
        break;
    case 3:
        if (vs_mainmenu_ready() != 0) {
            for (i = 0; i < D_8010511C; ++i) {
                spB8[i * 2] = vs_main_skills[D_80105110[i]].name;
                spB8[i * 2 + 1] = func_80103DD8(D_80105110[i]);
                sp110[i] = 0;
            }
            var_a0 = 4;
            if (D_8010511C == 1) {
                var_a0 = 1;
            } else if (D_8010511C < 5) {
                var_a0 = D_8010511C - 1;
            }
            i = vs_main_settings.cursorMemory;
            if (D_8010511F & 2) {
                D_8010511F -= 2;
                vs_main_settings.cursorMemory = 1;
            }
            vs_mainmenu_setMenuRows(var_a0, 0x11C, spB8, sp110);
            vs_main_settings.cursorMemory = i;
            D_8010511D = 5;
        }
        break;
    case 4:
        var_s0_5 = vs_mainmenu_getSelectedRow();
        skill = var_s0_5 + 1;
        if (skill != 0) {
            func_800FA8E0(0x28);
            if (skill < 0) {
                D_8010511D = 7;
                break;
            }
            func_800C8E04(3);
            skill = D_80105100[var_s0_5];
            D_800F5194 = vs_main_skills[skill].name;
            vs_mainmenu_setMessage(
                (char*)&D_80104ED8[VS_battleAbilitiesMenu_OFFSET_battleAbilityUnlock]);
            vs_main_skills[skill].flags |= 0x8000;
            D_8010511D = 6;
        }
        break;
    case 5:
        var_s0_5 = vs_mainmenu_getSelectedRow();
        skill = var_s0_5 + 1;
        if (skill != 0) {
            func_800FA8E0(0x28);
            if (skill < 0) {
                D_8010511D = 7;
                break;
            }
            func_800C8E04(3);
            skill = D_80105110[var_s0_5];
            D_800F5194 = vs_main_skills[skill].name;
            vs_mainmenu_setMessage(
                (char*)&D_80104ED8[VS_battleAbilitiesMenu_OFFSET_battleAbilityUnlock]);
            vs_main_skills[skill].flags |= 0x8000;
            D_8010511D = 6;
        }
        break;
    case 6:
        if ((D_800F5130 >> 0x1E) & 1) {
            if ((D_8010511E == 0) || ((char)vs_main_buttonsPressed != 0)) {
                return 1;
            }
            --D_8010511E;
        }
        break;
    case 7:
        if (vs_mainmenu_ready() != 0) {
            D_8010511D = 0;
        }
        break;
    }
    return 0;
}

int func_80104578(char* state)
{
    switch (*state) {
    case 0:
        func_800FFBC8();
        // Fallthrough
    case 1:
        *state = 3;
        if ((D_800F4E88 != 0) && (func_80103C3C(1) == 0)) {
            *state = 2;
        }
        break;
    case 2:
        if (func_80103C3C(0) != 0) {
            *state = 1;
        }
        break;
    case 3:
        *state = 5;
        if ((D_800F4FDA != 0) && (func_80103E20(1) == 0)) {
            *state = 4;
        }
        break;
    case 4:
        if (func_80103E20(0) != 0) {
            *state = 3;
        }
        break;
    case 5:
        if (func_800CD064(7) == 0) {
            *state = 0;
            return 1;
        }
        break;
    }
    return 0;
}
