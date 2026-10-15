#include "common.h"

#define VS_ROTATING_SURFACE_FUNCTION func_800F9800
#include "src/EFFECT/rotatingSurfaces.h"

#define VS_MIRROR_SURFACE_FUNCTION func_800FA6B8
#define VS_MIRROR_SURFACE_VERTICES D_800FCEC0
#include "src/EFFECT/mirroredSurfaces.h"

#define VS_CLOSED_RING_FUNCTION func_800FB32C
#define VS_CLOSED_RING_COLORS D_800FD140
#define VS_CLOSED_RING_TEXTURE_COLUMNS 4
#include "src/EFFECT/closedRings.h"

INCLUDE_ASM("build/src/EFFECT/PLG166.BIN/nonmatchings/0", func_800FC29C);
