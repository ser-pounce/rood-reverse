#pragma once
#include "common.h"
#include <libgte.h>
#include <libgpu.h>
#include <libetc.h>
#include <memory.h>

extern volatile u_long* D_80033548;
extern volatile u_long* D_8003354C;
extern volatile u_long* D_80033550;
extern volatile u_long* D_80033554;
extern volatile u_long* D_80033558;
extern int D_80033580;
extern int D_80033584;
extern u_char D_8003E2F8[];

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

/* libgpu global state (0x80 bytes, cleared by ResetGraph) */
typedef struct {
    u_char version; /* 0x00: GPU type returned by the reset */
    u_char unk1; /* 0x01 */
    u_char level; /* 0x02: debug level */
    u_char reverse; /* 0x03 */
    short w; /* 0x04 */
    short h; /* 0x06 */
    volatile int unk8; /* 0x08: set by _addque2, cleared before the DrawSync callback */
    void (*drawSyncCB)(void); /* 0x0C */
    DRAWENV draw; /* 0x10 */
    DISPENV disp; /* 0x6C */
} GpuEnv;

extern GpuEnv D_80033444;
extern int (*D_80033440)(); /* GPU_printf */
extern u_long D_800334F0[]; /* terminating primitive */
extern u_long D_80033504; /* tag linking to it */
extern volatile u_long* D_8003355C; /* DMA6 MADR */
extern volatile u_long* D_80033560; /* DMA6 BCR */
extern volatile u_long* D_80033564; /* DMA6 CHCR */
extern volatile u_long* D_80033568; /* DMA DPCR */
extern volatile int D_8003356C; /* command queue write index */
extern volatile int D_80033570; /* command queue read index */

int func_8002A3E8(int (*exec)(), u_long* p1, int len, u_long p2);
int func_8002A698(void);
void func_800286B8(char* name, RECT* rect);
void func_80029694(DR_ENV* dr_env, DRAWENV* env);
u_long func_80029924(short x, short y);
u_long func_800299BC(short x, short y);
u_long func_80029A54(int x, int y);
void func_8002B1DC(u_char* p, int c, int n);
inline void func_8002AB84(void);
int func_8002ABB8(void);
void _GPU_ResetCallback(void);

typedef struct {
    int unk0[3];
    u_long move[5]; /* 0x800334DC: VRAM->VRAM copy packet */
} GpuData334D0;
extern GpuData334D0 D_800334D0;

extern gpu_t D_800333FC;
extern int D_800334C4[];
extern int func_8002A8F8(int);
extern void GPU_cw(u_long*);
extern int printf(const char*, ...);
