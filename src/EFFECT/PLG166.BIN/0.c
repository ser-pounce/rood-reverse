#include "common.h"

INCLUDE_ASM("build/src/EFFECT/PLG166.BIN/nonmatchings/0", func_800F9800);

#define VS_MIRROR_SURFACE_FUNCTION func_800FA6B8
#define VS_MIRROR_SURFACE_VERTICES D_800FCEC0
#include "src/EFFECT/mirroredSurfaces.h"

INCLUDE_ASM("build/src/EFFECT/PLG166.BIN/nonmatchings/0", func_800FB32C);

#define VS_RING_FUNCTION func_800FC29C
#define VS_RING_COLORS D_800FD160
#define VS_RING_TRANSPOSED
#include "src/EFFECT/rings.h"
