#include "common.h"
#include "../MAINMENU.PRG/C48.h"
#include "../MAINMENU.PRG/413C.h"
#include "../MAINMENU.PRG/8170.h"
#include "../../BATTLE/BATTLE.PRG/146C.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"
#include "gpu.h"
#include <libetc.h>

typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
} D_80102C54_t;

typedef struct {
    int unk0;
    int unk4;
    int unk8;
} D_80102C48_t;

enum arrowType_e {
    arrowTypeUp,
    arrowTypeDown,
};

static char* _vsStringCpy(char* arg0, char* arg1);
static void func_80102CD8(int, int, char**);
static int func_801030A4();
static int func_80103110();
static void func_80103E6C(short*);
static void _drawPaginationArrow(enum arrowType_e arrowType);
static void func_80104A44();
static short func_80104C30(short* arg0);

extern D_80102C48_t D_80102C48;
extern D_80102C54_t D_80102C54[];
extern u_short D_80104E54[];
extern int D_80105228;
extern char D_8010522C;
extern char D_8010522D;
extern int D_80105230;
extern int D_80105234;
extern int D_80105240;
extern int D_80105244;
extern int D_80105248;
extern int _pageArrowAnimState;
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

static void func_80102CD8(int rowCount, int arg1, char** strings)
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

int func_80102EDC(char* state)
{

    switch (*state) {
    case 3:
        func_800FFB68(1);
        D_8010522D = 8;
        D_8010522C = 0;
        *state = 4;
        break;
    case 4:
        if (D_8010522C == 0) {
            D_8010522C = func_801030A4();
        }
        if (D_8010522D != 0) {
            D_8010522D -= 1;
        } else if (D_8010522C != 0) {
            func_8008A4DC(0);
            func_800CB654(1);
            D_800EB9B0 = 0x200000;
            *state = 5;
        }
        break;
    case 5:
        *state += vs_mainmenu_ready();
        break;
    case 6:
        D_80105228 = func_80103110();
        if (D_80105228 == 0) {
            break;
        }
        func_80100414(-4, 0x80);
        func_800CB654(0);
        D_800EB9B0 = 0;
        func_8008A4DC(1);
        func_800FFA88(0);
        func_800FA8E0(0x28);
        *state = 7;
        break;
    case 7:
        func_800FFB68(0);
        *state = 8;
        break;
    case 8:
        if (D_801022D8 != 0) {
            break;
        }
        if (D_80105228 == 2) {
            vs_battle_menuState.currentState = 0xA;
        }
        D_801022D6 = 0;
        *state = 0;
        return 1;
    }
    return 0;
}

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

static int func_8010391C(int arg0)
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

static void func_80103CF0()
{
    RECT rect;
    DR_AREA* area;
    int i;
    int var_v0;
    u_short* temp_s2;
    void** q;
    void** p = (void**)getScratchAddr(0);

    area = p[0];
    SetDrawArea(area, &vs_main_drawEnv[(vs_main_frameBuf + 1) & 1].clip);
    AddPrim(p[1], area++);
    p[0] = area;

    func_80104A44();

    var_v0 = *D_80105254;
    if (var_v0 < 0) {
        var_v0 += 3;
    }
    temp_s2 = (u_short*)D_80105254 + 8 + (var_v0 >> 2) * 2;

    for (i = 0; i < temp_s2[0]; ++i) {
        func_80103E6C(&temp_s2[temp_s2[i + 1]]);
    }
    if (vs_main_drawEnv[(vs_main_frameBuf + 1) & 1].clip.x >= 0x140) {
        rect.x = 0x14D;
    } else {
        rect.x = 0xD;
    }
    rect.w = 0x12C;
    rect.y = 0x37;
    rect.h = 0x82;

    q = (void**)getScratchAddr(0);
    area = q[0];
    SetDrawArea(area, &rect);
    AddPrim(q[1], area++);
    q[0] = area;
}

INCLUDE_ASM("build/src/MENU/MENUE.PRG/nonmatchings/494", func_80103E6C);

