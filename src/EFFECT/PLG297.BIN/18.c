#include "common.h"

#define VS_MIRROR_SURFACE_FUNCTION func_800F9818
#define VS_SURFACE_VERTICES D_800FCB70
#include "src/EFFECT/mirroredSurfaces.h"

#define VS_CLOSED_RING_FUNCTION func_800FA48C
#define VS_CLOSED_RING_COLORS D_800FCDF0
#define VS_CLOSED_RING_TEXTURE_COLUMNS 4
#include "src/EFFECT/closedRings.h"

#define VS_GRID_FUNCTION func_800FB3FC
#include "src/EFFECT/grids.h"

INCLUDE_ASM("build/src/EFFECT/PLG297.BIN/nonmatchings/18", func_800FBF4C);
