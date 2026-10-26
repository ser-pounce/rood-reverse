#include "1D8.h"

#define VS_EFFECT_NAME vs_effect_blackNebula

#include "src/EFFECT/tiledRings.h"

#include "src/EFFECT/mirroredSurfaces.h"

#define VS_PARTICLE_UNTEXTURED
#include "src/EFFECT/particleSetup.h"
#include "src/EFFECT/particleLineRender.h"
#include "src/EFFECT/particleDispatch.h"

#define VS_RING_TRANSPOSED
#include "src/EFFECT/rings.h"

#include "src/EFFECT/trails5.h"
