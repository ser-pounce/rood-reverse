#include "common.h"
#include "../MAINMENU.PRG/278.h"
#include "../MAINMENU.PRG/C48.h"
#include "../MAINMENU.PRG/413C.h"
#include "../MAINMENU.PRG/8170.h"
#include "../../SLUS_010.40/main.h"
#include "../../SLUS_010.40/31724.h"
#include "../../BATTLE/BATTLE.PRG/146C.h"
#include "../../BATTLE/BATTLE.PRG/2842C.h"
#include "../../BATTLE/BATTLE.PRG/2EA3C.h"
#include "../../BATTLE/BATTLE.PRG/30D14.h"
#include "../../BATTLE/BATTLE.PRG/40564.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"
#include <libetc.h>
#include <stdio.h>
#include <strings.h>
#include <libgpu.h>
#include "insertTPage.h"
#include "vs_string.h"

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
    char unk0;
    char unk1;
    char unk2;
    char unk3;
    short unk4;
    short unk6;
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
void func_80104CBC(MATRIX*);
void func_80104E90(MATRIX* arg0, short arg1);
void func_80104F04(MATRIX* arg0, short arg1);
void func_801051AC(int, int, int, int, int);
void func_80106528(void);
void func_80107600(void);
void func_801076A4(void);
void func_80107C34(void);
void func_8010812C(int);
int func_8010823C(void);
void func_801084E4(void);

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
extern char D_80102930[];
extern char D_801029AC[]; // %d
extern short D_801098A4[];
extern u_int D_801098C4[];
extern int D_80109904[];
extern int D_80109D04[];
extern char D_8010A104[];
extern char D_8010A204[];
extern int D_8010A224;
extern int D_8010A228;
extern D_8010A230_t D_8010A230[];
extern short D_8010A430[];
extern int D_8010A43C;
extern int D_8010A438;
extern int D_8010A444;
extern short D_8010A44E;
extern short D_8010A450;
extern int D_8010A45C;
extern long int D_8010A460;
extern short D_8010A464;
extern u_short D_8010A466;
extern u_short D_8010A468;
extern u_short D_8010A46A;
extern D_8010A470_t* D_8010A470;
extern u_short* D_8010A474;
extern char D_8010A480[16];
extern char D_8010A490[16];
extern int D_8010A4A0;
extern vs_main_CdQueueSlot* D_8010A4A4;
extern void* D_8010A4A8;
extern void* D_8010A4AC;
extern int D_8010A4B0;
extern int D_8010A4B4;

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

void func_80102E10(int arg0, int arg1, char** arg2, int arg3)
{
    int sp10[arg0];
    int i;
    char temp_s1;

    for (i = 0; i < arg0; ++i) {
        sp10[i] = 0;
    }

    if ((arg0 < 9) || (arg1 < 8)) {
        D_800F4EE8.unk0[2] = arg1;
        D_800F4EE8.unk0[3] = 0;
    } else if (arg1 >= (arg0 - 8)) {
        D_800F4EE8.unk0[2] = arg1 - (arg0 - 9);
        D_800F4EE8.unk0[3] = arg0 - 9;
    } else {
        D_800F4EE8.unk0[2] = 4;
        D_800F4EE8.unk0[3] = arg1 - 4;
    }
    temp_s1 = vs_main_settings.cursorMemory;
    vs_main_settings.cursorMemory = 1;
    vs_mainmenu_setMenuRows(arg0, 0x101, arg2, sp10);
    vs_main_settings.cursorMemory = temp_s1;
}

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

