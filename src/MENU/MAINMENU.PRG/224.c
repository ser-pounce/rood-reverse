#include "common.h"
#include "278.h"
#include "../BATTLE/BATTLE.PRG/2842C.h"
#include "../BATTLE/BATTLE.PRG/30D14.h"
#include "../BATTLE/BATTLE.PRG/3A1A0.h"
#include "../BATTLE/BATTLE.PRG/5BF94.h"

void func_800F9A24(int arg0)
{
    func_800F9A78(arg0);
    func_800F9CB0();
    D_800F453C->unk8 |= 0x800000;
    func_800A0204(1, 1, 0, 0);
}

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/224", func_800F9A78);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/224", func_800F9CB0);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/224", func_800F9E0C);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/224", func_800F9EB8);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/224", func_800FA188);

int func_800FA238(int arg0, int arg1, int arg2)
{
    D_800F45E0_t* temp_v1;
    D_800F45E0_t** var_t0;
    int i;
    int new_var;
    
    var_t0 = D_800F45E0;
    new_var = arg2 + 0x80;
    
    for (i = 0; i < 16; ++i) {
        temp_v1 = var_t0[i];
        if (((((((var_t0[i] != 0) && ((var_t0[i]->unk8 & 1) == 0))
                   && (!(temp_v1->unk8 & 0xF00)))
                  && (temp_v1->unk5C == arg0))
                 && (temp_v1->unk5E == arg1))
                && ((temp_v1->unk1E >= arg2) != 0))
            && (new_var >= temp_v1->unk1E)) {
            return 1;
        }
    }

    return 0;
}

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/224", func_800FA2CC);

void func_800FA3FC(int arg0)
{
    func_8007C8F8_t sp10;

    func_8009CC20(0, 0);
    sp10.unk0 = 7;
    sp10.unk1 = 0;
    sp10.unk2 = arg0;
    sp10.unk10 = 0;
    func_800995E8(&sp10);
}
