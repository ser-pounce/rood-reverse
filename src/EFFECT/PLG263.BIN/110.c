#include "common.h"

INCLUDE_ASM("build/src/EFFECT/PLG263.BIN/nonmatchings/110", func_800F9910);

INCLUDE_ASM("build/src/EFFECT/PLG263.BIN/nonmatchings/110", func_800FA4A8);

INCLUDE_ASM("build/src/EFFECT/PLG263.BIN/nonmatchings/110", func_800FB0CC);

#define VS_PARTICLE_ORIGIN_FUNCTION func_800FC00C
#define VS_PARTICLE_TARGET_FUNCTION func_800FC794
#define VS_PARTICLE_CONTROL_FUNCTION func_800FC9AC
#define VS_PARTICLE_RENDER_FUNCTION func_800FCE5C
#define VS_PARTICLE_DISPATCH_FUNCTION func_800FDA1C
#define VS_PARTICLE_CORNER_STATE D_800FDF70
#include "src/EFFECT/particleSetup.h"

INCLUDE_ASM("build/src/EFFECT/PLG263.BIN/nonmatchings/110", func_800FCE5C);

#include "src/EFFECT/particleDispatch.h"
