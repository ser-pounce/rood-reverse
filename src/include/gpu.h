#pragma once
#include <sys/types.h>
#include <libgpu.h>

enum vs_texMode { clut4Bit = 0, clut8Bit = 1, direct16Bit = 2 };

enum vs_semiTransparencyRate {
    semiTransparencyHalf = 0,
    semiTransparencyFull = 1,
    semiTransparencySubtract = 2,
    semiTransparencyQuarterFront = 3
};

enum vs_primAddr { primAddrNull = 0, primAddrEnd = 0xFFFFFF };

enum vs_dithering { ditheringOff = 0, ditheringOn = 1 };

enum vs_primType {
    primShadeTex = 1,
    primSemiTrans = 2,
    primPolyG4 = 0x38,
    primPolyG4SemiTrans = primPolyG4 | primSemiTrans,
    primLineF2 = 0x40,
    primLineF2SemiTrans = primLineF2 | primSemiTrans,
    primTile = 0x60,
    primTileSemiTrans = primTile | primSemiTrans,
    primSprt = 0x64,
    primSprtSemtTrans = primSprt | primSemiTrans
};

typedef struct {
    u_long tpage;
    u_long r0g0b0code;
    u_long x0y0;
    u_long wh;
} VS_TILE_TPAGE;

typedef struct {
    u_long r0g0b0code;
    u_long x0y0;
    u_long wh;
} VS_TILE;

typedef struct {
    u_long tpage;
    u_long r0g0b0code;
    u_long x0y0;
    u_long u0v0clut;
    u_long wh;
} VS_SPRT;

typedef struct {
    u_long tpage;
    u_long r0g0b0code;
    u_long x0y0;
    u_long r1g1b1;
    u_long x1y1;
    u_long r2g2b2;
    u_long x2y2;
    u_long r3g3b3;
    u_long x3y3;
} VS_POLY_G4_TPAGE;

typedef struct {
    u_long r0g0b0code;
    u_long x0y0;
    u_long r1g1b1;
    u_long x1y1;
    u_long r2g2b2;
    u_long x2y2;
    u_long r3g3b3;
    u_long x3y3;
} VS_POLY_G4;

#define vs_getXY(x, y) (((y)) << 16 | ((x)))
#define vs_getWH(w, h) vs_getXY((w), (h))
#define vs_getTag(type, addr) (((sizeof(type) / 4) << 24) | ((addr) & 0xFFFFFF))
#define vs_getTpage(x, y, tp, abr, dtd)                                                  \
    ((0xE1 << 24) | (((dtd) & 1) << 9) | getTPage((tp), (abr), (x), (y)))
#define vs_getTpageRaw(tpageVal) ((0xE1 << 24) | ((tpageVal) & 0xFFFF))
#define vs_getRGB0(code, r, g, b)                                                        \
    (((code) << 24) | (((b) & 0xFF) << 16) | (((g) & 0xFF) << 8) | ((r) & 0xFF))
#define vs_getRGB0Raw(code, rgb0) (((code) << 24) | (rgb0))
#define vs_getRGB5551(r, g, b, a)                                                        \
    (((r) & 0x1F) | (((g) & 0x1F) << 5) | (((b) & 0x1F) << 10) | (((a) & 0x1) << 15))
#define vs_getRGB888(r, g, b) (((r) & 0xFF) | (((g) & 0xFF) << 8) | (((b) & 0xFF) << 16))
#define vs_getUV0Clut(u, v, x, y) (((u) | ((v) << 8)) | (getClut((x), (y)) << 16))
