#include "common.h"
#include "../MAINMENU.PRG/C48.h"
#include "../MAINMENU.PRG/413C.h"
#include "../../BATTLE/BATTLE.PRG/573B8.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"

void func_80104650(int, int, int, int);

extern u_long* D_1F800000[];
extern u_short D_80105558[];
extern int D_80105D98;
extern int D_80105D9C;
extern int D_80105DA0;
extern int D_80105DA4;
extern char D_80105DB0;
extern u_char D_80105DB2;
extern char D_80105F40[];
extern char D_80105F53;

extern char D_80105D64[];
extern int D_80105D68;
extern int D_80105D6C;
extern u_short D_80105DB4[];
extern char D_80105E20[];

int func_80102888(int arg0)
{
    char* menuStrings[6];
    int rowTypes[3];
    int i;

    if (arg0 != 0) {
        D_80105D68 = 0;
        return 0;
    }
    switch (D_80105D68) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            for (i = 0; i < 3; ++i) {
                menuStrings[i * 2] = (char*)&D_80105558[D_80105558[i * 2 + 0x14]];
                menuStrings[i * 2 + 1] = (char*)&D_80105558[D_80105558[i * 2 + 0x15]];
                rowTypes[i] = 0;
            }
            for (i = 0; i < 3; ++i) {
                if (vs_main_settings.simpleMap == D_80105D64[i]) {
                    rowTypes[i] |= 4;
                }
            }
            vs_mainmenu_setMenuRows(3, 0x246, menuStrings, rowTypes);
            D_80105D68 = 1;
        }
        break;
    case 1:
        D_80105D6C = vs_mainmenu_getSelectedRow() + 1;
        if (D_80105D6C != 0) {
            if (D_80105D6C == -2) {
                func_800FA8E0(0x28);
                func_800FFBA8();
                func_800FFA88(0);
            } else {
                func_800FA8E0(7);
            }
            D_80105D68 = 2;
        }
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            return D_80105D6C;
        }
        break;
    }
    return 0;
}

extern int D_80105D70;
extern int D_80105D74;

int func_80102A5C(int arg0)
{
    char* menuStrings[4];
    int rowTypes[2];
    int i;

    if (arg0 != 0) {
        D_80105D70 = 0;
        return 0;
    }
    switch (D_80105D70) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            for (i = 0; i < 2; ++i) {
                menuStrings[i * 2] = (char*)&D_80105558[D_80105558[i * 2 + 0x1A]];
                menuStrings[i * 2 + 1] = (char*)&D_80105558[D_80105558[i * 2 + 0x1B]];
                rowTypes[i] = 0;
            }
            i = 1 - ((*(u_int*)&vs_main_settings >> 5) & 1);
            rowTypes[i] |= 4;
            vs_mainmenu_setMenuRows(2, 0x247, menuStrings, rowTypes);
            D_80105D70 = 1;
        }
        break;
    case 1:
        D_80105D74 = vs_mainmenu_getSelectedRow() + 1;
        if (D_80105D74 != 0) {
            if (D_80105D74 == -2) {
                func_800FA8E0(0x28);
                func_800FFBA8();
                func_800FFA88(0);
            } else {
                func_800FA8E0(7);
            }
            D_80105D70 = 2;
        }
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            return D_80105D74;
        }
        break;
    }
    return 0;
}

extern int D_80105D78;
extern int D_80105D7C;

int func_80102C0C(int arg0)
{
    char* menuStrings[4];
    int rowTypes[2];
    int i;

    if (arg0 != 0) {
        D_80105D78 = 0;
        return 0;
    }
    switch (D_80105D78) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            for (i = 0; i < 2; ++i) {
                menuStrings[i * 2] = (char*)&D_80105558[D_80105558[i * 2 + 0x1E]];
                menuStrings[i * 2 + 1] = (char*)&D_80105558[D_80105558[i * 2 + 0x1F]];
                rowTypes[i] = 0;
            }
            i = 1 - ((*(u_int*)&vs_main_settings >> 6) & 1);
            rowTypes[i] |= 4;
            vs_mainmenu_setMenuRows(2, 0x248, menuStrings, rowTypes);
            D_80105D78 = 1;
        }
        break;
    case 1:
        D_80105D7C = vs_mainmenu_getSelectedRow() + 1;
        if (D_80105D7C != 0) {
            if (D_80105D7C == -2) {
                func_800FA8E0(0x28);
                func_800FFBA8();
                func_800FFA88(0);
            } else {
                func_800FA8E0(7);
            }
            D_80105D78 = 2;
        }
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            return D_80105D7C;
        }
        break;
    }
    return 0;
}

