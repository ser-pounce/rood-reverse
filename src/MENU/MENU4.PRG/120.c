#include "common.h"
#include "../MAINMENU.PRG/C48.h"
#include "../MAINMENU.PRG/278.h"
#include "../MAINMENU.PRG/413C.h"
#include "../../BATTLE/BATTLE.PRG/146C.h"
#include "../../BATTLE/BATTLE.PRG/30D14.h"
#include "../../BATTLE/BATTLE.PRG/573B8.h"
#include "../../BATTLE/BATTLE.PRG/58578.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"
#include "../../assets/MENU/MENU4.PRG/status.h"
#include "../../SLUS_010.40/31724.h"
#include <libetc.h>

int func_80103744(int);
void func_80103AC8();
int func_80104134(vs_battle_equipment_t2*, int);
int func_80104514(int);
int func_801045B8(int);
int func_80105970(int);
void func_80105F60();
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

typedef struct {
    u_short unk0;
    u_short unk2;
    char unk4;
} func_80103080_t;

extern u_short* D_800F51A4;

extern char D_801024B9;

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
extern char D_801080BC;
extern int D_801080C8[];
extern int D_801080FC[];
extern int animWait;
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

void func_80102920(u_short* arg0)
{
    int i;

    D_80102545 = 1;
    func_800FD220();
    func_800FBD0C(0, 0, 0, 1);
    if (arg0[0xC] != 0) {
        vs_battle_memcpy(D_801024C0, arg0 + 0x94, 0x40);
        vs_battle_memcpy(D_801024C0 + 0x30, arg0 + 0xBC, 0x20);
        D_801024C0[0x3F] = arg0 == vs_battle_characterState->unk3C->unk3C;
        for (i = 0; i < 4; ++i) {
            D_801024C0[i + 0x20] = ((signed char*)arg0 + i)[0x64];
        }
        do {
            D_80102508 = (char)arg0[0x87];
        } while (0);
        func_800FC208((int)arg0[0x8A], (int)arg0[0x8B], (int)arg0[0x88], (int)arg0[0x89]);
        func_800FBD28((short)arg0[0x8C], (short)arg0[0x8E], (short)arg0[0x90], 1);
        D_801024A8[4] = (u_short)arg0[0x8D];
        D_801024A8[5] = (u_short)arg0[0x8F];
        D_801024A8[6] = (u_short)arg0[0x91];
        func_800FBD0C((char)arg0[0x92], (char)arg0[0x85], 0, 1);
    }
    func_800FBB8C(7);
}

void func_80102A64(u_short* arg0)
{
    int i;

    D_80102545 = 8;
    func_800FD220();
    if (arg0[12] != 0) {
        vs_battle_memcpy(D_801024C0, arg0 + 0x7A, 0x40);
        vs_battle_memcpy(D_801024C0 + 0x30, arg0 + 0xA2, 0x20);
        ;
        D_801024C0[63] = arg0 == vs_battle_characterState->unk3C->unk1D4;
        for (i = 0; i < 4; ++i) {
            D_801024C0[i + 0x20] = ((char*)arg0 + i)[0xF0];
        }
        func_800FC208(arg0[112], arg0[113], arg0[110], arg0[111]);
        func_800FBD28((short)arg0[114], (short)arg0[116], (short)arg0[118], 1);
        D_801024A8[4] = arg0[115];
        D_801024A8[5] = arg0[117];
        D_801024A8[6] = arg0[119];
    }
    func_800FBB8C(7);
}

void func_80102B70(u_short* arg0)
{
    int i;

    D_80102545 = 0x10;
    func_800FD220();
    if (arg0[0] != 0) {
        vs_battle_memcpy(D_801024C0, arg0 + 0x24, 0x40);
        vs_battle_memcpy(D_801024C0 + 0x30, arg0 + 0x4E, 0x20);
        D_801024C0[0x3F] = 0;
        for (i = 0; i < 5; ++i) {
            D_801024C0[0x3F] |= arg0 == vs_battle_characterState->unk3C->unk398[i].unk20;
        }

        for (i = 0; i < 4; ++i) {
            D_801024C0[i + 0x20] = arg0[i + 0x20];
        }
        func_800FC208(arg0[0x18], arg0[0x19], 0, 0);
        func_800FBD28((short)arg0[0x1A], (short)arg0[0x1C], (short)arg0[0x1E], 1);
        D_801024A8[4] = arg0[0x1B];
        D_801024A8[5] = arg0[0x1D];
        D_801024A8[6] = arg0[0x1F];
    }
    func_800FBB8C(7);
}

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

