#include "common.h"
#include "../MAINMENU.PRG/C48.h"
#include "../MAINMENU.PRG/413C.h"
#include "../MAINMENU.PRG/8170.h"
#include "../../BATTLE/BATTLE.PRG/146C.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"

static char* _vsStringCpy(char* arg0, char* arg1);
void func_80102CD8(int, int, char**);

extern u_short D_80104E54[];
extern int D_80105230;
extern int D_80105234;
extern int D_80105240;
extern int D_80105244;
extern int D_80105248;
extern int D_8010524C;
extern int* D_80105254;
extern int D_80105258;

static void func_80102C94(int arg0)
{
    if (arg0 != 0) {
        func_800FFA88(2);
        D_801022D6 = 0;
        return;
    }
    func_800FFA88(0);
    D_801022D6 = 1;
}

void func_80102CD8(int rowCount, int arg1, char** strings)
{
    int rowTypes[rowCount];
    int i;
    char cursor;

    for (i = 0; i < rowCount; ++i) {
        rowTypes[i] = 0;
    }

    rowTypes[rowCount - 1] |= 4;

    if ((rowCount < 9) || (arg1 < 8)) {
        D_800F4EE8.unk0[4] = arg1;
        D_800F4EE8.unk0[5] = 0;
    } else if (arg1 >= (rowCount - 8)) {
        D_800F4EE8.unk0[4] = arg1 - (rowCount - 9);
        D_800F4EE8.unk0[5] = rowCount - 9;
    } else {
        D_800F4EE8.unk0[4] = 4;
        D_800F4EE8.unk0[5] = arg1 - 4;
    }
    cursor = vs_main_settings.cursorMemory;
    vs_main_settings.cursorMemory = 1;
    vs_mainmenu_setMenuRows(rowCount, 0x102, strings, rowTypes);
    vs_main_settings.cursorMemory = cursor;
}

static int func_80102DF0()
{
    int row;

    row = vs_mainmenu_getSelectedRow();
    if (row < -1) {
        func_800FA8E0(5);
        return row;
    }
    if (row >= 0) {
        func_800FA92C(D_800F4EE8.unk0[4], 1);
    }
    return row;
}

static void func_80102E48(char* text)
{
    vs_battle_menuItem_t* menuItem;

    menuItem = vs_battle_setMenuItem(10, 320, 34, 0x8C, 9, text);
    menuItem->state = 2;
    menuItem->x = 180;
    menuItem->selected = 1;
    menuItem->unkA = 1;
}

static void func_80102E9C() { func_800FA8E0(8); }

static void _menuReady() { vs_mainmenu_ready(); }

INCLUDE_ASM("build/src/MENU/MENUE.PRG/nonmatchings/494", func_80102EDC);

static int func_801030A4()
{
    if (D_80060021 == 0) {
        vs_main_bzero(D_800F1BC8, sizeof(D_800F1BC8));
    }
    func_8007DFF0(0x1D, 3, 5);
    D_80105240 = 0;
    D_80105244 = 0;
    D_80105248 = 0;
    D_80105254 = 0;
    D_80105258 = 0;
    return 1;
}

INCLUDE_RODATA("build/src/MENU/MENUE.PRG/nonmatchings/494", D_80102818);

INCLUDE_ASM("build/src/MENU/MENUE.PRG/nonmatchings/494", func_80103110);

int func_8010391C(int arg0)
{
    char* sp10[28];
    int i;

    if (arg0 != 0) {
        D_80105230 = 0;
        D_80105234 = 0;
    }

    switch (D_80105230) {
    case 0:
        for (i = 0; i < 14; ++i) {
            sp10[i * 2] = (char*)&D_80104E54[D_80104E54[i]];
            sp10[i * 2 + 1] = (char*)&D_80104E54[D_80104E54[14 + i]];
        }
        func_80102CD8(0xE, *D_800F1BC8, sp10);
        ++D_80105230;
        break;
    case 1:
        D_80105234 = func_80102DF0();
        if (D_80105234 != -1) {
            return D_80105234;
        }
        break;
    }
    return -1;
}

static void func_80103A24(u_long* arg0, int arg1)
{
    RECT rect;
    int var_s0;

    var_s0 = 0;
    rect.w = 4;
    rect.h = 16;

    for (var_s0 = 0; var_s0 < arg1; ++var_s0) {
        rect.x = ((var_s0 % 48) * 4) + 832;
        rect.y = ((var_s0 / 48) * 16) + 256;
        LoadImage2(&rect, arg0);
        arg0 += 32;
    }
}

static void func_80103AD8(u_long* arg0, int arg1)
{
    RECT rect;
    int temp_v0;
    int var_s0;
    int var_v0;

    var_s0 = 0;
    rect.w = 0x10;
    rect.h = 1;

    for (var_s0 = 0; var_s0 < arg1; ++var_s0) {
        var_v0 = var_s0;
        if (var_s0 < 0) {
            var_v0 += 0xF;
        }
        temp_v0 = var_v0 >> 4;
        rect.x = ((var_s0 - (temp_v0 * 16)) * 16) + 768;
        rect.y = temp_v0 + 0x1F0;
        LoadImage2(&rect, arg0);
        arg0 += 8;
    }
}

