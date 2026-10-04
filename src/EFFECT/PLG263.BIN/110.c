#include "common.h"

#define VS_SURFACE_FUNCTION func_800F9910
#define VS_SURFACE_VERTICES D_800FDCB0
#include "src/EFFECT/surfaces.h"

#define VS_RING_FUNCTION func_800FA4A8
#define VS_RING_COLORS D_800FDF30
#include "src/EFFECT/rings.h"

INCLUDE_ASM("build/src/EFFECT/PLG263.BIN/nonmatchings/110", func_800FB0CC);

#define VS_PARTICLE_ORIGIN_FUNCTION func_800FC00C
#define VS_PARTICLE_TARGET_FUNCTION func_800FC794
#define VS_PARTICLE_CONTROL_FUNCTION func_800FC9AC
#define VS_PARTICLE_RENDER_FUNCTION func_800FCE5C
#define VS_PARTICLE_DISPATCH_FUNCTION func_800FDA1C
#define VS_PARTICLE_CORNER_STATE D_800FDF70
#include "src/EFFECT/particleSetup.h"

#include "src/EFFECT/particleRender.h"

#include "src/EFFECT/particleDispatch.h"
