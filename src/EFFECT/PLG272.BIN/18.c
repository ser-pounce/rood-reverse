#include "common.h"

INCLUDE_ASM("build/src/EFFECT/PLG272.BIN/nonmatchings/18", func_800F9818);

#define VS_CLOSED_RING_FUNCTION func_800FA368
#define VS_CLOSED_RING_COLORS D_800FBE70
#define VS_CLOSED_RING_TEXTURE_COLUMNS 4
#include "src/EFFECT/closedRings.h"

#define VS_SURFACE_FUNCTION func_800FB2D8
#define VS_SURFACE_VERTICES D_800FBE90
#include "src/EFFECT/surfaces.h"
