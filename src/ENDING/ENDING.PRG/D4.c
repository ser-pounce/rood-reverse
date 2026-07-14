#include "common.h"
#include "src/SLUS_010.40/main.h"
#include "src/SLUS_010.40/31724.h"
#include "src/SLUS_010.40/32154.h"
#include "build/src/include/lbas.h"
#include "gpu.h"
#include "texture_t.h"
#include <libapi.h>
#include <libetc.h>
#include <memory.h>
#include <stdio.h>

typedef struct _creditsElement {
    void (*renderer)(struct _creditsElement*);
    u_char* data;
    short state;
    u_short currentStep;
    u_short illustId;
    u_short width;
    int x;
    int y;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
} _creditsElement;

typedef struct {
    int unk0;
    u_char unk4;
    u_char unk5;
    u_char unk6;
    u_char unk7;
    short unk8;
    short unkA;
    short unkC;
    short unkE;
    u_char unk10;
    u_char unk11;
    u_char unk12;
    u_char unk13;
    short unk14;
    short unk16;
    short unk18;
    short unk1A;
    u_char unk1C;
    u_char unk1D;
    u_char unk1E;
    u_char unk1F;
    short unk20;
    short unk22;
    short unk24;
    short unk26;
    u_char unk28;
    u_char unk29;
    u_char unk2A;
    u_char unk2B;
    short unk2C;
    short unk2E;
} func_80069388_t;

typedef struct {
    int size;
    RECT rect;
    char data[0];
} func_8006A9C0_t;

typedef struct {
    u_char unk0;
    u_char unk1;
    u_char unk2;
    u_char unk3;
    int unk4;
    func_8006A9C0_t unk8;
} func_8006A9C0_t2;

enum easeMode {
    easeModeLinear,
    easeModeEaseOut,
    easeModeEaseInOut,
    easeModeEaseIn,
};

void _renderPhantomPain(_creditsElement* arg0);
void _renderVagrantStory(_creditsElement* arg0);
void _renderText(_creditsElement* arg0);
static void func_8006B9B4(void);
static void _setDrawEnv(DRAWENV*);
static void func_8006A888(void);
static void* _insertTpage(int tPage, int otOffset);
static void func_8006A9C0(func_8006A9C0_t2*);
static void _resetElements(void);
static int _renderElements(void);
static _creditsElement* _addRenderer(void (*arg0)(_creditsElement*))
    __attribute__((noreturn));
static void _parseCreditsScript(void);
static void func_8006AF44(func_8006A9C0_t2* arg0, void* arg1);
void func_8006AF64(void);
static int _drawScreen(u_long*);
static void func_8006B884(void);
static int _ease(short mode, short currentStep, short totalSteps);
static void _updateClearGameStats(void);
static void func_8006B930(void);
static void _checkStreamXaEnd(void);
static void func_8006BD78(void);
static int func_8006BE04(void);
static int _renderCongratulationsScreen(void);
void func_8006C3CC(int);
static void _renderCongratulations(int arg0, int arg1, int arg2);
static void _renderScore(int, int, int, int);
static void _renderIncrementalScore(int, int, int, int);
static void _renderMapCompletion(int arg0, int arg1, int arg2, int arg3);
static void _renderIncrementalMapCompletion(int, int, int, int);
static void _renderRiskbreakerRankHeader(int arg0, int arg1, int arg2);
void _renderRiskbreakerRank(int, int, int);
static void _parseTim(u_int* arg0, TIM_IMAGE* arg1);
static void _determineRank(void);
static void _updateScore(void);

extern void* D_1F800000[];

extern u_char D_8006E3FC[];
extern u_char D_8006FF7C[];
extern func_8006A9C0_t2 D_8007005C;
extern func_8006A9C0_t2 D_8007709C;
extern func_8006A9C0_t2 D_80088ABC;
extern func_8006A9C0_t2 D_8009A4DC;
extern func_8006A9C0_t2 D_800ABEFC;
extern func_8006A9C0_t2 D_800BD91C;
extern func_8006A9C0_t2 D_800CF33C;
extern func_8006A9C0_t2 D_800D7F7C;
extern func_8006A9C0_t2 D_800D837C;
extern func_8006A9C0_t2 D_800D975C;
extern func_8006A9C0_t2 D_800DB09C;
extern func_8006A9C0_t2 D_800DB26C;
extern int _countableRooms[];
extern u_char D_800DB72C;
extern func_8006A9C0_t2* D_800DB7B0;
extern u_short _illustrationTimers[];
extern int _illustLbas[];
extern int _illustSizes[];
extern _texture_t _disMap[];
extern u_char D_800DB876;
extern P_CODE D_800DBAA8[];
extern short titleThresholds[];
extern u_int rankScores[];
extern short D_800DBB68;
extern short D_800DBB6A;
extern u_short D_800DBB6C;
extern _creditsElement _creditsElements[];
extern u_char D_800DC188;
extern u_char D_800DC189;
extern u_char _skipInvoked;
extern int D_800DC18C;
extern int _textStreamDelay;
extern u_char* _creditsBytestreamHead;
extern short _scrollSpeed;
extern short D_800DC19A;
extern u_short D_800DC19C;
extern void* D_800DC1A0;
extern func_8006A9C0_t2* D_800DC1A4;
extern void* D_800DC1A8[];
extern u_int _rank;
extern int _clearCount;
extern u_int _score;
extern int _mapCompletion;
extern u_int _onScreenMapCompletion;
extern int _onScreenScore;
extern int _submenuState;
extern int D_800DC20C;
extern int D_800DC210;
extern int _incrementingScore;
extern int _incrementingMapCompletion;
extern u_char _riskbreakerRanks[][4];

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_800688D4);

// https://decomp.me/scratch/6icWO
INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", _renderPhantomPain);

