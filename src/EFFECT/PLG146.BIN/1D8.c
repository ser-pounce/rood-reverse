#include "1D8.h"

#define VS_TILED_RING_FUNCTION vs_effect_blackNebula_0
#include "src/EFFECT/tiledRings.h"

#define VS_MIRROR_SURFACE_FUNCTION vs_effect_blackNebula_1
#include "src/EFFECT/sphericalSurfaceVertices.h"

#include "src/EFFECT/mirroredSurfaces.h"

#define VS_PARTICLE_DISPATCH_FUNCTION vs_effect_blackNebula_2
#define VS_PARTICLE_UNTEXTURED
#include "src/EFFECT/particleSetup.h"
#include "src/EFFECT/particleLineRender.h"
#include "src/EFFECT/particleDispatch.h"

#define VS_RING_FUNCTION vs_effect_blackNebula_3
#define VS_RING_TRANSPOSED
#include "src/EFFECT/rings.h"

#define VS_TRAIL_DISPATCH_FUNCTION vs_effect_blackNebula_4
#include "src/EFFECT/trails5.h"
