#include "common.h"
#include "../MAINMENU.PRG/413C.h"
#include "../../BATTLE/BATTLE.PRG/146C.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"

extern u_short D_801067DC[][2];
extern u_char D_8010689C[];

INCLUDE_ASM("build/src/MENU/MENU0.PRG/nonmatchings/84", func_80102884);

INCLUDE_ASM("build/src/MENU/MENU0.PRG/nonmatchings/84", func_801029B8);

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
    func_800C8E5C_t* temp_v0;

    temp_v0 = func_800C8E5C(0, 0x140, 0x12, 0x8C, 8, &D_800EB9DC[D_800EB9DC[0]]);
    temp_v0->unk0 = 2;
    temp_v0->unk18 = 0xB4;
    temp_v0->unk6 = 1;
    func_800FFA88(2);
    func_800FFBC8();
}

INCLUDE_ASM("build/src/MENU/MENU0.PRG/nonmatchings/84", func_801042C8);
