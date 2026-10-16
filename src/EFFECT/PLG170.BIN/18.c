#include "common.h"

INCLUDE_ASM("build/src/EFFECT/PLG170.BIN/nonmatchings/18", func_800F9818);

#define VS_ROTATING_SURFACE_TEXTURE_COLUMNS 4
#define VS_ROTATING_SURFACE_FUNCTION func_800FA48C
#include "src/EFFECT/rotatingSurfaces.h"

INCLUDE_ASM("build/src/EFFECT/PLG170.BIN/nonmatchings/18", func_800FB348);

#define VS_GRID_FUNCTION func_800FBF6C
#include "src/EFFECT/grids.h"

#define VS_SURFACE_FUNCTION func_800FCABC
#define VS_SURFACE_VERTICES D_800FE864
#define VS_SURFACE_TEXTURE_COLUMNS 4
#include "src/EFFECT/surfaces.h"

#define VS_CLOSED_RING_FUNCTION func_800FD654
#define VS_CLOSED_RING_COLORS D_800FEAE4
#define VS_CLOSED_RING_TEXTURE_COLUMNS 4
#include "src/EFFECT/closedRings.h"
