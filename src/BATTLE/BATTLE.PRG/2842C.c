#include "common.h"
#include "146C.h"
#include "30DB0.h"
#include "38C1C.h"
#include "573B8.h"
#include "5BF94.h"
#include "gpu.h"
#include "src/SLUS_010.40/main.h"
#include <abs.h>
#include <memory.h>
#include <rand.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    int* unk0;
    void* unk4;
    short unk8;
    short unkA;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    SVECTOR unk1C;
    short unk24;
    short unk26;
    short unk28;
    short unk2A;
    short unk2C;
    short unk2E;
    short unk30;
    short unk32;
} func_80092F74_t;

typedef struct {
    int* unk0;
    union {
        u_short u16[2];
        short s16[2];
        int s32;
    } unk4[4];
    int unk14;
    int unk18;
} func_80092F74_t2;

typedef struct {
    int unk0;
    char unk4;
    char unk5;
    char unk6;
    char unk7;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
} D_800F1DD8_t2;

typedef struct {
    char unk0;
    u_char unk1;
    char unk2;
    char unk3;
    D_800F1DD8_t2* unk4;
    D_800F1DD8_t2* unk8;
} D_800F1DD8_t;

typedef struct {
    short unk0;
    short unk2;
} func_80092B04_t2;

typedef struct {
    int unk0;
    void* unk4;
    char unk8[0x2C];
} func_80092B04_t;

typedef struct {
    u_short unk0;
    u_short unk2;
    u_short unk4;
    u_short unk6;
    char unk8;
    char unk9;
    char unkA;
    char unkB;
    short unkC;
    char unkE;
    char unkF;
} func_800962E4_t;

typedef struct {
    u_char unk0[0xC];
    u_char unkC;
    u_char unkD;
    u_char unkE;
    u_char unkF;
    u_char unk10;
    u_char unk11;
    u_char unk12;
    u_char unk13;
    u_char unk14;
    u_char unk15;
    u_char unk16[0xA];
} func_80093914_t;

typedef struct {
    u_char unk0[0xC];
    u_char unkC;
    u_char unkD;
    u_char unkE;
    u_char unkF;
    u_char unk10;
    u_char unk11;
    u_char unk12;
    u_char unk13;
    u_char unk14;
    u_char unk15;
    u_char unk16[0xE];
    u_char unk24;
    u_char unk25;
    u_char unk26;
    u_char unk27;
} func_80093914_t2;

typedef struct {
    int geometryOffset;
    char unk4[3];
    u_char delay;
    u_char baseU;
    u_char baseV;
    u_char frameCount;
    u_char columns;
    u_char frameWidth;
    u_char frameHeight;
    u_char tick;
    u_char frame;
    u_char u[4];
    u_char v[4];
} func_80091C6C_t;

typedef struct {
    char unk0[0xF];
    u_char type;
    char unk10[3];
    u_char u2;
    char unk14[3];
    u_char v2;
    u_char u0;
    u_char v0;
    char unk1A[2];
    u_char u1;
    u_char v1;
    char unk1E[5];
    u_char u3;
    char unk24[3];
    u_char v3;
} func_80091C6C_t2;

typedef struct {
    int geometryOffset;
    char unk4[3];
    u_char delay;
    u_char baseU;
    u_char baseV;
    u_char width;
    u_char height;
    u_char currentU;
    u_char currentV;
    u_char windowWidth;
    u_char windowHeight;
    signed char stepU;
    signed char stepV;
    u_char tick;
    char unk13;
    u_char u[4];
    u_char v[4];
} func_80091E10_t;

typedef struct {
    u_char tick;
    u_char frame;
    u_char frameCount;
    u_char columns;
    char unk4[3];
    u_char delay;
    int scrollStep;
    RECT rect;
} func_80091FE8_t;

typedef struct {
    u_char count;
    u_char labels[2];
    u_char color;
} D_800690B4_t;

void func_8008F29C(int, int);
void func_8008F30C(int, int);
void func_8008F440(void);
void func_8008F9A4(int, int);
void func_8008FAC8(void);
void func_8008FDC4(void);
void func_80090434(void);
void func_80090B28(void);
void func_8009121C(void);
void func_800927AC(D_800F1DD8_t*);
int func_80092B04(func_80092B04_t*, int, D_800F1DD8_t*);
int func_8009291C(int);
void func_80092EDC(func_80092F74_t* arg0);
int func_8009306C(func_80092F74_t* arg0);
int func_80093364(func_80092F74_t* arg0);
int func_8009406C(int, int, int, int);
void func_80094844(short*, D_800F1BAC_t*);
void func_80094AF8(D_800F1BAC_t*);
void func_80094B0C(int, int, D_800F1BAC_t*);
int func_80094E18(int, int, D_800F1BAC_t*);
void func_8009506C(int, int, D_800F1BAC_t*);
void func_80095258(int, int, D_800F1BAC_t*);
void func_800957D0(int, int, int);
void func_800958A4(int, int, D_800F1BAC_t*);
void func_80095A4C(int, int, D_800F1BAC_t*);
void func_80095C18(int, int);
int func_80096254(int, int);
void* func_800962E4();
void func_8009639C(int);
void func_80096444(int);
void func_8009651C(SVECTOR*, int);
void func_8009695C(int, int, D_800F1BAC_t*);
void func_800970BC(void);

extern int (*D_800E85CC[])(D_800F1DD8_t2*);
extern int (*D_800E85E8[])(func_80092B04_t*, func_80092B04_t2*);
extern char D_80068EB4[];
extern int D_80068F04[][4];
extern u_short D_80068F64[][4];
extern int D_80068F94[];
extern RECT D_80068FAC[];
extern D_800690B4_t D_800690B4[];
extern const CVECTOR D_80069134[];
extern const RECT D_80069144[];
extern const RECT D_8006917C[];
extern char D_800691E4[];
extern int D_800E861C[];
extern short D_800E8634[];
extern RECT D_800E8640[];
extern u_short D_800F1CDC;
extern short D_800F1D00;
extern short D_800F1D98[];
extern short D_800F1DA4;
extern short D_800F1DB4;
extern short D_800F1DB6;
extern short D_800F1DBC;
extern short D_800F1DC0;
extern short D_800F1DC2;
extern short D_800F1DC4;
extern char D_800F1DCA;
extern char D_800F1DCB;
extern void* D_800F1DD4;
extern D_800F1DD8_t D_800F1DD8[];
extern short D_800F2258;
extern char D_800F225A;
extern char D_800F225B;
extern char D_800F2260[];
extern short D_800F2270;
extern short D_800F2272;
extern int D_800F2274;
extern short D_800F2278;
extern short D_800F227A;
extern short D_800F227C;
extern short D_800F227E;
extern SVECTOR D_800F2280;

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", D_80068EB4);

void func_80090C2C(int arg0)
{
    _mpdRoomSectionB* room = vs_battle_roomData.sectionB;

    if (room != NULL) {
        int sound = -2;

        D_800F1D98[7] = 1;
        D_800F1D98[9] = 1;
        D_800F1D98[8] = 1;
        D_800F1D98[4] = room->unk42;
        D_800F1D98[5] = room->unk36;
        D_800F1DCA = arg0;
        D_800F1DC4 = room->unk3C;
        func_8009121C();
        func_80090B28();

        switch (arg0) {
        case 0:
            break;
        case 1:
            func_8008F29C(vs_battle_clamp((room->unk48[1].s16[0] / 128)
                                              * (room->unk48[1].s16[1] / 128) / 4,
                              4, 128),
                arg0);
            sound = 21;
            break;
        case 2:
            func_8008F29C(vs_battle_clamp((room->unk48[1].s16[0] / 128)
                                              * (room->unk48[1].s16[1] / 128) / 4,
                              4, 128),
                arg0);
            break;
        case 3:
            func_8008F30C(vs_battle_clamp((room->unk48[1].s16[0] / 128)
                                              * (room->unk48[1].s16[1] / 128) / 4,
                              4, 128),
                arg0);
            break;
        case 4:
            func_8008F9A4(vs_battle_clamp((room->unk48[1].s16[0] / 128)
                                              * (room->unk48[1].s16[1] / 128) / 2,
                              4, 128),
                arg0);
            break;
        }

        if (D_800F1DBC != -1) {
            if ((D_800F1DBC >= 0) && (D_800F1DBC != sound)) {
                func_80045D64(0x200, D_800F1DBC);
            }
            if (sound >= 0) {
                vs_main_playSfxDefault(0x200, sound);
            }

            D_800F1DBC = sound;
        }
    } else if (D_800F1DBC >= 0) {
        func_80045D64(0x200, D_800F1DBC);
        D_800F1DBC = -2;
    }
}

void func_80090EEC(void)
{
    int masks[] = { 0xF, 0x1F, 0x3F, 0x7F };
    _mpdRoomSectionB* room = vs_battle_roomData.sectionB;

    if ((room == NULL) || (D_800F1DCA == 0)) {
        return;
    }

    if ((D_800F1BA4 == 0) && (D_800F1DCB != 0)) {
        int changed = 0;

        if ((D_800F1CDC & masks[room->unk3A]) == 0) {
            if ((rand() & 7) < 3) {
                D_800F1D98[7] *= -1;
            }

            D_800F1D98[5] += D_800F1D98[7];
            D_800F1D98[5] &= 0xFFF;
            D_800F1D98[5] = vs_battle_clamp(D_800F1D98[5], room->unk36, room->unk38);
            changed = 1;
        }
        if (((D_800F1CDC + 30) & masks[room->unk46]) == 0) {
            if ((rand() & 7) < 3) {
                D_800F1D98[9] *= -1;
            }

            D_800F1D98[4] += D_800F1D98[9];
            D_800F1D98[4] = vs_battle_clamp(D_800F1D98[4], room->unk42, room->unk44);
            changed = 1;
        }
        if (((D_800F1CDC + 60) & masks[room->unk40]) == 0) {
            if ((rand() & 7) < 3) {
                D_800F1D98[8] *= -1;
            }

            D_800F1DC4 += D_800F1D98[8];
            D_800F1DC4 = vs_battle_clamp(D_800F1DC4, room->unk3C, room->unk3E);
            func_8009121C();
            changed = 1;
        }
        if (changed != 0) {
            func_80090B28();
        }
    }
    switch (D_800F1DCA) {
    case 1:
        func_8008F440();
        break;
    case 2:
        func_8008FDC4();
        break;
    case 3:
        func_80090434();
        break;
    case 4:
        func_8008FAC8();
        break;
    }
}

