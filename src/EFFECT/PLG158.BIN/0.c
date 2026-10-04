#include "common.h"

#define VS_SURFACE_FUNCTION func_800F9800
#define VS_SURFACE_VERTICES D_800FCE38
#define VS_SURFACE_REPEAT
#include "src/EFFECT/surfaces.h"

#define VS_MIRROR_SURFACE_FUNCTION func_800FA398
#define VS_MIRROR_SURFACE_VERTICES D_800FD0B8
#include "src/EFFECT/mirroredSurfaces.h"

INCLUDE_ASM("build/src/EFFECT/PLG158.BIN/nonmatchings/0", func_800FB00C);

INCLUDE_ASM("build/src/EFFECT/PLG158.BIN/nonmatchings/0", func_800FBF7C);
