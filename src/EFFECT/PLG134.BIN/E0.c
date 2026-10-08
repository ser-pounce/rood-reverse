#include "common.h"
#include "src/BATTLE/BATTLE.PRG/5BF94.h"
#include "src/SLUS_010.40/32154.h"
#include "vs_inline_c.h"
#include "gpu.h"
#include <inline_c.h>
#include <rand.h>

#define VS_TRAIL_ORIGIN_FUNCTION func_800F98E0
#define VS_TRAIL_TARGET_FUNCTION func_800FA07C
#define VS_TRAIL_CONTROL_FUNCTION func_800FA294
#define VS_TRAIL_INIT_FUNCTION func_800FA758
#define VS_TRAIL_UPDATE_FUNCTION func_800FA8D0
#define VS_TRAIL_RENDER_FUNCTION func_800FAA5C
#define VS_TRAIL_DISPATCH_FUNCTION func_800FB4B8
#define VS_TRAIL_CORNER_STATE D_800FC96C
#include "src/EFFECT/trails5.h"

#define VS_CLOSED_RING_FUNCTION func_800FBA00
#define VS_CLOSED_RING_COLORS D_800FC970
#include "src/EFFECT/closedRings.h"
