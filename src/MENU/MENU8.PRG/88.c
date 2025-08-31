#include "common.h"
#include "../MAINMENU.PRG/413C.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"

void func_80104650(int, int, int, int);

extern char D_80105DB2;

INCLUDE_ASM("build/src/MENU/MENU8.PRG/nonmatchings/88", func_80102888);

INCLUDE_ASM("build/src/MENU/MENU8.PRG/nonmatchings/88", func_80102A5C);

INCLUDE_ASM("build/src/MENU/MENU8.PRG/nonmatchings/88", func_80102C0C);

INCLUDE_ASM("build/src/MENU/MENU8.PRG/nonmatchings/88", func_80102DBC);

INCLUDE_ASM("build/src/MENU/MENU8.PRG/nonmatchings/88", func_80102F68);

INCLUDE_ASM("build/src/MENU/MENU8.PRG/nonmatchings/88", func_80103110);

INCLUDE_ASM("build/src/MENU/MENU8.PRG/nonmatchings/88", func_801032B8);

INCLUDE_ASM("build/src/MENU/MENU8.PRG/nonmatchings/88", func_8010345C);

INCLUDE_ASM("build/src/MENU/MENU8.PRG/nonmatchings/88", func_801035FC);

INCLUDE_ASM("build/src/MENU/MENU8.PRG/nonmatchings/88", func_801037B4);

INCLUDE_ASM("build/src/MENU/MENU8.PRG/nonmatchings/88", func_80103D88);

INCLUDE_ASM("build/src/MENU/MENU8.PRG/nonmatchings/88", func_80103F1C);

INCLUDE_ASM("build/src/MENU/MENU8.PRG/nonmatchings/88", func_80103FD8);

extern u_long* D_1F800000[];

void func_80104650(int arg0, int arg1, int arg2, int arg3) {
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
    *temp_t4 = ((u_long) temp_t0 << 8) >> 8;
    D_1F800000[0] = temp_t0 + 10;
}

void func_801046F0(int arg0, int arg1, int arg2) {
    int temp_s1;
    int temp_s2;

    temp_s1 = arg1 * 12;
    temp_s2 = arg2 * 16;
    func_80104650(temp_s1 + 0x80, temp_s2 + 0x4C, 0xA, 0x12);
    func_800FFCDC(arg0, (temp_s1 + 0x70) | ((temp_s2 + 0x42) << 0x10));
}

INCLUDE_ASM("build/src/MENU/MENU8.PRG/nonmatchings/88", func_8010475C);

void func_8010493C(int arg0) {
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
