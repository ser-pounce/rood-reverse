#include "common.h"
// #include "../../build/assets/MENU/MENU8.PRG/rename.h"
#include "../MAINMENU.PRG/C48.h"
#include "../MAINMENU.PRG/413C.h"
#include "../../BATTLE/BATTLE.PRG/573B8.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"

static u_short D_80105558[] = {
#include "../../assets/MENU/MENU8.PRG/menu.vsString"
};

static char D_80105D64[] = { 3, 1, 0, 0 };

extern char D_80060029;
extern char D_800616B4;
extern char D_800616B5;
extern char D_800F4F72;
extern short D_80105D26[];

extern char D_80105F40[];
extern char D_80105F53;

static int func_80102888(int arg0)
{
    static int D_80105D68 = 0;
    static int D_80105D6C = 0;

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

static int func_80102A5C(int arg0)
{
    static int D_80105D70 = 0;
    static int D_80105D74 = 0;

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

static int func_80102C0C(int arg0)
{
    static int D_80105D78 = 0;
    static int D_80105D7C = 0;

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

static int func_80102DBC(int arg0)
{
    static int D_80105D80 = 0;
    static int D_80105D84 = 0;

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

static int func_80102F68(int arg0)
{
    static int D_80105D88 = 0;
    static int D_80105D8C = 0;

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

static int func_80103110(int arg0)
{
    static int D_80105D90 = 0;
    static int D_80105D94 = 0;

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

static int func_801032B8(int arg0)
{
    static int D_80105D98 = 0;
    static int D_80105D9C = 0;

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

static int func_8010345C(int arg0)
{
    static int D_80105DA0 = 0;
    static int D_80105DA4 = 0;

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

static int func_801035FC(int arg0)
{
    static int D_80105DA8 = 0;
    static int D_80105DAC = 0;

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
