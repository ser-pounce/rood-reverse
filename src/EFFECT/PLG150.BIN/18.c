#include "common.h"

#define VS_TILED_RING_FUNCTION func_800F9818
#define VS_TILED_RING_COLORS D_800FCA1C
#include "src/EFFECT/tiledRings.h"

#define VS_GRID_FUNCTION func_800FA710
#include "src/EFFECT/grids.h"

#define VS_SURFACE_FUNCTION func_800FB260
#define VS_SURFACE_VERTICES D_800FCA3C
#include "src/EFFECT/surfaces.h"

#define VS_RING_FUNCTION func_800FBDF8
#define VS_RING_COLORS D_800FCCBC
#define VS_RING_TRANSPOSED
#include "src/EFFECT/rings.h"
