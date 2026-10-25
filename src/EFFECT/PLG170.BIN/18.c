#include "18.h"

#define VS_MIRROR_SURFACE_FUNCTION vs_effect_retribution_0
#include "src/EFFECT/sphericalSurfaceVertices.h"

#include "src/EFFECT/mirroredSurfaces.h"

#define VS_ROTATING_SURFACE_TEXTURE_COLUMNS 4
#define VS_ROTATING_SURFACE_FUNCTION vs_effect_retribution_1
#include "src/EFFECT/rotatingSurfaces.h"

#define VS_RING_FUNCTION vs_effect_retribution_2
#define VS_RING_TRANSPOSED
#include "src/EFFECT/rings.h"

#define VS_GRID_FUNCTION vs_effect_retribution_3
#include "src/EFFECT/grids.h"

#define VS_SURFACE_FUNCTION vs_effect_retribution_4
#define VS_SURFACE_TEXTURE_COLUMNS 4
#include "src/EFFECT/sphericalSurfaceVertices.h"

#include "src/EFFECT/surfaces.h"

#define VS_CLOSED_RING_FUNCTION vs_effect_retribution_5
#define VS_CLOSED_RING_TEXTURE_COLUMNS 4
#include "src/EFFECT/closedRings.h"
