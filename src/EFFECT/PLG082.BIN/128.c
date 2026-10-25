#include "128.h"

#define VS_PARTICLE_ORIGIN_FUNCTION func_800F9928
#define VS_PARTICLE_TARGET_FUNCTION func_800FA0B0
#define VS_PARTICLE_CONTROL_FUNCTION func_800FA2C8
#include "src/EFFECT/particleSetup.h"

#define VS_PARTICLE_RENDER_FUNCTION func_800FA778
#include "src/EFFECT/particleRender.h"

#define VS_PARTICLE_DISPATCH_FUNCTION vs_effect_thunderbolt_0
#include "src/EFFECT/particleDispatch.h"

#define VS_GRID_FUNCTION vs_effect_thunderbolt_1
#include "src/EFFECT/grids.h"

#define VS_CLOSED_RING_FUNCTION vs_effect_thunderbolt_2
#include "src/EFFECT/closedRings.h"
