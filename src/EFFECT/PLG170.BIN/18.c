#include "common.h"

#define VS_MIRROR_SURFACE_FUNCTION func_800F9818
#define VS_MIRROR_SURFACE_VERTICES D_800FE5C4
#include "src/EFFECT/mirroredSurfaces.h"

INCLUDE_ASM("build/src/EFFECT/PLG170.BIN/nonmatchings/18", func_800FA48C);

#define VS_RING_FUNCTION func_800FB348
#define VS_RING_COLORS D_800FE844
#define VS_RING_TRANSPOSED
#include "src/EFFECT/rings.h"

#define VS_GRID_FUNCTION func_800FBF6C
#include "src/EFFECT/grids.h"

#define VS_SURFACE_FUNCTION func_800FCABC
#define VS_SURFACE_VERTICES D_800FE864
#define VS_SURFACE_REPEAT
#include "src/EFFECT/surfaces.h"

INCLUDE_ASM("build/src/EFFECT/PLG170.BIN/nonmatchings/18", func_800FD654);
