#include "common.h"

INCLUDE_ASM("build/src/EFFECT/PLG300.BIN/nonmatchings/110", func_800F9910);

#define VS_PARTICLE_ORIGIN_FUNCTION func_800FA584
#define VS_PARTICLE_TARGET_FUNCTION func_800FAD0C
#define VS_PARTICLE_CONTROL_FUNCTION func_800FAF24
#define VS_PARTICLE_RENDER_FUNCTION func_800FB3D4
#define VS_PARTICLE_DISPATCH_FUNCTION func_800FBF94
#define VS_PARTICLE_CORNER_STATE D_800FE34C
#include "src/EFFECT/particleSetup.h"

#include "src/EFFECT/particleRender.h"

#include "src/EFFECT/particleDispatch.h"

INCLUDE_ASM("build/src/EFFECT/PLG300.BIN/nonmatchings/110", func_800FC228);

INCLUDE_ASM("build/src/EFFECT/PLG300.BIN/nonmatchings/110", func_800FD198);
