#include "18.h"

#define VS_MIRROR_SURFACE_FUNCTION vs_effect_plg297_0
#include "src/EFFECT/sphericalSurfaceVertices.h"

#include "src/EFFECT/mirroredSurfaces.h"

#define VS_CLOSED_RING_FUNCTION vs_effect_plg297_1
#define VS_CLOSED_RING_TEXTURE_COLUMNS 4
#include "src/EFFECT/closedRings.h"

#define VS_GRID_FUNCTION vs_effect_plg297_2
#include "src/EFFECT/grids.h"

#define VS_RING_FUNCTION vs_effect_plg297_3
#define VS_RING_TRANSPOSED
#include "src/EFFECT/rings.h"
