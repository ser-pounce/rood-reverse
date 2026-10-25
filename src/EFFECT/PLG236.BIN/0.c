#include "0.h"

#define VS_CLOSED_RING_FUNCTION vs_effect_plg236_0
#define VS_CLOSED_RING_TEXTURE_COLUMNS 4
#include "src/EFFECT/closedRings.h"

#define VS_ROTATING_SURFACE_TEXTURE_COLUMNS 4
#define VS_ROTATING_SURFACE_FUNCTION vs_effect_plg236_1
#include "src/EFFECT/rotatingSurfaces.h"

#define VS_CLOSED_RING_FUNCTION vs_effect_plg236_2
#define VS_CLOSED_RING_TRANSPOSED
#include "src/EFFECT/closedRings.h"

#define VS_RING_FUNCTION vs_effect_plg236_3
#define VS_RING_TRANSPOSED
#include "src/EFFECT/rings.h"