void _renderFin(_creditsElement* arg0)
{
    int temp_a0_2;
    int temp_a0;
    int temp_v0;
    u_char var_s0;
    void** p;
    int new_var;

    SPRT* sprt = *(SPRT**)0x1F800000;

    switch (arg0->state) {
    case 1:
        arg0->currentStep = 0;
        arg0->state = 2;
        /* fallthrough */

    case 2:
        temp_v0 = arg0->currentStep;
        arg0->currentStep = temp_v0 + 1;
        var_s0 = (temp_v0 << 7) / 60;

        if (arg0->currentStep == 60) {
            arg0->currentStep = 0;
            arg0->state = 3;
        }
        break;

    case 3:
        var_s0 = 128;

        if (++arg0->currentStep == 240) {
            arg0->currentStep = 0;
            arg0->state = 4;
        }
        break;

    case 4:
        temp_a0 = arg0->currentStep;
        arg0->currentStep = temp_a0 + 1;
        var_s0 = ((0x3C - temp_a0) << 7) / 60;

        if (arg0->currentStep == 60) {
            arg0->state = -1;
        }

        break;
    }

    SetSprt(sprt);
    setXY0(sprt, 248, 184);
    setUV0(sprt, 0, 160);
    setWH(sprt, 36, 17);
    sprt->r0 = sprt->g0 = sprt->b0 = var_s0;
    setClut(sprt, 896, 82);

    p = (void**)0x1F800000;
    setaddr(sprt, ((u_long*)p[1])[1]);
    setaddr(p[1] + 4, sprt++);

    new_var = 0;
    p[new_var] = sprt;
    p[new_var] = _insertTpage(getTPage(clut4Bit, semiTransparencyFull, 896, 0), 1);
}

void _renderVagrantStory(_creditsElement* element)
{
    SPRT* sprt;
    int var_fp;
    void** s0;
    int new_var;

    sprt = *(SPRT**)0x1F800000;

    switch (element->state) {
    case 1:
        element->x = 61 << 8;
        element->y = 80 << 8;
        element->currentStep = 0;
        element->state = 2;
        /* fallthrough */

    case 2:
        var_fp = (D_800DC19C * ++element->currentStep) / 60;

        if (element->currentStep == 60) {
            element->state = 3;
            element->currentStep = 0;
        }
        break;

    case 3:
        var_fp = D_800DC19C;

        if (++element->currentStep == 60) {
            element->state = 4;
        }
        break;

    case 4:
        var_fp = D_800DC19C;
        element->y += _scrollSpeed;

        if (element->y < -(60 << 8)) {
            element->state = -1;
            return;
        }
        break;
    }

    SetSprt(sprt);
    setSemiTrans(sprt, 1);
    setXY0(sprt, element->x >> 8, element->y >> 8);
    setUV0(sprt, 0, 96);
    setWH(sprt, 208, 48);
    setClut(sprt, 896, 80);
    sprt->r0 = sprt->g0 = sprt->b0 = var_fp;

    s0 = (void**)0x1F800000;
    setaddr(sprt, getaddr(s0[1] + 12));
    setaddr(s0[1] + 12, sprt++);

    new_var = 0;
    s0[new_var] = sprt;

    sprt = _insertTpage(0x2E, 3);

    SetSprt(sprt);
    setSemiTrans(sprt, 1);
    setXY0(sprt, element->x >> 8, element->y >> 8);
    setUV0(sprt, 0, 0x60);
    setWH(sprt, 0xD0, 0x30);
    setClut(sprt, 896, 81);
    sprt->r0 = sprt->g0 = sprt->b0 = var_fp;

    setaddr(sprt, getaddr(s0[1] + 12));
    setaddr(s0[1] + 12, sprt++);

    s0[new_var] = sprt;
    s0[new_var] = _insertTpage(0x4E, 3);
    return;
}

static int _inverseDistanceFromScreencenter(int arg0, int arg1)
{
    arg0 -= 160;
    arg1 -= 112;
    return vs_gte_rsqrt(arg0 * arg0 + arg1 * arg1);
}

static void func_80069388(func_80069388_t* arg0, short arg1, short arg2)
    __attribute__((unused));
static void func_80069388(func_80069388_t* arg0, short arg1, short arg2)
{
    short temp_s0;
    short v0;

    if (arg2 == 0) {
        temp_s0 = (arg1 * 128) / 80;
        v0 = temp_s0
           + (((200 - _inverseDistanceFromScreencenter(arg0->unk8, arg0->unkA)) << 7)
               / 400);

        if (v0 < 0x81) {
            arg0->unk6 = v0;
        } else {
            arg0->unk6 = 128;
        }

        arg0->unk4 = arg0->unk5 = arg0->unk6;

        v0 = temp_s0
           + (((200 - _inverseDistanceFromScreencenter(arg0->unk14, arg0->unk16)) << 7)
               / 400);

        if (v0 < 0x81) {
            arg0->unk12 = v0;
        } else {
            arg0->unk12 = 128;
        }

        arg0->unk10 = arg0->unk11 = arg0->unk12;

        v0 = temp_s0
           + (((200 - _inverseDistanceFromScreencenter(arg0->unk20, arg0->unk22)) << 7)
               / 400);

        if (v0 < 0x81) {
            arg0->unk1E = v0;
        } else {
            arg0->unk1E = 128;
        }

        arg0->unk1C = arg0->unk1D = arg0->unk1E;

        v0 = temp_s0
           + (((200 - _inverseDistanceFromScreencenter(arg0->unk2C, arg0->unk2E)) << 7)
               / 400);

        if (v0 < 0x81) {
            arg0->unk2A = v0;
        } else {
            arg0->unk2A = 128;
        }

    } else {

        temp_s0 = ((0x50 - arg1) << 7) / 80;
        v0 = temp_s0
           - (((200 - _inverseDistanceFromScreencenter(arg0->unk8, arg0->unkA)) << 7)
               / 400);

        if (v0 >= 0) {
            arg0->unk6 = v0;
        } else {
            arg0->unk6 = 0;
        }

        arg0->unk4 = arg0->unk5 = arg0->unk6;

        v0 = temp_s0
           - (((200 - _inverseDistanceFromScreencenter(arg0->unk14, arg0->unk16)) << 7)
               / 400);

        if (v0 >= 0) {
            arg0->unk12 = v0;
        } else {
            arg0->unk12 = 0;
        }

        arg0->unk10 = arg0->unk11 = arg0->unk12;

        v0 = temp_s0
           - (((200 - _inverseDistanceFromScreencenter(arg0->unk20, arg0->unk22)) << 7)
               / 400);

        if (v0 >= 0) {
            arg0->unk1E = v0;
        } else {
            arg0->unk1E = 0;
        }

        arg0->unk1C = arg0->unk1D = arg0->unk1E;

        v0 = temp_s0
           - (((200 - _inverseDistanceFromScreencenter(arg0->unk2C, arg0->unk2E)) << 7)
               / 400);

        if (v0 >= 0) {
            arg0->unk2A = v0;
        } else {
            arg0->unk2A = 0;
        }
    }

    arg0->unk28 = arg0->unk29 = arg0->unk2A;
}

