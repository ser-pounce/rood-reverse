#include "common.h"
#include "../MAINMENU.PRG/413C.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"

INCLUDE_ASM("build/src/MENU/MENU2.PRG/nonmatchings/1620", func_80103E20);

int func_80103C3C(int);
int func_80103E20(int);

int func_80104578(char* state)
{
    switch (*state) {
    case 0:
        func_800FFBC8();
        // Fallthrough
    case 1:
        *state = 3;
        if ((D_800F4E88 != 0) && (func_80103C3C(1) == 0)) {
            *state = 2;
        }
        break;
    case 2:
        if (func_80103C3C(0) != 0) {
            *state = 1;
        }
        break;
    case 3:
        *state = 5;
        if ((D_800F4FDA != 0) && (func_80103E20(1) == 0)) {
            *state = 4;
        }
        break;
    case 4:
        if (func_80103E20(0) != 0) {
            *state = 3;
        }
        break;
    case 5:
        if (func_800CD064(7) == 0) {
            *state = 0;
            return 1;
        }
        break;
    }
    return 0;
}