static inline void _insertTpage(int primIndex, int tpage)
{
    __asm__("li         $t3, 0x1F800000;"
            "sll        $t0, %0, 2;"
            "lw         $t4, 4($t3);"
            "lw         $t7, ($t3);"
            "addu       $t0, $t4;"
            "lw         $t1, ($t0);"
            "li         $t4, 0xE1000000;"
            "and        $t6, %1, 0x1FF;" // texpage
            "or         $t4, 0x200;" // dtd
            "or         $t4, $t6;"
            "sw         $t4, 4($t7);"
            "sw         $zero, 8($t7);"
            "li         $t5, 0xFFFFFF;"
            "li         $t4, 0x2000000;"
            "li         $t6, 0xFF000000;"
            "and        $t2, $t1, $t5;"
            "or         $t4, $t2;"
            "sw         $t4, ($t7);"
            "and        $t2, $t1, $t6;"
            "and        $t4, $t7, $t5;"
            "or         $t4, $t2;"
            "sw         $t4, ($t0);"
            "addu       $t2, $t7, 0xC;"
            "sw         $t2, ($t3);"
            :
            : "r"(primIndex), "r"(tpage)
            : "t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7");
}

static void func_80104204(int arg0, int arg1, int arg2, int arg3, int arg4)
{
    static char const D_80102BD8[][4] = { { 0, 0x20, 0x50, 0 }, { 0x19, 0x82, 0x6C, 0 },
        { 0x40, 0x30, 0x66, 0 }, { 0x40, 0x38, 0x20, 0 } };
    static char const D_80102BE8[][4] = { { 0, 0x5, 0x33, 0 }, { 0x1, 0x28, 0x26, 0 },
        { 0x8, 0x8, 0x20, 0 }, { 0x10, 0x10, 0x8, 0 } };
    POLY_G4* poly;
    void** p;

    poly = *(POLY_G4**)getScratchAddr(0);
    setPolyG4(poly);
    setXY4(poly, arg0, arg1, (arg0 + arg2) - 1, arg1, arg0, (arg1 + arg3) - 1,
        (arg0 + arg2) - 1, (arg1 + arg3) - 1);
    setRGB0(poly, D_80102BD8[arg4][0], D_80102BD8[arg4][1], D_80102BD8[arg4][2]);
    setRGB1(poly, D_80102BE8[arg4][0], D_80102BE8[arg4][1], D_80102BE8[arg4][2]);
    setRGB2(poly, D_80102BD8[arg4][0], D_80102BD8[arg4][1], D_80102BD8[arg4][2]);
    setRGB3(poly, D_80102BE8[arg4][0], D_80102BE8[arg4][1], D_80102BE8[arg4][2]);

    p = (void**)getScratchAddr(0);
    AddPrim(p[1] + 0x1C, poly++);
    p[0] = poly;
    _insertTpage(7, 96);
}

static void func_8010435C()
{
    int sp10[4];
    int sp20[16];
    D_80102C54_t* var_v0;
    int j;
    int i;
    D_80102C54_t* var_v1;
    POLY_FT4* poly;
    TILE* tile;

    *(D_80102C48_t*)sp10 = D_80102C48;

    var_v1 = (D_80102C54_t*)sp20;
    var_v0 = D_80102C54;

    do {
        *var_v1++ = *var_v0++;
    } while (var_v0 != (D_80102C54 + 4));

    _drawPaginationArrow(arrowTypeUp);
    poly = *(void**)getScratchAddr(0);

    for (i = 0; i < 16; ++i) {
        for (j = 0; j < 3; ++j) {
            setPolyFT4(poly);
            setXY4(poly, j << 7, i + 52, sp10[j] + (j << 7), i + 52, j << 7, i + 53,
                sp10[j] + (j << 7), i + 53);
            setUV4(poly, 0, i + 52, sp10[j], i + 52, 0, i + 53, sp10[j], i + 53);
            setClut(poly, 768, 227);
            poly->tpage = (j + 32) | 128 | (640 >> 6) | (256 >> 4);
            setSemiTrans(poly, 1);
            setRGB0(poly, sp20[i], sp20[i], sp20[i]);
            AddPrim(*(u_long**)getScratchAddr(1) - 7, poly++);
        }
    }

    tile = (TILE*)poly;
    for (i = 0; i < 16; ++i) {
        setTile(&tile[i]);
        setSemiTrans(&tile[i], 1);
        setXY0(&tile[i], 0, i + 52);
        setWH(&tile[i], 320, 1);
        setRGB0(&tile[i], sp20[i], sp20[i], sp20[i]);
        AddPrim(*(u_long**)getScratchAddr(1) - 7, &tile[i]);
    }

    *(void**)getScratchAddr(0) = (void*)poly + 0x100;
    _insertTpage(-7, 64);
}

