#include "E0.h"
/**
 * Text rays from caster to target
 */
#define VS_TRAIL_ORIGIN_FUNCTION func_800F98E0
#define VS_TRAIL_TARGET_FUNCTION func_800FA07C
#define VS_TRAIL_CONTROL_FUNCTION func_800FA294
#define VS_TRAIL_INIT_FUNCTION func_800FA76C
#define VS_TRAIL_UPDATE_FUNCTION func_800FA8E4
#define VS_TRAIL_RENDER_FUNCTION func_800FAA70
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