int func_801031BC(void)
{
    int i;
    int j;
    int new_var;

    if (D_8005FFD8.unk0[1] & 0x800000) {
        D_8005FFD8.unk0[1] |= 0x400000;
    }

    D_8010A43C = 0;
    D_8010A45C = 0;

    if (vs_main_settings.cursorMemory == 0) {
        vs_main_bzero(D_800F1BF0, 8);
    }

    D_8010A46A = 0;

    for (i = 0; i < 16; ++i) {
        for (j = 0; j < 32; ++j) {
            if (D_8005FFD8.unk0[i] & D_800E8508[i] & ((new_var = 1) << j)) {
                ++D_8010A46A;
            }
        }
    }

    D_8010A468 = 0;

    for (i = 0; i < 64; ++i) {
        if (vs_main_stateFlags.unk33F[i + 0x81] != 0) {
            ++D_8010A468;
        }
    }

    D_8010A466 = vs_main_stateFlags.clearCount;

    if (D_8010A46A > D_8005FEA0.unk88[3]) {
        D_8005FEA0.unk88[3] = D_8010A46A;
    }
    if (D_8010A468 > D_8005FEA0.unk88[4]) {
        D_8005FEA0.unk88[4] = D_8010A468;
    }

    vs_main_memcpy(D_8010A480, (void*)0x1F800034, 0x10);
    vs_main_memcpy(D_8010A490, (void*)0x1F800054, 0x10);
    func_801076A4();
    func_80107C34();
    func_80107600();

    return 1;
}

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

void func_80104CBC(MATRIX* arg0)
{
    SVECTOR sp10;
    SVECTOR sp18;
    MATRIX sp20;
    int trig0;
    int trig1;
    int trig2;
    int var_v0;
    int* scratch;

    trig0 = vs_math_sine(D_8010A430[1]);
    trig1 = vs_math_cosine(D_8010A430[0]);
    trig0 *= D_8010A444;
    if (trig0 < 0) {
        trig0 += 0xFFF;
    }

    var_v0 = (trig0 >> 0xC) * trig1;
    if (var_v0 < 0) {
        var_v0 += 0xFFF;
    }

    sp18.vx = var_v0 >> 0xC;
    trig0 = vs_math_cosine(D_8010A430[1]);
    trig1 = vs_math_cosine(D_8010A430[0]);
    trig0 *= -D_8010A444;
    if (trig0 < 0) {
        trig0 += 0xFFF;
    }

    var_v0 = (trig0 >> 0xC) * trig1;
    if (var_v0 < 0) {
        var_v0 += 0xFFF;
    }

    sp18.vz = var_v0 >> 0xC;
    trig2 = vs_math_sine(D_8010A430[0]) * -D_8010A444;
    if (trig2 < 0) {
        trig2 += 0xFFF;
    }

    sp18.vy = (trig2 >> 0xC) - (D_8010A44E / 2);

    scratch = (int*)getScratchAddr(0);
    scratch[13] = sp18.vx << 0xC;
    scratch[14] = (sp18.vy << 0x10) >> 4;
    scratch[15] = sp18.vz << 0xC;
    scratch[21] = D_8010A430[0];
    scratch[22] = D_8010A430[1];
    scratch[23] = D_8010A430[2];

    func_80104E90(arg0, D_8010A430[1]);
    func_80104F04(&sp20, D_8010A430[0]);
    func_80041C68(&sp20, arg0);

    sp10.vx = -sp18.vx;
    sp10.vy = -sp18.vy;
    sp10.vz = -sp18.vz;

    ApplyMatrix(arg0, &sp10, (VECTOR*)&arg0->t);
}

void func_80104E90(MATRIX* arg0, short arg1)
{
    int sine = vs_math_sine(-arg1);
    int cosine = vs_math_cosine(-arg1);
    arg0->m[0][0] = cosine;
    arg0->m[0][1] = 0;
    arg0->m[0][2] = -sine;
    arg0->m[1][0] = 0;
    arg0->m[1][1] = 0x1000;
    arg0->m[1][2] = 0;
    arg0->m[2][0] = sine;
    arg0->m[2][1] = 0;
    arg0->m[2][2] = cosine;
}

