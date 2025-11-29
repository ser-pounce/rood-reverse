#include "common.h"
#include "../MAINMENU.PRG/C48.h"
#include "../MAINMENU.PRG/413C.h"
#include "../../SLUS_010.40/main.h"
#include "../../BATTLE/BATTLE.PRG/2842C.h"
#include "../../BATTLE/BATTLE.PRG/573B8.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"

typedef struct {
    u_short unk0;
    char unk2;
} func_8010406C_t;

typedef struct {
    int unk0[10];
    char unk28;
    char unk29;
    char unk2A;
    char unk2B;
    int unk2C[39];
    char unkC8;
    char unkC9[19];
    u_short unkDC;
    u_short unkDE;
    u_short unkE0;
    u_short unkE2;
    short unkE4;
    short unkE6;
    short unkE8;
    short unkEA;
    short unkEC;
    short unkEE;
    int unkF0;
    short unkF4[16];
    short unk114[16];
} func_80103E24_t;

void func_80102BE4(int);

extern int D_80109568;
extern void (*D_8010962C[])(int);
extern u_char D_801096A3;
extern char D_80109711;
extern char D_80109712;
extern char D_80109713;
extern char D_80109717;
extern int D_80109718;
extern int D_8010975C;
extern int D_80109760;

void func_8010296C(char arg0)
{
    D_80109711 = arg0;
    D_80109712 = arg0;
    D_80109713 = arg0;
}

int func_80102988(int arg0, int arg1)
{
    int temp_a1;
    int temp_s1;

    if ((vs_main_buttonsState & 0xC) != 0xC) {
        temp_s1 = arg1;
        temp_a1 = 1;
        arg0 = func_800FEA6C(arg0, 0);
        if (vs_main_buttonRepeat & 4) {
            arg1 = arg1 - temp_a1 + arg0;
        }
        if (vs_main_buttonRepeat & 8) {
            ++arg1;
        }
        if (arg1 >= arg0) {
            arg1 -= arg0;
        }
        if ((vs_main_buttonsPressed.all & 0xC) && (arg1 == temp_s1)) {
            func_800C02E0();
        }
    }
    return arg1;
}

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80102A3C);

void func_80102B78(int arg0)
{
    vs_battle_menuItem_t* menuItem;

    func_800FA8E0(0x28);
    menuItem = vs_battle_getMenuItem(0x1F);
    menuItem->state = 3;
    menuItem->x = 0x12;
    menuItem = vs_battle_getMenuItem(arg0);
    menuItem->state = 2;
    menuItem->x = 0x9B;
    menuItem->selected = 1;
    menuItem->unk3A = 0;
}

void func_80102BE4(int arg0)
{
    vs_battle_menuItem_t* menuItem;

    menuItem = vs_battle_getMenuItem(0x1F);
    menuItem->state = 2;
    menuItem->x = 0x10;
    menuItem->unk1 = 0xA4;
    menuItem = vs_battle_getMenuItem(arg0);
    menuItem->state = 3;
    menuItem->x = 0x12;
}

void func_80102C44(int arg0, int arg1)
{
    D_80109568 = 1;
    D_80109712 = 0;
    D_80109713 = 0;
    func_80102BE4(arg0);
    func_800FBBD4(arg1);
    func_800FBEA4(1);
}

void func_80102C94(int arg0, char** arg1, u_int arg2, int arg3)
{
    vs_battle_menuItem_t* temp_v0;

    vs_battle_playMenuChangeSfx();
    temp_v0 = vs_battle_setMenuItem(arg0, 0x9B, 0x12, 0xA5, 0, arg1[0]);
    temp_v0->selected = 1;
    temp_v0->flags = (arg2 >> 0x1A);
    temp_v0->unkC = (arg2 >> 0x10) & 7;
    vs_mainmenu_setMessage(arg1[1]);
    vs_battle_getMenuItem(0x1F)->unkE = arg3 + 1;
}

int func_80102D30(int arg0, int arg1)
{
    D_800F4EE8.unk0[(arg0 + 0x1E) * 2] = 0;
    D_800F4EE8.unk0[(arg0 + 0x1E) * 2 + 1] = arg1;
    return *(D_801022A8[arg0] + arg1);
}

void func_80102D7C(int arg0)
{
    vs_battle_playMenuLeaveSfx();
    func_800FA8E0(0x28);
    func_800FA810(-1);
    func_800FBBD4(-1);
    func_800FBEA4(2);
    D_80109717 = 2;
    D_80109718 = vs_main_buttonsPressed.all & 0x10;
    if (arg0 != 0) {
        vs_mainMenu_drawDpPpbars(4);
    }
}

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80102DEC);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80103034);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80103220);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80103460);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_801036BC);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_801038E4);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80103AD0);

