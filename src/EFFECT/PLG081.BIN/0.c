#include "common.h"

#define VS_ROTATING_SURFACE_FUNCTION func_800F9800
#include "src/EFFECT/rotatingSurfaces.h"

INCLUDE_ASM("build/src/EFFECT/PLG081.BIN/nonmatchings/0", func_800FA6B8);

#define VS_CLOSED_RING_FUNCTION func_800FB2DC
#define VS_CLOSED_RING_COLORS D_800FC26C
#define VS_CLOSED_RING_TEXTURE_COLUMNS 4
#include "src/EFFECT/closedRings.h"
