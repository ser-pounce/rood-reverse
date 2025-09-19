#include "common.h"
#include "../MAINMENU.PRG/C48.h"
#include "../MAINMENU.PRG/413C.h"
#include "../../BATTLE/BATTLE.PRG/146C.h"
#include "../../BATTLE/BATTLE.PRG/30D14.h"
#include "../../BATTLE/BATTLE.PRG/573B8.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"

int func_80104514(int);

typedef struct {
    u_short unk0[8];
    int unk10[8];
    short unk30;
    short unk32;
    short unk34;
    short unk36;
} func_80102CAC_t;

typedef struct {
    signed char unk0[8];
    u_short unk8;
    u_short unkA;
    int unkC;
    short unk10;
    char unk12;
    char unk13;
    short unk14;
    short unk16;
    char unk18;
} func_80102D64_t;

extern u_long* D_1F800000[];

static u_short _statusStrings[] = {
#include "../../assets/MENU/MENU4.PRG/status.vsString"
};

extern int D_801080A8;
extern int D_801080B0;
extern char D_801080B8;
extern char D_801080BA;
extern char D_801080BB;

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_80102920);

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_80102A64);

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_80102B70);

void func_80102CAC(func_80102CAC_t* arg0)
{
    int i;
    u_short* temp_v0;

    D_80102545 = 32;
    func_800FD220();

    if (arg0->unk0[0] != 0) {
        for (i = 0; i < 16; ++i) {
            temp_v0 = (arg0->unk0 + (i & 7));
            D_801024C0[i] = temp_v0[32];
            D_801024C0[i + 16] = temp_v0[40];
            D_801024C0[i + 32] = temp_v0[28];
        }
        func_800FBD28(arg0->unk30, arg0->unk32, arg0->unk34, 2);
    }
    func_800FBB8C(7);
}

void func_80102D64(u_short* arg0)
{
    int i;
    func_80102D64_t* temp_s0;

    temp_s0 = (func_80102D64_t*)(arg0 + 12);
    D_80102545 = 2;
    for (i = 0; i < 16; ++i) {
        D_801024C0[i] = (temp_s0->unk0 + (i & 7))[32];
        D_801024C0[i + 16] = (temp_s0->unk0 + (i & 7))[40];
    }
    func_800FC208(temp_s0->unk8, temp_s0->unkA, arg0[0x88], arg0[0x89]);
    func_800FBD28(temp_s0->unk0[5], temp_s0->unk0[6], temp_s0->unk0[7], 1);
    func_800FBD0C(temp_s0->unk18, temp_s0->unk12, 0, 1);
    func_800FBB8C(3);
    func_800FC268(0xB);
}

void func_80102E3C(signed char* arg0)
{
    int i;

    D_80102545 = 4;

    for (i = 0; i < 4; ++i) {
        D_801024C0[i + 0x20] = (arg0 + i)[0x1C];
    }
    func_800FBD28(arg0[5], arg0[6], arg0[7], 1);
    func_800FBB8C(4);
    func_800FC268(8);
}

void func_80102EC0(signed char* arg0)
{
    int i;

    D_80102545 = 64;

    for (i = 0; i < 16; ++i) {
        D_801024C0[i] = (arg0 + (i & 7))[32];
        D_801024C0[i + 16] = (arg0 + (i & 7))[40];
    }
    func_800FBD28(arg0[5], arg0[6], arg0[7], 1);
    func_800FBB8C(3);
    func_800FC268(8);
}

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_80102F64);

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_80103080);

void func_80103118(char*, int*, int*);
INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_80103118);

INCLUDE_RODATA("build/src/MENU/MENU4.PRG/nonmatchings/120", D_80102800);

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_8010317C);

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_801032C4);

int func_801033A4(int* arg0)
{
    int sp10[2];
    int sp18;

    func_800FCECC(arg0, sp10, &sp18, D_800F4E8C);
    return sp10[1];
}

int func_801033D4(u_short* arg0)
{
    int sp10[2];
    int sp18[10];
    int sp30[2];

    func_8006BADC(sp18, arg0);
    func_800FD084(sp18, sp10, sp30, D_800F4E8C);
    return sp10[1];
}

extern char D_801024B9;

