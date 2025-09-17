#include "common.h"
#include "../MAINMENU.PRG/C48.h"
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
    short* temp_a0;
    short* var_a2;
    int i;
    int var_a3;
    char temp_v0;
    func_80102D64_t* temp_s0;
    char* temp_v1;

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

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_8010341C);

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_801034BC);

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

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_8010399C);

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

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_80103EF8);

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

void func_80104B38(int arg0);
INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_80104B38);

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

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_80105E94);

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_80105F60);

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_80106150);

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_80106308);

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_801063F8);

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_801064D4);
