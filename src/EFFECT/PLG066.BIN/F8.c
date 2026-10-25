#include "F8.h"

#define VS_ROTATING_SURFACE_FUNCTION vs_effect_gaeaStrikeLv2_0
#include "src/EFFECT/rotatingSurfaces.h"

#define VS_CLOSED_RING_FUNCTION vs_effect_gaeaStrikeLv2_1
#include "src/EFFECT/closedRings.h"

#define VS_RING_FUNCTION vs_effect_gaeaStrikeLv2_2
#include "src/EFFECT/rings.h"

#define VS_PARTICLE_DISPATCH_FUNCTION vs_effect_gaeaStrikeLv2_3
#define VS_PARTICLE_UNTEXTURED
#include "src/EFFECT/particleSetup.h"
#include "src/EFFECT/particleLineRender.h"
#include "src/EFFECT/particleDispatch.h"