INCLUDE_RODATA("build/src/MENU/MENU3.PRG/nonmatchings/16C", D_80102800);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80103BE4);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80103CC8);

int func_80103E24(int arg0, func_80103E24_t* arg1)
{
    switch (arg0) {
    case 1:
        return -arg1->unk2B;
    case 4:
        return arg1->unkE0;
    case 5:
        return arg1->unkE2;
    case 6:
        return arg1->unkDC;
    case 7:
        return arg1->unkDE;
    case 8:
        return arg1->unkE4;
    case 9:
        return arg1->unkE8;
    case 10:
        return arg1->unkEC;
    default:
        if (arg0 < 0x21) {
            return arg1->unkF4[arg0 - 0x1B];
        }
        if (arg0 >= 0x28) {
            return *(arg0 + &arg1->unkC9[0]);
        }
        return arg1->unk114[arg0 - 0x21];
    }
}

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80103F00);

int func_8010406C(int arg0, func_8010406C_t* arg1)
{
    if (arg0 == 0) {
        return -arg1->unk0;
    }
    return arg1->unk2;
}

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_8010408C);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_801041CC);

void func_801042C4(void* arg0, int arg1, int arg2)
{
    switch (arg1) {
    case 1:
        func_8006AB44(arg0, D_80060168.unk280[arg2]);
        return;
    case 2:
        func_8006AC74(arg0, D_80060168.unk540[arg2]);
        return;
    case 4:
        func_8006ACFC(arg0, D_80060168.unk640[arg2]);
        return;
    case 5:
        func_8006AE0C(arg0, D_80060168.unk8C0[arg2]);
        return;
    }
}

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_8010439C);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80104530);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80104788);

int func_80104EC0(int arg0, int arg1)
{
    int var_v1;

    var_v1 = 0;
    if (arg0 == 1) {
        var_v1 = D_80060168.unk280[arg1][42];
    }
    if (arg0 == 2) {
        var_v1 = D_80060168.unk540[arg1][6];
    }
    if (arg0 == 5) {
        var_v1 = D_80060168.unk8C0[arg1][12];
        if (var_v1 & 0x80) {
            var_v1 = 0;
        }
    }
    return var_v1;
}

int func_80104F50(int arg0, int arg1)
{
    u_short var_v1;

    var_v1 = 0;
    if (arg0 == 5) {
        var_v1 = D_80060168.unk8C0[arg1][12];
        if (!(var_v1 & 0x80)) {
            var_v1 = 0;
        }
    }
    return var_v1 & 0x7F;
}

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80104F94);

void func_80105314(int arg0)
{
    int i;
    vs_battle_menuItem_t* temp_v0;

    while (D_801023D0 < 16) {
        func_80100A5C();
    }

    for (i = 20; i < 40; ++i) {
        temp_v0 = vs_battle_getMenuItem(i);
        if (temp_v0->state == 2) {
            temp_v0->state = 1;
            temp_v0->animSpeed = temp_v0->x;
        }
        temp_v0->selected = (i ^ (D_800F4EE8.unk0[(arg0 + 0x1E) * 2] + 0x14)) == 0;
    }
}

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_801053EC);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80106390);

int func_80106574(void) { return D_8010975C != 0 ? -1 : D_80109760; }

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_8010659C);

void func_80106BB4(int arg0)
{
    short sp10[48];
    int i;

    vs_mainMenu_resetStats();
    if (arg0 != 0) {
        func_8006B194(&sp10[0], (char*)(D_80102468 + ((arg0 * 10) - 10)));

        for (i = 0; i < 16; ++i) {
            short* temp_v0 = &sp10[i & 7];
            vs_mainMenu_equipmentStats[i] = temp_v0[32];
            vs_mainMenu_equipmentStats[i + 16] = temp_v0[40];
            vs_mainMenu_equipmentStats[i + 32] = temp_v0[28];
        }
        vs_mainMenu_setStrIntAgi(sp10[24], sp10[25], sp10[26], 2);
    }
    vs_mainMenu_equipmentSubtype = 0x20;
    D_801024A1 = arg0;
    func_800FBB8C(7);
}

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80106C94);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80107148);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80107620);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80107B14);

void func_80108010(int arg0)
{
    if (arg0 != 0) {
        if (arg0 == 8) {
            D_801096A3 = 3;
        } else {
            if (arg0 >= 3) {
                arg0 -= 2;
                D_801096A3 = 0;
            } else {
                D_801096A3 = arg0;
            }
        }
    }
    D_8010962C[D_801096A3](arg0);
}

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80108088);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80108518);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80108970);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_801090C4);

// https://decomp.me/scratch/g9L6W
// 2.7.2-cdk
INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80109320);

// https://decomp.me/scratch/3TToS
// 2.7.2-cdk
INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80109344);
