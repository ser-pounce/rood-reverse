#include "common.h"
#include "8170.h"
#include "C48.h"
#include "413C.h"
#include "../BATTLE/BATTLE.PRG/5BF94.h"

void func_80101970(void);
INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/8170", func_80101970);

void func_80101F38(void)
{
    int var_s0;

    var_s0 = D_801022D8;
    if (D_801023D4 != NULL) {
        func_80100A5C();
    }
    if (D_801022DC != 0) {
        var_s0 = var_s0 + 2;
        if (var_s0 >= 17) {
            var_s0 = 16;
        }
    } else {
        var_s0 = var_s0 - 2;
        if (var_s0 < 0) {
            var_s0 = 0;
        }
    }
    D_801022D8 = var_s0;
    if (var_s0 != 0) {
        func_80101118(var_s0);
    }
    if (vs_battle_shortcutInvoked == 0) {
        func_800FFA94();
    }
    if (vs_battle_menuItems != 0) {
        func_80101970();
    }
    func_80100164();
    func_800FBBD4(0);
    vs_battle_renderEquipStats(0);
    vs_mainMenu_drawDpPpbars(0);
}