extern int D_80105D80;
extern int D_80105D84;

int func_80102DBC(int arg0)
{
    char* menuStrings[4];
    int rowTypes[2];
    int i;

    if (arg0 != 0) {
        D_80105D80 = 0;
        return 0;
    }
    switch (D_80105D80) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            for (i = 0; i < 2; ++i) {
                menuStrings[i * 2] = (char*)&D_80105558[D_80105558[i * 2 + 0x22]];
                menuStrings[i * 2 + 1] = (char*)&D_80105558[D_80105558[i * 2 + 0x23]];
                rowTypes[i] = 0;
            }
            i = 1 - (vs_main_settings.timingWeaponArmor >> 7);
            rowTypes[i] |= 4;
            vs_mainmenu_setMenuRows(2, 0x249, menuStrings, rowTypes);
            D_80105D80 = 1;
        }
        break;
    case 1:
        D_80105D84 = vs_mainmenu_getSelectedRow() + 1;
        if (D_80105D84 != 0) {
            if (D_80105D84 == -2) {
                func_800FA8E0(0x28);
                func_800FFBA8();
                func_800FFA88(0);
            } else {
                func_800FA8E0(7);
            }
            D_80105D80 = 2;
        }
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            return D_80105D84;
        }
        break;
    }
    return 0;
}

extern int D_80105D88;
extern int D_80105D8C;

int func_80102F68(int arg0)
{
    char* menuStrings[4];
    int rowTypes[2];
    int i;

    if (arg0 != 0) {
        D_80105D88 = 0;
        return 0;
    }
    switch (D_80105D88) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            for (i = 0; i < 2; ++i) {
                menuStrings[i * 2] = (char*)&D_80105558[D_80105558[i * 2 + 0x26]];
                menuStrings[i * 2 + 1] = (char*)&D_80105558[D_80105558[i * 2 + 0x27]];
                rowTypes[i] = 0;
            }
            i = 1 - D_80060021;
            rowTypes[i] |= 4;
            vs_mainmenu_setMenuRows(2, 0x24A, menuStrings, rowTypes);
            D_80105D88 = 1;
        }
        break;
    case 1:
        D_80105D8C = vs_mainmenu_getSelectedRow() + 1;
        if (D_80105D8C != 0) {
            if (D_80105D8C == -2) {
                func_800FA8E0(0x28);
                func_800FFBA8();
                func_800FFA88(0);
            } else {
                func_800FA8E0(7);
            }
            D_80105D88 = 2;
        }
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            return D_80105D8C;
        }
        break;
    }
    return 0;
}

extern int D_80105D90;
extern int D_80105D94;

int func_80103110(int arg0)
{
    char* menuStrings[4];
    int rowTypes[2];
    int i;

    if (arg0 != 0) {
        D_80105D90 = 0;
        return 0;
    }
    switch (D_80105D90) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            for (i = 0; i < 2; ++i) {
                menuStrings[i * 2] = (char*)&D_80105558[D_80105558[i * 2 + 0x2A]];
                menuStrings[i * 2 + 1] = (char*)&D_80105558[D_80105558[i * 2 + 0x2B]];
                rowTypes[i] = 0;
            }
            i = 1 - D_80060028;
            rowTypes[i] |= 4;
            vs_mainmenu_setMenuRows(2, 0x24B, menuStrings, rowTypes);
            D_80105D90 = 1;
        }
        break;
    case 1:
        D_80105D94 = vs_mainmenu_getSelectedRow() + 1;
        if (D_80105D94 != 0) {
            if (D_80105D94 == -2) {
                func_800FA8E0(0x28);
                func_800FFBA8();
                func_800FFA88(0);
            } else {
                func_800FA8E0(7);
            }
            D_80105D90 = 2;
        }
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            return D_80105D94;
        }
        break;
    }
    return 0;
}