void func_80102F64(char* arg0, D_800F4E8C_t** arg1)
{
    char* c;
    vs_battle_stringContext[0x13] = D_8010229C[arg0[0x13] + 253];
    vs_battle_stringContext[0x12] = (char*)&D_80102540[D_80102540[arg0[4] + 0x18E]];
    vs_battle_stringContext[0x11] = (char*)&D_80102540[D_80102540[arg0[16] + 0x198]];
    c = arg0[4] + D_80102140;
    vs_battle_stringContext[0x10] = (char*)&D_80102540[D_80102540[(c[-1] + 0x19C)]];
    func_800C685C(
        func_800C685C(D_800F4E8C, (char*)&D_80102540[D_80102540[*(u_short*)arg0 - 1]]),
        (char*)(D_80102540 + 0x33FB));
    arg1[1] = (D_800F4E8C_t*)D_800F4E8C;
}

void func_80103080(func_80103080_t* arg0, D_800F4E8C_t** arg1)
{
    u_short* new_var2 = &arg0->unk0;
    D_800F51A4 = &D_80102540[D_80102540[arg0->unk4 + 0x280]];
    func_800C685C(
        func_800C685C(D_800F4E8C, (char*)(&D_80102540[D_80102540[(*new_var2) - 6]])),
        (char*)(D_80102540 + 0x3405));
    arg1[1] = D_800F4E8C;
}

void func_80103118(u_short* arg0, D_800F4E8C_t** arg1)
{
    vs_battle_memcpy(D_800F4E8C, D_80102540 + D_80102540[*arg0 - 0x8C], 0x60);
    arg1[1] = D_800F4E8C;
}

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

void func_80103FEC(int* arg0, int arg1)
{
    int temp_a0;
    int temp_s1;
    int temp_s2;
    u_int temp_s6;
    int temp_v1;
    int i;
    int var_s3;

    temp_s6 = func_800C9E08((vs_battle_equipment_t2*)arg0);
    var_s3 = 0;
    for (i = 0; i < 32; ++i) {
        temp_a0 = var_s3 & 7;
        if ((temp_s6 >> i) & 1) {
            int new_var = 0x10;
            temp_v1 = var_s3 >> 3;
            var_s3 += 1;
            temp_a0 *= 0x10;
            temp_s2 = (temp_a0) - (arg1 - new_var);
            temp_s1 = ((temp_v1 * new_var) + 0x90) << new_var;
            if (i >= new_var) {
                func_800C0224(0x80, ((temp_s2 + 8) & 0xFFFF) | temp_s1, 0x80008,
                    D_1F800000[1] - 2)[4]
                    = ((((i & 3) * 8) + 0x3068) | 0x37FF0000);
            }
            arg0 = func_800C0224(
                0x80, (temp_s2 & 0xFFFF) | temp_s1, 0x100010, D_1F800000[1] - 2);

            arg0[4]
                = (D_800EBC14[i] | (((0x0F0F906A >> i) & 1) ? 0x37F90000 : 0x37F80000));
        }
    }
}

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_80104134);

int func_80104514(int arg0)
{
    int i;

    for (i = 0; i < 6; ++i) {
        if (D_800F1928[arg0]->unk3C->unk398[i].unk6 == 0) {
            break;
        }
    }
    return i;
}

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

void func_80106150(void) {
    int temp_lo_5;
    int temp_s1;
    int temp_s0;
    int temp_s2;
    int* p;

    temp_s1 = (0x80 - D_801080B4);
    temp_s2 = D_800F453C[0x32B];
    temp_s0 = D_800F453C[0x31F];
    p = (int*) D_1F800000 + 13;
    p[4] = ((-vs_math_sine(D_8010809C) * temp_s1) >> 8) * temp_s2;
    p[5] = -(temp_s0 << 0xB);
    p[6] = ((vs_math_cosine(D_8010809C) * temp_s1) >> 8) * temp_s2;
    ((int *) D_1F800000)[13] = p[4] + ((vs_math_cosine(D_8010809C) * vs_math_cosine(D_801080A0)) >> 0xA) * temp_s2;
    p[1] = p[5] - vs_math_sine(D_801080A0) * temp_s2 * 4;
    temp_lo_5 = (vs_math_sine(D_8010809C) * vs_math_cosine(D_801080A0) >> 0xA) * temp_s2;
    p[8] = 0;
    p[9] = 0;
    p[10] = 0;
    p[12] = 0x1000;
    p[2] = p[6] + temp_lo_5;
    func_8007ACB0();
    if (D_801080BC != 0) {
        --D_801080BC;
    } else {
        func_800F9EB8(p - 8);
    }
    func_80105F60();
    func_80105E94();
    func_801045B8(0);
    func_80103AC8();
}

