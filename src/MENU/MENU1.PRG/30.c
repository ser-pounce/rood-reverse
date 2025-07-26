#include "common.h"
#include "../MAINMENU.PRG/413C.h"
#include "../../BATTLE/BATTLE.PRG/146C.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"

extern char D_8010451C[];

void func_80102830(int arg0)
{
    int temp_v0;
    int i;
    int bcd;

    temp_v0 = func_8008A5D0(0, arg0);
    vs_mainmenu_setTextHeader(1, "HP", 8, (temp_v0 >> 1) & 1);
    bcd = vs_main_skills[arg0].cost;
    D_8010451C[15] = 0;

    i = 15;
    do {
        --i;
        bcd = vs_battle_toBCD(bcd);
        D_8010451C[i] = (bcd & 0xF) + 0x30;
        bcd >>= 4;
    } while (bcd != 0);

    --i;
    D_8010451C[i] = 0x23;
    vs_mainmenu_setTextHeader(0, &D_8010451C[i], 72, (temp_v0 >> 1) & 1);
}

INCLUDE_ASM("build/src/MENU/MENU1.PRG/nonmatchings/30", func_80102914);

INCLUDE_ASM("build/src/MENU/MENU1.PRG/nonmatchings/30", func_80102A4C);

INCLUDE_ASM("build/src/MENU/MENU1.PRG/nonmatchings/30", func_80102F68);

void func_801031FC()
{
    vs_battle_menuItem_t* temp_v0;

    temp_v0 = vs_battle_setMenuItem(
        1, 0x140, 0x12, 0x8C, 8, (char*)&D_800EB9DC[D_800EB9DC[1]]);
    temp_v0->unk0 = 2;
    temp_v0->x = 180;
    temp_v0->selected = 1;
    func_800FFA88(2);
    func_800FFBC8();
}

INCLUDE_ASM("build/src/MENU/MENU1.PRG/nonmatchings/30", func_80103270);