void func_80104620()
{
    int sp10[4];
    int sp20[16];
    D_80102C54_t* var_v0;
    int j;
    int i;
    D_80102C54_t* var_v1;
    POLY_FT4* poly;
    TILE* tile;

    *(D_80102C48_t*)sp10 = D_80102C48;

    var_v1 = (D_80102C54_t*)sp20;
    var_v0 = D_80102C54;

    do {
        *var_v1++ = *var_v0++;
    } while (var_v0 != (D_80102C54 + 4));

    _drawPaginationArrow(arrowTypeDown);

    poly = *(void**)getScratchAddr(0);

    for (i = 0; i < 16; ++i) {
        for (j = 0; j < 3; ++j) {
            setPolyFT4(poly);
            setXY4(poly, j << 7, 0xBB - i, sp10[j] + (j << 7), 0xBB - i, j << 7, 0xBC - i,
                sp10[j] + (j << 7), 0xBC - i);
            setUV4(
                poly, 0, -0x45 - i, sp10[j], -0x45 - i, 0, -0x44 - i, sp10[j], -0x44 - i);
            setClut(poly, 768, 227);
            poly->tpage = (j + 32) | 128 | (640 >> 6) | (256 >> 4);
            setSemiTrans(poly, 1);
            setRGB0(poly, sp20[i], sp20[i], sp20[i]);
            AddPrim(*(u_long**)getScratchAddr(1) - 7, poly++);
        }
    }

    tile = (TILE*)poly;

    for (i = 0; i < 16; ++i) {
        setTile(&tile[i]);
        setSemiTrans(&tile[i], 1);
        setXY0(&tile[i], 0, 0xBB - i);
        setWH(&tile[i], 320, 1);
        setRGB0(&tile[i], sp20[i], sp20[i], sp20[i]);
        AddPrim(*(u_long**)getScratchAddr(1) - 7, &tile[i]);
    }

    *(void**)getScratchAddr(0) = (void*)poly + 0x100;
    _insertTpage(-7, 64);
}

static void _drawPaginationArrow(enum arrowType_e arrowType)
{
    int y;
    POLY_FT4* poly;
    u_long** p;

    if (arrowType != arrowTypeUp) {
        if (_pageArrowAnimState < 9) {
            y = (_pageArrowAnimState >> 1) + 184;
        } else {
            y = -(_pageArrowAnimState >> 2) + 190;
        }
    } else {
        if (_pageArrowAnimState < 9) {
            int v0 = 40;
            y = v0 - (_pageArrowAnimState >> 1);
        } else {
            y = (_pageArrowAnimState >> 2) + 34;
        }
    }

    poly = (POLY_FT4*)*getScratchAddr(0);
    setPolyFT4(poly);
    setShadeTex(poly, 1);
    setXY4(poly, 152, y, 168, y, 152, y + 16, 168, y + 16);
    setUV4(poly, arrowType * 16, 48, arrowType * 16 + 16, 48, arrowType * 16, 64,
        arrowType * 16 + 16, 64);
    setTPage(poly, clut4Bit, semiTransparencyHalf, 768, 0);

    if (vs_main_buttonsPreviousState & PADRleft) {
        setClut(poly, 896, 223);
    } else {
        setClut(poly, 912, 223);
    }
    p = (u_long**)getScratchAddr(0);
    AddPrim(p[1] - 7, poly++);
    p[0] = (void*)poly;
}

