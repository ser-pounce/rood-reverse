#include "common.h"
#include "src/SLUS_010.40/main.h"
#include "src/SLUS_010.40/31724.h"
#include "src/SLUS_010.40/32154.h"
#include "build/src/include/lbas.h"
#include "gpu.h"
#include <libapi.h>
#include <libetc.h>
#include <stdio.h>

typedef struct {
    int unk0;
    void* unk4;
    void* unk8;
    void* unkC;
    void* unk10;
} func_8006DF70_t;

typedef struct D_800DBB88_t {
    void (*unk0)(struct D_800DBB88_t*);
    int unk4;
    short unk8;
    short unkA;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
} D_800DBB88_t;

typedef struct {
    int unk0;
    int unk4;
    short unk8;
    u_short unkA;
} func_8006A3BC_t;

typedef struct {
    int unk0;
    int unk4;
    short unk8;
    u_short unkA;
    u_short unkC;
    u_short unkE;
} func_8006A438_t;

typedef struct {
    u_char unk0[0x52];
    u_char unk52;
    u_char unk53[0x3F];
    u_char unk92;
    u_char unk93[7];
    u_char unk9A;
    u_char unk9B;
    u_char unk9C;
    u_char unk9D;
    u_char unk9E;
    u_char unk9F;
    u_char unkA0;
    u_char unkA1;
    u_char unkA2;
    u_char unkA3;
    u_char unkA4;
    u_char unkA5;
    u_char unkA6;
    u_char unkA7;
    u_char unkA8;
    u_char unkA9;
    u_char unkAA;
    u_char unkAB[7];
    u_char unkB2;
    u_char unkB3;
    u_short unkB4;
    u_short unkB6;
    u_short unkB8;
    u_char unkBA;
    u_char unkBB;
    u_char unkBC[22];
    u_char unkD2;
} D_800DB814_t;

void func_8006B9B4(void);
void func_8006A0D8(D_800DBB88_t* arg0);
void _setDrawEnv(DRAWENV*);
void func_8006A4D8(D_800DBB88_t*);
void func_8006A888(void);
void* _insertTpage(int arg0, int arg1);
void func_8006A9C0(int*);
void func_8006AA6C(void);
int func_8006AAA0(void);
D_800DBB88_t* func_8006AB44(void (*arg0)(D_800DBB88_t*)) __attribute__((noreturn));
void func_8006ABF0(void);
void func_8006AF64(void);
void func_8006B450(int, int, int, int, int, int);
int func_8006B6A4(u_long*);
void func_8006B884(void);
int func_8006AE54(short, short, short);
static void _updateClearGameStats(void);
void func_8006B930(void);
void func_8006B9DC(void);
void func_8006BD78(void);
int func_8006BE04(void);
int func_8006C214(void);
void func_8006C3CC(int);
void func_8006C514(int arg0, int arg1, int arg2);
void func_8006C5C8(int, int, int, int);
void func_8006C744(int, int, int, int);
void func_8006C9A8(int arg0, int arg1, int arg2, int arg3);
void func_8006CAF4(int, int, int, int);
void func_8006CD38(int arg0, int arg1, int arg2);
void func_8006CD94(int, int, int);
void func_8006CF24(int, int, int, char*);
void func_8006D358(int, int, int, P_CODE*);
void func_8006DA18(int, int, int, P_CODE*, int);

extern void* D_1F800000[];

extern char D_800688A4;
extern char D_800688AC;
extern int D_8006E3FC;
extern u_char D_8006FF7C[];
extern int D_8007005C;
extern int D_8007709C;
extern int D_80088ABC;
extern int D_8009A4DC;
extern int D_800ABEFC;
extern int D_800BD91C;
extern int D_800CF33C;
extern int D_800D7F7C;
extern int D_800D837C;
extern int D_800D975C;
extern int D_800DB09C;
extern int D_800DB26C;
extern int _countableRooms[];
extern u_char D_800DB72C;
extern int _illustLbas[];
extern int _illustSizes[];
extern D_800DB814_t D_800DB814;
extern u_char D_800DB876;
extern char D_800DBA88[];
extern P_CODE D_800DBA90[];
extern char D_800DBA98[];
extern P_CODE D_800DBAA0[];
extern u_char D_800DBAA8[];
extern short D_800DBAB8[];
extern u_int D_800DBAD8[];
extern D_800DBB88_t D_800DBB88[];
extern D_800DBB88_t D_800DBBB8[];
extern u_char D_800DC188;
extern u_char D_800DC189;
extern u_char D_800DC18A;
extern int D_800DC18C;
extern int D_800DC190;
extern int* D_800DC194;
extern short D_800DC198;
extern short D_800DC19A;
extern u_short D_800DC19C;
extern int D_800DC1A0;
extern int D_800DC1A4;
extern void* D_800DC1A8[];
extern u_int D_800DC1F0;
extern u_int D_800DC1F8;
extern int D_800DC1FC;
extern u_int D_800DC200;
extern int D_800DC204;
extern int D_800DC208;
extern int D_800DC20C;
extern int D_800DC210;
extern int D_800DC214;
extern int D_800DC218;

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_800688D4);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_80068938);

