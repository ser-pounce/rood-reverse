#include "common.h"

INCLUDE_ASM("build/src/EFFECT/PLG153.BIN/nonmatchings/110", func_800F9910);

#define VS_RING_FUNCTION func_800FA41C
#define VS_RING_COLORS D_800FCDB4
#define VS_RING_TRANSPOSED
#include "src/EFFECT/rings.h"

#define VS_PARTICLE_ORIGIN_FUNCTION func_800FB040
#define VS_PARTICLE_TARGET_FUNCTION func_800FB7C8
#define VS_PARTICLE_CONTROL_FUNCTION func_800FB9E0
#define VS_PARTICLE_RENDER_FUNCTION func_800FBE90
#define VS_PARTICLE_DISPATCH_FUNCTION func_800FCA50
#define VS_PARTICLE_CORNER_STATE D_800FCDD4
#include "src/EFFECT/particleSetup.h"

#include "src/EFFECT/particleRender.h"

#include "src/EFFECT/particleDispatch.h"
