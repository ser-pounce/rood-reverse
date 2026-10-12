/* SPDX-License-Identifier: MIT
 * libgpu sys.c 1.140. PutDispEnv from ReGame-Labs/dcb_decomp
 * src/main/psyq/libgpu_sys_2.c; other function bodies adapted from Xeeynamo/psyz
 * decomp/src/libgpu/sys.c (commit bed6ece8becbc6fae3a41285018c47fb1914c2d6) and
 * Xeeynamo/sotn-decomp src/main/psxsdk/libgpu/sys.c (commit
 * ddfe818338828624899aaa9caf34cc2851786527); compiler recipe from ReGame-Labs/dcb_decomp
 * (commit 6c9caf124450cafa1b5f402d03d82b90bb02d16e). Copyright (c) 2024 github.com/psyqz
 * members Copyright (c) 2025 github.com/xeeynamo/sotn-decomp contributors Copyright (c)
 * 2026 ReGame Labs See LICENSES/psyz-MIT.txt and LICENSES/dcb_decomp-MIT.txt.
 */
#include "SYS_internal.h"

#define CLAMP(value, low, high)                                                \
    value < low ? low : (value > high ? high : value)

extern u_long D_8003E2B0[]; /* clear packet */
extern u_long D_8003E2D8[]; /* drawing-area restore packet */
typedef struct {
    int (*exec)();
    u_long* p1;
    u_long p2;
    u_long param[21];
} GpuQueue; /* 0x60 bytes */
extern volatile GpuQueue D_8003E400[64]; /* command queue */
extern int D_80033574; /* interrupt mask saved by _addque2 */
extern int D_80033578; /* interrupt mask saved by _exeque */
extern int D_8003357C; /* interrupt mask saved by _reset */
int SetIntrMask(int);
int func_8002ACFC(int mode);
void func_8002A34C(u_long madr);
u_long func_8002A394(u_long n);

typedef struct {
    u_short start;
    u_short end;
} GpuHRange;
extern GpuHRange D_80033518[2][5]; /* horizontal display start/end per video mode */
extern u_char D_80033540[5]; /* dot-clock multiplier per horizontal mode */
#define LIMIT(x, lo, hi) ((x) < (lo) ? (lo) : (x) > (hi) ? (hi) : (x))

u_long func_80029904(int dfe, int dtd, int tpage);
u_long func_80029A70(RECT* tw);

INCLUDE_RODATA("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", D_80010864);

int ResetGraph(int mode)
{
    switch (mode & 7) {
    case 3:
    case 0:
        printf("ResetGraph:jtb=%08x,env=%08x\n", &D_800333FC, &D_80033444);
    case 5:
        func_8002B1DC((u_char*)&D_80033444, 0, sizeof(D_80033444));
        ResetCallback();
        GPU_cw(((u_long*)((u_long)D_8003343C & 0xFFFFFF)));
        D_80033444.version = func_8002A8F8(mode);
        D_80033444.unk1 = 1;
        D_80033444.w = D_800334C4[D_80033444.version];
        D_80033444.h = D_800334D0.unk0[D_80033444.version];
        func_8002B1DC((u_char*)&D_80033444.draw, -1, sizeof(DRAWENV));
        func_8002B1DC((u_char*)&D_80033444.disp, -1, sizeof(DISPENV));
        return D_80033444.version;
    }
    if (D_80033444.level >= 2) {
        D_80033440("ResetGraph(%d)...\n", mode);
    }
    return D_8003343C->reset(1);
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", SetGraphDebug);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", SetGraphQueue);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", GetGraphDebug);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", DrawSyncCallback);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", SetDispMask);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", DrawSync);

