#include "592C.h"
#include "../MAINMENU.PRG/278.h"
#include "../../BATTLE/BATTLE.PRG/146C.h"
#include "../../BATTLE/BATTLE.PRG/2842C.h"
#include "../../BATTLE/BATTLE.PRG/30D14.h"
#include "../../BATTLE/BATTLE.PRG/40564.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"

int func_80107FBC(int arg0)
{
    int temp_s0 = D_800E8F28;

    switch (temp_s0) {
    case 0:
        func_8010812C(arg0);
        ++D_800E8F28;
        break;
    case 1:
        if (func_8010823C() != temp_s0) {
            ++D_800E8F28;
        }
        break;
    case 2:
        func_800F9CB0();
        D_800F453C->unk8 |= 0x800000;
        func_800A0204(1, 1, 0, 0);
        D_800E8F28 = 0;
        return 0;
    }
    return 1;
}

void func_80108098(void)
{
    func_8009CFB0(1);
    func_8009CFB0(0x10);
    func_801084E4();
}

void func_801080C8(void)
{
    D_800F453C_t* p = D_800F453C;
    p->unk5B8 = 0x21;
    p->unk8 &= 0xFF7FFFFF;
    func_800AD008(p, p + 1);
    func_800A087C(1, 3);
    func_8009F940(1, 0, NULL, NULL);
}
