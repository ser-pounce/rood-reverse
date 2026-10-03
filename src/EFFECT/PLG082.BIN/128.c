#include "common.h"

#define VS_PARTICLE_ORIGIN_FUNCTION func_800F9928
#define VS_PARTICLE_TARGET_FUNCTION func_800FA0B0
#define VS_PARTICLE_CONTROL_FUNCTION func_800FA2C8
#define VS_PARTICLE_RENDER_FUNCTION func_800FA778
#define VS_PARTICLE_DISPATCH_FUNCTION func_800FB338
#define VS_PARTICLE_CORNER_STATE D_800FD088
#include "src/EFFECT/particleSetup.h"

#include "src/EFFECT/particleRender.h"

#include "src/EFFECT/particleDispatch.h"

INCLUDE_ASM("build/src/EFFECT/PLG082.BIN/nonmatchings/128", func_800FB5CC);

INCLUDE_ASM("build/src/EFFECT/PLG082.BIN/nonmatchings/128", func_800FC11C);
