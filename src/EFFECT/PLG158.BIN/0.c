#include "0.h"

#define VS_SURFACE_FUNCTION vs_effect_hexFlux_0
#define VS_SURFACE_TEXTURE_COLUMNS 4
#include "src/EFFECT/sphericalSurfaceVertices.h"

#include "src/EFFECT/surfaces.h"

#define VS_MIRROR_SURFACE_FUNCTION vs_effect_hexFlux_1
#include "src/EFFECT/sphericalSurfaceVertices.h"

#include "src/EFFECT/mirroredSurfaces.h"

#define VS_CLOSED_RING_FUNCTION vs_effect_hexFlux_2
#define VS_CLOSED_RING_TEXTURE_COLUMNS 4
#include "src/EFFECT/closedRings.h"

#define VS_ROTATING_SURFACE_TEXTURE_COLUMNS 4
#define VS_ROTATING_SURFACE_FUNCTION vs_effect_hexFlux_3
#include "src/EFFECT/rotatingSurfaces.h"