void func_80104F04(MATRIX* arg0, short arg1)
{
    int temp_s0;
    int temp_v0;

    temp_s0 = vs_math_sine(arg1);
    temp_v0 = vs_math_cosine(arg1);
    arg0->m[0][0] = 0x1000;
    arg0->m[0][1] = 0;
    arg0->m[0][2] = 0;
    arg0->m[1][0] = 0;
    arg0->m[1][1] = temp_v0;
    arg0->m[1][2] = -temp_s0;
    arg0->m[2][0] = 0;
    arg0->m[2][1] = temp_s0;
    arg0->m[2][2] = temp_v0;
}

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_80104F74);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_801051AC);

void func_8010539C(int arg0)
{
    POLY_F4* polyF4;
    void** scratch = (void**)getScratchAddr(0);
    POLY_G4* polyG4 = scratch[0];

    setPolyG4(polyG4);
    setXY4(polyG4, 0, arg0, 0x140, arg0, 0, arg0 + 8, 0x140, arg0 + 8);
    setRGB0(polyG4, 0, 0, 0);
    setRGB1(polyG4, 0, 0, 0);
    setRGB2(polyG4, 0x80, 0x80, 0x80);
    setRGB3(polyG4, 0x80, 0x80, 0x80);
    setSemiTrans(polyG4, 1);
    AddPrim(scratch[1] + 0x1C, polyG4++);
    polyF4 = (POLY_F4*)polyG4;
    setPolyF4(polyF4);
    setXY4(polyF4, 0, arg0 + 8, 0x140, arg0 + 8, 0, 0xF0, 0x140, 0xF0);
    setRGB0(polyF4, 0, 0, 0);
    AddPrim(scratch[1] + 0x1C, polyF4++);
    scratch[0] = polyF4;
    _insertTPage(7, getTPage(0, 2, 0, 0));
}

INCLUDE_RODATA("build/src/MENU/MENU9.PRG/nonmatchings/238", D_80102820);

INCLUDE_RODATA("build/src/MENU/MENU9.PRG/nonmatchings/238", D_80102830);

INCLUDE_RODATA("build/src/MENU/MENU9.PRG/nonmatchings/238", jtbl_80102898);

void func_8010552C(int arg0)
{
    vs_battle_geomOffset sp18;
    vs_battle_geomOffset sp20;
    char sp28[128];
    MATRIX spA8;
    void** scratch;

    if (arg0 < 8) {
        func_80106528();
    }
    vs_battle_getGeomOffset(&sp18);
    sp20.x = 0x80 - ((8 - arg0) << 5);
    sp20.y = 0xF0;
    vs_battle_setGeomOffset(&sp20);
    func_80104CBC(&spA8);
    func_800F9EB8(&spA8);
    vs_battle_setGeomOffset(&sp18);
    sprintf(sp28, "#%ld", D_8010A460);
    scratch = (void**)getScratchAddr(0);
    func_800C6540("SCORE", (((arg0 * 0x10) - 0x78) & 0xFFFF) | 0x100000, 0x808080,
        scratch[1] + 0x1C);
    func_800C6540(sp28, ((arg0 * 0x10) & 0xFFFF) | 0x100000, 0x808080, scratch[1] + 0x1C);
    func_801051AC((arg0 * 0x10) - 0x80, 0x10, 0x88, 0xC, 2);
    func_800C6540("RISK   BREAKER   RANK", (((arg0 * 0x10) - 0x78) & 0xFFFF) | 0xB80000,
        0x808080, scratch[1] + 0x1C);
    func_801051AC((arg0 * 0x10) - 0x80, 0xB8, 0x88, 0xC, 1);
    func_8010539C(0xEC - (arg0 * 6));
}

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

