#include "common.h"

#define VS_RING_FUNCTION func_800F9800
#define VS_RING_COLORS D_800FD5A8
#define VS_RING_TRANSPOSED
#include "src/EFFECT/rings.h"

INCLUDE_ASM("build/src/EFFECT/PLG129.BIN/nonmatchings/0", func_800FA424);

#define VS_SURFACE_FUNCTION func_800FAF30
#define VS_SURFACE_VERTICES D_800FD698
#define VS_SURFACE_TEXTURE_COLUMNS 4
#include "src/EFFECT/surfaces.h"

INCLUDE_ASM("build/src/EFFECT/PLG129.BIN/nonmatchings/0", func_800FBAC8);

#define VS_ROTATING_SURFACE_TEXTURE_COLUMNS 4
#define VS_ROTATING_SURFACE_FUNCTION func_800FC6EC
#include "src/EFFECT/rotatingSurfaces.h"
