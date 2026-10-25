#include "F8.h"

#define VS_TILED_RING_FUNCTION vs_effect_radialSurgeLv4_0
#include "src/EFFECT/tiledRings.h"

#define VS_RING_FUNCTION vs_effect_radialSurgeLv4_1
#include "src/EFFECT/rings.h"

#define VS_TRAIL_ORIGIN_FUNCTION func_800FB414
#define VS_TRAIL_TARGET_FUNCTION func_800FBBB0
#define VS_TRAIL_CONTROL_FUNCTION func_800FBDC8
#define VS_TRAIL_INIT_FUNCTION func_800FC28C
#define VS_TRAIL_UPDATE_FUNCTION func_800FC404
#define VS_TRAIL_RENDER_FUNCTION func_800FC590
#define VS_TRAIL_DISPATCH_FUNCTION vs_effect_radialSurgeLv4_2
#include "src/EFFECT/trails5.h"

#define VS_ROTATING_SURFACE_FUNCTION vs_effect_radialSurgeLv4_3
#include "src/EFFECT/rotatingSurfaces.h"

#define VS_GRID_FUNCTION vs_effect_radialSurgeLv4_4
#include "src/EFFECT/grids.h"