static void _renderllustration(_creditsElement* element)
{
    SPRT* sprt;
    short temp_v0;
    void** p;

    temp_v0 = element->state - 1;

    switch (temp_v0) {
    case 0:
        if ((element->illustId >= 4) && (element->illustId != 15)) {
            func_8006AF44(D_800DB7B0, D_800DC1A8[element->illustId + 1]);
        }

        element->currentStep = 0;
        element->state = 2;
        D_800DBB6A = (element->illustId % 5) * 192;
        D_800DBB6C = (element->illustId % 5) + 480;
        /* fallthrough */

    case 1:
        D_800DBB68 = (D_800DC19C * element->currentStep) / 80;

        if (++element->currentStep == 80) {
            int var_a0 = 3;
            element->currentStep = 0;
            if (element->illustId == 15) {
                var_a0 = 5;
            }
            element->state = var_a0;
        }
        break;

    case 2:
        D_800DBB68 = 128;

        if (++element->currentStep == _illustrationTimers[element->illustId]) {
            element->currentStep = 0;
            element->state = 4;
        }

        break;

    case 3:
        D_800DBB68 = (D_800DC19C * (80 - element->currentStep)) / 80;

        if (++element->currentStep == 80) {
            if (++element->illustId >= 5) {
                func_8006A9C0(D_800DB7B0);
            }
            element->state = 1;
        }
        break;

    case 4:
        D_800DBB68 = 0x80;
        break;
    }

    p = (void**)0x1F800000;
    sprt = p[0];

    SetSprt(sprt);
    setXY0(sprt, 0, 0);
    setWH(sprt, 0xA0, 0xE0);
    setUV0(sprt, 0, 0);
    setSemiTrans(sprt, 1);
    setClut(sprt, 0, D_800DBB6C);
    sprt->r0 = sprt->g0 = sprt->b0 = D_800DBB68;

    AddPrim(p[1] + 0x10, sprt++);

    p[0] = sprt;
    sprt = _insertTpage(getTPage(1, 2, D_800DBB6A, 256), 4);

    SetSprt(sprt);
    setXY0(sprt, 0xA0, 0);
    setWH(sprt, 0xA0, 0xE0);
    setUV0(sprt, 0x20, 0);
    setSemiTrans(sprt, 1);
    setClut(sprt, 0, D_800DBB6C);
    sprt->r0 = sprt->g0 = sprt->b0 = D_800DBB68;

    AddPrim(p[1] + 0x10, sprt++);

    p[0] = sprt;
    p[0] = _insertTpage(getTPage(1, 2, D_800DBB6A + 64, 256), 4);
}

static int func_80069AEC(u_char* arg0)
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

// https://decomp.me/scratch/86Hv9
INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", _renderText);

void _renderCopyright(_creditsElement* arg0)
{
    void** p = (void**)0x1F800000;
    SPRT* sprt = p[0];
    int new_var;

    if (arg0->state == 1) {
        arg0->x = 100 << 8;
        arg0->y = 224 << 8;
        arg0->state = 2;
    }

    arg0->y += _scrollSpeed;

    if (arg0->y < -(12 << 8)) {
        arg0->state = -1;
        return;
    }

    SetSprt(sprt);
    setXY0(sprt, arg0->x >> 8, arg0->y >> 8);
    setUV0(sprt, 0, 0x30);
    setWH(sprt, 0x78, 0x10);
    setClut(sprt, 960, 64);
    sprt->r0 = sprt->g0 = sprt->b0 = D_800DC19C;

    setaddr(sprt, ((u_long*)p[1])[3]);
    setaddr(p[1] + 12, sprt++);

    new_var = 0;
    p[new_var] = sprt;
    p[new_var] = _insertTpage(getTPage(clut4Bit, semiTransparencyFull, 960, 0), 3);
}

static void _renderBackground(_creditsElement* arg0 __attribute__((unused)))
{
    TILE* tile;
    POLY_G4* poly;
    SPRT* sprt;
    void** data;

    data = (void**)0x1F800000;

    sprt = data[0];
    SetSprt(sprt);
    setXY0(sprt, 0, 10);
    setUV0(sprt, 0, 10);
    setWH(sprt, 256, 204);
    setClut(sprt, 780, 255);
    sprt->r0 = sprt->g0 = sprt->b0 = D_800DC19C;
    AddPrim(data[1] + 0x1FFC, sprt++);
    data[0] = sprt;

    sprt = (SPRT*)_insertTpage(getTPage(clut4Bit, semiTransparencyFull, 768, 0), 0x7FF);
    SetSprt(sprt);
    setUV0(sprt, 0, 10);
    setXY0(sprt, 256, 10);
    setWH(sprt, 64, 204);
    setClut(sprt, 780, 255);
    sprt->r0 = sprt->g0 = sprt->b0 = D_800DC19C;
    AddPrim(data[1] + 0x1FFC, sprt++);
    data[0] = sprt;

    poly =
        (POLY_G4*)_insertTpage(getTPage(clut4Bit, semiTransparencyFull, 832, 0), 0x7FF);
    SetPolyG4(poly);
    poly->x0 = poly->x2 = 0;
    poly->x1 = poly->x3 = 320;
    poly->y0 = poly->y1 = 10;
    poly->y2 = poly->y3 = 30;
    poly->r0 = poly->r1 = poly->g0 = poly->g1 = poly->b0 = poly->b1 = 255;
    poly->r2 = poly->r3 = poly->g2 = poly->g3 = poly->b2 = poly->b3 = 0;
    setSemiTrans(poly, 1);
    AddPrim(data[1] + 8, poly++);

    SetPolyG4(poly);
    poly->x0 = poly->x2 = 0;
    poly->x1 = poly->x3 = 320;
    poly->y0 = poly->y1 = 194;
    poly->y2 = poly->y3 = 214;
    poly->r0 = poly->r1 = poly->g0 = poly->g1 = poly->b0 = poly->b1 = 0;
    poly->r2 = poly->r3 = poly->g2 = poly->g3 = poly->b2 = poly->b3 = 255;
    setSemiTrans(poly, 1);
    AddPrim(data[1] + 8, poly++);

    tile = (TILE*)poly;
    SetTile(tile);
    tile->r0 = tile->g0 = tile->b0 = 0;
    setWH(tile, 320, 10);
    setXY0(tile, 0, 0);
    AddPrim(data[1] + 8, tile++);

    SetTile(tile);
    tile->r0 = tile->g0 = tile->b0 = 0;
    setWH(tile, 320, 10);
    setXY0(tile, 0, 0);
    AddPrim(data[1] + 8, tile++);

    SetTile(tile);
    tile->r0 = tile->g0 = tile->b0 = 0;
    setWH(tile, 320, 10);
    setXY0(tile, 0, 214);
    AddPrim(data[1] + 8, tile++);
    data[0] = tile;

    data[0] = _insertTpage(getTPage(clut8Bit, semiTransparencySubtract, 0, 0), 2);
}