// https://decomp.me/scratch/UJsTy
void func_80068EBC(D_800DBB88_t* arg0);
INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_80068EBC);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_80069088);

int _inverseDistanceFromScreencenter(int arg0, int arg1)
{
    arg0 -= 0xA0;
    arg1 -= 0x70;
    return vs_gte_rsqrt(arg0 * arg0 + arg1 * arg1);
}

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_80069388);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_80069730);

int func_80069AEC(u_char* arg0)
{
    short var_a1;
    short i;
    unsigned short var_a2;
    short temp_v0;
    int temp_v1;
    int new_var;

    temp_v0 = *arg0++;
    var_a1 = 0;
    var_a2 = 0;
    i = 0;

    for (i = 0; i < temp_v0; ++i, ++arg0) {
        temp_v1 = *arg0;
        if (temp_v1 < 32u) {
            switch (temp_v1) {
            case 1:
                var_a2 = 0;
                break;
            case 2:
                var_a2 = 0x70;
                break;
            case 31:
                --var_a1;
                break;
            }
        } else {
            var_a1 += D_8006FF7C[(var_a2 - (new_var = 32)) + temp_v1] + 0xFFFF;
        }
    }
    return var_a1;
}

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_80069BC0);

void func_80069F9C(D_800DBB88_t* arg0);
INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_80069F9C);

void func_8006A0D8(D_800DBB88_t* arg0 __attribute__((unused)))
{
    TILE* tile;
    POLY_G4* poly;
    SPRT* sprt;
    void** data;

    data = (void**)0x1F800000;

    sprt = data[0];
    SetSprt(sprt);
    setXY0(sprt, 0, 0xA);
    setUV0(sprt, 0, 0xA);
    setWH(sprt, 0x100, 0xCC);
    setClut(sprt, 780, 255);
    sprt->r0 = sprt->g0 = sprt->b0 = D_800DC19C;
    AddPrim(data[1] + 0x1FFC, sprt++);
    data[0] = sprt;

    sprt = (SPRT*)_insertTpage(0x2C, 0x7FF);
    SetSprt(sprt);
    setUV0(sprt, 0, 0xA);
    setXY0(sprt, 0x100, 0xA);
    setWH(sprt, 0x40, 0xCC);
    setClut(sprt, 780, 255);
    sprt->r0 = sprt->g0 = sprt->b0 = D_800DC19C;
    AddPrim(data[1] + 0x1FFC, sprt++);
    data[0] = sprt;

    poly = (POLY_G4*)_insertTpage(0x2D, 0x7FF);
    SetPolyG4(poly);
    poly->x0 = poly->x2 = 0;
    poly->x1 = poly->x3 = 0x140;
    poly->y0 = poly->y1 = 0xA;
    poly->y2 = poly->y3 = 0x1E;
    poly->r0 = poly->r1 = poly->g0 = poly->g1 = poly->b0 = poly->b1 = 0xFF;
    poly->r2 = poly->r3 = poly->g2 = poly->g3 = poly->b2 = poly->b3 = 0;
    setSemiTrans(poly, 1);
    AddPrim(data[1] + 8, poly++);

    SetPolyG4(poly);
    poly->x0 = poly->x2 = 0;
    poly->x1 = poly->x3 = 0x140;
    poly->y0 = poly->y1 = 0xC2;
    poly->y2 = poly->y3 = 0xD6;
    poly->r0 = poly->r1 = poly->g0 = poly->g1 = poly->b0 = poly->b1 = 0;
    poly->r2 = poly->r3 = poly->g2 = poly->g3 = poly->b2 = poly->b3 = 0xFF;
    setSemiTrans(poly, 1);
    AddPrim(data[1] + 8, poly++);

    tile = (TILE*)poly;
    SetTile(tile);
    tile->r0 = tile->g0 = tile->b0 = 0;
    setWH(tile, 0x140, 0xA);
    setXY0(tile, 0, 0);
    AddPrim(data[1] + 8, tile++);

    SetTile(tile);
    tile->r0 = tile->g0 = tile->b0 = 0;
    setWH(tile, 0x140, 0xA);
    setXY0(tile, 0, 0);
    AddPrim(data[1] + 8, tile++);

    SetTile(tile);
    tile->r0 = tile->g0 = tile->b0 = 0;
    setWH(tile, 0x140, 0xA);
    setXY0(tile, 0, 0xD6);
    AddPrim(data[1] + 8, tile++);
    data[0] = tile;

    data[0] = _insertTpage(0xC0, 2);
}

