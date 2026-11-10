#include "common.h"
#include "gpu.h"
#include "src/SLUS_010.40/libetc/INTR.h"
#include <libgte.h>
#include <libgpu.h>
#include <libetc.h>
#include <stdio.h>

typedef struct {
    u_char type;
    u_char unk1;
    u_char level;
    u_char reverse;
    short w;
    short h;
    volatile int unk8;
    void (*drawSyncCallback)(void);
} D_80033444_t;

typedef struct {
    void (*exec)(void*, void*);
    void* arg0;
    void* arg1;
    u_int data[21];
} D_8003E400_t;

int SetIntrMask(int);
u_int func_80029904(int, int, int);
u_int func_80029924(short, short);
u_int func_800299BC(short, short);
u_int func_80029A54(short, short);
u_int func_80029A70(RECT*);
void func_8002A34C(u_long*);
int func_8002A394(int);
void func_8002A698(void);
void func_8002AB84(void);
int func_8002ABB8(void);
int func_8002ACFC(int);
void func_8002B1DC(void*, int, int);

extern D_80033444_t D_80033444;
extern u_int* D_8003354C;
extern u_int* D_80033550;
extern u_int* D_80033558;
extern u_int* D_80033568;
extern volatile int _qin;
extern volatile int _qout;
extern int D_80033574;
extern int D_8003357C;
extern int D_80033580;
extern int D_80033584;
extern u_long D_8003E2B0[];
extern u_long D_8003E2D8[];
extern u_char D_8003E2F8[0x100];
extern volatile D_8003E400_t D_8003E400[64];

INCLUDE_RODATA("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", D_80010864);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", ResetGraph);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", SetGraphDebug);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", SetGraphQueue);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", GetGraphDebug);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", DrawSyncCallback);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", SetDispMask);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", DrawSync);

void func_800286B8(char* name, RECT* rect)
{
    switch (D_80033444.level) {
    case 1:
        if ((rect->w > D_80033444.w) || (rect->w + rect->x > D_80033444.w)
            || (rect->y > D_80033444.h) || (rect->y + rect->h > D_80033444.h)
            || (rect->w <= 0) || (rect->x < 0) || (rect->y < 0) || (rect->h <= 0)) {
            GPU_printf("%s:bad RECT", name);
            GPU_printf("(%d,%d)-(%d,%d)\n", rect->x, rect->y, rect->w, rect->h);
        }
        break;

    case 2:
        GPU_printf("%s:", name);
        GPU_printf("(%d,%d)-(%d,%d)\n", rect->x, rect->y, rect->w, rect->h);
        break;
    }
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", ClearImage);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", ClearImage2);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", LoadImage);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", StoreImage);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", MoveImage);

INCLUDE_RODATA("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", D_8001099C);

INCLUDE_RODATA("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", D_800109A8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", ClearOTag);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", ClearOTagR);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", DrawPrim);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", DrawOTag);

INCLUDE_RODATA("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", D_800109E4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", PutDrawEnv);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", DrawOTagEnv);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", GetDrawEnv);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", PutDispEnv);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", GetDispEnv);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", GetODE);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", SetDrawArea);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", SetDrawOffset);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", SetDrawEnv);

void func_80029694(DR_ENV* dr_env, DRAWENV* env)
{
    u_long* code = (u_long*)dr_env;
    RECT rect;
    int len;

    code[1] = func_80029924(env->clip.x, env->clip.y);
    code[2] = func_800299BC(env->clip.w + env->clip.x - 1, env->clip.y + env->clip.h - 1);
    code[3] = func_80029A54(env->ofs[0], env->ofs[1]);
    code[4] = func_80029904(env->dfe, env->dtd, env->tpage);
    code[5] = func_80029A70(&env->tw);
    code[6] = primMask << 24;

    len = 7;

    if (env->isbg) {
        setRECT(&rect, env->clip.x, env->clip.y, env->clip.w, env->clip.h);
        setWH(&rect,
            rect.w < 0                  ? 0
            : rect.w > D_80033444.w - 1 ? D_80033444.w - 1
                                        : rect.w,
            rect.h < 0                  ? 0
            : rect.h > D_80033444.h - 1 ? D_80033444.h - 1
                                        : rect.h);

        if ((rect.x & 0x3F) || (rect.w & 0x3F)) {
            rect.x -= env->ofs[0];
            rect.y -= env->ofs[1];
            code[len++] = (primTile << 24) | (env->b0 << 16) | (env->g0 << 8) | env->r0;
            code[len++] = *(u_long*)&rect.x;
            code[len++] = *(u_long*)&rect.w;
        } else {
            code[len++] =
                (primRectFill << 24) | (env->b0 << 16) | (env->g0 << 8) | env->r0;
            code[len++] = *(u_long*)&rect.x;
            code[len++] = *(u_long*)&rect.w;
        }
    }

    setlen(code, len - 1);
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", func_80029904);

u_int func_80029924(short x, short y)
{
    x = x < 0 ? 0 : x > D_80033444.w - 1 ? D_80033444.w - 1 : x;
    y = y < 0 ? 0 : y > D_80033444.h - 1 ? D_80033444.h - 1 : y;
    return 0xE3000000 | ((y & 0x3FF) << 10) | (x & 0x3FF);
}

u_int func_800299BC(short x, short y)
{
    x = x < 0 ? 0 : x > D_80033444.w - 1 ? D_80033444.w - 1 : x;
    y = y < 0 ? 0 : y > D_80033444.h - 1 ? D_80033444.h - 1 : y;
    return 0xE4000000 | ((y & 0x3FF) << 10) | (x & 0x3FF);
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", func_80029A54);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", func_80029A70);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", func_80029AF0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", func_80029B08);

