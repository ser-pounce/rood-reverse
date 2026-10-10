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
    int unk8; /* 0x08 */
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

int func_8002A3E8(int, int, int, int);
void func_8002A698(void);
void func_800286B8(char* name, RECT* rect);
void func_80029694(DR_ENV* dr_env, DRAWENV* env);
u_long func_80029924(short x, short y);
u_long func_800299BC(short x, short y);
u_long func_80029A54(int x, int y);
void func_8002B1DC(u_char* p, int c, int n);
inline void func_8002AB84(void);
int func_8002ABB8(void);
void _GPU_ResetCallback(void);

INCLUDE_RODATA("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", D_80010864);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", ResetGraph);

int SetGraphDebug(int level)
{
    u_char old = D_80033444.level;

    if ((D_80033444.level = level)) {
        D_80033440("SetGraphDebug:level:%d,type:%d reverse:%d\n", D_80033444.level,
            D_80033444.version, D_80033444.reverse);
    }
    return old;
}

int SetGraphQueue(int mode)
{
    u_char old = D_80033444.unk1;

    if (D_80033444.level >= 2) {
        D_80033440("SetGrapQue(%d)...\n", mode);
    }
    if (mode != D_80033444.unk1) {
        D_8003343C->reset(1);
        D_80033444.unk1 = mode;
        DMACallback(2, NULL);
    }
    return old;
}

int GetGraphDebug(void) { return D_80033444.level; }

u_long DrawSyncCallback(void (*func)(void))
{
    void (*old)(void);

    if (D_80033444.level >= 2) {
        D_80033440("DrawSyncCallback(%08x)...\n", func);
    }
    old = D_80033444.drawSyncCB;
    D_80033444.drawSyncCB = func;
    return (u_long)old;
}

void SetDispMask(int mask)
{
    if (D_80033444.level >= 2) {
        D_80033440("SetDispMask(%d)...\n", mask);
    }
    if (mask == 0) {
        func_8002B1DC((u_char*)&D_80033444.disp, -1, sizeof(DISPENV));
    }
    D_8003343C->ctl(mask ? 0x03000000 : 0x03000001);
}