void func_8006A3BC(func_8006A3BC_t* arg0)
{
    if (arg0->unk8 == 1) {
        arg0->unkA = 0;
        arg0->unk8 = 2;
    }

    if (++arg0->unkA == 0x80) {
        D_800DC189 = 0;
        arg0->unk8 = -1;
    }

    D_800DC19C = (u_int)func_8006AE54(0, arg0->unkA, 128) >> 5;
}

void func_8006A438(func_8006A438_t* arg0)
{
    if (arg0->unk8 == 1) {
        arg0->unk8 = 2;
        arg0->unkA = 0;
        D_800DC189 = 1;
    }

    if (++arg0->unkA == 128) {
        if (arg0->unkE != 0) {
            D_800DC188 = 1;
        }
        arg0->unk8 = -1;
    }

    D_800DC19C = 128 - ((func_8006AE54(0, arg0->unkA, 128) << 7) >> 0xC);
}

void func_8006A4D8(D_800DBB88_t* arg0)
{
    void** s2 = (void**)0x1F800000;
    TILE* temp_s0 = s2[0];

    if (arg0->unk8 == 1) {
        arg0->unkA = 0;
        arg0->unk8 = 2;
    }

    if (++arg0->unkA == 128u) {
        D_800DC188 = 1;
    }

    SetTile(temp_s0);
    setSemiTrans(temp_s0, 1);
    temp_s0->r0 = temp_s0->g0 = temp_s0->b0 =
        (func_8006AE54(1, arg0->unkA, 128) * 255) >> 0xC;
    setWH(temp_s0, 320, 240);
    setXY0(temp_s0, 0, 0);

    AddPrim(s2[1], temp_s0++);

    s2[0] = temp_s0;
    s2[0] = _insertTpage(0x40, 0);
}

void func_8006A5C0(void)
{
    vs_main_CdFile file;
    short i;
    vs_main_CdQueueSlot* slot;

    func_8006B884();
    SetGeomOffset(0xA0, 0x70);
    SetGeomScreen(0x200);
    _setDrawEnv(vs_main_drawEnv);
    _setDrawEnv(&vs_main_drawEnv[1]);
    vs_main_dispEnv[1].isinter = 0;
    vs_main_dispEnv[0].isinter = 0;
    func_8006A9C0(&D_8007005C);
    func_8006A9C0(&D_800CF33C);
    func_8006A9C0(&D_800D7F7C);
    func_8006A9C0(&D_800D975C);
    func_8006A9C0(&D_800D837C);
    func_8006A9C0(&D_800DB09C);
    func_8006A9C0(&D_800DB26C);
    func_8006A9C0(&D_8007709C);
    func_8006A9C0(&D_80088ABC);
    func_8006A9C0(&D_8009A4DC);
    func_8006A9C0(&D_800ABEFC);
    func_8006A9C0(&D_800BD91C);

    for (i = 5; i < 16; ++i) {
        file.lba = _illustLbas[i - 5];
        file.size = _illustSizes[i - 5];
        D_800DC1A8[i] = vs_main_allocHeapR(file.size);
        slot = vs_main_allocateCdQueueSlot(&file);
        vs_main_cdEnqueuePriority(slot, D_800DC1A8[i]);

        do {
            vs_main_gametimeUpdate(0);
        } while (slot->state != 4);

        vs_main_freeCdQueueSlot(slot);
    }
    D_800DC19C = 0;
    D_800DC18A = 0;
    func_8006AA6C();
    func_8006AB44(&func_8006A0D8);
    DrawSync(0);
    SetDispMask(1);
    D_800DC194 = &D_8006E3FC;
    D_800DC198 = -0x80;
    D_800DC188 = 0;
    D_800DC190 = 0;
    D_800DC18C = 0;
    D_800DC189 = 1;
    func_8006B9B4();
    func_8006A888();
    vs_main_checkStreamXaEnd();
    SetDispMask(0);
    for (i = 5; i < 16; ++i) {
        vs_main_freeHeapR(D_800DC1A8[i]);
    }
    func_8006B9DC();
    _updateClearGameStats();
    func_8006BD78();
}

void _setDrawEnv(DRAWENV* drawenv)
{
    drawenv->isbg = 1;
    drawenv->dtd = 0;
    drawenv->dfe = 0;
    drawenv->b0 = 0;
    drawenv->g0 = 0;
    drawenv->r0 = 0;
    drawenv->tpage = 0x20;
}

void func_8006A888(void)
{
    while (D_800DC188 == 0) {
        D_800DC19A = VSync(1);
        func_8006B930();
        func_8006ABF0();
        func_8006AAA0();
        func_8006AF64();
        if ((vs_main_buttonsPressed.all & 0x800) && (D_800DC18A == 0)) {
            func_8006AB44(func_8006A4D8);
            D_800DC18A = 1;
        }
        func_8006B6A4(*(u_long**)0x1F800004 + 0x7FF);
        D_800DC18C += 1;
    }
}