short vs_battle_clamp(short arg0, int arg1, int arg2)
{
    short var_t0;
    short var_v1;

    if ((arg1 << 0x10) < (arg2 << 0x10)) {
        var_t0 = arg1;
        var_v1 = arg2;
    } else {
        var_t0 = arg2;
        var_v1 = arg1;
    }
    if (arg0 < var_t0) {
        return var_t0;
    }
    if (var_v1 < arg0) {
        return var_v1;
    }
    return arg0;
}

void func_8009121C(void)
{
    short scale;

    D_800F1DC0 = vs_battle_clamp(D_800F1DC4 * 8, 4, D_800F1DC2);
    if (D_800F1DBC >= 0) {
        if (D_80068EB4[D_800F1DC4] != 0) {
            vs_main_playSfxDefault(0x200, D_800F1DBC);
            func_80045BFC(0x200, D_800F1DBC, D_80068EB4[D_800F1DC4], 8);
        } else {
            func_80045D64(0x200, D_800F1DBC);
        }
    }
    scale = vs_battle_clamp((D_800F1DC4 * 4) + (D_800F1DC4 * 2), 12, 90);
    D_800F1DA4 = scale + (scale >> 1) + (scale >> 2);
}

void func_80091314(int arg0) { D_800F1DCB = arg0; }

void func_80091320(int arg0)
{
    D_800F1DC4 = arg0;
    func_8009121C();
    func_80090B28();
}

void func_8009134C(int arg0, int arg1)
{
    D_800F1D98[5] = arg0;
    D_800F1D98[4] = arg1;
    func_80090B28();
}

void func_80091378(void)
{
    D_800F1DC0 = 0;
    D_800F1DC2 = 0;
    if (D_800F1DD4 != NULL) {
        vs_main_freeHeap(D_800F1DD4);
    }
    D_800F1DD4 = NULL;
}

int func_800913BC(int arg0)
{
    int temp_s3;

    temp_s3 = D_800F1DBC;
    D_800F1DBC = arg0;

    if (arg0 >= 0) {
        if (D_80068EB4[D_800F1DC4] != 0) {
            vs_main_playSfxDefault(0x200, (short)arg0);
            func_80045BFC(0x200, D_800F1DBC, D_80068EB4[D_800F1DC4], 8);
        } else {
            func_80045D64(0x200, (short)arg0);
        }
    }
    return temp_s3;
}

void func_80091468(int arg0, int arg1)
{
    D_800F1DB4 = arg0;
    D_800F1DB6 = arg1;
}

void func_8009147C(vs_battle_backgroundLayout* arg0, int arg1, int arg2, int arg3)
{
    void* buffer = ((vs_scratch_t*)0x1F800000)->unk0;
    vs_battle_backgroundTile* tiles = arg0->tiles;
    int cosStep = rcos(((vs_scratch_t*)0x1F800000)->camera.angles.vz) * 32;
    int sinStep = rsin(((vs_scratch_t*)0x1F800000)->camera.angles.vz) * 32;
    int row;
    int col;
    TILE* background;

    for (row = 0; row < arg0->height * 32; row += 32) {
        int y = row - arg2;
        POLY_GT4* prim = buffer;

        for (col = 0; col < 1024; col += 32) {
            int x = ((col + arg1) & 1023) - 512;
            int screenX = rcos(((vs_scratch_t*)0x1F800000)->camera.angles.vz) * x
                        - rsin(((vs_scratch_t*)0x1F800000)->camera.angles.vz) * y;
            int screenY = rsin(((vs_scratch_t*)0x1F800000)->camera.angles.vz) * x
                        + rcos(((vs_scratch_t*)0x1F800000)->camera.angles.vz) * y;
            vs_battle_backgroundTile* tile;

            if ((screenX < -64 * ONE) || (screenX > 384 * ONE) || (screenY < -64 * ONE)
                || (screenY > 304 * ONE)) {
                continue;
            }

            tile = &tiles[(row / 32) * arg0->width + (col / 32) % arg0->width];

            if ((tile->uv.w == 0) && (tile->uv.h == 0)) {
                continue;
            }

            setPolyGT4(prim);
            setXY4(prim, screenX / ONE, screenY / ONE, (screenX + cosStep) / ONE,
                (screenY + sinStep) / ONE, (screenX - sinStep) / ONE,
                (screenY + cosStep) / ONE, (screenX + cosStep - sinStep) / ONE,
                (screenY + sinStep + cosStep) / ONE);
            setRGB0(prim, tile->colors[0].r, tile->colors[0].g, tile->colors[0].b);
            setRGB1(prim, tile->colors[1].r, tile->colors[1].g, tile->colors[1].b);
            setRGB2(prim, tile->colors[2].r, tile->colors[2].g, tile->colors[2].b);
            setRGB3(prim, tile->colors[3].r, tile->colors[3].g, tile->colors[3].b);
            setUV4(prim, tile->uv.x, tile->uv.y, tile->uv.x + tile->uv.w, tile->uv.y,
                tile->uv.x, tile->uv.y + tile->uv.h, tile->uv.x + tile->uv.w,
                tile->uv.y + tile->uv.h);
            prim->tpage = arg3 | (tile->colors[1].cd << 7);
            prim->clut = getClut(768, 238);
            buffer += sizeof(POLY_GT4);
            AddPrim(((vs_scratch_t*)0x1F800000)->unk4 + 0x1FFC, prim++);
        }
    }

    background = buffer;
    setTile(background);
    setRGB0(background, 0, 0, 0);
    setXY0(background, 0, 0);
    setWH(background, 320, 240);
    AddPrim(((vs_scratch_t*)0x1F800000)->unk4 + 0x1FFC, background);
    ((vs_scratch_t*)0x1F800000)->unk0 = background + 1;
}

void func_800918E8(int arg0)
{
    if (D_800F1DBC >= 0) {
        if (arg0 != 0) {
            func_80045BFC(0x200, D_800F1DBC, D_80068EB4[D_800F1DC4] >> 2, 8);
        } else {
            func_80045BFC(0x200, D_800F1DBC, D_80068EB4[D_800F1DC4], 8);
        }
    }
}

void* func_8009195C(int arg0)
{
    if (vs_battle_roomData.geometrySection != NULL) {
        int v1 = *vs_battle_roomData.geometrySection;
        int* a1 = vs_battle_roomData.geometrySection + 1;
        if ((arg0 >= 0) && (arg0 < v1)) {
            return a1 + (arg0 * 16);
        }
    }
    return NULL;
}

int func_80091998(int arg0)
{
    int* temp_v0 = func_8009195C(arg0);
    if (temp_v0 != NULL) {
        *temp_v0 &= ~0x100;
        return 1;
    }
    return 0;
}

int func_800919D8(int arg0)
{
    int* temp_v0 = func_8009195C(arg0);
    if (temp_v0 != NULL) {
        *temp_v0 |= 0x100;
        return 1;
    }
    return 0;
}

int func_80091A1C(int arg0, int arg1)
{
    int* temp_s0 = func_8009195C(arg0);
    int* temp_a1 = func_8009195C(arg1);

    if ((temp_s0 != NULL) && (temp_a1 != NULL)) {
        int temp_a0 = *temp_s0;
        *temp_s0 = *temp_a1;
        *temp_a1 = temp_a0;
        return 1;
    }
    return 0;
}

int func_80091A78(int arg0, int arg1)
{
    u_short* temp_v0 = func_8009195C(arg0);
    if (temp_v0 != NULL) {
        temp_v0[1] = (u_short)(temp_v0[1] + arg1);
        return 1;
    }
    return 0;
}

int func_80091AC0(int arg0)
{
    int* temp_v0 = func_8009195C(arg0);
    if (temp_v0 != NULL) {
        *temp_v0 |= 0x1000;
        return 1;
    }
    return 0;
}

void func_80091B04(void)
{
    int i;

    for (i = 0; i < D_800F225A; ++i) {
        if ((D_800F1DD8[i].unk0 != 0) && (D_800F1DD8[i].unk1 < 7)
            && (D_800F1DD8[i].unk2 != 0)) {
            D_800F1DD8[i].unk0 = D_800E85CC[D_800F1DD8[i].unk1](D_800F1DD8[i].unk4);
        }
    }

    for (i = 0; i < D_800F225B; ++i) {
        if ((D_800F1DD8[i + 64].unk0 != 0) && (D_800F1DD8[i + 64].unk2 != 0)) {
            D_800F1DD8[i + 64].unk0 =
                func_80092B04((func_80092B04_t*)D_800F1DD8[i + 64].unk4,
                    D_800F1DD8[i + 64].unk1, &D_800F1DD8[i + 64]);
            if (D_800F1DD8[i + 64].unk0 == 0) {
                vs_main_freeHeap(D_800F1DD8[i + 64].unk4);
                D_800F1DD8[i + 64].unk4 = D_800F1DD8[i + 64].unk8;
            }
        }
    }
}

int func_80091C6C(func_80091C6C_t* arg0)
{
    func_80091C6C_t* quad = arg0;
    void* base = vs_battle_roomData.geometrySection;

    if (++arg0->tick > arg0->delay) {
        int u;
        int v;
        func_80091C6C_t2* polygon;

        arg0->tick = 0;

        if (++arg0->frame >= arg0->frameCount) {
            arg0->frame = 0;
        }

        u = arg0->baseU + arg0->frameWidth * (arg0->frame % arg0->columns);
        v = arg0->baseV + arg0->frameHeight * (arg0->frame / arg0->columns);
        polygon = base + arg0->geometryOffset;

        if ((polygon->type & 0x3C) == 0x34) {
            polygon->u0 = arg0->u[0] + u;
            polygon->u1 = arg0->u[1] + u;
            polygon->u2 = arg0->u[2] + u;
            polygon->v0 = arg0->v[0] + v;
            polygon->v1 = arg0->v[1] + v;
            polygon->v2 = arg0->v[2] + v;
        } else {
            polygon->u0 = quad->u[0] + u;
            polygon->u1 = quad->u[1] + u;
            polygon->u2 = quad->u[2] + u;
            polygon->u3 = quad->u[3] + u;
            polygon->v0 = quad->v[0] + v;
            polygon->v1 = quad->v[1] + v;
            polygon->v2 = quad->v[2] + v;
            polygon->v3 = quad->v[3] + v;
        }
    }

    return 1;
}

