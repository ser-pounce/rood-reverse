#include "common.h"
#include "src/BATTLE/BATTLE.PRG/5BF94.h"
#include "src/SLUS_010.40/32154.h"
#include "vs_inline_c.h"
#include "gpu.h"
#include <inline_c.h>
#include <rand.h>

#define VS_TRAIL_ORIGIN_FUNCTION func_800F98F8
#define VS_TRAIL_TARGET_FUNCTION func_800FA094
#define VS_TRAIL_CONTROL_FUNCTION func_800FA2AC
#define VS_TRAIL_INIT_FUNCTION func_800FA770
#define VS_TRAIL_UPDATE_FUNCTION func_800FA8E8
#define VS_TRAIL_RENDER_FUNCTION func_800FAA74
#define VS_TRAIL_DISPATCH_FUNCTION func_800FB4D0
#define VS_TRAIL_CORNER_STATE D_800FD4D8
#include "src/EFFECT/trails5.h"

#define VS_GRID_FUNCTION func_800FBA18
#include "src/EFFECT/grids.h"

#define VS_CLOSED_RING_FUNCTION func_800FC568
#define VS_CLOSED_RING_COLORS D_800FD4DC
#define VS_CLOSED_RING_TEXTURE_COLUMNS 4
#include "src/EFFECT/closedRings.h"
