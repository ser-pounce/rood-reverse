#include "F8.h"

#define VS_ROTATING_SURFACE_FUNCTION vs_effect_gaeaStrikeLv1_0
#include "src/EFFECT/rotatingSurfaces.h"

#define VS_CLOSED_RING_FUNCTION vs_effect_gaeaStrikeLv1_1
#include "src/EFFECT/closedRings.h"

#define VS_RING_FUNCTION vs_effect_gaeaStrikeLv1_2
#include "src/EFFECT/rings.h"

#define VS_PARTICLE_ORIGIN_FUNCTION func_800FC340
#define VS_PARTICLE_TARGET_FUNCTION func_800FCAC8
#define VS_PARTICLE_CONTROL_FUNCTION func_800FCCE0
#include "src/EFFECT/particleSetup.h"

#define VS_PARTICLE_RENDER_FUNCTION func_800FD190
#include "src/EFFECT/particleLineRender.h"

#define VS_PARTICLE_DISPATCH_FUNCTION vs_effect_gaeaStrikeLv1_3
#define VS_PARTICLE_UNTEXTURED
#include "src/EFFECT/particleDispatch.h"