static void _backgroundFadeIn(_creditsElement* element)
{
    if (element->state == 1) {
        element->currentStep = 0;
        element->state = 2;
    }

    if (++element->currentStep == 128) {
        D_800DC189 = 0;
        element->state = -1;
    }

    D_800DC19C = (u_int)_ease(easeModeLinear, element->currentStep, 128) / 32;
}

static void _backgroundFadeOut(_creditsElement* arg0)
{
    if (arg0->state == 1) {
        arg0->state = 2;
        arg0->currentStep = 0;
        D_800DC189 = 1;
    }

    if (++arg0->currentStep == 128) {
        if (arg0->width != 0) {
            D_800DC188 = 1;
        }
        arg0->state = -1;
    }

    D_800DC19C = 128 - ((_ease(easeModeLinear, arg0->currentStep, 128) << 7) >> 0xC);
}

static void func_8006A4D8(_creditsElement* element)
{
    void** s2 = (void**)0x1F800000;
    TILE* temp_s0 = s2[0];

    if (element->state == 1) {
        element->currentStep = 0;
        element->state = 2;
    }

    if (++element->currentStep == 128) {
        D_800DC188 = 1;
    }

    SetTile(temp_s0);
    setSemiTrans(temp_s0, 1);
    temp_s0->r0 = temp_s0->g0 = temp_s0->b0 =
        (_ease(easeModeEaseOut, element->currentStep, 128) * 255) >> 0xC;
    setWH(temp_s0, 320, 240);
    setXY0(temp_s0, 0, 0);

    AddPrim(s2[1], temp_s0++);

    s2[0] = temp_s0;
    s2[0] = _insertTpage(getTPage(clut4Bit, semiTransparencySubtract, 0, 0), 0);
}

void vs_ending_exec(void)
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
    _skipInvoked = 0;

    _resetElements();
    _addRenderer(_renderBackground);
    DrawSync(0);
    SetDispMask(1);

    _creditsBytestreamHead = D_8006E3FC;
    _scrollSpeed = -128;
    D_800DC188 = 0;
    _textStreamDelay = 0;
    D_800DC18C = 0;
    D_800DC189 = 1;

    func_8006B9B4();
    func_8006A888();
    vs_main_checkStreamXaEnd();
    SetDispMask(0);

    for (i = 5; i < 16; ++i) {
        vs_main_freeHeapR(D_800DC1A8[i]);
    }

    _checkStreamXaEnd();
    _updateClearGameStats();
    func_8006BD78();
}

static void _setDrawEnv(DRAWENV* drawenv)
{
    drawenv->isbg = 1;
    drawenv->dtd = 0;
    drawenv->dfe = 0;
    drawenv->b0 = 0;
    drawenv->g0 = 0;
    drawenv->r0 = 0;
    drawenv->tpage = 0x20;
}

static void func_8006A888(void)
{
    while (D_800DC188 == 0) {

        D_800DC19A = VSync(1);

        func_8006B930();
        _parseCreditsScript();
        _renderElements();
        func_8006AF64();

        if ((vs_main_buttonsPressed.all & PADstart) && (_skipInvoked == 0)) {
            _addRenderer(func_8006A4D8);
            _skipInvoked = 1;
        }

        _drawScreen(*(u_long**)0x1F800004 + 0x7FF);

        ++D_800DC18C;
    }
}

static void* _insertTpage(int tPage, int otOffset)
{
    void** scratch;
    DR_TPAGE* drTpage;

    scratch = (void**)0x1F800000;
    drTpage = scratch[0];
    SetDrawTPage(drTpage, 0, 1, tPage & 0xFFFF);
    AddPrim(scratch[1] + (otOffset * 4), drTpage++);
    return drTpage;
}

static void func_8006A9C0(func_8006A9C0_t2* arg0)
{
    RECT rect;
    func_8006A9C0_t* p = &arg0->unk8;

    if (arg0->unk4 & 8) {
        rect.x = p->rect.x;
        rect.y = p->rect.y;
        rect.w = p->rect.w;
        rect.h = p->rect.h;
        LoadImage(&rect, (void*)p->data);
        p = (func_8006A9C0_t*)((void*)arg0 + (p->size + 8));
    }

    rect.x = p->rect.x;
    rect.y = p->rect.y;
    rect.w = p->rect.w;
    rect.h = p->rect.h;

    LoadImage(&rect, (void*)p->data);
}

static void _resetElements(void)
{
    short i;
    _creditsElement* element = _creditsElements;
    for (i = 0; i < 32; ++i, ++element) {
        element->state = 0;
    }
}

static int _renderElements(void)
{
    short i;
    short var_s3 = 0;
    _creditsElement* element = _creditsElements;

    for (i = 0; i < 32; ++i, ++element) {
        if (element->state < 0) {
            element->state = 0;
        } else if (element->state > 0) {
            ++var_s3;
            element->renderer(element);
        }
    }

    return var_s3;
}

_creditsElement* _addRenderer(void (*renderer)(_creditsElement*))
{
    short i;
    _creditsElement* element = &_creditsElements[1];

    for (i = 1; i < 32; ++i, ++element) {
        if (element->state == 0) {
            element->renderer = renderer;
            element->state = 1;
            element->currentStep = 0;
            return element;
        }
    }

    SystemError('M', 100);
}