int func_801032B8(int arg0)
{
    char* menuStrings[4];
    int rowTypes[2];
    int i;

    if (arg0 != 0) {
        D_80105D98 = 0;
        return 0;
    }
    switch (D_80105D98) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            for (i = 0; i < 2; ++i) {
                menuStrings[i * 2] = (char*)&D_80105558[D_80105558[i * 2 + 0x2E]];
                menuStrings[i * 2 + 1] = (char*)&D_80105558[D_80105558[i * 2 + 0x2F]];
                rowTypes[i] = 0;
            }
            i = ((*(u_int*)&vs_main_settings) >> 3) & 1;
            rowTypes[i] |= 4;
            vs_mainmenu_setMenuRows(2, 0x24C, menuStrings, rowTypes);
            D_80105D98 = 1;
        }
        break;
    case 1:
        D_80105D9C = vs_mainmenu_getSelectedRow() + 1;
        if (D_80105D9C != 0) {
            if (D_80105D9C == -2) {
                func_800FA8E0(0x28);
                func_800FFBA8();
                func_800FFA88(0);
            } else {
                func_800FA8E0(7);
            }
            D_80105D98 = 2;
        }
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            return D_80105D9C;
        }
        break;
    }
    return 0;
}

int func_8010345C(int arg0)
{
    char* menuStrings[4];
    int rowTypes[2];
    int i;

    if (arg0 != 0) {
        D_80105DA0 = 0;
        return 0;
    }
    switch (D_80105DA0) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            for (i = 0; i < 2; ++i) {
                menuStrings[i * 2] = (char*)&D_80105558[D_80105558[i * 2 + 0x32]];
                menuStrings[i * 2 + 1] = (char*)&D_80105558[D_80105558[i * 2 + 0x33]];
                rowTypes[i] = 0;
            }
            i = vs_main_soundMono;
            rowTypes[i] |= 4;
            vs_mainmenu_setMenuRows(2, 0x24D, menuStrings, rowTypes);
            D_80105DA0 = 1;
        }
        break;
    case 1:
        D_80105DA4 = vs_mainmenu_getSelectedRow() + 1;
        if (D_80105DA4 != 0) {
            if (D_80105DA4 == -2) {
                func_800FA8E0(0x28);
                func_800FFBA8();
                func_800FFA88(0);
            } else {
                func_800FA8E0(7);
            }
            D_80105DA0 = 2;
        }
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            return D_80105DA4;
        }
        break;
    }
    return 0;
}

extern int D_80105DA8;
extern int D_80105DAC;

int func_801035FC(int arg0)
{
    char* menuStrings[4];
    int rowTypes[2];
    int i;
    int state;

    if (arg0 != 0) {
        D_80105DA8 = 0;
        return 0;
    }
    state = D_80105DA8;
    switch (state) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            for (i = 0; i < 2; ++i) {
                menuStrings[i * 2] = (char*)&D_80105558[D_80105558[i * 2 + 0x36]];
                menuStrings[i * 2 + 1] = (char*)&D_80105558[D_80105558[i * 2 + 0x37]];
                rowTypes[i] = 0;
            }
            i = 1 - vs_main_vibrationEnabled;
            rowTypes[i] |= 4;
            vs_mainmenu_setMenuRows(2, 0x24E, menuStrings, rowTypes);
            D_80105DA8 = 1;
        }
        break;
    case 1:
        D_80105DAC = vs_mainmenu_getSelectedRow() + 1;
        if (D_80105DAC != 0) {
            if (D_80105DAC == -2) {
                func_800FA8E0(0x28);
                func_800FFBA8();
                func_800FFA88(0);
            } else {
                if (D_80105DAC == state) {
                    func_800438C8(0);
                }
                func_800FA8E0(7);
            }
            D_80105DA8 = 2;
        }
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            return D_80105DAC;
        }
        break;
    }
    return 0;
}

