#include "common.h"
#include "../MAINMENU.PRG/C48.h"
#include "../MAINMENU.PRG/413C.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"

void func_80104650(int, int, int, int);

extern u_long* D_1F800000[];
extern u_short D_80105558[];
extern int D_80105D98;
extern int D_80105D9C;
extern int D_80105DA0;
extern int D_80105DA4;
extern char D_80105DB2;
extern char D_80105F40[];

INCLUDE_ASM("build/src/MENU/MENU8.PRG/nonmatchings/88", func_80102888);

INCLUDE_ASM("build/src/MENU/MENU8.PRG/nonmatchings/88", func_80102A5C);

INCLUDE_ASM("build/src/MENU/MENU8.PRG/nonmatchings/88", func_80102C0C);

INCLUDE_ASM("build/src/MENU/MENU8.PRG/nonmatchings/88", func_80102DBC);

INCLUDE_ASM("build/src/MENU/MENU8.PRG/nonmatchings/88", func_80102F68);

INCLUDE_ASM("build/src/MENU/MENU8.PRG/nonmatchings/88", func_80103110);

int func_801032B8(int arg0) {
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

INCLUDE_ASM("build/src/MENU/MENU8.PRG/nonmatchings/88", func_801035FC);

INCLUDE_ASM("build/src/MENU/MENU8.PRG/nonmatchings/88", func_801037B4);

INCLUDE_ASM("build/src/MENU/MENU8.PRG/nonmatchings/88", func_80103D88);

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

INCLUDE_ASM("build/src/MENU/MENU8.PRG/nonmatchings/88", func_8010475C);

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
