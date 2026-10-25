#include "1F0.h"

#define VS_SURFACE_FUNCTION vs_effect_apocalypse_0
#define VS_SURFACE_TEXTURE_COLUMNS 4
#include "src/EFFECT/sphericalSurfaceVertices.h"

#include "src/EFFECT/surfaces.h"

#define VS_CLOSED_RING_FUNCTION vs_effect_apocalypse_1
#define VS_CLOSED_RING_TEXTURE_COLUMNS 4
#include "src/EFFECT/closedRings.h"

#define VS_GRID_FUNCTION vs_effect_apocalypse_2
#include "src/EFFECT/grids.h"

#define VS_TRAIL_ORIGIN_FUNCTION func_800FC048
#define VS_TRAIL_TARGET_FUNCTION func_800FC7E4
#define VS_TRAIL_CONTROL_FUNCTION func_800FC9FC
#define VS_TRAIL_INIT_FUNCTION func_800FCEC0
#define VS_TRAIL_UPDATE_FUNCTION func_800FD038
#define VS_TRAIL_RENDER_FUNCTION func_800FD1C4
#define VS_TRAIL_DISPATCH_FUNCTION vs_effect_apocalypse_3
#include "src/EFFECT/trails5.h"

#define VS_PARTICLE_ORIGIN_FUNCTION func_800FE168
#define VS_PARTICLE_TARGET_FUNCTION func_800FE8F0
#define VS_PARTICLE_CONTROL_FUNCTION func_800FEB08
#include "src/EFFECT/particleSetup.h"

#define VS_PARTICLE_RENDER_FUNCTION func_800FEFB8
#include "src/EFFECT/particleLineRender.h"

#define VS_PARTICLE_DISPATCH_FUNCTION vs_effect_apocalypse_4
#define VS_PARTICLE_UNTEXTURED
#include "src/EFFECT/particleDispatch.h"
