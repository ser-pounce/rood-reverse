#include "common.h"

#define VS_SURFACE_FUNCTION func_800F9818
#define VS_SURFACE_VERTICES D_800FCA90
#include "src/EFFECT/surfaces.h"

#define VS_GRID_FUNCTION func_800FA3B0
#include "src/EFFECT/grids.h"

INCLUDE_ASM("build/src/EFFECT/PLG061.BIN/nonmatchings/18", func_800FAF00);

#define VS_CLOSED_RING_FUNCTION func_800FBB24
#define VS_CLOSED_RING_COLORS D_800FCD30
#include "src/EFFECT/closedRings.h"
