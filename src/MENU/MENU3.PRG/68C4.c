#include "common.h"
#include "../MAINMENU.PRG/278.h"
#include "../../BATTLE/BATTLE.PRG/146C.h"
#include "../../BATTLE/BATTLE.PRG/2842C.h"
#include "../../BATTLE/BATTLE.PRG/30D14.h"
#include "../../BATTLE/BATTLE.PRG/44F14.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"

int func_80109320(int);
void func_80109344(int, int);

int func_801090C4(int arg0, int arg1, int arg2)
{
    int _[6] __attribute__((unused));
    D_800F453C_t* temp_s1;
    int i;
    int temp_s0;
    void* temp_s0_2;

    temp_s1 = D_800F453C;
    temp_s0 = D_800E8F28;

    switch (temp_s0) {
    case 0:
        if (arg0 == 0) {
            func_8009AA84(1);
            if ((i = arg1 != 0) && (func_80109320(temp_s1->unk5B1) != 0)) {
                func_8009AA84(0);
                func_800FA3FC(0xA);
            }
        } else {
            if (arg0 != temp_s1->unk5B1) {
                func_800FA3FC(arg0);
            }
            func_8009AA84(0);
            if ((D_800F4594 != 0) && (func_80109320(arg0) != 0)) {
                func_8009AA84(1);
            }
        }
        func_80109344(arg1, arg2);
        func_8009D934(1, 0, 1);
        ++D_800E8F28;
        break;
    case 1:
        if ((func_8009967C() == 0) && (temp_s1->unk5B8 == temp_s0)) {
            func_800FA2CC();
            ++D_800E8F28;
        }
        break;
    case 2:
        temp_s0_2 = (char*)temp_s1 + 0xC54;
        func_800F9E0C();
        func_800F9A78(0);
        func_800F9CB0();
        temp_s1->unk8 &= 0xFF7FFFFF;
        func_800A0204(1, 1, 0, 0);
        func_800AFA28(temp_s1, temp_s0_2, 1);
        vs_main_memcpy(temp_s1 + 1, temp_s0_2, 0x550);

        for (i = 0; i < 2; ++i) {
            if (D_800F4590[i] != NULL) {
                D_800F4590[i][17] = 0;
            }
        }

        func_8009D934(1, 1, 1);
        ++D_800E8F28;
        break;
    case 3:
        if (temp_s1->unk5B8 == 0x65) {
            D_800E8F28 = 0;
            return 0;
        }
        break;
    }
    return 1;
}

int func_80109320(int a0)
{
    int v0;
    if (a0 < 3) {
        return 0;
    }
    if (a0 == 8) {
        return 1;
    }
    return a0 & 1;
}

void func_80109344(int arg0, int arg1)
{
    func_8007C8F8_t sp10;
    int var_a2;
    int var_a3;

    if (arg0 != 0) {
        var_a2 = 0;
        if (arg0 < 0x60) {
            var_a3 = 0xF0;
        } else {
            var_a2 = 1;
            var_a3 = 0xF1;
        }
        sp10.unk0 = 3;
        sp10.unk1 = var_a2;
        sp10.unk2 = arg0;
        sp10.unk4 = vs_battle_characterState->unk48[var_a2];
        sp10.unk10 = 0;
        sp10.unk11 = var_a3;
        sp10.unk12 = arg1;
        func_800995E8(&sp10);
    }
}