int func_80029BE8(RECT* rect, u_int color)
{
    setWH(rect,
        rect->w < 0                  ? 0
        : rect->w > D_80033444.w - 1 ? D_80033444.w - 1
                                     : rect->w,
        rect->h < 0                  ? 0
        : rect->h > D_80033444.h - 1 ? D_80033444.h - 1
                                     : rect->h);

    if (rect->x & 0x3F || rect->w & 0x3F) {
        D_8003E2B0[0] = ((u_long)D_8003E2D8 & 0xFFFFFF) | 0x08000000;
        D_8003E2B0[1] = 0xE3000000;
        D_8003E2B0[2] = 0xE4FFFFFF;
        D_8003E2B0[3] = 0xE5000000;
        D_8003E2B0[4] = 0xE6000000;
        D_8003E2B0[5] = 0xE1000000 | (*D_8003354C & 0x7FF) | ((color >> 31) << 10);
        D_8003E2B0[6] = 0x60000000 | (color & 0xFFFFFF);
        D_8003E2B0[7] = *(u_long*)&rect->x;
        D_8003E2B0[8] = *(u_long*)&rect->w;
        D_8003E2D8[0] = 0x03FFFFFF;
        D_8003E2D8[1] = func_8002A394(3) | 0xE3000000;
        D_8003E2D8[2] = func_8002A394(4) | 0xE4000000;
        D_8003E2D8[3] = func_8002A394(5) | 0xE5000000;
    } else {
        D_8003E2B0[0] = 0x05FFFFFF;
        D_8003E2B0[1] = 0xE6000000;
        D_8003E2B0[2] = 0xE1000000 | (*D_8003354C & 0x7FF) | ((color >> 31) << 10);
        D_8003E2B0[3] = 0x02000000 | (color & 0xFFFFFF);
        D_8003E2B0[4] = *(u_long*)&rect->x;
        D_8003E2B0[5] = *(u_long*)&rect->w;
    }

    func_8002A34C(D_8003E2B0);
    return 0;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", func_80029E18);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", func_8002A054);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", func_8002A2D4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", func_8002A2F8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", func_8002A30C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", func_8002A34C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", func_8002A394);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", func_8002A3C4);

int func_8002A3E8(void (*exec)(void*, void*), u_int* arg0, int size, void* arg1)
{
    int i;

    func_8002AB84();

    while (((_qin + 1) & 0x3F) == _qout) {
        if (func_8002ABB8()) {
            return -1;
        }

        func_8002A698();
    }

    D_80033574 = SetIntrMask(0);
    D_80033444.unk8 = 1;

    if (D_80033444.unk1 == 0
        || (_qin == _qout && !(*(volatile u_int*)D_80033558 & 0x1000000)
            && D_80033444.drawSyncCallback == NULL)) {
        while (!(*(volatile u_int*)D_8003354C & 0x4000000)) { }
        exec(arg0, arg1);
        SetIntrMask(D_80033574);
        return 0;
    }

    DMACallback(2, func_8002A698);

    if (size) {
        for (i = 0; i < size / 4; ++i) {
            D_8003E400[_qin].data[i] = arg0[i];
        }

        D_8003E400[_qin].arg0 = (void*)D_8003E400[_qin].data;
    } else {
        D_8003E400[_qin].arg0 = arg0;
    }

    D_8003E400[_qin].arg1 = arg1;
    D_8003E400[_qin].exec = exec;
    _qin = (_qin + 1) & 0x3F;
    SetIntrMask(D_80033574);
    func_8002A698();
    return (_qin - _qout) & 0x3F;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", func_8002A698);

int func_8002A8F8(int mode)
{
    D_8003357C = SetIntrMask(0);
    _qin = _qout = 0;

    switch (mode & 7) {
    case 0:
    case 5:
        *D_80033558 = 0x401;
        *D_80033568 |= 0x800;
        *D_8003354C = 0;
        func_8002B1DC(D_8003E2F8, 0, sizeof D_8003E2F8);
        func_8002B1DC((void*)D_8003E400, 0, sizeof D_8003E400);
        break;

    case 1:
    case 3:
        *D_80033558 = 0x401;
        *D_80033568 |= 0x800;
        *D_8003354C = 0x2000000;
        *D_8003354C = 0x1000000;
        break;
    }

    SetIntrMask(D_8003357C);

    if ((mode & 7) == 0) {
        return func_8002ACFC(mode);
    }

    return 0;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", func_8002AA48);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", func_8002AB84);

int func_8002ABB8(void)
{
    if ((VSync(-1) > D_80033580) || (D_80033584++ > 0xF0000)) {
        volatile u_int* status = D_8003354C;

        *status;
        printf("GPU timeout:que=%d,stat=%08x,chcr=%08x,madr=%08x\n",
            (_qin - _qout) & 0x3F, *status, *D_80033558, *D_80033550);
        D_8003357C = SetIntrMask(0);
        _qin = _qout = 0;
        *D_80033558 = 0x401;
        *D_80033568 |= 0x800;
        *D_8003354C = 0x2000000;
        *D_8003354C = 0x1000000;
        SetIntrMask(D_8003357C);
        return -1;
    }

    return 0;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", func_8002ACFC);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", LoadImage2);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", StoreImage2);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", MoveImage2);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", DrawOTag2);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", _GPU_ResetCallback);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", func_8002B1DC);