void func_80105A0C(int arg0, int arg1, int arg2, int arg3)
{
    char digits[2];
    int i;
    POLY_FT4* poly;

    sprintf(digits, D_80102930, arg2);
    arg0 += 0x13;
    poly = *(void**)0x1F800000;

    for (i = 1; i >= 0; --i, arg0 -= 5) {
        setPolyFT4(poly);
        poly->x0 = arg0;
        poly->y0 = arg1 - 4;
        poly->x1 = arg0 + 6;
        poly->y1 = arg1 - 4;
        poly->x2 = arg0;
        poly->y2 = arg1 + 6;
        poly->x3 = arg0 + 6;
        poly->y3 = arg1 + 6;
        setcode(poly, (getcode(poly) | 0x02) & 0xFE);
        poly->u0 = (digits[i] - 0x30) * 6;
        poly->v0 = 0;
        poly->u1 = ((digits[i] - 0x30) * 6) + 6;
        poly->v1 = 0;
        poly->u2 = (digits[i] - 0x30) * 6;
        poly->v2 = 0xA;
        poly->u3 = ((digits[i] - 0x30) * 6) + 6;
        poly->v3 = 0xA;
        if (arg3 != 0) {
            poly->tpage = 0x2C;
            poly->r0 = 0x20;
            poly->g0 = 0x20;
            poly->b0 = 0x20;
            poly->clut = 0x37F7;
        } else {
            poly->tpage = 0xC;
            poly->r0 = 0x80;
            poly->g0 = 0x80;
            poly->b0 = 0x80;
            poly->clut = 0x37F4;
        }
        AddPrim(*(void**)0x1F800008, poly++);
    }
    *(void**)0x1F800000 = poly;
}

INCLUDE_RODATA("build/src/MENU/MENU9.PRG/nonmatchings/238", D_80102930);

void func_80105BCC(int arg0, int arg1, int arg2, int arg3)
{
    char sp10[2];
    int i;
    POLY_FT4* poly;

    sprintf(sp10, "%03d", arg2);
    arg0 += 0x18;
    poly = *(void**)getScratchAddr(0);

    for (i = 2; i >= 0; --i, arg0 -= 5) {
        setPolyFT4(poly);
        setXY4(
            poly, arg0, arg1 - 4, arg0 + 6, arg1 - 4, arg0, arg1 + 6, arg0 + 6, arg1 + 6);
        setcode(poly, (getcode(poly) | 0x02) & 0xFE);
        setUV4(poly, (sp10[i] - 0x30) * 6, 0, ((sp10[i] - 0x30) * 6) + 6, 0,
            (sp10[i] - 0x30) * 6, 0xA, ((sp10[i] - 0x30) * 6) + 6, 0xA);
        if (arg3 != 0) {
            setTPage(poly, 0, 1, 768, 0);
            setRGB0(poly, 0x20, 0x20, 0x20);
            setClut(poly, 880, 223);
        } else {
            setTPage(poly, 0, 0, 768, 0);
            setRGB0(poly, 0x80, 0x80, 0x80);
            setClut(poly, 832, 223);
        }
        AddPrim(*(void**)getScratchAddr(2), poly++);
    }
    *(void**)getScratchAddr(0) = poly;
}

