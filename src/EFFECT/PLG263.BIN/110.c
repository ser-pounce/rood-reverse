#include "110.h"

#define VS_SURFACE_FUNCTION vs_effect_plg263_0
#include "src/EFFECT/sphericalSurfaceVertices.h"

#include "src/EFFECT/surfaces.h"

#define VS_RING_FUNCTION vs_effect_plg263_1
#include "src/EFFECT/rings.h"

#define VS_CLOSED_RING_FUNCTION vs_effect_plg263_2
#define VS_CLOSED_RING_TRANSPOSED
#include "src/EFFECT/closedRings.h"

#define VS_PARTICLE_DISPATCH_FUNCTION vs_effect_plg263_3
#include "src/EFFECT/particleSetup.h"
#include "src/EFFECT/particleRender.h"
#include "src/EFFECT/particleDispatch.h"
