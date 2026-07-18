#include "57BC.h"
#include "592C.h"
#include "src/BATTLE/BATTLE.PRG/146C.h"
#include "src/BATTLE/BATTLE.PRG/2842C.h"
#include "src/BATTLE/BATTLE.PRG/30D14.h"
#include "src/BATTLE/BATTLE.PRG/40564.h"
#include "src/BATTLE/BATTLE.PRG/5BF94.h"
#include "src/MENU/MAINMENU.PRG/224.h"

int vs_menu9_loadZud(int zudId)
{
    int state = vs_battle_loadObjectDataState;

    switch (state) {
    case 0:
        vs_menu9_loadZudFile(zudId);

        ++vs_battle_loadObjectDataState;
        break;

    case 1:
        if (vs_menu9_parseZudFile() != 1) {
            ++vs_battle_loadObjectDataState;
        }

        break;

    case 2:
        func_800F9CB0();

        D_800F4538[1]->unk0.weaponDrawn = 1;

        func_800A0204(1, 1, 0, 0);

        vs_battle_loadObjectDataState = 0;
        return 0;
    }

    return 1;
}

void vs_menu9_freeZud(void)
{
    func_8009CFB0(1);
    func_8009CFB0(16);
    vs_menu9_freeZudFile();
}

void func_801080C8(void)
{
    D_800F4538_t* p = D_800F4538[1];

    p->animationId = 33;
    p->unk0.weaponDrawn = 0;

    func_800AD008(p, &p->unk704);
    func_800A087C(1, 3);
    func_8009F940(1, 0, NULL, NULL);
}
