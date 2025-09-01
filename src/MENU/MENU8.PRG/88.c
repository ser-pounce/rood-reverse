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
extern char D_80105DB2;
extern char D_80105F40[];
extern char D_80105F53;

extern char D_80105D64[];
extern int D_80105D68;
extern int D_80105D6C;

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

INCLUDE_ASM("build/src/MENU/MENU8.PRG/nonmatchings/88", func_801037B4);

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

INCLUDE_ASM("build/src/MENU/MENU8.PRG/nonmatchings/88", func_80103FD8);

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

void func_801046F0(int arg0, int arg1, int arg2)
{
    int temp_s1;
    int temp_s2;

    temp_s1 = arg1 * 12;
    temp_s2 = arg2 * 16;
    func_80104650(temp_s1 + 0x80, temp_s2 + 0x4C, 0xA, 0x12);
    func_800FFCDC(arg0, (temp_s1 + 0x70) | ((temp_s2 + 0x42) << 0x10));
}

extern u_short D_80105DB4[];
extern char D_80105F00;
extern char D_80105F01;
extern char D_80105EF5;

int func_8010475C(int arg0)
{
    int i;
    vs_battle_menuItem_t* menuItem;

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

INCLUDE_ASM("build/src/MENU/MENU8.PRG/nonmatchings/88", func_80105314);
