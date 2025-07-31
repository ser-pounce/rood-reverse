#include "common.h"
#include "../../SLUS_010.40/main.h"
#include "../MAINMENU.PRG/413C.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"

extern u_short D_80104690[];
extern char D_8010505A[];
extern char D_80105078[];
extern char D_801050B0[];

void func_80102864(int ability)
{
    int temp_v0;
    int i;
    int temp_v0_2;
    char* temp_a1;
    int cost;

    vs_mainmenu_setAbilityCost(1, "RISK", 8, 0);
    cost = vs_main_skills[ability].cost;
    D_801050B0[15] = 0;

    i = 15;
    do {
        --i;
        cost = vs_battle_toBCD(cost);
        D_801050B0[i] = (cost & 0xF) + 0x30;
        cost >>= 4;
    } while (cost != 0);

    --i;
    D_801050B0[i] = '#';
    vs_mainmenu_setAbilityCost(0, &D_801050B0[i], 0x48, 0);
}

INCLUDE_ASM("build/src/MENU/MENU2.PRG/nonmatchings/64", func_80102928);

INCLUDE_ASM("build/src/MENU/MENU2.PRG/nonmatchings/64", func_80102B5C);

INCLUDE_ASM("build/src/MENU/MENU2.PRG/nonmatchings/64", func_80102CAC);

INCLUDE_ASM("build/src/MENU/MENU2.PRG/nonmatchings/64", func_801034FC);

INCLUDE_ASM("build/src/MENU/MENU2.PRG/nonmatchings/64", func_80103670);

INCLUDE_ASM("build/src/MENU/MENU2.PRG/nonmatchings/64", func_801037E4);

INCLUDE_ASM("build/src/MENU/MENU2.PRG/nonmatchings/64", func_801038D4);

INCLUDE_ASM("build/src/MENU/MENU2.PRG/nonmatchings/64", func_80103C3C);

char* func_80103DD8(int arg0)
{
    u_char temp_v1;

    temp_v1 = D_80105078[arg0];
    if (D_80105078[arg0] == 0) {
        return D_8010505A;
    }
    return (char*)&D_80104690[D_80104690[temp_v1]];
}

INCLUDE_ASM("build/src/MENU/MENU2.PRG/nonmatchings/64", func_80103E20);

INCLUDE_ASM("build/src/MENU/MENU2.PRG/nonmatchings/64", func_80104578);
