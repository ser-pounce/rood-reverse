#include "18.h"
#define VS_TILED_RING_FUNCTION func_800F9818
#define VS_TILED_RING_COLORS D_800FB260

static CVECTOR VS_TILED_RING_COLORS[] = { { 255, 255, 255 }, { 128, 128, 128 },
    { 255, 128, 0 }, { 0, 128, 255 }, { 0, 255, 0 }, { 255, 0, 255 }, { 0, 128, 0 },
    { 128, 0, 128 } };

#include "src/EFFECT/tiledRings.h"

#define VS_GRID_FUNCTION func_800FA710
#include "src/EFFECT/grids.h"
