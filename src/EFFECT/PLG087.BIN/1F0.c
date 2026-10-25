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

#define VS_TRAIL_DISPATCH_FUNCTION vs_effect_apocalypse_3
#include "src/EFFECT/trails5.h"

#define VS_PARTICLE_DISPATCH_FUNCTION vs_effect_apocalypse_4
#define VS_PARTICLE_UNTEXTURED
#include "src/EFFECT/particleSetup.h"
#include "src/EFFECT/particleLineRender.h"
#include "src/EFFECT/particleDispatch.h"