extern char D_80060029;
extern char D_800616B4;
extern char D_800616B5;
extern char D_800F4F72;
extern short D_80105D26[];

int func_801037B4(char* arg0)
{
    char* menuStrings[18];
    int rowTypes[9];
    int temp_v0;
    int i;
    int var_v1;
    u_int temp_v1_2;

    switch (*arg0) {
    case 3:
        if (vs_mainmenu_ready() == 0) {
            break;
        }
        func_800FFBC8();
        // Fallthrough
    case 4:
        for (i = 0; i < 9; ++i) {
            menuStrings[i * 2] = (char*)&D_80105558[D_80105558[i * 2]];
            menuStrings[i * 2 + 1] = (char*)&D_80105558[D_80105558[i * 2 + 1]];
            rowTypes[i] = 0;
        }

        if (D_800616B5 != 0) {
            menuStrings[13] = (char*)&D_80105D26;
            rowTypes[6] = 1;
        }
        i = vs_main_settings.cursorMemory;
        if (*arg0 != 3) {
            vs_main_settings.cursorMemory = 1;
        }
        vs_mainmenu_setMenuRows(9, 0x145, menuStrings, rowTypes);
        vs_main_settings.cursorMemory = i;
        *arg0 = 5;
        break;
    case 5:
        temp_v0 = vs_mainmenu_getSelectedRow();
        i = temp_v0 + 1;
        if (i != 0) {
            if (i > 0) {
                func_800FA92C(D_800F4F72, 1);
                switch (temp_v0) {
                case 0:
                    *arg0 = 6;
                    func_80102888(1);
                    return 0;
                case 1:
                    *arg0 = 7;
                    func_80102A5C(1);
                    return 0;
                case 2:
                    *arg0 = 8;
                    func_80102C0C(1);
                    return 0;
                case 3:
                    *arg0 = 9;
                    func_80102DBC(1);
                    return 0;
                case 4:
                    *arg0 = 0xA;
                    func_80102F68(1);
                    return 0;
                case 5:
                    *arg0 = 0xB;
                    func_80103110(1);
                    return 0;
                case 6:
                    *arg0 = 0xC;
                    func_801032B8(1);
                    return 0;
                case 7:
                    *arg0 = 0xD;
                    func_8010345C(1);
                    return 0;
                case 8:
                    *arg0 = 0xE;
                    func_801035FC(1);
                    return 0;
                }
            } else if (i == -2) {
                func_800FA8E0(0x28);
                *arg0 = 0x10;
            } else {
                func_800FA8E0(0x28);
                *arg0 = 0xF;
            }
        } else {
            if (D_800616B5 != 0) {
                if (func_801008B0() == 6) {
                    func_800C8E04(1);
                    D_800F514C = 0xB;
                } else if (D_80060028 != 0) {
                    func_800C8E04(2);
                    D_800F514C = 0xB;
                } else {
                    D_800F514C = 0;
                }
            }
            break;
        }
        break;
    case 6:
        i = func_80102888(0);
        if (i == 0) {
            break;
        }
        if (i == -2) {
            *arg0 = 0x10;
            break;
        }
        if (i > 0) {
            D_80060029 = D_80105D64[i - 1];
        }
        *arg0 = 4;
        break;
    case 7:
        i = func_80102A5C(0);
        if (i == 0) {
            break;
        }
        if (i == -2) {
            *arg0 = 0x10;
            break;
        }
        if (i > 0) {
            var_v1 = *(int*)&vs_main_settings & ~0x20;
            var_v1 |= ((2 - i) & 1) << 5;
            *(int*)&vs_main_settings = var_v1;
        }
        *arg0 = 4;
        break;
    case 8:
        i = func_80102C0C(0);
        if (i == 0) {
            break;
        }
        if (i == -2) {
            *arg0 = 0x10;
            break;
        }
        if (i > 0) {
            var_v1 = *(int*)&vs_main_settings & ~0x40;
            var_v1 |= (((2 - i) & 1) << 6);
            *(int*)&vs_main_settings = var_v1;
        }
        *arg0 = 4;
        break;
    case 9:
        i = func_80102DBC(0);
        if (i == 0) {
            break;
        }
        if (i == -2) {
            *arg0 = 0x10;
            break;
        }
        if (i > 0) {
            var_v1 = *(int*)&vs_main_settings & ~0x80;
            var_v1 |= (((2 - i) & 1) << 7);
            *(int*)&vs_main_settings = var_v1;
        }
        *arg0 = 4;
        break;
    case 10:
        i = func_80102F68(0);
        if (i == 0) {
            break;
        }
        if (i == -2) {
            *arg0 = 0x10;
            break;
        }
        if (i > 0) {
            D_80060021 = 2 - i;
        }
        *arg0 = 4;
        break;
    case 11:
        i = func_80103110(0);
        if (i == 0) {
            break;
        }
        if (i == -2) {
            *arg0 = 0x10;
            break;
        }
        if (i > 0) {
            D_80060028 = 2 - i;
            func_800FFBC8();
        }
        *arg0 = 4;
        break;
    case 12:
        i = func_801032B8(0);
        if (i == 0) {
            break;
        }
        if (i == -2) {
            *arg0 = 0x10;
            break;
        }
        if (i > 0) {
            temp_v1_2 = (*(int*)&vs_main_settings & ~8) | (((i - 1) & 1) * 8);
            *(int*)&vs_main_settings = temp_v1_2;
            D_800616B4 = ~(temp_v1_2 >> 3) & 1;
        }
        *arg0 = 4;
        break;
    case 13:
        i = func_8010345C(0);
        if (i == 0) {
            break;
        }
        if (i == -2) {
            *arg0 = 0x10;
            break;
        }
        if (i > 0) {
            vs_main_settings.monoSound = i - 1;
            vs_main_setMonoSound(vs_main_settings.monoSound);
        }
        *arg0 = 4;
        break;
    case 14:
        i = func_801035FC(0);
        if (i == 0) {
            break;
        }
        if (i == -2) {
            *arg0 = 0x10;
            break;
        }
        if (i > 0) {
            vs_main_vibrationEnabled = 2 - i;
        }
        *arg0 = 4;
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
        func_800FFBA8();
        func_800FFA88(0);
        if (vs_mainmenu_ready() != 0) {
            vs_battle_menuState.currentState = 8;
            *arg0 = 0;
            return 1;
        }
        break;
    }
    return 0;
}

