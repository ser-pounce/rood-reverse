#include "common.h"
#include "src/BATTLE/BATTLE.PRG/5BF94.h"
#include "src/SLUS_010.40/32154.h"
#include "vs_inline_c.h"
#include "gpu.h"
#include <inline_c.h>
#include <rand.h>

#define VS_CLOSED_RING_FUNCTION func_800F98E0
#define VS_CLOSED_RING_COLORS D_800FD824
#include "src/EFFECT/closedRings.h"

#define VS_ROTATING_SURFACE_FUNCTION func_800FA84C
#include "src/EFFECT/rotatingSurfaces.h"

#define VS_TRAIL_ORIGIN_FUNCTION func_800FB704
#define VS_TRAIL_TARGET_FUNCTION func_800FBEA0
#define VS_TRAIL_CONTROL_FUNCTION func_800FC0B8
#define VS_TRAIL_INIT_FUNCTION func_800FC590
#define VS_TRAIL_UPDATE_FUNCTION func_800FC708
#define VS_TRAIL_RENDER_FUNCTION func_800FC894
#define VS_TRAIL_DISPATCH_FUNCTION func_800FD2E4
#define VS_TRAIL_CORNER_STATE D_800FD844
#include "src/EFFECT/trails9.h"
