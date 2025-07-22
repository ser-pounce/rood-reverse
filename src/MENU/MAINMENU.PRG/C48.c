#include "common.h"
#include "C48.h"
#include "413C.h"
#include "../SLUS_010.40/main.h"
#include "../MENUC.PRG/168.h"
#include "../MENUD.PRG/234.h"
#include "../BATTLE/BATTLE.PRG/146C.h"
#include "../BATTLE/BATTLE.PRG/2842C.h"
#include "../BATTLE/BATTLE.PRG/30D14.h"
#include "../BATTLE/BATTLE.PRG/44F14.h"
#include "../BATTLE/BATTLE.PRG/573B8.h"
#include "../BATTLE/BATTLE.PRG/5BF94.h"
#include <libetc.h>

typedef struct {
    int unk0;
    signed char unk4;
    signed char unk5;
    signed char unk6;
    signed char unk7;
    signed char unk8[8];
} D_80102460_t;

int func_800FA238(int arg0, int arg1, int arg2);
void func_800FA3FC(int arg0);
int func_800FA9D0();
void func_800FB3C8(int);
void func_800FBD28(int, int, int, int);
void func_800FC208(int, int, int, int);
void func_800FC85C(int*, int*, int, int);
void func_800FCAA4(int, u_short**, int*, void*);
void func_800FCC0C(int, u_short**, int*, void*);
void func_800FCCE8(void*, int, int, int);
void func_800FCECC(int*, int, int, int);

extern short D_80102014[];
extern short D_8010202C[];
extern int D_80102034;
extern int D_801020F4;
extern u_char D_801020F8;
extern short D_80102134;
extern short D_80102136;
extern short D_80102138;
extern short D_8010213A;
extern D_8010229C_t* D_8010229C;
extern D_80102460_t* D_80102460;
extern char* D_8010246C;
extern char (*D_80102470)[256];
extern char D_80102480[];
extern char D_801024A1;
extern short D_801024A8[];
extern char D_801024B9;
extern short D_801024C0[];
extern u_short* D_80102540;
extern char D_80102544;
extern char D_80102545;

void func_800FA448()
{
    D_800F19FC_t2* temp_s1;
    int i;

    temp_s1 = D_800F19FC->unk38;

    if (temp_s1->unk149 != 0) {
        func_8006B8C0(D_80060148[temp_s1->unk149], temp_s1->unk3C);
    }

    if (temp_s1->unk2AE != 0) {
        func_8006B9E0(D_80060238[temp_s1->unk2AE], temp_s1->unk1D4);
    }

    for (i = 0; i < 6; ++i) {
        if (temp_s1->unk398[i].unkBA != 0) {
            func_8006BAA8(D_80060780[temp_s1->unk398[i].unkBA], temp_s1->unk398[i].unk20);
        }
    }

    if (temp_s1->unk36F != 0) {
        func_8006BADC(D_80060780[temp_s1->unk36F], &temp_s1->unk338);
    }
}

void func_800FA568() { }

void func_800FA570()
{
    func_8009967C();
    func_800995B0();
}

int func_800FA598(short* arg0, unsigned int arg1)
{
    int var_a2;
    int var_a3;
    int i;
    int var_t0;
    int var_t1;
    int var_t2;
    int var_v1;

    var_t2 = 0;
    var_t1 = 0;
    var_a3 = 0;
    var_a2 = 0;

    switch (arg1) {
    case 0:
        for (i = 0; i < 6; ++i) {
            if (var_a3 < arg0[156 + i]) {
                var_a2 = var_a3;
                var_a3 = arg0[156 + i];
                var_t1 = i;
            } else if (var_a2 < arg0[156 + i]) {
                var_a2 = arg0[156 + i];
            }
        }
        for (i = 0; i < 7; ++i) {
            if (var_a3 < arg0[172 + i]) {
                var_a2 = var_a3;
                var_a3 = arg0[172 + i];
                var_t1 = i;
                var_t2 = 1;
            } else if (var_a2 < arg0[172 + i]) {
                var_a2 = arg0[172 + i];
            }
        }
        break;

    case 1:
        for (i = 0; i < 6; ++i) {
            if (var_a3 < arg0[130 + i]) {
                var_a2 = var_a3;
                var_a3 = arg0[130 + i];
                var_t1 = i;
            } else if (var_a2 < arg0[130 + i]) {
                var_a2 = arg0[130 + i];
            }
        }

        for (i = 0; i < 7; ++i) {
            if (var_a3 < arg0[146 + i]) {
                var_a2 = var_a3;
                var_a3 = arg0[146 + i];
                var_t1 = i;
                var_t2 = 1;
            } else if (var_a2 < arg0[146 + i]) {
                var_a2 = arg0[146 + i];
            }
        }
        break;

    case 100: // arbitrary
    default:
        for (i = 0; i < 6; ++i) {
            if (var_a3 < arg0[44 + i]) {
                var_a2 = var_a3;
                var_a3 = arg0[44 + i];
                var_t1 = i;
            } else if (var_a2 < arg0[44 + i]) {
                var_a2 = arg0[44 + i];
            }
        }

        for (i = 0; i < 7; ++i) {
            if (var_a3 < arg0[60 + i]) {
                var_a2 = var_a3;
                var_a3 = arg0[60 + i];
                var_t1 = i;
                var_t2 = 1;
            } else if (var_a2 < arg0[60 + i]) {
                var_a2 = arg0[60 + i];
            }
        }
        break;
    }

    var_t0 = 0;
    for (i = 0; i < 11; ++i) {
        if (var_a2 < D_80102014[i]) {
            var_t0 = i;
            break;
        }
    }
    var_v1 = 0;
    for (i = 0; i < 3; ++i) {
        if (var_a3 < D_8010202C[i]) {
            var_v1 = i;
            break;
        }
    }

    {
        int a = (var_t2 * 6) + var_t1;
        int b = var_t0 + (var_v1 * 256);
        return b + (a << 0x10);
    }
}

