#include "common.h"
#include "../../BATTLE/BATTLE.PRG/146C.h"
#include "../../BATTLE/BATTLE.PRG/2842C.h"

// https://decomp.me/scratch/JlHtx
// 2.7.2-cdk
INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/68C4", func_801090C4);

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