_creditsElement* _replaceMainRenderer(void (*renderer)(_creditsElement*))
{
    if (_creditsElements[0].state == 0) {
        _creditsElements[0].renderer = renderer;
        _creditsElements[0].state = 1;
        _creditsElements[0].currentStep = 0;
        return &_creditsElements[0];
    }

    return NULL;
}

static void _parseCreditsScript(void)
{
    enum opcodes { wait = 1 };

    u_char* bytestream;
    int op;
    int delay;

    if (_textStreamDelay != 0) {
        --_textStreamDelay;
        return;
    }

    while (1) {
        bytestream = _creditsBytestreamHead;

        switch (bytestream[0]) {

        // 0x1 Wait: u8 duration
        case wait:
            _creditsBytestreamHead = bytestream + 1;
            delay = bytestream[1] * 2;
            _creditsBytestreamHead = bytestream + 2;
            _textStreamDelay = delay;
            return;

        // 0x2 Render text: u8 len
        case 2:
            _creditsBytestreamHead = bytestream + 1;
            _addRenderer(_renderText)->data = _creditsBytestreamHead;
            _creditsBytestreamHead += _creditsBytestreamHead[0] + 1;
            break;

        // 0x3 Enable background illustrations
        case 3:
            _creditsBytestreamHead = bytestream + 1;
            _addRenderer(_renderllustration)->illustId = 0;
            break;

        // 0x4 Render special: u8 secondary op
        case 4:
            _creditsBytestreamHead = bytestream + 1;
            op = bytestream[1];
            _creditsBytestreamHead = bytestream + 2;

            switch (op) {
            case 0:
                _addRenderer(_renderCopyright);
                break;

            case 1:
                _addRenderer(_renderVagrantStory);
                break;

            case 2:
                _addRenderer(_renderFin);
                break;

            case 3:
                _addRenderer(_renderPhantomPain);
                break;
            }
            break;

        // 0x5 Fade in
        case 5:
            _creditsBytestreamHead = bytestream + 1;
            _replaceMainRenderer(_backgroundFadeIn);
            break;

        // 0x6 Fade out
        case 6:
            _creditsBytestreamHead = bytestream + 1;
            _replaceMainRenderer(_backgroundFadeOut)->width = 0;
            break;

        // 0x7 Freeze scrolling
        case 7:
            _creditsBytestreamHead = bytestream + 1;
            _scrollSpeed = 0;
            break;

        // 0x8 Set illustration timer: u8 illustration id, u16 duration
        case 8:
            *(_illustrationTimers + bytestream[1]) =
                (bytestream[2] + (bytestream[3] << 8)) - 160;
            _creditsBytestreamHead = bytestream + 4;
            break;

        // 0xFF End of stream
        case 255:
            D_800DC188 = 1;
            return;

        default:
            return;
        }
    }
}

static int _ease(short mode, short currentStep, short totalSteps)
{
    switch (mode) {
    case 0:
        return (currentStep * ONE) / totalSteps;
    case 1:
        return rsin((currentStep * (ONE / 4)) / totalSteps);
    case 2:
        return (rcos(((currentStep * (ONE / 2)) / totalSteps) + (ONE / 2)) + ONE) >> 1;
    case 3:
        return rsin(((currentStep * (ONE / 4)) / totalSteps) - (ONE / 4)) + ONE;
    }
}

static void func_8006AF44(func_8006A9C0_t2* arg0, void* arg1)
{
    D_800DB72C = 1;
    D_800DC1A0 = arg1;
    D_800DC1A4 = arg0;
}

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006AF64);

static void func_8006B324(short arg0, short arg1, int arg2, u_char* arg3)
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

static void func_8006B450(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5)
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

static int _drawScreen(u_long* arg0)
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

static void func_8006B884(void)
{
    func_8006B450(0x140, 0xF0, 0x200, 0, 0, 0);
    vs_main_initHeap((vs_main_HeapHeader*)0x8010C000, 0xF2000);
    D_8005E0C0[0] = vs_main_allocHeap(0x20000);
    D_8005E0C0[1] = vs_main_allocHeap(0x20000);
    D_80055C80[0] = vs_main_allocHeap(0x2088);
    D_80055C80[1] = vs_main_allocHeap(0x2088);
}

static void _updateClearGameStats(void) { _do_updateClearGameStats(); }

static void func_8006B930(void)
{
    void* temp_a0;

    vs_main_processPadState();
    temp_a0 = D_80055C80[vs_main_frameBuf];
    D_1F800000[2] = temp_a0 + 8;
    D_1F800000[1] = temp_a0 + 0x48;
    ClearOTagR((u_long*)temp_a0, 0x822);
    D_1F800000[0] = D_8005E0C0[vs_main_frameBuf];
}

static void func_8006B9B4(void)
{
    vs_main_streamXa(VS_ENDING_XA_LBA, 0x7FFF); // Partial playback?
}

static void _checkStreamXaEnd(void) { vs_main_checkStreamXaEnd(); }

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

static void func_8006BD78(void)
{
    int temp_s0;

    _submenuState = 0;
    SetDispMask(1);

    do {
        func_8006B930();
        temp_s0 = func_8006BE04();
        _drawScreen(*(u_long**)0x1F800004 + 0x7FF);
    } while (temp_s0 == 0);

    do {
        func_8006B930();
        temp_s0 = _renderCongratulationsScreen();
        VSync(0);
        _drawScreen(*(u_long**)0x1F800004 + 0x7FF);
    } while (temp_s0 == 0);
}