int func_80091E10(func_80091E10_t* arg0)
{
    func_80091E10_t* quad = arg0;
    void* base = vs_battle_roomData.geometrySection;

    if (++arg0->tick > arg0->delay) {
        int u = arg0->currentU;
        int v = arg0->currentV;
        func_80091C6C_t2* polygon;

        u += arg0->stepU;
        v += arg0->stepV;
        arg0->tick = 0;

        if (u < arg0->baseU) {
            u = arg0->baseU + arg0->width - arg0->windowWidth;
        }

        if (v < arg0->baseV) {
            v = arg0->baseV + arg0->height - arg0->windowHeight;
        }

        if (arg0->baseU + arg0->width < u + arg0->windowWidth) {
            u = arg0->baseU;
        }

        if (arg0->baseV + arg0->height < v + arg0->windowHeight) {
            v = arg0->baseV;
        }

        arg0->currentU = u;
        arg0->currentV = v;
        polygon = base + arg0->geometryOffset;

        if ((polygon->type & 0x3C) == 0x34) {
            polygon->u0 = arg0->u[0] + u;
            polygon->u1 = arg0->u[1] + u;
            polygon->u2 = arg0->u[2] + u;
            polygon->v0 = arg0->v[0] + v;
            polygon->v1 = arg0->v[1] + v;
            polygon->v2 = arg0->v[2] + v;
        } else {
            polygon->u0 = quad->u[0] + u;
            polygon->u1 = quad->u[1] + u;
            polygon->u2 = quad->u[2] + u;
            polygon->u3 = quad->u[3] + u;
            polygon->v0 = quad->v[0] + v;
            polygon->v1 = quad->v[1] + v;
            polygon->v2 = quad->v[2] + v;
            polygon->v3 = quad->v[3] + v;
        }
    }

    return 1;
}

int func_80091FE8(func_80091FE8_t* arg0)
{
    RECT source;
    RECT halfSource;

    if (++arg0->tick > arg0->delay) {
        int destX;
        int destY;
        int halfDestX;
        int halfSourceX;

        arg0->rect.x -= 320;
        arg0->rect.y += 256;
        arg0->tick = 0;

        if (arg0->scrollStep == 0) {
            if (++arg0->frame > arg0->frameCount) {
                arg0->frame = 1;
            }

            setRECT(&source, arg0->rect.x + arg0->rect.w * (arg0->frame % arg0->columns),
                arg0->rect.y + arg0->rect.h * (arg0->frame / arg0->columns), arg0->rect.w,
                arg0->rect.h);
        } else {
            arg0->frame += arg0->scrollStep;

            if (arg0->frame >= arg0->rect.h) {
                arg0->frame = 0;
            }

            setRECT(&source, arg0->rect.x + arg0->rect.w / 2, arg0->rect.y + arg0->frame,
                arg0->rect.w / 2, arg0->rect.h - arg0->frame);
        }

        halfDestX = (arg0->rect.x % 64) / 2 - 64;
        destX = halfDestX + (arg0->rect.x & 0x3C0);
        destY = (arg0->rect.y % 256) / 2 + (arg0->rect.y & 0x100);
        halfSourceX = (source.x % 64) / 2 - 64;
        setRECT(&halfSource, halfSourceX + (source.x & 0x3C0),
            (source.y % 256) / 2 + (source.y & 0x100), source.w / 2, source.h / 2);
        MoveImage(&source, arg0->rect.x, arg0->rect.y);
        MoveImage(&halfSource, destX, destY);

        if (arg0->scrollStep != 0 && arg0->frame != 0) {
            int wrapY;

            source.y = arg0->rect.y;
            source.h = arg0->frame;
            wrapY = arg0->rect.y + arg0->rect.h - arg0->frame;
            destY = (wrapY % 256) / 2 + (wrapY & 0x100);
            halfSource.y = (source.y % 256) / 2 + (source.y & 0x100);
            halfSource.h = source.h / 2;
            MoveImage(&source, arg0->rect.x, wrapY);
            MoveImage(&halfSource, destX, destY);
        }

        arg0->rect.x += 320;
        arg0->rect.y -= 256;
    }

    return 1;
}

int func_800923F8(D_800F1DD8_t2* arg0)
{
    int* base = vs_battle_roomData.geometrySection;
    int* p;
    int delta;
    int ret = 1;

    if (arg0->unk4 != 0) {
        arg0->unk4 = 0;
        arg0->unk14 = arg0->unk1C;
        arg0->unk8 = arg0->unk20;
    }

    arg0->unk14 += arg0->unk8;
    arg0->unk8 += arg0->unkC * 8;
    delta = (arg0->unk14 - arg0->unk18) & 0xFFF;

    if (delta > ONE / 2) {
        delta = ONE - delta;
    }

    if (delta < ABS(arg0->unk8)) {
        arg0->unk8 = -(arg0->unk8 >> arg0->unk10);

        if (ABS(arg0->unk8) < 0x21) {
            arg0->unk14 = arg0->unk18;
            ret = 0;
        }
    }

    p = (void*)base + arg0->unk0;

    if (arg0->unk7 == 1) {
        p[5] = arg0->unk14;
        p[0] |= 0x6000;
    } else if (arg0->unk7 == 2) {
        p[4] = arg0->unk14;
    } else {
        p[6] = arg0->unk14;
    }

    if (ret != 0) {
        return 1;
    }

    delta = arg0->unk1C;
    arg0->unk20 = -arg0->unk20;
    arg0->unk8 = arg0->unk20;
    arg0->unk1C = arg0->unk18;
    arg0->unk18 = delta;
    arg0->unkC = -arg0->unkC;
    return 0;
}

int func_80092540(void) { return 0; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_80092548);

void func_800927AC(D_800F1DD8_t* arg0)
{
    int _[32] __attribute__((unused));
    int i;
    signed char* script;
    func_80092F74_t* elem = vs_main_allocHeap(sizeof *elem * arg0->unk1);
    signed char* ids = (signed char*)arg0->unk4;

    arg0->unk4 = (D_800F1DD8_t2*)elem;
    ids += 4;
    script = ids + arg0->unk1;

    if (arg0->unk1 % 4) {
        script = &script[4 - arg0->unk1 % 4];
    }

    for (i = 0; i < arg0->unk1; ++i, ++elem, ++ids) {
        elem->unk8 = *ids;
        elem->unk4 = script;
        if (elem->unk8 >= 0) {
            int* entry = func_8009195C(elem->unk8);
            elem->unk0 = entry;
            if (entry != NULL) {
                elem->unkC = entry[1] * 16;
                elem->unk10 = entry[2] * 16;
                elem->unk14 = entry[3] * 16;
                setVector(&elem->unk1C, entry[4], entry[5], entry[6]);
            }
        } else {
            elem->unk0 = NULL;
        }
        elem->unk18 = 0;
        elem->unk1C.pad = 0;
        if (elem->unk0 == NULL) {
            elem->unk8 = -1;
        }
    }
}

void func_80092914(void) { }

int func_8009291C(int arg0)
{
    if (arg0 < D_800F225A) {
        D_800F1DD8[arg0].unk0 = 1;
        return 1;
    }
    if (arg0 < 0x40) {
        return 0;
    }
    if (arg0 < D_800F225B + 0x40) {
        if ((D_800F1DD8[arg0].unk0 != 0)
            || (D_800F1DD8[arg0].unk4 != D_800F1DD8[arg0].unk8)) {
            vs_main_freeHeap(D_800F1DD8[arg0].unk4);
        }
        D_800F1DD8[arg0].unk0 = 1;
        D_800F1DD8[arg0].unk4 = D_800F1DD8[arg0].unk8;
        func_800927AC(&D_800F1DD8[arg0]);
        return 1;
    }
    return 0;
}

int func_80092A18(void)
{
    int i;

    if (D_800F225B == 0) {
        return 0;
    }

    for (i = 0; i < D_800F225B; ++i) {
        if ((D_800F1DD8[i + 64].unk0 != 0)
            || (D_800F1DD8[i + 64].unk4 != D_800F1DD8[i + 64].unk8)) {
            D_800F1DD8[i + 64].unk0 = 0;
            vs_main_freeHeap(D_800F1DD8[i + 64].unk4);
        }
    }

    if (D_800F2258 != -1) {
        if (vs_battle_roomData.section14 != NULL) {
            func_8004644C(0x200, vs_battle_roomData.section14, D_800F2258);
            D_800F2258 = -1;
        }
    }
    D_800F225B = 0;
    return 1;
}

int func_80092B04(func_80092B04_t* arg0, int arg1, D_800F1DD8_t* arg2)
{
    int i;
    int idle = 0;

    for (i = 0; i < arg1; ++i, ++arg0) {
        if (arg0->unk4 != NULL) {
            while (1) {
                func_80092B04_t2* temp_s0 = arg0->unk4;

                if ((temp_s0->unk0 != 0) && (temp_s0->unk2 < 0xD)) {
                    if (vs_main_stateFlags.unkA8 != 0) {
                        if (temp_s0->unk2 == 0xB) {
                            break;
                        }
                        while (D_800E85E8[temp_s0->unk2](arg0, temp_s0) != 0) { }
                    } else if (D_800E85E8[temp_s0->unk2](arg0, temp_s0) != 0) {
                        break;
                    }
                    arg0->unk4 = (char*)arg0->unk4 + temp_s0->unk0;
                } else {
                    arg0->unk4 = NULL;
                    break;
                }
            }
        } else {
            ++idle;
        }
    }
    return idle != arg1;
}