void func_800FA810(int arg0)
{
    func_800C8E5C_t* temp_v0 = func_800C8E48(arg0 + 0x20);
    if (temp_v0->unk0 != 0) {
        temp_v0->unk0 = 5;
        temp_v0->unk18 = -temp_v0->unk1;
    }
}

void func_800FA854(int arg0)
{
    int i;

    for (i = 0; i < 8; ++i) {
        if (i != arg0) {
            func_800FA810(i);
        }
    }
}

void func_800FA8A0(int arg0)
{
    func_800C8E5C_t* temp_v0;

    temp_v0 = func_800C8E48(arg0);
    if (temp_v0->unk0 != 0) {
        temp_v0->unk0 = 2;
        temp_v0->unk18 = 0x140;
    }
}

void func_800FA8E0(int arg0)
{
    int i;

    for (i = 0; i < 32; ++i) {
        if (i != arg0) {
            func_800FA8A0(i);
        }
    }
}

void func_800FA92C(int arg0, int arg1)
{
    func_800C8E5C_t* temp_v0;
    int var_s0;

    for (var_s0 = arg1 * 10; var_s0 < 30; ++var_s0) {
        func_800FA8A0(var_s0);
    }

    temp_v0 = func_800C8E48(arg0 + (arg1 * 10));
    temp_v0->unk0 = 4;
    temp_v0->unk18 = 0xB4;
    temp_v0->unk1A = (arg1 * 16) + 18;
    if (temp_v0->unk2 == 0) {
        temp_v0->unk2 = 1;
    }
}

int func_800FA9D0()
{
    func_800C8E5C_t* var_a0;
    int i;

    var_a0 = func_800C8E48(0);

    for (i = 0; i < 0x28; ++i) {
        if (var_a0->unk0 > 1) {
            return 0;
        }
        ++var_a0;
    }
    return 1;
}

int func_800FAA20()
{
    int temp_s0 = ++D_80102034;
    func_800FA8E0(0x28);
    return temp_s0 == 5;
}

int func_800FAA5C(int arg0)
{
    if (arg0 & 0x40) {
        D_800F51C0.unk0 = 0;
        func_800C930C(1);
        return 0;
    }
    if (D_800F4FDB == 0) {
        func_8007E0A8(0x1A, 3, 6);
    }
    D_800F51C0.unk0 = 0x7F;
    return 1;
}

// https://decomp.me/scratch/b42Kb
INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/C48", func_800FAAC8);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/C48", func_800FAEBC);

INCLUDE_RODATA("build/src/MENU/MAINMENU.PRG/nonmatchings/C48", D_800F9814);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/C48", func_800FB3C8);

int func_800FBB64(int arg0)
{
    do {
        arg0 = (arg0 + 1) & 3;
    } while (!((D_80102544 >> arg0) & 1));
    return arg0;
}

void func_800FBB8C(int arg0)
{
    D_80102544 = arg0;
    if (!((arg0 >> D_801024B9) & 1)) {
        D_801024B9 = func_800FBB64(D_801024B9);
    }
}

