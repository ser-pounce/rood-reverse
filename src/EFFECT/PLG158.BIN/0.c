#include "common.h"

#define VS_SURFACE_FUNCTION func_800F9800
#define VS_SURFACE_VERTICES D_800FCE38
#define VS_SURFACE_TEXTURE_COLUMNS 4
#include "src/EFFECT/surfaces.h"

INCLUDE_ASM("build/src/EFFECT/PLG158.BIN/nonmatchings/0", func_800FA398);

#define VS_CLOSED_RING_FUNCTION func_800FB00C
#define VS_CLOSED_RING_COLORS D_800FD338
#define VS_CLOSED_RING_TEXTURE_COLUMNS 4
#include "src/EFFECT/closedRings.h"

INCLUDE_ASM("build/src/EFFECT/PLG158.BIN/nonmatchings/0", func_800FBF7C);