int func_80092C68(func_80092F74_t* arg0, func_80092F74_t2* arg1)
{
    int x = arg0->unkC / 16 - arg1->unk4[0].s16[0];
    int y;
    int z;
    int d;

    arg0->unk24 = arg1->unk4[1].u16[1] - ABS(x);
    y = arg0->unk10 / 16 - arg1->unk4[0].s16[1];
    arg0->unk26 = arg1->unk4[1].u16[1] - ABS(y);
    z = arg0->unk14 / 16;
    z -= arg1->unk4[1].s16[0];
    arg0->unk28 = arg1->unk4[1].u16[1] - ABS(z);

    d = arg0->unk24;

    if (d > 0) {
        z = arg0->unkC - (arg1->unk4[0].s16[0] << 4);
        if (z < 0) {
            arg0->unk24 = -d;
        }
    } else {
        arg0->unk24 = 0;
    }

    d = arg0->unk26;

    if (d > 0) {
        if (arg0->unk10 - (arg1->unk4[0].s16[1] << 4) < 0) {
            arg0->unk26 = -d;
        }
    } else {
        arg0->unk26 = 0;
    }

    d = arg0->unk28;

    if (d > 0) {
        if (arg0->unk14 - (arg1->unk4[1].s16[0] << 4) < 0) {
            arg0->unk28 = -d;
        }
    } else {
        arg0->unk28 = 0;
    }

    arg0->unk24 /= 4;
    arg0->unk26 /= 4;
    arg0->unk28 /= 4;
    arg0->unk2A = arg1->unk4[2].u16[0] + 1;
    arg0->unk2C = (arg0->unk24 & 0x1F) - 16;
    arg0->unk2E = (arg0->unk26 & 0x3F) - 32;
    arg0->unk30 = 0;
    arg0->unk32 = 0;
    return 0;
}

int func_80092E14(func_80092F74_t* arg0, func_80092F74_t2* arg1)
{
    arg0->unk24 = arg1->unk4[0].u16[0];
    arg0->unk26 = arg1->unk4[0].u16[1];
    arg0->unk28 = arg1->unk4[1].u16[0];
    arg0->unk2A = arg1->unk4[1].u16[1];
    arg0->unk2C = arg1->unk4[2].u16[0];
    arg0->unk2E = arg1->unk4[2].u16[1];
    arg0->unk30 = arg1->unk4[3].u16[0];
    arg0->unk32 = arg1->unk4[3].u16[1];
    return 0;
}

int func_80092E7C(func_80092F74_t* arg0, func_80092F74_t2* arg1)
{
    arg0->unkC = arg1->unk4[0].s32;
    arg0->unk10 = arg1->unk4[1].s32;
    arg0->unk14 = arg1->unk4[2].s32;
    setVector(&arg0->unk1C, arg1->unk4[3].s32, arg1->unk14, arg1->unk18);
    func_80092EDC(arg0);
    return 0;
}

void func_80092EDC(func_80092F74_t* arg0)
{
    if (arg0->unk8 >= 0) {
        int* temp_v1 = arg0->unk0;
        temp_v1[1] = arg0->unkC / 16;
        temp_v1[2] = arg0->unk10 / 16;
        temp_v1[3] = arg0->unk14 / 16;

        temp_v1[4] = arg0->unk1C.vx;
        temp_v1[5] = arg0->unk1C.vy;
        temp_v1[6] = arg0->unk1C.vz;
    }
}

int func_80092F6C(func_80092F74_t* arg0 __attribute__((unused)),
    func_80092F74_t2* arg1 __attribute__((unused)))
{
    return 0;
}

int func_80092F74(func_80092F74_t* arg0, func_80092F74_t2* arg1 __attribute__((unused)))
{
    if (arg0->unk8 >= 0) {
        *arg0->unk0 = 0x100;
    }
    return 0;
}

int func_80092F98(func_80092F74_t* arg0, func_80092F74_t2* arg1)
{
    func_80091998(arg1->unk4[0].s32);
    return 0;
}

int func_80092FBC(func_80092F74_t* arg0, func_80092F74_t2* arg1)
{
    int var_a0 = 0;
    func_80092F74_t2* new_var = arg1;

    if (new_var->unk4[0].u16[1] == 1) {
        var_a0 = func_8009306C(arg0);
    } else if (new_var->unk4[0].u16[1] == 2) {
        var_a0 = func_80093364(arg0);
    }

    if (new_var->unk4[0].u16[0] == 0x8000) {
        if (var_a0 == 0) {
            return 0;
        }
    } else {
        ++arg0->unk18;
        if (arg0->unk18 >= new_var->unk4[0].u16[0]) {
            arg0->unk18 = 0;
            return 0;
        }
    }
    return 1;
}

int func_8009306C(func_80092F74_t* arg0);
INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_8009306C);

int func_80093364(func_80092F74_t* arg0)
{
    arg0->unkC += arg0->unk24;
    arg0->unk10 += arg0->unk26;
    arg0->unk14 += arg0->unk28;
    applyVector(&arg0->unk1C, arg0->unk2C, arg0->unk2E, arg0->unk30, +=);
    applyVector(&arg0->unk1C, 0xFFF, 0xFFF, 0xFFF, &=);

    if (arg0->unk2A != 0) {
        arg0->unk24 -= (arg0->unk24 * arg0->unk2A) / 16;
        arg0->unk26 -= (arg0->unk26 * arg0->unk2A) / 16;
        arg0->unk28 -= (arg0->unk28 * arg0->unk2A) / 16;
    }

    if (arg0->unk32 != 0) {
        arg0->unk2C -= (arg0->unk2C * arg0->unk32) / 16;
        arg0->unk2E -= (arg0->unk2E * arg0->unk32) / 16;
        arg0->unk30 -= (arg0->unk30 * arg0->unk32) / 16;
    }

    func_80092EDC(arg0);
    return 0;
}

int func_8009352C(func_80092F74_t* arg0, func_80092F74_t2* arg1)
{
    if (vs_battle_roomData.section14 != NULL) {
        if ((arg1->unk4[0].u16[0] == 0) || (D_800F1D00 != 0)) {
            func_800462E8(0x200, vs_battle_roomData.section14, arg1->unk4[0].u16[1]);
        } else {
            func_800461CC(
                0x200, vs_battle_roomData.section14, arg1->unk4[0].u16[1], 0x80, 0);
        }
        D_800F2258 = arg1->unk4[0].u16[1];
    }
    return 0;
}

int func_800935B8(func_80092F74_t* arg0, func_80092F74_t2* arg1)
{
    if (vs_battle_roomData.section14 != NULL) {
        func_8004644C(0x200, vs_battle_roomData.section14, arg1->unk4[0].u16[1]);
        D_800F2258 = -1;
    }
    return 0;
}

int func_800935F8(func_80092F74_t* arg0 __attribute__((unused)), func_80092F74_t2* arg1)
{
    func_8009291C(arg1->unk4[0].s32);
    return 0;
}

int func_8009361C(func_80092F74_t* unk0 __attribute__((unused)), func_80092F74_t2* arg1)
{
    func_800919D8(arg1->unk4[0].s32);
    return 0;
}

int func_80093640(func_80092F74_t* arg0, func_80092F74_t2* arg1)
{
    if (D_800F1DD8[arg1->unk4[0].s32 + 0x40].unk0 != 0) {
        vs_main_freeHeap(D_800F1DD8[arg1->unk4[0].s32 + 0x40].unk4);
        D_800F1DD8[arg1->unk4[0].s32 + 0x40].unk4 =
            D_800F1DD8[arg1->unk4[0].s32 + 0x40].unk8;
        D_800F1DD8[arg1->unk4[0].s32 + 0x40].unk0 = 0;
    }
    return 0;
}

int func_800936F0(func_80092F74_t* arg0 __attribute__((unused)),
    func_80092F74_t2* arg1 __attribute__((unused)))
{
    return 0;
}

int func_800936F8(int arg0)
{
    if (arg0 < D_800F225A) {
        D_800F1DD8[arg0].unk2 = D_800F1DD8[arg0].unk2 < 1U;
        return 1;
    }
    if ((arg0 >= 0x40) && (arg0 < (D_800F225B + 0x40))) {
        D_800F1DD8[arg0].unk2 = D_800F1DD8[arg0].unk2 < 1U;
        return 1;
    }
    return 0;
}

int func_80093764(int arg0) { return D_800F1DD8[arg0].unk0; }

void func_80093788(int arg0)
{
    D_800F1DD8_t2* temp_a2;
    int temp_a1;
    int temp_v0;
    int* temp_v1;

    if (arg0 < 0x40) {
        void* a0;
        if (D_800F1DD8[arg0].unk1 == 6) {
            temp_a2 = D_800F1DD8[arg0].unk4;
            a0 = (void*)vs_battle_roomData.geometrySection;
            if (D_800F1DD8[arg0].unk0 != 0) {
                temp_v1 = a0 + temp_a2->unk0;
                temp_v1[5] = temp_a2->unk18;
                temp_v1[0] = (temp_v1[0] | 0x6000);
                temp_v0 = -temp_a2->unk20;
                temp_a1 = temp_a2->unk1C;
                temp_a2->unk20 = temp_v0;
                temp_a2->unk8 = temp_v0;
                temp_a2->unk1C = temp_a2->unk18;
                temp_a2->unk18 = temp_a1;
                temp_a2->unkC = -temp_a2->unkC;
                D_800F1DD8[arg0].unk0 = 0;
            }
        }
    }
}

void func_80093824(int arg0)
{
    int temp_a1;
    D_800F1DD8_t2* temp_a2;
    int temp_v0;
    int* temp_a0;

    temp_a2 = (D_800F1DD8_t2*)D_800F1DD8[arg0].unk4;
    temp_a0 = (void*)vs_battle_roomData.geometrySection + temp_a2->unk0;

    if (temp_a2->unk7 == 2) {
        temp_a0[4] = temp_a2->unk18;
    } else {
        temp_a0[6] = temp_a2->unk18;
    }
    temp_v0 = -temp_a2->unk20;
    temp_a1 = temp_a2->unk1C;
    temp_a2->unk20 = temp_v0;
    temp_a2->unk8 = temp_v0;
    temp_a2->unk1C = temp_a2->unk18;
    temp_a2->unk18 = temp_a1;
    temp_a2->unkC = -temp_a2->unkC;
}

void func_800938AC(int arg0)
{
    if ((D_800F2258 != -1) && (vs_battle_roomData.section14 != NULL)) {
        if (arg0 != 0) {
            func_80046494(0x200, vs_battle_roomData.section14, D_800F2258, 0x20, 8);
        } else {
            func_80046494(0x200, vs_battle_roomData.section14, D_800F2258, 0x7F, 8);
        }
    }
}