void func_80105D8C(void)
{
    int j;
    int var_v0;
    int i;
    char var_a0_2;
    D_8010A470_t* var_a3;
    int new_var;
    int* new_var2;

    for (i = 0, var_a3 = D_8010A470; i < 0x4E; ++i, ++var_a3) {
        var_a3->unkC = 0;
        for (j = var_a3->unk4; j < (var_a3->unk4 + var_a3->unk6); ++j) {
            var_v0 = j;
            if (j < 0) {
                var_v0 += 0x1F;
            }
            var_v0 >>= 5;
            new_var =
                D_8005FEA0.unk9C[var_v0] & (1 << (j - ((*(new_var2 = &var_v0)) << 5)));
            if (new_var) {
                var_a3->unkC = 1;
                break;
            }
        }
    }

    for (i = 0, var_a3 = D_8010A470, var_a0_2 = -1; i < 0x4E; ++i, ++var_a3) {
        if (var_a3->unkC != 0) {
            var_a3->unkD = var_a0_2;
            var_a0_2 = i;
        }
    }

    for (i = 0, var_a3 = D_8010A470; i < 0x4E; ++i, ++var_a3) {
        if (var_a3->unkC != 0) {
            var_a3->unkD = var_a0_2;
            break;
        }
    }

    for (i = 0x4D, var_a3 = &D_8010A470[77], var_a0_2 = -1; i >= 0; --i, --var_a3) {
        if (var_a3->unkC != 0) {
            var_a3->unkE = var_a0_2;
            var_a0_2 = i;
        }
    }

    for (i = 0x4D, var_a3 = &D_8010A470[77]; i >= 0; --i, --var_a3) {
        if (var_a3->unkC != 0) {
            var_a3->unkE = var_a0_2;
            break;
        }
    }
}

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_80105F00);

INCLUDE_RODATA("build/src/MENU/MENU9.PRG/nonmatchings/238", D_80102940);

INCLUDE_RODATA("build/src/MENU/MENU9.PRG/nonmatchings/238", D_80102948);

INCLUDE_RODATA("build/src/MENU/MENU9.PRG/nonmatchings/238", D_80102950);

INCLUDE_RODATA("build/src/MENU/MENU9.PRG/nonmatchings/238", D_80102958);

INCLUDE_RODATA("build/src/MENU/MENU9.PRG/nonmatchings/238", D_80102960);

INCLUDE_RODATA("build/src/MENU/MENU9.PRG/nonmatchings/238", D_80102968);

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_801061F8);

void func_80106528(void)
{
    void** scratch = (void**)0x1F800000;
    POLY_G4* poly = scratch[0];

    setPolyG4(poly);
    setXY4(poly, 0, 0, 0x40, 0, 0, 0xF0, 0x40, 0xF0);
    setRGB0(poly, 0x80, 0x80, 0x80);
    setRGB1(poly, 0, 0, 0);
    setRGB2(poly, 0x80, 0x80, 0x80);
    setRGB3(poly, 0, 0, 0);
    setSemiTrans(poly, 1);
    AddPrim(scratch[1] + 0x20, poly++);
    setPolyG4(poly);
    setXY4(poly, 0x100, 0, 0x140, 0, 0x100, 0xF0, 0x140, 0xF0);
    setRGB0(poly, 0, 0, 0);
    setRGB1(poly, 0x80, 0x80, 0x80);
    setRGB2(poly, 0, 0, 0);
    setRGB3(poly, 0x80, 0x80, 0x80);
    setSemiTrans(poly, 1);
    AddPrim(scratch[1] + 0x20, poly++);
    scratch[0] = poly;
    _insertTPage(8, getTPage(0, 2, 0, 0));
}

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

void func_80106DE0(char* buf, int rank, int totalSeconds)
{
    int len;
    int i;
    int minutes;
    int seconds;
    char* str;

    if (D_8010A466 == 0) {
        _vsStrcpy((u_char*)buf, (u_char*)&_miscInfo[_miscInfo[0]]);
        return;
    }

    minutes = totalSeconds / 60;

    if (minutes >= 100) {
        minutes = 99;
        seconds = 59;
    } else {
        seconds = totalSeconds % 60;
    }

    *buf = vs_char_R;
    str = buf + 1;
    sprintf(str, D_801029AC, rank + 1);
    len = strlen(str);

    for (i = 0; i < len; ++i) {
        str[i] -= 0x30;
    }

    str = &str[len];
    *str++ = (u_char)vs_char_spacing;
    *str++ = 12;

    sprintf(str, D_80102930, minutes);
    len = strlen(str);

    for (i = 0; i < len; ++i) {
        str[i] -= 0x30;
    }

    str = &str[len];
    *str++ = (u_char)vs_char_colon;
    sprintf(str, D_80102930, seconds);
    len = strlen(str);

    for (i = 0; i < len; ++i) {
        str[i] -= 0x30;
    }

    str += len;
    *str = (u_char)vs_char_terminator;
}

