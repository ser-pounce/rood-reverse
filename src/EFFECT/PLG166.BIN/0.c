#include "0.h"

#define VS_ROTATING_SURFACE_FUNCTION vs_effect_sanctusFlare_0
#include "src/EFFECT/rotatingSurfaces.h"

#define VS_MIRROR_SURFACE_FUNCTION vs_effect_sanctusFlare_1
#include "src/EFFECT/sphericalSurfaceVertices.h"

#include "src/EFFECT/mirroredSurfaces.h"

#define VS_CLOSED_RING_FUNCTION vs_effect_sanctusFlare_2
#define VS_CLOSED_RING_TEXTURE_COLUMNS 4
#include "src/EFFECT/closedRings.h"

#define VS_RING_FUNCTION vs_effect_sanctusFlare_3
#define VS_RING_TRANSPOSED
#include "src/EFFECT/rings.h"
