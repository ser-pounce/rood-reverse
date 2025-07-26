#include "common.h"
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
    int temp_v0_2;
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

INCLUDE_ASM("build/src/MENU/MENU0.PRG/nonmatchings/84", func_80103464);

INCLUDE_ASM("build/src/MENU/MENU0.PRG/nonmatchings/84", func_801037A8);

INCLUDE_ASM("build/src/MENU/MENU0.PRG/nonmatchings/84", func_80103AEC);

INCLUDE_ASM("build/src/MENU/MENU0.PRG/nonmatchings/84", func_80103E30);

void func_80104254()
{
    vs_battle_menuItem_t* temp_v0;

    temp_v0 = vs_battle_setMenuItem(
        0, 0x140, 0x12, 0x8C, 8, (char*)&D_800EB9DC[D_800EB9DC[0]]);
    temp_v0->unk0 = 2;
    temp_v0->x = 180;
    temp_v0->selected = 1;
    func_800FFA88(2);
    func_800FFBC8();
}

INCLUDE_ASM("build/src/MENU/MENU0.PRG/nonmatchings/84", func_801042C8);
