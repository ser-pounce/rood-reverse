#include "common.h"
#include "src/BATTLE/BATTLE.PRG/5BF94.h"
#include "src/SLUS_010.40/32154.h"
#include "vs_inline_c.h"
#include "gpu.h"
#include <inline_c.h>
#include <rand.h>

#define VS_PARTICLE_ORIGIN_FUNCTION func_800F9910
#define VS_PARTICLE_TARGET_FUNCTION func_800FA098
#define VS_PARTICLE_CONTROL_FUNCTION func_800FA2B0
#define VS_PARTICLE_RENDER_FUNCTION func_800FA760
#define VS_PARTICLE_DISPATCH_FUNCTION func_800FB320
#define VS_PARTICLE_CORNER_STATE D_800FC524
#include "src/EFFECT/particleSetup.h"

#include "src/EFFECT/particleRender.h"

#include "src/EFFECT/particleDispatch.h"

#define VS_CLOSED_RING_FUNCTION func_800FB5B4
#define VS_CLOSED_RING_COLORS D_800FC528
#define VS_CLOSED_RING_TEXTURE_COLUMNS 4
#include "src/EFFECT/closedRings.h"
