#include "common.h"
#include "../MAINMENU.PRG/413C.h"
#include "../../BATTLE/BATTLE.PRG/146C.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"
#include "../../../build/src/BATTLE/BATTLE.PRG/menuStrings.h"

extern char _digitBuffer[];

static void _setArtCost(int art)
{
    int flags;
    int i;
    int cost;

    flags = vs_battle_getSkillFlags(0, art);
    vs_mainmenu_setAbilityCost(1, "HP", 8, (flags >> 1) & 1);
    cost = vs_main_skills[art].cost;
    _digitBuffer[15] = 0;

    i = 15;
    do {
        --i;
        cost = vs_battle_toBCD(cost);
        _digitBuffer[i] = (cost & 0xF) + 0x30;
        cost >>= 4;
    } while (cost != 0);

    --i;
    _digitBuffer[i] = 0x23;
    vs_mainmenu_setAbilityCost(0, &_digitBuffer[i], 72, (flags >> 1) & 1);
}

INCLUDE_ASM("build/src/MENU/MENU1.PRG/nonmatchings/30", func_80102914);

INCLUDE_ASM("build/src/MENU/MENU1.PRG/nonmatchings/30", func_80102A4C);

INCLUDE_ASM("build/src/MENU/MENU1.PRG/nonmatchings/30", func_80102F68);

void func_801031FC()
{
    vs_battle_menuItem_t* temp_v0;

    temp_v0 = vs_battle_setMenuItem(1, 0x140, 0x12, 0x8C, 8,
        (char*)&vs_battle_menuStrings
            [vs_battle_menuStrings[VS_menuStrings_INDEX_breakArts]]);
    temp_v0->state = 2;
    temp_v0->x = 180;
    temp_v0->selected = 1;
    func_800FFA88(2);
    func_800FFBC8();
}

INCLUDE_ASM("build/src/MENU/MENU1.PRG/nonmatchings/30", func_80103270);