void* _insertTpage(int arg0, int arg1)
{
    void** temp_s0;
    DR_TPAGE* tpage;

    temp_s0 = (void**)0x1F800000;
    tpage = temp_s0[0];
    SetDrawTPage(tpage, 0, 1, arg0 & 0xFFFF);
    AddPrim(temp_s0[1] + (arg1 * 4), tpage++);
    return tpage;
}

void func_8006A9C0(int* arg0)
{
    RECT rect;
    short* p = (short*)(arg0 + 2);

    if (arg0[1] & 8) {
        rect.x = p[2];
        rect.y = p[3];
        rect.w = p[4];
        rect.h = p[5];
        LoadImage(&rect, (u_long*)(arg0 + 5));
        p = (short*)((char*)arg0 + (arg0[2] + 8));
    }
    rect.x = p[2];
    rect.y = p[3];
    rect.w = p[4];
    rect.h = p[5];
    LoadImage(&rect, (u_long*)((char*)p + 0xC));
}

void func_8006AA6C(void)
{
    short i;
    D_800DBB88_t* var_v1 = D_800DBB88;
    for (i = 0; i < 32; ++i, ++var_v1) {
        var_v1->unk8 = 0;
    }
}

int func_8006AAA0(void)
{
    short i;
    short var_s3 = 0;
    D_800DBB88_t* var_s0 = D_800DBB88;

    for (i = 0; i < 32; ++i, ++var_s0) {
        if (var_s0->unk8 < 0) {
            var_s0->unk8 = 0;
        } else if (var_s0->unk8 > 0) {
            ++var_s3;
            var_s0->unk0(var_s0);
        }
    }

    return var_s3;
}

D_800DBB88_t* func_8006AB44(void (*arg0)(D_800DBB88_t*))
{
    short i;
    D_800DBB88_t* var_v1 = D_800DBBB8;

    for (i = 1; i < 32; ++i, var_v1 += 1) {
        if (var_v1->unk8 == 0) {
            var_v1->unk0 = arg0;
            var_v1->unk8 = 1;
            var_v1->unkA = 0;
            return var_v1;
        }
    }

    SystemError('M', 100);
}

D_800DBB88_t* func_8006ABBC(void (*arg0)(D_800DBB88_t*))
{
    if (D_800DBB88[0].unk8 == 0) {
        D_800DBB88[0].unk0 = arg0;
        D_800DBB88[0].unk8 = 1;
        D_800DBB88[0].unkA = 0;
        return D_800DBB88;
    }
    return NULL;
}

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006ABF0);

int func_8006AE54(short arg0, short arg1, short arg2)
{
    switch (arg0) {
    case 0:
        return (arg1 * ONE) / arg2;
    case 1:
        return rsin((arg1 * (ONE / 4)) / arg2);
    case 2:
        return (rcos(((arg1 * (ONE / 2)) / arg2) + (ONE / 2)) + ONE) >> 1;
    case 3:
        return rsin(((arg1 * (ONE / 4)) / arg2) - (ONE / 4)) + ONE;
    }
}

void func_8006AF44(int arg0, int arg1)
{
    D_800DB72C = 1;
    D_800DC1A0 = arg1;
    D_800DC1A4 = arg0;
}

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006AF64);

void func_8006B324(short arg0, short arg1, int arg2, u_char* arg3)
{
    int temp_v0;
    u_char var_v1_2;
    int var_v1;
    SPRT_8* var_a2;
    u_long** t4;

    var_v1 = *arg3;
    var_a2 = *(void**)0x1F800000;

    while (var_v1 != 0) {

        temp_v0 = var_v1 - 32;
        var_v1_2 = temp_v0;

        if (((temp_v0 & 0xFF) < 96u) && (var_v1_2 != 0)) {

            if (var_v1_2 == 60) {
                var_v1_2 = 15;
            }

            if (var_v1_2 > 64) {
                var_v1_2 -= 32;
            }

            setSprt8(var_a2);
            setShadeTex(var_a2, 1);
            setXY0(var_a2, arg0, arg1);
            setUV0(var_a2, (var_v1_2 & 0xF) * 8, (var_v1_2 & 0xF0) / 2);
            setClut(var_a2, 960, arg2 + 32);

            t4 = (u_long**)0x1F800000;
            setaddr(var_a2, *t4[1] & 0xFFFFFF);
            setaddr(t4[1], var_a2);

            ++var_a2;
        }

        ++arg3;
        var_v1 = *arg3;
        arg0 += 7;
    }

    *(void**)0x1F800000 = var_a2;
    *(void**)0x1F800000 = _insertTpage(0xF, 0);
}