void func_80106F9C(void)
{
    int i;
    D_8010A230_t* var_t0;

    for (i = 0, var_t0 = D_8010A230; i < 8; ++i, ++var_t0) {
        var_t0->unk4 = 0xC2;
        if ((D_8005FEA0.unk28[i][0] & 0xFFFFFF) == 0x800000) {
            var_t0->unk3 = 1;
            var_t0->unk8 = (char*)&_miscInfo[_miscInfo[4]];
            var_t0->unkC = (char*)&_miscInfo[_miscInfo[5]];
        } else {
            var_t0->unk3 = 0;
            var_t0->unk8 = (char*)&_timeAttacks[_timeAttacks[i]];
            var_t0->unkC = (char*)&_timeAttackDescriptions[_timeAttackDescriptions[i]];
        }
        var_t0->unk0 = 0;
        var_t0->unk2 = i + 1;
        var_t0->unk1 = 1;
    }
}

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

void func_80107A98(int arg0)
{
    int x;
    int clut;
    POLY_FT4* poly;
    void** scratch;
    int new_var;

    if (D_8010A45C == 0) {
        clut = getClut(896, 223);
        if (arg0 >= 2) {
            arg0 -= 2;
            clut = getClut(912, 223);
        }
        if (arg0 != 0) {
            func_800C6540("#R1", 0x62011E, 0x808080, NULL);
            if (D_8010A438 < 9) {
                x = (D_8010A438 >> 1) + 0x120;
            } else {
                x = -(D_8010A438 >> 2) + 0x126;
            }
        } else {
            func_800C6540("L1", 0x620022, 0x808080, NULL);
            if (D_8010A438 < 9) {
                new_var = 0x20;
                x = new_var - (D_8010A438 >> 1);
            } else {
                x = (D_8010A438 >> 2) + 0x1A;
            }
        }
        x -= 8;
        scratch = (void**)getScratchAddr(0);
        poly = scratch[0];
        setPolyFT4(poly);
        setXY4(poly, x, 0x60, x + 0x10, 0x60, x, 0x70, x + 0x10, 0x70);
        setUV4(poly, arg0 * 0x10, 0x30, (arg0 * 0x10) + 0x10, 0x30, arg0 * 0x10, 0x40,
            (arg0 * 0x10) + 0x10, 0x40);
        setTPage(poly, 0, 0, 768, 0);
        poly->clut = clut;
        setShadeTex(poly, 1);
        AddPrim(scratch[1], poly++);
        scratch[0] = poly;
    }
}

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

void func_8010812C(int id)
{
    vs_main_CdFile cdFile;
    int i;

    cdFile.lba = D_80109904[id];
    D_8010A4A0 = id;
    cdFile.size = D_80109D04[id];
    D_8010A4A4 = vs_main_allocateCdQueueSlot(&cdFile);
    D_8010A4A8 = vs_main_allocHeapR(cdFile.size);
    vs_main_cdEnqueueUrgent(D_8010A4A4, D_8010A4A8);
    D_8010A4B4 = D_8010A104[id];
    D_8010A4B0 = 0;

    for (i = 0; i < 6; ++i) {
        if (id == D_8010A204[i]) {
            D_8010A4B0 = i;
            break;
        }
    }

    if (D_8010A4B0 != 0) {
        D_8010A4AC = vs_main_allocHeap(0x3200);
    } else {
        D_8010A4AC = vs_main_allocHeap(0x24D0);
    }
}

INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_8010823C);

void func_801084E4(void)
{
    vs_main_freeHeapR(D_8010A4AC);
    D_8010A4AC = NULL;
}

void func_80108514(void) { }