static int func_80103B6C()
{
    int temp_v1;
    int var_a0;

    var_a0 = D_80105254[4] & 0xFFFF;
    temp_v1 = (D_80105254[4] & 0xFFFF) % 10;
    if (temp_v1 > 0) {
        var_a0 += 10 - temp_v1;
    }
    var_a0 -= 10;
    if (var_a0 < 0) {
        var_a0 = 0;
    }
    return var_a0;
}

static void func_80103BC8()
{
    char sp10[1024];
    int var_s0;
    int var_s2;
    u_short* temp_s3;
    char* var_a0;
    int temp_a1;

    sp10[0] = 0xF8;
    sp10[1] = 0;
    sp10[2] = 0xFB;
    sp10[3] = 6;
    sp10[4] = -0x18;

    temp_s3 = (ushort*)(D_80105254 + 4);
    var_s2 = D_80105244 + 10;
    var_a0 = sp10 + 4;

    if ((u_short)D_80105254[4] < var_s2) {
        var_s2 = (u_short)D_80105254[4];
    }

    temp_a1 = D_80105244;

    for (var_s0 = temp_a1; var_s0 < var_s2; ++var_s0) {
        temp_a1 = temp_s3[var_s0 + 1];
        var_a0 = _vsStringCpy(var_a0, (char*)(temp_s3 + temp_a1));
    }

    var_a0[-1] = 0xE7;
    func_800C6BF0(0, &sp10);
}

static char* _vsStringCpy(char* arg0, char* arg1)
{
    char c;

    for (c = *arg1; c != 0xE7; c = *arg1) {
        if (c >= 0xEC) {
            *arg0 = c;
            ++arg1;
            ++arg0;
        }
        *arg0++ = *arg1++;
    }
    *arg0 = 0xE8;
    return arg0 + 1;
}

INCLUDE_ASM("build/src/MENU/MENUE.PRG/nonmatchings/494", func_80103CF0);

INCLUDE_ASM("build/src/MENU/MENUE.PRG/nonmatchings/494", func_80103E6C);

INCLUDE_ASM("build/src/MENU/MENUE.PRG/nonmatchings/494", func_80104204);

INCLUDE_ASM("build/src/MENU/MENUE.PRG/nonmatchings/494", func_8010435C);

INCLUDE_ASM("build/src/MENU/MENUE.PRG/nonmatchings/494", func_80104620);

void func_80104908(int arg0)
{
    int var_a1;
    POLY_FT4* temp_s1;
    int v1;
    u_long p;

    if (arg0 != 0) {
        if (D_8010524C < 9) {
            var_a1 = (D_8010524C >> 1) + 0xB8;
        } else {
            var_a1 = -(D_8010524C >> 2) + 0xBE;
        }
    } else if (D_8010524C < 9) {
        v1 = 0x28;
        var_a1 = v1 - (D_8010524C >> 1);
    } else {
        var_a1 = (D_8010524C >> 2) + 0x22;
    }
    temp_s1 = *(void**)0x1F800000;
    setlen(temp_s1, 9);
    setcode(temp_s1, 0x2D);
    setXY4(temp_s1, 0x98, var_a1, 0xA8, var_a1, 0x98, var_a1 + 0x10, 0xA8, var_a1 + 0x10);
    setUV4(temp_s1, arg0 * 0x10, 0x30, arg0 * 0x10 + 0x10, 0x30, arg0 * 0x10, 0x40,
        arg0 * 0x10 + 0x10, 0x40);
    temp_s1->tpage = 0xC;

    if (vs_main_buttonsPreviousState & 0x80) {
        temp_s1->clut = 0x37F8;
    } else {
        temp_s1->clut = 0x37F9;
    }
    p = 0x1F800000;
    AddPrim(((void**)p)[1] - 0x1C, temp_s1++);
    *(void**)p = temp_s1;
}

INCLUDE_ASM("build/src/MENU/MENUE.PRG/nonmatchings/494", func_80104A44);

static short func_80104C30(short* arg0)
{
    short new_var;

    if (arg0[4] >= 0x10) {
        return arg0[6];
    }

    new_var = (((u_short)arg0[1]) >> arg0[4]);
    new_var = (new_var & 1);

    if (++arg0[5] >= arg0[2]) {
        arg0[5] = 0;
        if (++arg0[4] >= 0x10) {
            if (arg0[3] != 0) {
                arg0[4] = 0;
            }
        }
    }
    return arg0[6] = new_var ^ 1;
}

INCLUDE_ASM("build/src/MENU/MENUE.PRG/nonmatchings/494", func_80104CC4);

INCLUDE_RODATA("build/src/MENU/MENUE.PRG/nonmatchings/494", D_80102BF8);

INCLUDE_RODATA("build/src/MENU/MENUE.PRG/nonmatchings/494", D_80102C08);

INCLUDE_RODATA("build/src/MENU/MENUE.PRG/nonmatchings/494", D_80102C10);

INCLUDE_RODATA("build/src/MENU/MENUE.PRG/nonmatchings/494", D_80102C18);

INCLUDE_RODATA("build/src/MENU/MENUE.PRG/nonmatchings/494", D_80102C20);

INCLUDE_RODATA("build/src/MENU/MENUE.PRG/nonmatchings/494", jtbl_80102C28);

INCLUDE_RODATA("build/src/MENU/MENUE.PRG/nonmatchings/494", D_80102C48);

INCLUDE_RODATA("build/src/MENU/MENUE.PRG/nonmatchings/494", D_80102C54);