int func_8010341C(int arg0, int arg1)
{
    int ret;
    int v0;
    int v1;

    ret = 0;
    switch (arg0) {
    case 0:
        ret = (arg1 >> 5) & 1;
        break;
    case 1:
        ret = (arg1 >> 6) & 1;
        break;
    case 5:
    case 6:
    case 7:
        ret = D_801024B9 != 2;
        break;
    case 8:
        ret = D_801024B9 == 1;
        break;
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
        v1 = arg0 - 9;
        v0 = arg1 & 0xF;
        ret = (v0 < v1) ^ 1;
        break;
    case 16:
    case 17:
        ret = (arg1 >> 4) & 1;
        break;
    case 2:
    case 3:
    case 4:
    case 18:
    case 19:
    case 20:
        ret = 1;
        break;
    }
    return ret;
}

extern char D_8010214C[];

int func_801034BC(int arg0, int arg1)
{
    int var_s1;
    int var_s2;

    var_s1 = 0;
    var_s2 = arg0;
    if (vs_main_buttonRepeat & 0x1000) {
        var_s1 = 1;
    } else if (vs_main_buttonRepeat & 0x4000) {
        var_s1 = 2;
    } else if (vs_main_buttonRepeat & 0x8000) {
        var_s1 = 3;
    } else if (vs_main_buttonRepeat & 0x2000) {
        var_s1 = 4;
    }
    if (var_s1 != 0) {
        arg0 = D_8010214C[var_s1 - 1 + var_s2 * 4];
    }

    while (1) {
        if (func_8010341C(arg0, arg1) != 0) {
            break;
        }
        if (var_s2 == arg0) {
            if ((u_int)(arg0 - 2) < 0xE) {
                do {
                    --arg0;
                } while (func_8010341C(arg0, arg1) == 0);
                return arg0;
            }
            do {
                ++arg0;
            } while (func_8010341C(arg0, arg1) == 0);
            return arg0;
        }
        var_s2 = arg0;
        arg0 = D_8010214C[var_s1 - 1 + var_s2 * 4];
    }
    return arg0;
}

void func_80103608(int arg0)
{
    if (arg0 == 0) {
        D_801080B8 = 1;
        D_801080BA = 4;
    } else if (D_801080BB == 0) {
        func_800CB654(1);
        D_801080B8 = 4;
        D_801080BA = 4;
    } else {
        D_801080B8 = 2;
        D_801080BA = 4;
    }
    D_801080BB = arg0;
}

int func_80103688(int arg0, int arg1)
{
    int temp_a0;

    while (1) {
        arg0 = (arg0 + arg1) % 15;
        temp_a0 = func_800A0BE0(arg0);
        if ((D_800F1928[arg0] != 0) && (D_800F1928[arg0]->unk1C < 5)
            && (temp_a0 & 0x01000001) == 1) {
            break;
        }
    }
    return arg0;
}

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_80103744);

void func_8010399C(int arg0, int arg1, u_int* arg2)
{
    int i;

    if (arg1 != 0) {
        for (i = 0; i < 3; ++i) {
            vs_battle_setSprite(0x80, arg0, 0x90006, arg2)[4] = 0x37F400E4;
            arg0 -= 5;
        }
        func_800C9950(2, arg0, 0, arg2);
        arg0 -= 7;
    }

    arg0 += 0xFFFF0000;

    for (i = 0; i < 3; ++i) {
        vs_battle_setSprite(0x80, arg0, 0xA0007, arg2)[4] = 0x37F400EA;
        arg0 -= 6;
    }
}

void func_80103A6C(int arg0, int arg1, int arg2)
{

    if (arg2 == 0) {
        arg1 = 0;
        arg2 = 1;
    }

    if ((arg0 >> 8) == 0) {
        arg1 = arg2;
    }

    arg1 <<= 6;

    func_800C99DC(arg0 & 0xFF, ((arg1 + arg2) - 1) / arg2, D_1F800000[1] - 3);
}

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_80103AC8);

void func_80103E58(int arg0, int arg1, int arg2)
{
    u_int temp_v0;
    u_long* temp_a0;
    u_long* temp_t1;

    temp_t1 = D_1F800000[2];
    temp_a0 = D_1F800000[0];
    temp_v0 = D_800EBC54[arg0] >> arg2;
    temp_a0[0] = (*temp_t1 & 0xFFFFFF) | 0x06000000;
    temp_a0[1] = temp_v0 | 0x60000000;
    temp_a0[2] = arg1;
    temp_a0[3] = 0x70007;
    temp_a0[4] = (temp_v0 * 2) | 0x60000000;
    temp_a0[5] = arg1 + 0x10001;
    temp_a0[6] = 0x50005;
    *temp_t1 = ((u_long)temp_a0 << 8) >> 8;
    D_1F800000[0] = temp_a0 + 7;
}

