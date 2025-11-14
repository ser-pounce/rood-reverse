#include "common.h"
#include "../MAINMENU.PRG/278.h"
#include "../MAINMENU.PRG/C48.h"
#include "../MAINMENU.PRG/413C.h"
#include "../MAINMENU.PRG/8170.h"
#include "../../SLUS_010.40/main.h"
#include "../../SLUS_010.40/31724.h"
#include "../../BATTLE/BATTLE.PRG/146C.h"
#include "../../BATTLE/BATTLE.PRG/2842C.h"
#include "../../BATTLE/BATTLE.PRG/30D14.h"
#include "../../BATTLE/BATTLE.PRG/40564.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"
#include <libetc.h>
#include <stdio.h>
#include <strings.h>

typedef struct {
    char unk0;
    char unk1;
    char unk2;
    char unk3;
} D_8010989C_t;

typedef struct {
    char unk0;
    char unk1;
    char unk2;
    char unk3;
    short unk4;
    short unk6;
    char* unk8;
    char* unkC;
} D_8010A230_t;

typedef struct {
    int unk0;
    int unk4;
    int unk8;
    char unkC;
    char unkD;
    char unkE;
    char unkF;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
} D_8010A470_t;

void func_80102E10(int, int, char**, int);
void func_8010812C(int);
int func_8010823C(void);
void func_801084E4();

extern char D_800F1BF7;
extern char D_800F4EEA;

extern u_short _menuStrings[];
extern u_short _rankStrings[];
extern u_short _titleStrings[];
extern u_short _titleDescriptions[];
extern u_short _statHeaders[];
extern u_short _statDescriptions[];
extern u_short _timeAttacks[];
extern u_short _timeAttackDescriptions[];
extern u_short _miscInfo[];

extern D_8010989C_t D_8010989C;
extern char D_801029AC[]; // %d
extern short D_801098A4[];
extern u_int D_801098C4[];
extern int D_8010A224;
extern int D_8010A228;
extern D_8010A230_t D_8010A230[];
extern short D_8010A450;
extern int D_8010A460;
extern short D_8010A464;
extern D_8010A470_t* D_8010A470;
extern u_short* D_8010A474;
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

void func_80104B40(void)
{
    if (D_8010A470[D_8010A450].unkC != 0) {
        vs_mainmenu_setMessage((char*)&D_8010A474[D_8010A474[D_8010A450]]);
    } else {
        vs_mainmenu_setMessage((char*)&_miscInfo[_miscInfo[2]]);
    }
}

int func_80104BD0(int arg0)
{
    char* sp10[8];
    int i;

    if (arg0 != 0) {
        D_8010A224 = 0;
        D_8010A228 = 0;
    }

    switch (D_8010A224) {
    case 0:
        for (i = 0; i < 4; ++i) {
            sp10[i * 2] = (char*)&_menuStrings[_menuStrings[i]];
            sp10[i * 2 + 1] = NULL;
        }
        func_80102E10(4, D_800F1BF7, sp10, i);
        ++D_8010A224;
        break;
    case 1:
        D_8010A228 = func_80102F0C();
        if (D_8010A228 == -1) {
            break;
        }
        return D_8010A228;
    }
    return -1;
}

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_80104CBC);

void func_80104E90(short* arg0, short arg1)
{
    int sine = vs_math_sine(-arg1);
    int cosine = vs_math_cosine(-arg1);
    arg0[0] = cosine;
    arg0[2] = -sine;
    arg0[1] = 0;
    arg0[3] = 0;
    arg0[4] = 0x1000;
    arg0[5] = 0;
    arg0[6] = sine;
    arg0[7] = 0;
    arg0[8] = cosine;
}

void func_80104F04(short* arg0, short arg1)
{
    int temp_s0;
    int temp_v0;

    temp_s0 = vs_math_sine(arg1);
    temp_v0 = vs_math_cosine(arg1);
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

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_80104F74);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_801051AC);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_8010539C);

INCLUDE_RODATA("build/src/MENU/MENU9.PRG/nonmatchings/238", D_80102820);

INCLUDE_RODATA("build/src/MENU/MENU9.PRG/nonmatchings/238", D_80102830);

INCLUDE_RODATA("build/src/MENU/MENU9.PRG/nonmatchings/238", jtbl_80102898);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_8010552C);

void func_801056B8(void)
{
    int i;
    D_8010A230_t* var_a2;
    int new_var;

    for (i = 0, var_a2 = D_8010A230; i < 32; ++i, ++var_a2) {
        var_a2->unk4 = 0x3C;
        var_a2->unk6 = i + 1;
        var_a2->unk0 = 0;
        var_a2->unk2 = 0;
        var_a2->unk3 = 0;
        if (D_8005FEA0.unk0[0] & ((new_var = 1) << i)) {
            var_a2->unk1 = 1;
            var_a2->unk8 = (char*)&_titleStrings[_titleStrings[i]];
            var_a2->unkC = (char*)&_titleDescriptions[_titleDescriptions[i]];
        } else {
            var_a2->unk1 = 0;
            var_a2->unk8 = (char*)&_miscInfo[_miscInfo[0]];
            var_a2->unkC = (char*)&_miscInfo[_miscInfo[1]];
        }
    }
}

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

void func_80106780(void)
{
    int i;
    D_8010A230_t* p;

    for (i = 0, p = D_8010A230; i < 23; ++i, ++p) {
        p->unk4 = 16;
        p->unk8 = (void*)&_statHeaders[_statHeaders[i]];
        p->unkC = (void*)&_statDescriptions[_statDescriptions[i]];
        p->unk2 = 0;
        p->unk6 = i + 1;
        p->unk0 = 0;
        p->unk3 = 0;
        p->unk1 = 1;
    }
}

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_80106808);

void _toVsStringInt(char* buf, int value)
{
    int len;
    int i;
    buf++;
    buf--;
    sprintf(buf, D_801029AC, value);
    len = strlen(buf);

    for (i = 0; i < len; ++i) {
        buf[i] -= 0x30;
    }
    buf += len;
    *buf = -0x19;
}

void _toVsStringPercent(char* buf, int value)
{

    int len;
    int i;

    buf++;
    buf--;

    sprintf(buf, D_801029AC, value);

    len = strlen(buf);
    for (i = 0; i < len; ++i) {
        buf[i] -= 0x30;
    }
    buf += len;
    *((D_8010989C_t*)buf) = D_8010989C;
}

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_80106DE0);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_80106F9C);

void func_80107090(void)
{
    int i;
    D_8010A230_t* p = D_8010A230;

    for (i = 0; i < 8; ++i, ++p) {
        if (p->unk2 == 0) {
            vs_battle_menuItem_t* temp_v0 = vs_battle_getMenuItem(i);
            temp_v0->state = 2;
            temp_v0->x = 0x140;
        } else {
            p->unk2 = -1;
        }
    }
}

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

// https://decomp.me/scratch/cebYm
// Needs 2.7.2-cdk
INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_80107FBC);

// https://decomp.me/scratch/xyltD
// Needs 2.7.2-cdk
INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_80108098);

// https://decomp.me/scratch/da4gv
// Needs 2.7.2-cdk
INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_801080C8);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_8010812C);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_8010823C);

void func_801084E4(void)
{
    vs_main_freeHeapR(D_8010A4AC);
    D_8010A4AC = NULL;
}

void func_80108514(void) { }
