#include "E0.h"
/**
 * Text rays from caster to target
 */
#define VS_TRAIL_DISPATCH_FUNCTION vs_spiritSurge_renderTrails
#include "src/EFFECT/trails9.h"

/**
 * Concentric text circles over caster
 */
#define VS_RING_FUNCTION vs_spiritSurge_1
#include "src/EFFECT/rings.h"

/**
 * Target impact
 */
#define VS_TILED_RING_FUNCTION vs_spiritSurge_2
#include "src/EFFECT/tiledRings.h"

/**
 * Column of light and particles on cast
 */
#define VS_ROTATING_SURFACE_FUNCTION vs_spiritSurge_3
#include "src/EFFECT/rotatingSurfaces.h"