void func_8006B450(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5)
{
    RECT rect;
    int temp_s1;

    rect = (RECT) { 0, 0, 1024, 512 };

    SetDispMask(0);
    SetGeomOffset(arg0 / 2, (arg1 + (int)((u_int)arg1 >> 0x1F)) >> 1);
    SetGeomScreen(arg2);

    temp_s1 = arg1 - 0x10;

    SetDefDrawEnv(vs_main_drawEnv, 0, 0, arg0, temp_s1);
    SetDefDispEnv(vs_main_dispEnv, arg0, 0, arg0, temp_s1);
    SetDefDrawEnv(&vs_main_drawEnv[1], arg0, 0, arg0, temp_s1);
    SetDefDispEnv(&vs_main_dispEnv[1], 0, 0, arg0, temp_s1);

    setRECT(&vs_main_dispEnv[0].screen, 0, 8, 256, 224);
    setRECT(&vs_main_dispEnv[1].screen, 0, 8, 256, 224);

    D_8005DFD4 = 0;
    D_8005DFD8 = 0;
    D_8005DFD6 = arg0;
    D_8005DFDA = temp_s1;
    vs_main_drawEnv[1].dtd = 0;
    vs_main_drawEnv[0].dtd = 0;
    vs_main_drawEnv[1].isbg = 1;
    vs_main_drawEnv[0].isbg = 1;
    setRGB0(&vs_main_drawEnv[0], arg3, arg4, arg5);
    setRGB0(&vs_main_drawEnv[1], arg3, arg4, arg5);

    ClearImage(&rect, 0, 0, 0);
    DrawSync(0);
    FntLoad(0x3C0, 0);
    SetDumpFnt(FntOpen(0x28, 0x10, 0x200, 0x100, 0, 0x200));
    PutDispEnv(&vs_main_dispEnv[vs_main_frameBuf]);
    PutDrawEnv(&vs_main_drawEnv[vs_main_frameBuf]);

    vs_main_frameDuration = 0;
}

int func_8006B6A4(u_long* arg0)
{
    int _[2];
    int temp_s1;

    vs_main_frameBuf = vs_main_frameBuf == 0;

    DrawSync(0);

    temp_s1 = vs_main_gametimeUpdate(0);

    PutDispEnv(&vs_main_dispEnv[vs_main_frameBuf]);
    PutDrawEnv(&vs_main_drawEnv[vs_main_frameBuf]);
    DrawOTag(arg0);

    ++vs_main_frameDuration;

    return temp_s1;
}

static void _updateTitles(void);

static void _do_updateClearGameStats(void)
{
    int i;

    if (vs_main_scoredata.completionTimeMinutes == 0) {
        vs_main_scoredata.clearCount = vs_main_stateFlags.clearCount;
        vs_main_scoredata.completionTimeMinutes =
            (vs_main_gametime.t.h * 60) + vs_main_gametime.t.m;
    } else {
        int minutes = (vs_main_gametime.t.h * 60) + vs_main_gametime.t.m;
        if (minutes < vs_main_scoredata.completionTimeMinutes) {
            vs_main_scoredata.completionTimeMinutes = minutes;
            vs_main_scoredata.clearCount = vs_main_stateFlags.clearCount;
        }
    }

    _updateTitles();
    vs_main_bzero(&vs_main_mapStatus, sizeof vs_main_mapStatus);

    for (i = 0x10; i < 0x440; ++i) {
        ((u_char*)&vs_main_stateFlags)[i] = 0;
    }

    if (vs_main_stateFlags.difficulty != 0) {
        vs_main_stateFlags.normalModeCleared = 1;
    } else {
        vs_main_stateFlags.difficulty = 1;
    }

    if (vs_main_stateFlags.clearCount < 99) {
        ++vs_main_stateFlags.clearCount;
    }

    D_80061068.zndId = 1;
    D_80061068.mpdId = 0;
}

void func_8006B884(void)
{
    func_8006B450(0x140, 0xF0, 0x200, 0, 0, 0);
    vs_main_initHeap((vs_main_HeapHeader*)0x8010C000, 0xF2000);
    D_8005E0C0[0] = vs_main_allocHeap(0x20000);
    D_8005E0C0[1] = vs_main_allocHeap(0x20000);
    D_80055C80[0] = vs_main_allocHeap(0x2088);
    D_80055C80[1] = vs_main_allocHeap(0x2088);
}

static void _updateClearGameStats(void) { _do_updateClearGameStats(); }

void func_8006B930(void)
{
    void* temp_a0;

    vs_main_processPadState();
    temp_a0 = D_80055C80[vs_main_frameBuf];
    D_1F800000[2] = temp_a0 + 8;
    D_1F800000[1] = temp_a0 + 0x48;
    ClearOTagR((u_long*)temp_a0, 0x822);
    D_1F800000[0] = D_8005E0C0[vs_main_frameBuf];
}

void func_8006B9B4(void)
{
    vs_main_streamXa(VS_ENDING_XA_LBA, 0x7FFF); // Partial playback?
}

void func_8006B9DC(void) { vs_main_checkStreamXaEnd(); }