void func_80103EF8(int arg0, int arg1, int arg2, int arg3)
{
    int temp_t2;
    int temp_v0;
    u_long* temp_a2;
    u_long* temp_t0;
    int t4;

    arg3 = (0x687018 << arg3) | ((0x21 - arg3) << 0x19);
    temp_t2 = (arg0 * 0x10) + 0x2A;
    arg0 = ((arg1 >> 0x10) - temp_t2);

    temp_a2 = D_1F800000[0];
    temp_t0 = D_1F800000[1];

    t4 = (short)arg1;

    if (arg0 < 0) {
        arg0 = -arg0;
    }
    arg0 = (arg0 * 3) >> 1;

    temp_a2[0] = (temp_t0[-1] & 0xFFFFFF) | 0x08000000;
    temp_a2[1] = 0xE1000000;
    temp_a2[2] = arg3;
    temp_a2[3] = arg1;
    temp_v0 = ((t4 + ((arg0 * 2) / 3)) & 0xFFFF) | (temp_t2 << 0x10);
    temp_a2[4] = temp_v0;
    temp_a2[5] = (temp_t0[-1] & 0xFFFFFF) | 0x03000000;
    temp_a2[6] = arg3;
    temp_a2[7] = temp_v0;
    temp_a2[8] = (temp_t2 << 0x10) | 0xD8;
    temp_t0[-1] = (((u_long)temp_a2 << 8) >> 8);
    temp_a2 += 9;
    D_1F800000[0] = temp_a2;
}

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_80103FEC);

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_80104134);

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_80104514);

int func_8010455C(void)
{
    return func_80104514(D_801080A8 - 1) + 2
        + (D_800F1928[D_801080A8 - 1]->unk3C->unk338 != 0);
}

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_801045B8);

void func_80104AEC(int id)
{
    vs_battle_menuItem_t* menuItem;

    func_800FA8A0(4);
    menuItem = vs_battle_getMenuItem(id + 10);
    menuItem->state = 2;
    menuItem->x = 155;
    menuItem->selected = 1;
    menuItem->unk3A = 0;
}

void func_80104B38(int arg0)
{
    char var_a1;
    vs_battle_menuItem_t* menuItem;

    menuItem = vs_battle_setMenuItem(0x20, -0xA4, 0x12, 0xA4, 8,
        (char*)&_statusStrings[_statusStrings[arg0 < 2 ? arg0 + 9 : 11]]);

    menuItem->state = 5;
    menuItem->x = 0x10;
    menuItem->selected = 1;

    var_a1 = 0x1C;

    if (arg0 == 0) {
        var_a1 = 0x18;
    } else if (arg0 == 1) {
        var_a1 = 0x1B;
    }
    menuItem->weaponType = var_a1;
    menuItem = vs_battle_getMenuItem(arg0 + 10);
    menuItem->state = 3;
    menuItem->x = 0x12;
}

void func_80104C0C(int arg0, int arg1)
{
    func_80104B38(arg0);
    func_800FBBD4(arg1);
    func_800FBEA4(1);
}

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_80104C40);

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_80104DFC);

void func_80104F2C(int arg0)
{
    vs_battle_playMenuLeaveSfx();
    func_800FA8E0(0x28);
    func_800FA810(0);
    func_800FBBD4(-1);
    func_800FBEA4(2);
    if (arg0 != 0) {
        func_800FC268(4);
    }
}

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_80104F80);

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_80105970);

void func_80105E94(void)
{
    int var_a2;
    u_long* temp_a1;
    u_long* temp_t1;

    temp_a1 = D_1F800000[0];
    temp_t1 = D_1F800000[1];
    if (D_801080B0 != 0) {
        temp_a1[0] = ((temp_t1[-1] & 0xFFFFFF) | 0x0D000000);
        temp_a1[1] = 0xE1000000;
        temp_a1[2] = 0x3C000000;
        temp_a1[3] = 0;
        temp_a1[4] = 0;
        temp_a1[5] = 0x808080;
        temp_a1[6] = 0x60;

        var_a2 = 0x01000060;
        if (vs_main_frameBuf == 0) {
            var_a2 = 0x01050000 | 0x60;
        }
        temp_a1[7] = var_a2;
        temp_a1[8] = 0;
        temp_a1[9] = 0xF00000;
        temp_a1[10] = 0xF000;
        temp_a1[11] = 0x808080;
        temp_a1[12] = 0xF00060;
        temp_a1[13] = 0xF060;
        temp_t1[-1] = (((u_long)temp_a1 << 8) >> 8);
        D_1F800000[0] = temp_a1 + 14;
    }
}

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_80105F60);

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_80106150);

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_80106308);

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_801063F8);

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_801064D4);
