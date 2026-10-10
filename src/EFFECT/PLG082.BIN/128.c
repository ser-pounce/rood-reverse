#include "common.h"
#include "src/BATTLE/BATTLE.PRG/5BF94.h"
#include "src/SLUS_010.40/32154.h"
#include "vs_inline_c.h"
#include "gpu.h"
#include <inline_c.h>
#include <rand.h>

#define VS_PARTICLE_ORIGIN_FUNCTION func_800F9928
#define VS_PARTICLE_TARGET_FUNCTION func_800FA0B0
#define VS_PARTICLE_CONTROL_FUNCTION func_800FA2C8
#define VS_PARTICLE_RENDER_FUNCTION func_800FA778
#define VS_PARTICLE_DISPATCH_FUNCTION func_800FB338
#define VS_PARTICLE_CORNER_STATE D_800FD088
#include "src/EFFECT/particleSetup.h"

#include "src/EFFECT/particleRender.h"

#include "src/EFFECT/particleDispatch.h"

#define VS_GRID_FUNCTION func_800FB5CC
#include "src/EFFECT/grids.h"

#define VS_CLOSED_RING_FUNCTION func_800FC11C
#define VS_CLOSED_RING_COLORS D_800FD08C
#include "src/EFFECT/closedRings.h"