static void _updateTitles(void)
{
    int i;
    int j;
    u_int count;

    if (vs_main_scoredata.completionTimeMinutes < 600) {
        vs_main_scoredata.titles |= 2;
    }

    for (i = 184; i < 224; ++i) {
        if (!vs_main_skills[i].unlocked) {
            break;
        }
    }

    if (i == 224) {
        vs_main_scoredata.titles |= 1 << 14;
    }

    for (i = 22; i < 54; ++i) {
        if ((i != 33) && (i != 36) && (i != 38) && (i != 39)
            && !vs_main_skills[i].unlocked) {
            break;
        }
    }

    if (i == 54) {
        vs_main_scoredata.titles |= 1 << 15;
    }

    if (vs_main_settings.currentGameSaveCount == 0) {
        vs_main_scoredata.titles |= 1 << 16;
    }

    if (vs_main_stateFlags.magicUsed == 0) {
        vs_main_scoredata.titles |= 1 << 17;
    }

    if (vs_main_stateFlags.battleAbilitiesUsed == 0) {
        vs_main_scoredata.titles |= 1 << 18;
    }

    if (vs_main_stateFlags.breakArtsUsed == 0) {
        vs_main_scoredata.titles |= 1 << 19;
    }

    count = 0;

    for (i = 0; i < 16; ++i) {
        int t1 = 1;
        for (j = 0; j < 32; ++j) {
            if (vs_main_mapStatus.roomFlags[i] & _countableRooms[i] & (t1 << j)) {
                ++count;
            }
        }
    }

    if (vs_main_scoredata.mapCompletion < count) {
        vs_main_scoredata.mapCompletion = count;
    }

    count = 0;

    for (i = 0; i < 64; ++i) {
        if (vs_main_stateFlags.chestsOpened[i] != 0) {
            ++count;
        }
    }

    if (vs_main_scoredata.openedChestCount < count) {
        vs_main_scoredata.openedChestCount = count;
    }

    if (vs_main_stateFlags.damascusGolemDefeated != 0) {
        vs_main_scoredata.titles |= 1 << 4;
    }

    if (vs_main_stateFlags.damascusCrabDefeated != 0) {
        vs_main_scoredata.titles |= 1 << 5;
    }

    if (vs_main_stateFlags.ravanaDefeated != 0) {
        vs_main_scoredata.titles |= 1 << 6;
    }

    if (vs_main_stateFlags.dragonZombieDefeated != 0) {
        vs_main_scoredata.titles |= 1 << 7;
    }

    if (vs_main_stateFlags.deathAndOgreZombieDefeated != 0) {
        vs_main_scoredata.titles |= 1 << 8;
    }

    if (vs_main_stateFlags.asuraDefeated != 0) {
        vs_main_scoredata.titles |= 1 << 9;
    }

    if (vs_main_stateFlags.goldKeyObtained != 0) {
        vs_main_scoredata.titles |= 1 << 12;
    }

    if (vs_main_stateFlags.chestKeyObtained != 0) {
        vs_main_scoredata.titles |= 1 << 13;
    }
}

void func_8006BD78(void)
{
    int temp_s0;

    D_800DC208 = 0;
    SetDispMask(1);

    do {
        func_8006B930();
        temp_s0 = func_8006BE04();
        func_8006B6A4(*(u_long**)0x1F800004 + 0x7FF);
    } while (temp_s0 == 0);

    do {
        func_8006B930();
        temp_s0 = func_8006C214();
        VSync(0);
        func_8006B6A4(*(u_long**)0x1F800004 + 0x7FF);
    } while (temp_s0 == 0);
}

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006BE04);

int func_8006C214(void)
{
    if (D_800DC210 == 0) {

        if (D_800DC20C == 0xD0) {
            vs_main_playSfxDefault(0x7E, 0x77);
            vs_main_playSfxDefault(0x7E, 0x78);
        }

        func_8006C3CC(D_800DC20C);
        func_8006C514(0xA0, 0x28, D_800DC20C);
        func_8006C744(0xA0, 0x50, D_800DC20C - 0x20, D_800DC210);
        func_8006CAF4(0xA0, 0x66, D_800DC20C - 0x70, D_800DC210);
        func_8006CD38(0xA0, 0x8A, D_800DC20C - 0xC0);
        func_8006CD94(0xA0, 0x9A, D_800DC20C - 0xD0);

        if (D_800DC20C >= 0x1001) {
            D_800DC20C = 0x1000;
        }

        if (vs_main_buttonsPressed.all != 0) {
            D_800DC210 = 1;
            D_800DC20C = 0;
        }

    } else {

        func_8006C3CC(8 - D_800DC20C);
        func_8006C514(0xA0, 0x28, 8 - D_800DC20C);
        func_8006C5C8(0xA0, 0x50, 8 - D_800DC20C, 3);
        func_8006C9A8(0xA0, 0x66, 8 - D_800DC20C, 3);
        func_8006CD38(0xA0, 0x8A, 8 - D_800DC20C);
        func_8006CD94(0xA0, 0x9A, 8 - D_800DC20C);

        if (D_800DC20C >= 8) {
            return 1;
        }
    }

    ++D_800DC20C;
    return 0;
}