void func_800FBBD4(int arg0)
{
    int var_s1;
    int var_s0;

    var_s1 = 1;
    if (arg0 != 0) {
        if (arg0 > 0) {
            D_801024B9 = 3;
            func_800FBB8C(arg0);
        }
        D_801020F4 = arg0;
        D_801020F8 = 10;
        return;
    }
    var_s0 = D_801024B9;
    if (D_801020F4 > 0) {
        var_s1 = -D_800EBBC8[D_801020F8];
        if (D_801020F8 != 0) {
            --D_801020F8;
        } else if (vs_main_buttonsPressed & PADRleft) {
            var_s0 = func_800FBB64(var_s0);
            if (var_s0 != D_801024B9) {
                vs_main_playSfxDefault(0x7E, 14);
            } else {
                func_800C02E0();
            }
        }
    } else {
        if (D_801020F8 != 0) {
            --D_801020F8;
            var_s1 = (D_801020F8 - 10) * 24;
        }
    }
    if (var_s1 <= 0) {
        func_800FB3C8(var_s1);
    }
    D_801024B9 = var_s0;
}

void func_800FBD0C(int arg0, int arg1, int arg2, int arg3)
{
    D_80102480[0] = arg0;
    D_80102480[1] = arg1;
    D_80102480[2] = arg2;
    D_80102480[3] = arg3;
}

void func_800FBD28(int arg0, int arg1, int arg2, int arg3)
{
    D_801024A8[0] = arg0;
    D_801024A8[1] = arg1;
    D_801024A8[2] = arg2;
    D_801024A8[3] = arg3;
    func_800FBD0C(0, 0, 0, 0);
    vs_battle_memcpy(D_801024A8 + 4, D_801024A8, 8);
}

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/C48", func_800FBD80);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/C48", func_800FBEA4);

void func_800FC208(int arg0, int arg1, int arg2, int arg3)
{
    D_80102138 = arg2;
    D_8010213A = arg3;
    D_80102134 = (arg0 + 0x63) / 100;
    D_80102136 = (arg1 + 0x63) / 100;
}

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/C48", func_800FC268);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/C48", func_800FC510);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/C48", func_800FC704);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/C48", func_800FC85C);

void func_800FCA08(int arg0, int* arg1, int arg2, int arg3) {
    int sp10[102];

    if (D_80102470 == D_80060168) {
        func_8006AEAC(sp10, arg0);
    } else {
        func_80102A34(sp10, arg0, D_80109A8C);
    }
    func_800FC85C(sp10, arg1, arg2, arg3);
    *arg1 = arg0 + 8;
}

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/C48", func_800FCAA4);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/C48", func_800FCC0C);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/C48", func_800FCCE8);

void func_800FCE40(int arg0, int arg1, int arg2, int arg3)
{
    int sp10[90];

    if (D_8010246C == D_80060168[1]) {
        func_8006B02C(sp10, arg0);
    } else {
        func_80102BB0(sp10, arg0, D_80109A8C);
    }
    func_800FCCE8(sp10, arg1, arg2, arg3);
}

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/C48", func_800FCECC);

void func_800FD084(int arg0, int arg1, int arg2, int arg3)
{
    int sp10[48];

    func_8006B110(sp10, arg0);
    func_800FCECC(sp10, arg1, arg2, arg3);
}

void func_800FD0E0(u_short* arg0, func_800FD0E0_t* arg1, int* arg2, void* arg3)
{
    vs_battle_memcpy(arg3, D_80102540 + ((*arg0 + D_80102540)[-0x8C]), 0x60);
    arg1->unk0 = (D_8010229C + *arg0);
    arg1->unk4 = arg3;
    *arg2 = 0x58000000;
}

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/C48", func_800FD17C);

void func_800FD220()
{
    vs_battle_rMemzero(D_801024C0, 0x80);
    func_800FC208(0, 0, 0, 0);
    func_800FBD28(0, 0, 0, 1);
}

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/C48", func_800FD270);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/C48", func_800FD404);

void func_800FD504(int arg0)
{
    int i;
    D_80102460_t* temp_a2;

    temp_a2 = &D_80102460[arg0 - 1];
    for (i = 0; i < 4; ++i) {
        D_801024C0[i + 0x20] = temp_a2->unk8[i];
    }
    func_800FBD28(temp_a2->unk5, temp_a2->unk6, temp_a2->unk7, 1);
    D_80102545 = 4;
    D_801024A1 = arg0;
    func_800FBB8C(4);
}

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/C48", func_800FD5A0);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/C48", func_800FD700);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/C48", func_800FD878);