int DrawSync(int mode)
{
    if (D_80033444.level >= 2) {
        D_80033440("DrawSync(%d)...\n", mode);
    }
    return D_8003343C->sync(mode);
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", func_800286B8);

int ClearImage(RECT* rect, u_char r, u_char g, u_char b)
{
    func_800286B8("ClearImage", rect);
    return D_8003343C->addque2(D_8003343C->clr, rect, 8, (b << 16) | (g << 8) | r);
}

int ClearImage2(RECT* rect, u_char r, u_char g, u_char b)
{
    func_800286B8("ClearImage2", rect);
    return D_8003343C->addque2(
        D_8003343C->clr, rect, 8, 0x80000000 | (b << 16) | (g << 8) | r);
}

int LoadImage(RECT* rect, u_long* p)
{
    func_800286B8("LoadImage", rect);
    return D_8003343C->addque2(D_8003343C->dws, rect, 8, p);
}

int StoreImage(RECT* rect, u_long* p)
{
    func_800286B8("StoreImage", rect);
    return D_8003343C->addque2(D_8003343C->drs, rect, 8, p);
}

typedef struct {
    int unk0[3];
    u_long move[5]; /* 0x800334DC: VRAM->VRAM copy packet */
} GpuData334D0;
extern GpuData334D0 D_800334D0;

int MoveImage(RECT* rect, int x, int y)
{
    func_800286B8("MoveImage", rect);
    if (rect->w == 0 || rect->h == 0) {
        return -1;
    }
    D_800334D0.move[2] = *(u_long*)&rect->x;
    D_800334D0.move[3] = (y << 16) | (x & 0xFFFF);
    D_800334D0.move[4] = *(u_long*)&rect->w;
    return D_8003343C->addque2(D_8003343C->cwc, D_800334D0.move, 0x14, 0);
}

u_long* ClearOTag(u_long* ot, int n)
{
    u_long* term;

    if (D_80033444.level >= 2) {
        D_80033440("ClearOTag(%08x,%d)...\n", ot, n);
    }
    while (--n) {
        setlen(ot, 0);
        setaddr(ot, ot + 1);
        ot++;
    }
    term = &D_80033504;
    *term = ((u_long)D_800334F0 & 0xFFFFFF) | 0x04000000;
    *ot = (u_long)term & 0xFFFFFF;
    return ot;
}

u_long* ClearOTagR(u_long* ot, int n)
{
    u_long* term;

    if (D_80033444.level >= 2) {
        D_80033440("ClearOTagR(%08x,%d)...\n", ot, n);
    }
    D_8003343C->otc(ot, n);
    term = &D_80033504;
    *term = ((u_long)D_800334F0 & 0xFFFFFF) | 0x04000000;
    *ot = (u_long)term & 0xFFFFFF;
    return ot;
}

void DrawPrim(void* p)
{
    int len = ((P_TAG*)p)->len;

    D_8003343C->sync(0);
    D_8003343C->cwb((u_long*)p + 1, len);
}

void DrawOTag(u_long* p)
{
    if (D_80033444.level >= 2) {
        D_80033440("DrawOTag(%08x)...\n", p);
    }
    D_8003343C->addque2(D_8003343C->cwc, p, 0, 0);
}

DRAWENV* PutDrawEnv(DRAWENV* env)
{
    if (D_80033444.level >= 2) {
        D_80033440("PutDrawEnv(%08x)...\n", env);
    }
    func_80029694(&env->dr_env, env);
    env->dr_env.tag |= 0xFFFFFF;
    D_8003343C->addque2(D_8003343C->cwc, &env->dr_env, sizeof(DR_ENV), 0);
    memcpy(&D_80033444.draw, env, sizeof(DRAWENV));
    return env;
}

void DrawOTagEnv(u_long* p, DRAWENV* env)
{
    if (D_80033444.level >= 2) {
        D_80033440("DrawOTagEnv(%08x,&08x)...\n", p, env);
    }
    func_80029694(&env->dr_env, env);
    setaddr(&env->dr_env, p);
    D_8003343C->addque2(D_8003343C->cwc, &env->dr_env, sizeof(DR_ENV), 0);
    memcpy(&D_80033444.draw, env, sizeof(DRAWENV));
}

DRAWENV* GetDrawEnv(DRAWENV* env)
{
    memcpy(env, &D_80033444.draw, sizeof(DRAWENV));
    return env;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", PutDispEnv);

DISPENV* GetDispEnv(DISPENV* env)
{
    memcpy(env, &D_80033444.disp, sizeof(DISPENV));
    return env;
}

int GetODE(void) { return D_8003343C->status() >> 31; }

void SetDrawArea(DR_AREA* p, RECT* r)
{
    setlen(p, 2);
    p->code[0] = func_80029924(r->x, r->y);
    p->code[1] = func_800299BC(r->x + r->w - 1, r->y + r->h - 1);
}

void SetDrawOffset(DR_OFFSET* p, u_short* ofs)
{
    setlen(p, 2);
    p->code[0] = func_80029A54((short)ofs[0], (short)ofs[1]);
    p->code[1] = 0;
}

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

u_long func_80029A70(RECT* tw)
{
    int pmsk[4];

    if (tw) {
        pmsk[0] = (tw->x & 0xFF) >> 3;
        pmsk[2] = (-tw->w & 0xFF) >> 3;
        pmsk[1] = (tw->y & 0xFF) >> 3;
        pmsk[3] = (-tw->h & 0xFF) >> 3;
        return 0xE2000000 | (pmsk[1] << 15) | (pmsk[0] << 10) | (pmsk[3] << 5) | pmsk[2];
    }
    return 0;
}

u_long func_80029AF0(void) { return *D_8003354C; }

int func_80029B08(u_long* ot, int n)
{
    *D_80033568 |= 0x08000000;
    *D_80033564 = 0;
    *D_8003355C = (u_long)&ot[n - 1];
    *D_80033560 = n;
    *D_80033564 = 0x11000002;
    func_8002AB84();
    while (*D_80033564 & 0x01000000) {
        if (func_8002ABB8()) {
            return -1;
        }
    }
    return n;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", func_80029BE8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", func_80029E18);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", func_8002A054);

void func_8002A2D4(u_long n)
{
    *D_8003354C = n;
    D_8003E2F8[n >> 24] = n;
}

int func_8002A2F8(int n) { return D_8003E2F8[n]; }

int func_8002A30C(u_long* p, int n)
{
    int i = n - 1;

    *D_8003354C = 0x04000000;
    if (n != 0) {
        do {
            u_long v = *p++;
            *D_80033548 = v;
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

int func_8002AA48(int mode)
{
    int n;

    if (mode == 0) {
        func_8002AB84();
        while (D_8003356C != D_80033570) {
            func_8002A698();
            if (func_8002ABB8()) {
                return -1;
            }
        }
        while ((*D_80033558 & 0x01000000) || !(*D_8003354C & 0x04000000)) {
            if (func_8002ABB8()) {
                return -1;
            }
        }
        return 0;
    }
    n = (D_8003356C - D_80033570) & 0x3F;
    if (n) {
        func_8002A698();
    }
    if ((*D_80033558 & 0x01000000) || !(*D_8003354C & 0x04000000)) {
        if (n == 0) {
            return 1;
        }
    }
    return n;
}

inline void func_8002AB84(void)
{
    D_80033580 = VSync(-1) + 240;
    D_80033584 = 0;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", func_8002ABB8);

int func_8002ACFC(int mode)
{
    *D_8003354C = 0x10000007;
    if ((*D_80033548 & 0xFFFFFF) != 2) {
        *D_80033548 = 0xE1001000 | (*D_8003354C & 0x3FFF);
        *D_80033548;
        return 0;
    }
    if (!(mode & 8)) {
        return 1;
    }
    *D_8003354C = 0x09000001;
    return 2;
}

int LoadImage2(RECT* rect, u_long* p)
{
    func_800286B8("LoadImage2", rect);
    func_8002AB84();
    while ((*D_80033558 & 0x01000000) || !(*D_8003354C & 0x04000000)) {
        if (func_8002ABB8()) {
            return -1;
        }
    }
    DMACallback(2, _GPU_ResetCallback);
    D_8003343C->dws(rect, p);
    return 0;
}

int StoreImage2(RECT* rect, u_long* p)
{
    func_800286B8("StoreImage", rect);
    func_8002AB84();
    while ((*D_80033558 & 0x01000000) || !(*D_8003354C & 0x04000000)) {
        if (func_8002ABB8()) {
            return -1;
        }
    }
    DMACallback(2, _GPU_ResetCallback);
    D_8003343C->drs(rect, p);
    return 0;
}

int MoveImage2(RECT* rect, int x, int y)
{
    func_800286B8("MoveImage", rect);
    func_8002AB84();
    while ((*D_80033558 & 0x01000000) || !(*D_8003354C & 0x04000000)) {
        if (func_8002ABB8()) {
            return -1;
        }
    }
    DMACallback(2, _GPU_ResetCallback);
    if (rect->w == 0 || rect->h == 0) {
        return -1;
    }
    D_800334D0.move[2] = *(u_long*)&rect->x;
    D_800334D0.move[3] = (y << 16) | (x & 0xFFFF);
    D_800334D0.move[4] = *(u_long*)&rect->w;
    D_8003343C->cwc(D_800334D0.move);
    return 0;
}

int DrawOTag2(u_long* p)
{
    if (D_80033444.level >= 2) {
        D_80033440("DrawOTag(%08x)...\n", p);
    }
    func_8002AB84();
    while ((*D_80033558 & 0x01000000) || !(*D_8003354C & 0x04000000)) {
        if (func_8002ABB8()) {
            return -1;
        }
    }
    DMACallback(2, _GPU_ResetCallback);
    D_8003343C->cwc(p);
    return 0;
}

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
