#include "common.h"
#include "../../BATTLE/BATTLE.PRG/2842C.h"
#include "../../SLUS_010.40/main.h"

void func_801084E4();

extern short D_801098A4[];
extern u_int D_801098C4[];
extern int D_8010A460;
extern short D_8010A464;

void func_80107600(void) {
    int i;
    int var_a2;
    int a1;
    
    for (i = 0, var_a2 = 0, a1 = 1; i < 16; ++i) {
        if (D_8005FEA0.unk0[0] & (a1 << i)) {
            ++var_a2;
        }
    }

    for (i = 0; i < 16; ++i) {
        if ((var_a2 >= D_801098A4[i]) && (D_8010A460 >= D_801098C4[i])) {
            D_8010A464 = i;
            return;
        }
    }
}


INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/4E00", func_801076A4);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/4E00", func_80107A98);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/4E00", func_80107C34);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/4E00", func_80107FBC);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/4E00", func_80108098);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/4E00", func_801080C8);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/4E00", func_8010812C);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/4E00", func_8010823C);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/4E00", func_801084E4);

void func_80108514(void) { }
