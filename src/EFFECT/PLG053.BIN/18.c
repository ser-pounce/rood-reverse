#include "common.h"

#define VS_GRID_FUNCTION func_800F9818
#include "src/EFFECT/grids.h"

#define VS_CLOSED_RING_FUNCTION func_800FA368
#define VS_CLOSED_RING_COLORS D_800FB2D4

static CVECTOR VS_CLOSED_RING_COLORS[] = { { 255, 255, 255 }, { 128, 128, 128 },
    { 255, 128, 0 }, { 0, 128, 255 }, { 0, 255, 0 }, { 255, 0, 255 }, { 0, 128, 0 },
    { 128, 0, 128 } };

#include "src/EFFECT/closedRings.h"
