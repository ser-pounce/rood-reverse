#include "common.h"
#include "../MAINMENU.PRG/C48.h"
#include "../MAINMENU.PRG/278.h"
#include "../MAINMENU.PRG/413C.h"
#include "../../BATTLE/BATTLE.PRG/146C.h"
#include "../../BATTLE/BATTLE.PRG/30D14.h"
#include "../../BATTLE/BATTLE.PRG/573B8.h"
#include "../../BATTLE/BATTLE.PRG/58578.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"

int func_80103744(int);
void func_80103AC8();
int func_80104134(D_800F1964_t*, int);
int func_80104514(int);
int func_801045B8(int);
int func_80105970(int);
void func_80106150(void);
void func_80106308();
void func_801063F8();

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

typedef struct {
    int unk0[8];
} D_80108198_t;
extern D_80108198_t D_80108198;

typedef struct {
    int unk0[13];
} D_801081B8_t;

extern int D_8010809C;
extern int D_801080A0;
extern int D_801080A4;
extern int D_801080A8;
extern int D_801080AC;
extern int D_801080B0;
extern int D_801080B4;
extern char D_801080B8;
extern char D_801080B9;
extern char D_801080BA;
extern char D_801080BB;
extern int D_801080C8[];
extern int D_801080FC[];
extern int D_8010812C;
extern int D_80108130;
extern int D_80108134;
extern int D_80108188;
extern D_801081B8_t D_801081B8;
extern u_char D_801081EC;
extern u_char D_801081ED;
extern char D_801081EE;

extern u_long* D_1F800000[];

static u_short _statusStrings[] = {
#include "../../assets/MENU/MENU4.PRG/status.vsString"
};

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