void func_800286B8(char* log, RECT* r)
{
    switch (D_80033444.level) {
    case 1:
        if (r->w > D_80033444.w || r->w + r->x > D_80033444.w || r->y > D_80033444.h
            || r->y + r->h > D_80033444.h || r->w <= 0 || r->x < 0 || r->y < 0
            || r->h <= 0) {
            D_80033440("%s:bad RECT", log);
            D_80033440("(%d,%d)-(%d,%d)\n", r->x, r->y, r->w, r->h);
        }
        break;
    case 2:
        D_80033440("%s:", log);
        D_80033440("(%d,%d)-(%d,%d)\n", r->x, r->y, r->w, r->h);
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

DISPENV* PutDispEnv(DISPENV* env)
{
    long h_start, h_end, v_start, v_end;
    long width;
    volatile RECT* old;
    int mode;
    u_long cmd;

    cmd = 0x08000000;
    if (D_80033444.level >= 2) {
        D_80033440("PutDispEnv(%08x)...\n", env);
    }
    D_8003343C->ctl(0x05000000 | ((env->disp.y & 0x3FF) << 10) | (env->disp.x & 0x3FF));
    old = &D_80033444.disp.disp;
    if (*(long*)&D_80033444.disp.isinter != *(long*)&env->isinter || old->x != env->disp.x
        || old->y != env->disp.y || old->w != env->disp.w || old->h != env->disp.h) {
        if ((env->pad0 = GetVideoMode()) == 1) {
            cmd |= 0x08;
        }
        if (env->isrgb24) {
            cmd |= 0x10;
        }
        if (env->isinter) {
            cmd |= 0x20;
        }
        if (D_80033444.reverse) {
            cmd |= 0x80;
        }
        if (env->disp.w > 0x118) {
            if (env->disp.w <= 0x160) {
                cmd |= 1;
            } else if (env->disp.w <= 0x190) {
                cmd |= 0x40;
            } else if (env->disp.w <= 0x230) {
                cmd |= 2;
            } else {
                cmd |= 3;
            }
        }
        if (env->disp.h <= (env->pad0 ? 0x120 : 0x100)) {
        } else {
            cmd |= 0x24;
        }
        D_8003343C->ctl(cmd);
        env->pad0 = 8;
    }
    old = &D_80033444.disp.screen;
    if (old->x != env->screen.x || old->y != env->screen.y || old->w != env->screen.w
        || old->h != env->screen.h || env->pad0 == 8) {
        env->pad0 = GetVideoMode();
        v_start = env->screen.y + (env->pad0 ? 0x13 : 0x10);
        v_end = v_start + (env->screen.h ? env->screen.h : 0xF0);
        if (env->disp.w <= 0x118) {
            mode = 0;
        } else if (env->disp.w <= 0x160) {
            mode = 1;
        } else if (env->disp.w <= 0x190) {
            mode = 2;
        } else if (env->disp.w <= 0x230) {
            mode = 3;
        } else {
            mode = 4;
        }
        h_start = D_80033518[env->pad0][mode].start + env->screen.x * D_80033540[mode];
        width = D_80033518[env->pad0][mode].end - D_80033518[env->pad0][mode].start;
        h_end = h_start + (env->screen.w ? (width * env->screen.w) >> 8 : width);
        if (env->pad0) {
            h_start = LIMIT(h_start, 0x21C, 0xC94);
            h_end = LIMIT(h_end, h_start + D_80033540[mode] * 4, 0xCBC);
            v_start = LIMIT(v_start, 0x13, 0x12F);
            v_end = LIMIT(v_end, v_start + 2, 0x131);
        } else {
            h_start = LIMIT(h_start, 0x1F4, 0xCB2);
            h_end = LIMIT(h_end, h_start + D_80033540[mode] * 4, 0xCDA);
            v_start = LIMIT(v_start, 0x10, 0x101);
            v_end = LIMIT(v_end, v_start + 2, 0x102);
        }
        D_8003343C->ctl(0x06000000 | ((h_end & 0xFFF) << 12) | (h_start & 0xFFF));
        D_8003343C->ctl(0x07000000 | ((v_end & 0x3FF) << 10) | (v_start & 0x3FF));
    }
    memcpy((u_char*)&D_80033444.disp, (u_char*)env, sizeof(DISPENV));
    return env;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", GetDispEnv);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", GetODE);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", SetDrawArea);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", SetDrawOffset);

void SetDrawEnv(DR_ENV* dr_env_in, DRAWENV* env)
{
    RECT clip_rect;
    int offset;
    DR_ENV* dr_env;

    dr_env = dr_env_in;

    dr_env->code[0] = func_80029924(env->clip.x, env->clip.y);
    dr_env->code[1] =
        func_800299BC(env->clip.w + env->clip.x - 1, env->clip.y + env->clip.h - 1);
    dr_env->code[2] = func_80029A54(env->ofs[0], env->ofs[1]);
    dr_env->code[3] = func_80029904(env->dfe, env->dtd, env->tpage);
    dr_env->code[4] = func_80029A70(&env->tw);
    dr_env->code[5] = 0xE6000000;

    offset = 7;
    if (env->isbg != 0) {
        clip_rect.x = env->clip.x;
        clip_rect.y = env->clip.y;
        clip_rect.w = env->clip.w;
        clip_rect.h = env->clip.h;
        clip_rect.w = CLAMP(clip_rect.w, 0, D_80033444.w - 1);
        clip_rect.h = CLAMP(clip_rect.h, 0, D_80033444.h - 1);
        clip_rect.x -= env->ofs[0];
        clip_rect.y -= env->ofs[1];
        *((u_long*)dr_env + offset++) =
            0x60000000 | env->b0 << 0x10 | env->g0 << 8 | env->r0;
        *((u_long*)dr_env + offset++) = *(u_long*)&clip_rect.x;
        *((u_long*)dr_env + offset++) = *(u_long*)&clip_rect.w;
    }

    setlen(dr_env, offset - 1);
}

void func_80029694(DR_ENV* dr_env_in, DRAWENV* env)
{
    RECT clip_rect;
    int offset;
    DR_ENV* dr_env;

    dr_env = dr_env_in;

    dr_env->code[0] = func_80029924(env->clip.x, env->clip.y);
    dr_env->code[1] =
        func_800299BC(env->clip.w + env->clip.x - 1, env->clip.y + env->clip.h - 1);
    dr_env->code[2] = func_80029A54(env->ofs[0], env->ofs[1]);
    dr_env->code[3] = func_80029904(env->dfe, env->dtd, env->tpage);
    dr_env->code[4] = func_80029A70(&env->tw);
    dr_env->code[5] = 0xE6000000;

    offset = 7;
    if (env->isbg != 0) {
        clip_rect.x = env->clip.x;
        clip_rect.y = env->clip.y;
        clip_rect.w = env->clip.w;
        clip_rect.h = env->clip.h;
        clip_rect.w = CLAMP(clip_rect.w, 0, D_80033444.w - 1);
        clip_rect.h = CLAMP(clip_rect.h, 0, D_80033444.h - 1);
        if ((clip_rect.x & 0x3F) || (clip_rect.w & 0x3F)) {
            clip_rect.x -= env->ofs[0];
            clip_rect.y -= env->ofs[1];
            *((u_long*)dr_env + offset++) =
                0x60000000 | env->b0 << 0x10 | env->g0 << 8 | env->r0;
            *((u_long*)dr_env + offset++) = *(u_long*)&clip_rect.x;
            *((u_long*)dr_env + offset++) = *(u_long*)&clip_rect.w;
        } else {
            *((u_long*)dr_env + offset++) =
                0x02000000 | env->b0 << 0x10 | env->g0 << 8 | env->r0;
            *((u_long*)dr_env + offset++) = *(u_long*)&clip_rect.x;
            *((u_long*)dr_env + offset++) = *(u_long*)&clip_rect.w;
        }
    }

    setlen(dr_env, offset - 1);
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", func_80029904);

u_long func_80029924(short x, short y)
{
    x = CLAMP(x, 0, D_80033444.w - 1);
    y = CLAMP(y, 0, D_80033444.h - 1);
    return 0xE3000000 | ((y & 0x3FF) << 10) | (x & 0x3FF);
}

u_long func_800299BC(short x, short y)
{
    x = CLAMP(x, 0, D_80033444.w - 1);
    y = CLAMP(y, 0, D_80033444.h - 1);
    return 0xE4000000 | ((y & 0x3FF) << 10) | (x & 0x3FF);
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", func_80029A54);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", func_80029A70);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", func_80029AF0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", func_80029B08);

int func_80029BE8(RECT* rect, u_long color)
{
    rect->w = CLAMP(rect->w, 0, D_80033444.w - 1);
    rect->h = CLAMP(rect->h, 0, D_80033444.h - 1);
    if (rect->x & 0x3F || rect->w & 0x3F) {
        D_8003E2B0[0] = ((u_long)D_8003E2D8 & 0xFFFFFF) | 0x08000000;
        D_8003E2B0[1] = 0xE3000000;
        D_8003E2B0[2] = 0xE4FFFFFF;
        D_8003E2B0[3] = 0xE5000000;
        D_8003E2B0[4] = 0xE6000000;
        D_8003E2B0[5] = 0xE1000000 | *D_8003354C & 0x7FF | (color >> 0x1F) << 10;
        D_8003E2B0[6] = (color & 0xFFFFFF) | 0x60000000;
        D_8003E2B0[7] = *(u_long*)&rect->x;
        D_8003E2B0[8] = *(u_long*)&rect->w;
        D_8003E2D8[0] = 0xFFFFFF | 0x03000000;
        D_8003E2D8[1] = func_8002A394(3) | 0xE3000000;
        D_8003E2D8[2] = func_8002A394(4) | 0xE4000000;
        D_8003E2D8[3] = func_8002A394(5) | 0xE5000000;
    } else {
        D_8003E2B0[0] = 0xFFFFFF | 0x05000000;
        D_8003E2B0[1] = 0xE6000000;
        D_8003E2B0[2] = 0xE1000000 | *D_8003354C & 0x7FF | (color >> 0x1F) << 10;
        D_8003E2B0[3] = (color & 0xFFFFFF) | 0x02000000;
        D_8003E2B0[4] = *(u_long*)&rect->x;
        D_8003E2B0[5] = *(u_long*)&rect->w;
    }
    func_8002A34C((u_long)D_8003E2B0);
    return 0;
}

int func_80029E18(RECT* rect, u_long* data)
{
    int to_write;
    int size;
    int var_s0;
    int var_s4;

    var_s4 = 0;
    func_8002AB84();
    rect->w = CLAMP(rect->w, 0, D_80033444.w);
    rect->h = CLAMP(rect->h, 0, D_80033444.h);
    to_write = (rect->w * rect->h + 1) / 2;
    if (to_write <= 0) {
        return -1;
    }
    var_s0 = to_write % 16;
    size = to_write / 16;
    while (!(*D_8003354C & 0x04000000)) {
        if (func_8002ABB8()) {
            return -1;
        }
    }
    *D_8003354C = 0x04000000;
    *D_80033548 = 0x01000000;
    *D_80033548 = var_s4 ? 0xB0000000 : 0xA0000000;
    *D_80033548 = *(u_long*)&rect->x;
    *D_80033548 = *(u_long*)&rect->w;
    while (var_s0--) {
        *D_80033548 = *data++;
    }
    if (size) {
        *D_8003354C = 0x04000002;
        *D_80033550 = (u_long)data;
        *D_80033554 = size << 16 | 0x10;
        *D_80033558 = 0x01000201;
    }
    return 0;
}

int func_8002A054(RECT* rect, u_long* data)
{
    int to_read;
    int size;
    int var_s0;

    func_8002AB84();
    rect->w = CLAMP(rect->w, 0, D_80033444.w);
    rect->h = CLAMP(rect->h, 0, D_80033444.h);
    to_read = (rect->w * rect->h + 1) / 2;
    if (to_read <= 0) {
        return -1;
    }
    var_s0 = to_read % 16;
    size = to_read / 16;
    while (!(*D_8003354C & 0x04000000)) {
        if (func_8002ABB8()) {
            return -1;
        }
    }
    *D_8003354C = 0x04000000;
    *D_80033548 = 0x01000000;
    *D_80033548 = 0xC0000000;
    *D_80033548 = *(u_long*)&rect->x;
    *D_80033548 = *(u_long*)&rect->w;
    while (!(*D_8003354C & 0x08000000)) {
        if (func_8002ABB8()) {
            return -1;
        }
    }
    while (var_s0--) {
        *data++ = *D_80033548;
    }
    if (size != 0) {
        *D_8003354C = 0x04000003;
        *D_80033550 = (u_long)data;
        *D_80033554 = (size << 0x10) | 0x10;
        *D_80033558 = 0x01000200;
    }
    return 0;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", func_8002A2D4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", func_8002A2F8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", func_8002A30C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", func_8002A34C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", func_8002A394);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", func_8002A3C4);

int func_8002A3E8(int (*exec)(), u_long* p1, int len, u_long p2)
{
    int i;

    func_8002AB84();
    while (((D_8003356C + 1) & 0x3F) == D_80033570) {
        if (func_8002ABB8()) {
            return -1;
        }
        func_8002A698();
    }
    D_80033574 = SetIntrMask(0);
    D_80033444.unk8 = 1;
    if (D_80033444.unk1 == 0
        || (D_8003356C == D_80033570 && !(*D_80033558 & 0x01000000)
            && D_80033444.drawSyncCB == NULL)) {
        while (!(*D_8003354C & 0x04000000)) { }
        exec(p1, p2);
        SetIntrMask(D_80033574);
        return 0;
    }
    DMACallback(2, func_8002A698);
    if (len) {
        for (i = 0; i < len / 4; i++) {
            D_8003E400[D_8003356C].param[i] = p1[i];
        }
        D_8003E400[D_8003356C].p1 = (u_long*)D_8003E400[D_8003356C].param;
    } else {
        D_8003E400[D_8003356C].p1 = p1;
    }
    D_8003E400[D_8003356C].p2 = p2;
    D_8003E400[D_8003356C].exec = exec;
    D_8003356C = (D_8003356C + 1) & 0x3F;
    SetIntrMask(D_80033574);
    func_8002A698();
    return (D_8003356C - D_80033570) & 0x3F;
}

int func_8002A698(void)
{
    if (*D_80033558 & 0x01000000) {
        return 1;
    }
    D_80033578 = SetIntrMask(0);
    while (D_8003356C != D_80033570 && !(*D_80033558 & 0x01000000)) {
        if (((D_80033570 + 1) & 0x3F) == D_8003356C && D_80033444.drawSyncCB == NULL) {
            DMACallback(2, NULL);
        }
        while (!(*D_8003354C & 0x04000000)) { }
        D_8003E400[D_80033570].exec(D_8003E400[D_80033570].p1, D_8003E400[D_80033570].p2);
        D_80033570 = (D_80033570 + 1) & 0x3F;
    }
    SetIntrMask(D_80033578);
    if (D_8003356C == D_80033570 && !(*D_80033558 & 0x01000000) && D_80033444.unk8
        && D_80033444.drawSyncCB) {
        D_80033444.unk8 = 0;
        D_80033444.drawSyncCB();
    }
    return (D_8003356C - D_80033570) & 0x3F;
}

inline int func_8002A8F8(int mode)
{
    D_8003357C = SetIntrMask(0);
    D_80033570 = 0;
    D_8003356C = D_80033570;
    switch (mode & 7) {
    case 0:
    case 5:
        *D_80033558 = 0x401;
        *D_80033568 |= 0x800;
        *D_8003354C = 0;
        func_8002B1DC(D_8003E2F8, 0, 0x100);
        func_8002B1DC((u_char*)D_8003E400, 0, sizeof(D_8003E400));
        break;
    case 1:
    case 3:
        *D_80033558 = 0x401;
        *D_80033568 |= 0x800;
        *D_8003354C = 0x02000000;
        *D_8003354C = 0x01000000;
        break;
    }
    SetIntrMask(D_8003357C);
    return !(mode & 7) ? func_8002ACFC(mode) : 0;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", func_8002AA48);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/SYS", func_8002AB84);

int func_8002ABB8(void)
{
    if (D_80033580 < VSync(-1) || D_80033584++ > 0xF0000) {
        *D_8003354C;
        printf("GPU timeout:que=%d,stat=%08x,chcr=%08x,madr=%08x\n",
            (D_8003356C - D_80033570) & 0x3F, *D_8003354C, *D_80033558, *D_80033550);
        func_8002A8F8(1);
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