void func_80093914(int arg0)
{
    int* base = vs_battle_roomData.geometrySection;
    int* entry = func_8009195C(arg0);
    int* block;
    int n0;
    int n1;
    func_80093914_t* t;
    func_80093914_t2* q;
    int i;
    u_char tmp;

    if (entry == NULL) {
        return;
    }
    block = (int*)((u_char*)base + entry[7]);
    n0 = block[0];
    n1 = block[1];
    block += 2;
    t = (func_80093914_t*)block;
    for (i = 0; i < n0; ++i, ++t) {
        tmp = t->unkC;
        t->unkC = t->unkD;
        t->unkD = tmp;
        tmp = t->unk10;
        t->unk10 = t->unk11;
        t->unk11 = tmp;
        tmp = t->unk14;
        t->unk14 = t->unk15;
        t->unk15 = tmp;
    }
    q = (func_80093914_t2*)t;
    for (i = 0; i < n1; ++i, ++q) {
        tmp = q->unkC;
        q->unkC = q->unkD;
        q->unkD = tmp;
        tmp = q->unk10;
        q->unk10 = q->unk11;
        q->unk11 = tmp;
        tmp = q->unk14;
        q->unk14 = q->unk15;
        q->unk15 = tmp;
        tmp = q->unk24;
        q->unk24 = q->unk25;
        q->unk25 = tmp;
    }
}

void func_80093A14(void)
{
    D_800F1D00 = 1;
    if ((D_800F2258 != -1) && (vs_battle_roomData.section14 != NULL)) {
        func_80046494(0x200, vs_battle_roomData.section14, D_800F2258, 0x7F, 0);
    }
}

void func_80093A70(void)
{
    if (D_800F2258 != -1) {
        if (vs_battle_roomData.section14 != 0) {
            func_800462E8(0x200, vs_battle_roomData.section14, D_800F2258);
        }
    }
}

void func_80093AB4(void)
{
    D_800F2270 = 0;
    D_800F2272 = 0;
    D_800F227E = 0;
    D_800F2278 = 0;
    D_800F227A = 0;
    vs_main_bzero(D_800F1BAC, sizeof *D_800F1BAC);
}

int func_80093B04(u_short* arg0)
{
    func_800962E4_t* temp_v0;

    temp_v0 = func_800962E4();
    temp_v0->unkB = 0;
    temp_v0->unk8 = 3;
    temp_v0->unk0 = arg0[0];
    temp_v0->unk2 = arg0[1];
    temp_v0->unk4 = arg0[2];
    ++D_800F227E;
    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_80093B68);

int vs_battle_renderBattleAbilityTimingResult(int arg0)
{
    int _[2] __attribute__((unused));
    D_800F1BAC_t* p = *D_800F1BAC;
    int i;

    for (i = 0; i < D_800F227E; ++i, ++p) {
        if (p->unk8.u16 == 4) {
            func_80096444(i);
            break;
        }
    }

    p = func_800962E4();
    p->unkB = 0;
    p->unk8.u8[0] = 4;
    p->unk8.u8[1] = 0;
    p->unkC = arg0;
    p->displayTextLen = rand() & 7;
    ++D_800F227E;
    return 0;
}

int func_80093F24(int arg0)
{
    D_800F1BAC_t* p = *D_800F1BAC;
    D_800F1BAC_t* q;
    int i;

    for (i = 0; i < D_800F227E; ++i, ++p) {
        if (p->unk8.u16 == 5) {
            func_80096444(i);
            break;
        }
    }

    if (arg0 == 0) {
        return 0;
    }

    q = func_800962E4();
    q->unk8.u8[0] = 5;
    q->unkB = 0;
    q->unk8.u8[1] = 0;
    q->unkC = arg0;
    if (q->unkC >= 1000) {
        q->unkC = 999;
    }
    ++D_800F227E;
    return 0;
}

int func_80093FEC(int arg0, int arg1, int arg2, int arg3)
{
    int i;
    int var_s1;

    for (i = 0, var_s1 = 1; i < 29; ++i, var_s1 <<= 1) {
        if (arg2 & var_s1) {
            func_8009406C(arg0, 0xFB, i, arg3);
        }
    }
    return 0;
}

int func_8009406C(int arg0, int arg1, int arg2, int arg3)
{
    SVECTOR sp10;
    int i = 0;
    int found = 0;
    int frame = 0;
    int kind = 0;
    D_800F1BAC_t* p = *D_800F1BAC;

    for (; i < D_800F227E; ++i, ++p) {
        if ((p->unk8.u8[0] == 2) && (p->unk8.u8[1] == arg0)) {
            frame = p->displayTextLen + 0xC;
            if (p->unk6 >= 0) {
                kind = p->unkB;
                ++found;
            }
        }
    }

    p = func_800962E4();
    if (arg3 & 0x80) {
        if (func_800A1280(arg0, 0xFB, &sp10, 0) != 0) {
            return 0;
        }
        if ((u_short)sp10.vx >= 0x141) {
            return 0;
        }
        if ((u_short)sp10.vy >= 0xF1) {
            return 0;
        }
    }
    arg3 &= 0x7F;
    p->unk8.u8[0] = 2;
    p->unk0 = 0;
    p->unk2 = 0;
    p->unk4 = 0;
    p->unk6 = found;
    if (frame < 0x25) {
        p->displayTextLen = frame;
    } else {
        p->displayTextLen = 0;
    }
    p->unkB = kind;
    p->unk8.u8[1] = arg0;
    p->unkA = arg1;
    p->unkE = arg3;
    p->unkC = arg2;
    ++D_800F227E;
    return 0;
}

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", D_80068F04);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", D_80068F64);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", D_80068F94);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", D_80068FAC);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", D_800690B4);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", D_80069134);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", D_80069144);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", D_8006917C);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", D_800691E4);

void func_800941FC(void)
{
    long p;
    D_800F1BAC_t* label;
    int removed;
    int i;

    if (D_800F2272 > 0) {
        --D_800F2272;
        func_800970BC();
    }

    if (D_800F1BA4 == 0) {
        D_800F2278 += vs_gametime_tickspeed / 2;
    }

    if (D_800F2278 > 20) {
        label = *D_800F1BAC;
        D_800F2278 = 0;

        for (i = 0; i < D_800F227E; ++i, ++label) {
            if (label->unk8.u8[0] == 6 && --label->unk6 == -1) {
                for (p = 0; p < i; ++p) {
                    if ((*D_800F1BAC)[p].unk8.u8[0] == 6) {
                        (*D_800F1BAC)[p].unk12 += 10;
                    }
                }
            }
        }
    }

    removed = 0;
    label = *D_800F1BAC;
    D_800F227C = 0;

    for (i = 0; i < D_800F227E; ++i, ++label) {
        SVECTOR position;
        short screen[2];
        long flag;
        int visible;

        if (label->unk8.u8[0] == 0) {
            continue;
        }

        if (label->unk8.u8[0] < 3) {
            if (func_800A190C(label->unk8.u8[1], 251, &position, 0) != 0) {
                label->unk8.u8[0] = 0;
                ++removed;
                continue;
            }

            if (position.vy > 0) {
                position.vy = 0;
            }

            applyVector(&position, label->unk0, label->unk2, label->unk4, +=);
            visible = RotTransPers(&position, (long*)screen, &p, &flag);

            if (screen[0] < 32) {
                screen[0] = 32;
            }

            if (screen[0] > 288) {
                screen[0] = 288;
            }

            if (screen[1] < 40) {
                screen[1] = 40;
            }

            if (screen[1] > 200) {
                screen[1] = 200;
            }
        } else if (label->unk8.u8[0] == 3) {
            visible = RotTransPers((SVECTOR*)label, (long*)screen, &p, &flag);
        } else {
            visible = 1;
        }

        if (visible <= 0) {
            label->unk8.u8[0] = 0;
            ++removed;
            continue;
        }

        switch (label->unk8.u8[0]) {
        case 1:
            if (label->unk6 <= 0) {
                label->unkE &= 0x7F;
                screen[1] += 8;
                func_80094844(screen, label);

                if (label->unkE == 2) {
                    func_8009506C(screen[0], screen[1], label);
                } else {
                    func_80094B0C(screen[0], screen[1], label);
                }

                label->unkB += vs_gametime_tickspeed / 2;

                if (label->unkB >= 10) {
                    label->unk6 = -1;
                }

                if (label->unkB >= 31) {
                    label->unk8.u8[0] = 0;
                    ++removed;
                }
                break;
            }

            screen[1] += 8;
            func_80094844(screen, label);

            if (label->unkE & 0x80) {
                label->unkE &= 0x7F;
                func_80094AF8(label);
                break;
            }

            label->unkB += vs_gametime_tickspeed / 2;

            if (label->unkB >= 10) {
                func_80094AF8(label);
            }
            break;
        case 2:
            if (label->unk6 <= 0) {
                screen[1] -= label->displayTextLen;

                if (label->unk8.u8[1] != 0 || D_800F227A == 0) {
                    if (label->unkE == 2) {
                        func_8009506C(screen[0], screen[1], label);
                    } else {
                        func_80095258(screen[0], screen[1], label);
                    }
                }

                label->unkB += vs_gametime_tickspeed / 2;

                if (label->unkB >= 10) {
                    label->unk6 = -1;
                }

                if (label->unkB >= 31) {
                    label->unk8.u8[0] = 0;
                    ++removed;
                }
                break;
            }

            label->unkB += vs_gametime_tickspeed / 2;

            if (label->unkB >= 10) {
                func_80094AF8(label);
            }
            break;
        case 3:
            func_8009506C(screen[0], screen[1], label);
            label->unkB += vs_gametime_tickspeed / 2;

            if (label->unkB >= 31) {
                label->unk8.u8[0] = 0;
                ++removed;
            }
            break;
        case 4:
            func_800958A4(44, 48, label);
            label->unkB += vs_gametime_tickspeed / 2;

            if (label->unkB >= 46) {
                label->unk8.u8[0] = 0;
                ++removed;
            }
            break;
        case 5:
            func_80095A4C(44, 64, label);
            label->unkB += vs_gametime_tickspeed / 2;

            if (label->unkB >= 91) {
                label->unk8.u8[0] = 0;
                ++removed;
            }
            break;
        case 6:
            if (label->unk6 >= 0) {
                break;
            }

            func_8009695C(8, 172, label);

            if (D_800F1BA4 != 0) {
                break;
            }

            label->unkB += vs_gametime_tickspeed / 2;

            if (label->unkB >= 61) {
                label->unk8.u8[0] = 0;
                ++removed;
            }
            break;
        case 0:
        case 7:
            break;
        }
    }

    if (removed > 0) {
        func_8009639C(removed);
    }
}