int func_801064D4(char* arg0)
{
    int temp_v0_2;
    int var_s2;
    int var_s5;
    int var_s6;
    D_801081B8_t* var_a0;
    int temp_s0;
    int temp_s0_2;
    int temp_s1;
    int new_var2;

    var_s5 = 0;
    var_s6 = 0;

    switch (*arg0) {
    case 3:
        D_80108130 = 0;
        D_801081EC = 0xA;
        if (D_8010229C == 0) {
            func_800FE5CC(1);
        }
        if (vs_mainmenu_ready() != 0) {
            D_800EB9AE = 1;
            func_8008A4DC(0);
            func_80100414(0x7FE, 0x80);
            D_801080AC = 0;
            D_801080B0 = 0;
            D_801080A8 = 0;
            D_801080A4 = 0;
            D_801080B8 = 0;
            D_801080B9 = 0;
            D_801080BB = 0;
            func_80103744(1);
            D_80108130 = 1;
            D_8010812C = 1;
            D_80108188 = D_8005E248;
            func_8007CCF0(0x200);
            new_var2 = 13;
            var_a0 = (D_801081B8_t*)(&D_1F800000[new_var2]);
            D_80108198 = *(D_80108198_t*)&D_1F800000[5];
            D_801081B8 = *var_a0;
            D_1F800000[25] = (u_long*)0x1000;
            D_1F800000[21] = 0;
            D_1F800000[22] = 0;
            D_1F800000[23] = 0;
            D_8010809C = 0xB00;
            D_801080A0 = 0;
            func_800FFBC8();
            D_801081ED = 0;
            D_80102544 = 0;
            func_80106308();
            *arg0 = 5;
        }
        break;
    case 4:
        if (D_8010812C != 0) {
            D_8010812C -= 1;
            func_801045B8(-1);
            func_800FBEA4(1);
        } else {
            func_80106308();
            *arg0 = 5;
        }
        break;
    case 5:
        var_s5 = 0;
        if ((D_801080A8 == 1) || (D_800F1928[D_801080A8 - 1]->unk3C->unk954 & 0x20000)) {
            var_s5 = 1;
        }
        if (D_8010812C != 0) {
            if (func_80103744(0) != 0) {
                D_8010812C = 0;
                func_801045B8(-1);
                func_800FBEA4(1);
                temp_s1 = D_801081ED;
                if (temp_s1 < 6) {
                    var_s2 = func_80104514(D_801080A8 - 1) - 1;
                    if (var_s2 < temp_s1) {
                        D_801081ED = var_s2;
                    }
                    func_80106308();
                } else {
                    vs_mainmenu_setMessage(
                        (char*)&_statusStrings[_statusStrings[temp_s1 - 6]]);
                }
            }
        } else if (func_800FE5CC(0) != 0) {
            if (func_801045B8(-3) == 2) {
                if (vs_main_buttonsPressed.all & 0x10) {
                    vs_battle_playMenuLeaveSfx();
                    *arg0 = 0xD;
                    break;
                } else if (vs_main_buttonsPressed.all & 0x40) {
                    vs_battle_playMenuLeaveSfx();
                    *arg0 = 0xB;
                    break;
                } else if ((vs_main_buttonsPressed.all & 0x20)
                    && (temp_s0 = D_801081ED,
                        (((int)temp_s0 < func_80104514(D_801080A8 - 1)) != 0))) {
                    vs_battle_playMenuSelectSfx();
                    func_800FBEA4(2);
                    func_801045B8(-2);
                    D_8010812C = 8;
                    *arg0 = 7;
                    break;
                }
                var_s6 = 0;
                if (var_s5 != 0) {
                    temp_s0_2 = D_801081ED;
                    var_s6 = (int)temp_s0_2 < func_80104514(D_801080A8 - 1);
                }
                if (vs_main_buttonsPressed.all & 0x80) {
                    if (var_s6 != 0) {
                        vs_battle_playMenuSelectSfx();
                        func_801063F8();
                        func_800FBBD4(6);
                        D_801081EE = 0;
                        D_8010812C = 0xA;
                        *arg0 = 9;
                        break;
                    }
                    func_800C02E0();
                }
                if (vs_main_buttonsState & 1) {
                    temp_s1 = func_800C4708(vs_main_stickPosBuf.rStickX);
                    var_s2 = func_800C4708(vs_main_stickPosBuf.rStickY);
                    if (temp_s1 == 0) {
                        if (var_s2 == 0) {
                            if (vs_main_buttonsState & 0x1000) {
                                var_s2 = -0x40;
                            }
                            if (vs_main_buttonsState & 0x4000) {
                                var_s2 = 0x40;
                            }
                            if (vs_main_buttonsState & 0x8000) {
                                temp_s1 = -0x40;
                            }
                            if (vs_main_buttonsState & 0x2000) {
                                temp_s1 = 0x40;
                            }
                        }
                    }

                    D_8010809C += temp_s1;
                    D_801080A0 = D_801080A0 - var_s2;
                    if (D_801080A0 < 0) {
                        D_801080A0 = 0;
                    }
                    if (D_801080A0 >= 0x381) {
                        D_801080A0 = 0x380;
                    }
                } else {
                    temp_s1 = D_801081ED;
                    var_s2 = D_801080FC[temp_s1];
                    if (vs_main_buttonRepeat & 0x1000) {
                        temp_s1 = var_s2;
                    } else if (vs_main_buttonRepeat & 0x4000) {
                        temp_s1 = var_s2 >> 8;
                    } else if (vs_main_buttonRepeat & 0x8000) {
                        temp_s1 = var_s2 >> 0x10;
                    } else {
                        temp_s1 = D_801081ED;
                        if (vs_main_buttonRepeat & 0x2000) {
                            temp_s1 = var_s2 >> 0x18;
                        }
                    }
                    temp_s1 &= 0xFF;
                    func_801045B8(7);
                    if (temp_s1 == 0xD) {
                        if (func_80104134(D_800F1928[D_801080A8 - 1]->unk3C, 1) == 0) {
                            vs_battle_playMenuChangeSfx();
                            *arg0 = 6;
                            break;
                        }
                        temp_s1 = D_801081ED;
                    }
                    if (temp_s1 < 6) {
                        var_s2 = func_80104514(D_801080A8 - 1);
                        if (temp_s1 < var_s2) {
                            func_801045B8(temp_s1 + 1);
                        } else {
                            temp_s1 = 6;
                            if (!(vs_main_buttonRepeat & 0x4000)) {
                                temp_s1 = var_s2 - 1;
                                if (!(vs_main_buttonRepeat & 0x1000)) {
                                    D_801081ED = temp_s1;
                                }
                            }
                        }
                    }
                    D_801022D5 = (temp_s1 < func_80104514(D_801080A8 - 1)) ^ 1;
                    D_80108134 = func_800FFCDC(D_80108134, *((temp_s1) + D_801080C8));
                    if (temp_s1 != D_801081ED) {
                        vs_battle_playMenuChangeSfx();
                        if (temp_s1 != 0xD) {
                            D_801081ED = temp_s1;
                        }
                    }
                    if (temp_s1 < 6) {
                        func_80106308();
                    } else {
                        vs_mainmenu_setMessage(
                            (char*)&_statusStrings[_statusStrings[temp_s1 - 6]]);
                    }
                }
            }
            temp_s1 = D_801080A8 - 1;
            if (vs_main_buttonsPressed.all & 8) {
                temp_s1 = func_80103688(temp_s1, 1);
                var_s2 = 0x11;
            }
            if (vs_main_buttonsPressed.all & 4) {
                temp_s1 = func_80103688(temp_s1, 0xE);
                var_s2 = 1;
            }
            if (temp_s1 != (D_801080A8 - 1)) {
                D_801080A4 = D_801080A8;
                func_801045B8(-2);
                func_800FBEA4(2);
                func_80103608(temp_s1);
                func_80103744(temp_s1 + var_s2);
                D_8010812C = 1;
            }
        }
        D_801022D5 = (D_801081ED < func_80104514(D_801080A8 - 1)) ^ 1;
        break;
    case 6:
        var_s5 = 0;
        if ((D_801080A8 == 1) || (D_800F1928[D_801080A8 - 1]->unk3C->unk954 & 0x20000)) {
            var_s5 = 1;
        }
        if (D_8010812C != 0) {
            if (func_80103744(0) != 0) {
                func_80104134(D_800F1928[D_801080A8 - 1]->unk3C, 0);
                D_8010812C = 0;
                func_801045B8(-1);
                func_800FBEA4(1);
            }
        } else {
            temp_v0_2 = func_801045B8(-3);
            if (temp_v0_2 == 2) {
                temp_s1 = func_80104134(0, 1);
                if (temp_s1 != 0) {
                    switch (temp_s1) {
                    case 1:
                        *arg0 = 5;
                        break;
                    case 2:
                        vs_battle_playMenuLeaveSfx();
                        *arg0 = 0xD;
                        break;
                    case 3:
                        vs_battle_playMenuLeaveSfx();
                        *arg0 = 0xB;
                        break;
                    }
                }
            }
            temp_s1 = D_801080A8 - 1;
            if (vs_main_buttonsPressed.all & 8) {
                temp_s1 = func_80103688(temp_s1, 1);
                var_s2 = 0x11;
            }
            if (vs_main_buttonsPressed.all & 4) {
                temp_s1 = func_80103688(temp_s1, 0xE);
                var_s2 = 1;
            }
            if (temp_s1 != (D_801080A8 - 1)) {
                D_801080A4 = D_801080A8;
                func_801045B8(-2);
                func_800FBEA4(2);
                func_80103608(temp_s1);
                func_80103744(temp_s1 + var_s2);
                D_8010812C = 1;
                if (func_800C9E08(D_800F1928[temp_s1]->unk3C) == 0) {
                    *arg0 = 5;
                }
            }
        }
        break;
    case 7:
        if (D_8010812C == 0) {
            func_80105970(D_801081ED + 1);
            *arg0 = 8;
        } else {
            --D_8010812C;
        }
        break;
    case 8:
        temp_s1 = func_80105970(0);
        if (temp_s1 != 0) {
            if (temp_s1 != -2) {
                D_8010812C = 8;
                *arg0 = 4;
            } else {
                *arg0 = 0xD;
            }
        }
        break;
    case 9:
        if (D_8010812C != 0) {
            D_801080B4 = 0x80 - vs_battle_rowAnimationSteps[--D_8010812C];
        } else if (vs_main_buttonsPressed.all & 0x50) {
            vs_battle_playMenuLeaveSfx();
            func_800FBBD4(-1);
            if (vs_main_buttonsPressed.all & 0x10) {
                *arg0 = 0xD;
                break;
            }
            D_8010812C = 0xA;
            *arg0 = 0xA;
        } else {
            if ((vs_main_buttonsState & 0xC) != 0xC) {
                temp_s1 = D_801081ED;
                var_s2 = func_80104514(D_801080A8 - 1);
                if (vs_main_buttonRepeat & 4) {
                    char new_var = 1;
                    temp_s1 = (temp_s1 - new_var) + var_s2;
                }
                if (vs_main_buttonRepeat & 8) {
                    ++temp_s1;
                }
                if (temp_s1 >= var_s2) {
                    temp_s1 -= var_s2;
                }
                if (temp_s1 != D_801081ED) {
                    vs_battle_playMenuChangeSfx();
                    D_801081ED = temp_s1;
                    func_801063F8();
                }
            }
            temp_s1 = D_801081EE;
            var_s2 = 0xB - ((char)D_801024B9 * 4);
            if (temp_s1 >= var_s2) {
                temp_s1 = var_s2 - 1;
            }
            if (vs_main_buttonRepeat & 0x1000) {
                char new_var = 1;
                temp_s1 = (temp_s1 - new_var) + var_s2;
            }
            if (vs_main_buttonRepeat & 0x4000) {
                ++temp_s1;
            }
            if (temp_s1 >= var_s2) {
                temp_s1 -= var_s2;
            }
            if (temp_s1 != D_801081EE) {
                vs_battle_playMenuChangeSfx();
                D_801081EE = temp_s1;
            }

            vs_mainmenu_setMessage((char*)&_statusStrings[_statusStrings[temp_s1
                + (var_s2 != 3 ? 0x32 : 0x39)]]);
            D_80108134 = func_800FFCDC(D_80108134, ((temp_s1 * 0x10) + 0x32) << 0x10);
        }
        break;
    case 10:
        var_s5 = 1;
        if (D_8010812C != 0) {
            D_801080B4 = (int)vs_battle_rowAnimationSteps[--D_8010812C];
        } else {
            func_801045B8(D_801081ED + 1);
            *arg0 = 5;
        }
        break;
    case 11:
    case 13:
        func_800FBEA4(2);
        func_801045B8(-2);
        func_801045B8(0);
        func_80103608(0);
        func_80103AC8();
        func_8007CCF0(D_80108188);
        new_var2 = 13;
        var_a0 = (D_801081B8_t*)&D_1F800000[new_var2];
        *(D_80108198_t*)&D_1F800000[5] = D_80108198;
        *var_a0 = D_801081B8;
        func_8008A4DC(1);
        func_800FFA88(0);
        func_800FA8E0(0x28);
        func_800F9E0C();
        func_80100414(-2, 0x80);
        D_800EB9AE = 0;
        D_8010812C = 8;
        D_80108130 = 0;
        ++*arg0;
        break;
    case 12:
        func_801045B8(0);
        func_80103AC8();
        func_800FFB68(0);
        func_800FFBA8();
        if (D_8010812C <= 0) {
            if (func_800FE694() != 0) {
                *arg0 = 0;
                return 1;
            }
        }
        --D_8010812C;
        break;
    case 14:
        func_801045B8(0);
        func_80103AC8();
        func_800FFB68(0);
        func_800FFBA8();
        if (D_8010812C <= 0) {
            if (func_800FE694() != 0) {
                vs_battle_menuState.currentState = 5;
                *arg0 = 0;
                return 1;
            }
        }
        --D_8010812C;
        break;
    }

    if (D_80108130 != 0) {
        func_80106150();
    }
    if (var_s5 != 0) {
        if (D_801081EC != 0) {
            D_801081EC -= 1;
        }
    } else {
        D_801081EC = D_800EBC7C[D_801081EC];
    }
    if (D_801081EC < 0xA) {
        temp_s1 = vs_battle_rowAnimationSteps[D_801081EC];
        func_80100344(0x10 - temp_s1, 0x26, 0x58, 0xA);
        func_800FFC68(1, 8 - temp_s1, 0x24, 0);
        func_800C6540(
            "STATUS", ((0x1C - temp_s1) & 0xFFFF) | 0x260000, 0x404040 << var_s6, 0);
    }
    return 0;
}
