#include "common.h"
#include "../../SLUS_010.40/main.h"
#include "../../SLUS_010.40/31724.h"

extern short D_80108E74[][4];
extern int D_80108EB4;

INCLUDE_ASM("build/src/MENU/MENU5.PRG/nonmatchings/E84", func_80103684);

INCLUDE_ASM("build/src/MENU/MENU5.PRG/nonmatchings/E84", func_801042B0);

INCLUDE_ASM("build/src/MENU/MENU5.PRG/nonmatchings/E84", func_80104384);

INCLUDE_ASM("build/src/MENU/MENU5.PRG/nonmatchings/E84", func_8010451C);

void func_8010467C(int* arg0)
{
    int temp_a0;
    int i;
    int* var_a1;

    var_a1 = arg0 + 1;
    temp_a0 = *arg0;

    for (i = 0; i < temp_a0; ++i) {
        *var_a1 = 1;
        var_a1 += 3;
    }
}

INCLUDE_ASM("build/src/MENU/MENU5.PRG/nonmatchings/E84", func_801046B0);

INCLUDE_ASM("build/src/MENU/MENU5.PRG/nonmatchings/E84", func_80104780);

INCLUDE_ASM("build/src/MENU/MENU5.PRG/nonmatchings/E84", func_80105B18);

INCLUDE_ASM("build/src/MENU/MENU5.PRG/nonmatchings/E84", func_80105D3C);

INCLUDE_ASM("build/src/MENU/MENU5.PRG/nonmatchings/E84", func_80105EC0);

INCLUDE_ASM("build/src/MENU/MENU5.PRG/nonmatchings/E84", func_801060E0);

void func_80106178(short* arg0, short arg1) {
    int temp_s0 = vs_math_sine(-arg1);
    int temp_v0 = vs_math_cosine(-arg1);
    
    arg0[0] = temp_v0;
    arg0[1] = 0;
    arg0[2] = -temp_s0;
    arg0[3] = 0;
    arg0[4] = 0x1000;
    arg0[5] = 0;
    arg0[6] = temp_s0;
    arg0[7] = 0;
    arg0[8] = temp_v0;
}

void func_801061EC(short* arg0, short arg1)
{
    int temp_s0 = vs_math_sine(arg1);
    int temp_v0 = vs_math_cosine(arg1);
    
    arg0[0] = 0x1000;
    arg0[1] = 0;
    arg0[2] = 0;
    arg0[3] = 0;
    arg0[4] = temp_v0;
    arg0[5] = -temp_s0;
    arg0[6] = 0;
    arg0[7] = temp_s0;
    arg0[8] = temp_v0;
}

INCLUDE_ASM("build/src/MENU/MENU5.PRG/nonmatchings/E84", func_8010625C);

INCLUDE_ASM("build/src/MENU/MENU5.PRG/nonmatchings/E84", func_80106570);

INCLUDE_ASM("build/src/MENU/MENU5.PRG/nonmatchings/E84", func_80106618);

INCLUDE_ASM("build/src/MENU/MENU5.PRG/nonmatchings/E84", func_801066E0);

INCLUDE_ASM("build/src/MENU/MENU5.PRG/nonmatchings/E84", func_80106AF4);

INCLUDE_ASM("build/src/MENU/MENU5.PRG/nonmatchings/E84", func_80106C84);

INCLUDE_ASM("build/src/MENU/MENU5.PRG/nonmatchings/E84", func_801074AC);

INCLUDE_ASM("build/src/MENU/MENU5.PRG/nonmatchings/E84", func_80107630);

INCLUDE_ASM("build/src/MENU/MENU5.PRG/nonmatchings/E84", func_801079B8);

INCLUDE_ASM("build/src/MENU/MENU5.PRG/nonmatchings/E84", func_80107A9C);

INCLUDE_ASM("build/src/MENU/MENU5.PRG/nonmatchings/E84", func_80107B10);

INCLUDE_ASM("build/src/MENU/MENU5.PRG/nonmatchings/E84", func_8010800C);

INCLUDE_ASM("build/src/MENU/MENU5.PRG/nonmatchings/E84", func_8010815C);

void func_80108274(int arg0, int arg1, int arg2, int arg3)
{
    D_80108E74[D_80108EB4][0] = arg0;
    D_80108E74[D_80108EB4][1] = arg1;
    D_80108E74[D_80108EB4][2] = arg2;
    D_80108E74[D_80108EB4][3] = arg3;
    ++D_80108EB4;
}

INCLUDE_ASM("build/src/MENU/MENU5.PRG/nonmatchings/E84", func_801082A8);

int func_8008E7BC(int, int, u_int);

int func_8010839C(int arg0, int arg1, int arg2)
{
    u_int temp_a2 = arg0 - 0x41;

    if ((temp_a2 < 7) && ((func_8008E7BC(arg1, arg2, temp_a2) != 0))) {
        return 0;
    }
    return vs_main_stateFlags.unk33F[arg0] < 2;
}