void func_80094844(short* pos, D_800F1BAC_t* label)
{
    int i;

    if (label->unk10 == ONE && label->unk12 == ONE) {
        label->unk10 = 0;
        label->unk12 = 0;

        if (D_800F227C > 0) {
            int x;
            int y;

            for (i = 0; i < D_800F227C; ++i) {
                x = pos[0] - D_800F1CBC[i].vx;
                y = pos[1] - D_800F1CBC[i].vy;

                if (ABS(x) < 24 && ABS(y) < 10) {
                    break;
                }
            }

            if (i != D_800F227C) {
                int j;
                int dx;
                int dy;

                i = 0;

                for (dy = 0; dy < 48; dy += 8) {
                    for (dx = 0; dx < 32; dx += 8) {
                        for (j = 0; j < D_800F227C; ++j) {
                            y = pos[1] + dy - D_800F1CBC[j].vy;

                            if (ABS(y) < 10) {
                                x = pos[0] + dx - D_800F1CBC[j].vx;

                                if (ABS(x) < 24) {
                                    break;
                                }
                            }
                        }

                        if (j == D_800F227C) {
                            i = 1;
                            goto done;
                        }

                        for (j = 0; j < D_800F227C; ++j) {
                            y = pos[1] + dy - D_800F1CBC[j].vy;

                            if (ABS(y) < 10) {
                                x = pos[0] - dx - D_800F1CBC[j].vx;

                                if (ABS(x) < 24) {
                                    break;
                                }
                            }
                        }

                        if (j == D_800F227C) {
                            i = 1;
                            dx = -dx;
                            goto done;
                        }
                    }
                }

            done:
                if (i) {
                    label->unk10 = dx;
                    label->unk12 = dy;
                }
            }
        }
    }

    pos[0] += label->unk10;
    pos[1] += label->unk12;
    D_800F1CBC[D_800F227C].vx = pos[0];
    D_800F1CBC[D_800F227C].vy = pos[1];

    if (pos[0] < 32) {
        pos[0] = 32;
    }

    if (pos[0] > 288) {
        pos[0] = 288;
    }

    if (pos[1] > 200) {
        pos[1] = 200;
    }

    ++D_800F227C;
}

void func_80094AF8(D_800F1BAC_t* arg0)
{
    arg0->unkB = 0;
    arg0->unk6 = arg0->unk6 - 1;
}

void func_80094B0C(int x, int y, D_800F1BAC_t* p)
{
    CVECTOR colors[] = { { 128, 128, 128, 0 }, { 0, 128, 0, 0 }, { 128, 0, 128, 0 },
        { 0, 128, 128, 0 } };
    signed char bounce[] = { 0, -6, -12, -14, -16, -10, -5, -1, 0, -3, -6, -7, -8, -5, -3,
        -1, 0, -2, -1, 0 };
    int frame = 15;
    int color;
    int offset;
    int i;
    POLY_FT4* prim;

    if (p->unkE >= 3) {
        if (!(p->unkC & 0x8000)) {
            y -= p->unkB >> 1;
        } else {
            y += p->unkB >> 1;
        }

        i = func_80094E18(x, y, p);
        color = 0;
        offset = 0;
    } else {
        if (p->unkB < 16) {
            frame = p->unkB;
        }

        color = (p->unkE & 1) << 1;
        i = p->displayTextLen * 3;

        if (!(p->unkC & 0x8000)) {
            offset = bounce[frame];
            ++color;
        } else {
            offset = bounce[frame + 4];
        }
    }

    x += i - 6;
    prim = ((vs_scratch_t*)0x1F800000)->unk0;

    for (i = p->displayTextLen - 1; i >= 0; --i, x -= 6) {
        int digitY = y + offset;

        offset /= 2;

        if (x + 8 >= 328u) {
            continue;
        }

        setPolyFT4(prim);
        setXY4(prim, x, digitY - 6, x + 8, digitY - 6, x, digitY + 6, x + 8, digitY + 6);
        setShadeTex(prim, 0);
        setRGB0(prim, colors[color].r, colors[color].g, colors[color].b);
        setUV4(prim, (p->displayText[i] - '0') * 8 + 64, 0,
            (p->displayText[i] - '0') * 8 + 72, 0, (p->displayText[i] - '0') * 8 + 64, 12,
            (p->displayText[i] - '0') * 8 + 72, 12);
        setTPage(prim, 0, 0, 768, 0);
        setClut(prim, 832, 223);
        AddPrim(((vs_scratch_t*)0x1F800000)->unk4 - 20, prim++);
    }

    ((vs_scratch_t*)0x1F800000)->unk0 = prim;
}

int func_80094E18(int x, int y, D_800F1BAC_t* p)
{
    RECT* rect = &D_80068FAC[D_800E861C[p->unkE - 3]];
    POLY_FT4* prim = ((vs_scratch_t*)0x1F800000)->unk0;
    int sign = p->unkC;
    int width = (p->displayTextLen * 6 + rect->w + 12) / 2;

    x -= width;
    setPolyFT4(prim);
    setXY4(prim, x, y - 6, x + rect->w, y - 6, x, y + 6, x + rect->w, y + 6);
    setShadeTex(prim, 1);
    setUV4(prim, rect->x, rect->y, rect->x + rect->w, rect->y, rect->x, rect->y + 12,
        rect->x + rect->w, rect->y + 12);
    setTPage(prim, 0, 0, 448, 256);
    setClut(prim, 976, 220);
    sign = (sign & 0x8000) ? 0 : 8;
    AddPrim(((vs_scratch_t*)0x1F800000)->unk4 - 20, prim++);
    x += rect->w + 4;
    setPolyFT4(prim);
    setXY4(prim, x, y - 5, x + 8, y - 5, x, y + 5, x + 8, y + 5);
    setUV4(prim, sign + 154, 76, sign + 162, 76, sign + 154, 86, sign + 162, 86);
    setTPage(prim, 0, 0, 768, 0);
    setClut(prim, 864, 223);
    setShadeTex(prim, 1);
    AddPrim(((vs_scratch_t*)0x1F800000)->unk4 - 20, prim++);
    ((vs_scratch_t*)0x1F800000)->unk0 = prim;
    return width;
}

void func_8009506C(int arg0, int arg1, D_800F1BAC_t* arg2)
{
    POLY_FT4* prim;
    int step;
    int y0;
    int y1;
    int i;

    if (arg2->unkB < 4) {
        step = arg2->unkB;
    } else if (arg2->unkB >= 27) {
        step = 30 - arg2->unkB;
    } else {
        step = 4;
    }

    arg0 -= 16;
    y0 = arg1 - D_800E8634[step];
    y1 = arg1 + D_800E8634[step];
    prim = ((vs_scratch_t*)0x1F800000)->unk0;

    for (i = 0; i < 4; ++i) {
        if ((arg0 < 320) && ((arg0 + D_800E8640[i].w) >= 0)) {
            setPolyFT4(prim);
            setXY4(prim, arg0, y0, arg0 + D_800E8640[i].w, y0, arg0, y1,
                arg0 + D_800E8640[i].w, y1);
            setShadeTex(prim, 1);
            setUV4(prim, D_800E8640[i].x, D_800E8640[i].y,
                D_800E8640[i].x + D_800E8640[i].w, D_800E8640[i].y, D_800E8640[i].x,
                D_800E8640[i].y + 10, D_800E8640[i].x + D_800E8640[i].w,
                D_800E8640[i].y + 10);
            setSemiTrans(prim, 1);
            setTPage(prim, 0, 0, 768, 0);
            setClut(prim, 864, 223);
            AddPrim(((vs_scratch_t*)0x1F800000)->unk4 - 20, prim++);
        }

        arg0 += D_800E8640[i].w;
    }

    ((vs_scratch_t*)0x1F800000)->unk0 = prim;
}

void func_80095258(int x, int y, D_800F1BAC_t* p)
{
    short slide[] = { 32, 14, 6, 2 };
    short fade[] = { 5, 9, 13, 15 };
    RECT* rects[2];
    int step;
    int width;
    int i;
    POLY_FT4* prim;

    if (D_800690B4[p->unkC].count == 0) {
        return;
    }
    if (p->unkB < 4) {
        step = p->unkB;

        if (!(p->unkE & 1)) {
            x += slide[step];
        }
    } else if (p->unkB < 6) {
        step = 5;
    } else if (p->unkB >= 27) {
        step = 30 - p->unkB;

        if (!(p->unkE & 1)) {
            x -= slide[step];
        }
    } else {
        step = 4;

        if (p->unkB >= 25) {
            step = 5;
        }
    }
    if ((p->unkE & 1) && p->unkB >= 15) {
        width = p->unkB - 15;

        if (width > 4) {
            width = 4;
        }

        func_800957D0(x, y, width);
    }

    width = 0;

    for (i = 0; i < D_800690B4[p->unkC].count; ++i) {
        rects[i] = &D_80068FAC[D_800690B4[p->unkC].labels[i]];
        width += rects[i]->w;
    }

    x -= width / 2;

    if (p->unkE & 1) {
        width = 0;
    } else {
        width = D_800690B4[p->unkC].color;
    }

    prim = ((vs_scratch_t*)0x1F800000)->unk0;

    for (i = 0; i < D_800690B4[p->unkC].count; ++i) {
        if (x < 320 && x + rects[i]->w >= 0) {
            setPolyFT4(prim);
            setXY4(
                prim, x, y - 6, x + rects[i]->w, y - 6, x, y + 6, x + rects[i]->w, y + 6);
            setShadeTex(prim, 0);

            if (step == 5) {
                setRGB0(prim, D_80069134[width].r / 2 + 96, D_80069134[width].g / 2 + 96,
                    D_80069134[width].b / 2 + 96);
            } else if (step == 4) {
                setRGB0(prim, D_80069134[width].r / 2, D_80069134[width].g / 2,
                    D_80069134[width].b / 2);
            } else {
                setRGB0(prim, D_80069134[width].r * fade[step] / 32,
                    D_80069134[width].g * fade[step] / 32,
                    D_80069134[width].b * fade[step] / 32);
            }

            setUV4(prim, rects[i]->x, rects[i]->y, rects[i]->x + rects[i]->w, rects[i]->y,
                rects[i]->x, rects[i]->y + 12, rects[i]->x + rects[i]->w,
                rects[i]->y + 12);
            setSemiTrans(prim, 1);

            if (step != 4) {
                setTPage(prim, 0, 1, 448, 256);
                setClut(prim, 960, 220);
            } else {
                setTPage(prim, 0, 0, 448, 256);
                setClut(prim, 976, 220);
            }

            AddPrim(((vs_scratch_t*)0x1F800000)->unk4 - 20, prim++);
        }

        x += rects[i]->w;
    }

    ((vs_scratch_t*)0x1F800000)->unk0 = prim;
}

