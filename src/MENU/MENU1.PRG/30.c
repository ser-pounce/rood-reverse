#include "common.h"
#include "../MAINMENU.PRG/413C.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"

INCLUDE_ASM("build/src/MENU/MENU1.PRG/nonmatchings/30", func_80102830);

INCLUDE_ASM("build/src/MENU/MENU1.PRG/nonmatchings/30", func_80102914);

INCLUDE_ASM("build/src/MENU/MENU1.PRG/nonmatchings/30", func_80102A4C);

INCLUDE_ASM("build/src/MENU/MENU1.PRG/nonmatchings/30", func_80102F68);

void func_801031FC()
{
    func_800C8E5C_t* temp_v0;

    temp_v0 = func_800C8E5C(1, 0x140, 0x12, 0x8C, 8, &D_800EB9DC[D_800EB9DC[1]]);
    temp_v0->unk0 = 2;
    temp_v0->unk18 = 0xB4;
    temp_v0->unk6 = 1;
    func_800FFA88(2);
    func_800FFBC8();
}

INCLUDE_ASM("build/src/MENU/MENU1.PRG/nonmatchings/30", func_80103270);
