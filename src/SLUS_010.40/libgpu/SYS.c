#include "common.h"
#include <libgte.h>
#include <libgpu.h>
#include <libetc.h>

extern u_char D_80033446;
extern u_long* D_80033548;
extern u_long* D_8003354C;
extern u_long* D_80033550;
extern u_long* D_80033554;
extern u_long* D_80033558;
extern int D_80033580;
extern int D_80033584;

typedef struct {
    char* ver;
    int (*addque)();
    int (*addque2)();
    int (*clr)();
    int (*ctl)();
    int (*cwb)();
    int (*cwc)();
    int (*drs)();
    int (*dws)();
    int (*exeque)();
    int (*getctl)();
    int (*otc)();
    int (*param)();
    int (*reset)();
    u_long (*status)();
    int (*sync)();
} gpu_t;
extern gpu_t* D_8003343C;

int DMACallback(int, void (*)(void));
int func_8002A3E8(int, int, int, int);
void func_8002A698(void);

INCLUDE_RODATA("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", D_80010864);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", ResetGraph);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", SetGraphDebug);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", SetGraphQueue);

int GetGraphDebug(void) { return D_80033446; }

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", DrawSyncCallback);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", SetDispMask);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", DrawSync);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", func_800286B8);

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

int GetODE(void) { return D_8003343C->status() >> 31; }

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", SetDrawArea);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", SetDrawOffset);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", SetDrawEnv);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", func_80029694);

u_long func_80029904(int dfe, int dtd, int tpage)
{
    return (dtd ? 0xE1000200 : 0xE1000000) | (dfe ? 0x400 : 0) | (tpage & 0x9FF);
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", func_80029924);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", func_800299BC);

u_long func_80029A54(int x, int y)
{
    return 0xE5000000 | ((y & 0x7FF) << 11) | (x & 0x7FF);
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", func_80029A70);

u_long func_80029AF0(void) { return *D_8003354C; }

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", func_80029B08);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", func_80029BE8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", func_80029E18);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", func_8002A054);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", func_8002A2D4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", func_8002A2F8);

int func_8002A30C(u_long* p, int n)
{
    int i = n - 1;

    *D_8003354C = 0x04000000;
    if (n != 0) {
        do {
            *D_80033548 = *p++;
            i--;
        } while (i != -1);
    }
    return 0;
}

void func_8002A34C(u_long madr)
{
    *D_8003354C = 0x04000002;
    *D_80033550 = madr;
    *D_80033554 = 0;
    *D_80033558 = 0x01000401;
}

u_long func_8002A394(u_long n)
{
    *D_8003354C = n | 0x10000000;
    return *D_80033548 & 0xFFFFFF;
}

int func_8002A3C4(int a, int b, int c) { return func_8002A3E8(a, b, 0, c); }

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", func_8002A3E8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", func_8002A698);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", func_8002A8F8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", func_8002AA48);

void func_8002AB84(void)
{
    D_80033580 = VSync(-1) + 240;
    D_80033584 = 0;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", func_8002ABB8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", func_8002ACFC);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", LoadImage2);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", StoreImage2);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", MoveImage2);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", DrawOTag2);

void _GPU_ResetCallback(void) { DMACallback(2, func_8002A698); }

void func_8002B1DC(u_char* p, int c, int n)
{
    int i = n - 1;

    if (n != 0) {
        do {
            *p++ = c;
            i--;
        } while (i != -1);
    }
}
