#include "common.h"

INCLUDE_ASM("build/src/EFFECT/PLG162.BIN/nonmatchings/0", func_800F9800);

#define VS_ROTATING_SURFACE_FUNCTION func_800FA740
#include "src/EFFECT/rotatingSurfaces.h"

#define VS_RING_FUNCTION func_800FB5F8
#define VS_RING_COLORS D_800FD1AC
#include "src/EFFECT/rings.h"

#define VS_CLOSED_RING_FUNCTION func_800FC21C
#define VS_CLOSED_RING_COLORS D_800FD1CC
#define VS_CLOSED_RING_TEXTURE_COLUMNS 4
#include "src/EFFECT/closedRings.h"
