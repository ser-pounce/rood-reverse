#include "common.h"
#include "../MAINMENU.PRG/C48.h"
#include "../../SLUS_010.40/main.h"
#include "../../BATTLE/BATTLE.PRG/2842C.h"

void func_801084E4();

extern short D_801098A4[];
extern u_int D_801098C4[];
extern int D_8010A460;
extern short D_8010A464;
extern void* D_8010A4AC;

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_80102A38);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_80102A7C);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_80102E10);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_80102F0C);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_80102F64);

void func_80102FB8(void) { func_800FA8E0(8); }

void _menuReady(void) { vs_mainmenu_ready(); }

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_80102FF8);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_801031BC);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_8010337C);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_80104AF8);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_80104B40);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_80104BD0);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_80104CBC);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_80104E90);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_80104F04);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_80104F74);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_801051AC);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_8010539C);

INCLUDE_RODATA("build/src/MENU/MENU9.PRG/nonmatchings/238", D_80102820);

INCLUDE_RODATA("build/src/MENU/MENU9.PRG/nonmatchings/238", D_80102830);

INCLUDE_RODATA("build/src/MENU/MENU9.PRG/nonmatchings/238", jtbl_80102898);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_8010552C);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_801056B8);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_8010579C);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_80105A0C);

INCLUDE_RODATA("build/src/MENU/MENU9.PRG/nonmatchings/238", D_80102930);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_80105BCC);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_80105D8C);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_80105F00);

INCLUDE_RODATA("build/src/MENU/MENU9.PRG/nonmatchings/238", D_80102940);

INCLUDE_RODATA("build/src/MENU/MENU9.PRG/nonmatchings/238", D_80102948);

INCLUDE_RODATA("build/src/MENU/MENU9.PRG/nonmatchings/238", D_80102950);

INCLUDE_RODATA("build/src/MENU/MENU9.PRG/nonmatchings/238", D_80102958);

INCLUDE_RODATA("build/src/MENU/MENU9.PRG/nonmatchings/238", D_80102960);

INCLUDE_RODATA("build/src/MENU/MENU9.PRG/nonmatchings/238", D_80102968);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_801061F8);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_80106528);

void _vsStringCpy(u_char* arg0, u_char* arg1) {
    while (*arg1 != 0xE7) {
        *arg0++ = *arg1++;
    }
    *arg0 = *arg1;
}

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_80106724);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_80106780);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_80106808);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_80106CEC);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_80106D5C);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_80106DE0);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_80106F9C);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_80107090);

INCLUDE_RODATA("build/src/MENU/MENU9.PRG/nonmatchings/238", D_801029AC);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_80107120);

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


INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_801076A4);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_80107A98);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_80107C34);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_80107FBC);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_80108098);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_801080C8);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_8010812C);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_8010823C);

void func_801084E4(void) {
    vs_main_freeHeapR(D_8010A4AC);
    D_8010A4AC = NULL;
}


void func_80108514(void) { }
