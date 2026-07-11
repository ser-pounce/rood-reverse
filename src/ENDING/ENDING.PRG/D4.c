#include "common.h"
#include "src/SLUS_010.40/main.h"
#include "src/SLUS_010.40/31724.h"
#include "src/SLUS_010.40/32154.h"
#include "build/src/include/lbas.h"
#include "gpu.h"
#include <libapi.h>

typedef struct {
    int unk0;
    void* unk4;
    void* unk8;
    void* unkC;
    void* unk10;
} func_8006DF70_t;

typedef struct {
    void (*unk0)(void);
    int unk4;
    short unk8;
    short unkA;
} D_800DBB88_t;

typedef struct {
    int unk0;
    int unk4;
    short unk8;
    u_short unkA;
} func_8006A3BC_t;

void func_8006B9B4(void);
void func_8006A0D8(void);
void _setDrawEnv(DRAWENV*);
void func_8006A888(void);
void* _insertTpage(int arg0, int arg1);
void func_8006A9C0(int*);
void func_8006AA6C(void);
D_800DBB88_t* func_8006AB44(void (*)(void));
void func_8006B884(void);
u_int func_8006AE54(int, short, int);
static void _updateClearGameStats(void);
void func_8006B9DC(void);
void func_8006BD78(void);
void func_8006CF24(int, int, int, char*);

extern int D_8006E3FC;
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
extern signed char D_800DB72C;
extern int _illustLbas[];
extern int _illustSizes[];
extern char D_800DB876;
extern char D_800DBAA8[];
extern D_800DBB88_t D_800DBB88[];
extern D_800DBB88_t D_800DBBB8[];
extern signed char D_800DC188;
extern signed char D_800DC189;
extern signed char D_800DC18A;
extern int D_800DC18C;
extern int D_800DC190;
extern int* D_800DC194;
extern short D_800DC198;
extern short D_800DC19C;
extern int D_800DC1A0;
extern int D_800DC1A4;
extern void* D_800DC1A8[];

// https://decomp.me/scratch/Y9v8c
INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_800688D4);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_80068938);

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

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_80069AEC);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_80069BC0);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_80069F9C);

void func_8006A0D8(void)
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

    D_800DC19C = func_8006AE54(0, arg0->unkA, 128) >> 5;
}

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006A438);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006A4D8);

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

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006A888);

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
    for (i = 0; i < 32; ++i, var_v1 += 4) {
        var_v1->unk8 = 0;
    }
}

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006AAA0);

D_800DBB88_t* func_8006AB44(void (*arg0)(void)) __attribute__((noreturn));
D_800DBB88_t* func_8006AB44(void (*arg0)(void))
{
    short i;
    D_800DBB88_t* var_v1 = D_800DBBB8;

    for (i = 1; i < 32; ++i, var_v1 += 4) {
        if (var_v1->unk8 == 0) {
            var_v1->unk0 = arg0;
            var_v1->unk8 = 1;
            var_v1->unkA = 0;
            return var_v1;
        }
    }

    SystemError('M', 100);
}

D_800DBB88_t* func_8006ABBC(void (*arg0)(void))
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

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006AE54);

void func_8006AF44(int arg0, int arg1)
{
    D_800DB72C = 1;
    D_800DC1A0 = arg1;
    D_800DC1A4 = arg0;
}

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006AF64);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006B324);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006B450);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006B6A4);

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

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006B884);

static void _updateClearGameStats(void) { _do_updateClearGameStats(); }

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006B930);

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

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006BD78);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006BE04);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006C214);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006C3CC);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006C514);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006C5C8);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006C744);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006C9A8);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006CAF4);

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

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006DFD0);

INCLUDE_RODATA("build/src/ENDING/ENDING.PRG/nonmatchings/D4", D_800688A4);

INCLUDE_RODATA("build/src/ENDING/ENDING.PRG/nonmatchings/D4", D_800688AC);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006E074);
