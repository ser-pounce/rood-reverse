#include "common.h"

#define VS_GRID_FUNCTION func_800F9928
#include "src/EFFECT/grids.h"

#define VS_PARTICLE_ORIGIN_FUNCTION func_800FA478
#define VS_PARTICLE_TARGET_FUNCTION func_800FAC00
#define VS_PARTICLE_CONTROL_FUNCTION func_800FAE18
#define VS_PARTICLE_CORNER_STATE D_800FD088
#include "src/EFFECT/particleSetup.h"

INCLUDE_ASM("build/src/EFFECT/PLG152.BIN/nonmatchings/128", func_800FB2C8);

INCLUDE_ASM("build/src/EFFECT/PLG152.BIN/nonmatchings/128", func_800FBE88);

#define VS_CLOSED_RING_FUNCTION func_800FC11C
#define VS_CLOSED_RING_COLORS D_800FD08C
#include "src/EFFECT/closedRings.h"
