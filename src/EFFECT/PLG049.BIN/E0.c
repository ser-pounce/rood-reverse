#define VS_TRAIL_ORIGIN_FUNCTION func_800F98E0
#define VS_TRAIL_TARGET_FUNCTION func_800FA07C
#define VS_TRAIL_CONTROL_FUNCTION func_800FA294
#define VS_TRAIL_INIT_FUNCTION func_800FA76C
#define VS_TRAIL_UPDATE_FUNCTION func_800FA8E4
#define VS_TRAIL_RENDER_FUNCTION func_800FAA70
#define VS_TRAIL_DISPATCH_FUNCTION vs_spiritSurge_renderTrails
#define VS_TRAIL_CORNER_STATE D_800FE3D4
#include "src/EFFECT/trails9.h"

/**
 * Concentric text circles over caster
 */
#define VS_RING_FUNCTION func_800FBA00
#define VS_RING_COLORS D_800FE3D8
#include "src/EFFECT/rings.h"

/**
 * Target impact
 */
#define VS_TILED_RING_FUNCTION func_800FC624
#define VS_TILED_RING_COLORS D_800FE3F8
#include "src/EFFECT/tiledRings.h"

/**
 * Column of light and particles on cast
 */
INCLUDE_ASM("build/src/EFFECT/PLG049.BIN/nonmatchings/E0", func_800FD51C);