static int func_8006BE04(void)
{
    static const vs_main_CdFile endScrDisFiles[] = {
        { VS_END_DIS_LBA, VS_END_DIS_SIZE },
        { VS_ENDSCR00_DIS_LBA, VS_ENDSCR00_DIS_SIZE },
        { VS_ENDSCR01_DIS_LBA, VS_ENDSCR01_DIS_SIZE },
        { VS_ENDSCR02_DIS_LBA, VS_ENDSCR02_DIS_SIZE },
        { VS_ENDSCR03_DIS_LBA, VS_ENDSCR03_DIS_SIZE },
        { VS_ENDSCR04_DIS_LBA, VS_ENDSCR04_DIS_SIZE },
        { VS_ENDSCR05_DIS_LBA, VS_ENDSCR05_DIS_SIZE },
        { VS_ENDSCR06_DIS_LBA, VS_ENDSCR06_DIS_SIZE },
        { VS_ENDSCR07_DIS_LBA, VS_ENDSCR07_DIS_SIZE },
        { VS_ENDSCR08_DIS_LBA, VS_ENDSCR08_DIS_SIZE },
        { VS_ENDSCR09_DIS_LBA, VS_ENDSCR09_DIS_SIZE },
        { VS_ENDSCR10_DIS_LBA, VS_ENDSCR10_DIS_SIZE },
        { VS_ENDSCR11_DIS_LBA, VS_ENDSCR11_DIS_SIZE },
        { VS_ENDSCR12_DIS_LBA, VS_ENDSCR12_DIS_SIZE },
        { VS_ENDSCR13_DIS_LBA, VS_ENDSCR13_DIS_SIZE },
        { VS_ENDSCR14_DIS_LBA, VS_ENDSCR14_DIS_SIZE },
        { VS_ENDSCR15_DIS_LBA, VS_ENDSCR15_DIS_SIZE },
    };

    extern vs_main_CdQueueSlot* cdSlot;
    extern void* timData;

    TIM_IMAGE sp10;
    int i;
    int var_a1;
    int var_v1;

    if (_submenuState == 0) {

        timData = vs_main_allocHeapR(endScrDisFiles->size);
        cdSlot = vs_main_allocateCdQueueSlot(endScrDisFiles);

        vs_main_cdEnqueue(cdSlot, timData);

        ++_submenuState;

    } else if (_submenuState == 1) {

        if (cdSlot->state != vs_main_CdQueueStateLoaded) {
            return 0;
        }

        for (i = 0; i < 3; ++i) {

            _parseTim(timData + i * 0x8220, &sp10);

            if (sp10.paddr != NULL) {
                sp10.prect->x = 832 + i * 64;
                sp10.prect->y = 0x100;
                sp10.prect->h = 0xFF;
                LoadImage(sp10.prect, sp10.paddr);
            }

            if (i == 0) {
                if (sp10.caddr != NULL) {
                    sp10.crect->x = 0x300;
                    sp10.crect->y = 0x1FF;
                    sp10.crect->w = 0x80;
                    sp10.crect->h = 1;
                    *sp10.caddr = 0;
                    LoadImage(sp10.crect, sp10.caddr);
                }
            }
        }

        vs_main_freeCdQueueSlot(cdSlot);
        ++_submenuState;

    } else if (_submenuState == 2) {

        vs_main_freeHeapR(timData);

        var_a1 = 0;
        _onScreenMapCompletion = 0;
        _onScreenScore = 0;
        D_800DC20C = 0;
        D_800DC210 = 0;
        _clearCount = vs_main_stateFlags.clearCount;

        for (i = 0; i < 16; ++i) {
            int flag;
            for (flag = 0; flag < 32; ++flag) {
                int v = 1;
                if (vs_main_mapStatus.roomFlags[i] & _countableRooms[i] & (v << flag)) {
                    ++var_a1;
                }
            }
        }

        var_v1 = 0;

        for (i = 0; i < 64; ++i) {
            if (vs_main_stateFlags.chestsOpened[i] != 0) {
                ++var_v1;
            }
        }

        if (vs_main_scoredata.mapCompletion < var_a1) {
            vs_main_scoredata.mapCompletion = var_a1;
        }

        if (vs_main_scoredata.openedChestCount < var_v1) {
            vs_main_scoredata.openedChestCount = var_v1;
        }

        _mapCompletion = (vs_main_scoredata.mapCompletion * 100) / 361;

        _updateScore();
        _determineRank();

        timData = vs_main_allocHeapR(endScrDisFiles[_rank + 1].size);
        cdSlot = vs_main_allocateCdQueueSlot(&endScrDisFiles[_rank + 1]);
        vs_main_cdEnqueue(cdSlot, timData);
        ++_submenuState;

    } else if (_submenuState == 3) {

        if (cdSlot->state != 4) {
            return 0;
        }

        _parseTim(timData, &sp10);

        if (sp10.paddr != NULL) {
            sp10.prect->x = 0;
            sp10.prect->y = 0x100;
            LoadImage(sp10.prect, sp10.paddr);
        }

        vs_main_freeCdQueueSlot(cdSlot);

        ++_submenuState;

    } else {
        _submenuState = 0;
        vs_main_freeHeapR(timData);

        return 1;
    }

    return 0;
}

static int _renderCongratulationsScreen(void)
{
    if (D_800DC210 == 0) {

        if (D_800DC20C == 0xD0) {
            vs_main_playSfxDefault(0x7E, 0x77);
            vs_main_playSfxDefault(0x7E, 0x78);
        }

        func_8006C3CC(D_800DC20C);
        _renderCongratulations(0xA0, 0x28, D_800DC20C);
        _renderIncrementalScore(0xA0, 0x50, D_800DC20C - 0x20, D_800DC210);
        _renderIncrementalMapCompletion(0xA0, 0x66, D_800DC20C - 0x70, D_800DC210);
        _renderRiskbreakerRankHeader(0xA0, 0x8A, D_800DC20C - 0xC0);
        _renderRiskbreakerRank(0xA0, 0x9A, D_800DC20C - 0xD0);

        if (D_800DC20C >= 0x1001) {
            D_800DC20C = 0x1000;
        }

        if (vs_main_buttonsPressed.all != 0) {
            D_800DC210 = 1;
            D_800DC20C = 0;
        }

    } else {

        func_8006C3CC(8 - D_800DC20C);
        _renderCongratulations(0xA0, 0x28, 8 - D_800DC20C);
        _renderScore(0xA0, 0x50, 8 - D_800DC20C, 3);
        _renderMapCompletion(0xA0, 0x66, 8 - D_800DC20C, 3);
        _renderRiskbreakerRankHeader(0xA0, 0x8A, 8 - D_800DC20C);
        _renderRiskbreakerRank(0xA0, 0x9A, 8 - D_800DC20C);

        if (D_800DC20C >= 8) {
            return 1;
        }
    }

    ++D_800DC20C;
    return 0;
}