// https://decomp.me/scratch/0FKMG
INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006C3CC);

extern P_CODE D_800DBA7C[2];

void func_8006C514(int arg0, int arg1, int arg2)
{
    if (arg2 < 0) {
        arg2 = 0;
    }

    if (arg2 > 64) {
        arg2 = 64;
    }

    if (arg2 > 0) {
        D_800DBA7C[0].code = arg2;
        D_800DBA7C[1].code = arg2;
        arg0 = arg0 - ((D_800DB814.unkB2 + D_800DB814.unkBA) >> 1);
        func_8006D358(arg0, arg1, 0x16, D_800DBA7C);
        func_8006D358(arg0 + D_800DB814.unkB2, arg1, 0x17, &D_800DBA7C[1]);
    }
}

void func_8006C5C8(int arg0, int arg1, int arg2, int arg3 __attribute__((unused)))
{
    char sp10[10];
    int i;
    int v0;
    int v1;

    if (arg2 < 0) {
        arg2 = 0;
    }

    if (arg2 > 64) {
        arg2 = 64;
    }

    if (arg2 > 0) {

        D_800DBA88[3] = arg2;

        sprintf(sp10, &D_800688A4, D_800DC1F8);

        v1 = D_800DB814.unk92 + D_800DB814.unkD2 + D_800DB814.unkA2;
        arg0 -= (D_800DB814.unk52 * 2 + v1 + 0x74) >> 1;

        func_8006CF24(arg0, arg1, 0x12, D_800DBA88);

        arg0 += D_800DB814.unk92;

        func_8006CF24(arg0, arg1 + 7, 0x1A, D_800DBA88);

        v0 = arg0 + 2;
        arg0 = v0 + D_800DB814.unkD2;

        for (i = 0; i < 9; ++i) {
            func_8006CF24(arg0, arg1 + 3, sp10[i] - 0x30, D_800DBA88);
            arg0 += 12;
            if ((i == 2) || (i == 5)) {
                int v0;
                func_8006CF24(arg0, arg1 + 0xE, 0xA, D_800DBA88);
                v0 = arg0 + 3;
                arg0 = v0 + D_800DB814.unk52;
            }
        }

        func_8006CF24(arg0, arg1 + 8, 0x14, D_800DBA88);
    }
}

void func_8006C744(int arg0, int arg1, int arg2, int arg3)
{
    char sp18[16];
    int temp_s2;
    int var_s1;
    int i;
    int v0;
    int v1;

    var_s1 = arg2;

    if (var_s1 < 0) {
        var_s1 = 0;
    }

    if (var_s1 >= 0x41) {
        var_s1 = 0x40;
    }

    if (var_s1 > 0) {
        temp_s2 = arg0 + (var_s1 * 8);

        if (D_800DC1F8 != 0 && var_s1 >= 32) {

            if (D_800DC204 == 0) {
                D_800DC214 = 1;
                vs_main_playSfxDefault(0x7E, 0x72);
            }

            if ((D_800DC204 == D_800DC1F8) && (D_800DC214 != 0)) {
                D_800DC214 = 0;
                func_80045D64(0x7E, 0x72);
                vs_main_playSfxDefault(0x7E, 0x73);
            }
        }

        if (var_s1 >= 32) {
            D_800DC204 = ((u_int)D_800DC1F8 >> 5) * (var_s1 - 32);
        }

        if (var_s1 == 64) {
            D_800DC204 = D_800DC1F8;
        }

        sprintf(sp18, &D_800688A4, D_800DC204);

        v1 = D_800DB814.unk92 + D_800DB814.unkD2 + D_800DB814.unkA2;
        arg0 -= (D_800DB814.unk52 * 2 + v1 + 0x74) >> 1;

        func_8006DA18(arg0, arg1, 0x12, D_800DBA90, temp_s2);

        arg0 += D_800DB814.unk92;

        func_8006DA18(arg0, arg1 + 7, 0x1A, D_800DBA90, temp_s2);

        v0 = arg0 + 2;
        arg0 = v0 + D_800DB814.unkD2;

        for (i = 0; i < 9; ++i) {
            func_8006DA18(arg0, arg1 + 3, sp18[i] - '0', D_800DBA90, temp_s2);
            arg0 += 12;
            if ((i == 2) || (i == 5)) {
                func_8006DA18(arg0, arg1 + 0xE, 0xA, D_800DBA90, temp_s2);
                arg0 += 3 + D_800DB814.unk52;
            }
        }

        func_8006DA18(arg0, arg1 + 8, 0x14, D_800DBA90, temp_s2);
    }
}