void func_800957D0(int arg0, int arg1, int arg2)
{
    void** p = (void**)0x1F800000;
    POLY_FT4* prim = (POLY_FT4*)p[0];

    setlen(prim, 9);
    setcode(prim, 0x2C);
    arg0 -= 8;
    arg2 <<= 4;
    setXY4(
        prim, arg0, arg1 - 5, arg0 + 16, arg1 - 5, arg0, arg1 + 5, arg0 + 16, arg1 + 5);
    setUV4(
        prim, arg2 + 0x40, 0x30, arg2 + 0x50, 0x30, arg2 + 0x40, 0x3A, arg2 + 0x50, 0x3A);
    prim->tpage = 0x17;
    prim->clut = 0x373E;
    setShadeTex(prim, 1);
    AddPrim((u_long*)p[1] - 5, prim++);
    p[0] = prim;
}

void func_800958A4(int x, int y, D_800F1BAC_t* p)
{
    char* timing[] = { "$TOO   FAST!", "$FAST!", "", "$SLOW!", "$TOO   SLOW!" };
    char* success[] = { "$COOL!", "$GOOD!", "$EXCELLENT!", "$RIGHT   ON!", "$PERFECT!",
        "$WELL   TIMED!", "$NICE!", "$GREAT!" };
    short offsets[] = { 64, 16, 4, 1 };
    int colors[] = { vs_getRGB888(0, 128, 128), vs_getRGB888(32, 128, 96),
        vs_getRGB888(64, 128, 64), vs_getRGB888(96, 128, 32), vs_getRGB888(128, 128, 0) };
    int step;

    if (p->unkB < 4) {
        step = p->unkB;
        x -= offsets[step];
    } else if (p->unkB >= 42) {
        step = 45 - p->unkB;
        x -= offsets[step];
    }

    if (p->unkC != 2) {
        vs_battle_renderTextRawColor(timing[p->unkC], vs_getXY_2(x, y), colors[p->unkC],
            ((vs_scratch_t*)0x1F800000)->unk4 - 16);
    } else {
        vs_battle_renderTextRawColor(success[p->displayTextLen], vs_getXY_2(x, y),
            vs_getRGB888(64, 128, 64), ((vs_scratch_t*)0x1F800000)->unk4 - 16);
    }
}

void func_80095A4C(int x, int y, D_800F1BAC_t* p)
{
    char text[16];
    short offsets[] = { 64, 16, 4, 1 };

    if ((p->unkB < 4) && (p->unkC == 1)) {
        x -= offsets[p->unkB];
    } else if (p->unkB >= 87) {
        x -= offsets[90 - p->unkB];
    }
    if (p->unkC == 1) {
        sprintf(text, "$1 CHAIN");
    } else {
        sprintf(text, "$%d CHAINS", p->unkC);
    }

    vs_battle_renderTextRawColor(text, vs_getXY_2(x, y), vs_getRGB888(160, 64, 16),
        ((vs_scratch_t*)0x1F800000)->unk4 - 16);
}

void func_80095B70(int arg0) { D_800F2270 = arg0; }

void func_80095B7C(int arg0, int arg1)
{
    if (arg0 != 0) {
        if (arg1 & 0x80) {
            D_800F2260[arg0] |= 0x80;
            return;
        }
        if (arg1 & 0x40) {
            D_800F2260[arg0] &= 0x7F;
            return;
        }
        D_800F2260[arg0] &= 0x80;
        D_800F2260[arg0] |= arg1 & 0x7F;
        return;
    }
    memset(D_800F2260, arg1, 0x10);
}

void func_80095C18(int actor, int kind)
{
    SVECTOR position;
    SVECTOR other;
    int _[2] __attribute__((unused));
    long side;
    int xy;
    u_long* prim;
    u_long* ot;

    if (!(kind & 8)) {
        int flags;
        int z;
        int* corners;
        u_short* uv;

        if (kind & 0x80) {
            kind &= 7;

            if (kind < 1 || kind > 4) {
                kind = 5;
            }
        }
        if (func_800A1280(actor, 251, &position, 0)) {
            return;
        }
        if (func_800A1280(0, 251, &other, 0)) {
            return;
        }

        z = position.vz - 16;
        xy = *(int*)&position;

        if (other.vx + 32 < position.vx) {
            D_800F2274 &= ~(1 << actor);
        }
        if (position.vx < other.vx - 32) {
            D_800F2274 |= 1 << actor;
        }
        if (z < 64) {
            z = 64;
        } else if (z >= 2048) {
            z = 2047;
        }

        ot = (u_long*)((vs_scratch_t*)0x1F800000)->unk4 + z;
        side = (D_800F2274 >> actor) & 1;

        switch (kind) {
        case 0:
            return;
        case 1:
        case 2:
        case 3:
            while (kind) {
                --kind;
                vs_battle_setSprite(128, xy + kind * 6 + D_80068F94[side], vs_getWH(5, 5),
                    ot)[4] = vs_getUV0Clut(90, 18, 992, 220);
            }
            break;
        case 4:
            flags = 0;

            if (position.vx < 16) {
                position.vx = 16;
                flags = 1;
            }
            if (position.vx > 304) {
                position.vx = 304;
                flags |= 2;
            }
            if (flags) {
                if (position.vy < 40) {
                    position.vy = 40;
                    flags |= 4;
                }
            } else if (position.vy < 8) {
                position.vy = 40;
                flags = 4;
            }
            if (position.vy > 208) {
                position.vy = 208;
                flags |= 8;
            }
            if (flags) {
                func_8009651C(&position, flags);
                return;
            }

            side += 2;
            vs_battle_setSprite(128, xy + D_80068F94[side], vs_getWH(7, 12), ot)[4] =
                vs_getUV0Clut(152, 17, 992, 220);
            break;
        case 5:
            vs_battle_setSprite(128, xy + D_80068F94[side] + vs_getXY(2, -3),
                vs_getWH(16, 16), ot)[4] = vs_getUV0Clut(152, 32, 992, 220);
            break;
        case 6:
            side += 4;
            break;
        case 7:
            prim = vs_battle_setSprite(128, xy + vs_getXY(0, -22), vs_getWH(7, 12), ot);
            prim[1] = _get_mode(0, 0, getTPage(0, 0, 448, 256));
            prim[4] = vs_getUV0Clut(183, 17, 992, 220);
            return;
        }

        prim = ((vs_scratch_t*)0x1F800000)->unk0;
        corners = D_80068F04[side];
        uv = D_80068F64[side];
        prim[0] = vs_getTag(VS_POLY_FT4, *ot);
        prim[1] = vs_getRGB0(primPolyFT4, 128, 128, 128);
        prim[2] = func_80096254(xy, corners[0]);
        prim[3] = uv[0] | (getClut(992, 220) << 16);
        prim[4] = func_80096254(xy, corners[1]);
        prim[5] = uv[1] | (getTPage(0, 0, 448, 256) << 16);
        prim[6] = func_80096254(xy, corners[2]);
        prim[7] = uv[2];
        prim[8] = func_80096254(xy, corners[3]);
        prim[9] = uv[3];
        *ot = ((u_long)prim << 8) >> 8;
        ((vs_scratch_t*)0x1F800000)->unk0 = prim + 10;
    } else {
        long depth;

        if (func_800A190C(actor, 255, &other, 0) == 0) {
            if (func_800A190C(0, 255, &position, 0)) {
                return;
            }

            position.vx -= other.vx;
            position.vz -= other.vz;
            side = ABS(position.vx) + ABS(position.vz);

            if (side < 352) {
                D_800F2274 &= ~(1 << actor);
            }
            if (side > 416) {
                D_800F2274 |= 1 << actor;
            }

            side = (D_800F2274 >> actor) & 1;

            if (side) {
                return;
            }

            SetRotMatrix(&((vs_scratch_t*)0x1F800000)->viewMatrix);
            SetTransMatrix(&((vs_scratch_t*)0x1F800000)->viewMatrix);
            other.vy -= 64;
            RotTransPers(&other, (long*)&position, &depth, &side);
            ot = ((vs_scratch_t*)0x1F800000)->unk4;
            position.vx -= 8;
            position.vy -= 8;
            xy = *(int*)&position;
            depth = func_8009F858(actor);

            if (depth >= 0) {
                if (depth == 0) {
                    ++D_800F2260[actor];

                    if (!(D_800F2260[actor] & 7)) {
                        D_800F2260[actor] = 0;
                    }
                }

                prim = vs_battle_setSprite(128, xy, vs_getWH(16, 16), ot);
                prim[1] = _get_mode(0, 0, getTPage(0, 0, 768, 0));
                prim[4] = ((depth << 4) + 96) | vs_getUV0Clut(0, 32, 976, 223);
                return;
            }
        }

        D_800F2260[actor] = 0;
    }
}

int func_80096254(int arg0, int arg1)
{
    return (((arg0 & 0xFFFF) + (arg1 & 0xFFFF)) & 0xFFFF)
         | (((arg0 >> 0x10) + (arg1 >> 0x10)) << 0x10);
}

void func_8009627C(void)
{
    int i;

    if (D_800F2270 == 0) {
        for (i = 1; i < 16; ++i) {
            if (D_800F2260[i] != 0) {
                func_80095C18(i, D_800F2260[i]);
            }
        }
    }
}