void func_8006C3CC(int arg0)
{
    int var_s2;
    int i;
    int temp_s4;
    POLY_FT4* poly;

    if (arg0 < 0) {
        arg0 = 0;
    }

    if (arg0 > 64) {
        arg0 = 64;
    }

    temp_s4 = arg0 * 2;

    if (arg0 <= 0) {
        return;
    }

    poly = *(void**)0x1F800000;
    var_s2 = 64;

    for (i = 0; i < 5; ++i) {
        setPolyFT4(poly);
        setXY4(poly, i * 64, 8, 64 + i * 64, 8, i * 64, 232, 64 + i * 64, 232);
        setUV4(poly, 0, 0, 64, 0, 0, 224, 64, 224);
        setRGB0(poly, temp_s4, temp_s4, temp_s4);
        setClut(poly, 0, 0);
        poly->tpage = (i + 16) | getTPage(3, 0, 0, 0);
        AddPrim(*((void**)0x1F800004) + 0x1FF8, poly++);
        var_s2 += 64;
    }

    *(void**)0x1F800000 = poly;
}

static void _renderCongratulations(int arg0, int arg1, int arg2)
{
    extern P_CODE D_800DBA7C[2];

    if (arg2 < 0) {
        arg2 = 0;
    }

    if (arg2 > 64) {
        arg2 = 64;
    }

    if (arg2 > 0) {
        D_800DBA7C[0].code = arg2;
        D_800DBA7C[1].code = arg2;
        arg0 = arg0 - ((_disMap[22].w + _disMap[23].w) >> 1);
        _renderTexturePopIn(arg0, arg1, 0x16, D_800DBA7C);
        _renderTexturePopIn(arg0 + _disMap[22].w, arg1, 0x17, &D_800DBA7C[1]);
    }
}

static void _renderScore(int arg0, int arg1, int arg2, int arg3 __attribute__((unused)))
{
    extern P_CODE D_800DBA88[];

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

        D_800DBA88[0].code = arg2;

        sprintf(sp10, "%09d", _score);

        v1 = _disMap[18].w + _disMap[26].w + _disMap[20].w;
        arg0 -= (_disMap[10].w * 2 + v1 + 0x74) >> 1;

        _renderTextureFadeInTint(arg0, arg1, 0x12, D_800DBA88);

        arg0 += _disMap[18].w;

        _renderTextureFadeInTint(arg0, arg1 + 7, 0x1A, D_800DBA88);

        v0 = arg0 + 2;
        arg0 = v0 + _disMap[26].w;

        for (i = 0; i < 9; ++i) {
            _renderTextureFadeInTint(arg0, arg1 + 3, sp10[i] - 0x30, D_800DBA88);
            arg0 += 12;
            if ((i == 2) || (i == 5)) {
                int v0;
                _renderTextureFadeInTint(arg0, arg1 + 0xE, 0xA, D_800DBA88);
                v0 = arg0 + 3;
                arg0 = v0 + _disMap[10].w;
            }
        }

        _renderTextureFadeInTint(arg0, arg1 + 8, 0x14, D_800DBA88);
    }
}

static void _renderIncrementalScore(
    int arg0, int arg1, int arg2, int arg3 __attribute__((unused)))
{
    extern P_CODE D_800DBA90[];

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

    if (var_s1 > 64) {
        var_s1 = 64;
    }

    if (var_s1 > 0) {
        temp_s2 = arg0 + (var_s1 * 8);

        if (_score != 0 && var_s1 >= 32) {

            if (_onScreenScore == 0) {
                _incrementingScore = 1;
                vs_main_playSfxDefault(0x7E, 0x72);
            }

            if ((_onScreenScore == _score) && (_incrementingScore != 0)) {
                _incrementingScore = 0;
                func_80045D64(0x7E, 0x72);
                vs_main_playSfxDefault(0x7E, 0x73);
            }
        }

        if (var_s1 >= 32) {
            _onScreenScore = ((u_int)_score >> 5) * (var_s1 - 32);
        }

        if (var_s1 == 64) {
            _onScreenScore = _score;
        }

        sprintf(sp18, "%09d", _onScreenScore);

        v1 = _disMap[18].w + _disMap[26].w + _disMap[20].w;
        arg0 -= (_disMap[10].w * 2 + v1 + 0x74) >> 1;

        _renderTextureWipe(arg0, arg1, 0x12, D_800DBA90, temp_s2);

        arg0 += _disMap[18].w;

        _renderTextureWipe(arg0, arg1 + 7, 0x1A, D_800DBA90, temp_s2);

        v0 = arg0 + 2;
        arg0 = v0 + _disMap[26].w;

        for (i = 0; i < 9; ++i) {
            _renderTextureWipe(arg0, arg1 + 3, sp18[i] - '0', D_800DBA90, temp_s2);
            arg0 += 12;
            if ((i == 2) || (i == 5)) {
                _renderTextureWipe(arg0, arg1 + 0xE, 0xA, D_800DBA90, temp_s2);
                arg0 += 3 + _disMap[10].w;
            }
        }

        _renderTextureWipe(arg0, arg1 + 8, 0x14, D_800DBA90, temp_s2);
    }
}

static void _renderMapCompletion(
    int arg0, int arg1, int arg2, int arg3 __attribute__((unused)))
{
    extern P_CODE D_800DBA98[];

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

        D_800DBA98[0].code = arg2;

        sprintf(sp10, "%03d", _mapCompletion);

        arg0 -= ((_disMap[21].w + _disMap[26].w + _disMap[19].w + 0x26) >> 1);

        _renderTextureFadeInTint(arg0, arg1, 0x15, D_800DBA98);

        arg0 += _disMap[21].w;

        _renderTextureFadeInTint(arg0, arg1 + 7, 0x1A, D_800DBA98);

        v0 = arg0 + 2;
        arg0 = v0 + _disMap[26].w;

        for (i = 0; i < 3; ++i) {
            _renderTextureFadeInTint(arg0, arg1 + 3, sp10[i] - '0', D_800DBA98);
            arg0 += 12;
        }

        _renderTextureFadeInTint(arg0, arg1 + 8, 0x13, D_800DBA98);
    }
}

