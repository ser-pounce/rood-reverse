#include "F8.h"

#define VS_CLOSED_RING_FUNCTION vs_effect_judgment_0
#define VS_CLOSED_RING_TEXTURE_COLUMNS 4
#include "src/EFFECT/closedRings.h"

#define VS_ROTATING_SURFACE_FUNCTION vs_effect_judgment_1
#include "src/EFFECT/rotatingSurfaces.h"

#define VS_GRID_FUNCTION vs_effect_judgment_2
#include "src/EFFECT/grids.h"

#define VS_TRAIL_ORIGIN_FUNCTION func_800FC270
#define VS_TRAIL_TARGET_FUNCTION func_800FCA0C
#define VS_TRAIL_CONTROL_FUNCTION func_800FCC24
#define VS_TRAIL_INIT_FUNCTION func_800FD0E8
#define VS_TRAIL_UPDATE_FUNCTION func_800FD260
#define VS_TRAIL_RENDER_FUNCTION func_800FD3EC
#define VS_TRAIL_DISPATCH_FUNCTION vs_effect_judgment_3
#include "src/EFFECT/trails5.h"
