#include "common.h"

#define VS_PARTICLE_ORIGIN_FUNCTION func_800F9A08
#define VS_PARTICLE_TARGET_FUNCTION func_800FA190
#define VS_PARTICLE_CONTROL_FUNCTION func_800FA3A8
#define VS_PARTICLE_RENDER_FUNCTION func_800FA858
#define VS_PARTICLE_DISPATCH_FUNCTION func_800FB418
#define VS_PARTICLE_CORNER_STATE D_800FCCA0
#include "src/EFFECT/particleSetup.h"

INCLUDE_ASM("build/src/EFFECT/PLG114.BIN/nonmatchings/208", func_800FA858);

#include "src/EFFECT/particleDispatch.h"

INCLUDE_ASM("build/src/EFFECT/PLG114.BIN/nonmatchings/208", func_800FB6AC);

INCLUDE_ASM("build/src/EFFECT/PLG114.BIN/nonmatchings/208", func_800FBE34);

INCLUDE_ASM("build/src/EFFECT/PLG114.BIN/nonmatchings/208", func_800FC04C);

INCLUDE_ASM("build/src/EFFECT/PLG114.BIN/nonmatchings/208", func_800FC4FC);

INCLUDE_ASM("build/src/EFFECT/PLG114.BIN/nonmatchings/208", func_800FCA2C);
