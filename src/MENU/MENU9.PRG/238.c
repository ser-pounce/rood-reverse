#include "common.h"
#include "../MAINMENU.PRG/C48.h"
#include "../MAINMENU.PRG/413C.h"
#include "../MAINMENU.PRG/8170.h"
#include "../../SLUS_010.40/main.h"
#include "../../BATTLE/BATTLE.PRG/2842C.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"
#include <libetc.h>

void func_801084E4();

extern char D_800F4EEA;
extern short D_801098A4[];
extern u_int D_801098C4[];
extern int D_8010A460;
extern short D_8010A464;
extern char D_8010A480[16];
extern char D_8010A490[16];
extern void* D_8010A4AC;

void func_80102A38(int arg0)
{
    if (arg0 != 0) {
        func_800FFA88(2);
        D_801022D6 = 0;
    } else {
        func_800FFA88(0);
        D_801022D6 = 1;
    }
}

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_80102A7C);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_80102E10);

int func_80102F0C(void)
{
    int row;

    row = vs_mainmenu_getSelectedRow();
    if (row < -1) {
        func_800FA8E0(5);
    } else if (row >= 0) {
        func_800FA92C(D_800F4EEA, 1);
    }
    return row;
}

void func_80102F64(char* arg0)
{
    vs_battle_menuItem_t* temp_v0;

    temp_v0 = vs_battle_setMenuItem(0xA, 0x140, 0x22, 0x8C, 9, arg0);
    temp_v0->state = 2;
    temp_v0->x = 0xB4;
    temp_v0->selected = 1;
    temp_v0->unkA = 1;
}

void func_80102FB8(void) { func_800FA8E0(8); }

void _menuReady(void) { vs_mainmenu_ready(); }

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_80102FF8);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_801031BC);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_8010337C);

void func_80104AF8(void)
{
    vs_main_memcpy((void*)getScratchAddr(13), D_8010A480, sizeof D_8010A480);
    vs_main_memcpy((void*)getScratchAddr(21), D_8010A490, sizeof D_8010A490);
}

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

void _vsStrcpy(u_char* arg0, u_char* arg1)
{
    while (*arg1 != 0xE7) {
        *arg0++ = *arg1++;
    }
    *arg0 = *arg1;
}

void _vsStrcat(char* arg0, char* arg1)
{
    while (*arg0 != 0xE7) {
        ++arg0;
    }
    while (*arg1 != 0xE7) {
        *arg0++ = *arg1++;
    }
    *arg0 = *arg1;
}

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_80106780);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_80106808);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_80106CEC);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_80106D5C);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_80106DE0);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_80106F9C);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_80107090);

INCLUDE_RODATA("build/src/MENU/MENU9.PRG/nonmatchings/238", D_801029AC);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_80107120);

void func_80107600(void)
{
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

void func_801084E4(void)
{
    vs_main_freeHeapR(D_8010A4AC);
    D_8010A4AC = NULL;
}

void func_80108514(void) { }