int func_80103D88(int arg0)
{
    int temp_s1;
    int i;

    D_80105DB0 = 1;
    temp_s1 = arg0;

    if (vs_main_buttonRepeat & 0x10) {
        vs_battle_playMenuChangeSfx(vs_main_buttonRepeat);
        for (i = 19; arg0 < i; --i) {
            D_80105F40[i] = D_80105F40[i - 1];
        }
        D_80105F40[arg0] = 0x8F;
    } else if (vs_main_buttonRepeat & 0x80) {
        vs_battle_playMenuChangeSfx(vs_main_buttonRepeat);
        for (i = arg0; i < 19; ++i) {
            D_80105F40[i] = D_80105F40[i + 1];
        }
        D_80105F53 = 0x8F;
    } else if ((vs_main_buttonsState & 0xC) != 0xC) {
        if (vs_main_buttonRepeat & 4) {
            if (arg0 == 0) {
                if (vs_main_buttonsPressed.all & 4) {
                    arg0 = 19;
                }
            } else {
                --arg0;
            }
        }
        if (vs_main_buttonRepeat & 8) {
            if (arg0 == 0x13) {
                if (vs_main_buttonsPressed.all & 8) {
                    arg0 = 0;
                }
            } else {
                ++arg0;
            }
        }
    }
    if (arg0 != temp_s1) {
        vs_battle_playMenuChangeSfx();
    }
    return arg0;
}

int func_80103F1C(char* arg0)
{
    int var_a1;
    int i;

    for (var_a1 = 0, i = 0; i < 20; ++var_a1, ++i) {
        if (D_80105F40[i] == 0xE7) {
            break;
        }
        arg0[var_a1] = D_80105F40[i];
    }

    arg0[var_a1--] = 0xE7;

    while (arg0[var_a1] == 0x8F) {
        arg0[var_a1--] = 0xE7;
        if (var_a1 < 0) {
            return 1;
        }
    }

    var_a1 += 2;

    while (var_a1 < 0x18) {
        arg0[var_a1++] = 0;
    }

    return 0;
}

