#include "common.h"

extern u_short D_80104690[];
extern char D_8010505A[];
extern char D_80105078[];

INCLUDE_ASM("build/src/MENU/MENU2.PRG/nonmatchings/64", func_80102864);

INCLUDE_ASM("build/src/MENU/MENU2.PRG/nonmatchings/64", func_80102928);

INCLUDE_ASM("build/src/MENU/MENU2.PRG/nonmatchings/64", func_80102B5C);

INCLUDE_ASM("build/src/MENU/MENU2.PRG/nonmatchings/64", func_80102CAC);

INCLUDE_ASM("build/src/MENU/MENU2.PRG/nonmatchings/64", func_801034FC);

INCLUDE_ASM("build/src/MENU/MENU2.PRG/nonmatchings/64", func_80103670);

INCLUDE_ASM("build/src/MENU/MENU2.PRG/nonmatchings/64", func_801037E4);

INCLUDE_ASM("build/src/MENU/MENU2.PRG/nonmatchings/64", func_801038D4);

INCLUDE_ASM("build/src/MENU/MENU2.PRG/nonmatchings/64", func_80103C3C);

char* func_80103DD8(int arg0) {
    u_char temp_v1;

    temp_v1 = D_80105078[arg0];
    if (D_80105078[arg0] == 0) {
        return D_8010505A;
    }
    return (char*)&D_80104690[D_80104690[temp_v1]];
}

INCLUDE_ASM("build/src/MENU/MENU2.PRG/nonmatchings/64", func_80103E20);

INCLUDE_ASM("build/src/MENU/MENU2.PRG/nonmatchings/64", func_80104578);
