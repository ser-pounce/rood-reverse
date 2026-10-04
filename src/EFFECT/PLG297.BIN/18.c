#include "common.h"

#define VS_MIRROR_SURFACE_FUNCTION func_800F9818
#define VS_MIRROR_SURFACE_VERTICES D_800FCB70
#include "src/EFFECT/mirroredSurfaces.h"

INCLUDE_ASM("build/src/EFFECT/PLG297.BIN/nonmatchings/18", func_800FA48C);

#define VS_GRID_FUNCTION func_800FB3FC
#include "src/EFFECT/grids.h"

#define VS_RING_FUNCTION func_800FBF4C
#define VS_RING_COLORS D_800FCE10
#define VS_RING_TRANSPOSED
#include "src/EFFECT/rings.h"
