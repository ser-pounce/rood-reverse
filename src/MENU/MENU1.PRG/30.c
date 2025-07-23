#include "common.h"
#include "../MAINMENU.PRG/413C.h"
#include "../../BATTLE/BATTLE.PRG/146C.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"

extern char D_8010451C[];

void func_80102830(int arg0)
{
    int temp_v0;
    int var_s1;
    int var_a0;

    temp_v0 = func_8008A5D0(0, arg0);
    func_80100100(1, "HP", 8, (temp_v0 >> 1) & 1);
    var_s1 = 0xF;
    var_a0 = vs_main_skills[arg0].cost;
    D_8010451C[15] = 0;

    do {
        --var_s1;
        var_a0 = func_800CCC54(var_a0);
        D_8010451C[var_s1] = (var_a0 & 0xF) + 0x30;
        var_a0 >>= 4;
    } while (var_a0 != 0);

    --var_s1;
    D_8010451C[var_s1] = 0x23;
    func_80100100(0, &D_8010451C[var_s1], 0x48, (temp_v0 >> 1) & 1);
}

INCLUDE_ASM("build/src/MENU/MENU1.PRG/nonmatchings/30", func_80102914);

INCLUDE_ASM("build/src/MENU/MENU1.PRG/nonmatchings/30", func_80102A4C);

INCLUDE_ASM("build/src/MENU/MENU1.PRG/nonmatchings/30", func_80102F68);

void func_801031FC()
{
    func_800C8E5C_t* temp_v0;

    temp_v0 = func_800C8E5C(1, 0x140, 0x12, 0x8C, 8, (char*)&D_800EB9DC[D_800EB9DC[1]]);
    temp_v0->unk0 = 2;
    temp_v0->unk18 = 0xB4;
    temp_v0->unk6 = 1;
    func_800FFA88(2);
    func_800FFBC8();
}

INCLUDE_ASM("build/src/MENU/MENU1.PRG/nonmatchings/30", func_80103270);