u_long* func_800C0214(int, int);
void func_800C70F8(int, int, int, u_long*);
void func_800C7210(char arg0);
int func_800C8FAC(int, int, int);
extern char D_80105DB1;
extern int D_80105EA8[];
extern char D_80105EE8;
extern char D_80105EEC[];
extern char D_80105EF4;

void func_80103FD8(int arg0)
{
    u_int* sp18;
    int temp_s4;
    int temp_t1;
    int j;
    int i;
    char* temp_s1;
    u_long* var_s1;
    int temp_s0_2;
    int temp_s3;

    sp18 = (u_int*)D_1F800000[1] - 1;
    func_800FFC68(3, (-arg0 + 0x10), 0x32, 0);
    func_800FFC68(1, (-arg0 + 0x10), 0x42, 0);
    func_800FFC68(0, (-arg0 + 0x10), 0x52, 0);
    var_s1 = func_800C0214(0x100010, ((-arg0 + 0x10) & 0xFFFF) | 0x220000);
    var_s1[4] = 0x37FB70B0;
    var_s1 += 6;
    D_80105EEC[D_80105DB2] = 8;
    D_80105DB2 = 0;

    for (i = 1; i < 5; ++i) {
        temp_s0_2 = D_80105EEC[i];
        if (D_80105EEC[i] != 0) {
            --D_80105EEC[i];
        }
        temp_s4 = func_800C8FAC(8 - temp_s0_2, 0, 0x80) | 0x50000000;
        temp_t1 = func_800C8FAC(temp_s0_2, 0, 0x80);

        for (j = 0; j < 12; ++j) {
            int v1;
            var_s1[0] = (*sp18 & 0xFFFFFF) | 0x06000000;
            var_s1[1] = 0xE1000200;
            var_s1[2] = temp_s4;
            var_s1[3] = ((-arg0) & 0xFFFF) | (j + 20 + i * 16) << 0x10;
            var_s1[4] = temp_t1;
            v1 = j - 0x60;
            var_s1[5] = ((-arg0 - v1) & 0xFFFF) | (j + 20 + i * 16) << 0x10;
            var_s1[6] = 0xE1000000;
            *sp18 = ((u_long)var_s1 << 8) >> 8;
            var_s1 += 7;
        }
    }

    D_1F800000[0] = var_s1;
    func_800C7210(4);
    for (i = 0; i < 4; ++i) {
        temp_s1 = (char*)&D_80105DB4[D_80105DB4[0xC - i]];
        temp_s4 = 0x28;
        while ((j = *temp_s1++) != 0xE7) {
            func_800C70F8(j, temp_s4 - arg0, 0x54 - (i * 0x10), D_1F800000[1] - 5);
            temp_s4 += 6;
        }
    }

    vs_battle_setMenuItem(0x1D, arg0 + 0x9C, 0x30, 0xA4, 0, &D_80105EE8)->selected = 1;
    for (j = 0; j < 20; ++j) {
        temp_s0_2 = D_80105F40[j];
        if (temp_s0_2 != 0x8F) {
            int new_var3 = (j * 6 + 0xA2);
            func_800C70F8(temp_s0_2, arg0 + new_var3, 0x30, D_1F800000[2] - 2);
        }
    }
    if (arg0 == 0) {
        u_long* a1;
        temp_s3 = 0x404040;
        temp_s4 = 0x37F9;
        if ((D_80105DB0 != 0) || (D_80105DB1 != 0xB)) {
            temp_s3 = 0x808080;
            ++D_80105DB1;
            --temp_s4;
            if (D_80105DB1 >= 0xC) {
                D_80105DB1 = 0;
            }
        }
        D_80105DB0 = 0;
        j = (D_80105DB1 >> 2);
        func_800C6540("1", 0x330098, temp_s3, 0);
        func_800C6540("L", 0x330092, temp_s3, 0);
        func_800C0214(0x100010, (136 - j) | 0x300000)[4] = (temp_s4 << 0x10) | 0x3000;
        func_800C6540("1", 0x330124, temp_s3, 0);
        func_800C6540("R", 0x33011E, temp_s3, 0);
        func_800C0214(0x100010, (j + 0x128) | 0x300000)[4] = (temp_s4 << 0x10) | 0x3010;
        a1 = D_1F800000[2];
        var_s1 = D_1F800000[0];
        var_s1[0] = ((u_long)a1[0] & 0xFFFFFF) | 0x09000000;
        var_s1[1] = 0xE1000200;
        var_s1[2] = 0x38000000;
        var_s1[3] = 0x1E00D0;
        var_s1[4] = 0;
        var_s1[5] = 0x2000E8;
        var_s1[6] = 0xC0A080;
        var_s1[7] = 0x2E00E8;
        var_s1[8] = 0;
        var_s1[9] = 0x1E0100;
        D_1F800000[2][0] = ((u_long)var_s1 << 8) >> 8;
        D_1F800000[0] = var_s1 + 10;

        if (++D_80105EF4 >= 0xC) {
            D_80105EF4 = 0;
        }
    }

    temp_s1 = D_80105E20;
    for (i = 0; i < 9; ++i) {
        for (j = 0; j < 0xE; ++j) {
            int temp_s8 = (arg0 + 0x82);
            func_800C70F8(temp_s1[i * 0xF + j], temp_s8 + j * 0xC, (i * 0x10) + 0x4E,
                D_1F800000[2] - 2);
        }
    }

    for (j = 0; j < 16; j += 4) {
        var_s1 = D_1F800000[0];
        var_s1[0] = (*sp18 & 0xFFFFFF) | 0x09000000;
        var_s1[1] = 0xE1000200;
        var_s1[2] = 0x386B4100;
        var_s1[3] = arg0 + D_80105EA8[j];
        var_s1[4] = 0x330500;
        var_s1[5] = arg0 + D_80105EA8[j + 1];
        var_s1[6] = 0x330500;
        var_s1[7] = arg0 + D_80105EA8[j + 2];
        var_s1[8] = 0x330500;
        var_s1[9] = arg0 + D_80105EA8[j + 3];
        *sp18 = ((u_long)var_s1 << 8) >> 8;
        D_1F800000[0] = (u_long*)(var_s1 + 10);
    }
}

