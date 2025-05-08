#pragma once
#include <sys/types.h>
#include <libgpu.h>

enum vs_semiTransparencyRate {
    semiTransparencyHalf = 0,
    semiTransparencyFull = 1,
    semiTransparencySubtract = 2,
    semiTransparencyQuarterFront = 3
};

enum vs_texMode { clut4Bit = 0, clut8Bit = 1, direct16Bit = 2 };

enum vs_primAddr { primAddrNone = 0, primAddrEnd = 0xFFFFFF };

enum vs_primType {
    primShadeTex = 1,
    primSemiTrans = 2,
    primTile = 0x60,
    primTileSemiTrans = primTile | primSemiTrans
};

typedef struct {
    u_long tag;
    u_long tpage;
    u_long r0g0b0code;
    u_long x0y0;
    u_long wh;
} VS_TILE;

#define vs_setTag(p, addr)                                                               \
    (p)->tag = ((sizeof(*(p)) / 4 - 1) << 24) | ((addr) & 0xFFFFFF);
#define vs_setTpage(p, x, y, tp, abr)                                                    \
    (p)->tpage = ((0xE1) << 24) | getTPage((tp), (abr), (x), (y));
#define vs_setRGB0(p, code, r, g, b)                                                     \
    (p)->r0g0b0code                                                                      \
        = ((code) << 24) | (((b) & 0xFF) << 16) | (((g) & 0xFF) << 8) | ((r) & 0xFF);
#define vs_setXY0(p, x, y) (p)->x0y0 = (((y) & 0xFFFF) << 16) | ((x) & 0xFFFF);
#define vs_setWH(p, w, h) (p)->wh = (((h) & 0xFFFF) << 16) | ((w) & 0xFFFF);
