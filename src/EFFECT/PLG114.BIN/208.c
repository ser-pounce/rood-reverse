#include "208.h"

#define VS_PARTICLE_ORIGIN_FUNCTION func_800F9A08
#define VS_PARTICLE_TARGET_FUNCTION func_800FA190
#define VS_PARTICLE_CONTROL_FUNCTION func_800FA3A8
#include "src/EFFECT/particleSetup.h"

#define VS_PARTICLE_RENDER_FUNCTION func_800FA858
#include "src/EFFECT/particleRender.h"

#define VS_PARTICLE_DISPATCH_FUNCTION vs_effect_numbingNeedle_0
#include "src/EFFECT/particleDispatch.h"

#define VS_PARTICLE_ORIGIN_FUNCTION func_800FB6AC
#define VS_PARTICLE_TARGET_FUNCTION func_800FBE34
#define VS_PARTICLE_CONTROL_FUNCTION func_800FC04C
#include "src/EFFECT/particleSetup.h"

#define VS_PARTICLE_RENDER_FUNCTION func_800FC4FC
#include "src/EFFECT/particleLineRender.h"

#define VS_PARTICLE_DISPATCH_FUNCTION vs_effect_numbingNeedle_1
#define VS_PARTICLE_UNTEXTURED
#include "src/EFFECT/particleDispatch.h"