INCLUDE_ASM("build/src/MENU/MENU4.PRG/nonmatchings/120", func_80106308);

void func_801063F8(void)
{
    int i;
    vs_battle_equipment_t3* temp_a0
        = &D_800F1928[D_801080A8 - 1]->unk3C->unk398[D_801081ED];

    for (i = 0; i < 16; ++i) {
        D_801024C0[i + 16] = temp_a0->unk10[i & 7];
    }
    for (i = 0; i < 4; ++i) {
        D_801024C0[i + 32] = temp_a0->unk8[i];
    }
    func_801045B8(D_801081ED + 0x81);
}

int vs_menu4_Exec(char* state)
{
    enum state {
        none,
        init = 3,
        waitQuitToMenu = 11,
        quitToMenu,
        waitQuitToBattle,
        quitToBattle
    };

    int var_s2;
    int var_s5;
    int var_s6;
    D_801081B8_t* var_a0;
    int selectedRow;
    int new_var2;

    var_s5 = 0;
    var_s6 = 0;

    switch (*state) {
    case init:
        D_80108130 = 0;
        D_801081EC = 10;
        if (D_8010229C == NULL) {
            func_800FE5CC(1);
        }
        if (vs_mainmenu_ready() == 0) {
            break;
        }
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
        animWait = 1;
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
        *state = 5;
        break;
    case 4:
        if (animWait != 0) {
            --animWait;
            func_801045B8(-1);
            func_800FBEA4(1);
        } else {
            func_80106308();
            *state = 5;
        }
        break;
    case 5:
        var_s5 = 0;
        if ((D_801080A8 == 1) || (D_800F1928[D_801080A8 - 1]->unk3C->unk954 & 0x20000)) {
            var_s5 = 1;
        }
        if (animWait != 0) {
            if (func_80103744(0) != 0) {
                animWait = 0;
                func_801045B8(-1);
                func_800FBEA4(1);
                selectedRow = D_801081ED;
                if (selectedRow < VS_status_INDEX_statDesc) {
                    var_s2 = func_80104514(D_801080A8 - 1) - 1;
                    if (var_s2 < selectedRow) {
                        D_801081ED = var_s2;
                    }
                    func_80106308();
                } else {
                    vs_mainmenu_setMessage(
                        (char*)&_statusStrings[_statusStrings[selectedRow
                            - VS_status_INDEX_statDesc]]);
                }
            }
        } else if (func_800FE5CC(0) != 0) {
            if (func_801045B8(-3) == 2) {
                if (vs_main_buttonsPressed.all & PADRup) {
                    vs_battle_playMenuLeaveSfx();
                    *state = waitQuitToBattle;
                    break;
                } else if (vs_main_buttonsPressed.all & PADRdown) {
                    vs_battle_playMenuLeaveSfx();
                    *state = waitQuitToMenu;
                    break;
                } else if ((vs_main_buttonsPressed.all & PADRright)
                    && ((D_801081ED < func_80104514(D_801080A8 - 1)) != 0)) {
                    vs_battle_playMenuSelectSfx();
                    func_800FBEA4(2);
                    func_801045B8(-2);
                    animWait = 8;
                    *state = 7;
                    break;
                }
                var_s6 = 0;
                if (var_s5 != 0) {
                    int temp_s0_2 = D_801081ED;
                    var_s6 = temp_s0_2 < func_80104514(D_801080A8 - 1);
                }
                if (vs_main_buttonsPressed.all & PADRleft) {
                    if (var_s6 != 0) {
                        vs_battle_playMenuSelectSfx();
                        func_801063F8();
                        func_800FBBD4(6);
                        D_801081EE = 0;
                        animWait = 10;
                        *state = 9;
                        break;
                    }
                    func_800C02E0();
                }
                if (vs_main_buttonsState & PADL2) {
                    selectedRow = func_800C4708(vs_main_stickPosBuf.rStickX);
                    var_s2 = func_800C4708(vs_main_stickPosBuf.rStickY);
                    if (selectedRow == 0) {
                        if (var_s2 == 0) {
                            if (vs_main_buttonsState & PADLup) {
                                var_s2 = -64;
                            }
                            if (vs_main_buttonsState & PADLdown) {
                                var_s2 = 64;
                            }
                            if (vs_main_buttonsState & PADLleft) {
                                selectedRow = -64;
                            }
                            if (vs_main_buttonsState & PADLright) {
                                selectedRow = 64;
                            }
                        }
                    }

                    D_8010809C += selectedRow;
                    D_801080A0 -= var_s2;
                    if (D_801080A0 < 0) {
                        D_801080A0 = 0;
                    }
                    if (D_801080A0 > 896) {
                        D_801080A0 = 896;
                    }
                } else {
                    selectedRow = D_801081ED;
                    var_s2 = D_801080FC[selectedRow];
                    if (vs_main_buttonRepeat & PADLup) {
                        selectedRow = var_s2;
                    } else if (vs_main_buttonRepeat & PADLdown) {
                        selectedRow = var_s2 >> 8;
                    } else if (vs_main_buttonRepeat & PADLleft) {
                        selectedRow = var_s2 >> 16;
                    } else {
                        selectedRow = D_801081ED;
                        if (vs_main_buttonRepeat & PADLright) {
                            selectedRow = var_s2 >> 24;
                        }
                    }
                    selectedRow &= 0xFF;
                    func_801045B8(7);
                    if (selectedRow == 13) {
                        if (func_80104134(D_800F1928[D_801080A8 - 1]->unk3C, 1) == 0) {
                            vs_battle_playMenuChangeSfx();
                            *state = 6;
                            break;
                        }
                        selectedRow = D_801081ED;
                    }
                    if (selectedRow < 6) {
                        var_s2 = func_80104514(D_801080A8 - 1);
                        if (selectedRow < var_s2) {
                            func_801045B8(selectedRow + 1);
                        } else {
                            selectedRow = 6;
                            if (!(vs_main_buttonRepeat & PADLdown)) {
                                selectedRow = var_s2 - 1;
                                if (!(vs_main_buttonRepeat & PADLup)) {
                                    D_801081ED = selectedRow;
                                }
                            }
                        }
                    }
                    D_801022D5 = (selectedRow < func_80104514(D_801080A8 - 1)) ^ 1;
                    D_80108134 = func_800FFCDC(D_80108134, D_801080C8[selectedRow]);
                    if (selectedRow != D_801081ED) {
                        vs_battle_playMenuChangeSfx();
                        if (selectedRow != 13) {
                            D_801081ED = selectedRow;
                        }
                    }
                    if (selectedRow < 6) {
                        func_80106308();
                    } else {
                        vs_mainmenu_setMessage(
                            (char*)&_statusStrings[_statusStrings[selectedRow
                                - VS_status_INDEX_statDesc]]);
                    }
                }
            }
            selectedRow = D_801080A8 - 1;
            if (vs_main_buttonsPressed.all & PADR1) {
                selectedRow = func_80103688(selectedRow, 1);
                var_s2 = 17;
            }
            if (vs_main_buttonsPressed.all & PADL1) {
                selectedRow = func_80103688(selectedRow, 14);
                var_s2 = 1;
            }
            if (selectedRow != (D_801080A8 - 1)) {
                D_801080A4 = D_801080A8;
                func_801045B8(-2);
                func_800FBEA4(2);
                func_80103608(selectedRow);
                func_80103744(selectedRow + var_s2);
                animWait = 1;
            }
        }
        D_801022D5 = (D_801081ED < func_80104514(D_801080A8 - 1)) ^ 1;
        break;
    case 6:
        var_s5 = 0;
        if ((D_801080A8 == 1) || (D_800F1928[D_801080A8 - 1]->unk3C->unk954 & 0x20000)) {
            var_s5 = 1;
        }
        if (animWait != 0) {
            if (func_80103744(0) != 0) {
                func_80104134(D_800F1928[D_801080A8 - 1]->unk3C, 0);
                animWait = 0;
                func_801045B8(-1);
                func_800FBEA4(1);
            }
        } else {
            if (func_801045B8(-3) == 2) {
                selectedRow = func_80104134(0, 1);
                if (selectedRow != 0) {
                    switch (selectedRow) {
                    case 1:
                        *state = 5;
                        break;
                    case 2:
                        vs_battle_playMenuLeaveSfx();
                        *state = 13;
                        break;
                    case 3:
                        vs_battle_playMenuLeaveSfx();
                        *state = 11;
                        break;
                    }
                }
            }
            selectedRow = D_801080A8 - 1;
            if (vs_main_buttonsPressed.all & PADR1) {
                selectedRow = func_80103688(selectedRow, 1);
                var_s2 = 17;
            }
            if (vs_main_buttonsPressed.all & PADL1) {
                selectedRow = func_80103688(selectedRow, 14);
                var_s2 = 1;
            }
            if (selectedRow != (D_801080A8 - 1)) {
                D_801080A4 = D_801080A8;
                func_801045B8(-2);
                func_800FBEA4(2);
                func_80103608(selectedRow);
                func_80103744(selectedRow + var_s2);
                animWait = 1;
                if (func_800C9E08(D_800F1928[selectedRow]->unk3C) == 0) {
                    *state = 5;
                }
            }
        }
        break;
    case 7:
        if (animWait == 0) {
            func_80105970(D_801081ED + 1);
            *state = 8;
        } else {
            --animWait;
        }
        break;
    case 8:
        selectedRow = func_80105970(0);
        if (selectedRow != 0) {
            if (selectedRow != -2) {
                animWait = 8;
                *state = 4;
            } else {
                *state = 13;
            }
        }
        break;
    case 9:
        if (animWait != 0) {
            D_801080B4 = 128 - vs_battle_rowAnimationSteps[--animWait];
        } else if (vs_main_buttonsPressed.all & (PADRup | PADRdown)) {
            vs_battle_playMenuLeaveSfx();
            func_800FBBD4(-1);
            if (vs_main_buttonsPressed.all & PADRup) {
                *state = waitQuitToBattle;
                break;
            }
            animWait = 10;
            *state = 10;
        } else {
            if ((vs_main_buttonsState & (PADL1 | PADR1)) != (PADL1 | PADR1)) {
                selectedRow = D_801081ED;
                var_s2 = func_80104514(D_801080A8 - 1);
                if (vs_main_buttonRepeat & PADL1) {
                    char new_var = 1;
                    selectedRow = (selectedRow - new_var) + var_s2;
                }
                if (vs_main_buttonRepeat & PADR1) {
                    ++selectedRow;
                }
                if (selectedRow >= var_s2) {
                    selectedRow -= var_s2;
                }
                if (selectedRow != D_801081ED) {
                    vs_battle_playMenuChangeSfx();
                    D_801081ED = selectedRow;
                    func_801063F8();
                }
            }
            selectedRow = D_801081EE;
            var_s2 = 11 - D_801024B9 * 4;
            if (selectedRow >= var_s2) {
                selectedRow = var_s2 - 1;
            }
            if (vs_main_buttonRepeat & PADLup) {
                char new_var = 1;
                selectedRow = (selectedRow - new_var) + var_s2;
            }
            if (vs_main_buttonRepeat & PADLdown) {
                ++selectedRow;
            }
            if (selectedRow >= var_s2) {
                selectedRow -= var_s2;
            }
            if (selectedRow != D_801081EE) {
                vs_battle_playMenuChangeSfx();
                D_801081EE = selectedRow;
            }

            vs_mainmenu_setMessage((char*)&_statusStrings[_statusStrings[selectedRow
                + (var_s2 != 3 ? VS_status_INDEX_physicalDefense
                               : VS_status_INDEX_bluntDefense)]]);
            D_80108134 = func_800FFCDC(D_80108134, ((selectedRow * 16) + 50) << 16);
        }
        break;
    case 10:
        var_s5 = 1;
        if (animWait != 0) {
            D_801080B4 = vs_battle_rowAnimationSteps[--animWait];
        } else {
            func_801045B8(D_801081ED + 1);
            *state = 5;
        }
        break;
    case waitQuitToMenu:
    case waitQuitToBattle:
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
        func_800FA8E0(40);
        func_800F9E0C();
        func_80100414(-2, 128);
        D_800EB9AE = 0;
        animWait = 8;
        D_80108130 = 0;
        ++*state;
        break;
    case quitToMenu:
        func_801045B8(0);
        func_80103AC8();
        func_800FFB68(0);
        func_800FFBA8();
        if (animWait <= 0) {
            if (func_800FE694() != 0) {
                *state = none;
                return 1;
            }
        }
        --animWait;
        break;
    case quitToBattle:
        func_801045B8(0);
        func_80103AC8();
        func_800FFB68(0);
        func_800FFBA8();
        if (animWait <= 0) {
            if (func_800FE694() != 0) {
                vs_battle_menuState.currentState = 5;
                *state = none;
                return 1;
            }
        }
        --animWait;
        break;
    }

    if (D_80108130 != 0) {
        func_80106150();
    }
    if (var_s5 != 0) {
        if (D_801081EC != 0) {
            --D_801081EC;
        }
    } else {
        D_801081EC = D_800EBC7C[D_801081EC];
    }
    if (D_801081EC < 10) {
        selectedRow = vs_battle_rowAnimationSteps[D_801081EC];
        func_80100344(16 - selectedRow, 38, 88, 10);
        func_800FFC68(1, 8 - selectedRow, 36, 0);
        func_800C6540(
            "STATUS", ((0x1C - selectedRow) & 0xFFFF) | 0x260000, 0x404040 << var_s6, 0);
    }
    return 0;
}
