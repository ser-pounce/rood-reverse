#include "110.h"

#define VS_PARTICLE_ORIGIN_FUNCTION func_800F9910
#define VS_PARTICLE_TARGET_FUNCTION func_800FA098
#define VS_PARTICLE_CONTROL_FUNCTION func_800FA2B0

#include "src/EFFECT/particleSetup.h"

#define VS_PARTICLE_RENDER_FUNCTION func_800FA760
#include "src/EFFECT/particleRender.h"

#define VS_PARTICLE_DISPATCH_FUNCTION vs_effect_thunderBreath
#include "src/EFFECT/particleDispatch.h"
