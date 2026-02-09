#include "../MAINMENU.PRG/278.h"
#include "../../BATTLE/BATTLE.PRG/146C.h"
#include "../../BATTLE/BATTLE.PRG/30D14.h"

int func_8010BA58(int arg0)
{
    int _[6] __attribute__((unused));
    char* new_var = (char*)D_800F4538[0];

    if (arg0 == 1) {
        func_8009AA84(1);
        func_800FA2CC();
        return 0;
    }
    switch (D_800E8F28) {
    case 0:
        if (new_var[0x5B1] == 0xA) {
            return 0;
        }
        func_8009AA84(0);
        func_800FA3FC(0xA);
        ++D_800E8F28;
        break;
    case 1:
        if (func_8009967C() == 0) {
            func_800FA2CC();
            D_800E8F28 = 0;
            return 0;
        }
        break;
    }
    return 1;
}
