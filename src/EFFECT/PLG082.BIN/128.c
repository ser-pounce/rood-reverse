#include "common.h"

#define VS_PARTICLE_ORIGIN_FUNCTION func_800F9928
#define VS_PARTICLE_TARGET_FUNCTION func_800FA0B0
#define VS_PARTICLE_CONTROL_FUNCTION func_800FA2C8
#define VS_PARTICLE_CORNER_STATE D_800FD088
#include "src/EFFECT/particleSetup.h"

INCLUDE_ASM("build/src/EFFECT/PLG082.BIN/nonmatchings/128", func_800FA778);

INCLUDE_ASM("build/src/EFFECT/PLG082.BIN/nonmatchings/128", func_800FB338);

#define VS_GRID_FUNCTION func_800FB5CC
#include "src/EFFECT/grids.h"

#define VS_CLOSED_RING_FUNCTION func_800FC11C
#define VS_CLOSED_RING_COLORS D_800FD08C
#include "src/EFFECT/closedRings.h"