static int const _ = 0;

void func_80104650(int arg0, int arg1, int arg2, int arg3)
{
    u_long* temp_t0;
    u_long* temp_t4;

    temp_t4 = D_1F800000[2];
    temp_t0 = D_1F800000[0];
    temp_t0[0] = (*temp_t4 & 0xFFFFFF) | 0x09000000;
    temp_t0[1] = 0xE1000220;
    temp_t0[2] = 0x3AC0A080;
    temp_t0[3] = (arg0 | (arg1 << 0x10));
    temp_t0[4] = 0;
    temp_t0[5] = ((arg0 + arg2) | (arg1 << 0x10));
    temp_t0[6] = 0;
    temp_t0[7] = (arg0 | ((arg1 + arg3) << 0x10));
    temp_t0[8] = 0xC0A080;
    temp_t0[9] = ((arg0 + arg2) | ((arg1 + arg3) << 0x10));
    *temp_t4 = ((u_long)temp_t0 << 8) >> 8;
    D_1F800000[0] = temp_t0 + 10;
}

int func_801046F0(int arg0, int arg1, int arg2)
{
    int temp_s1;
    int temp_s2;

    temp_s1 = arg1 * 12;
    temp_s2 = arg2 * 16;
    func_80104650(temp_s1 + 0x80, temp_s2 + 0x4C, 0xA, 0x12);
    return func_800FFCDC(arg0, (temp_s1 + 0x70) | ((temp_s2 + 0x42) << 0x10));
}

extern char D_80105F00;
extern char D_80105F01;
extern char D_80105EF5;

