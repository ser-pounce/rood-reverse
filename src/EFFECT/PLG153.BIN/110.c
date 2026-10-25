#include "110.h"

#define VS_MESH10_FUNCTION vs_effect_gravisAether_0
#include "src/EFFECT/meshes10.h"

#define VS_RING_FUNCTION vs_effect_gravisAether_1
#define VS_RING_TRANSPOSED
#include "src/EFFECT/rings.h"

#define VS_PARTICLE_DISPATCH_FUNCTION vs_effect_gravisAether_2
#include "src/EFFECT/particleSetup.h"
#include "src/EFFECT/particleRender.h"
#include "src/EFFECT/particleDispatch.h"
