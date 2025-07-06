#include "common.h"
#include "../MAINMENU.PRG/278.h"

typedef struct {
    char unk0[0x2318];
    u_short unk2318[1][0xE];
} func_80103D14_t;

typedef struct {
    u_short unk0;
    char unk2;
} func_801055D0_t;

typedef struct {
    containerData_t unk0;
    short unk3C00[1];
} func_80102C94_t;

extern u_short D_80109944[];
extern signed char D_80109A7B;
extern signed char D_80109A7C;
extern signed char D_80109A7D;
extern short D_80109A82;

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80102A34);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80102BB0);

static short* func_80102C94(int arg0, func_80102C94_t* arg1)
{
    int i;
    int var_a3;

    i = 0;
    var_a3 = 0;
    if (arg0 > 0) {
        do {
            var_a3 += D_80109944[i++];
        } while (i < arg0);
    }
    return arg1->unk3C00 + var_a3;
}

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80102CD0);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80102D28);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80102D80);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80102F88);

short func_80103070(int, void*);
INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80103070);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80103110);

void func_801031A0();
INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_801031A0);

static void func_80103270()
{
    short* s0 = &D_80109A82;
    func_801031A0();
    D_80109A82 = func_80103070(6, &D_8010245C->unk4BB0);
}

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_801032AC);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_801037D8);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_801039AC);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80103B20);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80103C9C);

static int func_80103D14(int arg0, int arg1, func_80103D14_t* arg2)
{
    u_short var_v1;

    var_v1 = 0;
    if (arg0 == 5) {
        var_v1 = arg2->unk2318[arg1][0];
        if (!(var_v1 & 0x80)) {
            var_v1 = 0;
        }
    }
    return var_v1 & 0x7F;
}

static void func_80103D50(signed char arg0)
{
    D_80109A7B = arg0;
    D_80109A7C = arg0;
    D_80109A7D = arg0;
}

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80103D6C);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80103E24);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80103F64);

void func_80103FD4();
INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80103FD4);

static void func_80104034(int arg0 __attribute__((unused)), int arg1)
{
    D_80109A7C = 0;
    D_80109A7D = 0;
    func_80103FD4();
    func_800FBBD4(arg1);
    func_800FBEA4(1);
}

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80104078);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80104114);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80104170);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_801041E0);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_8010425C);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_801042D0);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80104534);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80104728);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_8010496C);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80104BDC);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80104E14);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80105008);

INCLUDE_RODATA("build/src/MENU/MENUD.PRG/nonmatchings/234", D_8010285C);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80105114);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_801051F8);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80105378);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80105454);

static int func_801055D0(int arg0, func_801055D0_t* arg1)
{
    if (arg0 == 0) {
        return -arg1->unk0;
    }
    return arg1->unk2;
}

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_801055F0);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_8010574C);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80105844);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_8010592C);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80105ACC);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80105D24);

INCLUDE_RODATA("build/src/MENU/MENUD.PRG/nonmatchings/234", D_80102910);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80106464);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80106504);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80106624);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80106684);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_801066DC);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80106784);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_801068BC);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80106948);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_801069B0);

static void func_80106A04(int arg0, int arg1)
{
    int i;
    u_short* var_v1;

    i = 0;
    var_v1 = (u_short*)D_8010245C + 0x61D8;
    for (i = 0; i < 64; ++i) {
        if (var_v1[i] == 0) {
            var_v1[i] = ((arg0 << 8) | (arg1 + 1));
            return;
        }
    }
}

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80106A50);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80106C64);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_801071D8);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_801072B0);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80107490);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_801089BC);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80108C6C);