int func_8010475C(int arg0)
{
    int i;

    if (arg0 != 0) {
        D_80105F01 = 0;
        D_80105F00 = 0;
    }

    switch (D_80105F00) {
    case 0:
    case 1:
    case 2: {
        vs_battle_menuItem_t* menuItem
            = vs_battle_setMenuItem(D_80105F00 + 0x14, 0x140, (D_80105F00 * 0x10) + 0x80,
                0x7E, 0, (char*)&D_80105DB4[D_80105DB4[D_80105F00 + 6]]);
        menuItem->state = 2;
        menuItem->x = 0xC2;
        ++D_80105F00;
        break;
    }
    case 3:
        D_80105F00 += vs_mainmenu_ready();
        break;
    case 4:
        for (i = 0; i < 3; ++i) {
            vs_battle_getMenuItem(i + 0x14)->selected = (D_80105F01 ^ i) == 0;
        }

        if (vs_main_buttonsPressed.all & 0x60) {
            for (i = 0; i < 3; ++i) {
                func_800FA8A0(i + 0x14);
            }
            if (vs_main_buttonsPressed.all & 0x40) {
                D_80105F01 = 1;
            }
            return D_80105F01 + 1;
        }
        i = D_80105F01;
        if (vs_main_buttonRepeat & 0x1000) {
            i += 2;
        }
        if (vs_main_buttonRepeat & 0x4000) {
            ++i;
        }
        if (i >= 3) {
            i -= 3;
        }
        if (i != D_80105F01) {
            vs_battle_playMenuChangeSfx();
            D_80105F01 = i;
        }
        D_80105EF5 = vs_battle_drawCursor(D_80105EF5, i + 7);
        break;
    }
    return 0;
}

void func_8010493C(int arg0)
{
    int i;

    if (arg0 < 4) {
        D_80105DB2 = arg0 + 1;
    }

    for (i = 4; i < 9; ++i) {
        vs_battle_getMenuItem(i + 29)->selected = i == arg0;
    }
}

INCLUDE_ASM("build/src/MENU/MENU8.PRG/nonmatchings/88", func_801049A0);

void func_80103FD8(int);
int func_801049A0(int);
extern char D_80060170[];
extern char D_80105F2E;
extern char D_80105F30;
extern u_char D_80105F31;
extern char* D_80105F34;

int func_80105314(char* arg0)
{
    int i;
    int temp_a0;
    int temp_s0;
    char* var_v1;
    char* var_v0;
    int v1;

    temp_s0 = *arg0;
    switch (temp_s0) {
    case 0:
        D_80105F2E = D_800F4E8C->unk1;
        D_80105F34 = D_80105E20;
        func_800FFBA8();
        v1 = 0x8F;
        i = 19;
        var_v0 = &D_80105F40[i];
        for (; i >= 0; --i) {
            *var_v0-- = v1;
        }
        if (D_800F4E8C->unk0 == 1) {
            var_v1 = (D_80105F2E << 5) + D_80060170;
            for (i = 0; i < 20; ++i) {
                temp_a0 = *var_v1++;
                if (temp_a0 == 0xE7) {
                    break;
                } else if (temp_a0 == 0x8F) {
                    continue;
                } else if (temp_a0 == 0xFA) {
                    var_v1 += 1;
                } else {
                    D_80105F40[i] = temp_a0;
                }
            }
        }
        D_80105F30 = 0;
        D_80105F31 = 10;
        *arg0 = 1;
        break;
    case 1:
        func_801049A0(1);
        D_80105F30 = temp_s0;
        *arg0 = 2;
        break;
    case 2:
        if (func_801049A0(0) != 0) {
            func_800FA8A0(0xA);
            func_800FA810(0);
            func_800FFBC8();
            *arg0 = 3;
        }
        break;
    case 3:
        if (D_80105F31 == 0xA) {
            *arg0 = 0;
            vs_battle_menuState.currentState = 0xD;
        }
        break;
    }
    if (D_80105F30 != 0) {
        if (D_80105F31 != 0) {
            --D_80105F31;
        }
        func_80103FD8(vs_battle_rowAnimationSteps[D_80105F31]);
    } else if (D_80105F31 < 10) {
        ++D_80105F31;
        func_80103FD8(D_80105F31 << 5);
    }
    return 0;
}
