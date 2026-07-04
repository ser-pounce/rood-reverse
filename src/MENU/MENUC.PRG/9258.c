#include "9258.h"
#include "src/MENU/MAINMENU.PRG/224.h"
#include "src/BATTLE/BATTLE.PRG/146C.h"
#include "src/BATTLE/BATTLE.PRG/30D14.h"
#include "src/BATTLE/BATTLE.PRG/3A1A0.h"

int _loadObject(int arg0)
{
    int _[6] __attribute__((unused));
    D_800F4538_t* new_var = D_800F4538[0];

    if (arg0 == 1) {
        func_8009AA84(1);
        func_800FA2CC();
        return 0;
    }

    switch (vs_battle_loadObjectDataState) {
    case 0:
        if (new_var->unk5B1 == 10) {
            return 0;
        }

        func_8009AA84(0);
        func_800FA3FC(10);

        ++vs_battle_loadObjectDataState;
        break;

    case 1:
        if (vs_battle_processObjectDataQueue() == 0) {

            func_800FA2CC();

            vs_battle_loadObjectDataState = 0;
            return 0;
        }

        break;
    }

    return 1;
}
