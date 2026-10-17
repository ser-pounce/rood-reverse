#include "common.h"
#include "src/BATTLE/BATTLE.PRG/5BF94.h"
#include "src/SLUS_010.40/32154.h"
#include "vs_inline_c.h"
#include "gpu.h"
#include <inline_c.h>
#include <rand.h>

#define VS_CLOSED_RING_FUNCTION func_800F98F8
#define VS_CLOSED_RING_COLORS D_800FE390
#define VS_CLOSED_RING_TEXTURE_COLUMNS 4
#include "src/EFFECT/closedRings.h"

#define VS_ROTATING_SURFACE_FUNCTION func_800FA868
#include "src/EFFECT/rotatingSurfaces.h"

#define VS_GRID_FUNCTION func_800FB720
#include "src/EFFECT/grids.h"

#define VS_TRAIL_ORIGIN_FUNCTION func_800FC270
#define VS_TRAIL_TARGET_FUNCTION func_800FCA0C
#define VS_TRAIL_CONTROL_FUNCTION func_800FCC24
#define VS_TRAIL_INIT_FUNCTION func_800FD0E8
#define VS_TRAIL_UPDATE_FUNCTION func_800FD260
#define VS_TRAIL_RENDER_FUNCTION func_800FD3EC
#define VS_TRAIL_DISPATCH_FUNCTION func_800FDE48
#define VS_TRAIL_CORNER_STATE D_800FE3B0
#include "src/EFFECT/trails5.h"