static void _renderIncrementalMapCompletion(
    int arg0, int arg1, int arg2, int arg3 __attribute__((unused)))
{
    extern P_CODE D_800DBAA0[];

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

    if (arg2 <= 0) {
        return;
    }

    temp_s4 = arg0 + arg2 * 8;

    if (_mapCompletion != 0 && arg2 >= 32) {

        if (_onScreenMapCompletion == 0) {
            _incrementingMapCompletion = 1;
            vs_main_playSfxDefault(0x7E, 0x72);
        }

        if ((_onScreenMapCompletion == _mapCompletion)
            && (_incrementingMapCompletion != 0)) {
            _incrementingMapCompletion = 0;
            func_80045D64(0x7E, 0x72);
            vs_main_playSfxDefault(0x7E, 0x73);
        }
    }

    if (arg2 >= 32) {
        if (_mapCompletion >= 32u) {
            _onScreenMapCompletion = (u_int)(_mapCompletion * (arg2 - 32)) >> 5;
        } else if (_onScreenMapCompletion < _mapCompletion) {
            _onScreenMapCompletion += 1;
        }
    }

    sprintf(sp18, "%03d", _onScreenMapCompletion);

    arg0 -= ((int)(_disMap[21].w + _disMap[26].w + _disMap[19].w + 0x26) >> 1);

    _renderTextureWipe(arg0, arg1, 0x15, D_800DBAA0, temp_s4);

    arg0 += _disMap[21].w;

    _renderTextureWipe(arg0, arg1 + 7, 0x1A, D_800DBAA0, temp_s4);

    v0 = arg0 + 2;
    arg0 = v0 + _disMap[26].w;

    for (i = 0; i < 3; ++i) {
        _renderTextureWipe(arg0, arg1 + 3, sp18[i] - '0', D_800DBAA0, temp_s4);
        arg0 += 12;
    }

    _renderTextureWipe(arg0, arg1 + 8, 0x13, D_800DBAA0, temp_s4);
}

static void _renderRiskbreakerRankHeader(int x, int y, int timer)
{
    if (timer < 0) {
        timer = 0;
    }

    if (timer > 64) {
        timer = 64;
    }

    if (timer > 0) {
        D_800DBAA8[0].code = timer;
        _renderTextureFadeInTint(x - (D_800DB876 >> 1), y, 12, D_800DBAA8);
    }
}

void _renderRiskbreakerRank(int x, int y, int timer)
{
    extern P_CODE D_800DBAB0[];

    int xInset;
    int i;

    if (timer < 0) {
        timer = 0;
    }

    if (timer > 64) {
        timer = 64;
    }

    xInset = 0;

    if (timer > 0) {

        D_800DBAB0[0].code = timer;

        for (i = 0; i < _riskbreakerRanks[_rank][0]; ++i) {
            xInset += _disMap[_riskbreakerRanks[_rank][i + 1]].w;
        }

        xInset /= 2;
        x -= xInset;

        for (i = 0; i < _riskbreakerRanks[_rank][0]; ++i) {
            _renderTexturePopIn(x, y, _riskbreakerRanks[_rank][i + 1], D_800DBAB0);

            x += _disMap[_riskbreakerRanks[_rank][i + 1]].w;
        }
    }
}

#include "src/renderTextures.h"

static void _parseTim(u_int* data, TIM_IMAGE* tim)
{

    ++data;
    tim->mode = *data;
    ++data;

    if (tim->mode & 8) {
        tim->crect = (void*)(data + 1);
        tim->caddr = (void*)(data + 3);
        data += data[0] / 4;
    } else {
        tim->crect = 0;
        tim->caddr = 0;
    }

    tim->prect = (void*)(data + 1);
    tim->paddr = (void*)(data + 3);
}

static void _determineRank(void)
{
    int unlockedTitles;
    int flag;
    int i;

    for (i = 0, unlockedTitles = 0, flag = 1; i < 16; ++i) {
        if (vs_main_scoredata.titles & (flag << i)) {
            ++unlockedTitles;
        }
    }

    for (i = 0; i < 16; ++i) {
        if (unlockedTitles >= titleThresholds[i]) {
            if (_score >= rankScores[i]) {
                _rank = i;
                return;
            }
        }
    }
}

static void _updateScore(void)
{
    short enemyKillPoints[] = { 20, 20, 40, 80, 100, 60 };
    short weaponAttackPoints[] = { 20, 40, 20, 100, 60, 100, 60, 100, 80, 60 };
    int i;

    _score = 0;

    for (i = 0; i < 6; ++i) {
        _score += vs_main_scoredata.enemyKills[i] * enemyKillPoints[i];
    }

    for (i = 0; i < 10; ++i) {
        _score += vs_main_scoredata.weaponAttacks[i] * weaponAttackPoints[i];
    }

    for (i = 0; i < 8; ++i) {
        if (vs_main_scoredata.bossTimeTrialScores[i][0].time != 0x800000) {
            _score += 20000;
        }
    }

    if (vs_main_scoredata.maxChain < 6) {
        _score += vs_main_scoredata.maxChain * 10;
    } else if (vs_main_scoredata.maxChain < 11) {
        _score += vs_main_scoredata.maxChain * 20;
    } else if (vs_main_scoredata.maxChain < 16) {
        _score += vs_main_scoredata.maxChain * 40;
    } else if (vs_main_scoredata.maxChain < 21) {
        _score += vs_main_scoredata.maxChain * 80;
    } else if (vs_main_scoredata.maxChain < 26) {
        _score += vs_main_scoredata.maxChain * 160;
    } else if (vs_main_scoredata.maxChain < 31) {
        _score += vs_main_scoredata.maxChain * 320;
    } else if (vs_main_scoredata.maxChain < 51) {
        _score += vs_main_scoredata.maxChain * 640;
    } else {
        _score += vs_main_scoredata.maxChain * 1280;
    }

    _score += _clearCount * 100000;

    if ((_clearCount != 0) && (vs_main_scoredata.completionTimeMinutes < 600)) {
        if (vs_main_scoredata.completionTimeMinutes >= 540) {
            _score += _score / 4;
        } else if (vs_main_scoredata.completionTimeMinutes >= 300) {
            _score += _score / 2;
        } else {
            _score *= 2;
        }
    }

    _score += vs_main_scoredata.streakScore;
    _score += vs_main_scoredata.miscScore;

    if (_score > 999999999) {
        _score = 999999999;
    }
}
