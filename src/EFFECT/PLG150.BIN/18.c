#include "common.h"

INCLUDE_ASM("build/src/EFFECT/PLG150.BIN/nonmatchings/18", func_800F9818);

#define VS_GRID_FUNCTION func_800FA710
#include "src/EFFECT/grids.h"

#define VS_SURFACE_FUNCTION func_800FB260
#define VS_SURFACE_VERTICES D_800FCA3C
#include "src/EFFECT/surfaces.h"

#define VS_RING_FUNCTION func_800FBDF8
#define VS_RING_COLORS D_800FCCBC
#define VS_RING_TRANSPOSED
#include "src/EFFECT/rings.h"