static void func_80104A44()
{
    short var_a1;
    short i;
    short* var_s0;
    int var_v0;
    int var_v1;
    LINE_F2* line;
    short s4;
    char* c;

    if (D_80105254[2] <= 0) {
        return;
    }

    line = *(LINE_F2**)getScratchAddr(0);

    var_v1 = D_80105254[0];
    if (var_v1 < 0) {
        var_v1 += 3;
    }
    var_v1 >>= 2;

    var_v0 = D_80105254[1];
    if (var_v0 < 0) {
        var_v0 += 3;
    }

    var_v0 = var_v1 + (var_v0 >> 2);
    var_s0 = (short*)&(D_80105254)[var_v0 + 4];

    s4 = *var_s0++;

    for (i = 0; i < s4; ++i) {
        var_a1 = 0;
        if (*var_s0 != 0) {
            var_a1 = func_80104C30(var_s0);
        }
        var_s0 += 8;
        setLineF2(line);
        line->x0 = *var_s0++ + 13;
        line->y0 = *var_s0++ + 55 - D_80105244 * 13;
        line->x1 = *var_s0++ + 13;
        line->y1 = *var_s0++ + 55 - D_80105244 * 13;
        c = (char*)var_s0;
        setRGB0(line, c[0], c[1], c[2]);
        var_s0 += 2;
        if ((line->y0 < 55) && ((line->y1 >= 55) == 0)) {
            continue;
        }
        if (((line->y0 < 186) || (line->y1 < 186)) && ((var_a1 << 16) == 0)) {
            AddPrim(*(void**)getScratchAddr(1), line++);
        }
    }
    *(void**)getScratchAddr(0) = line;
}

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

static void _drawControlsBg(int x, int y, int w, int h)
{
    int i;
    int j;
    LINE_G2* line;
    POLY_F4* poly;
    u_long** p;

    line = (LINE_G2*)*getScratchAddr(0);
    for (i = y, j = w; i < (y + h) - 1; ++i, --j) {
        setLineG2(line);
        setXY2(line, x, i, (x + j) - 1, i);
        setRGB0(line, 64, 56, 32);
        setRGB1(line, 16, 16, 8);
        AddPrim(*(u_long**)getScratchAddr(1) + 7, line++);
    }
    x += 2;
    y += 2;
    poly = (POLY_F4*)line;
    setPolyF4(poly);
    setXY4(poly, x, y, (x + w) - 1, y, x, (y + h) - 1, (x + w) - h, (y + h) - 1);
    setRGB0(poly, 0, 0, 0);

    p = (u_long**)getScratchAddr(0);
    AddPrim(p[1] + 7, poly);
    p[0] = (u_long*)(poly + 1);
}

INCLUDE_RODATA("build/src/MENU/MENUE.PRG/nonmatchings/494", D_80102BF8);

INCLUDE_RODATA("build/src/MENU/MENUE.PRG/nonmatchings/494", D_80102C08);

INCLUDE_RODATA("build/src/MENU/MENUE.PRG/nonmatchings/494", D_80102C10);

INCLUDE_RODATA("build/src/MENU/MENUE.PRG/nonmatchings/494", D_80102C18);

INCLUDE_RODATA("build/src/MENU/MENUE.PRG/nonmatchings/494", D_80102C20);

INCLUDE_RODATA("build/src/MENU/MENUE.PRG/nonmatchings/494", jtbl_80102C28);

INCLUDE_RODATA("build/src/MENU/MENUE.PRG/nonmatchings/494", D_80102C48);

INCLUDE_RODATA("build/src/MENU/MENUE.PRG/nonmatchings/494", D_80102C54);
