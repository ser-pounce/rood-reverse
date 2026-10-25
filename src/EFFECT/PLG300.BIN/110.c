#include "110.h"

#define VS_MIRROR_SURFACE_FUNCTION vs_effect_plg300_0
#include "src/EFFECT/sphericalSurfaceVertices.h"

#include "src/EFFECT/mirroredSurfaces.h"

#define VS_PARTICLE_DISPATCH_FUNCTION vs_effect_plg300_1
#include "src/EFFECT/particleSetup.h"
#include "src/EFFECT/particleRender.h"
#include "src/EFFECT/particleDispatch.h"

#define VS_CLOSED_RING_FUNCTION vs_effect_plg300_2
#define VS_CLOSED_RING_TEXTURE_COLUMNS 4
#include "src/EFFECT/closedRings.h"

// This ring links every quad into the same ordering table slot
#define VS_CLOSED_RING_FUNCTION vs_effect_plg300_3
#define VS_CLOSED_RING_OT_SLOT -15
#define VS_CLOSED_RING_TEXTURE_COLUMNS 4
#include "src/EFFECT/closedRings.h"