void func_8006C9A8(int arg0, int arg1, int arg2, int arg3 __attribute__((unused)))
{
    char sp10[2];
    int i;
    int v0;

    if (arg2 < 0) {
        arg2 = 0;
    }

    if (arg2 > 64) {
        arg2 = 64;
    }

    if (arg2 > 0) {

        D_800DBA98[3] = arg2;

        sprintf(sp10, &D_800688AC, D_800DC1FC);

        arg0 -= ((D_800DB814.unkAA + D_800DB814.unkD2 + D_800DB814.unk9A + 0x26) >> 1);

        func_8006CF24(arg0, arg1, 0x15, D_800DBA98);

        arg0 += D_800DB814.unkAA;

        func_8006CF24(arg0, arg1 + 7, 0x1A, D_800DBA98);

        v0 = arg0 + 2;
        arg0 = v0 + D_800DB814.unkD2;

        for (i = 0; i < 3; ++i) {
            func_8006CF24(arg0, arg1 + 3, sp10[i] - '0', D_800DBA98);
            arg0 += 12;
        }

        func_8006CF24(arg0, arg1 + 8, 0x13, D_800DBA98);
    }
}

void func_8006CAF4(int arg0, int arg1, int arg2, int arg3)
{
    char sp18[2];
    int temp_s4;
    int i;
    int v0;

    if (arg2 < 0) {
        arg2 = 0;
    }
    if (arg2 > 64) {
        arg2 = 64;
    }

    if (arg2 > 0) {

        temp_s4 = arg0 + arg2 * 8;

        if (D_800DC1FC != 0 && arg2 >= 32) {

            if (D_800DC200 == 0) {
                D_800DC218 = 1;
                vs_main_playSfxDefault(0x7E, 0x72);
            }

            if ((D_800DC200 == D_800DC1FC) && (D_800DC218 != 0)) {
                D_800DC218 = 0;
                func_80045D64(0x7E, 0x72);
                vs_main_playSfxDefault(0x7E, 0x73);
            }
        }

        if (arg2 >= 32) {
            if (D_800DC1FC >= 32u) {
                D_800DC200 = (u_int)(D_800DC1FC * (arg2 - 32)) >> 5;
            } else if (D_800DC200 < D_800DC1FC) {
                D_800DC200 += 1;
            }
        }

        sprintf(sp18, &D_800688AC, D_800DC200);

        arg0 -=
            ((int)(D_800DB814.unkAA + D_800DB814.unkD2 + D_800DB814.unk9A + 0x26) >> 1);

        func_8006DA18(arg0, arg1, 0x15, D_800DBAA0, temp_s4);

        arg0 += D_800DB814.unkAA;

        func_8006DA18(arg0, arg1 + 7, 0x1A, D_800DBAA0, temp_s4);

        v0 = arg0 + 2;
        arg0 = v0 + D_800DB814.unkD2;

        for (i = 0; i < 3; ++i) {
            func_8006DA18(arg0, arg1 + 3, sp18[i] - '0', D_800DBAA0, temp_s4);
            arg0 += 12;
        }

        func_8006DA18(arg0, arg1 + 8, 0x13, D_800DBAA0, temp_s4);
    }
}

void func_8006CD38(int arg0, int arg1, int arg2)
{
    if (arg2 < 0) {
        arg2 = 0;
    }
    if (arg2 > 0x40) {
        arg2 = 0x40;
    }
    if (arg2 > 0) {
        D_800DBAA8[3] = arg2;
        func_8006CF24(arg0 - (D_800DB876 >> 1), arg1, 0xC, D_800DBAA8);
    }
}

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006CD94);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006CF24);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006D358);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006DA18);

void func_8006DF70(u_int* arg0, func_8006DF70_t* arg1)
{

    ++arg0;
    arg1->unk0 = *arg0;
    ++arg0;
    if (arg1->unk0 & 8) {
        arg1->unk4 = arg0 + 1;
        arg1->unk8 = arg0 + 3;
        arg0 += *arg0 / 4;
    } else {
        arg1->unk4 = 0;
        arg1->unk8 = 0;
    }
    arg1->unkC = arg0 + 1;
    arg1->unk10 = arg0 + 3;
}

void func_8006DFD0(void)
{
    int var_a2;
    int var_v0;
    int i;

    for (i = 0, var_a2 = 0, var_v0 = 1; i < 16; ++i) {
        if (vs_main_scoredata.titles & (var_v0 << i)) {
            ++var_a2;
        }
    }

    for (i = 0; i < 16; ++i) {
        if (var_a2 >= D_800DBAB8[i]) {
            if (D_800DC1F8 >= D_800DBAD8[i]) {
                D_800DC1F0 = i;
                return;
            }
        }
    }
}

INCLUDE_RODATA("build/src/ENDING/ENDING.PRG/nonmatchings/D4", D_800688A4);

INCLUDE_RODATA("build/src/ENDING/ENDING.PRG/nonmatchings/D4", D_800688AC);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006E074);