void* func_800962E4(void)
{
    D_800F1BAC_t* p;
    int i;

    if (D_800F227E < 32) {
        p = &(*D_800F1BAC)[D_800F227E];
    } else {
        for (i = 0; i < 31; ++i) {
            vs_main_memcpy(
                &(*D_800F1BAC)[i], &(*D_800F1BAC)[i + 1], sizeof(*D_800F1BAC)[i]);
        }
        vs_main_bzero(&(*D_800F1BAC)[31], sizeof(*D_800F1BAC)[31]);
        p = &(*D_800F1BAC)[31];
    }
    return p;
}

void func_8009639C(int arg0)
{
    int j;
    int i;

    for (i = 0; i < arg0; ++i) {
        for (j = 0; j < D_800F227E; ++j) {
            if ((*D_800F1BAC)[j].unk8.u8[0] == 0) {
                func_80096444(j);
                break;
            }
        }
    }
}

void func_80096444(int arg0)
{
    int i;

    --D_800F227E;
    if (arg0 != D_800F227E) {
        for (i = arg0; i < D_800F227E; ++i) {
            vs_main_memcpy(
                &(*D_800F1BAC)[i], &(*D_800F1BAC)[i + 1], sizeof(*D_800F1BAC)[i]);
        }
    }
    vs_main_bzero(&(*D_800F1BAC)[D_800F227E], sizeof(*D_800F1BAC)[D_800F227E]);
}

void func_8009651C(SVECTOR* position, int direction)
{
    int dx[] = { -8, 0, 7, 10, 7, 0, -8, -11 };
    int dy[] = { -8, -11, -8, 0, 7, 10, 7, 0 };
    int x = position->vx;
    int y = position->vy;
    int index;
    POLY_FT4* prim;

    if (direction == 4) {
        index = 0;
    } else if (direction == 6) {
        index = 1;
    } else if (direction == 2) {
        index = 2;
    } else if (direction == 10) {
        index = 3;
    } else if (direction == 8) {
        index = 4;
    } else if (direction == 9) {
        index = 5;
    } else if (direction == 1) {
        index = 6;
    } else if (direction == 5) {
        index = 7;
    } else {
        return;
    }

    prim = ((vs_scratch_t*)0x1F800000)->unk0;
    setPolyFT4(prim);
    setShadeTex(prim, 1);
    setXY0(prim, dx[index] + x, dy[index] + y);
    index += 2;
    index &= 7;
    prim->x1 = dx[index] + x;
    prim->y1 = dy[index] + y;
    index += 2;
    index &= 7;
    prim->x3 = dx[index] + x;
    prim->y3 = dy[index] + y;
    index += 2;
    index &= 7;
    prim->x2 = dx[index] + x;
    prim->y2 = dy[index] + y;
    setUV4(prim, 48, 48, 63, 48, 48, 63, 63, 63);
    setTPage(prim, 0, 0, 768, 0);
    setClut(prim, 976, 223);
    AddPrim(((vs_scratch_t*)0x1F800000)->unk4 - 16, prim++);
    ((vs_scratch_t*)0x1F800000)->unk0 = prim;
}

int func_80096768(int arg0, int arg1, int arg2)
{
    int _[2] __attribute__((unused));
    int i;
    int count;
    D_800F1BAC_t* p;

    if ((vs_main_settings.weaponStatChange && (arg0 == 240))
        || (vs_main_settings.armorStatChange && (arg0 != 240))) {
        switch (arg0) {
        case 1:
            arg0 = 4;
            break;

        case 2:
            arg0 = 2;
            break;

        case 3:
            arg0 = 3;
            break;

        case 4:
            arg0 = 6;
            break;

        case 6:
            arg0 = 5;
            break;

        case 241:
            arg0 = 1;
            break;

        case 240:
            arg0 = 0;
            break;
        }

        p = *D_800F1BAC;
        count = 0;

        for (i = 0; i < D_800F227E; ++i, ++p) {
            if ((p->unk8.u8[0] == 6) || (p->unk8.u8[0] == 7)) {
                ++count;
            }
        }

        p = func_800962E4();
        p->unk8.u8[0] = 7;
        p->unk8.u8[1] = 0x7F;
        p->unk6 = count;
        p->unk12 = 0;
        p->unkB = 0;
        p->unkE = arg0;
        p->unkA = arg1;

        if ((arg2 & 0x7FFF) >= 1000) {
            p->unkC = 999 | ((arg2 & 0x80000000) >> 16);
        } else {
            p->unkC = (arg2 & 0x7FFF) | ((arg2 & 0x80000000) >> 16);
        }

        sprintf(p->displayText, D_800691E4, p->unkC & 0x7FFF);
        p->displayTextLen = strlen(p->displayText);
        ++D_800F227E;
    }

    return 0;
}

void func_8009695C(int x, int y, D_800F1BAC_t* p)
{
    CVECTOR colors[] = { { 128, 64, 0, 0 }, { 0, 64, 128, 0 } };
    int negative;
    int positive;
    int i;
    POLY_FT4* prim = ((vs_scratch_t*)0x1F800000)->unk0;

    y -= p->unk12;
    negative = p->unkC & 0x8000;
    positive = !negative;

    setPolyFT4(prim);
    setRGB0(prim, colors[positive].r, colors[positive].g, colors[positive].b);
    setXY4(prim, x, y, x + D_80069144[p->unkE].w, y, x, y + D_80069144[p->unkE].h,
        x + D_80069144[p->unkE].w, y + D_80069144[p->unkE].h);
    setUV4(prim, D_80069144[p->unkE].x, D_80069144[p->unkE].y,
        D_80069144[p->unkE].x + D_80069144[p->unkE].w, D_80069144[p->unkE].y,
        D_80069144[p->unkE].x, D_80069144[p->unkE].y + D_80069144[p->unkE].h,
        D_80069144[p->unkE].x + D_80069144[p->unkE].w,
        D_80069144[p->unkE].y + D_80069144[p->unkE].h);
    setTPage(prim, 0, 0, 768, 0);
    setClut(prim, 848, 223);
    AddPrim(((vs_scratch_t*)0x1F800000)->unk4 + 8, prim++);

    x += D_80069144[p->unkE].w + 2;
    setPolyFT4(prim);
    setRGB0(prim, colors[positive].r, colors[positive].g, colors[positive].b);
    setXY4(prim, x, y, x + D_8006917C[p->unkA].w, y, x, y + D_8006917C[p->unkA].h,
        x + D_8006917C[p->unkA].w, y + D_8006917C[p->unkA].h);
    setUV4(prim, D_8006917C[p->unkA].x, D_8006917C[p->unkA].y,
        D_8006917C[p->unkA].x + D_8006917C[p->unkA].w, D_8006917C[p->unkA].y,
        D_8006917C[p->unkA].x, D_8006917C[p->unkA].y + D_8006917C[p->unkA].h,
        D_8006917C[p->unkA].x + D_8006917C[p->unkA].w,
        D_8006917C[p->unkA].y + D_8006917C[p->unkA].h);
    setTPage(prim, 0, 0, 768, 0);
    setClut(prim, 848, 223);
    AddPrim(((vs_scratch_t*)0x1F800000)->unk4 + 8, prim++);

    x += D_8006917C[p->unkA].w + 2;
    setPolyFT4(prim);
    setRGB0(prim, colors[positive].r, colors[positive].g, colors[positive].b);
    setXY4(prim, x, y - 1, x + 8, y - 1, x, y + 7, x + 8, y + 7);
    setUV4(prim, positive * 8 + 120, 208, positive * 8 + 128, 208, positive * 8 + 120,
        216, positive * 8 + 128, 216);
    setTPage(prim, 0, 0, 768, 0);
    setClut(prim, 848, 223);
    AddPrim(((vs_scratch_t*)0x1F800000)->unk4 + 8, prim++);

    x += 2;
    x += p->displayTextLen * 5;

    for (i = p->displayTextLen - 1; i >= 0; --i, x -= 5) {
        setPolyFT4(prim);
        setRGB0(prim, colors[positive].r, colors[positive].g, colors[positive].b);
        prim->x0 = x;
        prim->x1 = x + 6;
        prim->y0 = y - 1;
        prim->y1 = y - 1;
        prim->x2 = x;
        prim->y2 = y + 9;
        prim->x3 = x + 6;
        prim->y3 = y + 9;
        setUV4(prim, (p->displayText[i] - '0') * 6, 0, (p->displayText[i] - '0') * 6 + 6,
            0, (p->displayText[i] - '0') * 6, 10, (p->displayText[i] - '0') * 6 + 6, 10);
        setTPage(prim, 0, 0, 768, 0);
        setClut(prim, 832, 223);
        AddPrim(((vs_scratch_t*)0x1F800000)->unk4 + 8, prim++);
    }

    ((vs_scratch_t*)0x1F800000)->unk0 = prim;
}

void func_80096FF0(int arg0)
{
    int d;

    if (!vs_main_settings.abilityTimingDisplay) {
        return;
    }

    if (func_800A1280(0, 0xFB, &D_800F2280, 0) != 0) {
        return;
    }

    if (D_800F2280.vy < 40) {
        d = 40 - D_800F2280.vy;
        D_800F2280.vy = 40;
        if (D_800F2280.vx + d < 288) {
            D_800F2280.vx += d;
        } else {
            D_800F2280.vx -= d;
        }
        D_800F2280.vy += d;
    }

    D_800F2272 += arg0;
}

void func_800970BC(void)
{
    void** p = (void**)0x1F800000;
    POLY_FT4* prim = (POLY_FT4*)p[0];

    setPolyFT4(prim);
    setXY4(prim, D_800F2280.vx - 11, D_800F2280.vy - 32, D_800F2280.vx + 11,
        D_800F2280.vy - 32, D_800F2280.vx - 11, D_800F2280.vy, D_800F2280.vx + 11,
        D_800F2280.vy);
    setUV4(prim, 0xC0, 0, 0xD6, 0, 0xC0, 0x20, 0xD6, 0x20);
    setRGB0(prim, 0xF0, 0x40, 0x20);
    setTPage(prim, 0, 0, 448, 256);
    setClut(prim, 960, 221);
    AddPrim((u_long*)p[1] - 5, prim++);
    p[0] = prim;
}

void func_800971D4(void)
{
    int i;
    D_800F1BAC_t* p = *D_800F1BAC;

    for (i = 0; i < D_800F227E; ++i, ++p) {
        if (p->unk8.u8[0] == 7) {
            p->unk8.u8[0] = 6;
        }
    }
}

void func_8009722C(void) { D_800F227A = 1; }
